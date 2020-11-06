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

#include "dx12_dispatch_table.h"

#include <d3d12.h>

const char kDx12CaptureDllName[] = "dx12_capture.dll";

HMODULE            dx12_capture_library = nullptr;
Dx12DispatchTable* dispatch_table       = nullptr;

EXTERN_C HRESULT WINAPI D3D12CreateDevice(IUnknown*         pAdapter,
                                          D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                          REFIID            riid, // Expected: ID3D12Device
                                          void**            ppDevice)
{
    if ((dispatch_table != nullptr) && (dispatch_table->create_device_func != nullptr))
    {
        return dispatch_table->create_device_func(pAdapter, MinimumFeatureLevel, riid, ppDevice);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI D3D12GetDebugInterface(REFIID riid, void** ppvDebug)
{
    if ((dispatch_table != nullptr) && (dispatch_table->get_debug_interface_func))
    {
        return dispatch_table->get_debug_interface_func(riid, ppvDebug);
    }

    return E_FAIL;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    BOOL success = TRUE;

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            if (dispatch_table == nullptr)
            {
                dx12_capture_library = LoadLibrary(kDx12CaptureDllName);
                if (dx12_capture_library != nullptr)
                {
                    auto get_table_func = reinterpret_cast<PFN_GetDx12DispatchTable>(
                        GetProcAddress(dx12_capture_library, "GetDx12DispatchTable"));

                    if (get_table_func != nullptr)
                    {
                        dispatch_table = get_table_func();
                    }
                }
            }
            break;
        case DLL_PROCESS_DETACH:
            if (lpvReserved == nullptr)
            {
                if (dx12_capture_library != nullptr)
                {
                    FreeLibrary(dx12_capture_library);
                }
            }
            break;
    }

    return success;
}
