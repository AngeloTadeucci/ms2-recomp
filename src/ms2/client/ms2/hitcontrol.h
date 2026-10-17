// hitcontrol.h - CHitControl (RTTI .?AVCHitControl@@, derives CPtred, 0x18 bytes): the base of the per-actor hit-reaction
// movers (CPushControl, the knock-back mover, is the only recovered derived class; see placeholder/pushcontrol.h).
// Header path/name assumed from the unit path. Owning unit: ?\hitcontrol.cpp (0x1413fc9d0-0x1413fd240).
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/ms2layout.h"

class GameObject;

class CHitControl : public CPtred
{
public:
    CHitControl();                                                  // 0x1413fc9d0
    virtual ~CHitControl();                                         // 0x1413fca10 (scalar deleting 0x1413fd0a0)
    virtual bool vfunc_1(GameObject* pActor, double dTime);         // 0x1413fca40 per-frame update: nothing to do
};
MS2_CHECK_SIZE(CHitControl, 0x18);
