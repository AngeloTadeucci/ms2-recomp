// csoapclient.h - PLACEHOLDER for CSoapClient (RTTI .?AVCSoapClient@@, 0xa0 bytes). NOT an original header.
// Bases: TSingleton<CSoapClient> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CSoapClient : public TSingleton<CSoapClient>
{
public:
    CSoapClient();                                          // 0x14176fbb0
    virtual ~CSoapClient();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xa0 - 0x8];
};
MS2_CHECK_SIZE(CSoapClient, 0xa0);
