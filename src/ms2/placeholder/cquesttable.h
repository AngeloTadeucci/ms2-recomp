// cquesttable.h - PLACEHOLDER for CQuestTable (RTTI .?AVCQuestTable@@, 0x58 bytes). NOT an original header.
// Bases: TSingleton<CQuestTable> at +0x0, CValidData<CQuestTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CQuestTable : public TSingleton<CQuestTable>, public CValidData<CQuestTable>
{
public:
    CQuestTable();                                          // 0x1416e3800
    virtual ~CQuestTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x58 - 0x10];
};
MS2_CHECK_SIZE(CQuestTable, 0x58);
