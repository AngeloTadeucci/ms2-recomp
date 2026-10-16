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
#include "ms2/placeholder/unk_nodeptr.h"

class Unk_140165cf0;    // game TinyXML element
CPtred* FUN_1404efd80(CPtred* pThis, const CPtred* pOther);      // the exe's CPtred assignment (ICF-folded `return this`)

// One <move> element of magicPath.xml (0xc0 bytes, RTTI base CPtred).
class CMagicData : public CPtred
{
public:
    CMagicData();                                                   // 0x14145bd70
    virtual ~CMagicData() = default;                                // 0 0x141468d80
    // A position between the two control points (random fractions per axis).
    Unk_StreamPoint FUN_14145c030(void* pRandom);                   // 0x14145c030
    CMagicData& operator=(const CMagicData& kOther);                // 0x141468f10 (the implicit copy assignment)
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

// ---- the running projectile ----
struct Unk_MagicTag;
// 16 byte smart pointers shared with the cube/world code (out-of-line members bound by VA in symbols-manual.tsv).
struct Unk_MagicTagPtr {
    Unk_MagicTagPtr();                                              // 0x141234900
    Unk_MagicTagPtr(int);                                           // 0x1410a6af0
    ~Unk_MagicTagPtr();                                             // 0x1410a6d40
    Unk_MagicTagPtr& operator=(const Unk_MagicTagPtr&);             // 0x141235040
    Unk_MagicTag* operator->() const;                               // 0x141235260
    void* m_pad;
    Unk_MagicTag* m_p;
};
MS2_CHECK_SIZE(Unk_MagicTagPtr, 0x10);
struct Unk_MagicValPtr {
    Unk_MagicValPtr() : m_p(0) {}                                   // 0x1414687c0 (inline)
    Unk_MagicValPtr(int);                                           // 0x141234840
    Unk_MagicValPtr(const Unk_MagicValPtr&);                        // 0x141234800
    ~Unk_MagicValPtr();                                             // 0x141234e70
    Unk_MagicValPtr& operator=(const Unk_MagicValPtr&);             // 0x141235000
    void* m_pad;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_MagicValPtr, 0x10);

// Element types of the 8 byte pointer arrays (distinct instantiations in the exe, so distinct types; names invented).
struct Unk_MagicNodeLink;
struct Unk_MagicTargetRef;
struct Unk_MagicArrowRef;

// One of the 16 effect slots of a CMagic: the ids spawned for it and the live effect handle.
struct Unk_MagicSlot {
    Unk_MagicSlot();                                                // 0x141468b30
    ~Unk_MagicSlot();                                               // 0x141468e40
    ATL::CAtlArray<Unk_MagicNodeLink*> m_ids;
    int m_nEffect;
};
MS2_CHECK_SIZE(Unk_MagicSlot, 0x28);

// An id -> id hash map whose members live out of line in the exe (additionalactionadditional.cpp); 0x48 bytes.
class Unk_MagicUIntMap {
public:
    Unk_MagicUIntMap(unsigned nBins, float fOptimalLoad, float fLowThreshold, float fHighThreshold, unsigned nBlockSize);  // 0x140181eb0
    ~Unk_MagicUIntMap();                                            // 0x1401835e0
private:
    void* m_raw[9];
};
MS2_CHECK_SIZE(Unk_MagicUIntMap, 0x48);

class CMagic : public CPtred
{
public:
    CMagic();                                                       // 0x14145d120
    virtual ~CMagic();                                              // 0 0x14145d390

    int m_nState;                                                   // +0x18
    unsigned m_nStateTick;                                          // +0x1c
    Unk_MagicTagPtr m_spSkill;                                      // +0x20
    Unk_MagicTagPtr m_spCaster;                                     // +0x30
    Unk_StreamPoint m_ptStart;                                      // +0x40
    Unk_StreamPoint m_ptTarget;                                     // +0x4c
    Unk_StreamPoint m_ptCurrent;                                    // +0x58
    Unk_StreamPoint m_ptDirection;                                  // +0x64
    Unk_StreamPoint m_ptLast;                                       // +0x70
    Unk_StreamPoint m_ptPredicted;                                  // +0x7c
    Unk_NiMatrix3 m_matRotation;                                    // +0x88
    Unk_StreamPoint m_ptAc;                                         // +0xac
    Unk_StreamPoint m_ptB8;                                         // +0xb8
    float m_fTotalTime;                                             // +0xc4
    float m_fRemainTime;                                            // +0xc8
    unsigned m_nLastTick;                                           // +0xcc
    int m_nD0;                                                      // +0xd0
    Unk_NodePtr m_spScene;                                          // +0xd8 "Scene Root"
    unsigned m_nEffectId;                                           // +0xe0
    unsigned m_nEffectId2;                                          // +0xe4
    CMagicData m_data;                                              // +0xe8 working copy of the move
    ATL::CAtlArray<Unk_MagicNodeLink*> m_arr1A8;                                 // +0x1a8
    int m_n1C8;
    int m_n1CC;
    int m_n1D0;
    Unk_MagicUIntMap m_map1D8;                                      // +0x1d8
    Unk_MagicUIntMap m_map220;                                      // +0x220
    int m_n268;
    int m_n26C;
    Unk_MagicValPtr m_spVal;                                        // +0x270
    int m_n280;
    int m_n284;
    ATL::CAtlArray<Unk_MagicTargetRef*> m_arr288;                                 // +0x288
    Unk_MagicSlot m_slots[16];                                      // +0x2a8
    int m_n528;
    int m_n52C;
    int m_n530;
    int m_n534;
    int m_n538;
    int m_n53C;
    void* m_pCollision;                                             // +0x540
};
MS2_CHECK_SIZE(CMagic, 0x548);

class CMagicModel : public CPtred
{
public:
    CMagicModel();                                                  // 0x141467480
    virtual ~CMagicModel() = default;                               // 0 0x141468db0

    Unk_SocketPtr<CMagic> m_spMagic;                                // +0x18
    Unk_MagicTagPtr m_spA;                                          // +0x28
    Unk_MagicTagPtr m_spB;                                          // +0x38
};
MS2_CHECK_SIZE(CMagicModel, 0x48);

class CArrowFillTargetContext : public CPtred
{
public:
    CArrowFillTargetContext();                                      // 0x1414689b0
    virtual ~CArrowFillTargetContext() = default;                   // 0 0x141468d30

    Unk_MagicTagPtr m_spOwner;                                      // +0x18
    void* m_p28;
    ATL::CAtlArray<Unk_MagicArrowRef*> m_arr30;
    Unk_StreamPoint m_ptFrom;                                       // +0x50
    Unk_StreamPoint m_ptTo;                                         // +0x5c
    Unk_NiMatrix3 m_matAim;                                         // +0x68
    int m_n8C;
    Unk_MagicValPtr m_spVal;                                        // +0x90
    int m_nA0;
    int m_nA4;
};
MS2_CHECK_SIZE(CArrowFillTargetContext, 0xa8);
