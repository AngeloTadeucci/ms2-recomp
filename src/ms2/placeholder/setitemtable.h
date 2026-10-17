// setitemtable.h - PLACEHOLDER for SetItemTable (RTTI .?AVSetItemTable@@, 0x98 bytes). NOT an original header.
// Bases: TSingleton<SetItemTable> at +0x0, CValidData<SetItemTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class SetItemTable : public TSingleton<SetItemTable>, public CValidData<SetItemTable>
{
public:
    SetItemTable();                                         // 0x1407c4980
    virtual ~SetItemTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x98 - 0x10];
};
MS2_CHECK_SIZE(SetItemTable, 0x98);
