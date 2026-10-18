// enchantscrollslot.h - EnchantScrollSlot: the scroll slot of the item enchant scroll window (UIEnchantScrollDialog). It
// holds the scroll item; dropping an item onto it sends the enchant request (packet 0x71, subtype 1: scroll uid, item
// uid) unless the refund prompt takes over. Owning unit: ?\enchantscrollslot.cpp (0x140cd73b0-0x140cd7ce0, .text$di
// 0x1400d04f0). Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0xa8 bytes. vftable (26 slots, ??_G 0x140cd7b70 sized delete 0xa8), ITooltip @+0x78.
class EnchantScrollSlot : public MS2DragSlot
{
public:
    EnchantScrollSlot(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem);   // 0x140cd74e0
    virtual ~EnchantScrollSlot() = default;             // 0x140cd7b40 (the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x140cd7bd0, TypeCast 0x140cd7c40 / 0x140cd7c90; ms_ClassInfo, SetupClassInfo 0x140cd7be0
    // (parent MS2DragSlot, id 0x6200063).
    EE_DECLARE_CLASS1(EnchantScrollSlot, 0x06200063, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140cd7950 build the item slot into p
    virtual int vfunc_14();                             // 14 0x140cd7760 remove the item (vfunc_17), return 1
    virtual int vfunc_17();                             // 17 0x140cd7580 clear the item, refresh the dialog
    virtual int vfunc_18(void* p);                      // 18 0x140cd75f0 an item was dropped on the slot
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x140cd7790 the item in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x140cd7830 build the tooltip into p

    void SetItem(MS2Ptr<CItem> spItem);                 // 0x140cd77e0

public:
    MS2_LAYOUT_FRIEND;
    unsigned __int64 m_nOwner;                          // +0x90 ctor argument (sent in the request packet)
    MS2Ptr<CItem> m_spItem;                             // +0x98
};
MS2_CHECK_SIZE(EnchantScrollSlot, 0xa8);
MS2_CHECK_OFFSET(EnchantScrollSlot, m_nOwner, 0x90);
MS2_CHECK_OFFSET(EnchantScrollSlot, m_spItem, 0x98);
