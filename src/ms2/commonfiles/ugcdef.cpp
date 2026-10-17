// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The UGC proxy records (users, uploads, items, banners, guild
// marks / posters, blueprint images, market listings, bookmarks) and the MS2Ptr / container glue over them.
// MS2-UNIT: commonfiles\ugcdef.cpp
// MS2-RANGE: 0x14088e340-0x14089e270 .text$mn
// MS2-RANGE: 0x1400bd940-0x1400bdb40 .text$di
// MS2-PIN: ??1IUgcProxy@@UEAA@XZ 0x1408999a0
// MS2-PIN: ??0Unk_UgcLock@@QEAA@AEAVCLockCriticalSection@@H@Z 0x140203610
// MS2-PIN: ??1Unk_UgcLock@@QEAA@XZ 0x1401b5120
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcdef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcdef.h"
#include "stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "constraints.h"
#include "ms2/placeholder/exception.h"
#include "ms2/unnamed/unit_1401b6d10.h"
#include "commonstruct.h"

// The UGC info behind CItem::FUN_1405278d0 as this unit reads it (name at +0x40, rarity at +0x48).
struct Unk_UgcItemInfoView
{
    char m_pad_00[0x40];
    CStringW m_strName;
    int m_nRarity;
};

// The time helpers of unit_14088dbf0: the time (a packed date / hour) of a reservation, and the broken-down current time.
struct Unk_DateParts
{
    void* m_00;
    int m_date;
    int m_hour;
    void* m_time;
    int m_year;
    int m_month;
    int m_day;
    int m_dow;
    int m_hour2;
    int m_minute;
};
MS2_CHECK_SIZE(Unk_DateParts, 0x30);
unsigned __int64 FUN_14088dbf0(int nDate, int nHour);
Unk_DateParts* FUN_14088dfa0(Unk_DateParts* out, __int64 t, int nHourOffset);
__int64 FUN_140869440();
unsigned char FUN_140898b80(CInPacket& packet, Unk_1402c45d0 checker);     // a byte that Unk_1402c45d0 accepts, else throws

// The UGC managers behind the item.cpp singleton FUN_14052d220 (only the "is the server a test server" query is used).
class Unk_SSGUgcMgr { public: int FUN_14187f3b0(); };
Unk_SSGUgcMgr* FUN_14052d220();
CStringW FUN_1406c6bd0(const wchar_t* pszFormat, const __int64& nArg);     // "{0}" formatter
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& arg0, const CStringW& arg1);
CString FUN_1410280d0(int nKind, CString strName);                         // the local file of a ugc content kind

// The music book table of item.cpp (the title of a music book lives at +0x28).
class Unk_MusicBookInfo : public CPtred { public: char m_pad18[0x10]; CString m_str28; };
class Unk_MusicBookTable { public: MS2Ptr<Unk_MusicBookInfo> FUN_14072cc10(unsigned); };
Unk_MusicBookTable* FUN_14052d1d0();

// The names of the market order kinds (CUgcMarketSchCond::m_n20 indexes them).
static CStringA s_orderNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// The scoped lock of a CLockCriticalSection (ctor 0x140203610, dtor 0x1401b5120).
struct Unk_UgcLock { Unk_UgcLock(CLockCriticalSection& cs, int n); ~Unk_UgcLock(); void* p; };
MS2_CHECK_SIZE(Unk_UgcLock, 8);

// Market lookups of the item and merat market units.
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_1406a5390(int nItemId);
bool FUN_1406a5800();
bool FUN_140164830(const CStringW& a, const CStringW& b);

// The music record of a CItem as CUgcItemMusicNote::FUN_140893bb0 reads it.
struct Unk_MusicSrcView
{
    char m_pad_00[0x18];
    int m_n18;
    int m_n1c;
    CStringW m_str20;
    CStringW m_str28;
    CStringA m_str30;
    char m_pad_38[0x18];
    int m_n50;
    __int64 m_n58;
    __int64 m_n60;
    CStringW m_str68;
};

// @0x140899640
IUgcProxy::IUgcProxy()
{
}

// @0x14089abe0
void IUgcProxy::Write(COutputStream& stream) const
{
}

// @0x14089abd0
void IUgcProxy::Read(CInPacket& packet)
{
}

// @0x14088e340
CUgcUserProxy::CUgcUserProxy()
{
    Clear();
}

// @0x14088e3b0
CUgcUserProxy::~CUgcUserProxy()
{
}

// @0x14088e410
void CUgcUserProxy::Clear()
{
    m_nType = 0;
    m_accountId = 0;
    m_characterId = 0;
    m_strObjectName = "";
    m_strName = L"";
}

// @0x14088e480
int CUgcUserProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcUserProxy* pSrc = static_cast<const CUgcUserProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nType = pSrc->m_nType;
    m_accountId = pSrc->m_accountId;
    m_characterId = pSrc->m_characterId;
    m_strObjectName = pSrc->m_strObjectName;
    m_strName = pSrc->m_strName;
    return 1;
}

// @0x14088e540
void CUgcUserProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_3(m_nType);
    stream.vfunc_o10_4(m_accountId);
    stream.vfunc_o10_4(m_characterId);
    stream.vfunc_o10_6(m_strObjectName);
    stream.vfunc_o10_8(m_strName);
}

// @0x14088e5f0
void CUgcUserProxy::Read(CInPacket& packet)
{
    Clear();
    m_nType = packet.vfunc_o8_3();
    m_accountId = packet.vfunc_o8_4();
    m_characterId = packet.vfunc_o8_4();
    m_strObjectName = packet.vfunc_o8_6();
    m_strName = packet.vfunc_o8_8();
}

// @0x14088e790
CUgcUploadProxy::CUgcUploadProxy()
{
    Clear();
}

// @0x14088e800
CUgcUploadProxy::~CUgcUploadProxy()
{
}

// @0x14088e860
void CUgcUploadProxy::Clear()
{
    m_uid = 0;
    m_strName = "";
    m_nType = 0;
    m_nState = 0xff;
    m_strPath = "";
}

// @0x14088e8d0
int CUgcUploadProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcUploadProxy* pSrc = static_cast<const CUgcUploadProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_uid = pSrc->m_uid;
    m_strName = pSrc->m_strName;
    m_nType = pSrc->m_nType;
    m_nState = pSrc->m_nState;
    m_strPath = pSrc->m_strPath;
    return 1;
}

// @0x14088e990
void CUgcUploadProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_uid);
    stream.vfunc_o10_6(m_strName);
    stream.vfunc_o10_1(m_nType);
    stream.vfunc_o10_1(m_nState);
    stream.vfunc_o10_6(m_strPath);
}

// @0x14088ea40
void CUgcUploadProxy::Read(CInPacket& packet)
{
    Clear();
    m_uid = packet.vfunc_o8_4();
    m_strName = packet.vfunc_o8_6();
    m_nType = packet.vfunc_o8_1();
    m_nState = packet.vfunc_o8_1();
    m_strPath = packet.vfunc_o8_6();
}

// @0x14088ebf0
CUgcItemProxy::CUgcItemProxy()
{
    Clear();
}

// @0x14088ec50
CUgcItemProxy::CUgcItemProxy(CItem* pItem)
{
    FUN_14088f100(pItem);
}

// @0x14088ecc0
CUgcItemProxy::~CUgcItemProxy()
{
}

// @0x14088ed00
void CUgcItemProxy::Clear()
{
    m_itemUid = 0;
    m_nItemId = 0;
    m_nCount = 0;
    m_strName = "";
    m_nRarity = 0;
    m_uid = 0;
    m_nFlags = 0;
}

// @0x14088ed80
int CUgcItemProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcItemProxy* pSrc = static_cast<const CUgcItemProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_itemUid = pSrc->m_itemUid;
    m_nItemId = pSrc->m_nItemId;
    m_nCount = pSrc->m_nCount;
    m_strName = pSrc->m_strName;
    m_nRarity = pSrc->m_nRarity;
    return 1;
}

// @0x14088ee30
void CUgcItemProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_itemUid);
    stream.vfunc_o10_3(m_nItemId);
    stream.vfunc_o10_3(m_nCount);
    stream.vfunc_o10_8(m_strName);
    stream.vfunc_o10_1(m_nRarity);
    stream.vfunc_o10_4(m_uid);
    stream.vfunc_o10_0(m_nFlags == 1);
}

// @0x14088ef20
void CUgcItemProxy::Read(CInPacket& packet)
{
    Clear();
    m_itemUid = packet.vfunc_o8_4();
    m_nItemId = packet.vfunc_o8_3();
    m_nCount = packet.vfunc_o8_3();
    m_strName = packet.vfunc_o8_8();
    m_nRarity = packet.vfunc_o8_1();
    m_uid = packet.vfunc_o8_4();
    m_nFlags = packet.vfunc_o8_0();
}

// @0x14088f100
void CUgcItemProxy::FUN_14088f100(CItem* pItem)
{
    if (pItem != 0 && pItem->FUN_140525f10() != 0 && pItem->FUN_140525f60() != 0)
    {
        m_itemUid = pItem->FUN_140526a50();
        m_nItemId = pItem->FUN_1405276c0();
        m_nCount = 1;
        m_strName = reinterpret_cast<Unk_UgcItemInfoView*>(pItem->FUN_1405278d0())->m_strName;
        m_nRarity = reinterpret_cast<Unk_UgcItemInfoView*>(pItem->FUN_1405278d0())->m_nRarity;
        return;
    }
    Clear();
}

// @0x14088f210
CUgcItemPC::CUgcItemPC(CItem* pItem, int nObjectId)
    : CUgcItemProxy(pItem)
{
    m_nObjectId = nObjectId;
    int nSlot;
    if (pItem)
        nSlot = pItem->FUN_14052a020();
    else
        nSlot = 0;
    m_nSlot = nSlot;
}

// @0x14088f2a0
CUgcItemPC::~CUgcItemPC()
{
}

// @0x14088f2d0
int CUgcItemPC::FUN_14088f2d0(const CUgcItemProxy* pOther)
{
    if (pOther == 0)
        return 0;
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    m_nObjectId = 0;
    m_nSlot = 0;
    return 1;
}

// @0x14088f330
void CUgcItemPC::Clear()
{
    CUgcItemProxy::Clear();
    m_nObjectId = 0;
    m_nSlot = 0;
}

// @0x14088f370
int CUgcItemPC::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcItemPC* pSrc = static_cast<const CUgcItemPC*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nObjectId = pSrc->m_nObjectId;
    m_nSlot = pSrc->m_nSlot;
    return 1;
}

// @0x14088f3f0
UgcItemIcon::CallBackData::CallBackData()
{
    FUN_14088f4b0();
}

// @0x14088f450
UgcItemIcon::CallBackData::~CallBackData()
{
    m_spCond = 0;
}

// @0x14088f4b0
void UgcItemIcon::CallBackData::FUN_14088f4b0()
{
    m_nKind = -1;
    m_spCond = 0;
    m_30 = 0;
    m_38 = 0;
}

// @0x14088f500
void UgcItemIcon::CallBackData::FUN_14088f500(int nKind, const CMeratMarketSchCond* pCond, __int64 n30, int n38)
{
    m_nKind = nKind;
    m_spCond = 0;
    if (pCond != 0)
    {
        m_spCond.AssignRaw(new CMeratMarketSchCond);
        m_spCond->FUN_1406a3720(pCond);
    }
    m_30 = n30;
    m_38 = n38;
}

// @0x14088f5e0
void UgcItemIcon::CallBackData::FUN_14088f5e0(const CallBackData* pOther)
{
    m_nKind = pOther->m_nKind;
    m_spCond = 0;
    if (pOther->m_spCond.get() != 0)
    {
        m_spCond.AssignRaw(new CMeratMarketSchCond);
        m_spCond->FUN_1406a3720(pOther->m_spCond.get());
    }
    m_30 = pOther->m_30;
    m_38 = pOther->m_38;
}

// @0x14088f6f0
CUgcItemIconPC::CUgcItemIconPC()
{
    Clear();
}

// @0x14088f750
CUgcItemIconPC::CUgcItemIconPC(CItem* pItem, int n50)
    : CUgcItemProxy(pItem)
{
    int nObjectId = pItem ? pItem->FUN_14052a020() : 0;
    int nKind;
    if (nObjectId == 0)
        nKind = 2;
    else
        nKind = 1;
    m_nKind = nKind;
    m_nObjectId = nObjectId;
    m_n50 = n50;
    m_callBack.FUN_14088f4b0();
}

// @0x14088f830
CUgcItemIconPC::CUgcItemIconPC(const UgcItemIcon::CallBackData& callBack)
    : CUgcItemProxy((CItem*)0)
{
    FUN_14088f960(callBack);
}

// @0x14088f8a0
CUgcItemIconPC::~CUgcItemIconPC()
{
}

// @0x14088f8e0
int CUgcItemIconPC::FUN_14088f8e0(const CUgcItemProxy* pOther)
{
    if (pOther == 0)
        return 0;
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    m_nKind = 0;
    m_nObjectId = 0;
    m_n50 = 0;
    m_callBack.FUN_14088f4b0();
    return 1;
}

// @0x14088f960
void CUgcItemIconPC::FUN_14088f960(const UgcItemIcon::CallBackData& callBack)
{
    m_nObjectId = 0;
    m_n50 = 0;
    m_nKind = 3;
    m_callBack.FUN_14088f5e0(&callBack);
}

// @0x14088f9c0
void CUgcItemIconPC::Clear()
{
    CUgcItemProxy::Clear();
    m_nKind = 0;
    m_nObjectId = 0;
    m_n50 = 0;
    m_callBack.FUN_14088f4b0();
}

// @0x14088fa20
int CUgcItemIconPC::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcItemIconPC* pSrc = static_cast<const CUgcItemIconPC*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nKind = pSrc->m_nKind;
    m_nObjectId = pSrc->m_nObjectId;
    m_n50 = pSrc->m_n50;
    m_callBack.FUN_14088f5e0(&pSrc->m_callBack);
    return 1;
}

// @0x14088fad0
CUgcItemCube::CUgcItemCube()
{
    Clear();
}

// @0x14088fb30
CUgcItemCube::CUgcItemCube(CItem* pItem, const egf::EntityID& id)
    : CUgcItemProxy(pItem)
{
    m_entityId = id;
}

// @0x14088fbb0
CUgcItemCube::~CUgcItemCube()
{
}

// @0x14088fbe0
int CUgcItemCube::FUN_14088fbe0(const CUgcItemProxy* pOther)
{
    if (pOther == 0)
        return 0;
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    efd::UInt64 zero = 0;
    m_entityId = zero;
    return 1;
}

// @0x14088fc40
void CUgcItemCube::Clear()
{
    CUgcItemProxy::Clear();
    efd::UInt64 zero = 0;
    m_entityId = zero;
}

// @0x14088fc80
int CUgcItemCube::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcItemCube* pSrc = static_cast<const CUgcItemCube*>(pOther);
    if (pSrc == 0)
        return 0;
    m_entityId = pSrc->m_entityId;
    return 1;
}

// @0x14088fd00
CUgcItemRidee::CUgcItemRidee()
{
    Clear();
}

// @0x14088fd60
CUgcItemRidee::CUgcItemRidee(CItem* pItem, const egf::EntityID& id)
    : CUgcItemProxy(pItem)
{
    m_entityId = id;
}

// @0x14088fde0
CUgcItemRidee::~CUgcItemRidee()
{
}

// @0x14088fe10
int CUgcItemRidee::FUN_14088fe10(const CUgcItemProxy* pOther)
{
    if (pOther == 0)
        return 0;
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    efd::UInt64 zero = 0;
    m_entityId = zero;
    return 1;
}

// @0x14088fe70
void CUgcItemRidee::Clear()
{
    CUgcItemProxy::Clear();
    efd::UInt64 zero = 0;
    m_entityId = zero;
}

// @0x14088feb0
int CUgcItemRidee::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (CUgcItemProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcItemRidee* pSrc = static_cast<const CUgcItemRidee*>(pOther);
    if (pSrc == 0)
        return 0;
    m_entityId = pSrc->m_entityId;
    return 1;
}

// @0x14088ff30
CUgcBannerProxy::CUgcBannerProxy()
{
    Clear();
}

// @0x14088ff80
CUgcBannerProxy::~CUgcBannerProxy()
{
}

// @0x14088ffb0
void CUgcBannerProxy::Clear()
{
    m_nBannerId = 0;
}

// @0x14088ffd0
int CUgcBannerProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcBannerProxy* pSrc = static_cast<const CUgcBannerProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nBannerId = pSrc->m_nBannerId;
    return 1;
}

// @0x140890030
void CUgcBannerProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4((unsigned int)m_nBannerId);
}

// @0x140890070
void CUgcBannerProxy::Read(CInPacket& packet)
{
    Clear();
    m_nBannerId = packet.vfunc_o8_4();
}

// @0x1408900d0
CUgcBannerReserve::CUgcBannerReserve()
{
    m_nBannerUid = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_nDate = 0;
    m_nHour = 0;
    m_n30 = 0;
}

// @0x140890150
CUgcBannerReserve::~CUgcBannerReserve()
{
}

// @0x140890180
int CUgcBannerReserve::FUN_140890180() const
{
    unsigned __int64 nReserved = FUN_14088dbf0(m_nDate, m_nHour);
    Unk_DateParts now;
    FUN_14088dfa0(&now, FUN_140869440(), 0);
    if (nReserved < (unsigned __int64)now.m_00)
        return 1;
    return 0;
}

// @0x1408901e0
void CUgcBannerReserve::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_nBannerUid);
    stream.vfunc_o10_3(m_n20);
    stream.vfunc_o10_4((unsigned int)m_n24);
    stream.vfunc_o10_3(m_nDate);
    stream.vfunc_o10_3(m_nHour);
    stream.vfunc_o10_4(m_n30);
}

// @0x1408902a0
void CUgcBannerReserve::Read(CInPacket& packet)
{
    m_nBannerUid = packet.vfunc_o8_4();
    m_n20 = packet.vfunc_o8_3();
    m_n24 = packet.vfunc_o8_4();
    m_nDate = packet.vfunc_o8_3();
    m_nHour = packet.vfunc_o8_3();
    m_n30 = packet.vfunc_o8_4();
}

// @0x1408903c0
unsigned __int64 CUgcBannerReserve::GetKey() const
{
    unsigned __int64 nKey = FUN_14088dbf0(m_nDate, m_nHour);
    return nKey;
}

// @0x140890400
CUgcPreReserve::CUgcPreReserve() : m_reserves(10)
{
    m_nCount = 0;
}

// @0x140890460
CUgcPreReserve::~CUgcPreReserve()
{
    m_reserves.RemoveAll();
}

// @0x1408904b0
void CUgcPreReserve::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4((unsigned int)m_nCount);
    unsigned int nCount = (unsigned int)m_reserves.GetCount();
    stream.vfunc_o10_3(nCount);
    for (POSITION pos = m_reserves.GetHeadPosition(); pos != NULL; m_reserves.GetNext(pos))
    {
        CUgcBannerReservePtr spReserve = m_reserves.GetValueAt(pos);
        if (spReserve.get() != 0)
            spReserve->Write(stream);
    }
}

// @0x1408905b0
void CUgcPreReserve::Read(CInPacket& packet)
{
    m_nCount = packet.vfunc_o8_4();
    unsigned int nCount = packet.vfunc_o8_3();
    for (unsigned int i = 0; i < nCount; ++i)
    {
        CUgcBannerReservePtr spReserve(new CUgcBannerReserve);
        spReserve->Read(packet);
        m_reserves.SetAt(spReserve->GetKey(), spReserve);
    }
}

// @0x140890700
CUgcBannerPost::CUgcBannerPost() : m_reserves(10)
{
    Clear();
}

// @0x140890760
CUgcBannerPost::~CUgcBannerPost()
{
}

// @0x1408907a0
void CUgcBannerPost::Clear()
{
    CUgcBannerProxy::Clear();
    m_reserves.RemoveAll();
}

// @0x1408907d0
int CUgcBannerPost::CopyFrom(const IUgcProxy* pOther)
{
    m_reserves.RemoveAll();
    if (CUgcBannerProxy::CopyFrom(pOther) == 0)
        return 0;
    const CUgcBannerPost* pSrc = static_cast<const CUgcBannerPost*>(pOther);
    if (pSrc == 0)
        return 0;
    for (POSITION pos = pSrc->m_reserves.GetHeadPosition(); pos != NULL; pSrc->m_reserves.GetNext(pos))
    {
        unsigned __int64 nKey = pSrc->m_reserves.GetKeyAt(pos);
        CUgcBannerReservePtr spReserve = pSrc->m_reserves.GetValueAt(pos);
        m_reserves.SetAt(nKey, spReserve);
    }
    return 1;
}

// @0x1408908e0
void CUgcBannerPost::Write(COutputStream& stream) const
{
    CUgcBannerProxy::Write(stream);
    stream.vfunc_o10_1((unsigned char)m_reserves.GetCount());
    for (POSITION pos = m_reserves.GetHeadPosition(); pos != NULL; m_reserves.GetNext(pos))
    {
        CUgcBannerReservePtr pUgcBannerReserve = m_reserves.GetValueAt(pos);
        MS2_ASSERT_AT(0x47b, pUgcBannerReserve);
        pUgcBannerReserve->Write(stream);
    }
}

// @0x1408909f0
void CUgcBannerPost::Read(CInPacket& packet)
{
    Clear();
    CUgcBannerProxy::Read(packet);
    int nCount = packet.vfunc_o8_1();
    for (int i = 0; i < nCount; ++i)
    {
        CUgcBannerReservePtr spReserve(new CUgcBannerReserve);
        if (spReserve.get() != 0)
        {
            spReserve->Read(packet);
            unsigned __int64 nKey = spReserve->GetKey();
            m_reserves.SetAt(nKey, spReserve);
        }
    }
}

// @0x140890bd0
__int64 CUgcBannerPost::FUN_140890bd0()
{
    Unk_BannerPtr banner = CFieldBannerData::GetBanner(m_nBannerId);
    if (banner == 0)
        return 0;
    __int64 nTotal = 0;
    if (banner->m_nAd == 0)
    {
        nTotal = banner->GetCurrentHourly();
    }
    else
    {
        for (POSITION pos = m_reserves.GetHeadPosition(); pos != NULL; m_reserves.GetNext(pos))
        {
            CUgcBannerReservePtr spReserve = m_reserves.GetValueAt(pos);
            if (spReserve.get() != 0)
            {
                CUgcBannerReserve* pReserve = spReserve.operator->();
                __int64 nHourly = banner->GetHourly(pReserve->m_nHour);
                nTotal += nHourly;
            }
        }
    }
    return nTotal;
}

// @0x140890d50
CUgcRegistBanner::CUgcRegistBanner()
{
    Clear();
}

// @0x140890df0
CUgcRegistBanner::~CUgcRegistBanner()
{
    Clear();
}

// @0x140890e80
void CUgcRegistBanner::Clear()
{
    m_nType = 0;
    static_cast<IUgcProxy&>(m_user).Clear();
    static_cast<IUgcProxy&>(m_upload).Clear();
    static_cast<IUgcProxy&>(m_post).Clear();
    m_strUrl = "";
}

// @0x140890f30
void CUgcRegistBanner::Write(COutputStream& stream) const
{
    stream.vfunc_o10_1((unsigned char)m_nType);
    static_cast<const IUgcProxy&>(m_user).Write(stream);
    static_cast<const IUgcProxy&>(m_upload).Write(stream);
    static_cast<const IUgcProxy&>(m_post).Write(stream);
    CStringA strUrl(m_strUrl);
    stream.vfunc_o10_6(strUrl);
}

// @0x140891020
void CUgcRegistBanner::Read(CInPacket& packet)
{
    Unk_1402c45d0 checker;
    m_nType = FUN_140898b80(packet, checker);
    static_cast<IUgcProxy&>(m_user).Read(packet);
    static_cast<IUgcProxy&>(m_upload).Read(packet);
    static_cast<IUgcProxy&>(m_post).Read(packet);
    m_strUrl = packet.vfunc_o8_6();
    if (FUN_14052d220()->FUN_14187f3b0() == 1)
    {
        static_cast<IUgcProxy&>(m_upload).Clear();
        static_cast<IUgcProxy&>(m_post).Clear();
        m_strUrl = "";
    }
}

// @0x1408911f0
int CUgcRegistBanner::FUN_1408911f0(unsigned __int64 nTime)
{
    Unk_BannerPtr banner = CFieldBannerData::GetBanner(m_post.m_nBannerId);
    if (banner.get() != 0 && banner->m_nAd == 0)
        return 0;
    int nResult = 1;
    for (POSITION pos = m_post.m_reserves.GetHeadPosition(); pos != NULL; m_post.m_reserves.GetNext(pos))
    {
        unsigned __int64 nKey = m_post.m_reserves.GetKeyAt(pos);
        if (nKey >= nTime)
        {
            nResult = 0;
            break;
        }
    }
    return nResult;
}

// The banner serial / upload serial pair of a banner upload (no RTTI; two byte-identical copies, 0x140891300 / 0x140891490).
struct Unk_BannerSN
{
    Unk_BannerSN() : m_nBannerSN(0), m_nUploadSN(0) {}
    void Write(COutputStream& stream) const;
    void Read(CInPacket& packet);
    CStringA ToString() const;
    unsigned int m_nBannerSN;
    unsigned __int64 m_nUploadSN;
};
MS2_CHECK_SIZE(Unk_BannerSN, 0x10);

// @0x140891330
void Unk_BannerSN::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_nBannerSN);
    stream.vfunc_o10_4(m_nUploadSN);
}

// @0x140891390
void Unk_BannerSN::Read(CInPacket& packet)
{
    m_nBannerSN = packet.vfunc_o8_4();
    m_nUploadSN = packet.vfunc_o8_4();
}

// @0x140891400
CStringA Unk_BannerSN::ToString() const
{
    CStringA str;
    str.Format("m_bannerSN:%I64d, m_uploadSN:%I64d", m_nBannerSN, m_nUploadSN);
    return str;
}

// The upload serials of a character (no RTTI).
struct Unk_CharUploadSNs
{
    Unk_CharUploadSNs() { m_serials.RemoveAll(); }
    void Write(COutputStream& stream) const;
    void Read(CInPacket& packet);
    CStringW ToString() const;
    ATL::CAtlArray<__int64> m_serials;
    CStringW m_strCharName;
};

// @0x140891670
void Unk_CharUploadSNs::Write(COutputStream& stream) const
{
    stream.vfunc_o10_8(m_strCharName);
    int nCount = (int)m_serials.GetCount();
    stream.vfunc_o10_3(nCount);
    for (int i = 0; i < nCount; ++i)
        stream.vfunc_o10_4(m_serials[i]);
}

// @0x140891730
void Unk_CharUploadSNs::Read(CInPacket& packet)
{
    m_strCharName = packet.vfunc_o8_8();
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
        m_serials.Add(packet.vfunc_o8_4());
}

// @0x140891820
CStringW Unk_CharUploadSNs::ToString() const
{
    CStringW strSerials;
    for (size_t i = 0; i < m_serials.GetCount(); ++i)
        strSerials += FUN_1406c6bd0(L"{0} ", m_serials[i]);
    CStringW strResult;
    strResult = FUN_140656190(L"m_charName={0}, m_uploadSN={1}", m_strCharName, strSerials);
    return strResult;
}

// @0x140891980
CUgcGuildMarkProxy::CUgcGuildMarkProxy()
{
    Clear();
}

// @0x1408919e0
CUgcGuildMarkProxy::~CUgcGuildMarkProxy()
{
    Clear();
}

// @0x140891a40
void CUgcGuildMarkProxy::Clear()
{
    m_nGuildId = 0;
    m_strName.Empty();
}

// @0x140891a80
int CUgcGuildMarkProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcGuildMarkProxy* pSrc = static_cast<const CUgcGuildMarkProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nGuildId = pSrc->m_nGuildId;
    m_strName = pSrc->m_strName;
    return 1;
}

// @0x140891b00
void CUgcGuildMarkProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_nGuildId);
}

// @0x140891b40
void CUgcGuildMarkProxy::Read(CInPacket& packet)
{
    m_nGuildId = packet.vfunc_o8_4();
}

// @0x140891b90
CUgcGuildPosterProxy::CUgcGuildPosterProxy()
{
    Clear();
}

// @0x140891bf0
CUgcGuildPosterProxy::~CUgcGuildPosterProxy()
{
    Clear();
}

// @0x140891c50
void CUgcGuildPosterProxy::Clear()
{
    m_nGuildId = 0;
    m_nIndex = 0;
    m_strName.Empty();
}

// @0x140891c90
int CUgcGuildPosterProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcGuildPosterProxy* pSrc = static_cast<const CUgcGuildPosterProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_nGuildId = pSrc->m_nGuildId;
    m_nIndex = pSrc->m_nIndex;
    m_strName = pSrc->m_strName;
    return 1;
}

// @0x140891d20
void CUgcGuildPosterProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_nGuildId);
    stream.vfunc_o10_3(m_nIndex);
}

// @0x140891d70
void CUgcGuildPosterProxy::Read(CInPacket& packet)
{
    m_nGuildId = packet.vfunc_o8_4();
    m_nIndex = packet.vfunc_o8_3();
}

// @0x140891de0
CUgcBannerEmptyProxy::CUgcBannerEmptyProxy()
{
}

// @0x140891e20
CUgcBannerEmptyProxy::~CUgcBannerEmptyProxy()
{
}

// @0x140891e50
void CUgcBannerEmptyProxy::Clear()
{
}

// @0x140891e60
int CUgcBannerEmptyProxy::CopyFrom(const IUgcProxy* pOther)
{
    return 1;
}

// @0x140891e80
void CUgcBannerEmptyProxy::Write(COutputStream& stream) const
{
}

// @0x140891ea0
void CUgcBannerEmptyProxy::Read(CInPacket& packet)
{
}

// @0x140891ec0
CUgcBannerRollingImageProxy::CUgcBannerRollingImageProxy()
{
}

// @0x140891f10
CUgcBannerRollingImageProxy::~CUgcBannerRollingImageProxy()
{
}

// @0x140891f50
void CUgcBannerRollingImageProxy::Clear()
{
    m_images.clear();
}

// @0x140891f80
int CUgcBannerRollingImageProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcBannerRollingImageProxy* pSrc = static_cast<const CUgcBannerRollingImageProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_images = pSrc->m_images;
    return 1;
}

// @0x140891ff0
void CUgcBannerRollingImageProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_2((short)m_images.size());
    for (size_t i = 0; i < m_images.size(); ++i)
        stream.vfunc_o10_4(m_images[i]);
}

// @0x1408920a0
void CUgcBannerRollingImageProxy::Read(CInPacket& packet)
{
    unsigned int nCount = (unsigned short)packet.vfunc_o8_2();
    m_images.clear();
    m_images.reserve(nCount);
    for (size_t i = 0; i < nCount; ++i)
    {
        unsigned int nImage = packet.vfunc_o8_4();
        m_images.push_back(nImage);
    }
}

// @0x140892170
CUgcShopBannerProxy::CUgcShopBannerProxy()
{
    Clear();
}

// @0x1408921e0
CUgcShopBannerProxy::~CUgcShopBannerProxy()
{
    Clear();
}

// @0x140892250
void CUgcShopBannerProxy::Clear()
{
    m_strKey.Empty();
}

// @0x140892280
int CUgcShopBannerProxy::CopyFrom(const IUgcProxy* pOther)
{
    Clear();
    if (pOther == 0)
        return 0;
    const CUgcShopBannerProxy* pSrc = static_cast<const CUgcShopBannerProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_strKey = pSrc->m_strKey;
    m_strEntity = pSrc->m_strEntity;
    return 1;
}

// @0x140892310
void CUgcShopBannerProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_6(m_strKey);
}

// @0x140892350
void CUgcShopBannerProxy::Read(CInPacket& packet)
{
    m_strKey = packet.vfunc_o8_6();
}

// @0x1408923d0
CBlueprintItemData::CBlueprintItemData()
{
    Clear();
}

// @0x140892430
CBlueprintItemData::~CBlueprintItemData()
{
}

// @0x140892470
void CBlueprintItemData::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_n28 = 0;
    m_n30 = 0;
    m_n38 = 0;
    m_n40 = 0;
    m_n48 = 0;
    m_strName = L"";
}

// @0x140892510
void CBlueprintItemData::CopyFrom(const CBlueprintItemData& other)
{
    m_n18 = other.m_n18;
    m_n20 = other.m_n20;
    m_n24 = other.m_n24;
    m_n28 = other.m_n28;
    m_n30 = other.m_n30;
    m_n38 = other.m_n38;
    m_n40 = other.m_n40;
    m_n48 = other.m_n48;
    m_strName = other.m_strName;
}

// @0x1408925d0
void CBlueprintItemData::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_n18);
    stream.vfunc_o10_3(m_n20);
    stream.vfunc_o10_3(m_n24);
    stream.vfunc_o10_3(m_n28);
    stream.vfunc_o10_4(m_n30);
    stream.vfunc_o10_3(m_n38);
    stream.vfunc_o10_4(m_n40);
    stream.vfunc_o10_4(m_n48);
    stream.vfunc_o10_8(m_strName);
}

// @0x1408926e0
void CBlueprintItemData::Read(CInputStream& stream)
{
    m_n18 = stream.vfunc_o8_4();
    m_n20 = stream.vfunc_o8_3();
    m_n24 = stream.vfunc_o8_3();
    m_n28 = stream.vfunc_o8_3();
    m_n30 = stream.vfunc_o8_4();
    m_n38 = stream.vfunc_o8_3();
    m_n40 = stream.vfunc_o8_4();
    m_n48 = stream.vfunc_o8_4();
    m_strName = stream.vfunc_o8_8();
}

// @0x140892810
CUgcBlueprintImageProxy::CUgcBlueprintImageProxy()
{
    Clear();
}

// @0x140892870
CUgcBlueprintImageProxy::~CUgcBlueprintImageProxy()
{
    Clear();
}

// @0x1408928d0
void CUgcBlueprintImageProxy::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n28 = 0;
    m_strName = L"";
}

// @0x140892930
int CUgcBlueprintImageProxy::CopyFrom(const IUgcProxy* pOther)
{
    if (pOther == 0)
        return 0;
    const CUgcBlueprintImageProxy* pSrc = static_cast<const CUgcBlueprintImageProxy*>(pOther);
    if (pSrc == 0)
        return 0;
    m_n18 = pSrc->m_n18;
    m_n20 = pSrc->m_n20;
    m_n28 = pSrc->m_n28;
    m_strName = pSrc->m_strName;
    return 1;
}

// @0x1408929c0
void CUgcBlueprintImageProxy::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_n18);
    stream.vfunc_o10_4(m_n20);
    stream.vfunc_o10_3(m_n28);
    stream.vfunc_o10_8(m_strName);
}

// @0x140892a50
void CUgcBlueprintImageProxy::Read(CInPacket& packet)
{
    m_n18 = packet.vfunc_o8_4();
    m_n20 = packet.vfunc_o8_4();
    m_n28 = packet.vfunc_o8_3();
    m_strName = packet.vfunc_o8_8();
}

// @0x140892b50
CUgcItemLook::CUgcItemLook()
{
    Clear();
}

// @0x140892bf0
CUgcItemLook::~CUgcItemLook()
{
}

// @0x140892c70
void CUgcItemLook::Clear()
{
    m_n18 = 0;
    m_str20 = "";
    m_str28 = L"";
    m_n30 = 0;
    m_n34 = 0;
    m_n38 = 0;
    m_n40 = 0;
    m_str48 = L"";
    m_n50 = 0;
    m_strUrl = "";
    m_n60 = 0;
}

// @0x140892d40
void CUgcItemLook::SetDefault()
{
    m_n18 = 1;
    m_n30 = 0;
    m_str28 = "";
    m_strUrl = "";
}

// @0x140892da0
void CUgcItemLook::CopyFrom(const CUgcItemLook* pOther)
{
    Clear();
    if (pOther == 0)
        return;
    m_n18 = pOther->m_n18;
    m_str20 = pOther->m_str20;
    m_str28 = pOther->m_str28;
    m_n30 = pOther->m_n30;
    m_n34 = pOther->m_n34;
    m_n38 = pOther->m_n38;
    m_n40 = pOther->m_n40;
    m_str48 = pOther->m_str48;
    m_n50 = pOther->m_n50;
    m_strUrl = pOther->m_strUrl;
    m_n60 = pOther->m_n60;
}

// @0x140892ec0
CStringA CUgcItemLook::GetLocalPath() const
{
    CStringA strResult("");
    if (m_n30 != 0)
    {
        if (m_strUrl.Find("item/", 0) >= 0)
            strResult = FUN_1410280d0(0xc9, m_strUrl);
        else if (m_strUrl.Find("blueprint/", 0) >= 0)
            strResult = FUN_1410280d0(0xd1, m_strUrl);
    }
    return strResult;
}

// @0x140893070
void CUgcItemLook::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_n18);
    stream.vfunc_o10_6(m_str20);
    stream.vfunc_o10_8(m_str28);
    stream.vfunc_o10_1((unsigned char)m_n30);
    stream.vfunc_o10_3(m_n34);
    stream.vfunc_o10_4(m_n38);
    stream.vfunc_o10_4(m_n40);
    stream.vfunc_o10_8(m_str48);
    stream.vfunc_o10_4(m_n50);
    if (m_n60 == 1)
    {
        {
            CStringA strEmpty("");
            stream.vfunc_o10_6(strEmpty);
        }
        stream.vfunc_o10_1((unsigned char)m_n60);
    }
    else
    {
        CStringA strUrl(m_strUrl);
        unsigned char nFlag = (unsigned char)m_n60;
        stream.vfunc_o10_6(strUrl);
        stream.vfunc_o10_1(nFlag);
    }
}

// @0x140893250
void CUgcItemLook::Read(CInputStream& stream)
{
    Clear();
    m_n18 = stream.vfunc_o8_4();
    m_str20 = stream.vfunc_o8_6();
    m_str28 = stream.vfunc_o8_8();
    m_n30 = stream.vfunc_o8_1();
    m_n34 = stream.vfunc_o8_3();
    m_n38 = stream.vfunc_o8_4();
    m_n40 = stream.vfunc_o8_4();
    m_str48 = stream.vfunc_o8_8();
    m_n50 = stream.vfunc_o8_4();
    m_strUrl = stream.vfunc_o8_6();
    m_n60 = stream.vfunc_o8_1();
    if (FUN_14052d220()->FUN_14187f3b0() == 1)
        m_strUrl = "";
}

// @0x1408934f0
int CUgcItemLook::FUN_1408934f0() const
{
    if (m_n18 == 1 || m_n60 == 1)
        return 1;
    return 0;
}

// @0x140893520
int CUgcItemLook::FUN_140893520() const
{
    if (m_n60 == 2)
        return 1;
    return 0;
}

// @0x140893540
bool CUgcItemLook::FUN_140893540() const
{
    if (FUN_1408934f0() != 0)
        return false;
    if ((unsigned __int64)m_n18 <= 1)
        return false;
    if (m_n30 == 0)
        return false;
    return true;
}

// @0x140893590
CUgcUpload::CUgcUpload()
{
    Clear();
}

// @0x140893600
CUgcUpload::~CUgcUpload()
{
    Clear();
}

// @0x140893670
void CUgcUpload::Clear()
{
    m_nKind = 0;
    m_n1c = 2;
    static_cast<IUgcProxy&>(m_user).Clear();
    static_cast<IUgcProxy&>(m_upload).Clear();
}

// MS2-FUNCTIONAL: codegen differs (temp/branch layout)
// @0x1408936e0
bool CUgcUpload::CopyFrom(const CUgcUpload* pOther)
{
    Clear();
    if (pOther != 0)
    {
        m_nKind = pOther->m_nKind;
        static_cast<IUgcProxy&>(m_user).CopyFrom(&pOther->m_user);
        static_cast<IUgcProxy&>(m_upload).CopyFrom(&pOther->m_upload);
    }
    return pOther != 0;
}

// @0x140893780
void CUgcUpload::Write(COutputStream& stream) const
{
    stream.vfunc_o10_1((unsigned char)m_nKind);
    stream.vfunc_o10_2((short)m_n1c);
    static_cast<const IUgcProxy&>(m_user).Write(stream);
    static_cast<const IUgcProxy&>(m_upload).Write(stream);
}

// @0x140893820
void CUgcUpload::Read(CInPacket& packet)
{
    Unk_1402c45d0 checker;
    m_nKind = FUN_140898b80(packet, checker);
    m_n1c = (unsigned short)packet.vfunc_o8_2();
    static_cast<IUgcProxy&>(m_user).Read(packet);
    static_cast<IUgcProxy&>(m_upload).Read(packet);
}

// @0x1408938d0
CUgcItemMusicNote::CUgcItemMusicNote()
{
    Clear();
}

// @0x140893970
CUgcItemMusicNote::~CUgcItemMusicNote()
{
}

// @0x1408939f0
void CUgcItemMusicNote::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n24 = 0;
    m_str28.Empty();
    m_str30.Empty();
    m_str38.Empty();
    m_info.m_n00 = 0;
    m_info.m_n08 = 0;
    m_info.m_n10 = 0;
    m_info.m_str18.Empty();
}

// @0x140893aa0
void CUgcItemMusicNote::CopyFrom(const CUgcItemMusicNote* pOther)
{
    Clear();
    if (pOther == 0)
        return;
    m_n18 = pOther->m_n18;
    m_n20 = pOther->m_n20;
    m_n24 = pOther->m_n24;
    m_str28 = pOther->m_str28;
    m_str30 = pOther->m_str30;
    m_str38 = pOther->m_str38;
    m_info.m_n00 = pOther->m_info.m_n00;
    m_info.m_n08 = pOther->m_info.m_n08;
    m_info.m_n10 = pOther->m_info.m_n10;
    m_info.m_str18 = pOther->m_info.m_str18;
}

// MS2-FUNCTIONAL: early-return layout differs
// @0x140893bb0
void CUgcItemMusicNote::FUN_140893bb0(const void* pSource, __int64 nId)
{
    Clear();
    const Unk_MusicSrcView* pSrc = (const Unk_MusicSrcView*)pSource;
    if (pSrc == 0)
        return;
    m_n18 = nId;
    m_n20 = pSrc->m_n18;
    m_n24 = pSrc->m_n1c;
    m_str28 = pSrc->m_str20;
    m_str30 = pSrc->m_str28;
    m_str38 = pSrc->m_str30;
    m_info.m_n00 = pSrc->m_n50;
    m_info.m_n08 = pSrc->m_n58;
    m_info.m_n10 = pSrc->m_n60;
    m_info.m_str18 = pSrc->m_str68;
}

// @0x140893cc0
void CUgcItemMusicNote::Write(COutputStream& stream) const
{
    stream.vfunc_o10_4(m_n18);
    stream.vfunc_o10_3(m_n20);
    stream.vfunc_o10_3(m_n24);
    stream.vfunc_o10_8(m_str28);
    stream.vfunc_o10_8(m_str30);
    stream.vfunc_o10_7(m_str38);
    stream.vfunc_o10_3(m_info.m_n00);
    stream.vfunc_o10_4(m_info.m_n08);
    stream.vfunc_o10_4(m_info.m_n10);
    stream.vfunc_o10_8(m_info.m_str18);
}

// @0x140893e10
void CUgcItemMusicNote::Read(CInputStream& stream)
{
    Clear();
    m_n18 = stream.vfunc_o8_4();
    m_n20 = stream.vfunc_o8_3();
    m_n24 = stream.vfunc_o8_3();
    m_str28 = stream.vfunc_o8_8();
    m_str30 = stream.vfunc_o8_8();
    m_str38 = stream.vfunc_o8_7();
    m_info.m_n00 = stream.vfunc_o8_3();
    m_info.m_n08 = stream.vfunc_o8_4();
    m_info.m_n10 = stream.vfunc_o8_4();
    m_info.m_str18 = stream.vfunc_o8_8();
}

// MS2-FUNCTIONAL: MS2Ptr dtor unwind offsets differ
// @0x140894060
CStringA CUgcItemMusicNote::FUN_140894060() const
{
    MS2Ptr<Unk_MusicBookInfo> spInfo = FUN_14052d1d0()->FUN_14072cc10(m_n24);
    if ((Unk_MusicBookInfo*)spInfo == 0)
        return CStringA("");
    return CStringA(spInfo->m_str28);
}

// @0x140894120
CUgcMarketSchCond::CUgcMarketSchCond()
{
    Clear();
}

// @0x140894180
CUgcMarketSchCond::CUgcMarketSchCond(CInPacket& packet)
{
    Read(packet);
}

// @0x1408941f0
CUgcMarketSchCond::~CUgcMarketSchCond()
{
    Clear();
}

// @0x140894250
void CUgcMarketSchCond::Clear()
{
    m_n18 = 0;
    m_n1c = 2;
    m_n20 = 0;
    m_str28 = "";
    m_n30 = 0;
    m_n34 = 0;
}

// @0x1408942c0
void CUgcMarketSchCond::CopyFrom(const CUgcMarketSchCond* pOther)
{
    Clear();
    if (pOther == 0)
        return;
    m_n18 = pOther->m_n18;
    m_n1c = pOther->m_n1c;
    m_n20 = pOther->m_n20;
    m_str28 = pOther->m_str28;
    m_n30 = pOther->m_n30;
    m_n34 = pOther->m_n34;
}

// @0x140894360
void CUgcMarketSchCond::Write(COutputStream& stream) const
{
    stream.vfunc_o10_3(m_n18);
    stream.vfunc_o10_1((unsigned char)m_n1c);
    stream.vfunc_o10_1((unsigned char)m_n20);
    stream.vfunc_o10_8(m_str28);
    stream.vfunc_o10_3(m_n30);
    stream.vfunc_o10_1((unsigned char)m_n34);
}

// @0x140894420
void CUgcMarketSchCond::Read(CInPacket& packet)
{
    Clear();
    m_n18 = packet.vfunc_o8_3();
    m_n1c = packet.vfunc_o8_1();
    m_n20 = packet.vfunc_o8_1();
    m_str28 = packet.vfunc_o8_8();
    m_n30 = packet.vfunc_o8_3();
    m_n34 = packet.vfunc_o8_1();
}

// @0x1408945c0
void CUgcMarketSchCond::WriteShort(COutputStream& stream) const
{
    stream.vfunc_o10_3(m_n18);
    stream.vfunc_o10_1((unsigned char)m_n1c);
    stream.vfunc_o10_1((unsigned char)m_n20);
    stream.vfunc_o10_8(m_str28);
    stream.vfunc_o10_3(m_n30);
}

// @0x140894670
void CUgcMarketSchCond::ReadShort(CInputStream& stream)
{
    Clear();
    m_n18 = stream.vfunc_o8_3();
    m_n1c = stream.vfunc_o8_1();
    m_n20 = stream.vfunc_o8_1();
    m_str28 = stream.vfunc_o8_8();
    m_n30 = stream.vfunc_o8_3();
}

// MS2-FUNCTIONAL: result materialisation differs
// @0x140894750
int CUgcMarketSchCond::FUN_140894750() const
{
    int nPage;
    if (m_n30 == 0)
        nPage = -1;
    else
        nPage = (m_n30 - 1) / 10;
    return nPage;
}

// MS2-FUNCTIONAL: result materialisation differs
// @0x1408947a0
int CUgcMarketSchCond::FUN_1408947a0() const
{
    int nPage = FUN_140894750();
    if (nPage == -1)
        nPage = 0;
    else
        nPage = nPage * 0x78 + 1;
    return nPage;
}

// MS2-FUNCTIONAL: result materialisation differs
// @0x1408947f0
int CUgcMarketSchCond::FUN_1408947f0() const
{
    int nPage = FUN_140894750();
    if (nPage == -1)
        nPage = 0;
    else
        nPage = (nPage + 1) * 0x78;
    return nPage;
}

// MS2-FUNCTIONAL: multiplier local layout differs
// @0x140894840
int CUgcMarketSchCond::FUN_140894840() const
{
    int n;
    if (m_n30 == 0)
        n = -1;
    else
        n = ((m_n30 - 1) / 0x32 + 1) * 600;
    return n;
}

// @0x1408948a0
CStringA CUgcMarketSchCond::FUN_1408948a0() const
{
    if (m_n20 < 0 || m_n20 >= 6)
        return CStringA("");
    CStringA strName(s_orderNames[m_n20]);
    return strName;
}

// @0x140894960
int CUgcMarketSchCond::FUN_140894960() const
{
    int nValue = 0;
    nValue = m_n18;
    return nValue;
}

// @0x140894990
int CUgcMarketSchCond::FUN_140894990() const
{
    int nResult = 0;
    switch (m_n18)
    {
    case 100:
        nResult = 199;
        break;
    case 200:
        nResult = 299;
        break;
    case 300:
        nResult = 399;
        break;
    case 400:
        nResult = 499;
        break;
    default:
        nResult = m_n18;
        break;
    }
    return nResult;
}

// MS2-FUNCTIONAL: compare operand load order differs
// @0x140894a10
int CUgcMarketSchCond::FUN_140894a10(const CUgcMarketSchCond* pOther) const
{
    if (pOther == 0)
        return 0;
    if (pOther->m_n18 != m_n18)
        return 0;
    if (pOther->m_n1c != m_n1c)
        return 0;
    if (pOther->m_n20 != m_n20)
        return 0;
    if (FUN_140164830(pOther->m_str28, m_str28))
        return 0;
    int nFirst = pOther->FUN_140894840();
    if (nFirst > pOther->FUN_140894840())
        return 0;
    return 1;
}

// @0x140894ad0
CUgcMarketProduct::CUgcMarketProduct()
{
    Clear();
}

// @0x140894bc0
CUgcMarketProduct::~CUgcMarketProduct()
{
    Clear();
}

// @0x140894cb0
void CUgcMarketProduct::Clear()
{
    m_n18 = 0;
    m_n20 = 0;
    m_n28 = 0;
    m_n2c = 0;
    m_n30 = 0;
    m_n34 = 3;
    m_n38 = 0;
    m_n50 = 0;
    m_n3c = 0;
    m_n40 = 0;
    m_n44 = 0;
    m_n48 = 0;
    m_n58 = 0;
    m_n60 = 0;
    m_n68 = 0;
    m_n70 = 0;
    m_n80 = 0;
    m_n88 = 0;
    m_n78 = 0;
    static_cast<IUgcProxy&>(m_user).Clear();
    m_str200 = "";
    m_str208 = "";
    m_str210 = "";
    m_look.Clear();
    m_music.Clear();
    m_blueprint.Clear();
    m_n1f0 = 0;
    m_n1f4 = 0;
    m_n1f8 = 1;
}

// @0x140894ea0
void CUgcMarketProduct::CopyFrom(const CUgcMarketProduct* pOther)
{
    if (pOther == 0)
        return;
    m_n18 = pOther->m_n18;
    m_n20 = pOther->m_n20;
    m_n28 = pOther->m_n28;
    m_n2c = pOther->m_n2c;
    m_n30 = pOther->m_n30;
    m_n34 = pOther->m_n34;
    m_n38 = pOther->m_n38;
    m_n50 = pOther->m_n50;
    m_n3c = pOther->m_n3c;
    m_n40 = pOther->m_n40;
    m_n44 = pOther->m_n44;
    m_n48 = pOther->m_n48;
    m_n58 = pOther->m_n58;
    m_n60 = pOther->m_n60;
    m_n68 = pOther->m_n68;
    m_n70 = pOther->m_n70;
    m_n80 = pOther->m_n80;
    m_n88 = pOther->m_n88;
    m_n78 = pOther->m_n78;
    static_cast<IUgcProxy&>(m_user).CopyFrom(&pOther->m_user);
    SetStr200(CStringW(pOther->m_str200));
    SetStr208(CStringW(pOther->m_str208));
    SetStr210(CStringW(pOther->m_str210));
    m_look.CopyFrom(&pOther->m_look);
    m_music.CopyFrom(&pOther->m_music);
    m_blueprint.CopyFrom(pOther->m_blueprint);
    m_n1f4 = pOther->m_n1f4;
    m_n1f8 = pOther->m_n1f8;
}

// @0x140895230
void CUgcMarketProduct::Write(COutputStream& stream) const
{
    stream.vfunc_o10_3(m_n18);
    stream.vfunc_o10_4(m_n20);
    stream.vfunc_o10_1((unsigned char)m_n28);
    stream.vfunc_o10_3(m_n2c);
    stream.vfunc_o10_3(m_n30);
    stream.vfunc_o10_1((unsigned char)m_n34);
    stream.vfunc_o10_3(m_n38);
    stream.vfunc_o10_4(m_n50);
    stream.vfunc_o10_3(m_n3c);
    stream.vfunc_o10_3(m_n40);
    stream.vfunc_o10_3(m_n44);
    stream.vfunc_o10_3(m_n48);
    stream.vfunc_o10_4(m_n58);
    stream.vfunc_o10_4(m_n60);
    stream.vfunc_o10_4(m_n68);
    stream.vfunc_o10_3(m_n70);
    stream.vfunc_o10_4(m_n80);
    stream.vfunc_o10_4(m_n88);
    stream.vfunc_o10_4(m_n78);
    m_user.Write(stream);
    stream.vfunc_o10_8(const_cast<CUgcMarketProduct*>(this)->GetStr200());
    stream.vfunc_o10_8(const_cast<CUgcMarketProduct*>(this)->GetStr208());
    stream.vfunc_o10_8(const_cast<CUgcMarketProduct*>(this)->GetStr210());
    m_look.Write(stream);
    m_music.Write(stream);
    m_blueprint.Write(stream);
    stream.vfunc_o10_1((unsigned char)m_n1f4);
}

// @0x140895670
void CUgcMarketProduct::Read(CInPacket& packet)
{
    m_n18 = packet.vfunc_o8_3();
    m_n20 = packet.vfunc_o8_4();
    m_n28 = packet.vfunc_o8_1();
    m_n2c = packet.vfunc_o8_3();
    m_n30 = packet.vfunc_o8_3();
    m_n34 = packet.vfunc_o8_1();
    m_n38 = packet.vfunc_o8_3();
    m_n50 = packet.vfunc_o8_4();
    m_n3c = packet.vfunc_o8_3();
    m_n40 = packet.vfunc_o8_3();
    m_n44 = packet.vfunc_o8_3();
    m_n48 = packet.vfunc_o8_3();
    m_n58 = packet.vfunc_o8_4();
    m_n60 = packet.vfunc_o8_4();
    m_n68 = packet.vfunc_o8_4();
    m_n70 = packet.vfunc_o8_3();
    m_n80 = packet.vfunc_o8_4();
    m_n88 = packet.vfunc_o8_4();
    m_n78 = packet.vfunc_o8_4();
    m_user.Read(packet);
    CStringW strValue;
    strValue = packet.vfunc_o8_8();
    SetStr200(CStringW(strValue));
    strValue = packet.vfunc_o8_8();
    SetStr208(CStringW(strValue));
    strValue = packet.vfunc_o8_8();
    SetStr210(CStringW(strValue));
    m_look.Read(packet);
    m_music.Read(packet);
    m_blueprint.Read(packet);
    m_n1f4 = packet.vfunc_o8_1();
    m_n1f8 = FUN_1406a5390(m_n2c);
}

// @0x140895dd0
CStringW CUgcMarketProduct::GetStr200()
{
    Unk_UgcLock lock(m_lock, 1);
    return CStringW(m_str200);
}

// @0x140895e50
void CUgcMarketProduct::SetStr200(CStringW str)
{
    Unk_UgcLock lock(m_lock, 1);
    m_str200 = str;
}

// @0x140895ed0
CStringW CUgcMarketProduct::GetStr200Head()
{
    CStringW str = GetStr200();
    int nPos = str.ReverseFind(L',');
    if (nPos != -1)
    {
        int nLen = str.GetLength();
        int nCount;
        if (nLen - nPos < 0)
            nCount = 0;
        else
            nCount = nLen - nPos;
        str.Delete(nPos, nCount);
    }
    return CStringW(str);
}

// @0x140895fa0
CStringW CUgcMarketProduct::GetStr208()
{
    Unk_UgcLock lock(m_lock, 1);
    return CStringW(m_str208);
}

// @0x140896020
void CUgcMarketProduct::SetStr208(CStringW str)
{
    Unk_UgcLock lock(m_lock, 1);
    m_str208 = str;
}

// @0x1408960a0
CStringW CUgcMarketProduct::GetStr210()
{
    Unk_UgcLock lock(m_lock, 1);
    return CStringW(m_str210);
}

// @0x140896120
void CUgcMarketProduct::SetStr210(CStringW str)
{
    Unk_UgcLock lock(m_lock, 1);
    m_str210 = str;
}

// @0x1408961a0
int CUgcMarketProduct::FUN_1408961a0() const
{
    if (m_n88 > 0 && m_n88 > FUN_140869440())
        return 1;
    return 0;
}

// @0x1408961e0
int CUgcMarketProduct::FUN_1408961e0() const
{
    __int64 nNow = FUN_140869440();
    if (nNow < m_n58 || nNow > m_n68)
        return 0;
    return 1;
}

// @0x140896230
bool CUgcMarketProduct::FUN_140896230(Unk_CommonOwner& owner)
{
    if (owner.id == 0)
        return false;
    if (FUN_140896310() != 0)
    {
        if (owner.Matches(m_music.m_info.m_n00, m_music.m_info.m_n08))
            return true;
    }
    else if (FUN_140896350() != 0)
    {
        if (owner.Matches(m_blueprint.m_n38, m_blueprint.m_n40))
            return true;
    }
    else
    {
        if (owner.Matches(m_look.m_n34, m_look.m_n38))
            return true;
    }
    return false;
}

// @0x140896310
int CUgcMarketProduct::FUN_140896310() const
{
    int nLast = 499;
    if (m_n30 >= 400 && m_n30 <= nLast)
        return 1;
    return 0;
}

// @0x140896350
int CUgcMarketProduct::FUN_140896350() const
{
    MS2Ptr<CItemData> spData = FUN_14053f870(m_n2c);
    if ((bool)spData.get() && spData->FUN_14053d900())
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: the result goes through an int local in the exe
// @0x1408963f0
bool CUgcMarketProduct::FUN_1408963f0(Unk_CommonOwner& owner)
{
    if (!FUN_140896230(owner) && FUN_1406a5800())
        return true;
    return false;
}
