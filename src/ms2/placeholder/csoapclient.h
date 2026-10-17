// csoapclient.h - PLACEHOLDER for CSoapClient (RTTI .?AVCSoapClient@@, 0xa0 bytes). NOT an original header.
// Bases: TSingleton<CSoapClient> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor and the called requests are
// declared, the members are not recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"

class CGameRankingParam;
class CGameRankingWebResult;

class CSoapClient : public TSingleton<CSoapClient>
{
public:
    CSoapClient();                                          // 0x14176fbb0
    virtual ~CSoapClient();
    MS2Ptr<CGameRankingWebResult> FUN_141770670(MS2Ptr<CGameRankingParam> spParam);   // the game ranking request
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xa0 - 0x8];
};
MS2_CHECK_SIZE(CSoapClient, 0xa0);
