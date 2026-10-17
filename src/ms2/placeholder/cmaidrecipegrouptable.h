// cmaidrecipegrouptable.h - PLACEHOLDER for CMaidRecipeGroupTable (RTTI .?AVCMaidRecipeGroupTable@@, 0x40 bytes). NOT an original header.
// Bases: TSingleton<CMaidRecipeGroupTable> at +0x0, CValidData<CMaidRecipeGroupTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CMaidRecipeGroupTable : public TSingleton<CMaidRecipeGroupTable>,
                              public CValidData<CMaidRecipeGroupTable>
{
public:
    CMaidRecipeGroupTable();                                // 0x140685680
    virtual ~CMaidRecipeGroupTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x40 - 0x10];
};
MS2_CHECK_SIZE(CMaidRecipeGroupTable, 0x40);
