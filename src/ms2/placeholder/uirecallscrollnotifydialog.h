// uirecallscrollnotifydialog.h - PLACEHOLDER for UIRecallScrollNotifyDialog (RTTI .?AVUIRecallScrollNotifyDialog@@,
// 0x218 bytes). NOT an original header. Ctor 0x14129ba60 (uiservice.cpp creates it); the members are not recovered,
// only what ?\uibottomcenteralignmanager.cpp touches.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"

class UIRecallScrollNotifyDialog : public UIDialog
{
public:
    void FUN_14129c8e0(int nOffset);                        // 0x14129c8e0 stores the int at +0x208
    bool FUN_14129c900();                                   // 0x14129c900 returns the byte at +0x20c
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_178[0x218 - 0x178];
};
MS2_CHECK_SIZE(UIRecallScrollNotifyDialog, 0x218);
