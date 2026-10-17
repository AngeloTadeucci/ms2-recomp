// cblackmarketman.h - PLACEHOLDER for CBlackMarketMan (RTTI .?AVCBlackMarketMan@@, 0x128 bytes). NOT an original header.
// Bases: TSingleton<CBlackMarketMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CBlackMarketMan : public TSingleton<CBlackMarketMan>
{
public:
    CBlackMarketMan();                                      // 0x140a20460
    virtual ~CBlackMarketMan();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x128 - 0x8];
};
MS2_CHECK_SIZE(CBlackMarketMan, 0x128);
