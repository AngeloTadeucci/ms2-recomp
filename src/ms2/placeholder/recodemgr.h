// recodemgr.h - PLACEHOLDER for RecodeMgr (RTTI .?AVRecodeMgr@@, 0x78 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<RecodeMgr> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"

class RecodeMgr : public CThread, public TSingleton<RecodeMgr>
{
public:
    RecodeMgr();                                            // 0x140c9ba20
    virtual ~RecodeMgr();
    void FUN_140c9bc00();                                    // stops the recording (also on device loss)
    void FUN_140c9bb20();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0x78 - 0x20];
};
MS2_CHECK_SIZE(RecodeMgr, 0x78);
