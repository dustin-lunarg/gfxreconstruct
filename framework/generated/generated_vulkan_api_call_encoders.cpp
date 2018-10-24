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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include <mutex>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/api_call_id.h"
#include "encode/custom_encoder_commands.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
#include "encode/parameter_encoder.h"
#include "layer/trace_layer.h"

#include "generated/generated_vulkan_api_call_encoders.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(encode::TraceManager::Get(), pCreateInfo, pAllocator, pInstance);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateInstance, encode::TraceManager::PreCall);
        if (encoder)
        {
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pInstance, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = dispatch_CreateInstance(pCreateInfo, pAllocator, pInstance);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateInstance, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pInstance, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(encode::TraceManager::Get(), result, pCreateInfo, pAllocator, pInstance);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(encode::TraceManager::Get(), instance, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyInstance, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_instance_table(instance)->DestroyInstance(instance, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyInstance, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(encode::TraceManager::Get(), instance, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceCount, pPhysicalDevices);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceCount, true);
        encoder->EncodeHandleIdArray(pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPhysicalDeviceCount, false);
        encoder->EncodeHandleIdArray(pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceCount, pPhysicalDevices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pFeatures, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pFormatProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encode_struct_ptr(encoder, pImageFormatProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pImageFormatProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount, true);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount, false);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(encode::TraceManager::Get(), physicalDevice, pCreateInfo, pAllocator, pDevice);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDevice, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(physicalDevice);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pDevice, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = dispatch_CreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDevice, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pDevice, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pCreateInfo, pAllocator, pDevice);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(encode::TraceManager::Get(), device, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDevice, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyDevice(device, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDevice, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(encode::TraceManager::Get(), device, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(encode::TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Value(queueIndex);
        encoder->EncodeHandleIdPtr(pQueue, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeHandleIdPtr(pQueue, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(encode::TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(encode::TraceManager::Get(), queue, submitCount, pSubmits, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueSubmit, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        encode_struct_array(encoder, pSubmits, submitCount, false);
        encoder->EncodeHandleIdValue(fence);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(queue)->QueueSubmit(queue, submitCount, pSubmits, fence);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueSubmit, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(encode::TraceManager::Get(), result, queue, submitCount, pSubmits, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(
    VkQueue                                     queue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(encode::TraceManager::Get(), queue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueWaitIdle, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(queue)->QueueWaitIdle(queue);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueWaitIdle, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(encode::TraceManager::Get(), result, queue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(
    VkDevice                                    device)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(encode::TraceManager::Get(), device);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDeviceWaitIdle, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->DeviceWaitIdle(device);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDeviceWaitIdle, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(encode::TraceManager::Get(), result, device);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pAllocator, pMemory);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateMemory, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pAllocateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pMemory, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateMemory, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pMemory, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pAllocator, pMemory);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(encode::TraceManager::Get(), device, memory, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeMemory, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(memory);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->FreeMemory(device, memory, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeMemory, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(encode::TraceManager::Get(), device, memory, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(encode::TraceManager::Get(), device, memory, offset, size, flags, ppData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMapMemory, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeVoidPtrPtr(ppData);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->MapMemory(device, memory, offset, size, flags, ppData);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMapMemory, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidPtrPtr(ppData);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(encode::TraceManager::Get(), result, device, memory, offset, size, flags, ppData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(encode::TraceManager::Get(), device, memory);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUnmapMemory, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->UnmapMemory(device, memory);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUnmapMemory, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(encode::TraceManager::Get(), device, memory);
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        encode_struct_array(encoder, pMemoryRanges, memoryRangeCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        encode_struct_array(encoder, pMemoryRanges, memoryRangeCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(encode::TraceManager::Get(), device, memory, pCommittedMemoryInBytes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizePtr(pCommittedMemoryInBytes, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVkDeviceSizePtr(pCommittedMemoryInBytes, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(encode::TraceManager::Get(), device, memory, pCommittedMemoryInBytes);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(encode::TraceManager::Get(), device, buffer, memory, memoryOffset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->BindBufferMemory(device, buffer, memory, memoryOffset);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(encode::TraceManager::Get(), result, device, buffer, memory, memoryOffset);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(encode::TraceManager::Get(), device, image, memory, memoryOffset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->BindImageMemory(device, image, memory, memoryOffset);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(encode::TraceManager::Get(), result, device, image, memory, memoryOffset);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, buffer, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        encode_struct_ptr(encoder, pMemoryRequirements, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryRequirements, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, buffer, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encode_struct_ptr(encoder, pMemoryRequirements, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetImageMemoryRequirements(device, image, pMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryRequirements, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount, true);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount, false);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties*              pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(samples);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(encode::TraceManager::Get(), queue, bindInfoCount, pBindInfo, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBindSparse, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfo, bindInfoCount, false);
        encoder->EncodeHandleIdValue(fence);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(queue)->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBindSparse, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(encode::TraceManager::Get(), result, queue, bindInfoCount, pBindInfo, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pFence);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateFence, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pFence, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateFence(device, pCreateInfo, pAllocator, pFence);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateFence, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pFence, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(encode::TraceManager::Get(), device, fence, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyFence, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(fence);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyFence(device, fence, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyFence, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(encode::TraceManager::Get(), device, fence, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(encode::TraceManager::Get(), device, fenceCount, pFences);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetFences, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleIdArray(pFences, fenceCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->ResetFences(device, fenceCount, pFences);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetFences, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(encode::TraceManager::Get(), result, device, fenceCount, pFences);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(encode::TraceManager::Get(), device, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceStatus, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(fence);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetFenceStatus(device, fence);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceStatus, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(encode::TraceManager::Get(), result, device, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(encode::TraceManager::Get(), device, fenceCount, pFences, waitAll, timeout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkWaitForFences, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleIdArray(pFences, fenceCount, false);
        encoder->EncodeVkBool32Value(waitAll);
        encoder->EncodeUInt64Value(timeout);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->WaitForFences(device, fenceCount, pFences, waitAll, timeout);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkWaitForFences, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(encode::TraceManager::Get(), result, device, fenceCount, pFences, waitAll, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSemaphore);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSemaphore, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSemaphore, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSemaphore, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSemaphore, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSemaphore);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(encode::TraceManager::Get(), device, semaphore, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySemaphore, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(semaphore);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroySemaphore(device, semaphore, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySemaphore, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(encode::TraceManager::Get(), device, semaphore, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pEvent);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateEvent, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pEvent, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateEvent(device, pCreateInfo, pAllocator, pEvent);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateEvent, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pEvent, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pEvent);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(encode::TraceManager::Get(), device, event, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyEvent, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(event);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyEvent(device, event, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyEvent, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(encode::TraceManager::Get(), device, event, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(encode::TraceManager::Get(), device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetEventStatus, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetEventStatus(device, event);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetEventStatus, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(encode::TraceManager::Get(), device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetEvent, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->SetEvent(device, event);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetEvent, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(encode::TraceManager::Get(), device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetEvent, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->ResetEvent(device, event);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetEvent, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pQueryPool);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateQueryPool, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pQueryPool, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateQueryPool, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pQueryPool, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pQueryPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(encode::TraceManager::Get(), device, queryPool, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyQueryPool, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(queryPool);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyQueryPool(device, queryPool, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyQueryPool, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(encode::TraceManager::Get(), device, queryPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(encode::TraceManager::Get(), device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueryPoolResults, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, true);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueryPoolResults, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidArray(pData, dataSize, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(encode::TraceManager::Get(), result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pBuffer);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateBuffer, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pBuffer, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateBuffer, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pBuffer, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pBuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(encode::TraceManager::Get(), device, buffer, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyBuffer, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(buffer);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyBuffer(device, buffer, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyBuffer, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(encode::TraceManager::Get(), device, buffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateBufferView, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pView, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateBufferView(device, pCreateInfo, pAllocator, pView);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateBufferView, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pView, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(encode::TraceManager::Get(), device, bufferView, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyBufferView, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(bufferView);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyBufferView(device, bufferView, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyBufferView, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(encode::TraceManager::Get(), device, bufferView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pImage);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImage, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pImage, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateImage(device, pCreateInfo, pAllocator, pImage);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImage, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pImage, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pImage);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(encode::TraceManager::Get(), device, image, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyImage, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(image);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyImage(device, image, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyImage, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(encode::TraceManager::Get(), device, image, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(encode::TraceManager::Get(), device, image, pSubresource, pLayout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encode_struct_ptr(encoder, pSubresource, false);
        encode_struct_ptr(encoder, pLayout, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetImageSubresourceLayout(device, image, pSubresource, pLayout);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pLayout, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(encode::TraceManager::Get(), device, image, pSubresource, pLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImageView, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pView, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateImageView(device, pCreateInfo, pAllocator, pView);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImageView, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pView, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(encode::TraceManager::Get(), device, imageView, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyImageView, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(imageView);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyImageView(device, imageView, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyImageView, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(encode::TraceManager::Get(), device, imageView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pShaderModule);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateShaderModule, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pShaderModule, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateShaderModule, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pShaderModule, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pShaderModule);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(encode::TraceManager::Get(), device, shaderModule, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyShaderModule, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(shaderModule);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyShaderModule(device, shaderModule, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyShaderModule, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(encode::TraceManager::Get(), device, shaderModule, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineCache);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineCache, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pPipelineCache, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineCache, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pPipelineCache, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipelineCache, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineCache);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyPipelineCache(device, pipelineCache, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipelineCache, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pDataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPipelineCacheData, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeSizeTPtr(pDataSize, true);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetPipelineCacheData(device, pipelineCache, pDataSize, pData);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPipelineCacheData, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeSizeTPtr(pDataSize, false);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches(
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(encode::TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergePipelineCaches, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleIdArray(pSrcCaches, srcCacheCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergePipelineCaches, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(encode::TraceManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineCache);
            encoder->EncodeUInt32Value(createInfoCount);
            encode_struct_array(encoder, pCreateInfos, createInfoCount, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdArray(pPipelines, createInfoCount, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdArray(pPipelines, createInfoCount, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateComputePipelines, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineCache);
            encoder->EncodeUInt32Value(createInfoCount);
            encode_struct_array(encoder, pCreateInfos, createInfoCount, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdArray(pPipelines, createInfoCount, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateComputePipelines, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdArray(pPipelines, createInfoCount, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(encode::TraceManager::Get(), device, pipeline, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipeline, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipeline);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyPipeline(device, pipeline, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipeline, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(encode::TraceManager::Get(), device, pipeline, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineLayout);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineLayout, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pPipelineLayout, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineLayout, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pPipelineLayout, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pipelineLayout, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipelineLayout, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineLayout);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyPipelineLayout(device, pipelineLayout, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipelineLayout, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pipelineLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSampler);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSampler, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSampler, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateSampler(device, pCreateInfo, pAllocator, pSampler);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSampler, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSampler, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSampler);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(encode::TraceManager::Get(), device, sampler, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySampler, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(sampler);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroySampler(device, sampler, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySampler, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(encode::TraceManager::Get(), device, sampler, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSetLayout);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSetLayout, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSetLayout, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSetLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, descriptorSetLayout, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorSetLayout);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, descriptorSetLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorPool);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorPool, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pDescriptorPool, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorPool, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pDescriptorPool, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorPool, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorPool);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyDescriptorPool(device, descriptorPool, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorPool, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetDescriptorPool, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorPool);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->ResetDescriptorPool(device, descriptorPool, flags);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetDescriptorPool, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(encode::TraceManager::Get(), result, device, descriptorPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pDescriptorSets);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateDescriptorSets, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pAllocateInfo, false);
            encoder->EncodeHandleIdArray(pDescriptorSets, pAllocateInfo->descriptorSetCount, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateDescriptorSets, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdArray(pDescriptorSets, pAllocateInfo->descriptorSetCount, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pDescriptorSets);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, descriptorSetCount, pDescriptorSets);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeDescriptorSets, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorPool);
            encoder->EncodeUInt32Value(descriptorSetCount);
            encoder->EncodeHandleIdArray(pDescriptorSets, descriptorSetCount, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeDescriptorSets, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(encode::TraceManager::Get(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const VkCopyDescriptorSet*                  pDescriptorCopies)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUpdateDescriptorSets, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        encode_struct_array(encoder, pDescriptorWrites, descriptorWriteCount, false);
        encoder->EncodeUInt32Value(descriptorCopyCount);
        encode_struct_array(encoder, pDescriptorCopies, descriptorCopyCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUpdateDescriptorSets, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pFramebuffer);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateFramebuffer, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pFramebuffer, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateFramebuffer, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pFramebuffer, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pFramebuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(encode::TraceManager::Get(), device, framebuffer, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyFramebuffer, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(framebuffer);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyFramebuffer(device, framebuffer, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyFramebuffer, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(encode::TraceManager::Get(), device, framebuffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pRenderPass, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pRenderPass, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(encode::TraceManager::Get(), device, renderPass, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyRenderPass, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(renderPass);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyRenderPass(device, renderPass, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyRenderPass, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(encode::TraceManager::Get(), device, renderPass, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(encode::TraceManager::Get(), device, renderPass, pGranularity);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(renderPass);
        encode_struct_ptr(encoder, pGranularity, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetRenderAreaGranularity(device, renderPass, pGranularity);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pGranularity, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(encode::TraceManager::Get(), device, renderPass, pGranularity);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pCommandPool);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateCommandPool, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pCommandPool, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateCommandPool, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pCommandPool, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pCommandPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyCommandPool, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(commandPool);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyCommandPool(device, commandPool, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyCommandPool, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandPool, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->ResetCommandPool(device, commandPool, flags);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandPool, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(encode::TraceManager::Get(), result, device, commandPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pCommandBuffers);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateCommandBuffers, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pAllocateInfo, false);
            encoder->EncodeHandleIdArray(pCommandBuffers, pAllocateInfo->commandBufferCount, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateCommandBuffers, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdArray(pCommandBuffers, pAllocateInfo->commandBufferCount, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pCommandBuffers);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeCommandBuffers, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(commandPool);
            encoder->EncodeUInt32Value(commandBufferCount);
            encoder->EncodeHandleIdArray(pCommandBuffers, commandBufferCount, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeCommandBuffers, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, pBeginInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBeginCommandBuffer, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pBeginInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(commandBuffer)->BeginCommandBuffer(commandBuffer, pBeginInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBeginCommandBuffer, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer, pBeginInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEndCommandBuffer, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(commandBuffer)->EndCommandBuffer(commandBuffer);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEndCommandBuffer, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandBuffer, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(commandBuffer)->ResetCommandBuffer(commandBuffer, flags);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandBuffer, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer, flags);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindPipeline, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(pipeline);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindPipeline, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewport, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        encode_struct_array(encoder, pViewports, viewportCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewport, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetScissor, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstScissor);
        encoder->EncodeUInt32Value(scissorCount);
        encode_struct_array(encoder, pScissors, scissorCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetScissor, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(encode::TraceManager::Get(), commandBuffer, lineWidth);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetLineWidth, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(lineWidth);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetLineWidth(commandBuffer, lineWidth);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetLineWidth, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(encode::TraceManager::Get(), commandBuffer, lineWidth);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(encode::TraceManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBias, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(depthBiasConstantFactor);
        encoder->EncodeFloatValue(depthBiasClamp);
        encoder->EncodeFloatValue(depthBiasSlopeFactor);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBias, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(encode::TraceManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4])
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, blendConstants);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetBlendConstants, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatArray(blendConstants, 4, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetBlendConstants(commandBuffer, blendConstants);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetBlendConstants, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, blendConstants);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(encode::TraceManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBounds, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(minDepthBounds);
        encoder->EncodeFloatValue(maxDepthBounds);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBounds, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(encode::TraceManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, compareMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(compareMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, compareMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, writeMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(writeMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, writeMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, reference);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilReference, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(reference);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetStencilReference(commandBuffer, faceMask, reference);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilReference, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, reference);
}

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(firstSet);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleIdArray(pDescriptorSets, descriptorSetCount, false);
        encoder->EncodeUInt32Value(dynamicOffsetCount);
        encoder->EncodeUInt32Array(pDynamicOffsets, dynamicOffsetCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, indexType);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeEnumValue(indexType);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, indexType);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleIdArray(pBuffers, bindingCount, false);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(encode::TraceManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDraw, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(vertexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstVertex);
        encoder->EncodeUInt32Value(firstInstance);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDraw, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(encode::TraceManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(encode::TraceManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexed, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(indexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstIndex);
        encoder->EncodeInt32Value(vertexOffset);
        encoder->EncodeUInt32Value(firstInstance);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexed, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(encode::TraceManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirect, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirect, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(encode::TraceManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatch, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatch, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(encode::TraceManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchIndirect, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDispatchIndirect(commandBuffer, buffer, offset);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchIndirect, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyBuffer, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyBuffer, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyImage, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyImage, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBlitImage, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount, false);
        encoder->EncodeEnumValue(filter);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBlitImage, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcBuffer);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdUpdateBuffer, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdUpdateBuffer, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdFillBuffer, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeUInt32Value(data);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdFillBuffer, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearColorImage, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeEnumValue(imageLayout);
        encode_struct_ptr(encoder, pColor, false);
        encoder->EncodeUInt32Value(rangeCount);
        encode_struct_array(encoder, pRanges, rangeCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearColorImage, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeEnumValue(imageLayout);
        encode_struct_ptr(encoder, pDepthStencil, false);
        encoder->EncodeUInt32Value(rangeCount);
        encode_struct_array(encoder, pRanges, rangeCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(encode::TraceManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearAttachments, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(attachmentCount);
        encode_struct_array(encoder, pAttachments, attachmentCount, false);
        encoder->EncodeUInt32Value(rectCount);
        encode_struct_array(encoder, pRects, rectCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearAttachments, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(encode::TraceManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResolveImage, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResolveImage, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetEvent, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeFlagsValue(stageMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetEvent(commandBuffer, event, stageMask);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetEvent, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResetEvent, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeFlagsValue(stageMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdResetEvent(commandBuffer, event, stageMask);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResetEvent, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(encode::TraceManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWaitEvents, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(eventCount);
        encoder->EncodeHandleIdArray(pEvents, eventCount, false);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        encode_struct_array(encoder, pMemoryBarriers, memoryBarrierCount, false);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        encode_struct_array(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount, false);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        encode_struct_array(encoder, pImageMemoryBarriers, imageMemoryBarrierCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWaitEvents, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(encode::TraceManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPipelineBarrier, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeFlagsValue(dependencyFlags);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        encode_struct_array(encoder, pMemoryBarriers, memoryBarrierCount, false);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        encode_struct_array(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount, false);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        encode_struct_array(encoder, pImageMemoryBarriers, imageMemoryBarrierCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPipelineBarrier, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginQuery, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBeginQuery(commandBuffer, queryPool, query, flags);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginQuery, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndQuery, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdEndQuery(commandBuffer, queryPool, query);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndQuery, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResetQueryPool, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResetQueryPool, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, queryPool, query);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteTimestamp, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteTimestamp, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushConstants, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeFlagsValue(stageFlags);
        encoder->EncodeUInt32Value(offset);
        encoder->EncodeUInt32Value(size);
        encoder->EncodeVoidArray(pValues, size, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushConstants, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, contents);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pRenderPassBegin, false);
        encoder->EncodeEnumValue(contents);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(encode::TraceManager::Get(), commandBuffer, contents);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(contents);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdNextSubpass(commandBuffer, contents);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(encode::TraceManager::Get(), commandBuffer, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdEndRenderPass(commandBuffer);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(encode::TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdExecuteCommands, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleIdArray(pCommandBuffers, commandBufferCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdExecuteCommands, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(encode::TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->BindBufferMemory2(device, bindInfoCount, pBindInfos);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->BindImageMemory2(device, bindInfoCount, pBindInfos);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDeviceMask, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetDeviceMask(commandBuffer, deviceMask);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDeviceMask, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchBase, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchBase, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount, true);
        encode_struct_array(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount, false);
        encode_struct_array(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encode_struct_ptr(encoder, pMemoryRequirements, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryRequirements, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encode_struct_ptr(encoder, pMemoryRequirements, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryRequirements, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount, true);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount, false);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pFeatures, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pFormatProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pImageFormatInfo, false);
        encode_struct_ptr(encoder, pImageFormatProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pImageFormatProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount, true);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount, false);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFormatInfo, false);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkTrimCommandPool, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->TrimCommandPool(device, commandPool, flags);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkTrimCommandPool, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(encode::TraceManager::Get(), device, pQueueInfo, pQueue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue2, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pQueueInfo, false);
        encoder->EncodeHandleIdPtr(pQueue, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetDeviceQueue2(device, pQueueInfo, pQueue);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue2, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeHandleIdPtr(pQueue, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(encode::TraceManager::Get(), device, pQueueInfo, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pYcbcrConversion, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pYcbcrConversion, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(ycbcrConversion);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalBufferInfo, false);
        encode_struct_ptr(encoder, pExternalBufferProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pExternalBufferProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalFenceInfo, false);
        encode_struct_ptr(encoder, pExternalFenceProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pExternalFenceProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalSemaphoreInfo, false);
        encode_struct_ptr(encoder, pExternalSemaphoreProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pExternalSemaphoreProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pCreateInfo, false);
        encode_struct_ptr(encoder, pSupport, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pSupport, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, surface, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySurfaceKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encoder->EncodeHandleIdValue(surface);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_instance_table(instance)->DestroySurfaceKHR(instance, surface, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySurfaceKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, surface, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, surface, pSupported);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeVkBool32Ptr(pSupported, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVkBool32Ptr(pSupported, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, surface, pSupported);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encode_struct_ptr(encoder, pSurfaceCapabilities, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pSurfaceCapabilities, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount, true);
        encode_struct_array(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount, false);
        encode_struct_array(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pPresentModeCount, pPresentModes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pPresentModeCount, true);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPresentModeCount, false);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pPresentModeCount, pPresentModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSwapchain);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSwapchainKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSwapchain, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSwapchainKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSwapchain, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSwapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySwapchainKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(swapchain);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroySwapchainKHR(device, swapchain, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySwapchainKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pSwapchainImageCount, pSwapchainImages);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt32Ptr(pSwapchainImageCount, true);
        encoder->EncodeHandleIdArray(pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pSwapchainImageCount, false);
        encoder->EncodeHandleIdArray(pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pSwapchainImageCount, pSwapchainImages);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, timeout, semaphore, fence, pImageIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImageKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeHandleIdValue(semaphore);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeUInt32Ptr(pImageIndex, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImageKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pImageIndex, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, timeout, semaphore, fence, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(encode::TraceManager::Get(), queue, pPresentInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueuePresentKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode_struct_ptr(encoder, pPresentInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(queue)->QueuePresentKHR(queue, pPresentInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueuePresentKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(encode::TraceManager::Get(), result, queue, pPresentInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR(
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), device, pDeviceGroupPresentCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pDeviceGroupPresentCapabilities, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pDeviceGroupPresentCapabilities, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, pDeviceGroupPresentCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), device, surface, pModes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeFlagsPtr(pModes, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeFlagsPtr(pModes, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), result, device, surface, pModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pRectCount, pRects);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pRectCount, true);
        encode_struct_array(encoder, pRects, (pRectCount != nullptr) ? (*pRectCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pRectCount, false);
        encode_struct_array(encoder, pRects, (pRectCount != nullptr) ? (*pRectCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pRectCount, pRects);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(encode::TraceManager::Get(), device, pAcquireInfo, pImageIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pAcquireInfo, false);
        encoder->EncodeUInt32Ptr(pImageIndex, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pImageIndex, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(encode::TraceManager::Get(), result, device, pAcquireInfo, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, planeIndex, pDisplayCount, pDisplays);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(planeIndex);
        encoder->EncodeUInt32Ptr(pDisplayCount, true);
        encoder->EncodeHandleIdArray(pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pDisplayCount, false);
        encoder->EncodeHandleIdArray(pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, planeIndex, pDisplayCount, pDisplays);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pCreateInfo, pAllocator, pMode);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(physicalDevice);
            encoder->EncodeHandleIdValue(display);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pMode, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(physicalDevice)->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pMode, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pCreateInfo, pAllocator, pMode);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, mode, planeIndex, pCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(mode);
        encoder->EncodeUInt32Value(planeIndex);
        encode_struct_ptr(encoder, pCapabilities, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pCapabilities, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, mode, planeIndex, pCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeUInt32Value(swapchainCount);
            encode_struct_array(encoder, pCreateInfos, swapchainCount, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdArray(pSwapchains, swapchainCount, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdArray(pSwapchains, swapchainCount, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    return result;
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, dpy, visualID);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(visualID);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, dpy, visualID);

    return result;
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, connection, visual_id);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(connection);
        encoder->EncodeUInt32Value(visual_id);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, connection, visual_id);

    return result;
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(display);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, display);

    return result;
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateMirSurfaceKHR(
    VkInstance                                  instance,
    const VkMirSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateMirSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceMirPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    MirConnection*                              connection)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, connection);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(connection);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceMirPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, connection);

    return result;
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pFeatures, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pFormatProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pImageFormatInfo, false);
        encode_struct_ptr(encoder, pImageFormatProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pImageFormatProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount, true);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount, false);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFormatInfo, false);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer, deviceMask);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->TrimCommandPoolKHR(device, commandPool, flags);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount, true);
        encode_struct_array(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(instance)->EnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount, false);
        encode_struct_array(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalBufferInfo, false);
        encode_struct_ptr(encoder, pExternalBufferProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pExternalBufferProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR(
    VkDevice                                    device,
    const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo, false);
        encoder->EncodeVoidPtrPtr(pHandle);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(encode::TraceManager::Get(), device, handleType, handle, pMemoryWin32HandleProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(handle);
        encode_struct_ptr(encoder, pMemoryWin32HandleProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryWin32HandleProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, handleType, handle, pMemoryWin32HandleProperties);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetFdInfo, false);
        encoder->EncodeInt32Ptr(pFd, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetMemoryFdKHR(device, pGetFdInfo, pFd);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeInt32Ptr(pFd, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(encode::TraceManager::Get(), device, handleType, fd, pMemoryFdProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeInt32Value(fd);
        encode_struct_ptr(encoder, pMemoryFdProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryFdProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, handleType, fd, pMemoryFdProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalSemaphoreInfo, false);
        encode_struct_ptr(encoder, pExternalSemaphoreProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pExternalSemaphoreProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pImportSemaphoreWin32HandleInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pImportSemaphoreWin32HandleInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->ImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportSemaphoreWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo, false);
        encoder->EncodeVoidPtrPtr(pHandle);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), device, pImportSemaphoreFdInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pImportSemaphoreFdInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportSemaphoreFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetFdInfo, false);
        encoder->EncodeInt32Ptr(pFd, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeInt32Ptr(pFd, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(set);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        encode_struct_array(encoder, pDescriptorWrites, descriptorWriteCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2KHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pRenderPass, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pRenderPass, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pRenderPassBegin, false);
        encode_struct_ptr(encoder, pSubpassBeginInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pSubpassBeginInfo, false);
        encode_struct_ptr(encoder, pSubpassEndInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassEndInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pSubpassEndInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetSwapchainStatusKHR(device, swapchain);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalFenceInfo, false);
        encode_struct_ptr(encoder, pExternalFenceProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pExternalFenceProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pImportFenceWin32HandleInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pImportFenceWin32HandleInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->ImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportFenceWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo, false);
        encoder->EncodeVoidPtrPtr(pHandle);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(encode::TraceManager::Get(), device, pImportFenceFdInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceFdKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pImportFenceFdInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->ImportFenceFdKHR(device, pImportFenceFdInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceFdKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportFenceFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceFdKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetFdInfo, false);
        encoder->EncodeInt32Ptr(pFd, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetFenceFdKHR(device, pGetFdInfo, pFd);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceFdKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeInt32Ptr(pFd, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pSurfaceInfo, false);
        encode_struct_ptr(encoder, pSurfaceCapabilities, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pSurfaceCapabilities, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pSurfaceInfo, false);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount, true);
        encode_struct_array(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount, false);
        encode_struct_array(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayProperties2KHR*                    pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModeProperties2KHR*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount, true);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPropertyCount, false);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pDisplayPlaneInfo, pCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pDisplayPlaneInfo, false);
        encode_struct_ptr(encoder, pCapabilities, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pCapabilities, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pDisplayPlaneInfo, pCapabilities);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encode_struct_ptr(encoder, pMemoryRequirements, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryRequirements, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encode_struct_ptr(encoder, pMemoryRequirements, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryRequirements, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount, true);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount, false);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pYcbcrConversion, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pYcbcrConversion, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(ycbcrConversion);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->BindBufferMemory2KHR(device, bindInfoCount, pBindInfos);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2KHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->BindImageMemory2KHR(device, bindInfoCount, pBindInfos);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2KHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pCreateInfo, false);
        encode_struct_ptr(encoder, pSupport, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pSupport, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pCallback);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pCallback, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pCallback, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pCallback);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, callback, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encoder->EncodeHandleIdValue(callback);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_instance_table(instance)->DestroyDebugReportCallbackEXT(instance, callback, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, callback, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT(
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const char*                                 pLayerPrefix,
    const char*                                 pMessage)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugReportMessageEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(object);
        encoder->EncodeSizeTValue(location);
        encoder->EncodeInt32Value(messageCode);
        encoder->EncodeString(pLayerPrefix, false);
        encoder->EncodeString(pMessage, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(instance)->DebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugReportMessageEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(encode::TraceManager::Get(), device, pTagInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pTagInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(encode::TraceManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(encode::TraceManager::Get(), device, pNameInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pNameInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(encode::TraceManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pMarkerInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pMarkerInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    size_t*                                     pInfoSize,
    void*                                       pInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(encode::TraceManager::Get(), device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetShaderInfoAMD, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeEnumValue(shaderStage);
        encoder->EncodeEnumValue(infoType);
        encoder->EncodeSizeTPtr(pInfoSize, true);
        encoder->EncodeVoidArray(pInfo, (pInfoSize != nullptr) ? (*pInfoSize) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetShaderInfoAMD, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeSizeTPtr(pInfoSize, false);
        encoder->EncodeVoidArray(pInfo, (pInfoSize != nullptr) ? (*pInfoSize) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(encode::TraceManager::Get(), result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    VkExternalImageFormatPropertiesNV*          pExternalImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeFlagsValue(externalHandleType);
        encode_struct_ptr(encoder, pExternalImageFormatProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pExternalImageFormatProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    return result;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(encode::TraceManager::Get(), device, memory, handleType, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeFlagsValue(handleType);
        encoder->EncodeVoidPtrPtr(pHandle);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetMemoryWin32HandleNV(device, memory, handleType, pHandle);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(encode::TraceManager::Get(), result, device, memory, handleType, pHandle);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_VI_NN
VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN(
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateViSurfaceNN, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateViSurfaceNN, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_VI_NN */

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pConditionalRenderingBegin, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);
}

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdProcessCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdProcessCommandsInfoNVX*          pProcessCommandsInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pProcessCommandsInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pProcessCommandsInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pProcessCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdReserveSpaceForCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdReserveSpaceForCommandsInfoNVX*  pReserveSpaceInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pReserveSpaceInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pReserveSpaceInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pReserveSpaceInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNVX* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNVX*                pIndirectCommandsLayout)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pIndirectCommandsLayout, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateIndirectCommandsLayoutNVX(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pIndirectCommandsLayout, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNVX                 indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, indirectCommandsLayout, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(indirectCommandsLayout);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, indirectCommandsLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateObjectTableNVX(
    VkDevice                                    device,
    const VkObjectTableCreateInfoNVX*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkObjectTableNVX*                           pObjectTable)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pObjectTable);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateObjectTableNVX, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pObjectTable, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateObjectTableNVX(device, pCreateInfo, pAllocator, pObjectTable);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateObjectTableNVX, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pObjectTable, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pObjectTable);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyObjectTableNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyObjectTableNVX, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(objectTable);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyObjectTableNVX(device, objectTable, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyObjectTableNVX, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL UnregisterObjectsNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const VkObjectEntryTypeNVX*                 pObjectEntryTypes,
    const uint32_t*                             pObjectIndices)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUnregisterObjectsNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(objectTable);
        encoder->EncodeUInt32Value(objectCount);
        encoder->EncodeEnumArray(pObjectEntryTypes, objectCount, false);
        encoder->EncodeUInt32Array(pObjectIndices, objectCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->UnregisterObjectsNVX(device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUnregisterObjectsNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(encode::TraceManager::Get(), result, device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    VkPhysicalDevice                            physicalDevice,
    VkDeviceGeneratedCommandsFeaturesNVX*       pFeatures,
    VkDeviceGeneratedCommandsLimitsNVX*         pLimits)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures, pLimits);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures, true);
        encode_struct_ptr(encoder, pLimits, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pFeatures, false);
        encode_struct_ptr(encoder, pLimits, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures, pLimits);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        encode_struct_array(encoder, pViewportWScalings, viewportCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkReleaseDisplayEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->ReleaseDisplayEXT(physicalDevice, display);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkReleaseDisplayEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display);

    return result;
}

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    VkDisplayKHR                                display)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, dpy, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeHandleIdValue(display);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice, dpy, display);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, dpy, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, dpy, rrOutput, pDisplay);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(rrOutput);
        encoder->EncodeHandleIdPtr(pDisplay, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeHandleIdPtr(pDisplay, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, dpy, rrOutput, pDisplay);

    return result;
}
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encode_struct_ptr(encoder, pSurfaceCapabilities, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pSurfaceCapabilities, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(encode::TraceManager::Get(), device, display, pDisplayPowerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(display);
        encode_struct_ptr(encoder, pDisplayPowerInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(encode::TraceManager::Get(), result, device, display, pDisplayPowerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(encode::TraceManager::Get(), device, pDeviceEventInfo, pAllocator, pFence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pDeviceEventInfo, false);
        encode_struct_ptr(encoder, pAllocator, false);
        encoder->EncodeHandleIdPtr(pFence, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeHandleIdPtr(pFence, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(encode::TraceManager::Get(), result, device, pDeviceEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(encode::TraceManager::Get(), device, display, pDisplayEventInfo, pAllocator, pFence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(display);
        encode_struct_ptr(encoder, pDisplayEventInfo, false);
        encode_struct_ptr(encoder, pAllocator, false);
        encoder->EncodeHandleIdPtr(pFence, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeHandleIdPtr(pFence, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(encode::TraceManager::Get(), result, device, display, pDisplayEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(encode::TraceManager::Get(), device, swapchain, counter, pCounterValue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeEnumValue(counter);
        encoder->EncodeUInt64Ptr(pCounterValue, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt64Ptr(pCounterValue, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, counter, pCounterValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(encode::TraceManager::Get(), device, swapchain, pDisplayTimingProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encode_struct_ptr(encoder, pDisplayTimingProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pDisplayTimingProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pDisplayTimingProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pPresentationTimingCount,
    VkPastPresentationTimingGOOGLE*             pPresentationTimings)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(encode::TraceManager::Get(), device, swapchain, pPresentationTimingCount, pPresentationTimings);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt32Ptr(pPresentationTimingCount, true);
        encode_struct_array(encoder, pPresentationTimings, (pPresentationTimingCount != nullptr) ? (*pPresentationTimingCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pPresentationTimingCount, false);
        encode_struct_array(encoder, pPresentationTimings, (pPresentationTimingCount != nullptr) ? (*pPresentationTimingCount) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pPresentationTimingCount, pPresentationTimings);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstDiscardRectangle);
        encoder->EncodeUInt32Value(discardRectangleCount);
        encode_struct_array(encoder, pDiscardRectangles, discardRectangleCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetHdrMetadataEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        encoder->EncodeHandleIdArray(pSwapchains, swapchainCount, false);
        encode_struct_array(encoder, pMetadata, swapchainCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetHdrMetadataEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);
}

#ifdef VK_USE_PLATFORM_IOS_MVK
VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_MACOS_MVK */

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(encode::TraceManager::Get(), device, pNameInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pNameInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(encode::TraceManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectTagInfoEXT*         pTagInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(encode::TraceManager::Get(), device, pTagInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pTagInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(encode::TraceManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode_struct_ptr(encoder, pLabelInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(queue)->QueueEndDebugUtilsLabelEXT(queue);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue);
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode_struct_ptr(encoder, pLabelInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pLabelInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pLabelInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pMessenger);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pMessenger, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pMessenger, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pMessenger);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, messenger, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encoder->EncodeHandleIdValue(messenger);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_instance_table(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, messenger, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeEnumValue(messageSeverity);
        encoder->EncodeFlagsValue(messageTypes);
        encode_struct_ptr(encoder, pCallbackData, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(encode::TraceManager::Get(), device, buffer, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeVoidPtr(buffer);
        encode_struct_ptr(encoder, pProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(encode::TraceManager::Get(), result, device, buffer, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID(
    VkDevice                                    device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
    struct AHardwareBuffer**                    pBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(encode::TraceManager::Get(), device, pInfo, pBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encoder->EncodeVoidPtrPtr(pBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidPtrPtr(pBuffer);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(encode::TraceManager::Get(), result, device, pInfo, pBuffer);

    return result;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSampleLocationsInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pSampleLocationsInfo, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSampleLocationsInfo);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(samples);
        encode_struct_ptr(encoder, pMultisampleProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_instance_table(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMultisampleProperties, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pValidationCache);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pValidationCache, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pValidationCache, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pValidationCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(validationCache);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyValidationCacheEXT(device, validationCache, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(encode::TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleIdArray(pSrcCaches, srcCacheCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->MergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(encode::TraceManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pDataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(validationCache);
        encoder->EncodeSizeTPtr(pDataSize, true);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetValidationCacheDataEXT(device, validationCache, pDataSize, pData);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeSizeTPtr(pDataSize, false);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(encode::TraceManager::Get(), result, device, validationCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, imageView, imageLayout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(imageView);
        encoder->EncodeEnumValue(imageLayout);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, imageView, imageLayout);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        encode_struct_array(encoder, pShadingRatePalettes, viewportCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(sampleOrderType);
        encoder->EncodeUInt32Value(customSampleOrderCount);
        encode_struct_array(encoder, pCustomSampleOrders, customSampleOrderCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNVX(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoNVX* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureNVX*                 pAccelerationStructure)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNVX>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pAccelerationStructure);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateAccelerationStructureNVX, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pAccelerationStructure, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateAccelerationStructureNVX(device, pCreateInfo, pAllocator, pAccelerationStructure);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateAccelerationStructureNVX, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pAccelerationStructure, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNVX>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNVX(
    VkDevice                                    device,
    VkAccelerationStructureNVX                  accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNVX>::Dispatch(encode::TraceManager::Get(), device, accelerationStructure, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNVX, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(accelerationStructure);
            encode_struct_ptr(encoder, pAllocator, false);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        get_device_table(device)->DestroyAccelerationStructureNVX(device, accelerationStructure, pAllocator);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNVX, encode::TraceManager::PostCall);
        if (encoder)
        {
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNVX>::Dispatch(encode::TraceManager::Get(), device, accelerationStructure, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNVX(
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoNVX* pInfo,
    VkMemoryRequirements2KHR*                   pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNVX>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encode_struct_ptr(encoder, pMemoryRequirements, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetAccelerationStructureMemoryRequirementsNVX(device, pInfo, pMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryRequirements, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNVX>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureScratchMemoryRequirementsNVX(
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoNVX* pInfo,
    VkMemoryRequirements2KHR*                   pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureScratchMemoryRequirementsNVX>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureScratchMemoryRequirementsNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo, false);
        encode_struct_ptr(encoder, pMemoryRequirements, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(device)->GetAccelerationStructureScratchMemoryRequirementsNVX(device, pInfo, pMemoryRequirements);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureScratchMemoryRequirementsNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryRequirements, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureScratchMemoryRequirementsNVX>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNVX(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindAccelerationStructureMemoryInfoNVX* pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNVX>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->BindAccelerationStructureMemoryNVX(device, bindInfoCount, pBindInfos);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNVX>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNVX(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureTypeNVX              type,
    uint32_t                                    instanceCount,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    uint32_t                                    geometryCount,
    const VkGeometryNVX*                        pGeometries,
    VkBuildAccelerationStructureFlagsNVX        flags,
    VkBool32                                    update,
    VkAccelerationStructureNVX                  dst,
    VkAccelerationStructureNVX                  src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, type, instanceCount, instanceData, instanceOffset, geometryCount, pGeometries, flags, update, dst, src, scratch, scratchOffset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(type);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeHandleIdValue(instanceData);
        encoder->EncodeVkDeviceSizeValue(instanceOffset);
        encoder->EncodeUInt32Value(geometryCount);
        encode_struct_array(encoder, pGeometries, geometryCount, false);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeVkBool32Value(update);
        encoder->EncodeHandleIdValue(dst);
        encoder->EncodeHandleIdValue(src);
        encoder->EncodeHandleIdValue(scratch);
        encoder->EncodeVkDeviceSizeValue(scratchOffset);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdBuildAccelerationStructureNVX(commandBuffer, type, instanceCount, instanceData, instanceOffset, geometryCount, pGeometries, flags, update, dst, src, scratch, scratchOffset);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, type, instanceCount, instanceData, instanceOffset, geometryCount, pGeometries, flags, update, dst, src, scratch, scratchOffset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNVX(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNVX                  dst,
    VkAccelerationStructureNVX                  src,
    VkCopyAccelerationStructureModeNVX          mode)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, dst, src, mode);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dst);
        encoder->EncodeHandleIdValue(src);
        encoder->EncodeEnumValue(mode);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdCopyAccelerationStructureNVX(commandBuffer, dst, src, mode);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, dst, src, mode);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNVX(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, width, height);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdTraceRaysNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(raygenShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(raygenShaderBindingOffset);
        encoder->EncodeHandleIdValue(missShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(missShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(missShaderBindingStride);
        encoder->EncodeHandleIdValue(hitShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(hitShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(hitShaderBindingStride);
        encoder->EncodeUInt32Value(width);
        encoder->EncodeUInt32Value(height);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdTraceRaysNVX(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, width, height);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdTraceRaysNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, width, height);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRaytracingPipelinesNVX(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRaytracingPipelineCreateInfoNVX*    pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRaytracingPipelinesNVX>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRaytracingPipelinesNVX, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineCache);
            encoder->EncodeUInt32Value(createInfoCount);
            encode_struct_array(encoder, pCreateInfos, createInfoCount, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdArray(pPipelines, createInfoCount, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_device_table(device)->CreateRaytracingPipelinesNVX(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRaytracingPipelinesNVX, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdArray(pPipelines, createInfoCount, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRaytracingPipelinesNVX>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRaytracingShaderHandlesNVX(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRaytracingShaderHandlesNVX>::Dispatch(encode::TraceManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRaytracingShaderHandlesNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetRaytracingShaderHandlesNVX(device, pipeline, firstGroup, groupCount, dataSize, pData);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRaytracingShaderHandlesNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidArray(pData, dataSize, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRaytracingShaderHandlesNVX>::Dispatch(encode::TraceManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNVX(
    VkDevice                                    device,
    VkAccelerationStructureNVX                  accelerationStructure,
    size_t                                      dataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNVX>::Dispatch(encode::TraceManager::Get(), device, accelerationStructure, dataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(accelerationStructure);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetAccelerationStructureHandleNVX(device, accelerationStructure, dataSize, pData);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeVoidArray(pData, dataSize, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNVX>::Dispatch(encode::TraceManager::Get(), result, device, accelerationStructure, dataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructurePropertiesNVX(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNVX                  accelerationStructure,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructurePropertiesNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, accelerationStructure, queryType, queryPool, query);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructurePropertiesNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(accelerationStructure);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdWriteAccelerationStructurePropertiesNVX(commandBuffer, accelerationStructure, queryType, queryPool, query);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructurePropertiesNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructurePropertiesNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, accelerationStructure, queryType, queryPool, query);
}

VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNVX(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    shader)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNVX>::Dispatch(encode::TraceManager::Get(), device, pipeline, shader);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCompileDeferredNVX, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeUInt32Value(shader);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->CompileDeferredNVX(device, pipeline, shader);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCompileDeferredNVX, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNVX>::Dispatch(encode::TraceManager::Get(), result, device, pipeline, shader);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(encode::TraceManager::Get(), device, handleType, pHostPointer, pMemoryHostPointerProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(pHostPointer);
        encode_struct_ptr(encoder, pMemoryHostPointerProperties, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    VkResult result = get_device_table(device)->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode_struct_ptr(encoder, pMemoryHostPointerProperties, false);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(encode::TraceManager::Get(), result, device, handleType, pHostPointer, pMemoryHostPointerProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeUInt32Value(marker);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, taskCount, firstTask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(taskCount);
        encoder->EncodeUInt32Value(firstTask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, taskCount, firstTask);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstExclusiveScissor);
        encoder->EncodeUInt32Value(exclusiveScissorCount);
        encode_struct_array(encoder, pExclusiveScissors, exclusiveScissorCount, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, pCheckpointMarker);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeVoidPtr(pCheckpointMarker);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(commandBuffer)->CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, pCheckpointMarker);
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointDataNV*                         pCheckpointData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(encode::TraceManager::Get(), queue, pCheckpointDataCount, pCheckpointData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV, encode::TraceManager::PreCall);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Ptr(pCheckpointDataCount, true);
        encode_struct_array(encoder, pCheckpointData, (pCheckpointDataCount != nullptr) ? (*pCheckpointDataCount) : 0, true);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    get_device_table(queue)->GetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);

    encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV, encode::TraceManager::PostCall);
    if (encoder)
    {
        encoder->EncodeUInt32Ptr(pCheckpointDataCount, false);
        encode_struct_array(encoder, pCheckpointData, (pCheckpointDataCount != nullptr) ? (*pCheckpointDataCount) : 0, false);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(encode::TraceManager::Get(), queue, pCheckpointDataCount, pCheckpointData);
}

#ifdef VK_USE_PLATFORM_FUCHSIA
VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA(
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA, encode::TraceManager::PreCall);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo, false);
            encode_struct_ptr(encoder, pAllocator, false);
            encoder->EncodeHandleIdPtr(pSurface, true);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }

        result = get_instance_table(instance)->CreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);

        encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA, encode::TraceManager::PostCall);
        if (encoder)
        {
            encoder->EncodeHandleIdPtr(pSurface, false);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_FUCHSIA */

BRIMSTONE_END_NAMESPACE(brimstone)
