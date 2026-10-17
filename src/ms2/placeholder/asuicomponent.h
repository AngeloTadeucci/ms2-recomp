// asuicomponent.h - PLACEHOLDER for ASUIComponent (RTTI .?AVASUIComponent@@, an ASMovieClip with UI hooks; the base of
// ASAdditionalEffectSlot and friends). NOT an original header. uiobject.cpp still carries a unit-local copy (as an AScript);
// new units include this one. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"

class ASUIComponent : public ASMovieClip
{
public:
    ASUIComponent(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422c7100 (the exe allocates 0x88 bytes)
    ASUIComponent(CString strName, int nMovieId);                   // 0x1422c7170 (by name; asitemslot.cpp)
    virtual ~ASUIComponent();                                       // 0x1422c7200 (asitemslot.cpp: the derived dtors call it)
    // Registers a (callback, id) pair on the component (Delegate passed by value: the callee destroys it).
    void FUN_1422c7a90(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> callback, long long n);

private:
    void* m_pad_80;
};
MS2_CHECK_SIZE(ASUIComponent, 0x88);
