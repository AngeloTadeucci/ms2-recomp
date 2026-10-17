// npcdata.h - CNpcData (Xml/NpcData/<id>.xml: one npc row), CNpcRegionSpawnData (Table/NpcRegionSpawnData.xml), the
// region spawn result classes and the NpcDataTable that loads them. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); NOT an original header: the member names come from the XML attribute names, the value-block type
// names (Unk_Npc*) are invented.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include <bitset>
#include <iterator>
#include <set>
#include <utility>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/xmlattr.h"

// The 7 floats of <distance>; ctor 0x1402666f0 and operator!= 0x140266790 are defined in commonstringtable.cpp.
struct Unk_Vec7
{
    float m_a, m_b, m_c, m_d, m_e, m_f, m_g;
    Unk_Vec7();
    bool operator!=(const Unk_Vec7& other) const;
};
class CNpcData;
class CNpcRegionSpawnData;
class CRegionSpawnProb;
class CRegionSpawnResult;

// <model>: the kfm, scale, animation speed, spawn alpha animation and offset.
struct Unk_NpcModel
{
    Unk_NpcModel();                                         // 0x1406c8910
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c8990
    bool operator!=(const Unk_NpcModel& o) const;           // 0x1406c8ba0
    CStringA m_strKfm;
    float m_fScale;
    float m_fAniSpeed;
    int m_nSpawnAlphaAnimation;
    Unk_StreamPoint m_vOffset;
};
MS2_CHECK_SIZE(Unk_NpcModel, 0x20);

// <stat>: the base value of each of the 35 stats and the scaling of the level 1 / level 2 tables.
struct Unk_NpcStat
{
    Unk_NpcStat();                                          // 0x1406c8c50
    bool operator!=(const Unk_NpcStat& o) const;            // 0x1406c8cc0
    float GetScaleStatRate() const;                         // 0x1406c8d90
    __int64 GetScaleBaseTap() const;                        // 0x1406c8db0
    __int64 GetScaleBaseDef() const;                        // 0x1406c8dd0
    float GetScaleBaseSpaRate() const;                      // 0x1406c8df0
    __int64 m_aBase[35];
    float m_fScaleStatRate;
    __int64 m_nScaleBaseTap;
    __int64 m_nScaleBaseDef;
    float m_fScaleBaseSpaRate;
};
MS2_CHECK_SIZE(Unk_NpcStat, 0x138);

// <skill>: ids, levels, probs.
struct Unk_NpcSkill
{
    Unk_NpcSkill();                                         // 0x1406c8e10
    bool operator!=(const Unk_NpcSkill& o) const;           // 0x1406c8e60
    bool IsEmpty() const;                                   // 0x1406c8ef0
    std::pair<unsigned, unsigned short> GetSkill(size_t nIndex) const;  // 0x1406c8f20
    size_t GetCount() const;                                // 0x1406c8fd0
    std::vector<unsigned> m_aIds;
    std::vector<unsigned short> m_aLevels;
    std::vector<unsigned> m_aProbs;
};
MS2_CHECK_SIZE(Unk_NpcSkill, 0x48);

// <collision> and <corpse> shape.
struct Unk_NpcShape
{
    Unk_NpcShape();                                         // 0x1406c9000
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c9080 (empty)
    bool operator!=(const Unk_NpcShape& o) const;           // 0x1406c90a0
    CStringA m_strShape;
    float m_fWidth;
    float m_fHeight;
    float m_fDepth;
    int m_nWidthOffset;
    int m_nDepthOffset;
    int m_nHeightOffset;
};
MS2_CHECK_SIZE(Unk_NpcShape, 0x20);

// <capsule>.
struct Unk_NpcCapsule
{
    Unk_NpcCapsule();                                       // 0x1406c92b0
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c92f0 (empty)
    bool operator!=(const Unk_NpcCapsule& o) const;         // 0x1406c9310
    float m_fRadius;
    float m_fHeight;
    int m_nIgnore;
};
MS2_CHECK_SIZE(Unk_NpcCapsule, 0xc);

// <push>.
struct Unk_NpcPush
{
    Unk_NpcPush();                                          // 0x1406c9370
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c93b0 (empty)
    bool operator!=(const Unk_NpcPush& o) const;            // 0x1406c93d0
    float m_fBack;
    float m_fUp;
    float m_fKnockback;
};
MS2_CHECK_SIZE(Unk_NpcPush, 0xc);

// <dead>.
struct Unk_NpcDead
{
    Unk_NpcDead();                                          // 0x1406c9430
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c94b0 (empty)
    bool operator!=(const Unk_NpcDead& o) const;            // 0x1406c94d0
    CStringA GetRandomDefaultAction() const;                // 0x1406c95b0
    CStringA GetRandomUpAction() const;                     // 0x1406c9680
    float m_fTime;
    ATL::CAtlArray<CStringA> m_aDefaultAction;
    ATL::CAtlArray<CStringA> m_aUpAction;
    unsigned m_nRevival;
    int m_nCount;
    float m_fLifeTime;
    unsigned m_nExtendRoomTime;
};
MS2_CHECK_SIZE(Unk_NpcDead, 0x58);

// <normal>: the idle actions with their probabilities and the move area.
struct Unk_NpcNormal
{
    Unk_NpcNormal();                                        // 0x1406c9750
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c9790 (empty)
    bool operator!=(const Unk_NpcNormal& o) const;          // 0x1406c97b0
    ATL::CAtlArray<std::pair<CStringA, int> > m_aActions;
    int m_nMoveArea;
};
MS2_CHECK_SIZE(Unk_NpcNormal, 0x28);

// <dropiteminfo>.
struct Unk_NpcDrop
{
    Unk_NpcDrop();                                          // 0x1406c9800
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c98b0 (empty)
    bool operator!=(const Unk_NpcDrop& o) const;            // 0x1406c98d0
    void GetGlobalDropBoxIds(std::set<unsigned>& setIds) const;     // 0x1406c9a20 (global, dead and hit lists)
    void GetIndividualDropBoxIds(std::set<unsigned>& setIds) const; // 0x1406c9c00 (individual and hit lists)
    float m_fDropHeight;
    float m_fDropDistanceBase;
    int m_nDropDistanceRandom;
    float m_fFireVelocity;
    std::vector<unsigned> m_aGlobalDropBoxId;
    std::vector<unsigned> m_aGlobalDeadDropBoxId;
    std::vector<unsigned> m_aIndividualDropBoxId;
    std::vector<unsigned> m_aGlobalHitDropBoxId;
    std::vector<unsigned> m_aIndividualHitDropBoxId;
};
MS2_CHECK_SIZE(Unk_NpcDrop, 0x88);

// <corpse>.
struct Unk_NpcCorpse
{
    Unk_NpcCorpse();                                        // 0x1406c9d40
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c9dc0 (empty)
    bool operator!=(const Unk_NpcCorpse& o) const;          // 0x1406c9de0
    int m_nHitAble;
    Unk_NpcShape m_shape;
    ATL::CAtlArray<int> m_aRotation;
    CStringA m_strCorpseEffect;
    float m_fOffsetNametag;
    float m_fAdded;
};
MS2_CHECK_SIZE(Unk_NpcCorpse, 0x58);

// <additionalEffect>.
struct Unk_NpcEffect
{
    Unk_NpcEffect();                                        // 0x1406d4dc0
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c9ec0 (empty)
    bool operator!=(const Unk_NpcEffect& o) const;          // 0x1406c9ee0
    ATL::CAtlArray<unsigned> m_aCodes;
    ATL::CAtlArray<unsigned short> m_aLevels;
    std::vector<std::pair<int, int> > m_aGroups;
    ATL::CAtlArray<unsigned> m_aRewardCodes;
    ATL::CAtlArray<unsigned short> m_aRewardLevels;
};
MS2_CHECK_SIZE(Unk_NpcEffect, 0x98);

// <interact>.
struct Unk_NpcInteract
{
    Unk_NpcInteract();                                      // 0x1406c9fb0
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406ca010 (empty)
    bool operator!=(const Unk_NpcInteract& o) const;        // 0x1406ca030
    unsigned m_nCastingTime;
    unsigned m_nCoolTime;
    CStringA m_strFunction;
    CStringA m_strCastingAnimation;
    bool m_bShowCastingBar;
};
MS2_CHECK_SIZE(Unk_NpcInteract, 0x20);

// <lookattarget> (never read by the loader).
struct Unk_NpcLookAt
{
    Unk_NpcLookAt();                                        // 0x1406ca0e0
    void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406ca120 (empty)
    bool operator!=(const Unk_NpcLookAt& o) const;          // 0x1406ca140
    int m_n0;
    int m_n1;
    bool m_b0;
    bool m_b1;
};
MS2_CHECK_SIZE(Unk_NpcLookAt, 0xc);

// One npc row (the <ms2><npc> element of Xml/NpcData/<id>.xml). 0x520 bytes.
class CNpcData : public CPtred
{
public:
    // A <collision> child of <nodeCollisions> / <nodeServerCollisions>.
    class NodeCollision : public CPtred
    {
    public:
        NodeCollision();                                    // 0x1406c9170
        virtual ~NodeCollision() = default;                 // 0x1406d5820 (pinned: the exe dtor has no vptr store)
        void WriteXml(Unk_140165cf0* pParent) const;            // 0x1406c9200 (empty)
        bool operator!=(const NodeCollision& o) const;      // 0x1406c9220
        CStringA m_strTargetNode;
        Unk_StreamPoint m_vVolume;
        Unk_StreamPoint m_vOffset;
    };

    CNpcData();                                             // 0x1406ca1c0
    virtual ~CNpcData();                                    // 0x1406ca570
    virtual bool LoadXml(Unk_140165cf0* pElem);             // 0x1406cae60
    bool operator!=(const CNpcData& o) const;               // 0x1406ca6b0
    bool Load(Unk_140165cf0* pRoot);                        // 0x1406cade0

    int GetId() const;                                      // 0x1406cce20
    CStringA GetStringId() const;                           // 0x1406cce40
    bool IsStationary() const;                              // 0x1406cce90
    bool IsMinimap() const;                                 // 0x1406ccf00
    int GetCorpseHitAble() const;                           // 0x1406ccf20
    bool IsBoss() const;                                    // 0x1406ccf40
    bool IsShopKind() const;                                // 0x1406ccf80
    int GetFriendly() const;                                // 0x1406ccfc0
    int GetAttackGroup() const;                             // 0x1406ccfe0
    int GetDefenseGroup() const;                            // 0x1406cd000
    int GetKind() const;                                    // 0x1406cd020
    int GetClass() const;                                   // 0x1406cd040
    unsigned short GetLevel() const;                        // 0x1406cd060
    CStringA GetEmptyString(int nUnused) const;                      // 0x1406cd080
    unsigned GetShopId() const;                             // 0x1406cd0d0
    int GetNpcType() const;                                 // 0x1406cd0f0
    int GetNpcTypeGroup() const;                            // 0x1406cd150
    bool HasPropertyTag(int nTag) const;                    // 0x1406cd200
    bool IsRace(int nRace) const;                           // 0x1406cd240
    bool HasEventTag(int nTag) const;                       // 0x1406cd280
    bool HasSkill() const;                                  // 0x1406cd2c0
    int GetRace() const;                                    // 0x1406cd310

    int m_nId;                                              // +0x18
    int m_nFriendly;                                        // +0x1c
    CStringA m_strStringId;                                 // +0x20
    unsigned short m_nLevel;                                // +0x28
    int m_nKind;                                            // +0x2c
    int m_nRace;                                            // +0x30
    int m_nAttackGroup;                                     // +0x34
    int m_nDefenseGroup;                                    // +0x38
    unsigned m_nShopId;                                     // +0x3c
    bool m_bMinimap;                                        // +0x40
    std::bitset<31> m_propertyTags;                         // +0x44
    std::bitset<6> m_eventTags;                             // +0x48
    Unk_NpcModel m_model;                                   // +0x50
    int m_nDefenceMaterial;                                 // +0x70
    int m_nHitImmune;                                       // +0x74
    int m_nAbnormalImmune;                                  // +0x78
    int m_nClass;                                           // +0x7c
    CStringA m_strRankIcon;                                 // +0x80
    bool m_bRotationDisabled;                               // +0x88
    bool m_bCarePathToEnemy;                                // +0x89
    bool m_bTalkAni;                                        // +0x8a
    bool m_bBossNotifyDefault;                              // +0x8b
    bool m_bBossNotify;                                     // +0x8c
    bool m_bInstallNpc;                                     // +0x8d
    CStringA m_strPortrait;                                 // +0x90
    float m_fDamagedColorScale;                             // +0x98
    float m_fDamagedVibrateDuration;                        // +0x9c
    float m_fDamagedVibrateAmp;                             // +0xa0
    float m_fCheckCameraDistance;                           // +0xa4
    float m_fExtraCameraDistance;                           // +0xa8
    float m_fBossSoundDistance;                             // +0xac
    float m_fBossSoundEndDistance;                          // +0xb0
    unsigned m_nEmotionId;                                  // +0xb4
    bool m_bLookAtMyPCWhenTalking;                          // +0xb8
    bool m_bUseTalkMotion;                                  // +0xb9
    __int64 m_nCustomExp;                                   // +0xc0
    float m_fShadowScale;                                   // +0xc8
    float m_fRotationSpeed;                                 // +0xcc
    float m_fWalkSpeed;                                     // +0xd0
    float m_fRunSpeed;                                      // +0xd4
    Unk_NpcStat m_stat;                                     // +0xd8
    Unk_Vec7 m_distance;                                    // +0x210
    Unk_NpcSkill m_skill;                                   // +0x230
    Unk_NpcShape m_collision;                               // +0x278
    ATL::CAtlArray<MS2Ptr<NodeCollision> > m_aNodeCollision;        // +0x298
    ATL::CAtlArray<MS2Ptr<NodeCollision> > m_aNodeServerCollision;  // +0x2b8
    Unk_NpcCapsule m_capsule;                               // +0x2d8
    Unk_NpcDead m_dead;                                     // +0x2e8
    Unk_NpcPush m_push;                                     // +0x340
    Unk_NpcNormal m_normal;                                 // +0x350
    Unk_NpcDrop m_drop;                                     // +0x378
    Unk_NpcCorpse m_corpse;                                 // +0x400
    Unk_NpcInteract m_interact;                             // +0x458
    Unk_NpcLookAt m_lookAt;                                 // +0x478
    Unk_NpcEffect m_effect;                                 // +0x488
};
MS2_CHECK_SIZE(CNpcData, 0x520);
