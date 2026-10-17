// cadbannermanager.h - PLACEHOLDER for CAdBannerManager (RTTI .?AVCAdBannerManager@@: CAdBannerManagerCli's base at
// +0x8, after its TSingleton; at most 0x68 bytes, the rest of the 0x70-byte CAdBannerManagerCli). NOT an original
// header; the members are not recovered.
#pragma once

#include "ms2/ms2layout.h"

class CAdBannerManager
{
public:
    virtual ~CAdBannerManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x68 - 0x8];
};
MS2_CHECK_SIZE(CAdBannerManager, 0x68);
