// scenestategame.h - PLACEHOLDER for CSceneStateGame (RTTI .?AVCSceneStateGame@@), the in-game scene state: 0x78 bytes,
// CSceneStateBase at +0 and IWorldServiceCallback at +0x10 (vftable 0x142f5fa18). NOT an original header: only what the
// scene-state registry (CStateService::OnPreInit) needs, i.e. the constructor (0x14170bda0, bound through
// progress/symbols-manual.tsv) and the size. The real class belongs to client\ms2\scenestategame.cpp.
#pragma once

#include "ms2/client/ms2/scenestatebase.h"

class CSceneStateGame : public CSceneStateBase
{
public:
    CSceneStateGame();                  // 0x14170bda0
private:
    char m_pad_10[0x68];
};
MS2_CHECK_SIZE(CSceneStateGame, 0x78);
