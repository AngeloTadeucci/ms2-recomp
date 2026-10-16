// Alpha components of the entity layer (names are the exe's RTTI names; members are invented).
//   AlphaComponent        abstract alpha value (+8) of something that can be applied with vfunc_0.
//   AlphaObject           alpha of one scene object: applying it purges the object's renderer data.
//   AlphaShellComposite   a set of render objects (shells) with a set of alpha objects: Update() sorts the alpha objects
//                         by depth, vfunc_0 hides the shells' colour output and applies every alpha object.
// Owning unit: ?\alphacomponent.cpp (0x14098eb30-0x140996b20, dir client\ms2).
#pragma once
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include <vector>
#include <efd/StdContainers.h>
#include <efd/MemObject.h>

class NiAVObject;
class NiRenderObject;
class NiPoint3;

class AlphaComponent : public efd::MemObject
{
public:
    virtual void vfunc_0() = 0;                             // 0 apply

    void SetAlpha(float fAlpha) { m_fAlpha = fAlpha; }      // 0x1409944d0
    float GetAlpha() const { return m_fAlpha; }             // 0x140994390

    float m_fAlpha;                                         // +8
};
MS2_CHECK_SIZE(AlphaComponent, 0x10);

class AlphaObject : public AlphaComponent
{
public:
    virtual void vfunc_0();                                 // 0 0x14098eb30 purge the renderer data of the object

    void Set(NiAVObject* pObject, float fAlpha);            // 0x14098eb80
    void SetObject(NiAVObject* pObject) { m_pObject = pObject; }    // 0x14098ebc0
    NiAVObject* GetObject() const { return m_pObject; }     // 0x14098ebe0

    NiAVObject* m_pObject;                                  // +0x10
};
MS2_CHECK_SIZE(AlphaObject, 0x18);

class AlphaShellComposite : public AlphaComponent
{
public:
    virtual void vfunc_0();                                 // 0 0x14098ec00 apply the shells and the alpha objects

    void Clear();                                           // 0x14098ef60
    void AddShell(NiRenderObject* pShell);                  // 0x14098efa0
    void AddObject(NiAVObject* pObject);                    // 0x14098efd0
    void Update(const NiPoint3* pDir);                      // 0x14098f020 alpha of every object from its depth along pDir
    static void MarkScene(NiAVObject* pRoot, bool bForce);  // 0x14098f4d0 stamp the extra data of every effect node
    static void ResetMarkCounter();                         // 0x14098f630
    static bool IsLessAlpha(const AlphaObject& a, const AlphaObject& b);   // 0x14098f650 sort predicate

    efd::vector<NiRenderObject*> m_aShells;                 // +0x10
    efd::vector<AlphaObject> m_aObjects;                    // +0x28
};
MS2_CHECK_SIZE(AlphaShellComposite, 0x40);
