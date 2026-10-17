// transparencymaterial.h - PLACEHOLDER for TransparencyMaterial / TransparencyStandardMaterial (RTTI names). NOT an
// original header; the out-of-line code is ?\transparencymaterial.cpp (0x14185ff70-0x141860bf0, not recovered yet).
// TransparencyMaterial : NiRefObject, 0x38 bytes: ctor 0x14185ff70 (stores the geometry at +0x10 and nulls four smart
// pointers at +0x18..+0x30), dtor 0x141860060, vftable 0x142f882e8 (slots 2-4 pure). TransparencyStandardMaterial
// (vftable 0x142dc3b48) only overrides slots 2-4; its ctor 0x140a16050 and dtor 0x140a16730 are header inlines (the
// first user, ?\bgtransparencymgr.cpp, owns the COMDATs and the vftable).
#pragma once

#include <NiRefObject.h>
#include <NiBound.h>

#include "ms2/ms2layout.h"

class NiRenderObject;

class TransparencyMaterial : public NiRefObject
{
public:
    TransparencyMaterial(NiRenderObject* pGeometry);                // 0x14185ff70
    virtual ~TransparencyMaterial();                                // 0x141860060 (deleting 0x141860ac0)
    virtual void vfunc_2(const NiBound& kBound) = 0;               // MS2: slot 2 apply (gets the entity's world bound)
    virtual void vfunc_3() = 0;                                     // MS2: slot 3 restore the mesh
    virtual void vfunc_4(float fAlpha) = 0;                         // MS2: slot 4 set alpha

    NiRenderObject* m_pGeometry;                                    // +0x10
    void* m_sp18;                                                   // +0x18 smart pointers (types not recovered)
    void* m_sp20;                                                   // +0x20
    void* m_sp28;                                                   // +0x28
    void* m_sp30;                                                   // +0x30
};
MS2_CHECK_SIZE(TransparencyMaterial, 0x38);

class TransparencyStandardMaterial : public TransparencyMaterial
{
public:
    // @0x140a16050
    TransparencyStandardMaterial(NiRenderObject* pGeometry) : TransparencyMaterial(pGeometry) {}
    virtual void vfunc_2(const NiBound& kBound);                    // 0x141860b20
    virtual void vfunc_3();                                         // 0x141860bd0
    virtual void vfunc_4(float fAlpha);                             // 0x141860bf0
};
MS2_CHECK_SIZE(TransparencyStandardMaterial, 0x38);
