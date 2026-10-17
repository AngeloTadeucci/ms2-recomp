// blindmanager.h - PLACEHOLDER for BlindManager (RTTI .?AVBlindManager@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<BlindManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class BlindManager : public TSingleton<BlindManager>
{
public:
    BlindManager();                                         // 0x140a24e90
    virtual ~BlindManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x20 - 0x8];
};
MS2_CHECK_SIZE(BlindManager, 0x20);
