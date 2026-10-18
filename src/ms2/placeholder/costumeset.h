// costumeset.h - CostumeSet (RTTI .?AVCostumeSet@@, 0xb0 bytes, base CPtred): one row of Table/CostumeSet.xml. NOT an
// original header (member names are invented). Ctor 0x140535bc0, dtor 0x140535c80 (unit unit_140535bc0).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CostumeSet : public CPtred
{
public:
    CostumeSet();                               // 0x140535bc0
    virtual ~CostumeSet();                      // 0x140535c80

    unsigned m_nSetId;                          // +0x18 "id" of the <costumeSet>
    ATL::CAtlMap<int, int> m_mapSlotItems;      // +0x20 slot index -> item id ("slot_N" attributes)
    ATL::CAtlMap<int, int> m_mapTransparency;   // +0x68 slot -> Transparency constant (from "transparencySlots")
};
MS2_CHECK_SIZE(CostumeSet, 0xb0);
MS2_CHECK_OFFSET(CostumeSet, m_nSetId, 0x18);
MS2_CHECK_OFFSET(CostumeSet, m_mapSlotItems, 0x20);
MS2_CHECK_OFFSET(CostumeSet, m_mapTransparency, 0x68);
