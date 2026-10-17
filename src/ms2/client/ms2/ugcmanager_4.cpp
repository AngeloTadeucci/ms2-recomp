// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Fourth translation unit of the client UGC code (the queue
// entry client\ms2\ugcmanager.cpp spans four TUs; see ugcmanager.h): CUploadFile, a local image the player can
// upload, and CUgcManager, which drives the uploads (one CUgcUploadCtrl at a time, previewed by its dialog) and places
// the downloaded UGC images on the field objects.
// MS2-UNIT: client\ms2\ugcmanager.cpp#4
// MS2-RANGE: 0x14187e3d0-0x14189cd00 .text$mn
// MS2-RANGE: 0x14010f2d0-0x14010f440 .text$di
// MS2-RANGE: 0x142cbc530-0x142cbc5c0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugcmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/header_statics_a.h"

#include <io.h>
#include <egf/Entity.h>
#include <NiImageConverter.h>
#include <NiRect.h>
#include <NiSourceTexture.h>

#include "ugcmanager.h"
#include "blockmanager.h"
#include "guildmanager.h"
#include "uiservice.h"
#include "uidialog.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cugcuploadctrl.h"
#include "ms2/placeholder/exception.h"
#include "ms2/unnamed/unit_1401b6d10.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- callees ------------------------------------------------------------------------------------------------------

CUIService* FUN_1403ed2b0();
CGuildManager* FUN_1403ed290();
void FUN_141275260(int nStringId, int nA, int nB);          // system message
CStringW FUN_1408116a0(int nId, const int& nArg);           // string table entry with one integer argument

// Block checks (blockmanager.cpp).
void FUN_140a30ad0(const BlockPtr& rec, int action, unsigned long long cb);
CBlockManager* FUN_140a6a830();

// The event log: "upload_exception" reports.
class Unk_UgcEventLog
{
public:
    void FUN_140a1f970(const CString& strEvent, const CString& strArg);
};
Unk_UgcEventLog* FUN_140d8ee90();
CString FUN_140741200(const char* szFormat, const CString& a1, const CString& a2);   // "{0} {1}" formatter

// UGC paths.
CStringW FUN_141026b20(const CStringW& strTitle);           // the thumbnail dir of a file title
CStringW FUN_141026c50(const CStringW& strTitle);           // the thumbnail file of a file title
CString FUN_14016a600(const wchar_t* psz, int nCodePage);   // wide to multi-byte
void FUN_1418fe1c0(const CString& strUrl);                  // open a web page

// The world service: the current map.
class Unk_UgcWorld
{
public:
    PCBase* FUN_141bd0cc0();                                // the player
    int FUN_141bd0dd0(efd::Point3& kA, efd::Point3& kB);
    unsigned FUN_141bd3060();
};
Unk_UgcWorld* FUN_1403ed2d0();

// The game settings; FUN_14036d570 tests a content switch.
class Unk_UgcSettings
{
public:
    bool FUN_14036d570(int nId);
};
Unk_UgcSettings* FUN_140166410();

// A client config singleton; +0xb0 is the default UGC image.
class Unk_UgcClientPaths
{
public:
    void* m_pad[0xb0 / 8];
    CString m_strDefaultImage;                              // +0xb0
};
Unk_UgcClientPaths* FUN_1401d31f0();
NiImageConverter* FUN_141851720();
extern NiTexture::FormatPrefs DAT_1439fc800;                // NiSourceTexture's default format preferences

extern unsigned DAT_143ab2830;                              // my character's job/type
extern __int64 DAT_143ab2820;                               // my account id
extern __int64 DAT_143ab2828;                               // my character id
extern int DAT_143ab2914;                                   // my level

// The player and its effect points (the profile shot).
__int64 FUN_141656a80(PCBase* pPlayer);                     // the character id
NiAVObject* FUN_141675150(PCBase* pPlayer, const CString& strName);   // a named node of the player model
const efd::Point3& FUN_140947900(NiAVObject* pObject);      // the world translate of a node
class Unk_UgcCamera
{
public:
    bool FUN_140af0700(const efd::Point3& kWorld, efd::Point3& kScreen);   // world to screen
};
Unk_UgcCamera* FUN_1409478c0();
Unk_UgcFileResult SaveUgcThumbnailImage(NiRect<unsigned int> kRect, int nTarget);   // ugcmanager.cpp#1
CStringW FUN_141026ab0();                                   // ".\Custom\Thumbnail"
CStringW FUN_141026920(int nType);                          // the upload directory of an upload kind

// An entry of the character list dialog; +0x20 is the character id.
class Unk_CharListEntry : public CPtred
{
public:
    __int64 FUN_1418e9cb0();                                // the character id
};

// Messages and strings.
class IMessageListener;
void FUN_140d73aa0(CStringW strMessage, int nType, IMessageListener* pListener, CStringW strArg);   // message box
void FUN_140d73bc0(int nStringId, int nType, IMessageListener* pListener, CStringW strArg);         // message box
CStringW FUN_14028b8e0(const CStringW& strKey);             // a string table entry by key
CStringW FUN_14028de60(int nId);                            // a string table entry
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);   // string table entry with two integer arguments
CStringW FUN_140a2fcd0(__int64 tFrom, __int64 tTo);         // a remaining time text
void FUN_1412751b0(const CStringW& strText, int nType);     // chat notice
CStringW FUN_141b6e360(const CStringW& strDir, const wchar_t* szFilter, const CStringW& strFile);   // open-file dialog
int FUN_14102ac40(const CStringW& strPath, CAtlArray<CStringW>& parts);   // split a path (2: title, 3: extension)

// The upload kinds sent through the web server (0: through the game server).
int FUN_14088db30(int nType);
class Unk_UgcSoap
{
public:
    void FUN_14176feb0();                                   // send the upload request
};
Unk_UgcSoap* FUN_140b2e990();

// The upload dialogs (vfunc_55: the dialog is closed).
class UIUGCImageUploadDialog : public UIDialog
{
public:
    void FUN_141b3a690(int nResult);
};
class UIUGCItemEditDialog : public UIDialog
{
public:
    void FUN_141b450d0(int nResult);
};
class UIUGCBannerDialog : public UIDialog
{
public:
    void FUN_141b35480(int nResult);
};
UIUGCItemEditDialog* FUN_140eeff60(int nId);                // uiugccubepalettedialog.cpp

// The open dialog of a UI id (0 when it is not created).
template <class T>
T* UgcFindDialog(eUIClassID nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObject = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (spObject.get() != 0)
            return dynamic_cast<T*>((UIObject*)spObject);
    }
    return 0;
}

// ---- CUploadFile ----------------------------------------------------------------------------------------------------

// @0x14187e3d0
static HRESULT FUN_14187e3d0(unsigned uA, unsigned uB, unsigned* puOut)
{
    unsigned long long ull64Result = (unsigned long long)uA * uB;
    if (ull64Result <= 0xffffffffull)
    {
        *puOut = (unsigned)ull64Result;
        return 0;
    }
    return 0x80070216;
}

// @0x14187e420
CUploadFile::CUploadFile()
{
    m_strPath = "";
    m_strName = "";
    m_strThumbDir = "";
    m_tWrite = 0;
    m_tCreate = 0;
}

// @0x14187e540
void CUploadFile::Set(const CStringW& strPath, const CStringW& strName, __int64 tWrite, __int64 tCreate, int bThumbnail)
{
    m_strPath = strPath;
    m_strName = strName;
    m_tWrite = tWrite;
    m_tCreate = tCreate;
    if (m_strPath.GetLength() > 0)
        SplitPath(bThumbnail);
}

// @0x14187e5e0
void CUploadFile::SetInDir(const CStringW& strFile, const CStringW& strDir, __int64 tWrite, __int64 tCreate, int bThumbnail)
{
    CStringW strPath;
    strPath.Format(L"%s\\%s", (const wchar_t*)strDir, (const wchar_t*)strFile);
    wchar_t szDir[0x100] = {0};
    wchar_t szDrive[3] = {0};
    wchar_t szFname[0x100] = {0};
    wchar_t szExt[0x100] = {0};
    wchar_t szFullPath[0x104] = {0};
    _wfullpath(szFullPath, strPath, 0x104);
    _wsplitpath_s(szFullPath, szDrive, 3, szDir, 0x100, szFname, 0x100, szExt, 0x100);
    CStringW strName;
    strName.Format(L"%s%s", szFname, szExt);
    CStringW strFullPath(szFullPath);
    Set(strFullPath, strName, tWrite, tCreate, bThumbnail);
}

// @0x14187e800
void CUploadFile::SplitPath(int bThumbnail)
{
    wchar_t szDir[0x100] = {0};
    wchar_t szDrive[3] = {0};
    wchar_t szFname[0x100] = {0};
    wchar_t szExt[0x100] = {0};
    _wsplitpath_s(m_strPath, szDrive, 3, szDir, 0x100, szFname, 0x100, szExt, 0x100);
    m_strTitle = szFname;
    m_strExt = szExt;
    if (bThumbnail)
    {
        m_strThumbDir = FUN_141026b20(m_strTitle);
        m_strThumbPath = FUN_141026c50(m_strTitle);
    }
}

// @0x14187e9f0
CStringW CUploadFile::GetPath()
{
    return m_strPath;
}

// @0x14187ea40
CStringW CUploadFile::GetName()
{
    return m_strName;
}

// @0x14187ea90
__int64 CUploadFile::GetCreateTime()
{
    return m_tCreate;
}

// @0x14187eab0
__int64 CUploadFile::GetWriteTime()
{
    return m_tWrite;
}

// @0x14187ead0
void CUploadFile::SetWriteTime(__int64 t)
{
    m_tWrite = t;
}

// @0x14187eaf0
CStringW CUploadFile::GetTitle()
{
    return m_strTitle;
}

// @0x14187eb40
CStringW CUploadFile::GetExt()
{
    return m_strExt;
}

// @0x14187eb90
CStringW CUploadFile::GetThumbnailDir()
{
    return m_strThumbDir;
}

// @0x14187ebe0
CStringW CUploadFile::GetThumbnailPath()
{
    return m_strThumbPath;
}

// @0x14187ec30
// Picks up a newer write time of the file (1 when it changed). The changed path returns without closing the find
// handle.
int CUploadFile::Refresh()
{
    WIN32_FIND_DATAW fd;
    CStringW strPath = GetPath();
    HANDLE hFind = FindFirstFileW(strPath, &fd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        CFileTime ft(fd.ftLastWriteTime);
        __int64 tWrite = ft.GetTime();
        if (tWrite != GetWriteTime())
        {
            SetWriteTime(tWrite);
            return 1;
        }
        FindClose(hFind);
    }
    return 0;
}

// ---- CUgcManager ----------------------------------------------------------------------------------------------------

// @0x14187ed30
CUgcManager::CUgcManager()
    : m_bReserveChanged(false)
{
    FUN_14188aae0();
    FUN_14188aca0();
    FUN_14188c9e0();
    FUN_14188cab0();
    CFieldBannerData::LoadTable();
    m_bLocked = 0;
    m_n1a0 = 0;
    m_str1a8 = "";
    m_nMode = 0;
    {
        NiPixelDataPtr spPixelData = NiDynamicCast(NiImageConverter, FUN_141851720())->ReadImageFile((const char*)FUN_1401d31f0()->m_strDefaultImage, NULL);
        m_spDefaultTexture = NiSourceTexture::Create(spPixelData, DAT_1439fc800, true);
    }
    m_str1b0 = "";
    m_str1b8 = "";
}

// @0x14187eff0
CUgcManager::~CUgcManager()
{
    m_files.RemoveAll();
    m_extensions.RemoveAll();
    m_mapBanner.RemoveAll();
    m_mapReserve.RemoveAll();
    FUN_14188b480();
    FUN_14188b4e0();
    FUN_14188bb20();
}

// @0x14187f1c0
void CUgcManager::FUN_14187f1c0()
{
    FUN_14188bbb0();
    FUN_14188bce0();
}

// @0x14187f1f0
void CUgcManager::FUN_14187f1f0()
{
    m_bInit = 1;
}

// @0x14187f210
// The message of an upload result (0 and 0x7a have none).
CStringW CUgcManager::FUN_14187f210(int nResult)
{
    if (nResult == 0)
        return L"";
    if (nResult == 0x7a)
        return L"";
    CStringW str = FUN_1408116a0(0x461, nResult);
    return str;
}

// @0x14187f2e0
CStringW CUgcManager::FUN_14187f2e0(int nResult)
{
    if (nResult == 0)
        return L"";
    CStringW str = FUN_1408116a0(0x461, nResult);
    return str;
}

// @0x14187f380
void CUgcManager::FUN_14187f380(int nMode)
{
    if (m_nMode == nMode)
        return;
    m_nMode = nMode;
}

// @0x14187f3b0
int CUgcManager::FUN_14187f3b0()
{
    return m_nMode;
}

// @0x14187f3d0
bool CUgcManager::FUN_14187f3d0()
{
    if (FUN_14188fdb0(0x4e69) == 0)
        return false;
    return FUN_14187f410();
}

// @0x14187f410
// Starts an equip upload (dialog 0x4e69).
bool CUgcManager::FUN_14187f410()
{
    {
        int nAction = 3;
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(nAction);
        if (blocked.get() != 0)
        {
            FUN_140a30ad0(blocked, nAction, 0);
            return false;
        }
    }
    if (FUN_14187f3b0() == 1)
    {
        FUN_141275260(0x2e7, 1, 1);
        return false;
    }
    int nType = 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl(new CUgcUploadCtrl());
    spCtrl->FUN_1418a3840(nType);
    FUN_141882450(spCtrl);
    spCtrl->FUN_1418a3ab0(0x4e69);
    return true;
}

// @0x14187f590
// Starts the banner upload of a banner object (the entity's banner id); a rolling banner or an ad banner with a web
// page opens the page instead.
void CUgcManager::FUN_14187f590(efd::SmartPointer<egf::Entity> spEntity)
{
    if (FUN_14187f3b0() == 1)
    {
        FUN_141275260(0x2e7, 1, 1);
        return;
    }
    if (spEntity == (egf::Entity*)NULL)
        return;
    int nProperty = 0;
    spEntity->GetPropertyValue(0x819a96c0, nProperty);
    unsigned nMapId = FUN_1403ed2d0()->FUN_141bd3060();
    int nBannerId = nProperty;
    Unk_BannerPtr spBanner = CFieldBannerData::GetBanner(nBannerId);
    if (spBanner == NULL)
        return;
    if (spBanner->m_nField != nMapId)
        return;
    MS2Ptr<CUgcBannerRollingImage> spRolling = FUN_14188c300(nBannerId);
    if (spRolling.get() != 0 && !spRolling->m_str50.IsEmpty())
    {
        CStringW strUrl = spRolling->m_str50;
        FUN_1418fe1c0(FUN_14016a600(strUrl, 0));
        return;
    }
    if (spBanner->m_bAdmin == true && DAT_143ab2914 < 0x32)
    {
        FUN_141275260(0x2e6, 1, 0);
        return;
    }
    {
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(5);
        if (blocked.get() != 0)
        {
            FUN_140a30ad0(blocked, 5, 0);
            return;
        }
    }
    if (spBanner->m_nAd == 2 && !spBanner->m_strWebOpenURL.IsEmpty())
    {
        FUN_1418fe1c0(spBanner->m_strWebOpenURL);
        return;
    }
    int nType = 3;
    int nDialog = 0;
    if (spBanner->m_nAd == 1)
        nDialog = 0x4e70;
    else if (spBanner->m_nAd == 0)
        nDialog = 0x4e56;
    if (FUN_14188fdb0(nDialog) == 0)
        return;
    MS2Ptr<CUgcViewerBanner> spViewer(new CUgcViewerBanner());
    spViewer->FUN_1418a0f90(nBannerId);
    MS2Ptr<CUgcUploadCtrl> spCtrl(new CUgcUploadCtrl());
    spCtrl->FUN_1418a3840(nType);
    spCtrl->m_spViewer = spViewer;
    FUN_141882450(spCtrl);
    spCtrl->FUN_1418a3ab0(nDialog);
    FUN_1403ed2b0()->FUN_141adc750((eUIClassID)nDialog);
}

// @0x14187fb30
// Starts the profile image upload.
void CUgcManager::FUN_14187fb30()
{
    if (FUN_14187f3b0() == 1)
    {
        FUN_141275260(0x2e7, 1, 1);
        return;
    }
    {
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(3);
        if (blocked.get() != 0)
        {
            FUN_140a30ad0(blocked, 3, 0);
            return;
        }
    }
    if (FUN_14188fdb0(0x4e56) == 0)
        return;
    MS2Ptr<CUgcViewerProfile> spViewer(new CUgcViewerProfile());
    spViewer->m_user.m_nType = DAT_143ab2830;
    spViewer->m_user.m_accountId = DAT_143ab2820;
    spViewer->m_user.m_characterId = DAT_143ab2828;
    MS2Ptr<CUgcUploadCtrl> spCtrl(new CUgcUploadCtrl());
    spCtrl->FUN_1418a3840(5);
    spCtrl->m_spViewer = spViewer;
    FUN_141882450(spCtrl);
    spCtrl->FUN_1418a3ab0(0x4e56);
    FUN_1403ed2b0()->FUN_141adc750(eUI_4e56);
}

bool FUN_140900550();                                       // the wedding profile can be changed

// @0x14187fd80
// Starts the wedding profile image upload.
void CUgcManager::FUN_14187fd80()
{
    if (FUN_14187f3b0() == 1)
    {
        FUN_141275260(0x2e7, 1, 1);
        return;
    }
    {
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(3);
        if (blocked.get() != 0)
        {
            FUN_140a30ad0(blocked, 3, 0);
            return;
        }
    }
    if (!FUN_140900550())
        return;
    if (FUN_14188fdb0(0x4e56) == 0)
        return;
    MS2Ptr<CUgcViewerWeddingProfile> spViewer(new CUgcViewerWeddingProfile());
    spViewer->m_user.m_nType = DAT_143ab2830;
    spViewer->m_user.m_accountId = DAT_143ab2820;
    spViewer->m_user.m_characterId = DAT_143ab2828;
    MS2Ptr<CUgcUploadCtrl> spCtrl(new CUgcUploadCtrl());
    spCtrl->FUN_1418a3840(10);
    spCtrl->m_spViewer = spViewer;
    FUN_141882450(spCtrl);
    spCtrl->FUN_1418a3ab0(0x4e56);
    FUN_1403ed2b0()->FUN_141adc750(eUI_4e56);
}

// @0x14187ffe0
// Starts the guild mark upload.
void CUgcManager::FUN_14187ffe0()
{
    if (FUN_14187f3b0() == 1)
    {
        FUN_141275260(0x2e7, 1, 1);
        return;
    }
    {
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(8);
        if (blocked.get() != 0)
        {
            FUN_140a30ad0(blocked, 8, 0);
            return;
        }
    }
    if (FUN_14188fdb0(0x4e56) == 0)
        return;
    __int64 nGuildId = FUN_1403ed290()->FUN_1404ccbd0();
    if (nGuildId == 0)
        return;
    MS2Ptr<CUgcViewerGuildMark> spViewer(new CUgcViewerGuildMark());
    spViewer->m_mark.m_nGuildId = nGuildId;
    MS2Ptr<CUgcUploadCtrl> spCtrl(new CUgcUploadCtrl());
    spCtrl->FUN_1418a3840(6);
    spCtrl->m_spViewer = spViewer;
    FUN_141882450(spCtrl);
    spCtrl->FUN_1418a3ab0(0x4e56);
    FUN_1403ed2b0()->FUN_141adc750(eUI_4e56);
}

// @0x141880230
// Starts the guild poster upload of a poster slot.
void CUgcManager::FUN_141880230(CString strName, int nIndex)
{
    if (FUN_14187f3b0() == 1)
    {
        FUN_141275260(0x2e7, 1, 1);
        return;
    }
    if (FUN_14188fdb0(0x4e56) == 0)
        return;
    __int64 nGuildId = FUN_1403ed290()->FUN_1404ccbd0();
    if (nGuildId == 0)
        return;
    MS2Ptr<CUgcViewerGuildPoster> spViewer(new CUgcViewerGuildPoster());
    spViewer->m_poster.m_nGuildId = nGuildId;
    spViewer->m_poster.m_strName = strName;
    spViewer->m_poster.m_nIndex = nIndex;
    MS2Ptr<CUgcUploadCtrl> spCtrl(new CUgcUploadCtrl());
    spCtrl->FUN_1418a3840(8);
    spCtrl->m_spViewer = spViewer;
    FUN_141882450(spCtrl);
    spCtrl->FUN_1418a3ab0(0x4e56);
    FUN_1403ed2b0()->FUN_141adc750(eUI_4e56);
}

// @0x141880490
// Shows a prepared upload in the upload dialog.
bool CUgcManager::FUN_141880490(MS2Ptr<CUgcUploadCtrl> spCtrl)
{
    if (spCtrl == 0)
        return false;
    if (FUN_14187f3b0() == 1)
    {
        FUN_141275260(0x2e7, 1, 1);
        return false;
    }
    if (!FUN_140166410()->FUN_14036d570(0xe9))
        return false;
    FUN_1403ed2b0()->FUN_141adc690(eUI_4e56);
    if (FUN_14188fdb0(0x4e56) == 0)
        return false;
    FUN_141882450(spCtrl);
    spCtrl->FUN_1418a3ab0(0x4e56);
    FUN_1403ed2b0()->FUN_141adc750(eUI_4e56);
    return true;
}

// @0x141880600
// Uploads a shot of a character as its profile image: the screen rect between the "Eff_UI" and "Eff_Body" points of
// the player, saved as a thumbnail image (the character list dialog asks for it).
void CUgcManager::FUN_141880600(MS2Ptr<Unk_CharListEntry> spEntry)
{
    if (spEntry == 0)
        return;
    efd::Point3 kA;
    efd::Point3 kB;
    if (FUN_1403ed2d0()->FUN_141bd0dd0(kB, kA) == 0)
        return;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    NiAVObject* pUI = FUN_141675150(pPlayer, "Eff_UI");
    if (pUI == 0)
        return;
    NiAVObject* pBody = FUN_141675150(pPlayer, "Eff_Body");
    if (pBody == 0)
        return;
    efd::Point3 kTop;
    efd::Point3 kBottom;
    NiRect<unsigned int> kRect;
    if (!FUN_1409478c0()->FUN_140af0700(FUN_140947900(pUI), kTop) || !FUN_1409478c0()->FUN_140af0700(FUN_140947900(pBody), kBottom))
        return;
    int n = (int)(kBottom.y - kTop.y);
    int nMargin = (int)(n * 0.2f);
    kRect.m_top = (unsigned int)(kTop.y + nMargin);
    kRect.m_bottom = (unsigned int)(kBottom.y - nMargin * 0.5f);
    n = kRect.m_bottom - kRect.m_top;
    n = (int)(n * 0.5);
    kRect.m_left = (unsigned int)(kTop.x - n);
    kRect.m_right = (unsigned int)(kTop.x + n);
    Unk_UgcFileResult result = SaveUgcThumbnailImage(kRect, 1);
    if (result.m_nResult != 0)
        return;
    MS2Ptr<CUgcViewerProfile> spViewer(new CUgcViewerProfile());
    spViewer->m_user.m_nType = DAT_143ab2830;
    spViewer->m_user.m_accountId = DAT_143ab2820;
    spViewer->m_user.m_characterId = spEntry->FUN_1418e9cb0();
    MS2Ptr<CUploadFile> spFile(new CUploadFile());
    spFile->SetInDir(result.m_strPath, FUN_141026ab0(), 0, 0, 1);
    MS2Ptr<CUgcUploadCtrl> spCtrl(new CUgcUploadCtrl());
    spCtrl->FUN_1418a3840(5);
    CUgcUserProxy* pUser = &spCtrl->m_user;
    pUser->CopyFrom(&spViewer->m_user);
    spCtrl->m_spViewer = spViewer;
    spCtrl->m_spFile = spFile;
    FUN_141882450(spCtrl);
    FUN_141882020();
}

// @0x141880c90
// Uploads a local image file as the player's profile image.
void CUgcManager::FUN_141880c90(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    MS2Ptr<CUgcViewerProfile> spViewer(new CUgcViewerProfile());
    spViewer->m_user.m_nType = DAT_143ab2830;
    spViewer->m_user.m_accountId = DAT_143ab2820;
    spViewer->m_user.m_characterId = FUN_141656a80(pPlayer);
    MS2Ptr<CUgcUploadCtrl> spCtrl(new CUgcUploadCtrl());
    spCtrl->FUN_1418a3840(5);
    spCtrl->m_spViewer = spViewer;
    spCtrl->m_spFile = spFile;
    FUN_141882450(spCtrl);
    FUN_141882020();
}

// @0x141880ec0
// The server answered the current upload; a finished upload unlocks the manager and is dropped.
void CUgcManager::FUN_141880ec0(int nResult)
{
    int bDone = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (m_spUpload == 0)
            return;
        m_spUpload->FUN_1418a3af0(nResult);
        if (m_spUpload->m_upload.m_nType == 0)
            bDone = 1;
    }
    if (bDone)
    {
        FUN_1418823f0();
        FUN_141882450(MS2Ptr<CUgcUploadCtrl>(0));
    }
}

// @0x141880fc0
// 1 when the viewer of the current upload has content to send.
int CUgcManager::FUN_141880fc0()
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return 0;
    if (spCtrl->m_spViewer == 0)
        return 0;
    int bContent = spCtrl->m_spViewer->vfunc_2();
    if (bContent == 0)
        return 0;
    return 1;
}

// @0x1418810c0
// Lets the player pick a design image (at most UGCImgUploadSizeLimit pixels wide and high) and copies it into the
// upload directory of the current upload kind.
int CUgcManager::FUN_1418810c0(const CStringW& strDir, const wchar_t* szFilter)
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return 0;
    int nType = spCtrl->m_nType;
    if (nType == 0)
    {
        FUN_140d73aa0(FUN_14028b8e0(L"s_msg_ugc_fail_select_design"), 0, 0, L"");
        return 0;
    }
    CStringW strFile = FUN_141b6e360(strDir, szFilter, L"");
    if (strFile.IsEmpty())
        return 0;
    if (_waccess(strFile, 0) != 0)
        return 0;
    D3DXIMAGE_INFO info;
    if (!FUN_14188bfd0(strFile, &info))
        return 0;
    int nLimit = FUN_1401d3200()->UGCImgUploadSizeLimit.Read();
    if ((int)info.Width > nLimit || (int)info.Height > nLimit)
    {
        FUN_140d73aa0(FUN_140811740(0x2ea, nLimit, nLimit), 0, 0, L"");
        return 0;
    }
    CAtlArray<CStringW> parts;
    int nError = FUN_14102ac40(strFile, parts);
    if (nError != 0)
        return 0;
    CStringW strDst;
    strDst.Format(L"%s\\%s%s", (const wchar_t*)FUN_141026920(nType), (const wchar_t*)parts[2], (const wchar_t*)parts[3]);
    BOOL bCopied = CopyFileW(strFile, strDst, 1);
    if (bCopied == 0)
    {
        FUN_140d73bc0(0x2e9, 0, 0, L"");
        return 0;
    }
    return 1;
}

// @0x141881650
// Previews a local file in the viewer of the current upload (when it is an upload of kind nType).
int CUgcManager::FUN_141881650(int nType, MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return 0;
    if (spCtrl->m_nType != nType)
        return 0;
    if (spCtrl->m_spViewer == 0)
        return 0;
    return spCtrl->m_spViewer->vfunc_3(spFile);
}

// @0x141881800
int CUgcManager::FUN_141881800(int nType, int nIndex)
{
    MS2Ptr<CUploadFile> spFile = FUN_14188a4b0(nIndex);
    return FUN_141881650(nType, spFile);
}

// @0x141881890
// 1 when the file at nIndex exists and is the file of the current upload.
int CUgcManager::FUN_141881890(int nIndex)
{
    MS2Ptr<CUploadFile> spFile = FUN_14188a4b0(nIndex);
    if (spFile == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return 0;
    if (spCtrl->m_spFile.get() != spFile.get())
        return 0;
    return 1;
}

// @0x141881a40
int CUgcManager::FUN_141881a40(int nIndex)
{
    MS2Ptr<CUploadFile> spFile = FUN_14188a4b0(nIndex);
    return FUN_141881ac0(spFile);
}

// @0x141881ac0
// 1 when the file still exists on disk.
int CUgcManager::FUN_141881ac0(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    return 1;
}

// @0x141881b90
// Sends the current item upload (equip, cube or mount): fills the item proxy of its viewer and starts the upload.
int CUgcManager::FUN_141881b90(int nType, int nCount, CStringW strName, __int64 uid, int nFlags)
{
    if (nType != 1 && nType != 2 && nType != 7)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0 || spCtrl->m_spViewer == 0)
        return 0;
    if (spCtrl->m_nType != nType)
        return 0;
    MS2Ptr<IUgcViewer> spViewer = spCtrl->m_spViewer;
    CUgcItemProxy* pItem = 0;
    if (nType == 1)
    {
        MS2Ptr<CUgcViewerEquip> spEquip(dynamic_cast<CUgcViewerEquip*>((IUgcViewer*)spViewer));
        if (spEquip == 0)
            return 0;
        pItem = &spEquip->m_item;
    }
    else if (nType == 2)
    {
        MS2Ptr<CUgcViewerCube> spCube(dynamic_cast<CUgcViewerCube*>((IUgcViewer*)spViewer));
        if (spCube == 0)
            return 0;
        pItem = &spCube->m_item;
    }
    else if (nType == 7)
    {
        MS2Ptr<CUgcViewerRidee> spRidee(dynamic_cast<CUgcViewerRidee*>((IUgcViewer*)spViewer));
        if (spRidee == 0)
            return 0;
        pItem = &spRidee->m_item;
    }
    if (pItem != 0)
    {
        pItem->m_nCount = nCount;
        pItem->m_strName = strName;
        pItem->m_nRarity = 1;
        pItem->m_uid = uid;
        pItem->m_nFlags = nFlags;
    }
    int nResult = FUN_141882020();
    if (nResult != 0)
    {
        FUN_1418826a0(nResult);
        return 0;
    }
    return 1;
}

// @0x141882020
// Starts sending the current upload (0 = started, else an upload result code).
int CUgcManager::FUN_141882020()
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return 0xd;
    if (spCtrl->m_spFile == 0)
        return 0xb;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0xc;
    int nResult = FUN_141882370();
    if (nResult != 0)
        return nResult;
    int bDirect = FUN_14088db30(spCtrl->m_nType);
    if (bDirect != 0)
    {
        {
            BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(3);
            if (blocked.get() != 0)
                return 0x7a;
        }
        FUN_141883170();
        nResult = 0;
    }
    else
    {
        try
        {
            spCtrl->m_upload.m_uid = 0;
            spCtrl->m_upload.m_strName = "";
            spCtrl->m_upload.m_nType = 1;
            BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(3);
            if (blocked.get() != 0)
            {
                nResult = 0x7a;
            }
            else
            {
                int nError = spCtrl->FUN_1418a3b80(0);
                if (nError != 0)
                    throw Exception(CString("error PreUpload"), nError);
                FUN_140b2e990()->FUN_14176feb0();
                nError = 0;
            }
        }
        catch (Exception& e)
        {
            nResult = e.GetCode();
        }
        FUN_1418826a0(nResult);
    }
    return nResult;
}

// @0x141882370
// Locks the manager for an upload (4 when an upload is being sent already).
int CUgcManager::FUN_141882370()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (m_bLocked == 1)
            return 4;
        m_bLocked = 1;
    }
    return 0;
}

// @0x1418823f0
int CUgcManager::FUN_1418823f0()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_bLocked = 0;
    }
    return 0;
}

// @0x141882450
// Makes spCtrl the current upload; asserts that no upload is being sent.
void CUgcManager::FUN_141882450(MS2Ptr<CUgcUploadCtrl> spCtrl)
{
    int bReport = 0;
    CString strPrev;
    CString strNext;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (m_bLocked != 0)
        {
            MS2_ASSERT_AT(0x6ac, 0);
            throw Exception(CString("err: UgcManager is locked"));
        }
        m_spUpload = spCtrl;
    }
    if (bReport)
    {
        static bool s_bReport = true;
        if (s_bReport)
        {
            s_bReport = false;
            if (FUN_140d8ee90())
            {
                CString strMessage = FUN_140741200("prevCtrl {0}, nextCtrl {1}", strPrev, strNext);
                FUN_140d8ee90()->FUN_140a1f970("upload_exception", strMessage);
            }
        }
    }
}

// @0x141882610
// The current upload (taken under the lock).
// MS2-FUNCTIONAL: the failed-lock path falls off the end (no return value); the exe has one more nop after the guard dtor
MS2Ptr<CUgcUploadCtrl> CUgcManager::FUN_141882610()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        return m_spUpload;
    }
}

// @0x1418826a0
// Shows an upload result in the dialog of the current upload; a failed upload is dropped (and unlocks the manager).
void CUgcManager::FUN_1418826a0(int nResult)
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return;
    if (spCtrl->FUN_1418a3ad0() == 0x4e56)
    {
        UIUGCImageUploadDialog* pDialog = UgcFindDialog<UIUGCImageUploadDialog>(eUI_4e56);
        if (pDialog != 0 && pDialog->vfunc_55() == 0)
            pDialog->FUN_141b3a690(nResult);
    }
    else if (spCtrl->FUN_1418a3ad0() == 0x4e69)
    {
        UIUGCItemEditDialog* pDialog = FUN_140eeff60(0x4e69);
        if (pDialog != 0 && pDialog->vfunc_55() == 0)
            pDialog->FUN_141b450d0(nResult);
    }
    else if (spCtrl->FUN_1418a3ad0() == 0x4e70)
    {
        UIUGCBannerDialog* pDialog = UgcFindDialog<UIUGCBannerDialog>(eUI_4e70);
        if (pDialog != 0 && pDialog->vfunc_55() == 0)
            pDialog->FUN_141b35480(nResult);
    }
    if (nResult != 0)
    {
        if (spCtrl->m_spViewer.get() != 0)
            spCtrl->m_spViewer->vfunc_4();
        FUN_1418823f0();
        FUN_141882450(MS2Ptr<CUgcUploadCtrl>(0));
    }
    if (nResult == 0x7a)
    {
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(3);
        if (blocked.get() != 0)
        {
            CStringW strTitle = FUN_14028de60(0x446);
            CStringW strTime = FUN_140a2fcd0((__int64)blocked->m_38, blocked->expiry);
            FUN_1412751b0(strTitle + strTime, 0x14);
        }
    }
}

// @0x1418829b0
// Opens the upload directory of an upload kind in the explorer.
void CUgcManager::FUN_1418829b0(int nType)
{
    CStringW strDir = FUN_141026920(nType);
    wchar_t szFullPath[0x104] = {0};
    _wfullpath(szFullPath, strDir, 0x104);
    ShellExecuteW(0, L"open", L"explorer", szFullPath, 0, 1);
}

// @0x141882a70
// Opens the file at nIndex in Paint (with bImageOnly, only a .png or .jpg file).
int CUgcManager::FUN_141882a70(int nIndex, int bImageOnly)
{
    MS2Ptr<CUploadFile> spFile = FUN_14188a4b0(nIndex);
    if (spFile == 0)
        return 0;
    if (bImageOnly != 0 && spFile->GetExt().CompareNoCase(L".png") != 0 && spFile->GetExt().CompareNoCase(L".jpg") != 0)
    {
        FUN_141275260(0x2de, 1, 1);
        return 0;
    }
    CStringW strCommand;
    strCommand.Format(L"mspaint \"%s\"", (const wchar_t*)spFile->GetPath());
    STARTUPINFOW si;
    memset(&si, 0, sizeof(si));
    si.cb = sizeof(si);
    PROCESS_INFORMATION pi;
    memset(&pi, 0, sizeof(pi));
    if (CreateProcessW(0, strCommand.GetBuffer(), 0, 0, 0, 0, 0, 0, &si, &pi))
    {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    return 1;
}

// @0x14188bfd0
int CUgcManager::FUN_14188bfd0(const CStringW& strPath, D3DXIMAGE_INFO* pInfo)
{
    HRESULT hr = D3DXGetImageInfoFromFileW(strPath, pInfo);
    if (FAILED(hr))
        return 0;
    return 1;
}

// @0x14188fdb0
// Only one of the upload dialogs is open: opening nDialog closes the other two (0 when it cannot open).
int CUgcManager::FUN_14188fdb0(int nDialog)
{
    if (nDialog == 0x4e56)
    {
        if (FUN_1403ed2b0()->FUN_141adc940(eUI_4e56) == 0)
            return 0;
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e69);
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e70);
    }
    else if (nDialog == 0x4e69)
    {
        if (FUN_1403ed2b0()->FUN_141adc940(eUI_4e69) == 0)
            return 0;
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e56);
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e70);
    }
    else if (nDialog == 0x4e70)
    {
        if (FUN_1403ed2b0()->FUN_141adc940(eUI_4e70) == 0)
            return 0;
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e56);
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e69);
    }
    return 1;
}
