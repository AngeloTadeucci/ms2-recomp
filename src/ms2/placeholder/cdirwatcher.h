// cdirwatcher.h - PLACEHOLDER for CDirWatcher (RTTI .?AVCDirWatcher@@, 0x28 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CDirWatcher> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"

class CDirWatcher : public CThread, public TSingleton<CDirWatcher>
{
public:
    CDirWatcher();                                          // 0x1401d1940
    virtual ~CDirWatcher();
    void FUN_1401d1cd0();                                   // stops the watch (InitInstance teardown)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0x28 - 0x20];
};
MS2_CHECK_SIZE(CDirWatcher, 0x28);
