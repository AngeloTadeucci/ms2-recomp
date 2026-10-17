// notifysystem.h - PLACEHOLDER for NotifySystem (RTTI .?AVNotifySystem@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<NotifySystem> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class NotifySystem : public TSingleton<NotifySystem>
{
public:
    NotifySystem();                                         // 0x140da4da0
    virtual ~NotifySystem();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x18 - 0x8];
};
MS2_CHECK_SIZE(NotifySystem, 0x18);
