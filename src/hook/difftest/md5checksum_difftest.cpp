// Differential test for src/ms2/commonfiles/md5checksum.cpp: CMD5Checksum::GetMD5(BYTE*, UINT), original
// (trampoline) vs. recovered, on random buffers + RFC 1321 vectors. The function is dead code in the game (only
// reachable through this test), so this is the unit's smoke test.
//
// GetMD5 is static and returns a CString by value: Win64 passes the hidden return slot first, the result is a CString
// = one pointer to the NUL-terminated character data. The test does not include MFC (hook flags), so the strings are
// compared as char* and leaked (a few KB once per process).
#include "difftest.h"

#include <cstring>

namespace {

using GetMD5Fn = char**(char** ret, unsigned char* buf, unsigned len);

}  // namespace

MS2_DIFFTEST(CMD5Checksum_GetMD5)
{
    auto fns = ms2::difftest::Pair<GetMD5Fn>(0x140696E00);
    if (!fns) return ctx.Skip("hook not installed");
    struct Vec { const char* in; const char* md5; };
    static const Vec kRfc[] = {{"", "d41d8cd98f00b204e9800998ecf8427e"},
                               {"abc", "900150983cd24fb0d6963f7d28e17f72"},
                               {"message digest", "f96b697d7cb7938d525a2f31aaf161d0"}};
    for (const Vec& v : kRfc) {
        char* a = nullptr;
        char* b = nullptr;
        unsigned n = static_cast<unsigned>(std::strlen(v.in));
        fns.orig(&a, reinterpret_cast<unsigned char*>(const_cast<char*>(v.in)), n);
        fns.repl(&b, reinterpret_cast<unsigned char*>(const_cast<char*>(v.in)), n);
        ctx.ExpectEq(0, std::strcmp(a, v.md5), "original vs RFC 1321");
        ctx.ExpectEq(0, std::strcmp(b, v.md5), "recovered vs RFC 1321");
    }
    unsigned char buf[300];
    for (unsigned n = 0; n < sizeof buf; n += 7) {
        ctx.rng.Fill(buf, sizeof buf);
        char* a = nullptr;
        char* b = nullptr;
        fns.orig(&a, buf, n);
        fns.repl(&b, buf, n);
        ctx.ExpectEq<size_t>(32, std::strlen(b), "digest length");
        ctx.ExpectBytes(a, b, 33, "digest string");
    }
}
