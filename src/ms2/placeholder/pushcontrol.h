// pushcontrol.h - CPushControl (RTTI .?AVCPushControl@@, derives CHitControl, 0x48 bytes): the knock-back mover each
// PCBase owns at +0x690. NOT an original header. Owning unit: ?\hitcontrol.cpp (0x1413fca60..), whose members are only
// declared here; the layout behind the vftable is not recovered yet.
// Slots: 0 scalar deleting dtor, 1 per-frame update (pushes the given actor, returns whether it moved).
#pragma once
#include "ms2/ms2layout.h"

class GameObject;

class CPushControl
{
public:
    CPushControl();                                                 // 0x1413fca60
    virtual ~CPushControl();                                        // 0x1413fcad0
    virtual bool vfunc_1(GameObject* pActor, double dTime);         // 0x1413fcb30
private:
    void* m_unk_08[8];
};
MS2_CHECK_SIZE(CPushControl, 0x48);
