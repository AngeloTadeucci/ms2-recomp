// ms2lightservice.h - MS2LightService (RTTI .?AVMS2LightService@@): the game's subclass of the engine's ecr::LightService.
// The exe's ecr::LightService is MS2-modified: when a light entity is added it only hands the entity id to a callback
// (see ms2/placeholder/ecrlightservice.h); MS2LightService queues those ids and creates the lights in one batch when the
// world finishes loading (IWorldServiceCallback slot 1), then turns automatic relighting off when the map has more
// point / spot / directional lights than an object can take. It also keeps the "light shadow" choice of every light per
// the graphics option, and scales the intensity of the lights of the map (the skill / stun screen effects).
// Bases: ecr::LightService (members end at 0x148), egf::IPropertyCallback (+0x148), IWorldServiceCallback (+0x150),
// TSingleton<MS2LightService> (+0x158). Recovered from MapleStory2.exe KMS2_DEV x64; owning unit `?\ms2lightservice.cpp`
// (0x1414bfc40-0x1414cf940, .text$di 0x1400f8d70-0x1400f8ee0, dir client\ms2).
#pragma once

#include "ms2/ms2layout.h"
#include <efd/SmartPointer.h>
#include <efd/StdContainers.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <egf/EntityChangeMessage.h>
#include <egf/IPropertyCallback.h>
#include <ecr/LightService.h>
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/ecrlightservice.h"

class MS2LightService;
template <class T> class TSingleton;
template <> class TSingleton<MS2LightService>
{
public:
    TSingleton();                                       // 0x1414c6fb0 (inline, ms2lightservice.cpp)
    virtual ~TSingleton() { s_instance = 0; }           // 0x1414c7af0
    static MS2LightService* s_instance;                 // 0x143ad95f0
};

class MS2LightService : public ecr::LightService, public egf::IPropertyCallback, public IWorldServiceCallback,
    public TSingleton<MS2LightService>
{
public:
    MS2LightService();                                                  // 0x1414bfc40
    virtual ~MS2LightService();                                         // 0x1414bfd40, ??_G 0x1414c9040
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar);     // 0x1414bfe10
    virtual efd::AsyncResult OnInit();                                  // 0x1414bfe80
    virtual efd::AsyncResult OnTick();                                  // 0x1414bfee0
    virtual void OnPropertyUpdate(const efd::ClassID& callerID, egf::Entity* pEntity, const egf::PropertyID& propertyID,
        const egf::IProperty* pProperty, const efd::UInt32 tags);      // 0x1414c0000

    // IWorldServiceCallback
    virtual void vfunc_0(int nMap);                                     // 0x1414c00f0 world load starts: queue new lights
    virtual void vfunc_1(int nMap);                                     // 0x1414c0400 world loaded: create the queued lights
    virtual void vfunc_3(int nMap);                                     // 0x1414c0120 world unloads: drop every light
    virtual void vfunc_5(int nMap);                                     // 0x1414c0440

    // Queues a light entity id; the light added callback while a world loads.
    static void QueueLight(const egf::EntityID& entityID);              // 0x1414bffd0
    void UpdateRelightingMode();                                        // 0x1414c0450 relighting off when too many lights
    void UpdateLightShadows();                                          // 0x1414c05d0 UpdateLightShadow for every light
    void UpdateLightShadow(egf::Entity* pEntity);                       // 0x1414c0670
    void RequestSortedRelight();                                        // 0x1414c0800 next tick relights the whole scene
    void ScaleLightIntensity(float fScale);                             // 0x1414c0820
    // kMSGID_OwnedEntityEnterWorld / ExitWorld: remember (and dim) the intensity of every light entering the world.
    void HandleEntityEnterWorld(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel);   // 0x1414c08e0
    void HandleEntityExitWorld(const egf::EntityChangeMessage* pMessage, efd::Category targetChannel);    // 0x1414c0af0
    // The engine's OnRenderedEntityRemoved, called by the instancing code when it swaps a scene graph out.
    void RemoveRenderedEntity(egf::Entity* pEntity, NiAVObject* pAVObject);   // 0x1414c0bb0
    bool CreateQueuedLights();                                          // 0x1414c0d60

public:
    efd::map<egf::EntityID, bool> m_lightShadow;                        // +0x160 light entity -> its own "shadow" value
    efd::map<egf::EntityPtr, float> m_lightIntensity;                   // +0x170 light entity -> its base intensity
    bool m_bSortedRelight;                                              // +0x180 relight everything along the default axis
};
MS2_CHECK_SIZE(MS2LightService, 0x188);
MS2_CHECK_OFFSET(MS2LightService, m_lightShadow, 0x160);
MS2_CHECK_OFFSET(MS2LightService, m_lightIntensity, 0x170);
MS2_CHECK_OFFSET(MS2LightService, m_bSortedRelight, 0x180);
