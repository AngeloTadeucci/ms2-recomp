// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The skill "magic" projectiles: CMagicData (one <move> of
// data/xml/table/magicPath.xml), CMagic (a running projectile), CMagicModel, CArrowFillTargetContext and CMagicService.
// Names of members are invented from the XML attribute names the loader reads.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/socketptr.h"

class Unk_140165cf0;    // game TinyXML element

// One <move> element of magicPath.xml (0xc0 bytes, RTTI base CPtred).
class CMagicData : public CPtred
{
public:
    CMagicData();                                                   // 0x14145bd70
    virtual ~CMagicData();                                          // 0 0x141468d80
    // A position between the two control points (random fractions per axis).
    Unk_StreamPoint FUN_14145c030(void* pRandom);                   // 0x14145c030
    bool FUN_14145c180();                                           // 0x14145c180 any control point is not the zero point

    Unk_StreamPoint m_ptFireOffset;                                 // +0x18 fireOffsetPosition
    Unk_StreamPoint m_ptFireFixed;                                  // +0x24 fireFixedPosition
    CString m_strFireNode;                                          // +0x30 fireNode
    int m_nRotation;                                                // +0x38 rotation
    float m_fLifeTime;                                              // +0x3c lifeTime
    float m_fDelayTime;                                             // +0x40 delayTime
    float m_fSpawnTime;                                             // +0x44 spawnTime
    Unk_StreamPoint m_ptDirection;                                  // +0x48 direction
    float m_fDirRotZ;                                               // +0x54 dirRotZDegree
    float m_fVelocity;                                              // +0x58 vel
    float m_fDistance;                                              // +0x5c distance
    float m_fSpeed;                                                 // +0x60 distance / vel
    float m_fNonTargetMoveDistance;                                 // +0x64 nonTargetMoveDistance
    float m_fTraceTargetDuration;                                   // +0x68 traceTargetDuration
    float m_fDestroyTime;                                           // +0x6c destroyTime
    Unk_StreamPoint m_ptControl[2];                                 // +0x70 controlValue0 / controlValue1
    float m_fControlRate;                                           // +0x88 controlRate
    Unk_StreamPoint m_ptControlEnd;                                 // +0x8c controlEndOffsetValue
    int m_nCatmullRom;                                              // +0x98 catmullrom
    unsigned m_nMoveEndHoldDuration;                                // +0x9c moveEndHoldDuration
    int m_nExplosionByDestroy;                                      // +0xa0 explosionByDestroy
    unsigned m_nPiercingAttackInterval;                             // +0xa4 piercingAttackInterval
    unsigned char m_nPiercingAttackMaxTargetCount;                  // +0xa8 piercingAttackMaxTargetCount
    int m_nLookAtType;                                              // +0xac lookAtType
    int m_nIgnoreCancelAtSpawnTime;                                 // +0xb0 ignoreCancelAtSpawnTime
    int m_nIgnorePhysxTestInitPosition;                             // +0xb4 ignorePhysxTestInitPosition
    int m_nTraceTargetOffsetPos;                                    // +0xb8 traceTargetOffsetPos
};
MS2_CHECK_SIZE(CMagicData, 0xc0);

// The <type> element of magicPath.xml: the <move> records of one magic id, boxed so the id table can share it. The exe's
// RTTI calls the element pointer TPtr<CMagicData> and the box TPtredDummy<CAtlArray<TPtr<CMagicData>>>.
typedef ATL::CAtlArray<Unk_SocketPtr<CMagicData> > Unk_MagicList;
template<> struct Unk_SocketRef<Unk_MagicList> {
    static CPtred* Base(Unk_MagicList* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_MagicList>, value);
        return result;
    }
    static TPtredDummy<Unk_MagicList>* New(void*) { return new TPtredDummy<Unk_MagicList>(); }
    static Unk_MagicList* Value(CPtred* p) {
        Unk_MagicList* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_MagicList>*>(p)->value;
        return result;
    }
    static Unk_MagicList* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
typedef Unk_SocketPtr<Unk_MagicList> Unk_MagicListPtr;
MS2_CHECK_SIZE(TPtredDummy<Unk_MagicList>, 0x38);
MS2_CHECK_OFFSET(TPtredDummy<Unk_MagicList>, value, 0x18);

// The magicPath.xml table (cached; reloaded when the file changes on disk).
Unk_MagicListPtr FUN_14145c250(unsigned nMagicId);                  // 0x14145c250 all moves of one id
Unk_SocketPtr<CMagicData> FUN_14145c300(unsigned nMagicId, int nIndex); // 0x14145c300 one move, index wraps
int FUN_14145c4d0();                                                // 0x14145c4d0 loads ./data/xml/table/magicPath.xml
