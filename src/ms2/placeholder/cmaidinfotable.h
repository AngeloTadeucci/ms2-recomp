// cmaidinfotable.h - PLACEHOLDER for CMaidInfoTable (RTTI .?AVCMaidInfoTable@@, 0x40 bytes). NOT an original header.
// Bases: TSingleton<CMaidInfoTable> at +0x0, CValidData<CMaidInfoTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CMaidInfoTable : public TSingleton<CMaidInfoTable>, public CValidData<CMaidInfoTable>
{
public:
    CMaidInfoTable();                                       // 0x14067edb0
    virtual ~CMaidInfoTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x40 - 0x10];
};
MS2_CHECK_SIZE(CMaidInfoTable, 0x40);
