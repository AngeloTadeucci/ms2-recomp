// ms2format.h - the game's "{0} {1}" string formatter on top of fmt (ms2/fmt/format.h). NOT an original header;
// the function name StringFormat is invented (no symbol, string or assert names it).
//
//   CString  StringFormat(const char* format, const fmt::ArgList& args);     // 0x1401dca30 (MemoryWriter -> CString)
//   CStringW StringFormat(const wchar_t* format, const fmt::ArgList& args);  // 0x1401d02a0 (wide)
//
// FMT_VARIADIC adds the templates StringFormat(format, const T0& v0, ..., const Tn& vn) for 1..15 arguments.
// Each distinct argument-type list is one COMDAT in the first unit that uses it (string literals are char[N],
// so the __FILE__ length makes most instances unit-local), together with the ArgType(const char(&)[N]) ctor
// and fmt::internal::make_type<char[N]> instances it calls. Write the call naturally, e.g. the GfxError macro shape:
//   StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(26), __FUNCTION__)
// (an int line binds to const int&). See docs/RECOVERY.md section 8 "fmt formatter".
#pragma once

#include "ms2/fmt/format.h"

CString StringFormat(const char* format, const fmt::ArgList& args);
CStringW StringFormat(const wchar_t* format, const fmt::ArgList& args);
FMT_VARIADIC(CString, StringFormat, const char*)
FMT_VARIADIC_W(CStringW, StringFormat, const wchar_t*)
CStringW StringFormat(const wchar_t* format);    // 0x1402a61e0: no arguments (out of line)

// The exe has a second, name-wise unknown formatter with the same signature (0x1402bf9a0: forwards to StringFormat, as the
// socket code uses it). Some units' FMT_VARIADIC instances call it instead of 0x1401dca30; the name is invented.
CString Unk_SocketFormat(const char* format, const fmt::ArgList& args);
FMT_VARIADIC(CString, Unk_SocketFormat, const char*)
