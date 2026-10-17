// cshopeventmanager.h - PLACEHOLDER for CShopEventManager (RTTI .?AVCShopEventManager@@, 0x80 bytes). NOT an original header.
// Bases: TSingleton<CShopEventManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CShopEventManager : public TSingleton<CShopEventManager>
{
public:
    CShopEventManager();                                    // 0x1407ce160
    virtual ~CShopEventManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x80 - 0x8];
};
MS2_CHECK_SIZE(CShopEventManager, 0x80);
