// ms2hook.h - glue between recovered game code (src/ms2/...) and the original MapleStory2.exe.
//
// Recovered code includes this header and uses four macros:
//
//   MS2_REPLACE(va, function, guardLen, guardHash)
//       Redirect the original function at `va` (KMS2_DEV x64 VA, ImageBase 0x140000000) to `function`
//       (free function or static member). Namespace scope, directly after the definition.
//   MS2_REPLACE_METHOD(va, Class, Method, guardLen, guardHash)
//       Same for a (virtual or non-virtual) member function. A thunk `R(Class* self, args...)` that calls
//       `self->Class::Method(args...)` non-virtually is generated, so virtual methods work too.
//       Method must not be overloaded.
//   guardLen/guardHash: FNV-1a-32 of the first guardLen bytes of the original function (normally the whole
//       function). Generate with `tools/ms2hook_sig.py <va>...`. The hook is refused (and logged) if the bytes in
//       memory differ, i.e. the exe is not the one the code was recovered from. guardLen 0 = unguarded (logged).
//
//   MS2_EXTERN(va, Signature, name)      typed callable for a not-yet-recovered original function:
//       MS2_EXTERN(0x140768210, void(CRandom* self, UINT seed), CRandom_Seed);  CRandom_Seed(&rnd, 5);
//       Member functions are declared with an explicit `self` first parameter (x64 has one calling
//       convention). Caveat: MSVC member functions returning a class by value use a hidden return pointer
//       *after* `this`; declare those as `Ret* (Self*, Ret* out, args...)`.
//   MS2_GLOBAL(va, Type, name)           reference to an original global:
//       MS2_GLOBAL(0x143aac528, CBufferCryptManager*, g_pBufferCryptManager);
//       g_pBufferCryptManager = p;  Type* p = &g_pBufferCryptManager;  name.get(), name->field, name[i].
//
//   MS2_ORIGINAL(va, Signature)          pointer to the original code (Detours trampoline if `va` is hooked,
//       the original address otherwise) - for calling the original from a replacement or a diff test.
//
// When everything is recovered the same sources are built into a standalone exe with MS2_STANDALONE defined:
// MS2_REPLACE* then expand to nothing and any remaining MS2_EXTERN / MS2_GLOBAL is a compile error
// (= an unrecovered dependency).
//
// Only standard C++17 + MSVC extensions: must build with cl 19.16 and clang-cl.
#pragma once

#include <cstddef>
#include <cstdint>
#include <utility>

#define MS2_CAT2(a, b) a##b
#define MS2_CAT(a, b) MS2_CAT2(a, b)

namespace ms2 {

constexpr uintptr_t kImageBase = 0x140000000;  // preferred (and, without DYNAMIC_BASE, actual) ImageBase

#ifndef MS2_STANDALONE

// Actual load address minus kImageBase. Set by the hook runtime before any hook is installed.
extern uintptr_t g_imageDelta;

inline void* VaToPtr(uintptr_t va) { return reinterpret_cast<void*>(va + g_imageDelta); }

namespace hook {

// One registered replacement. Static storage, linked into a list at static-init time (before DllMain).
struct Replacement {
    uintptr_t va;           // original function VA (ImageBase 0x140000000)
    void* fn;               // replacement
    const char* name;       // for the log
    const char* file;
    int line;
    uint32_t guardLen;      // 0 = unguarded
    uint32_t guardHash;     // FNV-1a-32 of guardLen original bytes at va
    // filled by the runtime
    Replacement* next;
    void* original;         // trampoline after install, else VaToPtr(va)
    volatile uint64_t* counter;  // call counter (counting stub), may be null
    bool installed;
};

bool Register(Replacement* r);
void* Original(uintptr_t va);         // trampoline if installed, else VaToPtr(va)
void* ReplacementFn(uintptr_t va);    // the registered replacement (bypassing the counting stub) or null
bool IsInstalled(uintptr_t va);
void Log(const char* fmt, ...);       // ms2hook.log next to the exe

namespace detail {
template <class T> struct MethodSig;
template <class C, class R, class... A> struct MethodSig<R (C::*)(A...)> { using Free = R (*)(C*, A...); };
template <class C, class R, class... A> struct MethodSig<R (C::*)(A...) const> { using Free = R (*)(const C*, A...); };
template <class F> inline void* FnToVoid(F f) { return reinterpret_cast<void*>(f); }
}  // namespace detail
}  // namespace hook

template <uintptr_t VA, class Sig> struct Extern;
template <uintptr_t VA, class R, class... A> struct Extern<VA, R(A...)> {
    using Fn = R (*)(A...);
    Fn get() const { return reinterpret_cast<Fn>(VaToPtr(VA)); }
    R operator()(A... a) const { return get()(std::forward<A>(a)...); }
};

template <uintptr_t VA, class T> struct Global {
    T& get() const { return *reinterpret_cast<T*>(VaToPtr(VA)); }
    operator T&() const { return get(); }
    T* operator&() const { return &get(); }
    T* operator->() const { return &get(); }
    template <class U> T& operator=(U&& v) const { return get() = std::forward<U>(v); }
    template <class I> decltype(auto) operator[](I i) const { return get()[i]; }
};

#endif  // !MS2_STANDALONE
}  // namespace ms2

#ifndef MS2_STANDALONE

#define MS2_REPLACE_IMPL(va, fnptr, nameStr, glen, ghash)                                                   \
    static ::ms2::hook::Replacement MS2_CAT(ms2_replacement_, __LINE__){                                   \
        (va), ::ms2::hook::detail::FnToVoid(fnptr), nameStr, __FILE__, __LINE__, (glen), (ghash),          \
        nullptr, nullptr, nullptr, false};                                                                  \
    static const bool MS2_CAT(ms2_registered_, __LINE__) =                                                  \
        ::ms2::hook::Register(&MS2_CAT(ms2_replacement_, __LINE__))

#define MS2_REPLACE(va, function, glen, ghash) MS2_REPLACE_IMPL(va, &function, #function, glen, ghash)

#define MS2_REPLACE_METHOD(va, Class, Method, glen, ghash)                                                  \
    MS2_REPLACE_IMPL(va,                                                                                    \
        static_cast<::ms2::hook::detail::MethodSig<decltype(&Class::Method)>::Free>(                        \
            [](auto* self, auto... a) -> decltype(auto) {                                                   \
                return self->Class::Method(std::forward<decltype(a)>(a)...);                                \
            }),                                                                                             \
        #Class "::" #Method, glen, ghash)

#define MS2_EXTERN(va, Sig, name) static constexpr ::ms2::Extern<(va), Sig> name {}
#define MS2_GLOBAL(va, Type, name) static constexpr ::ms2::Global<(va), Type> name {}

#define MS2_ORIGINAL(va, Sig)                                                                               \
    ([]() -> Sig* {                                                                                         \
        static Sig* const p = reinterpret_cast<Sig*>(::ms2::hook::Original(va));                           \
        return p;                                                                                           \
    }())

#else  // MS2_STANDALONE

#define MS2_REPLACE(va, function, glen, ghash) static_assert(true, "")
#define MS2_REPLACE_METHOD(va, Class, Method, glen, ghash) static_assert(true, "")
#define MS2_EXTERN(va, Sig, name) static_assert(false, "unrecovered function " #va " (" #name ")")
#define MS2_GLOBAL(va, Type, name) static_assert(false, "unrecovered global " #va " (" #name ")")
#define MS2_ORIGINAL(va, Sig) static_assert(false, "MS2_ORIGINAL is hook-DLL only")

#endif  // MS2_STANDALONE
