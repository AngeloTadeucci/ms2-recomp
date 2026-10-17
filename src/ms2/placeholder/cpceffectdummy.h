// cpceffectdummy.h - PLACEHOLDER for CPCEffectDummy (RTTI .?AVCPCEffectDummy@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<CPCEffectDummy> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CPCEffectDummy : public TSingleton<CPCEffectDummy>
{
public:
    CPCEffectDummy();                                       // 0x1416841a0
    virtual ~CPCEffectDummy();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x18 - 0x8];
};
MS2_CHECK_SIZE(CPCEffectDummy, 0x18);
