// jobtable.h - PLACEHOLDER for JobTable (RTTI .?AVJobTable@@, 0x50 bytes). NOT an original header.
// Bases: TSingleton<JobTable> at +0x0, CValidData<JobTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class JobTable : public TSingleton<JobTable>, public CValidData<JobTable>
{
public:
    JobTable();                                             // 0x140644470
    virtual ~JobTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x50 - 0x10];
};
MS2_CHECK_SIZE(JobTable, 0x50);
