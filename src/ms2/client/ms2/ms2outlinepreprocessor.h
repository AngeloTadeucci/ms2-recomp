// ms2outlinepreprocessor.h - MS2OutlinePreProcessor: NiShaderSortProcessor subclass (0xc0) that temporarily swaps the
// outline material (+0xb0) onto objects flagged for outlining, re-sorts them, then restores the originals.
// Owning unit: ?\ms2outlinepreprocessor.cpp (0x1414d3120-0x1414d4e20, dir client\ms2).
#pragma once
#include "ms2/ms2layout.h"
#include <NiShaderSortProcessor.h>

class MS2OutlinePreProcessor : public NiShaderSortProcessor
{
    NiDeclareRTTI;

public:
    MS2OutlinePreProcessor();                               // 0x1414d3120
    virtual ~MS2OutlinePreProcessor();                      // 0x1414d3cc0, ??_G 0x1414d3cf0
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1414d3360

public:
    void* m_spOutlineMaterial;   // +0xb0 smart pointer (ctor 0x1409a7460, assign 0x1414802a0, get 0x1409a8120, dtor 0x1409a7b00)
    int m_nOutlined;             // +0xb8 count of objects in the last re-sorted list
};
MS2_CHECK_SIZE(MS2OutlinePreProcessor, 0xc0);
