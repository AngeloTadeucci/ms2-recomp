// stringmanager.h - PLACEHOLDER for StringManager (RTTI .?AVStringManager@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<StringManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class StringManager : public TSingleton<StringManager>
{
public:
    StringManager();                                        // 0x14084f680
    virtual ~StringManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(StringManager, 0x38);
