// Buddy manager from RTTI; Unk_ names describe inferred packet and pointer types.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/coutpacket.h"
class Unk_BuddyInput;
class CBuddy : public CPtred {
public:
    CBuddy();
    void FUN_1401cc7c0(Unk_BuddyInput&);
    int FUN_1401cc3e0(); int FUN_1401cc3a0(); int FUN_1401cc5d0(); int FUN_1401cc5f0(); int FUN_1401cc680(); int FUN_1401cc660();
    void FUN_1401cc4b0(int); __int64 FUN_1401cc230(); __int64 FUN_1401cc2f0(); CStringW FUN_1401cc350();
    // Layout from ctor 0x1401cbd50, dtor 0x1401cc020 and packet reader FUN_1401cc7c0 (read order in comments).
    POSITION position;              // +0x18 node in CBuddyManager::list
    CStringW name;                  // +0x20 (4th read)
    CStringA m_28;                  // +0x28 (13th read; HomeBlockManager 0x140a47d10 copies a CStringA here)
    CStringW m_30;                  // +0x30 (5th read)
    __int64 id, account;            // +0x38, +0x40 (1st, 2nd read)
    __int64 m_48;                   // +0x48 (3rd read)
    unsigned __int64 m_50, m_58;    // +0x50, +0x58 (u32 reads, zero-extended)
    CStringW m_60;                  // +0x60
    CStringW memo;                  // +0x68
    void* m_70[4];                  // +0x70 0x20-byte array object (ctor 0x1401bfbd0, dtor 0x1401bff10)
    __int64 m_90;                   // +0x90
    short m_98;                     // +0x98
    int m_9c;                       // +0x9c
    int m_a0;                       // +0xa0 ctor 1
    int m_a4;                       // +0xa4
    int m_a8;                       // +0xa8 (u16 read)
    int m_ac[3];                    // +0xac 12-byte triple (ctor 0x140267ba0, reader 0x140267e70)
    int m_b8, m_bc, m_c0;           // +0xb8..+0xc0
    CStringW m_c8;                  // +0xc8
    int m_d0;                       // +0xd0
    unsigned flags;                 // +0xd4 bit flags (bits 0..8 cleared by ctor; reader sets bit 7)
};
MS2_CHECK_SIZE(CBuddy,0xd8);
MS2_CHECK_OFFSET(CBuddy,name,0x20);
MS2_CHECK_OFFSET(CBuddy,m_28,0x28);
MS2_CHECK_OFFSET(CBuddy,m_48,0x48);
MS2_CHECK_OFFSET(CBuddy,memo,0x68);
MS2_CHECK_OFFSET(CBuddy,m_70,0x70);
MS2_CHECK_OFFSET(CBuddy,m_98,0x98);
MS2_CHECK_OFFSET(CBuddy,m_a0,0xa0);
MS2_CHECK_OFFSET(CBuddy,m_a4,0xa4);
MS2_CHECK_OFFSET(CBuddy,m_c8,0xc8);
MS2_CHECK_OFFSET(CBuddy,flags,0xd4);
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
