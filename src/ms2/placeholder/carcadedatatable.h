// carcadedatatable.h - PLACEHOLDER for CArcadeDataTable (RTTI .?AVCArcadeDataTable@@, 0xe8 bytes). NOT an original header.
// Bases: TSingleton<CArcadeDataTable> at +0x0, CValidData<CArcadeDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CArcadeDataTable : public TSingleton<CArcadeDataTable>, public CValidData<CArcadeDataTable>
{
public:
    CArcadeDataTable();                                     // 0x141495e10
    virtual ~CArcadeDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xe8 - 0x10];
};
MS2_CHECK_SIZE(CArcadeDataTable, 0xe8);
