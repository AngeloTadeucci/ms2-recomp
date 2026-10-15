// asuicomponent.h - PLACEHOLDER for ASUIComponent (RTTI .?AVASUIComponent@@, an ASMovieClip with UI hooks; the base of
// ASAdditionalEffectSlot and friends). NOT an original header. uiobject.cpp still carries a unit-local copy (as an AScript);
// new units include this one. Declarations only.
#pragma once

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"

class ASUIComponent : public ASMovieClip
{
public:
    // Registers a (callback, id) pair on the component (Delegate passed by value: the callee destroys it).
    void FUN_1422c7a90(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> callback, long long n);
};
