// uigameoptiondialog.h - UIGameOptionDialog (RTTI .?AVUIGameOptionDialog@@, base UIDialog; 0x1d8 bytes): the options window.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names invented. Ctor 0x141941b80
// (operator new 0x1d8 in CUIService::RegisterDialogs), dtor 0x141942810 (deleting dtor 0x141944be0). The definitions
// belong to unit `?\uigameoptiondialog.cpp`; only the layout is declared here so other units can use the type.
//
// The ctor builds one CBaseOption page per tab id (1 camera, 2 interface, 3 status, 4 battle, 5 community, 6 graphic,
// 7 sound, 8 gamepad (feature 0xb5), 9..0xd input (0xc: feature 0xb5), 0xe language, 0x10 account, 0xf personal-info
// agreement (feature 0x117)) into m_mapPages (ctor 0x1419447f0 = CAtlMap(17, .75f, .25f, 2.25f, 10)).
#pragma once
#include <atlcoll.h>
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/baseoption.h"

class UIGameOptionDialog : public UIDialog
{
public:
    UIGameOptionDialog();                                           // 0x141941b80
    virtual ~UIGameOptionDialog();                                  // 0x141942810

    int m_nTab;                                                     // +0x178 current tab id (1 on a fresh dialog)
    ATL::CAtlMap<int, MS2Ptr<CBaseOption>> m_mapPages;              // +0x180 tab id -> page
    char m_bSimple;                                                 // +0x1c8 simplified (reduced-tab) mode
    int m_nF1cc;                                                    // +0x1cc
    char m_bF1d0;                                                   // +0x1d0
};
MS2_CHECK_SIZE(UIGameOptionDialog, 0x1d8);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_nTab, 0x178);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_mapPages, 0x180);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_bSimple, 0x1c8);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_nF1cc, 0x1cc);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_bF1d0, 0x1d0);
