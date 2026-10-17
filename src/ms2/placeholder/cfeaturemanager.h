// cfeaturemanager.h - PLACEHOLDER for CFeatureManager (RTTI .?AVCFeatureManager@@, 0x100 bytes). NOT an original header.
// Bases: TSingleton<CFeatureManager> at +0x0, CValidData<CFeatureManager> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CFeatureManager : public TSingleton<CFeatureManager>, public CValidData<CFeatureManager>
{
public:
    CFeatureManager();                                      // 0x14036ca70
    virtual ~CFeatureManager();
    int FUN_14036d8b0();                                     // the server number of the window title
    CString FUN_14036d8e0();                                 // the server name of the window title
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x100 - 0x10];
};
MS2_CHECK_SIZE(CFeatureManager, 0x100);
