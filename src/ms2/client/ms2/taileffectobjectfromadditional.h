// CTailEffectObjectFromAdditional (RTTI name): a CTailEffectObject spawned by an additional effect (buff); it remembers
// the additional effect id and never reports its owner alive (the buff ends the tail). Header name assumed from the unit
// ?\taileffectobjectfromadditional.cpp (0x140ad5df0-0x140ad5f00); the member name is inferred from the class name.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/taileffectobject.h"

class CTailEffectObjectFromAdditional : public CTailEffectObject
{
public:
    CTailEffectObjectFromAdditional(GameObject* pOwner, MS2SvrPtr<TailEffectData> spData, int nAdditionalId);  // 0x140ad5df0
    virtual ~CTailEffectObjectFromAdditional();     // 0x140ad5e80
    bool vfunc_1() override;                        // 0x140ad5eb0 always false

    int m_nAdditionalId;                            // +0x50 the additional effect that spawned the tail
};
MS2_CHECK_SIZE(CTailEffectObjectFromAdditional, 0x58);
MS2_CHECK_OFFSET(CTailEffectObjectFromAdditional, m_nAdditionalId, 0x50);
