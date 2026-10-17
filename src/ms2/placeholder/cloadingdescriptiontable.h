// cloadingdescriptiontable.h - PLACEHOLDER for CLoadingDescriptionTable (RTTI .?AVCLoadingDescriptionTable@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<CLoadingDescriptionTable> at +0x0, CValidData<CLoadingDescriptionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

// The description list (?\loadingdescription.cpp: the pointer dtor 0x14144f1f0, Release 0x14144fc50); not recovered.
class Unk_LoadingDescriptions : public CPtred
{
};

class CLoadingDescriptionTable : public TSingleton<CLoadingDescriptionTable>,
                                 public CValidData<CLoadingDescriptionTable>
{
public:
    // @0x141495f20
    CLoadingDescriptionTable() { FUN_14144e400(); }
    // @0x141497470
    virtual ~CLoadingDescriptionTable() {}
    void FUN_14144e400();                                   // loads the descriptions (?\loadingdescription.cpp)
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_LoadingDescriptions> m_spData;               // +0x10
};
MS2_CHECK_SIZE(CLoadingDescriptionTable, 0x20);
