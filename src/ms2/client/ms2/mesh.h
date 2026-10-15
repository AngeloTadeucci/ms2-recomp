// mesh.h - CMesh: a small dynamic NiMesh builder (positions [+normals] [+colors] [+N uv sets] + 16-bit triangle
// index stream) used for decals/shadows/beams. Owning unit: ?\mesh.cpp (0x14147af80-0x14147be60, 21 funcs; dir
// client\ms2). Header name assumed. Method names are invented from behaviour (VA noted on each).
//
// HOW TO USE THIS HEADER (for unit workers):
// - Derive `class X : public CMesh` (e.g. CObjectShadow: CMesh(false, false, 1, 4, 2, 0x12)). CMesh is NiRefObject
//   based (vptr +0, refcount +8); allocate with NiNew/new (efd::MemObject operator new 0x14208a860).
// - vftable 0x142f18240 has 2 slots: ??_G 0x14147bad0 and NiRefObject::DeleteThis 0x141d16bf0 (inherited).
// - Typical use: Set{Position,Normal,Color,UV}(i, ...) / SetTriangle / SetQuad for each element, then
//   SetVertexCount(n), SetTriangleCount(n), UpdateBound(); GetMesh() is attached to a scene node by the caller.
#pragma once
#include <NiRefObject.h>
#include <NiSmartPointer.h>
#include <NiMesh.h>
#include <NiDataStream.h>
#include <NiPoint2.h>
#include <NiPoint3.h>
#include <NiColor.h>

#include "ms2/ms2layout.h"

// 0x30 bytes.
class CMesh : public NiRefObject
{
public:
    // Builds the NiMesh (0x1a0) with the material registered under 0x143ae51e0 and adds the streams:
    // POSITION R32G32B32 (nMaxVerts), [NORMAL], [COLOR R32G32B32A32], nUVSets x TEXCOORD R32G32, INDEX UINT16
    // (nMaxTris * 3); then SetVertexCount(0), SetTriangleCount(0).
    CMesh(bool bNormals, bool bColors, unsigned int nUVSets, unsigned int nMaxVerts, unsigned int nMaxTris,
        unsigned char ucAccessMask);                                                      // 0x14147af80
    virtual ~CMesh();                                                                     // 0x14147b330

    bool SetPosition(unsigned int i, const NiPoint3& kPos);                               // 0x14147b390
    bool SetColor(unsigned int i, const NiColorA& kColor);                                // 0x14147b430
    bool SetUV(unsigned int i, unsigned int uiSet, const NiPoint2& kUV);                  // 0x14147b4d0
    bool SetNormal(unsigned int i, const NiPoint3& kNormal);                              // 0x14147b560
    bool SetTriangle(unsigned int i, unsigned short a, unsigned short b, unsigned short c);   // 0x14147b600
    bool SetQuad(unsigned int i, unsigned short a, unsigned short b, unsigned short c,
        unsigned short d);                                  // 0x14147b6d0: tris (a,b,d),(b,c,d) at i, i+1
    void* Lock(const NiFixedString& kSemantic, unsigned int uiIndex, unsigned char ucLockMask);   // 0x14147b7f0
    void Unlock(const NiFixedString& kSemantic, unsigned int uiIndex, unsigned char ucLockMask); // 0x14147b850
    void SetVertexCount(unsigned int n);                    // 0x14147b8b0 region-0 range of every vertex stream
    void SetTriangleCount(unsigned int n);                  // 0x14147b9c0 index region + mesh primitive count
    void UpdateBound();                                     // 0x14147ba30 NiBound::ComputeFromData(positions)
    void AddStream(const NiFixedString& kSemantic, unsigned int uiIndex, NiDataStreamElement::Format eFormat,
        unsigned int uiCount, unsigned char ucAccessMask, NiDataStream::Usage eUsage, const void* pvSource,
        bool bForceToolDS);                                 // 0x14147bb30
    NiDataStream* GetDataStream(const NiFixedString& kSemantic, unsigned int uiIndex);  // 0x14147bcc0

    NiMesh* GetMesh() const { return m_spMesh; }

public:
    MS2_LAYOUT_FRIEND;
    NiMeshPtr m_spMesh;                 // +0x10
    unsigned int m_nMaxVerts;           // +0x18
    unsigned int m_nMaxTris;            // +0x1c
    bool m_bNormals;                    // +0x20
    bool m_bColors;                     // +0x21
    unsigned int m_nUVSets;             // +0x24
    unsigned int m_nVerts;              // +0x28 (SetVertexCount)
    unsigned int m_nTris;               // +0x2c (SetTriangleCount)
};
MS2_CHECK_SIZE(CMesh, 0x30);
MS2_CHECK_OFFSET(CMesh, m_spMesh, 0x10);
MS2_CHECK_OFFSET(CMesh, m_nMaxVerts, 0x18);
MS2_CHECK_OFFSET(CMesh, m_bNormals, 0x20);
MS2_CHECK_OFFSET(CMesh, m_nUVSets, 0x24);
MS2_CHECK_OFFSET(CMesh, m_nTris, 0x2c);
