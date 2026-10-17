// cmanufacturemanager.h - PLACEHOLDER for CManufactureManager (RTTI .?AVCManufactureManager@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<CManufactureManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CManufactureManager : public TSingleton<CManufactureManager>
{
public:
    CManufactureManager();                                  // 0x140d50010
    virtual ~CManufactureManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(CManufactureManager, 0x38);
