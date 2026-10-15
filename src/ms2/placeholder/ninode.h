// ninode.h - PLACEHOLDER for Gamebryo's NiNode (NiNode : NiAVObject : NiObjectNET : NiObject : NiRefObject), because the
// CoreRuntime include dirs are not on the ms2game / progress.py path. NOT an original header.
// Layout: sizeof 0x130 (NiRefObject 0x10 + 0x120 of unrecovered NiObjectNET/NiAVObject/NiNode data, kept as opaque
// scalar pads). Virtual slot list (42 slots, proven from the LightUnaffectedNode vftable 0x142f1f3e8-ish table):
// 0 dtor, 1 DeleteThis (NiRefObject), 2 GetRTTI, 3 CreateClone, 4..41 as below. Slots 4..30 and 32..41 are declared
// as `vfunc_N()` with void/no-arg signatures (real signatures unknown; only the slot address matters for the vftable
// gate). Their NiNode implementations live in the exe (progress/symbols-manual.tsv: `?vfunc_N@NiNode@@UEAAXXZ`).
// Slot 31 is NiNode::UpdateEffectsDownward(NiDynamicEffectState*) (0x141d1c3f0), called qualified by derived classes.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"

class NiCloningProcess;
class NiDynamicEffectState;

// NiRTTI: {name, base}; the ctor is the engine's inline one (COMDAT 0x141d16b90).
class NiRTTI {
public:
    NiRTTI(const char* pcName, const NiRTTI* pkBase) : m_pcName(pcName), m_pkBaseRTTI(pkBase) {}
    const char* m_pcName;
    const NiRTTI* m_pkBaseRTTI;
};
MS2_CHECK_SIZE(NiRTTI, 0x10);

class NiNode : public NiRefObject {
public:
    explicit NiNode(unsigned int uiChildren);               // 0x141d19760
    virtual ~NiNode();                                      // slot 0, 0x141d19930
    virtual const NiRTTI* GetRTTI() const;                  // slot 2
    virtual NiRefObject* CreateClone(NiCloningProcess& kCloning);   // slot 3
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void UpdateEffectsDownward(NiDynamicEffectState* pkParentState);   // slot 31, 0x141d1c3f0
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();

    static const NiRTTI ms_RTTI;                            // 0x143afa4d8

protected:
    void CopyMembers(NiNode* pkDest, NiCloningProcess& kCloning);   // 0x141d1a1e0

    void* m_pad_10[36];                                     // +0x10 .. 0x130
};
MS2_CHECK_SIZE(NiNode, 0x130);
