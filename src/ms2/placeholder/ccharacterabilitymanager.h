// ccharacterabilitymanager.h - PLACEHOLDER for CCharacterAbilityManager (RTTI .?AVCCharacterAbilityManager@@, 0x48 bytes). NOT an original header.
// Bases: TSingleton<CCharacterAbilityManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CCharacterAbilityManager : public TSingleton<CCharacterAbilityManager>
{
public:
    CCharacterAbilityManager();                             // 0x140f29a20
    virtual ~CCharacterAbilityManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x48 - 0x8];
};
MS2_CHECK_SIZE(CCharacterAbilityManager, 0x48);
