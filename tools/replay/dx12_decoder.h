/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DX12_DECODER_H
#define GFXRECON_DECODE_DX12_DECODER_H

#include "decode/api_decoder.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include <algorithm>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12Consumer;

class Dx12Decoder : public ApiDecoder
{
  public:
    Dx12Decoder() {}

    virtual ~Dx12Decoder() override {}

    void AddConsumer(Dx12Consumer* consumer) { consumers_.push_back(consumer); }

    void RemoveConsumer(Dx12Consumer* consumer)
    {
        consumers_.erase(std::remove(consumers_.begin(), consumers_.end(), consumer));
    }

    virtual bool SupportsApiCall(format::ApiCallId call_id) override
    {
        auto family_id = format::GetApiCallFamily(call_id);
        return ((family_id == format::ApiFamilyId::ApiFamily_Dxgi) ||
                (family_id == format::ApiFamilyId::ApiFamily_D3D12));
    }

    virtual void DecodeFunctionCall(format::ApiCallId  call_id,
                                    const ApiCallInfo& call_options,
                                    const uint8_t*     parameter_buffer,
                                    size_t             buffer_size) override;

    virtual void DecodeMethodCall(format::ApiCallId  call_id,
                                  format::HandleId   object_id,
                                  const ApiCallInfo& call_options,
                                  const uint8_t*     parameter_buffer,
                                  size_t             buffer_size) override;

    virtual void DispatchStateBeginMarker(uint64_t frame_number) override {}

    virtual void DispatchStateEndMarker(uint64_t frame_number) override {}

    virtual void DispatchDisplayMessageCommand(format::ThreadId thread_id, const std::string& message) override {}

    virtual void DispatchFillMemoryCommand(
        format::ThreadId thread_id, uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override
    {}

    virtual void DispatchResizeWindowCommand(format::ThreadId thread_id,
                                             format::HandleId surface_id,
                                             uint32_t         width,
                                             uint32_t         height) override
    {}

    virtual void DispatchResizeWindowCommand2(format::ThreadId thread_id,
                                              format::HandleId surface_id,
                                              uint32_t         width,
                                              uint32_t         height,
                                              uint32_t         pre_transform) override
    {}

    virtual void
    DispatchCreateHardwareBufferCommand(format::ThreadId                                    thread_id,
                                        format::HandleId                                    memory_id,
                                        uint64_t                                            buffer_id,
                                        uint32_t                                            format,
                                        uint32_t                                            width,
                                        uint32_t                                            height,
                                        uint32_t                                            stride,
                                        uint32_t                                            usage,
                                        uint32_t                                            layers,
                                        const std::vector<format::HardwareBufferPlaneInfo>& plane_info) override
    {}

    virtual void DispatchDestroyHardwareBufferCommand(format::ThreadId thread_id, uint64_t buffer_id) override {}

    virtual void DispatchSetDevicePropertiesCommand(format::ThreadId   thread_id,
                                                    format::HandleId   physical_device_id,
                                                    uint32_t           api_version,
                                                    uint32_t           driver_version,
                                                    uint32_t           vendor_id,
                                                    uint32_t           device_id,
                                                    uint32_t           device_type,
                                                    const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                    const std::string& device_name) override
    {}

    virtual void
    DispatchSetDeviceMemoryPropertiesCommand(format::ThreadId                             thread_id,
                                             format::HandleId                             physical_device_id,
                                             const std::vector<format::DeviceMemoryType>& memory_types,
                                             const std::vector<format::DeviceMemoryHeap>& memory_heaps) override
    {}

    virtual void
    DispatchSetSwapchainImageStateCommand(format::ThreadId                                    thread_id,
                                          format::HandleId                                    device_id,
                                          format::HandleId                                    swapchain_id,
                                          uint32_t                                            last_presented_image,
                                          const std::vector<format::SwapchainImageStateInfo>& image_state) override
    {}

    virtual void DispatchBeginResourceInitCommand(format::ThreadId thread_id,
                                                  format::HandleId device_id,
                                                  uint64_t         max_resource_size,
                                                  uint64_t         max_copy_size) override
    {}

    virtual void DispatchEndResourceInitCommand(format::ThreadId thread_id, format::HandleId device_id) override {}

    virtual void DispatchInitBufferCommand(format::ThreadId thread_id,
                                           format::HandleId device_id,
                                           format::HandleId buffer_id,
                                           uint64_t         data_size,
                                           const uint8_t*   data) override
    {}

    virtual void DispatchInitImageCommand(format::ThreadId             thread_id,
                                          format::HandleId             device_id,
                                          format::HandleId             image_id,
                                          uint64_t                     data_size,
                                          uint32_t                     aspect,
                                          uint32_t                     layout,
                                          const std::vector<uint64_t>& level_sizes,
                                          const uint8_t*               data) override
    {}

  protected:
    const std::vector<Dx12Consumer*>& GetConsumers() const { return consumers_; }

  private:
    size_t Decode_D3D12CreateDevice(const uint8_t* parameter_buffer, size_t buffer_size);

    size_t
    Decode_IUnknown_QueryInterface(format::HandleId object_id, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_IUnknown_AddRef(format::HandleId object_id, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_IUnknown_Release(format::HandleId object_id, const uint8_t* parameter_buffer, size_t buffer_size);

    size_t Decode_ID3D12Device_CreateCommandQueue(format::HandleId object_id,
                                                  const uint8_t*   parameter_buffer,
                                                  size_t           buffer_size);

    size_t
    Decode_ID3D12CommandQueue_Signal(format::HandleId object_id, const uint8_t* parameter_buffer, size_t buffer_size);

  private:
    std::vector<Dx12Consumer*> consumers_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_DECODER_H
