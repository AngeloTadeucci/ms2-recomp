// ckeytable.h - PLACEHOLDER for CKeyTable (RTTI .?AVCKeyTable@@, 0x2a8 bytes). NOT an original header.
// Bases: TSingleton<CKeyTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CKeyTable : public TSingleton<CKeyTable>
{
public:
    CKeyTable();                                            // 0x141428830
    virtual ~CKeyTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x2a8 - 0x8];
};
MS2_CHECK_SIZE(CKeyTable, 0x2a8);
