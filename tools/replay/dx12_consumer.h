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

#ifndef GFXRECON_DECODE_DX12_CONSUMER_H
#define GFXRECON_DECODE_DX12_CONSUMER_H

#include "dx12_struct_decoders.h"
#include "decode/pointer_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "util/defines.h"

#include <cassert>
#include <d3d12.h>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12Consumer
{
  public:
    void Process_D3D12CreateDevice(int32_t                          result,
                                   format::HandleId                 pAdapter,
                                   D3D_FEATURE_LEVEL                MinimumFeatureLevel,
                                   IID                              riid,
                                   HandlePointerDecoder<IUnknown*>* ppDevice)
    {
        assert(ppDevice != nullptr);

        // This code would be in the replay consumer.
        if (!ppDevice->IsNull())
        {
            ppDevice->SetHandleLength(1);
        }

        auto capture_id    = ppDevice->GetPointer();
        auto replay_device = ppDevice->GetHandlePointer();
        auto replay_result = D3D12CreateDevice(
            MapObject<IUnknown>(pAdapter), MinimumFeatureLevel, riid, reinterpret_cast<void**>(replay_device));

        if (SUCCEEDED(replay_result) && (replay_device != nullptr) && (*replay_device != nullptr))
        {
            AddObject(*capture_id, *replay_device);
            GFXRECON_LOG_INFO("Successfully created D3D12 device with ID %" PRIu64, *capture_id);
        }

        CheckReplayResult("D3D12CreateDevice", result, replay_result);
    }

    void Process_IUnknown_QueryInterface(format::HandleId object_id) {}

    void Process_IUnknown_AddRef(format::HandleId object_id, ULONG result)
    {
        auto replay_object = MapObject<IUnknown>(object_id);
        if (replay_object != nullptr)
        {
            replay_object->AddRef();
        }
    }

    void Process_IUnknown_Release(format::HandleId object_id, ULONG result)
    {
        auto replay_object = MapObject<IUnknown>(object_id);
        if (replay_object != nullptr)
        {
            auto replay_count = replay_object->Release();
            if (replay_count == 0)
            {
                RemoveObject(object_id);
                GFXRECON_LOG_INFO("Object with ID %" PRIu64 " has been destroyed", object_id);
            }
        }
    }

    void Process_ID3D12Device_CreateCommandQueue(format::HandleId                                        object_id,
                                                 int32_t                                                 result,
                                                 StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
                                                 IID                                                     riid,
                                                 HandlePointerDecoder<IUnknown*>*                        ppCommandQueue)
    {
        assert((pDesc != nullptr) && (ppCommandQueue != nullptr));

        auto replay_object = MapObject<ID3D12Device>(object_id);

        if (replay_object != nullptr)
        {
            if (!ppCommandQueue->IsNull())
            {
                ppCommandQueue->SetHandleLength(1);
            }

            auto capture_id   = ppCommandQueue->GetPointer();
            auto replay_queue = ppCommandQueue->GetHandlePointer();
            auto replay_result =
                replay_object->CreateCommandQueue(pDesc->GetPointer(), riid, reinterpret_cast<void**>(replay_queue));

            if (SUCCEEDED(replay_result) && (capture_id != nullptr) && (replay_queue != nullptr) &&
                (*replay_queue != nullptr))
            {
                AddObject(*capture_id, *replay_queue);
                GFXRECON_LOG_INFO("Successfully created D3D12 command queue ID %" PRIu64, *capture_id);
            }
        }
    }

    void Process_ID3D12CommandQueue_Signal(format::HandleId object_id,
                                           int32_t          result,
                                           format::HandleId pFence,
                                           uint64_t         Value)
    {
        // Fence creation was not captured in the sample file, so this call can't be executed.
    }

  protected:
    template <typename T>
    T* MapObject(format::HandleId id)
    {
        auto entry = objects_.find(id);
        if (entry != objects_.end())
        {
            return static_cast<T*>(entry->second);
        }

        return nullptr;
    }

    void AddObject(format::HandleId id, IUnknown* object) { objects_.insert(std::make_pair(id, object)); }

    void RemoveObject(format::HandleId id) { objects_.erase(id); }

    void CheckReplayResult(const char* call_name, HRESULT capture_result, HRESULT replay_result)
    {
        if (capture_result != replay_result)
        {
            GFXRECON_LOG_ERROR("%s returned %d, which does not match the value returned at capture",
                               call_name,
                               replay_result,
                               capture_result);
        }
    }

  private:
    std::unordered_map<format::HandleId, IUnknown*> objects_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_CONSUMER_H
