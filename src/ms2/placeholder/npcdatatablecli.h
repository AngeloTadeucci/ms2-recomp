// npcdatatablecli.h - PLACEHOLDER for NpcDataTableCli (RTTI .?AVNpcDataTableCli@@, 0x160 bytes). NOT an original header.
// Bases: NpcDataTable at +0x8, TSingleton<NpcDataTableCli> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/npcdatatable.h"

class NpcDataTableCli : public NpcDataTable, public TSingleton<NpcDataTableCli>
{
public:
    NpcDataTableCli();                                      // 0x140a7ca40
    virtual ~NpcDataTableCli();
};
MS2_CHECK_SIZE(NpcDataTableCli, 0x160);
