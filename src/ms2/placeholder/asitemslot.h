// asitemslot.h - PLACEHOLDER for ASItemSlot (RTTI .?AVASItemSlot@@, 0x98 bytes, base ASUIComponent, vftable 0x142db7e38,
// 26 slots): the AS item slot icon with an item tooltip. NOT an original header (asitemslot.cpp is not recovered).
// Ctor 0x1409ba310, dtor 0x1409ba410 (deleting 0x1409bb920), vfunc_25 (the item tooltip value) 0x1409ba800.
//
// ASUIComponent declares no virtuals (its derived classes elsewhere would all need the slot symbols), so the slots it
// introduces (3 and 4 override ASDisplayObject, 16-24 are new) are declared here as ASItemSlot members; they are
// really ASUIComponent's (0x1422c7260, 0x1422c7230, 0x1422c7ec0-0x1422c80c0 in steps of 0x40/0x3c; slot 24 is validateNow).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASItemSlot : public ASUIComponent
{
public:
    ASItemSlot(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1409ba310
    virtual ~ASItemSlot();                                      // 0 (0x1409ba410)
    virtual void vfunc_3(int nVisible);                         // 3 0x1422c7260
    virtual void vfunc_4(bool b);                               // 4 0x1422c7230
    virtual void vfunc_16();                                    // 16 0x1422c7ec0
    virtual void vfunc_17();                                    // 17 0x1422c7f00
    virtual void vfunc_18();                                    // 18 0x1422c7f40
    virtual void vfunc_19();                                    // 19 0x1422c7f80
    virtual void vfunc_20();                                    // 20 0x1422c7fc0
    virtual void vfunc_21();                                    // 21 0x1422c8000
    virtual void vfunc_22();                                    // 22 0x1422c8040
    virtual void vfunc_23();                                    // 23 0x1422c8080
    virtual void vfunc_24(bool bRefresh);                       // 24 0x1422c80c0
    // Builds the item tooltip and returns its value through *ppOut (slot 25, 0x1409ba800).
    virtual void vfunc_25(Scaleform::GFx::Value** ppOut);
    void FUN_1409ba630(void* pItemData);                        // fills the slot from a reward item record

protected:
    MS2_LAYOUT_FRIEND;
    int m_itemId;                                               // +0x88
    int m_rarity;                                               // +0x8c
    void* m_pad_90;                                             // +0x90 (a flag byte at +0x95)
};
MS2_CHECK_SIZE(ASItemSlot, 0x98);
MS2_CHECK_OFFSET(ASItemSlot, m_itemId, 0x88);
