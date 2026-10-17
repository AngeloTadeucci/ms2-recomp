// crashmanagercli.h - PLACEHOLDER for CrashManagerCli (RTTI .?AVCrashManagerCli@@, 0xd0 bytes). NOT an original header.
// Bases: CCrashManager at +0x0, TSingleton<CrashManagerCli> at +0x68.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/crashmanager.h"
#include <atlcoll.h>
#include "ms2/placeholder/clockcriticalsection.h"

class CrashManagerCli;
// The exe's singleton pointer holds the derived object (TSingleton is the secondary base at +0x68), so the base ctor
// stores the downcast pointer, not os.h's base pointer.
template <> inline TSingleton<CrashManagerCli>::TSingleton();
template <> inline CrashManagerCli* TSingleton<CrashManagerCli>::GetInstance();

class CrashManagerCli : public CCrashManager, public TSingleton<CrashManagerCli>
{
public:
    // @0x1414961b0
    CrashManagerCli() {}
    // @0x141497620
    virtual ~CrashManagerCli() {}
    void FUN_140a435a0();                                   // installs the crash handler (InitInstance)
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x70
    ATL::CRBMap<int, CString> m_map;                        // +0xa0 (the value type is assumed: 8 bytes)
};
MS2_CHECK_SIZE(CrashManagerCli, 0xd0);

// @0x141495850
template <> inline TSingleton<CrashManagerCli>::TSingleton()
{
    s_instance = reinterpret_cast<TSingleton*>(static_cast<CrashManagerCli*>(this));
}
// The exe's copy (unit_140a435a0, 0x140a44830) reads the pointer as is.
template <> inline CrashManagerCli* TSingleton<CrashManagerCli>::GetInstance()
{
    return reinterpret_cast<CrashManagerCli*>(s_instance);
}
