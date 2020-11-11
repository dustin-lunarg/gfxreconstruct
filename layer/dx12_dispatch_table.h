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

#ifndef DX12_DISPATCH_TABLE_H
#define DX12_DISPATCH_TABLE_H

#include <d3d12.h>
#include <dxgi.h>
#include <windows.h>

// The real D3D12 functions retrieved from the real d3d12.dll
typedef HRESULT(WINAPI* PFN_D3D12CreateDevice)(IUnknown*, D3D_FEATURE_LEVEL, REFIID, void**);
typedef HRESULT(WINAPI* PFN_D3D12GetDebugInterface)(REFIID, void**);

// The real DXGI functions retrieved from the real dxgi.dll
typedef HRESULT(WINAPI* PFN_CreateDXGIFactory2)(UINT, REFIID, void**);

struct Dx12DispatchTable
{
    PFN_D3D12CreateDevice      create_device_func{ nullptr };
    PFN_D3D12GetDebugInterface get_debug_interface_func{ nullptr };
    PFN_CreateDXGIFactory2     create_dxgi_factory2_func{ nullptr };
};

typedef Dx12DispatchTable*(WINAPI* PFN_InitializeDx12Implementation)();
typedef void(WINAPI* PFN_ReleaseDx12Implementation)();

EXTERN_C Dx12DispatchTable* WINAPI InitializeDx12Implementation();

EXTERN_C void WINAPI ReleaseDx12Implementation();

#endif // DX12_DISPATCH_TABLE_H
