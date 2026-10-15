// tptreddummy.h - TPtredDummy<T> (RTTI name, e.g. .?AV?$TPtredDummy@V?$CRBMap@HV?$TPtr@VCSeasonData@@...): the heap box
// that the 16-byte smart pointer (TPtr<T>; MS2Ptr / Unk_SocketRef / Unk_PopupPtr in our tree) shares: a CPtred base
// (0x18) followed by the owned value, size 0x18 + sizeof(T); the smart pointer points at the value.
// Single shared definition (sb2): socketptr.h, fieldmetatable.h, clientreconnectionstructs.h and uicommunitypopup.h used
// to define it each, which made networkservice.h (-> gamesocket.h -> socketptr.h) unusable next to uicommunitypopup.h.
#pragma once
#include "ms2/placeholder/cptred.h"

template <class T>
class TPtredDummy : public CPtred
{
public:
    T value;
};
