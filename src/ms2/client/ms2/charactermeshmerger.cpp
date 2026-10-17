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
const NiMaterial* FUN_140a17cd0(NiMesh* pMesh);         // active material
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
