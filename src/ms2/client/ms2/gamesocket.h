// CGameSocket and its socket worker; names except RTTI/vfunc names are inferred.
#pragma once
#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif
#include <afx.h>
#include <winsock2.h>
#include <atlcoll.h>
#include <algorithm>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cthread.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/packetlogger.h"
#include "ms2/ms2format.h"
class CGameSocket;
class CSocketThread;
class CSimpleSocket;
#include "ms2/placeholder/cpacketbuffer.h"
#include "ms2/placeholder/coutpacketbuffer.h"
template<class T> class TPtredDummy : public CPtred { public: TPtredDummy()=default; virtual ~TPtredDummy()=default; T value; };
void FUN_14015b020(CPtred*); int FUN_140159bc0(CPtred*); void FUN_140159ba0(CPtred*);
CPtred* FUN_1401ba820(CPtred*);
// MS2-FUNCTIONAL: equivalent intrusive ownership; explicit casts and allocation temporaries differ.
template<class T> struct Unk_SocketRef {
    static __forceinline CPtred* Base(T* p) { return p; }
    static T* New(void*) { return new T; }
    static T* Create(void* p) { return static_cast<T*>(FUN_1401ba820(New(p))); }
};
// MS2-FUNCTIONAL: null-preserving conversion between the wrapper and its packet subobject.
template<> struct Unk_SocketRef<CInPacket> {
    static CPtred* Base(CInPacket* p) { return p ? reinterpret_cast<TPtredDummy<CInPacket>*>(reinterpret_cast<char*>(p)-0x18) : 0; }
    static TPtredDummy<CInPacket>* New(void*) { return new TPtredDummy<CInPacket>(); }
    static CInPacket* Value(TPtredDummy<CInPacket>* p) { return p ? &p->value : 0; }
    static CInPacket* Create(void* p) { return Value(static_cast<TPtredDummy<CInPacket>*>(FUN_1401ba820(New(p)))); }
};
struct Unk_SocketNew { explicit Unk_SocketNew(int) {} };
// MS2-FUNCTIONAL: nullptr overloads and typed reference helpers preserve ownership with different temporaries.
template<class T> class Unk_SocketPtr {
public:
    Unk_SocketPtr():p(0) {}
    Unk_SocketPtr(std::nullptr_t):p(0) {}
    Unk_SocketPtr(T* v):p(v) { AddRef(); }
    Unk_SocketPtr(const Unk_SocketPtr& v):p(v.p) { AddRef(); }
    Unk_SocketPtr(Unk_SocketPtr&& v):p(v.p) { v.p=0; }
    ~Unk_SocketPtr() { Release(); }
    Unk_SocketPtr& operator=(const Unk_SocketPtr& v) { v.AddRef(); Release(); p=v.p; return *this; }
    Unk_SocketPtr& operator=(T* v) { Unk_SocketPtr tmp(v); T* old=p; p=tmp.p; tmp.p=old; return *this; }
    Unk_SocketPtr& operator=(std::nullptr_t) { Release(); return *this; }
    Unk_SocketPtr& operator=(const Unk_SocketNew&) { ResetNew(); return *this; }
    T* get() const { return p; } T* operator->() const { return p; } T& operator*() const { return *p; }
    bool operator==(T* v) const { return p==v; }
private:
    static void Reference(CPtred* v) { FUN_14015b020(v); }
    void AddRef() const { if(p) AddRefImpl((void*)0); }
    void AddRefImpl(void*) const { Reference(Unk_SocketRef<T>::Base(p)); }
    void Release() { if(p) { ReleaseImpl((void*)0); p=0; } }
    void ReleaseImpl(void*) { CPtred* base=Unk_SocketRef<T>::Base(p); if(FUN_140159bc0(base)==0) { Reference(base); FUN_140159ba0(base); } }
    void ResetNew() { Release(); p=Unk_SocketRef<T>::Create((void*)0); }
    void* pad; T* p;
};
typedef Unk_SocketPtr<CInPacket> Unk_InPtr;
typedef Unk_SocketPtr<CPacketBuffer> Unk_BufferPtr;
class ISocketCallBack {
public:
    ISocketCallBack() {}
    virtual void vfunc_0(CSimpleSocket*,int) {}
    virtual void vfunc_1(CSimpleSocket*,int) {}
    virtual void vfunc_2(CSimpleSocket*,int) {}
    virtual void vfunc_3(CSimpleSocket*,int) {}
    virtual void vfunc_4(CSimpleSocket*,int) {}
    virtual void vfunc_5(CSimpleSocket*,int) {}
};
MS2_CHECK_SIZE(ISocketCallBack,8);
class CSocketBase {
public:
    explicit CSocketBase(SOCKET s):m_socket(s) {}
    ~CSocketBase() { FUN_141269780(); }
    operator SOCKET() const { return m_socket; }
    void FUN_141269780();
    bool operator==(const CSocketBase& o) const { return m_socket==o.m_socket; }
    void FUN_14126c5c0(int); void FUN_14126c610(int); void FUN_14126c680(int); void FUN_14126c7d0(int); void FUN_14126c840(int); void FUN_14126c8b0(int,int,int);
protected: SOCKET m_socket;
};
MS2_CHECK_SIZE(CSocketBase,8);
struct Unk_SocketAddress : sockaddr_in {
    Unk_SocketAddress(const char*,int);
    ~Unk_SocketAddress() {}
    operator const sockaddr*() const { return reinterpret_cast<const sockaddr*>(this); }
    void FUN_14126ce80(int,unsigned long);
    void FUN_14126ced0(unsigned short,unsigned long);
};
MS2_CHECK_SIZE(Unk_SocketAddress,16);
struct Unk_SocketOptions {
    Unk_SocketOptions():noDelay(INT_MAX),option5(INT_MAX),receiveBuffer(INT_MAX),sendBuffer(INT_MAX) {}
    int noDelay,option5,receiveBuffer,sendBuffer;
};
MS2_CHECK_SIZE(Unk_SocketOptions,16);
class CSimpleSocket : public CSocketBase {
public:
    CSimpleSocket(); virtual ~CSimpleSocket();
    virtual int vfunc_1(char*,int);
    virtual int vfunc_2(const char*,int);
    virtual int vfunc_3(char*,int);
    virtual int vfunc_4(const char*,int);
    void FUN_1412694d0(int,CSocketThread*);
    void FUN_141269750(); void FUN_141269990();
    int FUN_141269820(const sockaddr*,int);
    int FUN_141269890(const sockaddr* p) { return FUN_141269820(p,16); }
    int FUN_14126c3d0(const char*,int,int);
    ISocketCallBack* FUN_14126a3c0() { return m_callback; }
    void FUN_14126c5a0(ISocketCallBack* p) { m_callback=p; }
private:
    Unk_SocketPtr<CSocketThread> m_worker;
    ISocketCallBack* m_callback;
};
MS2_CHECK_SIZE(CSimpleSocket,0x28);
struct Unk_SocketCommand { CSimpleSocket* socket; int events; HANDLE done; };
MS2_CHECK_SIZE(Unk_SocketCommand,24);
class CSocketThread : public CPtred,public CThread {
public:
    CSocketThread(); virtual ~CSocketThread();
    unsigned int vfunc_1(void*,Unk_140659080&) override;
    void FUN_1412696b0(); int FUN_141269b30(HANDLE); void FUN_141269dc0();
    void FUN_14126a000(CSimpleSocket*,int);
    HANDLE FUN_14126b1c0(CSimpleSocket*); int FUN_14126b250(CSimpleSocket*);
    ATL::CAtlArray<HANDLE> m_events;
    CLockCriticalSection m_lock;
    ATL::CAtlList<Unk_SocketCommand> m_commands;
    ATL::CAtlMap<HANDLE,CSimpleSocket*> m_sockets;
    int m_quit;
};
MS2_CHECK_SIZE(CSocketThread,0x100);
MS2_CHECK_OFFSET(CSocketThread,m_events,0x30);
MS2_CHECK_OFFSET(CSocketThread,m_sockets,0xb0);
class CGameSocket : public ISocketCallBack {
public:
    CGameSocket(); ~CGameSocket();
    void vfunc_0(CSimpleSocket*,int) override {}
    void vfunc_1(CSimpleSocket*,int) override;
    void vfunc_2(CSimpleSocket*,int) override;
    void vfunc_3(CSimpleSocket*,int) override;
    void vfunc_4(CSimpleSocket*,int) override {}
    void vfunc_5(CSimpleSocket*,int) override;
    int FUN_141265420(CString,int,int,int);
    void FUN_1412657e0(); void FUN_141265850(); void FUN_141265960();
    void FUN_141265990(COutPacket&); void FUN_141265ae0(); void FUN_141266480(unsigned,unsigned);
    void FUN_141266500(int); void FUN_141267000(int); void FUN_141267070();
    void FUN_1412672a0(const Unk_SocketOptions&); void FUN_1412672d0();void FUN_1412673c0();
    int FUN_1412673f0(); void FUN_141267410(COutPacket&); int FUN_1412675d0(); int FUN_1412675f0(); CString FUN_141267630(); int FUN_141267680();
private:
    MS2_LAYOUT_FRIEND;
    CSimpleSocket m_socket;
    CLockCriticalSection m_lock,m_sendLock;
    int m_state;
    Unk_BufferPtr m_receiveBuffer;
    int m_received;
    ATL::CAtlList<Unk_InPtr> m_packets;
    ATL::CAtlList<Unk_BufferPtr> m_receiveQueue;
    unsigned m_sent,m_sendKey,m_receiveKey;
    ATL::CAtlList<Unk_BufferPtr> m_sendQueue;
    volatile int m_disconnect;
    CString m_host;
    int m_port,m_specialConnect;
    CString m_retryHost;
    int m_retryPort,m_showErrors;
    Unk_SocketOptions m_options;
    int m_sequence;
    Unk_SocketPtr<COutPacketBuffer> m_out;
    Unk_SocketPtr<CPacketLogger> m_logger;
};
MS2_CHECK_SIZE(CGameSocket,0x1b0);
MS2_CHECK_OFFSET(CGameSocket,m_state,0x90);
MS2_CHECK_OFFSET(CGameSocket,m_receiveBuffer,0x98);
MS2_CHECK_OFFSET(CGameSocket,m_packets,0xb0);
MS2_CHECK_OFFSET(CGameSocket,m_sendQueue,0x120);
MS2_CHECK_OFFSET(CGameSocket,m_out,0x190);
