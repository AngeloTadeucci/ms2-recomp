// cugcuploadctrl.h - PLACEHOLDER for CUgcUploadCtrl (RTTI .?AVCUgcUploadCtrl@@, 0xe8 bytes, vftable 0x142f8f020) and the
// IUgcViewer family (vftable 0x142f8eb98, 13 slots; the profile / banner / guild viewers add slot 13). NOT an original
// header. The classes are defined in ?\ugcviewerequip.cpp (0x14189eae0-); the layouts and the methods declared here
// are the ones CUgcManager (client\ms2\ugcmanager.cpp#4) uses.
//
// An upload in progress: the content kind, the owner and the upload proxies that go to the server, the viewer that
// previews the content in its dialog and the local file to send.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/ugcdef.h"

class CUploadFile;

// The preview of an upload kind (equip, cube, banner, profile, guild mark, ...).
class IUgcViewer : public CPtred
{
public:
    IUgcViewer();
    virtual ~IUgcViewer();                                  // 0
    virtual void vfunc_1();                                 // 1
    virtual int vfunc_2();                                  // 2 the viewer has content to upload
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile) = 0;    // 3 preview a local file
    virtual void vfunc_4() = 0;                             // 4 the upload finished
    virtual void vfunc_5();                                 // 5
    virtual void vfunc_6(int nResult);                      // 6 the upload failed
    virtual void vfunc_7();                                 // 7
    virtual int vfunc_8(CStringW strPath);                  // 8
    virtual void vfunc_9();                                 // 9
    virtual void vfunc_10();                                // 10
    virtual void vfunc_11() = 0;                            // 11
    virtual void vfunc_12(__int64 itemUid);                 // 12 an item to preview
};
MS2_CHECK_SIZE(IUgcViewer, 0x18);

// The item viewers (equip / cube / mount): the item proxy of the upload at +0x18 (only the fields CUgcManager sets are
// used; the classes are not created here).
class CUgcViewerEquip : public IUgcViewer
{
public:
    CUgcItemPC m_item;                                      // +0x18
};
MS2_CHECK_OFFSET(CUgcViewerEquip, m_item, 0x18);

class CUgcViewerCube : public IUgcViewer
{
public:
    CUgcItemCube m_item;                                    // +0x18
};
MS2_CHECK_OFFSET(CUgcViewerCube, m_item, 0x18);

class CUgcViewerRidee : public IUgcViewer
{
public:
    CUgcItemRidee m_item;                                   // +0x18
};
MS2_CHECK_OFFSET(CUgcViewerRidee, m_item, 0x18);

class CUgcViewerProfile : public IUgcViewer
{
public:
    CUgcViewerProfile();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_11();
    CUgcUserProxy m_user;                                   // +0x18
    char m_pad_58[0x60 - 0x58];
};
MS2_CHECK_SIZE(CUgcViewerProfile, 0x60);

class CUgcViewerWeddingProfile : public IUgcViewer
{
public:
    CUgcViewerWeddingProfile();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_11();
    CUgcUserProxy m_user;                                   // +0x18
    char m_pad_58[0x60 - 0x58];
};
MS2_CHECK_SIZE(CUgcViewerWeddingProfile, 0x60);

class CUgcViewerGuildMark : public IUgcViewer
{
public:
    CUgcViewerGuildMark();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_11();
    CUgcGuildMarkProxy m_mark;                              // +0x18
    char m_pad_40[0x48 - 0x40];
};
MS2_CHECK_SIZE(CUgcViewerGuildMark, 0x48);

class CUgcViewerGuildPoster : public IUgcViewer
{
public:
    CUgcViewerGuildPoster();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_11();
    CUgcGuildPosterProxy m_poster;                          // +0x18
    char m_pad_48[0x50 - 0x48];
};
MS2_CHECK_SIZE(CUgcViewerGuildPoster, 0x50);

class CUgcViewerBanner : public IUgcViewer
{
public:
    CUgcViewerBanner();
    virtual int vfunc_3(MS2Ptr<CUploadFile> spFile);
    virtual void vfunc_4();
    virtual void vfunc_11();
    void FUN_1418a0f90(int nBannerId);                      // the banner to preview
    char m_pad_18[0x88 - 0x18];
};
MS2_CHECK_SIZE(CUgcViewerBanner, 0x88);

class CUgcUploadCtrl : public CPtred
{
public:
    CUgcUploadCtrl();
    virtual ~CUgcUploadCtrl();
    void FUN_1418a3840(int nType);                          // set the content kind
    void FUN_1418a3ab0(int nDialog);                        // set the dialog that shows the upload
    int FUN_1418a3ad0();                                    // the dialog that shows the upload
    void FUN_1418a3af0(int nResult);
    int FUN_1418a3b80(__int64 uid);                         // prepare the upload (0 = ok)
    int FUN_1418a38a0();
    MS2Ptr<CUgcUploadCtrl> FUN_1418a4100();

    int m_nType;                                            // +0x18 the content kind
    CUgcUserProxy m_user;                                   // +0x20
    CUgcUploadProxy m_upload;                               // +0x60
    MS2Ptr<IUgcViewer> m_spViewer;                          // +0x98
    MS2Ptr<CUploadFile> m_spFile;                           // +0xa8
    __int64 m_itemUid;                                      // +0xb8
    char m_pad_c0[0xe8 - 0xc0];
};
MS2_CHECK_SIZE(CUgcUploadCtrl, 0xe8);
MS2_CHECK_OFFSET(CUgcUploadCtrl, m_spViewer, 0x98);
