// uiobject.h - PLACEHOLDER for UIObject (RTTI .?AVUIObject@@, 0x68 bytes, no fields of its own). NOT an original
// header. Base UISwfEntity. Primary vftable 0x142ee9d58 (52 slots), IMessageListener-in-UIObject 0x142ee9f00.
// Ctor 0x14131e150, dtor 0x14131e1a0. Ownership and slot rules: uiswfentity.h.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiswfentity.h"

class UIObject : public UISwfEntity
{
public:
    UIObject();
    virtual ~UIObject();                                                    //  0 0x14131f400 (??_G)
    virtual CString vfunc_1();                                              //  1 0x14131e1e0
    virtual void OnLoadInit();                                              // 20 0x14131eae0
    virtual void OnLoadComplete();                                          // 22 0x14131ec00
    virtual void vfunc_26();                                                // 26 0x14131ed10
    virtual void vfunc_42();                                                // 42 0x14131ee90
    virtual void vfunc_45();                                                // 45 0x14131e230
    virtual void vfunc_47();                                                // 47 0x14131edb0
    virtual int vfunc_48() = 0;                                             // 48 _purecall (UI type id)
    virtual void vfunc_49();                                                // 49 0x14131edf0
    virtual void vfunc_50();                                                // 50 0x14131ee10
    virtual void vfunc_51();                                                // 51 0x14131eee0
};
MS2_CHECK_SIZE(UIObject, 0x68);
