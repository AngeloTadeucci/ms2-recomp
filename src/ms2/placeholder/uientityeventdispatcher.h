// uientityeventdispatcher.h - PLACEHOLDER for UIEntityEventDispatcher (RTTI .?AVUIEntityEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIEntityEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered beyond the listener list (CAtlArray<void*> at +8); the fan-out virtuals are in ?\uientityeventlistener.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <afx.h>
#include <atlcoll.h>

class UIEntityEventDispatcher : public TSingleton<UIEntityEventDispatcher>
{
public:
    UIEntityEventDispatcher();                              // 0x141930820
    virtual ~UIEntityEventDispatcher();
protected:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<void*> m_listeners;                      // +0x08 the registered UIEntityEventListener*
};
MS2_CHECK_SIZE(UIEntityEventDispatcher, 0x28);
