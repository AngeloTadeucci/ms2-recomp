// gameeventmanagercli.h - PLACEHOLDER for GameEventManagerCli (RTTI .?AVGameEventManagerCli@@, 0x60 bytes). NOT an original header.
// Bases: TSingleton<GameEventManagerCli> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class GameEventManagerCli : public TSingleton<GameEventManagerCli>
{
public:
    GameEventManagerCli();                                  // 0x140ceaa70
    virtual ~GameEventManagerCli();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x60 - 0x8];
};
MS2_CHECK_SIZE(GameEventManagerCli, 0x60);
