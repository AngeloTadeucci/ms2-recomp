// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\mesh.cpp
// MS2-RANGE: 0x14147af80-0x14147be60 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mesh.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "mesh.h"
#include <NiMaterialLibrary.h>
#include <NiCommonSemantics.h>
#include <NiBound.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern NiFixedString DAT_143ae51e0;    // name of the material every CMesh uses

// @0x14147af80
CMesh::CMesh(bool bNormals, bool bColors, unsigned int nUVSets, unsigned int nMaxVerts, unsigned int nMaxTris,
    unsigned char ucAccessMask)
{
    m_nMaxVerts = nMaxVerts;
    m_nMaxTris = nMaxTris;
    m_bNormals = bNormals;
    m_bColors = bColors;
    m_nUVSets = nUVSets;
    m_nVerts = 0;
    m_nTris = 0;
    m_spMesh = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
    m_spMesh->ApplyAndSetActiveMaterial(NiMaterialLibrary::CreateMaterial(DAT_143ae51e0));
    AddStream(NiCommonSemantics::POSITION(), 0, NiDataStreamElement::F_FLOAT32_3, nMaxVerts, ucAccessMask,
        NiDataStream::USAGE_VERTEX, NULL, false);
    if (bNormals)
        AddStream(NiCommonSemantics::NORMAL(), 0, NiDataStreamElement::F_FLOAT32_3, nMaxVerts, ucAccessMask,
            NiDataStream::USAGE_VERTEX, NULL, false);
    if (bColors)
        AddStream(NiCommonSemantics::COLOR(), 0, NiDataStreamElement::F_FLOAT32_4, nMaxVerts, ucAccessMask,
            NiDataStream::USAGE_VERTEX, NULL, false);
    if (nUVSets > 0)
    {
        for (unsigned int i = 0; i < nUVSets; i++)
            AddStream(NiCommonSemantics::TEXCOORD(), i, NiDataStreamElement::F_FLOAT32_2, nMaxVerts, ucAccessMask,
                NiDataStream::USAGE_VERTEX, NULL, false);
    }
    AddStream(NiCommonSemantics::INDEX(), 0, NiDataStreamElement::F_UINT16_1, nMaxTris * 3, ucAccessMask,
        NiDataStream::USAGE_VERTEX_INDEX, NULL, false);
    m_spMesh->SetSubmeshCount(1);
    SetVertexCount(0);
    SetTriangleCount(0);
}

// @0x14147b330
CMesh::~CMesh()
{
    m_spMesh = 0;
}

// @0x14147b390
bool CMesh::SetPosition(unsigned int i, const NiPoint3& kPos)
{
    if (i >= m_nMaxVerts)
        return false;
    NiPoint3* pkPos = (NiPoint3*)Lock(NiCommonSemantics::POSITION(), 0, NiDataStream::LOCK_WRITE);
    if (pkPos)
    {
        pkPos[i] = kPos;
        Unlock(NiCommonSemantics::POSITION(), 0, NiDataStream::LOCK_WRITE);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14147b390, CMesh, SetPosition, 140, 0x6B88ABAA);

// @0x14147b430
bool CMesh::SetColor(unsigned int i, const NiColorA& kColor)
{
    if (i >= m_nMaxVerts)
        return false;
    NiColorA* pkColor = (NiColorA*)Lock(NiCommonSemantics::COLOR(), 0, NiDataStream::LOCK_WRITE);
    if (pkColor)
    {
        pkColor[i] = kColor;
        Unlock(NiCommonSemantics::COLOR(), 0, NiDataStream::LOCK_WRITE);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14147b430, CMesh, SetColor, 141, 0x68A85F6A);

// @0x14147b4d0
bool CMesh::SetUV(unsigned int i, unsigned int uiSet, const NiPoint2& kUV)
{
    if (i >= m_nMaxVerts)
        return false;
    NiPoint2* pkUV = (NiPoint2*)Lock(NiCommonSemantics::TEXCOORD(), uiSet, NiDataStream::LOCK_WRITE);
    if (pkUV)
    {
        pkUV[i] = kUV;
        Unlock(NiCommonSemantics::TEXCOORD(), uiSet, NiDataStream::LOCK_WRITE);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14147b4d0, CMesh, SetUV, 138, 0xEF512B0D);

// @0x14147b560
bool CMesh::SetNormal(unsigned int i, const NiPoint3& kNormal)
{
    if (i >= m_nMaxVerts)
        return false;
    NiPoint3* pkNormal = (NiPoint3*)Lock(NiCommonSemantics::NORMAL(), 0, NiDataStream::LOCK_WRITE);
    if (pkNormal)
    {
        pkNormal[i] = kNormal;
        Unlock(NiCommonSemantics::NORMAL(), 0, NiDataStream::LOCK_WRITE);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14147b560, CMesh, SetNormal, 140, 0x8CFDAC5F);

// @0x14147b600
bool CMesh::SetTriangle(unsigned int i, unsigned short a, unsigned short b, unsigned short c)
{
    if (i >= m_nMaxTris)
        return false;
    unsigned short* pIndex = (unsigned short*)Lock(NiCommonSemantics::INDEX(), 0, NiDataStream::LOCK_WRITE);
    if (pIndex)
    {
        unsigned int n = i * 3;
        pIndex[n] = a;
        pIndex[n + 1] = b;
        pIndex[n + 2] = c;
        Unlock(NiCommonSemantics::INDEX(), 0, NiDataStream::LOCK_WRITE);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14147b600, CMesh, SetTriangle, 190, 0xCAD40A50);

// @0x14147b6d0
bool CMesh::SetQuad(unsigned int i, unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    if (i + 1 >= m_nMaxTris)
        return false;
    unsigned short* pIndex = (unsigned short*)Lock(NiCommonSemantics::INDEX(), 0, NiDataStream::LOCK_WRITE);
    if (pIndex)
    {
        unsigned int n = i * 3;
        pIndex[n] = a;
        pIndex[n + 1] = b;
        pIndex[n + 2] = d;
        n += 3;
        pIndex[n] = b;
        pIndex[n + 1] = c;
        pIndex[n + 2] = d;
        Unlock(NiCommonSemantics::INDEX(), 0, NiDataStream::LOCK_WRITE);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14147b6d0, CMesh, SetQuad, 270, 0xD1FE3B27);

// @0x14147b7f0
void* CMesh::Lock(const NiFixedString& kSemantic, unsigned int uiIndex, unsigned char ucLockMask)
{
    NiDataStream* pkStream = GetDataStream(kSemantic, uiIndex);
    if (pkStream)
        return pkStream->Lock(ucLockMask);
    return NULL;
}
MS2_REPLACE_METHOD(0x14147b7f0, CMesh, Lock, 81, 0xA1A287D3);

// @0x14147b850
void CMesh::Unlock(const NiFixedString& kSemantic, unsigned int uiIndex, unsigned char ucLockMask)
{
    NiDataStream* pkStream = GetDataStream(kSemantic, uiIndex);
    if (pkStream)
        pkStream->Unlock(ucLockMask);
}
MS2_REPLACE_METHOD(0x14147b850, CMesh, Unlock, 77, 0x759369EB);

// @0x14147b8b0
void CMesh::SetVertexCount(unsigned int n)
{
    m_nVerts = n;
    GetDataStream(NiCommonSemantics::POSITION(), 0)->GetRegion(0).SetRange(n);
    if (m_bNormals)
        GetDataStream(NiCommonSemantics::NORMAL(), 0)->GetRegion(0).SetRange(n);
    if (m_bColors)
        GetDataStream(NiCommonSemantics::COLOR(), 0)->GetRegion(0).SetRange(n);
    for (unsigned int i = 0; i < m_nUVSets; i++)
        GetDataStream(NiCommonSemantics::TEXCOORD(), i)->GetRegion(0).SetRange(n);
}
MS2_REPLACE_METHOD(0x14147b8b0, CMesh, SetVertexCount, 266, 0x4E44A3DA);

// @0x14147b9c0
void CMesh::SetTriangleCount(unsigned int n)
{
    m_nTris = n;
    GetDataStream(NiCommonSemantics::INDEX(), 0)->GetRegion(0).SetRange(n);
    m_spMesh->UpdateCachedPrimitiveCount();
}
MS2_REPLACE_METHOD(0x14147b9c0, CMesh, SetTriangleCount, 98, 0x1C1138D6);

// @0x14147ba30
void CMesh::UpdateBound()
{
    if (!m_nVerts)
        return;
    NiPoint3* pkPos = (NiPoint3*)Lock(NiCommonSemantics::POSITION(), 0, NiDataStream::LOCK_READ);
    if (pkPos)
    {
        NiBound kBound;
        kBound.ComputeFromData(m_nVerts, pkPos);
        m_spMesh->SetModelBound(kBound);
        Unlock(NiCommonSemantics::POSITION(), 0, NiDataStream::LOCK_READ);
    }
}
MS2_REPLACE_METHOD(0x14147ba30, CMesh, UpdateBound, 151, 0xF47CE4A7);

// @0x14147bb30
void CMesh::AddStream(const NiFixedString& kSemantic, unsigned int uiIndex, NiDataStreamElement::Format eFormat,
    unsigned int uiCount, unsigned char ucAccessMask, NiDataStream::Usage eUsage, const void* pvSource,
    bool bForceToolDS)
{
    NiDataStream* pkStream = NiDataStream::CreateSingleElementDataStream(eFormat, uiCount, ucAccessMask, eUsage,
        pvSource, true, bForceToolDS);
    m_spMesh->AddStreamRef(pkStream, kSemantic, uiIndex, false);
}
MS2_REPLACE_METHOD(0x14147bb30, CMesh, AddStream, 142, 0xA041BA35);

// @0x14147bcc0
NiDataStream* CMesh::GetDataStream(const NiFixedString& kSemantic, unsigned int uiIndex)
{
    NiDataStreamRef* pkRef = m_spMesh->FindStreamRef(kSemantic, uiIndex);
    if (pkRef)
        return pkRef->GetDataStream();
    return NULL;
}
MS2_REPLACE_METHOD(0x14147bcc0, CMesh, GetDataStream, 89, 0xFFB071AE);
