// softparticlesmanager.h - SoftParticlesManager (0x28 bytes; RTTI name from vftable 0x142db5b48; ctor
// 0x1409a7940 and scalar deleting dtor 0x1409a8710 are compiled into ?\applyeffect.cpp). A helper that renders
// the soft-particle scene nodes into a second 3D view and points their texturing properties at the MRT target.
// Owning unit: ?\softparticlesmanager.cpp (0x141773630-0x141774240).
#pragma once
#include "ms2/placeholder/nirefobject.h"
#include <NiViewRenderClick.h>
#include <Ni3DRenderView.h>
#include <NiMaterial.h>

class SoftParticlesManager : public NiRefObject
{
public:
    SoftParticlesManager();                                     // 0x1409a7940 (?\applyeffect.cpp)
    virtual ~SoftParticlesManager();                            // 0x1417738e0

    MS2_LAYOUT_FRIEND;
    NiViewRenderClickPtr m_spClick;     // +0x10 the "SoftParticleClick" render click
    Ni3DRenderViewPtr m_spView;         // +0x18 the mirrored 3D view
    NiMaterialPtr m_spMaterial;         // +0x20 the material created for the view
};
MS2_CHECK_SIZE(SoftParticlesManager, 0x28);
MS2_CHECK_OFFSET(SoftParticlesManager, m_spClick, 0x10);
MS2_CHECK_OFFSET(SoftParticlesManager, m_spView, 0x18);
MS2_CHECK_OFFSET(SoftParticlesManager, m_spMaterial, 0x20);
