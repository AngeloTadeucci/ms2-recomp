// applyeffect.h - PLACEHOLDER for ApplyEffect (RTTI .?AVApplyEffect@@, 0x70 bytes). NOT an original header.
// Bases: TSingleton<ApplyEffect> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class ApplyEffect : public TSingleton<ApplyEffect>
{
public:
    ApplyEffect();                                          // 0x1409a36c0
    virtual ~ApplyEffect();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x70 - 0x8];
};
MS2_CHECK_SIZE(ApplyEffect, 0x70);
