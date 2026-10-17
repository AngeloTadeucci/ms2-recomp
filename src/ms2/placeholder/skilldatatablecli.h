// skilldatatablecli.h - PLACEHOLDER for SkillDataTableCli (RTTI .?AVSkillDataTableCli@@, 0x1c8 bytes). NOT an original header.
// Bases: SkillDataTable at +0x0, TSingleton<SkillDataTableCli> at +0x140.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/skilldatatable.h"

class SkillDataTableCli : public SkillDataTable, public TSingleton<SkillDataTableCli>
{
public:
    SkillDataTableCli();                                    // 0x140aae580
    virtual ~SkillDataTableCli();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_148[0x1c8 - 0x148];
};
MS2_CHECK_SIZE(SkillDataTableCli, 0x1c8);
