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

#ifndef GFXRECON_DECODE_DX12_STRUCT_DECODERS_H
#define GFXRECON_DECODE_DX12_STRUCT_DECODERS_H

#include "util/defines.h"

#include <d3d12.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Struct decoding type and function declaration.
struct Decoded_D3D12_COMMAND_QUEUE_DESC
{
    using struct_type = D3D12_COMMAND_QUEUE_DESC;

    D3D12_COMMAND_QUEUE_DESC* decoded_value{ nullptr };
};

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_D3D12_COMMAND_QUEUE_DESC* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_STRUCT_DECODERS_H
