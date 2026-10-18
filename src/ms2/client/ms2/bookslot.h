// bookslot.h - BookSlot / BookSlotBag: the slots of the skill book window (a skill of the job tree per slot). The slot
// holds the MS2Ptr<JobSkill>; the bag builds one slot per skill of the list it was created from. Owning unit:
// ?\bookslot.cpp (0x140a365c0-0x140a376e0, .text$di 0x1400c3320). Header name assumed from the unit path; member names
// are invented from the use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/ms2dragslot.h"

class JobSkill;

// 0xa0 bytes. vftable 0x142dc56a0 (26 slots, ??_G 0x140a368a0 sized delete 0xa0), ITooltip @+0x78 0x142dc5778.
class BookSlot : public MS2DragSlot
{
public:
    BookSlot(const CString& strName, int nIndex, MS2Ptr<JobSkill> spSkill);     // 0x140a365c0
    virtual ~BookSlot();                                // 0x140a36650

    // slots 2-4: GetClassDesc 0x140a36900, TypeCast 0x140a36a70 / 0x140a36ac0; ms_ClassInfo 0x143ab5e20,
    // SetupClassInfo 0x140a36950 (parent MS2DragSlot, id 0x6200051).
    EE_DECLARE_CLASS1(BookSlot, 0x06200051, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                       // 8  0x140a367a0 build the skill slot into p
    virtual int vfunc_11();                             // 11 0x140a366f0 drop the skill
    virtual int vfunc_18(void* p);                      // 18 0x140a36730 a slot was dropped on it
    virtual int vfunc_0(void* p);                       // ITooltip 0x140a36780 return 1

    unsigned FUN_140a366a0();                           // the id of the skill (0 when empty)

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<JobSkill> m_spSkill;                         // +0x90
};
MS2_CHECK_SIZE(BookSlot, 0xa0);
MS2_CHECK_OFFSET(BookSlot, m_spSkill, 0x90);

// 0xa8 bytes. vftable (16 slots, ??_G 0x140a371d0 sized delete 0xa8).
class BookSlotBag : public DragSlotBag
{
public:
    BookSlotBag(const CString& strName, std::vector<MS2Ptr<JobSkill> >& skills);    // 0x140a36d50
    virtual ~BookSlotBag();                             // 0x140a36e20

    // slots 2-4: GetClassDesc 0x140a37380, TypeCast 0x140a37640 / 0x140a37690; ms_ClassInfo 0x143ab6230,
    // SetupClassInfo 0x140a37580 (parent DragSlotBag, id 0x6200052).
    EE_DECLARE_CLASS1(BookSlotBag, 0x06200052, DragSlotBag);
public:
    virtual CString vfunc_15(int nIndex);               // 15 0x140a36e60 "<name>.<index>"
    virtual DragSlot* vfunc_16(int nIndex);             // 16 0x140a36f20 new BookSlot for the skill at nIndex

    MS2Ptr<JobSkill> FUN_140a37060(int nIndex);         // the skill at nIndex (null when out of range)

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<JobSkill> > m_skills;         // +0x88
};
MS2_CHECK_SIZE(BookSlotBag, 0xa8);
MS2_CHECK_OFFSET(BookSlotBag, m_skills, 0x88);
