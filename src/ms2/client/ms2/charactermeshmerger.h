// Character mesh merger (render subsystem): merges the skinned NiMeshes of a character into one NiMesh per material
// group and packs the character textures into an atlas.
//   CCharacterMeshMerger::TexNode   binary-tree texture atlas node (0x38 bytes, NiRefObject)
//   MeshList / MeshGroups           meshes that share a parent and property state, and the list of such groups
// All other exe functions of the unit are free/static helpers declared in charactermeshmerger.cpp.
// Owning unit: client\ms2\charactermeshmerger.cpp (0x141049240-0x141064d70, dir client\ms2).
#pragma once
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include <vector>
#include <map>
#include <set>
#include <atlcoll.h>
#include <efd/StdContainers.h>
#include <efd/SmartPointer.h>
#include <NiRefObject.h>
#include <NiRect.h>

class NiMesh;
class NiTexture;

typedef efd::vector<NiMesh*> MeshList;
typedef efd::vector<MeshList> MeshGroups;

class CCharacterMeshMerger
{
public:
    class TexNode : public NiRefObject
    {
    public:
        TexNode(unsigned int uiLeft, unsigned int uiTop, unsigned int uiRight, unsigned int uiBottom);   // 0x14104cc90

        TexNode* Insert(NiTexture* pTexture);                // 0x14104cdc0, first free leaf that fits the texture, or NULL

        efd::SmartPointer<TexNode> m_spChild[2];            // +0x10
        NiRect<unsigned int> m_kRect;                       // +0x20 left, right, top, bottom
        efd::SmartPointer<NiTexture> m_spTexture;           // +0x30
    };
};
MS2_CHECK_SIZE(CCharacterMeshMerger::TexNode, 0x38);
