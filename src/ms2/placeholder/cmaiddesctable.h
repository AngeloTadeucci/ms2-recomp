// cmaiddesctable.h - PLACEHOLDER for CMaidDescTable (RTTI .?AVCMaidDescTable@@, 0x40 bytes). NOT an original header.
// Bases: TSingleton<CMaidDescTable> at +0x0, CValidData<CMaidDescTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CMaidDescTable : public TSingleton<CMaidDescTable>, public CValidData<CMaidDescTable>
{
public:
    CMaidDescTable();                                       // 0x14067f240
    virtual ~CMaidDescTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x40 - 0x10];
};
MS2_CHECK_SIZE(CMaidDescTable, 0x40);
