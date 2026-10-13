// ms2layout.h - layout pins for recovered and placeholder classes. NOT an original Nexon header.
// Usable from headers (unlike ms2recover.h, which needs MS2_THIS_FILE). Conventions: docs/RECOVERY.md.
//
//   MS2_CHECK_SIZE(T, n) / MS2_CHECK_OFFSET(T, member, off)
//       static_assert(sizeof / offsetof) with the size/offset from Ghidra or the disassembly; no code.
//       Put them right after the class. offsetof on a non-standard-layout class is fine under cl/clang-cl.
//   Placeholder padding: use scalar fields (void*, int), never char[N]. /GS treats a local of any class containing
//   an array as a buffer, which adds the cookie and __GSHandlerCheck where the exe has none.
//   MS2_LAYOUT_FRIEND
//       Put it in the class body when MS2_CHECK_OFFSET names private/protected members (one friend declaration;
//       it changes neither layout nor codegen). The offset check is then an explicit specialization of the friend.
#pragma once

#include <stddef.h>

template <class T, int nLine> struct MS2LayoutCheck;

#define MS2_LAYOUT_FRIEND template <class, int> friend struct ::MS2LayoutCheck
#define MS2_CHECK_SIZE(T, n) static_assert(sizeof(T) == (n), "sizeof(" #T ") != " #n)
#define MS2_CHECK_OFFSET(T, member, off)                                                                   \
    template <> struct MS2LayoutCheck<T, __LINE__> {                                                       \
        static_assert(offsetof(T, member) == (off), "offsetof(" #T ", " #member ") != " #off);             \
    }
