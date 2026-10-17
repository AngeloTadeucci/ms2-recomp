// cquestnavigationmap.h - PLACEHOLDER for CQuestNavigationMap (RTTI .?AVCQuestNavigationMap@@, 0xe0 bytes). NOT an original header.
// Bases: TSingleton<CQuestNavigationMap> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CQuestNavigationMap : public TSingleton<CQuestNavigationMap>
{
public:
    CQuestNavigationMap();                                  // 0x140c90840
    virtual ~CQuestNavigationMap();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xe0 - 0x8];
};
MS2_CHECK_SIZE(CQuestNavigationMap, 0xe0);
