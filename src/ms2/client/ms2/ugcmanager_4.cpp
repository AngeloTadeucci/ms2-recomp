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
#include <comutil.h>
#include <egf/Entity.h>
#include <NiImageConverter.h>
#include <NiRect.h>
#include <NiSourceTexture.h>
#include <NiTexturingProperty.h>

#include "ugcmanager.h"
#include "blockmanager.h"
#include "guildmanager.h"
#include "uiservice.h"
#include "uidialog.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "statemanager.h"
#include "ridee.h"
#include "ms2/placeholder/cube.h"
#include "itemugcmesh.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/cugcdownloaddown.h"
#include "ms2/placeholder/cugcgetcosttable.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cugcuploadctrl.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/ms2format.h"
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
class Unk_UgcWearer;
class Unk_UgcWorld
{
public:
    PCBase* FUN_141bd0cc0();                                // the player
    Unk_UgcWearer* FUN_141bd1290(int nObjectId);            // a player by object id
    egf::Entity* FUN_141bd04d0(int nObjectId);              // an entity by object id
    Unk_UgcBoxPtr<CAtlList<efd::SmartPointer<egf::Entity> > > FUN_141bd0420(unsigned nModel);   // the entities of a model
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
CStringW FormatStringId(int nId, const fmt::ArgList& args);   // a string table entry with {0} arguments
FMT_VARIADIC_W(CStringW, FormatStringId, int)
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);   // equal to a literal
void FUN_140841420(CStringW& str);                         // lower case
CString FUN_1410272e0(CString strName);                     // the cache key of a downloaded file
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
    int FUN_14176feb0();                                    // send the upload request
    void FUN_14176fcf0(CString strUrl, int nResult);        // an upload answer of the web server
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
    void FUN_141b45020();                                   // drop the edited item
    void FUN_141b45180(MS2Ptr<CItem> spItem);               // the look of the edited item changed
};
class UIUGCBannerDialog : public UIDialog
{
public:
    void FUN_141b35480(int nResult);
    int FUN_141b35540(MS2Ptr<CUgcPreReserve> spReserve);    // the reservations of the banner (0 = ok)
};
UIUGCItemEditDialog* FUN_140eeff60(int nId);                // uiugccubepalettedialog.cpp

CStateService* FUN_140aa6d30();                             // the state service
CUgcManager* FUN_14052d220();                               // the UGC manager singleton

// The kinds whose upload is answered by the game server (0: the file goes through the web server first).
int FUN_14088db90(int nType);

// The character select dialog (0x4ef1): a character's new profile image.
class Unk_CharSelectDialog
{
public:
    void FUN_1418ed4e0(__int64 characterId, CString strPath);
    void FUN_1418ed5a0(__int64 characterId, CString strUrl);
};
Unk_CharSelectDialog* FUN_140b72de0(int nId);

// The download paths of the uploaded kinds 0xc9 / 0xd1.
CString FUN_141027880(const CString& strPath);
CString FUN_141027a20(const CString& strPath);

// ---- the item records the download requests read ----

class Unk_ItemEquipData : public CItemData { };             // CItem::FUN_140527840's record (item.cpp)
int FUN_14088dcf0(MS2Ptr<CItemData> spData);                // the UGC kind of an item record (1 equip, 2 cube, 7 mount, 9 blueprint)
CString FUN_1410280d0(int nKind, CString strUrl);           // the local file of a downloaded UGC url

// A cube item (cubeiteminfo.h; spelled here because that header has its own CUgcItemLook).
class CubeItemInfo : public CPtred
{
public:
    int FUN_1408b3860();                                    // the cube has a UGC look
    int itemId;                                             // +0x18
    __int64 instanceId;                                     // +0x20
    int count;                                              // +0x28
    MS2Ptr<CUgcItemLook> look;                              // +0x30
};
MS2_CHECK_OFFSET(CubeItemInfo, look, 0x30);

// ---- Delegate<CString(const CString&)>: the url of a download kind ----

// The empty-delegate error.
class InvalidCallException : public std::exception
{
public:
    InvalidCallException();                                 // 0x14056be40
};

template <class R>
R ThrowInvalidCall()
{
    throw InvalidCallException();
}

typedef Delegate<CString(const CString&)> Unk_UgcUrlFn;

template <> inline Unk_UgcUrlFn::DelegateImplBase::DelegateImplBase()
{
}
template <> inline Unk_UgcUrlFn::DelegateImplBase::~DelegateImplBase()
{
}
template <> template <> inline CString Unk_UgcUrlFn::DelegateImpl<CString (*)(const CString&)>::vfunc_2(const CString& a1)
{
    return m_f(a1);
}
template <> inline Unk_UgcUrlFn::Delegate(const Delegate& o)
{
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
}
template <> inline Unk_UgcUrlFn::~Delegate()
{
    if (m_pImpl)
        delete m_pImpl;
}
template <> inline CString Unk_UgcUrlFn::operator()(const CString& a1) const
{
    if (m_pImpl == 0)
        ThrowInvalidCall<CString>();
    return m_pImpl->vfunc_2(a1);
}

// The day picked in the banner dialog.
struct Unk_BannerDay
{
    int m_0;                                                // +0x00
    int m_4;                                                // +0x04
    int m_nDate;                                            // +0x08
};

CUgcDownloadDown* FUN_1414a57f0();                          // the download queue
// The scene-graph texture cache (ugcmanager.cpp#1 keeps the same declaration).
class Unk_UgcTextureCache
{
public:
    NiTexturePtr FUN_141553eb0(CString strPath, NiTexture* pkSelf);
};
Unk_UgcTextureCache* FUN_140a0afd0();
// A player in the field (Unk_UgcWorld::FUN_141bd1290 finds it by object id).
class Unk_UgcWearer : public PCBase
{
public:
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 itemUid);      // a worn item by uid
};
MS2Ptr<CItemData> FUN_14053f870(int nItemId);               // the table data of an item id
NiAVObject* FUN_141b6ef70(egf::EntityID id);                // the scene node of an entity
NiAVObjectPtr FUN_141423480(NiAVObjectPtr spRoot, const CString& strName);
int FUN_1414232f0(NiAVObjectPtr spMesh, NiTexturePtr spTexture);

NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);            // the scene node of an entity
// Ridee::FUN_141707440 (ridee.h / pcbase.h) returns the mount's RideeItemInfo under this placeholder name.
class Unk_PCBaseComp_b18 : public RideeItemInfo
{
};

CStringW FUN_14016a730(const char* psz, int nCodePage);      // multi-byte to wide
// Hidden (reported) content.
class Unk_UgcBlindManager
{
public:
    bool FUN_140a259b0(int nKind, __int64 uid);             // the content is blinded
};
Unk_UgcBlindManager* FUN_1409c1730();

unsigned __int64 FUN_14088dbf0(int nDate, int nHour);       // the reservation key of an hour
// The platform services: vfunc_54 sets a character's profile image (1 = changed).
class Unk_UgcPlatform
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35();
    virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43();
    virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47();
    virtual void vfunc_48(); virtual void vfunc_49(); virtual void vfunc_50(); virtual void vfunc_51();
    virtual void vfunc_52(); virtual void vfunc_53();
    virtual int vfunc_54(CStringW strPath, CStringW strArg, int nKind, CStringW strUrl);
};
Unk_UgcPlatform* FUN_140d86260();

void FUN_1410268a0(CString strA, CString strB);

// The item containers: the bag and the cube fallback inventory (unit_14092f420.cpp / uicommon.cpp).
class Unk_UgcBagInventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 itemUid);
};
extern Unk_UgcBagInventory DAT_143ab2a90;
class Unk_UgcCubeInventory
{
public:
    MS2Ptr<CItem> FUN_1408fbf90(__int64 itemUid);
};
extern Unk_UgcCubeInventory DAT_143ab2e20;

// The blueprint create dialog (0x4f7b; uiitemblueprintcreatedialog.cpp).
class Unk_UgcBlueprintDialog : public UIDialog
{
public:
    void FUN_140c36b40(CItem* pItem);
};
Unk_UgcBlueprintDialog* FUN_140d27260(int nId);

// The UGC events (vfunc_1: a character's profile image changed).
class Unk_UgcEventHub
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1(__int64 characterId, CString strUrl);
};
Unk_UgcEventHub* FUN_140bc09f0();

CString FUN_141028be0(__int64 characterId, const CString& strUrl, int nSize, CString strExt);   // the profile image file
CStringW FUN_1409eec40(int nId);
CStringW FUN_140a228f0(int nId, const int& nArg, const CStringW& strArg);
void FUN_1412751f0(const CStringW& strText, int nA, int nB);

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
    int nType = spCtrl->m_nKind;
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
    if (spCtrl->m_nKind != nType)
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
    if (spCtrl->m_nKind != nType)
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
    int bDirect = FUN_14088db30(spCtrl->m_nKind);
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

// @0x141882d80
// The file of an upload was sent (nResult 0: ok): the profile kinds are applied at once, the others are sent to the game
// server.
void CUgcManager::FUN_141882d80(MS2Ptr<CUgcUploadCtrl> spCtrl, int nResult, const CString& strPath)
{
    MS2Ptr<CUgcUploadCtrl> spCurrent = FUN_141882610();
    if (spCtrl == 0 || spCtrl.get() != spCurrent.get())
        return;
    if (spCtrl->m_spViewer == 0)
        return;
    spCtrl->m_upload.m_strPath = strPath;
    FUN_1418826a0(nResult);
    if (nResult == 0)
    {
        int nKind = spCtrl->m_nKind;
        if (nKind == 5)
        {
            int nState = FUN_140aa6d30()->FUN_1417e2610();
            if (nState == 0x620000c)
            {
                PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pPlayer != 0)
                {
                    FUN_141883380(strPath);
                    FUN_1418823f0();
                    FUN_141882450(MS2Ptr<CUgcUploadCtrl>(0));
                }
            }
            else
            {
                Unk_CharSelectDialog* pDialog = FUN_140b72de0(0x4ef1);
                if (pDialog != 0)
                    pDialog->FUN_1418ed4e0(spCurrent->m_user.m_characterId, strPath);
                FUN_1418823f0();
                FUN_141882450(MS2Ptr<CUgcUploadCtrl>(0));
            }
        }
        else if (nKind == 10)
        {
            FUN_141883780(strPath);
            FUN_1418823f0();
            FUN_141882450(MS2Ptr<CUgcUploadCtrl>(0));
        }
        else
        {
            int bGameServer = FUN_14088db90(nKind);
            if (bGameServer != 0)
                FUN_1418832a0();
            else
                FUN_141883860(strPath);
        }
    }
    else
    {
        FUN_141883800();
    }
    return;
}

// @0x141883170
void CUgcManager::FUN_141883170()
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return;
    if (spCtrl->m_spViewer == 0)
        return;
    COutPacket packet(0x38, 0);
    packet.Encode1(1);
    packet.Encode8(spCtrl->m_itemUid);
    spCtrl->Write(packet);
    spCtrl->m_spViewer->vfunc_6(packet);
    FUN_140710590(packet);
}

// @0x1418832a0
void CUgcManager::FUN_1418832a0()
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return;
    if (spCtrl->m_spViewer == 0)
        return;
    COutPacket packet(0x38, 0);
    packet.Encode1(3);
    spCtrl->Write(packet);
    FUN_140710590(packet);
}

// @0x141883380
void CUgcManager::FUN_141883380(CString strPath)
{
    COutPacket packet(0x38, 0);
    packet.Encode1(0xb);
    packet.vfunc_o10_6(strPath);
    FUN_140710590(packet);
}

// @0x141883400
// Reserves the picked hours of a day for the banner of the current upload.
void CUgcManager::FUN_141883400(CRBMap<int, int>& hours, const Unk_BannerDay& day)
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return;
    if (spCtrl->m_nKind != 3)
        return;
    CUgcViewerBanner* pViewer = (CUgcViewerBanner*)spCtrl->m_spViewer.get();
    if (pViewer == 0)
        return;
    int nBannerId = pViewer->m_nBannerId;
    Unk_BannerPtr spBanner = CFieldBannerData::GetBanner(nBannerId);
    if (spBanner == NULL)
        return;
    if (spBanner->m_nAd == 0)
        return;
    MS2Ptr<CUgcPreReserve> spReserve(new CUgcPreReserve);
    spReserve->m_nCount = nBannerId;
    for (POSITION pos = hours.GetHeadPosition(); pos != 0; hours.GetNext(pos))
    {
        int nHour = hours.GetKeyAt(pos);
        CUgcBannerReservePtr spHour(new CUgcBannerReserve);
        spHour->m_nBannerUid = 0;
        spHour->m_n20 = DAT_143ab2830;
        spHour->m_n24 = nBannerId;
        spHour->m_nDate = day.m_nDate;
        spHour->m_nHour = nHour;
        spReserve->m_reserves.SetAt(spHour->GetKey(), spHour);
    }
    COutPacket packet(0x38, 0);
    packet.Encode1(0x13);
    spReserve->Write(packet);
    FUN_140710590(packet);
}

// @0x141883780
void CUgcManager::FUN_141883780(CString strPath)
{
    COutPacket packet(0x38, 0);
    packet.Encode1(0xc);
    packet.vfunc_o10_6(strPath);
    FUN_140710590(packet);
}

// @0x141883800
void CUgcManager::FUN_141883800()
{
    COutPacket packet(0x38, 0);
    packet.Encode1(0);
    FUN_140710590(packet);
}

// @0x141883860
// The upload is done: the viewers of the upload (and of its chained upload) download the stored content.
void CUgcManager::FUN_141883860(CString strPath)
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    int nKind = spCtrl->m_nKind;
    if (nKind == 3)
    {
        FUN_1418823f0();
        FUN_141882450(MS2Ptr<CUgcUploadCtrl>(0));
        return;
    }
    if (nKind == 5)
    {
        FUN_141884d70(&spCtrl->m_user, strPath);
    }
    else
    {
        CAtlArray<MS2Ptr<CUgcUploadCtrl> > ctrls;
        ctrls.Add(spCtrl);
        CUgcUploadCtrl* pChained = spCtrl->FUN_1418a4100().get();
        if (pChained != 0)
            ctrls.Add(spCtrl->FUN_1418a4100());
        for (size_t i = 0; i < ctrls.GetCount(); i++)
        {
            MS2Ptr<CUgcUploadCtrl> spItem = ctrls[i];
            if (spItem == 0)
                continue;
            MS2Ptr<IUgcProxy> spProxy = FUN_141886340(spItem->m_nKind);
            if (spItem->m_spViewer->vfunc_8(spProxy, spItem->m_nKind) == 0)
                continue;
            CUgcDownloadParam param;
            param.m_nType = spItem->m_nKind;
            if (spItem->m_nKind == 0xc9)
                param.m_strUrl = FUN_141027880(strPath);
            else if (spItem->m_nKind == 0xd1)
                param.m_strUrl = FUN_141027a20(strPath);
            else
                param.m_strUrl = strPath;
            param.m_user.CopyFrom(&spItem->m_user);
            param.m_upload.CopyFrom(&spItem->m_upload);
            FUN_141886150(&param, spProxy.get());
        }
    }
    FUN_1418823f0();
    FUN_141882450(MS2Ptr<CUgcUploadCtrl>(0));
}

// @0x141883df0
// Downloads the UGC look of an item (and its icon) unless the url is empty.
void CUgcManager::FUN_141883df0(MS2Ptr<CItem> spItem, const egf::EntityID& id)
{
    if (spItem == 0)
        return;
    int nKind = FUN_14088dcf0(MS2Ptr<CItemData>(((CItem*)spItem)->FUN_140527840()));
    CUgcItemLook* pLook = ((CItem*)spItem)->FUN_140528380();
    if (pLook == 0)
        return;
    CString strLocal = FUN_1410280d0(nKind, pLook->m_strUrl);
    int bLocal = 0;
    if (_access(strLocal, 0) == 0)
        bLocal = 1;
    CUgcDownloadParam param;
    param.m_nType = nKind;
    param.m_strUrl = pLook->m_strUrl;
    param.m_bLocal = bLocal;
    param.m_user.m_nType = DAT_143ab2830;
    param.m_user.m_characterId = ((CItem*)spItem)->FUN_140526ad0();
    param.m_upload.m_uid = pLook->m_n18;
    param.m_upload.m_strName = pLook->m_str20;
    param.m_upload.m_nType = 3;
    if (param.m_strUrl.GetLength() == 0)
        return;
    if (nKind == 1)
    {
        CUgcItemPC item(spItem.get(), ((CItem*)spItem)->FUN_140526b10());
        FUN_141886150(&param, &item);
    }
    else if (nKind == 2)
    {
        CUgcItemCube item(spItem.get(), id);
        FUN_141886150(&param, &item);
    }
    else if (nKind == 7)
    {
        CUgcItemRidee item(spItem.get(), id);
        FUN_141886150(&param, &item);
    }
    FUN_1418841f0(pLook, spItem, 0);
}

// @0x1418841f0
int CUgcManager::FUN_1418841f0(CUgcItemLook* pLook, MS2Ptr<CItem> spItem, const UgcItemIcon::CallBackData* pCallBack)
{
    Unk_UgcUrlFn fnUrl(FUN_141027880);
    int nObjectId = 0;
    return FUN_141885e20(pLook, 0xc9, nObjectId, fnUrl, spItem, pCallBack);
}

// @0x141884300
void CUgcManager::FUN_141884300(MS2Ptr<CItem> spItem, int nObjectId)
{
    if (spItem == 0)
        return;
    int nKind = FUN_14088dcf0(MS2Ptr<CItemData>(((CItem*)spItem)->FUN_140527840()));
    if (nKind != 1)
        return;
    CUgcItemLook* pLook = ((CItem*)spItem)->FUN_140528380();
    if (pLook == 0)
        return;
    CUgcItemPC item(spItem.get(), nObjectId);
    CString strLocal = FUN_1410280d0(nKind, pLook->m_strUrl);
    int bLocal = 0;
    if (_access(strLocal, 0) == 0)
        bLocal = 1;
    CUgcDownloadParam param;
    param.m_nType = nKind;
    param.m_strUrl = pLook->m_strUrl;
    param.m_bLocal = bLocal;
    param.m_user.m_nType = DAT_143ab2830;
    param.m_user.m_characterId = ((CItem*)spItem)->FUN_140526ad0();
    param.m_upload.m_uid = pLook->m_n18;
    param.m_upload.m_strName = pLook->m_str20;
    param.m_upload.m_nType = 3;
    if (param.m_strUrl.GetLength() == 0)
        return;
    FUN_141886150(&param, &item);
}

// @0x1418845a0
void CUgcManager::FUN_1418845a0(CubeItemInfo* pInfo, egf::EntityID id)
{
    if (pInfo == 0)
        return;
    if (pInfo->FUN_1408b3860() == 0)
        return;
    CUgcItemCube item;
    item.m_itemUid = pInfo->instanceId;
    item.m_nItemId = pInfo->itemId;
    item.m_nCount = 1;
    item.m_strName = pInfo->look->m_str28;
    item.m_nRarity = pInfo->look->m_n30;
    item.m_entityId = id;
    CString strLocal = FUN_1410280d0(2, pInfo->look->m_strUrl);
    int bLocal = 0;
    if (_access(strLocal, 0) == 0)
        bLocal = 1;
    CUgcDownloadParam param;
    param.m_nType = 2;
    param.m_strUrl = pInfo->look->m_strUrl;
    param.m_bLocal = bLocal;
    param.m_user.m_nType = DAT_143ab2830;
    param.m_user.m_characterId = 0;
    param.m_upload.m_uid = pInfo->look->m_n18;
    param.m_upload.m_strName = pInfo->look->m_str20;
    param.m_upload.m_nType = 3;
    if (param.m_strUrl.GetLength() == 0)
        return;
    FUN_141886150(&param, &item);
}

// @0x141884830
void CUgcManager::FUN_141884830(MS2Ptr<Unk_PCBaseComp_b18> spInfo, egf::EntityID id)
{
    if (spInfo == 0)
        return;
    if (spInfo->IsValid() == 0)
        return;
    CUgcItemRidee item;
    item.m_itemUid = spInfo->m_nUid;
    item.m_nItemId = spInfo->m_nId;
    item.m_nCount = 1;
    item.m_strName = spInfo->m_look.m_str28;
    item.m_nRarity = spInfo->m_look.m_n30;
    item.m_entityId = id;
    CString strLocal = FUN_1410280d0(7, spInfo->m_look.m_strUrl);
    int bLocal = 0;
    if (_access(strLocal, 0) == 0)
        bLocal = 1;
    CUgcDownloadParam param;
    param.m_nType = 7;
    param.m_strUrl = spInfo->m_look.m_strUrl;
    param.m_bLocal = bLocal;
    param.m_user.m_nType = DAT_143ab2830;
    param.m_user.m_characterId = 0;
    param.m_upload.m_uid = spInfo->m_look.m_n18;
    param.m_upload.m_strName = spInfo->m_look.m_str20;
    param.m_upload.m_nType = 3;
    if (param.m_strUrl.GetLength() == 0)
        return;
    FUN_141886150(&param, &item);
}

// @0x141884af0
void CUgcManager::FUN_141884af0(MS2Ptr<CUgcRegistBanner> spBanner)
{
    if (spBanner == 0)
        return;
    CString strLocal = FUN_1410280d0(3, spBanner->m_strUrl);
    int bLocal = 0;
    if (_access(strLocal, 0) == 0)
        bLocal = 1;
    CUgcDownloadParam param;
    param.m_nType = spBanner->m_nType;
    param.m_strUrl = spBanner->m_strUrl;
    param.m_bLocal = bLocal;
    param.m_user.CopyFrom(&spBanner->m_user);
    param.m_upload.CopyFrom(&spBanner->m_upload);
    if (param.m_strUrl.GetLength() == 0)
        return;
    MS2Ptr<CUgcBannerPost> spPost(new CUgcBannerPost);
    spPost->CopyFrom(&spBanner->m_post);
    FUN_141886150(&param, spPost.get());
}

// @0x141884d70
void CUgcManager::FUN_141884d70(CUgcUserProxy* pUser, CString strPath)
{
    if (pUser == 0)
        return;
    CUgcDownloadParam param;
    param.m_nType = 5;
    param.m_user.CopyFrom(pUser);
    param.m_strUrl = strPath;
    FUN_141886150(&param, pUser);
}

// @0x141884e30
void CUgcManager::FUN_141884e30(int nType, __int64 accountId, __int64 characterId, CString strPath, CString strObjectName)
{
    CUgcUserProxy user;
    user.m_nType = nType;
    user.m_accountId = accountId;
    user.m_characterId = characterId;
    user.m_strObjectName = strObjectName;
    FUN_141884d70(&user, strPath);
}

// @0x141884f10
void CUgcManager::FUN_141884f10(CUgcUserProxy* pUser, CString strPath)
{
    if (pUser == 0)
        return;
    CUgcDownloadParam param;
    param.m_nType = 10;
    param.m_user.CopyFrom(pUser);
    param.m_strUrl = strPath;
    FUN_141886150(&param, pUser);
}

// @0x141884fd0
void CUgcManager::FUN_141884fd0(int nType, __int64 accountId, __int64 characterId, CString strPath)
{
    CUgcUserProxy user;
    user.m_nType = nType;
    user.m_accountId = accountId;
    user.m_characterId = characterId;
    FUN_141884f10(&user, strPath);
}

// @0x141885090
void CUgcManager::FUN_141885090(__int64 guildId, CString strUrl, CString strName)
{
    MS2Ptr<CUgcGuildMarkProxy> spMark(new CUgcGuildMarkProxy);
    spMark->m_nGuildId = guildId;
    spMark->m_strName = strName;
    CUgcDownloadParam param;
    param.m_nType = 6;
    param.m_strUrl = strUrl;
    param.m_user.Clear();
    param.m_upload.Clear();
    FUN_141886150(&param, spMark.get());
}

// @0x1418851e0
void CUgcManager::FUN_1418851e0(__int64 guildId, CString strUrl, int nIndex, CString strName)
{
    MS2Ptr<CUgcGuildPosterProxy> spPoster(new CUgcGuildPosterProxy);
    spPoster->m_nGuildId = guildId;
    spPoster->m_strName = strName;
    spPoster->m_nIndex = nIndex;
    CUgcDownloadParam param;
    param.m_nType = 8;
    param.m_strUrl = strUrl;
    param.m_user.Clear();
    param.m_upload.Clear();
    FUN_141886150(&param, spPoster.get());
}

// @0x141885340
void CUgcManager::FUN_141885340(CString strUrl)
{
    MS2Ptr<CUgcBannerEmptyProxy> spProxy(new CUgcBannerEmptyProxy);
    CUgcDownloadParam param;
    param.m_nType = 0xca;
    param.m_strUrl = strUrl;
    param.m_user.Clear();
    param.m_upload.Clear();
    FUN_141886150(&param, spProxy.get());
}

// @0x141885440
void CUgcManager::FUN_141885440(int nKind, CString strKey, CString strUrl)
{
    MS2Ptr<CUgcShopBannerProxy> spProxy(new CUgcShopBannerProxy);
    spProxy->m_strKey = strKey;
    FUN_141885570(spProxy, nKind, strUrl);
}

// @0x141885570
void CUgcManager::FUN_141885570(MS2Ptr<CUgcShopBannerProxy> spProxy, int nKind, CString strUrl)
{
    if (spProxy == 0)
        return;
    CUgcDownloadParam param;
    param.m_nType = nKind;
    param.m_strUrl = strUrl;
    param.m_user.Clear();
    param.m_upload.Clear();
    FUN_141886150(&param, spProxy.get());
}

// @0x141885670
void CUgcManager::FUN_141885670(int nKind, CString strUrl)
{
    MS2Ptr<CUgcBannerEmptyProxy> spProxy(new CUgcBannerEmptyProxy);
    CUgcDownloadParam param;
    param.m_nType = nKind;
    param.m_strUrl = strUrl;
    param.m_user.Clear();
    param.m_upload.Clear();
    FUN_141886150(&param, spProxy.get());
}

// @0x141885770
void CUgcManager::FUN_141885770(const CString& strUrl, const std::vector<unsigned int>& images)
{
    MS2Ptr<CUgcBannerRollingImageProxy> spProxy(new CUgcBannerRollingImageProxy);
    spProxy->m_images = images;
    CUgcDownloadParam param;
    param.m_nType = 0xce;
    param.m_strUrl = strUrl;
    param.m_user.Clear();
    param.m_upload.Clear();
    FUN_141886150(&param, spProxy.get());
}

// @0x141885880
void CUgcManager::FUN_141885880(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return;
    int nKind = FUN_14088dcf0(MS2Ptr<CItemData>(((CItem*)spItem)->FUN_140527840()));
    if (nKind != 9)
        return;
    CUgcItemLook* pLook = ((CItem*)spItem)->FUN_140528380();
    if (pLook == 0)
        return;
    CBlueprintItemData* pBlueprint = ((CItem*)spItem)->FUN_1405284f0();
    if (pBlueprint == 0)
        return;
    FUN_141885d20(pLook, 0, spItem, 0);
}

// @0x1418859f0
// Downloads the image of a blueprint (false: no url, or the file is already there).
bool CUgcManager::FUN_1418859f0(const CUgcItemLook* pLook, const CBlueprintItemData* pBlueprint, MS2Ptr<CItem> spItem)
{
    if (pBlueprint == 0)
        return false;
    int nKind = 9;
    CUgcBlueprintImageProxy image;
    image.m_n18 = pBlueprint->m_n18;
    image.m_n20 = spItem.get() != 0 ? ((CItem*)spItem)->FUN_140526a50() : 0;
    image.m_n28 = spItem.get() != 0 ? ((CItem*)spItem)->FUN_1405276c0() : 0;
    image.m_strName = pLook->m_str28;
    CString strLocal = FUN_1410280d0(nKind, pLook->m_strUrl);
    int bLocal = 0;
    if (_access(strLocal, 0) == 0)
        return false;
    if (pLook->m_strUrl.GetLength() == 0)
        return false;
    CUgcDownloadParam param;
    param.m_nType = nKind;
    param.m_strUrl = pLook->m_strUrl;
    param.m_bLocal = bLocal;
    param.m_user.m_nType = DAT_143ab2830;
    param.m_user.m_characterId = spItem.get() != 0 ? ((CItem*)spItem)->FUN_140526ad0() : 0;
    param.m_upload.m_uid = pLook->m_n18;
    param.m_upload.m_strName = pLook->m_str20;
    param.m_upload.m_nType = 3;
    FUN_141886150(&param, &image);
    return true;
}

// @0x141885d20
int CUgcManager::FUN_141885d20(CUgcItemLook* pLook, const int& nObjectId, MS2Ptr<CItem> spItem, const UgcItemIcon::CallBackData* pCallBack)
{
    Unk_UgcUrlFn fnUrl(FUN_141027a20);
    return FUN_141885e20(pLook, 0xd1, nObjectId, fnUrl, spItem, pCallBack);
}

// @0x141885e20
// Downloads the icon of a look (fnUrl maps the look's url to the icon url); 0 when it is on disk already.
int CUgcManager::FUN_141885e20(CUgcItemLook* pLook, const int& nKind, const int& nObjectId, Unk_UgcUrlFn fnUrl,
                               MS2Ptr<CItem> spItem, const UgcItemIcon::CallBackData* pCallBack)
{
    if (pLook->m_n30 == 1)
    {
        CString strLocal = FUN_1410280d0(nKind, pLook->m_strUrl);
        int bLocal = 0;
        if (_access(strLocal, 0) == 0)
            return 0;
        CString strUrl = fnUrl(pLook->m_strUrl);
        if (!strUrl.IsEmpty())
        {
            CUgcDownloadParam param;
            param.m_nType = nKind;
            param.m_strUrl = strUrl;
            param.m_bLocal = bLocal;
            param.m_user.m_nType = DAT_143ab2830;
            param.m_user.m_characterId = spItem.get() != 0 ? ((CItem*)spItem)->FUN_140526ad0() : 0;
            param.m_upload.m_uid = pLook->m_n18;
            param.m_upload.m_strName = pLook->m_str20;
            param.m_upload.m_nType = 3;
            CUgcItemIconPC icon(spItem.get(), spItem.get() != 0 ? ((CItem*)spItem)->FUN_140526b10() : 0);
            if (pCallBack != 0)
                icon.FUN_14088f960(*pCallBack);
            if (nObjectId != 0)
                icon.m_nKind = nObjectId;
            FUN_141886150(&param, &icon);
            return 1;
        }
    }
    return 0;
}

// @0x141886150
void CUgcManager::FUN_141886150(CUgcDownloadParam* pParam, IUgcProxy* pProxy)
{
    FUN_1414a57f0()->Push(pParam, pProxy);
}

// @0x141886190
// A download finished: keeps its control under its name with the result.
void CUgcManager::FUN_141886190(CString strName, MS2Ptr<CUgcDownloadCtrl> spCtrl, int nResult)
{
    if (spCtrl == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        spCtrl->SetResult(nResult);
        m_mapDownload.SetAt(strName, spCtrl);
    }
}

// @0x141886270
void CUgcManager::FUN_141886270(CString strName, int nResult)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        MS2Ptr<CUgcDownloadCtrl> spCtrl(0);
        m_mapDownload.Lookup(strName, spCtrl);
        if (spCtrl.get() != 0)
            spCtrl->SetResult(nResult);
    }
}

// @0x141886340
MS2Ptr<IUgcProxy> CUgcManager::FUN_141886340(int nKind)
{
    MS2Ptr<IUgcProxy> spProxy(0);
    switch (nKind)
    {
    case 1:
        spProxy.AssignRaw(new CUgcItemPC);
        break;
    case 2:
        spProxy.AssignRaw(new CUgcItemCube);
        break;
    case 0xc9:
        spProxy.AssignRaw(new CUgcItemIconPC);
        break;
    case 3:
        spProxy.AssignRaw(new CUgcBannerPost);
        break;
    case 5:
        spProxy.AssignRaw(new CUgcUserProxy);
        break;
    case 10:
        spProxy.AssignRaw(new CUgcUserProxy);
        break;
    case 6:
        spProxy.AssignRaw(new CUgcGuildMarkProxy);
        break;
    case 8:
        spProxy.AssignRaw(new CUgcGuildPosterProxy);
        break;
    case 7:
        spProxy.AssignRaw(new CUgcItemRidee);
        break;
    case 9:
        spProxy.AssignRaw(new CUgcBlueprintImageProxy);
        break;
    case 0xd1:
        spProxy.AssignRaw(new CUgcItemIconPC);
        break;
    default:
        spProxy.AssignRaw(new CUgcBannerEmptyProxy);
        break;
    }
    return spProxy;
}

// @0x141886980
// Puts a downloaded image on the worn item of a player.
int CUgcManager::FUN_141886980(CUgcItemPC* pItem, CString strPath)
{
    if (pItem == 0)
        return 0;
    NiTexturePtr spTexture = FUN_140a0afd0()->FUN_141553eb0(strPath, 0);
    if (spTexture == 0)
        return 0;
    return FUN_141886a90(pItem, spTexture);
}

// @0x141886a90
int CUgcManager::FUN_141886a90(CUgcItemPC* pItem, NiTexture* pTexture)
{
    if (pItem == 0)
        return 0;
    if (pTexture == 0)
        return 0;
    Unk_UgcWearer* pWearer = FUN_1403ed2d0()->FUN_141bd1290(pItem->m_nObjectId);
    if (pWearer == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->m_nItemId);
    if (spData == 0)
        return 0;
    CString strMesh = spData->cubeTextureName.mesh;
    if (strMesh.GetLength() == 0)
        return 0;
    MS2Ptr<CEquipItem> spEquip = pWearer->FUN_141655c30(pItem->m_itemUid);
    if (spEquip == 0)
        return 0;
    MS2Ptr<CItemUgcMeshContainer> spMeshes = spEquip->FUN_1411dd950();
    if (spMeshes == 0)
        return 0;
    spMeshes->FUN_141426810(pTexture);
    return 1;
}

// @0x141886cc0
// Puts a downloaded image on a placed cube.
int CUgcManager::FUN_141886cc0(CUgcItemCube* pItem, CString strPath, unsigned __int64 uid)
{
    if (pItem == 0)
        return 0;
    NiTexturePtr spTexture = FUN_140a0afd0()->FUN_141553eb0(strPath, 0);
    if (spTexture == 0)
        return 0;
    return FUN_141886de0(pItem, spTexture);
}

// @0x141886de0
int CUgcManager::FUN_141886de0(CUgcItemCube* pItem, NiTexture* pTexture)
{
    if (pItem == 0)
        return 0;
    if (pTexture == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->m_nItemId);
    if (spData == 0)
        return 0;
    CString strMesh = spData->cubeTextureName.mesh;
    if (strMesh.GetLength() == 0)
        return 0;
    NiAVObjectPtr spRoot = FUN_141b6ef70(pItem->m_entityId);
    if (spRoot == 0)
        return 0;
    NiAVObjectPtr spMesh = FUN_141423480(spRoot, strMesh);
    if (spMesh)
        FUN_1414232f0(spMesh, pTexture);
    return 1;
}

// @0x141887040
// Puts a downloaded image on a mount.
int CUgcManager::FUN_141887040(CUgcItemRidee* pItem, CString strPath, unsigned __int64 uid)
{
    if (pItem == 0)
        return 0;
    NiTexturePtr spTexture = FUN_140a0afd0()->FUN_141553eb0(strPath, 0);
    if (spTexture == 0)
        return 0;
    return FUN_141887160(pItem, spTexture);
}

// @0x141887160
int CUgcManager::FUN_141887160(CUgcItemRidee* pItem, NiTexture* pTexture)
{
    if (pItem == 0)
        return 0;
    if (pTexture == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_14053f870(pItem->m_nItemId);
    if (spData == 0)
        return 0;
    CString strMesh = spData->cubeTextureName.mesh;
    if (strMesh.GetLength() == 0)
        return 0;
    NiAVObjectPtr spRoot = FUN_141b6ef70(pItem->m_entityId);
    if (spRoot == 0)
        return 0;
    NiAVObjectPtr spMesh = FUN_141423480(spRoot, strMesh);
    if (spMesh)
        FUN_1414232f0(spMesh, pTexture);
    return 1;
}

// @0x1418873c0
// Puts the downloaded image on a placed cube, or requests it.
int CUgcManager::FUN_1418873c0(Cube* pCube)
{
    if (pCube == 0)
        return 0;
    if (pCube->entity == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_14053f870(pCube->FUN_1408b4f20());
    if (spData == 0)
        return 0;
    CUgcItemLook* pLook = pCube->FUN_1408b4f80();
    if (pLook == 0)
        return 0;
    CString strPath = FUN_1410280d0(2, pLook->m_strUrl);
    NiTexture* pTexture = FUN_140a0afd0()->FUN_141553eb0(strPath, 0);
    if (pTexture == 0)
    {
        FUN_1418845a0(pCube->item, pCube->entity->GetEntityID());
        return 0;
    }
    CString strMesh = spData->cubeTextureName.mesh;
    if (strMesh.GetLength() == 0)
        return 0;
    NiAVObjectPtr spRoot = FUN_141b6efc0(pCube->entity);
    if (spRoot == 0)
        return 0;
    NiAVObjectPtr spMesh = FUN_141423480(spRoot, strMesh);
    if (spMesh)
        FUN_1414232f0(spMesh, pTexture);
    return 1;
}

// @0x141887810
// Puts the downloaded image on a mount, or requests it.
int CUgcManager::FUN_141887810(Ridee* pRidee)
{
    if (pRidee == 0)
        return 0;
    MS2Ptr<Unk_PCBaseComp_b18> spInfo = pRidee->FUN_141707440();
    if (spInfo == 0)
        return 0;
    if (spInfo->IsValid() == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_14053f870(spInfo->m_nId);
    if (spData == 0)
        return 0;
    CString strPath = FUN_1410280d0(7, spInfo->m_look.m_strUrl);
    NiTexturePtr spTexture = FUN_140a0afd0()->FUN_141553eb0(strPath, 0);
    if (spTexture == 0)
    {
        if (pRidee->FUN_14123c410() != 0)
            FUN_141884830(spInfo, pRidee->FUN_14123c410()->GetEntityID());
        return 0;
    }
    CString strMesh = spData->cubeTextureName.mesh;
    if (strMesh.GetLength() == 0)
        return 0;
    NiAVObjectPtr spRoot = FUN_141b6efc0(pRidee->FUN_14123c410());
    if (spRoot == 0)
        return 0;
    NiAVObjectPtr spMesh = FUN_141423480(spRoot, strMesh);
    if (spMesh)
        FUN_1414232f0(spMesh, spTexture);
    return 1;
}

// @0x141887ce0
MS2Ptr<CUgcRegistBanner> CUgcManager::FUN_141887ce0(int nBannerId)
{
    MS2Ptr<CUgcRegistBanner> spBanner(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        CRBMap<int, MS2Ptr<CUgcRegistBanner> >::CPair* pPair = m_mapBanner.Lookup(nBannerId);
        if (pPair != 0)
            spBanner = pPair->m_value;
    }
    return spBanner;
}

// @0x141887dc0
// The registration of a banner arrived: shows its image (or downloads it); none or a blinded one shows the default.
void CUgcManager::FUN_141887dc0(int nBannerId, MS2Ptr<CUgcRegistBanner> spBanner)
{
    if (FUN_141887ce0(nBannerId) == spBanner.get())
        return;
    if (spBanner == 0)
    {
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
        {
            m_mapBanner.RemoveKey(nBannerId);
        }
        efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(nBannerId);
        if (spEntity != 0)
        {
            NiTexturePtr spTexture = FUN_1418896e0(nBannerId);
            if (spTexture != 0)
                FUN_141888770(spEntity, spTexture);
        }
    }
    else if (FUN_1409c1730()->FUN_140a259b0(2, spBanner->m_upload.m_uid))
    {
        FUN_1418885b0(nBannerId);
    }
    else
    {
        CString strPath = FUN_1410280d0(3, spBanner->m_strUrl);
        if (_access(strPath, 0) == 0)
        {
            int bShown = FUN_1418881e0(nBannerId, strPath, spBanner);
            if (bShown != 0)
            {
                if (Unk_LockGuard guard = m_lock)
                {
                }
                else
                {
                    m_mapBanner.RemoveKey(nBannerId);
                    m_mapBanner.SetAt(nBannerId, spBanner);
                }
            }
        }
        else
        {
            FUN_141884af0(spBanner);
        }
    }
}

// @0x1418881e0
int CUgcManager::FUN_1418881e0(int nBannerId, CString strPath, MS2Ptr<CUgcRegistBanner> spBanner)
{
    if (spBanner == 0)
        return 0;
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(nBannerId);
    if (spEntity == 0)
        return 0;
    NiTexturePtr spTexture = FUN_140a0afd0()->FUN_141553eb0(strPath, 0);
    if (spTexture == 0)
    {
        FUN_141884af0(spBanner);
        return 1;
    }
    return FUN_141888770(spEntity, spTexture);
}

// @0x141888420
int CUgcManager::FUN_141888420(int nBannerId, CString strPath)
{
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(nBannerId);
    if (spEntity == 0)
        return 0;
    NiTexture* pTexture = LoadCachedTexture(FUN_14016a730(strPath, 0));
    if (pTexture == 0)
        return 0;
    return FUN_141888770(spEntity, pTexture);
}

// @0x1418885b0
void CUgcManager::FUN_1418885b0(int nBannerId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapBanner.RemoveKey(nBannerId);
    }
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(nBannerId);
    if (spEntity != 0)
    {
        if (m_spDefaultTexture != 0)
        {
            FUN_141888770(spEntity, m_spDefaultTexture);
        }
        else
        {
            NiTexturePtr spTexture = FUN_1418896e0(nBannerId);
            if (spTexture != 0)
                FUN_141888770(spEntity, spTexture);
        }
    }
}

// @0x141888770
// Puts pTexture as the decal of the banner object's "Index00MeshName" mesh.
// MS2-FUNCTIONAL: same calls and flow; the exe frame is 0x20 smaller (stack slots of the temporaries differ)
int CUgcManager::FUN_141888770(efd::SmartPointer<egf::Entity> spEntity, NiTexture* pTexture)
{
    if (spEntity == 0)
        return 0;
    NiAVObject* pRoot = FUN_141b6efc0(spEntity);
    if (pRoot != 0)
    {
        efd::utf8string strMeshName;
        spEntity->GetPropertyValue(efd::utf8string("Index00MeshName"), strMeshName);
        if (!strMeshName.empty())
        {
            NiAVObject* pMesh = pRoot->GetObjectByName(NiFixedString(strMeshName.c_str()));
            if (pMesh != 0)
            {
                NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(NiProperty::TEXTURING));
                if (pTexturing != 0)
                {
                    NiTexturingProperty::Map* pMap = NiNew NiTexturingProperty::Map();
                    pMap->SetTexture(pTexture);
                    pTexturing->SetDecalMap(0, pMap);
                    pMesh->UpdateProperties();
                }
            }
        }
    }
    return 1;
}

// @0x1418889d0
void CUgcManager::FUN_1418889d0(int nBannerId, unsigned __int64 key, const ReserveBannerInfo& info)
{
    Unk_UgcBoxPtr<CReserveMap> spMap(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapReserve.Lookup(nBannerId, spMap);
        if (spMap == 0)
        {
            spMap = Unk_UgcNewTag(0);
            m_mapReserve.SetAt(nBannerId, spMap);
        }
        if (spMap->Lookup(key) == 0)
            spMap->SetAt(key, info);
    }
}

// @0x141888af0
void CUgcManager::FUN_141888af0(int nBannerId, unsigned __int64 key, int nState)
{
    Unk_UgcBoxPtr<CReserveMap> spMap(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (m_mapReserve.Lookup(nBannerId, spMap) == true)
        {
            ReserveBannerInfo info;
            CReserveMap::CPair* pPair = spMap->Lookup(key);
            if (pPair != 0)
                pPair->m_value.m_nState = nState;
            FUN_141888da0(1);
        }
    }
}

// @0x141888bf0
void CUgcManager::FUN_141888bf0(int nBannerId, int nDate, CRBMap<int, ReserveBannerInfo>& hours)
{
    hours.RemoveAll();
    Unk_UgcBoxPtr<CReserveMap> spMap(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapReserve.Lookup(nBannerId, spMap);
        if (spMap == 0)
            return;
        for (int nHour = 0; nHour < 24; nHour++)
        {
            unsigned __int64 key = FUN_14088dbf0(nDate, nHour);
            CReserveMap::CPair* pPair = spMap->Lookup(key);
            if (pPair != 0)
                hours.SetAt(nHour, pPair->m_value);
        }
    }
}

// @0x141888d30
void CUgcManager::FUN_141888d30(int nBannerId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapReserve.RemoveKey(nBannerId);
    }
}

// @0x141888da0
void CUgcManager::FUN_141888da0(bool bChanged)
{
    m_bReserveChanged = bChanged;
}

// @0x141888dc0
bool CUgcManager::FUN_141888dc0()
{
    return m_bReserveChanged;
}

// @0x141889150
// Keeps the decal image of every banner object that has none in the map yet.
// MS2-FUNCTIONAL: same calls and flow; the exe frame is 0x20 smaller (stack slots of the temporaries differ)
void CUgcManager::FUN_141889150()
{
    Unk_UgcBoxPtr<CAtlList<efd::SmartPointer<egf::Entity> > > spList = FUN_1403ed2d0()->FUN_141bd0420(0xc7f9dd65);
    if (spList == 0)
        return;
    POSITION pos = spList->GetHeadPosition();
    while (pos != 0)
    {
        efd::SmartPointer<egf::Entity> spEntity = spList->GetNext(pos);
        if ((egf::Entity*)spEntity != 0)
        {
            int nId;
            spEntity->GetPropertyValue(0x819a96c0, nId);
            int nObjectId = nId;
            bool bNone = FUN_1418896e0(nId) == 0;
            if (bNone)
            {
                NiAVObject* pRoot = FUN_141b6efc0(spEntity);
                if (pRoot != 0)
                {
                    efd::utf8string strMeshName;
                    spEntity->GetPropertyValue(efd::utf8string("Index00MeshName"), strMeshName);
                    efd::utf8string strTexturePath;
                    spEntity->GetPropertyValue(efd::utf8string("Index00TexturePath"), strTexturePath);
                    if (!strMeshName.empty())
                    {
                        NiAVObject* pMesh = pRoot->GetObjectByName(NiFixedString(strMeshName.c_str()));
                        if (pMesh != 0)
                        {
                            NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(NiProperty::TEXTURING));
                            if (pTexturing != 0)
                            {
                                NiTexturingProperty::Map* pMap = pTexturing->GetDecalMap(0);
                                NiTexturePtr spDecal = pMap->GetTexture();
                                FUN_1418895d0(nObjectId, spDecal);
                            }
                        }
                    }
                }
            }
        }
    }
}

// @0x1418894d0
void CUgcManager::FUN_1418894d0()
{
    Unk_UgcBoxPtr<CAtlList<efd::SmartPointer<egf::Entity> > > spList = FUN_1403ed2d0()->FUN_141bd0420(0xc7f9dd65);
    if (spList == 0)
        return;
    POSITION pos = spList->GetHeadPosition();
    while (pos != 0)
    {
        efd::SmartPointer<egf::Entity> spEntity = spList->GetNext(pos);
        if ((egf::Entity*)spEntity != 0)
        {
            int nId;
            spEntity->GetPropertyValue(0x819a96c0, nId);
            int nObjectId = nId;
            FUN_141889670(nObjectId);
        }
    }
}

// @0x1418895d0
void CUgcManager::FUN_1418895d0(int nObjectId, NiTexturePtr spTexture)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (m_mapTexture.Lookup(nObjectId) == 0)
            m_mapTexture.SetAt(nObjectId, spTexture);
    }
}

// @0x141889670
void CUgcManager::FUN_141889670(int nObjectId)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapTexture.RemoveKey(nObjectId);
    }
}

// @0x1418896e0
NiTexturePtr CUgcManager::FUN_1418896e0(int nObjectId)
{
    NiTexturePtr spTexture(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_mapTexture.Lookup(nObjectId, spTexture);
    }
    return spTexture;
}

// @0x1418897a0
NiTexturePtr CUgcManager::FUN_1418897a0()
{
    return m_spDefaultTexture;
}

// @0x1418897f0
void CUgcManager::FUN_1418897f0(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    if (nType == 2)
    {
        int nResult = FUN_14188dd70(packet);
        if (nResult != 0)
            FUN_1418826a0(nResult);
        else
            FUN_14188fbd0();
    }
    else if (nType == 4)
    {
        int nResult = FUN_14188e0d0(packet);
        CString strPath = packet.vfunc_o8_6();
        if (nResult != 0)
            FUN_1418826a0(nResult);
        else
            FUN_141883860(strPath);
    }
    else if (nType == 0x14)
    {
        int nResult = FUN_14188da70(packet);
        if (nResult != 0)
            FUN_1418826a0(nResult);
    }
    else if (nType == 0xb)
    {
        FUN_14188e200(packet);
    }
    else if (nType == 0xd || nType == 0xe || nType == 0xf)
    {
        FUN_14188e5b0(packet, nType);
    }
    else if (nType == 0x10)
    {
        FUN_14188e930(packet);
    }
    else if (nType == 0x11)
    {
        CString strUrl = packet.vfunc_o8_6();
        CString strA = packet.vfunc_o8_6();
        CString strB = packet.vfunc_o8_6();
        int nResult = packet.vfunc_o8_1();
        FUN_140b2e990()->FUN_14176fcf0(strUrl, nResult);
        FUN_1410268a0(strA, strB);
    }
    else if (nType == 0x12)
    {
        FUN_14188eb30(packet);
    }
    else if (nType == 7)
    {
        FUN_14188f0e0(packet);
    }
    else if (nType == 8)
    {
        FUN_14188f220(packet);
    }
    else if (nType == 6)
    {
        FUN_14188f350(packet);
    }
    else if (nType == 0x15)
    {
        CUgcGetCostTable::GetInstance()->Read(packet);
    }
    else if (nType == 0x16)
    {
        int nMode = packet.vfunc_o8_3();
        FUN_14187f380(nMode);
    }
    else if (nType == 0)
    {
        FUN_14188f450(packet);
    }
}

// @0x141889ce0
// Re-read the local files of an upload kind (warns when the directory holds too many); a changed list replaces the cached
// one and the thumbnails are made again.
void CUgcManager::FUN_141889ce0(int nType)
{
    CAtlArray<MS2Ptr<CUploadFile> > files;
    FUN_14188d380(nType, files);
    if (files.GetCount() >= *FUN_1401d3200()->UGCImgFileCountCheck.Get())
        FUN_140d73bc0(0x2e3, 0, 0, L"");
    if (FUN_14188c020(files) == 0)
    {
        FUN_14188b480();
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
        {
            m_files.RemoveAll();
            m_files.Append(files);
        }
    }
}

// @0x141889e20
// Rows of nCount local files from nStart for the AS list (a missing thumbnail is made first).
void CUgcManager::FUN_141889e20(unsigned int nCount, int nStart, ASArray* pArray)
{
    int nEnd = nCount + nStart;
    if (nEnd < 0)
        return;
    CAtlArray<MS2Ptr<CUploadFile> > files;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        int nFirst = nStart;
        unsigned int nNum = nCount;
        for (unsigned int i = 0; i < nNum; i++)
        {
            unsigned int nIndex = nFirst + i;
            if (m_files.GetCount() > nIndex)
                files.Add(m_files[nIndex]);
        }
    }
    for (unsigned int i = 0; i < files.GetCount(); i++)
    {
        MS2Ptr<CUploadFile> spFile = files[i];
        if (spFile == NULL)
        {
            MS2_ASSERT_AT(0x2b1, 0);
            continue;
        }
        if (_waccess(spFile->GetThumbnailDir(), 0) != 0)
            ConvertIconFile(spFile->GetPath());
        ASObj obj(2);
        if (FUN_14188d8c0(obj, spFile.get()))
            pArray->FUN_1422bc050(obj.FUN_1422bb870());
    }
}

// @0x14188a140
// Same, for a page of the list (nothing when there are no files).
void CUgcManager::FUN_14188a140(unsigned int nCount, unsigned int nStart, ASArray* pArray)
{
    if (m_files.IsEmpty())
        return;
    size_t nTotal = m_files.GetCount();
    CAtlArray<MS2Ptr<CUploadFile> > files;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (size_t i = 0; i < nCount; i++)
        {
            size_t nIndex = nStart + i;
            if (nTotal > nIndex)
                files.Add(m_files[nIndex]);
        }
    }
    nCount = min(nCount, files.GetCount());
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<CUploadFile> spFile = files[i];
        if (spFile == NULL)
            continue;
        if (_waccess(spFile->GetThumbnailDir(), 0) != 0)
            ConvertIconFile(spFile->GetPath());
        ASObj obj(2);
        if (FUN_14188d8c0(obj, spFile.get()))
            pArray->FUN_1422bc050(obj.FUN_1422bb870());
    }
}

// @0x14188a480
// The number of local files.
int CUgcManager::FUN_14188a480()
{
    return m_files.GetCount();
}

// @0x14188a4b0
MS2Ptr<CUploadFile> CUgcManager::FUN_14188a4b0(int nIndex)
{
    if (nIndex < 0 || nIndex >= FUN_14188a480())
        return MS2Ptr<CUploadFile>(0);
    MS2Ptr<CUploadFile> spFile(0);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        spFile = m_files[nIndex];
    }
    return spFile;
}

// @0x14188a5b0
// The index of the local file with this path (-1: none).
int CUgcManager::FUN_14188a5b0(const CStringW& strPath)
{
    int nIndex = -1;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        for (size_t i = 0; i < m_files.GetCount(); i++)
        {
            MS2Ptr<CUploadFile> spFile = m_files[i];
            if (spFile == NULL)
                continue;
            if (spFile->GetPath() == strPath)
            {
                nIndex = (int)i;
                break;
            }
        }
    }
    return nIndex;
}

// @0x14188a6f0
// Clear the read-only attribute of a file.
void CUgcManager::FUN_14188a6f0(const CStringW& strPath)
{
    DWORD dwAttributes = GetFileAttributesW(strPath);
    if (dwAttributes == INVALID_FILE_ATTRIBUTES)
        return;
    if ((dwAttributes & FILE_ATTRIBUTE_READONLY) != 0)
        SetFileAttributesW(strPath, dwAttributes & ~FILE_ATTRIBUTE_READONLY);
}

// @0x14188a760
void CUgcManager::FUN_14188a760(const CStringW& strDir, int bRemoveDir)
{
    std::set<CStringW> exclude;
    FUN_14188a7c0(strDir, bRemoveDir, exclude);
}

// @0x14188a7c0
// Delete the files of a directory tree except the excluded directories; bRemoveDir also removes the directory itself.
void CUgcManager::FUN_14188a7c0(const CStringW& strDir, int bRemoveDir, std::set<CStringW>& exclude)
{
    if (exclude.find(strDir) != exclude.end())
        return;
    CStringW strFind;
    strFind.Format(L"%s\\*.*", (const wchar_t*)strDir);
    WIN32_FIND_DATAW fd;
    HANDLE hFind = FindFirstFileW(strFind, &fd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            CStringW strName(fd.cFileName);
            CStringW strPath = StringFormat(L"{0}\\{1}", strDir, strName);
            if (FUN_1403b3c40(strName, L".") || FUN_1403b3c40(strName, L".."))
                continue;
            BOOL bDir = (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? TRUE : FALSE;
            if (bDir == TRUE)
            {
                FUN_14188a7c0(strPath, 1, exclude);
            }
            else
            {
                FUN_14188a6f0(strPath);
                DeleteFileW(strPath);
            }
        } while (FindNextFileW(hFind, &fd));
        FindClose(hFind);
    }
    if (bRemoveDir)
        RemoveDirectoryW(strDir);
}

// @0x14188aa20
// 1 when the file was downloaded in this session.
// MS2-FUNCTIONAL: same calls and flow; the exe has a nop after the guard dtor on the fall-off path (no return value)
int CUgcManager::FUN_14188aa20(const CString& strName)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        return m_setC8.find(strName) != m_setC8.end();
    }
}

// @0x14188aae0
// Clear the merat market downloads of the market kind that is not in use.
void CUgcManager::FUN_14188aae0()
{
    FUN_14188a760(FUN_14016a730(".\\Custom\\Download\\MeratMarketBanner", 0), 1);
    if (FUN_140166410()->FUN_14036d570(0x108))
    {
        FUN_14188a760(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Banner", 0), 1);
        FUN_14188a760(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Limited", 0), 1);
    }
    else
    {
        FUN_14188a760(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\HomeProduct", 0), 0);
        FUN_14188a760(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Special", 0), 0);
    }
}

// @0x14188aca0
void CUgcManager::FUN_14188aca0()
{
    CreateDirectoryW(FUN_14016a730(".\\Custom", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Icon", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Profile", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\WeddingProfile", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Item", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Guild", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Guild\\Poster", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\BannderAd", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\CashshopBanner", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Blueprint", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket", 0), NULL);
    if (FUN_140166410()->FUN_14036d570(0x108))
    {
        CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\HomeProduct", 0), NULL);
        CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Special", 0), NULL);
    }
    else
    {
        CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Banner", 0), NULL);
        CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Limited", 0), NULL);
    }
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Image", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\WeddingProfile", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Equip", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Image", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Cube", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Guild", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Guild\\Poster", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Ridee", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Image", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Convert", 0), NULL);
    CStringW hidden[] = { FUN_14016a730(".\\Custom\\Thumbnail", 0) };
    for (int i = 0; i < _countof(hidden); i++)
    {
        CStringW strDir = hidden[i];
        CreateDirectoryW(strDir, NULL);
        SetFileAttributesW(strDir, FILE_ATTRIBUTE_HIDDEN);
    }
}

// @0x14188b480
// Delete the thumbnails (they are made again from the files).
void CUgcManager::FUN_14188b480()
{
    FUN_14188a760(FUN_14016a730(".\\Custom\\Thumbnail", 0), 0);
}

// @0x14188b4e0
// Clear the download cache (the banner directories are kept), create its directories again and delete the converted
// images.
// MS2-FUNCTIONAL: same calls and flow; the exe keeps the _bstr_t("\\") temporary in a low stack slot (frame 0x10 smaller)
void CUgcManager::FUN_14188b4e0()
{
    std::set<CStringW> exclude;
    exclude.insert(FUN_14016a730(".\\Custom\\Download\\BannderAd", 0));
    exclude.insert(FUN_14016a730(".\\Custom\\Download\\CashshopBanner", 0));
    exclude.insert(FUN_14016a730(".\\Custom\\Download\\MeratMarket", 0));
    FUN_14188a7c0(FUN_14016a730(".\\Custom\\Download", 0), 0, exclude);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Icon", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Profile", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Item", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Guild", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\Guild\\Poster", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\BannderAd", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\CashshopBanner", 0), NULL);
    CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket", 0), NULL);
    if (FUN_140166410()->FUN_14036d570(0x108))
    {
        CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\HomeProduct", 0), NULL);
        CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Special", 0), NULL);
    }
    else
    {
        CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Banner", 0), NULL);
        CreateDirectoryW(FUN_14016a730(".\\Custom\\Download\\MeratMarket\\Limited", 0), NULL);
    }
    CStringW strConvert = FUN_14016a730(".\\Custom\\Convert", 0);
    CStringW strFind = strConvert + L"\\.dds";
    WIN32_FIND_DATAW fd;
    HANDLE hFind = FindFirstFileW(strFind, &fd);
    do
    {
        CString strPath = (const char*)((const wchar_t*)strConvert + _bstr_t("\\"));
        strPath += fd.cFileName;
        DeleteFileA(strPath);
    } while (FindNextFileW(hFind, &fd));
}

// @0x14188bb20
// Delete the files of m_map190.
void CUgcManager::FUN_14188bb20()
{
    for (std::map<CStringW, CStringW>::iterator it = m_map190.begin(); it != m_map190.end(); ++it)
        DeleteFileW(it->first);
}

// @0x14188bbb0
// Stop the current upload and close its dialog.
void CUgcManager::FUN_14188bbb0()
{
    m_bInit = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else if (m_spUpload.get())
    {
        m_spUpload->FUN_1418a38a0();
    }
    if (m_bInit)
    {
        MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
        if (spCtrl == NULL)
            return;
        if (FUN_1403ed2b0()->FUN_141adc890((eUIClassID)spCtrl->FUN_1418a3ad0()))
            FUN_1403ed2b0()->FUN_141adc5d0((eUIClassID)spCtrl->FUN_1418a3ad0());
    }
}

// @0x14188bce0
// Finish the ended downloads: a successful one is remembered and its proxies get the file; ended ones are dropped.
void CUgcManager::FUN_14188bce0()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        CAtlArray<CString> done;
        for (POSITION pos = m_mapDownload.GetHeadPosition(); pos != NULL; m_mapDownload.GetNext(pos))
        {
            CString strName = m_mapDownload.GetKeyAt(pos);
            MS2Ptr<CUgcDownloadCtrl> spCtrl = m_mapDownload.GetValueAt(pos);
            if (spCtrl == NULL)
            {
                done.Add(strName);
                continue;
            }
            if (spCtrl->GetResult() != 1)
            {
                if (spCtrl->GetResult() == 0)
                    m_setC8.insert(FUN_1410272e0(strName));
                spCtrl->ProcessResult();
                done.Add(strName);
                continue;
            }
        }
        for (size_t i = 0; i < done.GetCount(); i++)
        {
            CString strName = done[i];
            m_mapDownload.RemoveKey(strName);
        }
        done.RemoveAll();
    }
}

// @0x14188bfd0
int CUgcManager::FUN_14188bfd0(const CStringW& strPath, D3DXIMAGE_INFO* pInfo)
{
    HRESULT hr = D3DXGetImageInfoFromFileW(strPath, pInfo);
    if (FAILED(hr))
        return 0;
    return 1;
}

static int __cdecl FUN_141890240(const void* p1, const void* p2);

// @0x14188c020
// 1 when the files are the cached ones (same names and write times, in the same order).
int CUgcManager::FUN_14188c020(CAtlArray<MS2Ptr<CUploadFile> >& files)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (m_files.GetCount() != files.GetCount())
            return 0;
        for (unsigned int i = 0; i < files.GetCount(); i++)
        {
            if (files[i]->GetName() != m_files[i]->GetName())
                return 0;
            if (files[i]->GetWriteTime() != m_files[i]->GetWriteTime())
                return 0;
        }
    }
    return 1;
}

// @0x14188d380
// The image files of an upload kind's directory with an allowed extension and size, the newest first.
void CUgcManager::FUN_14188d380(int nType, CAtlArray<MS2Ptr<CUploadFile> >& files)
{
    files.RemoveAll();
    wchar_t szDir[0x100] = {0};
    wchar_t szDrive[3] = {0};
    wchar_t szFname[0x100] = {0};
    wchar_t szExt[0x100] = {0};
    CStringW strDir = FUN_141026920(nType);
    CStringW strFind = StringFormat(L"{0}\\*.*", strDir);
    WIN32_FIND_DATAW fd;
    HANDLE hFind = FindFirstFileW(strFind, &fd);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            DWORD bDir = fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
            CStringW strName(fd.cFileName);
            CStringW strPath = StringFormat(L"{0}\\{1}", strDir, strName);
            if (FUN_1403b3c40(strName, L".") || FUN_1403b3c40(strName, L".."))
                continue;
            if (bDir != 0)
                continue;
            _wsplitpath_s(strPath, szDrive, 3, szDir, 0x100, szFname, 0x100, szExt, 0x100);
            CStringW strExt(szExt);
            FUN_140841420(strExt);
            for (size_t i = 0; i < m_extensions.GetCount(); i++)
            {
                CStringW strAllowed = m_extensions[i];
                if (strAllowed == strExt)
                {
                    D3DXIMAGE_INFO info;
                    if (FUN_14188bfd0(strPath, &info) == 0)
                        continue;
                    if ((int)info.Width > *FUN_1401d3200()->UGCImgUploadSizeLimit.Get()
                        || (int)info.Height > *FUN_1401d3200()->UGCImgUploadSizeLimit.Get())
                        continue;
                    CFileTime tWrite(fd.ftLastWriteTime);
                    CFileTime tCreate(fd.ftCreationTime);
                    MS2Ptr<CUploadFile> spFile(new CUploadFile());
                    spFile->Set(strPath, strName, tWrite.GetTime(), tCreate.GetTime(), 1);
                    files.Add(spFile);
                }
            }
        } while (FindNextFileW(hFind, &fd));
        FindClose(hFind);
    }
    qsort(files.GetData(), files.GetCount(), sizeof(MS2Ptr<CUploadFile>), FUN_141890240);
}

// @0x14188d8c0
// The AS row of a local file: its name, the tooltip and the thumbnail.
int CUgcManager::FUN_14188d8c0(ASObj& obj, CUploadFile* pFile)
{
    if (pFile == NULL)
        return 0;
    obj.FUN_1407cbb20("fileName", pFile->GetName());
    CStringW strTooltip = FormatStringId(0x2ec, pFile->GetName());
    obj.FUN_1407cbb20("tooltip", strTooltip);
    CStringW strImage = FUN_141026c50(pFile->GetTitle());
    obj.FUN_1407cbb20("imgPath", strImage);
    return 1;
}

// @0x14188da70
// The reservations of the banner being uploaded.
int CUgcManager::FUN_14188da70(CInPacket& packet)
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return 0xd;
    int nResult = 1;
    try
    {
        MS2Ptr<CUgcPreReserve> spReserve(new CUgcPreReserve);
        spReserve->Read(packet);
        if (spCtrl->m_nKind != 3)
            throw Exception(CString("invaild ugcType"), 0x5b);
        UIUGCBannerDialog* pDialog = UgcFindDialog<UIUGCBannerDialog>(eUI_4e70);
        if (pDialog == 0 || pDialog->vfunc_55() == 1)
            throw Exception(CString("error dialog"), 0x29);
        nResult = pDialog->FUN_141b35540(spReserve);
        if (nResult != 0)
            throw Exception(CString("error reserve result"), nResult);
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
    }
    return nResult;
}

// @0x14188dd70
// The upload was accepted by the game server: register it and send the file to the web server.
int CUgcManager::FUN_14188dd70(CInPacket& packet)
{
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return 0xd;
    int nResult = 1;
    try
    {
        int nKind = packet.vfunc_o8_1();
        if (spCtrl->m_nKind != nKind)
            throw Exception(CString("invaild ugcType"), 0x5b);
        __int64 uid = packet.vfunc_o8_4();
        spCtrl->m_upload.m_uid = uid;
        spCtrl->m_upload.m_strName = packet.vfunc_o8_6();
        spCtrl->m_upload.m_nType = 1;
        nResult = spCtrl->FUN_1418a3b80(uid);
        if (nResult != 0)
            throw Exception(CString("error PreUpload"), nResult);
        nResult = FUN_140b2e990()->FUN_14176feb0();
        if (nResult != 0)
            throw Exception(CString("error soap upload"), nResult);
    }
    catch (Exception& e)
    {
        nResult = e.GetCode();
    }
    return nResult;
}

// @0x14188e0d0
int CUgcManager::FUN_14188e0d0(CInPacket& packet)
{
    int nKind = packet.vfunc_o8_1();
    __int64 uid = packet.vfunc_o8_4();
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl == 0)
        return 0xd;
    if (spCtrl->m_nKind != nKind)
        return 0x5b;
    if (spCtrl->m_upload.m_uid != uid)
        return 0x5c;
    return 0;
}

// @0x14188e200
// A character's profile image: the character select dialog or the player in the field shows it.
void CUgcManager::FUN_14188e200(CInPacket& packet)
{
    int nObjectId = packet.vfunc_o8_3();
    __int64 characterId = packet.vfunc_o8_4();
    CString strUrl = packet.vfunc_o8_6();
    if (FUN_14187f3b0() == 1)
        strUrl = "";
    if (nObjectId == 0)
    {
        int nState = FUN_140aa6d30()->FUN_1417e2610();
        if (nState == 0x620000d)
        {
            Unk_CharSelectDialog* pDialog = FUN_140b72de0(0x4ef1);
            if (pDialog != 0)
            {
                pDialog->FUN_1418ed5a0(characterId, strUrl);
                CString strPath = FUN_1410280d0(5, strUrl);
                if (_access(strPath, 0) != 0)
                    FUN_141884e30(DAT_143ab2830, 0, characterId, strUrl, "");
            }
        }
    }
    else
    {
        Unk_UgcWearer* pPlayer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
        if (pPlayer == 0)
            return;
        CString strPath = FUN_141028be0(FUN_141656a80(pPlayer), strUrl, 0, "");
        if (!strPath.IsEmpty())
        {
            FUN_140bc09f0()->vfunc_1(FUN_141656a80(pPlayer), strUrl);
        }
    }
}

// @0x14188e5b0
// The look of one of my items was changed (0xe: an item of the cube inventory).
// MS2-FUNCTIONAL: same calls and flow; the exe materializes both viewer checks as bool temporaries (frame 0x10 larger)
void CUgcManager::FUN_14188e5b0(CInPacket& packet, int nType)
{
    int nObjectId = packet.vfunc_o8_3();
    CUgcItemProxy proxy;
    proxy.Read(packet);
    CUgcItemLook look;
    look.Read(packet);
    Unk_UgcWearer* pWearer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pWearer == 0)
        return;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != pWearer)
        return;
    __int64 itemUid = proxy.m_itemUid;
    MS2Ptr<CItem> spItem(0);
    if (nType == 0xe)
        spItem = DAT_143ab2e20.FUN_1408fbf90(itemUid);
    else
        spItem = DAT_143ab2a90.FUN_140a5d680(itemUid);
    if (spItem == 0)
        return;
    spItem->FUN_140528300(&look);
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
    if (spCtrl.get() != 0 && spCtrl->m_spViewer.get() != 0)
        spCtrl->m_spViewer->vfunc_12(itemUid);
    UIUGCItemEditDialog* pDialog = FUN_140eeff60(0x4e69);
    if (pDialog != 0 && pDialog->vfunc_55() == 0)
        pDialog->FUN_141b45180(spItem);
}

// @0x14188e930
// The look of one of my blueprints was changed.
void CUgcManager::FUN_14188e930(CInPacket& packet)
{
    int nObjectId = packet.vfunc_o8_3();
    CUgcBlueprintImageProxy proxy;
    proxy.Read(packet);
    CUgcItemLook look;
    look.Read(packet);
    __int64 itemUid = proxy.m_n20;
    Unk_UgcWearer* pWearer = FUN_1403ed2d0()->FUN_141bd1290(nObjectId);
    if (pWearer == 0)
        return;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != pWearer)
        return;
    CItem* pItem = DAT_143ab2a90.FUN_140a5d680(itemUid).get();
    if (pItem == 0)
        return;
    pItem->FUN_140528300(&look);
    Unk_UgcBlueprintDialog* pDialog = FUN_140d27260(0x4f7b);
    if (pDialog != 0 && pDialog->vfunc_55() == 0)
        pDialog->FUN_140c36b40(pItem);
}

// @0x14188eb30
// The banners of the field: the rolling images, the registrations and the reservations.
void CUgcManager::FUN_14188eb30(CInPacket& packet)
{
    CAtlArray<MS2Ptr<CUgcBannerRollingImage> > images;
    int nImages = packet.vfunc_o8_3();
    for (int i = 0; i < nImages; i++)
    {
        int bHas = packet.vfunc_o8_1();
        if (bHas != 0)
        {
            MS2Ptr<CUgcBannerRollingImage> spImage(new CUgcBannerRollingImage);
            spImage->Read(packet);
            spImage->FUN_140897740();
            images.Add(spImage);
        }
    }
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_rollingImages.RemoveAll();
        m_rollingImages.Copy(images);
    }
    int nBanners = packet.vfunc_o8_3();
    for (int i = 0; i < nBanners; i++)
    {
        int nBannerId = packet.vfunc_o8_4();
        int bRegistered = packet.vfunc_o8_1();
        MS2Ptr<CUgcRegistBanner> spBanner(0);
        if (bRegistered != 0)
        {
            spBanner.AssignRaw(new CUgcRegistBanner);
            spBanner->Read(packet);
        }
        if (FUN_141887ce0(nBannerId).get() != spBanner.get())
            FUN_141887dc0(nBannerId, spBanner);
    }
    int nReserves = packet.vfunc_o8_3();
    for (int i = 0; i < nReserves; i++)
    {
        int nBannerId = packet.vfunc_o8_4();
        int nHours = packet.vfunc_o8_3();
        FUN_141888d30(nBannerId);
        for (int j = 0; j < nHours; j++)
        {
            ReserveBannerInfo info;
            unsigned __int64 key = packet.vfunc_o8_4();
            info.Read(packet);
            FUN_1418889d0(nBannerId, key, info);
        }
    }
    FUN_14188c6f0();
}

// @0x14188f0e0
// The registration of one banner changed.
void CUgcManager::FUN_14188f0e0(CInPacket& packet)
{
    int nBannerId = packet.vfunc_o8_4();
    int bRegistered = packet.vfunc_o8_1();
    MS2Ptr<CUgcRegistBanner> spBanner(0);
    if (bRegistered == 1)
    {
        spBanner.AssignRaw(new CUgcRegistBanner);
        spBanner->Read(packet);
    }
    FUN_141887dc0(nBannerId, spBanner);
}

// @0x14188f220
// The reservations of one banner.
void CUgcManager::FUN_14188f220(CInPacket& packet)
{
    int nBannerId = packet.vfunc_o8_4();
    int nHours = packet.vfunc_o8_3();
    FUN_141888d30(nBannerId);
    for (int i = 0; i < nHours; i++)
    {
        ReserveBannerInfo info;
        unsigned __int64 key = packet.vfunc_o8_4();
        info.Read(packet);
        FUN_1418889d0(nBannerId, key, info);
    }
}

// @0x14188f350
// Reservations of a banner were confirmed.
void CUgcManager::FUN_14188f350(CInPacket& packet)
{
    int nBannerId = packet.vfunc_o8_4();
    int nHours = packet.vfunc_o8_3();
    for (int i = 0; i < nHours; i++)
    {
        ReserveBannerInfo info;
        unsigned __int64 key = packet.vfunc_o8_4();
        FUN_141888af0(nBannerId, key, 1);
    }
}

// @0x14188f450
// An upload error of the game server; the manager is unlocked.
void CUgcManager::FUN_14188f450(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    int nError = packet.vfunc_o8_1();
    switch (nError)
    {
    case 0x13:
        FUN_140d73bc0(0x34, 0, 0, L"");
        break;
    case 0x79:
        FUN_140d73bc0(0x443, 0, 0, L"");
        break;
    case 0x7a:
        FUN_140d73bc0(0x446, 0, 0, L"");
        break;
    case 0x7b:
        FUN_140d73bc0(0x8b5, 0, 0, L"");
        break;
    case 0x7c:
    {
        UIUGCItemEditDialog* pDialog = FUN_140eeff60(0x4e69);
        if (pDialog != 0)
            pDialog->FUN_141b45020();
        FUN_140d73bc0(0x8ba, 0, 0, L"");
        break;
    }
    case 0x7d:
        FUN_140d73bc0(0x8b7, 0, 0, L"");
        break;
    case 0x81:
        FUN_140d73bc0(0x43, 0, 0, L"");
        break;
    case 0x82:
        FUN_140d73aa0(FUN_14028b8e0(L"s_err_lack_price"), 0, 0, L"");
        break;
    case 0x83:
        FUN_1403ed2b0()->FUN_141add1f0();
        break;
    case 0x84:
        FUN_140d73aa0(FUN_14028b8e0(L"s_err_warehouse"), 0, 0, L"");
        break;
    case 0x85:
        FUN_140d73aa0(FUN_14028b8e0(L"s_ugc_itemedit_error_change_price"), 0, 0, L"");
        break;
    case 0x87:
        FUN_1412751f0(FUN_140a228f0(0x688, *TSingleton<Client::Constants>::GetInstance()->PropertyProtectionTime.Get(), FUN_1409eec40(0x5a8)), 1, 1);
        break;
    case 0x8a:
        break;
    case 0x8b:
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e69);
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e70);
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4f7b);
        break;
    case 0x8e:
        FUN_140d73aa0(FUN_14028b8e0(L"s_ugc_uic_error"), 0, 0, L"");
        break;
    default:
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e69);
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4e70);
        FUN_1403ed2b0()->FUN_141adc5d0(eUI_4f7b);
        FUN_141275260(0x6d7, 1, 1);
        break;
    }
    FUN_1418823f0();
}

// @0x14188fbd0
// The upload went through the game server: a profile image is set on the platform too.
void CUgcManager::FUN_14188fbd0()
{
    {
        MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_141882610();
        if (spCtrl.get() != 0 && !m_str1b0.IsEmpty() && !m_str1b8.IsEmpty())
        {
            if (FUN_140d86260()->vfunc_54(m_str1b0, L"", spCtrl->m_nKind, m_str1b8) == 1)
                FUN_141275260(0x465, 1, 1);
        }
    }
    m_str1b0 = "";
    m_str1b8 = "";
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

// @0x141890240
// qsort order of the local files: the newest first, the same time by name.
static int __cdecl FUN_141890240(const void* p1, const void* p2)
{
    MS2Ptr<CUploadFile> spFile1 = *static_cast<const MS2Ptr<CUploadFile>*>(p1);
    MS2Ptr<CUploadFile> spFile2 = *static_cast<const MS2Ptr<CUploadFile>*>(p2);
    if (spFile1->GetCreateTime() == spFile2->GetCreateTime())
        return spFile1->GetName().Compare(spFile2->GetName());
    return (unsigned __int64)spFile1->GetCreateTime() < (unsigned __int64)spFile2->GetCreateTime() ? 1 : -1;
}
