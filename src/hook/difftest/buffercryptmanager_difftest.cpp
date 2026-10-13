// Differential tests for src/ms2/commonfiles/buffercryptmanager.cpp: original (trampoline) vs. recovered code on
// identical random buffers. The crypter objects are faked with layout-compatible structs: the replacements are
// called through their non-virtual thunks, so the vptr is never used.
#include "difftest.h"

#include <vector>

#include "ms2/commonfiles/buffercryptmanager.h"

namespace {

using CryptFn = void(IBufferCrypter*, BYTE*, UINT, void*);
using DecryptFn = BOOL(IBufferCrypter*, BYTE*, UINT, void*);

struct FakeXOR { void* vptr; BYTE* pKey; };
struct FakeTable { void* vptr; BYTE* pEnc; BYTE* pDec; };
struct FakeRearrange { void* vptr; };

// Run orig and repl on copies of the same random buffer for a range of sizes (0..300 and a few big ones).
template <class Sig, class Obj>
void RunBuffers(ms2::difftest::Context& ctx, uintptr_t va, Obj* obj, const char* what)
{
    auto fns = ms2::difftest::Pair<Sig>(va);
    if (!fns) return ctx.Skip("hook not installed");
    auto* self = reinterpret_cast<IBufferCrypter*>(obj);
    static const UINT kBig[] = {1023, 4096, 65537};
    for (UINT k = 0; k < 301 + 3; ++k) {
        UINT n = k < 301 ? k : kBig[k - 301];
        std::vector<BYTE> a(n + 1), b;
        ctx.rng.Fill(a.data(), a.size());
        b = a;  // last byte is a canary: must stay untouched
        if constexpr (std::is_same_v<Sig, DecryptFn>) {
            ctx.ExpectEq(fns.orig(self, a.data(), n, nullptr), fns.repl(self, b.data(), n, nullptr), "return value");
        } else {
            fns.orig(self, a.data(), n, nullptr);
            fns.repl(self, b.data(), n, nullptr);
        }
        ctx.ExpectBytes(a.data(), b.data(), a.size(), what);
    }
}

// Not-yet-recovered originals, called on the fake objects to get the real key/tables (version 2525).
MS2_EXTERN(0x1401CD3B0, void(FakeXOR* self), CXORCrypter_Init);
MS2_EXTERN(0x1401CD6B0, void(FakeTable* self), CTableCrypter_Init);
MS2_GLOBAL(0x143AAC528, void*, g_pBufferCryptManager);  // TSingleton<CBufferCryptManager>::ms_pInstance

}  // namespace

MS2_DIFFTEST(CXORCrypter_RealKey)
{
    if (!ms2::hook::IsInstalled(0x1401CD490)) return ctx.Skip("hook not installed");
    // Runs before the exe's CRT init: the singleton must not exist yet.
    ctx.ExpectEq<void*>(nullptr, g_pBufferCryptManager, "g_pBufferCryptManager before game init");
    FakeXOR obj{nullptr, nullptr};
    CXORCrypter_Init(&obj);  // original code: allocates the 2-byte key with the game's operator new[]
    ms2::hook::Log("DIFFTEST   CXORCrypter_RealKey: original Init -> key %02x %02x", obj.pKey[0], obj.pKey[1]);
    RunBuffers<CryptFn>(ctx, 0x1401CD490, &obj, "Encrypt buffer");
    RunBuffers<DecryptFn>(ctx, 0x1401CD530, &obj, "Decrypt buffer");
}

MS2_DIFFTEST(CTableCrypter_RealTable)
{
    if (!ms2::hook::IsInstalled(0x1401CD7D0)) return ctx.Skip("hook not installed");
    FakeTable obj{nullptr, nullptr, nullptr};
    CTableCrypter_Init(&obj);
    unsigned inverseOk = 0;
    for (int i = 0; i < 256; ++i) inverseOk += obj.pDec[obj.pEnc[i]] == i;
    ctx.ExpectEq(256u, inverseOk, "decrypt table is the inverse of the encrypt table");
    RunBuffers<CryptFn>(ctx, 0x1401CD7D0, &obj, "Encrypt buffer");
    RunBuffers<DecryptFn>(ctx, 0x1401CD840, &obj, "Decrypt buffer");
}

MS2_DIFFTEST(CXORCrypter)
{
    BYTE key[2];
    ctx.rng.Fill(key, sizeof(key));
    FakeXOR obj{nullptr, key};
    RunBuffers<CryptFn>(ctx, 0x1401CD490, &obj, "Encrypt buffer");
    RunBuffers<DecryptFn>(ctx, 0x1401CD530, &obj, "Decrypt buffer");
}

MS2_DIFFTEST(CTableCrypter)
{
    BYTE enc[256], dec[256];
    for (int i = 0; i < 256; ++i) enc[i] = static_cast<BYTE>(i);
    for (int i = 255; i > 0; --i) std::swap(enc[i], enc[ctx.rng.Below(i + 1)]);  // random permutation
    for (int i = 0; i < 256; ++i) dec[enc[i]] = static_cast<BYTE>(i);
    FakeTable obj{nullptr, enc, dec};
    RunBuffers<CryptFn>(ctx, 0x1401CD7D0, &obj, "Encrypt buffer");
    RunBuffers<DecryptFn>(ctx, 0x1401CD840, &obj, "Decrypt buffer");
}

MS2_DIFFTEST(CRearrangeCrypter)
{
    FakeRearrange obj{nullptr};
    RunBuffers<CryptFn>(ctx, 0x1401CD920, &obj, "Encrypt buffer");
    RunBuffers<DecryptFn>(ctx, 0x1401CD9B0, &obj, "Decrypt buffer");
    // CallBoth: the helper for pure functions (same arguments, compare return values). Size 0 = no side effects.
    if (auto fns = ms2::difftest::Pair<DecryptFn>(0x1401CD9B0))
        ctx.CallBoth(fns, reinterpret_cast<IBufferCrypter*>(&obj), static_cast<BYTE*>(nullptr), 0u, nullptr);
}
