// skillrecord.cpp - the skill cast records (SkillTargetRecord, CSkillRecord, the damage records).
// MS2-UNIT: ?\skillrecord.cpp
// MS2-RANGE: 0x141758d70-0x14175c840 .text$mn
//
// Not written yet (blocked): the motion/attack readers of CSkillRecord (0x141759830..0x14175a210), the attack readers
// of CDamageRecord (0x14175a850..0x14175ab80, 0x14175ac30..0x14175ae80) and the two vfunc_1 bodies. They read
// SkillMotionData / SkillAttackData fields that commonfiles/skilloverlapcompare.h does not name yet.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\skillrecord.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "skillrecord.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/magicdata.h"

// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

extern Unk_StreamPoint DAT_143b01a60;                       // the zero point
SkillDataTable* FUN_1401958b0();                            // the skill table
unsigned FUN_141472bc0();                                   // the tick count

// The own field world (only the time mode of a field object is read).
class Unk_SrWorld
{
public:
    int FUN_141bd19d0(int nObjectId);
};
Unk_SrWorld* FUN_1403ed2d0();

// ---- SkillTargetRecord ----

// @0x141758d70
bool SkillTargetRecord::FUN_141758d70(unsigned long long nTagId, unsigned long long nTagSub, int nOwnerId,
    int nCasterId, int nSkillId, short nLevel, int nMotion, const Unk_StreamPoint& ptDir, int n80, int n84,
    int nAttack, int n8c)
{
    m_spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    if (m_spSkill == 0)
        return false;
    m_spLevel = m_spSkill->FUN_1407e90a0(nLevel);
    if (m_spLevel == 0)
        return false;
    m_spLinked = 0;
    m_n80 = n80;
    m_nTagId = nTagId;
    m_nTagSub = nTagSub;
    m_nOwnerId = nOwnerId;
    m_nTimeMode = FUN_1403ed2d0()->FUN_141bd19d0(m_nOwnerId);
    m_nCasterId = nCasterId;
    m_n84 = n84;
    m_nMotion = nMotion;
    m_ptDir = ptDir;
    m_nStartTick = 0;
    m_nAttack = nAttack;
    m_n8c = n8c;
    return true;
}

// @0x141759010
SkillMotionData* SkillTargetRecord::FUN_141759010()
{
    return m_spLevel->FUN_140803f00(m_nMotion);
}

// @0x141759050
SkillAttackData* SkillTargetRecord::FUN_141759050()
{
    return m_spLevel->FUN_140803f60(m_nMotion, m_nAttack);
}

// @0x141759090
int SkillTargetRecord::FUN_141759090()
{
    return m_spLevel->FUN_1408043f0(m_nMotion, m_nAttack);
}

// @0x141758fb0
unsigned SkillTargetRecord::FUN_141758fb0()
{
    return m_spSkill->GetId();
}

// @0x141758fe0
unsigned short SkillTargetRecord::FUN_141758fe0()
{
    return m_spLevel->FUN_140803df0();
}

// @0x141759190
int SkillTargetRecord::FUN_141759190()
{
    return m_nStartTick;
}

// ---- CSkillRecord ----

// @0x141759260
CSkillRecord::CSkillRecord()
    : m_nTick(0), m_nSendTick(0), m_nSendCount(0), m_nCastId(0), m_ptPos(DAT_143b01a60), m_ptDir(DAT_143b01a60),
      m_ptRot(DAT_143b01a60), m_fCooldown(0), m_fDuration(0), m_fElapsed(0), m_f80(0), m_n84(0), m_n88(0), m_nMotion(0),
      m_nAttack(0), m_nAttackIndex(0), m_n98(0), m_n9c(0), m_nA0(0), m_nA4(0), m_nA8(0), m_bAC(false), m_bAD(true), m_bAE(false), m_nB0(0), m_bEnd(false), m_n1b8(0)
{
}

// @0x141759520
CSkillRecord::~CSkillRecord()
{
}

// @0x1417595d0
bool CSkillRecord::Init(Unk_InventorySkillRequest& kReq)
{
    m_spSkill = FUN_1401958b0()->GetSkillData(kReq.m_nSkillId);
    if (m_spSkill == 0)
        return false;
    m_spLevel = m_spSkill->FUN_1407e90a0(kReq.m_nLevel);
    if (m_spLevel == 0)
        return false;
    m_nTick = kReq.m_nTick;
    m_nSendTick = kReq.m_nTick;
    m_nCastId = kReq.m_nCastId;
    m_nMotion = kReq.m_nMotion;
    m_ptPos = kReq.m_ptPos;
    m_ptDir = kReq.m_ptDir;
    m_ptRot = Unk_StreamPoint(0, 0, kReq.m_fRotZ);
    m_bAE = kReq.m_b3a;
    m_bAD = kReq.m_b38;
    m_nA4 = kReq.m_n34;
    m_n1b8 = kReq.m_n40;
    return true;
}

// @0x141759830
SkillMotionData* CSkillRecord::FUN_141759830()
{
    return m_spLevel ? m_spLevel->FUN_140803f00(m_nMotion) : 0;
}

// @0x141759960
unsigned CSkillRecord::GetSkillId()
{
    return m_spSkill->GetId();
}

// @0x141759990
unsigned short CSkillRecord::GetLevel()
{
    return m_spLevel->FUN_140803df0();
}

// @0x1417599c0
__int64 CSkillRecord::FUN_1417599c0()
{
    return m_n1b8;
}

// @0x141759fc0
void CSkillRecord::FUN_141759fc0()
{
    m_nAttack = 1;
}

// @0x141759fe0
void CSkillRecord::FUN_141759fe0()
{
    m_bEnd = true;
}

// @0x14175a280
void CSkillRecord::AddTarget(int nKey, unsigned nTarget)
{
    TargetSetPtr spTargets;
    if (m_targets.Lookup(nKey, spTargets)) {
        spTargets->insert(nTarget);
    }
    else {
        spTargets = Unk_CubeNewTag(0);
        spTargets->insert(nTarget);
        m_targets.SetAt(nKey, spTargets);
    }
}

// @0x14175a360
int CSkillRecord::HasTarget(int nKey, unsigned nTarget)
{
    TargetSetPtr spTargets;
    if (m_targets.Lookup(nKey, spTargets))
        return spTargets->find(nTarget) != spTargets->end();
    return 0;
}

// @0x14175a430
void CSkillRecord::FUN_14175a430()
{
    m_nSendTick = FUN_141472bc0();
    COutPacket packet(0x20);
    packet.Encode1(3);
    packet.Encode8(m_nCastId);
    packet.Encode4(m_nSendTick);
    FUN_140710590(packet);
    m_nSendCount++;
    m_targets.RemoveAll();
}

// ---- CDamageRecord ----

// @0x14175a4e0
CDamageRecord::CDamageRecord()
{
    m_nTagId = 0;
    m_nTagSub = 0;
    m_nD0 = 0;
    m_pt78 = DAT_143b01a60;
    m_ptHit = DAT_143b01a60;
}

// @0x14175a610
int CDamageRecord::Init(unsigned long long nTagId, unsigned long long nTagSub, int nOwnerId, int nCasterId,
    int nSkillId, short nLevel, int nMotion, int nAttack, const Unk_StreamPoint& ptPos,
    const Unk_StreamPoint& ptDir, const Unk_StreamPoint& ptHit)
{
    m_nTagId = nTagId;
    m_nTagSub = nTagSub;
    m_nOwnerId = nOwnerId;
    m_nCasterId = nCasterId;
    m_nSkillId = nSkillId;
    m_nLevel = nLevel;
    m_spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    m_spLevel = m_spSkill->FUN_1407e90a0(nLevel);
    m_nMotion = nMotion;
    m_nAttack = nAttack;
    m_ptPos = ptPos;
    m_ptDir = ptDir;
    m_ptHit = ptHit;
    if (!m_spSkill || !m_spLevel)
        return 0;
    return 1;
}

// @0x14175a820
SkillData* CDamageRecord::FUN_14175a820()
{
    return m_spSkill.get();
}

// @0x14175a850
SkillMotionData* CDamageRecord::FUN_14175a850()
{
    return m_spLevel ? m_spLevel->FUN_140803f00(m_nMotion) : 0;
}

// @0x14175a8b0
SkillAttackData* CDamageRecord::FUN_14175a8b0()
{
    return m_spLevel ? m_spLevel->FUN_140803f60(m_nMotion, m_nAttack) : 0;
}

// @0x14175abc0
void CDamageRecord::FUN_14175abc0(int nType, __int64 nDamage)
{
    if (nType == 8) {
        m_nD0 = 8;
        nType = 3;
    }
    m_types.Add(nType);
    m_damages.Add(nDamage);
}

// @0x14175ac30
__int64 CDamageRecord::FUN_14175ac30()
{
    __int64 nTotal = 0;
    for (unsigned i = 0; i < m_damages.GetCount(); i++)
        nTotal += m_damages[i];
    return nTotal;
}

// @0x14175acc0
int CDamageRecord::FUN_14175acc0()
{
    return (static_cast<bool>(m_spLevel) && m_spLevel->FUN_1408043f0(m_nMotion, m_nAttack) != 0) ? 1 : 0;
}

// @0x14175aeb0
unsigned __int64 CDamageRecord::FUN_14175aeb0()
{
    return m_damages.GetCount();
}

// @0x14175aee0
int CDamageRecord::FUN_14175aee0(int nIndex, int& nType)
{
    if ((int)m_types.GetCount() <= nIndex)
        return 0;
    nType = m_types[nIndex];
    return 1;
}

// ---- CDotDamageRecord ----

// @0x14175af90
CDotDamageRecord::CDotDamageRecord()
{
    m_nOwnerId = 0;
    m_nCasterId = 0;
    m_nEffectLevel = 0;
}

// @0x14175aff0
int CDotDamageRecord::Init(int nOwnerId, int nCasterId, int nEffectLevel, int nType, __int64 nDamage)
{
    m_nOwnerId = nOwnerId;
    m_nCasterId = nCasterId;
    m_nEffectLevel = nEffectLevel;
    m_damages.Add(nDamage);
    m_types.Add(nType);
    return 1;
}

// @0x14175b130
int CDotDamageRecord::FUN_14175b130()
{
    if (m_types.IsEmpty())
        return 0;
    return m_types[0];
}

// ---- CSplashDamageRecord ----

// @0x14175b180
CSplashDamageRecord::CSplashDamageRecord()
{
}

// @0x14175b1c0
int CSplashDamageRecord::Init(int nCasterId, int nOwnerId, unsigned long long nTagId, int nSkillId, short nLevel,
    int nMotion, int nAttack, const Unk_StreamPoint& ptPos, const Unk_StreamPoint& ptDir)
{
    m_nCasterId = nCasterId;
    m_nOwnerId = nOwnerId;
    m_nTagId = nTagId;
    m_nSkillId = nSkillId;
    m_nLevel = nLevel;
    m_spSkill = FUN_1401958b0()->GetSkillData(nSkillId);
    m_spLevel = m_spSkill->FUN_1407e90a0(nLevel);
    m_nMotion = nMotion;
    m_nAttack = nAttack;
    m_ptPos = ptPos;
    m_ptDir = ptDir;
    if (!m_spSkill || !m_spLevel)
        return 0;
    return 1;
}
