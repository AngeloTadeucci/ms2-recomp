// cgameoption.h - PLACEHOLDER for CGameOption (RTTI .?AVCGameOption@@, 0x468 bytes). NOT an original header.
// Bases: TSingleton<CGameOption> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CGameOption : public TSingleton<CGameOption>
{
public:
    CGameOption();                                          // 0x141241810
    virtual ~CGameOption();
    void FUN_141243850();                                    // MS2::OnPreInit
    void FUN_141243860();                                    // MS2::Run, before the message loop
    void FUN_1412438d0();                                    // MS2::Run, after the message loop
    void FUN_1412438e0();                                    // MS2::OnShutdown
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x468 - 0x8];
};
MS2_CHECK_SIZE(CGameOption, 0x468);
