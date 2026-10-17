// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Character mesh merger: merges skinned NiMeshes per material group,
// packs the character textures into an atlas and saves debug NIFs.
// MS2-UNIT: client\ms2\charactermeshmerger.cpp
// MS2-RANGE: 0x141049240-0x141064d70 .text$mn
// MS2-RANGE: 0x1400e4c80-0x1400e4e20 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\charactermeshmerger.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "charactermeshmerger.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "hook/ms2hook.h"
#include <NiMesh.h>
#include <NiNode.h>
#include <NiStream.h>
#include <NiSkinningMeshModifier.h>
#include <NiMorphMeshModifier.h>
#include <NiCommonSemantics.h>
#include <NiTexture.h>
#include <efd/LoggerMacros.h>
#include "ms2/commonfiles/logstring.h"

// Scene walker of the cube code (ctor 0x14098cb80); children are queued by AddChildren and Next returns the next object.
class Unk_CubeSceneIterator {
public:
    Unk_CubeSceneIterator(NiAVObject* pRoot);
    ~Unk_CubeSceneIterator();
    NiAVObject* FUN_14098e0d0(bool descend);
    void FUN_14098d6d0(NiNode* pNode);                  // queue the children
private:
    ATL::CAtlList<NiAVObject*> pending;
};
MS2_CHECK_SIZE(Unk_CubeSceneIterator, 0x30);

bool FUN_14098dad0(NiAVObject* pObject);                // object is hidden/culled
NiNode* FUN_140a0b000(NiAVObject* pObject);             // parent node
bool FUN_141052aa0(const NiPropertyState* pA, const NiPropertyState* pB);   // property states are equal

struct Unk_MaterialTable;                               // DAT_143d69198 (MS2StandardMaterial RTTI)
struct Unk_MaterialEntry;
extern Unk_MaterialTable DAT_143d69198;
Unk_MaterialEntry* FUN_140a17af0(Unk_MaterialTable* pTable, const NiMaterial* pMaterial);
int FUN_140ef4dd0(Unk_MaterialEntry* pEntry);
NiMaterial* FUN_140a17cd0(NiMesh* pMesh);         // active material
int FUN_141049fa0(NiMesh* pMesh, const MeshGroups& kGroups);

CLogString* FUN_140166440();

// Four-argument wide log (template instance 0x141054b90).
template<class T, class U, class V, class W> inline void Unk_MeshLog(CLogString* log, int level, int category, const wchar_t* format,
                                                                   const T& first, const U& second, const V& third, const W& fourth) {
    const fmt::internal::ArgArray<4>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(third),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(fourth)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third, fourth), args));
}

typedef ATL::CAtlArray<efd::SmartPointer<NiMesh> > MeshArray;

// One element of the merged vertex stream: semantic, semantic index and format (ctor 0x141066fd0).
struct Unk_StreamElementDesc
{
    Unk_StreamElementDesc(const NiFixedString& kSemantic, unsigned int uiIndex, NiDataStreamElement::Format eFormat)
        : m_kSemantic(kSemantic), m_uiIndex(uiIndex), m_eFormat(eFormat) {}

    NiFixedString m_kSemantic;
    unsigned int m_uiIndex;
    NiDataStreamElement::Format m_eFormat;
};
MS2_CHECK_SIZE(Unk_StreamElementDesc, 0x10);

// Skinning merge state of one group (ctor 0x141067020, dtor 0x1410682d0; 0x50 bytes).
struct MergeInfo
{
    MergeInfo();
    ~MergeInfo();

    efd::SmartPointer<NiSkinningMeshModifier> m_spSkin;                             // +0 the merged modifier
    std::map<NiMesh*, std::map<unsigned char, unsigned char> > m_kBoneRemap;        // +8 per mesh: old bone index -> merged index
    std::vector<std::vector<unsigned char> > m_kBoneLists;                          // +0x18 per bucket: merged bone indices
    std::vector<std::map<unsigned char, unsigned char> > m_kBucketRemap;            // +0x30
};

MeshGroups* FUN_141066d90(MeshGroups* pGroups);
void FUN_14104a1c0(const MeshList& kGroup, MeshGroups& kBuckets, MergeInfo& kInfo);
NiMesh* FUN_14104ae20(const MeshGroups& kBuckets, MergeInfo& kInfo, NiAVObject* pRoot);
void FUN_14104e800(const MeshList& kGroup, MeshGroups& kBuckets, MergeInfo& kInfo);
NiMesh* FUN_14104f460(const MeshGroups& kBuckets, MergeInfo& kInfo, NiAVObject* pRoot);
void FUN_141049d50(NiAVObject* pRoot, MeshGroups& kGroups);
void FUN_14104b530(NiMesh* pMerged, const MeshGroups& kBuckets);
void FUN_14104bbb0(NiMesh* pMerged, MergeInfo& kInfo, const MeshGroups& kBuckets, const NiTransform& kRootTransform);
int FUN_141051ee0(std::set<NiAVObject*>& kBones, NiAVObject** ppBones, unsigned int uiCount);
void FUN_14104d450(NiAVObject* pRoot, MeshGroups& kGroups);

// @0x141049240
void FUN_141049240(NiAVObject* pRoot, MeshArray& kSource, MeshArray& kMerged)
{
    if (pRoot != 0)
    {
        MeshGroups kGroups;
        FUN_141049d50(pRoot, kGroups);
        for (unsigned int i = 0; i < kGroups.size(); i++)
        {
            if (kGroups[i].size() != 1)
            {
                for (unsigned int j = 0; j < kGroups[i].size(); j++)
                    kSource.Add(efd::SmartPointer<NiMesh>(kGroups[i][j]));
            }
        }
        if (kSource.GetCount() == 0)
            return;
        for (unsigned int i = 0; i < kGroups.size(); i++)
        {
            CString kLine = StringFormat("{0}:", i);
            for (unsigned int j = 0; j < kGroups[i].size(); j++)
                kLine += StringFormat(" {0}", (const char*)kGroups[i][j]->GetName());
            EE_LOG_AT(1, 1, ((const char*)kLine), MS2_THIS_FILE, 0x68f);
        }
        for (unsigned int i = 0; i < kGroups.size(); i++)
        {
            if (kGroups[i].size() != 1)
            {
                MeshGroups kBuckets;
                MergeInfo kInfo;
                FUN_14104a1c0(kGroups[i], kBuckets, kInfo);
                efd::SmartPointer<NiMesh> spMerged(FUN_14104ae20(kBuckets, kInfo, pRoot));
                kMerged.Add(spMerged);
                NiStream kStream;
                kStream.InsertObject(spMerged);
                kStream.InsertObject(kInfo.m_spSkin);
                kStream.Save((const char*)StringFormat("D:\\MergedMesh_{0}.nif", i));
            }
        }
    }
}

// @0x1410497c0
void FUN_1410497c0(NiAVObject* pRoot, MeshArray& kSource, MeshArray& kMerged)
{
    if (pRoot != 0)
    {
        MeshGroups kGroups;
        FUN_14104d450(pRoot, kGroups);
        for (unsigned int i = 0; i < kGroups.size(); i++)
        {
            for (unsigned int j = 0; j < kGroups[i].size(); j++)
            {
                kSource.Add(efd::SmartPointer<NiMesh>(kGroups[i][j]));
                OutputDebugStringA((const char*)kGroups[i][j]->GetName());
                OutputDebugStringA(",");
            }
            OutputDebugStringA("\n");
        }
        if (kSource.GetCount() == 0)
            return;
        NiAVObject* pParent = kSource[0]->GetParent();
        for (unsigned int i = 0; i < kGroups.size(); i++)
        {
            MeshGroups kBuckets;
            MergeInfo kInfo;
            FUN_14104e800(kGroups[i], kBuckets, kInfo);
            efd::SmartPointer<NiMesh> spMerged(FUN_14104f460(kBuckets, kInfo, pParent));
            kMerged.Add(spMerged);
            NiStream kStream;
            kStream.InsertObject(spMerged);
            kStream.InsertObject(kInfo.m_spSkin);
            kStream.Save("MergedMesh.nif");
        }
    }
}

// @0x141049b10
void FUN_141049b10(NiAVObject* pRoot, CAtlArray<CString>& kNames, MeshArray& kMerged, CString& strFirstParent)
{
    MeshArray kSource;
    FUN_1410497c0(pRoot, kSource, kMerged);
    kNames.RemoveAll();
    for (unsigned int i = 0; i < kSource.GetCount(); i++)
    {
        efd::SmartPointer<NiMesh>& spMesh = kSource[i];
        kNames.Add(CString((const char*)spMesh->GetName()));
        if (i == 0)
        {
            if (FUN_140a0b000(spMesh) != 0)
                strFirstParent = (const char*)FUN_140a0b000(spMesh)->GetName();
        }
    }
}

// Mesh is skinned, unlit by properties, has no morph modifier and uses a material of kind 2 (0x141049c60).
// @0x141049c60
bool FUN_141049c60(NiMesh* pMesh)
{
    if (pMesh->GetPrimitiveType() == 0)
    {
        if (pMesh->GetProperty(0) == 0)
        {
            if (NiDynamicCast(NiMorphMeshModifier, pMesh->GetModifierByType(&NiMorphMeshModifier::ms_RTTI)) == 0)
            {
                if (NiDynamicCast(NiSkinningMeshModifier, pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI)) != 0)
                {
                    Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, FUN_140a17cd0(pMesh));
                    if (pEntry != 0)
                        return FUN_140ef4dd0(pEntry) == 2;
                }
            }
        }
    }
    return false;
}

// Collects the mergeable meshes of the scene and groups them by parent and property state (0x141049d50).
// @0x141049d50
void FUN_141049d50(NiAVObject* pRoot, MeshGroups& kGroups)
{
    MeshList kMeshes;
    Unk_CubeSceneIterator kIter(pRoot);
    while (NiAVObject* pObject = kIter.FUN_14098e0d0(false))
    {
        if (!FUN_14098dad0(pObject))
        {
            if (!(pObject->GetName() == "Bip01"))
            {
                NiNode* pNode = NiDynamicCast(NiNode, pObject);
                if (pNode == 0)
                {
                    NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
                    if (pMesh != 0 && FUN_141049c60(pMesh))
                        kMeshes.push_back(pMesh);
                }
                else
                {
                    kIter.FUN_14098d6d0(pNode);
                }
            }
        }
    }
    for (MeshList::iterator it = kMeshes.begin(); it != kMeshes.end(); ++it)
    {
        NiMesh* pMesh = *it;
        int iGroup = FUN_141049fa0(pMesh, kGroups);
        if (iGroup == -1)
        {
            kGroups.push_back(MeshList());
            iGroup = (int)kGroups.size() - 1;
        }
        kGroups[iGroup].push_back(pMesh);
    }
}

// Index of the group whose first mesh shares parent and property state with pMesh, or -1 (0x141049fa0).
// @0x141049fa0
int FUN_141049fa0(NiMesh* pMesh, const MeshGroups& kGroups)
{
    for (size_t i = 0; i < kGroups.size(); i++)
    {
        NiMesh* pFirst = kGroups[i][0];
        if (FUN_140a0b000(pFirst) == FUN_140a0b000(pMesh))
        {
            if (FUN_141052aa0(pFirst->GetPropertyState(), pMesh->GetPropertyState()))
                return (int)i;
        }
    }
    return -1;
}

// Total vertex and index counts of all meshes in the groups (0x14104a080).
// @0x14104a080
void FUN_14104a080(const MeshGroups& kGroups, int* pVertices, int* pIndices)
{
    for (MeshGroups::const_iterator itGroup = kGroups.begin(); itGroup != kGroups.end(); ++itGroup)
    {
        const MeshList& kList = *itGroup;
        for (MeshList::const_iterator it = kList.begin(); it != kList.end(); ++it)
        {
            NiMesh* pMesh = *it;
            *pVertices += pMesh->GetVertexCount();
            *pIndices += pMesh->GetCount(0, NiCommonSemantics::INDEX(), 0);
        }
    }
}
// @0x14104a1c0
void FUN_14104a1c0(const MeshList& kGroup, MeshGroups& kBuckets, MergeInfo& kInfo)
{
    ATL::CAtlArray<NiAVObject*> kBones;
    ATL::CAtlArray<NiTransform*> kTransforms;
    ATL::CAtlArray<NiBound*> kBounds;
    NiSkinningMeshModifier* pFirstSkin = 0;
    kBuckets.push_back(MeshList());
    std::vector<std::set<NiAVObject*> > kBucketBones;
    kBucketBones.push_back(std::set<NiAVObject*>());
    std::vector<std::set<unsigned char> > kBucketIndices;
    kBucketIndices.push_back(std::set<unsigned char>());
    NiSyncArgs kArgs;
    kArgs.m_uiSubmitPoint = 0x8000;
    kArgs.m_uiCompletePoint = 0x8000;
    for (unsigned int i = 0; i < kGroup.size(); i++)
    {
        NiMesh* pMesh = kGroup[i];
        NiSkinningMeshModifier* pSkin = (NiSkinningMeshModifier*)pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI);
        NiAVObject** ppBones = pSkin->GetBones();
        NiTransform* pTransforms = pSkin->GetSkinToBoneTransforms();
        NiBound* pBounds = pSkin->GetBoneBounds();
        unsigned int uiBoneCount = pSkin->GetBoneCount();
        pMesh->CompleteModifiers(&kArgs);
        if (pFirstSkin == 0)
            pFirstSkin = pSkin;
        unsigned int uiBucket = 0;
        while (uiBucket < kBucketBones.size())
        {
            if (FUN_141051ee0(kBucketBones[uiBucket], ppBones, uiBoneCount) < 0x3d)
                break;
            uiBucket++;
        }
        if (uiBucket == kBucketBones.size())
        {
            kBuckets.push_back(MeshList());
            kBucketBones.push_back(std::set<NiAVObject*>());
            kBucketIndices.push_back(std::set<unsigned char>());
        }
        kInfo.m_kBoneRemap.insert(std::make_pair(pMesh, std::map<unsigned char, unsigned char>()));
        std::map<unsigned char, unsigned char>& kRemap = kInfo.m_kBoneRemap[pMesh];
        for (unsigned char ucBone = 0; ucBone < uiBoneCount; ucBone++)
        {
            NiAVObject* pBone = ppBones[ucBone];
            unsigned char ucFound = 0;
            while (ucFound < kBones.GetCount())
            {
                if (pBone == kBones[ucFound])
                {
                    if (!(pTransforms[ucBone].m_Translate == kTransforms[ucFound]->m_Translate))
                    {
                        NiPoint3 kDiff = pTransforms[ucBone].m_Translate - kTransforms[ucFound]->m_Translate;
                        Unk_MeshLog(FUN_140166440(), 2, 0x13, L"[MeshOptimizer] Bone {0}의 SkinToBoneTransform이 앞에 설정된 것과 다릅니다 Diff :({1},{2},{3})",
                                    (const char*)pBone->GetName(), kDiff.x, kDiff.y, kDiff.z);
                        kRemap[ucBone] = ucFound;
                    }
                    else
                    {
                        kRemap[ucBone] = ucFound;
                    }
                    break;
                }
                ucFound++;
            }
            if (ucFound == kBones.GetCount())
            {
                kBones.Add(pBone);
                NiTransform* pTransform = &pTransforms[ucBone];
                kTransforms.Add(pTransform);
                NiBound* pBound = &pBounds[ucBone];
                kBounds.Add(pBound);
                kRemap[ucBone] = ucFound;
            }
            kBucketBones[uiBucket].insert(pBone);
            kBucketIndices[uiBucket].insert(ucFound);
        }
        kBuckets[uiBucket].push_back(pMesh);
    }
    unsigned int uiMergedCount = kBones.GetCount();
    NiSkinningMeshModifier* pMerged = NiNew NiSkinningMeshModifier(uiMergedCount);
    pMerged->EnableDynamicBounds();
    NiAVObject** ppMergedBones = pMerged->GetBones();
    NiTransform* pMergedTransforms = pMerged->GetSkinToBoneTransforms();
    NiBound* pMergedBounds = pMerged->GetBoneBounds();
    pMerged->SetRootBoneParent(pFirstSkin->GetRootBoneParent());
    pMerged->SetRootBoneParentToSkinTransform(pFirstSkin->GetRootBoneParentToSkinTransform());
    for (unsigned int i = 0; i < uiMergedCount; i++)
    {
        ppMergedBones[i] = kBones[i];
        pMergedTransforms[i] = *kTransforms[i];
        pMergedBounds[i] = *kBounds[i];
    }
    kInfo.m_spSkin = pMerged;
    for (unsigned int i = 0; i < kBucketIndices.size(); i++)
    {
        kInfo.m_kBoneLists.push_back(std::vector<unsigned char>(kBucketIndices[i].size()));
        std::copy(kBucketIndices[i].begin(), kBucketIndices[i].end(), kInfo.m_kBoneLists[i].begin());
    }
    for (unsigned int i = 0; i < kBucketIndices.size(); i++)
    {
        kInfo.m_kBucketRemap.push_back(std::map<unsigned char, unsigned char>());
        std::vector<unsigned char>& kList = kInfo.m_kBoneLists[i];
        std::map<unsigned char, unsigned char>& kBucketRemap = kInfo.m_kBucketRemap[i];
        for (unsigned char uc = 0; uc < kList.size(); uc++)
            kBucketRemap.insert(std::make_pair(kList[uc], uc));
    }
}

// @0x14104e800
void FUN_14104e800(const MeshList& kGroup, MeshGroups& kBuckets, MergeInfo& kInfo)
{
    ATL::CAtlArray<NiAVObject*> kBones;
    ATL::CAtlArray<NiTransform*> kTransforms;
    ATL::CAtlArray<NiBound*> kBounds;
    NiSkinningMeshModifier* pFirstSkin = 0;
    kBuckets.push_back(MeshList());
    std::vector<std::set<NiAVObject*> > kBucketBones;
    kBucketBones.push_back(std::set<NiAVObject*>());
    std::vector<std::set<unsigned char> > kBucketIndices;
    kBucketIndices.push_back(std::set<unsigned char>());
    NiSyncArgs kArgs;
    kArgs.m_uiSubmitPoint = 0x8000;
    kArgs.m_uiCompletePoint = 0x8000;
    for (unsigned int i = 0; i < kGroup.size(); i++)
    {
        NiMesh* pMesh = kGroup[i];
        NiSkinningMeshModifier* pSkin = (NiSkinningMeshModifier*)pMesh->GetModifierByType(&NiSkinningMeshModifier::ms_RTTI);
        NiAVObject** ppBones = pSkin->GetBones();
        NiTransform* pTransforms = pSkin->GetSkinToBoneTransforms();
        NiBound* pBounds = pSkin->GetBoneBounds();
        unsigned int uiBoneCount = pSkin->GetBoneCount();
        pMesh->CompleteModifiers(&kArgs);
        if (pFirstSkin == 0)
            pFirstSkin = pSkin;
        unsigned int uiBucket = 0;
        while (uiBucket < kBucketBones.size())
        {
            if (FUN_141051ee0(kBucketBones[uiBucket], ppBones, uiBoneCount) < 0x3d)
                break;
            uiBucket++;
        }
        if (uiBucket == kBucketBones.size())
        {
            kBuckets.push_back(MeshList());
            kBucketBones.push_back(std::set<NiAVObject*>());
            kBucketIndices.push_back(std::set<unsigned char>());
        }
        kInfo.m_kBoneRemap.insert(std::make_pair(pMesh, std::map<unsigned char, unsigned char>()));
        std::map<unsigned char, unsigned char>& kRemap = kInfo.m_kBoneRemap[pMesh];
        for (unsigned char ucBone = 0; ucBone < uiBoneCount; ucBone++)
        {
            NiAVObject* pBone = ppBones[ucBone];
            unsigned char ucFound = 0;
            while (ucFound < kBones.GetCount())
            {
                if (pBone == kBones[ucFound])
                {
                    if (!(pTransforms[ucBone].m_Translate == kTransforms[ucFound]->m_Translate))
                    {
                        NiPoint3 kDiff = pTransforms[ucBone].m_Translate - kTransforms[ucFound]->m_Translate;
                        Unk_MeshLog(FUN_140166440(), 2, 0x13, L"[MeshOptimizer] Bone {0}의 SkinToBoneTransform이 앞에 설정된 것과 다릅니다 Diff :({1},{2},{3})",
                                    (const char*)pBone->GetName(), kDiff.x, kDiff.y, kDiff.z);
                        kRemap[ucBone] = ucFound;
                    }
                    else
                    {
                        kRemap[ucBone] = ucFound;
                    }
                    break;
                }
                ucFound++;
            }
            if (ucFound == kBones.GetCount())
            {
                kBones.Add(pBone);
                NiTransform* pTransform = &pTransforms[ucBone];
                kTransforms.Add(pTransform);
                NiBound* pBound = &pBounds[ucBone];
                kBounds.Add(pBound);
                kRemap[ucBone] = ucFound;
            }
            kBucketBones[uiBucket].insert(pBone);
            kBucketIndices[uiBucket].insert(ucFound);
        }
        kBuckets[uiBucket].push_back(pMesh);
    }
    unsigned int uiMergedCount = kBones.GetCount();
    NiSkinningMeshModifier* pMerged = NiNew NiSkinningMeshModifier(uiMergedCount);
    pMerged->EnableDynamicBounds();
    NiAVObject** ppMergedBones = pMerged->GetBones();
    NiTransform* pMergedTransforms = pMerged->GetSkinToBoneTransforms();
    NiBound* pMergedBounds = pMerged->GetBoneBounds();
    pMerged->SetRootBoneParent(pFirstSkin->GetRootBoneParent());
    pMerged->SetRootBoneParentToSkinTransform(pFirstSkin->GetRootBoneParentToSkinTransform());
    for (unsigned int i = 0; i < uiMergedCount; i++)
    {
        ppMergedBones[i] = kBones[i];
        pMergedTransforms[i] = *kTransforms[i];
        pMergedBounds[i] = *kBounds[i];
    }
    kInfo.m_spSkin = pMerged;
    for (unsigned int i = 0; i < kBucketIndices.size(); i++)
    {
        kInfo.m_kBoneLists.push_back(std::vector<unsigned char>(kBucketIndices[i].size()));
        std::copy(kBucketIndices[i].begin(), kBucketIndices[i].end(), kInfo.m_kBoneLists[i].begin());
    }
    for (unsigned int i = 0; i < kBucketIndices.size(); i++)
    {
        kInfo.m_kBucketRemap.push_back(std::map<unsigned char, unsigned char>());
        std::vector<unsigned char>& kList = kInfo.m_kBoneLists[i];
        std::map<unsigned char, unsigned char>& kBucketRemap = kInfo.m_kBucketRemap[i];
        for (unsigned char uc = 0; uc < kList.size(); uc++)
            kBucketRemap.insert(std::make_pair(kList[uc], uc));
    }
}


// Size the bone set would have after adding the bones (0x141051ee0).
// @0x141051ee0
int FUN_141051ee0(std::set<NiAVObject*>& kBones, NiAVObject** ppBones, unsigned int uiCount)
{
    int iSize = (int)kBones.size();
    for (unsigned char uc = 0; uc < uiCount; uc++)
    {
        NiAVObject* pBone = ppBones[uc];
        if (kBones.find(pBone) == kBones.end())
            iSize++;
    }
    return iSize;
}

// Builds the merged mesh of one group: concatenated indices and vertices, one submesh per bone bucket (0x14104ae20).
// @0x14104ae20
NiMesh* FUN_14104ae20(const MeshGroups& kBuckets, MergeInfo& kInfo, NiAVObject* pRoot)
{
    unsigned int uiBucketCount = (unsigned int)kBuckets.size();
    int iVertices = 0;
    int iIndices = 0;
    FUN_14104a080(kBuckets, &iVertices, &iIndices);
    if (iVertices == 0)
        return 0;

    NiMesh* pMerged = NiNew NiMesh;
    NiMesh* pFirst = kBuckets[0][0];
    NiTransform kRootTransform = pRoot->GetWorldTransform();
    pMerged->SetPrimitiveType(pFirst->GetPrimitiveType());
    pMerged->SetSubmeshCount((unsigned int)kBuckets.size());
    FUN_14104b530(pMerged, kBuckets);
    FUN_14104bbb0(pMerged, kInfo, kBuckets, kRootTransform);

    if (kInfo.m_spSkin != 0)
    {
        unsigned int uiMaxBones = 0;
        unsigned int uiTotalBones = 0;
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            unsigned int uiBones = (unsigned int)kInfo.m_kBoneLists[i].size();
            if (uiMaxBones < uiBones)
                uiMaxBones = uiBones;
            uiTotalBones += uiBones;
        }
        unsigned short* pPalette = (unsigned short*)_malloca(uiMaxBones * uiBucketCount * sizeof(unsigned short));
        unsigned short* pOut = pPalette;
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            const std::vector<unsigned char>& kList = kInfo.m_kBoneLists[i];
            for (unsigned int j = 0; j < kList.size(); j++)
                *pOut++ = kList[j];
            for (unsigned int j = (unsigned int)kList.size(); j < uiMaxBones; j++)
                *pOut++ = 0;
        }
        int iPaletteCount = uiMaxBones * uiBucketCount;
        NiDataStreamRef* pRef = pMerged->AddStream(NiCommonSemantics::BONE_PALETTE(), 0, NiDataStreamElement::F_UINT16_1, iPaletteCount,
                                                   3, NiDataStream::USAGE_USER, pPalette, false, true);
        _freea(pPalette);
        pRef->SetSubmeshCount(uiBucketCount, 0);
        for (unsigned int i = 0; i < uiBucketCount; i++)
        {
            NiDataStream::Region kRegion(i * uiMaxBones, uiMaxBones);
            if (i == 0)
                pRef->GetDataStream()->SetRegion(kRegion, 0);
            else
                pRef->GetDataStream()->AddRegion(kRegion);
            pRef->BindRegionToSubmesh(i, i);
        }
    }

    NiBound kBound = pFirst->GetModelBound();
    for (unsigned int i = 0; i < kBuckets.size(); i++)
    {
        const MeshList& kList = kBuckets[i];
        for (unsigned int j = 0; j < kList.size(); j++)
            kBound.Merge(&kList[j]->GetModelBound());
    }
    pMerged->SetModelBound(kBound);
    pMerged->AddModifier(kInfo.m_spSkin, true);
    pMerged->AttachProperty(pFirst->GetProperty(8));
    pMerged->SetName(NiFixedString("MergedMesh"));
    for (unsigned int i = 0; i < 12; i++)
    {
        if (i != 8)
        {
            NiProperty* pProperty = pFirst->GetProperty(i);
            if (pProperty != 0)
                pMerged->AttachProperty(pProperty);
        }
    }
    pMerged->ApplyAndSetActiveMaterial(FUN_140a17cd0(pFirst), 0xffffffff);
    unsigned short usExtra = pFirst->GetExtraDataSize();
    for (unsigned short us = 0; us < usExtra; us++)
        pMerged->AddExtraData(pFirst->GetExtraDataAt(us));
    pMerged->SetEffectState(pFirst->GetEffectState());
    pMerged->UpdateProperties();
    pMerged->CompleteUpdateModifiers();
    pMerged->UpdateEffects();
    pMerged->Update(0.0, true);
    return pMerged;
}

// Copies the 16- or 32-bit indices of one source mesh into the merged index buffer, rebased by the vertex offset (0x14104ba70).
// @0x14104ba70
void FUN_14104ba70(unsigned int** ppDst, NiDataStreamRef* pRef, unsigned int uiCount, int iVertexOffset, bool b32)
{
    if (pRef != 0 && uiCount != 0)
    {
        NiDataStream* pStream = pRef->GetDataStream();
        unsigned short* pSrc = (unsigned short*)pStream->Lock(5);
        if (!b32)
        {
            unsigned short* pIn = pSrc;
            for (unsigned int i = 0; i < uiCount; i++)
            {
                **ppDst = *pIn + iVertexOffset;
                (*ppDst)++;
                pIn++;
            }
        }
        else
        {
            for (unsigned int i = 0; i < uiCount; i++)
            {
                **ppDst = *(int*)pSrc + iVertexOffset;
                (*ppDst)++;
                pSrc += 2;
            }
        }
        pRef->GetDataStream()->Unlock(5);
    }
}

// Concatenates the index streams of all groups into one 32-bit stream with a region per group (0x14104b530).
// @0x14104b530
void FUN_14104b530(NiMesh* pMerged, const MeshGroups& kBuckets)
{
    unsigned int uiTotal = 0;
    for (const MeshList& kList : kBuckets)
        for (NiMesh* pMesh : kList)
            uiTotal += pMesh->GetCount(0, NiCommonSemantics::INDEX(), 0);

    NiDataStreamRef* pRef = pMerged->AddStream(NiCommonSemantics::INDEX(), 0, NiDataStreamElement::F_UINT32_1, uiTotal, 0x12,
                                               NiDataStream::USAGE_VERTEX_INDEX, 0, false, true);
    unsigned int* pDst = (unsigned int*)pRef->GetDataStream()->LockWrite();
    int iVertexOffset = 0;
    for (const MeshList& kList : kBuckets)
    {
        for (NiMesh* pMesh : kList)
        {
            unsigned int uiCount = pMesh->GetCount(0, NiCommonSemantics::INDEX(), 0);
            unsigned int uiVertices = pMesh->GetVertexCount();
            FUN_14104ba70(&pDst, pMesh->FindStreamRef(NiCommonSemantics::INDEX(), 0, NiDataStreamElement::F_UINT16_1), uiCount, iVertexOffset, false);
            FUN_14104ba70(&pDst, pMesh->FindStreamRef(NiCommonSemantics::INDEX(), 0, NiDataStreamElement::F_UINT32_1), uiCount, iVertexOffset, true);
            iVertexOffset += uiVertices;
        }
    }
    pRef->GetDataStream()->UnlockWrite();

    unsigned int uiBucketCount = (unsigned int)kBuckets.size();
    pRef->SetSubmeshCount(uiBucketCount, 0);
    int iStart = 0;
    for (unsigned int i = 0; i < uiBucketCount; i++)
    {
        int iCount = 0;
        for (NiMesh* pMesh : kBuckets[i])
            iCount += pMesh->GetCount(0, NiCommonSemantics::INDEX(), 0);
        NiDataStream::Region kRegion(iStart, iCount);
        if (i == 0)
            pRef->GetDataStream()->SetRegion(kRegion, 0);
        else
            pRef->GetDataStream()->AddRegion(kRegion);
        iStart += iCount;
        pRef->BindRegionToSubmesh(i, i);
    }
}

// Same offset and format as the invalid element placeholder (the exe compares the two fields in the inline operator==).
inline bool Unk_IsInvalidElement(const NiDataStreamElement& kElement)
{
    return kElement.GetOffset() == NiDataStreamElement::ms_kInvalidElement.GetOffset() &&
           kElement.GetFormat() == NiDataStreamElement::ms_kInvalidElement.GetFormat();
}

// Appends the element of (semantic, index) to the merged layout if all source streams agree on its format; 0x10 on a mismatch (0x14104c870).
// @0x14104c870
int FUN_14104c870(std::vector<Unk_StreamElementDesc>& kLayout, const std::vector<NiDataStreamRef*>& kSources, const NiFixedString& kSemantic, unsigned int uiIndex)
{
    int iFormat = 0;
    for (NiDataStreamRef* pSource : kSources)
    {
        const NiDataStreamElement& kElement = pSource->FindElementDesc(kSemantic, uiIndex);
        if (!Unk_IsInvalidElement(kElement))
        {
            if (iFormat != 0 && iFormat != kElement.GetFormat())
                return 0x10;
            iFormat = kElement.GetFormat();
        }
    }
    if (iFormat != 0)
        kLayout.push_back(Unk_StreamElementDesc(kSemantic, uiIndex, (NiDataStreamElement::Format)iFormat));
    return iFormat;
}

// Index of the first vertex-usage stream of the mesh, or none (0x14104cc20).
// @0x14104cc20
NiDataStreamRef* FUN_14104cc20(NiMesh* pMesh)
{
    unsigned int uiCount = pMesh->GetStreamRefCount();
    for (unsigned int i = 0; i < uiCount; i++)
    {
        NiDataStreamRef* pRef = pMesh->GetStreamRefAt(i);
        if (pRef->GetUsage() == NiDataStream::USAGE_VERTEX)
            return pRef;
    }
    return 0;
}

// Creates the merged vertex stream and its stream ref for the layout (0x14104c9e0).
// @0x14104c9e0
NiDataStreamRef* FUN_14104c9e0(const std::vector<Unk_StreamElementDesc>& kLayout, unsigned int uiVertexCount)
{
    NiDataStreamElementSet kElements;
    for (const Unk_StreamElementDesc& kDesc : kLayout)
        kElements.AddElement(kDesc.m_eFormat);
    NiDataStream* pStream = NiDataStream::CreateDataStream(kElements, uiVertexCount, 0x13, NiDataStream::USAGE_VERTEX, false);
    NiDataStream::Region kRegion(0, uiVertexCount);
    pStream->AddRegion(kRegion);
    NiDataStreamRef* pRef = NiNew NiDataStreamRef;
    pRef->SetPerInstance(true);
    pRef->SetSubmeshCount(1, 0xffff);
    pRef->SetDataStream(pStream);
    for (unsigned int i = 0; i < kLayout.size(); i++)
        pRef->BindSemanticToElementDescAt(i, kLayout[i].m_kSemantic, kLayout[i].m_uiIndex);
    return pRef;
}

// @0x14104cc90
CCharacterMeshMerger::TexNode::TexNode(unsigned int uiLeft, unsigned int uiTop, unsigned int uiRight, unsigned int uiBottom)
    : m_kRect(0, 0, 0, 0)
{
    m_spChild[0] = 0;
    m_spChild[1] = 0;
    m_spTexture = 0;
    m_kRect.m_left = uiLeft;
    m_kRect.m_top = uiTop;
    m_kRect.m_right = uiRight;
    m_kRect.m_bottom = uiBottom;
}

// Builds the merged vertex stream: checks that all meshes agree on the vertex layout, then copies every element, transforming
// positions/normals into the merged space and remapping bone indices (0x14104bbb0).
// @0x14104bbb0
void FUN_14104bbb0(NiMesh* pMerged, MergeInfo& kInfo, const MeshGroups& kBuckets, const NiTransform& kRootTransform)
{
    int iVertexTotal = 0;
    std::vector<NiDataStreamRef*> kSources;
    for (const MeshList& kList : kBuckets)
    {
        for (NiMesh* pMesh : kList)
        {
            iVertexTotal += pMesh->GetVertexCount();
            NiDataStreamRef* pSource = FUN_14104cc20(pMesh);
            if (pSource == 0)
                pMesh->GetVertexCount();
            else
                kSources.push_back(pSource);
        }
    }

    std::vector<Unk_StreamElementDesc> kLayout;
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::POSITION(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::NORMAL(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BINORMAL(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::TANGENT(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::POSITION_BP(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::NORMAL_BP(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BINORMAL_BP(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::TANGENT_BP(), 0);
    for (unsigned int uiSet = 0; uiSet < 8; uiSet++)
        FUN_14104c870(kLayout, kSources, NiCommonSemantics::TEXCOORD(), uiSet);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BLENDWEIGHT(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BLENDINDICES(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BONEMATRICES(), 0);
    FUN_14104c870(kLayout, kSources, NiCommonSemantics::BONE_PALETTE(), 0);

    NiDataStreamRef* pMergedRef = FUN_14104c9e0(kLayout, iVertexTotal);
    int iDstStride = pMergedRef->GetStride();
    int iVertexBase = 0;
    unsigned char* pDst = (unsigned char*)pMergedRef->GetDataStream()->Lock(10);
    for (unsigned int uiBucket = 0; uiBucket < kBuckets.size(); uiBucket++)
    {
        for (NiMesh* pMesh : kBuckets[uiBucket])
        {
            NiTransform kInverseParent;
            NiTransform kParentWorld = pMesh->GetParent()->GetWorldTransform();
            kParentWorld.Invert(kInverseParent);
            NiTransform kLocalToRoot = pMesh->GetLocalTransform() * kRootTransform;
            NiTransform kXform = kLocalToRoot * kInverseParent;

            NiDataStreamRef* pSourceRef = FUN_14104cc20(pMesh);
            unsigned char* pSrc = (unsigned char*)pSourceRef->GetDataStream()->Lock(5);
            int iDstOffset = 0;
            int iSrcStride = pSourceRef->GetStride();
            for (const Unk_StreamElementDesc& kDesc : kLayout)
            {
                const NiDataStreamElement& kElement = pSourceRef->FindElementDesc(kDesc.m_kSemantic, kDesc.m_uiIndex);
                size_t stSize = NiDataStreamElement::SizeOfFormat(kDesc.m_eFormat);
                if (!Unk_IsInvalidElement(kElement))
                {
                    int iSrcOffset = kElement.GetOffset();
                    std::map<unsigned char, unsigned char>& kMeshRemap = kInfo.m_kBoneRemap[pMesh];
                    std::map<unsigned char, unsigned char>& kBucketRemap = kInfo.m_kBucketRemap[uiBucket];
                    if (kDesc.m_kSemantic == NiCommonSemantics::BLENDINDICES())
                    {
                        for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                        {
                            for (unsigned int c = 0; c < 4; c++)
                            {
                                unsigned char ucOld = pSrc[c + v * iSrcStride + iSrcOffset];
                                unsigned char ucMerged = kMeshRemap[ucOld];
                                unsigned char ucBucket = kBucketRemap[ucMerged];
                                pDst[c + (v + iVertexBase) * iDstStride + iDstOffset] = ucBucket;
                            }
                        }
                    }
                    else if (kDesc.m_kSemantic == NiCommonSemantics::POSITION_BP())
                    {
                        for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                        {
                            NiPoint3* pIn = (NiPoint3*)(pSrc + v * iSrcStride + iSrcOffset);
                            NiPoint3* pOut = (NiPoint3*)(pDst + (v + iVertexBase) * iDstStride + iDstOffset);
                            *pOut = kXform * *pIn;
                        }
                    }
                    else if (kDesc.m_kSemantic == NiCommonSemantics::NORMAL_BP())
                    {
                        for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                        {
                            NiPoint3* pIn = (NiPoint3*)(pSrc + v * iSrcStride + iSrcOffset);
                            NiPoint3* pOut = (NiPoint3*)(pDst + (v + iVertexBase) * iDstStride + iDstOffset);
                            *pOut = kXform.m_Rotate * *pIn;
                        }
                    }
                    else
                    {
                        for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                            NiMemcpy(pDst + (v + iVertexBase) * iDstStride + iDstOffset, pSrc + v * iSrcStride + iSrcOffset, stSize);
                    }
                }
                else
                {
                    for (unsigned int v = 0; v < pMesh->GetVertexCount(); v++)
                        memset(pDst + (v + iVertexBase) * iDstStride + iDstOffset, 0, stSize);
                }
                iDstOffset += (int)NiDataStreamElement::SizeOfFormat(kDesc.m_eFormat);
            }
            pSourceRef->GetDataStream()->Unlock(5);
            iVertexBase += pMesh->GetVertexCount();
        }
    }
    pMergedRef->GetDataStream()->Unlock(10);

    pMergedRef->SetSubmeshCount((unsigned int)kBuckets.size(), 0);
    int iStart = 0;
    for (unsigned int i = 0; i < kBuckets.size(); i++)
    {
        int iCount = 0;
        const MeshList& kList = kBuckets[i];
        for (unsigned int j = 0; j < kList.size(); j++)
            iCount += kList[j]->GetVertexCount();
        NiDataStream::Region kRegion(iStart, iCount);
        if (i == 0)
            pMergedRef->GetDataStream()->SetRegion(kRegion, 0);
        else
            pMergedRef->GetDataStream()->AddRegion(kRegion);
        iStart += iCount;
        pMergedRef->BindRegionToSubmesh(i, i);
    }
    pMerged->AddStreamRef(pMergedRef);
    // the exe releases its extra reference to the temporary ref afterwards
    NiDelete pMergedRef;
}
