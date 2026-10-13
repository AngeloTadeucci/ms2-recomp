// Differential tests: run the original code (via its Detours trampoline) and the recovered replacement on the
// same inputs inside the game process and compare. Hook-DLL only (src/hook/difftest/*.cpp).
//
//   MS2_DIFFTEST(CXORCrypter_Encrypt) {
//       auto fns = ms2::difftest::Pair<void(CXORCrypter*, BYTE*, UINT, void*)>(0x1401cd490);
//       if (!fns) return ctx.Skip("not installed");
//       ... set up two identical inputs with ctx.rng, call fns.orig(...) and fns.repl(...),
//       ctx.ExpectBytes(...) / ctx.ExpectEq(...) / ctx.CallBoth(fns, args...) for pure functions.
//   }
//
// Tests run in DllMain right after the hooks are installed (MS2HOOK_DIFFTEST=0 disables them), i.e. before any
// game code (and before the exe's CRT init): only use them for pure functions that need no game state.
// Results go to ms2hook.log ("DIFFTEST PASS/FAIL/SKIP name: checks=N").
#pragma once

#include "ms2hook.h"

#include <cstdint>
#include <cstring>
#include <type_traits>

namespace ms2::difftest {

struct Rng {  // xorshift64*, deterministic per test
    uint64_t s;
    uint64_t Next() {
        s ^= s >> 12;
        s ^= s << 25;
        s ^= s >> 27;
        return s * 0x2545F4914F6CDD1Dull;
    }
    uint32_t Below(uint32_t n) { return n ? static_cast<uint32_t>(Next() % n) : 0; }
    void Fill(void* p, size_t n) {
        auto* b = static_cast<uint8_t*>(p);
        for (size_t i = 0; i < n; ++i) b[i] = static_cast<uint8_t>(Next() >> 56);
    }
};

template <class Sig> struct Fns;
template <class R, class... A> struct Fns<R(A...)> {
    R (*orig)(A...);
    R (*repl)(A...);
    explicit operator bool() const { return orig && repl; }
};

// Original (trampoline) and replacement of a hooked VA; both null if the hook is not installed.
template <class Sig> Fns<Sig> Pair(uintptr_t va) {
    Fns<Sig> f{nullptr, nullptr};
    if (hook::IsInstalled(va)) {
        f.orig = reinterpret_cast<decltype(f.orig)>(hook::Original(va));
        f.repl = reinterpret_cast<decltype(f.repl)>(hook::ReplacementFn(va));
    }
    return f;
}

struct Context {
    const char* name;
    Rng rng;
    unsigned checks = 0;
    unsigned failures = 0;
    const char* skipped = nullptr;

    void Skip(const char* why) { skipped = why; }
    void Fail(const char* fmt, ...);

    bool ExpectBytes(const void* orig, const void* repl, size_t n, const char* what);

    template <class T> bool ExpectEq(const T& orig, const T& repl, const char* what) {
        ++checks;
        if (orig == repl) return true;
        if constexpr (std::is_integral_v<T> || std::is_enum_v<T>)
            Fail("%s: orig=%lld repl=%lld", what, static_cast<long long>(orig), static_cast<long long>(repl));
        else
            Fail("%s: values differ", what);
        return false;
    }

    // Pure function: call both with the same arguments, compare the results.
    template <class R, class... A, class... P> bool CallBoth(const Fns<R(A...)>& f, P&&... args) {
        if constexpr (std::is_void_v<R>) {
            f.orig(args...);
            f.repl(args...);
            ++checks;
            return true;
        } else {
            R a = f.orig(args...);
            R b = f.repl(args...);
            return ExpectEq(a, b, "return value");
        }
    }
};

using TestFn = void (*)(Context&);
bool Register(const char* name, TestFn fn, const char* file, int line);

}  // namespace ms2::difftest

#define MS2_DIFFTEST(name)                                                                                  \
    static void ms2_difftest_##name(::ms2::difftest::Context& ctx);                                         \
    static const bool ms2_difftest_registered_##name =                                                      \
        ::ms2::difftest::Register(#name, &ms2_difftest_##name, __FILE__, __LINE__);                         \
    static void ms2_difftest_##name(::ms2::difftest::Context& ctx)
