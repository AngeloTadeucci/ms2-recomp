// attendgiftdatatable.h - PLACEHOLDER for AttendGiftDataTable (RTTI .?AVAttendGiftDataTable@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<AttendGiftDataTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class AttendGiftDataTable : public TSingleton<AttendGiftDataTable>
{
public:
    AttendGiftDataTable();                                  // 0x1401ae2a0
    virtual ~AttendGiftDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x18 - 0x8];
};
MS2_CHECK_SIZE(AttendGiftDataTable, 0x18);
