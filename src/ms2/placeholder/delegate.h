// delegate.h - PLACEHOLDER for the game's Delegate<R(Args...)> (RTTI e.g. .?AV?$Delegate@$$A6A_NH...@@ with nested
// DelegateImplBase / DelegateImpl<F> / DelegateImpl<std::pair<C*, R (C::*)(Args...)>>). NOT an original header.
//
// 8 bytes: a pointer to a heap DelegateImplBase (vftable: 0 = deleting dtor, 2 = Invoke; 1 and 3 unknown, pure in
// the base). The ctor/IsNull/operator() bodies are inline because their COMDATs are in recovered units (for
// R(Args) = CString(CString, bool): 0x1422dcac0 / 0x1422dcbb0 / 0x1422dcae0, uiswfentity.cpp); the rest is declared
// only (~Delegate 0x1416291c0, operator= 0x1416292e0 for the same R(Args)). Only the arities recovered code uses
// are spelled out; the original is probably variadic.
#pragma once

#include "ms2/ms2layout.h"

template <class F> class Delegate;

template <class R, class A1, class A2>
class Delegate<R(A1, A2)>
{
public:
    class DelegateImplBase
    {
    public:
        virtual ~DelegateImplBase();                    // 0
        virtual DelegateImplBase* vfunc_1() const = 0;  // 1 (clone?)
        virtual R Invoke(A1 a1, A2 a2) = 0;             // 2
        virtual bool vfunc_3() const = 0;               // 3 (compare?)
    };

    Delegate() : m_pImpl(0) {}
    ~Delegate();
    Delegate& operator=(const Delegate& o);
    bool IsNull() const { return m_pImpl == 0; }
    R operator()(A1 a1, A2 a2) const { return m_pImpl->Invoke(a1, a2); }

private:
    DelegateImplBase* m_pImpl;          // +0x00
};
