// uiobject.h - PLACEHOLDER for UIObject (RTTI .?AVUIObject@@, 0x68 bytes, no fields of its own). NOT an original
// header. Base UISwfEntity (src/ms2/gfxui/uiswfentity.h). Primary vftable 0x142ee9d58 (52 slots: UISwfEntity's 47
// + 47..51), IMessageListener-in-UIObject 0x142ee9f00. Its unit is ?\uiobject.cpp (0x14131e150-0x14131f690, 30
// functions; work/map/units.tsv). Ctor 0x14131e150, dtor 0x14131e1a0.
//
// Complete slot list (signatures from the prologues of all 385 derived classes' implementations); slots 0-46 are
// declared in uiswfentity.h, only UIObject's overrides are repeated here. Ownership: wave-1 foundation; unit agents
// do not edit it (the uiobject.cpp unit agent turns it into the real header and may add non-virtual members).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/gfxui/uiswfentity.h"

class UIObject : public UISwfEntity
{
public:
    UIObject();                                                             // 0x14131e150
    virtual ~UIObject();                                                    //  0 0x14131e1a0 (??_G 0x14131f400)
    virtual CString vfunc_1();                                              //  1 0x14131e1e0
    virtual void OnLoadInit();                                              // 20 0x14131eae0
    virtual void OnLoadComplete();                                          // 22 0x14131ec00
    virtual void vfunc_26();                                                // 26 0x14131ed10
    virtual void vfunc_42(GfxException* pException);                        // 42 0x14131ee90 MessageBox(e->what()); unload
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
                                                                            // 45 0x14131e230 "getTooltip", "webPage", ...
    virtual void vfunc_47(int n);                                           // 47 0x14131edb0 FUN_141901420(n, vfunc_48())
    virtual int vfunc_48() = 0;                                             // 48 _purecall: UI type id (e.g. 20094)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x14131edf0 ("getTooltip")
    virtual void vfunc_50(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 50 0x14131ee10 ("playSystemSound")
    virtual void vfunc_51(void* pParams);                                   // 51 0x14131eee0 debug tooltip; *(Value**)pParams = result
};
MS2_CHECK_SIZE(UIObject, 0x68);
