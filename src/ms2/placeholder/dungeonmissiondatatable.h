// dungeonmissiondatatable.h - PLACEHOLDER for DungeonMissionDataTable (RTTI .?AVDungeonMissionDataTable@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<DungeonMissionDataTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class DungeonMissionDataTable : public TSingleton<DungeonMissionDataTable>
{
public:
    DungeonMissionDataTable();                              // 0x140318c80
    virtual ~DungeonMissionDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x18 - 0x8];
};
MS2_CHECK_SIZE(DungeonMissionDataTable, 0x18);
