// crashmanagercli.h - PLACEHOLDER for CrashManagerCli (RTTI .?AVCrashManagerCli@@, 0xd0 bytes). NOT an original header.
// Bases: CCrashManager at +0x0, TSingleton<CrashManagerCli> at +0x68.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/crashmanager.h"

class CrashManagerCli : public CCrashManager, public TSingleton<CrashManagerCli>
{
public:
    CrashManagerCli();                                      // 0x1414961b0
    virtual ~CrashManagerCli();
    void FUN_140a435a0();                                   // installs the crash handler (InitInstance)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_70[0xd0 - 0x70];
};
MS2_CHECK_SIZE(CrashManagerCli, 0xd0);
