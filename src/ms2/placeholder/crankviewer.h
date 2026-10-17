// crankviewer.h - PLACEHOLDER for CRankViewer (RTTI .?AVCRankViewer@@, 0x78 bytes). NOT an original header.
// Bases: TSingleton<CRankViewer> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CRankViewer : public TSingleton<CRankViewer>
{
public:
    CRankViewer();                                          // 0x1407694c0
    virtual ~CRankViewer();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x78 - 0x8];
};
MS2_CHECK_SIZE(CRankViewer, 0x78);
