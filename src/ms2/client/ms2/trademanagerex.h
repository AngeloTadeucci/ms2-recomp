// trademanagerex.h - CTradeManagerEx (player-to-player trade manager, packet type 0x49 and the trade UI messages) and the
// trade UI slot classes TradeSlot / TradeSlotBag. Owning unit: ?\trademanagerex.cpp (three consecutive objs in the exe:
// CTradeManagerEx 0x14185b1b0-0x14185dca0, TradeSlot 0x14185dca0-0x14185e970, TradeSlotBag 0x14185e970-0x14185f0b0;
// dir client\ms2).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class CItem;
class CInPacket;

// The items currently on the trade table: global DAT_143ab2e80 (0x58 bytes, zero-initialised, set up by the
// CTradeManagerEx ctor). m_nSlots slots (5), the items by uid (ATL::CRBMap node: key +0, value +8, color +0x18,
// left/right/parent +0x20/+0x28/+0x30) and by slot index.
class Unk_TradeItemTable
{
public:
    void FUN_14185b1b0();                           // m_nSlots = 5; size the slot array; Reset()
    void FUN_14185b200();                           // Reset: clear the map, size the slot array, clear every slot
    int FUN_14185b2a0(CItem* pItem);                // put the item on the table (assigns a free slot if its slot is -1)
    void FUN_14185b3d0(__int64 uid);                // take the item with this uid off the table
    MS2Ptr<CItem> FUN_14185b4a0(__int64 uid);       // find an item by uid
    void FUN_14185b520(ATL::CAtlArray<MS2Ptr<CItem> >& out); // append every item (MS2Ptr<CItem> copies) to out
    int FUN_14185b5c0();                            // first free slot index, -1 if none

public:
    MS2_LAYOUT_FRIEND;
    int m_nSlots;                                   // +0x00
    ATL::CRBMap<__int64, MS2Ptr<CItem> > m_byUid;   // +0x08
    ATL::CAtlArray<MS2Ptr<CItem> > m_bySlot;        // +0x38
};
MS2_CHECK_SIZE(Unk_TradeItemTable, 0x58);
MS2_CHECK_OFFSET(Unk_TradeItemTable, m_byUid, 0x8);
MS2_CHECK_OFFSET(Unk_TradeItemTable, m_bySlot, 0x38);
extern Unk_TradeItemTable DAT_143ab2e80;

// 0xa8 bytes. vftable 0x142f87cc0 (26 slots, ??_G 0x14185e6e0 sized delete 0xa8), ITooltip @+0x78 0x142f87d98.
// DragSlot::m_nIndex is the trade slot index (0..4 = my offer?), m_bMine tells whose side the slot shows.
class TradeSlot : public MS2DragSlot
{
public:
    TradeSlot(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, bool bMine);    // 0x14185dca0
    virtual ~TradeSlot();                           // 0x14185e6b0

    // slots 2-4: GetClassDesc 0x14185e740, TypeCast 0x14185e7b0 / 0x14185e800; ms_ClassInfo 0x143aef8a0,
    // SetupClassInfo 0x14185e750 (parent MS2DragSlot, id 0x6200057).
    EE_DECLARE_CLASS1(TradeSlot, 0x06200057, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                   // 8  0x14185e1b0 build the item slot tooltip into p
    virtual int vfunc_14();                         // 14 0x14185dd50
    virtual int vfunc_15();                         // 15 0x14185ddf0
    virtual int vfunc_18(void* p);                  // 18 0x14185de60
    virtual int vfunc_20();                         // 20 0x14185e2c0
    virtual CStringW vfunc_22();                    // 22 0x14185e670
    virtual MS2Ptr<CItem> vfunc_25();               // 25 0x14185e320 the item in the slot
    virtual int vfunc_0(void* p);                   // ITooltip 0x14185df40 build the item tooltip into p

    void FUN_14185e370(MS2Ptr<CItem> spItem);       // play the item's pickup/drop sound
    void FUN_14185e4e0(MS2Ptr<CItem> spItem);       // m_spItem = spItem
    __int64 FUN_14185e530();                        // item template id, 0 if empty
    __int64 FUN_14185e580();                        // item uid, 0 if empty
    void FUN_14185e5d0();                           // send "remove item" for this slot if it is mine
    bool FUN_14185e630();                           // return m_bMine

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_spItem;                         // +0x90
    bool m_bMine;                                   // +0xa0
};
MS2_CHECK_SIZE(TradeSlot, 0xa8);
MS2_CHECK_OFFSET(TradeSlot, m_spItem, 0x90);
MS2_CHECK_OFFSET(TradeSlot, m_bMine, 0xa0);

// 0x98 bytes. vftable 0x142f87ef0 (17 slots, ??_G 0x14185ee20 sized delete 0x98), UIItemEventListener @+0x88 0x142f87f80.
class TradeSlotBag : public DragSlotBag, public UIItemEventListener
{
public:
    explicit TradeSlotBag(const CString& strName);  // 0x14185e970
    virtual ~TradeSlotBag();                        // 0x14185ea20

    // slots 2-4: GetClassDesc 0x14185ee80, TypeCast 0x14185eef0 / 0x14185ef40; ms_ClassInfo 0x143aefcf0,
    // SetupClassInfo 0x14185ee90 (parent DragSlotBag, id 0x620005a).
    EE_DECLARE_CLASS1(TradeSlotBag, 0x0620005A, DragSlotBag);
public:
    virtual DragSlot* vfunc_16(int nIndex);         // 16 0x14185eb20 new TradeSlot(name of slot nIndex)
    virtual void vfunc_18(void* p);                 // UIItemEventListener 18-20 (0x14185eac0 / eae0 / eb00): {}
    virtual void vfunc_19(void* p);
    virtual void vfunc_20(void* p);

    void FUN_14185ec30(bool b);                     // m_bMine = b
    bool FUN_14185ec50();                           // return m_bMine
    int FUN_14185ec70(void*);                       // return 1 (not virtual)

public:
    MS2_LAYOUT_FRIEND;
    bool m_bMine;                                   // +0x90 (passed to the TradeSlot ctor)
};
MS2_CHECK_SIZE(TradeSlotBag, 0x98);
MS2_CHECK_OFFSET(TradeSlotBag, m_bMine, 0x90);
