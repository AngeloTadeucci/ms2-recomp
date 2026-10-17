// cfieldmaidmanager.h - PLACEHOLDER for CFieldMaidManager (RTTI .?AVCFieldMaidManager@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<CFieldMaidManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CFieldMaidManager : public TSingleton<CFieldMaidManager>
{
public:
    CFieldMaidManager();                                    // 0x14127e190
    virtual ~CFieldMaidManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(CFieldMaidManager, 0x38);
