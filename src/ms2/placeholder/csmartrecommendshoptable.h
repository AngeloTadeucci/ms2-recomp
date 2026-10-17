// csmartrecommendshoptable.h - PLACEHOLDER for CSmartRecommendShopTable (RTTI .?AVCSmartRecommendShopTable@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<CSmartRecommendShopTable> at +0x0, CValidData<CSmartRecommendShopTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CSmartRecommendShopTable : public TSingleton<CSmartRecommendShopTable>,
                                 public CValidData<CSmartRecommendShopTable>
{
public:
    CSmartRecommendShopTable();                             // 0x1414960d0
    virtual ~CSmartRecommendShopTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x28 - 0x10];
};
MS2_CHECK_SIZE(CSmartRecommendShopTable, 0x28);
