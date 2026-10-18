// cooltimemanager.h - PLACEHOLDER for CooltimeManager (RTTI .?AVCooltimeManager@@, 0x30 bytes). NOT an original header.
// Bases: TSingleton<CooltimeManager> at +0x0, CValidData<CooltimeManager> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Loads Table/CooltimeTable.xml
// (<cooltime cooltimeID cooltimeTick/>, ms ticks) and gates uses of a cooltime id (cooldown check).
#pragma once

#include <map>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CooltimeManager : public TSingleton<CooltimeManager>, public CValidData<CooltimeManager>
{
public:
    CooltimeManager();                                      // 0x140a40940
    virtual ~CooltimeManager();
    void Load();                                            // 0x140a40a40 (the ctor calls it)
    bool Use(unsigned nCooltimeId);                              // 0x140a40ca0, 0 while the id is still cooling down

    // @0x140a422b0
    static void SetInit(bool bInit) { s_bInit = bInit; }
    static bool s_bInit;                                    // DAT_143ab6720

    std::map<unsigned, unsigned> m_ticks;                             // +0x10 cooltimeID -> cooltimeTick
    std::map<unsigned, unsigned> m_ready;                             // +0x20 cooltimeID -> time it is usable again
};
MS2_CHECK_SIZE(CooltimeManager, 0x30);
MS2_CHECK_OFFSET(CooltimeManager, m_ticks, 0x10);
MS2_CHECK_OFFSET(CooltimeManager, m_ready, 0x20);
