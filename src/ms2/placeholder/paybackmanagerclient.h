// paybackmanagerclient.h - PLACEHOLDER for PaybackManagerClient (RTTI .?AVPaybackManagerClient@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<PaybackManagerClient> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class PaybackManagerClient : public TSingleton<PaybackManagerClient>
{
public:
    PaybackManagerClient();                                 // 0x140a8af50
    virtual ~PaybackManagerClient();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(PaybackManagerClient, 0x28);
