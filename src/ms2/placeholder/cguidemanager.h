// cguidemanager.h - PLACEHOLDER for CGuideManager (RTTI .?AVCGuideManager@@, 0x1d0 bytes). NOT an original header.
// Bases: TSingleton<CGuideManager> at +0x0, UIItemEventListener at +0x8, UIUGCEventListener at +0x10, UIStatusEventListener at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class CGuideManager : public TSingleton<CGuideManager>,
                      public UIItemEventListener,
                      public UIUGCEventListener,
                      public UIStatusEventListener
{
public:
    CGuideManager();                                        // 0x14138a4d0
    virtual ~CGuideManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0x1d0 - 0x20];
};
MS2_CHECK_SIZE(CGuideManager, 0x1d0);
