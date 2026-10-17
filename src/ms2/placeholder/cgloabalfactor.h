// cgloabalfactor.h - PLACEHOLDER for CGloabalFactor (RTTI .?AVCGloabalFactor@@, 0x1608 bytes). NOT an original header.
// Bases: TSingleton<CGloabalFactor> at +0x0, CValidData<CGloabalFactor> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CGloabalFactor : public TSingleton<CGloabalFactor>, public CValidData<CGloabalFactor>
{
public:
    CGloabalFactor();                                       // 0x1404c11a0
    virtual ~CGloabalFactor();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x1608 - 0x10];
};
MS2_CHECK_SIZE(CGloabalFactor, 0x1608);
