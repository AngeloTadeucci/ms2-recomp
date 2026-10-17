// weddingmanager.h - PLACEHOLDER for WeddingManager (RTTI .?AVWeddingManager@@, 0x228 bytes). NOT an original header.
// Bases: TSingleton<WeddingManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class WeddingManager : public TSingleton<WeddingManager>
{
public:
    WeddingManager();                                       // 0x141b835d0
    virtual ~WeddingManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x228 - 0x8];
};
MS2_CHECK_SIZE(WeddingManager, 0x228);
