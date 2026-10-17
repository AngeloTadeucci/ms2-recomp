// ccashmarketman.h - PLACEHOLDER for CCashMarketMan (RTTI .?AVCCashMarketMan@@, 0x100 bytes). NOT an original header.
// Bases: TSingleton<CCashMarketMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CCashMarketMan : public TSingleton<CCashMarketMan>
{
public:
    CCashMarketMan();                                       // 0x140b05e40
    virtual ~CCashMarketMan();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x100 - 0x8];
};
MS2_CHECK_SIZE(CCashMarketMan, 0x100);
