###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2020 Advanced Micro Devices, Inc.
# All rights reserved
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Author: LunarG Team
# Author: AMD Developer Tools Team
# Description: CMake script for framework util target
###############################################################################

if (WIN32)

add_library(dx12_capture SHARED "")
target_sources(dx12_capture PRIVATE ${CMAKE_CURRENT_LIST_DIR}/dx12_dispatch_table.h ${CMAKE_CURRENT_LIST_DIR}/dll_main_dx12.cpp ${CMAKE_CURRENT_LIST_DIR}/dx12_capture.def)
target_include_directories(dx12_capture PUBLIC ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR})
target_link_libraries(dx12_capture platform_specific)
common_build_directives(dx12_capture)

add_library(d3d12 SHARED "")
target_sources(d3d12 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/dll_main_d3d12.cpp ${CMAKE_CURRENT_LIST_DIR}/d3d12.def)
target_include_directories(d3d12 PUBLIC ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR})
target_link_libraries(d3d12 platform_specific ${CMAKE_CURRENT_LIST_DIR}/d3d12_ms.lib)
common_build_directives(d3d12)

add_library(dxgi SHARED "")
target_sources(dxgi PRIVATE ${CMAKE_CURRENT_LIST_DIR}/dll_main_dxgi.cpp ${CMAKE_CURRENT_LIST_DIR}/dxgi.def)
target_include_directories(dxgi PUBLIC ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR})
target_link_libraries(dxgi platform_specific ${CMAKE_CURRENT_LIST_DIR}/dxgi_ms.lib)
common_build_directives(dxgi)

endif()


add_library(VkLayer_gfxreconstruct SHARED "")

target_sources(VkLayer_gfxreconstruct
               PRIVATE
                   ${CMAKE_CURRENT_LIST_DIR}/dll_main.cpp
                   ${CMAKE_CURRENT_LIST_DIR}/trace_layer.h
                   ${CMAKE_CURRENT_LIST_DIR}/trace_layer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_layer_func_table.h
                   $<$<BOOL:WIN32>:${CMAKE_CURRENT_LIST_DIR}/trace_layer.def>
              )

target_include_directories(VkLayer_gfxreconstruct
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${CMAKE_SOURCE_DIR})

target_link_libraries(VkLayer_gfxreconstruct gfxrecon_encode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

common_build_directives(VkLayer_gfxreconstruct)

# The json output file needs Unix "/" separators or Windows "\" separators
# On top of that, Windows separators actually need to be doubled because the json format uses backslash escapes
file(TO_NATIVE_PATH "./" RELATIVE_PATH_PREFIX)
string(REPLACE "\\" "\\\\" RELATIVE_PATH_PREFIX "${RELATIVE_PATH_PREFIX}")
include("GenerateLayerJson")
# Generate the JSON file that will be generated into the build directory
GENERATE_LAYER_JSON_FILE(VkLayer_gfxreconstruct_json
        "${RELATIVE_PATH_PREFIX}"
        $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
        ${CMAKE_CURRENT_SOURCE_DIR}/json/VkLayer_gfxreconstruct.json.in
        $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json
        )

if(UNIX)
        # Generate a JSON file that can be installed into system directories (w/o the "./" prefix in the library_path)
        set(RELATIVE_PATH_PREFIX "")
        GENERATE_LAYER_JSON_FILE(VkLayer_gfxreconstruct_json-staging
                "${RELATIVE_PATH_PREFIX}"
                $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
                ${CMAKE_CURRENT_SOURCE_DIR}/json/VkLayer_gfxreconstruct.json.in
                $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/VkLayer_gfxreconstruct.json
                )
endif()

install(TARGETS VkLayer_gfxreconstruct RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
if (UNIX)
    install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/VkLayer_gfxreconstruct.json DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/vulkan/explicit_layer.d)
else()
    install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

if (${RUN_TESTS})
    add_executable(VkLayer_gfxreconstruct_test "")

    target_sources(VkLayer_gfxreconstruct_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)
    target_link_libraries(VkLayer_gfxreconstruct_test PRIVATE VkLayer_gfxreconstruct)

    common_build_directives(VkLayer_gfxreconstruct_test)
    common_test_directives(VkLayer_gfxreconstruct_test)
endif()
