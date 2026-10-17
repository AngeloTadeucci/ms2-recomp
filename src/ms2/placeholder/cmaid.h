// cmaid.h - PLACEHOLDER for CMaid (RTTI .?AVCMaid@@, 0xf8 bytes), one maid (housekeeper NPC) entry of the maid
// managers. NOT an original header. Bases: CPtred at +0x0 (the exe's Ghidra names its ctor "CMFCZoomKernel").
// Only what the maid managers touch is declared: the key at +0x20 and the order value at +0x54. The rest of the
// layout is unrecovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CInPacket;

class CMaid : public CPtred
{
public:
    CMaid();                                    // 0x14067d030
    virtual ~CMaid();
    void FUN_14067def0(int nMode);       // sets the maid's mode byte
    void FUN_14067d730(CInPacket* pPacket);     // reads the maid's fields from the packet
    MS2_LAYOUT_FRIEND;
    char m_pad_18[0x20 - 0x18];
    unsigned __int64 m_nId;                      // +0x20: the map key
    char m_pad_28[0x54 - 0x28];
    int m_nOrder;                               // +0x54
    char m_pad_58[0xf8 - 0x58];
};
MS2_CHECK_SIZE(CMaid, 0xf8);
MS2_CHECK_OFFSET(CMaid, m_nId, 0x20);
MS2_CHECK_OFFSET(CMaid, m_nOrder, 0x54);
