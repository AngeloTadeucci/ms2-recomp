// cmeratmarketman.h - PLACEHOLDER for CMeratMarketMan (RTTI .?AVCMeratMarketMan@@, 0x2e0 bytes). NOT an original header.
// Bases: TSingleton<CMeratMarketMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMeratMarketMan : public TSingleton<CMeratMarketMan>
{
public:
    CMeratMarketMan();                                      // 0x140d53ad0
    virtual ~CMeratMarketMan();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x2e0 - 0x8];
};
MS2_CHECK_SIZE(CMeratMarketMan, 0x2e0);
