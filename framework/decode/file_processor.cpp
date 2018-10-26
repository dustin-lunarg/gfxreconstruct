/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <cassert>

#include "util/compressor.h"
#include "util/logging.h"
#include "util/platform.h"
#include "decode/file_processor.h"
#include "format/format_util.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

FileProcessor::FileProcessor() : file_descriptor_(nullptr), bytes_read_(0), compressor_(nullptr) {}

FileProcessor::~FileProcessor()
{
    if (nullptr != compressor_)
    {
        delete compressor_;
        compressor_ = nullptr;
    }

    if (file_descriptor_)
    {
        fclose(file_descriptor_);
    }
}

bool FileProcessor::Initialize(const std::string& filename)
{
    bool success = false;

    int32_t result = util::platform::FileOpen(&file_descriptor_, filename.c_str(), "rb");

    if ((result == 0) && (file_descriptor_ != nullptr))
    {
        success = ReadFileHeader();

        if (success)
        {
            filename_ = filename;
        }
        else
        {
            BRIMSTONE_LOG_ERROR("Failed to load file header from %s", filename.c_str());
            fclose(file_descriptor_);
            file_descriptor_ = nullptr;
        }
    }
    else
    {
        BRIMSTONE_LOG_ERROR("Failed to open file %s", filename.c_str());
    }

    return success;
}

bool FileProcessor::ProcessNextFrame()
{
    // TODO: Frame blocks in trace file.
    bool                success = IsFileValid();
    format::BlockHeader block_header;

    while (success)
    {
        success = ReadBlockHeader(&block_header);

        if (success)
        {
            format::BlockType base_type = format::RemoveCompressedBlockBit(block_header.type);

            if ((base_type == format::BlockType::kFunctionCallBlock) ||
                (base_type == format::BlockType::kFunctionCallPreBlock) ||
                (base_type == format::BlockType::kFunctionCallPostBlock))
            {
                format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                success = ReadBytes(&api_call_id, sizeof(api_call_id));

                if (success)
                {
                    if (base_type == format::BlockType::kFunctionCallBlock)
                    {
                        success = ProcessFunctionCallUnified(block_header, api_call_id);
                    }
                    else if (base_type == format::BlockType::kFunctionCallPreBlock)
                    {
                        success = ProcessFunctionCallPre(block_header, api_call_id);
                    }
                    else if (base_type == format::BlockType::kFunctionCallPostBlock)
                    {
                        success = ProcessFunctionCallPost(block_header, api_call_id);
                    }

                    // Break from loop on frame delimiter.
                    if ((base_type != format::BlockType::kFunctionCallPreBlock) && IsFrameDelimiter(api_call_id))
                    {
                        break;
                    }
                }
                else
                {
                    BRIMSTONE_LOG_ERROR("Failed to read function call block header");
                }
            }
            else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kMetaDataBlock)
            {
                format::MetaDataType meta_type = format::MetaDataType::kUnknownMetaDataType;

                success = ReadBytes(&meta_type, sizeof(meta_type));

                if (success)
                {
                    success = ProcessMetaData(block_header, meta_type);
                }
                else
                {
                    BRIMSTONE_LOG_ERROR("Failed to read meta-data block header");
                }
            }
            else
            {
                // Unrecognized block type.
                BRIMSTONE_LOG_WARNING("Skipping unrecognized file block with type %u", block_header.type);
                success = SkipBytes(block_header.size);
            }

            if (success)
            {
                // Check for EOF.
                success = IsFileValid();
            }
        }
        else
        {
            if (!feof(file_descriptor_))
            {
                BRIMSTONE_LOG_ERROR("Failed to read block header");
            }
        }
    }

    return success;
}

bool FileProcessor::ProcessAllFrames()
{
    bool success = IsFileValid();

    while (success)
    {
        success = ProcessNextFrame();
    }

    return success;
}

bool FileProcessor::ReadFileHeader()
{
    bool success = false;

    if (ReadBytes(&file_header_, sizeof(file_header_)))
    {
        success = format::ValidateFileHeader(file_header_);
    }

    if (success)
    {
        file_options_.resize(file_header_.num_options);

        size_t option_data_size = file_header_.num_options * sizeof(format::FileOptionPair);

        if (ReadBytes(file_options_.data(), option_data_size))
        {
            success = true;

            for (const auto& option : file_options_)
            {
                switch (option.key)
                {
                    case format::FileOption::kCompressionType:
                        enabled_options_.compression_type = static_cast<format::CompressionType>(option.value);
                        break;
                    case format::FileOption::kHaveThreadId:
                        enabled_options_.record_thread_id = option.value ? true : false;
                        break;
                    case format::FileOption::kHaveBeginEndTimestamp:
                        enabled_options_.record_begin_end_timestamp = option.value ? true : false;
                        break;
                    case format::FileOption::kOmitTextures:
                        enabled_options_.omit_textures = option.value ? true : false;
                        break;
                    case format::FileOption::kOmitBuffers:
                        enabled_options_.omit_buffers = option.value ? true : false;
                        break;
                    case format::FileOption::kAddressEncodingSize:
                    case format::FileOption::kObjectEncodingSize:
                    case format::FileOption::kHandleEncodingSize:
                        // We currently assume all pointer/address values are encoded as 8 byte values.
                        break;
                    default:
                        BRIMSTONE_LOG_WARNING("Ignoring unrecognized file header option %u", option.key);
                        break;
                }
            }
        }
    }

    compressor_ = format::CreateCompressor(enabled_options_.compression_type);
    if ((nullptr == compressor_) && (format::CompressionType::kNone != enabled_options_.compression_type))
    {
        BRIMSTONE_LOG_WARNING(
            "Failed to initialized file compression module (type = %u); replay of compressed data will not be possible",
            enabled_options_.compression_type);
        success = false;
    }

    return success;
}

bool FileProcessor::ReadBlockHeader(format::BlockHeader* block_header)
{
    assert(block_header != nullptr);

    bool success = false;

    if (ReadBytes(block_header, sizeof(*block_header)))
    {
        success = true;
    }

    return success;
}

bool FileProcessor::ReadParameterBuffer(size_t buffer_size, std::vector<uint8_t>* parameter_buffer)
{
    assert(parameter_buffer != nullptr);

    if (buffer_size > parameter_buffer->size())
    {
        parameter_buffer->resize(buffer_size);
    }

    return ReadBytes(parameter_buffer->data(), buffer_size);
}

bool FileProcessor::ReadCompressedParameterBuffer(size_t                compressed_buffer_size,
                                                  size_t                expected_uncompressed_size,
                                                  size_t*               uncompressed_buffer_size,
                                                  std::vector<uint8_t>* compressed_parameter_buffer,
                                                  std::vector<uint8_t>* parameter_buffer)
{
    assert(compressed_parameter_buffer != nullptr);
    assert(parameter_buffer != nullptr);

    if (compressed_buffer_size > compressed_parameter_buffer->size())
    {
        compressed_parameter_buffer->resize(compressed_buffer_size);
    }

    if (ReadBytes(compressed_parameter_buffer->data(), compressed_buffer_size))
    {
        if (parameter_buffer->size() < expected_uncompressed_size)
        {
            parameter_buffer->resize(expected_uncompressed_size);
        }

        size_t uncompressed_size = compressor_->Decompress(
            compressed_buffer_size, (*compressed_parameter_buffer), expected_uncompressed_size, parameter_buffer);

        if ((0 < uncompressed_size) && (uncompressed_size == expected_uncompressed_size))
        {
            *uncompressed_buffer_size = uncompressed_size;
            return true;
        }
    }

    return false;
}

bool FileProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    size_t bytes_read = util::platform::FileRead(buffer, 1, buffer_size, file_descriptor_);
    bytes_read_ += bytes_read;
    return (bytes_read == buffer_size) ? true : false;
}

bool FileProcessor::SkipBytes(uint64_t skip_size)
{
    bool success = util::platform::FileSeek(file_descriptor_, skip_size, util::platform::FileSeekCurrent);

    if (success)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += skip_size;
    }

    return success;
}

bool FileProcessor::ProcessFunctionCallUnified(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    format::ApiCallOptions call_options          = {};
    size_t                 parameter_buffer_size = 0;
    bool                   success =
        ProcessFunctionCallCommon(block_header, call_id, &call_options, &parameter_buffer_, &parameter_buffer_size);

    if (success)
    {
        for (auto decoder : decoders_)
        {
            if (decoder->SupportsApiCall(call_id))
            {
                decoder->DecodeFunctionCall(call_id, call_options, parameter_buffer_.data(), parameter_buffer_size);
            }
        }
    }

    return success;
}

bool FileProcessor::ProcessFunctionCallPre(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    format::ApiCallOptions call_options          = {};
    size_t                 parameter_buffer_size = 0;
    bool                   success =
        ProcessFunctionCallCommon(block_header, call_id, &call_options, &parameter_buffer_, &parameter_buffer_size);

    if (success)
    {
        SplitApiCallInfo* info = new SplitApiCallInfo;

        info->thread_id       = call_options.thread_id;
        info->complete        = false;
        info->call_id         = call_id;
        info->pre_options     = call_options;
        info->pre_buffer_size = parameter_buffer_size;
        info->pre_buffer.swap(parameter_buffer_);

        current_thread_calls_[call_options.thread_id] = info;
        active_calls_.push_back(info);
    }

    return success;
}

bool FileProcessor::ProcessFunctionCallPost(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    format::ApiCallOptions call_options          = {};
    size_t                 parameter_buffer_size = 0;
    bool                   success =
        ProcessFunctionCallCommon(block_header, call_id, &call_options, &parameter_buffer_, &parameter_buffer_size);

    if (success)
    {
        auto info = current_thread_calls_[call_options.thread_id];
        assert(info != nullptr);

        if (info != nullptr)
        {
            assert(info->thread_id == call_options.thread_id);
            assert(info->call_id == call_id);

            current_thread_calls_[call_options.thread_id] = nullptr;

            info->complete         = true;
            info->post_options     = call_options;
            info->post_buffer_size = parameter_buffer_size;
            info->post_buffer.swap(parameter_buffer_);

            ProcessPendingCalls();
        }
    }

    return success;
}

bool FileProcessor::ProcessFunctionCallCommon(const format::BlockHeader& block_header,
                                              format::ApiCallId          call_id,
                                              format::ApiCallOptions*    call_options,
                                              std::vector<uint8_t>*      parameter_buffer,
                                              size_t*                    parameter_buffer_size)
{
    assert(call_options != nullptr);
    assert(parameter_buffer != nullptr);
    assert(parameter_buffer_size != nullptr);

    BRIMSTONE_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);

    bool     success           = true;
    size_t   data_size         = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t uncompressed_size = 0;

    if (format::IsBlockCompressed(block_header.type))
    {
        assert(compressor_ != nullptr);
        if (compressor_ != nullptr)
        {
            data_size -= sizeof(uncompressed_size);
            success = ReadBytes(&uncompressed_size, sizeof(uncompressed_size));
        }
        else
        {
            success = false;
            BRIMSTONE_LOG_ERROR("Failed to process compressed function call block; compression is not enabled.");
        }
    }

    if (success && enabled_options_.record_thread_id)
    {
        data_size -= sizeof(call_options->thread_id);
        success = ReadBytes(&(call_options->thread_id), sizeof(call_options->thread_id));
    }

    if (success && enabled_options_.record_begin_end_timestamp)
    {
        data_size -= sizeof(call_options->begin_time) + sizeof(call_options->end_time);

        success = ReadBytes(&(call_options->begin_time), sizeof(call_options->begin_time));
        success |= ReadBytes(&(call_options->end_time), sizeof(call_options->end_time));
    }

    if (success)
    {
        if (format::IsBlockCompressed(block_header.type))
        {
            BRIMSTONE_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);

            size_t actual_size = 0;
            success            = ReadCompressedParameterBuffer(data_size,
                                                    static_cast<size_t>(uncompressed_size),
                                                    &actual_size,
                                                    &compressed_parameter_buffer_,
                                                    parameter_buffer);

            if (success)
            {
                assert(actual_size == uncompressed_size);
                (*parameter_buffer_size) = actual_size;
            }
        }
        else
        {
            success = ReadParameterBuffer(data_size, parameter_buffer);

            if (success)
            {
                (*parameter_buffer_size) = data_size;
            }
        }
    }
    else
    {
        BRIMSTONE_LOG_ERROR("Failed to read function call block header");
    }

    return success;
}

bool FileProcessor::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type)
{
    bool success = true;

    if (meta_type == format::MetaDataType::kFillMemoryCommand)
    {
        format::FillMemoryCommandHeader header;

        success = ReadBytes(&header.memory_id, sizeof(header.memory_id));
        success |= ReadBytes(&header.memory_offset, sizeof(header.memory_offset));
        success |= ReadBytes(&header.memory_size, sizeof(header.memory_size));

        if (success)
        {
            BRIMSTONE_CHECK_CONVERSION_DATA_LOSS(size_t, header.memory_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                assert(compressor_ != nullptr);
                if (compressor_ != nullptr)
                {
                    size_t uncompressed_size = 0;
                    size_t compressed_size   = static_cast<size_t>(block_header.size) - sizeof(meta_type) -
                                             sizeof(header.memory_id) - sizeof(header.memory_offset) -
                                             sizeof(header.memory_size);

                    success = ReadCompressedParameterBuffer(compressed_size,
                                                            static_cast<size_t>(header.memory_size),
                                                            &uncompressed_size,
                                                            &compressed_parameter_buffer_,
                                                            &parameter_buffer_);
                }
                else
                {
                    success = false;
                    BRIMSTONE_LOG_ERROR("Failed to process compressed meta-data block; compression is not enabled.");
                }
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.memory_size), &parameter_buffer_);
            }
        }
        else
        {
            BRIMSTONE_LOG_ERROR("Failed to read fill memory meta-data block header");
        }

        if (success)
        {
            for (auto decoder : decoders_)
            {
                decoder->DispatchFillMemoryCommand(
                    header.memory_id, header.memory_offset, header.memory_size, parameter_buffer_.data());
            }
        }
    }
    else if (meta_type == format::MetaDataType::kResizeWindowCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::ResizeWindowCommand command;

        success = ReadBytes(&command.surface_id, sizeof(command.surface_id));
        success |= ReadBytes(&command.width, sizeof(command.width));
        success |= ReadBytes(&command.height, sizeof(command.height));

        if (success)
        {
            for (auto decoder : decoders_)
            {
                decoder->DispatchResizeWindowCommand(command.surface_id, command.width, command.height);
            }
        }
        else
        {
            BRIMSTONE_LOG_ERROR("Failed to read resize window meta-data block");
        }
    }
    else if (meta_type == format::MetaDataType::kDisplayMessageCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::DisplayMessageCommandHeader header;

        success = ReadBytes(&header.message_size, sizeof(header.message_size));

        if (success)
        {
            BRIMSTONE_CHECK_CONVERSION_DATA_LOSS(size_t, header.message_size);
            success = ReadParameterBuffer(static_cast<size_t>(header.message_size), &parameter_buffer_);
        }
        else
        {
            BRIMSTONE_LOG_ERROR("Failed to read display message meta-data block header");
        }

        if (success)
        {
            std::string message(parameter_buffer_.begin(), parameter_buffer_.end());

            for (auto decoder : decoders_)
            {
                decoder->DispatchDisplayMessageCommand(message);
            }
        }
    }
    else
    {
        // Unrecognized metadata type.
        BRIMSTONE_LOG_WARNING("Skipping unrecognized meta-data block with type %u", meta_type);
        BRIMSTONE_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);

        success = SkipBytes(static_cast<size_t>(block_header.size) - sizeof(meta_type));
    }

    return success;
}

bool FileProcessor::IsFrameDelimiter(format::ApiCallId call_id) const
{
    // TODO: IDs of API calls that were treated as frame delimiters by the trace layer should be in the trace file
    // header.
    return (call_id == format::ApiCallId::ApiCall_vkQueuePresentKHR) ? true : false;
}

void FileProcessor::ProcessPendingCalls()
{
    while (!active_calls_.empty())
    {
        auto value = active_calls_.front();
        assert(value != nullptr);

        if (value->complete)
        {
            for (auto decoder : decoders_)
            {
                decoder->DecodeFunctionCall(value->call_id,
                                            value->pre_options,
                                            value->pre_buffer.data(),
                                            value->pre_buffer_size,
                                            value->post_options,
                                            value->post_buffer.data(),
                                            value->post_buffer_size);
            }

            active_calls_.pop_front();
            delete value;
        }
        else
        {
            break;
        }
    }
}

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)
