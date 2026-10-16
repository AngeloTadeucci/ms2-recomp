// scalemodifier.h - CScaleModifier (RTTI .?AVCScaleModifier@@, base NiRefObject): a time-based "pop" scale animation
// (grows to m_fMaxScale and back over m_fDuration seconds). Header name assumed; member names invented from use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"

// 0x30 bytes, vftable 0x142f5c228 (deleting dtor, NiRefObject::DeleteThis).
class CScaleModifier : public NiRefObject
{
public:
    CScaleModifier();                   // 0x14170b530
    virtual ~CScaleModifier();          // 0x14170b5e0

    bool Update();                      // 0x14170b610: false once finished and already reset
    void Start(float fBaseScale);       // 0x14170b7a0
    // inline COMDATs first emitted by ?\makeupcontroller.cpp (names invented)
    float GetOriginalScale() const { return m_fBaseScale; }                 // 0x141477fe0
    float GetCurrentScale() const { return m_fScale; }                         // 0x141477fd0
    bool IsRunning() const { return m_bActive; }                         // 0x141478010
    void SetDuration(float fDuration) { m_fDuration = fDuration; }      // 0x141478020
    void SetMaxScale(float fMaxScale) { m_fMaxScale = fMaxScale; }      // 0x141478040

    float m_fBaseScale;                 // +0x10
    float m_fScale;                     // +0x14 current output
    float m_fDuration;                  // +0x18 seconds
    float m_fMaxScale;                  // +0x1c peak factor
    double m_dStartTime;                // +0x20
    bool m_bActive;                     // +0x28
};
MS2_CHECK_SIZE(CScaleModifier, 0x30);
MS2_CHECK_OFFSET(CScaleModifier, m_dStartTime, 0x20);
MS2_CHECK_OFFSET(CScaleModifier, m_bActive, 0x28);
