// sdkshim/Kernel/SF_SIMD.h - clang-cl only (cmake/ms2-scaleform-sdk.cmake puts src/ms2/sdkshim before the SDK for clang).
// The SDK's Kernel/SF_SIMD_SSE.h::Constant<> initialises a __m128i with 16 byte values under `#if defined(_MSC_VER)`; that is
// only valid for cl's union-style __m128i, clang's __m128i is a vector type ("excess elements in vector initializer").
// The layout-relevant parts (SF_SIMD_ALIGN = 16-byte alignment of Matrix*/CxForm, SF_ENABLE_SIMD) must stay the same as cl, so
// SIMD is NOT turned off: the real header is included with the GNU branches selected instead (`x __attribute__((aligned(16)))`
// is the same alignment as __declspec(align(16)); Constant<> then uses _mm_set_epi32). Verified identical by
// work/sf1/layout_probe (sizeof/alignof/offsetof static_asserts under both compilers).
// cl 19.16 never sees this file (the shim dir is only added for clang), so there is no #include_next problem.
#pragma once
#if defined(__clang__) && defined(_MSC_VER)
    #include "GFxConfig.h"
    #include "Kernel/SF_Types.h"      // decides SF_CC_*/SF_CPU_SSE while _MSC_VER is still set
    #pragma push_macro("_MSC_VER")
    #undef _MSC_VER
    #define __GNUC__ 4
    #define SF_CC_GNU
    #include_next "Kernel/SF_SIMD.h"
    #undef SF_CC_GNU
    #undef __GNUC__
    #pragma pop_macro("_MSC_VER")
#else
    #include_next "Kernel/SF_SIMD.h"
#endif
