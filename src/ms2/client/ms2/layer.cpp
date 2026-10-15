// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Layer / LayerManager: the per-scene-node layer lists
// (sorted by layer id; the highest id is the active layer) and the std::map / std::vector COMDATs they instantiate.
// MS2-UNIT: ?\layer.cpp
// MS2-RANGE: 0x141443550-0x141447080 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\layer.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "layer.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x141443550
Layer::Layer(unsigned int nId)
{
    m_nId = nId;
}

// @0x1414435a0
void Layer::vfunc_19()
{
}
MS2_REPLACE_METHOD(0x1414435A0, Layer, vfunc_19, 6, 0xA9AF6E37);

// @0x1414435b0
void Layer::vfunc_20()
{
}
MS2_REPLACE_METHOD(0x1414435B0, Layer, vfunc_20, 6, 0xA9AF6E37);

// @0x1414435c0
int Layer::GetId() const
{
    return m_nId;
}
MS2_REPLACE_METHOD(0x1414435C0, Layer, GetId, 14, 0xC2D0886F);

// @0x1414435e0
LayerEntry::LayerEntry()
{
    m_spNode = 0;
}

// @0x141443640
LayerEntry::LayerEntry(NiObjectNET* pNode)
{
    m_spNode = pNode;
}

// @0x1414436a0
void LayerEntry::AddLayer(Layer* pLayer)
{
    Layer* pTop = GetTop();
    if (pTop == 0)
    {
        m_vecLayers.push_back(pLayer);
        pLayer->vfunc_19();
    }
    else if (pTop->GetId() <= pLayer->GetId())
    {
        pTop->vfunc_20();
        m_vecLayers.push_back(pLayer);
        pLayer->vfunc_19();
    }
    else
    {
        for (unsigned int i = 0; i < m_vecLayers.size(); ++i)
        {
            Layer* pElem = m_vecLayers.at(i);
            if (pElem->GetId() > pLayer->GetId())
            {
                m_vecLayers.insert(m_vecLayers.begin() + i, pLayer);
                return;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1414436A0, LayerEntry, AddLayer, 557, 0x51A7611A);

// @0x1414438e0
void LayerEntry::Refresh(Layer* pLayer)
{
    if (GetTop() == pLayer)
    {
        pLayer->vfunc_20();
        pLayer->vfunc_19();
    }
}
MS2_REPLACE_METHOD(0x1414438E0, LayerEntry, Refresh, 74, 0x4309C4CA);

// @0x141443930
void LayerEntry::RemoveLayer(Layer* pLayer)
{
    bool bTop = GetTop() == pLayer;
    std::vector<NiPointer<Layer> >::iterator it = std::find(m_vecLayers.begin(), m_vecLayers.end(), pLayer);
    if (it == m_vecLayers.end())
        return;
    if (bTop)
        (*it)->vfunc_20();
    m_vecLayers.erase(it);
    Layer* pNewTop = GetTop();
    if (bTop && pNewTop != 0)
        pNewTop->vfunc_19();
}
MS2_REPLACE_METHOD(0x141443930, LayerEntry, RemoveLayer, 345, 0x4441CFEA);

// @0x141443a90
Layer* LayerEntry::GetTop()
{
    int n = (int)(m_vecLayers.size() - 1);
    if (n < 0)
    {
        return 0;
    }
    else
    {
        return m_vecLayers.at(n);
    }
}
MS2_REPLACE_METHOD(0x141443A90, LayerEntry, GetTop, 79, 0xFC7445B9);

// @0x141443af0
void LayerManager::AddLayer(Layer* pLayer)
{
    NiObjectNET* pNode = pLayer->vfunc_18();
    std::map<NiPointer<NiObjectNET>, LayerEntry>::iterator it = m_mapLayers.find(pNode);
    if (it == m_mapLayers.end())
    {
        it = m_mapLayers.insert(std::make_pair(pNode, LayerEntry(pNode))).first;
        NiPointer<Layer> spBase = vfunc_18(pLayer->vfunc_18());
        if (spBase)
            it->second.AddLayer(spBase);
    }
    it->second.AddLayer(pLayer);
}
MS2_REPLACE_METHOD(0x141443AF0, LayerManager, AddLayer, 479, 0xEEA28320);

// @0x141443ce0
void LayerManager::Refresh(Layer* pLayer)
{
    NiObjectNET* pNode = pLayer->vfunc_18();
    std::map<NiPointer<NiObjectNET>, LayerEntry>::iterator it = m_mapLayers.find(pNode);
    if (it == m_mapLayers.end())
        return;
    it->second.Refresh(pLayer);
}
MS2_REPLACE_METHOD(0x141443CE0, LayerManager, Refresh, 177, 0x33D6CF53);

// @0x141443da0
void LayerManager::RemoveLayer(Layer* pLayer)
{
    NiObjectNET* pNode = pLayer->vfunc_18();
    std::map<NiPointer<NiObjectNET>, LayerEntry>::iterator it = m_mapLayers.find(pNode);
    if (it == m_mapLayers.end())
        return;
    it->second.RemoveLayer(pLayer);
}
MS2_REPLACE_METHOD(0x141443DA0, LayerManager, RemoveLayer, 177, 0x38A65784);

// @0x141443e60
void LayerManager::RemoveNode(NiObjectNET* pNode)
{
    std::map<NiPointer<NiObjectNET>, LayerEntry>::iterator it = m_mapLayers.find(pNode);
    if (it == m_mapLayers.end())
        return;
    m_mapLayers.erase(it);
}
MS2_REPLACE_METHOD(0x141443E60, LayerManager, RemoveNode, 153, 0xE1CF952E);

// @0x141443f00
void LayerManager::Clear()
{
    m_mapLayers.clear();
}
MS2_REPLACE_METHOD(0x141443F00, LayerManager, Clear, 31, 0x938B077C);

// @0x141443f30
bool LayerManager::IsEmpty() const
{
    return m_mapLayers.size() == 0;
}
MS2_REPLACE_METHOD(0x141443F30, LayerManager, IsEmpty, 59, 0x5FC3744C);

// @0x141443f80
NiPointer<Layer> LayerManager::vfunc_18(NiAVObject* pObject)
{
    return NiPointer<Layer>((Layer*)0);
}
MS2_REPLACE_METHOD(0x141443F80, LayerManager, vfunc_18, 60, 0xB8256069);

MS2_EMIT_CRT_MEMMOVE_S();
