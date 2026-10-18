// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateFallDamage, the actor state after taking fall damage:
// plays the hurt animation and returns to idle when it ends. See statefalldamage.h.
// MS2-UNIT: ?\statefalldamage.cpp
// MS2-RANGE: 0x1417c7be0-0x1417c8240 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statefalldamage.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>

#include "statefalldamage.h"

#include "ms2/client/ms2/statefall.h"               // the shared animation-prefix callees
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The actor's buff set: the fall-damage knock-back direction.
class Unk_FallDmgBuff { public: efd::Point3 FUN_1416836d0(); };

// @0x1417c7be0
StateFallDamage::StateFallDamage(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417c7c50
StateFallDamage::~StateFallDamage()
{
}

// @0x1417c7c90
// MS2-FUNCTIONAL: frame / temporaries differ from the exe
void StateFallDamage::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_strAnim = m_pOwner->vfunc_123(0x3f);
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        CString strRec;
        bool bHasRec = !FUN_1416561a0(pPC)->FUN_1411eabd0().IsEmpty();
        if (bHasRec)
            strRec = FUN_1416561a0(pPC)->FUN_1411eabd0();
        if (!strRec.IsEmpty())
        {
            efd::utf8string kAnim((const char*)FUN_14038f6d0(strRec, m_strAnim.c_str()));
            int nSeq = FUN_141b6f910()->FUN_140999490(m_pOwner->FUN_14123c460(), kAnim);
            if (nSeq != -2)
                m_strAnim = kAnim;
        }
    }
    m_pOwner->FUN_14166dd20(m_strAnim, m_pOwner->FUN_1416713c0(), false, false);
}

// @0x1417c7f30
// MS2-FUNCTIONAL: the entity key temporary differs from the exe
void StateFallDamage::vfunc_5(int n)
{
    egf::EntityID kKey = m_pOwner->FUN_14123c460();
    FUN_141b6f910()->FUN_1409fad80(kKey, false);
    m_strAnim = "";
    State::vfunc_5(n);
}

// @0x1417c7fb0
void StateFallDamage::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    efd::Point3 kMove = efd::Point3::ZERO;
    m_pOwner->vfunc_68(&kMove, fTime, 0, 0, 0);
}

// @0x1417c8030
// MS2-FUNCTIONAL: the knock-back copy sequence differs from the exe
void StateFallDamage::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    if (m_pOwner->vfunc_63() != 0)
    {
        Unk_FallDmgBuff* pBuff = (Unk_FallDmgBuff*)m_pOwner->FUN_14166d240();
        efd::Point3 kTmp = pBuff->FUN_1416836d0();
        efd::Point3 kDir = kTmp;
        m_pOwner->vfunc_22(kDir);
        if (!m_pOwner->FUN_1416749c0())
            FUN_1417b9460();
        else
            m_pOwner->vfunc_59(2, 0, 0, 0);
    }
}

// @0x1417c8150
void StateFallDamage::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_pOwner->FUN_14166de90(0x3f, eSequenceID))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417c81c0
void StateFallDamage::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
}

// @0x1417c8230
int StateFallDamage::vfunc_1()
{
    return 0x1f;
}
