// cpopupprofileimageman.h - PLACEHOLDER for CPopupProfileImageMan (RTTI .?AVCPopupProfileImageMan@@, 0x98 bytes). NOT an original header.
// Bases: TSingleton<CPopupProfileImageMan> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CPopupProfileImageMan : public TSingleton<CPopupProfileImageMan>
{
public:
    CPopupProfileImageMan();                                // 0x141697320
    virtual ~CPopupProfileImageMan();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x98 - 0x8];
};
MS2_CHECK_SIZE(CPopupProfileImageMan, 0x98);
