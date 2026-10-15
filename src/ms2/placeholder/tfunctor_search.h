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
