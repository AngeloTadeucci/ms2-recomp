// mailitemslot.h - MailItemSlot: the slot that shows an attached item of a mail. Owning unit: ?\mailitemslot.cpp
// (0x1414723a0-0x141472ba0). Member names are invented from their use.
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class CItem;

// 0xa8 bytes. vftable (26 slots, ??_G 0x141472a30 sized delete 0xa8), ITooltip @+0x78.
class MailItemSlot : public MS2DragSlot
{
public:
    MailItemSlot(const CString& strName, MS2Ptr<CItem> spItem, int nValue, int nIndex);   // 0x1414723a0
    virtual ~MailItemSlot() = default;                  // 0x141472a00 (implicit: the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x141472a90, TypeCast 0x141472b00 / 0x141472b50; ms_ClassInfo 0x143adcff0,
    // SetupClassInfo 0x141472aa0 (parent MS2DragSlot, id 0x620003a).
    EE_DECLARE_CLASS1(MailItemSlot, 0x0620003A, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x1414726f0 build the item slot into p
    virtual int vfunc_11();                             // 11 0x1414724d0 clear the item
    virtual int vfunc_14();                             // 14 0x141472510 return 0
    virtual int vfunc_15();                             // 15 0x141472520
    virtual int vfunc_18(void* p);                      // 18 0x1414725a0
    virtual CStringW vfunc_22();                        // 22 0x141472920
    virtual MS2Ptr<CItem> vfunc_25();                   // 25 0x141472960 the item in the slot
    virtual int vfunc_0(void* p);                       // ITooltip 0x1414725d0 build the tooltip into p

    int GetItemId();                                    // 0x141472440
    int HasItem();                                      // 0x141472490

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_spItem;                             // +0x90
    int m_nValue;                                       // +0xa0
};
MS2_CHECK_SIZE(MailItemSlot, 0xa8);
MS2_CHECK_OFFSET(MailItemSlot, m_spItem, 0x90);
MS2_CHECK_OFFSET(MailItemSlot, m_nValue, 0xa0);
