// itemextractiontable.h - CExtractionItemInfo / CItemExtractionTable (RTTI names): the item extraction table read from
// Table/itemExtraction.xml (<key ScrollCount TargetItemID ResultItemID/>). Header name assumed. Member names are
// invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

// One <key> row. RTTI CExtractionItemInfo, 0x28 bytes, base CPtred; vftable slot 0 the deleting destructor.
class CExtractionItemInfo : public CPtred
{
public:
    CExtractionItemInfo();                  // 0x140596fb0
    // The destructor (0x140597920) and deleting destructor (0x140597a70) are implicit.

    unsigned int m_nScrollCount;            // +0x18 "ScrollCount" (zero is rejected by the loader)
    unsigned int m_nTargetItemId;           // +0x1c "TargetItemID" (the map key)
    unsigned int m_nResultItemId;           // +0x20 "ResultItemID"
};
MS2_CHECK_SIZE(CExtractionItemInfo, 0x28);
MS2_CHECK_OFFSET(CExtractionItemInfo, m_nTargetItemId, 0x1c);
MS2_CHECK_OFFSET(CExtractionItemInfo, m_nResultItemId, 0x20);

typedef MS2Ptr<CExtractionItemInfo> CExtractionItemInfoPtr;

// The table. RTTI CItemExtractionTable, 0x80 bytes: CCacheData +0, TSingleton +0x28, CValidData +0x30, the target item
// id -> row map +0x38. Created by CGameApp::InitInstance (?\ms2.cpp).
class CItemExtractionTable : public CCacheData,
                             public TSingleton<CItemExtractionTable>,
                             public CValidData<CItemExtractionTable>
{
public:
    CItemExtractionTable();                 // 0x140597010
    virtual ~CItemExtractionTable();        // 0x1405970d0

    void Load();                            // 0x140597150 parses the xml into the map
    int HasRow(unsigned int nTargetItemId);        // 0x140597430
    unsigned int GetResultItemId(unsigned int nTargetItemId);   // 0x1405974b0 (0 when missing)
    int IsTarget(unsigned int nTargetItemId);      // 0x140597540
    CExtractionItemInfoPtr GetData(unsigned int nTargetItemId);     // 0x140597580 the row (null when missing)

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<unsigned int, CExtractionItemInfoPtr> m_map;      // +0x38 target item id -> row
};
MS2_CHECK_OFFSET(CItemExtractionTable, m_map, 0x38);
