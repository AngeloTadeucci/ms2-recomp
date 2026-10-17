// skilldatatable.h - PLACEHOLDER for SkillDataTable (RTTI .?AVSkillDataTable@@, 0x140 bytes: SkillDataTableCli's base,
// its TSingleton at +0x140). NOT an original header; the members are not recovered.
#pragma once

#include "ms2/ms2layout.h"

class SkillDataTable
{
public:
    virtual ~SkillDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x140 - 0x8];
};
MS2_CHECK_SIZE(SkillDataTable, 0x140);
