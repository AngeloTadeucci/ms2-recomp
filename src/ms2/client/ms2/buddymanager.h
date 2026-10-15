// Buddy manager from RTTI; Unk_ names describe inferred packet and pointer types.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/coutpacket.h"
class Unk_BuddyInput;
class CBuddy : public CPtred {
public:
    CBuddy();
    void FUN_1401cc7c0(Unk_BuddyInput&);
    int FUN_1401cc3e0(); int FUN_1401cc3a0(); int FUN_1401cc5d0(); int FUN_1401cc5f0(); int FUN_1401cc680(); int FUN_1401cc660();
    void FUN_1401cc4b0(int); __int64 FUN_1401cc230(); __int64 FUN_1401cc2f0(); CStringW FUN_1401cc350();
    POSITION position; CStringW name; void* pad28; void* pad30; __int64 id,account;
    void* pad48; void* pad50; void* pad58; void* pad60; CStringW memo;
    void* pad70; void* pad78; void* pad80; void* pad88; void* pad90; void* pad98;
    void* pada0; void* pada8; void* padb0; void* padb8; void* padc0; void* padc8; int padd0; unsigned flags;
};
MS2_CHECK_SIZE(CBuddy,0xd8);
MS2_CHECK_OFFSET(CBuddy,name,0x20);
MS2_CHECK_OFFSET(CBuddy,flags,0xd4);
class CLockCriticalSection {
public:
    CLockCriticalSection(); virtual ~CLockCriticalSection(); virtual void vfunc_1(); virtual void vfunc_2();
    CRITICAL_SECTION section;
};
MS2_CHECK_SIZE(CLockCriticalSection,0x30);
class Unk_BuddyGuard { public: Unk_BuddyGuard(CLockCriticalSection&); ~Unk_BuddyGuard(); operator int(); private: void* p; };
template<class T> class Unk_BuddyPtr {
public:
    Unk_BuddyPtr() : p(0) {} Unk_BuddyPtr(int); Unk_BuddyPtr(T*); Unk_BuddyPtr(const Unk_BuddyPtr&); Unk_BuddyPtr(Unk_BuddyPtr&&); ~Unk_BuddyPtr();
    Unk_BuddyPtr& operator=(const Unk_BuddyPtr& o) { o.AddRef(); Release(); p=o.p; return *this; }
    Unk_BuddyPtr& operator=(T* value) { Unk_BuddyPtr temp(value); T* old=p; p=temp.p; temp.p=old; return *this; }
    T* get() const; T* operator->() const; bool operator==(T*) const;
    bool operator!() const { return p==0; }
private: void AddRef() const; void Release(); void* pad; T* p;
};
MS2_CHECK_SIZE(Unk_BuddyPtr<CBuddy>,16);
struct Unk_BuddyRequest {
    Unk_BuddyRequest() : protocol(0),id(0) {} ~Unk_BuddyRequest() {}
    void FUN_1401fc790(COutPacket&);
    unsigned char protocol; __int64 id; CStringW name,memo;
};
struct Unk_BuddyResponse {
    Unk_BuddyResponse() : protocol(0),id(0),unknown10(0),flag(0),result(0),unknown30(0) {} ~Unk_BuddyResponse() {}
    void FUN_1407a3cc0(Unk_BuddyInput&);
    unsigned char protocol; __int64 id,unknown10; CStringW name,memo; char flag; int result; __int64 unknown30;
};
class CBuddyManager : public TSingleton<CBuddyManager> {
public:
    typedef Unk_BuddyPtr<CBuddy> Ptr;
    CBuddyManager(); virtual ~CBuddyManager();
    void FUN_140ae2e90(Unk_BuddyInput&);
    void FUN_140ae4820(Unk_BuddyRequest&);
    Ptr FUN_140ae4880(__int64); Ptr FUN_140ae4950(const CStringW&); Ptr FUN_140ae4ad0(); Ptr FUN_140ae4b70(__int64);
    Ptr FUN_140ae4c30(__int64,__int64,const CStringW&);
    bool FUN_140ae4d70(__int64); void FUN_140ae4df0(ATL::CAtlArray<Ptr>&); unsigned int FUN_140ae4ed0();
    int FUN_140ae4f50(); int FUN_140ae5070(); void FUN_140ae5190(); unsigned FUN_140ae51b0(__int64); unsigned FUN_140ae5240(const CStringW&);
    int FUN_140ae52d0(int,int); int FUN_140ae5410(CStringW); void FUN_140ae55a0(); void FUN_140ae5630(Ptr); void FUN_140ae5750(__int64); void FUN_140ae5850(Ptr); void FUN_140ae5910();
    ATL::CAtlList<Ptr> list;
    ATL::CAtlMap<__int64,Ptr> ids,accounts;
    CLockCriticalSection lock;
};
MS2_CHECK_OFFSET(CBuddyManager,list,8);
MS2_CHECK_OFFSET(CBuddyManager,ids,0x38);
MS2_CHECK_OFFSET(CBuddyManager,accounts,0x80);
MS2_CHECK_OFFSET(CBuddyManager,lock,0xc8);
MS2_CHECK_SIZE(CBuddyManager,0xf8);
