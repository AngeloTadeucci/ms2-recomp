// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTailEffectObjectFromAdditional: the effect tail of an
// additional effect.
// MS2-UNIT: ?\taileffectobjectfromadditional.cpp
// MS2-RANGE: 0x140ad5df0-0x140ad5f00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\taileffectobjectfromadditional.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "taileffectobjectfromadditional.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140ad5df0
// The by-value data pointer is const: the base is handed a copy made with the const copy ctor (0x140ad0640).
CTailEffectObjectFromAdditional::CTailEffectObjectFromAdditional(GameObject* pOwner,
                                                                 const MS2SvrPtr<TailEffectData> spData,
                                                                 int nAdditionalId)
    : CTailEffectObject(pOwner, spData), m_nAdditionalId(nAdditionalId)
{
}

// @0x140ad5e80
CTailEffectObjectFromAdditional::~CTailEffectObjectFromAdditional()
{
}

// @0x140ad5eb0
bool CTailEffectObjectFromAdditional::vfunc_1()
{
    return false;
}
