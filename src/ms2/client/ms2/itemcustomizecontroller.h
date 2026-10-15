// itemcustomizecontroller.h - shared declarations of the ?\itemcustomizecontroller.cpp family (four TUs fused in the
// unit table: CItemCustomizeController base, ItemEnchantSlotBag/ItemInfoSlot, CItemMorphController, CItemPickingHelper).
// Member names are invented from their use. Owning units: ?\itemcustomizecontroller.cpp#1..#4 (0x141410cd0-0x141419df0).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiRefObject.h>
#include <NiRenderObject.h>
#include <efd/Point2.h>
#include <NiPoint3.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class NiAVObject;
class CMeshUVPicker;       // 0x98 bytes, unit ?\meshuvpicker.cpp (not recovered yet)

// The item/equipment object a picking helper can ray-pick against (CPtred-derived, refcounted in MS2Ptr).
struct Unk_PickTarget : public CPtred
{
    MS2Ptr<CItem> FUN_141200940() const;        // the item the slot shows
    void* FUN_141200850() const;                // the slot's game object (owns the model)
    NiAVObject* FUN_1411676d0(NiRenderObject** pPart) const;   // the model node of one attach part
};

// Smart pointer to a scene node (NiRefObject::IncRefCount 0x140980460 / DecRefCount 0x1405a93d0). 8 bytes.
struct Unk_PickMeshPtr
{
    Unk_PickMeshPtr(NiAVObject* p);             // 0x1414197a0
    ~Unk_PickMeshPtr();                         // 0x141419840
    Unk_PickMeshPtr& FUN_141418a00(NiAVObject* p);  // assignment (0x141418a00)
    NiAVObject* FUN_141412c90() const;          // get
    NiAVObject* m_p;
};
MS2_CHECK_SIZE(Unk_PickMeshPtr, 8);

// Owning pointer to the UV picker (out-of-line members elsewhere in the exe).
struct Unk_UVPickerPtr
{
    Unk_UVPickerPtr(int);                       // 0x141286170
    ~Unk_UVPickerPtr();                         // 0x1412861b0
    Unk_UVPickerPtr& FUN_1412861e0(CMeshUVPicker* p);   // reset
    CMeshUVPicker* FUN_141286290() const;       // get
    CMeshUVPicker* m_p;
};
MS2_CHECK_SIZE(Unk_UVPickerPtr, 8);

// Ray-picks the parts of one or more equipped items against the cursor (item customize / dye UI). Ref-counted.
class CItemPickingHelper : public NiRefObject
{
public:
    CItemPickingHelper();                                       // 0x141418c00
    virtual ~CItemPickingHelper();                              // 0x141418cd0, ??_G 0x141419870

    void CreatePicker();                                        // 0x141418d60
    void ClearTargets();                                        // 0x141418e00
    void AddTarget(Unk_PickTarget* pTarget);                    // 0x141418e30
    Unk_PickTarget* GetPickedTarget();                          // 0x141418e90
    int GetPickedIndex() const;                                 // 0x141418ef0
    int Pick(efd::Point3* pHit, CAtlArray<NiRenderObject*>& parts);   // 0x141418f10
    void Reset();                                               // 0x141419210
    int PickTarget(Unk_PickTarget* pTarget, NiRenderObject** pPart, NiPoint3* pHit);    // 0x141419250
    int PickMesh(NiAVObject* pMesh, CAtlArray<NiRenderObject*>& skins, NiPoint3* pHit);    // 0x1414194b0

    Unk_PickMeshPtr m_spMesh;                                   // +0x10 mesh hit by the last successful pick
    int m_nUnk18;                                               // +0x18
    Unk_UVPickerPtr m_spPicker;                                 // +0x20
    ATL::CAtlArray<MS2Ptr<Unk_PickTarget> > m_targets;          // +0x28
    int m_nPicked;                                              // +0x48 index into m_targets, -1 = none
    efd::Point2 m_kUv0;                                         // +0x4c
    efd::Point2 m_kUv1;                                         // +0x54
    Unk_PickMeshPtr m_spLast;                                   // +0x60
};
MS2_CHECK_SIZE(CItemPickingHelper, 0x68);
MS2_CHECK_OFFSET(CItemPickingHelper, m_spPicker, 0x20);
MS2_CHECK_OFFSET(CItemPickingHelper, m_targets, 0x28);
MS2_CHECK_OFFSET(CItemPickingHelper, m_nPicked, 0x48);
MS2_CHECK_OFFSET(CItemPickingHelper, m_spLast, 0x60);
