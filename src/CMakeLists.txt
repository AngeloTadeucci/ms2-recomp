# Recompiled MapleStory2 code + hook DLL (proxy dinput8.dll loaded by the original KMS2_DEV x64 MapleStory2.exe).
#   clang-cl:  cmake -G Ninja -S src -B build/hook-clang -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-clangcl-x64.cmake
#   cl 19.16:  cmake -G Ninja -S src -B build/hook-msvc  -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-msvc1416-wine.cmake
# See NOTES.md "Recompiled source layout & hook DLL".
cmake_minimum_required(VERSION 3.20)
if(NOT DEFINED CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif()
project(ms2recomp C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(MS2HOOK_WITH_GAME "Link the recovered game code (src/ms2) and its difftests into the hook DLL" ON)
option(MS2HOOK_WITH_COMPAT "Link the client compatibility fixes (src/hook/compat, not game code; NOTES \"Field-entry crash\")" ON)

add_compile_definitions(WIN32_LEAN_AND_MEAN NOMINMAX _CRT_SECURE_NO_WARNINGS)
add_compile_options(/W3 /EHsc /utf-8)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wno-microsoft-cast -Wno-unused-command-line-argument)
endif()

# Recovered game code: OBJECT library `ms2game` (src/ms2/CMakeLists.txt), compiled with Nexon's game-code flags under
# cl 19.16 (cmake/ms2-game-flags.cmake; NOTES "Game-code compiler flags (byte-matching)") and linked object by object
# into the DLL (never via a static library: the linker would drop objects whose only content is MS2_REPLACE
# registrations, since nothing references them).
file(GLOB_RECURSE MS2_DIFFTEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/hook/difftest/*.cpp")
file(GLOB_RECURSE MS2_COMPAT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/hook/compat/*.cpp")

add_library(detours STATIC hook/detours/detours.cpp hook/detours/disasm.cpp hook/detours/modules.cpp)
target_compile_definitions(detours PRIVATE DETOURS_X64 DETOURS_64BIT)
target_compile_options(detours PRIVATE /W0)

add_library(dinput8 SHARED
    hook/dinput8_proxy.cpp
    hook/hook_runtime.cpp
    hook/difftest.cpp)
if(MS2HOOK_WITH_GAME)
    add_subdirectory(ms2)
    target_sources(dinput8 PRIVATE $<TARGET_OBJECTS:ms2game> ${MS2_DIFFTEST_SOURCES})
endif()
if(MS2HOOK_WITH_COMPAT)
    target_sources(dinput8 PRIVATE ${MS2_COMPAT_SOURCES})
endif()
target_include_directories(dinput8 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/hook")
target_link_libraries(dinput8 PRIVATE detours)
set_target_properties(dinput8 PROPERTIES OUTPUT_NAME dinput8 PREFIX "")
target_link_options(dinput8 PRIVATE /DEBUG /OPT:REF /OPT:ICF)
