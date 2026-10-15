# Scaleform GFx SDK headers (4.1.19, partial copy in work/scaleform; untracked, never copied into src/) for the recovered game
# code. Included by src/ms2/CMakeLists.txt; tools/progress.py parses MS2_SCALEFORM_DEFINITIONS / MS2_SCALEFORM_INCLUDE_DIRS from
# this file (keep the "..." one-per-line format). Opt-in: MS2_SCALEFORM_SDK defaults to work/scaleform/4.1.19/Scaleform when it
# exists; pass -DMS2_SCALEFORM_SDK= (empty) to build with the MS2 placeholders only (src/ms2/placeholder/gfxvalue.h).
# When on, the compiler sees MS2_HAVE_SCALEFORM_SDK=1 and gfxvalue.h includes the real <GFx/GFx_Player.h>.
#
# The exe links Scaleform 4.1.18 (NOTES.md "sf1: Scaleform 4.1.19 SDK"): Kernel / GFx::Value / FunctionHandler layouts match
# 4.1.19 (validated), the Render HAL (D3D9::HAL, Render::HAL) does not, so HAL/Video/Nexon types stay MS2 placeholders.
#   SF_BUILD_SHIPPING     no SF_BUILD_DEBUG (no asserts in Array/Hash), no AMP
#   SF_BUILD_STATICLIB    SF_EXPORT expands to nothing. The exe itself was built without it (it exports Scaleform symbols), but
#                         here declarations must not become dllexport of the hook DLL.
# GFxConfig.h defaults are kept (GFX_AS3_SUPPORT on: Value::DataAux at +0x18, matches the exe).
set(MS2_SCALEFORM_DEFINITIONS
    "SF_BUILD_SHIPPING"
    "SF_BUILD_STATICLIB"
    "MS2_HAVE_SCALEFORM_SDK=1"
)
set(MS2_SCALEFORM_INCLUDE_DIRS
    "Include"
    "Src"
)
set(_ms2_sf_default "${CMAKE_CURRENT_LIST_DIR}/../work/scaleform/4.1.19/Scaleform")
if(NOT IS_DIRECTORY "${_ms2_sf_default}")
    set(_ms2_sf_default "")
endif()
set(MS2_SCALEFORM_SDK "${_ms2_sf_default}" CACHE PATH "Scaleform GFx SDK root (dir with Include/ and Src/); empty = placeholders only")

# clang-cl: src/ms2/sdkshim is searched before the SDK (Kernel/SF_SIMD.h shim, see there). cl 19.16 uses the SDK as is.
function(ms2_scaleform_flags target)
    if(NOT MS2_SCALEFORM_SDK OR NOT IS_DIRECTORY "${MS2_SCALEFORM_SDK}")
        return()
    endif()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_include_directories(${target} BEFORE PRIVATE "${PROJECT_SOURCE_DIR}/ms2/sdkshim")
        # clang-cl builds as C++17: the SDK uses `register` locals (Render_Containers.h) and similar C++03 idioms.
        target_compile_options(${target} PRIVATE -Wno-register -Wno-deprecated-declarations)
    endif()
    foreach(d ${MS2_SCALEFORM_INCLUDE_DIRS})
        target_include_directories(${target} PRIVATE "${MS2_SCALEFORM_SDK}/${d}")
    endforeach()
    target_compile_definitions(${target} PRIVATE ${MS2_SCALEFORM_DEFINITIONS})
endfunction()
