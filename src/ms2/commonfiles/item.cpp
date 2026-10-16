// MS2-UNIT: commonfiles\item.cpp
// MS2-RANGE: 0x140523790-0x140530640 .text$mn
// MS2-RANGE: 0x1400b9290-0x1400b9410 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8?$MS2Ptr@VCItemUgc@@@@QEBA_NPEAVCItemUgc@@@Z 0x14052cc40 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\item.cpp"
// item.cpp - CItem (commonfiles\item.cpp; the wassert path is e:\build\kr\22_04\ms2code\commonfiles\item.cpp).
// Partial: the plain scalar field accessors. The constructor, serializer and smart-pointer slot helpers are not
// recovered yet (their pointee types and the COMDAT glue are still open).
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/item.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/commonfiles/itemenchantinfo.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class Unk_ItemEquipData : public CItemData
{
public:
    int FUN_14053c620();
    int FUN_14053f0d0(int);
    int FUN_14053f390(int, int);
    int FUN_14053e9e0();
};
class Unk_ItemPriceSvc { public: int FUN_140678760(int, int, int); };
extern Unk_ItemPriceSvc* FUN_1401c0db0();
class Unk_ItemEnchantData : public CItemStatus {};
class Unk_ItemOwnerRef : public CItemTransfer {};
extern __int64 FUN_140869440();
extern unsigned FUN_14054b400(ItemModelData*);
extern unsigned __int64 FUN_140632030(CItemUgc*);

// w101 additions: unit-local record types for the table lookups CItem makes (names are descriptive, not original).
class Unk_IngItem : public CPtred { public: bool FUN_14054aca0(); };
class Unk_IngTable { public: MS2Ptr<Unk_IngItem> FUN_1405565f0(int); };
extern Unk_IngTable* FUN_140281980();
extern bool FUN_1403b3c40(const CStringW&, const wchar_t*);
extern void* FUN_140166410();
extern unsigned short FUN_14036dc40(void*);
extern MS2Ptr<CItemData> FUN_14053f870(int);
// @0x14052d230 TSingleton<ItemGachaBoxTable>::GetInstance (s_instance is the exe's DAT_143aaf1d0)
ItemGachaBoxTable* FUN_14052d230();
class Unk_SingletonObj;
extern void* DAT_143aaf1a8;
extern void* DAT_143aaf1b0;
extern void* DAT_143aaf1b8;
extern void* DAT_143aaf1c0;
extern Unk_SingletonObj* DAT_143aaf1c8;
extern Unk_SingletonObj* DAT_143aaf1d8;
#define MS2_ASSERT_MSG_AT(line, msg, cond) (void)((!!(cond)) || (_wassert(msg, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))

// @0x14052a020
int CItem::FUN_14052a020()
{
    return m_20;
}
MS2_REPLACE_METHOD(0x14052A020, CItem, FUN_14052a020, 14, 0xA25B27BF);

// @0x14052a040
void CItem::FUN_14052a040(int v)
{
    m_20 = v;
}
MS2_REPLACE_METHOD(0x14052A040, CItem, FUN_14052a040, 22, 0xF6E32213);

// @0x14052a150
int CItem::FUN_14052a150()
{
    return m_24;
}
MS2_REPLACE_METHOD(0x14052A150, CItem, FUN_14052a150, 14, 0xBA6447E3);

// @0x14052a130
void CItem::FUN_14052a130(int v)
{
    m_24 = v;
}
MS2_REPLACE_METHOD(0x14052A130, CItem, FUN_14052a130, 22, 0x5ED7A56F);

// @0x1405268f0
int CItem::FUN_1405268f0()
{
    return m_2c;
}
MS2_REPLACE_METHOD(0x1405268F0, CItem, FUN_1405268f0, 14, 0x6A78E4AB);

// @0x1405268d0
void CItem::FUN_1405268d0(int v)
{
    m_2c = v;
}
MS2_REPLACE_METHOD(0x1405268D0, CItem, FUN_1405268d0, 22, 0x0EEC4237);

// @0x140526930
unsigned char CItem::FUN_140526930()
{
    return m_30;
}
MS2_REPLACE_METHOD(0x140526930, CItem, FUN_140526930, 15, 0x228C1F9D);

// @0x140526910
void CItem::FUN_140526910(unsigned char v)
{
    m_30 = v;
}
MS2_REPLACE_METHOD(0x140526910, CItem, FUN_140526910, 23, 0x09675A9D);

// @0x140526a10
int CItem::FUN_140526a10()
{
    return m_34;
}
MS2_REPLACE_METHOD(0x140526A10, CItem, FUN_140526a10, 14, 0x9A8B24F3);

// @0x140526a30
void CItem::FUN_140526a30(int v)
{
    m_34 = v;
}
MS2_REPLACE_METHOD(0x140526A30, CItem, FUN_140526a30, 22, 0xFEAFFEDF);

// @0x140526970
int CItem::FUN_140526970()
{
    return m_38;
}
MS2_REPLACE_METHOD(0x140526970, CItem, FUN_140526970, 14, 0xB2976B17);

// @0x1405269b0
int CItem::FUN_1405269b0()
{
    return m_3c;
}
MS2_REPLACE_METHOD(0x1405269B0, CItem, FUN_1405269b0, 14, 0xCAA08B3B);

// @0x140526990
void CItem::FUN_140526990(int v)
{
    m_3c = v;
}
MS2_REPLACE_METHOD(0x140526990, CItem, FUN_140526990, 22, 0x2EC56527);

// @0x140526a50
__int64 CItem::FUN_140526a50()
{
    return m_40;
}
MS2_REPLACE_METHOD(0x140526A50, CItem, FUN_140526a50, 15, 0x8B0075C1);

// @0x140526a70
void CItem::FUN_140526a70(__int64 v)
{
    m_40 = v;
}
MS2_REPLACE_METHOD(0x140526A70, CItem, FUN_140526a70, 25, 0x9BEF1163);

// @0x140526a90
__int64 CItem::FUN_140526a90()
{
    return m_48;
}
MS2_REPLACE_METHOD(0x140526A90, CItem, FUN_140526a90, 15, 0x5AEB0F79);

// @0x140526ab0
void CItem::FUN_140526ab0(__int64 v)
{
    m_48 = v;
}
MS2_REPLACE_METHOD(0x140526AB0, CItem, FUN_140526ab0, 25, 0x4C00882B);

// @0x140526ad0
__int64 CItem::FUN_140526ad0()
{
    return m_50;
}
MS2_REPLACE_METHOD(0x140526AD0, CItem, FUN_140526ad0, 15, 0x6B2752D1);

// @0x140526af0
void CItem::FUN_140526af0(__int64 v)
{
    m_50 = v;
}
MS2_REPLACE_METHOD(0x140526AF0, CItem, FUN_140526af0, 25, 0x7C15EE73);

// @0x140526b10
int CItem::FUN_140526b10()
{
    return m_58;
}
MS2_REPLACE_METHOD(0x140526B10, CItem, FUN_140526b10, 14, 0x7245C177);

// @0x140526b30
void CItem::FUN_140526b30(int v)
{
    m_58 = v;
}
MS2_REPLACE_METHOD(0x140526B30, CItem, FUN_140526b30, 22, 0x05E09DEB);

// @0x140526b50
int CItem::FUN_140526b50()
{
    return m_5c;
}
MS2_REPLACE_METHOD(0x140526B50, CItem, FUN_140526b50, 14, 0x8A52079B);

// @0x140526b70
void CItem::FUN_140526b70(int v)
{
    m_5c = v;
}
MS2_REPLACE_METHOD(0x140526B70, CItem, FUN_140526b70, 22, 0x6DD84747);

// @0x140526b90
int CItem::FUN_140526b90()
{
    return m_60;
}
MS2_REPLACE_METHOD(0x140526B90, CItem, FUN_140526b90, 14, 0xA1BBC3FF);

// @0x140526bd0
int CItem::FUN_140526bd0()
{
    return m_64;
}
MS2_REPLACE_METHOD(0x140526BD0, CItem, FUN_140526bd0, 14, 0xB9C4E423);

// @0x140526bf0
void CItem::FUN_140526bf0(int v)
{
    m_64 = v;
}
MS2_REPLACE_METHOD(0x140526BF0, CItem, FUN_140526bf0, 22, 0x5E3B67AF);

// @0x140526c30
int CItem::FUN_140526c30()
{
    return m_68;
}
MS2_REPLACE_METHOD(0x140526C30, CItem, FUN_140526c30, 14, 0xD1D12A47);

// @0x140526c10
void CItem::FUN_140526c10(int v)
{
    m_68 = v;
}
MS2_REPLACE_METHOD(0x140526C10, CItem, FUN_140526c10, 22, 0x2659249B);

// @0x140526c50
int CItem::FUN_140526c50()
{
    return m_6c;
}
MS2_REPLACE_METHOD(0x140526C50, CItem, FUN_140526c50, 14, 0x69D980EB);

// @0x140526e40
int CItem::FUN_140526e40()
{
    return m_70;
}
MS2_REPLACE_METHOD(0x140526E40, CItem, FUN_140526e40, 14, 0x81E2A10F);

// @0x140528910
__int64 CItem::FUN_140528910()
{
    return m_80;
}
MS2_REPLACE_METHOD(0x140528910, CItem, FUN_140528910, 18, 0x841B6891);

// @0x1405288e0
void CItem::FUN_1405288e0(__int64 v)
{
    m_80 = v;
}
MS2_REPLACE_METHOD(0x1405288E0, CItem, FUN_1405288e0, 28, 0xF376627F);

// @0x140528a90
__int64 CItem::FUN_140528a90()
{
    return m_88;
}
MS2_REPLACE_METHOD(0x140528A90, CItem, FUN_140528a90, 18, 0x4EDF9779);

// @0x140528a60
void CItem::FUN_140528a60(__int64 v)
{
    m_88 = v;
}
MS2_REPLACE_METHOD(0x140528A60, CItem, FUN_140528a60, 28, 0x28AF0D97);

// @0x140528ae0
__int64 CItem::FUN_140528ae0()
{
    return m_90;
}
MS2_REPLACE_METHOD(0x140528AE0, CItem, FUN_140528ae0, 18, 0xEE8FE4C1);

// @0x140528ab0
void CItem::FUN_140528ab0(__int64 v)
{
    m_90 = v;
}
MS2_REPLACE_METHOD(0x140528AB0, CItem, FUN_140528ab0, 28, 0x5DEADEAF);

// @0x140529260
int CItem::FUN_140529260()
{
    return m_98;
}
MS2_REPLACE_METHOD(0x140529260, CItem, FUN_140529260, 17, 0xA9AE535B);

// @0x140527300
int CItem::FUN_140527300()
{
    return m_9c;
}
MS2_REPLACE_METHOD(0x140527300, CItem, FUN_140527300, 17, 0x444DCEE7);

// @0x1405272e0
void CItem::FUN_1405272e0(int v)
{
    m_9c = v;
}
MS2_REPLACE_METHOD(0x1405272E0, CItem, FUN_1405272e0, 25, 0x79F379CB);

// @0x140527340
int CItem::FUN_140527340()
{
    return m_a0;
}
MS2_REPLACE_METHOD(0x140527340, CItem, FUN_140527340, 17, 0xB518FD33);

// @0x140527320
void CItem::FUN_140527320(int v)
{
    m_a0 = v;
}
MS2_REPLACE_METHOD(0x140527320, CItem, FUN_140527320, 25, 0x9EB3CF4F);

// @0x140528ca0
int CItem::FUN_140528ca0()
{
    return m_a4;
}
MS2_REPLACE_METHOD(0x140528CA0, CItem, FUN_140528ca0, 17, 0x4FB552BF);

// @0x140528c80
void CItem::FUN_140528c80(int v)
{
    m_a4 = v;
}
MS2_REPLACE_METHOD(0x140528C80, CItem, FUN_140528c80, 25, 0x041453C3);

// @0x140528e00
__int64 CItem::FUN_140528e00()
{
    return m_a8;
}
MS2_REPLACE_METHOD(0x140528E00, CItem, FUN_140528e00, 18, 0x23C88FD9);

// @0x140528dd0
void CItem::FUN_140528dd0(__int64 v)
{
    m_a8 = v;
}
MS2_REPLACE_METHOD(0x140528DD0, CItem, FUN_140528dd0, 28, 0x7D973C77);

// @0x140529070
int CItem::FUN_140529070()
{
    return m_b0;
}
MS2_REPLACE_METHOD(0x140529070, CItem, FUN_140529070, 17, 0x1F8D7963);

// @0x140529090
int CItem::FUN_140529090()
{
    return m_b4;
}
MS2_REPLACE_METHOD(0x140529090, CItem, FUN_140529090, 17, 0xBA29CEEF);

// @0x140528b90
__int64 CItem::FUN_140528b90()
{
    return m_c0;
}
MS2_REPLACE_METHOD(0x140528B90, CItem, FUN_140528b90, 18, 0xADEC8FD1);

// @0x140528b60
void CItem::FUN_140528b60(__int64 v)
{
    m_c0 = v;
}
MS2_REPLACE_METHOD(0x140528B60, CItem, FUN_140528b60, 28, 0xC9A2153F);

// @0x140528bd0
int CItem::FUN_140528bd0()
{
    return m_c8;
}
MS2_REPLACE_METHOD(0x140528BD0, CItem, FUN_140528bd0, 17, 0x690E246B);

// @0x140528bb0
void CItem::FUN_140528bb0(int v)
{
    m_c8 = v;
}
MS2_REPLACE_METHOD(0x140528BB0, CItem, FUN_140528bb0, 25, 0xA8D572C7);

// @0x140528c20
unsigned short CItem::FUN_140528c20()
{
    return m_cc;
}
MS2_REPLACE_METHOD(0x140528C20, CItem, FUN_140528c20, 18, 0xB3C569C6);

// @0x140528bf0
void CItem::FUN_140528bf0(unsigned short v)
{
    m_cc = v;
}
MS2_REPLACE_METHOD(0x140528BF0, CItem, FUN_140528bf0, 28, 0xF1E0B56E);

// @0x140528c60
int CItem::FUN_140528c60()
{
    return m_d0;
}
MS2_REPLACE_METHOD(0x140528C60, CItem, FUN_140528c60, 17, 0x9E46CF83);

// @0x140528c40
void CItem::FUN_140528c40(int v)
{
    m_d0 = v;
}
MS2_REPLACE_METHOD(0x140528C40, CItem, FUN_140528c40, 25, 0x09284B7F);

// @0x140529620
unsigned char CItem::FUN_140529620()
{
    return m_d4;
}
MS2_REPLACE_METHOD(0x140529620, CItem, FUN_140529620, 18, 0x9D8408D9);

// @0x1405292a0
int CItem::FUN_1405292a0()
{
    return m_d8;
}
MS2_REPLACE_METHOD(0x1405292A0, CItem, FUN_1405292a0, 17, 0xD382A09B);

// @0x140529280
void CItem::FUN_140529280(int v)
{
    m_d8 = v;
}
MS2_REPLACE_METHOD(0x140529280, CItem, FUN_140529280, 25, 0x3E60F697);

// @0x140529640
int CItem::FUN_140529640()
{
    return m_dc;
}
MS2_REPLACE_METHOD(0x140529640, CItem, FUN_140529640, 17, 0x6E1EF627);

// @0x140529660
void CItem::FUN_140529660(int v)
{
    m_dc = v;
}
MS2_REPLACE_METHOD(0x140529660, CItem, FUN_140529660, 25, 0xA3C4A10B);

// @0x1405269f0
unsigned char CItem::FUN_1405269f0()
{
    return m_198;
}
MS2_REPLACE_METHOD(0x1405269F0, CItem, FUN_1405269f0, 18, 0x6158C2DC);

// @0x1405269d0
void CItem::FUN_1405269d0(unsigned char v)
{
    m_198 = v;
}
MS2_REPLACE_METHOD(0x1405269D0, CItem, FUN_1405269d0, 26, 0x4FD40BDC);

// @0x1405291f0
int CItem::FUN_1405291f0()
{
    return m_19c;
}
MS2_REPLACE_METHOD(0x1405291F0, CItem, FUN_1405291f0, 17, 0x1679479E);

// @0x140525640
int CItem::FUN_140525640()
{
    return m_spData->FUN_14053cc40();
}
MS2_REPLACE_METHOD(0x140525640, CItem, FUN_140525640, 44, 0x892B8595);

// @0x140525870
int CItem::FUN_140525870()
{
    return m_spData->FUN_14053d150();
}
MS2_REPLACE_METHOD(0x140525870, CItem, FUN_140525870, 44, 0x1B3AC98C);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525ca0
int CItem::FUN_140525ca0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053ce20();
}
MS2_REPLACE_METHOD(0x140525CA0, CItem, FUN_140525ca0, 74, 0x4FAA5D2F);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525db0
int CItem::FUN_140525db0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053d1f0();
}
MS2_REPLACE_METHOD(0x140525DB0, CItem, FUN_140525db0, 74, 0x1FA82CFB);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525e00
int CItem::FUN_140525e00()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053d210();
}
MS2_REPLACE_METHOD(0x140525E00, CItem, FUN_140525e00, 74, 0xAE2063CB);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525e50
int CItem::FUN_140525e50(int nGender, int nCategory)
{
    if (!m_spData->FUN_14053cae0(nGender, nCategory))
        return 0;
    return FUN_140525eb0(nGender, nCategory);
}
MS2_REPLACE_METHOD(0x140525E50, CItem, FUN_140525e50, 86, 0xCD65FAD7);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525eb0
int CItem::FUN_140525eb0(int nGender, int nB)
{
    if (m_spData.get() == 0)
        return 0;
    return m_spData->FUN_14053c9e0(nGender, nB);
}
MS2_REPLACE_METHOD(0x140525EB0, CItem, FUN_140525eb0, 87, 0x3CF14EF1);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140526010
int CItem::FUN_140526010()
{
    if (m_spData.get() == 0)
        return 0;
    return m_spData->FUN_14053d900();
}
MS2_REPLACE_METHOD(0x140526010, CItem, FUN_140526010, 72, 0x6813C8A0);

// @0x140526100
int CItem::FUN_140526100()
{
    if (m_spData == 0)
        return 0;
    return m_spData->FUN_14053d8c0();
}
MS2_REPLACE_METHOD(0x140526100, CItem, FUN_140526100, 76, 0x532D60CC);

// @0x1405262c0
int CItem::FUN_1405262c0()
{
    if (m_spData == 0)
        return 0;
    return m_spData->FUN_14053dad0();
}
MS2_REPLACE_METHOD(0x1405262C0, CItem, FUN_1405262c0, 76, 0x8CD26A7C);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140526320
bool CItem::FUN_140526320()
{
    if (m_spData == 0)
        return false;
    return m_spData->FUN_14053c6f0() == 0x60;
}
MS2_REPLACE_METHOD(0x140526320, CItem, FUN_140526320, 100, 0x95712DC4);

// @0x140526790
void CItem::FUN_140526790(int nJob)
{
    m_spData->FUN_14053c8e0(nJob);
}
MS2_REPLACE_METHOD(0x140526790, CItem, FUN_140526790, 49, 0xCA42CD40);

// @0x1405267d0
void CItem::FUN_1405267d0(int nGender)
{
    m_spData->FUN_14053c940(nGender);
}
MS2_REPLACE_METHOD(0x1405267D0, CItem, FUN_1405267d0, 49, 0xC0D977A0);

// @0x140526810
void CItem::FUN_140526810(unsigned short nLevel)
{
    m_spData->FUN_14053c9a0(nLevel);
}
MS2_REPLACE_METHOD(0x140526810, CItem, FUN_140526810, 51, 0xAFB2B386);

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
MS2_REPLACE_METHOD(0x14052D040, Unk_MusicNoteBlock, FUN_14052d040, 69, 0x99410530);

// @0x14052c0f0
CItemTransfer::CItemBinding::CItemBinding() : m_n18(0)
{
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
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
MS2_REPLACE_METHOD(0x14052D000, CItemCoupleInfo, FUN_14052d000, 61, 0xDD3E3735);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
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
int FUN_14053f990(unsigned);

// @0x140524240
void CItem::vfunc_1()
{
}
MS2_REPLACE_METHOD(0x140524240, CItem, vfunc_1, 6, 0xA9AF6E37);

// @0x1405268c0
void CItem::vfunc_2()
{
}
MS2_REPLACE_METHOD(0x1405268C0, CItem, vfunc_2, 6, 0xA9AF6E37);

// @0x140526d80
void CItem::vfunc_3(int)
{
    MS2_ASSERT_AT(0x43d, 0);
}
MS2_REPLACE_METHOD(0x140526D80, CItem, vfunc_3, 52, 0x532D3E75);

// @0x140526dc0
int CItem::vfunc_4()
{
    unsigned nCount = FUN_140526c50();
    if (m_198 != 0)
        return nCount > 0 ? nCount - 1 : 0;
    return nCount;
}
MS2_REPLACE_METHOD(0x140526DC0, CItem, vfunc_4, 81, 0x28A974E4);

// @0x140525590
void CItem::FUN_140525590(__int64 n)
{
    m_spProxy->vfunc_5(n);
}
MS2_REPLACE_METHOD(0x140525590, CItem, FUN_140525590, 64, 0xECB9E513);

// @0x1405255e0
void CItem::FUN_1405255e0(CInPacket& pkt)
{
    m_spProxy->vfunc_6(reinterpret_cast<CInputStream*>(reinterpret_cast<char*>(&pkt) + 8));
}
MS2_REPLACE_METHOD(0x1405255E0, CItem, FUN_1405255e0, 81, 0x6811AC4A);

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
MS2_REPLACE_METHOD(0x140525730, CItem, FUN_140525730, 81, 0x2CA15262);

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
MS2_REPLACE_METHOD(0x140525790, CItem, FUN_140525790, 81, 0x1FD1AC30);

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
MS2_REPLACE_METHOD(0x1405257F0, CItem, FUN_1405257f0, 115, 0xC01347F9);

// @0x1405258b0
int CItem::FUN_1405258b0()
{
    return m_spData->FUN_14053cf90();
}
MS2_REPLACE_METHOD(0x1405258B0, CItem, FUN_1405258b0, 44, 0x1E0F1D2F);

// @0x1405258f0
int CItem::FUN_1405258f0()
{
    return FUN_14053f8c0(FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1405258F0, CItem, FUN_1405258f0, 34, 0xB579842C);

// @0x140525920
int CItem::FUN_140525920()
{
    return FUN_14053f940(FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x140525920, CItem, FUN_140525920, 34, 0xA303E991);

// @0x140525950
int CItem::FUN_140525950()
{
    return FUN_14053f990(FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x140525950, CItem, FUN_140525950, 31, 0x537B6C6C);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1405259e0
int CItem::FUN_1405259e0()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053ce80();
}
MS2_REPLACE_METHOD(0x1405259E0, CItem, FUN_1405259e0, 74, 0xC931371A);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140525a30
int CItem::FUN_140525a30()
{
    if (m_spData.IsNull())
        return 0;
    return m_spData->FUN_14053cc00();
}
MS2_REPLACE_METHOD(0x140525A30, CItem, FUN_140525a30, 74, 0xA87C95CD);

// @0x140529210
void CItem::FUN_140529210(unsigned nId, __int64 nCount)
{
    if (nId > 0)
    {
        FUN_1405288e0(nCount);
        m_98 = nId;
    }
}
MS2_REPLACE_METHOD(0x140529210, CItem, FUN_140529210, 60, 0xC03BAF7D);

// @0x1405292c0
void CItem::FUN_1405292c0(const CItemCoupleInfo& src)
{
    MS2_ASSERT_MSG_AT(0xb40, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    *m_spCouple = src;
}
MS2_REPLACE_METHOD(0x1405292C0, CItem, FUN_1405292c0, 103, 0x10173ED6);

// @0x140529330
void CItem::FUN_140529330(const CStringW& str)
{
    MS2_ASSERT_MSG_AT(0xb46, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    m_spCouple->m_str20 = str;
}
MS2_REPLACE_METHOD(0x140529330, CItem, FUN_140529330, 108, 0x6C0038BA);

// @0x1405293b0
__int64 CItem::FUN_1405293b0()
{
    MS2_ASSERT_MSG_AT(0xb34, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    return m_spCouple->m_n18;
}
MS2_REPLACE_METHOD(0x1405293B0, CItem, FUN_1405293b0, 89, 0x8AEEB83D);

// @0x1405294a0
unsigned char CItem::FUN_1405294a0()
{
    MS2_ASSERT_MSG_AT(0xb4c, L"m_pCoupleInfo != NULL", m_spCouple.get() != 0);
    return m_spCouple->m_b28;
}
MS2_REPLACE_METHOD(0x1405294A0, CItem, FUN_1405294a0, 89, 0xB5B90365);

// @0x140529500
void CItem::FUN_140529500(const CStringW& str)
{
    m_strE0 = str;
}
MS2_REPLACE_METHOD(0x140529500, CItem, FUN_140529500, 44, 0x44BD2447);

// @0x140529540
CStringW* CItem::FUN_140529540()
{
    return &m_strE0;
}
MS2_REPLACE_METHOD(0x140529540, CItem, FUN_140529540, 17, 0x8A8CEFA3);

// @0x140529600
void CItem::FUN_140529600()
{
    m_d4 = 1;
}
MS2_REPLACE_METHOD(0x140529600, CItem, FUN_140529600, 18, 0xAAF63E0F);

// @0x140529680
bool CItem::FUN_140529680(int n)
{
    return m_dc == n;
}
MS2_REPLACE_METHOD(0x140529680, CItem, FUN_140529680, 55, 0xA5806025);

// @0x140529fd0
void CItem::FUN_140529fd0(CString str)
{
    m_strName = str;
}
MS2_REPLACE_METHOD(0x140529FD0, CItem, FUN_140529fd0, 63, 0xD01079EB);

// @0x14052a210
void CItem::FUN_14052a210(unsigned n)
{
    m_28 = n;
}
MS2_REPLACE_METHOD(0x14052A210, CItem, FUN_14052a210, 22, 0x26F5625B);

// @0x14052a230
void CItem::FUN_14052a230(unsigned n)
{
    m_28 = m_28 | n;
}
MS2_REPLACE_METHOD(0x14052A230, CItem, FUN_14052a230, 32, 0x19425900);

// @0x14052a260
void CItem::FUN_14052a260(unsigned n)
{
    m_28 = m_28 & ~n;
}
MS2_REPLACE_METHOD(0x14052A260, CItem, FUN_14052a260, 36, 0x2B91A089);

// @0x14052a290
bool CItem::FUN_14052a290(unsigned n)
{
    return (m_28 & n) > 0;
}
MS2_REPLACE_METHOD(0x14052A290, CItem, FUN_14052a290, 56, 0x7063F737);

// @0x14052a2d0
bool CItem::FUN_14052a2d0()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525ca0() == 1;
}
MS2_REPLACE_METHOD(0x14052A2D0, CItem, FUN_14052a2d0, 78, 0xF3A5AB3E);

// @0x14052a330
bool CItem::FUN_14052a330()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525db0() == 1;
}
MS2_REPLACE_METHOD(0x14052A330, CItem, FUN_14052a330, 78, 0x28AA9D71);

// @0x14052a390
bool CItem::FUN_14052a390()
{
    if (FUN_14052a290(1))
        return false;
    return FUN_140525e00() == 1;
}
MS2_REPLACE_METHOD(0x14052A390, CItem, FUN_14052a390, 78, 0xE7EBFA56);

// @0x14052a480
__int64 CItem::FUN_14052a480()
{
    MS2_ASSERT_MSG_AT(0xc28, L"m_pMoveStoreChar != NULL", m_spBinding.get() != 0);
    return m_spBinding->FUN_14052d1c0();
}
MS2_REPLACE_METHOD(0x14052A480, CItem, FUN_14052a480, 93, 0xC2E28FA1);

// @0x14052b340
int CItem::FUN_14052b340(unsigned n)
{
    m_6c = n;
    return 1;
}
MS2_REPLACE_METHOD(0x14052B340, CItem, FUN_14052b340, 27, 0xE2CA3F90);

// @0x14052b710
bool CItem::FUN_14052b710(unsigned* pA, __int64* pB)
{
    FUN_140528c80(*pA);
    FUN_140528dd0(*pB);
    return true;
}
MS2_REPLACE_METHOD(0x14052B710, CItem, FUN_14052b710, 61, 0x8AB3CC15);

// @0x14052b630
unsigned char CItem::FUN_14052b630()
{
    if (FUN_140527930() == 0)
        return 1;
    return reinterpret_cast<CItemTransfer*>(FUN_140527930())->FUN_1406352b0();
}
MS2_REPLACE_METHOD(0x14052B630, CItem, FUN_14052b630, 51, 0xDD6A277F);

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
MS2_REPLACE_METHOD(0x14052D1C0, CItemTransfer::CItemBinding, FUN_14052d1c0, 15, 0xBBB219C9);

// @0x140527840
Unk_ItemEquipData* CItem::FUN_140527840()
{
    return static_cast<Unk_ItemEquipData*>(m_spData.get());
}
MS2_REPLACE_METHOD(0x140527840, CItem, FUN_140527840, 33, 0xFF365AEE);

// @0x1405277b0
Unk_ItemEquipData* CItem::FUN_1405277b0()
{
    return static_cast<Unk_ItemEquipData*>(m_spData.get());
}
MS2_REPLACE_METHOD(0x1405277B0, CItem, FUN_1405277b0, 33, 0x7099585E);

// @0x140527870
Unk_UserProxyItemData* CItem::FUN_140527870()
{
    return m_spProxy.get();
}
MS2_REPLACE_METHOD(0x140527870, CItem, FUN_140527870, 33, 0x82E03B80);

// @0x1405278a0
Unk_ItemEnchantData* CItem::FUN_1405278a0()
{
    return static_cast<Unk_ItemEnchantData*>(m_spStatus.get());
}
MS2_REPLACE_METHOD(0x1405278A0, CItem, FUN_1405278a0, 33, 0x1C66B116);

// @0x1405278d0
Unk_ItemUgcInfo* CItem::FUN_1405278d0()
{
    return reinterpret_cast<Unk_ItemUgcInfo*>(m_spUgc.get());
}
MS2_REPLACE_METHOD(0x1405278D0, CItem, FUN_1405278d0, 33, 0xF5A6EEE7);

// @0x140527900
CItemGem* CItem::FUN_140527900()
{
    return m_spGem.get();
}
MS2_REPLACE_METHOD(0x140527900, CItem, FUN_140527900, 33, 0xF400AA87);

// @0x140527930
Unk_ItemOwnerRef* CItem::FUN_140527930()
{
    return static_cast<Unk_ItemOwnerRef*>(m_spTransfer.get());
}
MS2_REPLACE_METHOD(0x140527930, CItem, FUN_140527930, 33, 0x70254757);

// @0x140527960
CItemCustomMusicScore* CItem::FUN_140527960()
{
    return m_spMusic.get();
}
MS2_REPLACE_METHOD(0x140527960, CItem, FUN_140527960, 33, 0xD0F5E797);

// @0x140527990
CItemCustomMusicScore* CItem::FUN_140527990()
{
    return m_spMusic.get();
}
MS2_REPLACE_METHOD(0x140527990, CItem, FUN_140527990, 33, 0xC78B125C);

// @0x1405279c0
CItemSocket* CItem::FUN_1405279c0()
{
    return m_spSocket.get();
}
MS2_REPLACE_METHOD(0x1405279C0, CItem, FUN_1405279c0, 33, 0x830CFC5C);

// @0x1405279f0
int CItem::FUN_1405279f0()
{
    if (FUN_140525680())
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1405279F0, CItem, FUN_1405279f0, 40, 0x27EECBC7);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140526160
int CItem::FUN_140526160()
{
    if ((unsigned)m_dc > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140526160, CItem, FUN_140526160, 29, 0x4E475867);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140526c70
void CItem::FUN_140526c70(int nCount)
{
    unsigned n = nCount;
    m_6c = n < FUN_1405281e0() ? n : FUN_1405281e0();
}
MS2_REPLACE_METHOD(0x140526C70, CItem, FUN_140526c70, 70, 0x1DBDC687);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140526cc0
unsigned CItem::FUN_140526cc0(int nAdd)
{
    m_6c = m_6c + nAdd;
    FUN_140526c70(m_6c);
    return m_6c;
}
MS2_REPLACE_METHOD(0x140526CC0, CItem, FUN_140526cc0, 93, 0x92394BB5);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140526d30
int CItem::FUN_140526d30()
{
    if (FUN_1405277b0()->FUN_14053cd10())
        return 0x17;
    if (FUN_140525640() == 0)
        return 0;
    return 0x18;
}
MS2_REPLACE_METHOD(0x140526D30, CItem, FUN_140526d30, 69, 0x30D36CF3);

// @0x1405274e0
unsigned CItem::FUN_1405274e0()
{
    if (m_spData == NULL)
        return 0;
    return m_spData->property.rePackingLimitCount;
}
MS2_REPLACE_METHOD(0x1405274E0, CItem, FUN_1405274e0, 71, 0x3C7D6924);

// @0x140527530
unsigned CItem::FUN_140527530()
{
    if (m_spData == NULL)
        return 0;
    return m_spData->property.rePackingItemConsumeCount;
}
MS2_REPLACE_METHOD(0x140527530, CItem, FUN_140527530, 71, 0xB0CECF7D);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140527580
int CItem::FUN_140527580()
{
    unsigned n;
    if (FUN_1405274e0() - FUN_140527440() < 0)
        n = 0;
    else
        n = FUN_1405274e0() - FUN_140527440();
    return n;
}
MS2_REPLACE_METHOD(0x140527580, CItem, FUN_140527580, 100, 0xDED28C8F);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140527640
__int64 CItem::FUN_140527640()
{
    return FUN_140527670() * (unsigned __int64)m_6c;
}
MS2_REPLACE_METHOD(0x140527640, CItem, FUN_140527640, 36, 0x1268982F);

// @0x140527670
__int64 CItem::FUN_140527670()
{
    return m_spData->FUN_14053ea00(FUN_140526bd0());
}
MS2_REPLACE_METHOD(0x140527670, CItem, FUN_140527670, 59, 0xD7F60E55);

// @0x1405276c0
int CItem::FUN_1405276c0()
{
    if (m_spData != NULL)
        return m_spData->FUN_14053c510();
    return 0;
}
MS2_REPLACE_METHOD(0x1405276C0, CItem, FUN_1405276c0, 69, 0x027BAB5E);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140527710
unsigned CItem::FUN_140527710()
{
    if (m_spData.get() == 0)
        return 0;
    return m_spData->limit.levelLimit;
}
MS2_REPLACE_METHOD(0x140527710, CItem, FUN_140527710, 67, 0x198C6BCE);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140527760
int CItem::FUN_140527760()
{
    if (m_spData.get() == 0)
        return 0;
    return m_spData->FUN_14053c600();
}
MS2_REPLACE_METHOD(0x140527760, CItem, FUN_140527760, 69, 0xAC97522B);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1405277e0
bool CItem::FUN_1405277e0(int n)
{
    if (m_spData.get() == 0)
        return false;
    return m_spData->FUN_14053c6b0(n);
}
MS2_REPLACE_METHOD(0x1405277E0, CItem, FUN_1405277e0, 77, 0x4F881743);

// @0x140527a20
unsigned CItem::FUN_140527a20()
{
    if (m_68 != 0 && m_spData->FUN_14053d510())
        return m_68;
    return FUN_14054b400(m_spData->FUN_14053eba0());
}
MS2_REPLACE_METHOD(0x140527A20, CItem, FUN_140527a20, 104, 0x946235F9);

// @0x1405281e0
unsigned CItem::FUN_1405281e0()
{
    if (m_spData == NULL)
        return 0;
    return m_spData->property.slotMax;
}
MS2_REPLACE_METHOD(0x1405281E0, CItem, FUN_1405281e0, 71, 0xD8B41AF4);

// @0x1405282d0
unsigned short CItem::FUN_1405282d0()
{
    return m_spData->limit.levelLimit;
}
MS2_REPLACE_METHOD(0x1405282D0, CItem, FUN_1405282d0, 40, 0x5F468EB9);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x140528930
bool CItem::FUN_140528930()
{
    __int64 nNow = FUN_140869440();
    if (m_80 < 1 || nNow < m_80)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140528930, CItem, FUN_140528930, 64, 0x2211389E);

// @0x140528b00
void CItem::FUN_140528b00(const CStringW& str)
{
    m_strB8 = str;
}
MS2_REPLACE_METHOD(0x140528B00, CItem, FUN_140528b00, 44, 0x874D4D35);

// @0x140528b40
CStringW* CItem::FUN_140528b40()
{
    return &m_strB8;
}
MS2_REPLACE_METHOD(0x140528B40, CItem, FUN_140528b40, 17, 0x2B7FF74B);

// @0x140528da0
bool CItem::FUN_140528da0()
{
    if (FUN_140528ca0() == 1)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140528DA0, CItem, FUN_140528da0, 35, 0x83E8C624);

// @0x140528e20
bool CItem::FUN_140528e20()
{
    if (FUN_140528ca0() == 1)
        return true;
    if (FUN_140528ca0() == 0)
    {
        if (FUN_140869440() < FUN_140528e00())
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140528E20, CItem, FUN_140528e20, 83, 0x1359AAF1);

// @0x140525f60
int CItem::FUN_140525f60()
{
    if (m_spUgc == NULL)
        return 0;
    if (FUN_140632030(m_spUgc.get()) > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140525F60, CItem, FUN_140525f60, 87, 0x14B28FAE);

// ---- w98 batch 1: table-row / UGC delegations
extern bool FUN_1403b3c40(const CStringW&, const wchar_t*);
extern bool FUN_14026d4d0(void*, int, __int64);
extern __int64 FUN_1406321d0(CItemUgc*);
extern int g_ItemFunctionFlags[4];   // 0x142d568c0

// @0x140525c00
int CItem::FUN_140525c00()
{
    if (m_spData.IsNull())
        return 0;
    return FUN_1403b3c40(m_spData->function.name, L"StoryBook");
}
MS2_REPLACE_METHOD(0x140525C00, CItem, FUN_140525c00, 87, 0xBF027633);

// @0x140525cf0
int CItem::FUN_140525cf0()
{
    if (m_spData.IsNull())
        return 0;
    int nCount = 4;
    for (int i = 0; i < nCount; i++)
    {
        if (m_spData->FUN_14053eba0()->FUN_14054b450(g_ItemFunctionFlags[i]))
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140525CF0, CItem, FUN_140525cf0, 171, 0xC6A23014);

// @0x140525f10
int CItem::FUN_140525f10()
{
    if (m_spData.get() != 0)
        return m_spData->FUN_14053d6f0();
    return 0;
}
MS2_REPLACE_METHOD(0x140525F10, CItem, FUN_140525f10, 72, 0x5D744C7D);

// @0x140525fc0
__int64 CItem::FUN_140525fc0()
{
    if (m_spUgc == NULL)
        return 0;
    return FUN_1406321d0(m_spUgc.get());
}
MS2_REPLACE_METHOD(0x140525FC0, CItem, FUN_140525fc0, 73, 0xDD20CE3F);

// @0x140526060
int CItem::FUN_140526060(void* pArg)
{
    if (!FUN_140525f10() || !FUN_140525f60())
        return 0;
    CUgcItemLook* pItemLook = FUN_140528380();
    MS2_ASSERT_MSG_AT(0x296, L"pItemLook != NULL", pItemLook != NULL);
    if (FUN_14026d4d0(pArg, pItemLook->unknown34, pItemLook->unknown38))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140526060, CItem, FUN_140526060, 145, 0x57D9062C);

// @0x140526850
bool CItem::FUN_140526850()
{
    if (!(!FUN_140527840()->FUN_14053cbc0() && FUN_140526c50() != 1 && FUN_1405257f0() != 0 && !FUN_140528e20()))
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140526850, CItem, FUN_140526850, 91, 0xCCCB08AA);

// ---- w98 batch 2: status (enchant) / transfer delegations
class Unk_ItemPlusInfo { public: int FUN_1408bbc50(); void FUN_1408bbcb0(int, bool); };

// @0x140526fc0
int CItem::FUN_140526fc0()
{
    if (m_spStatus == NULL)
        return 0;
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
        return 0;
    return pInfo->FUN_14058c5f0();
}
MS2_REPLACE_METHOD(0x140526FC0, CItem, FUN_140526fc0, 100, 0xC4F66D3A);

// @0x140527030
int CItem::FUN_140527030()
{
    if (m_spStatus == NULL)
        return 0;
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
        return 0;
    return pInfo->FUN_14058c8a0();
}
MS2_REPLACE_METHOD(0x140527030, CItem, FUN_140527030, 100, 0xBD08A65D);

// @0x1405270a0
int CItem::FUN_1405270a0()
{
    if (m_spStatus == NULL)
        return 0;
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
        return 0;
    return pInfo->FUN_14058c730();
}
MS2_REPLACE_METHOD(0x1405270A0, CItem, FUN_1405270a0, 100, 0xCC383426);

// @0x140527110
void CItem::FUN_140527110(int nExp)
{
    if (m_spStatus == NULL)
        return;
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
        return;
    pInfo->FUN_14058c7c0(nExp);
}
MS2_REPLACE_METHOD(0x140527110, CItem, FUN_140527110, 104, 0x12B5FEE3);

// @0x140527270
int CItem::FUN_140527270()
{
    if (m_spStatus == NULL)
        return 0;
    Unk_ItemPlusInfo* pInfo = m_spStatus->FUN_140630d90();
    if (pInfo == 0)
        return 0;
    return pInfo->FUN_1408bbc50();
}
MS2_REPLACE_METHOD(0x140527270, CItem, FUN_140527270, 100, 0x46C766FE);

// @0x140527360
bool CItem::FUN_140527360()
{
    if (m_a0 > 0)
    {
        m_a0 = m_a0 - 1;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140527360, CItem, FUN_140527360, 50, 0x6B1F3D35);

// @0x1405273a0
__int64 CItem::FUN_1405273a0()
{
    if (m_spTransfer.get() != 0)
        return m_spTransfer->FUN_140634fa0();
    return 0;
}
MS2_REPLACE_METHOD(0x1405273A0, CItem, FUN_1405273a0, 69, 0xCE7A4785);

// @0x1405273f0
void CItem::FUN_1405273f0(unsigned n)
{
    if (m_spTransfer.get() != 0)
        m_spTransfer->FUN_140634fc0(n);
}
MS2_REPLACE_METHOD(0x1405273F0, CItem, FUN_1405273f0, 73, 0x5F564C20);

// @0x140527440
__int64 CItem::FUN_140527440()
{
    if (m_spTransfer.get() != 0)
        return m_spTransfer->FUN_140634fe0();
    return 0;
}
MS2_REPLACE_METHOD(0x140527440, CItem, FUN_140527440, 69, 0xFB6124AE);

// @0x140527490
void CItem::FUN_140527490(unsigned n)
{
    if (m_spTransfer.get() != 0)
        m_spTransfer->FUN_140635000(n);
}
MS2_REPLACE_METHOD(0x140527490, CItem, FUN_140527490, 73, 0xB4A0DF13);

// @0x1405275f0
void CItem::FUN_1405275f0()
{
    if (m_spTransfer.get() != 0)
        m_spTransfer->FUN_140635300();
}
MS2_REPLACE_METHOD(0x1405275F0, CItem, FUN_1405275f0, 65, 0x42D1E6C9);

// @0x1405290b0
void CItem::FUN_1405290b0()
{
    if (!FUN_140527840()->FUN_14053cbc0())
    {
        m_b4 = 0;
        m_b0 = 0;
        return;
    }
    int nA = FUN_140526bd0();
    int nB = FUN_140527840()->FUN_14053c620();
    int nLevel = FUN_140526fc0();
    int nBase = FUN_140527840()->FUN_14053f0d0(nA);
    m_b4 = FUN_140527840()->FUN_14053f390(nBase, nLevel);
    int nPlus = FUN_140527270();
    if (0 < nPlus)
    {
        int nExtra = FUN_140527840()->FUN_14053e9e0();
        int nBonus = FUN_1401c0db0()->FUN_140678760(nPlus, nExtra, nB);
        m_b4 = m_b4 + nBonus;
    }
    m_b0 = m_b4 + nBase;
}
MS2_REPLACE_METHOD(0x1405290B0, CItem, FUN_1405290b0, 314, 0x1A68A1AB);

// @0x140526e60
bool CItem::FUN_140526e60(int nLevel, bool bFlag)
{
    if (m_spStatus == NULL)
    {
        MS2_ASSERT_MSG_AT(0xca8, L"FALSE", false);
        return false;
    }
    CItemEnchantInfo* pInfo = m_spStatus->FUN_140630d60();
    if (pInfo == 0)
    {
        MS2_ASSERT_MSG_AT(0xcaf, L"FALSE", false);
        return false;
    }
    pInfo->FUN_14058c6b0(nLevel, bFlag);
    if (bFlag)
    {
        FUN_1405290b0();
        vfunc_5(true);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140526E60, CItem, FUN_140526e60, 229, 0x7BD37AA2);

// @0x140527180
bool CItem::FUN_140527180(int nLevel, bool bFlag)
{
    if (m_spStatus == NULL)
    {
        MS2_ASSERT_MSG_AT(0xcf6, L"FALSE", false);
        return false;
    }
    Unk_ItemPlusInfo* pInfo = m_spStatus->FUN_140630d90();
    if (pInfo == 0)
    {
        MS2_ASSERT_MSG_AT(0xcfd, L"FALSE", false);
        return false;
    }
    pInfo->FUN_1408bbcb0(nLevel, bFlag);
    if (bFlag)
    {
        FUN_1405290b0();
        vfunc_5(true);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140527180, CItem, FUN_140527180, 229, 0x6E805001);

// @0x140526f50
void CItem::FUN_140526f50(unsigned nLevel, bool bFlag)
{
    if (!FUN_140526e60(nLevel, bFlag))
        return;
    CItemEnchantInfo* pInfo = FUN_1405278a0()->FUN_140630d60();
    if (pInfo != 0)
        pInfo->FUN_14058c830();
}
MS2_REPLACE_METHOD(0x140526F50, CItem, FUN_140526f50, 93, 0x5DBC915F);

// @0x14052a170
int CItem::FUN_14052a170()
{
    if (m_24 != -1)
        return m_24;
    int nKind = 0;
    if (FUN_140527840()->FUN_14053cf90())
        nKind = 1;
    else if (FUN_140527840()->FUN_14053e130())
        nKind = 0;
    else if (FUN_140527840()->property.flag08 != 0)
        nKind = 3;
    return nKind;
}
MS2_REPLACE_METHOD(0x14052A170, CItem, FUN_14052a170, 143, 0xF8F11542);

// @0x14052a3f0
bool FUN_14052a3f0(int nA, __int64 nB, int nC, int nD, int nE)
{
    bool bResult = false;
    if (nA != 0 && nB > 0)
        bResult = true;
    else if (nD != 0)
    {
        if (nD == 3 && nC == 1)
            bResult = true;
        else if (nD == 4 && nC == 2)
            bResult = true;
    }
    else
    {
        if (nE != 0 && nC != 0 && nE == nC)
            bResult = true;
    }
    return bResult;
}

// @0x14052a4f0
CStringW CItem::FUN_14052a4f0()
{
    MS2_ASSERT_MSG_AT(0xc2e, L"m_pMoveStoreChar != NULL", m_spBinding.get() != 0);
    return m_spBinding->FUN_14052d1b0();
}
MS2_REPLACE_METHOD(0x14052A4F0, CItem, FUN_14052a4f0, 136, 0x2B76F1F7);

// @0x14052a580
int CItem::FUN_14052a580(void* pArg)
{
    MS2_ASSERT_MSG_AT(0xc34, L"m_pMoveStoreChar != NULL", m_spBinding.get() != 0);
    if (m_spBinding->FUN_14052d1c0() == 0)
        return 1;
    return m_spBinding->FUN_140634790(pArg);
}
MS2_REPLACE_METHOD(0x14052A580, CItem, FUN_14052a580, 145, 0x2731BEF2);

// @0x14052d1b0
const CStringW& CItemTransfer::CItemBinding::FUN_14052d1b0()
{
    return m_str20;
}

// MS2-FUNCTIONAL: switch temporaries/slot layout differ from the exe (jump table and behaviour identical)
// @0x140528cc0
bool CItem::FUN_140528cc0()
{
    if (FUN_140528ca0() == 1)
        return false;
    if (FUN_140525ca0() == 1)
        return false;
    if (FUN_140525db0() == 1)
        return false;
    if (FUN_140525e00() == 1)
        return false;
    int nType = FUN_140527840()->FUN_14053c5c0();
    unsigned nIdx = nType - 1;
    switch (nIdx)
    {
    case 0:
    case 4:
    case 8:
    case 10:
    case 11:
    case 12:
    case 20:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140528CC0, CItem, FUN_140528cc0, 178, 0xE2BEDD66);

// @0x140528980
bool CItem::FUN_140528980()
{
    if (FUN_140528930() && FUN_140525640() == 0)
    {
        if (!FUN_140527840()->FUN_14053cde0())
            return false;
    }
    if (FUN_140527840()->FUN_14053cd10())
    {
        if (!FUN_140525730() && FUN_140527340() < 1)
            return false;
        if (FUN_140525680())
        {
            CItemCustomMusicScore* pScore = FUN_140527990();
            if (pScore == 0)
                return false;
            if (pScore->m_n38 != 0 && pScore->m_n38 != 1)
                return false;
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140528980, CItem, FUN_140528980, 210, 0xC3F33C70);

// @0x140525680
bool CItem::FUN_140525680()
{
    if (!FUN_1405277b0()->FUN_14053cd10())
        return false;
    MS2Ptr<Unk_IngItem> spIng = FUN_140281980()->FUN_1405565f0(FUN_1405276c0());
    if (spIng == 0)
        return false;
    return spIng->FUN_14054aca0();
}
MS2_REPLACE_METHOD(0x140525680, CItem, FUN_140525680, 170, 0x68FB8AA6);

// @0x140525980
int CItem::FUN_140525980()
{
    return FUN_1405258f0() || FUN_140525920() || FUN_140525950();
}
MS2_REPLACE_METHOD(0x140525980, CItem, FUN_140525980, 78, 0xEC17A787);

// @0x140525a80
int CItem::FUN_140525a80()
{
    if (m_spData.IsNull())
        return 0;
    switch (m_spData->FUN_14053c5c0())
    {
    case 1:
        if (FUN_140525f10() != 0 && FUN_140525f60() == 0)
            return 1;
        break;
    case 2:
    case 5:
    case 9:
    case 0xb:
    case 0xc:
    case 0x18:
        return 1;
    }
    if (m_spData->FUN_14053cd90())
    {
        CStringW* pName = &m_spData->function.name;
        if (FUN_1403b3c40(*pName, L"RecallParty") || FUN_1403b3c40(*pName, L"TreasureMap"))
            return 0;
        return 1;
    }
    if ((unsigned)m_spData->FUN_14053ddb0() > 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140525A80, CItem, FUN_140525a80, 340, 0x9FD5B6B6);

// @0x140526190
int CItem::FUN_140526190()
{
    if (FUN_140526160() == 1)
    {
        GachaBoxDataPtr spBox = FUN_14052d230()->FUN_14059e340(FUN_140529640());
        if (spBox == 0)
            return 0;
        MS2Ptr<CItemData> spCoin = FUN_14053f870(spBox->m_nCoinItemID);
        if (spCoin == 0)
            return 0;
        if (spBox->m_nCoinItemAmount == 0)
            return 0;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140526190, CItem, FUN_140526190, 294, 0x9B68AECD);

// @0x140526390
int CItem::FUN_140526390()
{
    if (m_spData == 0)
        return 0;
    if (m_spData->FUN_14053e670())
        return 1;
    CItemSocket* pSocket = FUN_1405279c0();
    if (pSocket != 0 && pSocket->FUN_140620de0())
        return 1;
    if (m_spStatus.get() != 0)
    {
        if (m_spStatus->m_spOption->FUN_1405cbc90() != 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140526390, CItem, FUN_140526390, 213, 0xDBB250D2);

// @0x140526470
void CItem::FUN_140526470(unsigned nSlot)
{
    unsigned nResult;
    if (FUN_140525640())
        FUN_140526670(nSlot, &nResult);
    else
        FUN_1405264c0(nSlot, &nResult);
}
MS2_REPLACE_METHOD(0x140526470, CItem, FUN_140526470, 72, 0x8C36A151);

// @0x1405264c0
int CItem::FUN_1405264c0(int nSlot, unsigned* pResult)
{
    if (m_spData.IsNull())
    {
        *pResult = 1;
        return false;
    }
    if (FUN_140526bd0() < 4)
    {
        *pResult = 7;
        return false;
    }
    if (!m_spData->FUN_14053d600() && !m_spData->FUN_14053d5c0())
    {
        *pResult = 8;
        return false;
    }
    if (m_spData->limit.levelLimit < FUN_14036dc40(FUN_140166410()))
    {
        *pResult = 4;
        return false;
    }
    if (m_spData->property.remakeDisable == 1)
    {
        *pResult = 2;
        return false;
    }
    if (m_spStatus->m_spOption->FUN_1405cbbb0(nSlot) == 0)
    {
        *pResult = 6;
        return false;
    }
    *pResult = 0;
    return true;
}
MS2_REPLACE_METHOD(0x1405264C0, CItem, FUN_1405264c0, 378, 0x2F4CADF4);

// @0x140526640
void CItem::FUN_140526640(unsigned nSlot)
{
    unsigned nResult;
    FUN_140526670(nSlot, &nResult);
}
MS2_REPLACE_METHOD(0x140526640, CItem, FUN_140526640, 37, 0x01B62087);

// @0x140526670
int CItem::FUN_140526670(int nSlot, unsigned* pResult)
{
    if (m_spData.IsNull())
    {
        *pResult = 1;
        return false;
    }
    if (FUN_140526bd0() < 3)
    {
        *pResult = 7;
        return false;
    }
    if (!m_spData->FUN_14053cc40())
    {
        *pResult = 8;
        return false;
    }
    if (m_spData->property.remakeDisable == 1)
    {
        *pResult = 2;
        return false;
    }
    if (m_spStatus->m_spOption->FUN_1405cbbb0(nSlot) == 0)
    {
        *pResult = 6;
        return false;
    }
    *pResult = 0;
    return true;
}
MS2_REPLACE_METHOD(0x140526670, CItem, FUN_140526670, 273, 0x5F65DE16);

// The TSingleton<T>::GetInstance bodies this unit instantiates (the s_instance statics are the exe's own data).
// @0x14052d1d0
void* FUN_14052d1d0()
{
    return DAT_143aaf1a8;
}

// @0x14052d1e0
void* FUN_14052d1e0()
{
    return DAT_143aaf1b0;
}

// @0x14052d1f0
void* FUN_14052d1f0()
{
    return DAT_143aaf1b8;
}

// @0x14052d200
void* FUN_14052d200()
{
    return DAT_143aaf1c0;
}

// @0x14052d210
Unk_SingletonObj* FUN_14052d210()
{
    return DAT_143aaf1c8;
}

// @0x14052d220
Unk_SingletonObj* FUN_14052d220()
{
    return DAT_143aaf1d8;
}

// @0x14052d230
ItemGachaBoxTable* FUN_14052d230()
{
    return TSingleton<ItemGachaBoxTable>::s_instance;
}
