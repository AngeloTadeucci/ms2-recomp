// cviptable.h - PLACEHOLDER for CVIPTable (RTTI .?AVCVIPTable@@, 0x140 bytes). NOT an original header.
// Bases: TSingleton<CVIPTable> at +0x0, CValidData<CVIPTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CVIPTable : public TSingleton<CVIPTable>, public CValidData<CVIPTable>
{
public:
    CVIPTable();                                            // 0x1408f56f0
    virtual ~CVIPTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x140 - 0x10];
};
MS2_CHECK_SIZE(CVIPTable, 0x140);
