// gameeventuservaluemanager.h - PLACEHOLDER for GameEventUserValueManager (RTTI .?AVGameEventUserValueManager@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<GameEventUserValueManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class GameEventUserValueManager : public TSingleton<GameEventUserValueManager>
{
public:
    GameEventUserValueManager();                            // 0x140da5390
    virtual ~GameEventUserValueManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x18 - 0x8];
};
MS2_CHECK_SIZE(GameEventUserValueManager, 0x18);
