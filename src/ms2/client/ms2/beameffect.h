// beameffect.h - CBeamEffect (RTTI name): the runtime "Beam" effect (effect XML type 0x15), created by
// CBeamEffectParam::vfunc_6. Owning unit: client\ms2\beameffect.cpp (0x140a071a0-0x140a0c300, not recovered yet).
// Header name assumed. Only the shape that beameffectparam.cpp needs is declared (size 0x78 from the operator_new in
// CBeamEffectParam::vfunc_6); the owning unit completes the members and virtuals.
#pragma once
#include "ms2/client/ms2/effectparam.h"

class CBeamEffect : public CEffect
{
    NiDeclareRTTI;
public:
    CBeamEffect();
    virtual ~CBeamEffect();
    virtual int vfunc_12();

    char m_unk_30[0x48];            // +0x30 .. 0x78 (unrecovered)
};
MS2_CHECK_SIZE(CBeamEffect, 0x78);
