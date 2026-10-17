// ctaximanager.h - PLACEHOLDER for CTaxiManager (RTTI .?AVCTaxiManager@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<CTaxiManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CTaxiManager : public TSingleton<CTaxiManager>
{
public:
    CTaxiManager();                                         // 0x14085f650
    virtual ~CTaxiManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x18 - 0x8];
};
MS2_CHECK_SIZE(CTaxiManager, 0x18);
