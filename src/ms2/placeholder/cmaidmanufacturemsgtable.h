// cmaidmanufacturemsgtable.h - PLACEHOLDER for CMaidManufactureMsgTable (RTTI .?AVCMaidManufactureMsgTable@@, 0x40 bytes). NOT an original header.
// Bases: TSingleton<CMaidManufactureMsgTable> at +0x0, CValidData<CMaidManufactureMsgTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CMaidManufactureMsgTable : public TSingleton<CMaidManufactureMsgTable>,
                                 public CValidData<CMaidManufactureMsgTable>
{
public:
    CMaidManufactureMsgTable();                             // 0x14067f840
    virtual ~CMaidManufactureMsgTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x40 - 0x10];
};
MS2_CHECK_SIZE(CMaidManufactureMsgTable, 0x40);
