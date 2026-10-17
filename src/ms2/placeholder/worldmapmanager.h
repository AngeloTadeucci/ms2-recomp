// worldmapmanager.h - PLACEHOLDER for WorldMapManager (RTTI .?AVWorldMapManager@@, 0xf8 bytes). NOT an original header.
// Bases: TSingleton<WorldMapManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class WorldMapManager : public TSingleton<WorldMapManager>
{
public:
    WorldMapManager();                                      // 0x141b95380
    virtual ~WorldMapManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xf8 - 0x8];
};
MS2_CHECK_SIZE(WorldMapManager, 0xf8);
