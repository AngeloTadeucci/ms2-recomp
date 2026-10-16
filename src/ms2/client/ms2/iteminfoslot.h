// iteminfoslot.h - ItemInfoSlot (a UI item slot with an optional item, a count text, a tooltip and three callbacks),
// its CreateParam and ItemEnchantSlotBag (the bag of such slots shown by the item-enchant window). Owning unit:
// ?\itemcustomizecontroller.cpp#2 (0x141414d60-0x141416dd0). ItemInfoSlot::SetupClassInfo lives in gemstoneslot.cpp
// (0x140cfeba0, the first obj that included this class), so the header is shared with that unit.
// Member names are invented from their use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;
class ASSlot;
class ASTooltip;
class ItemInfoSlot;

// Callbacks of an ItemInfoSlot. The 8-byte Delegate handles are instantiated per signature.
typedef Delegate<void(ItemInfoSlot*, ASSlot*)> ItemInfoSlotSlotFn;       // fill the slot movie clip
typedef Delegate<void(ItemInfoSlot*, ASTooltip*)> ItemInfoSlotTipFn;     // fill the tooltip
typedef Delegate<int(ItemInfoSlot*)> ItemInfoSlotCanFn;                  // may the tooltip be shown?

// 0xe8 bytes. vftable 0x142f0fea8 (26 slots, ??_G 0x141416b20 sized delete 0xe8), ITooltip @+0x78 0x142f0ff80.
class ItemInfoSlot : public MS2DragSlot
{
public:
    // 0x58 bytes (CPtred + creation parameters), vftable 0x142f0fe98 (deleting dtor 0x141416ae0 only).
    class CreateParam : public CPtred
    {
    public:
        CreateParam();                                  // 0x141415390
        virtual ~CreateParam() {}                       // inline, COMDAT 0x140ba4e80 (deleting dtor 0x141416ae0)

        MS2Ptr<CItem> m_spItem;                         // +0x18
        int m_nIndex;                                   // +0x28 slot index
        int m_nIconType;                                // +0x2c 0: 0x415
        int m_nFlags;                                   // +0x30 0: 0x20
        CString m_strCount;                             // +0x38
        CString m_strSlotText;                          // +0x40
        CStringW m_strTip;                              // +0x48
        int m_nTipArg;                                  // +0x50 -1
        bool m_bEnabled;                                // +0x54
    };

    ItemInfoSlot(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags);   // 0x141415640
    ItemInfoSlot(const CString& strName, CreateParam* pParam);   // 0x1414157d0
    virtual ~ItemInfoSlot();                            // 0x1414159a0

    // slots 2-4: GetClassDesc 0x141416b80, TypeCast 0x141416b90 / 0x141416be0; ms_ClassInfo 0x143adb2e0,
    // SetupClassInfo 0x140cfeba0 (gemstoneslot.cpp; parent MS2DragSlot, id 0x620002f).
    EE_DECLARE_CLASS1(ItemInfoSlot, 0x0620002F, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x141416380 build the item slot into p
    virtual int vfunc_11();                             // 11 0x141415c20
    virtual int vfunc_15();                             // 15 0x141415a70
    virtual int vfunc_18(void* p);                      // 18 0x141415c50
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x141415b60 the item in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x141415c90 build the tooltip into p

    void SetItem(MS2Ptr<CItem> spItem);                 // 0x141415af0
    int GetItemId();                                    // 0x141415b40
    void UpdateItemId();                                // 0x141415bb0
    void SetSlotFn(ItemInfoSlotSlotFn fn);              // 0x141416650
    void SetTipFn(ItemInfoSlotTipFn fn);                // 0x1414166a0
    void SetCanFn(ItemInfoSlotCanFn fn);                // 0x1414166f0
    void SetCountText(int a, int b);                    // 0x141416740 write "m_count" into the movie

public:
    MS2_LAYOUT_FRIEND;
    int m_nItemId;                                      // +0x90 template id of the item (0 if empty)
    MS2Ptr<CItem> m_spItem;                             // +0x98
    int m_nIconType;                                    // +0xa8
    int m_nFlags;                                       // +0xac
    CString m_strCount;                                 // +0xb0 count text
    CString m_strSlotText;                              // +0xb8
    CStringW m_strTip;                                  // +0xc0 text tooltip of an empty slot
    int m_nTipArg;                                      // +0xc8
    ItemInfoSlotSlotFn m_fnSlot;                        // +0xd0
    ItemInfoSlotTipFn m_fnTip;                          // +0xd8
    ItemInfoSlotCanFn m_fnCan;                          // +0xe0
};
MS2_CHECK_SIZE(ItemInfoSlot, 0xe8);
MS2_CHECK_OFFSET(ItemInfoSlot, m_nItemId, 0x90);
MS2_CHECK_OFFSET(ItemInfoSlot, m_spItem, 0x98);
MS2_CHECK_OFFSET(ItemInfoSlot, m_strCount, 0xb0);
MS2_CHECK_OFFSET(ItemInfoSlot, m_nTipArg, 0xc8);
MS2_CHECK_OFFSET(ItemInfoSlot, m_fnSlot, 0xd0);
MS2_CHECK_OFFSET(ItemInfoSlot, m_fnCan, 0xe0);

// 0xa8 bytes. vftable (16 slots, ??_G 0x141415220 sized delete 0xa8).
class ItemEnchantSlotBag : public DragSlotBag
{
public:
    ItemEnchantSlotBag(const CString& strName, const ATL::CAtlArray<unsigned __int64>& items);   // 0x141414ea0
    virtual ~ItemEnchantSlotBag();                      // 0x141414f20

    // slots 2-4: GetClassDesc 0x141415280, TypeCast 0x1414152f0 / 0x141415340; ms_ClassInfo 0x143adade0,
    // SetupClassInfo 0x141415290 (parent DragSlotBag, id 0x620005d).
    EE_DECLARE_CLASS1(ItemEnchantSlotBag, 0x0620005D, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x141414f80 (calls the base)
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x141414fd0 new ItemInfoSlot for the uid at nIndex

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<unsigned __int64> m_uids;                     // +0x88 uids of the items shown
};
MS2_CHECK_SIZE(ItemEnchantSlotBag, 0xa8);
MS2_CHECK_OFFSET(ItemEnchantSlotBag, m_uids, 0x88);
