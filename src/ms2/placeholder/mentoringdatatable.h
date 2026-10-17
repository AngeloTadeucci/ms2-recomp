// mentoringdatatable.h - PLACEHOLDER for MentoringDataTable (RTTI .?AVMentoringDataTable@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<MentoringDataTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class MentoringDataTable : public TSingleton<MentoringDataTable>
{
public:
    MentoringDataTable();                                   // 0x14069bcb0
    virtual ~MentoringDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(MentoringDataTable, 0x38);
