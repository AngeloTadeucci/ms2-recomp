// citemoptiontable.h - PLACEHOLDER for CItemOptionTable (RTTI .?AVCItemOptionTable@@, 0x118 bytes). NOT an original header.
// Bases: TSingleton<CItemOptionTable> at +0x0, CValidData<CItemOptionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemOptionTable : public TSingleton<CItemOptionTable>, public CValidData<CItemOptionTable>
{
public:
    CItemOptionTable();                                     // 0x1405f4140
    virtual ~CItemOptionTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x118 - 0x10];
};
MS2_CHECK_SIZE(CItemOptionTable, 0x118);
