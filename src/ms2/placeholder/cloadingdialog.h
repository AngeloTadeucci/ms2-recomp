// cloadingdialog.h - PLACEHOLDER for CLoadingDialog (RTTI .?AVCLoadingDialog@@, 0xf0 bytes). NOT an original header.
// Bases: CPtred at +0x0. The startup splash window CGameApp::InitInstance (?\ms2.cpp) opens (unit_140d4a310, not
// recovered); only the members InitInstance calls are declared.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CLoadingDialog : public CPtred
{
public:
    CLoadingDialog();                                       // 0x140d4a310
    bool FUN_140d4a530(const char* pszName, int n);        // creates the window ("LoadingDialog", 0; true on success)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_18[0xf0 - 0x18];
};
MS2_CHECK_SIZE(CLoadingDialog, 0xf0);
