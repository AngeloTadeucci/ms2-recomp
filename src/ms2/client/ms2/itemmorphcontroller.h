// itemmorphcontroller.h - CItemMorphController (RTTI .?AVCItemMorphController@@, 0xc0 bytes): the customize
// controller of the face/hair morph sliders (equip slot 1 = hair "HR:0/HR0:0/HR1:1", otherwise the "Editable Mesh" /
// "Editable Poly" face meshes). It drives the NiInterpController of the picked mesh. Owning unit:
// ?\itemcustomizecontroller.cpp#3 (src/ms2/client/ms2/itemcustomizecontroller_3.cpp, 0x141416de0-0x141418bf0).
// Header name assumed. Member names are invented from their use.
#pragma once
#include "itemcustomizecontroller_1.h"
#include <NiSmartPointer.h>
#include <efd/SmartPointer.h>

class NiAVObject;
class NiInterpController;
class NiFixedString;

class CItemMorphController : public CItemCustomizeController
{
public:
    CItemMorphController();                                         // 0x141416de0
    virtual ~CItemMorphController();                                // 0x141416e20, ??_G 0x141418a70
    NiDeclareRTTI;                                                  // 2  GetRTTI 0x141418ad0
    virtual int vfunc_3();                                          // 3  0x141416e50
    virtual void vfunc_4();                                         // 4  0x141416eb0
    virtual void vfunc_5();                                         // 5  0x141416f00 (empty)
    virtual void vfunc_6();                                         // 6  0x141416ed0
    virtual void vfunc_11();                                        // 11 0x141417230 mouse wheel
    virtual void vfunc_14(float fValue);                            // 14 0x141417100
    virtual void vfunc_15(int nIndex, float fValue);                // 15 0x141417140
    virtual float vfunc_19();                                       // 19 0x141416f10
    virtual float vfunc_20();                                       // 20 0x141416f40
    virtual const Unk_CustomizeRange* vfunc_23();                   // 23 0x141416f70
    virtual const Unk_CustomizeRange* vfunc_24(int nIndex);         // 24 0x141416fd0
    virtual void vfunc_25(float* pfMin, float* pfMax);              // 25 0x141417030
    virtual void vfunc_26(int nIndex, float* pfMin, float* pfMax);  // 26 0x141417090
    virtual int vfunc_27();                                         // 27 0x1414171e0 number of value ranges
    virtual void vfunc_28();                                        // 28 0x141417470 picking mesh names
    virtual int vfunc_29();                                         // 29 0x141417310
    virtual int vfunc_38(int bActive, const efd::Point3& kPos);     // 38 0x141417870
    virtual float vfunc_40();                                       // 40 0x1414175c0
    virtual int vfunc_41();                                         // 41 0x1414175e0 mouse wheel (inverted)
    virtual void vfunc_42(int nIndex, float fValue, NiInterpController* pCtrl);   // 42 0x141417660 (new slot)

    // non-virtual (names invented)
    int HasMorphController();                                      // 0x141417830
    void ResetMeshHighlight();                                      // 0x141417930
    void ApplyMorph();                                              // 0x141417c10
    NiInterpController* FindMorphController(int bTrack);            // 0x141417ea0
    NiInterpController* SelectMorphController(int nIndex);          // 0x141418550
    efd::SmartPointer<NiAVObject> FindMorphNode(int nIndex);        // 0x141418620

    float m_fWheelStep;                                             // +0xb8 wheel step (client config +0x2d90)
    int m_nBC;                                                      // +0xbc
};
MS2_CHECK_SIZE(CItemMorphController, 0xc0);
MS2_CHECK_OFFSET(CItemMorphController, m_fWheelStep, 0xb8);
