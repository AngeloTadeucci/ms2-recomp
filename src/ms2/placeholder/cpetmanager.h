// cpetmanager.h - PLACEHOLDER for CPetManager (RTTI .?AVCPetManager@@, 0x198 bytes). NOT an original header.
// Bases: TSingleton<CPetManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CPetManager : public TSingleton<CPetManager>
{
public:
    CPetManager();                                          // 0x140c894b0
    virtual ~CPetManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x198 - 0x8];
};
MS2_CHECK_SIZE(CPetManager, 0x198);
