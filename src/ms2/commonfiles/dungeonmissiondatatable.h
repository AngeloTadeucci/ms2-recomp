// dungeonmissiondatatable.h - DungeonMissionDataTable (RTTI .?AVDungeonMissionDataTable@@): the dungeon missions of
// Table/DungeonMission.xml by id. Owning unit: commonfiles\dungeonmissiondatatable.cpp (0x140318c80-0x14031b800).
// Method names follow the log text (ReadFromXml) or are invented. NOT an original header.
#pragma once
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/dungeonmissiondata.h"

// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. vftable 0x142d25fa8. 0x18 bytes.
class DungeonMissionDataTable : public TSingleton<DungeonMissionDataTable>
{
public:
    DungeonMissionDataTable();                              // 0x140318c80 loads the table
    MS2Ptr<DungeonMissionData> GetMission(unsigned nId);    // 0x140318ce0 NULL if unknown
    BOOL ReadFromXml();                                     // 0x140318d40

private:
    MS2_LAYOUT_FRIEND;
    std::map<unsigned, MS2Ptr<DungeonMissionData>> m_missions;  // +0x08
};
MS2_CHECK_SIZE(DungeonMissionDataTable, 0x18);
MS2_CHECK_OFFSET(DungeonMissionDataTable, m_missions, 0x8);
