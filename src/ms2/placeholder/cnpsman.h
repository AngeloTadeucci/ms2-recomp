// cnpsman.h - PLACEHOLDER for CNPSMan (RTTI .?AVCNPSMan@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<CNPSMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CNPSMan : public TSingleton<CNPSMan>
{
public:
    CNPSMan();                                              // 0x140db8d80
    virtual ~CNPSMan();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(CNPSMan, 0x38);
