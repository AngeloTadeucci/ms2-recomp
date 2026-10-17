// conlinepatchmanagercli.h - PLACEHOLDER for COnlinePatchManagerCli (RTTI .?AVCOnlinePatchManagerCli@@, 0x30 bytes). NOT an original header.
// Bases: TSingleton<COnlinePatchManagerCli> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class COnlinePatchManagerCli : public TSingleton<COnlinePatchManagerCli>
{
public:
    COnlinePatchManagerCli();                               // 0x140a848a0
    virtual ~COnlinePatchManagerCli();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x30 - 0x8];
};
MS2_CHECK_SIZE(COnlinePatchManagerCli, 0x30);
