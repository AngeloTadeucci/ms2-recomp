// cquestmasktable.h - PLACEHOLDER for CQuestMaskTable (RTTI .?AVCQuestMaskTable@@, 0x98 bytes). NOT an original header.
// Bases: TSingleton<CQuestMaskTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CQuestMaskTable : public TSingleton<CQuestMaskTable>
{
public:
    CQuestMaskTable();                                      // 0x1407648d0
    virtual ~CQuestMaskTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x98 - 0x8];
};
MS2_CHECK_SIZE(CQuestMaskTable, 0x98);
