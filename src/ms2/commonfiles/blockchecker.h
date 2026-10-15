// CBlockChecker recovered from RTTI; helper and field names inferred.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
void FUN_14015b020(CPtred*);
int FUN_140159bc0(CPtred*);
void FUN_140159ba0(CPtred*);
struct Unk_BlockRecord : CPtred {
    void* m_18;
    __int64 id;
    int kind;
    int m_2c;
    void* m_30;
    void* m_38;
    __int64 expiry;
};
MS2_CHECK_OFFSET(Unk_BlockRecord,id,0x20);
MS2_CHECK_OFFSET(Unk_BlockRecord,kind,0x28);
MS2_CHECK_OFFSET(Unk_BlockRecord,expiry,0x40);
template<class T> class Unk_BlockPtr {
public:
    Unk_BlockPtr() : m_p(0) {}
    Unk_BlockPtr(int) : m_p(0) {}
    Unk_BlockPtr(const Unk_BlockPtr& p) : m_p(p.m_p) { AddRef(); }
    Unk_BlockPtr(Unk_BlockPtr&& p) : m_p(p.m_p) { p.m_p=0; }
    ~Unk_BlockPtr() { Release(); }
    Unk_BlockPtr& operator=(const Unk_BlockPtr& p) { p.AddRef();Release();m_p=p.m_p;return *this; }
    Unk_BlockPtr& operator=(int) { Release();return *this; }
    bool operator==(T* p) const { return m_p==p; }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
private:
    void AddRef() const { if(m_p) AddRefImpl(0); }
    static void Ref(CPtred* p) { FUN_14015b020(p); }
    void AddRefImpl(void*) const { Ref(m_p); }
    void Release() { if(m_p) { ReleaseImpl(0);m_p=0; } }
    void ReleaseImpl(void*) { if(FUN_140159bc0(m_p)==0) { Ref(m_p);FUN_140159ba0(m_p); } }
    void* m_00;
    T* m_p;
};
typedef Unk_BlockPtr<Unk_BlockRecord> BlockPtr;
MS2_CHECK_SIZE(BlockPtr,0x10);
class CBlockChecker : public CPtred {
public:
    CBlockChecker();
    virtual ~CBlockChecker();
    BlockPtr FindId(__int64);
    BlockPtr FindType(int);
    BlockPtr FindAction(int);
    bool GetAll(ATL::CAtlArray<BlockPtr>&);
    void Set(const BlockPtr&);
    BlockPtr Remove(__int64);
    BlockPtr ExtendType(int,int);
    BlockPtr ExtendId(__int64,int);
    BlockPtr SetExpiry(__int64,__int64);
    void Clear();
    bool IsExpired(BlockPtr);
    bool IsBlockedAction(int,int);
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<BlockPtr> m_records;
};
MS2_CHECK_SIZE(CBlockChecker,0x38);
MS2_CHECK_OFFSET(CBlockChecker,m_records,0x18);
CStringW FUN_1401ca400(const BlockPtr&,int);
int FUN_1401ca560(int,int);
