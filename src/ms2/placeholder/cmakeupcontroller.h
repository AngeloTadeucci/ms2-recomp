// cmakeupcontroller.h - PLACEHOLDER for CMakeupController (RTTI .?AVCMakeupController@@, 0xe0 bytes), the customize
// controller of the makeup slot. Real owner: ?\makeupcontroller.cpp (not recovered); only what the factory in
// itemcustomizecontroller_1b.cpp needs (size proved by operator new(0xe0) at 0x1414131e0). The unit that recovers
// it replaces this file with its own header.
#pragma once
#include "ms2/client/ms2/itemcustomizecontroller_1.h"

class CMakeupController : public CItemCustomizeController
{
public:
    CMakeupController();                                            // 0x1414762e0 (makeupcontroller.cpp)
    ~CMakeupController();
    char m_pad_b8[0xe0 - 0xb8];
};
MS2_CHECK_SIZE(CMakeupController, 0xe0);
