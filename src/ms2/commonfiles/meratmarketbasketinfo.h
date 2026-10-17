// meratmarketbasketinfo.h - the merat (premium cash) market: the basket entry (CMeratMarketBasketInfo), the premium
// product records (CDBPremiumProduct, CMeratMarketPremiumProduct), the premium table (CMeratMarketPremium,
// Table/Server/shop_merat.xml), a market product (premium or UGC: CMeratMarketProduct) and the market packets.
// Recovered from ?\meratmarketbasketinfo.cpp (0x14069c3e0-0x1406ae9c0). NOT an original header; member names follow
// the XML attribute names where there are any, the rest are invented.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"

class Unk_140165cf0;
class CUgcPremiumProduct;

// The key of a market product: a premium product id, or a UGC product serial (asitemslot.cpp: Unk_MeratOid).
struct Unk_MeratProductKey
{
    // @0x1402038a0
    Unk_MeratProductKey() { Reset(); }
    // @0x1406a8510
    Unk_MeratProductKey(int nPremiumId, __int64 nUgcId) : m_nPremiumId(nPremiumId), m_nUgcId(nUgcId) {}
    // @0x140207730
    void Reset() { m_nPremiumId = 0; m_nUgcId = 0; }
    // @0x1406ad6b0
    void Set(int nPremiumId, __int64 nUgcId) { m_nPremiumId = nPremiumId; m_nUgcId = nUgcId; }
    // @0x1406a9c70
    void Write(COutputStream& stream) const { stream.vfunc_o10_3(m_nPremiumId); stream.vfunc_o10_4(m_nUgcId); }
    // @0x1406a9b40
    void Read(CInPacket& packet) { m_nPremiumId = packet.vfunc_o8_3(); m_nUgcId = packet.vfunc_o8_4(); }

    int m_nPremiumId;                                       // +0x00
    __int64 m_nUgcId;                                       // +0x08
};
MS2_CHECK_SIZE(Unk_MeratProductKey, 0x10);

// One basket (cart) entry.
class CMeratMarketBasketInfo : public CPtred
{
public:
    CMeratMarketBasketInfo();                               // 0x14069c440
    virtual ~CMeratMarketBasketInfo();                      // 0x14069c510
    void Write(COutputStream* pStream);                     // 0x14069c540
    void Read(CInPacket& packet);                           // 0x14069c650

    int m_nKind;                                            // +0x18
    Unk_MeratProductKey m_key;                              // +0x20
    __int64 m_n30;                                          // +0x30
    int m_n38;                                              // +0x38 (byte)
    int m_n3c;                                              // +0x3c
    int m_n40;                                              // +0x40
    int m_n44;                                              // +0x44 (byte)
    int m_n48;                                              // +0x48
    __int64 m_n50;                                          // +0x50
    __int64 m_n58;                                          // +0x58
};
MS2_CHECK_SIZE(CMeratMarketBasketInfo, 0x60);

int FUN_14069c3e0(int nType);                               // currency type -> payment flag

// A premium product row (the server's DB record).
class CDBPremiumProduct : public CPtred
{
public:
    CDBPremiumProduct();                                    // 0x14069c860
    virtual ~CDBPremiumProduct();                           // 0x14069c9c0
    virtual void Reset();                                   // slot 1
    virtual void CopyFrom(const CDBPremiumProduct* pOther); // slot 2
    virtual void Write(COutputStream& stream);              // slot 3
    virtual void Read(CInPacket& packet);                   // slot 4
    virtual void WriteBrief(COutputStream& stream);         // slot 5
    virtual void ReadBrief(CInPacket& packet);              // slot 6
    virtual __int64 GetSalePrice(const CDBPremiumProduct* pParent); // slot 7
    virtual __int64 GetPoint();                             // slot 8

    int FUN_14069fe40();                                    // 0 no item, 1 stackable, 2 single
    int FUN_14069fee0();
    bool FUN_14069ff00();
    bool FUN_14069ff50();
    int GetCurrencyItemId();                                // 0x14069ff80
    bool FUN_14069ffc0(std::vector<unsigned>& ids, const unsigned& nFlags);
    bool FUN_1406a0090();
    CStringW GetName();                                     // 0x1406a00e0
    CStringA GetIconPath();                                 // 0x1406a0160
    int FUN_1406a0230();
    __int64 FUN_1406a0270();
    CStringW GetSellDayText();                              // 0x1406a02c0

    int m_nId;                                              // +0x18 "sn"
    int m_n1c;                                              // +0x1c (8)
    CStringW m_strName;                                     // +0x20
    int m_nType;                                            // +0x28 1 bundle, 3 limited, 6 home, 7/8 random
    int m_n2c;                                              // +0x2c
    int m_nChartOrder;                                      // +0x30
    int m_nCouponFlags;                                     // +0x34
    int m_bVisible;                                         // +0x38
    int m_nSaleTag;                                         // +0x3c
    int m_nCurrency;                                        // +0x40
    __int64 m_nPrice;                                       // +0x48
    __int64 m_nSalePrice;                                   // +0x50
    int m_n58;                                              // +0x58
    CMsTime m_startDate;                                    // +0x60
    CMsTime m_endDate;                                      // +0x70
    int m_n80;                                              // +0x80
    int m_n84;                                              // +0x84
    int m_nBuyLimit;                                        // +0x88
    int m_nBuyLimitMax;                                     // +0x8c
    int m_n90;                                              // +0x90
    short m_n94;                                            // +0x94
    short m_n96;                                            // +0x96
    int m_n98;                                              // +0x98 (0xfff)
    int m_n9c;                                              // +0x9c
    CStringA m_strCategory;                                 // +0xa0
    unsigned m_nItemId;                                     // +0xa8 "id"
    int m_nGrade;                                           // +0xac
    int m_nb0;                                              // +0xb0
    int m_nb4;                                              // +0xb4
    int m_nb8;                                              // +0xb8
    int m_nCategoryId;                                      // +0xbc
    int m_nLimitCount;                                      // +0xc0
    int m_nc4;                                              // +0xc4
    CAtlArray<int> m_arrc8;                                 // +0xc8
    CStringA m_strIcon;                                     // +0xe8
    bool m_bf0;                                             // +0xf0
    int m_nf4;                                              // +0xf4
    int m_nf8;                                              // +0xf8
    int m_nfc;                                              // +0xfc
    int m_n100;                                             // +0x100
    int m_n104;                                             // +0x104
    bool m_b108;                                            // +0x108
    int m_n10c;                                             // +0x10c
    bool m_bPoint;                                          // +0x110
    __int64 m_nPoint;                                       // +0x118
    int m_n120;                                             // +0x120
    int m_n124;                                             // +0x124
    int m_n128;                                             // +0x128
    CMsTime m_eventStart;                                   // +0x130
    CMsTime m_eventEnd;                                     // +0x140
    CStringA m_strEventCategory;                            // +0x150
    int m_n158;                                             // +0x158
    CStringA m_str160;                                      // +0x160
    bool m_b168;                                            // +0x168
    int m_n16c;                                             // +0x16c
    int m_n170;                                             // +0x170
    int m_n174;                                             // +0x174
    CMsTime m_time178;                                      // +0x178
    CMsTime m_time188;                                      // +0x188
    CMsTime m_time198;                                      // +0x198
    int m_n1a8;                                             // +0x1a8
    int m_n1ac;                                             // +0x1ac random sale
    int m_n1b0;                                             // +0x1b0 random sale rate
    int m_n1b4;                                             // +0x1b4
    CMsTime m_randomSaleDay;                                // +0x1b8
};
MS2_CHECK_SIZE(CDBPremiumProduct, 0x1c8);
MS2_CHECK_OFFSET(CDBPremiumProduct, m_arrc8, 0xc8);
MS2_CHECK_OFFSET(CDBPremiumProduct, m_randomSaleDay, 0x1b8);

// A premium product of the merat market table (shop_merat.xml), with its sub products.
class CMeratMarketPremiumProduct : public CDBPremiumProduct
{
public:
    CMeratMarketPremiumProduct();                           // 0x1406a0490
    virtual ~CMeratMarketPremiumProduct();                  // 0x1406a0510
    void Reset() override;                                  // 0x1406a0570
    void Write(COutputStream& stream) override;             // 0x1406a1020
    void Read(CInPacket& packet) override;                  // 0x1406a10e0
    void WriteBrief(COutputStream& stream) override;        // 0x1406a11e0
    void ReadBrief(CInPacket& packet) override;             // 0x1406a1240

    BOOL Copy(MS2Ptr<CDBPremiumProduct> spProduct);         // 0x1406a05d0
    BOOL Copy(MS2Ptr<CMeratMarketPremiumProduct> spProduct, int nBuyCount, int nLimitCount, int nHomeCount);
    void SetCounts(int nBuyCount, int nLimitCount, int nHomeCount);    // 0x1406a0970
    BOOL HasLimit();                                        // 0x1406a09c0
    bool IsBuyLimitReached();                               // 0x1406a0a60
    bool IsLimitSoldOut();                                  // 0x1406a0ad0
    bool IsHomeSoldOut();                                   // 0x1406a0b50
    int GetRemainCount();                                   // 0x1406a0bd0
    bool IsSoldOut();                                       // 0x1406a0cc0
    bool IsNotSelling(__int64 nOffset);                     // 0x1406a0d20
    bool IsNotEventPeriod(__int64 nOffset);                 // 0x1406a0d60
    bool IsSelling(__int64 nOffset);                        // 0x1406a0da0
    bool IsEventPeriod(__int64 nOffset);                    // 0x1406a0ea0
    bool FUN_1406a0fe0();
    BOOL LoadXml(Unk_140165cf0* pElem);                     // 0x1406a12a0
    int GetGrade();                                         // 0x1406a1630
    int GetCurrency();                                      // 0x1406a1650
    int GetDisplayId();                                     // 0x1406a1670
    MS2Ptr<CDBPremiumProduct> GetSubProduct(int nId);       // 0x1406a16d0
    MS2Ptr<CDBPremiumProduct> GetLimitProduct(int nId);     // 0x1406a1760
    int GetB0(int nSubId);                                  // 0x1406a17f0
    int GetB4(int nSubId);                                  // 0x1406a1880
    int GetB8(int nSubId);                                  // 0x1406a1910
    CMsTime GetStartDate(int nSubId);                       // 0x1406a19a0
    CMsTime GetEndDate(int nSubId);                         // 0x1406a1a70
    __int64 GetSalePriceOf(int nSubId);                     // 0x1406a1b30
    __int64 GetPriceOf(int nSubId);                         // 0x1406a1be0
    bool FUN_1406a1c70(int nSubId);
    BOOL HasSubProducts();                                  // 0x1406a1d60
    __int64 GetPointOf(int nSubId);                         // 0x1406a1da0
    CStringA GetCategory();                                 // 0x1406a1e50
    int FUN_1406a1ee0();
    CStringA FUN_1406a1f00();
    bool FUN_1406a1f50();
    void WriteSubProducts(COutputStream& stream);           // 0x1406a1f70
    void ReadSubProducts(CInPacket& packet);                // 0x1406a2090
    void WriteLimitProducts(COutputStream& stream);         // 0x1406a21f0
    void ReadLimitProducts(CInPacket& packet);              // 0x1406a2310

    int m_nBuyCount;                                        // +0x1c8
    int m_nSoldCount;                                       // +0x1cc
    int m_nHomeSoldCount;                                   // +0x1d0
    CRBMap<int, MS2Ptr<CDBPremiumProduct> > m_mapSub;       // +0x1d8
    CRBMap<int, MS2Ptr<CDBPremiumProduct> > m_mapLimit;     // +0x208
};
MS2_CHECK_SIZE(CMeratMarketPremiumProduct, 0x238);
MS2_CHECK_OFFSET(CMeratMarketPremiumProduct, m_mapSub, 0x1d8);

CStringA FUN_1406a2470(__int64 nTime);                      // "YYYY-MM-DD hh:mm:ss"
