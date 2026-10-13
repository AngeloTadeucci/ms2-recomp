// ms2stdafx.h - PLACEHOLDER for the game's common (precompiled) header. NOT an original Nexon header.
// Conventions: docs/RECOVERY.md ("Placeholders").
//
// Holds what nearly every client unit evidently saw through its stdafx.h, as far as it changes code generation:
//   * MFC/ATL (CString = CStringT<char, StrTraitMFC_DLL<char>>, _MBCS + _AFXDLL from the build flags);
//   * a plain (non-dllimport) redeclaration of _stricmp: 2062 call sites in the exe call the linker's import thunk
//     0x14209b200 directly (`call rel32`), only 4 use `call [__imp__stricmp]`. A redeclaration without
//     __declspec(dllimport) after <string.h> reproduces the direct call (one before <string.h> is an error).
//     Units whose _stricmp calls go through the IAT must not include this header.
#pragma once

#include <afx.h>
#include <afxwin.h>

#include <string.h>

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winconsistent-dllimport"
#else
#pragma warning(push)
#pragma warning(disable : 4273)  // inconsistent dll linkage: intended
#endif
extern "C" int __cdecl _stricmp(const char* _String1, const char* _String2);
#if defined(__clang__)
#pragma clang diagnostic pop
#else
#pragma warning(pop)
#endif
