// cpetdatatable.h - PLACEHOLDER for CPetDataTable (RTTI .?AVCPetDataTable@@, 0x130 bytes). NOT an original header.
// Bases: TSingleton<CPetDataTable> at +0x0, CValidData<CPetDataTable> at +0x8, CCacheData at +0x10.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ccachedata.h"

class CPetDataTable : public TSingleton<CPetDataTable>, public CValidData<CPetDataTable>, public CCacheData
{
public:
    CPetDataTable();                                        // 0x140728840
    virtual ~CPetDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_38[0x130 - 0x38];
};
MS2_CHECK_SIZE(CPetDataTable, 0x130);
