// httpdownloadcallback.h - the URLMON download callback of the client UGC downloads (RTTI .?AVXBindStatusCallback@@,
// .?AVHttpDownloadCallback@@). The file name is the original (it is in the assert texts); the contents are recovered
// from the inline copies that client\ms2\ugcmanager.cpp#2 emitted.
//
// XBindStatusCallback is the receiver side: IBindStatusCallback without IUnknown, every method a no-op returning S_OK
// (vftable 0x142f8a900). HttpDownloadCallback is the COM object handed to URLDownloadToFileW; it counts its own
// references (it lives inside its owner, so the count stays 1) and forwards every notification to the owner
// (vftable 0x142f8a948, the virtual dtor in slot 11).
#pragma once

#include <assert.h>
#include <urlmon.h>

#include "ms2/ms2layout.h"

// <assert.h> only declares _wassert without NDEBUG (the clang-cl RelWithDebInfo build defines it).
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#define HTTPDOWNLOADCALLBACK_ASSERT(line, expr)                                                                       \
    (void)((!!(expr)) ||                                                                                             \
           (_wassert(_CRT_WIDE(#expr), L"e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\httpdownloadcallback.h", line), 0))

class XBindStatusCallback
{
public:
    // @0x14187ca30
    virtual HRESULT OnStartBinding(DWORD dwReserved, IBinding* pib) { return S_OK; }
    // @0x14187c9b0
    virtual HRESULT GetPriority(LONG* pnPriority) { return S_OK; }
    // @0x14187c9e0
    virtual HRESULT OnLowResource(DWORD reserved) { return S_OK; }
    // @0x14187ca10
    virtual HRESULT OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
    {
        return S_OK;
    }
    // @0x14187ca50
    virtual HRESULT OnStopBinding(HRESULT hresult, LPCWSTR szError) { return S_OK; }
    // @0x14187c990
    virtual HRESULT GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo) { return S_OK; }
    // @0x14187c9c0
    virtual HRESULT OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
    {
        return S_OK;
    }
    // @0x14187c9f0
    virtual HRESULT OnObjectAvailable(REFIID riid, IUnknown* punk) { return S_OK; }
};
MS2_CHECK_SIZE(XBindStatusCallback, 0x8);

class HttpDownloadCallback : public IBindStatusCallback
{
public:
    // @0x1418771e0
    HttpDownloadCallback(XBindStatusCallback* pOwner) : m_ref(1), m_pOwner(pOwner) {}

    // @0x14187b350
    STDMETHODIMP QueryInterface(REFIID riid, void** ppvObject)
    {
        if (riid == __uuidof(IUnknown))
            *ppvObject = this;
        else if (riid == __uuidof(IBindStatusCallback))
            *ppvObject = this;
        else
            return E_NOINTERFACE;
        AddRef();
        return S_OK;
    }
    // @0x1418786f0
    STDMETHODIMP_(ULONG) AddRef()
    {
        HTTPDOWNLOADCALLBACK_ASSERT(0x4f, m_ref < 0x7fffffff);
        return ++m_ref;
    }
    // @0x14187bb30
    STDMETHODIMP_(ULONG) Release()
    {
        HTTPDOWNLOADCALLBACK_ASSERT(0x56, m_ref > 0);
        if (--m_ref == 0)
        {
            delete this;
            return 0;
        }
        return m_ref;
    }

    // @0x14187b200
    STDMETHODIMP OnStartBinding(DWORD dwReserved, IBinding* pib) { return m_pOwner->OnStartBinding(dwReserved, pib); }
    // @0x14187a380
    STDMETHODIMP GetPriority(LONG* pnPriority) { return m_pOwner->GetPriority(pnPriority); }
    // @0x14187b140
    STDMETHODIMP OnLowResource(DWORD reserved) { return m_pOwner->OnLowResource(reserved); }
    // @0x14187b1b0
    STDMETHODIMP OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
    {
        return m_pOwner->OnProgress(ulProgress, ulProgressMax, ulStatusCode, szStatusText);
    }
    // @0x14187b240
    STDMETHODIMP OnStopBinding(HRESULT hresult, LPCWSTR szError) { return m_pOwner->OnStopBinding(hresult, szError); }
    // @0x141879550
    STDMETHODIMP GetBindInfo(DWORD* grfBINDF, BINDINFO* pbindinfo) { return m_pOwner->GetBindInfo(grfBINDF, pbindinfo); }
    // @0x14187b0f0
    STDMETHODIMP OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC* pformatetc, STGMEDIUM* pstgmed)
    {
        return m_pOwner->OnDataAvailable(grfBSCF, dwSize, pformatetc, pstgmed);
    }
    // @0x14187b170
    STDMETHODIMP OnObjectAvailable(REFIID riid, IUnknown* punk) { return m_pOwner->OnObjectAvailable(riid, punk); }

    // @0x141877880
    virtual ~HttpDownloadCallback() { HTTPDOWNLOADCALLBACK_ASSERT(0x34, m_ref == 1); }

private:
    MS2_LAYOUT_FRIEND;
    int m_ref;                                              // +0x08
    XBindStatusCallback* m_pOwner;                          // +0x10
};
MS2_CHECK_SIZE(HttpDownloadCallback, 0x18);
