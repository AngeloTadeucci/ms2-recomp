// cshopeventmanager.h - PLACEHOLDER for CShopEventManager (RTTI .?AVCShopEventManager@@, 0x80 bytes). NOT an original header.
// Bases: TSingleton<CShopEventManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

template <class T> class MS2Ptr;
struct PreminmMarketSaleEventContext;

class CShopEventManager : public TSingleton<CShopEventManager>
{
public:
    CShopEventManager();                                    // 0x1407ce160
    virtual ~CShopEventManager();
    void FUN_1407ce2a0(int eventId, MS2Ptr<PreminmMarketSaleEventContext> spContext);  // GameEventPremiumMarketSale on
    void FUN_1407ce320(int eventId);                                                  // ... off
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x80 - 0x8];
};
MS2_CHECK_SIZE(CShopEventManager, 0x80);
