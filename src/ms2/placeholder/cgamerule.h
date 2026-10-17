// cgamerule.h - PLACEHOLDER for CGameRule (RTTI .?AVCGameRule@@, 0xf58 bytes). NOT an original header.
// Bases: TSingleton<CGameRule> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CGameRule : public TSingleton<CGameRule>
{
public:
    CGameRule();                                            // 0x140474af0
    virtual ~CGameRule();
    // @0x1403f31d0 (GameEventTransferItemBound; name invented)
    void SetTransferItemBound(bool bBound) { m_transferItemBound = bBound; }
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xa9c - 0x8];
    bool m_transferItemBound;                               // +0xa9c
    char m_pad_a9d[0xf58 - 0xa9d];
};
MS2_CHECK_SIZE(CGameRule, 0xf58);
MS2_CHECK_OFFSET(CGameRule, m_transferItemBound, 0xa9c);
