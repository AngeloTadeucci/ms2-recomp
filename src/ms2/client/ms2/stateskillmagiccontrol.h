// stateskillmagiccontrol.h - StateSkillMagicControl (state type 0x41): while the caster channels a guided skill the
// actor follows the controlled target. NOT an original header. Size 0x40 (no members beyond State).
#pragma once
#include "ms2/placeholder/state.h"

class StateSkillMagicControl : public State
{
public:
    StateSkillMagicControl(PCBase* pOwner);      // 0x140ac02e0
    virtual ~StateSkillMagicControl();           // 0x140ac0320
    virtual int vfunc_1();                       // 1  0x140ac0790: 0x41
    virtual void vfunc_3(double fTime);          // 3  0x140ac0380
    virtual void vfunc_4(StateData* pData);      // 4  0x140ac0350
    virtual void vfunc_8(double fTime);          // 8  0x140ac0640
    virtual int vfunc_15();                      // 15 0x140ac0780: 1
};
MS2_CHECK_SIZE(StateSkillMagicControl, 0x40);
