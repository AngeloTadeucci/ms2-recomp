// ms2recover.h - helpers for byte-matching recovered game code. NOT an original Nexon header.
// Conventions: docs/RECOVERY.md. Must stay C++14 and compile under cl 19.16 and clang-cl.
//
//   MS2_THIS_FILE        every recovered .cpp defines it (before including anything) as the original __FILE__ string,
//                        e.g. #define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\md5checksum.cpp"
//   MS2_ASSERT_AT(line, expr)
//                        assert() with the original line number: same code as <assert.h>'s assert (no NDEBUG in the
//                        game build), but file/line are the original ones, so the source keeps its own line numbers
//                        (and line tables stay usable by tools/progress.py). Use the line from the decompiled
//                        _wassert call (3rd argument).
//   MS2_LINE(line)       an original __LINE__ value used outside assert (logging/exception macros).
//   MS2_CHECK_SIZE(T, n) / MS2_CHECK_OFFSET(T, member, off)
//                        layout pins (ms2layout.h, which headers include directly).
//   MS2_EMIT_CRT_MEMMOVE_S()
//                        ~45% of the original objs contain an unreferenced copy of the CRT's static-inline memmove_s
//                        (271 bytes, sorted last in the obj's COMDAT tail). Its referrer was a discarded COMDAT whose
//                        source is unknown (not reproducible from afx/atl/std headers alone). This forces the same copy
//                        through ATL::Checked::memmove_s, which the original also used. Put it once at file scope.
#pragma once

#include <assert.h>
#include <stddef.h>

#include "ms2/ms2layout.h"

#ifndef MS2_THIS_FILE
#error "define MS2_THIS_FILE (the original __FILE__ string) before including ms2recover.h"
#endif

// <assert.h> only declares _wassert without NDEBUG (the clang-cl RelWithDebInfo build defines it); the game asserts always.
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#define MS2_ASSERT_AT(line, expression)                                                                   \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))

#define MS2_LINE(line) (line)


#define MS2_EMIT_CRT_MEMMOVE_S()                                                                          \
    __declspec(selectany) extern void(__cdecl* const ms2_pfnCheckedMemmoveS)(void*, size_t, const void*, size_t) = \
        &ATL::Checked::memmove_s
