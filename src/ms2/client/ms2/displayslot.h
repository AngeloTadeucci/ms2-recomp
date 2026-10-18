// displayslot.h - DisplaySlot: a read-only slot that shows one item (tooltip + slot icon) and accepts a dropped item of
// the right type. Owning unit: ?\displayslot.cpp (0x140a50440-0x140a50d40). Header name and member names assumed
// from the unit path / use. Same shape as MailItemSlot.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0xa8 bytes, RTTI id 0x06200087, ITooltip @+0x78.
class DisplaySlot : public MS2DragSlot
{
public:
    DisplaySlot(const CString& strName, MS2Ptr<CItem> spItem, int nSlotType);   // 0x140a50440
    virtual ~DisplaySlot() = default;                   // 0x140a50ba0 (implicit: no vptr writes; ??_G 0x140a50bd0)

    // slots 2-4: GetClassDesc 0x140a50c30, TypeCast 0x140a50ca0 / 0x140a50cf0; ms_ClassInfo 0x143ab6e70,
    // SetupClassInfo 0x140a50c40 (parent MS2DragSlot).
    EE_DECLARE_CLASS1(DisplaySlot, 0x06200087, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140a507f0 build the item slot into p
    virtual int vfunc_14();                             // 14 0x140a50670 clear the item
    virtual int vfunc_18(void* p);                      // 18 0x140a504e0 accept a dropped item
    virtual int vfunc_0(void* p);                       // ITooltip 0x140a50710 build the tooltip into p

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_spItem;                             // +0x90
    int m_nSlotType;                                    // +0xa0 item type the slot accepts (0 = any)
};
MS2_CHECK_SIZE(DisplaySlot, 0xa8);
MS2_CHECK_OFFSET(DisplaySlot, m_spItem, 0x90);
MS2_CHECK_OFFSET(DisplaySlot, m_nSlotType, 0xa0);
