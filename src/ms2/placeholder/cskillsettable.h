// cskillsettable.h - PLACEHOLDER for CSkillSetTable (RTTI .?AVCSkillSetTable@@, 0x98 bytes). NOT an original header.
// Bases: TSingleton<CSkillSetTable> at +0x0, CValidData<CSkillSetTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CSkillSetTable : public TSingleton<CSkillSetTable>, public CValidData<CSkillSetTable>
{
public:
    CSkillSetTable();                                       // 0x140809660
    virtual ~CSkillSetTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x98 - 0x10];
};
MS2_CHECK_SIZE(CSkillSetTable, 0x98);
