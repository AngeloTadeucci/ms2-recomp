// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See magicdata.h.
// MS2-UNIT: ?\magicdata.cpp
// MS2-RANGE: 0x14145bd70-0x1414723a0 .text$mn
// MS2-RANGE: 0x1400f7440-0x1400f77f0 .text$di
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\magicdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "magicdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern Unk_StreamPoint DAT_143b01a60;       // the zero point
extern Unk_StreamPoint DAT_143a08ce8;       // the default direction
extern float FUN_1407680d0(void* pRandom);
extern void FUN_140965c40(Unk_StreamPoint* pRange, Unk_StreamPoint* pOut, Unk_StreamPoint* pBase, void* pCtx, float x, float z);

// @0x14145bd70
CMagicData::CMagicData()
{
    m_ptFireOffset = DAT_143b01a60;
    m_ptFireFixed = DAT_143b01a60;
    m_nRotation = 1;
    m_fLifeTime = 0;
    m_fDelayTime = 0;
    m_fSpawnTime = 0;
    m_ptDirection = DAT_143a08ce8;
    m_fDirRotZ = 0;
    m_fVelocity = 0;
    m_fDistance = 0;
    m_fSpeed = (m_fVelocity > 0.0f) ? m_fDistance / m_fVelocity : 0.0f;
    m_fNonTargetMoveDistance = 0;
    m_fTraceTargetDuration = 0;
    m_fDestroyTime = 0;
    m_ptControl[0] = DAT_143b01a60;
    m_ptControl[1] = DAT_143b01a60;
    m_fControlRate = 0;
    m_ptControlEnd = DAT_143b01a60;
    m_nCatmullRom = 0;
    m_nMoveEndHoldDuration = 0;
    m_nExplosionByDestroy = 1;
    m_nPiercingAttackInterval = 0;
    m_nPiercingAttackMaxTargetCount = 0;
    m_nLookAtType = 0;
    m_nIgnorePhysxTestInitPosition = 0;
    m_nIgnoreCancelAtSpawnTime = 0;
    m_nTraceTargetOffsetPos = 0;
}

// @0x14145c030
// MS2-FUNCTIONAL: efd::Point3 random-range helper; the exe keeps the random floats in the outgoing-argument slots, a different temp layout than any source form probed
Unk_StreamPoint CMagicData::FUN_14145c030(void* pRandom)
{
    float rx = FUN_1407680d0(pRandom);
    float ry = FUN_1407680d0(pRandom);
    float rz = FUN_1407680d0(pRandom);
    Unk_StreamPoint range;
    FUN_140965c40(&m_ptControl[1], &range, &m_ptControl[0], pRandom, rx, rz);
    Unk_StreamPoint result = DAT_143b01a60;
    result.x = m_ptControl[0].x + range.x * rx;
    result.y = m_ptControl[0].y + range.y * ry;
    result.z = m_ptControl[0].z + range.z * rz;
    return result;
}

// @0x14145c180
// MS2-FUNCTIONAL: any-nonzero-control-point test; exe passes the Point3 ctor's returned pointer to operator!=, 7 bytes of temp shuffling differ
bool CMagicData::FUN_14145c180()
{
    Unk_StreamPoint zeroA(0, 0, 0);
    if (m_ptControl[0].FUN_140552700(zeroA))
        return true;
    Unk_StreamPoint zeroB(0, 0, 0);
    if (m_ptControl[1].FUN_140552700(zeroB))
        return true;
    Unk_StreamPoint zeroC(0, 0, 0);
    return m_ptControlEnd.FUN_140552700(zeroC);
}

// @0x141468d80
// MS2-FUNCTIONAL: dtor chain differs in the exe's COMDAT/unwind form
CMagicData::~CMagicData()
{
}
