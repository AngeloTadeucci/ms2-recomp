// cponytailcontroller.h - PLACEHOLDER for CPonyTailController (RTTI .?AVCPonyTailController@@, 0x250 bytes), the
// customize controller of the hair-physics (slot 1) ponytail. Real owner: client\ms2\ponytailphysxhelper.cpp (not
// recovered); only what the factory in itemcustomizecontroller_1b.cpp needs (size proved by operator new(0x250) at
// 0x1414131e0).
#pragma once
#include "ms2/client/ms2/itemcustomizecontroller_1.h"

class CPonyTailController : public CItemCustomizeController
{
public:
    CPonyTailController();   // 0x141691a20
    ~CPonyTailController();   // 0x141691a20
    char m_pad_b8[0x250 - 0xb8];
};
MS2_CHECK_SIZE(CPonyTailController, 0x250);
