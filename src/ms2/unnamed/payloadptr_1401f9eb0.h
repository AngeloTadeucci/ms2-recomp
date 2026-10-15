// Unit-local spelling of the unknown 16-byte intrusive-pointer template.
#pragma once
#include "ms2/ms2layout.h"
struct Unk_PayloadRef {
    void FUN_14015b020();
    int FUN_140159bc0();
    void FUN_140159ba0();
};
template<class T> class Unk_PayloadPtr {
public:
    Unk_PayloadPtr(){p=0;}
    Unk_PayloadPtr(int){p=0;}
    Unk_PayloadPtr(T* value){p=value;AddRef();}
    Unk_PayloadPtr(const Unk_PayloadPtr& value){p=value.p;AddRef();}
    Unk_PayloadPtr(Unk_PayloadPtr&& value){p=value.p;value.p=0;}
    ~Unk_PayloadPtr(){Release();}
    Unk_PayloadPtr& operator=(const Unk_PayloadPtr& value){value.AddRef();Release();p=value.p;return *this;}
    operator T*()const{return p;}
    T* operator->()const{return p;}
    T* get()const{return p;}
    bool operator==(T* value)const{return p==value;}
private:
    void AddRef()const{if(p)AddRefImpl(0);}
    void AddRefImpl(void*)const{Reference(p);}
    static void Reference(T* value){reinterpret_cast<Unk_PayloadRef*>(value)->FUN_14015b020();}
    void Release(){if(p){ReleaseImpl(0);p=0;}}
    void ReleaseImpl(void*){if(reinterpret_cast<Unk_PayloadRef*>(p)->FUN_140159bc0()==0){Reference(p);reinterpret_cast<Unk_PayloadRef*>(p)->FUN_140159ba0();}}
    void* unknown;T* p;
};
MS2_CHECK_SIZE(Unk_PayloadPtr<int>,16);
