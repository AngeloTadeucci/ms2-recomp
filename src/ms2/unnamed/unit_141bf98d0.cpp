// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService.cpp COMDAT glue: the ClassFunHandler invokers of
// COptimizer / WorldService callbacks, std::less<void*> and the ordering of the entity-keyed set the world service keeps.
// MS2-UNIT: unit_141bf98d0
// MS2-RANGE: 0x141bf98d0-0x141bf99b8 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <functional>
#include <egf/EntityID.h>

#include "ms2/placeholder/tfunctor.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"

// The key of the world service's entity set: an object whose egf::EntityID sits at +0x10 and which orders by it.
struct Unk_WsEntityKey
{
    __int64 m_pad_00;
    __int64 m_pad_08;
    egf::EntityID m_id;                                     // +0x10
    bool operator<(const Unk_WsEntityKey& rhs) const { return m_id < rhs.m_id; }   // 0x141bf98d0
};

// ClassFunHandler<TFunctor<void,EmptyParam>, COptimizer*, void (COptimizer::*)()>::vfunc_2 (0x141bf9900)
template void ClassFunHandler<TFunctor<void, EmptyParam>, COptimizer*, void (COptimizer::*)()>::Invoke();

// ... , WorldService*, void (WorldService::*)()>::vfunc_2 (0x141bf9920)
template void ClassFunHandler<TFunctor<void, EmptyParam>, WorldService*, void (WorldService::*)()>::Invoke();

// std::less<void*>::operator() (0x141bf9950) and std::less<Unk_WsEntityKey>::operator() (0x141bf9990)
template bool std::less<void*>::operator()(void* const&, void* const&) const;
template bool std::less<Unk_WsEntityKey>::operator()(const Unk_WsEntityKey&, const Unk_WsEntityKey&) const;
