// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNpcData (Xml/NpcData/<id>.xml), the value blocks of a row
// (model, stats, shapes, drop, ...), the region spawn classes (Table/NpcRegionSpawnData.xml) and the NpcDataTable that
// loads them, plus the container glue of those members (CAtlArray, std::vector, CAtlMap, std::bitset).
// MS2-UNIT: commonfiles\npcdata.cpp
// MS2-RANGE: 0x1406c8680-0x1406dc170 .text$mn
// MS2-RANGE: 0x1400bb810-0x1400bb9a0 .text$di
// MS2-PIN: ??1NodeCollision@CNpcData@@UEAA@XZ 0x1406d5820
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\npcdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "npcdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <stdlib.h>

// The sort names of the item lists (header statics; the 8 name table first, as in the exe's initializer order).
static CStringA s_sortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CStringA s_sortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// Unrecovered helpers.
void FUN_14086f970(void* pElem, const char* pszName, double fValue);            // SetDoubleAttribute
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);               // SetAttribute(name, int)
void FUN_140874050(void* pElem, const char* pszName, const CStringA& strValue); // SetAttribute(name, string)
struct Unk_NpcPoint3
{
    Unk_NpcPoint3(const Unk_StreamPoint& pt);   // 0x14027dcf0
    float x, y, z;
};
void FUN_140874ad0(void* pElem, const char* pszName, const Unk_NpcPoint3& vValue);      // SetAttribute(name, "x, y, z")
void* FUN_14086e000(void* pParent, const void* pChild);                         // InsertEndChild
Unk_140165cf0* FUN_14028f8d0(Unk_140165cf0* pParent);                           // first child element
bool FUN_14028d470(float a, float b);                                           // approx equal

class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
private:
    void* m_data[0x12];
};

// @0x1406c8910
Unk_NpcModel::Unk_NpcModel() : m_fScale(1.0f), m_fAniSpeed(1.0f), m_nSpawnAlphaAnimation(1), m_vOffset(0.0f, 0.0f, 0.0f)
{
}

// @0x1406c8990
// MS2-FUNCTIONAL: frame is 2 bytes larger in the exe (the zero Unk_StreamPoint temp / Unk_NpcPoint3 temp placement)
void Unk_NpcModel::WriteXml(Unk_140165cf0* pParent) const
{
    static Unk_NpcModel s_default;
    if (*this != s_default)
    {
        Unk_TiXmlElement elem("model");
        if (m_strKfm != "")
            FUN_140874050(&elem, "kfm", m_strKfm);
        if (m_fScale != 1.0f)
            FUN_14086f970(&elem, "scale", m_fScale);
        if (m_fAniSpeed != 1.0f)
            FUN_14086f970(&elem, "anispeed", m_fAniSpeed);
        if (m_nSpawnAlphaAnimation != 1)
            FUN_140873ca0(&elem, "spawnAlphaAnimation", m_nSpawnAlphaAnimation);
        if (m_vOffset.FUN_140552700(Unk_StreamPoint(0.0f, 0.0f, 0.0f)))
            FUN_140874ad0(&elem, "offset", Unk_NpcPoint3(m_vOffset));
        FUN_14086e000(pParent, &elem);
    }
}

// @0x1406c8ba0
bool Unk_NpcModel::operator!=(const Unk_NpcModel& o) const
{
    if (m_strKfm != o.m_strKfm)
        return true;
    if (m_fScale != o.m_fScale)
        return true;
    if (m_fAniSpeed != o.m_fAniSpeed)
        return true;
    if (m_nSpawnAlphaAnimation != o.m_nSpawnAlphaAnimation)
        return true;
    if (m_vOffset.FUN_140552700(o.m_vOffset))
        return true;
    return false;
}

// Container comparisons (true = same).
template <class T> bool IsSameArray(const ATL::CAtlArray<T>& a, const ATL::CAtlArray<T>& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (size_t i = 0; i < a.GetCount(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
template <class T> bool IsSameArray(const ATL::CAtlArray<MS2Ptr<T> >& a, const ATL::CAtlArray<MS2Ptr<T> >& b)
{
    if (a.GetCount() != b.GetCount())
        return false;
    for (size_t i = 0; i < a.GetCount(); i++)
    {
        if (*a[i] != *b[i])
            return false;
    }
    return true;
}
template <class T> bool IsSameVector(const std::vector<T>& a, const std::vector<T>& b)
{
    if (a.size() != b.size())
        return false;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// @0x1406c8c50
Unk_NpcStat::Unk_NpcStat() : m_fScaleStatRate(0), m_nScaleBaseTap(0), m_nScaleBaseDef(0), m_fScaleBaseSpaRate(0)
{
    memset(m_aBase, 0, sizeof(m_aBase));
}

// @0x1406c8cc0
bool Unk_NpcStat::operator!=(const Unk_NpcStat& o) const
{
    for (int i = 0; i < 35; i++)
    {
        if (m_aBase[i] != o.m_aBase[i])
            return true;
    }
    if (m_fScaleStatRate != o.m_fScaleStatRate)
        return true;
    if (m_nScaleBaseTap != o.m_nScaleBaseTap)
        return true;
    if (m_nScaleBaseDef != o.m_nScaleBaseDef)
        return true;
    if (m_fScaleBaseSpaRate != o.m_fScaleBaseSpaRate)
        return true;
    return false;
}

// @0x1406c8d90
float Unk_NpcStat::GetScaleStatRate() const
{
    return m_fScaleStatRate;
}

// @0x1406c8db0
__int64 Unk_NpcStat::GetScaleBaseTap() const
{
    return m_nScaleBaseTap;
}

// @0x1406c8dd0
__int64 Unk_NpcStat::GetScaleBaseDef() const
{
    return m_nScaleBaseDef;
}

// @0x1406c8df0
float Unk_NpcStat::GetScaleBaseSpaRate() const
{
    return m_fScaleBaseSpaRate;
}

// @0x1406c8e10
Unk_NpcSkill::Unk_NpcSkill()
{
}

// @0x1406c8e60
bool Unk_NpcSkill::operator!=(const Unk_NpcSkill& o) const
{
    if (m_aIds != o.m_aIds)
        return true;
    if (m_aLevels != o.m_aLevels)
        return true;
    if (m_aProbs != o.m_aProbs)
        return true;
    return false;
}

// @0x1406c8ef0
bool Unk_NpcSkill::IsEmpty() const
{
    return m_aIds.empty();
}

// @0x1406c8f20
std::pair<unsigned, unsigned short> Unk_NpcSkill::GetSkill(size_t nIndex) const
{
    if (nIndex >= m_aIds.size())
        return std::pair<unsigned, unsigned short>();
    unsigned short nLevel = 1;
    if (nIndex < m_aLevels.size())
        nLevel = m_aLevels[nIndex];
    return std::pair<unsigned, unsigned short>(m_aIds[nIndex], nLevel);
}

// @0x1406c8fd0
size_t Unk_NpcSkill::GetCount() const
{
    return m_aIds.size();
}

// @0x1406c9000
Unk_NpcShape::Unk_NpcShape()
    : m_fWidth(0), m_fHeight(0), m_fDepth(0), m_nWidthOffset(0), m_nDepthOffset(0), m_nHeightOffset(0)
{
}

// @0x1406c9080
void Unk_NpcShape::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c90a0
bool Unk_NpcShape::operator!=(const Unk_NpcShape& o) const
{
    if (m_strShape != o.m_strShape)
        return true;
    if (m_fWidth != o.m_fWidth)
        return true;
    if (m_fHeight != o.m_fHeight)
        return true;
    if (m_fDepth != o.m_fDepth)
        return true;
    if (m_nWidthOffset != o.m_nWidthOffset)
        return true;
    if (m_nDepthOffset != o.m_nDepthOffset)
        return true;
    if (m_nHeightOffset != o.m_nHeightOffset)
        return true;
    return false;
}

// @0x1406c9170
CNpcData::NodeCollision::NodeCollision() : m_vVolume(0.0f, 0.0f, 0.0f), m_vOffset(0.0f, 0.0f, 0.0f)
{
}

// @0x1406c9200
void CNpcData::NodeCollision::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c9220
bool CNpcData::NodeCollision::operator!=(const NodeCollision& o) const
{
    if (m_strTargetNode != o.m_strTargetNode)
        return true;
    if (m_vVolume.FUN_140552700(o.m_vVolume))
        return true;
    if (m_vOffset.FUN_140552700(o.m_vOffset))
        return true;
    return false;
}

// @0x1406c92b0
Unk_NpcCapsule::Unk_NpcCapsule() : m_fRadius(0), m_fHeight(0), m_nIgnore(0)
{
}

// @0x1406c92f0
void Unk_NpcCapsule::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c9310
bool Unk_NpcCapsule::operator!=(const Unk_NpcCapsule& o) const
{
    if (m_fRadius != o.m_fRadius)
        return true;
    if (m_fHeight != o.m_fHeight)
        return true;
    if (m_nIgnore != o.m_nIgnore)
        return true;
    return false;
}

// @0x1406c9370
Unk_NpcPush::Unk_NpcPush() : m_fBack(0), m_fUp(0), m_fKnockback(0)
{
}

// @0x1406c93b0
void Unk_NpcPush::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c93d0
bool Unk_NpcPush::operator!=(const Unk_NpcPush& o) const
{
    if (m_fBack != o.m_fBack)
        return true;
    if (m_fUp != o.m_fUp)
        return true;
    if (m_fKnockback != o.m_fKnockback)
        return true;
    return false;
}

// @0x1406c9430
Unk_NpcDead::Unk_NpcDead() : m_fTime(0), m_nRevival(0), m_nCount(0), m_fLifeTime(0), m_nExtendRoomTime(0)
{
}

// @0x1406c94b0
void Unk_NpcDead::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c94d0
bool Unk_NpcDead::operator!=(const Unk_NpcDead& o) const
{
    if (m_fTime != o.m_fTime)
        return true;
    if (!IsSameArray(m_aDefaultAction, o.m_aDefaultAction))
        return true;
    if (!IsSameArray(m_aUpAction, o.m_aUpAction))
        return true;
    if (m_nRevival != o.m_nRevival)
        return true;
    if (m_nCount != o.m_nCount)
        return true;
    if (m_fLifeTime != o.m_fLifeTime)
        return true;
    if (m_nExtendRoomTime != o.m_nExtendRoomTime)
        return true;
    return false;
}

// @0x1406c95b0
CStringA Unk_NpcDead::GetRandomDefaultAction() const
{
    if (m_aDefaultAction.IsEmpty())
        return CStringA("Dead_A");
    return m_aDefaultAction[rand() % m_aDefaultAction.GetCount()];
}

// @0x1406c9680
CStringA Unk_NpcDead::GetRandomUpAction() const
{
    if (m_aUpAction.IsEmpty())
        return CStringA("");
    return m_aUpAction[rand() % m_aUpAction.GetCount()];
}

// @0x1406c9750
Unk_NpcNormal::Unk_NpcNormal() : m_nMoveArea(0)
{
}

// @0x1406c9790
void Unk_NpcNormal::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c97b0
bool Unk_NpcNormal::operator!=(const Unk_NpcNormal& o) const
{
    if (!IsSameArray(m_aActions, o.m_aActions))
        return true;
    if (m_nMoveArea != o.m_nMoveArea)
        return true;
    return false;
}

// @0x1406c9800
Unk_NpcDrop::Unk_NpcDrop() : m_fDropHeight(0), m_fDropDistanceBase(50.0f), m_nDropDistanceRandom(100), m_fFireVelocity(100.0f)
{
}

// @0x1406c98b0
void Unk_NpcDrop::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c98d0
bool Unk_NpcDrop::operator!=(const Unk_NpcDrop& o) const
{
    if (m_fDropHeight != o.m_fDropHeight)
        return true;
    if (m_fDropDistanceBase != o.m_fDropDistanceBase)
        return true;
    if (m_nDropDistanceRandom != o.m_nDropDistanceRandom)
        return true;
    if (m_fFireVelocity != o.m_fFireVelocity)
        return true;
    if (!IsSameVector(m_aGlobalDropBoxId, o.m_aGlobalDropBoxId))
        return true;
    if (!IsSameVector(m_aGlobalDeadDropBoxId, o.m_aGlobalDeadDropBoxId))
        return true;
    if (!IsSameVector(m_aIndividualDropBoxId, o.m_aIndividualDropBoxId))
        return true;
    if (!IsSameVector(m_aGlobalHitDropBoxId, o.m_aGlobalHitDropBoxId))
        return true;
    if (!IsSameVector(m_aIndividualHitDropBoxId, o.m_aIndividualHitDropBoxId))
        return true;
    return false;
}

// @0x1406c9a20
void Unk_NpcDrop::GetGlobalDropBoxIds(std::set<unsigned>& setIds) const
{
    std::copy(m_aGlobalDropBoxId.begin(), m_aGlobalDropBoxId.end(), std::inserter(setIds, setIds.end()));
    std::copy(m_aGlobalDeadDropBoxId.begin(), m_aGlobalDeadDropBoxId.end(), std::inserter(setIds, setIds.end()));
    std::copy(m_aGlobalHitDropBoxId.begin(), m_aGlobalHitDropBoxId.end(), std::inserter(setIds, setIds.end()));
}

// @0x1406c9c00
void Unk_NpcDrop::GetIndividualDropBoxIds(std::set<unsigned>& setIds) const
{
    std::copy(m_aIndividualDropBoxId.begin(), m_aIndividualDropBoxId.end(), std::inserter(setIds, setIds.end()));
    std::copy(m_aIndividualHitDropBoxId.begin(), m_aIndividualHitDropBoxId.end(), std::inserter(setIds, setIds.end()));
}

// @0x1406c9d40
Unk_NpcCorpse::Unk_NpcCorpse() : m_nHitAble(0), m_fOffsetNametag(0), m_fAdded(0)
{
}

// @0x1406c9dc0
void Unk_NpcCorpse::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c9de0
bool Unk_NpcCorpse::operator!=(const Unk_NpcCorpse& o) const
{
    if (m_nHitAble != o.m_nHitAble)
        return true;
    if (m_shape != o.m_shape)
        return true;
    if (!IsSameArray(m_aRotation, o.m_aRotation))
        return true;
    if (m_strCorpseEffect != o.m_strCorpseEffect)
        return true;
    if (m_fOffsetNametag != o.m_fOffsetNametag)
        return true;
    if (m_fAdded != o.m_fAdded)
        return true;
    return false;
}

// @0x1406c9ec0
void Unk_NpcEffect::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406c9ee0
bool Unk_NpcEffect::operator!=(const Unk_NpcEffect& o) const
{
    if (!IsSameArray(m_aCodes, o.m_aCodes))
        return true;
    if (!IsSameArray(m_aLevels, o.m_aLevels))
        return true;
    if (!IsSameVector(m_aGroups, o.m_aGroups))
        return true;
    if (!IsSameArray(m_aRewardCodes, o.m_aRewardCodes))
        return true;
    if (!IsSameArray(m_aRewardLevels, o.m_aRewardLevels))
        return true;
    return false;
}

// @0x1406c9fb0
Unk_NpcInteract::Unk_NpcInteract() : m_nCastingTime(0), m_nCoolTime(0), m_bShowCastingBar(true)
{
}

// @0x1406ca010
void Unk_NpcInteract::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406ca030
bool Unk_NpcInteract::operator!=(const Unk_NpcInteract& o) const
{
    if (m_nCastingTime != o.m_nCastingTime)
        return true;
    if (m_nCoolTime != o.m_nCoolTime)
        return true;
    if (m_strFunction != o.m_strFunction)
        return true;
    if (m_strCastingAnimation != o.m_strCastingAnimation)
        return true;
    if (m_bShowCastingBar != o.m_bShowCastingBar)
        return true;
    return false;
}

// @0x1406ca0e0
Unk_NpcLookAt::Unk_NpcLookAt() : m_n0(0), m_n1(0), m_b0(false), m_b1(false)
{
}

// @0x1406ca120
void Unk_NpcLookAt::WriteXml(Unk_140165cf0*) const
{
}

// @0x1406ca140
bool Unk_NpcLookAt::operator!=(const Unk_NpcLookAt& o) const
{
    if (m_n0 != o.m_n0)
        return true;
    if (m_n1 != o.m_n1)
        return true;
    if (m_b0 != o.m_b0)
        return true;
    if (m_b1 != o.m_b1)
        return true;
    return false;
}

// @0x1406ca1c0
CNpcData::CNpcData()
    : m_nId(0), m_nFriendly(0), m_nLevel(1), m_nKind(0), m_nRace(0), m_nAttackGroup(0), m_nDefenseGroup(0), m_nShopId(0),
      m_bMinimap(true), m_nDefenceMaterial(0), m_nHitImmune(0), m_nAbnormalImmune(0), m_nClass(1),
      m_bRotationDisabled(false), m_bCarePathToEnemy(false), m_bTalkAni(true), m_bBossNotifyDefault(false),
      m_bBossNotify(false), m_bInstallNpc(false), m_fDamagedColorScale(2.0f), m_fDamagedVibrateDuration(0),
      m_fDamagedVibrateAmp(0), m_fCheckCameraDistance(0), m_fExtraCameraDistance(0), m_fBossSoundDistance(2000.0f),
      m_fBossSoundEndDistance(3000.0f), m_nEmotionId(0), m_bLookAtMyPCWhenTalking(true), m_bUseTalkMotion(true),
      m_nCustomExp(-1), m_fShadowScale(0), m_fRotationSpeed(0), m_fWalkSpeed(0), m_fRunSpeed(0)
{
}

// @0x1406ca570
CNpcData::~CNpcData()
{
}

// @0x1406ca6b0
bool CNpcData::operator!=(const CNpcData& o) const
{
    if (m_model != o.m_model)
        return true;
    if (m_strStringId != o.m_strStringId)
        return true;
    if (m_nFriendly != o.m_nFriendly)
        return true;
    if (m_nAttackGroup != o.m_nAttackGroup)
        return true;
    if (m_nDefenseGroup != o.m_nDefenseGroup)
        return true;
    if (m_nKind != o.m_nKind)
        return true;
    if (m_nShopId != o.m_nShopId)
        return true;
    if (m_bMinimap != o.m_bMinimap)
        return true;
    if (m_nDefenceMaterial != o.m_nDefenceMaterial)
        return true;
    if (m_nHitImmune != o.m_nHitImmune)
        return true;
    if (m_nAbnormalImmune != o.m_nAbnormalImmune)
        return true;
    if (m_nLevel != o.m_nLevel)
        return true;
    if (m_nClass != o.m_nClass)
        return true;
    if (m_strRankIcon != o.m_strRankIcon)
        return true;
    if (m_bRotationDisabled != o.m_bRotationDisabled)
        return true;
    if (m_bCarePathToEnemy != o.m_bCarePathToEnemy)
        return true;
    if (m_bBossNotify != o.m_bBossNotify)
        return true;
    if (m_nEmotionId != o.m_nEmotionId)
        return true;
    if (m_bInstallNpc != o.m_bInstallNpc)
        return true;
    if (m_strPortrait != o.m_strPortrait)
        return true;
    if (m_bTalkAni != o.m_bTalkAni)
        return true;
    if (m_fDamagedColorScale != o.m_fDamagedColorScale)
        return true;
    if (m_fDamagedVibrateDuration != o.m_fDamagedVibrateDuration)
        return true;
    if (m_fDamagedVibrateAmp != o.m_fDamagedVibrateAmp)
        return true;
    if (m_fCheckCameraDistance != o.m_fCheckCameraDistance)
        return true;
    if (m_fExtraCameraDistance != o.m_fExtraCameraDistance)
        return true;
    if (m_fBossSoundDistance != o.m_fBossSoundDistance)
        return true;
    if (m_fBossSoundEndDistance != o.m_fBossSoundEndDistance)
        return true;
    if (m_bLookAtMyPCWhenTalking != o.m_bLookAtMyPCWhenTalking)
        return true;
    if (m_bUseTalkMotion != o.m_bUseTalkMotion)
        return true;
    if (m_fShadowScale != o.m_fShadowScale)
        return true;
    if (m_fRotationSpeed != o.m_fRotationSpeed)
        return true;
    if (m_fWalkSpeed != o.m_fWalkSpeed)
        return true;
    if (m_fRunSpeed != o.m_fRunSpeed)
        return true;
    if (m_stat != o.m_stat)
        return true;
    if (m_distance != o.m_distance)
        return true;
    if (m_skill != o.m_skill)
        return true;
    if (m_effect != o.m_effect)
        return true;
    if (m_interact != o.m_interact)
        return true;
    if (m_lookAt != o.m_lookAt)
        return true;
    if (m_collision != o.m_collision)
        return true;
    if (!IsSameArray(m_aNodeCollision, o.m_aNodeCollision))
        return true;
    if (!IsSameArray(m_aNodeServerCollision, o.m_aNodeServerCollision))
        return true;
    if (m_corpse != o.m_corpse)
        return true;
    if (m_capsule != o.m_capsule)
        return true;
    if (m_dead != o.m_dead)
        return true;
    if (m_push != o.m_push)
        return true;
    if (m_nCustomExp != o.m_nCustomExp)
        return true;
    if (m_normal != o.m_normal)
        return true;
    if (m_drop != o.m_drop)
        return true;
    return false;
}

// @0x1406cade0
bool CNpcData::Load(Unk_140165cf0* pRoot)
{
    FUN_140873220(pRoot, "id", (unsigned&)m_nId);
    if (m_nId == 0)
        return false;
    Unk_140165cf0* pElem = FUN_14028f8d0(pRoot);
    if (!pElem)
        return false;
    return LoadXml(pElem);
}

// @0x1406cce20
int CNpcData::GetId() const
{
    return m_nId;
}

// @0x1406cce40
CStringA CNpcData::GetStringId() const
{
    return m_strStringId;
}

// @0x1406cce90
bool CNpcData::IsStationary() const
{
    return (FUN_14028d470(m_fRunSpeed, 0) && FUN_14028d470(m_fWalkSpeed, 0)) ? 1 : 0;
}

// @0x1406ccf00
bool CNpcData::IsMinimap() const
{
    return m_bMinimap;
}

// @0x1406ccf20
int CNpcData::GetCorpseHitAble() const
{
    return m_corpse.m_nHitAble;
}

// @0x1406ccf40
bool CNpcData::IsBoss() const
{
    if (GetFriendly() == 0 && m_nClass >= 3)
        return true;
    return false;
}

// @0x1406ccf80
bool CNpcData::IsShopKind() const
{
    if (m_nKind == 1 || (m_nKind > 10 && m_nKind < 30))
        return true;
    return false;
}

// @0x1406ccfc0
int CNpcData::GetFriendly() const
{
    return m_nFriendly;
}

// @0x1406ccfe0
int CNpcData::GetAttackGroup() const
{
    return m_nAttackGroup;
}

// @0x1406cd000
int CNpcData::GetDefenseGroup() const
{
    return m_nDefenseGroup;
}

// @0x1406cd020
int CNpcData::GetKind() const
{
    return m_nKind;
}

// @0x1406cd040
int CNpcData::GetClass() const
{
    return m_nClass;
}

// @0x1406cd060
unsigned short CNpcData::GetLevel() const
{
    return m_nLevel;
}

// @0x1406cd080
CStringA CNpcData::GetEmptyString(int) const
{
    return CStringA("");
}

// @0x1406cd0d0
unsigned CNpcData::GetShopId() const
{
    return m_nShopId;
}

// @0x1406cd0f0
int CNpcData::GetNpcType() const
{
    if (IsShopKind())
        return 1;
    if (m_nKind >= 30 && m_nKind < 40)
        return 4;
    return m_nKind;
}

// @0x1406cd150
int CNpcData::GetNpcTypeGroup() const
{
    switch (GetNpcType())
    {
    case 0x50:
        return 11;
    case 0x51:
        return 13;
    case 0x52:
    case 0x55:
        return 14;
    case 0x54:
        return 15;
    case 4:
        return 10;
    case 0x1f5:
        return 16;
    case 0x57:
        return 2;
    default:
        return 3;
    }
}

// @0x1406cd200
bool CNpcData::HasPropertyTag(int nTag) const
{
    if (nTag >= 31)
        return false;
    return m_propertyTags.test(nTag);
}

// @0x1406cd240
bool CNpcData::IsRace(int nRace) const
{
    return m_nRace == nRace;
}

// @0x1406cd280
bool CNpcData::HasEventTag(int nTag) const
{
    if (nTag >= 6)
        return false;
    return m_eventTags.test(nTag);
}

// @0x1406cd2c0
bool CNpcData::HasSkill() const
{
    return m_skill.m_aIds.size() > 0;
}

// @0x1406cd310
int CNpcData::GetRace() const
{
    return m_nRace;
}

// --- Table/NpcRegionSpawnData.xml and the NpcData xml cache ---------------------------------------------------------

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_1402804e0(void*, unsigned __int64, unsigned __int64, int, const wchar_t*);
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
int FUN_1408731e0(Unk_140165cf0*, const char*, int&);
int FUN_1408733e0(Unk_140165cf0*, const char*, CString&);
int FUN_140873420(Unk_140165cf0*, const char*, CStringW&);
CStringW FUN_1401bf530(Unk_140165cf0* pElem, const char* pszName, CStringW strDefault);
void FUN_14025a680(CStringW& src, ATL::CAtlArray<CStringW>& out, const wchar_t* pszSep);
bool FUN_14025cd60(const CStringW&, const CStringW&);
void FUN_1403992a0(CString pattern, CString directory, std::vector<CString>& output, CString exclude, bool localOnly);
void* FUN_140166410();
bool FUN_14036d4b0(void*, const CStringW&);
CString FUN_14036d8e0(void*);
bool FUN_1401647e0(const CString&, const CString&);
float FUN_14028d2e0();
CStringW FUN_140298ea0(CStringW strKey);
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);

// The weight table of the black market's rarity roll, reused for the region spawn weights (0x143aac4c8).
class Unk_NpcWeightMgr { public: int FUN_1406762d0(int nMain, int nSub, int nRare, int nDiff); };
Unk_NpcWeightMgr* FUN_1401c0db0();

class Unk_NpcTableCli { public: MS2Ptr<CNpcData> FUN_140a7cab0(int nNpcId); };
static Unk_NpcTableCli* s_pNpcTable;

// How often a query's main / sub tags hit one region spawn row.
struct Unk_RegionTagHit
{
    int m_nMain;
    int m_nSub;
};

// @0x1406c8680
CNpcRegionSpawnData::CNpcRegionSpawnData()
    : m_nNpcId(0), m_nMaxSpawnCount(0), m_nGroupSpawnCount(0), m_nRareDegree(0), m_nDifficulty(0)
{
}

// @0x1406d5570
CNpcRegionSpawnData::~CNpcRegionSpawnData()
{
}

// @0x1406d4fe0
CRegionSpawnProb::CRegionSpawnProb()
{
    m_pSpawn = 0;
    m_fRate = 0.0f;
    m_fWeight = 0.0f;
}

// @0x1406d5620
CRegionSpawnProb::~CRegionSpawnProb()
{
}

// @0x1406d5060
CRegionSpawnResult::CRegionSpawnResult() : m_nMaxDifficulty(0), m_nMinDifficulty(0), m_nUnused(0)
{
}

// @0x1406d5650
CRegionSpawnResult::~CRegionSpawnResult()
{
    m_aProb.RemoveAll();
}

// @0x1406c8730
MS2Ptr<CRegionSpawnProb> CRegionSpawnResult::Pick() const
{
    if (m_aProb.IsEmpty())
        return MS2Ptr<CRegionSpawnProb>(0);
    if (m_aProb.GetCount() == 1)
        return m_aProb[0];
    float fRoll = FUN_14028d2e0();
    float fSum = 0.0f;
    for (int i = 0; i < (int)m_aProb.GetCount(); i++)
    {
        if (fSum <= fRoll && fRoll <= fSum + m_aProb[i]->m_fRate)
            return m_aProb[i];
        fSum += m_aProb[i]->m_fRate;
    }
    return m_aProb[m_aProb.GetCount() - 1];
}

// @0x1406cd330
// MS2-FUNCTIONAL: the exe moves the looked-up pointer into the result (MS2Ptr has no move constructor here)
MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId)
{
    if (nNpcId == 0)
        return MS2Ptr<CNpcData>(0);
    return s_pNpcTable->FUN_140a7cab0(nNpcId);
}

// @0x1406d6e90
Unk_NpcTableCli* FUN_1406d6e90()
{
    return s_pNpcTable;
}

// @0x1406cd420
CStringW FUN_1406cd420(int nNpcType)
{
    if (nNpcType == 2)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_bank"));
    if (nNpcType >= 11 && nNpcType <= 29)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_shop"));
    if (nNpcType >= 31 && nNpcType <= 39)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_beautyshop"));
    if (nNpcType == 0x50)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_job"));
    if (nNpcType == 0x51)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_doctor"));
    if (nNpcType == 0x52)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_transfer"));
    if (nNpcType == 0x57)
        return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_enchant"));
    return FUN_140298ea0(CStringW(L"s_gamedictionary_npc_type_normal"));
}

// @0x1406cd750
CNpcDataTable::CNpcDataTable()
{
    LoadNpcCache();
    LoadRegionSpawn();
}

// @0x1406cd840
MS2Ptr<CRegionSpawnResult> CNpcDataTable::FindSpawnResult(CStringW strTags, int nMinDifficulty, int nMaxDifficulty)
{
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        for (int i = 0; i < (int)m_aResult.GetCount(); i++)
        {
            MS2Ptr<CRegionSpawnResult> pResult = m_aResult[i];
            if (FUN_14025cd60(pResult->m_strTag, strTags) && pResult->m_nMaxDifficulty == nMaxDifficulty &&
                pResult->m_nMinDifficulty == nMinDifficulty)
                return pResult;
        }
    }

    ATL::CAtlArray<CStringW> aTags;
    FUN_14025a680(strTags, aTags, L",");
    for (int i = 0; i < (int)aTags.GetCount(); i++)
        aTags[i].Trim();

    ATL::CRBMap<unsigned, Unk_RegionTagHit> mapHit(10);
    for (int nGroup = 0; nGroup < 2; nGroup++)
    {
        for (int j = 0; j < (int)aTags.GetCount(); j++)
        {
            Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > pIds;
            {
                Unk_CriticalSectionLock lock(m_lock, 1);
                m_mapTag[nGroup].Lookup(aTags[j], pIds);
            }
            if (pIds.get() != 0)
            {
                for (int k = 0; k < (int)pIds->GetCount(); k++)
                {
                    unsigned nNpcId = (*pIds)[k];
                    MS2Ptr<CNpcRegionSpawnData> pData = GetRegionSpawnData(nNpcId);
                    if (!(pData == 0))
                    {
                        if (nMaxDifficulty < pData->m_nDifficulty)
                            continue;
                        if (pData->m_nDifficulty < nMinDifficulty)
                            continue;
                        ATL::CRBMap<unsigned, Unk_RegionTagHit>::CPair* pHit = mapHit.Lookup(nNpcId);
                        if (pHit == 0)
                        {
                            Unk_RegionTagHit hit;
                            hit.m_nMain = nGroup == 0;
                            hit.m_nSub = nGroup != 0;
                            mapHit.SetAt(nNpcId, hit);
                        }
                        else if (nGroup == 0)
                            pHit->m_value.m_nMain++;
                        else
                            pHit->m_value.m_nSub++;
                    }
                }
            }
        }
    }

    MS2Ptr<CRegionSpawnResult> pResult(new CRegionSpawnResult);
    pResult->m_nMaxDifficulty = nMaxDifficulty;
    pResult->m_nMinDifficulty = nMinDifficulty;
    pResult->m_strTag = strTags;
    float fTotal = 0.0f;
    for (POSITION pos = mapHit.GetHeadPosition(); pos != 0; mapHit.GetNext(pos))
    {
        unsigned nNpcId = mapHit.GetKeyAt(pos);
        Unk_RegionTagHit hit = mapHit.GetValueAt(pos);
        MS2Ptr<CNpcRegionSpawnData> pData = GetRegionSpawnData(nNpcId);
        if (!(pData == 0))
        {
            if (hit.m_nMain == 0 && hit.m_nSub == 0)
                continue;
            if (hit.m_nMain == (int)pData->m_aTags[0].GetCount())
            {
                MS2Ptr<CRegionSpawnProb> pProb(new CRegionSpawnProb);
                pProb->m_pSpawn = pData;
                int nDiff = nMaxDifficulty - pData->m_nDifficulty;
                pProb->m_fWeight = (float)FUN_1401c0db0()->FUN_1406762d0(hit.m_nMain, hit.m_nSub, pData->m_nRareDegree, nDiff);
                fTotal += pProb->m_fWeight;
                pResult->m_aProb.Add(pProb);
            }
        }
    }
    for (int i = 0; i < (int)pResult->m_aProb.GetCount(); i++)
        pResult->m_aProb[i]->m_fRate = pResult->m_aProb[i]->m_fWeight / fTotal;
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        m_aResult.Add(pResult);
    }
    return pResult;
}

// @0x1406ce1d0
MS2Ptr<CNpcRegionSpawnData> CNpcDataTable::GetRegionSpawnData(int nNpcId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    MS2Ptr<CNpcRegionSpawnData> pData(0);
    m_mapSpawn.Lookup(nNpcId, pData);
    return pData;
}

// @0x1406ce280
void CNpcDataTable::IndexRegionSpawn(MS2Ptr<CNpcRegionSpawnData> pData)
{
    if (!(pData == 0))
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        for (int nGroup = 0; nGroup < 2; nGroup++)
        {
            for (int i = 0; i < (int)pData->m_aTags[nGroup].GetCount(); i++)
            {
                CStringW strTag = pData->m_aTags[nGroup][i];
                Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > pIds;
                if (!m_mapTag[nGroup].Lookup(strTag, pIds))
                {
                    pIds = Unk_BmNewTag(0);
                    m_mapTag[nGroup].SetAt(strTag, pIds);
                }
                pIds->Add(pData->m_nNpcId);
            }
        }
    }
}

// @0x1406ce4a0
void CNpcDataTable::LoadNpcCache()
{
    std::vector<CString> aFiles;
    FUN_140166420();
    FUN_1403992a0(CString(".xml"), CString("./Data/Xml/NpcData/"), aFiles, CString(""), false);
    for (std::vector<CString>::iterator it = aFiles.begin(); it != aFiles.end(); ++it)
    {
        int nNpcId = GetIdFromPath(*it);
        m_mapLoaded[nNpcId] = false;
        CCacheData* pCache = new CCacheData(CString(*it));
        m_mapCache[nNpcId].AssignRaw(pCache);
    }
}

// @0x1406ce6d0
void CNpcDataTable::LoadRegionSpawn()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("NpcRegionSpawnData.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
    {
        FUN_1402804e0(FUN_140166440(), 0, 0, 0xc, L"NpcDataTable.cpp:Init : File not found NpcRegionSpawnData.xml");
        return;
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("NpcRegionSpawnData"); pNode != 0;
         pNode = pNode->FUN_140168650("NpcRegionSpawnData"))
    {
        CStringW strFeature;
        CString strLocale;
        FUN_140873420(pNode, "feature", strFeature);
        FUN_1408733e0(pNode, "locale", strLocale);
        bool bSkip = !strLocale.IsEmpty() && FUN_1401647e0(strLocale, FUN_14036d8e0(FUN_140166410()));
        if (bSkip)
            continue;
        if (!FUN_14036d4b0(FUN_140166410(), strFeature))
            continue;
        MS2Ptr<CNpcRegionSpawnData> pData(new CNpcRegionSpawnData);
        pData->m_nNpcId = atoi(FUN_14086f4b0(pNode, "npcID"));
        CStringW strMain = FUN_1401bf530(pNode, "mainTags", CStringW(L""));
        FUN_14025a680(strMain, pData->m_aTags[0], L",");
        CStringW strSub = FUN_1401bf530(pNode, "subTags", CStringW(L""));
        FUN_14025a680(strSub, pData->m_aTags[1], L",");
        for (int nGroup = 0; nGroup < 2; nGroup++)
            for (int i = 0; i < (int)pData->m_aTags[nGroup].GetCount(); i++)
                pData->m_aTags[nGroup][i].Trim();
        FUN_1408731e0(pNode, "maxSpawnCount", pData->m_nMaxSpawnCount);
        FUN_1408731e0(pNode, "groupSpawnCount", pData->m_nGroupSpawnCount);
        FUN_1408731e0(pNode, "rareDegree", pData->m_nRareDegree);
        FUN_1408731e0(pNode, "difficulty", pData->m_nDifficulty);
        {
            Unk_CriticalSectionLock lock(m_lock, 1);
            m_mapSpawn.SetAt(pData->m_nNpcId, pData);
        }
        IndexRegionSpawn(pData);
    }
}

// @0x1406ced30
int CNpcDataTable::GetIdFromPath(const CStringA& strPath)
{
    char szName[256];
    _splitpath(strPath, 0, 0, szName, 0);
    return atoi(szName);
}

// @0x1406cedb0
bool CNpcDataTable::NeedsLoad(int nNpcId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<int, MS2Ptr<CCacheData> >::iterator it = m_mapCache.find(nNpcId);
    if (it == m_mapCache.end())
        return false;
    MS2Ptr<CCacheData> pCache = it->second;
    if (pCache == 0)
        return false;
    if (FUN_1401d1320(pCache.get()) != 0)
        return true;
    std::map<int, bool>::iterator itLoaded = m_mapLoaded.find(nNpcId);
    if (itLoaded == m_mapLoaded.end())
        return false;
    return itLoaded->second != true;
}
