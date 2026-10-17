// cloadingimagetable.h - PLACEHOLDER for CLoadingImageTable (RTTI .?AVCLoadingImageTable@@, 0xa8 bytes). NOT an original header.
// Bases: TSingleton<CLoadingImageTable> at +0x0, CValidData<CLoadingImageTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CLoadingImageTable : public TSingleton<CLoadingImageTable>, public CValidData<CLoadingImageTable>
{
public:
    CLoadingImageTable();                                   // 0x140d44410
    virtual ~CLoadingImageTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xa8 - 0x10];
};
MS2_CHECK_SIZE(CLoadingImageTable, 0xa8);
