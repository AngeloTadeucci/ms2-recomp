// Zero- and two-argument variants, from CFileSearcher's callback helpers.
#pragma once
#include "ms2/placeholder/tfunctor.h"
template<class R,class A,class B>
class FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> : public FunctorImplBase<R> {
public: virtual R Invoke(A,B)=0;
};
template<class R,class A,class B> class TFunctor<R,ParamList<A,ParamList<B,EmptyParam>>> {
public:
    typedef FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> Impl;
    TFunctor() : implementation(0) {}
    // MS2: bound member function (effectservice.cpp, 0x1411ab4a0 for CEffectService)
    template<class Object,class Method> TFunctor(const Object& o,Method m)
        : implementation(new ClassFunHandler<TFunctor,Object,Method>(o,m)) {}
    TFunctor(const TFunctor& o) : implementation(Clone(o.implementation)) {}
    ~TFunctor() { Clear(); }
    TFunctor& operator=(const TFunctor& o) { Clear();implementation=Clone(o.implementation);return *this; }
    R operator()(A a,B b) { return implementation->Invoke(a,b); }
    bool IsNull() const { return implementation==0; }
    void Clear() { if(implementation) { delete implementation;implementation=0; } }
private:
    static Impl* Clone(Impl* p) { if(p==nullptr)return nullptr;Impl* result=static_cast<Impl*>(p->Clone());return result; }
    Impl* implementation;
};
// MS2: two-argument handler (effectservice.cpp: CEffectService::FUN_1411a5a60 as the field sound callback)
template<class R,class A,class B,class Object,class Method>
class ClassFunHandler<TFunctor<R,ParamList<A,ParamList<B,EmptyParam>>>,Object,Method>
    : public FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> {
public:
    typedef FunctorImpl<R,ParamList<A,ParamList<B,EmptyParam>>> Impl;
    ClassFunHandler(const Object& o,Method m) : object(o),method(m) {}
    ClassFunHandler(const ClassFunHandler& o) noexcept : Impl(o),object(o.object),method(o.method) {}
    virtual ~ClassFunHandler() = default;
    virtual ClassFunHandler* Clone() const { return new ClassFunHandler(*this); }
    virtual R Invoke(A a,B b) { return (object->*method)(a,b); }
private:
    Object object;
    Method method;
};
