// layer.h - Layer / LayerManager: NiObject-based "layer" system of the renderer (chaos light layers, texture layers).
// A LayerManager owns, per scene node, the list of layers applied to it; subclasses create the layers (vfunc_18).
// Owning unit of the bases: the 0x141443xxx layer unit (ctor 0x141443550, vfunc_19/20 0x1414435a0/0x1414435b0,
// LayerManager::vfunc_18 0x141443f80); the inline dtors and LayerManager ctor/dtor are emitted in
// ?\chaoslighttransitiondata.cpp (chaoslighteffect.h). Header name assumed. Member names are invented from use.
#pragma once
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include <NiObject.h>
#include <NiAVObject.h>
#include <NiSmartPointer.h>

// Vftable 0x142f13990 (21 slots: the 18 NiObject slots, then 18 pure, 19 and 20 empty). 0x18 bytes.
class Layer : public NiObject
{
public:
    explicit Layer(unsigned int nId);                   // 0x141443550 stores the id at +0x10
    virtual ~Layer() = default;                                 // inline: 0x141047370 (calls ~NiObject), ??_G 0x141446200
    virtual NiAVObject* vfunc_18() = 0;                 // 18 pure: the scene node the layer is applied to
    virtual void vfunc_19();                            // 19 0x1414435a0 {} apply the layer
    virtual void vfunc_20();                            // 20 0x1414435b0 {} remove the layer
    int GetId() const;                                  // 0x1414435c0 (non-virtual, invented name)
public:
    unsigned int m_nId;             // +0x10 (-1: none; the chaos light layer takes it from the param's "layer")
};
MS2_CHECK_SIZE(Layer, 0x18);
typedef NiPointer<Layer> LayerPtr;

// The layers applied to one scene node: the node the layers were created for and the layer list.
struct LayerEntry
{
    LayerEntry();                                       // 0x1414435e0
    explicit LayerEntry(NiObjectNET* pNode);            // 0x141443640
    void AddLayer(Layer* pLayer);                       // 0x1414436a0 insert sorted by id; the top (highest id) layer is the active one
    void Refresh(Layer* pLayer);                        // 0x1414438e0 re-apply when pLayer is the active layer
    void RemoveLayer(Layer* pLayer);                    // 0x141443930
    Layer* GetTop();                              // 0x141443a90 last element or null
    NiPointer<NiObjectNET> m_spNode;                     // +0x00
    std::vector<NiPointer<Layer> > m_vecLayers;         // +0x08
};
MS2_CHECK_SIZE(LayerEntry, 0x20);

// 0x20 bytes. Vftable 0x142ea3318 (19 slots; 18 returns an empty pointer by default).
class LayerManager : public NiObject
{
public:
    LayerManager();                                     // 0x1410470b0
    virtual ~LayerManager() = default;                          // implicit: 0x1410473c0, ??_G 0x141047790
    virtual NiPointer<Layer> vfunc_18(NiAVObject* pObject);   // 18 0x141443f80 create the layer for a node (base: null)
    void AddLayer(Layer* pLayer);                       // 0x141443af0 (invented names below)
    void Refresh(Layer* pLayer);                        // 0x141443ce0
    void RemoveLayer(Layer* pLayer);                    // 0x141443da0
    void RemoveNode(NiObjectNET* pNode);                // 0x141443e60
    void Clear();                                       // 0x141443f00
    bool IsEmpty() const;                               // 0x141443f30
public:
    std::map<NiPointer<NiObjectNET>, LayerEntry> m_mapLayers;    // +0x10
};
MS2_CHECK_SIZE(LayerManager, 0x20);
