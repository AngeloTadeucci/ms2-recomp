// asslot.h - PLACEHOLDER for ASSlot (RTTI .?AVASSlot@@, base ASObj, 0x40 bytes): the AS item slot object (asitemslot.cpp,
// not recovered). Ctor 0x1409c1c20 (type), dtor 0x1409c1cb0. NOT an original header. uiattendgiftdialog.cpp still carries
// a unit-local copy; new units include this one.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asobj.h"

class CItem;

class ASSlot : public ASObj
{
public:
    ASSlot(int nType);
    virtual ~ASSlot();
    int FUN_1409c3860(CItem* pItem, void* pPlayer, int nFlags);          // fill the slot from an item
    void FUN_1409c2650();                                                // darken / disable the slot icon
};
MS2_CHECK_SIZE(ASSlot, 0x40);
