// cnametagsymboltable.h - PLACEHOLDER for CNametagSymbolTable (RTTI .?AVCNametagSymbolTable@@, 0x60 bytes). NOT an original header.
// Bases: TSingleton<CNametagSymbolTable> at +0x0, CValidData<CNametagSymbolTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CNametagSymbolTable : public TSingleton<CNametagSymbolTable>, public CValidData<CNametagSymbolTable>
{
public:
    CNametagSymbolTable();                                  // 0x1406c53d0
    virtual ~CNametagSymbolTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x60 - 0x10];
};
MS2_CHECK_SIZE(CNametagSymbolTable, 0x60);
