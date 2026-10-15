// timebasedanimation.h - CTimeBasedAnimation (RTTI .?AVCTimeBasedAnimation@@): the abstract base of the time-driven
// animations (vftable 0x142f847a0, 5 slots, the four virtuals are pure). Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the base's own unit `?\timebasedanimation.cpp` (0x1418519c0-0x141851ba0: ctor, dtor, deleting dtor) is not
// recovered yet, so only declarations live here. Header name assumed; vfunc names are invented from the derived class.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class Unk_MorphOwner;                                   // the object whose model the animation drives (defined elsewhere)

// 0x20 bytes.
class CTimeBasedAnimation : public CPtred
{
public:
    CTimeBasedAnimation(Unk_MorphOwner* pOwner);        // 0x1418519c0
    virtual ~CTimeBasedAnimation();                     // 0x141851a10, ??_G 0x141851a40

    virtual void vfunc_1() = 0;                         // slot 1: play from the start
    virtual void vfunc_2() = 0;                         // slot 2: stop
    virtual bool vfunc_3(int nTime) = 0;                // slot 3: advance to nTime (ms), returns whether it still runs
    virtual int vfunc_4() = 0;                         // slot 4: has data

    Unk_MorphOwner* m_pOwner;                           // +0x18
};
MS2_CHECK_SIZE(CTimeBasedAnimation, 0x20);
MS2_CHECK_OFFSET(CTimeBasedAnimation, m_pOwner, 0x18);
