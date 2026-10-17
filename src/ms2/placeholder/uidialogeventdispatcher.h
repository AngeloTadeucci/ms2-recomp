// uidialogeventdispatcher.h - PLACEHOLDER for UIDialogEventDispatcher (RTTI .?AVUIDialogEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIDialogEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered. UIAdPushDialog derives from it at +0x178 (ctor 0x141927fb0 called from its ctor) and inherits slots 1-4.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIDialogEventDispatcher : public TSingleton<UIDialogEventDispatcher>
{
public:
    UIDialogEventDispatcher();                              // 0x141927fb0
    virtual ~UIDialogEventDispatcher();                     // 0x141928000
    virtual void vfunc_1(int);                              // 1 0x141928170 broadcast to the listeners
    virtual void vfunc_2(int);                              // 2 0x141928200
    virtual void vfunc_3(void*);                            // 3 0x141928290
    virtual void vfunc_4(void*);                            // 4 0x141928320
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(UIDialogEventDispatcher, 0x28);
