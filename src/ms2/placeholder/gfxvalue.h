// gfxvalue.h - Scaleform::GFx::Value / FunctionHandler::Params: the real SDK headers when MS2_HAVE_SCALEFORM_SDK is defined,
// otherwise the PLACEHOLDER below (Scaleform 4.x, x64; not the SDK header). Evidence: the result of AScript's Invoke helpers is destroyed by 0x140614800,
// which is Value::~Value() (IsManagedValue 0x140614b60 -> ReleaseManagedValue 0x140614ba0, then Type = 0 at +0x08);
// AScript (0x40 bytes) = CPtred (0x18) + 8 + Value (0x20) at +0x20; GFx::FunctionHandler appears in RTTI.
#pragma once

#include "ms2/ms2layout.h"

#if defined(MS2_HAVE_SCALEFORM_SDK)
// Real Scaleform GFx SDK headers (cmake/ms2-scaleform-sdk.cmake: MS2_SCALEFORM_SDK, SF_BUILD_SHIPPING, SF_BUILD_STATICLIB;
// tools/progress.py adds the same /I and /D). Value and FunctionHandler::Params come from <GFx/GFx_Player.h>; their layouts
// are validated against the exe (NOTES.md "sf1: Scaleform 4.1.19 SDK"). The SDK's Params names the AS argument array
// pArgsWithThisRef (the placeholder called it pArgsWithThis; no recovered unit used the field). The Render HAL, Video and Nexon
// Scaleform types are NOT in the SDK layout of the exe (4.1.18) and stay MS2 placeholders. Include SDK headers through this
// file.
//
// Static initializers: the SDK defines `template<class T> Matrix4x4<T> Matrix4x4<T>::Identity;` (and 2x4, 3x4) in the header; cl
// emits a dynamic initializer (`??__E?Identity...`) for each in every unit. The exe's units have none (no .text$di function in the
// Scaleform lib range stores an identity matrix; the SetIdentity callers are only the `??_F` closures), and these look-alike
// `sub rsp,28h / lea rcx / call / add rsp / ret` functions make progress.py's auto-pairing of the unit's atexit thunks ambiguous
// (questmanager_2: 4 matched thunks became stubs). The extern template declarations suppress the definitions; nothing uses Identity.
#include "GFxConfig.h"
#include "Render/Render_Matrix2x4.h"
#include "Render/Render_Matrix3x4.h"
#include "Render/Render_Matrix4x4.h"
namespace Scaleform { namespace Render {
extern template Matrix2x4<float> Matrix2x4<float>::Identity;
extern template Matrix3x4<float> Matrix3x4<float>::Identity;
extern template Matrix4x4<float> Matrix4x4<float>::Identity;
}}
#pragma warning(push)
#pragma warning(disable : 4838 4244)    // SF_SIMD_SSE.h(111), Render_HAL.h(658): SDK noise
#include "GFx/GFx_Player.h"
#pragma warning(pop)

MS2_CHECK_SIZE(Scaleform::GFx::Value, 0x20);
MS2_CHECK_SIZE(Scaleform::GFx::FunctionHandler::Params, 0x38);
#else

namespace Scaleform {
namespace GFx {

class Value
{
public:
    Value();                            // 0x1409affa0
    Value(const Value& o);              // 0x1406146a0 (copy, adds a reference to managed values)
    Value(bool b);                      // 0x140f17720 (appended by the uiobject.cpp agent)
    ~Value();                           // 0x140614800
    Value& operator=(const Value& o);   // 0x1409b4bc0 (appended by the uiobject.cpp agent)

private:
    void* m_pObjectInterface;           // +0x00
    int m_Type;                         // +0x08 ValueType
    int m_pad_0c;                       // not char[4]: an array member makes every local Value a /GS buffer
    void* m_mValue;                     // +0x10 ValueUnion
    void* m_DataAux;                    // +0x18
};
MS2_CHECK_SIZE(Value, 0x20);

// FunctionHandler::Params: the argument block of an AS -> C++ function callback (Scaleform 4.x layout; only pRetVal
// is used so far). Appended by the uiobject.cpp agent (UIObject::vfunc_51 is bound as a
// Delegate<void(const Params&)>; RTTI spells it `struct Scaleform::GFx::FunctionHandler::Params`).
class FunctionHandler
{
public:
    struct Params
    {
        Value* pRetVal;                 // +0x00
        void* pMovie;                   // +0x08
        Value* pThis;                   // +0x10
        Value* pArgsWithThis;           // +0x18
        Value* pArgs;                   // +0x20
        unsigned int ArgCount;          // +0x28
        void* pUserData;                // +0x30
    };
};

}  // namespace GFx
}  // namespace Scaleform
#endif  // MS2_HAVE_SCALEFORM_SDK
