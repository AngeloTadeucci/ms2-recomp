// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TransparencyStandardMaterial::vfunc_4: fades a mesh by
// scaling its material alpha (against the saved material) and its alpha-test reference.
// MS2-UNIT: unit_141860bf0
// MS2-RANGE: 0x141860bf0-0x141860e60 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE ""   // no assert in the unit
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/transparencymaterial.h"
#include <NiAVObject.h>
#include <NiRenderObject.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x141860bf0
void TransparencyStandardMaterial::vfunc_4(float fAlpha)
{
    NiMaterialProperty* pMaterial = static_cast<NiMaterialProperty*>(m_pGeometry->GetProperty(NiProperty::MATERIAL));
    if (pMaterial)
    {
        float fBaseAlpha = 1.0f;
        if (m_spMaterial)
            fBaseAlpha = m_spMaterial->GetAlpha();
        pMaterial->SetAlpha(fBaseAlpha * fAlpha);
    }
    NiAlphaProperty* pAlpha = NiDynamicCast(NiAlphaProperty, m_pGeometry->GetProperty(NiProperty::ALPHA));
    if (pAlpha)
    {
        if (pAlpha->GetAlphaTesting())
        {
            int nRef = pAlpha->GetTestRef();
            nRef = (int)(fAlpha * nRef);
            pAlpha->SetTestRef(nRef & 0xff);
        }
    }
    m_pGeometry->UpdateProperties();
}

MS2_EMIT_CRT_MEMMOVE_S();
