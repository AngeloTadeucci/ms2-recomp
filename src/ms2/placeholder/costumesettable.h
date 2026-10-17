// costumesettable.h - PLACEHOLDER for CostumeSetTable (RTTI .?AVCostumeSetTable@@, 0xe0 bytes). NOT an original header.
// Bases: TSingleton<CostumeSetTable> at +0x0, CValidData<CostumeSetTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CostumeSetTable : public TSingleton<CostumeSetTable>, public CValidData<CostumeSetTable>
{
public:
    CostumeSetTable();                                      // 0x140535cd0
    virtual ~CostumeSetTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xe0 - 0x10];
};
MS2_CHECK_SIZE(CostumeSetTable, 0xe0);
