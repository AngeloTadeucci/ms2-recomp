// specialeffectfunctionmanager.h - CSpecialEffectFunctionManager (RTTI name): the registry of special effect functions.
// Header name assumed. Method names are invented from use. Registered by CSpecialEffectFunctionManager's ctor
// (id 4 -> CSEReduceSkillGroupCooltime); looked up by a CSpecialEffectCtx's kind.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cspecialeffectctx.h"
#include "ms2/commonfiles/os.h"

// One effect function. RTTI CSpecialEffectFunction, 0x18 bytes (CPtred only), vftable 0x142d96aa0.
class CSpecialEffectFunction : public CPtred
{
public:
    // implicit ctor 0x140827dd0 (`new T()` zero-fills first)
    virtual bool vfunc_1(CSpecialEffectCtx* pCtx);  // 0x140827580: base function accepts every ctx
};
MS2_CHECK_SIZE(CSpecialEffectFunction, 0x18);

// RTTI CSEReduceSkillGroupCooltime, vftable 0x142f62e30-ish (own vftable, 2 slots).
class CSEReduceSkillGroupCooltime : public CSpecialEffectFunction
{
public:
    // implicit ctor 0x140827da0
    virtual bool vfunc_1(CSpecialEffectCtx* pCtx);  // 0x1408275a0
};
MS2_CHECK_SIZE(CSEReduceSkillGroupCooltime, 0x18);

class CSpecialEffectFunctionManager : public TSingleton<CSpecialEffectFunctionManager>
{
public:
    typedef MS2Ptr<CSpecialEffectFunction> FunctionPtr;
    typedef ATL::CAtlMap<unsigned int, FunctionPtr> Map;

    CSpecialEffectFunctionManager();                // 0x140827800
    virtual ~CSpecialEffectFunctionManager();       // 0x140827910

    bool Execute(CSpecialEffectCtx* pCtx);          // 0x140827970 (name invented): runs the function registered for the ctx kind
    FunctionPtr Find(unsigned int nId);                    // 0x140827a20 (inline)
    void Register(unsigned int nId, FunctionPtr pFunction);    // 0x140827aa0 (inline): first registration of an id wins

private:
    MS2_LAYOUT_FRIEND;
    Map m_map;                                      // +0x08
};
MS2_CHECK_SIZE(CSpecialEffectFunctionManager, 0x50);
MS2_CHECK_OFFSET(CSpecialEffectFunctionManager, m_map, 0x08);

inline CSpecialEffectFunctionManager::FunctionPtr CSpecialEffectFunctionManager::Find(unsigned int nId)
{
    FunctionPtr pFunction(0);
    m_map.Lookup(nId, pFunction);
    return pFunction;
}

inline void CSpecialEffectFunctionManager::Register(unsigned int nId, FunctionPtr pFunction)
{
    if (Find(nId).get() != 0)
        return;
    m_map.SetAt(nId, pFunction);
}
