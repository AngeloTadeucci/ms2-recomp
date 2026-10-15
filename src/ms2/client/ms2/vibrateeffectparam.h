// vibrateeffectparam.h - CVibrateEffectParam and CVibrateEffect: vibration effect (effect XML type 0x??).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\vibrateeffectparam.cpp
// MS2-RANGE: 0x141b72630-0x141b72f60 .text$mn
#pragma once

#include "ms2/client/ms2/effectparam.h"
#include "ms2/ms2layout.h"

// 0x70 bytes. vftable at 0x142ff4050, 8 slots.
class CVibrateEffectParam : public CEffectParam
{
public:
    CVibrateEffectParam();                      // 0x141b72630
    virtual ~CVibrateEffectParam();             // scalar_deleting_destructor 0x141b72f00

    virtual void vfunc_1(Unk_140165cf0* pNode);    // 0x141b72690
    virtual bool vfunc_2();                        // 0x141b72730
    // vfunc_3, vfunc_4, vfunc_5 inherited from CEffectParam
    virtual CEffectPtr vfunc_6();                  // 0x141b727b0 creates CVibrateEffect
    virtual bool vfunc_7(Unk_EffectTarget* p);     // 0x141b72850

    // Getters for effect parameters
    float GetMagnitude() const;         // 0x141b728a0
    float GetFrequency() const;         // 0x141b728e0

    // Unknown methods
    void FUN_141b72e00();               // 0x141b72e00
    void FUN_141b72e70();               // 0x141b72e70
    void FUN_141b72e80();               // 0x141b72e80
    void FUN_141b72ea0();               // 0x141b72ea0
    void FUN_141b72f40();               // 0x141b72f40
    void FUN_141b72f50();               // 0x141b72f50

    // Additional members beyond CEffectParam (0x48 bytes)
    float m_fMagnitude;                 // +0x48
    float m_fFrequency;                 // +0x4c
    void* m_pad_50;                     // +0x50
    void* m_pad_58;                     // +0x58
    void* m_pad_60;                     // +0x60
    void* m_pad_68;                     // +0x68
};
MS2_CHECK_SIZE(CVibrateEffectParam, 0x70);
MS2_CHECK_OFFSET(CVibrateEffectParam, m_fMagnitude, 0x48);
MS2_CHECK_OFFSET(CVibrateEffectParam, m_fFrequency, 0x4c);

// 0x38 bytes. Runtime vibrate effect.
class CVibrateEffect : public CEffect
{
public:
    CVibrateEffect();                   // 0x141b72910
    virtual ~CVibrateEffect();          // 0x141b72bd0

    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);  // 0x141b72e00
    virtual int vfunc_12();             // 0x141b72f40 return type indicator

    float m_fMagnitude;                 // +0x30
    float m_fFrequency;                 // +0x34
};
MS2_CHECK_SIZE(CVibrateEffect, 0x38);
MS2_CHECK_OFFSET(CVibrateEffect, m_fMagnitude, 0x30);
MS2_CHECK_OFFSET(CVibrateEffect, m_fFrequency, 0x34);
