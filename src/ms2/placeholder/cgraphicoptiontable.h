// cgraphicoptiontable.h - PLACEHOLDER for CGraphicOptionTable (RTTI .?AVCGraphicOptionTable@@, 0x168 bytes). NOT an original header.
// Bases: TSingleton<CGraphicOptionTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CGraphicOptionTable : public TSingleton<CGraphicOptionTable>
{
public:
    CGraphicOptionTable();                                  // 0x141375cb0
    virtual ~CGraphicOptionTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x168 - 0x8];
};
MS2_CHECK_SIZE(CGraphicOptionTable, 0x168);
