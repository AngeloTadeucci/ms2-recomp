// cadbannermanagercli.h - PLACEHOLDER for CAdBannerManagerCli (RTTI .?AVCAdBannerManagerCli@@, 0x70 bytes). NOT an original header.
// Bases: CAdBannerManager at +0x8, TSingleton<CAdBannerManagerCli> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cadbannermanager.h"

class CAdBannerManagerCli : public CAdBannerManager, public TSingleton<CAdBannerManagerCli>
{
public:
    CAdBannerManagerCli();                                  // 0x14096b300
    virtual ~CAdBannerManagerCli();
};
MS2_CHECK_SIZE(CAdBannerManagerCli, 0x70);
