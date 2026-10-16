// makeupcontroller.h - CMakeupController (RTTI .?AVCMakeupController@@, 0xe0 bytes): the customize controller of the
// face makeup slot (equip slot 3). It edits the four values of the "FA_Skin" face mesh's NiFloatsExtraData (0 = x,
// 1 = y, 2 = angle, 3 = scale), mirrors them into the item's proxy data and plays a "pop" scale animation
// (CScaleModifier) after a drag. Owning unit: ?\makeupcontroller.cpp (src/ms2/client/ms2/makeupcontroller.cpp,
// 0x1414762e0-0x141478090). Header name assumed. Member names are invented from their use. Replaces the size-only
// placeholder placeholder/cmakeupcontroller.h.
#pragma once
#include "itemcustomizecontroller_1.h"
#include "itempickinghelper.h"
#include "scalemodifier.h"
#include <NiSmartPointer.h>

class NiFloatsExtraData;

class CMakeupController : public CItemCustomizeController
{
public:
    CMakeupController();                                            // 0x1414762e0
    virtual ~CMakeupController();                                   // 0x1414763d0, ??_G 0x141477f70
    NiDeclareRTTI;                                                  // 2  GetRTTI 0x141477ff0
    virtual int vfunc_3();                                          // 3  0x141476430
    virtual void vfunc_4();                                         // 4  0x1414765f0
    virtual void vfunc_5();                                         // 5  0x141476650
    virtual void vfunc_6();                                         // 6  0x141476680
    virtual void vfunc_9(int nIndex);                               // 9  0x141476c40 preset
    virtual void vfunc_10(float fDegrees);                          // 10 0x141476bf0
    virtual void vfunc_13(MS2Ptr<CEquipItem> spOld);                // 13 0x141476b60
    virtual void vfunc_14(float fValue);                            // 14 0x141476870
    virtual void vfunc_16();                                        // 16 0x1414768d0 randomize
    virtual int vfunc_17();                                         // 17 0x141476850
    virtual float vfunc_18();                                       // 18 0x1414766b0
    virtual float vfunc_19();                                       // 19 0x141476790
    virtual float vfunc_20();                                       // 20 0x1414767c0
    virtual const Unk_CustomizeRange* vfunc_23();                   // 23 0x141476740
    virtual void vfunc_25(float* pfMin, float* pfMax);              // 25 0x1414767f0
    virtual void vfunc_28();                                        // 28 0x141476d50 picking mesh names
    virtual int vfunc_29();                                         // 29 0x141476d30
    virtual void vfunc_30(const NiPoint3& kPos);                    // 30 0x141476e20 drag (mode 1) begin
    virtual void vfunc_32(const NiPoint3& kHit, const NiPoint3& kNormal, const NiPoint2& kUV, float fValue);
                                                                    // 32 0x141476ec0 drag (mode 1) hit
    virtual void vfunc_33();                                        // 33 0x141476f40 drag (mode 1) end
    virtual void vfunc_34(const NiPoint3& kPos);                    // 34 0x141477590 drag (mode 2) begin
    virtual void vfunc_35();                                        // 35 0x141477640 drag (mode 2) update
    virtual void vfunc_36();                                        // 36 0x141477720 drag (mode 2) end
    virtual float vfunc_40();                                       // 40 0x141476e00
    virtual void vfunc_42(float fValue, NiFloatsExtraData* pExtra);                 // 42 0x141477080 (new slot) value
    virtual void vfunc_43(float fRadians, NiFloatsExtraData* pExtra);               // 43 0x141477260 (new slot) angle
    virtual void vfunc_44(float fX, float fY, NiFloatsExtraData* pExtra);           // 44 0x1414773d0 (new slot) x / y

    // non-virtual (names invented)
    void SetPreviewApply(bool bOn);                                 // 0x141477730
    void SaveToProxy();                                             // 0x141477780
    void LoadFromProxy();                                           // 0x141477960
    void UpdateScaleAnimation();                                    // 0x141477b20
    void FindFaceMesh();                                            // 0x141477bd0

    float m_fWheelStep;                                             // +0xb8 wheel step (client config +0x2de8)
    float m_fDragScale;                                             // +0xbc degrees per pixel of the drag (config +0x2e40)
    float m_fDragStartX;                                            // +0xc0 cursor x at the start of drag mode 2
    float m_fDragStartAngle;                                        // +0xc4 angle (degrees) at the start of drag mode 2
    Unk_PickMeshPtr m_spFaceMesh;                                   // +0xc8 the "FA_Skin" face mesh
    NiPointer<CScaleModifier> m_spScale;                            // +0xd0
    int m_nPresetIndex;                                             // +0xd8 -1 = none
};
MS2_CHECK_SIZE(CMakeupController, 0xe0);
MS2_CHECK_OFFSET(CMakeupController, m_fWheelStep, 0xb8);
MS2_CHECK_OFFSET(CMakeupController, m_spFaceMesh, 0xc8);
MS2_CHECK_OFFSET(CMakeupController, m_spScale, 0xd0);
MS2_CHECK_OFFSET(CMakeupController, m_nPresetIndex, 0xd8);
