// cbigdatalogsystem.h - PLACEHOLDER for CBigDataLogSystem (RTTI .?AVCBigDataLogSystem@@, 0xe8 bytes). NOT an original header.
// Bases: TSingleton<CBigDataLogSystem> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CBigDataLogSystem : public TSingleton<CBigDataLogSystem>
{
public:
    CBigDataLogSystem();                                    // 0x140a1f690
    virtual ~CBigDataLogSystem();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xe8 - 0x8];
};
MS2_CHECK_SIZE(CBigDataLogSystem, 0xe8);
