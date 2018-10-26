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

#include <cstddef>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "decode/pnext_node.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/value_decoder.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(decode)

size_t VulkanDecoder::Decode_vkCreateInstance(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_VkInstanceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pInstance;
    VkResult return_value;

    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pInstance.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateInstance(return_value, pCreateInfo, pAllocator, pInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateInstance(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_VkInstanceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pInstance;
    VkResult return_value;

    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pInstance.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pInstance.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateInstance(return_value, pCreateInfo, pAllocator, pInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyInstance(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyInstance(instance, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyInstance(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyInstance(instance, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDevices(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceCount;
    PointerDecoder<format::HandleId> pPhysicalDevices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPhysicalDevices.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDevices(return_value, instance, pPhysicalDeviceCount, pPhysicalDevices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDevices(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceCount;
    PointerDecoder<format::HandleId> pPhysicalDevices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPhysicalDevices.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPhysicalDeviceCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pPhysicalDevices.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDevices(return_value, instance, pPhysicalDeviceCount, pPhysicalDevices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFeatures.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFormatProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    StructPointerDecoder<Decoded_VkImageFormatProperties> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &tiling);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += pImageFormatProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties(return_value, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    StructPointerDecoder<Decoded_VkImageFormatProperties> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &tiling);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);
    bytes_read += pImageFormatProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pImageFormatProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties(return_value, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDevice(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pDevice;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pDevice.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDevice(return_value, physicalDevice, pCreateInfo, pAllocator, pDevice);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDevice(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pDevice;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pDevice.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDevice.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDevice(return_value, physicalDevice, pCreateInfo, pAllocator, pDevice);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDevice(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDevice(device, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDevice(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDevice(device, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    PointerDecoder<format::HandleId> pQueue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queueIndex);
    bytes_read += pQueue.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t queueFamilyIndex;
    uint32_t queueIndex;
    PointerDecoder<format::HandleId> pQueue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queueIndex);
    bytes_read += pQueue.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pQueue.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSubmit(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo> pSubmits;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueSubmit(return_value, queue, submitCount, pSubmits, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueSubmit(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t submitCount;
    StructPointerDecoder<Decoded_VkSubmitInfo> pSubmits;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &submitCount);
    bytes_read += pSubmits.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &fence);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueSubmit(return_value, queue, submitCount, pSubmits, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueWaitIdle(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueWaitIdle(return_value, queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueWaitIdle(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queue);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueWaitIdle(return_value, queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDeviceWaitIdle(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDeviceWaitIdle(return_value, device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDeviceWaitIdle(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDeviceWaitIdle(return_value, device);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateMemory(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo> pAllocateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pMemory;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMemory.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateMemory(return_value, device, pAllocateInfo, pAllocator, pMemory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateMemory(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo> pAllocateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pMemory;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMemory.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemory.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateMemory(return_value, device, pAllocateInfo, pAllocator, pMemory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeMemory(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memory);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeMemory(device, memory, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeMemory(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memory);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeMemory(device, memory, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMapMemory(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkMemoryMapFlags flags;
    PointerDecoder<uint64_t> ppData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += ppData.DecodeVoidPtr((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMapMemory(return_value, device, memory, offset, size, flags, ppData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMapMemory(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    VkDeviceSize offset;
    VkDeviceSize size;
    VkMemoryMapFlags flags;
    PointerDecoder<uint64_t> ppData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);
    bytes_read += ppData.DecodeVoidPtr((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ppData.DecodeVoidPtr((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMapMemory(return_value, device, memory, offset, size, flags, ppData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnmapMemory(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memory);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUnmapMemory(device, memory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnmapMemory(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memory);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUnmapMemory(device, memory);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFlushMappedMemoryRanges(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFlushMappedMemoryRanges(return_value, device, memoryRangeCount, pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFlushMappedMemoryRanges(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFlushMappedMemoryRanges(return_value, device, memoryRangeCount, pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkInvalidateMappedMemoryRanges(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkInvalidateMappedMemoryRanges(return_value, device, memoryRangeCount, pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkInvalidateMappedMemoryRanges(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t memoryRangeCount;
    StructPointerDecoder<Decoded_VkMappedMemoryRange> pMemoryRanges;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memoryRangeCount);
    bytes_read += pMemoryRanges.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkInvalidateMappedMemoryRanges(return_value, device, memoryRangeCount, pMemoryRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryCommitment(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    PointerDecoder<VkDeviceSize> pCommittedMemoryInBytes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memory);
    bytes_read += pCommittedMemoryInBytes.DecodeVkDeviceSize((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceMemoryCommitment(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    PointerDecoder<VkDeviceSize> pCommittedMemoryInBytes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memory);
    bytes_read += pCommittedMemoryInBytes.DecodeVkDeviceSize((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pCommittedMemoryInBytes.DecodeVkDeviceSize((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    format::HandleId memory;
    VkDeviceSize memoryOffset;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memoryOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory(return_value, device, buffer, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    format::HandleId memory;
    VkDeviceSize memoryOffset;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memoryOffset);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory(return_value, device, buffer, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    format::HandleId memory;
    VkDeviceSize memoryOffset;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memoryOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory(return_value, device, image, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    format::HandleId memory;
    VkDeviceSize memoryOffset;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memoryOffset);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory(return_value, device, image, memory, memoryOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += pMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += pMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &image);
    bytes_read += pMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkMemoryRequirements> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &image);
    bytes_read += pMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &image);
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &image);
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkSampleCountFlagBits samples;
    VkImageUsageFlags usage;
    VkImageTiling tiling;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &samples);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &tiling);
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkSampleCountFlagBits samples;
    VkImageUsageFlags usage;
    VkImageTiling tiling;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &samples);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &tiling);
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBindSparse(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindSparseInfo> pBindInfo;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueBindSparse(return_value, queue, bindInfoCount, pBindInfo, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBindSparse(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindSparseInfo> pBindInfo;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queue);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &fence);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueBindSparse(return_value, queue, bindInfoCount, pBindInfo, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFence(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateFence(return_value, device, pCreateInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFence(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFence.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateFence(return_value, device, pCreateInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFence(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId fence;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &fence);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyFence(device, fence, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFence(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId fence;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &fence);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyFence(device, fence, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetFences(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t fenceCount;
    PointerDecoder<format::HandleId> pFences;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetFences(return_value, device, fenceCount, pFences);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetFences(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t fenceCount;
    PointerDecoder<format::HandleId> pFences;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetFences(return_value, device, fenceCount, pFences);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceStatus(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &fence);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceStatus(return_value, device, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceStatus(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId fence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &fence);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceStatus(return_value, device, fence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitForFences(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t fenceCount;
    PointerDecoder<format::HandleId> pFences;
    VkBool32 waitAll;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkBool32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &waitAll);
    bytes_read += ValueDecoder::DecodeUInt64Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWaitForFences(return_value, device, fenceCount, pFences, waitAll, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkWaitForFences(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t fenceCount;
    PointerDecoder<format::HandleId> pFences;
    VkBool32 waitAll;
    uint64_t timeout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &fenceCount);
    bytes_read += pFences.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkBool32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &waitAll);
    bytes_read += ValueDecoder::DecodeUInt64Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &timeout);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkWaitForFences(return_value, device, fenceCount, pFences, waitAll, timeout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSemaphore(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSemaphore;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSemaphore.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSemaphore(return_value, device, pCreateInfo, pAllocator, pSemaphore);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSemaphore(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSemaphore;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSemaphore.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSemaphore.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSemaphore(return_value, device, pCreateInfo, pAllocator, pSemaphore);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySemaphore(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &semaphore);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySemaphore(device, semaphore, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySemaphore(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId semaphore;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &semaphore);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySemaphore(device, semaphore, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateEvent(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkEventCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pEvent;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pEvent.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateEvent(return_value, device, pCreateInfo, pAllocator, pEvent);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateEvent(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkEventCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pEvent;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pEvent.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pEvent.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateEvent(return_value, device, pCreateInfo, pAllocator, pEvent);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyEvent(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &event);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyEvent(device, event, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyEvent(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &event);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyEvent(device, event, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetEventStatus(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetEventStatus(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetEventStatus(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &event);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetEventStatus(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetEvent(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetEvent(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetEvent(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &event);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetEvent(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetEvent(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetEvent(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetEvent(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId event;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &event);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetEvent(return_value, device, event);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateQueryPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pQueryPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pQueryPool.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateQueryPool(return_value, device, pCreateInfo, pAllocator, pQueryPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateQueryPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pQueryPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pQueryPool.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pQueryPool.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateQueryPool(return_value, device, pCreateInfo, pAllocator, pQueryPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyQueryPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryPool);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyQueryPool(device, queryPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyQueryPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryPool);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyQueryPool(device, queryPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueryPoolResults(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkDeviceSize stride;
    VkQueryResultFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetQueryPoolResults(return_value, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueryPoolResults(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkDeviceSize stride;
    VkQueryResultFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);

    bytes_read = 0;
    bytes_read += pData.DecodeVoid((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetQueryPoolResults(return_value, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pBuffer.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateBuffer(return_value, device, pCreateInfo, pAllocator, pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pBuffer.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pBuffer.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateBuffer(return_value, device, pCreateInfo, pAllocator, pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyBuffer(device, buffer, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId buffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyBuffer(device, buffer, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBufferView(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pView.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateBufferView(return_value, device, pCreateInfo, pAllocator, pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateBufferView(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pView.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pView.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateBufferView(return_value, device, pCreateInfo, pAllocator, pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBufferView(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId bufferView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bufferView);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyBufferView(device, bufferView, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyBufferView(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId bufferView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bufferView);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyBufferView(device, bufferView, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImage(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pImage;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pImage.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImage(return_value, device, pCreateInfo, pAllocator, pImage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImage(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pImage;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pImage.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pImage.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImage(return_value, device, pCreateInfo, pAllocator, pImage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImage(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &image);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyImage(device, image, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImage(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &image);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyImage(device, image, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSubresourceLayout(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &image);
    bytes_read += pSubresource.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pLayout.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSubresourceLayout(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId image;
    StructPointerDecoder<Decoded_VkImageSubresource> pSubresource;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &image);
    bytes_read += pSubresource.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pLayout.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pLayout.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImageView(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pView.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImageView(return_value, device, pCreateInfo, pAllocator, pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImageView(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageViewCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pView;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pView.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pView.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImageView(return_value, device, pCreateInfo, pAllocator, pView);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImageView(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &imageView);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyImageView(device, imageView, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyImageView(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId imageView;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &imageView);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyImageView(device, imageView, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateShaderModule(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pShaderModule;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pShaderModule.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateShaderModule(return_value, device, pCreateInfo, pAllocator, pShaderModule);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateShaderModule(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pShaderModule;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pShaderModule.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pShaderModule.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateShaderModule(return_value, device, pCreateInfo, pAllocator, pShaderModule);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyShaderModule(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &shaderModule);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyShaderModule(device, shaderModule, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyShaderModule(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId shaderModule;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &shaderModule);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyShaderModule(device, shaderModule, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineCache(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelineCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPipelineCache.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePipelineCache(return_value, device, pCreateInfo, pAllocator, pPipelineCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineCache(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelineCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPipelineCache.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPipelineCache.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePipelineCache(return_value, device, pCreateInfo, pAllocator, pPipelineCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineCache(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineCache);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineCache(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineCache);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineCacheData(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineCache);
    bytes_read += pDataSize.DecodeSizeT((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPipelineCacheData(return_value, device, pipelineCache, pDataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPipelineCacheData(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineCache);
    bytes_read += pDataSize.DecodeSizeT((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDataSize.DecodeSizeT((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPipelineCacheData(return_value, device, pipelineCache, pDataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergePipelineCaches(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    PointerDecoder<format::HandleId> pSrcCaches;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcCacheCount);
    bytes_read += pSrcCaches.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMergePipelineCaches(return_value, device, dstCache, srcCacheCount, pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergePipelineCaches(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    PointerDecoder<format::HandleId> pSrcCaches;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcCacheCount);
    bytes_read += pSrcCaches.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMergePipelineCaches(return_value, device, dstCache, srcCacheCount, pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateGraphicsPipelines(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPipelines.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateGraphicsPipelines(return_value, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateGraphicsPipelines(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPipelines.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPipelines.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateGraphicsPipelines(return_value, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateComputePipelines(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPipelines.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateComputePipelines(return_value, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateComputePipelines(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPipelines.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPipelines.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateComputePipelines(return_value, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipeline(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipeline);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipeline(device, pipeline, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipeline(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipeline);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipeline(device, pipeline, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineLayout(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelineLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPipelineLayout.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePipelineLayout(return_value, device, pCreateInfo, pAllocator, pPipelineLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreatePipelineLayout(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelineLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPipelineLayout.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPipelineLayout.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreatePipelineLayout(return_value, device, pCreateInfo, pAllocator, pPipelineLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineLayout(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineLayout);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyPipelineLayout(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineLayout);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSampler(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSampler;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSampler.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSampler(return_value, device, pCreateInfo, pAllocator, pSampler);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSampler(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSampler;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSampler.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSampler.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSampler(return_value, device, pCreateInfo, pAllocator, pSampler);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySampler(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId sampler;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &sampler);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySampler(device, sampler, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySampler(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId sampler;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &sampler);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySampler(device, sampler, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorSetLayout(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSetLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSetLayout.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorSetLayout(return_value, device, pCreateInfo, pAllocator, pSetLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorSetLayout(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSetLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSetLayout.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSetLayout.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorSetLayout(return_value, device, pCreateInfo, pAllocator, pSetLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorSetLayout(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorSetLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorSetLayout);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorSetLayout(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorSetLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorSetLayout);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pDescriptorPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pDescriptorPool.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorPool(return_value, device, pCreateInfo, pAllocator, pDescriptorPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pDescriptorPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pDescriptorPool.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDescriptorPool.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorPool(return_value, device, pCreateInfo, pAllocator, pDescriptorPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorPool);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorPool);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetDescriptorPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    VkDescriptorPoolResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetDescriptorPool(return_value, device, descriptorPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetDescriptorPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    VkDescriptorPoolResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetDescriptorPool(return_value, device, descriptorPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateDescriptorSets(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo> pAllocateInfo;
    PointerDecoder<format::HandleId> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pDescriptorSets.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateDescriptorSets(return_value, device, pAllocateInfo, pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateDescriptorSets(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo> pAllocateInfo;
    PointerDecoder<format::HandleId> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pDescriptorSets.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDescriptorSets.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateDescriptorSets(return_value, device, pAllocateInfo, pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeDescriptorSets(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    uint32_t descriptorSetCount;
    PointerDecoder<format::HandleId> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorSetCount);
    bytes_read += pDescriptorSets.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeDescriptorSets(return_value, device, descriptorPool, descriptorSetCount, pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeDescriptorSets(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorPool;
    uint32_t descriptorSetCount;
    PointerDecoder<format::HandleId> pDescriptorSets;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorSetCount);
    bytes_read += pDescriptorSets.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeDescriptorSets(return_value, device, descriptorPool, descriptorSetCount, pDescriptorSets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSets(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
    uint32_t descriptorCopyCount;
    StructPointerDecoder<Decoded_VkCopyDescriptorSet> pDescriptorCopies;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorCopyCount);
    bytes_read += pDescriptorCopies.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUpdateDescriptorSets(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;
    uint32_t descriptorCopyCount;
    StructPointerDecoder<Decoded_VkCopyDescriptorSet> pDescriptorCopies;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorCopyCount);
    bytes_read += pDescriptorCopies.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFramebuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pFramebuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pFramebuffer.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateFramebuffer(return_value, device, pCreateInfo, pAllocator, pFramebuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateFramebuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pFramebuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pFramebuffer.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFramebuffer.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateFramebuffer(return_value, device, pCreateInfo, pAllocator, pFramebuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFramebuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId framebuffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &framebuffer);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyFramebuffer(device, framebuffer, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyFramebuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId framebuffer;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &framebuffer);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyFramebuffer(device, framebuffer, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pRenderPass.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRenderPass(return_value, device, pCreateInfo, pAllocator, pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pRenderPass.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pRenderPass.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRenderPass(return_value, device, pCreateInfo, pAllocator, pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyRenderPass(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &renderPass);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyRenderPass(device, renderPass, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyRenderPass(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &renderPass);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyRenderPass(device, renderPass, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRenderAreaGranularity(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &renderPass);
    bytes_read += pGranularity.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRenderAreaGranularity(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId renderPass;
    StructPointerDecoder<Decoded_VkExtent2D> pGranularity;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &renderPass);
    bytes_read += pGranularity.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pGranularity.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateCommandPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pCommandPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pCommandPool.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateCommandPool(return_value, device, pCreateInfo, pAllocator, pCommandPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateCommandPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pCommandPool;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pCommandPool.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pCommandPool.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateCommandPool(return_value, device, pCreateInfo, pAllocator, pCommandPool);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyCommandPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandPool);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyCommandPool(device, commandPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyCommandPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandPool);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyCommandPool(device, commandPool, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetCommandPool(return_value, device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetCommandPool(return_value, device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateCommandBuffers(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo> pAllocateInfo;
    PointerDecoder<format::HandleId> pCommandBuffers;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pCommandBuffers.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateCommandBuffers(return_value, device, pAllocateInfo, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAllocateCommandBuffers(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo> pAllocateInfo;
    PointerDecoder<format::HandleId> pCommandBuffers;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pAllocateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pCommandBuffers.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pCommandBuffers.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAllocateCommandBuffers(return_value, device, pAllocateInfo, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeCommandBuffers(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    uint32_t commandBufferCount;
    PointerDecoder<format::HandleId> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkFreeCommandBuffers(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    uint32_t commandBufferCount;
    PointerDecoder<format::HandleId> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBeginCommandBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo> pBeginInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBeginInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBeginCommandBuffer(return_value, commandBuffer, pBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBeginCommandBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo> pBeginInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pBeginInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBeginCommandBuffer(return_value, commandBuffer, pBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEndCommandBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEndCommandBuffer(return_value, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEndCommandBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEndCommandBuffer(return_value, commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCommandBufferResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetCommandBuffer(return_value, commandBuffer, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkResetCommandBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCommandBufferResetFlags flags;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkResetCommandBuffer(return_value, commandBuffer, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindPipeline(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipeline);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindPipeline(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId pipeline;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipeline);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewport(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewport(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewport> pViewports;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewports.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetScissor(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetScissor(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstScissor;
    uint32_t scissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &scissorCount);
    bytes_read += pScissors.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineWidth(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float lineWidth;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &lineWidth);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLineWidth(commandBuffer, lineWidth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetLineWidth(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float lineWidth;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &lineWidth);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetLineWidth(commandBuffer, lineWidth);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBias(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &depthBiasConstantFactor);
    bytes_read += ValueDecoder::DecodeFloatValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &depthBiasClamp);
    bytes_read += ValueDecoder::DecodeFloatValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &depthBiasSlopeFactor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBias(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float depthBiasConstantFactor;
    float depthBiasClamp;
    float depthBiasSlopeFactor;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &depthBiasConstantFactor);
    bytes_read += ValueDecoder::DecodeFloatValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &depthBiasClamp);
    bytes_read += ValueDecoder::DecodeFloatValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &depthBiasSlopeFactor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetBlendConstants(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    PointerDecoder<float> blendConstants;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += blendConstants.DecodeFloat((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetBlendConstants(commandBuffer, blendConstants);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetBlendConstants(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    PointerDecoder<float> blendConstants;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += blendConstants.DecodeFloat((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetBlendConstants(commandBuffer, blendConstants);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBounds(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &minDepthBounds);
    bytes_read += ValueDecoder::DecodeFloatValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &maxDepthBounds);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDepthBounds(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    float minDepthBounds;
    float maxDepthBounds;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFloatValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &minDepthBounds);
    bytes_read += ValueDecoder::DecodeFloatValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &maxDepthBounds);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilCompareMask(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &compareMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilCompareMask(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t compareMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &compareMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilWriteMask(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &writeMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilWriteMask(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t writeMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &writeMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilReference(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &reference);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetStencilReference(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkStencilFaceFlags faceMask;
    uint32_t reference;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &faceMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &reference);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetStencilReference(commandBuffer, faceMask, reference);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindDescriptorSets(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t firstSet;
    uint32_t descriptorSetCount;
    PointerDecoder<format::HandleId> pDescriptorSets;
    uint32_t dynamicOffsetCount;
    PointerDecoder<uint32_t> pDynamicOffsets;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstSet);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorSetCount);
    bytes_read += pDescriptorSets.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dynamicOffsetCount);
    bytes_read += pDynamicOffsets.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindDescriptorSets(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t firstSet;
    uint32_t descriptorSetCount;
    PointerDecoder<format::HandleId> pDescriptorSets;
    uint32_t dynamicOffsetCount;
    PointerDecoder<uint32_t> pDynamicOffsets;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstSet);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorSetCount);
    bytes_read += pDescriptorSets.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dynamicOffsetCount);
    bytes_read += pDynamicOffsets.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindIndexBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkIndexType indexType;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &indexType);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindIndexBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    VkIndexType indexType;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &indexType);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindVertexBuffers(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    PointerDecoder<format::HandleId> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstBinding);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bindingCount);
    bytes_read += pBuffers.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pOffsets.DecodeVkDeviceSize((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindVertexBuffers(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstBinding;
    uint32_t bindingCount;
    PointerDecoder<format::HandleId> pBuffers;
    PointerDecoder<VkDeviceSize> pOffsets;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstBinding);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bindingCount);
    bytes_read += pBuffers.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pOffsets.DecodeVkDeviceSize((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDraw(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &vertexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstVertex);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstInstance);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDraw(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t vertexCount;
    uint32_t instanceCount;
    uint32_t firstVertex;
    uint32_t firstInstance;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &vertexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstVertex);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstInstance);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexed(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t vertexOffset;
    uint32_t firstInstance;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &indexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstIndex);
    bytes_read += ValueDecoder::DecodeInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &vertexOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstInstance);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexed(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t indexCount;
    uint32_t instanceCount;
    uint32_t firstIndex;
    int32_t vertexOffset;
    uint32_t firstInstance;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &indexCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstIndex);
    bytes_read += ValueDecoder::DecodeInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &vertexOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstInstance);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirect(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirect(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirect(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirect(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatch(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatch(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchIndirect(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchIndirect(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchIndirect(commandBuffer, buffer, offset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImage(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImage(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBlitImage(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageBlit> pRegions;
    VkFilter filter;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &filter);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBlitImage(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageBlit> pRegions;
    VkFilter filter;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &filter);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBufferToImage(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyBufferToImage(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcBuffer;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImageToBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyImageToBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstBuffer;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkBufferImageCopy> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdUpdateBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdUpdateBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize dataSize;
    PointerDecoder<uint8_t> pData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdFillBuffer(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &data);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdFillBuffer(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize size;
    uint32_t data;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &size);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &data);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearColorImage(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearColorValue> pColor;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &imageLayout);
    bytes_read += pColor.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearColorImage(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearColorValue> pColor;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &imageLayout);
    bytes_read += pColor.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearDepthStencilImage(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearDepthStencilValue> pDepthStencil;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &imageLayout);
    bytes_read += pDepthStencil.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearDepthStencilImage(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId image;
    VkImageLayout imageLayout;
    StructPointerDecoder<Decoded_VkClearDepthStencilValue> pDepthStencil;
    uint32_t rangeCount;
    StructPointerDecoder<Decoded_VkImageSubresourceRange> pRanges;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &image);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &imageLayout);
    bytes_read += pDepthStencil.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &rangeCount);
    bytes_read += pRanges.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearAttachments(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkClearAttachment> pAttachments;
    uint32_t rectCount;
    StructPointerDecoder<Decoded_VkClearRect> pRects;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &attachmentCount);
    bytes_read += pAttachments.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &rectCount);
    bytes_read += pRects.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdClearAttachments(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t attachmentCount;
    StructPointerDecoder<Decoded_VkClearAttachment> pAttachments;
    uint32_t rectCount;
    StructPointerDecoder<Decoded_VkClearRect> pRects;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &attachmentCount);
    bytes_read += pAttachments.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &rectCount);
    bytes_read += pRects.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResolveImage(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageResolve> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResolveImage(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId srcImage;
    VkImageLayout srcImageLayout;
    format::HandleId dstImage;
    VkImageLayout dstImageLayout;
    uint32_t regionCount;
    StructPointerDecoder<Decoded_VkImageResolve> pRegions;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcImage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcImageLayout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstImage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstImageLayout);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &regionCount);
    bytes_read += pRegions.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetEvent(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stageMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetEvent(commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetEvent(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stageMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetEvent(commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetEvent(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stageMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResetEvent(commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetEvent(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId event;
    VkPipelineStageFlags stageMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &event);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stageMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResetEvent(commandBuffer, event, stageMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWaitEvents(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    PointerDecoder<format::HandleId> pEvents;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &eventCount);
    bytes_read += pEvents.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWaitEvents(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t eventCount;
    PointerDecoder<format::HandleId> pEvents;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &eventCount);
    bytes_read += pEvents.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPipelineBarrier(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    VkDependencyFlags dependencyFlags;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dependencyFlags);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPipelineBarrier(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlags srcStageMask;
    VkPipelineStageFlags dstStageMask;
    VkDependencyFlags dependencyFlags;
    uint32_t memoryBarrierCount;
    StructPointerDecoder<Decoded_VkMemoryBarrier> pMemoryBarriers;
    uint32_t bufferMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier> pBufferMemoryBarriers;
    uint32_t imageMemoryBarrierCount;
    StructPointerDecoder<Decoded_VkImageMemoryBarrier> pImageMemoryBarriers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstStageMask);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dependencyFlags);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memoryBarrierCount);
    bytes_read += pMemoryBarriers.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bufferMemoryBarrierCount);
    bytes_read += pBufferMemoryBarriers.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &imageMemoryBarrierCount);
    bytes_read += pImageMemoryBarriers.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginQuery(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    VkQueryControlFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &query);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginQuery(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;
    VkQueryControlFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &query);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndQuery(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndQuery(commandBuffer, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndQuery(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndQuery(commandBuffer, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetQueryPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryCount);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdResetQueryPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryCount);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteTimestamp(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineStage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteTimestamp(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineStage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyQueryPoolResults(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize stride;
    VkQueryResultFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryCount);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyQueryPoolResults(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId queryPool;
    uint32_t firstQuery;
    uint32_t queryCount;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    VkDeviceSize stride;
    VkQueryResultFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstQuery);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryCount);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushConstants(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId layout;
    VkShaderStageFlags stageFlags;
    uint32_t offset;
    uint32_t size;
    PointerDecoder<uint8_t> pValues;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stageFlags);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &size);
    bytes_read += pValues.DecodeVoid((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushConstants(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId layout;
    VkShaderStageFlags stageFlags;
    uint32_t offset;
    uint32_t size;
    PointerDecoder<uint8_t> pValues;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stageFlags);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &size);
    bytes_read += pValues.DecodeVoid((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &contents);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &contents);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &contents);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdNextSubpass(commandBuffer, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkSubpassContents contents;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &contents);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdNextSubpass(commandBuffer, contents);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdExecuteCommands(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t commandBufferCount;
    PointerDecoder<format::HandleId> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdExecuteCommands(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t commandBufferCount;
    PointerDecoder<format::HandleId> pCommandBuffers;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBufferCount);
    bytes_read += pCommandBuffers.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory2(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory2(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory2(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory2(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeatures(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &heapIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &localDeviceIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &remoteDeviceIndex);
    bytes_read += pPeerMemoryFeatures.DecodeFlags((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeatures(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &heapIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &localDeviceIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &remoteDeviceIndex);
    bytes_read += pPeerMemoryFeatures.DecodeFlags((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPeerMemoryFeatures.DecodeFlags((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMask(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &deviceMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDeviceMask(commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMask(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &deviceMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDeviceMask(commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBase(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &baseGroupX);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &baseGroupY);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &baseGroupZ);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBase(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &baseGroupX);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &baseGroupY);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &baseGroupZ);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroups(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDeviceGroups(return_value, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroups(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDeviceGroups(return_value, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFeatures.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFormatProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties2(return_value, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pImageFormatProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties2(return_value, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPool(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkTrimCommandPool(device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPool(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkTrimCommandPool(device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue2(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2> pQueueInfo;
    PointerDecoder<format::HandleId> pQueue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pQueueInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pQueue.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceQueue2(device, pQueueInfo, pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceQueue2(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2> pQueueInfo;
    PointerDecoder<format::HandleId> pQueue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pQueueInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pQueue.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pQueue.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceQueue2(device, pQueueInfo, pQueue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversion(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSamplerYcbcrConversion(return_value, device, pCreateInfo, pAllocator, pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversion(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pYcbcrConversion.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSamplerYcbcrConversion(return_value, device, pCreateInfo, pAllocator, pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversion(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversion(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplate(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorUpdateTemplate(return_value, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplate(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDescriptorUpdateTemplate.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorUpdateTemplate(return_value, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplate(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplate(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pExternalBufferProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFenceProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFenceProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pExternalFenceProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pExternalSemaphoreProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupport(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSupport.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupport(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSupport.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSupport.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySurfaceKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &surface);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySurfaceKHR(instance, surface, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySurfaceKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &surface);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySurfaceKHR(instance, surface, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceSupportKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    format::HandleId surface;
    PointerDecoder<VkBool32> pSupported;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &surface);
    bytes_read += pSupported.DecodeVkBool32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceSupportKHR(return_value, physicalDevice, queueFamilyIndex, surface, pSupported);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceSupportKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    format::HandleId surface;
    PointerDecoder<VkBool32> pSupported;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &surface);
    bytes_read += pSupported.DecodeVkBool32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSupported.DecodeVkBool32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceSupportKHR(return_value, physicalDevice, queueFamilyIndex, surface, pSupported);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(return_value, physicalDevice, surface, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurfaceCapabilities.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(return_value, physicalDevice, surface, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceFormatCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceFormatsKHR(return_value, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceFormatCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurfaceFormatCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceFormatsKHR(return_value, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &surface);
    bytes_read += pPresentModeCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPresentModes.DecodeEnum((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfacePresentModesKHR(return_value, physicalDevice, surface, pPresentModeCount, pPresentModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pPresentModeCount;
    PointerDecoder<VkPresentModeKHR> pPresentModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &surface);
    bytes_read += pPresentModeCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPresentModes.DecodeEnum((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPresentModeCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pPresentModes.DecodeEnum((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfacePresentModesKHR(return_value, physicalDevice, surface, pPresentModeCount, pPresentModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSwapchainKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSwapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSwapchain.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSwapchainKHR(return_value, device, pCreateInfo, pAllocator, pSwapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSwapchainKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSwapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSwapchain.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSwapchain.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSwapchainKHR(return_value, device, pCreateInfo, pAllocator, pSwapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySwapchainKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchain);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySwapchainKHR(device, swapchain, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySwapchainKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchain);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySwapchainKHR(device, swapchain, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainImagesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pSwapchainImageCount;
    PointerDecoder<format::HandleId> pSwapchainImages;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchain);
    bytes_read += pSwapchainImageCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSwapchainImages.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainImagesKHR(return_value, device, swapchain, pSwapchainImageCount, pSwapchainImages);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainImagesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pSwapchainImageCount;
    PointerDecoder<format::HandleId> pSwapchainImages;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchain);
    bytes_read += pSwapchainImageCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSwapchainImages.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSwapchainImageCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pSwapchainImages.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainImagesKHR(return_value, device, swapchain, pSwapchainImageCount, pSwapchainImages);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImageKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    uint64_t timeout;
    format::HandleId semaphore;
    format::HandleId fence;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeUInt64Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &semaphore);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &fence);
    bytes_read += pImageIndex.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireNextImageKHR(return_value, device, swapchain, timeout, semaphore, fence, pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImageKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    uint64_t timeout;
    format::HandleId semaphore;
    format::HandleId fence;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeUInt64Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &timeout);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &semaphore);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &fence);
    bytes_read += pImageIndex.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pImageIndex.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireNextImageKHR(return_value, device, swapchain, timeout, semaphore, fence, pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueuePresentKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkPresentInfoKHR> pPresentInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queue);
    bytes_read += pPresentInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueuePresentKHR(return_value, queue, pPresentInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueuePresentKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkPresentInfoKHR> pPresentInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queue);
    bytes_read += pPresentInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueuePresentKHR(return_value, queue, pPresentInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPresentCapabilitiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR> pDeviceGroupPresentCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pDeviceGroupPresentCapabilities.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPresentCapabilitiesKHR(return_value, device, pDeviceGroupPresentCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPresentCapabilitiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR> pDeviceGroupPresentCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pDeviceGroupPresentCapabilities.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDeviceGroupPresentCapabilities.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPresentCapabilitiesKHR(return_value, device, pDeviceGroupPresentCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupSurfacePresentModesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId surface;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &surface);
    bytes_read += pModes.DecodeFlags((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupSurfacePresentModesKHR(return_value, device, surface, pModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupSurfacePresentModesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId surface;
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR> pModes;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &surface);
    bytes_read += pModes.DecodeFlags((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pModes.DecodeFlags((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupSurfacePresentModesKHR(return_value, device, surface, pModes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDevicePresentRectanglesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pRectCount;
    StructPointerDecoder<Decoded_VkRect2D> pRects;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &surface);
    bytes_read += pRectCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pRects.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDevicePresentRectanglesKHR(return_value, physicalDevice, surface, pRectCount, pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDevicePresentRectanglesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    PointerDecoder<uint32_t> pRectCount;
    StructPointerDecoder<Decoded_VkRect2D> pRects;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &surface);
    bytes_read += pRectCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pRects.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pRectCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pRects.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDevicePresentRectanglesKHR(return_value, physicalDevice, surface, pRectCount, pRects);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImage2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR> pAcquireInfo;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pAcquireInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pImageIndex.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireNextImage2KHR(return_value, device, pAcquireInfo, pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireNextImage2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR> pAcquireInfo;
    PointerDecoder<uint32_t> pImageIndex;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pAcquireInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pImageIndex.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pImageIndex.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireNextImage2KHR(return_value, device, pAcquireInfo, pImageIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPropertiesKHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPropertiesKHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneSupportedDisplaysKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t planeIndex;
    PointerDecoder<uint32_t> pDisplayCount;
    PointerDecoder<format::HandleId> pDisplays;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &planeIndex);
    bytes_read += pDisplayCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pDisplays.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneSupportedDisplaysKHR(return_value, physicalDevice, planeIndex, pDisplayCount, pDisplays);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneSupportedDisplaysKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t planeIndex;
    PointerDecoder<uint32_t> pDisplayCount;
    PointerDecoder<format::HandleId> pDisplays;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &planeIndex);
    bytes_read += pDisplayCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pDisplays.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDisplayCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pDisplays.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneSupportedDisplaysKHR(return_value, physicalDevice, planeIndex, pDisplayCount, pDisplays);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModePropertiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayModePropertiesKHR(return_value, physicalDevice, display, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModePropertiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayModePropertiesKHR(return_value, physicalDevice, display, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayModeKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pMode;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &display);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMode.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDisplayModeKHR(return_value, physicalDevice, display, pCreateInfo, pAllocator, pMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayModeKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pMode;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &display);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMode.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMode.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDisplayModeKHR(return_value, physicalDevice, display, pCreateInfo, pAllocator, pMode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilitiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId mode;
    uint32_t planeIndex;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &mode);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &planeIndex);
    bytes_read += pCapabilities.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneCapabilitiesKHR(return_value, physicalDevice, mode, planeIndex, pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilitiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId mode;
    uint32_t planeIndex;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &mode);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &planeIndex);
    bytes_read += pCapabilities.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pCapabilities.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneCapabilitiesKHR(return_value, physicalDevice, mode, planeIndex, pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayPlaneSurfaceKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDisplayPlaneSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDisplayPlaneSurfaceKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDisplayPlaneSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSharedSwapchainsKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t swapchainCount;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSwapchains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchainCount);
    bytes_read += pCreateInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSwapchains.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSharedSwapchainsKHR(return_value, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSharedSwapchainsKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t swapchainCount;
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSwapchains;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchainCount);
    bytes_read += pCreateInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSwapchains.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSwapchains.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSharedSwapchainsKHR(return_value, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateXlibSurfaceKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateXlibSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateXlibSurfaceKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateXlibSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dpy;
    size_t visualID;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeSizeTValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &visualID);
    bytes_read += ValueDecoder::DecodeVkBool32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, dpy, visualID);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t dpy;
    size_t visualID;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeSizeTValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &visualID);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeVkBool32Value((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, dpy, visualID);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateXcbSurfaceKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateXcbSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateXcbSurfaceKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateXcbSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t connection;
    uint32_t visual_id;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &connection);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &visual_id);
    bytes_read += ValueDecoder::DecodeVkBool32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, connection, visual_id);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t connection;
    uint32_t visual_id;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &connection);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &visual_id);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeVkBool32Value((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, connection, visual_id);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateWaylandSurfaceKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateWaylandSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateWaylandSurfaceKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateWaylandSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t display;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeVkBool32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t display;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &display);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeVkBool32Value((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMirSurfaceKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMirSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateMirSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMirSurfaceKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMirSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateMirSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMirPresentationSupportKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t connection;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &connection);
    bytes_read += ValueDecoder::DecodeVkBool32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMirPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, connection);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMirPresentationSupportKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    uint64_t connection;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &connection);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeVkBool32Value((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMirPresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex, connection);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAndroidSurfaceKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateAndroidSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAndroidSurfaceKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateAndroidSurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateWin32SurfaceKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateWin32SurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateWin32SurfaceKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateWin32SurfaceKHR(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queueFamilyIndex);
    bytes_read += ValueDecoder::DecodeVkBool32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint32_t queueFamilyIndex;
    VkBool32 return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queueFamilyIndex);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeVkBool32Value((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(return_value, physicalDevice, queueFamilyIndex);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFeatures2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2> pFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFeatures.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceFormatProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    StructPointerDecoder<Decoded_VkFormatProperties2> pFormatProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &format);
    bytes_read += pFormatProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFormatProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties2KHR(return_value, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2> pImageFormatInfo;
    StructPointerDecoder<Decoded_VkImageFormatProperties2> pImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pImageFormatInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pImageFormatProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pImageFormatProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceImageFormatProperties2KHR(return_value, physicalDevice, pImageFormatInfo, pImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pQueueFamilyPropertyCount;
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2> pQueueFamilyProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pQueueFamilyPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pQueueFamilyProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMemoryProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2> pMemoryProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pMemoryProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2> pFormatInfo;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2> pProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFormatInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &heapIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &localDeviceIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &remoteDeviceIndex);
    bytes_read += pPeerMemoryFeatures.DecodeFlags((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t heapIndex;
    uint32_t localDeviceIndex;
    uint32_t remoteDeviceIndex;
    PointerDecoder<VkPeerMemoryFeatureFlags> pPeerMemoryFeatures;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &heapIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &localDeviceIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &remoteDeviceIndex);
    bytes_read += pPeerMemoryFeatures.DecodeFlags((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPeerMemoryFeatures.DecodeFlags((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMaskKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &deviceMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDeviceMaskKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t deviceMask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &deviceMask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDeviceMaskKHR(commandBuffer, deviceMask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBaseKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &baseGroupX);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &baseGroupY);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &baseGroupZ);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDispatchBaseKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t baseGroupX;
    uint32_t baseGroupY;
    uint32_t baseGroupZ;
    uint32_t groupCountX;
    uint32_t groupCountY;
    uint32_t groupCountZ;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &baseGroupX);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &baseGroupY);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &baseGroupZ);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPoolKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkTrimCommandPoolKHR(device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkTrimCommandPoolKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId commandPool;
    VkCommandPoolTrimFlags flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandPool);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkTrimCommandPoolKHR(device, commandPool, flags);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroupsKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDeviceGroupsKHR(return_value, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkEnumeratePhysicalDeviceGroupsKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    PointerDecoder<uint32_t> pPhysicalDeviceGroupCount;
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties> pPhysicalDeviceGroupProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPhysicalDeviceGroupCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pPhysicalDeviceGroupProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkEnumeratePhysicalDeviceGroupsKHR(return_value, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo> pExternalBufferInfo;
    StructPointerDecoder<Decoded_VkExternalBufferProperties> pExternalBufferProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalBufferInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pExternalBufferProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pExternalBufferProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pHandle.DecodeVoidPtr((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandlePropertiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t handle;
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR> pMemoryWin32HandleProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &handle);
    bytes_read += pMemoryWin32HandleProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandlePropertiesKHR(return_value, device, handleType, handle, pMemoryWin32HandleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandlePropertiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t handle;
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR> pMemoryWin32HandleProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &handle);
    bytes_read += pMemoryWin32HandleProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryWin32HandleProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandlePropertiesKHR(return_value, device, handleType, handle, pMemoryWin32HandleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFd.DecodeInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdPropertiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    int fd;
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR> pMemoryFdProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &fd);
    bytes_read += pMemoryFdProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryFdPropertiesKHR(return_value, device, handleType, fd, pMemoryFdProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryFdPropertiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    int fd;
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR> pMemoryFdProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &fd);
    bytes_read += pMemoryFdProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryFdProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryFdPropertiesKHR(return_value, device, handleType, fd, pMemoryFdProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo> pExternalSemaphoreInfo;
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties> pExternalSemaphoreProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalSemaphoreInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pExternalSemaphoreProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pExternalSemaphoreProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreWin32HandleKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR> pImportSemaphoreWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreWin32HandleInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportSemaphoreWin32HandleKHR(return_value, device, pImportSemaphoreWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreWin32HandleKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR> pImportSemaphoreWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreWin32HandleInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportSemaphoreWin32HandleKHR(return_value, device, pImportSemaphoreWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreWin32HandleKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreWin32HandleKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pHandle.DecodeVoidPtr((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreFdKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR> pImportSemaphoreFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreFdInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportSemaphoreFdKHR(return_value, device, pImportSemaphoreFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportSemaphoreFdKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR> pImportSemaphoreFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pImportSemaphoreFdInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportSemaphoreFdKHR(return_value, device, pImportSemaphoreFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreFdKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSemaphoreFdKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFd.DecodeInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSemaphoreFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSetKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t set;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &set);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdPushDescriptorSetKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineBindPoint pipelineBindPoint;
    format::HandleId layout;
    uint32_t set;
    uint32_t descriptorWriteCount;
    StructPointerDecoder<Decoded_VkWriteDescriptorSet> pDescriptorWrites;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineBindPoint);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &set);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorWriteCount);
    bytes_read += pDescriptorWrites.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplateKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorUpdateTemplateKHR(return_value, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDescriptorUpdateTemplateKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pDescriptorUpdateTemplate;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pDescriptorUpdateTemplate.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDescriptorUpdateTemplate.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDescriptorUpdateTemplateKHR(return_value, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplateKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDescriptorUpdateTemplateKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId descriptorUpdateTemplate;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &descriptorUpdateTemplate);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pRenderPass.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRenderPass2KHR(return_value, device, pCreateInfo, pAllocator, pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRenderPass2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pRenderPass;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pRenderPass.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pRenderPass.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRenderPass2KHR(return_value, device, pCreateInfo, pAllocator, pRenderPass);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR> pSubpassBeginInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSubpassBeginInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginRenderPass2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo> pRenderPassBegin;
    StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR> pSubpassBeginInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pRenderPassBegin.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSubpassBeginInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfoKHR> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassBeginInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSubpassEndInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdNextSubpass2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR> pSubpassBeginInfo;
    StructPointerDecoder<Decoded_VkSubpassEndInfoKHR> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassBeginInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSubpassEndInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfoKHR> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassEndInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndRenderPass2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSubpassEndInfoKHR> pSubpassEndInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSubpassEndInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainStatusKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainStatusKHR(return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainStatusKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchain);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainStatusKHR(return_value, device, swapchain);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo> pExternalFenceInfo;
    StructPointerDecoder<Decoded_VkExternalFenceProperties> pExternalFenceProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pExternalFenceInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pExternalFenceProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pExternalFenceProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportFenceWin32HandleKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR> pImportFenceWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pImportFenceWin32HandleInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportFenceWin32HandleKHR(return_value, device, pImportFenceWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportFenceWin32HandleKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR> pImportFenceWin32HandleInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pImportFenceWin32HandleInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportFenceWin32HandleKHR(return_value, device, pImportFenceWin32HandleInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceWin32HandleKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceWin32HandleKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR> pGetWin32HandleInfo;
    PointerDecoder<uint64_t> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pGetWin32HandleInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pHandle.DecodeVoidPtr((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceWin32HandleKHR(return_value, device, pGetWin32HandleInfo, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportFenceFdKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR> pImportFenceFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pImportFenceFdInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportFenceFdKHR(return_value, device, pImportFenceFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkImportFenceFdKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR> pImportFenceFdInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pImportFenceFdInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkImportFenceFdKHR(return_value, device, pImportFenceFdInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceFdKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetFenceFdKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR> pGetFdInfo;
    PointerDecoder<int> pFd;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pGetFdInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pFd.DecodeInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFd.DecodeInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetFenceFdKHR(return_value, device, pGetFdInfo, pFd);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurfaceCapabilities.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(return_value, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurfaceCapabilities.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurfaceCapabilities.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(return_value, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurfaceFormatCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceFormats2KHR(return_value, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR> pSurfaceInfo;
    PointerDecoder<uint32_t> pSurfaceFormatCount;
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR> pSurfaceFormats;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pSurfaceInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurfaceFormatCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurfaceFormatCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pSurfaceFormats.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceFormats2KHR(return_value, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayProperties2KHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayProperties2KHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(return_value, physicalDevice, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModeProperties2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayModeProperties2KHR(return_value, physicalDevice, display, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayModeProperties2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    PointerDecoder<uint32_t> pPropertyCount;
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &display);
    bytes_read += pPropertyCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPropertyCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayModeProperties2KHR(return_value, physicalDevice, display, pPropertyCount, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilities2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR> pDisplayPlaneInfo;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pDisplayPlaneInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pCapabilities.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneCapabilities2KHR(return_value, physicalDevice, pDisplayPlaneInfo, pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDisplayPlaneCapabilities2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR> pDisplayPlaneInfo;
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR> pCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pDisplayPlaneInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pCapabilities.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pCapabilities.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDisplayPlaneCapabilities2KHR(return_value, physicalDevice, pDisplayPlaneInfo, pCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageMemoryRequirements2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetBufferMemoryRequirements2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetImageSparseMemoryRequirements2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2> pInfo;
    PointerDecoder<uint32_t> pSparseMemoryRequirementCount;
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2> pSparseMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSparseMemoryRequirementCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pSparseMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversionKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSamplerYcbcrConversionKHR(return_value, device, pCreateInfo, pAllocator, pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateSamplerYcbcrConversionKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pYcbcrConversion;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pYcbcrConversion.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pYcbcrConversion.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateSamplerYcbcrConversionKHR(return_value, device, pCreateInfo, pAllocator, pYcbcrConversion);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversionKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroySamplerYcbcrConversionKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId ycbcrConversion;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &ycbcrConversion);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory2KHR(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindBufferMemory2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindBufferMemory2KHR(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2KHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory2KHR(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindImageMemory2KHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindImageMemory2KHR(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupportKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSupport.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetDescriptorSetLayoutSupportKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo> pCreateInfo;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport> pSupport;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSupport.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSupport.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountKHR(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountKHR(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugReportCallbackEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pCallback;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pCallback.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDebugReportCallbackEXT(return_value, instance, pCreateInfo, pAllocator, pCallback);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugReportCallbackEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pCallback;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pCallback.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pCallback.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDebugReportCallbackEXT(return_value, instance, pCreateInfo, pAllocator, pCallback);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugReportCallbackEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId callback;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &callback);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugReportCallbackEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId callback;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &callback);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugReportMessageEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    VkDebugReportFlagsEXT flags;
    VkDebugReportObjectTypeEXT objectType;
    uint64_t object;
    size_t location;
    int32_t messageCode;
    StringDecoder pLayerPrefix;
    StringDecoder pMessage;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &objectType);
    bytes_read += ValueDecoder::DecodeUInt64Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &object);
    bytes_read += ValueDecoder::DecodeSizeTValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &location);
    bytes_read += ValueDecoder::DecodeInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &messageCode);
    bytes_read += pLayerPrefix.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMessage.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugReportMessageEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    VkDebugReportFlagsEXT flags;
    VkDebugReportObjectTypeEXT objectType;
    uint64_t object;
    size_t location;
    int32_t messageCode;
    StringDecoder pLayerPrefix;
    StringDecoder pMessage;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &objectType);
    bytes_read += ValueDecoder::DecodeUInt64Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &object);
    bytes_read += ValueDecoder::DecodeSizeTValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &location);
    bytes_read += ValueDecoder::DecodeInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &messageCode);
    bytes_read += pLayerPrefix.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMessage.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectTagEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugMarkerSetObjectTagEXT(return_value, device, pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectTagEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugMarkerSetObjectTagEXT(return_value, device, pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectNameEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugMarkerSetObjectNameEXT(return_value, device, pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDebugMarkerSetObjectNameEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDebugMarkerSetObjectNameEXT(return_value, device, pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerBeginEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerBeginEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerEndEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerEndEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerEndEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerEndEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerInsertEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDebugMarkerInsertEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT> pMarkerInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pMarkerInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountAMD(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndirectCountAMD(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountAMD(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawIndexedIndirectCountAMD(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetShaderInfoAMD(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    VkShaderStageFlagBits shaderStage;
    VkShaderInfoTypeAMD infoType;
    PointerDecoder<size_t> pInfoSize;
    PointerDecoder<uint8_t> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &shaderStage);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &infoType);
    bytes_read += pInfoSize.DecodeSizeT((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pInfo.DecodeVoid((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetShaderInfoAMD(return_value, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetShaderInfoAMD(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    VkShaderStageFlagBits shaderStage;
    VkShaderInfoTypeAMD infoType;
    PointerDecoder<size_t> pInfoSize;
    PointerDecoder<uint8_t> pInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &shaderStage);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &infoType);
    bytes_read += pInfoSize.DecodeSizeT((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pInfo.DecodeVoid((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pInfoSize.DecodeSizeT((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pInfo.DecodeVoid((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetShaderInfoAMD(return_value, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    VkExternalMemoryHandleTypeFlagsNV externalHandleType;
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV> pExternalImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &tiling);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &externalHandleType);
    bytes_read += pExternalImageFormatProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(return_value, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkFormat format;
    VkImageType type;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkImageCreateFlags flags;
    VkExternalMemoryHandleTypeFlagsNV externalHandleType;
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV> pExternalImageFormatProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &format);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &tiling);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &usage);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &externalHandleType);
    bytes_read += pExternalImageFormatProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pExternalImageFormatProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(return_value, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    VkExternalMemoryHandleTypeFlagsNV handleType;
    PointerDecoder<uint64_t> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &handleType);
    bytes_read += pHandle.DecodeVoidPtr((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandleNV(return_value, device, memory, handleType, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryWin32HandleNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId memory;
    VkExternalMemoryHandleTypeFlagsNV handleType;
    PointerDecoder<uint64_t> pHandle;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &memory);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &handleType);
    bytes_read += pHandle.DecodeVoidPtr((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pHandle.DecodeVoidPtr((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryWin32HandleNV(return_value, device, memory, handleType, pHandle);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateViSurfaceNN(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateViSurfaceNN(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateViSurfaceNN(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateViSurfaceNN(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginConditionalRenderingEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT> pConditionalRenderingBegin;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pConditionalRenderingBegin.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginConditionalRenderingEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT> pConditionalRenderingBegin;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pConditionalRenderingBegin.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndConditionalRenderingEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndConditionalRenderingEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndConditionalRenderingEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndConditionalRenderingEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdProcessCommandsNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX> pProcessCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pProcessCommandsInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdProcessCommandsNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX> pProcessCommandsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pProcessCommandsInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdReserveSpaceForCommandsNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX> pReserveSpaceInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pReserveSpaceInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdReserveSpaceForCommandsNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX> pReserveSpaceInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pReserveSpaceInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIndirectCommandsLayoutNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pIndirectCommandsLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pIndirectCommandsLayout.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateIndirectCommandsLayoutNVX(return_value, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIndirectCommandsLayoutNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pIndirectCommandsLayout;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pIndirectCommandsLayout.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pIndirectCommandsLayout.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateIndirectCommandsLayoutNVX(return_value, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyIndirectCommandsLayoutNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &indirectCommandsLayout);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyIndirectCommandsLayoutNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &indirectCommandsLayout);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateObjectTableNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pObjectTable;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pObjectTable.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateObjectTableNVX(return_value, device, pCreateInfo, pAllocator, pObjectTable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateObjectTableNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pObjectTable;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pObjectTable.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pObjectTable.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateObjectTableNVX(return_value, device, pCreateInfo, pAllocator, pObjectTable);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyObjectTableNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId objectTable;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &objectTable);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyObjectTableNVX(device, objectTable, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyObjectTableNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId objectTable;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &objectTable);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyObjectTableNVX(device, objectTable, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnregisterObjectsNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId objectTable;
    uint32_t objectCount;
    PointerDecoder<VkObjectEntryTypeNVX> pObjectEntryTypes;
    PointerDecoder<uint32_t> pObjectIndices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &objectTable);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &objectCount);
    bytes_read += pObjectEntryTypes.DecodeEnum((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pObjectIndices.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUnregisterObjectsNVX(return_value, device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkUnregisterObjectsNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId objectTable;
    uint32_t objectCount;
    PointerDecoder<VkObjectEntryTypeNVX> pObjectEntryTypes;
    PointerDecoder<uint32_t> pObjectIndices;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &objectTable);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &objectCount);
    bytes_read += pObjectEntryTypes.DecodeEnum((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pObjectIndices.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkUnregisterObjectsNVX(return_value, device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX> pFeatures;
    StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX> pLimits;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pLimits.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX> pFeatures;
    StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX> pLimits;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += pFeatures.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pLimits.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFeatures.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pLimits.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWScalingNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewportWScalings.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportWScalingNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &viewportCount);
    bytes_read += pViewportWScalings.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseDisplayEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkReleaseDisplayEXT(return_value, physicalDevice, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkReleaseDisplayEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &display);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkReleaseDisplayEXT(return_value, physicalDevice, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireXlibDisplayEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint64_t dpy;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &display);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireXlibDisplayEXT(return_value, physicalDevice, dpy, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkAcquireXlibDisplayEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint64_t dpy;
    format::HandleId display;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &display);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkAcquireXlibDisplayEXT(return_value, physicalDevice, dpy, display);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRandROutputDisplayEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint64_t dpy;
    size_t rrOutput;
    PointerDecoder<format::HandleId> pDisplay;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeSizeTValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &rrOutput);
    bytes_read += pDisplay.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRandROutputDisplayEXT(return_value, physicalDevice, dpy, rrOutput, pDisplay);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRandROutputDisplayEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    uint64_t dpy;
    size_t rrOutput;
    PointerDecoder<format::HandleId> pDisplay;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dpy);
    bytes_read += ValueDecoder::DecodeSizeTValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &rrOutput);
    bytes_read += pDisplay.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDisplay.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRandROutputDisplayEXT(return_value, physicalDevice, dpy, rrOutput, pDisplay);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(return_value, physicalDevice, surface, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    format::HandleId surface;
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT> pSurfaceCapabilities;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &surface);
    bytes_read += pSurfaceCapabilities.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurfaceCapabilities.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(return_value, physicalDevice, surface, pSurfaceCapabilities);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDisplayPowerControlEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT> pDisplayPowerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &display);
    bytes_read += pDisplayPowerInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDisplayPowerControlEXT(return_value, device, display, pDisplayPowerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDisplayPowerControlEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT> pDisplayPowerInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &display);
    bytes_read += pDisplayPowerInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDisplayPowerControlEXT(return_value, device, display, pDisplayPowerInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDeviceEventEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT> pDeviceEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pDeviceEventInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkRegisterDeviceEventEXT(return_value, device, pDeviceEventInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDeviceEventEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT> pDeviceEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pDeviceEventInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFence.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkRegisterDeviceEventEXT(return_value, device, pDeviceEventInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDisplayEventEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT> pDisplayEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &display);
    bytes_read += pDisplayEventInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkRegisterDisplayEventEXT(return_value, device, display, pDisplayEventInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkRegisterDisplayEventEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId display;
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT> pDisplayEventInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pFence;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &display);
    bytes_read += pDisplayEventInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pFence.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pFence.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkRegisterDisplayEventEXT(return_value, device, display, pDisplayEventInfo, pAllocator, pFence);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainCounterEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkSurfaceCounterFlagBitsEXT counter;
    PointerDecoder<uint64_t> pCounterValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &counter);
    bytes_read += pCounterValue.DecodeUInt64((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainCounterEXT(return_value, device, swapchain, counter, pCounterValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetSwapchainCounterEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    VkSurfaceCounterFlagBitsEXT counter;
    PointerDecoder<uint64_t> pCounterValue;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchain);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &counter);
    bytes_read += pCounterValue.DecodeUInt64((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pCounterValue.DecodeUInt64((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetSwapchainCounterEXT(return_value, device, swapchain, counter, pCounterValue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRefreshCycleDurationGOOGLE(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE> pDisplayTimingProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchain);
    bytes_read += pDisplayTimingProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRefreshCycleDurationGOOGLE(return_value, device, swapchain, pDisplayTimingProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRefreshCycleDurationGOOGLE(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE> pDisplayTimingProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchain);
    bytes_read += pDisplayTimingProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDisplayTimingProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRefreshCycleDurationGOOGLE(return_value, device, swapchain, pDisplayTimingProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPastPresentationTimingGOOGLE(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pPresentationTimingCount;
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE> pPresentationTimings;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchain);
    bytes_read += pPresentationTimingCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPresentationTimings.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPastPresentationTimingGOOGLE(return_value, device, swapchain, pPresentationTimingCount, pPresentationTimings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPastPresentationTimingGOOGLE(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId swapchain;
    PointerDecoder<uint32_t> pPresentationTimingCount;
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE> pPresentationTimings;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchain);
    bytes_read += pPresentationTimingCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPresentationTimings.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPresentationTimingCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pPresentationTimings.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPastPresentationTimingGOOGLE(return_value, device, swapchain, pPresentationTimingCount, pPresentationTimings);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDiscardRectangleEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstDiscardRectangle;
    uint32_t discardRectangleCount;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstDiscardRectangle);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &discardRectangleCount);
    bytes_read += pDiscardRectangles.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetDiscardRectangleEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstDiscardRectangle;
    uint32_t discardRectangleCount;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstDiscardRectangle);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &discardRectangleCount);
    bytes_read += pDiscardRectangles.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetHdrMetadataEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t swapchainCount;
    PointerDecoder<format::HandleId> pSwapchains;
    StructPointerDecoder<Decoded_VkHdrMetadataEXT> pMetadata;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &swapchainCount);
    bytes_read += pSwapchains.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMetadata.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetHdrMetadataEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t swapchainCount;
    PointerDecoder<format::HandleId> pSwapchains;
    StructPointerDecoder<Decoded_VkHdrMetadataEXT> pMetadata;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &swapchainCount);
    bytes_read += pSwapchains.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMetadata.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIOSSurfaceMVK(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateIOSSurfaceMVK(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateIOSSurfaceMVK(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateIOSSurfaceMVK(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMacOSSurfaceMVK(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateMacOSSurfaceMVK(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateMacOSSurfaceMVK(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateMacOSSurfaceMVK(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectNameEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetDebugUtilsObjectNameEXT(return_value, device, pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectNameEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pNameInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pNameInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetDebugUtilsObjectNameEXT(return_value, device, pNameInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectTagEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetDebugUtilsObjectTagEXT(return_value, device, pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSetDebugUtilsObjectTagEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT> pTagInfo;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pTagInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSetDebugUtilsObjectTagEXT(return_value, device, pTagInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBeginDebugUtilsLabelEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueBeginDebugUtilsLabelEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueEndDebugUtilsLabelEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queue);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueEndDebugUtilsLabelEXT(queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueEndDebugUtilsLabelEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queue);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueEndDebugUtilsLabelEXT(queue);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueInsertDebugUtilsLabelEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkQueueInsertDebugUtilsLabelEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queue);
    bytes_read += pLabelInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkQueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginDebugUtilsLabelEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBeginDebugUtilsLabelEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndDebugUtilsLabelEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdEndDebugUtilsLabelEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdEndDebugUtilsLabelEXT(commandBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdInsertDebugUtilsLabelEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdInsertDebugUtilsLabelEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pLabelInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pLabelInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugUtilsMessengerEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pMessenger;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMessenger.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDebugUtilsMessengerEXT(return_value, instance, pCreateInfo, pAllocator, pMessenger);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateDebugUtilsMessengerEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pMessenger;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMessenger.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMessenger.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateDebugUtilsMessengerEXT(return_value, instance, pCreateInfo, pAllocator, pMessenger);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugUtilsMessengerEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId messenger;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &messenger);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyDebugUtilsMessengerEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    format::HandleId messenger;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &messenger);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSubmitDebugUtilsMessageEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT messageTypes;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT> pCallbackData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &messageSeverity);
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &messageTypes);
    bytes_read += pCallbackData.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkSubmitDebugUtilsMessageEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity;
    VkDebugUtilsMessageTypeFlagsEXT messageTypes;
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT> pCallbackData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &messageSeverity);
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &messageTypes);
    bytes_read += pCallbackData.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkSubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAndroidHardwareBufferPropertiesANDROID(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint64_t buffer;
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += pProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAndroidHardwareBufferPropertiesANDROID(return_value, device, buffer, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAndroidHardwareBufferPropertiesANDROID(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint64_t buffer;
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID> pProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += pProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAndroidHardwareBufferPropertiesANDROID(return_value, device, buffer, pProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryAndroidHardwareBufferANDROID(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID> pInfo;
    PointerDecoder<uint64_t> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pBuffer.DecodeVoidPtr((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryAndroidHardwareBufferANDROID(return_value, device, pInfo, pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryAndroidHardwareBufferANDROID(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID> pInfo;
    PointerDecoder<uint64_t> pBuffer;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pBuffer.DecodeVoidPtr((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pBuffer.DecodeVoidPtr((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryAndroidHardwareBufferANDROID(return_value, device, pInfo, pBuffer);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetSampleLocationsEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSampleLocationsInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetSampleLocationsEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT> pSampleLocationsInfo;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += pSampleLocationsInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkSampleCountFlagBits samples;
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT> pMultisampleProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &samples);
    bytes_read += pMultisampleProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId physicalDevice;
    VkSampleCountFlagBits samples;
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT> pMultisampleProperties;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &physicalDevice);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &samples);
    bytes_read += pMultisampleProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMultisampleProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateValidationCacheEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pValidationCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pValidationCache.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateValidationCacheEXT(return_value, device, pCreateInfo, pAllocator, pValidationCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateValidationCacheEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pValidationCache;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pValidationCache.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pValidationCache.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateValidationCacheEXT(return_value, device, pCreateInfo, pAllocator, pValidationCache);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyValidationCacheEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId validationCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &validationCache);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyValidationCacheEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId validationCache;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &validationCache);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyValidationCacheEXT(device, validationCache, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergeValidationCachesEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    PointerDecoder<format::HandleId> pSrcCaches;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &srcCacheCount);
    bytes_read += pSrcCaches.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMergeValidationCachesEXT(return_value, device, dstCache, srcCacheCount, pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkMergeValidationCachesEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId dstCache;
    uint32_t srcCacheCount;
    PointerDecoder<format::HandleId> pSrcCaches;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &srcCacheCount);
    bytes_read += pSrcCaches.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkMergeValidationCachesEXT(return_value, device, dstCache, srcCacheCount, pSrcCaches);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetValidationCacheDataEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId validationCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &validationCache);
    bytes_read += pDataSize.DecodeSizeT((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetValidationCacheDataEXT(return_value, device, validationCache, pDataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetValidationCacheDataEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId validationCache;
    PointerDecoder<size_t> pDataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &validationCache);
    bytes_read += pDataSize.DecodeSizeT((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pDataSize.DecodeSizeT((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetValidationCacheDataEXT(return_value, device, validationCache, pDataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindShadingRateImageNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &imageView);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &imageLayout);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBindShadingRateImageNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId imageView;
    VkImageLayout imageLayout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &imageView);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &imageLayout);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportShadingRatePaletteNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV> pShadingRatePalettes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &viewportCount);
    bytes_read += pShadingRatePalettes.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetViewportShadingRatePaletteNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstViewport;
    uint32_t viewportCount;
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV> pShadingRatePalettes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstViewport);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &viewportCount);
    bytes_read += pShadingRatePalettes.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoarseSampleOrderNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCoarseSampleOrderTypeNV sampleOrderType;
    uint32_t customSampleOrderCount;
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV> pCustomSampleOrders;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &sampleOrderType);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &customSampleOrderCount);
    bytes_read += pCustomSampleOrders.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCoarseSampleOrderNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkCoarseSampleOrderTypeNV sampleOrderType;
    uint32_t customSampleOrderCount;
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV> pCustomSampleOrders;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &sampleOrderType);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &customSampleOrderCount);
    bytes_read += pCustomSampleOrders.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAccelerationStructureNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNVX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pAccelerationStructure;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAccelerationStructure.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateAccelerationStructureNVX(return_value, device, pCreateInfo, pAllocator, pAccelerationStructure);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateAccelerationStructureNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNVX> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pAccelerationStructure;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAccelerationStructure.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pAccelerationStructure.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateAccelerationStructureNVX(return_value, device, pCreateInfo, pAllocator, pAccelerationStructure);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyAccelerationStructureNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &accelerationStructure);
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyAccelerationStructureNVX(device, accelerationStructure, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkDestroyAccelerationStructureNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &accelerationStructure);
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkDestroyAccelerationStructureNVX(device, accelerationStructure, pAllocator);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureMemoryRequirementsNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNVX> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureMemoryRequirementsNVX(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureMemoryRequirementsNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNVX> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureMemoryRequirementsNVX(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureScratchMemoryRequirementsNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNVX> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureScratchMemoryRequirementsNVX(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureScratchMemoryRequirementsNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNVX> pInfo;
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR> pMemoryRequirements;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += pInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pMemoryRequirements.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryRequirements.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureScratchMemoryRequirementsNVX(device, pInfo, pMemoryRequirements);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindAccelerationStructureMemoryNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNVX> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindAccelerationStructureMemoryNVX(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkBindAccelerationStructureMemoryNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    uint32_t bindInfoCount;
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNVX> pBindInfos;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &bindInfoCount);
    bytes_read += pBindInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkBindAccelerationStructureMemoryNVX(return_value, device, bindInfoCount, pBindInfos);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBuildAccelerationStructureNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkAccelerationStructureTypeNVX type;
    uint32_t instanceCount;
    format::HandleId instanceData;
    VkDeviceSize instanceOffset;
    uint32_t geometryCount;
    StructPointerDecoder<Decoded_VkGeometryNVX> pGeometries;
    VkBuildAccelerationStructureFlagsNVX flags;
    VkBool32 update;
    format::HandleId dst;
    format::HandleId src;
    format::HandleId scratch;
    VkDeviceSize scratchOffset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instanceData);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instanceOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &geometryCount);
    bytes_read += pGeometries.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeVkBool32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &update);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dst);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &src);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &scratch);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &scratchOffset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBuildAccelerationStructureNVX(commandBuffer, type, instanceCount, instanceData, instanceOffset, geometryCount, pGeometries, flags, update, dst, src, scratch, scratchOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdBuildAccelerationStructureNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkAccelerationStructureTypeNVX type;
    uint32_t instanceCount;
    format::HandleId instanceData;
    VkDeviceSize instanceOffset;
    uint32_t geometryCount;
    StructPointerDecoder<Decoded_VkGeometryNVX> pGeometries;
    VkBuildAccelerationStructureFlagsNVX flags;
    VkBool32 update;
    format::HandleId dst;
    format::HandleId src;
    format::HandleId scratch;
    VkDeviceSize scratchOffset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instanceCount);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instanceData);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instanceOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &geometryCount);
    bytes_read += pGeometries.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeFlagsValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeVkBool32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &update);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dst);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &src);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &scratch);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &scratchOffset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdBuildAccelerationStructureNVX(commandBuffer, type, instanceCount, instanceData, instanceOffset, geometryCount, pGeometries, flags, update, dst, src, scratch, scratchOffset);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyAccelerationStructureNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dst;
    format::HandleId src;
    VkCopyAccelerationStructureModeNVX mode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dst);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &src);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &mode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyAccelerationStructureNVX(commandBuffer, dst, src, mode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdCopyAccelerationStructureNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId dst;
    format::HandleId src;
    VkCopyAccelerationStructureModeNVX mode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dst);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &src);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &mode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdCopyAccelerationStructureNVX(commandBuffer, dst, src, mode);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId raygenShaderBindingTableBuffer;
    VkDeviceSize raygenShaderBindingOffset;
    format::HandleId missShaderBindingTableBuffer;
    VkDeviceSize missShaderBindingOffset;
    VkDeviceSize missShaderBindingStride;
    format::HandleId hitShaderBindingTableBuffer;
    VkDeviceSize hitShaderBindingOffset;
    VkDeviceSize hitShaderBindingStride;
    uint32_t width;
    uint32_t height;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &raygenShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &raygenShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &missShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &missShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &missShaderBindingStride);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &hitShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &hitShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &hitShaderBindingStride);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &width);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &height);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdTraceRaysNVX(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, width, height);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdTraceRaysNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId raygenShaderBindingTableBuffer;
    VkDeviceSize raygenShaderBindingOffset;
    format::HandleId missShaderBindingTableBuffer;
    VkDeviceSize missShaderBindingOffset;
    VkDeviceSize missShaderBindingStride;
    format::HandleId hitShaderBindingTableBuffer;
    VkDeviceSize hitShaderBindingOffset;
    VkDeviceSize hitShaderBindingStride;
    uint32_t width;
    uint32_t height;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &raygenShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &raygenShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &missShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &missShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &missShaderBindingStride);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &hitShaderBindingTableBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &hitShaderBindingOffset);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &hitShaderBindingStride);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &width);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &height);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdTraceRaysNVX(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, width, height);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRaytracingPipelinesNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkRaytracingPipelineCreateInfoNVX> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pPipelines.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRaytracingPipelinesNVX(return_value, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateRaytracingPipelinesNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipelineCache;
    uint32_t createInfoCount;
    StructPointerDecoder<Decoded_VkRaytracingPipelineCreateInfoNVX> pCreateInfos;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pPipelines;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineCache);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &createInfoCount);
    bytes_read += pCreateInfos.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pPipelines.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pPipelines.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateRaytracingPipelinesNVX(return_value, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRaytracingShaderHandlesNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t firstGroup;
    uint32_t groupCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstGroup);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &groupCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRaytracingShaderHandlesNVX(return_value, device, pipeline, firstGroup, groupCount, dataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetRaytracingShaderHandlesNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t firstGroup;
    uint32_t groupCount;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstGroup);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &groupCount);
    bytes_read += ValueDecoder::DecodeSizeTValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pData.DecodeVoid((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetRaytracingShaderHandlesNVX(return_value, device, pipeline, firstGroup, groupCount, dataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureHandleNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &accelerationStructure);
    bytes_read += ValueDecoder::DecodeSizeTValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureHandleNVX(return_value, device, accelerationStructure, dataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetAccelerationStructureHandleNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId accelerationStructure;
    size_t dataSize;
    PointerDecoder<uint8_t> pData;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &accelerationStructure);
    bytes_read += ValueDecoder::DecodeSizeTValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dataSize);
    bytes_read += pData.DecodeVoid((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pData.DecodeVoid((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetAccelerationStructureHandleNVX(return_value, device, accelerationStructure, dataSize, pData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteAccelerationStructurePropertiesNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId accelerationStructure;
    VkQueryType queryType;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &accelerationStructure);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteAccelerationStructurePropertiesNVX(commandBuffer, accelerationStructure, queryType, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteAccelerationStructurePropertiesNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId accelerationStructure;
    VkQueryType queryType;
    format::HandleId queryPool;
    uint32_t query;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &accelerationStructure);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryType);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queryPool);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &query);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteAccelerationStructurePropertiesNVX(commandBuffer, accelerationStructure, queryType, queryPool, query);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCompileDeferredNVX(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t shader;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &shader);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCompileDeferredNVX(return_value, device, pipeline, shader);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCompileDeferredNVX(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    format::HandleId pipeline;
    uint32_t shader;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipeline);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &shader);

    bytes_read = 0;
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCompileDeferredNVX(return_value, device, pipeline, shader);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryHostPointerPropertiesEXT(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t pHostPointer;
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT> pMemoryHostPointerProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pHostPointer);
    bytes_read += pMemoryHostPointerProperties.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryHostPointerPropertiesEXT(return_value, device, handleType, pHostPointer, pMemoryHostPointerProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetMemoryHostPointerPropertiesEXT(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId device;
    VkExternalMemoryHandleTypeFlagBits handleType;
    uint64_t pHostPointer;
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT> pMemoryHostPointerProperties;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &device);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &handleType);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pHostPointer);
    bytes_read += pMemoryHostPointerProperties.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pMemoryHostPointerProperties.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetMemoryHostPointerPropertiesEXT(return_value, device, handleType, pHostPointer, pMemoryHostPointerProperties);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteBufferMarkerAMD(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pipelineStage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &marker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdWriteBufferMarkerAMD(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    VkPipelineStageFlagBits pipelineStage;
    format::HandleId dstBuffer;
    VkDeviceSize dstOffset;
    uint32_t marker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeEnumValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pipelineStage);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &dstOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &marker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t taskCount;
    uint32_t firstTask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &taskCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstTask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t taskCount;
    uint32_t firstTask;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &taskCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstTask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    uint32_t drawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &drawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectCountNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdDrawMeshTasksIndirectCountNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    format::HandleId buffer;
    VkDeviceSize offset;
    format::HandleId countBuffer;
    VkDeviceSize countBufferOffset;
    uint32_t maxDrawCount;
    uint32_t stride;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &buffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &offset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBuffer);
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &countBufferOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &maxDrawCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &stride);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetExclusiveScissorNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pExclusiveScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &firstExclusiveScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((param_buffer + bytes_read), (param_buffer_size - bytes_read), &exclusiveScissorCount);
    bytes_read += pExclusiveScissors.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetExclusiveScissorNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint32_t firstExclusiveScissor;
    uint32_t exclusiveScissorCount;
    StructPointerDecoder<Decoded_VkRect2D> pExclusiveScissors;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &firstExclusiveScissor);
    bytes_read += ValueDecoder::DecodeUInt32Value((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &exclusiveScissorCount);
    bytes_read += pExclusiveScissors.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCheckpointNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint64_t pCheckpointMarker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeAddress((param_buffer + bytes_read), (param_buffer_size - bytes_read), &pCheckpointMarker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCmdSetCheckpointNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId commandBuffer;
    uint64_t pCheckpointMarker;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &commandBuffer);
    bytes_read += ValueDecoder::DecodeAddress((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &pCheckpointMarker);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueueCheckpointDataNV(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointDataNV> pCheckpointData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &queue);
    bytes_read += pCheckpointDataCount.DecodeUInt32((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pCheckpointData.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkGetQueueCheckpointDataNV(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId queue;
    PointerDecoder<uint32_t> pCheckpointDataCount;
    StructPointerDecoder<Decoded_VkCheckpointDataNV> pCheckpointData;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &queue);
    bytes_read += pCheckpointDataCount.DecodeUInt32((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pCheckpointData.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pCheckpointDataCount.DecodeUInt32((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += pCheckpointData.Decode((post_buffer + bytes_read), (post_buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkGetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImagePipeSurfaceFUCHSIA(const uint8_t* param_buffer, size_t param_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((param_buffer + bytes_read), (param_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((param_buffer + bytes_read), (param_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImagePipeSurfaceFUCHSIA(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

size_t VulkanDecoder::Decode_vkCreateImagePipeSurfaceFUCHSIA(const uint8_t* pre_buffer, size_t pre_buffer_size, const uint8_t* post_buffer, size_t post_buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId instance;
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA> pCreateInfo;
    StructPointerDecoder<Decoded_VkAllocationCallbacks> pAllocator;
    PointerDecoder<format::HandleId> pSurface;
    VkResult return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((pre_buffer + bytes_read), (pre_buffer_size - bytes_read), &instance);
    bytes_read += pCreateInfo.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pAllocator.Decode((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));
    bytes_read += pSurface.DecodeHandleId((pre_buffer + bytes_read), (pre_buffer_size - bytes_read));

    bytes_read = 0;
    bytes_read += pSurface.DecodeHandleId((post_buffer + bytes_read), (post_buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((post_buffer + bytes_read), (post_buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_vkCreateImagePipeSurfaceFUCHSIA(return_value, instance, pCreateInfo, pAllocator, pSurface);
    }

    return bytes_read;
}

void VulkanDecoder::DecodeFunctionCall(format::ApiCallId             call_id,
                                       const format::ApiCallOptions& call_options,
                                       const uint8_t*                param_buffer,
                                       size_t                        param_buffer_size)
{
    switch(call_id)
    {
    default:
        VulkanDecoderBase::DecodeFunctionCall(call_id, call_options, param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateInstance:
        Decode_vkCreateInstance(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyInstance:
        Decode_vkDestroyInstance(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices:
        Decode_vkEnumeratePhysicalDevices(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures:
        Decode_vkGetPhysicalDeviceFeatures(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties:
        Decode_vkGetPhysicalDeviceFormatProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties:
        Decode_vkGetPhysicalDeviceImageFormatProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties:
        Decode_vkGetPhysicalDeviceProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties:
        Decode_vkGetPhysicalDeviceMemoryProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDevice:
        Decode_vkCreateDevice(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDevice:
        Decode_vkDestroyDevice(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceQueue:
        Decode_vkGetDeviceQueue(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueSubmit:
        Decode_vkQueueSubmit(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueWaitIdle:
        Decode_vkQueueWaitIdle(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDeviceWaitIdle:
        Decode_vkDeviceWaitIdle(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateMemory:
        Decode_vkAllocateMemory(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeMemory:
        Decode_vkFreeMemory(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMapMemory:
        Decode_vkMapMemory(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUnmapMemory:
        Decode_vkUnmapMemory(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges:
        Decode_vkFlushMappedMemoryRanges(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges:
        Decode_vkInvalidateMappedMemoryRanges(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment:
        Decode_vkGetDeviceMemoryCommitment(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory:
        Decode_vkBindBufferMemory(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory:
        Decode_vkBindImageMemory(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements:
        Decode_vkGetBufferMemoryRequirements(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements:
        Decode_vkGetImageMemoryRequirements(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements:
        Decode_vkGetImageSparseMemoryRequirements(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueBindSparse:
        Decode_vkQueueBindSparse(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateFence:
        Decode_vkCreateFence(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyFence:
        Decode_vkDestroyFence(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetFences:
        Decode_vkResetFences(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceStatus:
        Decode_vkGetFenceStatus(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitForFences:
        Decode_vkWaitForFences(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSemaphore:
        Decode_vkCreateSemaphore(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySemaphore:
        Decode_vkDestroySemaphore(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateEvent:
        Decode_vkCreateEvent(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyEvent:
        Decode_vkDestroyEvent(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetEventStatus:
        Decode_vkGetEventStatus(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetEvent:
        Decode_vkSetEvent(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetEvent:
        Decode_vkResetEvent(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateQueryPool:
        Decode_vkCreateQueryPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyQueryPool:
        Decode_vkDestroyQueryPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueryPoolResults:
        Decode_vkGetQueryPoolResults(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateBuffer:
        Decode_vkCreateBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyBuffer:
        Decode_vkDestroyBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateBufferView:
        Decode_vkCreateBufferView(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyBufferView:
        Decode_vkDestroyBufferView(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImage:
        Decode_vkCreateImage(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyImage:
        Decode_vkDestroyImage(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSubresourceLayout:
        Decode_vkGetImageSubresourceLayout(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImageView:
        Decode_vkCreateImageView(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyImageView:
        Decode_vkDestroyImageView(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateShaderModule:
        Decode_vkCreateShaderModule(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyShaderModule:
        Decode_vkDestroyShaderModule(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePipelineCache:
        Decode_vkCreatePipelineCache(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipelineCache:
        Decode_vkDestroyPipelineCache(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineCacheData:
        Decode_vkGetPipelineCacheData(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMergePipelineCaches:
        Decode_vkMergePipelineCaches(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateGraphicsPipelines:
        Decode_vkCreateGraphicsPipelines(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateComputePipelines:
        Decode_vkCreateComputePipelines(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipeline:
        Decode_vkDestroyPipeline(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePipelineLayout:
        Decode_vkCreatePipelineLayout(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipelineLayout:
        Decode_vkDestroyPipelineLayout(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSampler:
        Decode_vkCreateSampler(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySampler:
        Decode_vkDestroySampler(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout:
        Decode_vkCreateDescriptorSetLayout(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout:
        Decode_vkDestroyDescriptorSetLayout(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorPool:
        Decode_vkCreateDescriptorPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorPool:
        Decode_vkDestroyDescriptorPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetDescriptorPool:
        Decode_vkResetDescriptorPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateDescriptorSets:
        Decode_vkAllocateDescriptorSets(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeDescriptorSets:
        Decode_vkFreeDescriptorSets(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUpdateDescriptorSets:
        Decode_vkUpdateDescriptorSets(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateFramebuffer:
        Decode_vkCreateFramebuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyFramebuffer:
        Decode_vkDestroyFramebuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass:
        Decode_vkCreateRenderPass(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyRenderPass:
        Decode_vkDestroyRenderPass(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRenderAreaGranularity:
        Decode_vkGetRenderAreaGranularity(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateCommandPool:
        Decode_vkCreateCommandPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyCommandPool:
        Decode_vkDestroyCommandPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetCommandPool:
        Decode_vkResetCommandPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateCommandBuffers:
        Decode_vkAllocateCommandBuffers(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeCommandBuffers:
        Decode_vkFreeCommandBuffers(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBeginCommandBuffer:
        Decode_vkBeginCommandBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEndCommandBuffer:
        Decode_vkEndCommandBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetCommandBuffer:
        Decode_vkResetCommandBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindPipeline:
        Decode_vkCmdBindPipeline(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewport:
        Decode_vkCmdSetViewport(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetScissor:
        Decode_vkCmdSetScissor(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineWidth:
        Decode_vkCmdSetLineWidth(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBias:
        Decode_vkCmdSetDepthBias(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetBlendConstants:
        Decode_vkCmdSetBlendConstants(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBounds:
        Decode_vkCmdSetDepthBounds(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask:
        Decode_vkCmdSetStencilCompareMask(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask:
        Decode_vkCmdSetStencilWriteMask(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilReference:
        Decode_vkCmdSetStencilReference(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindDescriptorSets:
        Decode_vkCmdBindDescriptorSets(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindIndexBuffer:
        Decode_vkCmdBindIndexBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindVertexBuffers:
        Decode_vkCmdBindVertexBuffers(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDraw:
        Decode_vkCmdDraw(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexed:
        Decode_vkCmdDrawIndexed(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirect:
        Decode_vkCmdDrawIndirect(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect:
        Decode_vkCmdDrawIndexedIndirect(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatch:
        Decode_vkCmdDispatch(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchIndirect:
        Decode_vkCmdDispatchIndirect(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBuffer:
        Decode_vkCmdCopyBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImage:
        Decode_vkCmdCopyImage(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBlitImage:
        Decode_vkCmdBlitImage(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBufferToImage:
        Decode_vkCmdCopyBufferToImage(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer:
        Decode_vkCmdCopyImageToBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdUpdateBuffer:
        Decode_vkCmdUpdateBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdFillBuffer:
        Decode_vkCmdFillBuffer(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearColorImage:
        Decode_vkCmdClearColorImage(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage:
        Decode_vkCmdClearDepthStencilImage(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearAttachments:
        Decode_vkCmdClearAttachments(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResolveImage:
        Decode_vkCmdResolveImage(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetEvent:
        Decode_vkCmdSetEvent(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetEvent:
        Decode_vkCmdResetEvent(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWaitEvents:
        Decode_vkCmdWaitEvents(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPipelineBarrier:
        Decode_vkCmdPipelineBarrier(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginQuery:
        Decode_vkCmdBeginQuery(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndQuery:
        Decode_vkCmdEndQuery(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetQueryPool:
        Decode_vkCmdResetQueryPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteTimestamp:
        Decode_vkCmdWriteTimestamp(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults:
        Decode_vkCmdCopyQueryPoolResults(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushConstants:
        Decode_vkCmdPushConstants(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass:
        Decode_vkCmdBeginRenderPass(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass:
        Decode_vkCmdNextSubpass(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass:
        Decode_vkCmdEndRenderPass(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdExecuteCommands:
        Decode_vkCmdExecuteCommands(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory2:
        Decode_vkBindBufferMemory2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory2:
        Decode_vkBindImageMemory2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures:
        Decode_vkGetDeviceGroupPeerMemoryFeatures(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDeviceMask:
        Decode_vkCmdSetDeviceMask(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchBase:
        Decode_vkCmdDispatchBase(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups:
        Decode_vkEnumeratePhysicalDeviceGroups(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2:
        Decode_vkGetImageMemoryRequirements2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2:
        Decode_vkGetBufferMemoryRequirements2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2:
        Decode_vkGetImageSparseMemoryRequirements2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2:
        Decode_vkGetPhysicalDeviceFeatures2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2:
        Decode_vkGetPhysicalDeviceProperties2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2:
        Decode_vkGetPhysicalDeviceFormatProperties2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2:
        Decode_vkGetPhysicalDeviceImageFormatProperties2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2:
        Decode_vkGetPhysicalDeviceMemoryProperties2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTrimCommandPool:
        Decode_vkTrimCommandPool(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceQueue2:
        Decode_vkGetDeviceQueue2(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion:
        Decode_vkCreateSamplerYcbcrConversion(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion:
        Decode_vkDestroySamplerYcbcrConversion(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate:
        Decode_vkCreateDescriptorUpdateTemplate(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate:
        Decode_vkDestroyDescriptorUpdateTemplate(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties:
        Decode_vkGetPhysicalDeviceExternalBufferProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties:
        Decode_vkGetPhysicalDeviceExternalFenceProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties:
        Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport:
        Decode_vkGetDescriptorSetLayoutSupport(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySurfaceKHR:
        Decode_vkDestroySurfaceKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR:
        Decode_vkGetPhysicalDeviceSurfaceSupportKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR:
        Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR:
        Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR:
        Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSwapchainKHR:
        Decode_vkCreateSwapchainKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySwapchainKHR:
        Decode_vkDestroySwapchainKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR:
        Decode_vkGetSwapchainImagesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireNextImageKHR:
        Decode_vkAcquireNextImageKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueuePresentKHR:
        Decode_vkQueuePresentKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR:
        Decode_vkGetDeviceGroupPresentCapabilitiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR:
        Decode_vkGetDeviceGroupSurfacePresentModesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR:
        Decode_vkGetPhysicalDevicePresentRectanglesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireNextImage2KHR:
        Decode_vkAcquireNextImage2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR:
        Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR:
        Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR:
        Decode_vkGetDisplayPlaneSupportedDisplaysKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR:
        Decode_vkGetDisplayModePropertiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDisplayModeKHR:
        Decode_vkCreateDisplayModeKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR:
        Decode_vkGetDisplayPlaneCapabilitiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR:
        Decode_vkCreateDisplayPlaneSurfaceKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR:
        Decode_vkCreateSharedSwapchainsKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR:
        Decode_vkCreateXlibSurfaceKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR:
        Decode_vkCreateXcbSurfaceKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR:
        Decode_vkCreateWaylandSurfaceKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR:
        Decode_vkCreateMirSurfaceKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceMirPresentationSupportKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR:
        Decode_vkCreateAndroidSurfaceKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR:
        Decode_vkCreateWin32SurfaceKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR:
        Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR:
        Decode_vkGetPhysicalDeviceFeatures2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR:
        Decode_vkGetPhysicalDeviceProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceFormatProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR:
        Decode_vkGetPhysicalDeviceMemoryProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR:
        Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR:
        Decode_vkCmdSetDeviceMaskKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR:
        Decode_vkCmdDispatchBaseKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTrimCommandPoolKHR:
        Decode_vkTrimCommandPoolKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR:
        Decode_vkEnumeratePhysicalDeviceGroupsKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR:
        Decode_vkGetMemoryWin32HandleKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR:
        Decode_vkGetMemoryWin32HandlePropertiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryFdKHR:
        Decode_vkGetMemoryFdKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR:
        Decode_vkGetMemoryFdPropertiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR:
        Decode_vkImportSemaphoreWin32HandleKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR:
        Decode_vkGetSemaphoreWin32HandleKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR:
        Decode_vkImportSemaphoreFdKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR:
        Decode_vkGetSemaphoreFdKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR:
        Decode_vkCmdPushDescriptorSetKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR:
        Decode_vkCreateDescriptorUpdateTemplateKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR:
        Decode_vkDestroyDescriptorUpdateTemplateKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass2KHR:
        Decode_vkCreateRenderPass2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR:
        Decode_vkCmdBeginRenderPass2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR:
        Decode_vkCmdNextSubpass2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR:
        Decode_vkCmdEndRenderPass2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR:
        Decode_vkGetSwapchainStatusKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR:
        Decode_vkImportFenceWin32HandleKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR:
        Decode_vkGetFenceWin32HandleKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportFenceFdKHR:
        Decode_vkImportFenceFdKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceFdKHR:
        Decode_vkGetFenceFdKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR:
        Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR:
        Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR:
        Decode_vkGetPhysicalDeviceDisplayProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR:
        Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR:
        Decode_vkGetDisplayModeProperties2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR:
        Decode_vkGetDisplayPlaneCapabilities2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR:
        Decode_vkGetImageMemoryRequirements2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR:
        Decode_vkGetBufferMemoryRequirements2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR:
        Decode_vkGetImageSparseMemoryRequirements2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR:
        Decode_vkCreateSamplerYcbcrConversionKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR:
        Decode_vkDestroySamplerYcbcrConversionKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory2KHR:
        Decode_vkBindBufferMemory2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory2KHR:
        Decode_vkBindImageMemory2KHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR:
        Decode_vkGetDescriptorSetLayoutSupportKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR:
        Decode_vkCmdDrawIndirectCountKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR:
        Decode_vkCmdDrawIndexedIndirectCountKHR(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT:
        Decode_vkCreateDebugReportCallbackEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT:
        Decode_vkDestroyDebugReportCallbackEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugReportMessageEXT:
        Decode_vkDebugReportMessageEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT:
        Decode_vkDebugMarkerSetObjectTagEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT:
        Decode_vkDebugMarkerSetObjectNameEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT:
        Decode_vkCmdDebugMarkerBeginEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT:
        Decode_vkCmdDebugMarkerEndEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT:
        Decode_vkCmdDebugMarkerInsertEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD:
        Decode_vkCmdDrawIndirectCountAMD(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD:
        Decode_vkCmdDrawIndexedIndirectCountAMD(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetShaderInfoAMD:
        Decode_vkGetShaderInfoAMD(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV:
        Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV:
        Decode_vkGetMemoryWin32HandleNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateViSurfaceNN:
        Decode_vkCreateViSurfaceNN(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT:
        Decode_vkCmdBeginConditionalRenderingEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT:
        Decode_vkCmdEndConditionalRenderingEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX:
        Decode_vkCmdProcessCommandsNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX:
        Decode_vkCmdReserveSpaceForCommandsNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX:
        Decode_vkCreateIndirectCommandsLayoutNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX:
        Decode_vkDestroyIndirectCommandsLayoutNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateObjectTableNVX:
        Decode_vkCreateObjectTableNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyObjectTableNVX:
        Decode_vkDestroyObjectTableNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUnregisterObjectsNVX:
        Decode_vkUnregisterObjectsNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX:
        Decode_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV:
        Decode_vkCmdSetViewportWScalingNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseDisplayEXT:
        Decode_vkReleaseDisplayEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT:
        Decode_vkAcquireXlibDisplayEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT:
        Decode_vkGetRandROutputDisplayEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT:
        Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDisplayPowerControlEXT:
        Decode_vkDisplayPowerControlEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT:
        Decode_vkRegisterDeviceEventEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT:
        Decode_vkRegisterDisplayEventEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT:
        Decode_vkGetSwapchainCounterEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE:
        Decode_vkGetRefreshCycleDurationGOOGLE(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE:
        Decode_vkGetPastPresentationTimingGOOGLE(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT:
        Decode_vkCmdSetDiscardRectangleEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetHdrMetadataEXT:
        Decode_vkSetHdrMetadataEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK:
        Decode_vkCreateIOSSurfaceMVK(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK:
        Decode_vkCreateMacOSSurfaceMVK(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT:
        Decode_vkSetDebugUtilsObjectNameEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT:
        Decode_vkSetDebugUtilsObjectTagEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT:
        Decode_vkQueueBeginDebugUtilsLabelEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT:
        Decode_vkQueueEndDebugUtilsLabelEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT:
        Decode_vkQueueInsertDebugUtilsLabelEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT:
        Decode_vkCmdBeginDebugUtilsLabelEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT:
        Decode_vkCmdEndDebugUtilsLabelEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT:
        Decode_vkCmdInsertDebugUtilsLabelEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT:
        Decode_vkCreateDebugUtilsMessengerEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT:
        Decode_vkDestroyDebugUtilsMessengerEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT:
        Decode_vkSubmitDebugUtilsMessageEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID:
        Decode_vkGetAndroidHardwareBufferPropertiesANDROID(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID:
        Decode_vkGetMemoryAndroidHardwareBufferANDROID(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT:
        Decode_vkCmdSetSampleLocationsEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT:
        Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateValidationCacheEXT:
        Decode_vkCreateValidationCacheEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT:
        Decode_vkDestroyValidationCacheEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMergeValidationCachesEXT:
        Decode_vkMergeValidationCachesEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT:
        Decode_vkGetValidationCacheDataEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV:
        Decode_vkCmdBindShadingRateImageNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV:
        Decode_vkCmdSetViewportShadingRatePaletteNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV:
        Decode_vkCmdSetCoarseSampleOrderNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAccelerationStructureNVX:
        Decode_vkCreateAccelerationStructureNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNVX:
        Decode_vkDestroyAccelerationStructureNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNVX:
        Decode_vkGetAccelerationStructureMemoryRequirementsNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureScratchMemoryRequirementsNVX:
        Decode_vkGetAccelerationStructureScratchMemoryRequirementsNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNVX:
        Decode_vkBindAccelerationStructureMemoryNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNVX:
        Decode_vkCmdBuildAccelerationStructureNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNVX:
        Decode_vkCmdCopyAccelerationStructureNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysNVX:
        Decode_vkCmdTraceRaysNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRaytracingPipelinesNVX:
        Decode_vkCreateRaytracingPipelinesNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRaytracingShaderHandlesNVX:
        Decode_vkGetRaytracingShaderHandlesNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNVX:
        Decode_vkGetAccelerationStructureHandleNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructurePropertiesNVX:
        Decode_vkCmdWriteAccelerationStructurePropertiesNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCompileDeferredNVX:
        Decode_vkCompileDeferredNVX(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT:
        Decode_vkGetMemoryHostPointerPropertiesEXT(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD:
        Decode_vkCmdWriteBufferMarkerAMD(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV:
        Decode_vkCmdDrawMeshTasksNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV:
        Decode_vkCmdDrawMeshTasksIndirectNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV:
        Decode_vkCmdDrawMeshTasksIndirectCountNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV:
        Decode_vkCmdSetExclusiveScissorNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCheckpointNV:
        Decode_vkCmdSetCheckpointNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV:
        Decode_vkGetQueueCheckpointDataNV(param_buffer, param_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA:
        Decode_vkCreateImagePipeSurfaceFUCHSIA(param_buffer, param_buffer_size);
        break;
    }
}


void VulkanDecoder::DecodeFunctionCall(format::ApiCallId             call_id,
                                       const format::ApiCallOptions& pre_call_options,
                                       const uint8_t*                pre_buffer,
                                       size_t                        pre_buffer_size,
                                       const format::ApiCallOptions& post_call_options,
                                       const uint8_t*                post_buffer,
                                       size_t                        post_buffer_size)
{
    switch(call_id)
    {
    default:
        VulkanDecoderBase::DecodeFunctionCall(call_id, pre_call_options, pre_buffer, pre_buffer_size, post_call_options, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateInstance:
        Decode_vkCreateInstance(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyInstance:
        Decode_vkDestroyInstance(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices:
        Decode_vkEnumeratePhysicalDevices(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures:
        Decode_vkGetPhysicalDeviceFeatures(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties:
        Decode_vkGetPhysicalDeviceFormatProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties:
        Decode_vkGetPhysicalDeviceImageFormatProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties:
        Decode_vkGetPhysicalDeviceProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties:
        Decode_vkGetPhysicalDeviceMemoryProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDevice:
        Decode_vkCreateDevice(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDevice:
        Decode_vkDestroyDevice(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceQueue:
        Decode_vkGetDeviceQueue(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueSubmit:
        Decode_vkQueueSubmit(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueWaitIdle:
        Decode_vkQueueWaitIdle(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDeviceWaitIdle:
        Decode_vkDeviceWaitIdle(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateMemory:
        Decode_vkAllocateMemory(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeMemory:
        Decode_vkFreeMemory(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMapMemory:
        Decode_vkMapMemory(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUnmapMemory:
        Decode_vkUnmapMemory(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges:
        Decode_vkFlushMappedMemoryRanges(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges:
        Decode_vkInvalidateMappedMemoryRanges(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment:
        Decode_vkGetDeviceMemoryCommitment(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory:
        Decode_vkBindBufferMemory(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory:
        Decode_vkBindImageMemory(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements:
        Decode_vkGetBufferMemoryRequirements(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements:
        Decode_vkGetImageMemoryRequirements(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements:
        Decode_vkGetImageSparseMemoryRequirements(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueBindSparse:
        Decode_vkQueueBindSparse(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateFence:
        Decode_vkCreateFence(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyFence:
        Decode_vkDestroyFence(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetFences:
        Decode_vkResetFences(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceStatus:
        Decode_vkGetFenceStatus(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkWaitForFences:
        Decode_vkWaitForFences(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSemaphore:
        Decode_vkCreateSemaphore(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySemaphore:
        Decode_vkDestroySemaphore(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateEvent:
        Decode_vkCreateEvent(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyEvent:
        Decode_vkDestroyEvent(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetEventStatus:
        Decode_vkGetEventStatus(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetEvent:
        Decode_vkSetEvent(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetEvent:
        Decode_vkResetEvent(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateQueryPool:
        Decode_vkCreateQueryPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyQueryPool:
        Decode_vkDestroyQueryPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueryPoolResults:
        Decode_vkGetQueryPoolResults(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateBuffer:
        Decode_vkCreateBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyBuffer:
        Decode_vkDestroyBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateBufferView:
        Decode_vkCreateBufferView(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyBufferView:
        Decode_vkDestroyBufferView(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImage:
        Decode_vkCreateImage(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyImage:
        Decode_vkDestroyImage(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSubresourceLayout:
        Decode_vkGetImageSubresourceLayout(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImageView:
        Decode_vkCreateImageView(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyImageView:
        Decode_vkDestroyImageView(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateShaderModule:
        Decode_vkCreateShaderModule(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyShaderModule:
        Decode_vkDestroyShaderModule(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePipelineCache:
        Decode_vkCreatePipelineCache(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipelineCache:
        Decode_vkDestroyPipelineCache(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPipelineCacheData:
        Decode_vkGetPipelineCacheData(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMergePipelineCaches:
        Decode_vkMergePipelineCaches(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateGraphicsPipelines:
        Decode_vkCreateGraphicsPipelines(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateComputePipelines:
        Decode_vkCreateComputePipelines(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipeline:
        Decode_vkDestroyPipeline(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreatePipelineLayout:
        Decode_vkCreatePipelineLayout(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyPipelineLayout:
        Decode_vkDestroyPipelineLayout(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSampler:
        Decode_vkCreateSampler(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySampler:
        Decode_vkDestroySampler(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout:
        Decode_vkCreateDescriptorSetLayout(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout:
        Decode_vkDestroyDescriptorSetLayout(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorPool:
        Decode_vkCreateDescriptorPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorPool:
        Decode_vkDestroyDescriptorPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetDescriptorPool:
        Decode_vkResetDescriptorPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateDescriptorSets:
        Decode_vkAllocateDescriptorSets(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeDescriptorSets:
        Decode_vkFreeDescriptorSets(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUpdateDescriptorSets:
        Decode_vkUpdateDescriptorSets(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateFramebuffer:
        Decode_vkCreateFramebuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyFramebuffer:
        Decode_vkDestroyFramebuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass:
        Decode_vkCreateRenderPass(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyRenderPass:
        Decode_vkDestroyRenderPass(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRenderAreaGranularity:
        Decode_vkGetRenderAreaGranularity(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateCommandPool:
        Decode_vkCreateCommandPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyCommandPool:
        Decode_vkDestroyCommandPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetCommandPool:
        Decode_vkResetCommandPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAllocateCommandBuffers:
        Decode_vkAllocateCommandBuffers(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkFreeCommandBuffers:
        Decode_vkFreeCommandBuffers(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBeginCommandBuffer:
        Decode_vkBeginCommandBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEndCommandBuffer:
        Decode_vkEndCommandBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkResetCommandBuffer:
        Decode_vkResetCommandBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindPipeline:
        Decode_vkCmdBindPipeline(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewport:
        Decode_vkCmdSetViewport(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetScissor:
        Decode_vkCmdSetScissor(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetLineWidth:
        Decode_vkCmdSetLineWidth(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBias:
        Decode_vkCmdSetDepthBias(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetBlendConstants:
        Decode_vkCmdSetBlendConstants(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDepthBounds:
        Decode_vkCmdSetDepthBounds(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask:
        Decode_vkCmdSetStencilCompareMask(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask:
        Decode_vkCmdSetStencilWriteMask(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetStencilReference:
        Decode_vkCmdSetStencilReference(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindDescriptorSets:
        Decode_vkCmdBindDescriptorSets(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindIndexBuffer:
        Decode_vkCmdBindIndexBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindVertexBuffers:
        Decode_vkCmdBindVertexBuffers(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDraw:
        Decode_vkCmdDraw(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexed:
        Decode_vkCmdDrawIndexed(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirect:
        Decode_vkCmdDrawIndirect(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect:
        Decode_vkCmdDrawIndexedIndirect(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatch:
        Decode_vkCmdDispatch(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchIndirect:
        Decode_vkCmdDispatchIndirect(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBuffer:
        Decode_vkCmdCopyBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImage:
        Decode_vkCmdCopyImage(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBlitImage:
        Decode_vkCmdBlitImage(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyBufferToImage:
        Decode_vkCmdCopyBufferToImage(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer:
        Decode_vkCmdCopyImageToBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdUpdateBuffer:
        Decode_vkCmdUpdateBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdFillBuffer:
        Decode_vkCmdFillBuffer(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearColorImage:
        Decode_vkCmdClearColorImage(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage:
        Decode_vkCmdClearDepthStencilImage(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdClearAttachments:
        Decode_vkCmdClearAttachments(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResolveImage:
        Decode_vkCmdResolveImage(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetEvent:
        Decode_vkCmdSetEvent(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetEvent:
        Decode_vkCmdResetEvent(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWaitEvents:
        Decode_vkCmdWaitEvents(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPipelineBarrier:
        Decode_vkCmdPipelineBarrier(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginQuery:
        Decode_vkCmdBeginQuery(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndQuery:
        Decode_vkCmdEndQuery(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdResetQueryPool:
        Decode_vkCmdResetQueryPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteTimestamp:
        Decode_vkCmdWriteTimestamp(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults:
        Decode_vkCmdCopyQueryPoolResults(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushConstants:
        Decode_vkCmdPushConstants(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass:
        Decode_vkCmdBeginRenderPass(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass:
        Decode_vkCmdNextSubpass(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass:
        Decode_vkCmdEndRenderPass(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdExecuteCommands:
        Decode_vkCmdExecuteCommands(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory2:
        Decode_vkBindBufferMemory2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory2:
        Decode_vkBindImageMemory2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures:
        Decode_vkGetDeviceGroupPeerMemoryFeatures(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDeviceMask:
        Decode_vkCmdSetDeviceMask(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchBase:
        Decode_vkCmdDispatchBase(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups:
        Decode_vkEnumeratePhysicalDeviceGroups(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2:
        Decode_vkGetImageMemoryRequirements2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2:
        Decode_vkGetBufferMemoryRequirements2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2:
        Decode_vkGetImageSparseMemoryRequirements2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2:
        Decode_vkGetPhysicalDeviceFeatures2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2:
        Decode_vkGetPhysicalDeviceProperties2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2:
        Decode_vkGetPhysicalDeviceFormatProperties2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2:
        Decode_vkGetPhysicalDeviceImageFormatProperties2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2:
        Decode_vkGetPhysicalDeviceMemoryProperties2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTrimCommandPool:
        Decode_vkTrimCommandPool(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceQueue2:
        Decode_vkGetDeviceQueue2(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion:
        Decode_vkCreateSamplerYcbcrConversion(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion:
        Decode_vkDestroySamplerYcbcrConversion(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate:
        Decode_vkCreateDescriptorUpdateTemplate(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate:
        Decode_vkDestroyDescriptorUpdateTemplate(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties:
        Decode_vkGetPhysicalDeviceExternalBufferProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties:
        Decode_vkGetPhysicalDeviceExternalFenceProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties:
        Decode_vkGetPhysicalDeviceExternalSemaphoreProperties(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport:
        Decode_vkGetDescriptorSetLayoutSupport(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySurfaceKHR:
        Decode_vkDestroySurfaceKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR:
        Decode_vkGetPhysicalDeviceSurfaceSupportKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR:
        Decode_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR:
        Decode_vkGetPhysicalDeviceSurfaceFormatsKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR:
        Decode_vkGetPhysicalDeviceSurfacePresentModesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSwapchainKHR:
        Decode_vkCreateSwapchainKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySwapchainKHR:
        Decode_vkDestroySwapchainKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR:
        Decode_vkGetSwapchainImagesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireNextImageKHR:
        Decode_vkAcquireNextImageKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueuePresentKHR:
        Decode_vkQueuePresentKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR:
        Decode_vkGetDeviceGroupPresentCapabilitiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR:
        Decode_vkGetDeviceGroupSurfacePresentModesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR:
        Decode_vkGetPhysicalDevicePresentRectanglesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireNextImage2KHR:
        Decode_vkAcquireNextImage2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR:
        Decode_vkGetPhysicalDeviceDisplayPropertiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR:
        Decode_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR:
        Decode_vkGetDisplayPlaneSupportedDisplaysKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR:
        Decode_vkGetDisplayModePropertiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDisplayModeKHR:
        Decode_vkCreateDisplayModeKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR:
        Decode_vkGetDisplayPlaneCapabilitiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR:
        Decode_vkCreateDisplayPlaneSurfaceKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR:
        Decode_vkCreateSharedSwapchainsKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR:
        Decode_vkCreateXlibSurfaceKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceXlibPresentationSupportKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR:
        Decode_vkCreateXcbSurfaceKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceXcbPresentationSupportKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR:
        Decode_vkCreateWaylandSurfaceKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceWaylandPresentationSupportKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMirSurfaceKHR:
        Decode_vkCreateMirSurfaceKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMirPresentationSupportKHR:
        Decode_vkGetPhysicalDeviceMirPresentationSupportKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR:
        Decode_vkCreateAndroidSurfaceKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR:
        Decode_vkCreateWin32SurfaceKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR:
        Decode_vkGetPhysicalDeviceWin32PresentationSupportKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR:
        Decode_vkGetPhysicalDeviceFeatures2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR:
        Decode_vkGetPhysicalDeviceProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceFormatProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceImageFormatProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR:
        Decode_vkGetPhysicalDeviceQueueFamilyProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR:
        Decode_vkGetPhysicalDeviceMemoryProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR:
        Decode_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR:
        Decode_vkGetDeviceGroupPeerMemoryFeaturesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR:
        Decode_vkCmdSetDeviceMaskKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR:
        Decode_vkCmdDispatchBaseKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkTrimCommandPoolKHR:
        Decode_vkTrimCommandPoolKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR:
        Decode_vkEnumeratePhysicalDeviceGroupsKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalBufferPropertiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR:
        Decode_vkGetMemoryWin32HandleKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR:
        Decode_vkGetMemoryWin32HandlePropertiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryFdKHR:
        Decode_vkGetMemoryFdKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR:
        Decode_vkGetMemoryFdPropertiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR:
        Decode_vkImportSemaphoreWin32HandleKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR:
        Decode_vkGetSemaphoreWin32HandleKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR:
        Decode_vkImportSemaphoreFdKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR:
        Decode_vkGetSemaphoreFdKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR:
        Decode_vkCmdPushDescriptorSetKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR:
        Decode_vkCreateDescriptorUpdateTemplateKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR:
        Decode_vkDestroyDescriptorUpdateTemplateKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRenderPass2KHR:
        Decode_vkCreateRenderPass2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR:
        Decode_vkCmdBeginRenderPass2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR:
        Decode_vkCmdNextSubpass2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR:
        Decode_vkCmdEndRenderPass2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR:
        Decode_vkGetSwapchainStatusKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR:
        Decode_vkGetPhysicalDeviceExternalFencePropertiesKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR:
        Decode_vkImportFenceWin32HandleKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR:
        Decode_vkGetFenceWin32HandleKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkImportFenceFdKHR:
        Decode_vkImportFenceFdKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetFenceFdKHR:
        Decode_vkGetFenceFdKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR:
        Decode_vkGetPhysicalDeviceSurfaceCapabilities2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR:
        Decode_vkGetPhysicalDeviceSurfaceFormats2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR:
        Decode_vkGetPhysicalDeviceDisplayProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR:
        Decode_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR:
        Decode_vkGetDisplayModeProperties2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR:
        Decode_vkGetDisplayPlaneCapabilities2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR:
        Decode_vkGetImageMemoryRequirements2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR:
        Decode_vkGetBufferMemoryRequirements2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR:
        Decode_vkGetImageSparseMemoryRequirements2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR:
        Decode_vkCreateSamplerYcbcrConversionKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR:
        Decode_vkDestroySamplerYcbcrConversionKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindBufferMemory2KHR:
        Decode_vkBindBufferMemory2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindImageMemory2KHR:
        Decode_vkBindImageMemory2KHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR:
        Decode_vkGetDescriptorSetLayoutSupportKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR:
        Decode_vkCmdDrawIndirectCountKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR:
        Decode_vkCmdDrawIndexedIndirectCountKHR(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT:
        Decode_vkCreateDebugReportCallbackEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT:
        Decode_vkDestroyDebugReportCallbackEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugReportMessageEXT:
        Decode_vkDebugReportMessageEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT:
        Decode_vkDebugMarkerSetObjectTagEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT:
        Decode_vkDebugMarkerSetObjectNameEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT:
        Decode_vkCmdDebugMarkerBeginEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT:
        Decode_vkCmdDebugMarkerEndEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT:
        Decode_vkCmdDebugMarkerInsertEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD:
        Decode_vkCmdDrawIndirectCountAMD(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD:
        Decode_vkCmdDrawIndexedIndirectCountAMD(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetShaderInfoAMD:
        Decode_vkGetShaderInfoAMD(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV:
        Decode_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV:
        Decode_vkGetMemoryWin32HandleNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateViSurfaceNN:
        Decode_vkCreateViSurfaceNN(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT:
        Decode_vkCmdBeginConditionalRenderingEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT:
        Decode_vkCmdEndConditionalRenderingEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX:
        Decode_vkCmdProcessCommandsNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX:
        Decode_vkCmdReserveSpaceForCommandsNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX:
        Decode_vkCreateIndirectCommandsLayoutNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX:
        Decode_vkDestroyIndirectCommandsLayoutNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateObjectTableNVX:
        Decode_vkCreateObjectTableNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyObjectTableNVX:
        Decode_vkDestroyObjectTableNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkUnregisterObjectsNVX:
        Decode_vkUnregisterObjectsNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX:
        Decode_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV:
        Decode_vkCmdSetViewportWScalingNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkReleaseDisplayEXT:
        Decode_vkReleaseDisplayEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT:
        Decode_vkAcquireXlibDisplayEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT:
        Decode_vkGetRandROutputDisplayEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT:
        Decode_vkGetPhysicalDeviceSurfaceCapabilities2EXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDisplayPowerControlEXT:
        Decode_vkDisplayPowerControlEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT:
        Decode_vkRegisterDeviceEventEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT:
        Decode_vkRegisterDisplayEventEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT:
        Decode_vkGetSwapchainCounterEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE:
        Decode_vkGetRefreshCycleDurationGOOGLE(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE:
        Decode_vkGetPastPresentationTimingGOOGLE(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT:
        Decode_vkCmdSetDiscardRectangleEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetHdrMetadataEXT:
        Decode_vkSetHdrMetadataEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK:
        Decode_vkCreateIOSSurfaceMVK(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK:
        Decode_vkCreateMacOSSurfaceMVK(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT:
        Decode_vkSetDebugUtilsObjectNameEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT:
        Decode_vkSetDebugUtilsObjectTagEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT:
        Decode_vkQueueBeginDebugUtilsLabelEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT:
        Decode_vkQueueEndDebugUtilsLabelEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT:
        Decode_vkQueueInsertDebugUtilsLabelEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT:
        Decode_vkCmdBeginDebugUtilsLabelEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT:
        Decode_vkCmdEndDebugUtilsLabelEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT:
        Decode_vkCmdInsertDebugUtilsLabelEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT:
        Decode_vkCreateDebugUtilsMessengerEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT:
        Decode_vkDestroyDebugUtilsMessengerEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT:
        Decode_vkSubmitDebugUtilsMessageEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID:
        Decode_vkGetAndroidHardwareBufferPropertiesANDROID(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID:
        Decode_vkGetMemoryAndroidHardwareBufferANDROID(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT:
        Decode_vkCmdSetSampleLocationsEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT:
        Decode_vkGetPhysicalDeviceMultisamplePropertiesEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateValidationCacheEXT:
        Decode_vkCreateValidationCacheEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT:
        Decode_vkDestroyValidationCacheEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkMergeValidationCachesEXT:
        Decode_vkMergeValidationCachesEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT:
        Decode_vkGetValidationCacheDataEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV:
        Decode_vkCmdBindShadingRateImageNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV:
        Decode_vkCmdSetViewportShadingRatePaletteNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV:
        Decode_vkCmdSetCoarseSampleOrderNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateAccelerationStructureNVX:
        Decode_vkCreateAccelerationStructureNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNVX:
        Decode_vkDestroyAccelerationStructureNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNVX:
        Decode_vkGetAccelerationStructureMemoryRequirementsNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureScratchMemoryRequirementsNVX:
        Decode_vkGetAccelerationStructureScratchMemoryRequirementsNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNVX:
        Decode_vkBindAccelerationStructureMemoryNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNVX:
        Decode_vkCmdBuildAccelerationStructureNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNVX:
        Decode_vkCmdCopyAccelerationStructureNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdTraceRaysNVX:
        Decode_vkCmdTraceRaysNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateRaytracingPipelinesNVX:
        Decode_vkCreateRaytracingPipelinesNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetRaytracingShaderHandlesNVX:
        Decode_vkGetRaytracingShaderHandlesNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNVX:
        Decode_vkGetAccelerationStructureHandleNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructurePropertiesNVX:
        Decode_vkCmdWriteAccelerationStructurePropertiesNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCompileDeferredNVX:
        Decode_vkCompileDeferredNVX(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT:
        Decode_vkGetMemoryHostPointerPropertiesEXT(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD:
        Decode_vkCmdWriteBufferMarkerAMD(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV:
        Decode_vkCmdDrawMeshTasksNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV:
        Decode_vkCmdDrawMeshTasksIndirectNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV:
        Decode_vkCmdDrawMeshTasksIndirectCountNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV:
        Decode_vkCmdSetExclusiveScissorNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCmdSetCheckpointNV:
        Decode_vkCmdSetCheckpointNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV:
        Decode_vkGetQueueCheckpointDataNV(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    case format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA:
        Decode_vkCreateImagePipeSurfaceFUCHSIA(pre_buffer, pre_buffer_size, post_buffer, post_buffer_size);
        break;
    }
}


BRIMSTONE_END_NAMESPACE(decode)
BRIMSTONE_END_NAMESPACE(brimstone)
