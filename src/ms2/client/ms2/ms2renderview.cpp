// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\ms2renderview.cpp
// MS2-RANGE: 0x1400d3d00-0x1400d3d30 .text$di
// MS2-RANGE: 0x140d9dba0-0x140d9e530 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2renderview.h"

#ifdef __clang__
static volatile unsigned __int64 s_msZero;
static const NiRTTI* msBaseRTTI() { return (const NiRTTI*)((unsigned __int64)&Ni3DRenderView::ms_RTTI + s_msZero); }
const NiRTTI MS2RenderView::ms_RTTI("MS2RenderView", msBaseRTTI());
#else
// @0x1400d3d00
const NiRTTI MS2RenderView::ms_RTTI("MS2RenderView", &Ni3DRenderView::ms_RTTI);
#endif

// @0x140d9dba0
MS2RenderView::MS2RenderView(NiCamera* pkCamera, NiCullingProcess* pkCullingProcess, bool bAlwaysUseCameraViewport)
    : Ni3DRenderView(pkCamera, pkCullingProcess, bAlwaysUseCameraViewport)
{
}

// @0x140d9dc00
MS2RenderView::~MS2RenderView()
{
}

// @0x140d9dc30
void MS2RenderView::CalculatePVGeometry()
{
    if (m_spCamera && m_spCullingProcess)
    {
        m_spCullingProcess->Cull(m_spCamera, (NiTPointerList<NiAVObject*>*)&m_kScenes, &m_kCachedPVGeometry);
    }
    else
    {
        NiTListIterator kIter = m_kScenes.GetHeadPos();
        while (kIter)
        {
            NiAVObject* pkScene = m_kScenes.GetNext(kIter);
            AddToPVGeometryArray(pkScene);
        }
    }
}
