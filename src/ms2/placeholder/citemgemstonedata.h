// CItemGemStoneData / CItemGemStoneUpgradeTable (RTTI names). Rows of itemGemstoneUpgrade.xml and their table; the
// recovered users are the socket-system helpers in commonfiles\itemsocketsystemutil.cpp. The table's own unit
// (commonfiles\itemgemstonedata.cpp, 0x1405b0b70) is not recovered yet. Field names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

// One row, built by 0x1405b0b70 (CPtred base, +0x18 short, +0x1c int, CStringW at +0x20, +0x28 = 7, ingredient
// container at +0x30). Heap-only here: the members past +0x28 are not read by recovered code.
class CItemGemStoneData : public CPtred
{
public:
    unsigned short m_nSlot;                 // +0x18
    int m_nLinked;                          // +0x1c the id of the row this one links to (0 = none)
    CStringW m_strName;                     // +0x20
    unsigned m_nMask;                       // +0x28 (default 7)
};
MS2_CHECK_OFFSET(CItemGemStoneData, m_nSlot, 0x18);
MS2_CHECK_OFFSET(CItemGemStoneData, m_nLinked, 0x1c);
MS2_CHECK_OFFSET(CItemGemStoneData, m_strName, 0x20);
MS2_CHECK_OFFSET(CItemGemStoneData, m_nMask, 0x28);

class CItemGemStoneUpgradeTable
{
public:
    MS2Ptr<CItemGemStoneData> FUN_1405b1a60(unsigned nId);      // 0x1405b1a60 find a row (an empty pointer for none)
};
