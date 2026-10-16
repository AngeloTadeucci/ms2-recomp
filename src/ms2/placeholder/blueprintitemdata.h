// blueprintitemdata.h - CBlueprintItemData (RTTI .?AVCBlueprintItemData@@, commonfiles\ugcdef.cpp), the blueprint half
// of a CItemUgc (item.h, at +0x80). 0x58 bytes: CPtred, eight scalar fields, one wide string. Ctor 0x1408923d0 (CPtred
// ctor, vftable, string ctor, reset), dtor 0x140892430, deleting dtor 0x140899e90. Member names are by offset.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"

class COutputStream;
class CInputStream;

class CBlueprintItemData : public CPtred {
public:
    CBlueprintItemData();                       // 0x1408923d0
    virtual ~CBlueprintItemData();              // 0x140892430
    void FUN_140892470();                       // reset every field, the string to L""
    void FUN_140892510(const CBlueprintItemData* pSource);      // field-wise copy
    void FUN_1408925d0(COutputStream* pStream);
    void FUN_1408926e0(CInputStream* pStream);
    __int64 m_n18;
    int m_n20, m_n24, m_n28;
    __int64 m_n30;
    int m_n38;
    __int64 m_n40, m_n48;
    CStringW m_str50;
};
MS2_CHECK_SIZE(CBlueprintItemData, 0x58);
MS2_CHECK_OFFSET(CBlueprintItemData, m_n30, 0x30);
MS2_CHECK_OFFSET(CBlueprintItemData, m_str50, 0x50);
