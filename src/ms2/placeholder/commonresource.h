// commonresource.h - PLACEHOLDER for CommonResource (RTTI .?AVCommonResource@@, 0x608 bytes). NOT an original header.
// Bases: TSingleton<CommonResource> at +0x0, CValidData<CommonResource> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CommonResource : public TSingleton<CommonResource>, public CValidData<CommonResource>
{
public:
    CommonResource();                                       // 0x140cc2da0
    virtual ~CommonResource();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x608 - 0x10];
};
MS2_CHECK_SIZE(CommonResource, 0x608);
