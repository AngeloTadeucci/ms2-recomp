// Unit-local typed interface to the socket page's ASItemBag controls.
// Slots 16..25 verified against ASItemBag RTTI vftable and /Od argument homing.
// The controls are owned by the exe; this view is never constructed.
#pragma once
#include "ms2/placeholder/asuicomponent.h"
class Unk_SocketPageBag : public ASUIComponent {
public:
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool);
    virtual void vfunc_25(const Scaleform::GFx::Value&);
};
