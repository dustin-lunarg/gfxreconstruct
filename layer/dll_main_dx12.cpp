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

// This needs to be included before d3d12.h so that IIDs are defined and not just declared.
#include <initguid.h>

#include "dx12_dispatch_table.h"

#include "format/api_call_id.h"
#include "encode/custom_encoder_commands.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
#include "util/defines.h"

#include <atomic>
#include <cstdint>
#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <functional>
#include <mutex>
#include <Unknwn.h>
#include <unordered_map>
#include <vector>
#include <windows.h>

#undef GetObject

std::atomic<uint64_t> current_id = 0;

uint64_t GetUniqueId()
{
    return ++current_id;
}

template <typename T>
typename T::WrappedType* UnwrapObject(typename T::WrappedType* wrapped_object)
{
    if (wrapped_object != nullptr)
    {
        return reinterpret_cast<const T*>(wrapped_object)->GetObjectAs<T::WrappedType>();
    }

    return nullptr;
}

template <typename T>
void CreateWrappedObject(typename T::WrappedType** object)
{
    if ((object != nullptr) && (*object != nullptr))
    {
        T* wrapper = new T(*object);
        (*object)  = reinterpret_cast<T::WrappedType*>(wrapper);
    }
}

template <typename T>
void GetOrCreateWrappedObject(typename T::WrappedType** object)
{
    if ((object != nullptr) && (*object != nullptr))
    {
        auto wrapper = T::GetWrapper(*object);
        if (wrapper != nullptr)
        {
            // PROTOTYPE: Release the additional ref count added to the object by QueryInterface, or whatever mechanism
            // retrieved the object, and increment the ref count for the wrapper being returned.
            auto count = (*object)->Release();

            // PROTOYPE: This represents that AddRef that was performed on the wrapped object by QueryInterface, or
            // whatever mechanism retrieved the object, and should not be written to the capture file.
            wrapper->AddRefInternal();

            (*object) = reinterpret_cast<T::WrappedType*>(wrapper);
        }
        else
        {
            CreateWrappedObject<T>(object);
        }
    }
}

void GetOrCreateWrappedObject(REFIID riid, void** object);

// Forward declarations for encode function declarations.
class IUnknown_Wrapper;
class ID3D12Device_Wrapper;
class ID3D12CommandQueue_Wrapper;

// Encoder function declarations.
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Encode_D3D12CreateDevice(HRESULT           result,
                              IUnknown*         pAdapter,
                              D3D_FEATURE_LEVEL MinimumFeatureLevel,
                              REFIID            riid, // Expected: ID3D12Device
                              void**            ppDevice);

void Encode_ID3D12Device_CreateCommandQueue(ID3D12Device_Wrapper*           wrapper,
                                            HRESULT                         result,
                                            const D3D12_COMMAND_QUEUE_DESC* pDesc,
                                            REFIID                          riid,
                                            void**                          ppCommandQueue);

void Encode_ID3D12CommandQueue_Signal(ID3D12CommandQueue_Wrapper* wrapper,
                                      HRESULT                     result,
                                      ID3D12Fence*                pFence,
                                      UINT64                      Value);

void Encode_IUnknown_QueryInterface(IUnknown_Wrapper* wrapper, HRESULT result, REFIID riid, void** ppvObject);

void Encode_IUnknown_AddRef(IUnknown_Wrapper* wrapper, uint32_t result);

void Encode_IUnknown_Release(IUnknown_Wrapper* wrapper, uint32_t result);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

class IUnknown_Wrapper : public IUnknown
{
  public:
    typedef IUnknown WrappedType;

  public:
    IUnknown_Wrapper(IUnknown* wrapped_object) : object_(wrapped_object), object_id_(GetUniqueId()), ref_count_(1) {}

    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) override
    {
        // PROTOTYPE: Example fully instrumented capture function.
        gfxrecon::encode::CustomEncoderPreCall<gfxrecon::format::ApiCallId::ApiCall_IUnknown_QueryInterface>::Dispatch(
            gfxrecon::encode::TraceManager::Get(), this, riid, ppvObject);

        auto result = object_->QueryInterface(riid, ppvObject);

        if (SUCCEEDED(result) && (ppvObject != nullptr))
        {
            // PROTOTYPE: If the retrieved object matches the wrapped object, return the current wrapper.  There is an
            // issue here when the retrieved object is a version of a type that is not wrapped.  For example, if the
            // query was for IDXGIFactory6, but the latest factory version supported by the wrappers is IDXGIFactory4,
            // an IDXGIFactory4_Wrapper type will be returned, leading to failures when the caller attempts to use
            // IDXGIFactory6 methods.  There will also be an issue here with multiple inheritance, if the same pointer
            // is returned for an IID associated with a type from a different inheritance hierarchy.
            if (*ppvObject == object_)
            {
                // PROTOTYPE: Release the additional ref count added to the object by QueryInterface and increment the
                // ref count for the wrapper being returned.
                auto count = reinterpret_cast<IUnknown*>(*ppvObject)->Release();

                // PROTOYPE: This represents that AddRef that was performed on the wrapped object by QueryInterface, and
                // should not be written to the capture file.
                AddRefInternal();

                (*ppvObject) = this;
            }
            else
            {
                // PROTOTYPE: Retrieve an existing wrapper or create a new wrapper for the retrieved object.
                GetOrCreateWrappedObject(riid, ppvObject);
            }
        }

        gfxrecon::encode::Encode_IUnknown_QueryInterface(this, result, riid, ppvObject);

        gfxrecon::encode::CustomEncoderPostCall<gfxrecon::format::ApiCallId::ApiCall_IUnknown_QueryInterface>::Dispatch(
            gfxrecon::encode::TraceManager::Get(), this, result, riid, ppvObject);

        return result;
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void) override
    {
        // PROTOTYPE: Example fully instrumented capture function.
        gfxrecon::encode::CustomEncoderPreCall<gfxrecon::format::ApiCallId::ApiCall_IUnknown_AddRef>::
            Dispatch(gfxrecon::encode::TraceManager::Get(), this);

        auto count = AddRefInternal();

        gfxrecon::encode::Encode_IUnknown_AddRef(this, count);

        gfxrecon::encode::CustomEncoderPostCall<gfxrecon::format::ApiCallId::ApiCall_IUnknown_AddRef>::Dispatch(
            gfxrecon::encode::TraceManager::Get(), this, count);

        return count;
    }

    virtual ULONG STDMETHODCALLTYPE Release(void) override
    {
        // PROTOTYPE: Example fully instrumented capture function.
        gfxrecon::encode::CustomEncoderPreCall<gfxrecon::format::ApiCallId::ApiCall_IUnknown_Release>::Dispatch(
            gfxrecon::encode::TraceManager::Get(), this);

        auto count = InterlockedDecrement(&ref_count_);

        gfxrecon::encode::Encode_IUnknown_Release(this, count);

        gfxrecon::encode::CustomEncoderPostCall<gfxrecon::format::ApiCallId::ApiCall_IUnknown_Release>::Dispatch(
            gfxrecon::encode::TraceManager::Get(), this, count);

        if (count == 0)
        {
            if (destroy_func_)
            {
                destroy_func_();
            }

            // Release the wrapper's reference to the wrapped object before destroying the wrapper.
            object_->Release();
            delete this;
        }

        return count;
    }

    ULONG AddRefInternal()
    {
        InterlockedIncrement(&ref_count_);
        return ref_count_;
    }

    void SetDestroyFunc(std::function<void()> destroy_func) { destroy_func_ = destroy_func; }

    uint64_t GetObjectId() const { return object_id_; }

    IUnknown* GetObject() const { return object_; }

    template <typename T>
    T* GetObjectAs() const
    {
        return reinterpret_cast<T*>(object_);
    }

  private:
    IUnknown*             object_;
    uint64_t              object_id_;
    ULONG                 ref_count_;
    std::function<void()> destroy_func_;
};

class ID3D12Object_Wrapper : public IUnknown_Wrapper
{
  public:
    typedef ID3D12Object WrappedType;

  public:
    ID3D12Object_Wrapper(ID3D12Object* object) : IUnknown_Wrapper(object) {}

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID guid, UINT* pDataSize, void* pData)
    {
        return GetObjectAs<ID3D12Object>()->GetPrivateData(guid, pDataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID guid, UINT DataSize, const void* pData)
    {
        return GetObjectAs<ID3D12Object>()->SetPrivateData(guid, DataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID guid, const IUnknown* pData)
    {
        return GetObjectAs<ID3D12Object>()->SetPrivateDataInterface(guid, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetName(LPCWSTR Name) { return GetObjectAs<ID3D12Object>()->SetName(Name); }
};

class ID3D12Device_Wrapper : public ID3D12Object_Wrapper
{
  public:
    typedef ID3D12Device WrappedType;

  public:
    ID3D12Device_Wrapper(ID3D12Device* object) : ID3D12Object_Wrapper(object) {}

    virtual UINT STDMETHODCALLTYPE GetNodeCount(void) { return GetObjectAs<ID3D12Device>()->GetNodeCount(); }

    virtual HRESULT STDMETHODCALLTYPE CreateCommandQueue(const D3D12_COMMAND_QUEUE_DESC* pDesc,
                                                         REFIID                          riid,
                                                         void**                          ppCommandQueue)
    {
        // PROTOTYPE: Example fully instrumented capture function.
        gfxrecon::encode::CustomEncoderPreCall<gfxrecon::format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue>::
            Dispatch(gfxrecon::encode::TraceManager::Get(), this, pDesc, riid, ppCommandQueue);

        // PROTOTYPE: Example of wrapping an object at creation.
        auto result = GetObjectAs<ID3D12Device>()->CreateCommandQueue(pDesc, riid, ppCommandQueue);

        if (SUCCEEDED(result) && ppCommandQueue != nullptr)
        {
            GetOrCreateWrappedObject(riid, ppCommandQueue);
        }

        gfxrecon::encode::Encode_ID3D12Device_CreateCommandQueue(this, result, pDesc, riid, ppCommandQueue);

        gfxrecon::encode::CustomEncoderPostCall<gfxrecon::format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue>::
            Dispatch(gfxrecon::encode::TraceManager::Get(), this, result, pDesc, riid, ppCommandQueue);

        return result;
    }

    virtual HRESULT STDMETHODCALLTYPE CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE type,
                                                             REFIID                  riid,
                                                             void**                  ppCommandAllocator)
    {
        return GetObjectAs<ID3D12Device>()->CreateCommandAllocator(type, riid, ppCommandAllocator);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateGraphicsPipelineState(const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
                                                                  REFIID                                    riid,
                                                                  void** ppPipelineState)
    {
        return GetObjectAs<ID3D12Device>()->CreateGraphicsPipelineState(pDesc, riid, ppPipelineState);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateComputePipelineState(const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
                                                                 REFIID                                   riid,
                                                                 void** ppPipelineState)
    {
        return GetObjectAs<ID3D12Device>()->CreateComputePipelineState(pDesc, riid, ppPipelineState);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateCommandList(UINT                    nodeMask,
                                                        D3D12_COMMAND_LIST_TYPE type,
                                                        ID3D12CommandAllocator* pCommandAllocator,
                                                        ID3D12PipelineState*    pInitialState,
                                                        REFIID                  riid,
                                                        void**                  ppCommandList)
    {
        return GetObjectAs<ID3D12Device>()->CreateCommandList(
            nodeMask, type, pCommandAllocator, pInitialState, riid, ppCommandList);
    }

    virtual HRESULT STDMETHODCALLTYPE CheckFeatureSupport(D3D12_FEATURE Feature,
                                                          void*         pFeatureSupportData,
                                                          UINT          FeatureSupportDataSize)
    {
        return GetObjectAs<ID3D12Device>()->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateDescriptorHeap(const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
                                                           REFIID                            riid,
                                                           void**                            ppvHeap)
    {
        return GetObjectAs<ID3D12Device>()->CreateDescriptorHeap(pDescriptorHeapDesc, riid, ppvHeap);
    }

    virtual UINT STDMETHODCALLTYPE GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
    {
        return GetObjectAs<ID3D12Device>()->GetDescriptorHandleIncrementSize(DescriptorHeapType);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateRootSignature(UINT        nodeMask,
                                                          const void* pBlobWithRootSignature,
                                                          SIZE_T      blobLengthInBytes,
                                                          REFIID      riid,
                                                          void**      ppvRootSignature)
    {
        return GetObjectAs<ID3D12Device>()->CreateRootSignature(
            nodeMask, pBlobWithRootSignature, blobLengthInBytes, riid, ppvRootSignature);
    }

    virtual void STDMETHODCALLTYPE CreateConstantBufferView(const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
                                                            D3D12_CPU_DESCRIPTOR_HANDLE            DestDescriptor)
    {
        GetObjectAs<ID3D12Device>()->CreateConstantBufferView(pDesc, DestDescriptor);
    }

    virtual void STDMETHODCALLTYPE CreateShaderResourceView(ID3D12Resource*                        pResource,
                                                            const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
                                                            D3D12_CPU_DESCRIPTOR_HANDLE            DestDescriptor)
    {
        GetObjectAs<ID3D12Device>()->CreateShaderResourceView(pResource, pDesc, DestDescriptor);
    }

    virtual void STDMETHODCALLTYPE CreateUnorderedAccessView(ID3D12Resource*                         pResource,
                                                             ID3D12Resource*                         pCounterResource,
                                                             const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
                                                             D3D12_CPU_DESCRIPTOR_HANDLE             DestDescriptor)
    {
        GetObjectAs<ID3D12Device>()->CreateUnorderedAccessView(pResource, pCounterResource, pDesc, DestDescriptor);
    }

    virtual void STDMETHODCALLTYPE CreateRenderTargetView(ID3D12Resource*                      pResource,
                                                          const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
                                                          D3D12_CPU_DESCRIPTOR_HANDLE          DestDescriptor)
    {
        GetObjectAs<ID3D12Device>()->CreateRenderTargetView(pResource, pDesc, DestDescriptor);
    }

    virtual void STDMETHODCALLTYPE CreateDepthStencilView(ID3D12Resource*                      pResource,
                                                          const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
                                                          D3D12_CPU_DESCRIPTOR_HANDLE          DestDescriptor)
    {
        GetObjectAs<ID3D12Device>()->CreateDepthStencilView(pResource, pDesc, DestDescriptor);
    }

    virtual void STDMETHODCALLTYPE CreateSampler(const D3D12_SAMPLER_DESC*   pDesc,
                                                 D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
    {
        GetObjectAs<ID3D12Device>()->CreateSampler(pDesc, DestDescriptor);
    }

    virtual void STDMETHODCALLTYPE CopyDescriptors(UINT                               NumDestDescriptorRanges,
                                                   const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
                                                   const UINT*                        pDestDescriptorRangeSizes,
                                                   UINT                               NumSrcDescriptorRanges,
                                                   const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
                                                   const UINT*                        pSrcDescriptorRangeSizes,
                                                   D3D12_DESCRIPTOR_HEAP_TYPE         DescriptorHeapsType)
    {
        GetObjectAs<ID3D12Device>()->CopyDescriptors(NumDestDescriptorRanges,
                                                     pDestDescriptorRangeStarts,
                                                     pDestDescriptorRangeSizes,
                                                     NumSrcDescriptorRanges,
                                                     pSrcDescriptorRangeStarts,
                                                     pSrcDescriptorRangeSizes,
                                                     DescriptorHeapsType);
    }

    virtual void STDMETHODCALLTYPE CopyDescriptorsSimple(UINT                        NumDescriptors,
                                                         D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
                                                         D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
                                                         D3D12_DESCRIPTOR_HEAP_TYPE  DescriptorHeapsType)
    {
        GetObjectAs<ID3D12Device>()->CopyDescriptorsSimple(
            NumDescriptors, DestDescriptorRangeStart, SrcDescriptorRangeStart, DescriptorHeapsType);
    }

    virtual D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE
    GetResourceAllocationInfo(UINT visibleMask, UINT numResourceDescs, const D3D12_RESOURCE_DESC* pResourceDescs)
    {
        return GetObjectAs<ID3D12Device>()->GetResourceAllocationInfo(visibleMask, numResourceDescs, pResourceDescs);
    }

    virtual D3D12_HEAP_PROPERTIES STDMETHODCALLTYPE GetCustomHeapProperties(UINT nodeMask, D3D12_HEAP_TYPE heapType)
    {
        return GetObjectAs<ID3D12Device>()->GetCustomHeapProperties(nodeMask, heapType);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateCommittedResource(const D3D12_HEAP_PROPERTIES* pHeapProperties,
                                                              D3D12_HEAP_FLAGS             HeapFlags,
                                                              const D3D12_RESOURCE_DESC*   pDesc,
                                                              D3D12_RESOURCE_STATES        InitialResourceState,
                                                              const D3D12_CLEAR_VALUE*     pOptimizedClearValue,
                                                              REFIID                       riidResource,
                                                              void**                       ppvResource)
    {
        return GetObjectAs<ID3D12Device>()->CreateCommittedResource(
            pHeapProperties, HeapFlags, pDesc, InitialResourceState, pOptimizedClearValue, riidResource, ppvResource);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateHeap(const D3D12_HEAP_DESC* pDesc, REFIID riid, void** ppvHeap)
    {
        return GetObjectAs<ID3D12Device>()->CreateHeap(pDesc, riid, ppvHeap);
    }

    virtual HRESULT STDMETHODCALLTYPE CreatePlacedResource(ID3D12Heap*                pHeap,
                                                           UINT64                     HeapOffset,
                                                           const D3D12_RESOURCE_DESC* pDesc,
                                                           D3D12_RESOURCE_STATES      InitialState,
                                                           const D3D12_CLEAR_VALUE*   pOptimizedClearValue,
                                                           REFIID                     riid,
                                                           void**                     ppvResource)
    {
        return GetObjectAs<ID3D12Device>()->CreatePlacedResource(
            pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateReservedResource(const D3D12_RESOURCE_DESC* pDesc,
                                                             D3D12_RESOURCE_STATES      InitialState,
                                                             const D3D12_CLEAR_VALUE*   pOptimizedClearValue,
                                                             REFIID                     riid,
                                                             void**                     ppvResource)
    {
        return GetObjectAs<ID3D12Device>()->CreateReservedResource(
            pDesc, InitialState, pOptimizedClearValue, riid, ppvResource);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateSharedHandle(
        ID3D12DeviceChild* pObject, const SECURITY_ATTRIBUTES* pAttributes, DWORD Access, LPCWSTR Name, HANDLE* pHandle)
    {
        return GetObjectAs<ID3D12Device>()->CreateSharedHandle(pObject, pAttributes, Access, Name, pHandle);
    }

    virtual HRESULT STDMETHODCALLTYPE OpenSharedHandle(HANDLE NTHandle, REFIID riid, void** ppvObj)
    {
        return GetObjectAs<ID3D12Device>()->OpenSharedHandle(NTHandle, riid, ppvObj);
    }

    virtual HRESULT STDMETHODCALLTYPE OpenSharedHandleByName(LPCWSTR Name, DWORD Access, HANDLE* pNTHandle)
    {
        return GetObjectAs<ID3D12Device>()->OpenSharedHandleByName(Name, Access, pNTHandle);
    }

    virtual HRESULT STDMETHODCALLTYPE MakeResident(UINT NumObjects, ID3D12Pageable* const* ppObjects)
    {
        return GetObjectAs<ID3D12Device>()->MakeResident(NumObjects, ppObjects);
    }

    virtual HRESULT STDMETHODCALLTYPE Evict(UINT NumObjects, ID3D12Pageable* const* ppObjects)
    {
        return GetObjectAs<ID3D12Device>()->Evict(NumObjects, ppObjects);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateFence(UINT64            InitialValue,
                                                  D3D12_FENCE_FLAGS Flags,
                                                  REFIID            riid,
                                                  void**            ppFence)
    {
        // PROTOTYPE: Example of wrapping an object at creation.
        auto result = GetObjectAs<ID3D12Device>()->CreateFence(InitialValue, Flags, riid, ppFence);

        if (SUCCEEDED(result) && ppFence != nullptr)
        {
            GetOrCreateWrappedObject(riid, ppFence);
        }

        return result;
    }

    virtual HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason(void)
    {
        return GetObjectAs<ID3D12Device>()->GetDeviceRemovedReason();
    }

    virtual void STDMETHODCALLTYPE GetCopyableFootprints(const D3D12_RESOURCE_DESC*          pResourceDesc,
                                                         UINT                                FirstSubresource,
                                                         UINT                                NumSubresources,
                                                         UINT64                              BaseOffset,
                                                         D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
                                                         UINT*                               pNumRows,
                                                         UINT64*                             pRowSizeInBytes,
                                                         UINT64*                             pTotalBytes)
    {
        GetObjectAs<ID3D12Device>()->GetCopyableFootprints(pResourceDesc,
                                                           FirstSubresource,
                                                           NumSubresources,
                                                           BaseOffset,
                                                           pLayouts,
                                                           pNumRows,
                                                           pRowSizeInBytes,
                                                           pTotalBytes);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateQueryHeap(const D3D12_QUERY_HEAP_DESC* pDesc, REFIID riid, void** ppvHeap)
    {
        return GetObjectAs<ID3D12Device>()->CreateQueryHeap(pDesc, riid, ppvHeap);
    }

    virtual HRESULT STDMETHODCALLTYPE SetStablePowerState(BOOL Enable)
    {
        return GetObjectAs<ID3D12Device>()->SetStablePowerState(Enable);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateCommandSignature(const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
                                                             ID3D12RootSignature*                pRootSignature,
                                                             REFIID                              riid,
                                                             void**                              ppvCommandSignature)
    {
        return GetObjectAs<ID3D12Device>()->CreateCommandSignature(pDesc, pRootSignature, riid, ppvCommandSignature);
    }

    virtual void STDMETHODCALLTYPE GetResourceTiling(ID3D12Resource*           pTiledResource,
                                                     UINT*                     pNumTilesForEntireResource,
                                                     D3D12_PACKED_MIP_INFO*    pPackedMipDesc,
                                                     D3D12_TILE_SHAPE*         pStandardTileShapeForNonPackedMips,
                                                     UINT*                     pNumSubresourceTilings,
                                                     UINT                      FirstSubresourceTilingToGet,
                                                     D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips)
    {
        GetObjectAs<ID3D12Device>()->GetResourceTiling(pTiledResource,
                                                       pNumTilesForEntireResource,
                                                       pPackedMipDesc,
                                                       pStandardTileShapeForNonPackedMips,
                                                       pNumSubresourceTilings,
                                                       FirstSubresourceTilingToGet,
                                                       pSubresourceTilingsForNonPackedMips);
    }

    virtual LUID STDMETHODCALLTYPE GetAdapterLuid(void) { return GetObjectAs<ID3D12Device>()->GetAdapterLuid(); }
};

class ID3D12DeviceChild_Wrapper : public ID3D12Object_Wrapper
{
  public:
    typedef ID3D12DeviceChild WrappedType;

  public:
    ID3D12DeviceChild_Wrapper(ID3D12DeviceChild* object) : ID3D12Object_Wrapper(object) {}

    virtual HRESULT STDMETHODCALLTYPE GetDevice(REFIID riid, void** ppvDevice)
    {
        // PROTOTYPE: Example of wrapping an object at retrieval.
        auto result = GetObjectAs<ID3D12DeviceChild>()->GetDevice(riid, ppvDevice);

        if (SUCCEEDED(result) && (ppvDevice != nullptr))
        {
            GetOrCreateWrappedObject(riid, ppvDevice);
        }

        return result;
    }
};

class ID3D12Pageable_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    typedef ID3D12Pageable WrappedType;

  public:
    ID3D12Pageable_Wrapper(ID3D12Pageable* object) : ID3D12DeviceChild_Wrapper(object) {}
};

class ID3D12Fence_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    typedef ID3D12Fence WrappedType;

  public:
    ID3D12Fence_Wrapper(ID3D12Fence* object) : ID3D12Pageable_Wrapper(object)
    {
        std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
        active_wrappers_[object] = this;

        SetDestroyFunc([this]() {
            std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
            active_wrappers_.erase(GetObject());
        });
    }

    virtual UINT64 STDMETHODCALLTYPE GetCompletedValue(void) { return GetObjectAs<ID3D12Fence>()->GetCompletedValue(); }

    virtual HRESULT STDMETHODCALLTYPE SetEventOnCompletion(UINT64 Value, HANDLE hEvent)
    {
        // PROTOTYPE: Replay will need to create events for this call, or will need to skip this call.
        return GetObjectAs<ID3D12Fence>()->SetEventOnCompletion(Value, hEvent);
    }

    virtual HRESULT STDMETHODCALLTYPE Signal(UINT64 Value) { return GetObjectAs<ID3D12Fence>()->Signal(Value); }

    static ID3D12Fence_Wrapper* GetWrapper(ID3D12Fence* object)
    {
        if (object != nullptr)
        {
            std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
            auto                        entry = active_wrappers_.find(object);

            if (entry != active_wrappers_.end())
            {
                return entry->second;
            }
        }

        return nullptr;
    }

  private:
    static std::mutex                                      active_wrappers_lock_;
    static std::unordered_map<void*, ID3D12Fence_Wrapper*> active_wrappers_;
};

std::mutex                                      ID3D12Fence_Wrapper::active_wrappers_lock_;
std::unordered_map<void*, ID3D12Fence_Wrapper*> ID3D12Fence_Wrapper::active_wrappers_;

class ID3D12CommandQueue_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    typedef ID3D12CommandQueue WrappedType;

  public:
    ID3D12CommandQueue_Wrapper(ID3D12CommandQueue* object) : ID3D12Pageable_Wrapper(object)
    {
        std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
        active_wrappers_[object] = this;

        SetDestroyFunc([this]() {
            std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
            active_wrappers_.erase(GetObject());
        });
    }

    virtual void STDMETHODCALLTYPE
    UpdateTileMappings(ID3D12Resource*                        pResource,
                       UINT                                   NumResourceRegions,
                       const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates,
                       const D3D12_TILE_REGION_SIZE*          pResourceRegionSizes,
                       ID3D12Heap*                            pHeap,
                       UINT                                   NumRanges,
                       const D3D12_TILE_RANGE_FLAGS*          pRangeFlags,
                       const UINT*                            pHeapRangeStartOffsets,
                       const UINT*                            pRangeTileCounts,
                       D3D12_TILE_MAPPING_FLAGS               Flags)
    {
        GetObjectAs<ID3D12CommandQueue>()->UpdateTileMappings(pResource,
                                                              NumResourceRegions,
                                                              pResourceRegionStartCoordinates,
                                                              pResourceRegionSizes,
                                                              pHeap,
                                                              NumRanges,
                                                              pRangeFlags,
                                                              pHeapRangeStartOffsets,
                                                              pRangeTileCounts,
                                                              Flags);
    }

    virtual void STDMETHODCALLTYPE CopyTileMappings(ID3D12Resource*                        pDstResource,
                                                    const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
                                                    ID3D12Resource*                        pSrcResource,
                                                    const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
                                                    const D3D12_TILE_REGION_SIZE*          pRegionSize,
                                                    D3D12_TILE_MAPPING_FLAGS               Flags)
    {
        GetObjectAs<ID3D12CommandQueue>()->CopyTileMappings(
            pDstResource, pDstRegionStartCoordinate, pSrcResource, pSrcRegionStartCoordinate, pRegionSize, Flags);
    }

    virtual void STDMETHODCALLTYPE ExecuteCommandLists(UINT NumCommandLists, ID3D12CommandList* const* ppCommandLists)
    {
        GetObjectAs<ID3D12CommandQueue>()->ExecuteCommandLists(NumCommandLists, ppCommandLists);
    }

    virtual void STDMETHODCALLTYPE SetMarker(UINT Metadata, _In_reads_bytes_opt_(Size) const void* pData, UINT Size)
    {
        GetObjectAs<ID3D12CommandQueue>()->SetMarker(Metadata, pData, Size);
    }

    virtual void STDMETHODCALLTYPE BeginEvent(UINT Metadata, const void* pData, UINT Size)
    {
        GetObjectAs<ID3D12CommandQueue>()->BeginEvent(Metadata, pData, Size);
    }

    virtual void STDMETHODCALLTYPE EndEvent(void) { GetObjectAs<ID3D12CommandQueue>()->EndEvent(); }

    virtual HRESULT STDMETHODCALLTYPE Signal(ID3D12Fence* pFence, UINT64 Value)
    {
        // PROTOTYPE: Example fully instrumented capture function.
        gfxrecon::encode::CustomEncoderPreCall<gfxrecon::format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal>::
            Dispatch(gfxrecon::encode::TraceManager::Get(), this, pFence, Value);

        // PROTOTYPE: Unwrap an object when it is used as a parameter.
        auto result = GetObjectAs<ID3D12CommandQueue>()->Signal(UnwrapObject<ID3D12Fence_Wrapper>(pFence), Value);

        gfxrecon::encode::Encode_ID3D12CommandQueue_Signal(this, result, pFence, Value);

        gfxrecon::encode::CustomEncoderPostCall<gfxrecon::format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal>::
            Dispatch(gfxrecon::encode::TraceManager::Get(), this, result, pFence, Value);

        return result;
    }

    virtual HRESULT STDMETHODCALLTYPE Wait(ID3D12Fence* pFence, UINT64 Value)
    {
        // PROTOTYPE: Unwrap an object when it is used as a parameter.
        return GetObjectAs<ID3D12CommandQueue>()->Wait(UnwrapObject<ID3D12Fence_Wrapper>(pFence), Value);
    }

    virtual HRESULT STDMETHODCALLTYPE GetTimestampFrequency(UINT64* pFrequency)
    {
        return GetObjectAs<ID3D12CommandQueue>()->GetTimestampFrequency(pFrequency);
    }

    virtual HRESULT STDMETHODCALLTYPE GetClockCalibration(UINT64* pGpuTimestamp, UINT64* pCpuTimestamp)
    {
        return GetObjectAs<ID3D12CommandQueue>()->GetClockCalibration(pGpuTimestamp, pCpuTimestamp);
    }

    virtual D3D12_COMMAND_QUEUE_DESC STDMETHODCALLTYPE GetDesc(void)
    {
        return GetObjectAs<ID3D12CommandQueue>()->GetDesc();
    }

    static ID3D12CommandQueue_Wrapper* GetWrapper(ID3D12CommandQueue* object)
    {
        if (object != nullptr)
        {
            std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
            auto                        entry = active_wrappers_.find(object);

            if (entry != active_wrappers_.end())
            {
                return entry->second;
            }
        }

        return nullptr;
    }

  private:
    static std::mutex                                             active_wrappers_lock_;
    static std::unordered_map<void*, ID3D12CommandQueue_Wrapper*> active_wrappers_;
};

std::mutex                                             ID3D12CommandQueue_Wrapper::active_wrappers_lock_;
std::unordered_map<void*, ID3D12CommandQueue_Wrapper*> ID3D12CommandQueue_Wrapper::active_wrappers_;

class ID3D12Device1_Wrapper : public ID3D12Device_Wrapper
{
  public:
    typedef ID3D12Device1 WrappedType;

  public:
    ID3D12Device1_Wrapper(ID3D12Device1* object) : ID3D12Device_Wrapper(object)
    {
        std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
        active_wrappers_[object] = this;

        SetDestroyFunc([this]() {
            std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
            active_wrappers_.erase(GetObject());
        });
    }

    virtual HRESULT STDMETHODCALLTYPE CreatePipelineLibrary(const void* pLibraryBlob,
                                                            SIZE_T      BlobLength,
                                                            REFIID      riid,
                                                            void**      ppPipelineLibrary)
    {
        return GetObjectAs<ID3D12Device1>()->CreatePipelineLibrary(pLibraryBlob, BlobLength, riid, ppPipelineLibrary);
    }

    virtual HRESULT STDMETHODCALLTYPE SetEventOnMultipleFenceCompletion(ID3D12Fence* const*             ppFences,
                                                                        const UINT64*                   pFenceValues,
                                                                        UINT                            NumFences,
                                                                        D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
                                                                        HANDLE                          hEvent)
    {
        // PROTOTYPE: Unwrap an array of objects.  The unwrapping could be in a templated utility function.
        static thread_local std::vector<ID3D12Fence*> unwrapped_objects;

        // Clear data from previous use.
        unwrapped_objects.clear();

        // Grow when necessary.
        if (unwrapped_objects.size() < NumFences)
        {
            unwrapped_objects.resize(NumFences);
        }

        for (UINT i = 0; i < NumFences; ++i)
        {
            unwrapped_objects[i] = UnwrapObject<ID3D12Fence_Wrapper>(ppFences[i]);
        }

        return GetObjectAs<ID3D12Device1>()->SetEventOnMultipleFenceCompletion(
            unwrapped_objects.data(), pFenceValues, NumFences, Flags, hEvent);
    }

    virtual HRESULT STDMETHODCALLTYPE SetResidencyPriority(UINT                            NumObjects,
                                                           ID3D12Pageable* const*          ppObjects,
                                                           const D3D12_RESIDENCY_PRIORITY* pPriorities)
    {
        return GetObjectAs<ID3D12Device1>()->SetResidencyPriority(NumObjects, ppObjects, pPriorities);
    }

    static ID3D12Device_Wrapper* GetWrapper(ID3D12Device* object)
    {
        if (object != nullptr)
        {
            std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
            auto                        entry = active_wrappers_.find(object);

            if (entry != active_wrappers_.end())
            {
                return entry->second;
            }
        }

        return nullptr;
    }

  private:
    static std::mutex                                        active_wrappers_lock_;
    static std::unordered_map<void*, ID3D12Device1_Wrapper*> active_wrappers_;
};

std::mutex                                        ID3D12Device1_Wrapper::active_wrappers_lock_;
std::unordered_map<void*, ID3D12Device1_Wrapper*> ID3D12Device1_Wrapper::active_wrappers_;

class IDXGIObject_Wrapper : public IUnknown_Wrapper
{
  public:
    typedef IDXGIObject WrappedType;

  public:
    IDXGIObject_Wrapper(IDXGIObject* object) : IUnknown_Wrapper(object) {}

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID Name, UINT DataSize, const void* pData)
    {
        return GetObjectAs<IDXGIObject>()->SetPrivateData(Name, DataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID Name, const IUnknown* pUnknown)
    {
        return GetObjectAs<IDXGIObject>()->SetPrivateDataInterface(Name, pUnknown);
    }

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID Name, UINT* pDataSize, void* pData)
    {
        return GetObjectAs<IDXGIObject>()->GetPrivateData(Name, pDataSize, pData);
    }

    virtual HRESULT STDMETHODCALLTYPE GetParent(REFIID riid, void** ppParent)
    {
        return GetObjectAs<IDXGIObject>()->GetParent(riid, ppParent);
    }
};

class IDXGIFactory_Wrapper : public IDXGIObject_Wrapper
{
  public:
    typedef IDXGIFactory WrappedType;

  public:
    IDXGIFactory_Wrapper(IDXGIFactory* object) : IDXGIObject_Wrapper(object) {}

    virtual HRESULT STDMETHODCALLTYPE EnumAdapters(UINT Adapter, IDXGIAdapter** ppAdapter)
    {
        return GetObjectAs<IDXGIFactory>()->EnumAdapters(Adapter, ppAdapter);
    }

    virtual HRESULT STDMETHODCALLTYPE MakeWindowAssociation(HWND WindowHandle, UINT Flags)
    {
        return GetObjectAs<IDXGIFactory>()->MakeWindowAssociation(WindowHandle, Flags);
    }

    virtual HRESULT STDMETHODCALLTYPE GetWindowAssociation(HWND* pWindowHandle)
    {
        return GetObjectAs<IDXGIFactory>()->GetWindowAssociation(pWindowHandle);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChain(IUnknown*             pDevice,
                                                      DXGI_SWAP_CHAIN_DESC* pDesc,
                                                      IDXGISwapChain**      ppSwapChain)
    {
        return GetObjectAs<IDXGIFactory>()->CreateSwapChain(
            UnwrapObject<IUnknown_Wrapper>(pDevice), pDesc, ppSwapChain);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateSoftwareAdapter(HMODULE Module, IDXGIAdapter** ppAdapter)
    {
        return GetObjectAs<IDXGIFactory>()->CreateSoftwareAdapter(Module, ppAdapter);
    }
};

class IDXGIFactory1_Wrapper : public IDXGIFactory_Wrapper
{
  public:
    typedef IDXGIFactory1 WrappedType;

  public:
    IDXGIFactory1_Wrapper(IDXGIFactory1* object) : IDXGIFactory_Wrapper(object) {}

    virtual HRESULT STDMETHODCALLTYPE EnumAdapters1(UINT Adapter, IDXGIAdapter1** ppAdapter)
    {
        return GetObjectAs<IDXGIFactory1>()->EnumAdapters1(Adapter, ppAdapter);
    }

    virtual BOOL STDMETHODCALLTYPE IsCurrent(void) { return GetObjectAs<IDXGIFactory1>()->IsCurrent(); }
};

class IDXGIFactory2_Wrapper : public IDXGIFactory1_Wrapper
{
  public:
    typedef IDXGIFactory2 WrappedType;

  public:
    IDXGIFactory2_Wrapper(IDXGIFactory2* object) : IDXGIFactory1_Wrapper(object) {}

    virtual BOOL STDMETHODCALLTYPE IsWindowedStereoEnabled(void)
    {
        return GetObjectAs<IDXGIFactory2>()->IsWindowedStereoEnabled();
    }

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForHwnd(IUnknown*                              pDevice,
                                                             HWND                                   hWnd,
                                                             const DXGI_SWAP_CHAIN_DESC1*           pDesc,
                                                             const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
                                                             IDXGIOutput*                           pRestrictToOutput,
                                                             IDXGISwapChain1**                      ppSwapChain)
    {
        return GetObjectAs<IDXGIFactory2>()->CreateSwapChainForHwnd(
            UnwrapObject<IUnknown_Wrapper>(pDevice), hWnd, pDesc, pFullscreenDesc, pRestrictToOutput, ppSwapChain);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForCoreWindow(IUnknown*                    pDevice,
                                                                   IUnknown*                    pWindow,
                                                                   const DXGI_SWAP_CHAIN_DESC1* pDesc,
                                                                   IDXGIOutput*                 pRestrictToOutput,
                                                                   IDXGISwapChain1**            ppSwapChain)
    {
        return GetObjectAs<IDXGIFactory2>()->CreateSwapChainForCoreWindow(
            UnwrapObject<IUnknown_Wrapper>(pDevice), pWindow, pDesc, pRestrictToOutput, ppSwapChain);
    }

    virtual HRESULT STDMETHODCALLTYPE GetSharedResourceAdapterLuid(HANDLE hResource, LUID* pLuid)
    {
        return GetObjectAs<IDXGIFactory2>()->GetSharedResourceAdapterLuid(hResource, pLuid);
    }

    virtual HRESULT STDMETHODCALLTYPE RegisterStereoStatusWindow(HWND WindowHandle, UINT wMsg, DWORD* pdwCookie)
    {
        return GetObjectAs<IDXGIFactory2>()->RegisterStereoStatusWindow(WindowHandle, wMsg, pdwCookie);
    }

    virtual HRESULT STDMETHODCALLTYPE RegisterStereoStatusEvent(HANDLE hEvent, DWORD* pdwCookie)
    {
        return GetObjectAs<IDXGIFactory2>()->RegisterStereoStatusEvent(hEvent, pdwCookie);
    }

    virtual void STDMETHODCALLTYPE UnregisterStereoStatus(DWORD dwCookie)
    {
        return GetObjectAs<IDXGIFactory2>()->UnregisterStereoStatus(dwCookie);
    }

    virtual HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusWindow(HWND WindowHandle, UINT wMsg, DWORD* pdwCookie)
    {
        return GetObjectAs<IDXGIFactory2>()->RegisterOcclusionStatusWindow(WindowHandle, wMsg, pdwCookie);
    }

    virtual HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusEvent(HANDLE hEvent, DWORD* pdwCookie)
    {
        return GetObjectAs<IDXGIFactory2>()->RegisterOcclusionStatusEvent(hEvent, pdwCookie);
    }

    virtual void STDMETHODCALLTYPE UnregisterOcclusionStatus(DWORD dwCookie)
    {
        return GetObjectAs<IDXGIFactory2>()->UnregisterOcclusionStatus(dwCookie);
    }

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForComposition(IUnknown*                    pDevice,
                                                                    const DXGI_SWAP_CHAIN_DESC1* pDesc,
                                                                    IDXGIOutput*                 pRestrictToOutput,
                                                                    IDXGISwapChain1**            ppSwapChain)
    {
        return GetObjectAs<IDXGIFactory2>()->CreateSwapChainForComposition(
            UnwrapObject<IUnknown_Wrapper>(pDevice), pDesc, pRestrictToOutput, ppSwapChain);
    }
};

class IDXGIFactory3_Wrapper : public IDXGIFactory2_Wrapper
{
  public:
    typedef IDXGIFactory3 WrappedType;

  public:
    IDXGIFactory3_Wrapper(IDXGIFactory3* object) : IDXGIFactory2_Wrapper(object) {}

    virtual UINT STDMETHODCALLTYPE GetCreationFlags(void) { return GetObjectAs<IDXGIFactory3>()->GetCreationFlags(); }
};

class IDXGIFactory4_Wrapper : public IDXGIFactory3_Wrapper
{
  public:
    typedef IDXGIFactory4 WrappedType;

  public:
    IDXGIFactory4_Wrapper(IDXGIFactory4* object) : IDXGIFactory3_Wrapper(object) {}

    virtual HRESULT STDMETHODCALLTYPE EnumAdapterByLuid(LUID AdapterLuid, REFIID riid, void** ppvAdapter)
    {
        return GetObjectAs<IDXGIFactory4>()->EnumAdapterByLuid(AdapterLuid, riid, ppvAdapter);
    }

    virtual HRESULT STDMETHODCALLTYPE EnumWarpAdapter(REFIID riid, void** ppvAdapter)
    {
        return GetObjectAs<IDXGIFactory4>()->EnumWarpAdapter(riid, ppvAdapter);
    }
};

class IDXGIFactory5_Wrapper : public IDXGIFactory4_Wrapper
{
  public:
    typedef IDXGIFactory5 WrappedType;

  public:
    IDXGIFactory5_Wrapper(IDXGIFactory5* object) : IDXGIFactory4_Wrapper(object) {}

    virtual HRESULT STDMETHODCALLTYPE CheckFeatureSupport(DXGI_FEATURE Feature,
                                                          void*        pFeatureSupportData,
                                                          UINT         FeatureSupportDataSize)
    {
        return GetObjectAs<WrappedType>()->CheckFeatureSupport(Feature, pFeatureSupportData, FeatureSupportDataSize);
    }
};

class IDXGIFactory6_Wrapper : public IDXGIFactory5_Wrapper
{
  public:
    typedef IDXGIFactory6 WrappedType;

  public:
    IDXGIFactory6_Wrapper(IDXGIFactory6* object) : IDXGIFactory5_Wrapper(object)
    {
        std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
        active_wrappers_[object] = this;

        SetDestroyFunc([this]() {
            std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
            active_wrappers_.erase(GetObject());
        });
    }

  public:
    virtual HRESULT STDMETHODCALLTYPE EnumAdapterByGpuPreference(UINT                Adapter,
                                                                 DXGI_GPU_PREFERENCE GpuPreference,
                                                                 REFIID              riid,
                                                                 void**              ppvAdapter)
    {
        return GetObjectAs<WrappedType>()->EnumAdapterByGpuPreference(Adapter, GpuPreference, riid, ppvAdapter);
    }

    static IDXGIFactory6_Wrapper* GetWrapper(IDXGIFactory6* object)
    {
        if (object != nullptr)
        {
            std::lock_guard<std::mutex> lock_guard(active_wrappers_lock_);
            auto                        entry = active_wrappers_.find(object);

            if (entry != active_wrappers_.end())
            {
                return entry->second;
            }
        }

        return nullptr;
    }

  private:
    static std::mutex                                        active_wrappers_lock_;
    static std::unordered_map<void*, IDXGIFactory6_Wrapper*> active_wrappers_;
};

std::mutex                                        IDXGIFactory6_Wrapper::active_wrappers_lock_;
std::unordered_map<void*, IDXGIFactory6_Wrapper*> IDXGIFactory6_Wrapper::active_wrappers_;

void GetOrCreateWrappedObject(REFIID riid, void** object)
{
    if (IsEqualIID(riid, IID_ID3D12Device) || IsEqualIID(riid, IID_ID3D12Device1))
    {
        // PROTOTYPE: Create a wrapper for the most recent class version.  When creating a wrapper for a
        // class version that is different than the version specified by riid, QueryInterface could be used to
        // confirm that the pointers retrieved for both class versions match.  If there is a mismatch,
        // promotion to the latest version would be skipped.
        GetOrCreateWrappedObject<ID3D12Device1_Wrapper>(reinterpret_cast<ID3D12Device1**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12Fence))
    {
        GetOrCreateWrappedObject<ID3D12Fence_Wrapper>(reinterpret_cast<ID3D12Fence**>(object));
    }
    else if (IsEqualIID(riid, IID_ID3D12CommandQueue))
    {
        GetOrCreateWrappedObject<ID3D12CommandQueue_Wrapper>(reinterpret_cast<ID3D12CommandQueue**>(object));
    }
    if (IsEqualIID(riid, IID_IDXGIFactory6) || IsEqualIID(riid, IID_IDXGIFactory5) ||
        IsEqualIID(riid, IID_IDXGIFactory4) || IsEqualIID(riid, IID_IDXGIFactory3) ||
        IsEqualIID(riid, IID_IDXGIFactory2) || IsEqualIID(riid, IID_IDXGIFactory1) ||
        IsEqualIID(riid, IID_IDXGIFactory))
    {
        // PROTOTYPE: Create a wrapper for the most recent class version.  When creating a wrapper for a
        // class version that is different than the version specified by riid, QueryInterface could be used to
        // confirm that the pointers retrieved for both class versions match.  If there is a mismatch,
        // promotion to the latest version would be skipped.
        GetOrCreateWrappedObject<IDXGIFactory6_Wrapper>(reinterpret_cast<IDXGIFactory6**>(object));
    }
    else
    {
        // Raise/report error
    }
}

// The real D3D12 functions retrieved from the real d3d12.dll
typedef HRESULT(WINAPI* PFN_D3D12CreateDevice)(IUnknown*, D3D_FEATURE_LEVEL, REFIID, void**);
typedef HRESULT(WINAPI* PFN_D3D12GetDebugInterface)(REFIID, void**);

// The real DXGI functions retrieved from the real dxgi.dll
typedef HRESULT(WINAPI* PFN_CreateDXGIFactory2)(UINT, REFIID, void**);

namespace gfxr
{
const char kD3D12DllName[] = "d3d12_ms.dll";
const char kDxgiDllName[]  = "dxgi_ms.dll";

HMODULE d3d12_library = nullptr;
HMODULE dxgi_library  = nullptr;

PFN_D3D12CreateDevice      create_device_func        = nullptr;
PFN_D3D12GetDebugInterface get_debug_interface_func  = nullptr;
PFN_CreateDXGIFactory2     create_dxgi_factory2_func = nullptr;

Dx12DispatchTable* dispatch_table = nullptr;

// PROTOTYPE: Scope counter for API call depth.  A scope count of 1 indicates the application has called the function
// directly.  A scope count greater than 1 indicates that the function was called by another function in the run time.
// Only wrap objects for functions called by the application, to prevent wrappers from being used in the run time.
thread_local uint32_t call_scope = 0;

HRESULT D3D12CreateDevice(IUnknown*         pAdapter,
                          D3D_FEATURE_LEVEL MinimumFeatureLevel,
                          REFIID            riid, // Expected: ID3D12Device
                          void**            ppDevice)
{
    if (create_device_func != nullptr)
    {
        ++call_scope;

        // PROTOTYPE: Example function instrumented for capture.
        gfxrecon::encode::CustomEncoderPreCall<gfxrecon::format::ApiCallId::ApiCall_D3D12CreateDevice>::Dispatch(
            gfxrecon::encode::TraceManager::Get(), pAdapter, MinimumFeatureLevel, riid, ppDevice);

        auto result = create_device_func(pAdapter, MinimumFeatureLevel, riid, ppDevice);

        // PROTOTYPE: Only wrap objects for functions called by the application, when scope_count is 1, to prevent
        // wrappers from being used in the run time.
        if (SUCCEEDED(result) && ppDevice != nullptr && (call_scope == 1))
        {
            // PROTOTYPE: Check for the expected type before falling back on the generic IID based function.
            if (IsEqualIID(riid, IID_ID3D12Device) || IsEqualIID(riid, IID_ID3D12Device1))
            {
                // PROTOTYPE: Create a wrapper for the most recent class version.  When creating a wrapper for a
                // class version that is different than the version specified by riid, QueryInterface could be used to
                // confirm that the pointers retrieved for both class versions match.  If there is a mismatch,
                // promotion to the latest version would be skipped.
                GetOrCreateWrappedObject<ID3D12Device1_Wrapper>(reinterpret_cast<ID3D12Device1**>(ppDevice));
            }
            else
            {
                GetOrCreateWrappedObject(riid, ppDevice);
            }
        }

        gfxrecon::encode::Encode_D3D12CreateDevice(result, pAdapter, MinimumFeatureLevel, riid, ppDevice);

        gfxrecon::encode::CustomEncoderPostCall<gfxrecon::format::ApiCallId::ApiCall_D3D12CreateDevice>::Dispatch(
            gfxrecon::encode::TraceManager::Get(), result, pAdapter, MinimumFeatureLevel, riid, ppDevice);

        --call_scope;

        return result;
    }

    return E_FAIL;
}

HRESULT D3D12GetDebugInterface(REFIID riid, void** ppvDebug)
{
    if (get_debug_interface_func != nullptr)
    {
        ++call_scope;

        auto result = get_debug_interface_func(riid, ppvDebug);

        --call_scope;

        return result;
    }

    return E_FAIL;
}

HRESULT CreateDXGIFactory2(UINT Flags, REFIID riid, void** ppFactory)
{
    if (create_dxgi_factory2_func != nullptr)
    {
        ++call_scope;

        auto result = create_dxgi_factory2_func(Flags, riid, ppFactory);

        // PROTOTYPE: Only wrap objects for functions called by the application, when scope_count is 1, to prevent
        // wrappers from being used in the run time.
        if (SUCCEEDED(result) && ppFactory != nullptr && (call_scope == 1))
        {
            // PROTOTYPE: Check for the expected type before falling back on the generic IID based function.
            if (IsEqualIID(riid, IID_IDXGIFactory6) || IsEqualIID(riid, IID_IDXGIFactory5) ||
                IsEqualIID(riid, IID_IDXGIFactory4) || IsEqualIID(riid, IID_IDXGIFactory3) ||
                IsEqualIID(riid, IID_IDXGIFactory2) || IsEqualIID(riid, IID_IDXGIFactory1) ||
                IsEqualIID(riid, IID_IDXGIFactory))
            {
                // PROTOTYPE: Create a wrapper for the most recent class version.  When creating a wrapper for a
                // class version that is different than the version specified by riid, QueryInterface could be used to
                // confirm that the pointers retrieved for both class versions match.  If there is a mismatch,
                // promotion to the latest version would be skipped.
                GetOrCreateWrappedObject<IDXGIFactory6_Wrapper>(reinterpret_cast<IDXGIFactory6**>(ppFactory));
            }
            else
            {
                GetOrCreateWrappedObject(riid, ppFactory);
            }
        }

        --call_scope;

        return result;
    }

    return E_FAIL;
}

void Load()
{
    d3d12_library = LoadLibrary(kD3D12DllName);
    if (d3d12_library != nullptr)
    {
        create_device_func =
            reinterpret_cast<PFN_D3D12CreateDevice>(GetProcAddress(d3d12_library, "D3D12CreateDevice"));
        get_debug_interface_func =
            reinterpret_cast<PFN_D3D12GetDebugInterface>(GetProcAddress(d3d12_library, "D3D12GetDebugInterface"));
    }

    dxgi_library = LoadLibrary(kDxgiDllName);
    if (dxgi_library != nullptr)
    {
        create_dxgi_factory2_func =
            reinterpret_cast<PFN_CreateDXGIFactory2>(GetProcAddress(dxgi_library, "CreateDXGIFactory2"));
    }

    dispatch_table =
        new Dx12DispatchTable{ gfxr::D3D12CreateDevice, gfxr::D3D12GetDebugInterface, gfxr::CreateDXGIFactory2 };
}

void Destroy()
{
    if (d3d12_library != nullptr)
    {
        FreeLibrary(d3d12_library);
    }

    if (dxgi_library != nullptr)
    {
        FreeLibrary(dxgi_library);
    }

    delete dispatch_table;
}
} // namespace gfxr

EXTERN_C Dx12DispatchTable* WINAPI InitializeDx12Implementation()
{
    // This could potentially be called in thread attach.
    gfxrecon::encode::TraceManager::CreateInstance();

    return gfxr::dispatch_table;
}

EXTERN_C void WINAPI ReleaseDx12Implementation()
{
    // This could potentially be called in thread detach.
    gfxrecon::encode::TraceManager::DestroyInstance();
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    BOOL success = TRUE;

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            if (gfxr::dispatch_table == nullptr)
            {
                gfxr::Load();
            }
            break;
        case DLL_PROCESS_DETACH:
            if (lpvReserved == nullptr)
            {
                if (gfxr::dispatch_table != nullptr)
                {
                    gfxr::Destroy();
                }
            }
            break;
    }

    return success;
}

//
// Encoder implementations
//
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// This would most likely be implemented in a custom ParameterEncoded::EncodeIID method.
void EncodeIID(ParameterEncoder* encoder, REFIID riid)
{
    encoder->EncodeUInt32Value(riid.Data1);
    encoder->EncodeUInt16Value(riid.Data2);
    encoder->EncodeUInt16Value(riid.Data3);
    encoder->EncodeUInt64Value(*(reinterpret_cast<const uint64_t*>(riid.Data4)));
}

// This would most likely be implemented in a custom ParameterEncoded::EncodeDxObjectPtr method.
void EncodeDxObjectPtr(ParameterEncoder* encoder, void** object, bool omit_output_data)
{
    format::HandleId  device_id     = format::kNullHandleId;
    format::HandleId* device_id_ptr = nullptr;
    if ((object != nullptr) && (*object != nullptr))
    {
        device_id     = reinterpret_cast<const IUnknown_Wrapper*>(*object)->GetObjectId();
        device_id_ptr = &device_id;
    }
    // The final version of the encoder would use the address of object as the address that is encoded for the
    // pointer value.
    encoder->EncodeHandleIdPtr(device_id_ptr, omit_output_data);
}

// This would be a generated struct encode function.
void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMMAND_QUEUE_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeInt32Value(value.Priority);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.NodeMask);
}

// The following would be generated API function/method call encode functions.
void Encode_D3D12CreateDevice(HRESULT           result,
                              IUnknown*         pAdapter,
                              D3D_FEATURE_LEVEL MinimumFeatureLevel,
                              REFIID            riid, // Expected: ID3D12Device
                              void**            ppDevice)
{
    bool omit_output_data = false;

    if (FAILED(result))
    {
        omit_output_data = true;
    }

    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_D3D12CreateDevice);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(format::kNullHandleId); // Ignored for now as not supported for wrapping.
        encoder->EncodeEnumValue(MinimumFeatureLevel);
        EncodeIID(encoder, riid);
        EncodeDxObjectPtr(encoder, ppDevice, omit_output_data);
        encoder->EncodeInt32Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateCommandQueue(ID3D12Device_Wrapper*           wrapper,
                                            HRESULT                         result,
                                            const D3D12_COMMAND_QUEUE_DESC* pDesc,
                                            REFIID                          riid,
                                            void**                          ppCommandQueue)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue,
                                                             wrapper->GetObjectId());
    if (encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeIID(encoder, riid);
        EncodeDxObjectPtr(encoder, ppCommandQueue, FAILED(result));
        encoder->EncodeInt32Value(result);

        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_Signal(ID3D12CommandQueue_Wrapper* wrapper,
                                      HRESULT                     result,
                                      ID3D12Fence*                pFence,
                                      UINT64                      Value)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal,
                                                             wrapper->GetObjectId());
    if (encoder)
    {
        encoder->EncodeHandleIdValue(reinterpret_cast<ID3D12Fence_Wrapper*>(wrapper)->GetObjectId());
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeInt32Value(result);

        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IUnknown_QueryInterface(IUnknown_Wrapper* wrapper, HRESULT result, REFIID riid, void** ppvObject)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IUnknown_QueryInterface,
                                                             wrapper->GetObjectId());
    if (encoder)
    {
        EncodeIID(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvObject, FAILED(result));
        encoder->EncodeInt32Value(result);

        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IUnknown_AddRef(IUnknown_Wrapper* wrapper, uint32_t result)
{
    auto encoder =
        TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IUnknown_AddRef, wrapper->GetObjectId());
    if (encoder)
    {
        encoder->EncodeUInt32Value(result);

        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IUnknown_Release(IUnknown_Wrapper* wrapper, uint32_t result)
{
    auto encoder =
        TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IUnknown_Release, wrapper->GetObjectId());
    if (encoder)
    {
        encoder->EncodeUInt32Value(result);

        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
