#pragma once
#include <map>
#include <vector>
#include <NiNode.h>
#include <efd/AssetID.h>
#include <NiMesh.h>
#include <NiMeshHWInstance.h>
#include <egf/Entity.h>
#include "ms2/ms2layout.h"

MS2_CHECK_SIZE(NiMeshHWInstance, 0xf8);

// Heap-only configuration view, copied by 14147d4b0; trailing count at +0x68.
struct Unk_MeshInstancingConfig {
    efd::AssetID asset;
    bool flags30, flags31, flags32;
    unsigned unknown34;
    unsigned __int64 unknown38, unknown40;
    float unknown48, unknown4c, unknown50, unknown54;
    NiPoint3 unknown58;
    unsigned unknown64;
    int activeCount;
};
MS2_CHECK_SIZE(Unk_MeshInstancingConfig, 0x70);
struct Unk_MeshInstanceEntry {
    egf::Entity* entity;
    NiPointer<NiNode> clone;
    NiPointer<NiNode> original;
    efd::vector<NiPointer<NiMeshHWInstance>> instances;
};
MS2_CHECK_SIZE(Unk_MeshInstanceEntry, 0x30);

// Constructor 14147be60, destructor 14147bf70. The constructor's last field
// is the mode at +0xd0; EntityInstancing begins its own list at +0xd8.
class MeshInstancing {
public:
    MeshInstancing(const Unk_MeshInstancingConfig&, int);
    virtual ~MeshInstancing();
    virtual void vfunc_1();
    void FUN_14147c010(egf::Entity*, unsigned, unsigned, NiTransform*, bool);
    NiMesh* FUN_14147ce70(const NiFixedString&);
    efd::SmartPointer<egf::Entity> source;
    egf::EntityID id10, id18;
    unsigned capacity;
    bool unknown24, dirty, flag26, flag27, flag28, ready, flag2a, flag2b;
    NiPointer<NiNode> root;
    Unk_MeshInstancingConfig config;
    efd::vector<NiMesh*> meshes;
    std::map<egf::EntityID, Unk_MeshInstanceEntry> entries;
    int mode;
};
MS2_CHECK_SIZE(MeshInstancing, 0xd8);
MS2_CHECK_OFFSET(MeshInstancing, dirty, 0x25);
MS2_CHECK_OFFSET(MeshInstancing, root, 0x30);
MS2_CHECK_OFFSET(MeshInstancing, config, 0x38);
MS2_CHECK_OFFSET(MeshInstancing, meshes, 0xa8);
MS2_CHECK_OFFSET(MeshInstancing, entries, 0xc0);
