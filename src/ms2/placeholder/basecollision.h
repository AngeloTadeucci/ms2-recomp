// basecollision.h - CBaseCollision (RTTI .?AVCBaseCollision@@), the CPtred-derived base of the debug/trigger collision
// shape visualisers (CBoxCollision 0x150, CCylinderCollision 0xc8, CHoleCylinderCollision). Owning unit:
// ?\basecollision.cpp (0x1409fbc80-..., not recovered yet); this header is a placeholder written from the derived
// units (unit_141083230 = CCylinderCollision). Member names are invented; layout proven from the ctor 0x1409fbc80.
//
// Size 0x78, vftable 0x142e... (8 slots): 0 ~CBaseCollision (scalar deleting), 1 vfunc_1 (render), 2/3 transform
// setters (identical bodies), 4 empty, 5 Build (pure here; the derived classes build the NiMesh outlines), 6 float
// accessor (pure here), 7 intersection test.
// The ctor builds the first NiMesh (m_spMesh) and a NiVertexColorProperty (vertex colours, no lighting) on it.
// ctor 0x1409fbc80, dtor 0x1409fbed0, vfunc_1 0x1409fbf20, vfunc_2 0x1409fbff0, vfunc_3 0x1409fbfa0, vfunc_4 0x1409fc040,
// vfunc_7 0x1409fc050; these have no source in the tree yet and are bound through progress/symbols-manual.tsv.
#pragma once

#include <NiMesh.h>
#include <NiColor.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"

class CBaseCollision : public CPtred
{
public:
    CBaseCollision();                                                       // 0x1409fbc80
    virtual ~CBaseCollision();                                              // 0x1409fbed0
    virtual void vfunc_1();                                                 // 0x1409fbf20 builds if needed, then renders m_spMesh
    virtual void vfunc_2(Unk_StreamPoint pos, Unk_StreamPoint rot, float scale);   // 0x1409fbff0
    virtual void vfunc_3(Unk_StreamPoint pos, Unk_StreamPoint rot, float scale);   // 0x1409fbfa0 m_pos = pos, then 0x1409fe440
    virtual void vfunc_4();                                                 // 0x1409fc040 (empty)
    virtual void vfunc_5() = 0;                                             // Build the meshes
    virtual float vfunc_6() = 0;
    virtual int vfunc_7(void* a, void* b);                                  // 0x1409fc050

    int m_18;                                                               // +0x18
    Unk_StreamPoint m_pos;                                                  // +0x1c
    Unk_StreamPoint m_28;                                                   // +0x28
    Unk_StreamPoint m_34;                                                   // +0x34
    int m_40;                                                               // +0x40
    NiColorA m_color;                                                       // +0x44 (1, 0, 0, 1)
    bool m_blocking;                                                        // +0x54
    int m_58;                                                               // +0x58
    CStringW m_60;                                                          // +0x60
    NiMeshPtr m_spMesh;                                                     // +0x68
    int m_built;                                                            // +0x70
};
MS2_CHECK_SIZE(CBaseCollision, 0x78);
MS2_CHECK_OFFSET(CBaseCollision, m_pos, 0x1c);
MS2_CHECK_OFFSET(CBaseCollision, m_color, 0x44);
MS2_CHECK_OFFSET(CBaseCollision, m_60, 0x60);
MS2_CHECK_OFFSET(CBaseCollision, m_spMesh, 0x68);
MS2_CHECK_OFFSET(CBaseCollision, m_built, 0x70);
