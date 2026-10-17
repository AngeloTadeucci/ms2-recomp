// cmasterytable.h - PLACEHOLDER for CMasteryTable (RTTI .?AVCMasteryTable@@, 0x328 bytes). NOT an original header.
// Bases: TSingleton<CMasteryTable> at +0x0, CValidData<CMasteryTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CMasteryTable : public TSingleton<CMasteryTable>, public CValidData<CMasteryTable>
{
public:
    CMasteryTable();                                        // 0x140669a20
    virtual ~CMasteryTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x328 - 0x10];
};
MS2_CHECK_SIZE(CMasteryTable, 0x328);
