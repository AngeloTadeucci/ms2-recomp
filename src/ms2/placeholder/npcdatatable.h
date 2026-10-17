// npcdatatable.h - PLACEHOLDER for NpcDataTable (RTTI .?AVNpcDataTable@@: NpcDataTableCli's base at +0x8, after its
// TSingleton; at most 0x158 bytes, the rest of the 0x160-byte NpcDataTableCli). NOT an original header; the members
// are not recovered.
#pragma once

#include "ms2/ms2layout.h"

class NpcDataTable
{
public:
    virtual ~NpcDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x158 - 0x8];
};
MS2_CHECK_SIZE(NpcDataTable, 0x158);
