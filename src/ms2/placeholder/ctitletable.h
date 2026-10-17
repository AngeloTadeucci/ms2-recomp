// ctitletable.h - PLACEHOLDER for CTitleTable (RTTI .?AVCTitleTable@@, 0x98 bytes). NOT an original header.
// Bases: TSingleton<CTitleTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CTitleTable : public TSingleton<CTitleTable>
{
public:
    CTitleTable();                                          // 0x14087a3e0
    virtual ~CTitleTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x98 - 0x8];
};
MS2_CHECK_SIZE(CTitleTable, 0x98);
