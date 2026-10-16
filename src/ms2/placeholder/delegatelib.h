// delegatelib.h - DelegateLib::DelegateBase / Delegate2<A1,A2,R> / DelegateMember2<C,A1,A2,R> (RTTI names): the small
// virtual-function delegate library the condition checkers use (CQuestConditionCheckerUserFind keeps a map of them).
// NOT an original header (names assumed except the RTTI class names); layout and slots recovered from the instances in
// commonfiles\conditionutil.cpp (0x1402a5880 .. 0x1402aa600).
//
// DelegateBase: vftable only (8 bytes). Slots: 0 deleting dtor, 1 operator== (pure), 2 operator!= (calls slot 1),
// 3 Clone (pure). Delegate2 adds slot 4, operator() (pure). DelegateMember2<C,..> binds an object and a member
// function pointer (single inheritance, 8 bytes): +8 object, +0x10 function; 0x18 bytes.
#pragma once

#include "ms2/ms2layout.h"

namespace DelegateLib
{
class DelegateBase
{
public:
    // @0x1402aa1b0
    DelegateBase() {}
    // @0x1402aa190
    DelegateBase(const DelegateBase&) {}
    // @0x1402a5ab0
    virtual ~DelegateBase() {}
    virtual bool operator==(const DelegateBase& rhs) const = 0;
    // @0x1402a5b80
    virtual bool operator!=(const DelegateBase& rhs) const { return !operator==(rhs); }
    virtual DelegateBase* Clone() const = 0;
};

template <class A1, class A2, class R>
class Delegate2 : public DelegateBase
{
public:
    Delegate2() {}
    Delegate2(const Delegate2& o) : DelegateBase(o) {}
    virtual R operator()(A1 a1, A2 a2) = 0;
};

template <class C, class A1, class A2, class R>
class DelegateMember2 : public Delegate2<A1, A2, R>
{
public:
    typedef R (C::*MemberFunc)(A1, A2);

    DelegateMember2() : m_pObject(0), m_pFunc(0) {}
    DelegateMember2(C* pObject, MemberFunc pFunc) { Bind(pObject, pFunc); }
    DelegateMember2(const DelegateMember2& o) throw() : Delegate2<A1, A2, R>(o), m_pObject(o.m_pObject), m_pFunc(o.m_pFunc) {}
    DelegateMember2& operator=(const DelegateMember2& o)
    {
        Delegate2<A1, A2, R>::operator=(o);
        m_pObject = o.m_pObject;
        m_pFunc = o.m_pFunc;
        return *this;
    }
    void Bind(C* pObject, MemberFunc pFunc)
    {
        m_pObject = pObject;
        m_pFunc = pFunc;
    }
    virtual bool operator==(const DelegateBase& rhs) const
    {
        const DelegateMember2* pOther = dynamic_cast<const DelegateMember2*>(&rhs);
        return pOther != 0 && m_pFunc == pOther->m_pFunc && m_pObject == pOther->m_pObject;
    }
    virtual DelegateBase* Clone() const { return new DelegateMember2(*this); }
    virtual R operator()(A1 a1, A2 a2) { return (m_pObject->*m_pFunc)(a1, a2); }

private:
    C* m_pObject;           // +0x08
    MemberFunc m_pFunc;     // +0x10
};

// @0x1402a9d20 (for C = CQuestConditionCheckerUserFind)
template <class C, class A1, class A2, class R>
DelegateMember2<C, A1, A2, R> MakeDelegate(C* pObject, R (C::*pFunc)(A1, A2))
{
    return DelegateMember2<C, A1, A2, R>(pObject, pFunc);
}
}
