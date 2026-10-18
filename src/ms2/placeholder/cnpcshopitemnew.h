// cnpcshopitemnew.h - PLACEHOLDER for CNpcShopItemNew (RTTI .?AVCNpcShopItemNew@@, CPtred-derived, 0x48 bytes: ctor
// 0x1406de4d0, dtor 0x1406ef7a0 (??_G 0x1406f10c0)): the item record of a "new" NPC shop product. NOT an original
// header; the real class belongs to commonfiles\npcshopdata.cpp (unrecovered). Only the members the client reads are named.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"

class CInPacket;
class CNpcShopBuyPeriod;

class CNpcShopItemNew : public CPtred
{
public:
    CNpcShopItemNew();                                      // 0x1406de4d0
    virtual ~CNpcShopItemNew();                             // 0x1406ef7a0
    void FUN_1406de840(CInPacket& in);                      // read the record from a packet

    unsigned m_nItemId;                                     // +0x18
    bool m_bFlag;                                           // +0x1c
    unsigned m_nRarity;                                     // +0x20
    CString m_strName;                                      // +0x28
    int m_nProductType;                                     // +0x30 (the product's "property 1")
    int m_nProductKind;                                     // +0x34 (the product's "property 2")
    MS2SvrPtr<CNpcShopBuyPeriod> m_spPeriod;                // +0x38
};
MS2_CHECK_SIZE(CNpcShopItemNew, 0x48);
MS2_CHECK_OFFSET(CNpcShopItemNew, m_nProductType, 0x30);
