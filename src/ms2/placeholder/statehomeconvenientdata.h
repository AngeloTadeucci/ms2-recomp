// statehomeconvenientdata.h - PLACEHOLDER for StateHomeConvenientData (RTTI .?AVStateHomeConvenientData@@, vftable
// 0x142e3c010, 0x20 bytes, StateData-derived): the payload of the home convenience state (state 0x36).
// Owning unit is ?\statehomeconvenientdata.cpp (0x140ddcf00-0x140dde050), not recovered yet; this declares only what
// MyPC needs. Field names are invented. NOT an original header.
#pragma once

#include "ms2/placeholder/state.h"

class StateHomeConvenientData : public StateData
{
public:
    StateHomeConvenientData(int nKind);     // 0x140ddcf40

    int m_nKind;                            // +0x18
};
MS2_CHECK_SIZE(StateHomeConvenientData, 0x20);
MS2_CHECK_OFFSET(StateHomeConvenientData, m_nKind, 0x18);
