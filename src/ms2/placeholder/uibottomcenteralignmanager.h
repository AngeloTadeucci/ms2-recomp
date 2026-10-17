// uibottomcenteralignmanager.h - PLACEHOLDER for UIBottomCenterAlignManager (RTTI .?AVUIBottomCenterAlignManager@@, 0x8 bytes). NOT an original header.
// Bases: TSingleton<UIBottomCenterAlignManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the unit is ?\uibottomcenteralignmanager.cpp
// (0x140bc16c0-0x140bc1b00).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIBottomCenterAlignManager : public TSingleton<UIBottomCenterAlignManager>
{
public:
    UIBottomCenterAlignManager();                           // 0x140bc16c0
    virtual ~UIBottomCenterAlignManager();                  // 0x140bc1700
    void FUN_140bc1730();                                   // stacks the bottom-centre dialogs
};
MS2_CHECK_SIZE(UIBottomCenterAlignManager, 0x8);
