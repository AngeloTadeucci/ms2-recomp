// cquestnavigator.h - PLACEHOLDER for CQuestNavigator (RTTI .?AVCQuestNavigator@@, 0xc0 bytes). NOT an original header.
// Bases: TSingleton<CQuestNavigator> at +0x0, UIQuestEventListener at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"

class CQuestNavigator : public TSingleton<CQuestNavigator>, public UIQuestEventListener
{
public:
    CQuestNavigator();                                      // 0x140c99700
    virtual ~CQuestNavigator();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xc0 - 0x10];
};
MS2_CHECK_SIZE(CQuestNavigator, 0xc0);
