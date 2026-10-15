// asgameentity.h - PLACEHOLDER for ASGameEntity (RTTI .?AVASGameEntity@@, base ASDisplayObject, vftable 0x1431...,
// ctor 0x1422de590). NOT an original header.
// 0x88 bytes (operator new(0x88) in FUN_140ba77e0, the `new ASGameEntity(v, n)` wrapper). Units must include this
// header instead of redefining the class.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"

class ASGameEntity : public ASDisplayObject
{
public:
    int FUN_1422c1500();                                    // width
    int FUN_1422c1530();                                    // height
    void FUN_1422bffe0(int x, int y);                       // set the position

private:
    void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58; void* m_pad_60; void* m_pad_68;
    void* m_pad_70; void* m_pad_78; void* m_pad_80;
};
MS2_CHECK_SIZE(ASGameEntity, 0x88);
