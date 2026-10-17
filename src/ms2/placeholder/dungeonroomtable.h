// dungeonroomtable.h - PLACEHOLDER for DungeonRoomTable (RTTI .?AVDungeonRoomTable@@, 0x108 bytes). NOT an original header.
// Bases: TSingleton<DungeonRoomTable> at +0x0, CValidData<DungeonRoomTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class DungeonRoomTable : public TSingleton<DungeonRoomTable>, public CValidData<DungeonRoomTable>
{
public:
    DungeonRoomTable();                                     // 0x14031f5d0
    virtual ~DungeonRoomTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x108 - 0x10];
};
MS2_CHECK_SIZE(DungeonRoomTable, 0x108);
