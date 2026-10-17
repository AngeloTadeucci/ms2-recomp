// csmartrecommendshoptable.h - PLACEHOLDER for CSmartRecommendShopTable (RTTI .?AVCSmartRecommendShopTable@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<CSmartRecommendShopTable> at +0x0, CValidData<CSmartRecommendShopTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

// The shop list (unit_140815690: the pointer dtor 0x140816560, Release 0x1408178f0); not recovered.
class Unk_SmartRecommendShops : public CPtred
{
};

class CSmartRecommendShopTable : public TSingleton<CSmartRecommendShopTable>,
                                 public CValidData<CSmartRecommendShopTable>
{
public:
    // @0x1414960d0
    CSmartRecommendShopTable() { FUN_140815690(); }
    // @0x141497570
    virtual ~CSmartRecommendShopTable() {}
    void FUN_140815690();                                   // loads the table (unit_140815690)
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_SmartRecommendShops> m_spData;               // +0x10
    char m_pad_20[0x28 - 0x20];
};
MS2_CHECK_SIZE(CSmartRecommendShopTable, 0x28);
