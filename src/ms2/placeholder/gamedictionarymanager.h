// gamedictionarymanager.h - PLACEHOLDER for GameDictionaryManager (RTTI .?AVGameDictionaryManager@@, 0x98 bytes). NOT an original header.
// Bases: TSingleton<GameDictionaryManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class GameDictionaryManager : public TSingleton<GameDictionaryManager>
{
public:
    GameDictionaryManager();                                // 0x1403b72d0
    virtual ~GameDictionaryManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x98 - 0x8];
};
MS2_CHECK_SIZE(GameDictionaryManager, 0x98);
