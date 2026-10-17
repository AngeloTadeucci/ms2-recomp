// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The AS item slot components: ASItemSlot and
// ASAdditionalEffectSlot (slot icons with tooltips), the merat market product data objects (ASMeratMarketProductBase and
// its Product / LimitedProduct / HomeProduct kinds), ASScrollPanel, and ASSlot (the slot data object the icons are fed
// with). The range holds four TUs (four header-static groups in .text$di); they are recovered here as one file, with
// each group's statics under its own names.
// MS2-UNIT: ?\asitemslot.cpp
// MS2-RANGE: 0x1409ba1d0-0x1409c4b40 .text$mn
// MS2-RANGE: 0x1400c06c0-0x1400c13a0 .text$di
// MS2-RANGE: 0x142c9daa0-0x142c9e1c0 .text$yd
// MS2-PIN: ??_7ASObj@@6B@ 0x142db7e28
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\asitemslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <new>
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics, in the exe's initializer order (.text$di) ----
// The ASItemSlot TU.
static CString s_strSortTypeNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillA = "skill";
static CString s_strStunA = "stun";
// The merat market TU.
static CString s_strChartSortNamesB[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillB = "skill";
static CString s_strStunB = "stun";
static Unk_1402a9d70 s_unk1402a9d70B(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputB;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
// The ASSlot TU: the AS member names of the slot data, then the common header statics.
static CString s_strDisable = "disable";
static CString s_strDisableDrag = "disableDrag";
static CString s_strDropShadowDisable = "dropShadowDisable";
static CString s_strGrayColor = "grayColor";
static CString s_strIconPath = "iconPath";
static CString s_strIndex = "index";
static CString s_strItemBothEquip = "itemBothEquip";
static CString s_strItemCash = "itemCash";
static CString s_strItemCategory = "itemCategory";
static CString s_strItemColor = "itemColor";
static CString s_strItemCount = "itemCount";
static CString s_strItemEquip2 = "itemEquip2";
static CString s_strItemEquip = "itemEquip";
static CString s_strItemEvent = "itemEvent";
static CString s_strItemGrade = "itemGrade";
static CString s_strItemGUID = "itemGUID";
static CString s_strItemIconLock = "itemIconLock";
static CString s_strItemPiece = "itemPiece";
static CString s_strItemIconUnLock = "itemIconUnLock";
static CString s_strItemID = "itemID";
static CString s_strItemLock = "itemLock";
static CString s_strItemName = "itemName";
static CString s_strItemNew = "itemNew";
static CString s_strItemPcBang = "itemPcBang";
static CString s_strItemPet = "itemPet";
static CString s_strItemResultTag = "itemResultTag";
static CString s_strItemSeal = "itemSeal";
static CString s_strItemSkin = "itemSkin";
static CString s_strItemSummon = "itemSummon";
static CString s_strItemVIP = "itemVIP";
static CString s_strItemWedding = "itemWedding";
static CString s_strItemConditionLock = "itemConditionLock";
static CString s_strItemPetRank = "itemPetRank";
static CString s_strItemPetSkin = "itemPetSkin";
static CString s_strLearn = "learn";
static CString s_strSkillmaster = "skillmaster";
static CString s_strSkilltype = "skilltype";
static CString s_strSlotHint = "slotHint";
static CString s_strUgctag = "ugctag";
static CString s_strSortTypeNamesD[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillD = "skill";
static CString s_strStunD = "stun";
static Unk_1402a9d70 s_unk1402a9d70D(17, 0.75f, 0.25f, 2.25f, 10);

// ---- externals ----
typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> Unk_AsDelegate;

void FUN_1422c63f0(Scaleform::GFx::Value& value, int nGroup);   // unbind
void FUN_1422c6380(Scaleform::GFx::Value& value, int nGroup);   // bind
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
void FUN_1422bcc70(Scaleform::GFx::Value* pDst, Scaleform::GFx::Value v);                                // argument = value
void* FUN_1403ed2d0();
void* FUN_141bd0cc0(void*);                                     // the local player (tooltip owner)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                   // the item table row
CStringW FUN_14016a730(const char* sz, int nCodePage);          // multibyte -> wide
CStringW FUN_14028de60(int nStringId);
__int64 FUN_140869440();                                        // server time
unsigned short FUN_140626f20(unsigned nItemId);                 // fixed enchant level of an item
CString FUN_14021c050(int nTag);                                // ugc tag name
CStringW FUN_141b71910(__int64 nUid);                           // item uid text
CStringW FUN_1409e5320(const int& nSeason);                     // season number text

// An AS function object calling back into C++ (ctor 0x1422c8430, dtor 0x1422c85b0; uiquesteventlistener.cpp).
class ASFunction : public AScript
{
public:
    ASFunction(const Unk_AsDelegate& cb, __int64 nUser, int nMovieId);   // the user value is 64-bit (uiquesteventlistener.cpp declares it int)
    virtual ~ASFunction();
private:
    void* m_40;
};

// The reward record ASItemSlot::FUN_1409ba630 reads (slots 0-2: item id, rarity, count).
class Unk_ItemSlotSource
{
public:
    virtual int vfunc_0() const;
    virtual int vfunc_1() const;
    virtual int vfunc_2() const;
};

// The hotkey state the click preview checks (FUN_14025e7c0).
class Unk_SlotKeyState
{
public:
    bool FUN_14116dcb0(int nKey, int a1, int a2);
};
Unk_SlotKeyState* FUN_14025e7c0();

// The item preview window the click preview opens (TSingleton instance 0x143ab3fc0).
class Unk_ItemPreview
{
public:
    int FUN_140d40670();                                        // can preview
    void FUN_140d40120(MS2Ptr<CItem> spItem, int n);            // preview the item
};
extern Unk_ItemPreview* DAT_143ab3fc0;
Unk_ItemPreview* FUN_1409bb9e0();

// The additional effect (buff) record and its table.
class Unk_AdditionalEffect : public CPtred
{
public:
    CString FUN_1401756c0();                                    // copy of the icon path
};
class Unk_SlotSkillData;
class Unk_SlotTables                                            // the client table set (FUN_1401958b0)
{
public:
    MS2Ptr<Unk_AdditionalEffect> FUN_140aafef0(int nId, unsigned short nLevel);
    MS2Ptr<Unk_SlotSkillData> FUN_1407ee1d0(int nSkillId);
};
Unk_SlotTables* FUN_1401958b0();

// ---- ASItemSlot TU ----

class ASAdditionalEffectSlot : public ASUIComponent
{
public:
    ASAdditionalEffectSlot(CString strName, int nMovieId);
    ASAdditionalEffectSlot(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASAdditionalEffectSlot();                          // 0
    virtual void vfunc_3(int nVisible);                         // 3 0x1422c7260 (ASUIComponent's)
    virtual void vfunc_4(bool b);                               // 4 0x1422c7230
    virtual void vfunc_16();                                    // 16-24 0x1422c7ec0..0x1422c80c0
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    virtual void vfunc_25(Scaleform::GFx::Value** ppOut);       // 25 the effect tooltip
    void FUN_1409badd0();                                       // push the slot data
    void FUN_1409baf10(int nId, unsigned short nLevel);         // set the effect and refresh
    void FUN_1409bb060(Unk_AsDelegate callback, __int64 nUser);     // setTooltipFunction
    void FUN_1409bb100(const Scaleform::GFx::FunctionHandler::Params& params);   // the tooltip callback
private:
    int m_nId;                                                  // +0x88
    unsigned short m_nLevel;                                    // +0x8c
};
MS2_CHECK_SIZE(ASAdditionalEffectSlot, 0x90);

// The AScript::Invoke instances with an AS object argument by value (the callee destroys it).
// @0x1409bb370
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, ASFunction a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1.FUN_1422bb890());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409bb460
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, ASSlot a1)
{
    ASArgList args;
    args.FUN_1409b2800(1);
    FUN_1422bcc70(args.FUN_1409b1f70(0), a1.FUN_1422bb890());
    return FUN_1422bb8f0(szMethod, args);
}

// @0x1409ba1d0
ASItemSlot::ASItemSlot(CString strName, int nUnused)
    : ASUIComponent(strName, 2)
{
    m_itemId = 0;
    m_rarity = 0;
    m_nCount = 0;
    m_bLocked = false;
    FUN_1409ba980(Unk_AsDelegate(this, &ASItemSlot::FUN_1409baa20), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409ba310
ASItemSlot::ASItemSlot(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
    m_itemId = 0;
    m_rarity = 0;
    m_nCount = 0;
    m_bLocked = false;
    m_bPreview = false;
    FUN_1409ba980(Unk_AsDelegate(this, &ASItemSlot::FUN_1409baa20), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409ba410
ASItemSlot::~ASItemSlot()
{
    FUN_1422c63f0(FUN_1422bb890(), 2);
}

// @0x1409ba460
void ASItemSlot::FUN_1409ba460()
{
    ASSlot slot(2);
    if (slot.FUN_1409c4510(m_itemId, m_rarity, m_nCount) != 0)
    {
        if (m_bLocked)
            slot.FUN_1409c1e80(1);
        Invoke("setSlotData", slot);
    }
    else if (m_itemId == 0)
    {
        slot.FUN_1409c23a0(m_itemId);
        Invoke("setSlotData", slot);
    }
}

// @0x1409ba5d0
void ASItemSlot::FUN_1409ba5d0(int nItemId, int nRarity, int nCount)
{
    m_itemId = nItemId;
    m_rarity = nRarity;
    m_nCount = nCount;
    FUN_1409ba460();
}
MS2_REPLACE_METHOD(0x1409BA5D0, ASItemSlot, FUN_1409ba5d0, 83, 0);

// @0x1409ba630
void ASItemSlot::FUN_1409ba630(const Unk_ItemSlotSource& item)
{
    FUN_1409ba5d0(item.vfunc_0(), item.vfunc_1(), item.vfunc_2());
}

// @0x1409ba6d0
void ASItemSlot::FUN_1409ba6d0()
{
    MS2Ptr<CItemData> spData = FUN_14053f870(m_itemId);
    if (spData == 0)
        return;
    FUN_1422c2cb0(Unk_AsDelegate(this, &ASItemSlot::FUN_1409baa60));
    FUN_1422c2c30(Unk_AsDelegate(this, &ASItemSlot::FUN_1409baa60), 0);
    m_bPreview = true;
}

// @0x1409ba800
void ASItemSlot::vfunc_25(Scaleform::GFx::Value** ppOut)
{
    if (m_itemId == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(m_itemId, m_rarity, 0) != 0)
    {
        ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 0x20, 2);
        if (tip.FUN_1409e0d40(spItem.get()) != 0)
        {
            if (m_bPreview)
                tip.FUN_1409db7b0(spItem);
            **ppOut = tip.FUN_1422bb870();
        }
    }
}

// @0x1409ba980
void ASItemSlot::FUN_1409ba980(Unk_AsDelegate callback, __int64 nUser)
{
    Invoke("setTooltipFunction", ASFunction(callback, nUser, m_nMovieId));
}

// @0x1409baa20
void ASItemSlot::FUN_1409baa20(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_25(reinterpret_cast<Scaleform::GFx::Value**>(const_cast<Scaleform::GFx::FunctionHandler::Params*>(&params)));
}

// @0x1409baa60
void ASItemSlot::FUN_1409baa60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (!FUN_14025e7c0()->FUN_14116dcb0(0x49406, 0, 0))
        return;
    MS2Ptr<CItem> spItem(new CItem());
    if (spItem->FUN_14052b130(m_itemId, m_rarity, 0) != 0 && FUN_1409bb9e0()->FUN_140d40670() != 0)
        FUN_1409bb9e0()->FUN_140d40120(spItem, 0);
}

// @0x1409bab90
ASAdditionalEffectSlot::ASAdditionalEffectSlot(CString strName, int nUnused)
    : ASUIComponent(strName, 2)
{
    m_nId = 0;
    m_nLevel = 0;
    FUN_1409bb060(Unk_AsDelegate(this, &ASAdditionalEffectSlot::FUN_1409bb100), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409bacb0
ASAdditionalEffectSlot::ASAdditionalEffectSlot(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
    m_nId = 0;
    m_nLevel = 0;
    FUN_1409bb060(Unk_AsDelegate(this, &ASAdditionalEffectSlot::FUN_1409bb100), 0);
    FUN_1422c6380(FUN_1422bb890(), 2);
}

// @0x1409bad80
ASAdditionalEffectSlot::~ASAdditionalEffectSlot()
{
    FUN_1422c63f0(FUN_1422bb890(), 2);
}

// @0x1409badd0
void ASAdditionalEffectSlot::FUN_1409badd0()
{
    MS2Ptr<Unk_AdditionalEffect> spEffect = FUN_1401958b0()->FUN_140aafef0(m_nId, m_nLevel);
    if (spEffect == 0)
        return;
    ASSlot slot(2);
    if (slot.FUN_1409c48b0(spEffect->FUN_1401756c0()))
        Invoke("setSlotData", slot);
}

// @0x1409baf10
void ASAdditionalEffectSlot::FUN_1409baf10(int nId, unsigned short nLevel)
{
    m_nId = nId;
    m_nLevel = nLevel;
    FUN_1409badd0();
}

// @0x1409baf60
void ASAdditionalEffectSlot::vfunc_25(Scaleform::GFx::Value** ppOut)
{
    MS2Ptr<Unk_AdditionalEffect> spEffect = FUN_1401958b0()->FUN_140aafef0(m_nId, m_nLevel);
    if (spEffect == 0)
        return;
    ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 1, 2);
    if (tip.FUN_1409e2750(spEffect.get(), 5, 0) != 0)
        **ppOut = tip.FUN_1422bb870();
}

// @0x1409bb060
void ASAdditionalEffectSlot::FUN_1409bb060(Unk_AsDelegate callback, __int64 nUser)
{
    Invoke("setTooltipFunction", ASFunction(callback, nUser, m_nMovieId));
}

// @0x1409bb100
void ASAdditionalEffectSlot::FUN_1409bb100(const Scaleform::GFx::FunctionHandler::Params& params)
{
    vfunc_25(reinterpret_cast<Scaleform::GFx::Value**>(const_cast<Scaleform::GFx::FunctionHandler::Params*>(&params)));
}

// @0x1409bb9e0 TSingleton<item preview>::GetInstance
Unk_ItemPreview* FUN_1409bb9e0()
{
    return DAT_143ab3fc0;
}


// ---- ASScrollPanel / ASSlot TU ----

class ASScrollPanel : public ASUIComponent
{
public:
    ASScrollPanel(const Scaleform::GFx::Value& v, int nMovieId);
    virtual ~ASScrollPanel();                                   // 0
    virtual void vfunc_3(int nVisible);                         // 3 0x1422c7260 (ASUIComponent's)
    virtual void vfunc_4(bool b);                               // 4 0x1422c7230
    virtual void vfunc_16();                                    // 16-24 0x1422c7ec0..0x1422c80c0
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1409c1ba0(int nHeight);                            // setContentsHeight
};
MS2_CHECK_SIZE(ASScrollPanel, 0x88);

// The local player, as the slot code sees it.
class Unk_SlotSkillBook;
class Unk_SlotSkillLevel : public CPtred
{
public:
    float FUN_140804660();                                      // the cooldown in seconds
};
class Unk_SlotSkillRow : public CPtred
{
public:
    MS2Ptr<Unk_SlotSkillLevel> FUN_1407e90a0(unsigned short nLevel);
private:
    void* m_pad_18[(0x17c - 0x18) / 8];
    int m_pad_178;
public:
    int m_bCooldown;                                            // +0x17c the skill has a cooldown
};
MS2_CHECK_OFFSET(Unk_SlotSkillRow, m_bCooldown, 0x17c);
class Unk_SlotSkillBook
{
public:
    virtual void vfunc_0();
    virtual MS2Ptr<Unk_SlotSkillLevel> vfunc_1(int nSkillId);   // 1 the learned level of a skill
};
class Unk_SlotSkillCooldowns
{
public:
    float FUN_141765fe0(int nSkillId, int n);                   // the cooldown left
};
class Unk_SlotPc
{
public:
    int FUN_1416764d0();                                        // riding
    Unk_SlotSkillCooldowns* FUN_141523bc0();
    int FUN_14152e970(int nId);                                 // the free skill points of nId
};
Unk_SlotPc* FUN_1409613d0(void* pPc);
int FUN_141275a10(CItem* pItem);                                // the usable state of an item (1 locked, 2 disabled, 3 condition)                           // PCBase -> MyPC (NULL for others)
Unk_SlotSkillBook* FUN_1416546d0(Unk_SlotPc* pPc);
MS2Ptr<Unk_SlotSkillRow> FUN_140639210(int nSkillId);            // the skill table row

// The equip set of a PC (FUN_1416561a0).
class CEquipItem;
class Unk_SlotEquipSet
{
public:
    MS2Ptr<CEquipItem> FUN_1411e1780(int nSlot, int nKind);
};
Unk_SlotEquipSet* FUN_1416561a0(void* pPc);
class Unk_SlotMyPc
{
public:
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 nItemUid);        // a worn item by uid
};

// A skill entry (the skill window rows).
class Unk_SlotSkillInfo : public CPtred
{
public:
    int FUN_140637cc0();                                        // skill id
    int FUN_140637e00();                                        // skill tree id
private:
    char m_pad_18[7];
public:
    bool m_bLearned;                                            // +0x1f
};
MS2_CHECK_OFFSET(Unk_SlotSkillInfo, m_bLearned, 0x1f);
// The skill record of the skill table (FUN_1407ee1d0).
class Unk_SlotSkillData : public CPtred
{
public:
    bool FUN_1407e9de0();                                       // passive
private:
    void* m_pad_18[(0x48 - 0x18) / 8];
public:
    CString m_strIcon;                                          // +0x48
};
MS2_CHECK_OFFSET(Unk_SlotSkillData, m_strIcon, 0x48);
bool FUN_140ecf630(MS2Ptr<Unk_SlotSkillInfo> spSkill, int nPoints);   // can upgrade

// The icon source FUN_1409c4860 reads (an icon path at +0xc0).
class Unk_SlotIconSource
{
private:
    void* m_pad_00[0xc0 / 8];
public:
    CString m_strIcon;                                          // +0xc0
};
MS2_CHECK_OFFSET(Unk_SlotIconSource, m_strIcon, 0xc0);

// Item helpers.
class Unk_SlotModelHead                                         // ItemModelHead (itemdata.h)
{
public:
    bool FUN_140547190();                                       // dyeable
};
class Unk_ItemEquipData : public CItemData                      // CItem::FUN_140527840's record (item.cpp)
{
public:
    Unk_SlotModelHead* FUN_14053ec70();                         // the model head (CItemData declares it void)
};
class Unk_UserProxyItemData
{
public:
    unsigned long FUN_140599fd0(int n);                         // the dye colour
};
class Unk_ItemEnchantData
{
public:
    CItemEnchantInfo* FUN_140630d60();                          // the enchant record
    Unk_ItemPlusInfo* FUN_140630d90();                          // the unlimited enchant record
};
class CItemEnchantInfo
{
public:
    int FUN_14058c5f0();                                        // enchant level
    int FUN_14058c8a0();                                        // broken
};
class Unk_ItemPlusInfo
{
public:
    int FUN_1408bbc50();                                        // unlimited enchant level
};
class Unk_SlotSeasonTable
{
public:
    bool FUN_14059eec0(int nItemId);
    int FUN_14059ebb0(int nItemId);
    bool FUN_14059ef70(int nSeason);
};
Unk_SlotSeasonTable* FUN_14052d230();
class Unk_SlotLapenTable
{
public:
    unsigned short FUN_1405b5780(int nItemId);
};
class Unk_SlotPetRow : public CPtred
{
private:
    char m_pad_18[4];
public:
    bool m_bSummonable;                                         // +0x1c
};
MS2_CHECK_OFFSET(Unk_SlotPetRow, m_bSummonable, 0x1c);
class Unk_SlotPetTable
{
public:
    MS2Ptr<Unk_SlotPetRow> FUN_1407290f0(int nPetId);
};
Unk_SlotPetTable* FUN_14052d210();
class Unk_SlotBreakManager
{
public:
    int FUN_140531aa0(MS2Ptr<CItem> spItem);
};
class Unk_SlotLockManager
{
public:
    int FUN_140613430(MS2Ptr<CItem> spItem);
};
Unk_SlotLockManager* FUN_140535310();
class Unk_SlotQuestManager
{
public:
    int FUN_1416ce6a0(MS2Ptr<CItem> spItem);
};
Unk_SlotQuestManager* FUN_140764020();
class Unk_SlotFeatures
{
public:
    bool FUN_14036d570(int nFeature);
};
Unk_SlotFeatures* FUN_140166410();
class Unk_SlotStrings
{
public:
    CStringW FUN_141811980(int nTable, int nId);
    CStringW FUN_141812f60(int nId);
};
Unk_SlotStrings* FUN_1401a9d70();
class Unk_SlotUidSource
{
public:
    __int64 FUN_140c8b2e0();
};
Unk_SlotUidSource* FUN_140535320();
// The inventory dialog's break/lock mode (UIInventoryDialog +0x1a4).
class Unk_SlotInventoryDialog : public UIDialog
{
public:
    int FUN_1409c4b00() { return m_nMode; }
private:
    void* m_pad_178[(0x1a0 - 0x178) / 8];
    int m_pad_1a0;
public:
    int m_nMode;                                                // +0x1a4
};
MS2_CHECK_OFFSET(Unk_SlotInventoryDialog, m_nMode, 0x1a4);
Unk_SlotInventoryDialog* FUN_1405344f0(int nDialogId);
extern Unk_SlotBreakManager* DAT_143aaf300;
extern Unk_SlotLapenTable* DAT_143aafd98;
Unk_SlotBreakManager* FUN_1409c4b20();
Unk_SlotLapenTable* FUN_1409c4b30();

// @0x1409c1b20
ASScrollPanel::ASScrollPanel(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1409c1b70
ASScrollPanel::~ASScrollPanel()
{
}

// @0x1409c1ba0
void ASScrollPanel::FUN_1409c1ba0(int nHeight)
{
    Invoke("setContentsHeight", nHeight);
}

// @0x1409c1c20
ASSlot::ASSlot(int nType)
    : ASObj(nType)
{
}

// @0x1409c1c60
ASSlot::ASSlot(const Scaleform::GFx::Value& v, int nMovieId)
    : ASObj(v, nMovieId)
{
}

// @0x1409c1cb0
ASSlot::~ASSlot()
{
}

// @0x1409c1ce0
void ASSlot::FUN_1409c1ce0(int n)
{
    FUN_1407cb9c0(s_strItemPet, n);
}

// @0x1409c1d20
void ASSlot::FUN_1409c1d20(int n)
{
    FUN_1407cb9c0(s_strItemCash, n);
}

// @0x1409c1d60
void ASSlot::FUN_1409c1d60(int n)
{
    FUN_1407cb9c0(s_strItemSkin, n);
}

// @0x1409c1da0
void ASSlot::FUN_1409c1da0(bool b)
{
    FUN_1407cb9c0(s_strItemPcBang, b != false);
}

// @0x1409c1e00
void ASSlot::FUN_1409c1e00(int n)
{
    FUN_1407cb9c0(s_strItemVIP, n);
}

// @0x1409c1e40
void ASSlot::FUN_1409c1e40(int n)
{
    FUN_1407cb9c0(s_strItemWedding, n);
}

// @0x1409c1e80
void ASSlot::FUN_1409c1e80(int n)
{
    FUN_1407cb9c0(s_strItemLock, n);
}

// @0x1409c1ec0
void ASSlot::FUN_1409c1ec0(int n)
{
    FUN_1407cb9c0(s_strItemConditionLock, n);
}

// @0x1409c1f00
void ASSlot::FUN_1409c1f00(int n)
{
    FUN_1407cb9c0(s_strItemSeal, n);
}

// @0x1409c1f40
void ASSlot::FUN_1409c1f40(CItem* pItem)
{
    int nLock = pItem->FUN_140528ca0();
    __int64 tUnlock = pItem->FUN_140528e00();
    if (nLock == 0 && tUnlock > FUN_140869440())
    {
        FUN_1407cbbe0(s_strItemIconLock, false);
        FUN_1407cbbe0(s_strItemIconUnLock, true);
        return;
    }
    if (nLock == 1)
    {
        FUN_1407cbbe0(s_strItemIconLock, true);
        FUN_1407cbbe0(s_strItemIconUnLock, false);
    }
    else
    {
        FUN_1407cbbe0(s_strItemIconLock, false);
        FUN_1407cbbe0(s_strItemIconUnLock, false);
    }
}

// @0x1409c2050
void ASSlot::FUN_1409c2050(int n)
{
    FUN_1407cb9c0(s_strItemPiece, n);
}

// @0x1409c2090
void ASSlot::FUN_1409c2090(int n)
{
    FUN_1407cb9c0(s_strGrayColor, n);
}

// @0x1409c20d0
void ASSlot::FUN_1409c20d0(int n)
{
    FUN_1407cb9c0(s_strItemEquip, n);
}

// @0x1409c2110
void ASSlot::FUN_1409c2110(int n)
{
    FUN_1407cb9c0(s_strItemEquip2, n);
}

// @0x1409c2150
void ASSlot::FUN_1409c2150(int n)
{
    FUN_1407cb9c0(s_strItemSummon, n);
}

// @0x1409c2190
void ASSlot::FUN_1409c2190(unsigned n)
{
    if (n > 0)
        FUN_1407cbb20(s_strItemCount, StringFormat(L"{0}", n));
}

// @0x1409c2200
void ASSlot::FUN_1409c2200(CItem* pItem)
{
    FUN_1407cbb20(s_strItemCount, pItem->FUN_140527840()->FUN_14053c7c0() ? StringFormat(L"{0}", (unsigned)pItem->FUN_140526c50()) : CStringW(L""));
}

// @0x1409c2360
void ASSlot::FUN_1409c2360(unsigned long nColor)
{
    FUN_1409c4990(s_strItemColor, nColor);
}

// @0x1409c23a0
void ASSlot::FUN_1409c23a0(unsigned nItemId)
{
    FUN_1409c0d20(s_strItemID, nItemId);
}

// @0x1409c23e0
void ASSlot::FUN_1409c23e0(int nGrade)
{
    FUN_1409adc90(s_strItemGrade, nGrade);
}

// @0x1409c2420
void ASSlot::FUN_1409c2420(int nRank)
{
    FUN_1409adc90(s_strItemPetRank, nRank);
    FUN_1409c2610();
}

// @0x1409c2470
void ASSlot::FUN_1409c2470(int n)
{
    FUN_1407cb9c0(s_strItemPetSkin, n);
}

// @0x1409c24b0
void ASSlot::FUN_1409c24b0(int n)
{
    FUN_1407cb9c0(s_strItemBothEquip, n);
}

// @0x1409c24f0
void ASSlot::FUN_1409c24f0(int n)
{
    FUN_1407cb9c0(s_strItemNew, n);
}

// @0x1409c2530
void ASSlot::FUN_1409c2530(int n)
{
    FUN_1407cb9c0(s_strItemEvent, n);
}

// @0x1409c2570
void ASSlot::FUN_1409c2570(int n)
{
    FUN_1407cb9c0(s_strItemResultTag, n);
}

// @0x1409c25b0
void ASSlot::FUN_1409c25b0(const CStringW& strName)
{
    FUN_1407cbb20(s_strItemName, strName);
}

// @0x1409c2610
void ASSlot::FUN_1409c2610()
{
    FUN_1407cb9c0(s_strDropShadowDisable, 1);
}

// @0x1409c2650
void ASSlot::FUN_1409c2650()
{
    FUN_1407cb9c0(s_strDisableDrag, 1);
}

// @0x1409c2690
void ASSlot::FUN_1409c2690(int n)
{
    FUN_1407cb9c0(s_strLearn, n);
}

// @0x1409c26d0
void ASSlot::FUN_1409c26d0(int nIndex)
{
    FUN_1407cb9c0(s_strIndex, nIndex);
}

// @0x1409c2710
void ASSlot::FUN_1409c2710(int n)
{
    FUN_1407cb9c0(s_strDisable, n);
}

// @0x1409c2750
void ASSlot::FUN_1409c2750(const CString& strPath)
{
    FUN_1409c27c0(FUN_14016a730(strPath, 0));
}

// @0x1409c27c0
void ASSlot::FUN_1409c27c0(const CStringW& strPath)
{
    FUN_1407cbb20(s_strIconPath, strPath);
}

// @0x1409c2820
void ASSlot::FUN_1409c2820(const CString& strHint)
{
    FUN_1409c2890(FUN_14016a730(strHint, 0));
}

// @0x1409c2890
void ASSlot::FUN_1409c2890(const CStringW& strHint)
{
    FUN_1407cbb20(s_strSlotHint, strHint);
}

// @0x1409c28f0
void ASSlot::FUN_1409c28f0(const CStringW& strGuid)
{
    FUN_1407cbb20(s_strItemGUID, strGuid);
}

// @0x1409c2950
void ASSlot::FUN_1409c2950(int nTag)
{
    if (nTag == 0)
        return;
    FUN_1407cb9c0(s_strUgctag, nTag);
}

// @0x1409c2990
void ASSlot::FUN_1409c2990(const CStringW& strCategory)
{
    FUN_1407cbb20(s_strItemCategory, strCategory);
}

// @0x1409c29f0
void ASSlot::FUN_1409c29f0(unsigned nType)
{
    FUN_1409c0d20(s_strSkilltype, nType);
}

// @0x1409c2a30
void ASSlot::FUN_1409c2a30(int n)
{
    FUN_1407cb9c0(s_strSkillmaster, n);
}

// @0x1409c2a70
void ASSlot::FUN_1409c2a70(MS2Ptr<Unk_SlotSkillInfo> spSkill, int nPoints)
{
    FUN_1407cbbe0("upgradeCondition", FUN_140ecf630(spSkill, nPoints));
}

// @0x1409c2af0
// MS2-FUNCTIONAL: the skill row pointer is built through a converting copy in the exe (FUN_1407f4f80)
void ASSlot::FUN_1409c2af0(CItem* pItem, void* pPlayer)
{
    if (pItem->FUN_140526100() != 0)
        return;
    if (pItem->FUN_140527840()->FUN_14053dc20() == 0)
        return;
    Unk_SlotPc* pPc = FUN_1409613d0(pPlayer);
    if (pPc == NULL)
        return;
    FUN_1416546d0(pPc);
    MS2Ptr<Unk_SlotSkillRow> spRow = FUN_140639210(pItem->FUN_140527840()->FUN_14053dc20());
    if (spRow.IsNull())
        return;
    MS2Ptr<Unk_SlotSkillLevel> spLevel(0);
    if (pPc->FUN_1416764d0() == 0)
        spLevel = FUN_1416546d0(pPc)->vfunc_1(pItem->FUN_140527840()->FUN_14053dc20());
    else
        spLevel = spRow->FUN_1407e90a0(1);
    if (spLevel.IsNull())
        return;
    if (spRow->m_bCooldown == 0)
        return;
    FUN_1409c2dc0(pPc->FUN_141523bc0()->FUN_141765fe0(pItem->FUN_140527840()->FUN_14053dc20(), 0));
    FUN_1409c2e00(spLevel->FUN_140804660());
    FUN_1409c2e40();
}

// @0x1409c2dc0
void ASSlot::FUN_1409c2dc0(float fRemain)
{
    FUN_1409c4a30("remainTime", fRemain);
}

// @0x1409c2e00
void ASSlot::FUN_1409c2e00(float fTotal)
{
    FUN_1409c4a30("totalTime", fTotal);
}

// @0x1409c2e40
void ASSlot::FUN_1409c2e40()
{
    FUN_1407cbb20("cooldownSecStr", FUN_14028de60(0x5cb));
    FUN_1407cbb20("cooldownMinStr", FUN_14028de60(0x5ca));
    FUN_1407cbb20("cooldownHourStr", FUN_14028de60(0x5cc));
    FUN_1407cbb20("cooldownDayStr", FUN_14028de60(0x5ce));
}

// @0x1409c2f40
void ASSlot::FUN_1409c2f40(CItemEnchantInfo* pEnchant)
{
    if (pEnchant->FUN_14058c8a0() != 0)
    {
        int nLevel = pEnchant->FUN_14058c5f0();
        if (nLevel > 0)
        {
            FUN_1407cb9c0("enchantBroken", 1);
            FUN_1407cb9c0("enchant", nLevel);
        }
    }
    else
    {
        int nLevel = pEnchant->FUN_14058c5f0();
        if (nLevel > 0)
            FUN_1407cb9c0("enchant", nLevel);
    }
}

// @0x1409c2fe0
void ASSlot::FUN_1409c2fe0(Unk_ItemPlusInfo* pPlus)
{
    if (pPlus->FUN_1408bbc50() > 0)
    {
        int nLevel = pPlus->FUN_1408bbc50();
        if (nLevel > 0)
            FUN_1407cb9c0("unlimited", nLevel);
    }
}

// @0x1409c3040
void ASSlot::FUN_1409c3040(MS2Ptr<CItemData> spData)
{
    if (spData == 0 || !spData->FUN_14053d840())
        return;
    unsigned short nLevel = FUN_140626f20(spData->FUN_14053c510());
    if (nLevel == 0)
        return;
    FUN_1409c48f0("enchant", nLevel);
}

// @0x1409c30f0
void ASSlot::FUN_1409c30f0(MS2Ptr<CItemData> spData)
{
    if (spData == 0 || !spData->FUN_14053d8c0())
        return;
    unsigned short nLevel = FUN_1409c4b30()->FUN_1405b5780(spData->FUN_14053c510());
    if (nLevel == 0)
        return;
    FUN_1409c48f0("enchant", nLevel);
}

// @0x1409c31b0
void ASSlot::FUN_1409c31b0(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(spItem->FUN_140527840());
    if (spData == 0)
        return;
    FUN_1409c3290(spData);
}

// @0x1409c3290
void ASSlot::FUN_1409c3290(MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return;
    int nItemId = spData->FUN_14053c510();
    int nSeason = spData->FUN_14053dec0();
    Unk_SlotSeasonTable* pTable = FUN_14052d230();
    if (pTable != NULL && pTable->FUN_14059eec0(nItemId) == true)
        nSeason = pTable->FUN_14059ebb0(nItemId);
    if (nSeason == 0)
        return;
    if (!pTable->FUN_14059ef70(nSeason))
        return;
    CStringW strSeason = FUN_1409e5320(nSeason);
    FUN_1407cbb20("itemSeason", strSeason);
}

// @0x1409c33d0
void ASSlot::FUN_1409c33d0()
{
    FUN_1407cb9c0("enchant", 0);
}

// @0x1409c3400
void ASSlot::FUN_1409c3400()
{
    FUN_1407cb9c0("gradeBG", 0);
}

// @0x1409c3430
void ASSlot::FUN_1409c3430(CItem* pItem)
{
    switch (FUN_140764020()->FUN_1416ce6a0(MS2Ptr<CItem>(pItem)))
    {
    case 0:
        FUN_1407cb9c0("questBeginAble", 1);
        break;
    case 1:
        FUN_1407cb9c0("questProgress", 1);
        break;
    }
}

// @0x1409c34e0
// MS2-FUNCTIONAL: switch temporaries
void ASSlot::FUN_1409c34e0(CItem* pItem)
{
    Unk_SlotInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
    if (pInventory == NULL || pInventory->vfunc_55() != 0)
        return;
    switch (pInventory->FUN_1409c4b00())
    {
    case 0:
        break;
    case 1:
    case 2:
        if (FUN_1409c4b20()->FUN_140531aa0(MS2Ptr<CItem>(pItem)) == 0)
            FUN_1409c1f00(1);
        break;
    case 3:
        if (FUN_140535310()->FUN_140613430(MS2Ptr<CItem>(pItem)) == 0)
            FUN_1409c1f00(1);
        break;
    case 4:
        if (pItem->FUN_1405292a0() == 0)
            FUN_1409c1f00(1);
        break;
    case 5:
        if (pItem->FUN_140525640() == 0)
        {
            FUN_1409c1f00(1);
        }
        else
        {
            MS2Ptr<Unk_SlotPetRow> spPet = FUN_14052d210()->FUN_1407290f0(pItem->FUN_140527840()->FUN_14053dc60());
            if (spPet.IsNull())
                FUN_1409c1f00(1);
            else if (!spPet->m_bSummonable)
                FUN_1409c1f00(1);
        }
        break;
    }
}

// @0x1409c3750
void ASSlot::FUN_1409c3750(bool b)
{
    FUN_1407cbbe0("useRightClick", b);
}

// @0x1409c3780
int ASSlot::FUN_1409c3780()
{
    Scaleform::GFx::Value v = FUN_1422baa20(s_strItemID);
    int nItemId = v.GetUInt();
    return nItemId;
}

// @0x1409c37f0
int ASSlot::FUN_1409c37f0()
{
    Scaleform::GFx::Value v = FUN_1422baa20(s_strItemGrade);
    int nGrade = v.GetInt();
    return nGrade;
}

// @0x1409c3860
// MS2-FUNCTIONAL: big flag-driven filler; frame layout of the temporaries differs
int ASSlot::FUN_1409c3860(CItem* pItem, void* pPlayer, int nFlags)
{
    if (pItem == NULL)
        return 0;
    MS2Ptr<CItemData> spData(pItem->FUN_140527840());
    if (spData.IsNull())
        return 0;
    if (nFlags & 1)
    {
        FUN_1409c23a0(spData->FUN_14053c510());
        FUN_1409c23e0(pItem->FUN_140526bd0());
        FUN_1409c26d0(pItem->FUN_140526b50());
        if (!FUN_140166410()->FUN_14036d570(0x8c))
            FUN_1409c1ce0(spData->FUN_14053cc40());
        else if (spData->FUN_14053cc40())
            FUN_1409c2420(pItem->FUN_140526bd0());
        FUN_1409c2470(spData->FUN_14053e900() == 11);
        FUN_1409c1d20(spData->FUN_14053e130());
        FUN_1409c1d60(spData->FUN_14053cf90());
        FUN_1409c1da0(spData->FUN_14053ce20());
        FUN_1409c1e00(spData->FUN_14053d1f0());
        FUN_1409c1e40(spData->FUN_14053d210());
        FUN_1409c2750(pItem->FUN_140528590());
        FUN_1409c2950(pItem->FUN_140528840());
        if (pPlayer != NULL)
            FUN_1409c2af0(pItem, pPlayer);
        FUN_1409c2f40(pItem->FUN_1405278a0()->FUN_140630d60());
        FUN_1409c2fe0(pItem->FUN_1405278a0()->FUN_140630d90());
        FUN_1409c1f40(pItem);
        FUN_1409c2050(spData->FUN_14053d990());
        FUN_1409c3040(spData);
        FUN_1409c30f0(spData);
        FUN_1409c31b0(MS2Ptr<CItem>(pItem));
    }
    if (nFlags & 0x400)
        FUN_1409c2650();
    if (nFlags & 0x800)
        FUN_1409c25b0(pItem->FUN_140527b10());
    if ((nFlags & 0x20) && pPlayer != NULL)
    {
        Unk_SlotPc* pPc = FUN_1409613d0(pPlayer);
        if (pPc != NULL)
        {
            bool bEquipped = false;
            if (pItem->FUN_140527840()->FUN_14053cbc0())
            {
                MS2Ptr<CEquipItem> spEquip = reinterpret_cast<Unk_SlotMyPc*>(pPc)->FUN_141655c30(pItem->FUN_140526a50());
                bEquipped = spEquip.get() != NULL;
            }
            if (bEquipped)
                FUN_1409c20d0(bEquipped);
        }
    }
    if ((nFlags & 0x10000) && pItem->FUN_140525640() != 0)
    {
        __int64 nUid = pItem->FUN_140526a50();
        if (nUid == FUN_140535320()->FUN_140c8b2e0())
            FUN_1409c2150(1);
    }
    if (nFlags & 2)
    {
        if (pItem->FUN_1405268f0() == 0)
        {
            if (pItem->FUN_140526930())
                FUN_1409c2530(1);
        }
        else
        {
            FUN_1409c24f0(1);
        }
    }
    if (nFlags & 4)
    {
        FUN_1409c0d20("level", pItem->FUN_140527710());
        if (pPlayer != NULL)
        {
            Unk_SlotPc* pPc = FUN_1409613d0(pPlayer);
            if (pPc != NULL && pItem->FUN_140527840()->FUN_14053c8b0())
            {
                int nUsable = FUN_141275a10(pItem);
                if (nUsable == 1)
                    FUN_1409c1e80(1);
                else if (nUsable == 2)
                    FUN_1409c2710(1);
                else if (nUsable == 3)
                    FUN_1409c1ec0(1);
            }
        }
    }
    if (nFlags & 8)
    {
        if (pItem->FUN_140527840()->FUN_14053ec70()->FUN_140547190())
            FUN_1409c2360(pItem->FUN_140527870()->FUN_140599fd0(0));
    }
    if (nFlags & 0x10)
        FUN_1409c2200(pItem);
    if (nFlags & 0x80)
        FUN_1409c2820(FUN_14021c050(pItem->FUN_140526c30()));
    if (nFlags & 0x100)
        FUN_1409c28f0(FUN_141b71910(pItem->FUN_140526a50()));
    if (nFlags & 0x1000)
    {
        int nCategory = pItem->FUN_1405276c0();
        FUN_1409c2990(FUN_1401a9d70()->FUN_141812f60(nCategory));
    }
    if ((nFlags & 0x200) && pItem->FUN_140526970() != 0)
        FUN_1409c2570(1);
    if (nFlags & 0x2000)
        FUN_1409c2610();
    if (nFlags & 0x4000)
        FUN_1409c3430(pItem);
    if (nFlags & 0x8000)
        FUN_1409c34e0(pItem);
    if (nFlags & 0x20000)
        FUN_1409c33d0();
    if (nFlags & 0x40000)
        FUN_1409c3400();
    return 1;
}

// @0x1409c41f0
// MS2-FUNCTIONAL: the both-equip test materializes a bool temporary in the exe
int ASSlot::FUN_1409c41f0(CItem* pItem, void* pPc, int nSlot, int nFlags)
{
    if (pPc == NULL)
        return 0;
    if (pItem == NULL)
        return 0;
    if (FUN_1409c3860(pItem, pPc, nFlags) != 0)
    {
        MS2Ptr<CEquipItem> spMain = FUN_1416561a0(pPc)->FUN_1411e1780(nSlot, 0);
        MS2Ptr<CEquipItem> spSub = FUN_1416561a0(pPc)->FUN_1411e1780(nSlot, 1);
        if (pItem->FUN_1405258b0() != 0 && spMain.get() != NULL)
            FUN_1409c24b0(1);
        else if (pItem->FUN_1405258b0() == 0 && spSub.get() != NULL)
            FUN_1409c24b0(1);
        else
            FUN_1409c24b0(0);
        return 1;
    }
    return 0;
}

// @0x1409c4360
int ASSlot::FUN_1409c4360(Unk_SlotSkillInfo* pSkill, unsigned nFlags)
{
    Unk_SlotPc* pPc = static_cast<Unk_SlotPc*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (pPc == NULL)
        return 0;
    MS2Ptr<Unk_SlotSkillData> spRow = FUN_1401958b0()->FUN_1407ee1d0(pSkill->FUN_140637cc0());
    if (spRow.IsNull())
        return 0;
    if (nFlags & 1)
    {
        FUN_1409c2750(spRow->m_strIcon);
        FUN_1409c2a70(MS2Ptr<Unk_SlotSkillInfo>(pSkill), pPc->FUN_14152e970(pSkill->FUN_140637e00()));
    }
    if (nFlags & 0x400)
    {
        FUN_1409c2710(pSkill->m_bLearned == false);
        if (spRow->FUN_1407e9de0())
            FUN_1409c2650();
    }
    return 1;
}

// @0x1409c4510
// MS2-FUNCTIONAL: frame layout of the temporaries differs
int ASSlot::FUN_1409c4510(int nItemId, int nRarity, int nCount)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData.IsNull())
        return 0;
    FUN_1409c23a0(nItemId);
    FUN_1409c23e0(nRarity);
    if (!FUN_140166410()->FUN_14036d570(0x8c))
        FUN_1409c1ce0(spData->FUN_14053cc40());
    else if (spData->FUN_14053cc40())
        FUN_1409c2420(nRarity);
    FUN_1409c1d20(spData->FUN_14053e130());
    FUN_1409c1d60(spData->FUN_14053cf90());
    FUN_1409c1da0(spData->FUN_14053ce20());
    FUN_1409c1e00(spData->FUN_14053d1f0());
    FUN_1409c1e40(spData->FUN_14053d210());
    FUN_1409c2750(spData->FUN_14053fdd0());
    FUN_1409c25b0(FUN_1401a9d70()->FUN_141811980(1, nItemId));
    FUN_1409c2190(nCount);
    FUN_1409c2650();
    FUN_1409c3040(spData);
    FUN_1409c30f0(spData);
    FUN_1409c3290(spData);
    FUN_1409c2050(spData->FUN_14053d990());
    return 1;
}

// @0x1409c4860
int ASSlot::FUN_1409c4860(Unk_SlotIconSource* pSource)
{
    if (pSource == NULL)
        return 0;
    FUN_1409c2750(pSource->m_strIcon);
    FUN_1409c2650();
    return 1;
}

// @0x1409c48b0
int ASSlot::FUN_1409c48b0(const CString& strText)
{
    FUN_1409c2750(strText);
    FUN_1409c2650();
    return 1;
}

// The ASObj::Set instances (one per value type) first used here.
// @0x1409c48f0
void ASObj::FUN_1409c48f0(const char* szName, short n)
{
    ASData data;
    data.FUN_1422b7f70((unsigned short)n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c4990
void ASObj::FUN_1409c4990(const char* szName, unsigned long n)
{
    ASData data;
    data.FUN_1422b8090(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c4a30
void ASObj::FUN_1409c4a30(const char* szName, float f)
{
    ASData data;
    data.FUN_1422b80f0(f);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409c4b20 TSingleton<item break manager>::GetInstance
Unk_SlotBreakManager* FUN_1409c4b20()
{
    return DAT_143aaf300;
}

// @0x1409c4b30 TSingleton<lapenshard table>::GetInstance
Unk_SlotLapenTable* FUN_1409c4b30()
{
    return DAT_143aafd98;
}
