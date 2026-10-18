// itemexchangeslot.h - ItemExchangeSlot: the slot of the item-exchange-scroll dialog; a dropped item is reported to the
// server (packet 0x9b). Owning unit: ?\itemexchangeslot.cpp (0x140b6c7a0-0x140b6d070). Header name and member names
// assumed from the unit path / use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0xa8 bytes, RTTI id 0x06200077, ITooltip @+0x78.
class ItemExchangeSlot : public MS2DragSlot
{
public:
    ItemExchangeSlot(const CString& strName, __int64 nTarget, MS2Ptr<CItem> spItem);   // 0x140b6c8d0
    virtual ~ItemExchangeSlot() = default;              // 0x140b6ced0 (implicit; ??_G 0x140b6cf00)

    // slots 2-4: GetClassDesc 0x140b6cf60, TypeCast 0x140b6cfd0 / 0x140b6d020; ms_ClassInfo 0x143abb1f0,
    // SetupClassInfo 0x140b6cf70 (parent MS2DragSlot).
    EE_DECLARE_CLASS1(ItemExchangeSlot, 0x06200077, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140b6cce0 build the item slot into p
    virtual int vfunc_14();                             // 14 0x140b6caf0 vfunc_17(); return 1
    virtual int vfunc_17();                             // 17 0x140b6c970 clear the item, refresh the dialog
    virtual int vfunc_18(void* p);                      // 18 0x140b6c9e0 accept a dropped item, tell the server
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140b6cb20 the item in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x140b6cbc0 build the tooltip into p

    void SetItem(MS2Ptr<CItem> spItem);                 // 0x140b6cb70

public:
    MS2_LAYOUT_FRIEND;
    __int64 m_nTarget;                                  // +0x90
    MS2Ptr<CItem> m_spItem;                             // +0x98
};
MS2_CHECK_SIZE(ItemExchangeSlot, 0xa8);
MS2_CHECK_OFFSET(ItemExchangeSlot, m_nTarget, 0x90);
MS2_CHECK_OFFSET(ItemExchangeSlot, m_spItem, 0x98);
