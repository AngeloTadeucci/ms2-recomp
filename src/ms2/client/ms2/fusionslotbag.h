// fusionslotbag.h - FusionSlotBag: the bag of ItemInfoSlots of the item fusion (merge) windows. It holds the uids of the
// items to show and creates one ItemInfoSlot per uid; each slot gets a "mergeStep" slot callback and a tooltip-allowed
// callback bound to the item merge option dialog (0x4e68). Owning unit: ?\fusionslotbag.cpp (0x14123a080-0x14123b2b0).
// Header name assumed from the unit path; member names are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/iteminfoslot.h"

class ASSlot;

// 0xb0 bytes. vftable (16 slots, ??_G 0x14123adb0 sized delete 0xb0).
class FusionSlotBag : public DragSlotBag
{
public:
    FusionSlotBag(const CString& strName, int nType, const ATL::CAtlArray<unsigned __int64>& items);   // 0x14123a1e0
    virtual ~FusionSlotBag();                           // 0x14123a270

    // slots 2-4: GetClassDesc 0x14123ae10, TypeCast 0x14123ae80 / 0x14123aed0; ms_ClassInfo 0x143ad4850,
    // SetupClassInfo 0x14123ae20 (parent DragSlotBag, id 0x6200043).
    EE_DECLARE_CLASS1(FusionSlotBag, 0x06200043, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x14123a2b0 (calls the base)
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x14123a300 new ItemInfoSlot for the uid at nIndex + callbacks

    void FUN_14123a650(ItemInfoSlot& slot, ASSlot& as); // slot callback: sets "mergeStep" from the item's status

public:
    MS2_LAYOUT_FRIEND;
    int m_nType;                                        // +0x88 ctor argument (0 in the creator)
    int m_pad_8c;
    ATL::CAtlArray<unsigned __int64> m_uids;            // +0x90 uids of the items shown
};
MS2_CHECK_SIZE(FusionSlotBag, 0xb0);
MS2_CHECK_OFFSET(FusionSlotBag, m_nType, 0x88);
MS2_CHECK_OFFSET(FusionSlotBag, m_uids, 0x90);
