// cluaclient.h - PLACEHOLDER for CLuaClient (RTTI .?AVCLuaClient@@, 0x78 bytes). NOT an original header.
// Bases: CLua at +0x0, TSingleton<CLuaClient> at +0x70.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/clua.h"

class CLuaClient : public CLua, public TSingleton<CLuaClient>
{
public:
    CLuaClient();                                           // 0x14067a440
    virtual ~CLuaClient();
};
MS2_CHECK_SIZE(CLuaClient, 0x78);
