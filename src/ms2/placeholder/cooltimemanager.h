// cooltimemanager.h - PLACEHOLDER for CooltimeManager (RTTI .?AVCooltimeManager@@, 0x30 bytes). NOT an original header.
// Bases: TSingleton<CooltimeManager> at +0x0, CValidData<CooltimeManager> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CooltimeManager : public TSingleton<CooltimeManager>, public CValidData<CooltimeManager>
{
public:
    CooltimeManager();                                      // 0x140a40940
    virtual ~CooltimeManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x30 - 0x10];
};
MS2_CHECK_SIZE(CooltimeManager, 0x30);
