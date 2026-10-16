// cequipitem.h - PLACEHOLDER for CEquipItem (RTTI .?AVCEquipItem@@, CPtred-derived, 0xb0 bytes; owning unit
// ?\equipitem.cpp, not recovered): the worn item of an actor's equip slot. NOT an original header; only the members
// that done units call are declared.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class CItem;

class CEquipItem : public CPtred
{
public:
    MS2Ptr<CItem> FUN_1411dc7a0();                                  // 0x1411dc7a0 the item the slot shows
private:
    char m_pad_18[0xb0 - 0x18];                                     // unrecovered members
};
MS2_CHECK_SIZE(CEquipItem, 0xb0);
