// ccaprotationcontroller.h - PLACEHOLDER for CCapRotationController (RTTI .?AVCCapRotationController@@, 0x140 bytes), the
// customize controller of the cap (slot 6) rotation. Real owner: ?\caprotationcontroller.cpp (not recovered); only what
// the factory in itemcustomizecontroller_1b.cpp needs (size proved by operator new(0x140) at 0x1414131e0).
#pragma once
#include "ms2/client/ms2/itemcustomizecontroller_1.h"

class CCapRotationController : public CItemCustomizeController
{
public:
    CCapRotationController();   // 0x140b00540
    ~CCapRotationController();   // 0x140b00540
    char m_pad_b8[0x140 - 0xb8];
};
MS2_CHECK_SIZE(CCapRotationController, 0x140);
