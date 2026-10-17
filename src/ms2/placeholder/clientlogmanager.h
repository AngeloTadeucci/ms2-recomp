// clientlogmanager.h - PLACEHOLDER for ClientLogManager (RTTI .?AVClientLogManager@@, 0x68 bytes). NOT an original header.
// Bases: TSingleton<ClientLogManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class ClientLogManager : public TSingleton<ClientLogManager>
{
public:
    ClientLogManager();                                     // 0x141451410
    virtual ~ClientLogManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x68 - 0x8];
};
MS2_CHECK_SIZE(ClientLogManager, 0x68);
