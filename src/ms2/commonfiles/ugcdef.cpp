// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The UGC proxy records (users, uploads, items, banners, guild
// marks / posters, blueprint images, market listings, bookmarks) and the MS2Ptr / container glue over them.
// MS2-UNIT: commonfiles\ugcdef.cpp
// MS2-RANGE: 0x14088e340-0x14089e270 .text$mn
// MS2-PIN: ??1IUgcProxy@@UEAA@XZ 0x1408999a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\ugcdef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcdef.h"
#include "stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

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
