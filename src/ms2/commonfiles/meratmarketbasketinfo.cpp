// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The merat (premium cash) market: basket entries, the
// premium product records and table (Table/Server/shop_merat.xml), market products and packets.
// MS2-UNIT: ?\meratmarketbasketinfo.cpp
// MS2-RANGE: 0x14069c3e0-0x1406ae9c0 .text$mn
// MS2-PIN: ??_7CMeratMarketPremium@@6B?$TSingleton@VCMeratMarketPremium@@@@@ 0x142d782c8
// MS2-RANGE: 0x1400bb3f0-0x1400bb6a0 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\meratmarketbasketinfo.cpp"   // no asserts of its own
#include "ms2/placeholder/ms2stdafx.h"
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);  // xmlattr.h asserts (NDEBUG DLL build)
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include <string>
#include "ms2/ms2format.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/logstring.h"
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
CStringA FUN_14071a5b0(const CStringA& strDir, const CStringA& strFile);    // Table/<dir>/<file>
bool FUN_1406a4fe0(int nId);
bool FUN_1406a5010(int nId);

// The common log (FUN_140166440()).
class Unk_MeratLog : public CLogString
{
public:
    template <class T> void Log(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* format, const T& value)
    {
        fmt::internal::Value values[] = { fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(value) };
        FUN_1406535b0(a, b, flags, format, fmt::ArgList(fmt::internal::make_type(value), values));
    }
};
Unk_MeratLog* FUN_140166440();

// ---- statics (.text$di in this order) -----------------------------------------------------------------------------

CLockCriticalSection CMeratMarketPremium::s_lock;
CStringA g_premiumSortNames[8] = { "None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd" };
CStringA g_ugcSortNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
CStringA g_strDesignersHomeLayout("designersHomeLayout.xml");
CStringA g_strMeratHomeLayout("meratHomeLayout.xml");
CStringA g_strPremiumHomeLayout("premiumHomeLayout.xml");
std::string g_strLocaleDir("kr/");
std::string g_strLocaleDir2("kr/");

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
MS2_REPLACE(0x14069C3E0, FUN_14069c3e0, 79, 0x5DB2E5B1);

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
MS2_REPLACE_METHOD(0x14069C540, CMeratMarketBasketInfo, Write, 263, 0x23EDB9E2);

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
MS2_REPLACE_METHOD(0x14069C650, CMeratMarketBasketInfo, Read, 518, 0x5F2177E5);

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
// MS2-FUNCTIONAL: the exe is 83 bytes longer; its field copy order and temporaries are not recovered
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
// MS2-FUNCTIONAL: the exe frame is 0x10 larger; the CString read temporaries are laid out differently
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
// MS2-FUNCTIONAL: the sale-event loop codegen differs (exe 30 bytes shorter)
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
MS2_REPLACE_METHOD(0x14069F980, CDBPremiumProduct, GetSalePrice, 1149, 0xF2A3A3EA);

// @0x14069fe10
// MS2-FUNCTIONAL: the exe homes r8, an unused parameter that is not recovered
__int64 CDBPremiumProduct::GetPoint()
{
    return m_bPoint ? m_nPoint : 0;
}
MS2_REPLACE_METHOD(0x14069FE10, CDBPremiumProduct, GetPoint, 38, 0xDC68781C);

// @0x14069fe40
// MS2-FUNCTIONAL: branch layout differs (exe 10 bytes shorter)
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
MS2_REPLACE_METHOD(0x14069FE40, CDBPremiumProduct, FUN_14069fe40, 153, 0xD3C9C9A1);

// @0x14069fee0
int CDBPremiumProduct::FUN_14069fee0()
{
    return m_n10c;
}
MS2_REPLACE_METHOD(0x14069FEE0, CDBPremiumProduct, FUN_14069fee0, 17, 0xFFA719EE);

// @0x14069ff00
bool CDBPremiumProduct::FUN_14069ff00()
{
    if (!m_bPoint)
        return false;
    return m_nPoint > 0;
}
MS2_REPLACE_METHOD(0x14069FF00, CDBPremiumProduct, FUN_14069ff00, 69, 0xB9AF4874);

// @0x14069ff50
bool CDBPremiumProduct::FUN_14069ff50()
{
    if (m_n90 == 0 || m_n90 == 99)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x14069FF50, CDBPremiumProduct, FUN_14069ff50, 40, 0xB45F7A29);

// @0x14069ff80
int CDBPremiumProduct::GetCurrencyItemId()
{
    if (m_nCurrency == 1)
        return 100000;
    else if (m_nCurrency == 2)
        return 100001;
    return 0;
}
MS2_REPLACE_METHOD(0x14069FF80, CDBPremiumProduct, GetCurrencyItemId, 44, 0xE8D982E0);

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
MS2_REPLACE_METHOD(0x14069FFC0, CDBPremiumProduct, FUN_14069ffc0, 193, 0x0D2AE106);

// @0x1406a0090
bool CDBPremiumProduct::FUN_1406a0090()
{
    if (m_n1ac == 0)
        return true;
    if (IsNotRecentDayChange(m_randomSaleDay.Get()))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406A0090, CDBPremiumProduct, FUN_1406a0090, 69, 0x0A3F66AA);

// @0x1406a00e0
CStringW CDBPremiumProduct::GetName()
{
    if (m_nType == 3)
        return m_strName;
    return FUN_141425950(m_nItemId);
}
MS2_REPLACE_METHOD(0x1406A00E0, CDBPremiumProduct, GetName, 116, 0x15484927);

// @0x1406a0160
// MS2-FUNCTIONAL: the order of the path temporaries differs
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
MS2_REPLACE_METHOD(0x1406A0160, CDBPremiumProduct, GetIconPath, 191, 0x7FE7101A);

// @0x1406a0230
int CDBPremiumProduct::FUN_1406a0230()
{
    int nCurrency = m_nCurrency;
    if (nCurrency == 3)
        nCurrency = 1;
    return FUN_14069c3e0(nCurrency);
}
MS2_REPLACE_METHOD(0x1406A0230, CDBPremiumProduct, FUN_1406a0230, 50, 0xEF9BAC3A);

// @0x1406a0270
__int64 CDBPremiumProduct::FUN_1406a0270()
{
    if (m_nType != 7)
        return 0;
    __int64 nPrice = FUN_1406a6150(m_nSalePrice, m_n1b0);
    return nPrice;
}
MS2_REPLACE_METHOD(0x1406A0270, CDBPremiumProduct, FUN_1406a0270, 64, 0xC6CAFFCB);

// @0x1406a02c0
// MS2-FUNCTIONAL: the day-text building temporaries differ (exe 55 bytes longer)
CStringW CDBPremiumProduct::GetSellDayText()
{
    if (m_nType == 7 || m_nType == 8)
    {
        CMsTime zero(0);
        if (!(m_randomSaleDay == zero))
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
MS2_REPLACE_METHOD(0x1406A02C0, CDBPremiumProduct, GetSellDayText, 446, 0xFE195BD6);

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
MS2_REPLACE_METHOD(0x1406A0570, CMeratMarketPremiumProduct, Reset, 80, 0x94908197);

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
// MS2-FUNCTIONAL: the copy order differs (exe 22 bytes shorter)
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
MS2_REPLACE_METHOD(0x1406A0970, CMeratMarketPremiumProduct, SetCounts, 65, 0xD1469120);

// @0x1406a09c0
BOOL CMeratMarketPremiumProduct::HasLimit()
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
    return FALSE;
}
MS2_REPLACE_METHOD(0x1406A09C0, CMeratMarketPremiumProduct, HasLimit, 149, 0xB461C77D);

// @0x1406a0a60
bool CMeratMarketPremiumProduct::IsBuyLimitReached()
{
    if (!HasLimit())
        return false;
    if (m_nBuyLimit)
        return m_nBuyCount >= m_nBuyLimitMax;
    return false;
}
MS2_REPLACE_METHOD(0x1406A0A60, CMeratMarketPremiumProduct, IsBuyLimitReached, 97, 0x258A820F);

// @0x1406a0ad0
// MS2-FUNCTIONAL: branch layout differs
bool CMeratMarketPremiumProduct::IsLimitSoldOut()
{
    if (!HasLimit())
        return false;
    if (m_nType == 3)
    {
        if (m_nLimitCount == 0)
            return false;
        return m_nSoldCount >= m_nLimitCount;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1406A0AD0, CMeratMarketPremiumProduct, IsLimitSoldOut, 112, 0x7FDBB94B);

// @0x1406a0b50
// MS2-FUNCTIONAL: branch layout differs
bool CMeratMarketPremiumProduct::IsHomeSoldOut()
{
    if (!HasLimit())
        return false;
    if (m_nType == 6)
    {
        if (m_nLimitCount == 0)
            return false;
        return m_nHomeSoldCount >= m_nLimitCount;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1406A0B50, CMeratMarketPremiumProduct, IsHomeSoldOut, 112, 0x271C8904);

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
MS2_REPLACE_METHOD(0x1406A0BD0, CMeratMarketPremiumProduct, GetRemainCount, 222, 0x373A971F);

// @0x1406a0cc0
bool CMeratMarketPremiumProduct::IsSoldOut()
{
    return IsBuyLimitReached() || IsLimitSoldOut() || IsHomeSoldOut();
}
MS2_REPLACE_METHOD(0x1406A0CC0, CMeratMarketPremiumProduct, IsSoldOut, 88, 0x5CDCCBAD);

// @0x1406a0d20
bool CMeratMarketPremiumProduct::IsNotSelling(__int64 nOffset)
{
    if (!IsSelling(nOffset))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406A0D20, CMeratMarketPremiumProduct, IsNotSelling, 47, 0xC65BF660);

// @0x1406a0d60
bool CMeratMarketPremiumProduct::IsNotEventPeriod(__int64 nOffset)
{
    if (!IsEventPeriod(nOffset))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1406A0D60, CMeratMarketPremiumProduct, IsNotEventPeriod, 47, 0x3B0DCD4B);

// @0x1406a0da0
bool CMeratMarketPremiumProduct::IsSelling(__int64 nOffset)
{
    CMsTime zeroStart(0);
    if (m_startDate == zeroStart)
    {
        CMsTime zeroEnd(0);
        if (m_endDate == zeroEnd)
            return true;
    }
    CMsTime now(GetServerTime());
    CMsTime start(m_startDate.Get() - nOffset);
    return now >= start && now <= m_endDate;
}
MS2_REPLACE_METHOD(0x1406A0DA0, CMeratMarketPremiumProduct, IsSelling, 250, 0xACFDCFAD);

// @0x1406a0ea0
bool CMeratMarketPremiumProduct::IsEventPeriod(__int64 nOffset)
{
    CMsTime zeroStart(0);
    if (m_eventStart == zeroStart)
    {
        CMsTime zeroEnd(0);
        if (m_eventEnd == zeroEnd)
            return false;
    }
    CMsTime now(GetServerTime());
    CMsTime start(m_eventStart.Get() - nOffset);
    bool bInPeriod = now >= start && now <= m_eventEnd;
    if (!bInPeriod)
        return false;
    if (IsSelling(nOffset))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406A0EA0, CMeratMarketPremiumProduct, IsEventPeriod, 309, 0xFD9AF27F);

// @0x1406a0fe0
bool CMeratMarketPremiumProduct::FUN_1406a0fe0()
{
    return m_n9c == 0;
}
MS2_REPLACE_METHOD(0x1406A0FE0, CMeratMarketPremiumProduct, FUN_1406a0fe0, 48, 0xABBF3BA7);

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
MS2_REPLACE_METHOD(0x1406A1020, CMeratMarketPremiumProduct, Write, 182, 0x55B666E1);

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
MS2_REPLACE_METHOD(0x1406A10E0, CMeratMarketPremiumProduct, Read, 239, 0xF64B2730);

// @0x1406a11e0
void CMeratMarketPremiumProduct::WriteBrief(COutputStream& stream)
{
    CDBPremiumProduct::WriteBrief(stream);
    if (m_nType == 1)
        WriteSubProducts(stream);
    else if (m_nType == 3)
        WriteLimitProducts(stream);
}
MS2_REPLACE_METHOD(0x1406A11E0, CMeratMarketPremiumProduct, WriteBrief, 88, 0x7630A694);

// @0x1406a1240
void CMeratMarketPremiumProduct::ReadBrief(CInPacket& packet)
{
    CDBPremiumProduct::ReadBrief(packet);
    if (m_nType == 1)
        ReadSubProducts(packet);
    else if (m_nType == 3)
        ReadLimitProducts(packet);
}
MS2_REPLACE_METHOD(0x1406A1240, CMeratMarketPremiumProduct, ReadBrief, 88, 0x2F2F442F);

// @0x1406a12a0
// MS2-FUNCTIONAL: the attribute read temporaries differ (exe 13 bytes shorter)
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
        CStringA strFormat("%04d-%02d-%02d-%02d-%02d-%02d");
        if (FUN_14028e280(t, strFormat, strStart))
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
        CStringA strFormat("%04d-%02d-%02d-%02d-%02d-%02d");
        if (FUN_14028e280(t, strFormat, strEnd))
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
MS2_REPLACE_METHOD(0x1406A12A0, CMeratMarketPremiumProduct, LoadXml, 892, 0x6BF24D93);

// @0x1406a1630
int CMeratMarketPremiumProduct::GetGrade()
{
    return m_nGrade;
}
MS2_REPLACE_METHOD(0x1406A1630, CMeratMarketPremiumProduct, GetGrade, 17, 0x84EDFDD7);

// @0x1406a1650
int CMeratMarketPremiumProduct::GetCurrency()
{
    return m_nCurrency;
}
MS2_REPLACE_METHOD(0x1406A1650, CMeratMarketPremiumProduct, GetCurrency, 14, 0x620CA41F);

// @0x1406a1670
int CMeratMarketPremiumProduct::GetDisplayId()
{
    int nId = 0;
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
    }
    return nId;
}
MS2_REPLACE_METHOD(0x1406A1670, CMeratMarketPremiumProduct, GetDisplayId, 89, 0xCDF1CA84);

// @0x1406a16d0
MS2Ptr<CDBPremiumProduct> CMeratMarketPremiumProduct::GetSubProduct(int nId)
{
    MS2Ptr<CDBPremiumProduct> spProduct(0);
    m_mapSub.Lookup(nId, spProduct);
    return spProduct;
}
MS2_REPLACE_METHOD(0x1406A16D0, CMeratMarketPremiumProduct, GetSubProduct, 123, 0xF92751D5);

// @0x1406a1760
MS2Ptr<CDBPremiumProduct> CMeratMarketPremiumProduct::GetLimitProduct(int nId)
{
    MS2Ptr<CDBPremiumProduct> spProduct(0);
    m_mapLimit.Lookup(nId, spProduct);
    return spProduct;
}
MS2_REPLACE_METHOD(0x1406A1760, CMeratMarketPremiumProduct, GetLimitProduct, 123, 0xEF481C73);

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
MS2_REPLACE_METHOD(0x1406A17F0, CMeratMarketPremiumProduct, GetB0, 136, 0x2060EF93);

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
MS2_REPLACE_METHOD(0x1406A1880, CMeratMarketPremiumProduct, GetB4, 136, 0x6B08FAA6);

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
MS2_REPLACE_METHOD(0x1406A1910, CMeratMarketPremiumProduct, GetB8, 136, 0x0DB071D5);

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
MS2_REPLACE_METHOD(0x1406A19A0, CMeratMarketPremiumProduct, GetStartDate, 202, 0x4A66A353);

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
MS2_REPLACE_METHOD(0x1406A1A70, CMeratMarketPremiumProduct, GetEndDate, 186, 0xDAA7A8CB);

// @0x1406a1b30
__int64 CMeratMarketPremiumProduct::GetSalePriceOf(int nSubId)
{
    if (nSubId == 0)
        return GetSalePrice(this);
    __int64 n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->GetSalePrice(this);
    }
    return n;
}
MS2_REPLACE_METHOD(0x1406A1B30, CMeratMarketPremiumProduct, GetSalePriceOf, 169, 0xE287036E);

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
MS2_REPLACE_METHOD(0x1406A1BE0, CMeratMarketPremiumProduct, GetPriceOf, 135, 0xEF940809);

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
        if (m_nType != 1)
            return false;
        return true;
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
MS2_REPLACE_METHOD(0x1406A1C70, CMeratMarketPremiumProduct, FUN_1406a1c70, 221, 0x1442EE2B);

// @0x1406a1d60
BOOL CMeratMarketPremiumProduct::HasSubProducts()
{
    if (m_mapSub.IsEmpty())
        return FALSE;
    return TRUE;
}
MS2_REPLACE_METHOD(0x1406A1D60, CMeratMarketPremiumProduct, HasSubProducts, 49, 0x7E7D6807);

// @0x1406a1da0
__int64 CMeratMarketPremiumProduct::GetPointOf(int nSubId)
{
    if (nSubId == 0)
        return GetPoint();
    __int64 n = 0;
    if (m_nType == 1)
    {
        MS2Ptr<CDBPremiumProduct> spSub = GetSubProduct(nSubId);
        if (spSub.get())
            n = spSub->GetPoint();
    }
    return n;
}
MS2_REPLACE_METHOD(0x1406A1DA0, CMeratMarketPremiumProduct, GetPointOf, 159, 0x7BB0F0B3);

// @0x1406a1e50
// MS2-FUNCTIONAL: a stack slot differs
CStringA CMeratMarketPremiumProduct::GetCategory()
{
    if (!IsEventPeriod(0))
        return m_strCategory;
    return m_strEventCategory;
}
MS2_REPLACE_METHOD(0x1406A1E50, CMeratMarketPremiumProduct, GetCategory, 130, 0x2EE05A1E);

// @0x1406a1ee0
int CMeratMarketPremiumProduct::FUN_1406a1ee0()
{
    return m_n158;
}
MS2_REPLACE_METHOD(0x1406A1EE0, CMeratMarketPremiumProduct, FUN_1406a1ee0, 17, 0xF95067D2);

// @0x1406a1f00
CStringA CMeratMarketPremiumProduct::FUN_1406a1f00()
{
    return m_str160;
}
MS2_REPLACE_METHOD(0x1406A1F00, CMeratMarketPremiumProduct, FUN_1406a1f00, 68, 0x4B23F95C);

// @0x1406a1f50
bool CMeratMarketPremiumProduct::FUN_1406a1f50()
{
    return m_b168;
}
MS2_REPLACE_METHOD(0x1406A1F50, CMeratMarketPremiumProduct, FUN_1406a1f50, 18, 0x7970D0EC);

// @0x1406a1f70
void CMeratMarketPremiumProduct::WriteSubProducts(COutputStream& stream)
{
    int nCount = (int)m_mapSub.GetCount();
    stream.vfunc_o10_1((unsigned char)nCount);
    for (POSITION pos = m_mapSub.GetHeadPosition(); pos; m_mapSub.GetNext(pos))
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
    }
}
MS2_REPLACE_METHOD(0x1406A1F70, CMeratMarketPremiumProduct, WriteSubProducts, 281, 0xF5F0BA0A);

// @0x1406a2090
void CMeratMarketPremiumProduct::ReadSubProducts(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        int nExists = packet.vfunc_o8_1();
        if (nExists == 1)
        {
            MS2Ptr<CDBPremiumProduct> spSub(new CDBPremiumProduct);
            spSub->Read(packet);
            m_mapSub.SetAt(spSub->m_nId, spSub);
        }
    }
}
MS2_REPLACE_METHOD(0x1406A2090, CMeratMarketPremiumProduct, ReadSubProducts, 341, 0x414652F1);

// @0x1406a21f0
void CMeratMarketPremiumProduct::WriteLimitProducts(COutputStream& stream)
{
    int nCount = (int)m_mapLimit.GetCount();
    stream.vfunc_o10_1((unsigned char)nCount);
    for (POSITION pos = m_mapLimit.GetHeadPosition(); pos; m_mapLimit.GetNext(pos))
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
    }
}
MS2_REPLACE_METHOD(0x1406A21F0, CMeratMarketPremiumProduct, WriteLimitProducts, 281, 0x6CBC751C);

// @0x1406a2310
void CMeratMarketPremiumProduct::ReadLimitProducts(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        int nExists = packet.vfunc_o8_1();
        if (nExists == 1)
        {
            MS2Ptr<CDBPremiumProduct> spSub(new CDBPremiumProduct);
            spSub->Read(packet);
            m_mapLimit.SetAt(spSub->m_nId, spSub);
        }
    }
}
MS2_REPLACE_METHOD(0x1406A2310, CMeratMarketPremiumProduct, ReadLimitProducts, 341, 0x96DD3F11);

// @0x1406a2470
// MS2-FUNCTIONAL: the StringFormat argument temporaries differ
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
MS2_REPLACE(0x1406A2470, FUN_1406a2470, 261, 0x9D2D65E2);

// ---- CMeratMarketPremium -------------------------------------------------------------------------------------------

// @0x1406a2580
CMeratMarketPremium::CMeratMarketPremium()
{
}

// @0x1406a26b0
CMeratMarketPremium::~CMeratMarketPremium()
{
}

// @0x1406a2750
void CMeratMarketPremium::Clear()
{
    m_products.RemoveAll();
    m_productMap.RemoveAll();
    m_categoryMap.RemoveAll();
    m_ugcMap.RemoveAll();
}
MS2_REPLACE_METHOD(0x1406A2750, CMeratMarketPremium, Clear, 86, 0x79A303C8);

// @0x1406a27b0
int CMeratMarketPremium::Init()
{
    m_nShopType = 100000;
    Clear();
    LoadCategories();
    CStringA strServerPath = FUN_14071a5b0("Table/Server", "shop_merat.xml");
    FUN_1401d1160(strServerPath);
    CStringA strPath = FUN_14071a5b0("Table", "shop_merat.xml");
    return 1;
}
MS2_REPLACE_METHOD(0x1406A27B0, CMeratMarketPremium, Init, 325, 0x52A35A3A);

// @0x1406a2900
int CMeratMarketPremium::LoadXml(const CStringA& strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == NULL)
        return 0;
    for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("item"); pElem; pElem = pElem->FUN_140168650("item"))
    {
        MS2Ptr<CMeratMarketPremiumProduct> spProduct(new CMeratMarketPremiumProduct);
        if (spProduct.get())
        {
            spProduct->LoadXml(pElem);
            CStringA strCategory;
            FUN_1408733e0(pElem, "category", strCategory);
            unsigned nItemId = spProduct->m_nItemId;
            {
                MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
                if (spItem.get())
                {
                    if (strCategory.IsEmpty())
                        strCategory = spItem->property.category;
                }
                else
                {
                    FUN_140166440()->Log(0, 0, 0x2d, L"CMeratMarket::Read - error item id ({0})", nItemId);
                    continue;
                }
            }
            spProduct->m_nCategoryId = GetCategoryId(strCategory);
            m_products.Add(spProduct);
            m_productMap.SetAt(spProduct->m_nId, spProduct);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1406A2900, CMeratMarketPremium, LoadXml, 841, 0x490FF2B8);

// @0x1406a2c50
int CMeratMarketPremium::LoadUgcXml(const CStringA& strPath)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == NULL)
        return 0;
    for (Unk_140165cf0* pElem = pRoot->FUN_140165cf0("item"); pElem; pElem = pElem->FUN_140168650("item"))
    {
        MS2Ptr<CUgcPremiumProduct> spProduct(new CUgcPremiumProduct);
        if (spProduct.get())
        {
            FUN_140873220(pElem, "id", spProduct->m_nId);
            FUN_1408731e0(pElem, "sn", spProduct->m_nSn);
            FUN_140873220(pElem, "price", spProduct->m_nPrice);
            unsigned nId = spProduct->m_nId;
            if (spProduct->m_nPrice > 0)
                m_ugcMap.SetAt(nId, spProduct);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1406A2C50, CMeratMarketPremium, LoadUgcXml, 568, 0x285D3BB5);

// @0x1406a2e90
int CMeratMarketPremium::LoadCategories()
{
    if (CShopCategoryTable::GetInstance() == NULL)
        CShopCategoryTable::CreateInstance();
    int nShopType = m_nShopType;
    Unk_ShopCategoryBoxPtr<CShopCategoryTable::TabList> spTabs = CShopCategoryTable::GetInstance()->FUN_1407cb490(nShopType);
    if (static_cast<bool>(spTabs.get()) && !spTabs->IsEmpty())
    {
        for (POSITION pos = spTabs->GetHeadPosition(); pos; spTabs->GetNext(pos))
        {
            MS2Ptr<CShopCategoryTable::TabInfo> spTab(spTabs->GetAt(pos));
            if (spTab.get())
            {
                if (!spTab->m_subTabs.IsEmpty())
                {
                    CShopCategoryTable::TabList* pSubTabs = &spTab->m_subTabs;
                    for (POSITION subPos = pSubTabs->GetHeadPosition(); subPos; pSubTabs->GetNext(subPos))
                    {
                        MS2Ptr<CShopCategoryTable::TabInfo> spSubTab(pSubTabs->GetAt(subPos));
                        if (spSubTab.get())
                            AddCategory(spSubTab);
                    }
                }
                else
                {
                    AddCategory(spTab);
                }
            }
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1406A2E90, CMeratMarketPremium, LoadCategories, 607, 0x13C3A945);

// @0x1406a3100
void CMeratMarketPremium::AddCategory(MS2Ptr<CShopCategoryTable::TabInfo> tab)
{
    CAtlArray<CStringA> names;
    FUN_14015f050(tab->m_strCategories, names, ",");
    for (unsigned i = 0; i < names.GetCount(); i++)
    {
        CStringA strName(names[i]);
        if (m_categoryMap.Lookup(strName) == NULL)
            m_categoryMap.SetAt(strName, tab->m_nId);
    }
}

// @0x1406a3240
int CMeratMarketPremium::GetCategoryId(CStringA strCategory)
{
    if (strCategory.IsEmpty())
        return 0;
    int nId = 0;
    m_categoryMap.Lookup(strCategory, nId);
    return nId;
}
MS2_REPLACE_METHOD(0x1406A3240, CMeratMarketPremium, GetCategoryId, 138, 0x17D7B8FE);

// @0x1406a32d0
// MS2-FUNCTIONAL: the exe pads the lock guard else-path with a nop
MS2Ptr<CMeratMarketPremiumProduct> CMeratMarketPremium::FindProduct(int nId)
{
    if (Unk_LockGuard guard = s_lock) {} else
    {
        MS2Ptr<CMeratMarketPremiumProduct> spProduct(0);
        m_productMap.Lookup(nId, spProduct);
        return spProduct;
    }
}
MS2_REPLACE_METHOD(0x1406A32D0, CMeratMarketPremium, FindProduct, 179, 0x8C57130B);

// @0x1406a3390
// MS2-FUNCTIONAL: the exe pads the lock guard else-path with a nop
MS2Ptr<CUgcPremiumProduct> CMeratMarketPremium::FindUgcProduct(unsigned nId)
{
    if (Unk_LockGuard guard = s_lock) {} else
    {
        MS2Ptr<CUgcPremiumProduct> spProduct(0);
        m_ugcMap.Lookup(nId, spProduct);
        return spProduct;
    }
}
MS2_REPLACE_METHOD(0x1406A3390, CMeratMarketPremium, FindUgcProduct, 181, 0xDFF4960D);

// @0x1406a3450
int CMeratMarketPremium::GetShopType()
{
    return m_nShopType;
}
MS2_REPLACE_METHOD(0x1406A3450, CMeratMarketPremium, GetShopType, 14, 0x828204CF);

// @0x1406a3470
CAtlMap<int, MS2Ptr<CMeratMarketPremiumProduct> >* CMeratMarketPremium::GetProductMap()
{
    return &m_productMap;
}
MS2_REPLACE_METHOD(0x1406A3470, CMeratMarketPremium, GetProductMap, 15, 0x27BBF311);

// @0x1406a3490
CAtlArray<MS2Ptr<CMeratMarketPremiumProduct> >* CMeratMarketPremium::GetProducts()
{
    return &m_products;
}
MS2_REPLACE_METHOD(0x1406A3490, CMeratMarketPremium, GetProducts, 15, 0x676E38F1);

// ---- CMeratMarketSchCond -------------------------------------------------------------------------------------------

// @0x1406a34b0
CMeratMarketSchCond::CMeratMarketSchCond()
{
    Clear();
}

// @0x1406a3510
CMeratMarketSchCond::CMeratMarketSchCond(CInPacket& packet)
{
    Read(packet);
}

// @0x1406a3580
CMeratMarketSchCond::~CMeratMarketSchCond()
{
    Clear();
}

// @0x1406a35e0
void CMeratMarketSchCond::Clear()
{
    m_18 = 0;
    m_1c = 3;
    m_20 = 0;
    m_24 = 0;
    m_str = "";
    m_30 = 1;
    m_34 = 1;
    m_3c = 0;
    m_38 = 0;
    m_40 = 0x12;
    m_44 = 0;
    m_48 = 0;
}
MS2_REPLACE_METHOD(0x1406A35E0, CMeratMarketSchCond, Clear, 171, 0xC93C3525);

// @0x1406a36a0
void CMeratMarketSchCond::Set(const CStringW& str)
{
    Clear();
    m_str = str;
    m_18 = 1;
    m_1c = 3;
    m_20 = 0xfff;
    m_30 = 1;
    m_34 = 1;
}
MS2_REPLACE_METHOD(0x1406A36A0, CMeratMarketSchCond, Set, 112, 0xF19ECEA1);

// @0x1406a3720
void CMeratMarketSchCond::FUN_1406a3720(const CMeratMarketSchCond* pOther)
{
    Clear();
    if (!pOther)
        return;
    *this = *pOther;
}
MS2_REPLACE_METHOD(0x1406A3720, CMeratMarketSchCond, FUN_1406a3720, 54, 0x2C2EE794);

// @0x1406a3760
void CMeratMarketSchCond::Write(COutputStream* pStream)
{
    pStream->vfunc_o10_3(m_18);
    pStream->vfunc_o10_1((unsigned char)m_1c);
    pStream->vfunc_o10_3(m_20);
    pStream->vfunc_o10_1((unsigned char)m_24);
    pStream->vfunc_o10_8(m_str);
    pStream->vfunc_o10_3(m_30);
    pStream->vfunc_o10_3(m_34);
    pStream->vfunc_o10_1((unsigned char)m_38);
    pStream->vfunc_o10_1((unsigned char)m_3c);
    pStream->vfunc_o10_1((unsigned char)m_40);
}
MS2_REPLACE_METHOD(0x1406A3760, CMeratMarketSchCond, Write, 278, 0xE90DE073);

// @0x1406a3880
void CMeratMarketSchCond::Read(CInPacket& packet)
{
    Clear();
    m_18 = packet.vfunc_o8_3();
    m_1c = packet.vfunc_o8_1();
    m_20 = packet.vfunc_o8_3();
    m_24 = packet.vfunc_o8_1();
    m_str = packet.vfunc_o8_8();
    m_30 = packet.vfunc_o8_3();
    m_34 = packet.vfunc_o8_3();
    m_38 = packet.vfunc_o8_1();
    m_3c = packet.vfunc_o8_1();
    m_40 = packet.vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x1406A3880, CMeratMarketSchCond, Read, 628, 0x5DFF5C54);

// @0x1406a3b00
void CMeratMarketSchCond::WriteBrief(COutputStream* pStream)
{
    pStream->vfunc_o10_3(m_18);
    pStream->vfunc_o10_1((unsigned char)m_1c);
    pStream->vfunc_o10_3(m_20);
    pStream->vfunc_o10_1((unsigned char)m_24);
    pStream->vfunc_o10_8(m_str);
    pStream->vfunc_o10_3(m_30);
    pStream->vfunc_o10_3(m_34);
    pStream->vfunc_o10_1((unsigned char)m_38);
    pStream->vfunc_o10_1((unsigned char)m_40);
}
MS2_REPLACE_METHOD(0x1406A3B00, CMeratMarketSchCond, WriteBrief, 253, 0xB09B7120);

// @0x1406a3c10
void CMeratMarketSchCond::ReadBrief(CInputStream* pStream)
{
    Clear();
    m_18 = pStream->vfunc_o8_3();
    m_1c = pStream->vfunc_o8_1();
    m_20 = pStream->vfunc_o8_3();
    m_24 = pStream->vfunc_o8_1();
    m_str = pStream->vfunc_o8_8();
    m_30 = pStream->vfunc_o8_3();
    m_34 = pStream->vfunc_o8_3();
    m_38 = pStream->vfunc_o8_1();
    m_40 = pStream->vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x1406A3C10, CMeratMarketSchCond, ReadBrief, 313, 0x30427471);

// @0x1406a3d50
bool CMeratMarketSchCond::FUN_1406a3d50()
{
    return FUN_1406a5010(m_18);
}
MS2_REPLACE_METHOD(0x1406A3D50, CMeratMarketSchCond, FUN_1406a3d50, 27, 0x55302461);

// @0x1406a3d80
bool CMeratMarketSchCond::FUN_1406a3d80()
{
    return FUN_1406a4fe0(m_18);
}
MS2_REPLACE_METHOD(0x1406A3D80, CMeratMarketSchCond, FUN_1406a3d80, 27, 0x13D3DEC1);

// @0x1406a3db0
int CMeratMarketSchCond::GetPageGroup()
{
    if (m_30 == 0)
        return -1;
    int nIndex = m_30 - 1;
    int nGroup = nIndex / 5;
    return nGroup;
}
MS2_REPLACE_METHOD(0x1406A3DB0, CMeratMarketSchCond, GetPageGroup, 64, 0x4B7A4534);

// @0x1406a3e00
int CMeratMarketSchCond::GetPageGroupFirst()
{
    int nGroup = GetPageGroup();
    if (nGroup == -1)
        return 0;
    int nGroupSize = m_40 * 5;
    int nFirst = nGroup * nGroupSize + 1;
    return nFirst;
}
MS2_REPLACE_METHOD(0x1406A3E00, CMeratMarketSchCond, GetPageGroupFirst, 71, 0x18CC09A0);

// @0x1406a3e50
int CMeratMarketSchCond::GetPageGroupLast()
{
    int nGroup = GetPageGroup();
    if (nGroup == -1)
        return 0;
    int nGroupSize = m_40 * 5;
    int nLast = (nGroup + 1) * nGroupSize;
    return nLast;
}
MS2_REPLACE_METHOD(0x1406A3E50, CMeratMarketSchCond, GetPageGroupLast, 71, 0x9CBF5E2A);

// @0x1406a3ea0
int CMeratMarketSchCond::FUN_1406a3ea0()
{
    if (m_30 == 0)
        return -1;
    int nIndex = m_30 - 1;
    int nBlock = nIndex / 15;
    int nBlockSize = m_40 * 15;
    int nCount = (nBlock + 1) * nBlockSize;
    return nCount;
}
MS2_REPLACE_METHOD(0x1406A3EA0, CMeratMarketSchCond, FUN_1406a3ea0, 92, 0x6BC4FC5B);

// @0x1406a3f10
int CMeratMarketSchCond::GetPageSize()
{
    return m_40;
}
MS2_REPLACE_METHOD(0x1406A3F10, CMeratMarketSchCond, GetPageSize, 14, 0x620CA41F);

// @0x1406a3f30
int CMeratMarketSchCond::GetMaxPageSize()
{
    return 0x12;
}
MS2_REPLACE_METHOD(0x1406A3F30, CMeratMarketSchCond, GetMaxPageSize, 11, 0xCC810D29);

// @0x1406a3f50
CStringA CMeratMarketSchCond::GetSortName()
{
    if (m_24 < 0 || m_24 >= 7)
        return "";
    CStringA strName = g_premiumSortNames[m_24];
    return strName;
}
MS2_REPLACE_METHOD(0x1406A3F50, CMeratMarketSchCond, GetSortName, 172, 0x3F6D17D6);

// @0x1406a4010
int CMeratMarketSchCond::GetType()
{
    return m_18;
}
MS2_REPLACE_METHOD(0x1406A4010, CMeratMarketSchCond, GetType, 14, 0x72E52537);

// @0x1406a4030
int CMeratMarketSchCond::FUN_1406a4030()
{
    int nId = 0;
    if (m_18 % 100 == 0)
        nId = m_18 + 99;
    else
        nId = m_18;
    return nId;
}
MS2_REPLACE_METHOD(0x1406A4030, CMeratMarketSchCond, FUN_1406a4030, 73, 0xD1C235E0);

// @0x1406a4080
int CMeratMarketSchCond::IsSameQuery(const CMeratMarketSchCond* pOther)
{
    if (pOther == NULL)
        return 0;
    if (!IsSameSearch(pOther))
        return 0;
    if (const_cast<CMeratMarketSchCond*>(pOther)->FUN_1406a3ea0() > FUN_1406a3ea0())
        return 0;
    if (pOther->m_34 != m_34)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1406A4080, CMeratMarketSchCond, IsSameQuery, 117, 0x57F536DB);

// @0x1406a4100
int CMeratMarketSchCond::IsSameSearch(const CMeratMarketSchCond* pOther)
{
    if (pOther == NULL)
        return 0;
    if (pOther->m_18 != m_18)
        return 0;
    if (pOther->m_1c != m_1c)
        return 0;
    if (pOther->m_20 != m_20)
        return 0;
    if (pOther->m_24 != m_24)
        return 0;
    if (pOther->m_str != m_str)
        return 0;
    if (pOther->m_38 != m_38)
        return 0;
    if (pOther->m_40 != m_40)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1406A4100, CMeratMarketSchCond, IsSameSearch, 214, 0x95CB4598);

// @0x1406a41e0
bool CMeratMarketSchCond::IsValidPageSize()
{
    if (m_40 < 1 || m_40 > GetMaxPageSize())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406A41E0, CMeratMarketSchCond, IsValidPageSize, 51, 0x107DCEFD);

// ---- free helpers --------------------------------------------------------------------------------------------------

// @0x1406a4940
CStringA FUN_1406a4940()
{
    return g_strMeratHomeLayout;
}
MS2_REPLACE(0x1406A4940, FUN_1406a4940, 56, 0x743527AB);

// @0x1406a4980
CStringA FUN_1406a4980()
{
    return g_strPremiumHomeLayout;
}
MS2_REPLACE(0x1406A4980, FUN_1406a4980, 56, 0x5A1CB0F3);

// @0x1406a49c0
CStringA FUN_1406a49c0()
{
    return g_strDesignersHomeLayout;
}
MS2_REPLACE(0x1406A49C0, FUN_1406a49c0, 56, 0x9979CA64);

// @0x1406a4a00
CStringA FUN_1406a4a00()
{
    return FUN_14071a5b0("Table/Server", g_strMeratHomeLayout);
}
MS2_REPLACE(0x1406A4A00, FUN_1406a4a00, 99, 0xC1F7BB05);

// @0x1406a4a70
CStringA FUN_1406a4a70()
{
    return FUN_14071a5b0("Table/Server", g_strPremiumHomeLayout);
}
MS2_REPLACE(0x1406A4A70, FUN_1406a4a70, 99, 0xFD277E46);

// @0x1406a4ae0
CStringA FUN_1406a4ae0()
{
    return FUN_14071a5b0("Table/Server", g_strDesignersHomeLayout);
}
MS2_REPLACE(0x1406A4AE0, FUN_1406a4ae0, 99, 0x1C0A91EE);

// @0x1406a4fe0
bool FUN_1406a4fe0(int nId)
{
    if (nId >= 100 && nId <= 10000)
        return true;
    return false;
}
MS2_REPLACE(0x1406A4FE0, FUN_1406a4fe0, 28, 0xD244AD6D);

// @0x1406a5010
bool FUN_1406a5010(int nId)
{
    if (nId >= 40000 && nId <= 50000)
        return true;
    return false;
}
MS2_REPLACE(0x1406A5010, FUN_1406a5010, 31, 0x1922E959);

// @0x1406a5040
bool FUN_1406a5040(int nId)
{
    if (nId >= 10 && nId <= 12)
        return true;
    return false;
}
MS2_REPLACE(0x1406A5040, FUN_1406a5040, 25, 0x91706C4D);

// @0x1406a5060
bool FUN_1406a5060(int nId)
{
    if (FUN_1406a5040(nId) || FUN_1406a4fe0(nId) || FUN_1406a5010(nId))
        return true;
    return false;
}
MS2_REPLACE(0x1406A5060, FUN_1406a5060, 67, 0x0E89B702);
