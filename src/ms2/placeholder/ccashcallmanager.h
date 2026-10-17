// ccashcallmanager.h - PLACEHOLDER for CCashCallManager (RTTI .?AVCCashCallManager@@, 0x8 bytes). NOT an original header.
// Bases: TSingleton<CCashCallManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CCashCallManager : public TSingleton<CCashCallManager>
{
public:
    CCashCallManager();                                     // 0x140b03040
    virtual ~CCashCallManager();
};
MS2_CHECK_SIZE(CCashCallManager, 0x8);
