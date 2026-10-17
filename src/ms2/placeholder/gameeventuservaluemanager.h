// gameeventuservaluemanager.h - PLACEHOLDER for GameEventUserValueManager (RTTI .?AVGameEventUserValueManager@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<GameEventUserValueManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates: event id -> listener delegates. Recovered in
// unnamed\unit_140da50e0.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/delegate.h"
#include <map>
#include <vector>
class GameEventVariable;

class GameEventUserValueManager : public TSingleton<GameEventUserValueManager>
{
public:
    GameEventUserValueManager();                            // 0x140da5390
    virtual ~GameEventUserValueManager();
    void RegisterListener(unsigned nEvent, Delegate<void(GameEventVariable*)> listener);     // 0x140da5430
    void UnregisterListener(unsigned nEvent, Delegate<void(GameEventVariable*)> listener);   // 0x140da5490
    void Dispatch(unsigned nEvent, GameEventVariable* pVariable);                            // 0x140da55a0
private:
    MS2_LAYOUT_FRIEND;
    std::map<unsigned, std::vector<Delegate<void(GameEventVariable*)> > > m_listeners;       // +0x08
};
MS2_CHECK_SIZE(GameEventUserValueManager, 0x18);
