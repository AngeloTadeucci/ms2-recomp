// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The merat (premium cash) market: basket entries, the
// premium product records and table (Table/Server/shop_merat.xml), market products and packets.
// MS2-UNIT: ?\meratmarketbasketinfo.cpp
// MS2-RANGE: 0x14069c3e0-0x1406ae9c0 .text$mn
// MS2-RANGE: 0x1400bb3f0-0x1400bb6a0 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\meratmarketbasketinfo.cpp"   // no asserts of its own
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include <string>
#include "ms2/ms2format.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringW FUN_141425950(int nItemId);                                        // item name
CStringA FUN_140540050(const char* pszFormat, const CStringA& strArg);       // StringFormat with one string
CStringW FUN_14028b8e0(const CStringW& strKey);                             // string table text
int FUN_14028e280(CMsTime& out, const CStringA& strFormat, const CStringA& str); // parses a date string
struct Unk_MeratDefaultIcon { char m_pad[0xc0]; CStringA m_strIcon; };
Unk_MeratDefaultIcon* FUN_1401d31f0();
CShopEventManager* FUN_1403ed2a0();                                         // TSingleton<CShopEventManager>::GetInstance
void FUN_1407ce380(CShopEventManager* pManager, CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> >& arr,
                   const int& nCurrency);                                   // the sale events of a currency
bool FUN_1407cde30(PreminmMarketSaleEventContext* pContext, unsigned nId, int nCurrency);  // the event covers the id
int FUN_1407ce100(PreminmMarketSaleEventContext* pContext, int nPrice);    // the discounted price
bool FUN_1406a5840();
__int64 FUN_1406a61c0(__int64 nPrice, int nRate);
__int64 FUN_1406a6150(__int64 nPrice, int nRate);

// ---- CMeratMarketBasketInfo ------------------------------------------------------------------------------------------

// @0x14069c3e0
int FUN_14069c3e0(int nType)
{
    switch (nType)
    {
    case 0:
        return 1;
    case 1:
        return 3;
    case 2:
        return 9;
    case 3:
        return 0x11;
    default:
        return 1;
    }
}

// @0x14069c440
CMeratMarketBasketInfo::CMeratMarketBasketInfo()
{
    m_nKind = 2;
    m_key.Reset();
    m_n30 = 0;
    m_n38 = 0;
    m_n3c = 0;
    m_n40 = 0;
    m_n44 = 0;
    m_n48 = 0;
    m_n50 = 0;
    m_n58 = 0;
}

// @0x14069c510
CMeratMarketBasketInfo::~CMeratMarketBasketInfo()
{
}

// @0x14069c540
void CMeratMarketBasketInfo::Write(COutputStream* pStream)
{
    pStream->vfunc_o10_1((unsigned char)m_nKind);
    m_key.Write(*pStream);
    pStream->vfunc_o10_4(m_n30);
    pStream->vfunc_o10_1((unsigned char)m_n38);
    pStream->vfunc_o10_3(m_n3c);
    pStream->vfunc_o10_3(m_n40);
    pStream->vfunc_o10_1((unsigned char)m_n44);
    pStream->vfunc_o10_3(m_n48);
    pStream->vfunc_o10_4(m_n50);
    pStream->vfunc_o10_4(m_n58);
}

// @0x14069c650
void CMeratMarketBasketInfo::Read(CInPacket& packet)
{
    m_nKind = packet.vfunc_o8_1();
    m_key.Read(packet);
    m_n30 = packet.vfunc_o8_4();
    m_n38 = packet.vfunc_o8_1();
    m_n3c = packet.vfunc_o8_3();
    m_n40 = packet.vfunc_o8_3();
    m_n44 = packet.vfunc_o8_1();
    m_n48 = packet.vfunc_o8_3();
    m_n50 = packet.vfunc_o8_4();
    m_n58 = packet.vfunc_o8_4();
}

// ---- CDBPremiumProduct -----------------------------------------------------------------------------------------------

// @0x14069c860
CDBPremiumProduct::CDBPremiumProduct()
{
    Reset();
}

// @0x14069c9c0
CDBPremiumProduct::~CDBPremiumProduct()
{
}

// @0x14069ca70
void CDBPremiumProduct::Reset()
{
    m_nId = 0;
    m_n1c = 8;
    m_strName.Empty();
    m_nType = 0;
    m_n2c = 0;
    m_nChartOrder = 0;
    m_nCouponFlags = 0;
    m_bVisible = 0;
    m_nSaleTag = 0;
    m_nCurrency = 0;
    m_nPrice = 0;
    m_nSalePrice = 0;
    m_n58 = 0;
    m_startDate = 0;
    m_endDate = 0;
    m_n80 = 0;
    m_n84 = 0;
    m_nBuyLimit = 0;
    m_nBuyLimitMax = 0;
    m_n90 = 0;
    m_n94 = 0;
    m_n96 = 0;
    m_n98 = 0xfff;
    m_nItemId = 0;
    m_nGrade = 0;
    m_nb0 = 0;
    m_nb4 = 0;
    m_nb8 = 0;
    m_nCategoryId = 0;
    m_nLimitCount = 0;
    m_nc4 = 0;
    m_arrc8.RemoveAll();
    m_n9c = 0;
    m_strCategory.Empty();
    m_bf0 = false;
    m_n120 = 0;
    m_n124 = 0;
    m_n128 = 0;
    m_nf4 = 0;
    m_n104 = 0;
    m_b108 = false;
    m_nf8 = 0;
    m_nfc = 0;
    m_n100 = 0;
    m_n10c = 0;
    m_bPoint = false;
    m_nPoint = 0;
    m_eventStart = 0;
    m_eventEnd = 0;
    m_strEventCategory.Empty();
    m_n158 = 0;
    m_b168 = false;
    m_n16c = 0;
    m_n170 = 0;
    m_n174 = 0;
    m_time178 = 0;
    m_time188 = 0;
    m_time198 = 0;
    m_n1a8 = 0;
    m_n1ac = 0;
    m_n1b0 = 0;
    m_n1b4 = 0;
    m_randomSaleDay = 0;
}

// @0x14069ce50
void CDBPremiumProduct::CopyFrom(const CDBPremiumProduct* pOther)
{
    if (!pOther)
        return;
    m_nId = pOther->m_nId;
    m_n1c = pOther->m_n1c;
    m_strName = pOther->m_strName;
    m_nType = pOther->m_nType;
    m_n2c = pOther->m_n2c;
    m_nChartOrder = pOther->m_nChartOrder;
    m_nCouponFlags = pOther->m_nCouponFlags;
    m_bVisible = pOther->m_bVisible;
    m_nSaleTag = pOther->m_nSaleTag;
    m_nCurrency = pOther->m_nCurrency;
    m_nPrice = pOther->m_nPrice;
    m_nSalePrice = pOther->m_nSalePrice;
    m_n58 = pOther->m_n58;
    m_startDate = pOther->m_startDate;
    m_endDate = pOther->m_endDate;
    m_n80 = pOther->m_n80;
    m_n84 = pOther->m_n84;
    m_nBuyLimit = pOther->m_nBuyLimit;
    m_nBuyLimitMax = pOther->m_nBuyLimitMax;
    m_n90 = pOther->m_n90;
    m_n94 = pOther->m_n94;
    m_n96 = pOther->m_n96;
    m_n98 = pOther->m_n98;
    m_nItemId = pOther->m_nItemId;
    m_nGrade = pOther->m_nGrade;
    m_nb0 = pOther->m_nb0;
    m_nb4 = pOther->m_nb4;
    m_nb8 = pOther->m_nb8;
    m_nCategoryId = pOther->m_nCategoryId;
    m_nLimitCount = pOther->m_nLimitCount;
    m_nc4 = pOther->m_nc4;
    m_arrc8.Copy(pOther->m_arrc8);
    m_n9c = pOther->m_n9c;
    m_strCategory = pOther->m_strCategory;
    m_bf0 = pOther->m_bf0;
    m_n120 = pOther->m_n120;
    m_n124 = pOther->m_n124;
    m_n128 = pOther->m_n128;
    m_nf4 = pOther->m_nf4;
    m_n104 = pOther->m_n104;
    m_b108 = pOther->m_b108;
    m_nf8 = pOther->m_nf8;
    m_nfc = pOther->m_nfc;
    m_n100 = pOther->m_n100;
    m_n10c = pOther->m_n10c;
    m_bPoint = pOther->m_bPoint;
    m_nPoint = pOther->m_nPoint;
    m_eventStart = pOther->m_eventStart;
    m_eventEnd = pOther->m_eventEnd;
    m_strEventCategory = pOther->m_strEventCategory;
    m_n158 = pOther->m_n158;
    m_b168 = pOther->m_b168;
    m_n16c = pOther->m_n16c;
    m_n170 = pOther->m_n170;
    m_n174 = pOther->m_n174;
    m_time178 = pOther->m_time178;
    m_time188 = pOther->m_time188;
    m_time198 = pOther->m_time198;
    m_n1a8 = pOther->m_n1a8;
    m_n1ac = pOther->m_n1ac;
    m_n1b0 = pOther->m_n1b0;
    m_n1b4 = pOther->m_n1b4;
    m_randomSaleDay = pOther->m_randomSaleDay;
}

// @0x14069d460
void CDBPremiumProduct::Write(COutputStream& stream)
{
    stream.vfunc_o10_3(m_nId);
    stream.vfunc_o10_1((unsigned char)m_n1c);
    stream.vfunc_o10_8(m_strName);
    stream.vfunc_o10_1((unsigned char)m_nType);
    stream.vfunc_o10_3(m_n2c);
    stream.vfunc_o10_3(m_nChartOrder);
    stream.vfunc_o10_3(m_nCouponFlags);
    stream.vfunc_o10_1((unsigned char)m_bVisible);
    stream.vfunc_o10_1((unsigned char)m_nSaleTag);
    stream.vfunc_o10_1((unsigned char)m_nCurrency);
    stream.vfunc_o10_4(m_nPrice);
    stream.vfunc_o10_4(m_nSalePrice);
    stream.vfunc_o10_1((unsigned char)m_n58);
    stream.vfunc_o10_4(m_startDate.Get());
    stream.vfunc_o10_4(m_endDate.Get());
    stream.vfunc_o10_3(m_n80);
    stream.vfunc_o10_3(m_n84);
    stream.vfunc_o10_1((unsigned char)m_nBuyLimit);
    stream.vfunc_o10_3(m_nBuyLimitMax);
    stream.vfunc_o10_1((unsigned char)m_n90);
    stream.vfunc_o10_2(m_n94);
    stream.vfunc_o10_2(m_n96);
    stream.vfunc_o10_3(m_n98);
    stream.vfunc_o10_3(m_nItemId);
    stream.vfunc_o10_1((unsigned char)m_nGrade);
    stream.vfunc_o10_3(m_nb0);
    stream.vfunc_o10_3(m_nb4);
    stream.vfunc_o10_3(m_nb8);
    stream.vfunc_o10_3(m_nCategoryId);
    stream.vfunc_o10_3(m_nLimitCount);
    stream.vfunc_o10_1((unsigned char)m_nc4);
    stream.vfunc_o10_3(m_n9c);
    stream.vfunc_o10_7(m_strCategory);
    stream.vfunc_o10_7(m_strIcon);
    stream.vfunc_o10_0(m_bf0);
    stream.vfunc_o10_1((unsigned char)m_nf4);
    stream.vfunc_o10_3(m_n104);
    stream.vfunc_o10_0(m_b108);
    stream.vfunc_o10_3(m_nf8);
    stream.vfunc_o10_3(m_nfc);
    stream.vfunc_o10_3(m_n100);
    stream.vfunc_o10_1((unsigned char)m_n10c);
    stream.vfunc_o10_0(m_bPoint);
    stream.vfunc_o10_3((int)m_nPoint);
    if (!m_eventStart.IsNull())
    {
        stream.vfunc_o10_0(true);
        stream.vfunc_o10_7(m_strEventCategory);
        stream.vfunc_o10_4(m_eventStart.Get());
        stream.vfunc_o10_4(m_eventEnd.Get());
    }
    else
    {
        stream.vfunc_o10_0(false);
    }
    stream.vfunc_o10_1((unsigned char)m_n158);
    stream.vfunc_o10_6(m_str160);
    stream.vfunc_o10_0(m_b168);
    if (m_nType == 6)
    {
        stream.vfunc_o10_1((unsigned char)m_n16c);
        stream.vfunc_o10_1((unsigned char)m_n170);
        stream.vfunc_o10_3(m_n174);
        stream.vfunc_o10_4(m_time178.Get());
        stream.vfunc_o10_4(m_time188.Get());
        stream.vfunc_o10_4(m_time198.Get());
        stream.vfunc_o10_3(m_n1a8);
    }
    if (m_nType == 7 || m_nType == 8)
    {
        stream.vfunc_o10_3(m_n1ac);
        stream.vfunc_o10_3(m_n1b0);
        stream.vfunc_o10_3(m_n1b4);
        stream.vfunc_o10_4(m_randomSaleDay.Get());
    }
}

// @0x14069de70
void CDBPremiumProduct::Read(CInPacket& packet)
{
    m_nId = packet.vfunc_o8_3();
    m_n1c = packet.vfunc_o8_1();
    m_strName = packet.vfunc_o8_8();
    m_nType = packet.vfunc_o8_1();
    m_n2c = packet.vfunc_o8_3();
    m_nChartOrder = packet.vfunc_o8_3();
    m_nCouponFlags = packet.vfunc_o8_3();
    m_bVisible = packet.vfunc_o8_1();
    m_nSaleTag = packet.vfunc_o8_1();
    m_nCurrency = packet.vfunc_o8_1();
    m_nPrice = packet.vfunc_o8_4();
    m_nSalePrice = packet.vfunc_o8_4();
    m_n58 = packet.vfunc_o8_1();
    m_startDate = packet.vfunc_o8_4();
    m_endDate = packet.vfunc_o8_4();
    m_n80 = packet.vfunc_o8_3();
    m_n84 = packet.vfunc_o8_3();
    m_nBuyLimit = packet.vfunc_o8_1();
    m_nBuyLimitMax = packet.vfunc_o8_3();
    m_n90 = packet.vfunc_o8_1();
    m_n94 = packet.vfunc_o8_2();
    m_n96 = packet.vfunc_o8_2();
    m_n98 = packet.vfunc_o8_3();
    m_nItemId = packet.vfunc_o8_3();
    m_nGrade = packet.vfunc_o8_1();
    m_nb0 = packet.vfunc_o8_3();
    m_nb4 = packet.vfunc_o8_3();
    m_nb8 = packet.vfunc_o8_3();
    m_nCategoryId = packet.vfunc_o8_3();
    m_nLimitCount = packet.vfunc_o8_3();
    m_nc4 = packet.vfunc_o8_1();
    m_n9c = packet.vfunc_o8_3();
    m_strCategory = packet.vfunc_o8_7();
    m_strIcon = packet.vfunc_o8_7();
    m_bf0 = packet.vfunc_o8_0();
    m_nf4 = packet.vfunc_o8_1();
    m_n104 = packet.vfunc_o8_3();
    m_b108 = packet.vfunc_o8_0();
    m_nf8 = packet.vfunc_o8_3();
    m_nfc = packet.vfunc_o8_3();
    m_n100 = packet.vfunc_o8_3();
    m_n10c = packet.vfunc_o8_1();
    m_bPoint = packet.vfunc_o8_0();
    m_nPoint = (unsigned)packet.vfunc_o8_3();
    if (packet.vfunc_o8_0())
    {
        m_strEventCategory = packet.vfunc_o8_7();
        m_eventStart = packet.vfunc_o8_4();
        m_eventEnd = packet.vfunc_o8_4();
    }
    m_n158 = packet.vfunc_o8_1();
    m_str160 = packet.vfunc_o8_6();
    m_b168 = packet.vfunc_o8_0();
    if (m_nType == 6)
    {
        m_n16c = packet.vfunc_o8_1();
        m_n170 = packet.vfunc_o8_1();
        m_n174 = packet.vfunc_o8_3();
        m_time178 = packet.vfunc_o8_4();
        m_time188 = packet.vfunc_o8_4();
        m_time198 = packet.vfunc_o8_4();
        m_n1a8 = packet.vfunc_o8_3();
    }
    if (m_nType == 7 || m_nType == 8)
    {
        m_n1ac = packet.vfunc_o8_3();
        m_n1b0 = packet.vfunc_o8_3();
        m_n1b4 = packet.vfunc_o8_3();
        m_randomSaleDay = packet.vfunc_o8_4();
    }
}

// @0x14069eeb0
void CDBPremiumProduct::WriteBrief(COutputStream& stream)
{
    stream.vfunc_o10_3(m_nId);
    stream.vfunc_o10_1((unsigned char)m_n1c);
    stream.vfunc_o10_8(m_strName);
    stream.vfunc_o10_1((unsigned char)m_nType);
    stream.vfunc_o10_3(m_n2c);
    stream.vfunc_o10_3(m_nCouponFlags);
    stream.vfunc_o10_1((unsigned char)m_bVisible);
    stream.vfunc_o10_1((unsigned char)m_nSaleTag);
    stream.vfunc_o10_1((unsigned char)m_nCurrency);
    stream.vfunc_o10_4(m_nPrice);
    stream.vfunc_o10_4(m_nSalePrice);
    stream.vfunc_o10_1((unsigned char)m_n58);
    stream.vfunc_o10_3(m_n80);
    stream.vfunc_o10_3(m_n84);
    stream.vfunc_o10_1((unsigned char)m_nBuyLimit);
    stream.vfunc_o10_3(m_nBuyLimitMax);
    stream.vfunc_o10_1((unsigned char)m_n90);
    stream.vfunc_o10_2(m_n94);
    stream.vfunc_o10_2(m_n96);
    stream.vfunc_o10_3(m_n98);
    stream.vfunc_o10_3(m_nItemId);
    stream.vfunc_o10_1((unsigned char)m_nGrade);
    stream.vfunc_o10_3(m_nb0);
    stream.vfunc_o10_3(m_nb4);
    stream.vfunc_o10_3(m_nb8);
    stream.vfunc_o10_3(m_nCategoryId);
    stream.vfunc_o10_3(m_nf8);
    stream.vfunc_o10_3(m_nfc);
    stream.vfunc_o10_1((unsigned char)m_n10c);
    stream.vfunc_o10_0(m_bPoint);
    stream.vfunc_o10_3((int)m_nPoint);
}

// @0x14069f210
void CDBPremiumProduct::ReadBrief(CInPacket& packet)
{
    m_nId = packet.vfunc_o8_3();
    m_n1c = packet.vfunc_o8_1();
    m_strName = packet.vfunc_o8_8();
    m_nType = packet.vfunc_o8_1();
    m_n2c = packet.vfunc_o8_3();
    m_nCouponFlags = packet.vfunc_o8_3();
    m_bVisible = packet.vfunc_o8_1();
    m_nSaleTag = packet.vfunc_o8_1();
    m_nCurrency = packet.vfunc_o8_1();
    m_nPrice = packet.vfunc_o8_4();
    m_nSalePrice = packet.vfunc_o8_4();
    m_n58 = packet.vfunc_o8_1();
    m_n80 = packet.vfunc_o8_3();
    m_n84 = packet.vfunc_o8_3();
    m_nBuyLimit = packet.vfunc_o8_1();
    m_nBuyLimitMax = packet.vfunc_o8_3();
    m_n90 = packet.vfunc_o8_1();
    m_n94 = packet.vfunc_o8_2();
    m_n96 = packet.vfunc_o8_2();
    m_n98 = packet.vfunc_o8_3();
    m_nItemId = packet.vfunc_o8_3();
    m_nGrade = packet.vfunc_o8_1();
    m_nb0 = packet.vfunc_o8_3();
    m_nb4 = packet.vfunc_o8_3();
    m_nb8 = packet.vfunc_o8_3();
    m_nCategoryId = packet.vfunc_o8_3();
    m_nf8 = packet.vfunc_o8_3();
    m_nfc = packet.vfunc_o8_3();
    m_n10c = packet.vfunc_o8_1();
    m_bPoint = packet.vfunc_o8_0();
    m_nPoint = (unsigned)packet.vfunc_o8_3();
}

// @0x14069f980
__int64 CDBPremiumProduct::GetSalePrice(const CDBPremiumProduct* pParent)
{
    if (m_nType == 3 || m_nType == 6 || m_nType == 7)
        return m_nSalePrice;
    else if (m_nType == 8)
        return FUN_1406a61c0(m_nSalePrice, m_n1b0);

    int nCurrency = GetCurrencyItemId();
    if (nCurrency == 0)
        return m_nSalePrice;

    unsigned nCouponFlags = m_nCouponFlags;
    if (pParent && m_nType == 2)
        nCouponFlags = pParent->m_nCouponFlags;
    MS2Ptr<PreminmMarketSaleEventContext> spBest(0);
    if (nCouponFlags & 1)
    {
        CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> > arrAll;
        const int nAllCurrency = 100002;
        FUN_1407ce380(FUN_1403ed2a0(), arrAll, nAllCurrency);
        if (!arrAll.IsEmpty())
        {
            int nCount = (int)arrAll.GetCount();
            for (int i = 0; i < nCount; i++)
            {
                MS2Ptr<PreminmMarketSaleEventContext>& spContext = arrAll[i];
                if (spContext == 0)
                    continue;
                if (!(spBest == 0) && spContext->m_18 <= spBest->m_18)
                    continue;
                spBest = spContext;
            }
        }
    }
    CAtlArray<MS2Ptr<PreminmMarketSaleEventContext> > arr;
    FUN_1407ce380(FUN_1403ed2a0(), arr, nCurrency);
    if (!arr.IsEmpty())
    {
        std::vector<unsigned> ids;
        ids.reserve(5);
        ids.push_back(0);
        if (0 < m_nCategoryId)
        {
            const unsigned nCategoryId = m_nCategoryId;
            ids.push_back(nCategoryId);
        }
        if (0 < (int)nCouponFlags)
            FUN_14069ffc0(ids, nCouponFlags);
        int nCount = (int)arr.GetCount();
        for (int i = 0; i < nCount; i++)
        {
            MS2Ptr<PreminmMarketSaleEventContext>& spContext = arr[i];
            if (spContext == 0)
                continue;
            for (size_t j = 0; j < ids.size(); j++)
            {
                unsigned nId = ids[j];
                if (!FUN_1407cde30(spContext.operator->(), nId, nCurrency))
                    continue;
                if (!(spBest == 0) && spContext->m_18 <= spBest->m_18)
                    continue;
                spBest = spContext;
            }
        }
    }
    if (spBest.get() == NULL)
        return m_nSalePrice;
    return FUN_1407ce100(spBest.operator->(), (int)m_nSalePrice);
}

// @0x14069fe10
__int64 CDBPremiumProduct::GetPoint()
{
    return m_bPoint ? m_nPoint : 0;
}

// @0x14069fe40
int CDBPremiumProduct::FUN_14069fe40()
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(m_nItemId);
    if (spItem.get())
    {
        if (spItem->property.slotMax > 1 && m_nb4 == 0)
            return 1;
        return 2;
    }
    return 0;
}

// @0x14069fee0
int CDBPremiumProduct::FUN_14069fee0()
{
    return m_n10c;
}

// @0x14069ff00
bool CDBPremiumProduct::FUN_14069ff00()
{
    if (!m_bPoint)
        return false;
    return m_nPoint > 0;
}

// @0x14069ff50
bool CDBPremiumProduct::FUN_14069ff50()
{
    if (m_n90 == 0 || m_n90 == 99)
        return false;
    return true;
}

// @0x14069ff80
int CDBPremiumProduct::GetCurrencyItemId()
{
    if (m_nCurrency == 1)
        return 100000;
    else if (m_nCurrency == 2)
        return 100001;
    return 0;
}

// @0x14069ffc0
bool CDBPremiumProduct::FUN_14069ffc0(std::vector<unsigned>& ids, const unsigned& nFlags)
{
    if (nFlags == 0 || nFlags == 1)
        return false;
    if ((nFlags & 2) || (nFlags & 8))
        ids.push_back(10);
    if ((nFlags & 4) || (nFlags & 0x10))
        ids.push_back(11);
    return !ids.empty();
}

// @0x1406a0090
bool CDBPremiumProduct::FUN_1406a0090()
{
    if (m_n1ac == 0)
        return true;
    if (IsNotRecentDayChange(m_randomSaleDay.Get()))
        return true;
    return false;
}

// @0x1406a00e0
CStringW CDBPremiumProduct::GetName()
{
    if (m_nType == 3)
        return m_strName;
    return FUN_141425950(m_nItemId);
}

// @0x1406a0160
CStringA CDBPremiumProduct::GetIconPath()
{
    if (m_nType == 3)
    {
        if (m_strIcon.IsEmpty())
            return FUN_1401d31f0()->m_strIcon;
        return FUN_140540050("./Data/Resource/Image/Item/icon/{0}", m_strIcon);
    }
    return CStringA("");
}

// @0x1406a0230
int CDBPremiumProduct::FUN_1406a0230()
{
    int nCurrency = m_nCurrency;
    if (nCurrency == 3)
        nCurrency = 1;
    return FUN_14069c3e0(nCurrency);
}

// @0x1406a0270
__int64 CDBPremiumProduct::FUN_1406a0270()
{
    if (m_nType != 7)
        return 0;
    __int64 nPrice = FUN_1406a6150(m_nSalePrice, m_n1b0);
    return nPrice;
}

// @0x1406a02c0
CStringW CDBPremiumProduct::GetSellDayText()
{
    if (m_nType == 7 || m_nType == 8)
    {
        if (!(m_randomSaleDay == CMsTime(0)))
        {
            const CStringW& strFormat = FUN_14028b8e0(CStringW(L"s_meratmarket_tooltip_sell_day"));
            int nDay = m_randomSaleDay.GetDay();
            int nMonth = m_randomSaleDay.GetMonth();
            int nYear = m_randomSaleDay.GetYear();
            return StringFormat((const wchar_t*)strFormat, nYear, nMonth, nDay);
        }
    }
    return CStringW(L"");
}

// ---- CMeratMarketPremiumProduct --------------------------------------------------------------------------------------

// @0x1406a0490
CMeratMarketPremiumProduct::CMeratMarketPremiumProduct()
    : m_mapSub(10), m_mapLimit(10)
{
    Reset();
}

// @0x1406a0510
CMeratMarketPremiumProduct::~CMeratMarketPremiumProduct()
{
}

// @0x1406a0570
void CMeratMarketPremiumProduct::Reset()
{
    CDBPremiumProduct::Reset();
    SetCounts(0, 0, 0);
    m_mapSub.RemoveAll();
    m_mapLimit.RemoveAll();
}

// @0x1406a05d0
BOOL CMeratMarketPremiumProduct::Copy(MS2Ptr<CDBPremiumProduct> spProduct)
{
    if (spProduct == 0)
        return FALSE;
    if (spProduct->m_nType != 1 && spProduct->m_nType != 3 && spProduct->m_nType != 6 && spProduct->m_nType != 7 &&
        spProduct->m_nType != 8)
        return FALSE;
    CDBPremiumProduct::CopyFrom(spProduct.get());
    SetCounts(0, 0, 0);
    m_mapSub.RemoveAll();
    m_mapLimit.RemoveAll();
    return TRUE;
}

// @0x1406a06f0
BOOL CMeratMarketPremiumProduct::Copy(MS2Ptr<CMeratMarketPremiumProduct> spProduct, int nBuyCount, int nLimitCount,
                                      int nHomeCount)
{
    if (spProduct == 0)
        return FALSE;
    if (spProduct->m_nType != 1 && spProduct->m_nType != 3 && spProduct->m_nType != 6 && spProduct->m_nType != 7 &&
        spProduct->m_nType != 8)
        return FALSE;
    CDBPremiumProduct::CopyFrom(spProduct.get());
    SetCounts(nBuyCount, nLimitCount, nHomeCount);
    m_mapSub.RemoveAll();
    POSITION pos = spProduct->m_mapSub.GetHeadPosition();
    while (pos)
    {
        MS2Ptr<CDBPremiumProduct>& spSub = spProduct->m_mapSub.GetValueAt(pos);
        const int& nKey = spProduct->m_mapSub.GetKeyAt(pos);
        m_mapSub.SetAt(nKey, spSub);
        spProduct->m_mapSub.GetNext(pos);
    }
    m_mapLimit.RemoveAll();
    pos = spProduct->m_mapLimit.GetHeadPosition();
    while (pos)
    {
        MS2Ptr<CDBPremiumProduct>& spSub = spProduct->m_mapLimit.GetValueAt(pos);
        const int& nKey = spProduct->m_mapLimit.GetKeyAt(pos);
        m_mapLimit.SetAt(nKey, spSub);
        spProduct->m_mapLimit.GetNext(pos);
    }
    return TRUE;
}

// @0x1406a0970
void CMeratMarketPremiumProduct::SetCounts(int nBuyCount, int nLimitCount, int nHomeCount)
{
    m_nBuyCount = nBuyCount;
    m_nSoldCount = nLimitCount;
    m_nHomeSoldCount = nHomeCount;
}

// @0x1406a09c0
bool CMeratMarketPremiumProduct::HasLimit()
{
    switch (m_nType)
    {
    case 1:
    case 7:
    case 8:
        return m_nBuyLimit != 0;
    case 3:
    case 6:
        return m_nLimitCount != 0 || m_nBuyLimit != 0;
    }
    return false;
}

// @0x1406a0a60
bool CMeratMarketPremiumProduct::IsBuyLimitReached()
{
    if (!HasLimit())
        return false;
    if (m_nBuyLimit == 0)
        return false;
    return m_nBuyLimitMax <= m_nBuyCount;
}

// @0x1406a0ad0
bool CMeratMarketPremiumProduct::IsLimitSoldOut()
{
    if (!HasLimit())
        return false;
    if (m_nType == 3)
    {
        if (m_nLimitCount == 0)
            return false;
        return m_nLimitCount <= m_nSoldCount;
    }
    return false;
}

// @0x1406a0b50
bool CMeratMarketPremiumProduct::IsHomeSoldOut()
{
    if (!HasLimit())
        return false;
    if (m_nType == 6)
    {
        if (m_nLimitCount == 0)
            return false;
        return m_nLimitCount <= m_nHomeSoldCount;
    }
    return false;
}

// @0x1406a0bd0
int CMeratMarketPremiumProduct::GetRemainCount()
{
    int nRemain = 0;
    if (m_nType == 3)
    {
        if (0 < m_nLimitCount)
            nRemain = m_nLimitCount - m_nSoldCount < 0 ? 0 : m_nLimitCount - m_nSoldCount;
    }
    else if (m_nType == 6 && 0 < m_nLimitCount)
    {
        nRemain = m_nLimitCount - m_nHomeSoldCount < 0 ? 0 : m_nLimitCount - m_nHomeSoldCount;
    }
    return nRemain;
}

// @0x1406a0cc0
bool CMeratMarketPremiumProduct::IsSoldOut()
{
    return IsBuyLimitReached() || IsLimitSoldOut() || IsHomeSoldOut();
}

// @0x1406a0d20
bool CMeratMarketPremiumProduct::IsNotSelling(__int64 nOffset)
{
    return !IsSelling(nOffset);
}

// @0x1406a0d60
bool CMeratMarketPremiumProduct::IsNotEventPeriod(__int64 nOffset)
{
    return !IsEventPeriod(nOffset);
}

// @0x1406a0da0
bool CMeratMarketPremiumProduct::IsSelling(__int64 nOffset)
{
    if (m_startDate == CMsTime(0) && m_endDate == CMsTime(0))
        return true;
    CMsTime now(GetServerTime());
    return now >= CMsTime(m_startDate.Get() - nOffset) && now <= m_endDate;
}

// @0x1406a0ea0
bool CMeratMarketPremiumProduct::IsEventPeriod(__int64 nOffset)
{
    if (m_eventStart == CMsTime(0) && m_eventEnd == CMsTime(0))
        return false;
    CMsTime now(GetServerTime());
    bool bInPeriod = now >= CMsTime(m_eventStart.Get() - nOffset) && now <= m_eventEnd;
    if (bInPeriod)
        return !IsSelling(nOffset);
    return false;
}

// @0x1406a0fe0
bool CMeratMarketPremiumProduct::FUN_1406a0fe0()
{
    return m_n9c == 0;
}

// @0x1406a1020
void CMeratMarketPremiumProduct::Write(COutputStream& stream)
{
    CDBPremiumProduct::Write(stream);
    stream.vfunc_o10_3(m_nBuyCount);
    if (m_nType == 1)
    {
        WriteSubProducts(stream);
    }
    else if (m_nType == 3)
    {
        stream.vfunc_o10_3(m_nSoldCount);
        WriteLimitProducts(stream);
    }
    else if (m_nType == 6)
    {
        stream.vfunc_o10_3(m_nHomeSoldCount);
    }
}

// @0x1406a10e0
void CMeratMarketPremiumProduct::Read(CInPacket& packet)
{
    CDBPremiumProduct::Read(packet);
    m_nBuyCount = packet.vfunc_o8_3();
    if (m_nType == 1)
    {
        ReadSubProducts(packet);
    }
    else if (m_nType == 3)
    {
        m_nSoldCount = packet.vfunc_o8_3();
        ReadLimitProducts(packet);
    }
    else if (m_nType == 6)
    {
        m_nHomeSoldCount = packet.vfunc_o8_3();
    }
}

// @0x1406a11e0
void CMeratMarketPremiumProduct::WriteBrief(COutputStream& stream)
{
    CDBPremiumProduct::WriteBrief(stream);
    if (m_nType == 1)
        WriteSubProducts(stream);
    else if (m_nType == 3)
        WriteLimitProducts(stream);
}

// @0x1406a1240
void CMeratMarketPremiumProduct::ReadBrief(CInPacket& packet)
{
    CDBPremiumProduct::ReadBrief(packet);
    if (m_nType == 1)
        ReadSubProducts(packet);
    else if (m_nType == 3)
        ReadLimitProducts(packet);
}

// @0x1406a12a0
BOOL CMeratMarketPremiumProduct::LoadXml(Unk_140165cf0* pElem)
{
    FUN_1408731e0(pElem, "sn", m_nId);
    FUN_140873220(pElem, "id", m_nItemId);
    FUN_1408731e0(pElem, "grade", m_nGrade);
    FUN_1408731e0(pElem, "saleTag", m_nSaleTag);
    CStringA strStart;
    FUN_1408733e0(pElem, "startDate", strStart);
    if (strStart.Trim().IsEmpty())
    {
        m_startDate = CMsTime(2010, 1, 1, 0, 0, 0);
    }
    else
    {
        CMsTime t;
        if (FUN_14028e280(t, CStringA("%04d-%02d-%02d-%02d-%02d-%02d"), strStart))
            m_startDate = t;
    }
    CStringA strEnd;
    FUN_1408733e0(pElem, "endDate", strEnd);
    if (strEnd.Trim().IsEmpty())
    {
        m_endDate = CMsTime(2100, 1, 1, 0, 0, 0);
    }
    else
    {
        CMsTime t;
        if (FUN_14028e280(t, CStringA("%04d-%02d-%02d-%02d-%02d-%02d"), strEnd))
            m_endDate = t;
    }
    FUN_1408731e0(pElem, "chartOrder", m_nChartOrder);
    bool bVisible = false;
    FUN_1408730a0(pElem, "visible", bVisible);
    m_bVisible = bVisible;
    int nBuyLimit = 0;
    FUN_1408731e0(pElem, "buyLimit", nBuyLimit);
    if (nBuyLimit < 0 || 2 < nBuyLimit)
        return FALSE;
    m_nBuyLimit = nBuyLimit;
    FUN_1408731e0(pElem, "buyLimitMax", m_nBuyLimitMax);
    return TRUE;
}

// @0x1406a1630
int CMeratMarketPremiumProduct::GetGrade()
{
    return m_nGrade;
}

// @0x1406a1650
int CMeratMarketPremiumProduct::GetCurrency()
{
    return m_nCurrency;
}

// @0x1406a1670
int CMeratMarketPremiumProduct::GetDisplayId()
{
    int nId;
    switch (m_nType)
    {
    case 1:
    case 3:
        nId = m_nId;
        break;
    case 2:
    case 4:
        nId = m_n2c;
        break;
    default:
        return 0;
    }
    return nId;
}

// @0x1406a16d0
MS2Ptr<CDBPremiumProduct> CMeratMarketPremiumProduct::GetSubProduct(int nId)
{
    MS2Ptr<CDBPremiumProduct> spProduct(0);
    m_mapSub.Lookup(nId, spProduct);
    return spProduct;
}

// @0x1406a1760
MS2Ptr<CDBPremiumProduct> CMeratMarketPremiumProduct::GetLimitProduct(int nId)
{
    MS2Ptr<CDBPremiumProduct> spProduct(0);
    m_mapLimit.Lookup(nId, spProduct);
    return spProduct;
}

// @0x1406a17f0
int CMeratMarketPremiumProduct::GetB0(int nSubId)
{
    if (nSubId == 0)
        return m_nb0;
    int n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->m_nb0;
    }
    return n;
}

// @0x1406a1880
int CMeratMarketPremiumProduct::GetB4(int nSubId)
{
    if (nSubId == 0)
        return m_nb4;
    int n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->m_nb4;
    }
    return n;
}

// @0x1406a1910
int CMeratMarketPremiumProduct::GetB8(int nSubId)
{
    if (nSubId == 0)
        return m_nb8;
    int n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->m_nb8;
    }
    return n;
}

// @0x1406a19a0
CMsTime CMeratMarketPremiumProduct::GetStartDate(int nSubId)
{
    if (nSubId == 0)
        return CMsTime(m_startDate.Get());
    CMsTime t(0);
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            t = spSub->m_startDate.Get();
    }
    return t;
}

// @0x1406a1a70
CMsTime CMeratMarketPremiumProduct::GetEndDate(int nSubId)
{
    if (nSubId == 0)
        return m_endDate;
    CMsTime t(0);
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            t = spSub->m_endDate;
    }
    return t;
}

// @0x1406a1b30
__int64 CMeratMarketPremiumProduct::GetSalePriceOf(int nSubId)
{
    __int64 n;
    if (nSubId == 0)
    {
        n = GetSalePrice(this);
    }
    else
    {
        n = 0;
        if (m_nType == 1)
        {
            MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
            if (spSub.get())
                n = spSub->GetSalePrice(this);
        }
    }
    return n;
}

// @0x1406a1be0
__int64 CMeratMarketPremiumProduct::GetPriceOf(int nSubId)
{
    if (nSubId == 0)
        return m_nPrice;
    __int64 n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->m_nPrice;
    }
    return n;
}

// @0x1406a1c70
bool CMeratMarketPremiumProduct::FUN_1406a1c70(int nSubId)
{
    if (!FUN_1406a5840())
        return false;
    if (nSubId == 0)
    {
        if (m_n58 == 0)
            return false;
        if (m_nBuyLimit != 0)
            return false;
        return m_nType == 1;
    }
    bool b = false;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            b = spSub->m_n58 == 1;
    }
    return b;
}

// @0x1406a1d60
bool CMeratMarketPremiumProduct::HasSubProducts()
{
    return !m_mapSub.IsEmpty();
}

// @0x1406a1da0
__int64 CMeratMarketPremiumProduct::GetPointOf(int nSubId)
{
    __int64 n;
    if (nSubId == 0)
    {
        n = GetPoint();
    }
    else
    {
        n = 0;
        if (m_nType == 1)
        {
            MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
            if (spSub.get())
                n = spSub->GetPoint();
        }
    }
    return n;
}

// @0x1406a1e50
CStringA CMeratMarketPremiumProduct::GetCategory()
{
    if (!IsEventPeriod(0))
        return m_strCategory;
    return m_strEventCategory;
}

// @0x1406a1ee0
int CMeratMarketPremiumProduct::FUN_1406a1ee0()
{
    return m_n158;
}

// @0x1406a1f00
CStringA CMeratMarketPremiumProduct::FUN_1406a1f00()
{
    return m_str160;
}

// @0x1406a1f50
bool CMeratMarketPremiumProduct::FUN_1406a1f50()
{
    return m_b168;
}

// @0x1406a1f70
void CMeratMarketPremiumProduct::WriteSubProducts(COutputStream& stream)
{
    stream.vfunc_o10_1((unsigned char)m_mapSub.GetCount());
    POSITION pos = m_mapSub.GetHeadPosition();
    while (pos)
    {
        MS2Ptr<CDBPremiumProduct> spSub = m_mapSub.GetValueAt(pos);
        if (spSub == 0)
        {
            stream.vfunc_o10_1(0);
        }
        else
        {
            stream.vfunc_o10_1(1);
            spSub->Write(stream);
        }
        m_mapSub.GetNext(pos);
    }
}

// @0x1406a2090
void CMeratMarketPremiumProduct::ReadSubProducts(CInPacket& packet)
{
    unsigned char nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        if (packet.vfunc_o8_1() == 1)
        {
            MS2Ptr<CDBPremiumProduct> spSub(new CDBPremiumProduct);
            spSub->Read(packet);
            m_mapSub.SetAt(spSub->m_nId, spSub);
        }
    }
}

// @0x1406a21f0
void CMeratMarketPremiumProduct::WriteLimitProducts(COutputStream& stream)
{
    stream.vfunc_o10_1((unsigned char)m_mapLimit.GetCount());
    POSITION pos = m_mapLimit.GetHeadPosition();
    while (pos)
    {
        MS2Ptr<CDBPremiumProduct> spSub = m_mapLimit.GetValueAt(pos);
        if (spSub == 0)
        {
            stream.vfunc_o10_1(0);
        }
        else
        {
            stream.vfunc_o10_1(1);
            spSub->Write(stream);
        }
        m_mapLimit.GetNext(pos);
    }
}

// @0x1406a2310
void CMeratMarketPremiumProduct::ReadLimitProducts(CInPacket& packet)
{
    unsigned char nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        if (packet.vfunc_o8_1() == 1)
        {
            MS2Ptr<CDBPremiumProduct> spSub(new CDBPremiumProduct);
            spSub->Read(packet);
            m_mapLimit.SetAt(spSub->m_nId, spSub);
        }
    }
}

// @0x1406a2470
CStringA FUN_1406a2470(__int64 nTime)
{
    CMsTime t(nTime);
    int nSecond = t.GetSecond();
    int nMinute = t.GetMinute();
    int nHour = t.GetHour();
    int nDay = t.GetDay();
    int nMonth = t.GetMonth();
    int nYear = t.GetYear();
    return StringFormat("{0:04d}-{1:02d}-{2:02d} {3:02d}:{4:02d}:{5:02d}", nYear, nMonth, nDay, nHour, nMinute, nSecond);
}
