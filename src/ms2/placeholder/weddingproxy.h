// weddingproxy.h - PLACEHOLDER for WeddingProxy (RTTI .?AVWeddingProxy@@, 0x140 bytes), the own character's wedding
// record: the couple's two partner records. NOT an original header. Embedded in WeddingManager at +0x8
// (WeddingManager::FUN_140d295d0). Layout from the v2525 reference decomp (work/ext/v2525, include/ms2/client/
// WeddingProxy.h: ctor 0x1408fea10, dtor 0x1408feb00); member names are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// One partner of the couple (0x50 bytes, ctor 0x1408fe100).
struct Unk_WeddingPartner
{
    unsigned char m_pad_00[0x30];
    __int64 m_nCharacterId;                                 // +0x30
    unsigned char m_pad_38[8];
    CStringW m_strName;                                     // +0x40 the character name
    unsigned char m_pad_48[8];
};
MS2_CHECK_OFFSET(Unk_WeddingPartner, m_strName, 0x40);
MS2_CHECK_SIZE(Unk_WeddingPartner, 0x50);

class WeddingProxy : public CPtred
{
public:
    WeddingProxy();                                         // 0x1408fea10
    virtual ~WeddingProxy();

    unsigned char m_pad_18[8];
    int m_nState;                                           // +0x20 the wedding progress state
    unsigned char m_pad_24[0x14];
    Unk_WeddingPartner m_groom;                             // +0x38
    Unk_WeddingPartner m_bride;                             // +0x88
    unsigned char m_pad_d8[0x68];                           // +0xd8 a CLockCriticalSection and unrecovered state
};
MS2_CHECK_OFFSET(WeddingProxy, m_groom, 0x38);
MS2_CHECK_OFFSET(WeddingProxy, m_bride, 0x88);
MS2_CHECK_SIZE(WeddingProxy, 0x140);
