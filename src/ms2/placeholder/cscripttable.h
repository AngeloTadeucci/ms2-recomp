// cscripttable.h - PLACEHOLDER for CScriptTable (RTTI .?AVCScriptTable@@, 0x58 bytes). NOT an original header.
// Bases: TSingleton<CScriptTable> at +0x0, CValidData<CScriptTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CScriptTable : public TSingleton<CScriptTable>, public CValidData<CScriptTable>
{
public:
    CScriptTable();                                         // 0x141020bd0
    virtual ~CScriptTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x58 - 0x10];
};
MS2_CHECK_SIZE(CScriptTable, 0x58);
