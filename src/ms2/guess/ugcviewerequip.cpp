// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The UGC viewers: the previews that CUgcManager attaches to a
// CUgcUploadCtrl (equip, cube, mount, banner, profile, wedding profile, guild mark, guild poster, blueprint image), the
// base IUgcViewer, and CUgcUploadCtrl itself (the upload in progress: content kind, the viewer, the local file and the
// result text). Class names are the RTTI names; the unit name is a guess (queue row ?\ugcviewerequip.cpp).
// MS2-UNIT: ?\ugcviewerequip.cpp
// MS2-RANGE: 0x14189eae0-0x1418a7310 .text$mn
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugcviewerequip.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <io.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <efd/SmartPointer.h>
#include <NiTexture.h>
#include <NiSourceTexture.h>
#include <efd/utf8string.h>
#include <NiTexturingProperty.h>

#include "ms2/placeholder/cugcuploadctrl.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/postprocesseffect.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/itemugcmesh.h"
#include "ms2/client/ms2/clonecube.h"
#include "ms2/client/ms2/avatarcube.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/ugcmanager.h"
#include "ms2/unnamed/unit_1401b6d10.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/interactobject.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names) ----

class UIItemBlueprintCreateDialog;
class Unk_VwWearer;

// The world service: the player and the object / entity lookups.
class Unk_ItemEquipData : public CItemData { };             // CItem::FUN_140527840's record (item.cpp)
class Unk_SgNifLoader { public: NiTexturePtr FUN_141553eb0(CString strPath, NiTexture* pkSelf); };
Unk_SgNifLoader* FUN_140a0afd0();
CString FUN_1410280d0(int nKind, CString strName);          // the local file of a ugc content kind
NiAVObject* FUN_141b6efc0(void* pEntity);                   // the scene root of an entity
void FUN_141890b60(egf::Entity* pEntity, const efd::utf8string& strProp, efd::utf8string& strOut);
class Unk_VwWorld
{
public:
    GameObject* FUN_141bd0cc0();                            // the local player
    GameObject* FUN_141bd1290(int nObjectId);               // a player by object id
    egf::Entity* FUN_141bd04d0(int nObjectId);              // an entity by object id
    GameObject* FUN_141bd0fa0(egf::EntityID id);            // the game object of an entity
    MS2Ptr<CInteractObject> FUN_141bc66b0(const CString& strName);   // an interact object by name
};
Unk_VwWorld* FUN_1403ed2d0();
Unk_VwWearer* FUN_140b120b0(GameObject* pPlayer);           // the player as a wearer of items

class Unk_VwWearer
{
public:
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 itemUid);      // a worn item by uid
};

extern Unk_StreamPoint DAT_143b01a60;                       // the zero point
void FUN_1409618c0(egf::Entity* pEntity, unsigned nProperty, Unk_StreamPoint* pOut);   // reads a point property
float FUN_140966f00(NiPoint3 kA, Unk_StreamPoint kB);           // the distance
void* FUN_1401d31f0();                                      // the client config (+0xd8: the upload directory)
void* FUN_140166410();                                      // the game settings
bool FUN_14036e510(void* pSettings);                        // a content switch
void* FUN_1403ed290();                                      // the guild manager (+8: the own guild)
__int64 FUN_1404ccbd0(void* pGuild);                        // the guild id
void* FUN_1403ed2b0();                                      // the UI service
void* FUN_1409eed90();                                      // the singleton of the own character
struct Unk_VwSummary { char m_pad[0x20]; int m_nState; };   // the own character's summary (+0x20: 2 = wedding done)
Unk_VwSummary* FUN_140d295d0(void* pSingleton);


// The upload manager; the CUgcManager singleton.
CUgcManager* FUN_14052d220();

// UI dialogs by id.
void* FUN_140938c30(int nId);                               // 0x2711 the profile dialog
void* FUN_1418764c0(int nId);                               // 0x4f8c the wedding profile dialog
void* FUN_14136f480(int nId);                               // 0x4e4f the guild mark dialog
void FUN_14132faf0(void* pDialog, CStringW strFile);        // show the uploaded image (profile)
void FUN_14132fa90(void* pDialog);
void FUN_140fc7e80(void* pDialog, CStringW strFile);        // (wedding profile)
void FUN_140fc7f30(void* pDialog);
void FUN_141976980(void* pDialog, CStringW strFile);        // (guild mark)
void FUN_1419769d0(void* pDialog);
void FUN_141403180(CInteractGuildPosterObject* pPoster, CStringW strFile);   // load the poster file into the entity
void FUN_141402eb0(CInteractGuildPosterObject* pPoster, unsigned char bShow);

// Textures of the preview files and the format helper strings.
int FUN_14186ced0(NiTexture* pTexture, int nItemId, int nKind, CStringW& strOut);   // the texture fits the item mesh (0 = yes)
int FUN_14186d050(NiTexture* pTexture, int nBannerId, CStringW& strOut);
CString FUN_1411c0aa0(const char* szText);                  // a text without arguments
void FUN_14186bd30(Unk_PPSmartC* pOut, const CStringW& strPath, int nSize, int nFlag);   // the texture of an image file (null on error)

// ---- CUgcViewerEquip ----------------------------------------------------------------------------------------------

// @0x14189eae0
CUgcViewerEquip::CUgcViewerEquip()
{
    m_item.Clear();
    m_icon.Clear();
    m_n108 = 0;
    m_spMesh = 0;
    m_spProperty = 0;
    m_spTexture = 0;
}

// @0x14189ec30
CUgcViewerEquip::CUgcViewerEquip(CItem* pItem)
    : m_item(pItem, pItem == 0 ? 0 : pItem->FUN_140526b10())
    , m_icon(pItem, pItem == 0 ? 0 : pItem->FUN_140526b10())
{
}

// @0x14189ed40
CUgcViewerEquip::~CUgcViewerEquip()
{
    m_spMesh = 0;
    m_spProperty = 0;
    m_spTexture = 0;
}

// @0x14189ee30
int CUgcViewerEquip::vfunc_2()
{
    Unk_VwWearer* pWearer = FUN_140b120b0(FUN_1403ed2d0()->FUN_141bd1290(FUN_14189f730()));
    if (pWearer == 0)
        return 0;
    MS2Ptr<CEquipItem> spEquip = pWearer->FUN_141655c30(m_item.m_itemUid);
    if (spEquip == 0)
        return 0;
    MS2Ptr<CItemUgcMeshContainer> spMeshes = spEquip->FUN_1411dd950();
    if (spMeshes == 0)
        return 0;
    NiTexturePtr spTexture = spMeshes->FUN_141426e30();
    if (spTexture == 0)
        return 0;
    CStringW strError;
    return FUN_14186ced0(spTexture, m_item.m_nItemId, 1, strError) == 0;
}

// @0x14189f040
int CUgcViewerEquip::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    Unk_PPSmartC spTexture;
    FUN_14186bd30(&spTexture, spFile->GetPath(), vfunc_9(), 1);
    if (spTexture.Get() == 0)
        return 0;
    if (FUN_14052d220()->FUN_141886a90(&m_item, (NiTexture*)spTexture.Get()) == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    return 1;
}

// @0x14189f260
void CUgcViewerEquip::vfunc_4()
{
    Unk_VwWearer* pWearer = FUN_140b120b0(FUN_1403ed2d0()->FUN_141bd1290(FUN_14189f730()));
    if (pWearer == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pWearer->FUN_141655c30(m_item.m_itemUid);
    if (spEquip == 0)
        return;
    MS2Ptr<CItemUgcMeshContainer> spMeshes = spEquip->FUN_1411dd950();
    if (spMeshes == 0)
        return;
    spMeshes->FUN_141426980();
}

// @0x14189f360
void CUgcViewerEquip::vfunc_5()
{
    Unk_VwWearer* pWearer = FUN_140b120b0(FUN_1403ed2d0()->FUN_141bd1290(FUN_14189f730()));
    if (pWearer == 0)
        return;
    MS2Ptr<CEquipItem> spEquip = pWearer->FUN_141655c30(m_item.m_itemUid);
    if (spEquip == 0)
        return;
    MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
    if (spItem == 0)
        return;
    if (spItem->FUN_140527840() == 0)
        return;
    m_strMesh = spItem->FUN_140527840()->cubeTextureName.mesh;
}

// @0x14189f490
CString CUgcViewerEquip::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [strUgcMesh={1}] [dropOid={2}] [pcOid={3}]", "UgcViewerEquip", m_strMesh, m_item.m_nSlot, m_item.m_nObjectId);
    return str;
}

// @0x14189f560
void CUgcViewerEquip::vfunc_6(COutPacket& packet)
{
    m_item.Write(packet);
}

// @0x14189f5a0
void CUgcViewerEquip::vfunc_7()
{
}

// @0x14189f5c0
int CUgcViewerEquip::vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind)
{
    if (spProxy == 0)
        return 0;
    if (nKind == 1)
    {
        IUgcProxy* pProxy = spProxy.get();
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_item);
    }
    else if (nKind == 0xc9)
    {
        CUgcItemIconPC* pProxy = static_cast<CUgcItemIconPC*>(spProxy.get());
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_icon);
        pProxy->m_nKind = 2;
    }
    return 1;
}

// @0x14189f700
void CUgcViewerEquip::vfunc_12(__int64 itemUid)
{
    m_item.m_itemUid = itemUid;
    m_icon.m_itemUid = itemUid;
}

// @0x14189f730
int CUgcViewerEquip::FUN_14189f730()
{
    return m_item.m_nObjectId;
}

// @0x14189f750
void CUgcViewerEquip::FUN_14189f750(int nObjectId)
{
    m_item.m_nObjectId = nObjectId;
}

// @0x14189f770
MS2Ptr<IUgcProxy> CUgcViewerEquip::FUN_14189f770(MS2Ptr<IUgcProxy> spOut)
{
    return spOut;
}

// ---- CUgcViewerCube -----------------------------------------------------------------------------------------------

// @0x14189f7c0
CUgcViewerCube::CUgcViewerCube()
{
}

// @0x14189f840
CUgcViewerCube::~CUgcViewerCube()
{
}

// @0x14189f8b0
int CUgcViewerCube::vfunc_2()
{
    efd::SmartPointer<AvatarCube> spCube = efd::DynamicCast<AvatarCube>(FUN_1403ed2d0()->FUN_141bd0fa0(FUN_1418a0110()));
    if (spCube == 0)
        return 0;
    MS2Ptr<CItemUgcMeshContainer> spMeshes = spCube->FUN_141085830();
    if (spMeshes == 0)
        return 0;
    NiTexturePtr spTexture = spMeshes->FUN_141426e30();
    if (spTexture == 0)
        return 0;
    CStringW strError;
    return FUN_14186ced0(spTexture, m_item.m_nItemId, 2, strError) == 0;
}

// @0x14189fab0
int CUgcViewerCube::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    Unk_PPSmartC spTexture;
    FUN_14186bd30(&spTexture, spFile->GetPath(), vfunc_9(), 1);
    if (spTexture.Get() == 0)
        return 0;
    if (FUN_14052d220()->FUN_141886de0(&m_item, (NiTexture*)spTexture.Get()) == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    return 1;
}

// @0x14189fcd0
void CUgcViewerCube::vfunc_4()
{
    efd::SmartPointer<AvatarCube> spCube = efd::DynamicCast<AvatarCube>(FUN_1403ed2d0()->FUN_141bd0fa0(FUN_1418a0110()));
    if (spCube == 0)
        return;
    spCube->FUN_141085250();
}

// @0x14189fd80
void CUgcViewerCube::vfunc_5()
{
    efd::SmartPointer<AvatarCube> spCube = efd::DynamicCast<AvatarCube>(FUN_1403ed2d0()->FUN_141bd0fa0(FUN_1418a0110()));
    if (spCube == 0)
        return;
    CItemData* pData = spCube->FUN_141085880().get();
    if (pData == 0)
        return;
    m_strMesh = pData->cubeTextureName.mesh;
}

// @0x14189fe90
CString CUgcViewerCube::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [strUgcMesh={1}] [itemSN={2}]", "UgcViewerCube", m_strMesh, m_item.m_itemUid);
    return str;
}

// @0x14189ff60
void CUgcViewerCube::vfunc_6(COutPacket& packet)
{
    m_item.Write(packet);
}

// @0x14189ffa0
int CUgcViewerCube::vfunc_8(MS2Ptr<IUgcProxy> spProxy, int nKind)
{
    if (spProxy == 0)
        return 0;
    if (nKind == 2)
    {
        IUgcProxy* pProxy = spProxy.get();
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_item);
    }
    else if (nKind == 0xc9)
    {
        CUgcItemIconPC* pProxy = static_cast<CUgcItemIconPC*>(spProxy.get());
        if (pProxy == 0)
            return 0;
        pProxy->CopyFrom(&m_icon);
        pProxy->m_nKind = 2;
    }
    return 1;
}

// @0x1418a00e0
void CUgcViewerCube::vfunc_12(__int64 itemUid)
{
    m_item.m_itemUid = itemUid;
    m_icon.m_itemUid = itemUid;
}

// @0x1418a0110
egf::EntityID CUgcViewerCube::FUN_1418a0110()
{
    return m_item.m_entityId;
}

// @0x1418a0150
void CUgcViewerCube::FUN_1418a0150(const egf::EntityID& id)
{
    m_item.m_entityId = id;
}

// ---- CUgcViewerBanner (the post at +0x18, the decal state at +0x68, the image at +0x70, the banner record at +0x78) ----

static CUgcBannerPost& Unk_VwPost(CUgcViewerBanner* pViewer)
{
    return *reinterpret_cast<CUgcBannerPost*>(reinterpret_cast<char*>(pViewer) + 0x18);
}
static int& Unk_VwLoaded(CUgcViewerBanner* pViewer)
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(pViewer) + 0x68);
}
static NiTexturePtr& Unk_VwImage(CUgcViewerBanner* pViewer)
{
    return *reinterpret_cast<NiTexturePtr*>(reinterpret_cast<char*>(pViewer) + 0x70);
}
static Unk_BannerPtr& Unk_VwBanner(CUgcViewerBanner* pViewer)
{
    return *reinterpret_cast<Unk_BannerPtr*>(reinterpret_cast<char*>(pViewer) + 0x78);
}

// @0x1418a0180
CUgcViewerBanner::CUgcViewerBanner()
{
    new (&Unk_VwPost(this)) CUgcBannerPost();
    new (&Unk_VwImage(this)) NiTexturePtr(0);
    new (&Unk_VwBanner(this)) Unk_BannerPtr(0);
    Unk_VwPost(this).Clear();
    Unk_VwLoaded(this) = 0;
    Unk_VwImage(this) = 0;
    Unk_VwBanner(this) = 0;
}

// @0x1418a0250
CUgcViewerBanner::~CUgcViewerBanner()
{
    Unk_VwImage(this) = 0;
    Unk_VwBanner(this) = 0;
    Unk_VwBanner(this).~Unk_BannerPtr();
    Unk_VwImage(this).~NiTexturePtr();
    Unk_VwPost(this).~CUgcBannerPost();
}

// @0x1418a02f0
void CUgcViewerBanner::vfunc_1()
{
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_nBannerId);
    if (spEntity == 0)
        return;
    GameObject* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    NiPoint3 kPlayer = pPlayer->vfunc_18();
    Unk_StreamPoint kBanner = DAT_143b01a60;
    FUN_1409618c0(spEntity, 0xfd95ca52, &kBanner);
    float fDistance = FUN_140966f00(kPlayer, kBanner);
    float fLimit = FUN_1401d3200()->RegistUgcDistanceClose.Read();
    if (fLimit < fDistance)
        FUN_14052d220()->FUN_14187f1f0();
}

// @0x1418a04d0
int CUgcViewerBanner::vfunc_2()
{
    if (Unk_VwImage(this) == 0)
        return 0;
    CStringW strError;
    return FUN_14186d050(Unk_VwImage(this), m_nBannerId, strError) == 0;
}

// @0x1418a0580
int CUgcViewerBanner::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_nBannerId);
    if (spEntity == 0)
        return 0;
    Unk_PPSmartC spTexture;
    FUN_14186bd30(&spTexture, spFile->GetPath(), vfunc_9(), 1);
    if (spTexture.Get() == 0)
        return 0;
    if (FUN_14052d220()->FUN_141888770(spEntity, (NiTexture*)spTexture.Get()) == 1)
        spCtrl->m_spFile = spFile;
    return 1;
}

// @0x1418a0800
void CUgcViewerBanner::vfunc_4()
{
    int nBannerId = m_nBannerId;
    NiTexturePtr spTexture;
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_nBannerId);
    if (spEntity == 0)
        return;
    MS2Ptr<CUgcRegistBanner> spRegist = FUN_14052d220()->FUN_141887ce0(nBannerId);
    if (spRegist != 0)
    {
        CString strFile = FUN_1410280d0(3, spRegist->m_strUrl);
        if (_access(strFile, 0) == 0)
        {
            spTexture = FUN_140a0afd0()->FUN_141553eb0(strFile, 0);
            if (spTexture == 0)
            {
                FUN_14052d220()->FUN_141884af0(spRegist);
                return;
            }
        }
        else
            spTexture = Unk_VwImage(this);
    }
    else
        spTexture = Unk_VwImage(this);
    FUN_14052d220()->FUN_141888770(spEntity, spTexture);
}

// @0x1418a0b10
void CUgcViewerBanner::vfunc_5()
{
    if (Unk_VwLoaded(this) == 1)
        return;
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_nBannerId);
    if (spEntity == 0)
        return;
    NiAVObject* pRoot = FUN_141b6efc0(spEntity.data());
    if (pRoot == 0)
        return;
    efd::utf8string strMesh;
    efd::utf8string strTexture;
    FUN_141890b60(spEntity, efd::utf8string("Index00MeshName"), strMesh);
    FUN_141890b60(spEntity, efd::utf8string("Index00TexturePath"), strTexture);
    if (strMesh.empty())
        return;
    NiAVObject* pMesh = pRoot->GetObjectByName(NiFixedString(strMesh.c_str()));
    if (pMesh == 0)
        return;
    NiTexturingProperty* pProperty = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(NiProperty::TEXTURING));
    if (pProperty == 0)
        return;
    Unk_VwImage(this) = pProperty->GetDecalMap(0)->GetTexture();
    Unk_VwLoaded(this) = 1;
}

// @0x1418a0d70
CString CUgcViewerBanner::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [bannerSN={1}]", "UgcViewerBanner", m_nBannerId);
    return str;
}

// @0x1418a0e20
void CUgcViewerBanner::vfunc_6(COutPacket& packet)
{
    Unk_VwPost(this).Write(packet);
}

// @0x1418a0e60
int CUgcViewerBanner::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&Unk_VwPost(this));
    return 1;
}

// @0x1418a0f20
int CUgcViewerBanner::vfunc_9()
{
    CFieldBannerData* pBanner = CFieldBannerData::GetBanner(m_nBannerId).get();
    if (pBanner == 0)
        return 0;
    return pBanner->m_nSize;
}

// @0x1418a0f90
void CUgcViewerBanner::FUN_1418a0f90(int nBannerId)
{
    m_nBannerId = nBannerId;
    Unk_VwBanner(this) = CFieldBannerData::GetBanner(nBannerId);
}

// @0x1418a1000
void CUgcViewerBanner::FUN_1418a1000()
{
    efd::SmartPointer<egf::Entity> spEntity = FUN_1403ed2d0()->FUN_141bd04d0(m_nBannerId);
    if (spEntity == 0)
        return;
    NiTexturePtr spTexture = Unk_VwImage(this);
    FUN_14052d220()->FUN_141888770(spEntity, spTexture);
}

// ---- CUgcViewerProfile --------------------------------------------------------------------------------------------

// @0x1418a10e0
CUgcViewerProfile::CUgcViewerProfile()
{
    m_bRefreshed = 0;
    m_user.Clear();
}

// @0x1418a1160
CUgcViewerProfile::~CUgcViewerProfile()
{
}

// @0x1418a11a0
int CUgcViewerProfile::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    void* pDialog = FUN_140938c30(0x2711);
    if (pDialog == 0)
        return 0;
    FUN_14132faf0(pDialog, strThumb);
    return 1;
}

// @0x1418a1430
void CUgcViewerProfile::vfunc_4()
{
    void* pDialog = FUN_140938c30(0x2711);
    if (pDialog != 0)
        FUN_14132fa90(pDialog);
}

// @0x1418a1470
void CUgcViewerProfile::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a1490
CString CUgcViewerProfile::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [objectId={1}]", "UgcViewerProfile", m_user.m_strObjectName);
    return str;
}

// @0x1418a1540
int CUgcViewerProfile::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_user);
    return 1;
}

// @0x1418a1600
int CUgcViewerProfile::vfunc_9()
{
    return 0x6b;
}

// ---- CUgcViewerWeddingProfile -------------------------------------------------------------------------------------

// @0x1418a1620
CUgcViewerWeddingProfile::CUgcViewerWeddingProfile()
{
    m_bRefreshed = 0;
    m_user.Clear();
}

// @0x1418a1670
CUgcViewerWeddingProfile::~CUgcViewerWeddingProfile()
{
}

// @0x1418a16b0
int CUgcViewerWeddingProfile::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    if (FUN_140d295d0(FUN_1409eed90())->m_nState != 2)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    void* pDialog = FUN_1418764c0(0x4f8c);
    if (pDialog == 0)
        return 0;
    FUN_140fc7e80(pDialog, strThumb);
    return 1;
}

// @0x1418a1970
void CUgcViewerWeddingProfile::vfunc_4()
{
    void* pDialog = FUN_1418764c0(0x4f8c);
    if (pDialog != 0)
        FUN_140fc7f30(pDialog);
}

// @0x1418a19b0
void CUgcViewerWeddingProfile::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a19d0
CString CUgcViewerWeddingProfile::vfunc_11()
{
    CString str;
    str = FUN_1411c0aa0("[viewer=UgcViewerWeddingProfile]");
    return str;
}

// @0x1418a1a70
int CUgcViewerWeddingProfile::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_user);
    return 1;
}

// @0x1418a1b30
int CUgcViewerWeddingProfile::vfunc_9()
{
    return 0xaa;
}

// ---- CUgcViewerGuildMark ------------------------------------------------------------------------------------------

// @0x1418a1b50
CUgcViewerGuildMark::CUgcViewerGuildMark()
{
    m_bRefreshed = 0;
    m_mark.Clear();
}

// @0x1418a1bd0
CUgcViewerGuildMark::~CUgcViewerGuildMark()
{
}

// @0x1418a1c10
int CUgcViewerGuildMark::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    if (FUN_1404ccbd0((char*)FUN_1403ed290() + 8) == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    void* pDialog = FUN_14136f480(0x4e4f);
    if (pDialog == 0)
        return 0;
    FUN_141976980(pDialog, strThumb);
    return 1;
}

// @0x1418a1ee0
void CUgcViewerGuildMark::vfunc_4()
{
    void* pDialog = FUN_14136f480(0x4e4f);
    if (pDialog != 0)
        FUN_1419769d0(pDialog);
}

// @0x1418a1f20
void CUgcViewerGuildMark::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a1f40
CString CUgcViewerGuildMark::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [guild={1}] [objectId={2}]", "UgcViewerGuildMark", m_mark.m_nGuildId, m_mark.m_strName);
    return str;
}

// @0x1418a2000
void CUgcViewerGuildMark::vfunc_6(COutPacket& packet)
{
    m_mark.Write(packet);
}

// @0x1418a2040
int CUgcViewerGuildMark::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_mark);
    return 1;
}

// @0x1418a2100
int CUgcViewerGuildMark::vfunc_9()
{
    return 0x6b;
}

// ---- CUgcViewerGuildPoster ----------------------------------------------------------------------------------------

// @0x1418a2120
CUgcViewerGuildPoster::CUgcViewerGuildPoster()
{
    m_bRefreshed = 0;
    m_poster.Clear();
}

// @0x1418a21a0
CUgcViewerGuildPoster::~CUgcViewerGuildPoster()
{
}

// @0x1418a21e0
int CUgcViewerGuildPoster::vfunc_3(MS2Ptr<CUploadFile> spFile)
{
    if (spFile == 0)
        return 0;
    MS2Ptr<CUgcUploadCtrl> spCtrl = FUN_14052d220()->FUN_141882610();
    if (spCtrl == 0)
        return 0;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    if (FUN_1404ccbd0((char*)FUN_1403ed290() + 8) == 0)
        return 0;
    CStringW strPath = spFile->GetPath();
    if (_waccess(strPath, 0) != 0)
        return 0;
    CStringW strThumb = spFile->GetThumbnailPath();
    if (strThumb.GetLength() == 0)
        return 0;
    spCtrl->m_spFile = spFile;
    MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(m_poster.m_strName);
    CInteractGuildPosterObject* pPoster = dynamic_cast<CInteractGuildPosterObject*>(spObject.get());
    if (pPoster != 0)
        FUN_141403180(pPoster, strThumb);
    return 1;
}

// @0x1418a2520
void CUgcViewerGuildPoster::vfunc_4()
{
    MS2Ptr<CInteractObject> spObject = FUN_1403ed2d0()->FUN_141bc66b0(m_poster.m_strName);
    CInteractGuildPosterObject* pPoster = dynamic_cast<CInteractGuildPosterObject*>(spObject.get());
    if (pPoster != 0)
        FUN_141402eb0(pPoster, 1);
}

// @0x1418a25d0
void CUgcViewerGuildPoster::vfunc_5()
{
    m_bRefreshed = 1;
}

// @0x1418a25f0
CString CUgcViewerGuildPoster::vfunc_11()
{
    CString str;
    str = Unk_SocketFormat("[viewer={0}] [guild={1}] [objectId={2}]", "CUgcViewerGuildPoster", m_poster.m_nGuildId, m_poster.m_strName);
    return str;
}

// @0x1418a26b0
void CUgcViewerGuildPoster::vfunc_6(COutPacket& packet)
{
    m_poster.Write(packet);
}

// @0x1418a26f0
int CUgcViewerGuildPoster::vfunc_13(MS2Ptr<IUgcProxy> spProxy)
{
    if (spProxy == 0)
        return 0;
    IUgcProxy* pProxy = spProxy.get();
    if (pProxy == 0)
        return 0;
    pProxy->CopyFrom(&m_poster);
    return 1;
}

// @0x1418a27b0
int CUgcViewerGuildPoster::vfunc_9()
{
    return 0x6b;
}
