// cugcmanager.h - PLACEHOLDER for CUgcManager (RTTI .?AVCUgcManager@@, 0x1c0 bytes, vftable 0x142f8dd68). NOT an
// original header. Bases: TSingleton<CUgcManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; recovered in client\ms2\ugcmanager.cpp#4
// (src/ms2/client/ms2/ugcmanager_4.cpp). It drives the UGC uploads (one CUgcUploadCtrl at a time, previewed by the
// upload dialogs), keeps the local upload files, and places the downloaded UGC images (banners, rolling banners, cube /
// mount / profile images) on the field objects. The download code (ugcmanager.cpp#2) reports back through
// FUN_141886190 and the image setters.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <set>
#include <map>

#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tptreddummy.h"

namespace egf { class Entity; }

class CUgcDownloadCtrl;
struct ReserveBannerInfo;                                  // ugcdef.h (not included: ms2.cpp has other copies of its classes)
class Unk_CharListEntry;
class CUgcItemCube;
class CUgcItemRidee;
class CUgcRegistBanner;
class CUgcBannerRollingImage;
class CUgcUploadCtrl;
class CUploadFile;
class NiTexture;

CPtred* FUN_1401ba820(CPtred* p);                           // sets the count of a new box to 1

// The creating-constructor tag of the boxed pointer below (`Unk_UgcBoxPtr<T> p(Unk_UgcNewTag(0))`).
struct Unk_UgcNewTag
{
    explicit Unk_UgcNewTag(int);                            // 0x1401b7b90 (returns its this, no code)
};

// TPtr<T> over a TPtredDummy<T> box (16 bytes, the pointer at +8 points at the boxed value). Name invented; the same
// template as Unk_BmBoxPtr (blackmarketitemoption.h).
template <class T>
class Unk_UgcBoxPtr
{
public:
    Unk_UgcBoxPtr();
    Unk_UgcBoxPtr(int);
    Unk_UgcBoxPtr(const Unk_UgcNewTag&);
    Unk_UgcBoxPtr(const Unk_UgcBoxPtr& o);
    ~Unk_UgcBoxPtr();
    Unk_UgcBoxPtr& operator=(const Unk_UgcBoxPtr& o);
    Unk_UgcBoxPtr& operator=(const Unk_UgcNewTag&);
    T* get() const;
    T* operator->() const;
    bool operator==(T* p) const;

private:
    void AddRef() const;
    void Make();
    void Release();
    static TPtredDummy<T>* Allocate(void*);
    static T* Value(TPtredDummy<T>* p);
    static TPtredDummy<T>* Owner(T* p);
    static void Ref(CPtred* p);
    static T* Create(void*);
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    void* m_00;
    T* m_p;
};

template <class T> Unk_UgcBoxPtr<T>::Unk_UgcBoxPtr() { m_p = 0; }
template <class T> Unk_UgcBoxPtr<T>::Unk_UgcBoxPtr(int) { m_p = 0; }
template <class T> Unk_UgcBoxPtr<T>::Unk_UgcBoxPtr(const Unk_UgcNewTag&) { m_p = 0; Make(); }
template <class T> Unk_UgcBoxPtr<T>::Unk_UgcBoxPtr(const Unk_UgcBoxPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_UgcBoxPtr<T>::~Unk_UgcBoxPtr() { Release(); }
template <class T> Unk_UgcBoxPtr<T>& Unk_UgcBoxPtr<T>::operator=(const Unk_UgcBoxPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> Unk_UgcBoxPtr<T>& Unk_UgcBoxPtr<T>::operator=(const Unk_UgcNewTag&) { Make(); return *this; }
template <class T> T* Unk_UgcBoxPtr<T>::get() const { return m_p; }
template <class T> T* Unk_UgcBoxPtr<T>::operator->() const { return m_p; }
template <class T> bool Unk_UgcBoxPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> void Unk_UgcBoxPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_UgcBoxPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_UgcBoxPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> TPtredDummy<T>* Unk_UgcBoxPtr<T>::Allocate(void*) { return new TPtredDummy<T>(); }
template <class T> T* Unk_UgcBoxPtr<T>::Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
template <class T> TPtredDummy<T>* Unk_UgcBoxPtr<T>::Owner(T* p)
{
    return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
}
template <class T> void Unk_UgcBoxPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> T* Unk_UgcBoxPtr<T>::Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
template <class T> void Unk_UgcBoxPtr<T>::AddRefImpl(void*) const { Ref(Owner(m_p)); }
template <class T> void Unk_UgcBoxPtr<T>::ReleaseImpl(void*)
{
    CPtred* owner = Owner(m_p);
    if (CPtred::ReleasePtred(owner) == 0) { Ref(owner); CPtred::DeletePtred(owner); }
}

class CUgcManager : public TSingleton<CUgcManager>
{
public:
    typedef CRBMap<CString, MS2Ptr<CUgcDownloadCtrl>, CStringElementTraitsI<CString> > CCtrlMap;
    typedef CRBMap<unsigned __int64, ReserveBannerInfo> CReserveMap;       // hour -> reservation

    CUgcManager();                                          // 0x14187ed30
    virtual ~CUgcManager();                                 // 0x14187eff0

    void FUN_141886190(CString strName, MS2Ptr<CUgcDownloadCtrl> spCtrl, int nResult);   // a download finished
    void FUN_141886cc0(CUgcItemCube* pItem, CString strPath, unsigned __int64 uid);        // a cube image not placed yet
    void FUN_141887040(CUgcItemRidee* pItem, CString strPath, unsigned __int64 uid);       // a mount image not spawned yet
    void FUN_141887dc0(int nBannerId, MS2Ptr<CUgcRegistBanner> spBanner);                  // a banner image arrived
    int FUN_141888420(int nBannerId, CString strPath);                                     // a rolling banner image arrived

    void FUN_14187f1c0();                                   // per-frame update
    void FUN_14187f1f0();                                   // initialized
    CStringW FUN_14187f210(int nResult);                    // upload result message
    CStringW FUN_14187f2e0(int nResult);
    void FUN_14187f380(int nMode);
    int FUN_14187f3b0();                                    // mode (1: uploads disabled)
    bool FUN_14187f3d0();                                    // open the equip upload
    bool FUN_14187f410();
    void FUN_14187f590(efd::SmartPointer<egf::Entity> spEntity);   // open the banner upload of a banner object
    void FUN_14187fb30();                                   // open the profile upload
    void FUN_14187fd80();                                   // open the wedding profile upload
    void FUN_14187ffe0();                                   // open the guild mark upload
    void FUN_141880230(CString strName, int nIndex);        // open a guild poster upload
    bool FUN_141880490(MS2Ptr<CUgcUploadCtrl> spCtrl);
    void FUN_141880600(MS2Ptr<Unk_CharListEntry> spEntry);  // upload a shot of a character as its profile image
    void FUN_141880c90(MS2Ptr<CUploadFile> spFile);         // upload a file as the profile image
    void FUN_141880ec0(int nResult);                        // the server answered the upload
    int FUN_141880fc0();                                    // the current upload has content
    int FUN_1418810c0(const CStringW& strDir, const wchar_t* szFilter);   // copy a picked design image
    int FUN_141881650(int nType, MS2Ptr<CUploadFile> spFile);   // preview a file
    int FUN_141881800(int nType, int nIndex);
    int FUN_141881890(int nIndex);                          // the file is the one of the current upload
    int FUN_141881a40(int nIndex);
    int FUN_141881ac0(MS2Ptr<CUploadFile> spFile);          // the file exists
    int FUN_141881b90(int nType, int nCount, CStringW strName, __int64 uid, int nFlags);   // send an item upload
    int FUN_141882020();                                    // start sending the current upload
    int FUN_141882370();                                    // lock (4: locked already)
    int FUN_1418823f0();                                    // unlock
    void FUN_141882450(MS2Ptr<CUgcUploadCtrl> spCtrl);      // set the current upload
    MS2Ptr<CUgcUploadCtrl> FUN_141882610();                 // the current upload
    void FUN_1418826a0(int nResult);                        // show an upload result
    void FUN_1418829b0(int nType);                          // open the upload directory in the explorer
    int FUN_141882a70(int nIndex, int bImageOnly);          // open a file in Paint
    void FUN_141883170();
    MS2Ptr<CUploadFile> FUN_14188a4b0(int nIndex);          // the local file at nIndex
    int FUN_14188bfd0(const CStringW& strPath, struct _D3DXIMAGE_INFO* pInfo);   // the image size of a file
    void FUN_14188aae0();
    void FUN_14188aca0();                                   // create the Custom directories
    void FUN_14188b480();
    void FUN_14188b4e0();
    void FUN_14188bb20();
    void FUN_14188bbb0();
    void FUN_14188bce0();
    MS2Ptr<CUgcBannerRollingImage> FUN_14188c300(int nBannerId);  // the active rolling image of a banner
    void FUN_14188c9e0();                                   // the upload file types
    void FUN_14188cab0();
    int FUN_14188fdb0(int nDialog);                         // open one upload dialog, close the others

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x08
    int m_bInit;                                            // +0x38
    int m_nMode;                                            // +0x3c 1: uploads are disabled
    bool m_bReserveChanged;                                 // +0x40
    int m_bLocked;                                          // +0x44 an upload is being sent
    MS2Ptr<CUgcUploadCtrl> m_spUpload;                      // +0x48 the current upload
    CAtlArray<MS2Ptr<CUploadFile> > m_files;                // +0x58
    CAtlArray<CStringW> m_extensions;                       // +0x78 the file types an upload may use
    CCtrlMap m_mapDownload;                                 // +0x98
    std::set<CString> m_setC8;                              // +0xc8
    CRBMap<int, MS2Ptr<CUgcRegistBanner> > m_mapBanner;     // +0xd8 banner id -> registration
    CRBMap<int, Unk_UgcBoxPtr<CReserveMap> > m_mapReserve;  // +0x108 banner id -> reservations
    CRBMap<int, efd::SmartPointer<NiTexture> > m_mapTexture;   // +0x138 object id -> image
    efd::SmartPointer<NiTexture> m_spDefaultTexture;        // +0x168
    CAtlArray<MS2Ptr<CUgcBannerRollingImage> > m_rollingImages;   // +0x170
    std::map<CStringW, CStringW> m_map190;                  // +0x190
    __int64 m_n1a0;                                         // +0x1a0
    CString m_str1a8;                                       // +0x1a8
    CStringW m_str1b0;                                      // +0x1b0
    CStringW m_str1b8;                                      // +0x1b8
};
MS2_CHECK_SIZE(CUgcManager, 0x1c0);
MS2_CHECK_OFFSET(CUgcManager, m_spUpload, 0x48);
MS2_CHECK_OFFSET(CUgcManager, m_mapDownload, 0x98);
MS2_CHECK_OFFSET(CUgcManager, m_mapReserve, 0x108);
MS2_CHECK_OFFSET(CUgcManager, m_spDefaultTexture, 0x168);
MS2_CHECK_OFFSET(CUgcManager, m_map190, 0x190);
