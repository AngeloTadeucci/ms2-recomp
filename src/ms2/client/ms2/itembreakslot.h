// itembreakslot.h - ItemBreakSlot / ItemBreakSlotBag: the drop slots of the item break (disassemble) window.
// Owning unit: ?\itembreakslot.cpp (0x14140ff10-0x141410cd0). Header name assumed from the unit path; names are invented
// from the use. The slot shows the Nth item of the break manager's list (slot 25 asks the manager); dropping an item
// onto it adds the item to the list; ItemBreakSlotBag creates 100 of them ("<bag>.<n>").
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0x90 bytes (no members of its own). vftable (26 slots, ??_G 0x141410560 sized delete 0x90), ITooltip @+0x78.
class ItemBreakSlot : public MS2DragSlot
{
public:
    ItemBreakSlot(const CString& strName, int nIndex);  // 0x14140ff10
    virtual ~ItemBreakSlot() = default;                 // 0x141410540 (implicit: the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x1414105c0, TypeCast 0x141410630 / 0x141410680; ms_ClassInfo 0x143ada2d0,
    // SetupClassInfo 0x1414105d0 (parent MS2DragSlot, id 0x620005b).
    EE_DECLARE_CLASS1(ItemBreakSlot, 0x0620005B, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x141410370 build the item slot into p
    virtual int vfunc_14();                             // 14 0x141410070 add the item to the break list
    virtual int vfunc_15();                             // 15 0x141410130
    virtual int vfunc_18(void* p);                      // 18 0x14140ff80 an item was dropped on the slot
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x1414101c0 the item in the slot (the manager's Nth)
    virtual int vfunc_0(void* p);                       // ITooltip 0x141410210 build the tooltip into p

    int FUN_141410480(__int64 nItemUid);                // can the item be broken
};
MS2_CHECK_SIZE(ItemBreakSlot, 0x90);

// 0x88 bytes. vftable (16 slots, ??_G 0x141410a40 sized delete 0x88).
class ItemBreakSlotBag : public DragSlotBag
{
public:
    ItemBreakSlotBag(const CString& strName, int nUnused);  // 0x1414107d0 (the second argument is not used)
    virtual ~ItemBreakSlotBag();                        // 0x141410820

    // slots 2-4: GetClassDesc 0x141410aa0, TypeCast 0x141410b10 / 0x141410b60; ms_ClassInfo 0x143ada780,
    // SetupClassInfo 0x141410ab0 (parent DragSlotBag, id 0x620005c).
    EE_DECLARE_CLASS1(ItemBreakSlotBag, 0x0620005C, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x141410850 (calls the base)
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x1414108a0 new ItemBreakSlot
};
MS2_CHECK_SIZE(ItemBreakSlotBag, 0x88);
