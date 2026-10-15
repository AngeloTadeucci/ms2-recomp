#pragma once
#include <list>
#include <map>
#include <vector>
#include <NiNode.h>
#include <efd/AssetID.h>
#include <NiMesh.h>
#include <NiMeshHWInstance.h>
#include <egf/Entity.h>
#include "ms2/ms2layout.h"

MS2_CHECK_SIZE(NiMeshHWInstance, 0xf8);

struct Unk_MeshInstancingVec4 { float x, y, z, w; };
// Heap-only configuration view, copied by 14147d4b0; trailing count at +0x68.
struct Unk_MeshInstancingConfig {
    Unk_MeshInstancingConfig(const Unk_MeshInstancingConfig&);  // 0x14147d4b0
    efd::AssetID asset;
    bool flags30, flags31, flags32;
    unsigned unknown34;
    std::list<egf::EntityID> ids;
    Unk_MeshInstancingVec4 unknown48;
    NiPoint3 unknown58;
    unsigned unknown64;
    int activeCount;
};
MS2_CHECK_SIZE(Unk_MeshInstancingConfig, 0x70);
struct Unk_MeshInstanceEntry {
    Unk_MeshInstanceEntry() : entity(NULL), clone(NULL), original(NULL) {}   // 0x141196260
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
    void FUN_14147c730(double);
    void FUN_14147c830();
    void FUN_14147c910(double);
    void FUN_14147ca20(bool);
    void FUN_14147caa0();
    void FUN_14147cbc0();
    void FUN_14147ccf0();
    bool FUN_14147cde0(const egf::EntityID&);
    NiMesh* FUN_14147ce70(const NiFixedString&);
    unsigned FUN_14147cf40();
    int FUN_14147cf90(const Unk_MeshInstancingConfig&);
    int FUN_14147cfd0(const Unk_MeshInstancingConfig&);
    bool FUN_14147d010(egf::Entity*);
    void FUN_14147d0c0(bool);
    void FUN_14147d180(bool);
    NiNode* FUN_14147d200(egf::Entity*);
    void FUN_14147d290();
    void* FUN_14147d2f0(void* out, void* a, void* b);
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
