// citemenchantutil.h - PLACEHOLDER for CItemEnchantUtil (RTTI .?AVCItemEnchantUtil@@, 0x50 bytes). NOT an original header.
// Bases: TSingleton<CItemEnchantUtil> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CItemEnchantUtil : public TSingleton<CItemEnchantUtil>
{
public:
    CItemEnchantUtil();                                     // 0x1405942e0
    virtual ~CItemEnchantUtil();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x50 - 0x8];
};
MS2_CHECK_SIZE(CItemEnchantUtil, 0x50);
