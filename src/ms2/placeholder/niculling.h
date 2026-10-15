// niculling.h - PLACEHOLDER for Gamebryo's NiCullingProcess / NiSPWorkflowManager (engine/gamebryo/.../NiMain), because the
// CoreRuntime include dirs are not on the ms2game / progress.py path. NOT an original header.
// NiCullingProcess : NiRefObject, sizeof 0xc0 (members m_pkVisibleSet 0x18, m_pkWorkflowManager 0x20, m_pkCamera 0x28,
// m_pkLODCamera 0x30; the frustum/planes tail is opaque). Virtual slots (MSVC reverses same-name overloads, so the
// exe order is Process(NiAVObject*), Process(list), Process(scene)): 0 dtor, 1 DeleteThis, 2 GetRTTI, 3 Process(NiAVObject*),
// 4 Process(camera, list, visible), 5 Process(camera, scene, visible), 6 PreProcess, 7 PostProcess, 8 AppendVirtual.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"
#include "ms2/placeholder/ninode.h"

class NiAVObject;
class NiCamera;
class NiVisibleArray;
class NiRenderObject;
class NiFrustum;
template <class T> class NiTPointerList;

// NiSPWorkflowManager: 0x38 bytes, MemObject with a virtual dtor (ctor 0x141cfbd30, FlushTaskGroup 0x141cfcbf0).
class NiSPWorkflowManager : public efd::MemObject {
public:
    NiSPWorkflowManager(unsigned short a, int b, unsigned int c);   // 0x141cfbd30
    virtual ~NiSPWorkflowManager();
    void FlushTaskGroup(unsigned int a, unsigned int b);            // 0x141cfcbf0
    void* m_08[6];
};
MS2_CHECK_SIZE(NiSPWorkflowManager, 0x38);

class NiCullingProcess : public NiRefObject {
public:
    NiCullingProcess(NiVisibleArray* pkVisibleSet, NiSPWorkflowManager* pkWorkflowManager);                      // 0x141d53c30
    NiCullingProcess(NiVisibleArray* pkVisibleSet, NiSPWorkflowManager* pkWorkflowManager, bool bUseVirtualAppend); // 0x141d53d10
    virtual ~NiCullingProcess();                                    // 0x141d53df0
    virtual const NiRTTI* GetRTTI() const;
    virtual void Process(const NiCamera* pkCamera, NiAVObject* pkScene, NiVisibleArray* pkVisibleSet);                  // 0x141d54110
    virtual void Process(const NiCamera* pkCamera, NiTPointerList<NiAVObject*>* pkSceneList, NiVisibleArray* pkVisibleSet);
    virtual void PreProcess();
    virtual void PostProcess();
    virtual void AppendVirtual(NiRenderObject&) {}
    virtual void Process(NiAVObject* pkObject);                     // 0x141d53f30
    void SetFrustum(const NiFrustum& kFrustum);                     // 0x141d541e0

    static const NiRTTI ms_RTTI;                                    // 0x143afaf20

    bool m_bUseVirtualAppend;                                       // +0x10
    NiVisibleArray* m_pkVisibleSet;                                 // +0x18
    NiSPWorkflowManager* m_pkWorkflowManager;                       // +0x20
    const NiCamera* m_pkCamera;                                     // +0x28
    const NiCamera* m_pkLODCamera;                                  // +0x30
    char m_tail[0x88];                                              // frustum, planes, flags
};
MS2_CHECK_SIZE(NiCullingProcess, 0xc0);
