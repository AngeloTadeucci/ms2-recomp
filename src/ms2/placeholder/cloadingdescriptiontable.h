// cloadingdescriptiontable.h - PLACEHOLDER for CLoadingDescriptionTable (RTTI .?AVCLoadingDescriptionTable@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<CLoadingDescriptionTable> at +0x0, CValidData<CLoadingDescriptionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CLoadingDescriptionTable : public TSingleton<CLoadingDescriptionTable>,
                                 public CValidData<CLoadingDescriptionTable>
{
public:
    CLoadingDescriptionTable();                             // 0x141495f20
    virtual ~CLoadingDescriptionTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x20 - 0x10];
};
MS2_CHECK_SIZE(CLoadingDescriptionTable, 0x20);
