// gfxvalue.h - PLACEHOLDER for Scaleform::GFx::Value (Scaleform 4.x, x64). NOT the SDK header.
// The SDK is not in the repository. Evidence: the result of AScript's Invoke helpers is destroyed by 0x140614800,
// which is Value::~Value() (IsManagedValue 0x140614b60 -> ReleaseManagedValue 0x140614ba0, then Type = 0 at +0x08);
// AScript (0x40 bytes) = CPtred (0x18) + 8 + Value (0x20) at +0x20; GFx::FunctionHandler appears in RTTI.
#pragma once

#include "ms2/ms2layout.h"

namespace Scaleform {
namespace GFx {

class Value
{
public:
    Value();                            // 0x1409affa0
    ~Value();                           // 0x140614800

private:
    void* m_pObjectInterface;           // +0x00
    int m_Type;                         // +0x08 ValueType
    int m_pad_0c;                       // not char[4]: an array member makes every local Value a /GS buffer
    void* m_mValue;                     // +0x10 ValueUnion
    void* m_DataAux;                    // +0x18
};
MS2_CHECK_SIZE(Value, 0x20);

}  // namespace GFx
}  // namespace Scaleform
