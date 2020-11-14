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

#include "dx12_decoder.h"

#include "dx12_consumer.h"
#include "dx12_struct_decoders.h"
#include "decode/pointer_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/value_decoder.h"

#include <cassert>
#include <d3d12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static size_t DecodeIID(const uint8_t* parameter_buffer, size_t buffer_size, IID* iid)
{
    size_t bytes_read = 0;

    bytes_read +=
        ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &iid->Data1);
    bytes_read +=
        ValueDecoder::DecodeUInt16Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &iid->Data2);
    bytes_read +=
        ValueDecoder::DecodeUInt16Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &iid->Data3);
    bytes_read += ValueDecoder::DecodeUInt64Value(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), reinterpret_cast<uint64_t*>(iid->Data4));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_COMMAND_QUEUE_DESC* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                    bytes_read = 0;
    D3D12_COMMAND_QUEUE_DESC* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &value->Type);
    bytes_read += ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->Priority);
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &value->Flags);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->NodeMask);

    return bytes_read;
}

void Dx12Decoder::DecodeFunctionCall(format::ApiCallId  call_id,
                                     const ApiCallInfo& call_info,
                                     const uint8_t*     parameter_buffer,
                                     size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_D3D12CreateDevice:
            Decode_D3D12CreateDevice(parameter_buffer, buffer_size);
            break;
        default:
            break;
    }
}

void Dx12Decoder::DecodeMethodCall(format::ApiCallId  call_id,
                                   format::HandleId   object_id,
                                   const ApiCallInfo& call_info,
                                   const uint8_t*     parameter_buffer,
                                   size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    switch (call_id)
    {
        case format::ApiCallId::ApiCall_IUnknown_QueryInterface:
            Decode_IUnknown_QueryInterface(object_id, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_IUnknown_AddRef:
            Decode_IUnknown_AddRef(object_id, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_IUnknown_Release:
            Decode_IUnknown_Release(object_id, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue:
            Decode_ID3D12Device_CreateCommandQueue(object_id, parameter_buffer, buffer_size);
            break;
        case format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal:
            Decode_ID3D12CommandQueue_Signal(object_id, parameter_buffer, buffer_size);
            break;
        default:
            break;
    }
}

size_t Dx12Decoder::Decode_D3D12CreateDevice(const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId                pAdapter            = format::kNullHandleId;
    D3D_FEATURE_LEVEL               MinimumFeatureLevel = D3D_FEATURE_LEVEL_10_0;
    IID                             riid;
    HandlePointerDecoder<IUnknown*> ppDevice;
    int32_t                         result = E_FAIL;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pAdapter);
    bytes_read += ValueDecoder::DecodeEnumValue(
        (parameter_buffer + bytes_read), (buffer_size - bytes_read), &MinimumFeatureLevel);
    bytes_read += DecodeIID((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &result);

    for (auto consumer : consumers_)
    {
        consumer->Process_D3D12CreateDevice(result, pAdapter, MinimumFeatureLevel, riid, &ppDevice);
    }

    // NOTE: These return values are left over from an earlier design and are unnecessary.
    return bytes_read;
}

size_t Dx12Decoder::Decode_IUnknown_QueryInterface(format::HandleId object_id,
                                                   const uint8_t*   parameter_buffer,
                                                   size_t           buffer_size)
{
    size_t bytes_read = 0;

    IID                             riid;
    HandlePointerDecoder<IUnknown*> ppvObject;
    int32_t                         result = E_FAIL;

    bytes_read += DecodeIID((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvObject.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &result);

    for (auto consumer : consumers_)
    {
        consumer->Process_IUnknown_QueryInterface(object_id);
    }

    return bytes_read;
}

size_t
Dx12Decoder::Decode_IUnknown_AddRef(format::HandleId object_id, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint32_t count = 0;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &count);

    for (auto consumer : consumers_)
    {
        consumer->Process_IUnknown_AddRef(object_id, count);
    }

    return bytes_read;
}

size_t
Dx12Decoder::Decode_IUnknown_Release(format::HandleId object_id, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint32_t count = 0;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &count);

    for (auto consumer : consumers_)
    {
        consumer->Process_IUnknown_Release(object_id, count);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateCommandQueue(format::HandleId object_id,
                                                           const uint8_t*   parameter_buffer,
                                                           size_t           buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC> pDesc;
    IID                                                    riid;
    HandlePointerDecoder<IUnknown*>                        ppCommandQueue;
    int32_t                                                result = E_FAIL;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeIID((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppCommandQueue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &result);

    for (auto consumer : consumers_)
    {
        consumer->Process_ID3D12Device_CreateCommandQueue(object_id, result, &pDesc, riid, &ppCommandQueue);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_Signal(format::HandleId object_id,
                                                     const uint8_t*   parameter_buffer,
                                                     size_t           buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pFence = format::kNullHandleId;
    uint64_t         Value  = 0;
    int32_t          result = E_FAIL;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pFence);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Value);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &result);

    for (auto consumer : consumers_)
    {
        consumer->Process_ID3D12CommandQueue_Signal(object_id, result, pFence, Value);
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
