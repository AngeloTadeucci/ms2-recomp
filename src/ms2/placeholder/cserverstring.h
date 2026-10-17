// cserverstring.h - PLACEHOLDER for CServerString (RTTI .?AVCServerString@@, 0x260 bytes). NOT an original header.
// Bases: TSingleton<CServerString> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CServerString : public TSingleton<CServerString>
{
public:
    CServerString();                                        // 0x14087f180
    virtual ~CServerString();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x260 - 0x8];
};
MS2_CHECK_SIZE(CServerString, 0x260);
