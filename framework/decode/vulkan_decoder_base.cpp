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

#include "decode/descriptor_update_template_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/value_decoder.h"
#include "decode/vulkan_decoder_base.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

void VulkanDecoderBase::DispatchDisplayMessageCommand(const std::string& message)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessDisplayMessageCommand(message);
    }
}

void VulkanDecoderBase::DispatchFillMemoryCommand(uint64_t       memory_id,
                                                  uint64_t       offset,
                                                  uint64_t       size,
                                                  const uint8_t* data)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessFillMemoryCommand(memory_id, offset, size, data);
    }
}

void VulkanDecoderBase::DispatchResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    for (auto consumer : consumers_)
    {
        consumer->ProcessResizeWindowCommand(surface_id, width, height);
    }
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplate(const uint8_t* param_buffer,
                                                                   size_t         param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pData.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplate(const uint8_t* pre_buffer,
                                                                   size_t         pre_buffer_size,
                                                                   const uint8_t* post_buffer,
                                                                   size_t         post_buffer_size)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(post_buffer);
    BRIMSTONE_UNREFERENCED_PARAMETER(post_buffer_size);

    size_t bytes_read = 0;

    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pData.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCmdPushDescriptorSetWithTemplateKHR(const uint8_t* param_buffer,
                                                                       size_t         param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                commandBuffer;
    format::HandleId                descriptorUpdateTemplate;
    format::HandleId                layout;
    uint32_t                        set;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &set);
    bytes_read += pData.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkCmdPushDescriptorSetWithTemplateKHR(
            commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkCmdPushDescriptorSetWithTemplateKHR(const uint8_t* pre_buffer,
                                                                       size_t         pre_buffer_size,
                                                                       const uint8_t* post_buffer,
                                                                       size_t         post_buffer_size)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(post_buffer);
    BRIMSTONE_UNREFERENCED_PARAMETER(post_buffer_size);

    size_t bytes_read = 0;

    format::HandleId                commandBuffer;
    format::HandleId                descriptorUpdateTemplate;
    format::HandleId                layout;
    uint32_t                        set;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &set);
    bytes_read += pData.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkCmdPushDescriptorSetWithTemplateKHR(
            commandBuffer, descriptorUpdateTemplate, layout, set, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplateKHR(const uint8_t* param_buffer,
                                                                      size_t         param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pData.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkUpdateDescriptorSetWithTemplateKHR(const uint8_t* pre_buffer,
                                                                      size_t         pre_buffer_size,
                                                                      const uint8_t* post_buffer,
                                                                      size_t         post_buffer_size)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(post_buffer);
    BRIMSTONE_UNREFERENCED_PARAMETER(post_buffer_size);

    size_t bytes_read = 0;

    format::HandleId                device;
    format::HandleId                descriptorSet;
    format::HandleId                descriptorUpdateTemplate;
    DescriptorUpdateTemplateDecoder pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorSet);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pData.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : consumers_)
    {
        consumer->Process_vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkRegisterObjectsNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                                    device;
    format::HandleId                                    objectTable;
    uint32_t                                            objectCount;
    StructPointerDecoder<Decoded_VkObjectTableEntryNVX> ppObjectTableEntries;
    PointerDecoder<uint32_t>                            pObjectIndices;
    VkResult                                            return_value;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &objectTable);
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &objectCount);
    bytes_read += ppObjectTableEntries.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pObjectIndices.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        consumer->Process_vkRegisterObjectsNVX(
            return_value, device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);
    }

    return bytes_read;
}

size_t VulkanDecoderBase::Decode_vkRegisterObjectsNVX(const uint8_t* pre_buffer,
                                                      size_t         pre_buffer_size,
                                                      const uint8_t* post_buffer,
                                                      size_t         post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                                    device;
    format::HandleId                                    objectTable;
    uint32_t                                            objectCount;
    StructPointerDecoder<Decoded_VkObjectTableEntryNVX> ppObjectTableEntries;
    PointerDecoder<uint32_t>                            pObjectIndices;
    VkResult                                            return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &objectTable);
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &objectCount);
    bytes_read += ppObjectTableEntries.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pObjectIndices.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read +=
        ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : consumers_)
    {
        consumer->Process_vkRegisterObjectsNVX(
            return_value, device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);
    }

    return bytes_read;
}

void VulkanDecoderBase::DecodeFunctionCall(format::ApiCallId             call_id,
                                           const format::ApiCallOptions& call_options,
                                           const uint8_t*                param_buffer,
                                           size_t                        param_buffer_size)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(call_options);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate:
            Decode_vkUpdateDescriptorSetWithTemplate(param_buffer, param_buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR:
            Decode_vkCmdPushDescriptorSetWithTemplateKHR(param_buffer, param_buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR:
            Decode_vkUpdateDescriptorSetWithTemplateKHR(param_buffer, param_buffer_size);
            break;
        case format::ApiCallId::ApiCall_vkRegisterObjectsNVX:
            Decode_vkRegisterObjectsNVX(param_buffer, param_buffer_size);
            break;
        default:
            break;
    }
}

void VulkanDecoderBase::DecodeFunctionCall(format::ApiCallId             call_id,
                                           const format::ApiCallOptions& pre_call_options,
                                           const uint8_t*                pre_call_buffer,
                                           size_t                        pre_call_size,
                                           const format::ApiCallOptions& post_call_options,
                                           const uint8_t*                post_call_buffer,
                                           size_t                        post_call_size)
{
    BRIMSTONE_UNREFERENCED_PARAMETER(pre_call_options);
    BRIMSTONE_UNREFERENCED_PARAMETER(post_call_options);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplate:
            Decode_vkUpdateDescriptorSetWithTemplate(pre_call_buffer, pre_call_size, post_call_buffer, post_call_size);
            break;
        case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetWithTemplateKHR:
            Decode_vkCmdPushDescriptorSetWithTemplateKHR(
                pre_call_buffer, pre_call_size, post_call_buffer, post_call_size);
            break;
        case format::ApiCallId::ApiCall_vkUpdateDescriptorSetWithTemplateKHR:
            Decode_vkUpdateDescriptorSetWithTemplateKHR(
                pre_call_buffer, pre_call_size, post_call_buffer, post_call_size);
            break;
        case format::ApiCallId::ApiCall_vkRegisterObjectsNVX:
            Decode_vkRegisterObjectsNVX(pre_call_buffer, pre_call_size, post_call_buffer, post_call_size);
            break;
        default:
            break;
    }
}

BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)
