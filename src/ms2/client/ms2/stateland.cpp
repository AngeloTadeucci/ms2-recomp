// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateLand, the actor state of a player landing after a
// fall or jump: snaps the standing-on entity with a ray cast, plays the landing animation, leaves for idle. See
// stateland.h.
// MS2-UNIT: ?\stateland.cpp
// MS2-RANGE: 0x1417d9c70-0x1417da7a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateland.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "stateland.h"

#include "ms2/client/ms2/statefall.h"               // the animation service view (Unk_FallAnimSvc)
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The ray cast request / result (0x68).
struct Unk_LandRay
{
    Unk_LandRay();                                          // 0x140ad4440
    efd::Point3 m_origin;                                   // +0x00
    efd::Point3 m_dir;                                      // +0x0c
    float m_maxDist;                                        // +0x18
    int m_groups;                                           // +0x1c
    void* m_20;
    void* m_28;
    egf::Entity* m_hitEntity;                               // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                        // +0x48
    efd::Point3 m_hitPoint;                                 // +0x4c
    efd::Point3 m_hitNormal;                                // +0x58
    int m_pad_64;
};
MS2_CHECK_SIZE(Unk_LandRay, 0x68);
class Unk_LandPhysX
{
public:
    int FUN_14168a310(const efd::Point3& kFrom, efd::Point3* pHit, Unk_LandRay* pInfo, float fMaxDist, efd::Point3* pNormal, int nMask);
};
Unk_LandPhysX* FUN_1409f7ca0();

// The body's hit report: the entity the actor stands on.
class Unk_LandHitReport
{
public:
    egf::EntityID FUN_140cfaf70();                          // id of the entity stood on
    void FUN_140cfb020(egf::Entity* pEntity);               // set the entity stood on
};
class Unk_LandBody { public: Unk_LandHitReport* FUN_141240f20(); };
const egf::EntityID* FUN_1408b76f0(egf::Entity* pEntity);

// The actor's buff set.
class Unk_LandBuff
{
public:
    efd::Point3 FUN_141683290();                            // knock-back direction
    bool FUN_141682fe0(int nBuff);
};
// The land sound service.
class Unk_LandSound { public: void FUN_141377420(PCBase* pOwner, CString strKey); };
Unk_LandSound* FUN_141475cf0();

// Cube craft selection of the owner (gates the "cube landing" animation).
class Unk_LandCube { public: bool FUN_1410aa010(); };
Unk_LandCube* FUN_141659700(PCBase* p);
int FUN_1416595d0(PCBase* p);

CString FUN_1409a2360(const char* psz, int n);                              // text conversion

// @0x1417d9c70
StateLand::StateLand(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417d9ce0
StateLand::~StateLand()
{
}

// @0x1417d9d20
// MS2-FUNCTIONAL: first draft
void StateLand::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_spLand.AssignRaw(dynamic_cast<StateLandData*>(pData));
    if (m_pOwner->FUN_141676b70() == 0)
        m_n10 = 0x86;
    else
        m_n10 = 0x87;
    PCBase* pPC = FUN_1417b8370();
    Unk_LandRay kRay;
    efd::Point3 kFrom = m_pOwner->vfunc_18() + efd::Point3(0.0f, 0.0f, 30.0f);
    efd::Point3 kHit = efd::Point3::ZERO;
    efd::Point3 kNormal = efd::Point3::ZERO;
    int nHit = FUN_1409f7ca0()->FUN_14168a310(kFrom, &kHit, &kRay, 50.0f, &kNormal, 0);
    if (nHit != 0 && pPC != 0 && kRay.m_hitEntity != 0)
    {
        Unk_LandHitReport* pReport = ((Unk_LandBody*)pPC->FUN_14166d220())->FUN_141240f20();
        if (*FUN_1408b76f0(kRay.m_hitEntity) != pReport->FUN_140cfaf70())
            pReport->FUN_140cfb020(kRay.m_hitEntity);
    }
    m_pOwner->vfunc_93(true);
    FUN_141475cf0()->FUN_141377420(m_pOwner, CString("land"));
    MyPC* pMyPC = FUN_1417b84b0();
    if (pMyPC != 0)
        pMyPC->FUN_14152dbc0();
    if (m_pOwner->FUN_141675ed0() != 0)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417da070
// MS2-FUNCTIONAL: the zero point is copied byte-wise in the exe
void StateLand::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    efd::Point3 kMove = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417da0f0
// MS2-FUNCTIONAL: the knock-back copy sequence differs from the exe
void StateLand::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    Unk_LandBuff* pBuff = (Unk_LandBuff*)m_pOwner->FUN_14166d240();
    efd::Point3 kTmp = pBuff->FUN_141683290();
    efd::Point3 kDir = kTmp;
    m_pOwner->vfunc_22(kDir);
    if (!m_pOwner->FUN_1416749c0())
    {
        if (m_pOwner->FUN_141671a30() != 0 && pBuff->FUN_141682fe0(0x493e1))
        {
            m_pOwner->vfunc_59(6, 0, 0x25, 0);
            return;
        }
        if (m_pOwner->FUN_141675ed0() == 0)
            FUN_1417b9460();
        else
            m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        m_pOwner->vfunc_59(2, 0, 0, 0);
    }
}

// @0x1417da290
// MS2-FUNCTIONAL: the goto-shaped name selection is written as a flag
void StateLand::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    efd::utf8string strAnim;
    bool bNamed = false;
    bool bHasData = m_spLand.get() != 0;
    if (bHasData)
    {
        if (!m_spLand->m_str.IsEmpty())
        {
            strAnim = (const char*)FUN_1409a2360((const char*)m_spLand->m_str, 0);
            bNamed = true;
        }
    }
    if (!bNamed)
    {
        if (m_n10 == 0x86)
        {
            PCBase* pPC = FUN_1417b8370();
            if (pPC != 0 && FUN_1416595d0(pPC) != 0 && FUN_141659700(pPC)->FUN_1410aa010())
            {
                strAnim = pPC->vfunc_123(0x3c);
            }
            else
            {
                strAnim = m_pOwner->vfunc_123(3);
            }
        }
        else if (m_n10 == 0x87)
        {
            strAnim = m_pOwner->vfunc_123(0x48);
        }
    }
    int nSeq = -2;
    nSeq = FUN_141b6f910()->FUN_140999490(m_pOwner->FUN_14123c460(), strAnim);
    if (nSeq == -2)
        m_pOwner->vfunc_59(1, 0, 0, 0);
    else
        m_pOwner->FUN_14166dd20(strAnim, 1.0f, false, false);
}

// @0x1417da580
// MS2-FUNCTIONAL: the exe nests the animation tests instead of chaining them
void StateLand::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    bool bDone = false;
    bool bHasData = m_spLand.get() != 0;
    if (bHasData && !m_spLand->m_str.IsEmpty())
    {
        bDone = true;
    }
    else if (m_pOwner->FUN_14166de90(3, eSequenceID))
    {
        bDone = true;
    }
    else if (m_pOwner->FUN_14166de90(0x3c, eSequenceID))
    {
        bDone = true;
    }
    else if (m_pOwner->FUN_14166de90(0x48, eSequenceID))
    {
        bDone = true;
    }
    if (bDone)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417da780
int StateLand::vfunc_15()
{
    return 1;
}

// @0x1417da790
int StateLand::vfunc_1()
{
    return 4;
}
