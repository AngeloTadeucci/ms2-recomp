// cmesomarketman.h - PLACEHOLDER for CMesoMarketMan (RTTI .?AVCMesoMarketMan@@, 0xf8 bytes). NOT an original header.
// Bases: TSingleton<CMesoMarketMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMesoMarketMan : public TSingleton<CMesoMarketMan>
{
public:
    CMesoMarketMan();                                       // 0x140d6e2b0
    virtual ~CMesoMarketMan();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xf8 - 0x8];
};
MS2_CHECK_SIZE(CMesoMarketMan, 0xf8);
