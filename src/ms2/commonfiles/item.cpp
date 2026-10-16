// MS2-UNIT: commonfiles\item.cpp
// MS2-RANGE: 0x140523790-0x140530640 .text$mn
// MS2-RANGE: 0x1400b9290-0x1400b9410 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\item.cpp"
// item.cpp - CItem (commonfiles\item.cpp; the wassert path is e:\build\kr\22_04\ms2code\commonfiles\item.cpp).
// Partial: the plain scalar field accessors. The constructor, serializer and smart-pointer slot helpers are not
// recovered yet (their pointee types and the COMDAT glue are still open).
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/item.h"
#include "ms2/ms2recover.h"
#define MS2_ASSERT_MSG_AT(line, msg, cond) (void)((!!(cond)) || (_wassert(msg, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))

// @0x14052a020
int CItem::FUN_14052a020()
{
    return m_20;
}

// @0x14052a040
void CItem::FUN_14052a040(int v)
{
    m_20 = v;
}

// @0x14052a150
int CItem::FUN_14052a150()
{
    return m_24;
}

// @0x14052a130
void CItem::FUN_14052a130(int v)
{
    m_24 = v;
}

// @0x1405268f0
int CItem::FUN_1405268f0()
{
    return m_2c;
}

// @0x1405268d0
void CItem::FUN_1405268d0(int v)
{
    m_2c = v;
}

// @0x140526930
unsigned char CItem::FUN_140526930()
{
    return m_30;
}

// @0x140526910
void CItem::FUN_140526910(unsigned char v)
{
    m_30 = v;
}

// @0x140526a10
int CItem::FUN_140526a10()
{
    return m_34;
}

// @0x140526a30
void CItem::FUN_140526a30(int v)
{
    m_34 = v;
}

// @0x140526970
int CItem::FUN_140526970()
{
    return m_38;
}

// @0x1405269b0
int CItem::FUN_1405269b0()
{
    return m_3c;
}

// @0x140526990
void CItem::FUN_140526990(int v)
{
    m_3c = v;
}

// @0x140526a50
__int64 CItem::FUN_140526a50()
{
    return m_40;
}

// @0x140526a70
void CItem::FUN_140526a70(__int64 v)
{
    m_40 = v;
}

// @0x140526a90
__int64 CItem::FUN_140526a90()
{
    return m_48;
}

// @0x140526ab0
void CItem::FUN_140526ab0(__int64 v)
{
    m_48 = v;
}

// @0x140526ad0
__int64 CItem::FUN_140526ad0()
{
    return m_50;
}

// @0x140526af0
void CItem::FUN_140526af0(__int64 v)
{
    m_50 = v;
}

// @0x140526b10
int CItem::FUN_140526b10()
{
    return m_58;
}

// @0x140526b30
void CItem::FUN_140526b30(int v)
{
    m_58 = v;
}

// @0x140526b50
int CItem::FUN_140526b50()
{
    return m_5c;
}

// @0x140526b70
void CItem::FUN_140526b70(int v)
{
    m_5c = v;
}

// @0x140526b90
int CItem::FUN_140526b90()
{
    return m_60;
}

// @0x140526bd0
int CItem::FUN_140526bd0()
{
    return m_64;
}

// @0x140526bf0
void CItem::FUN_140526bf0(int v)
{
    m_64 = v;
}

// @0x140526c30
int CItem::FUN_140526c30()
{
    return m_68;
}

// @0x140526c10
void CItem::FUN_140526c10(int v)
{
    m_68 = v;
}

// @0x140526c50
int CItem::FUN_140526c50()
{
    return m_6c;
}

// @0x140526e40
int CItem::FUN_140526e40()
{
    return m_70;
}

// @0x140528910
__int64 CItem::FUN_140528910()
{
    return m_80;
}

// @0x1405288e0
void CItem::FUN_1405288e0(__int64 v)
{
    m_80 = v;
}

// @0x140528a90
__int64 CItem::FUN_140528a90()
{
    return m_88;
}

// @0x140528a60
void CItem::FUN_140528a60(__int64 v)
{
    m_88 = v;
}

// @0x140528ae0
__int64 CItem::FUN_140528ae0()
{
    return m_90;
}

// @0x140528ab0
void CItem::FUN_140528ab0(__int64 v)
{
    m_90 = v;
}

// @0x140529260
int CItem::FUN_140529260()
{
    return m_98;
}

// @0x140527300
int CItem::FUN_140527300()
{
    return m_9c;
}

// @0x1405272e0
void CItem::FUN_1405272e0(int v)
{
    m_9c = v;
}

// @0x140527340
int CItem::FUN_140527340()
{
    return m_a0;
}

// @0x140527320
void CItem::FUN_140527320(int v)
{
    m_a0 = v;
}

// @0x140528ca0
int CItem::FUN_140528ca0()
{
    return m_a4;
}

// @0x140528c80
void CItem::FUN_140528c80(int v)
{
    m_a4 = v;
}

// @0x140528e00
__int64 CItem::FUN_140528e00()
{
    return m_a8;
}

// @0x140528dd0
void CItem::FUN_140528dd0(__int64 v)
{
    m_a8 = v;
}

// @0x140529070
int CItem::FUN_140529070()
{
    return m_b0;
}

// @0x140529090
int CItem::FUN_140529090()
{
    return m_b4;
}

// @0x140528b90
__int64 CItem::FUN_140528b90()
{
    return m_c0;
}

// @0x140528b60
void CItem::FUN_140528b60(__int64 v)
{
    m_c0 = v;
}

// @0x140528bd0
int CItem::FUN_140528bd0()
{
    return m_c8;
}

// @0x140528bb0
void CItem::FUN_140528bb0(int v)
{
    m_c8 = v;
}

// @0x140528c20
unsigned short CItem::FUN_140528c20()
{
    return m_cc;
}

// @0x140528bf0
void CItem::FUN_140528bf0(unsigned short v)
{
    m_cc = v;
}

// @0x140528c60
int CItem::FUN_140528c60()
{
    return m_d0;
}

// @0x140528c40
void CItem::FUN_140528c40(int v)
{
    m_d0 = v;
}

// @0x140529620
unsigned char CItem::FUN_140529620()
{
    return m_d4;
}

// @0x1405292a0
int CItem::FUN_1405292a0()
{
    return m_d8;
}

// @0x140529280
void CItem::FUN_140529280(int v)
{
    m_d8 = v;
}

// @0x140529640
int CItem::FUN_140529640()
{
    return m_dc;
}

// @0x140529660
void CItem::FUN_140529660(int v)
{
    m_dc = v;
}

// @0x1405269f0
unsigned char CItem::FUN_1405269f0()
{
    return m_198;
}

// @0x1405269d0
void CItem::FUN_1405269d0(unsigned char v)
{
    m_198 = v;
}

// @0x1405291f0
int CItem::FUN_1405291f0()
{
    return m_19c;
}

// @0x140525640
int CItem::FUN_140525640()
{
    return m_spData->FUN_14053cc40();
}

// @0x140525870
int CItem::FUN_140525870()
{
    return m_spData->FUN_14053d150();
}

// @0x140525ca0
int CItem::FUN_140525ca0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053ce20();
}

// @0x140525db0
int CItem::FUN_140525db0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053d1f0();
}

// @0x140525e00
int CItem::FUN_140525e00()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053d210();
}

// @0x140525e50
int CItem::FUN_140525e50(int nGender, int nCategory)
{
    if (!m_spData->FUN_14053cae0(nGender, nCategory))
        return 0;
    return FUN_140525eb0(nGender, nCategory);
}

// @0x140525eb0
int CItem::FUN_140525eb0(int nGender, int nB)
{
    if (m_spData.get() == 0)
        return 0;
    return m_spData->FUN_14053c9e0(nGender, nB);
}

// @0x140526010
int CItem::FUN_140526010()
{
    if (m_spData.get() == 0)
        return 0;
    return m_spData->FUN_14053d900();
}

// @0x140526100
int CItem::FUN_140526100()
{
    if (m_spData == 0)
        return 0;
    return m_spData->FUN_14053d8c0();
}

// @0x1405262c0
int CItem::FUN_1405262c0()
{
    if (m_spData == 0)
        return 0;
    return m_spData->FUN_14053dad0();
}

// @0x140526320
bool CItem::FUN_140526320()
{
    if (m_spData == 0)
        return false;
    return m_spData->FUN_14053c6f0() == 0x60;
}

// @0x140526790
void CItem::FUN_140526790(int nJob)
{
    m_spData->FUN_14053c8e0(nJob);
}

// @0x1405267d0
void CItem::FUN_1405267d0(int nGender)
{
    m_spData->FUN_14053c940(nGender);
}

// @0x140526810
void CItem::FUN_140526810(unsigned short nLevel)
{
    m_spData->FUN_14053c9a0(nLevel);
}

// MS2-PIN: ?IsNull@?$MS2Ptr@VCItemData@@@@QEBA_NXZ 0x1402ffd90

// @0x14052c230
Unk_MusicNoteBlock::Unk_MusicNoteBlock()
{
    FUN_14052d040();
}

// @0x14052d040
void Unk_MusicNoteBlock::FUN_14052d040()
{
    m_n00 = 0;
    m_n08 = 0;
    m_n10 = 0;
    m_str18.Empty();
}

// @0x14052c0f0
CItemTransfer::CItemBinding::CItemBinding() : m_n18(0)
{
}

// @0x14052c4e0
CItemTransfer::CItemBinding::~CItemBinding()
{
}

// @0x14052c140
CItemCoupleInfo::CItemCoupleInfo()
{
    FUN_14052d000();
}

// @0x14052d000
void CItemCoupleInfo::FUN_14052d000()
{
    m_n18 = 0;
    m_str20 = L"";
    m_b28 = 0;
}

// @0x14052c510
CItemCoupleInfo::~CItemCoupleInfo()
{
}

// @0x14052c1a0
CItemCustomMusicScore::CItemCustomMusicScore()
{
    FUN_1406328c0();
}

// @0x140523790
CItem::CItem()
    : m_strName("")
    , m_20(0)
    , m_24(-1)
    , m_28(0)
    , m_2c(0)
    , m_30(0)
    , m_34(0)
    , m_38(0)
    , m_3c(0)
    , m_40(0)
    , m_48(0)
    , m_50(0)
    , m_58(0)
    , m_5c(-1)
    , m_60(-1)
    , m_64(0)
    , m_68(0)
    , m_6c(1)
    , m_70(0)
    , m_80(0)
    , m_88(0)
    , m_90(0)
    , m_98(0)
    , m_9c(0)
    , m_a0(0)
    , m_a4(0)
    , m_a8(0)
    , m_b0(0)
    , m_b4(0)
    , m_strB8("")
    , m_c0(0)
    , m_c8(0)
    , m_cc(1)
    , m_d0(0)
    , m_d4(0)
    , m_d8(0)
    , m_dc(0)
    , m_spData(0)
    , m_spStatus(0)
    , m_spProxy(0)
    , m_spUgc(0)
    , m_spGem(0)
    , m_spTransfer(0)
    , m_spMusic(0)
    , m_spCouple(0)
    , m_spBinding(0)
    , m_198(0)
    , m_19c(0)
{
}

// @0x140523b00
CItem::~CItem()
{
}

// @0x14052c0d0
Unk_ItemSlot188::Unk_ItemSlot188()
{
    m_p = 0;
}

unsigned char FUN_14053f8c0(unsigned);
unsigned char FUN_14053f940(unsigned);
void FUN_14053f990(unsigned);

// @0x140524240
void CItem::vfunc_1()
{
}

// @0x1405268c0
void CItem::vfunc_2()
{
}

// @0x140526d80
void CItem::vfunc_3(int)
{
    MS2_ASSERT_AT(0x43d, 0);
}

// @0x140526dc0
int CItem::vfunc_4()
{
    unsigned nCount = FUN_140526c50();
    if (m_198 != 0)
        return nCount > 0 ? nCount - 1 : 0;
    return nCount;
}

// @0x140525590
void CItem::FUN_140525590(__int64 n)
{
    m_spProxy->vfunc_5(n);
}

// @0x1405255e0
void CItem::FUN_1405255e0(CInPacket& pkt)
{
    m_spProxy->vfunc_6(reinterpret_cast<CInputStream*>(reinterpret_cast<char*>(&pkt) + 8));
}

// @0x140525730
bool CItem::FUN_140525730()
{
    if (!FUN_140525680())
        return false;
    CItemCustomMusicScore* pScore = FUN_140527960();
    if (pScore != 0 && pScore->FUN_140632780())
        return true;
    return false;
}

// @0x140525790
bool CItem::FUN_140525790()
{
    if (!FUN_140525680())
        return false;
    CItemCustomMusicScore* pScore = FUN_140527960();
    if (pScore != 0 && !pScore->FUN_140632780())
        return true;
    return false;
}

// @0x1405257f0
int CItem::FUN_1405257f0()
{
    if (FUN_140527a20() != 0)
        return 0;
    if (FUN_140525c60() != 0 && m_spData->period.usePeriod > 0)
        return 0;
    if (m_spData->property.slotMax > 1)
        return 1;
    return 0;
}

// @0x1405258b0
int CItem::FUN_1405258b0()
{
    return m_spData->FUN_14053cf90();
}

// @0x1405258f0
int CItem::FUN_1405258f0()
{
    return FUN_14053f8c0(FUN_1405276c0());
}

// @0x140525920
int CItem::FUN_140525920()
{
    return FUN_14053f940(FUN_1405276c0());
}

// @0x140525950
void CItem::FUN_140525950()
{
    FUN_14053f990(FUN_1405276c0());
}

// @0x1405259e0
int CItem::FUN_1405259e0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053ce80();
}

// @0x140525a30
int CItem::FUN_140525a30()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053cc00();
}

// @0x140529210
void CItem::FUN_140529210(unsigned nId, __int64 nCount)
{
    if (nId > 0)
    {
        FUN_1405288e0(nCount);
        m_98 = nId;
    }
}

// @0x1405292c0
void CItem::FUN_1405292c0(const CItemCoupleInfo& src)
{
    MS2_ASSERT_MSG_AT(0xb40, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    *m_spCouple = src;
}

// @0x140529330
void CItem::FUN_140529330(const CStringW& str)
{
    MS2_ASSERT_MSG_AT(0xb46, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    m_spCouple->m_str20 = str;
}

// @0x1405293b0
__int64 CItem::FUN_1405293b0()
{
    MS2_ASSERT_MSG_AT(0xb34, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    return m_spCouple->m_n18;
}

// @0x1405294a0
unsigned char CItem::FUN_1405294a0()
{
    MS2_ASSERT_MSG_AT(0xb4c, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    return m_spCouple->m_b28;
}

// @0x140529500
void CItem::FUN_140529500(const CStringW& str)
{
    m_strE0 = str;
}

// @0x140529540
CStringW* CItem::FUN_140529540()
{
    return &m_strE0;
}

// @0x140529600
void CItem::FUN_140529600()
{
    m_d4 = 1;
}

// @0x140529680
bool CItem::FUN_140529680(int n)
{
    return m_dc == n;
}

// @0x140529fd0
void CItem::FUN_140529fd0(CString str)
{
    m_strName = str;
}

// @0x14052a210
void CItem::FUN_14052a210(unsigned n)
{
    m_28 = n;
}

// @0x14052a230
void CItem::FUN_14052a230(unsigned n)
{
    m_28 = m_28 | n;
}

// @0x14052a260
void CItem::FUN_14052a260(unsigned n)
{
    m_28 = m_28 & ~n;
}

// @0x14052a290
bool CItem::FUN_14052a290(unsigned n)
{
    return (m_28 & n) > 0;
}

// @0x14052a2d0
bool CItem::FUN_14052a2d0()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525ca0() == 1;
}

// @0x14052a330
bool CItem::FUN_14052a330()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525db0() == 1;
}

// @0x14052a390
bool CItem::FUN_14052a390()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525e00() == 1;
}

// @0x14052a480
__int64 CItem::FUN_14052a480()
{
    MS2_ASSERT_MSG_AT(0xc28, L"m_pMoveStoreChar != NULL", m_spBinding.get() != 0);
    return m_spBinding->FUN_14052d1c0();
}

// @0x14052b340
int CItem::FUN_14052b340(unsigned n)
{
    m_6c = n;
    return 1;
}

// @0x14052b710
bool CItem::FUN_14052b710(unsigned* pA, __int64* pB)
{
    FUN_140528c80(*pA);
    FUN_140528dd0(*pB);
    return true;
}

// @0x14052b630
unsigned char CItem::FUN_14052b630()
{
    if (FUN_140527930() == 0)
        return 1;
    return reinterpret_cast<CItemTransfer*>(FUN_140527930())->FUN_1406352b0();
}

// @0x14052cae0
CItemCoupleInfo& CItemCoupleInfo::operator=(const CItemCoupleInfo& o)
{
    CPtred::operator=(o);
    m_n18 = o.m_n18;
    m_str20 = o.m_str20;
    m_b28 = o.m_b28;
    return *this;
}

// @0x14052d1c0
__int64 CItemTransfer::CItemBinding::FUN_14052d1c0()
{
    return m_n18;
}
