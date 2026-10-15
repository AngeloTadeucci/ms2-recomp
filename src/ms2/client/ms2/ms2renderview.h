// MS2RenderView: Ni3DRenderView subclass (0x70 bytes, no extra members) used by the MS2 render steps. The
// *Cli-less engine bases (NiRenderView 0x38, Ni3DRenderView 0x70) come from the real Gamebryo headers.
#pragma once
#include "ms2/ms2layout.h"
#include <Ni3DRenderView.h>

class MS2RenderView : public Ni3DRenderView {
    NiDeclareRTTI;

public:
    MS2RenderView(NiCamera* pkCamera = NULL, NiCullingProcess* pkCullingProcess = NULL, bool bAlwaysUseCameraViewport = true);
    virtual ~MS2RenderView();
protected:
    virtual void CalculatePVGeometry();             // 0x140d9dc30
};
MS2_CHECK_SIZE(MS2RenderView, 0x70);
