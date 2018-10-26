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

#ifndef BRIMSTONE_DECODE_FILE_PROCESSOR_H
#define BRIMSTONE_DECODE_FILE_PROCESSOR_H

#include <algorithm>
#include <cstdio>
#include <deque>
#include <string>
#include <unordered_map>
#include <vector>

#include "util/defines.h"
#include "util/compressor.h"
#include "decode/api_decoder.h"
#include "format/api_call_id.h"
#include "format/format.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

class FileProcessor
{
  public:
    FileProcessor();

    ~FileProcessor();

    void AddDecoder(ApiDecoder* decoder) { decoders_.push_back(decoder); }

    void RemoveDecoder(ApiDecoder* decoder)
    {
        decoders_.erase(std::remove(decoders_.begin(), decoders_.end(), decoder), decoders_.end());
    }

    bool Initialize(const std::string& filename);

    bool ProcessNextFrame();

    bool ProcessAllFrames();

    const format::FileHeader& GetFileHeader() const { return file_header_; }

    const std::vector<format::FileOptionPair>& GetFileOptions() const { return file_options_; }

    uint64_t NumBytesRead() { return bytes_read_; }

  private:
    struct SplitApiCallInfo
    {
        uint32_t               thread_id{ 0 };
        bool                   complete{ false };
        format::ApiCallId      call_id{ format::ApiCallId::ApiCall_Unknown };
        format::ApiCallOptions pre_options;
        std::vector<uint8_t>   pre_buffer;
        size_t                 pre_buffer_size;
        format::ApiCallOptions post_options;
        std::vector<uint8_t>   post_buffer;
        size_t                 post_buffer_size;
    };

    typedef std::deque<SplitApiCallInfo*>                   ActiveCalls;
    typedef std::unordered_map<uint32_t, SplitApiCallInfo*> CurrentThreadCalls;

  private:
    bool ReadFileHeader();

    bool ReadBlockHeader(format::BlockHeader* block_header);

    bool ReadParameterBuffer(size_t buffer_size, std::vector<uint8_t>* parameter_buffer);

    bool ReadCompressedParameterBuffer(size_t                compressed_buffer_size,
                                       size_t                expected_uncompressed_size,
                                       size_t*               uncompressed_buffer_size,
                                       std::vector<uint8_t>* compressed_parameter_buffer,
                                       std::vector<uint8_t>* parameter_buffer);

    bool ReadBytes(void* buffer, size_t buffer_size);

    bool SkipBytes(uint64_t skip_size);

    bool ProcessFunctionCallUnified(const format::BlockHeader& block_header, format::ApiCallId call_id);

    bool ProcessFunctionCallPre(const format::BlockHeader& block_header, format::ApiCallId call_id);

    bool ProcessFunctionCallPost(const format::BlockHeader& block_header, format::ApiCallId call_id);

    bool ProcessFunctionCallCommon(const format::BlockHeader& block_header,
                                   format::ApiCallId          call_id,
                                   format::ApiCallOptions*    call_options,
                                   std::vector<uint8_t>*      parameter_buffer,
                                   size_t*                    parameter_buffer_size);

    bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataType meta_type);

    bool IsFrameDelimiter(format::ApiCallId call_id) const;

    bool IsFileHeaderValid() const { return (file_header_.fourcc == BRIMSTONE_FOURCC) ? true : false; }

    bool IsFileValid() const
    {
        return (file_descriptor_ && !feof(file_descriptor_) && !ferror(file_descriptor_)) ? true : false;
    }

    void ProcessPendingCalls();

  private:
    FILE*                               file_descriptor_;
    std::string                         filename_;
    format::FileHeader                  file_header_;
    std::vector<format::FileOptionPair> file_options_;
    format::EnabledOptions              enabled_options_;
    uint64_t                            bytes_read_;
    std::vector<ApiDecoder*>            decoders_;
    CurrentThreadCalls                  current_thread_calls_;
    ActiveCalls                         active_calls_;
    std::vector<uint8_t>                parameter_buffer_; // Single threaded parameter buffer.
    std::vector<uint8_t>                compressed_parameter_buffer_;
    util::Compressor*                   compressor_;
};

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_DECODE_FILE_PROCESSOR_H
