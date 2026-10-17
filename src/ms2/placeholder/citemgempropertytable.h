// citemgempropertytable.h - PLACEHOLDER for CItemGemPropertyTable (RTTI .?AVCItemGemPropertyTable@@, 0xa8 bytes). NOT an original header.
// Bases: TSingleton<CItemGemPropertyTable> at +0x0, CValidData<CItemGemPropertyTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemGemPropertyTable : public TSingleton<CItemGemPropertyTable>,
                              public CValidData<CItemGemPropertyTable>
{
public:
    CItemGemPropertyTable();                                // 0x1405abd00
    virtual ~CItemGemPropertyTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xa8 - 0x10];
};
MS2_CHECK_SIZE(CItemGemPropertyTable, 0xa8);
