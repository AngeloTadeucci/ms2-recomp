// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See vibrateeffectparam.h.
// MS2-UNIT: ?\vibrateeffectparam.cpp
// MS2-RANGE: 0x141b72630-0x141b72f60 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\vibrateeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "vibrateeffectparam.h"

#include <efd/MemoryDefines.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- Helper placeholders ----
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);
};

// @0x141b72630
CVibrateEffectParam::CVibrateEffectParam()
    : CEffectParam(0), m_fMagnitude(0.0f), m_fFrequency(0.0f)
{
}

// @0x141b72690
void CVibrateEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    // Parse XML for magnitude and frequency
}
MS2_REPLACE_METHOD(0x141b72690, CVibrateEffectParam, vfunc_1, 150, 0);

// @0x141b72730
bool CVibrateEffectParam::vfunc_2()
{
    return CEffectParam::vfunc_2();
}
MS2_REPLACE_METHOD(0x141b72730, CVibrateEffectParam, vfunc_2, 117, 0);

// @0x141b727b0
CEffectPtr CVibrateEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CVibrateEffect;
}

// @0x141b72850
bool CVibrateEffectParam::vfunc_7(Unk_EffectTarget* p)
{
    return CEffectParam::vfunc_7(p);
}
MS2_REPLACE_METHOD(0x141b72850, CVibrateEffectParam, vfunc_7, 62, 0);

// @0x141b728a0
float CVibrateEffectParam::GetMagnitude() const
{
    return m_fMagnitude;
}

// @0x141b728e0
float CVibrateEffectParam::GetFrequency() const
{
    return m_fFrequency;
}

// @0x141b72910
CVibrateEffect::CVibrateEffect()
    : m_fMagnitude(0.0f), m_fFrequency(0.0f)
{
}

// @0x141b72bd0
CVibrateEffect::~CVibrateEffect()
{
}

// @0x141b72e00
bool CVibrateEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CVibrateEffectParam* pVibrate = static_cast<const CVibrateEffectParam*>(pParam);
    m_fMagnitude = pVibrate->m_fMagnitude;
    m_fFrequency = pVibrate->m_fFrequency;
    return true;
}
MS2_REPLACE_METHOD(0x141b72e00, CVibrateEffect, vfunc_3, 95, 0);

// @0x141b72e70
void CVibrateEffectParam::FUN_141b72e70()
{
}

// @0x141b72e80
void CVibrateEffectParam::FUN_141b72e80()
{
}

// @0x141b72ea0
void CVibrateEffectParam::FUN_141b72ea0()
{
}

// @0x141b72f00
// scalar_deleting_destructor at 0x141b72f00

// @0x141b72f40
int CVibrateEffect::vfunc_12()
{
    return 0;
}

// @0x141b72f50
void FUN_141b72f50()
{
}
