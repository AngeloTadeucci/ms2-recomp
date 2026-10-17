// ccharacterabilitytable.h - PLACEHOLDER for CCharacterAbilityTable (RTTI .?AVCCharacterAbilityTable@@, 0xf0 bytes). NOT an original header.
// Bases: TSingleton<CCharacterAbilityTable> at +0x0, CValidData<CCharacterAbilityTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CCharacterAbilityTable : public TSingleton<CCharacterAbilityTable>,
                               public CValidData<CCharacterAbilityTable>
{
public:
    CCharacterAbilityTable();                               // 0x1401df5e0
    virtual ~CCharacterAbilityTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xf0 - 0x10];
};
MS2_CHECK_SIZE(CCharacterAbilityTable, 0xf0);
