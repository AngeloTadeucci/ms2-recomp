// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item gems: the 12 gem types (CGemBase and subclasses) and
// their holder CItemGem; see itemgem.h. The unit also holds the COMDAT tail of their MS2Ptr<> smart pointers and of the
// CAtlMap<int,int> that maps equip slots to the gem transparency table.
// MS2-UNIT: ?\itemgem.cpp
// MS2-RANGE: 0x1400ba010-0x1400ba1d0 .text$di
// MS2-RANGE: 0x1405a3940-0x1405abd00 .text$mn
// MS2-RANGE: 0x142c9b050-0x142c9b100 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VCGemBase@@@@QEAA@$$QEAV0@@Z 0x1405a7e00 ; unique
// MS2-PIN: ??1?$MS2Ptr@VUnk_PCBaseComp_aa8@@@@QEAA@XZ 0x1405a8980 ; prop
// MS2-PIN: ??1?$MS2Ptr@VCGemTransparency@@@@QEAA@XZ 0x1405a89b0 ; prop
// MS2-PIN: ??4?$MS2Ptr@VCGemBase@@@@QEAAAEAV0@AEBV0@@Z 0x1405a8a20 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VCEquipItem@@@@QEBAPEAVCEquipItem@@XZ 0x1405a8e70 ; prop
// MS2-PIN: ?get@?$MS2Ptr@VUnk_PCBaseComp_aa8@@@@QEBAPEAVUnk_PCBaseComp_aa8@@XZ 0x1405a8eb0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VUnk_PCBaseComp_a78@@@@QEBAPEAVUnk_PCBaseComp_a78@@XZ 0x1405a8ec0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCEquipItem@@@@QEBAPEAVCEquipItem@@XZ 0x1405a8ed0 ; prop
// MS2-PIN: ??C?$MS2Ptr@VCGemTransparency@@@@QEBAPEAVCGemTransparency@@XZ 0x1405a8f30 ; unique
// MS2-PIN: ??C?$MS2Ptr@VUnk_PCBaseComp_aa8@@@@QEBAPEAVUnk_PCBaseComp_aa8@@XZ 0x1405a8f40 ; prop
// MS2-PIN: ?vfunc_1@CGemCharEffect@@UEAAHXZ 0x1405a9a60 ; unique
// MS2-PIN: ?vfunc_1@CGemChatBalloon@@UEAAHXZ 0x1405a9a70 ; unique
// MS2-PIN: ?vfunc_1@CGemEffect@@UEAAHXZ 0x1405a9a80 ; unique
// MS2-PIN: ?vfunc_1@CGemNametag@@UEAAHXZ 0x1405a9a90 ; unique
// MS2-PIN: ?vfunc_1@CGemTransparency@@UEAAHXZ 0x1405a9aa0 ; unique
// MS2-PIN: ?vfunc_9@CGemPetSkin@@UEAAHXZ 0x1405a9b20 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_PCBaseComp_aa8@@@@CAXPEAVUnk_PCBaseComp_aa8@@@Z 0x1405aaca0 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VCGemTransparency@@@@AEAAXXZ 0x1405ab510 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCItem@@@@AEAAXPEAX@Z 0x1405abaf0 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_PCBaseComp_aa8@@@@AEAAXPEAX@Z 0x1405abb40 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ?Release@?$MS2Ptr@VCGemEffectData@@@@AEAAXXZ 0x1405ab250
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCGemEffectData@@@@AEAAXPEAX@Z 0x1405ab820
// MS2-PIN: ?Reference@?$MS2Ptr@VCGemEffectData@@@@CAXPEAVCGemEffectData@@@Z 0x1405aab60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemgem.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include "itemgem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/clonepc.h"
#include "ms2/client/ms2/uichatballoon.h"
#include "ms2/client/ms2/uinametag.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The gem transparency table: equip slot -> the equip part constant it hides. Filled by the first CGemTransparency.
enum Unk_GemSlot { Unk_GemSlot_0, Unk_GemSlot_1, Unk_GemSlot_2, Unk_GemSlot_3, Unk_GemSlot_4, Unk_GemSlot_5, Unk_GemSlot_6,
    Unk_GemSlot_7, Unk_GemSlot_8, Unk_GemSlot_9 };
static ATL::CAtlMap<Unk_GemSlot, unsigned> s_mapGemSlots;                                      // 0x143aafcc0
// The statics of the common header, constructed after the map.
#include "ms2/placeholder/header_statics_a.h"

// The actor components behind PCBase slots 82 / 85 (see pcbase.h): the name tag and chat balloon entities.
class Unk_PCBaseComp_a78 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred {};

// The client config singleton: the equip slots' constants of the transparency gem start at +0x3050 (stride 0x58).
class Unk_IdleChance
{
public:
    unsigned FUN_140536a30();                                       // 0x140536a30
    char m_pad[0x58];
};
struct Unk_BannerCfg
{
    char m_pad_00[0x3050];
    Unk_IdleChance m_slot0, m_slot1, m_slot2, m_slot3, m_slot4, m_slot5, m_slot6, m_slot7, m_slot8, m_slot9;    // +0x3050
};
Unk_BannerCfg* FUN_1401d3200();                                     // 0x1401d3200

// The cast of an actor to ClonePC (class id 0x6200044), NULL when it is none.
ClonePC* FUN_1405a7e30(PC* pPC);                                    // 0x1405a7e30
__int64 FUN_14028d0e0();                                            // 0x14028d0e0
void FUN_140526b30(CItem* pItem, int nOwnerId);                     // 0x140526b30
CItemData* FUN_140527840(CItem* pItem);                             // 0x140527840
Unk_PCEquipSet* FUN_1416561a0(PC* pPC);                             // 0x1416561a0
CString FUN_140719190(int nValue);                                  // 0x140719190

// A view of the item data (CItemData +0x78: a flag the gem items set).
struct Unk_GemItemDataFlags
{
    char m_pad[0x78];
    bool m_bGemItem;                                                // +0x78
};


// The pet table (FUN_14052d210) and its row.
struct Unk_GemPetRow
{
    int FUN_1407287e0(int nKind);                                   // 0x1407287e0 the item id of the pet's skin
};
class Unk_GemPetTable
{
public:
    MS2Ptr<Unk_GemPetRow> FUN_1407290f0(int nPetId);                // 0x1407290f0
};
Unk_GemPetTable* FUN_14052d210();                                   // 0x14052d210
template <> MS2Ptr<Unk_GemPetRow>::~MS2Ptr();                       // 0x14052c420
template <> Unk_GemPetRow* MS2Ptr<Unk_GemPetRow>::operator->() const;   // 0x14052ceb0
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                       // 0x14053f870

// The UI manager (FUN_1403ed2b0): a gem that shows an effect of its own registers with it.
class Unk_UiManager
{
public:
    void FUN_141ad9d00(MS2Ptr<CGemBase> spGem);                     // 0x141ad9d00
};
Unk_UiManager* FUN_1403ed2b0();                                     // 0x1403ed2b0
class Unk_StringTable
{
public:
    CStringW FUN_141811980(int nTable, int nId, int nFlags);        // 0x141811980
};
Unk_StringTable* FUN_1401a9d70();                                   // 0x1401a9d70

// The effect manager (FUN_1403ed280).
class Unk_RideeEffects
{
public:
    int FUN_1411a49c0(Unk_EffectQuery* pQuery);                     // spawn, returns the handle
    void FUN_1411a6060(int nHandle);                                // release
};
Unk_RideeEffects* FUN_1403ed280();                                  // 0x1403ed280

// The actor's equipment (FUN_14165f460 hands it out as a void*): the gem items' worn-item calls.
class Unk_GemEquipment
{
public:
    bool FUN_141271090(MS2Ptr<CItem> spItem, const CString& strEffect);     // 0x141271090 equip an effect item
    void FUN_1412711e0(MS2Ptr<CItem> spItem);                       // 0x1412711e0
};
void* FUN_14165f460(PC* pPC);                                       // 0x14165f460
int FUN_141658e60(PCBase* pPC);                                     // 0x141658e60 the partner gem id of an actor
void FUN_1416636e0(PC* pPC, MS2Ptr<CItem> spItem, int nGemId);      // 0x1416636e0
void FUN_141663870(PC* pPC);                                        // 0x141663870
CString FUN_1405a7e80(int nValue);                                  // 0x1405a7e80

int FUN_1405a46d0(int nSlot);                                        // 0x1405a46d0 the equip part constant of a slot

// @0x1405a3940
CGemBase::CGemBase(int nType, int nGemId)
{
    m_nType = nType;
    m_nGemId = nGemId;
}

// @0x1405a39a0
CGemBase::~CGemBase()
{
}

// @0x1405a39d0
int CGemBase::vfunc_1()
{
    return m_nType;
}

// @0x1405a39f0
int CGemBase::FUN_1405a39f0()
{
    return m_nGemId;
}

// @0x1405a3a10
void CGemBase::vfunc_2(COutputStream& stream)
{
}

// @0x1405a3a30
void CGemBase::vfunc_3(CInputStream& stream)
{
}

// @0x1405a3a50
MS2Ptr<CGemBase> CGemBase::vfunc_4()
{
    return MS2Ptr<CGemBase>(0);
}

// @0x1405a3a90
int CGemBase::vfunc_5(PC* pPC, MS2Ptr<CItem> spItem)
{
    return 1;
}

// @0x1405a3ad0
int CGemBase::vfunc_6(PC* pPC, MS2Ptr<CItem> spItem)
{
    return 1;
}

// @0x1405a3b10
int CGemBase::vfunc_7(PC* pPC, MS2Ptr<CItem> spItem)
{
    return 1;
}

// @0x1405a3b50
void CGemBase::vfunc_8()
{
}

// @0x1405a3b60
int CGemBase::vfunc_9()
{
    return 0;
}

// @0x1405a3b70
CString CGemBase::vfunc_10()
{
    return "";
}

// @0x1405a3bc0
CStringW CGemBase::vfunc_11()
{
    return L"";
}

// @0x1405a3c10
CGemTransparency::CGemTransparency(int nType, int nGemId) : CGemBase(nType, nGemId)
{
    for (size_t i = 0; i < 10; i++)
        m_aHidden[i] = 0;
    if (s_mapGemSlots.GetCount() == 0)
    {
        s_mapGemSlots.SetAt(Unk_GemSlot_0, FUN_1401d3200()->m_slot0.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_1, FUN_1401d3200()->m_slot1.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_2, FUN_1401d3200()->m_slot2.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_3, FUN_1401d3200()->m_slot3.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_4, FUN_1401d3200()->m_slot4.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_5, FUN_1401d3200()->m_slot5.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_6, FUN_1401d3200()->m_slot6.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_7, FUN_1401d3200()->m_slot7.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_8, FUN_1401d3200()->m_slot8.FUN_140536a30());
        s_mapGemSlots.SetAt(Unk_GemSlot_9, FUN_1401d3200()->m_slot9.FUN_140536a30());
    }
}

// @0x1405a3e90
CGemTransparency::CGemTransparency(const CGemTransparency& o) : CGemBase(o.m_nType, o.m_nGemId)
{
}

// @0x1405a3ee0
CGemTransparency::~CGemTransparency()
{
}

// @0x1405a3f10
void CGemTransparency::vfunc_2(COutputStream& stream)
{
    CGemBase::vfunc_2(stream);
    for (size_t i = 0; i < 10; i++)
        stream.vfunc_o10_1(m_aHidden[i] != 0);
}

// @0x1405a3f90
void CGemTransparency::vfunc_3(CInputStream& stream)
{
    CGemBase::vfunc_3(stream);
    for (size_t i = 0; i < 10; i++)
        m_aHidden[i] = stream.vfunc_o8_1();
}

// @0x1405a4000
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
MS2Ptr<CGemBase> CGemTransparency::vfunc_4()
{
    MS2Ptr<CGemTransparency> spGem(new CGemTransparency(*this));
    for (size_t i = 0; i < 10; i++)
    {
        int nHidden = FUN_1405a4140((int)i);
        spGem->FUN_1405a4100((int)i, nHidden);
    }
    return MS2Ptr<CGemBase>((MS2Ptr<CGemBase>&&)spGem);
}

// @0x1405a4100
void CGemTransparency::FUN_1405a4100(int nSlot, int nHidden)
{
    if (nSlot < 0 || nSlot >= 10)
        return;
    m_aHidden[nSlot] = nHidden;
}

// @0x1405a4140
int CGemTransparency::FUN_1405a4140(int nSlot)
{
    if (nSlot < 0 || nSlot >= 10)
        return 0;
    return m_aHidden[nSlot];
}

// @0x1405a4170
int CGemTransparency::vfunc_5(PC* pPC, MS2Ptr<CItem> spItem)
{
    return vfunc_6(pPC, spItem);
}

// @0x1405a41f0
int CGemTransparency::vfunc_6(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_6(pPC, spItem) == 0)
        return 0;
    ClonePC* pClone = FUN_1405a7e30(pPC);
    if (pClone != 0 && pClone->FUN_141088590() == 0)
        return 0;
    for (POSITION pos = s_mapGemSlots.GetStartPosition(); pos != 0; s_mapGemSlots.GetNext(pos))
    {
        int nSlot = s_mapGemSlots.GetKeyAt(pos);
        unsigned nItemId = s_mapGemSlots.GetValueAt(pos);
        MS2Ptr<CItem> spNew(new CItem);
        if (spNew->FUN_140523c40(nItemId, 1, 0))
        {
            spNew->FUN_140526a70(FUN_14028d0e0());
            spNew->FUN_140526c10(FUN_1405a46d0(nSlot));
            FUN_140526b30(spNew.operator->(), pPC->FUN_14123c580());
            {
                MS2Ptr<CItemData> spData(FUN_140527840(spNew.operator->()));
                if (spData.get() != 0)
                    ((Unk_GemItemDataFlags*)(void*)spData.operator->())->m_bGemItem = true;
            }
            if (FUN_1405a4140(nSlot) != 0)
                pPC->vfunc_127(spNew.get(), 0);
            else
                pPC->vfunc_128(spNew.get(), 0);
        }
    }
    return 1;
}

// @0x1405a4520
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemTransparency::vfunc_7(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_7(pPC, spItem) == 0)
        return 0;
    for (POSITION pos = s_mapGemSlots.GetStartPosition(); pos != 0; s_mapGemSlots.GetNext(pos))
    {
        Unk_GemSlot nSlot = s_mapGemSlots.GetKeyAt(pos);
        MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(pPC)->FUN_1411e1780(FUN_1405a46d0(nSlot), 3);
        if (spEquip.get() != 0)
        {
            MS2Ptr<CItem> spWorn = spEquip->FUN_1411dc7a0();
            pPC->vfunc_128(spWorn.get(), 0);
        }
    }
    return 1;
}

// @0x1405a46d0
int FUN_1405a46d0(int nSlot)
{
    if (nSlot == 0)
        return 0x6;
    if (nSlot == 1)
        return 0xd;
    if (nSlot == 2)
        return 0x8;
    if (nSlot == 3)
        return 0x9;
    if (nSlot == 4)
        return 0x7;
    if (nSlot == 5)
        return 0xe;
    if (nSlot == 6)
        return 0xc;
    if (nSlot == 7)
        return 0xa;
    if (nSlot == 8)
        return 0x10;
    if (nSlot == 9)
        return 0xb;
    return 0;
}

// @0x1405a4770
CGemChatBalloon::CGemChatBalloon(int nType, int nGemId) : CGemBase(nType, nGemId)
{
}

// @0x1405a47c0
CGemChatBalloon::CGemChatBalloon(const CGemChatBalloon& o) : CGemBase(o.m_nType, o.m_nGemId)
{
}

// @0x1405a4810
CGemChatBalloon::~CGemChatBalloon()
{
}

// @0x1405a48a0
MS2Ptr<CGemBase> CGemChatBalloon::vfunc_4()
{
    MS2Ptr<CGemChatBalloon> spGem(new CGemChatBalloon(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a4cd0
CGemNametag::CGemNametag(int nType, int nGemId) : CGemBase(nType, nGemId)
{
}

// @0x1405a4d20
CGemNametag::CGemNametag(const CGemNametag& o) : CGemBase(o.m_nType, o.m_nGemId)
{
}

// @0x1405a4d70
CGemNametag::~CGemNametag()
{
}

// @0x1405a4da0
MS2Ptr<CGemBase> CGemNametag::vfunc_4()
{
    MS2Ptr<CGemNametag> spGem(new CGemNametag(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a51d0
CGemTombStone::CGemTombStone(int nType, int nGemId) : CGemBase(nType, nGemId)
{
    m_nDataId = nGemId;
}

// @0x1405a5240
CGemTombStone::CGemTombStone(const CGemTombStone& o) : CGemBase(o.m_nType, o.m_nGemId)
{
    m_nDataId = o.m_nDataId;
    m_spData = o.m_spData;
}

// @0x1405a52d0
CGemTombStone::~CGemTombStone()
{
}

// @0x1405a5310
MS2Ptr<CGemBase> CGemTombStone::vfunc_4()
{
    MS2Ptr<CGemTombStone> spGem(new CGemTombStone(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a5530
CGemSwim::CGemSwim(int nType, int nGemId) : CGemBase(nType, nGemId)
{
    m_nDataId = nGemId;
}

// @0x1405a55a0
CGemSwim::CGemSwim(const CGemSwim& o) : CGemBase(o.m_nType, o.m_nGemId)
{
    m_nDataId = o.m_nDataId;
    m_spData = o.m_spData;
}

// @0x1405a5630
CGemSwim::~CGemSwim()
{
}

// @0x1405a5670
MS2Ptr<CGemBase> CGemSwim::vfunc_4()
{
    MS2Ptr<CGemSwim> spGem(new CGemSwim(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a5870
CGemDamageFont::CGemDamageFont(int nType, int nGemId) : CGemBase(nType, nGemId)
{
}

// @0x1405a58c0
CGemDamageFont::CGemDamageFont(const CGemDamageFont& o) : CGemBase(o.m_nType, o.m_nGemId)
{
}

// @0x1405a5910
CGemDamageFont::~CGemDamageFont()
{
}

// @0x1405a5940
MS2Ptr<CGemBase> CGemDamageFont::vfunc_4()
{
    MS2Ptr<CGemDamageFont> spGem(new CGemDamageFont(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a5a50
CGemFishing::CGemFishing(int nType, int nGemId) : CGemBase(nType, nGemId)
{
    m_nDataId = nGemId;
}

// @0x1405a5aa0
CGemFishing::CGemFishing(const CGemFishing& o) : CGemBase(o.m_nType, o.m_nGemId)
{
    m_nDataId = o.m_nDataId;
}

// @0x1405a5b00
CGemFishing::~CGemFishing()
{
}

// @0x1405a5b30
MS2Ptr<CGemBase> CGemFishing::vfunc_4()
{
    MS2Ptr<CGemFishing> spGem(new CGemFishing(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a5c00
CGemCharEffect::CGemCharEffect(int nType, int nGemId) : CGemBase(nType, nGemId), m_listEffects(10)
{
    m_nDataId = nGemId;
}

// @0x1405a5c90
CGemCharEffect::CGemCharEffect(const CGemCharEffect& o) : CGemBase(o.m_nType, o.m_nGemId), m_listEffects(10)
{
    m_nDataId = o.m_nDataId;
}

// @0x1405a5d20
CGemCharEffect::~CGemCharEffect()
{
}

// @0x1405a5d70
MS2Ptr<CGemBase> CGemCharEffect::vfunc_4()
{
    MS2Ptr<CGemCharEffect> spGem(new CGemCharEffect(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a62f0
CGemAutoMastery::CGemAutoMastery(int nType, int nGemId) : CGemBase(nType, nGemId)
{
}

// @0x1405a6340
CGemAutoMastery::CGemAutoMastery(const CGemAutoMastery& o) : CGemBase(o.m_nType, o.m_nGemId)
{
}

// @0x1405a6390
CGemAutoMastery::~CGemAutoMastery()
{
}

// @0x1405a63c0
MS2Ptr<CGemBase> CGemAutoMastery::vfunc_4()
{
    MS2Ptr<CGemAutoMastery> spGem(new CGemAutoMastery(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a6470
CGemEffect::CGemEffect(int nType, int nGemId) : CGemBase(nType, nGemId)
{
    m_nDataId = nGemId;
}

// @0x1405a64e0
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
CGemEffect::CGemEffect(const CGemEffect& o) : CGemBase(o.m_nType, o.m_nGemId)
{
    m_nDataId = o.m_nDataId;
    m_spData = o.m_spData;
}

// @0x1405a6560
CGemEffect::~CGemEffect()
{
}

// @0x1405a65a0
MS2Ptr<CGemBase> CGemEffect::vfunc_4()
{
    MS2Ptr<CGemEffect> spGem(new CGemEffect(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a69d0
CGemPetSkin::CGemPetSkin(int nType, int nGemId) : CGemBase(nType, nGemId)
{
    m_nDataId = 0;
    m_nPetId = 0;
    m_nDataId = nGemId;
}

// @0x1405a6a40
CGemPetSkin::CGemPetSkin(const CGemPetSkin& o) : CGemBase(o.m_nType, o.m_nGemId)
{
    m_nDataId = o.m_nDataId;
    m_nPetId = o.m_nPetId;
}

// @0x1405a6ab0
CGemPetSkin::~CGemPetSkin()
{
}

// @0x1405a6ae0
MS2Ptr<CGemBase> CGemPetSkin::vfunc_4()
{
    MS2Ptr<CGemPetSkin> spGem(new CGemPetSkin(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a6db0
CGemMeta::CGemMeta(int nType, int nGemId) : CGemBase(nType, nGemId)
{
}

// @0x1405a6e00
CGemMeta::CGemMeta(const CGemMeta& o) : CGemBase(o.m_nType, o.m_nGemId)
{
}

// @0x1405a6e50
CGemMeta::~CGemMeta()
{
}

// @0x1405a6e80
MS2Ptr<CGemBase> CGemMeta::vfunc_4()
{
    MS2Ptr<CGemMeta> spGem(new CGemMeta(*this));
    return MS2Ptr<CGemBase>(spGem.get());
}

// @0x1405a4840
void CGemChatBalloon::vfunc_2(COutputStream& stream)
{
    CGemBase::vfunc_2(stream);
}

// @0x1405a4870
void CGemChatBalloon::vfunc_3(CInputStream& stream)
{
    CGemBase::vfunc_3(stream);
}

// @0x1405a4950
int CGemChatBalloon::vfunc_5(PC* pPC, MS2Ptr<CItem> spItem)
{
    return vfunc_6(pPC, spItem);
}

// @0x1405a49d0
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemChatBalloon::vfunc_6(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_6(pPC, spItem) == 0)
        return 0;
    if (pPC->vfunc_85().get() != 0)
        ((UIChatBalloon::Entity*)(void*)pPC->vfunc_85().operator->())->FUN_1418fb6f0(FUN_1405a7e80(m_nGemId));
    return 1;
}

// @0x1405a4b60
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemChatBalloon::vfunc_7(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_7(pPC, spItem) == 0)
        return 0;
    if (pPC->vfunc_85().get() != 0)
        ((UIChatBalloon::Entity*)(void*)pPC->vfunc_85().operator->())->FUN_1418fb6f0(CString(""));
    return 1;
}

// @0x1405a4e50
int CGemNametag::vfunc_5(PC* pPC, MS2Ptr<CItem> spItem)
{
    return vfunc_6(pPC, spItem);
}

// @0x1405a4ed0
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemNametag::vfunc_6(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_6(pPC, spItem) == 0)
        return 0;
    if (pPC->vfunc_82().get() != 0)
        ((UINameTag::Entity*)(void*)pPC->vfunc_82().operator->())->FUN_141a5f040(FUN_1405a7e80(m_nGemId));
    return 1;
}

// @0x1405a5060
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemNametag::vfunc_7(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_7(pPC, spItem) == 0)
        return 0;
    if (pPC->vfunc_82().get() != 0)
        ((UINameTag::Entity*)(void*)pPC->vfunc_82().operator->())->FUN_141a5f040(CString(""));
    return 1;
}

// @0x1405a53c0
MS2Ptr<CGemTombStoneData> CGemTombStone::FUN_1405a53c0()
{
    bool bLoad = (m_spData == 0) ? true : false;
    bLoad = true;
    if (bLoad)
        m_spData.AssignRaw(dynamic_cast<CGemTombStoneData*>(FUN_1405a96f0()->FUN_1405ac160(m_nDataId).get()));
    return m_spData;
}

// @0x1405a54c0
void CGemTombStone::vfunc_8()
{
    if (m_spData.get() != 0)
    {
        m_spData->m_attrA.FUN_1405ac670();
        m_spData->m_attrB.FUN_1405ac670();
    }
}

// @0x1405a5720
MS2Ptr<CGemSwimData> CGemSwim::FUN_1405a5720()
{
    bool bLoad = (m_spData == 0) ? true : false;
    bLoad = true;
    if (bLoad)
        m_spData.AssignRaw(dynamic_cast<CGemSwimData*>(FUN_1405a96f0()->FUN_1405ac160(m_nDataId).get()));
    return m_spData;
}

// @0x1405a5820
void CGemSwim::vfunc_8()
{
    if (m_spData.get() != 0)
        m_spData->FUN_1405ac9e0();
}

// @0x1405a59f0
void CGemDamageFont::vfunc_8()
{
    FUN_1403ed2b0()->FUN_141ad9d00(MS2Ptr<CGemBase>(this));
}

// @0x1405a6f30
void CGemMeta::vfunc_8()
{
    FUN_1403ed2b0()->FUN_141ad9d00(MS2Ptr<CGemBase>(this));
}

// @0x1405a5be0
int CGemFishing::FUN_1405a5be0()
{
    return m_nDataId;
}

// @0x1405a5e20
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemCharEffect::vfunc_6(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_6(pPC, spItem) == 0)
        return 0;
    if (FUN_1405a7e30(pPC) != 0)
        return 0;
    MS2Ptr<CGemCharEffectData> spData = FUN_1405a61f0();
    if (spData == 0)
        return 0;
    Unk_EffectQuery query;
    query.m_strName = spData->FUN_1405acbd0(FUN_141658e60(pPC));
    query.m_nObject = 0;
    query.FUN_140a53190(pPC->FUN_14123c580());
    int nHandle = FUN_1403ed280()->FUN_1411a49c0(&query);
    if (nHandle != 0)
        m_listEffects.AddTail(nHandle);
    FUN_1416636e0(pPC, spItem, m_nDataId);
    return 1;
}

// @0x1405a6080
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemCharEffect::vfunc_7(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_7(pPC, spItem) == 0)
        return 0;
    if (FUN_1405a7e30(pPC) != 0)
        return 0;
    POSITION pos = m_listEffects.GetHeadPosition();
    while (pos != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_listEffects.GetAt(pos));
        m_listEffects.GetNext(pos);
    }
    m_listEffects.RemoveAll();
    FUN_141663870(pPC);
    return 1;
}

// @0x1405a61f0
MS2Ptr<CGemCharEffectData> CGemCharEffect::FUN_1405a61f0()
{
    bool bLoad = (m_spData == 0) ? true : false;
    bLoad = true;
    if (bLoad)
        m_spData.AssignRaw(dynamic_cast<CGemCharEffectData*>(FUN_1405a96f0()->FUN_1405ac160(m_nDataId).get()));
    return m_spData;
}

// @0x1405a6650
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemEffect::vfunc_6(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (CGemBase::vfunc_6(pPC, spItem) == 0)
        return 0;
    MS2Ptr<CGemEffectData> spData = FUN_1405a68d0();
    if (spData == 0)
        return 0;
    const CString* pstrEffect = &spData->m_strEffect;
    if (((Unk_GemEquipment*)FUN_14165f460(pPC))->FUN_141271090(spItem, *pstrEffect) == 0)
        return 0;
    return 1;
}

// @0x1405a67e0
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
int CGemEffect::vfunc_7(PC* pPC, MS2Ptr<CItem> spItem)
{
    int nResult = CGemBase::vfunc_7(pPC, spItem);
    if (nResult != 0)
        ((Unk_GemEquipment*)FUN_14165f460(pPC))->FUN_1412711e0(spItem);
    return nResult != 0;
}

// @0x1405a68d0
MS2Ptr<CGemEffectData> CGemEffect::FUN_1405a68d0()
{
    bool bLoad = (m_spData == 0) ? true : false;
    bLoad = true;
    if (bLoad)
        m_spData.AssignRaw(dynamic_cast<CGemEffectData*>(FUN_1405a96f0()->FUN_1405ac160(m_nDataId).get()));
    return m_spData;
}

// @0x1405a6b90
void CGemPetSkin::vfunc_2(COutputStream& stream)
{
    CGemBase::vfunc_2(stream);
    stream.vfunc_o10_3(m_nPetId);
}

// @0x1405a6bd0
void CGemPetSkin::vfunc_3(CInputStream& stream)
{
    CGemBase::vfunc_3(stream);
    m_nPetId = stream.vfunc_o8_3();
}

// @0x1405a6c10
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
CString CGemPetSkin::vfunc_10()
{
    MS2Ptr<Unk_GemPetRow> spPet = FUN_14052d210()->FUN_1407290f0(m_nPetId);
    if (!spPet.IsNull())
    {
        MS2Ptr<CItemData> spItem = FUN_14053f870(spPet->FUN_1407287e0(1));
        if (!spItem.IsNull())
            return spItem->FUN_14053fdd0();
    }
    return CString("");
}

// @0x1405a6d50
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
CStringW CGemPetSkin::vfunc_11()
{
    return FUN_1401a9d70()->FUN_141811980(0x3b, m_nPetId, 0);
}

// @0x1405a6f90
CItemGem::CItemGem()
{
}

// @0x1405a6fe0
CItemGem::~CItemGem()
{
}

// @0x1405a7020
// MS2-FUNCTIONAL: equivalent typed body; cl orders the returned-temp / stack-slot handling differently (extra temp or frame size); no source form found
bool CItemGem::FUN_1405a7020(int nType, int nGemId)
{
    switch (nType)
    {
    case 1:
        m_spGem.AssignRaw(new CGemTransparency(nType, nGemId));
        break;
    case 2:
        m_spGem.AssignRaw(new CGemDamageFont(nType, nGemId));
        break;
    case 3:
        m_spGem.AssignRaw(new CGemChatBalloon(nType, nGemId));
        break;
    case 4:
        m_spGem.AssignRaw(new CGemNametag(nType, nGemId));
        break;
    case 5:
        m_spGem.AssignRaw(new CGemTombStone(nType, nGemId));
        break;
    case 6:
        m_spGem.AssignRaw(new CGemSwim(nType, nGemId));
        break;
    case 7:
        m_spGem.AssignRaw(new CGemCharEffect(nType, nGemId));
        break;
    case 8:
        m_spGem.AssignRaw(new CGemFishing(nType, nGemId));
        break;
    case 9:
        m_spGem.AssignRaw(new CGemAutoMastery(nType, nGemId));
        break;
    case 10:
        m_spGem.AssignRaw(new CGemEffect(nType, nGemId));
        break;
    case 11:
        m_spGem.AssignRaw(new CGemPetSkin(nType, nGemId));
        break;
    case 12:
        m_spGem.AssignRaw(new CGemMeta(nType, nGemId));
        break;
    }
    return m_spGem.get() != 0;
}

// @0x1405a7680
int CItemGem::vfunc_1()
{
    if (m_spGem.get() != 0)
        return m_spGem->vfunc_1();
    return 0;
}

// @0x1405a76e0
MS2Ptr<CItemGem> CItemGem::vfunc_2()
{
    MS2Ptr<CItemGem> spClone(new CItemGem);
    if (m_spGem.get() != 0)
        spClone->FUN_1405aa540(m_spGem->vfunc_4());
    return spClone;
}

// @0x1405a7810
void CItemGem::vfunc_3(COutputStream& stream)
{
    stream.vfunc_o10_0(m_spGem.get() != 0);
    if (m_spGem.get() != 0)
    {
        stream.vfunc_o10_1(m_spGem->vfunc_1());
        stream.vfunc_o10_3(m_spGem->FUN_1405a39f0());
        m_spGem->vfunc_2(stream);
    }
}

// @0x1405a7920
void CItemGem::vfunc_4(CInputStream& stream)
{
    bool bHas = stream.vfunc_o8_0();
    if (bHas)
    {
        int nType = stream.vfunc_o8_1();
        int nGemId = stream.vfunc_o8_3();
        if (FUN_1405a7020(nType, nGemId))
            m_spGem->vfunc_3(stream);
    }
}

// @0x1405a79d0
int CItemGem::vfunc_5(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (m_spGem.get() != 0)
        return m_spGem->vfunc_5(pPC, spItem);
    return 0;
}

// @0x1405a7a90
int CItemGem::vfunc_6(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (m_spGem.get() != 0)
        return m_spGem->vfunc_6(pPC, spItem);
    return 0;
}

// @0x1405a7b50
int CItemGem::vfunc_7(PC* pPC, MS2Ptr<CItem> spItem)
{
    if (m_spGem.get() != 0)
        return m_spGem->vfunc_7(pPC, spItem);
    return 0;
}

// @0x1405a7c10
void CItemGem::vfunc_8()
{
    if (m_spGem.get() != 0)
        m_spGem->vfunc_8();
}

// @0x1405a7c60
int CItemGem::FUN_1405a7c60()
{
    if (m_spGem.IsNull())
        return 0;
    return m_spGem->vfunc_9();
}

// @0x1405a7cc0
CString CItemGem::FUN_1405a7cc0()
{
    if (m_spGem.IsNull())
        return CString("");
    return m_spGem->vfunc_10();
}

// @0x1405a7d60
CStringW CItemGem::FUN_1405a7d60()
{
    if (m_spGem.IsNull())
        return CStringW(L"");
    return m_spGem->vfunc_11();
}

// @0x1405a7e30
ClonePC* FUN_1405a7e30(PC* pPC)
{
    void* pValue = 0;
    if (pPC != 0 && pPC->TypeCast(0x6200044, &pValue))
        return (ClonePC*)pValue;
    else
        return 0;
}

// @0x1405a7e80
CString FUN_1405a7e80(int nValue)
{
    return FUN_140719190(nValue);
}
