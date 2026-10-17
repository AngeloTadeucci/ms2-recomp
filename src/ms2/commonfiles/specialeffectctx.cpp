// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See ms2/placeholder/cspecialeffectctx.h.
// MS2-UNIT: ?\specialeffectctx.cpp
// MS2-RANGE: 0x140827420-0x140827580 .text$mn
// MS2-PIN: ??_GCSpecialEffectCtx@@UEAAPEAXI@Z 0x140827540
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\specialeffectctx.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/cspecialeffectctx.h"

#include "ms2/ms2recover.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140827420
CSpecialEffectCtx::CSpecialEffectCtx()
    : m_nKind(0),
      m_n30(0)
{
}

// @0x140827490
CSpecialEffectCtx::CSpecialEffectCtx(int nKind)
    : m_nKind(nKind),
      m_n30(0)
{
}

// @0x140827500
CSpecialEffectCtx::~CSpecialEffectCtx()
{
}
