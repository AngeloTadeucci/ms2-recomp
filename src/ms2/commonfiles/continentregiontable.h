// continentregiontable.h - CContinentRegionTable (RTTI name): the continent table read from Table/MapContinentTable.xml.
// Header name assumed. Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"

// One <continent> row of MapContinentTable.xml. RTTI ContinentInfo, 0x28 bytes; vftable 0x142d20398 (CPtred's slots).
class ContinentInfo : public CPtred
{
public:
    ContinentInfo();                    // 0x1402c5850

    int m_nId;                          // +0x18 attribute "id"
    int m_nHideOtherWorldQuest;         // +0x1c
    int m_nShadowContinent;             // +0x20
    int m_nRepresentWorldmapContinent;  // +0x24
};
MS2_CHECK_SIZE(ContinentInfo, 0x28);
MS2_CHECK_OFFSET(ContinentInfo, m_nId, 0x18);
MS2_CHECK_OFFSET(ContinentInfo, m_nRepresentWorldmapContinent, 0x24);

class CContinentRegionTable : public TSingleton<CContinentRegionTable>, public CValidData<CContinentRegionTable>
{
public:
    typedef MS2SvrPtr<ContinentInfo> InfoPtr;
    typedef ATL::CAtlMap<DWORD, InfoPtr> Map;

    CContinentRegionTable();            // 0x1402c5180
    virtual ~CContinentRegionTable();   // 0x1402c5230

    void Load();                        // 0x1402c52b0 (name invented)
    InfoPtr GetContinent(DWORD nId);    // 0x1402c5570 (name invented)

    static void CheckInit();            // 0x1402c5b50
    static void SetInit(bool b);        // 0x1402c6a20

    static bool s_bInit;                // 0x143aad150

private:
    MS2_LAYOUT_FRIEND;
    Map m_map;                          // +0x10
};
MS2_CHECK_SIZE(CContinentRegionTable, 0x58);
MS2_CHECK_OFFSET(CContinentRegionTable, m_map, 0x10);
