// cdpsmetersystem.h - PLACEHOLDER for CDPSMeterSystem (RTTI .?AVCDPSMeterSystem@@, 0x2a8 bytes). NOT an original header.
// Bases: TSingleton<CDPSMeterSystem> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CDPSMeterSystem : public TSingleton<CDPSMeterSystem>
{
public:
    CDPSMeterSystem();                                      // 0x14117acd0
    virtual ~CDPSMeterSystem();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x2a8 - 0x8];
};
MS2_CHECK_SIZE(CDPSMeterSystem, 0x2a8);
