// clua.h - PLACEHOLDER for CLua (RTTI .?AVCLua@@, 0x70 bytes: CLuaClient's base, its TSingleton at +0x70). NOT an
// original header; the members are not recovered.
#pragma once

#include "ms2/ms2layout.h"

class CLua
{
public:
    virtual ~CLua();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x70 - 0x8];
};
MS2_CHECK_SIZE(CLua, 0x70);
