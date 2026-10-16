// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See functioncubeobject.h.
// MS2-UNIT: client\ms2\functioncubeobject.cpp
// MS2-RANGE: 0x141225080-0x14123a080 .text$mn
// MS2-RANGE: 0x1400e9c70-0x1400ea080 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\functioncubeobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "functioncubeobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/gfxui/uiswfentity.h"
#include <efd/AssetID.h>
#include <egf/EntityIDFactory.h>
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/client/ms2/statedata.h"

// ---- unit-local placeholders ----

// Reference counted service objects (AddRef / Release are the first virtuals after the destructor).
class Unk_FcRefObj
{
public:
    virtual ~Unk_FcRefObj();
    virtual void vfunc_1();                                         // AddRef
    virtual void vfunc_2();                                         // Release
};

// Item rows seen through the item service: the row owns a text block with the notice string.
class Unk_FcItemText : public CPtred
{
public:
    const CStringW& FUN_1408b49c0();                                // the notice string
    char m_pad_18[0x28];
};
// An item table row (ItemData): only its id and the text block are read here.
class Unk_FcItemRow : public CPtred
{
public:
    int FUN_1408b4f20();                                            // item id
    char m_pad_18[0xe8];
    MS2Ptr<Unk_FcItemText> m_spText;                                // +0x100
};
MS2_CHECK_OFFSET(Unk_FcItemRow, m_spText, 0x100);

// The item service the global at 0x143b059e8 hands out.
class Unk_FcItemSvc : public Unk_FcRefObj
{
public:
    Unk_FcItemRow* FUN_1410b8b00(int nItemId);                      // find the row of an item
};
class Unk_FcItemSvcPtr
{
public:
    Unk_FcItemSvcPtr(Unk_FcItemSvc* p)
    {
        m_p = p;
        if (m_p)
            m_p->vfunc_1();
    }
    ~Unk_FcItemSvcPtr();                                            // 0x1401cd150
    Unk_FcItemSvc* FUN_1401cd1a0() const;                           // operator->
    bool FUN_140ef4cb0(int) const;                                  // == NULL
private:
    Unk_FcItemSvc* m_p;
};
extern char DAT_143b059e8;                                          // service lookup cell
Unk_FcItemSvc* FUN_1401cd040(char* pCell);

// The game-wide effect / sound manager (a request is the 0x78-byte Unk_FcSoundReq).
class Unk_FcFxMgr
{
public:
    int FUN_1411a49c0(Unk_FcSoundReq* pRequest);                    // play, returns the handle
    void FUN_1411a6060(int nHandle);                                // stop
    void FUN_1411a5580(int nId, int nOwner, int bFlag, const Unk_StreamPoint& vPos, unsigned nColor);
};
Unk_FcFxMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_FcSoundReq* p);                              // construct
void FUN_1405a89e0(Unk_FcSoundReq* p);                              // destroy
void FUN_1409fabf0(void* pSub, void* pAnchor);                      // construct the 0x68 block from an anchor
void* FUN_14098d8d0(void* pCell, NiAVObject* pRoot);
extern char DAT_143afa4d8;
NiAVObject* FUN_141b6efc0(Unk_Entity* pEntity);

// The camera manager and the camera effect it plays.
struct Unk_FcCamFx
{
    int m_nKind;                                                    // +0x00
    float m_fScale;                                                 // +0x04
    int m_n8;                                                       // +0x08
    int m_nC;                                                       // +0x0c
    int m_n10;                                                      // +0x10
    Unk_StreamPoint m_v14;                                          // +0x14
    Unk_StreamPoint m_v20;                                          // +0x20
    int m_n2c;                                                      // +0x2c
    int m_n30;                                                      // +0x30
    int m_n34;                                                      // +0x34
    int m_n38;                                                      // +0x38
    char m_unk3c[12];                                               // +0x3c
    char m_unk48[56];                                               // +0x48
};
MS2_CHECK_SIZE(Unk_FcCamFx, 0x80);
class Unk_FcCamMgr
{
public:
    int FUN_140a18070();                                            // has a camera
    int FUN_140ad4b40();
    int FUN_140af7f00();
    int FUN_140af7ea0();
    Unk_StreamPoint* FUN_140a17e10(Unk_StreamPoint* pOut);
    Unk_StreamPoint* FUN_140af8290(Unk_StreamPoint* pOut);
    void FUN_140aeb420(int nEffect, Unk_FcCamFx* pParam);
};
Unk_FcCamMgr* FUN_1409478c0();
void FUN_140947440(Unk_FcCamFx* p);                                 // construct
void FUN_141839640(void* pDst, void* pSrc);
void FUN_14183c3e0(void* pDst, void* pSrc);

// Entity property access and ids (free functions: x64 has one calling convention).
int FUN_1409618c0(Unk_Entity* pEntity, unsigned uPropId, Unk_StreamPoint* pOut);           // point property (0 = ok)
void FUN_1402bd040(Unk_StreamPoint* p);
Unk_StreamPoint* FUN_14027dda0(Unk_StreamPoint* t, float x, float y, float z);
void FUN_1408a20a0(Unk_Entity* pEntity, unsigned nHash, char* pbOut);
const egf::EntityID* FUN_1408b76f0(Unk_Entity* pEntity);
egf::EntityID* FUN_1408b6b20(egf::EntityID* pDst, const egf::EntityID* pSrc);
void FUN_141b71e70(egf::EntityID id, bool bEnable, unsigned uColor, bool bSkipEffectRoot);
class Unk_FcAnimSvc { public: char m_pad[8]; };
struct Unk_FcAnimName { char m_pad[0x10]; };
Unk_FcAnimSvc* FUN_141b6f910();
void FUN_1409989e0(Unk_FcAnimName*, const char*);
void FUN_1409a1fc0(Unk_FcAnimSvc*, const egf::EntityID&, Unk_FcAnimName*, float);
void FUN_1408a8900(Unk_FcAnimName*);

unsigned char FUN_1402a5b40(const CString& a, const char* b);                // CString != C string
unsigned char FUN_1401647e0(const CString& a, const CString& b);             // CString == CString

// The use-request the cube sends (CString id + count); constructed / destroyed by exe helpers.
struct Unk_FcUseInfo
{
    CString m_strId;                                                // +0x00
    int m_nCount;                                                   // +0x08
    char m_pad_0c[4];
};
void FUN_140ac2e80(Unk_FcUseInfo* p);                               // construct
void FUN_140ac3050(Unk_FcUseInfo* p);                               // destroy
void FUN_1401fc610(Unk_FcUseInfo* pInfo, COutPacket* pPacket);      // serialize
void FUN_140710590(COutPacket& packet);                             // send

// The game constants table (the camera-fx / sound range constant is a float slot).
struct Unk_FcConstF { char m_pad[8]; float FUN_1402bac70() const; };
struct Unk_FcConstTable
{
    char m_pad_00[0x13f8];
    Unk_FcConstF m_range;                                           // +0x13f8
};
MS2_CHECK_OFFSET(Unk_FcConstTable, m_range, 0x13f8);
Unk_FcConstTable* FUN_1401d3200();

// UI windows this unit opens (classes of other units; only what is called).
class Unk_FcUIMgr
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                        // find a window
    bool FUN_141adc890(int nId);                                    // is open
    void FUN_141adc5d0(int nId);                                    // close
};
Unk_FcUIMgr* FUN_1403ed2b0();
class UITriggerEditorDialog : public UIDialog { public: void FUN_141b2b9a0(CString str, int n); };
class UIHomePasswordDialog : public UIDialog { public: void FUN_1412c9680(CString str); };
class UIHomeSummonDialog : public UIDialog { public: void FUN_141299eb0(CString str); };
class UIObjectStoreDialog : public UIDialog { public: virtual void vfunc_84(CString* pId, int nItemId); };
void FUN_141924680(UIDialog* pDialog);                              // show
template <class T> T* Unk_FcDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// The UI message sent to the swf entity registered for an event id (UIMsg: 0x50 bytes; dtor 0x140c30570).
struct Unk_FcUIMsg
{
    ~Unk_FcUIMsg();                                                 // 0x140c30570
    char m_pad[0x50];
};
void FUN_1422e4490(Unk_FcUIMsg* p);                                 // construct
void FUN_1422b82b0(Unk_FcUIMsg* p, const char* psz);                // append an argument
void* FUN_1408e57f0();
UISwfEntity* FUN_1422b9e20(void* pMgr, int nEvent);                 // the entity registered for the event
void FUN_1422b9fd0(void* pMgr, int nEvent);                         // unregister
void FUN_140de2a30(void* pCell, int nItemId, int nCubeItemId);
extern char DAT_143ab2d80;

// Physics helper (singleton): the interaction-start call.
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();
void FUN_141689ec0(CPhysXHelper* pHelper, Unk_Entity* pEntity, short nKind, int nArg, int bFlag);

// Housing data service (singleton) and the cube service the objects talk to.
class Unk_FcHomeSvc;
Unk_FcHomeSvc* FUN_1409670b0();
void FUN_141231ce0(Unk_FcHomeSvc* pSvc, int nSlot, CString strId, int bShow);
void FUN_1419f37f0(unsigned nFlag);


// The popups the object owns (members of unrecovered UI classes, called as free functions).
void FUN_1410315f0(UIBootyPopup* p);                                // close and release
void FUN_141031660(UIBootyPopup* p, Unk_StreamPoint vPos);
void FUN_141031690(UIBootyPopup* p, egf::EntityID kId);
void FUN_1410316d0(UIBootyPopup* p, int nItemId);
void FUN_1410315c0(UIBootyPopup* p);                                // show
void FUN_141031a60(UIBootyPopup* p, int bShow);
void FUN_140fb4be0(UIUGCCubeNoticePopup* p);                        // close and release
void FUN_140fb4c50(UIUGCCubeNoticePopup* p, Unk_StreamPoint vPos);
void FUN_140fb4cc0(UIUGCCubeNoticePopup* p, const CStringW& strA, const CStringW& strB);
void FUN_140fb4bb0(UIUGCCubeNoticePopup* p);
void FUN_140fb5080(UIUGCCubeNoticePopup* p, int bShow);

// Strings and animation/listener glue of other units.
class Unk_FcStrMgr { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_FcStrMgr* FUN_1401a9d70();
CStringW FUN_14028de60(int nId);                                    // string table lookup
CStringW FUN_14061ad70(const CStringW& str, const wchar_t* psz);    // str + psz
CStringW FUN_1401d0080(const CStringW& strA, const CStringW& strB); // strA + strB
void FUN_140997ab0(egf::EntityPtr spEntity, NiActorManager::CallbackObject* pCb);
extern Unk_StreamPoint DAT_143b01a60;                               // the zero point

// ---- the unit's header statics ----
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static egf::EntityID s_nullId(0);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x14122edc0
int FUN_14122edc0(int nState)
{
    switch (nState)
    {
    case 4:
        return 1;
    case 3:
        return 0;
    case 5:
        return 2;
    }
    return nState;
}

// @0x141225080
CFunctionCubeObject::CFunctionCubeObject()
    : m_bAlt(0), m_ent(0), m_nState(0), m_nArg2(0), m_n60(0), m_nSoundHandle(0)
{
    m_b21 = 0;
    m_ent = 0;
    m_bFxOn = 0;
    m_spItem.AssignRaw(new CubeItemInfo);
    m_spData.AssignRaw(new FunctionCubeData);
}

// @0x141225270
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
CFunctionCubeObject::~CFunctionCubeObject()
{
    if (m_nSoundHandle != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nSoundHandle);
    if (m_bFxOn != 0)
        FUN_1409478c0()->FUN_140aeb420(2, 0);
    m_ent = 0;
    m_spItem = 0;
    m_spData = 0;
    if (m_spBooty.get() != 0)
        FUN_1410315f0(m_spBooty.get());
    m_spBooty = 0;
    if (m_spNotice.get() != 0)
        FUN_140fb4be0(m_spNotice.get());
    m_spNotice = 0;
}

// @0x1412255c0
void CFunctionCubeObject::vfunc_1(Unk_FcMsg* pMsg)
{
    m_nState = pMsg->m_src.vfunc_3();
}

// @0x141226300
void CFunctionCubeObject::vfunc_3()
{
}

// @0x141226310
void CFunctionCubeObject::vfunc_4()
{
}

// @0x141226320
void CFunctionCubeObject::vfunc_5(float)
{
}

// @0x141225610
// MS2-FUNCTIONAL: row copy and box setup written with typed stand-ins; frame layout and the temporaries differ
int CFunctionCubeObject::vfunc_2(Unk_Entity* pEntity, const Unk_FcRow* pRow, int nArg, __int64 nArg2, CubeItemInfo* pItem)
{
    m_nArg = nArg;
    m_nArg2 = nArg2;
    m_spData->m_nCubeId = pRow->m_nCubeId;
    m_spData->m_nKind = pRow->m_nKind;
    m_spData->m_nSubKind = pRow->m_nSubKind;
    m_spData->m_nSub = pRow->m_nSub;
    m_spData->m_nEffect = pRow->m_nEffect;
    m_spData->m_bBuff = 0;
    m_spData->m_bLike = 0;
    m_spData->m_n84 = pRow->m_n84;
    m_spData->m_strModel = pRow->m_strModel;
    m_spData->m_n90 = pRow->m_n118;
    m_spData->m_strStr98 = pRow->m_strStr98;
    m_spData->m_vA0 = pRow->m_vA0;
    m_spData->m_vAC = pRow->m_vAC;
    m_spData->m_strB8 = pRow->m_strB8;
    m_spData->m_strC0 = pRow->m_strC0;
    m_spData->m_strC8 = pRow->m_strC8;
    m_spData->m_opt = pRow->m_opt;
    m_spData->m_nE8 = pRow->m_nE8;
    m_spData->m_nEC = pRow->m_nEC;
    m_spData->m_nF0 = pRow->m_nF0;
    m_spData->m_nF4 = pRow->m_nF4;
    m_spData->m_nF8 = pRow->m_nF8;
    m_spData->m_skill = pRow->m_skill;
    m_spData->m_strNotice = pRow->m_strNotice;
    m_spItem->FUN_1408b3700(pItem);
    if (pRow->m_nKind == 3 && pRow->m_nSub == 1)
        m_spData->m_bBuff = 1;
    if (pRow->m_nKind == 9 && pRow->m_nSub == 1)
        m_spData->m_bBuff = 1;
    if (pRow->m_nKind == 3 && pRow->m_nSub == 2)
        m_spData->m_bLike = 1;
    m_spData->m_anims.SetCount(6, -1);
    for (size_t i = 0; i < m_spData->m_anims.GetCount(); i++)
    {
        if (FUN_1402a5b40(pRow->m_anims[i], ""))
            m_spData->m_anims[i].Add(pRow->m_anims[i]);
    }
    m_spData->m_sounds.SetCount(6, -1);
    for (size_t i = 0; i < m_spData->m_sounds.GetCount(); i++)
        m_spData->m_sounds[i] = pRow->m_sounds[i];
    for (size_t i = 0; i < 3; i++)
        m_spData->m_aAnim[i] = pRow->m_aAnim[i];
    m_ent.FUN_1408b6ec0(pEntity);
    Unk_StreamPoint vSize;
    Unk_StreamPoint vRot;
    Unk_StreamPoint vPos;
    FUN_1409618c0(pEntity, 0xcb086a2d, &vSize);
    FUN_1409618c0(pEntity, 0xfd95ca52, &vPos);
    FUN_1409618c0(pEntity, 0x68c7c29d, &vRot);
    if (vSize.FUN_140552690(DAT_143b01a60))
    {
        vSize.x = 150.0f;
        vSize.y = 150.0f;
        vSize.z = 150.0f;
    }
    Unk_StreamPoint vBox(vSize.x, vSize.y * 0.5f, vSize.z);
    Unk_StreamPoint vOffset(0.0f, vSize.y * 0.5f, 0.0f);
    m_spBox.AssignRaw(new CBoxCollision);
    m_spBox->m_ptBox = vBox;
    m_spBox->m_ptSize = vOffset;
    m_spBox->m_kColor = NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
    m_spBox->vfunc_4();
    m_spBox->vfunc_3(vPos, vRot, 1.0f);
    FUN_140997ab0(egf::EntityPtr(reinterpret_cast<egf::Entity*>(pEntity)), static_cast<CGlobalKeyTextCallback*>(this));
    vfunc_12(pRow->m_nState, true);
    if (pRow->m_opt.m_n14 != 0)
    {
        m_spBooty.AssignRaw(new UIBootyPopup);
        FUN_141031660(m_spBooty.operator->(), Unk_StreamPoint(vPos.x, vPos.y, vPos.z + 150.0f));
        FUN_141031690(m_spBooty.operator->(), *FUN_1408b76f0(m_ent.FUN_1408a9280()));
        FUN_1410316d0(m_spBooty.operator->(), FUN_141226cd0());
        FUN_1410315c0(m_spBooty.operator->());
    }
    return 1;
}

// @0x141226340
// MS2-FUNCTIONAL: string pieces glued with FUN_ operators; frame layout differs
CStringW CFunctionCubeObject::vfunc_6()
{
    Unk_FcItemSvcPtr spSvc(FUN_1401cd040(&DAT_143b059e8));
    if (!spSvc.FUN_140ef4cb0(0))
    {
        Unk_FcItemRow* pRow = spSvc.FUN_1401cd1a0()->FUN_1410b8b00(FUN_14112e110());
        if (pRow == 0)
            return CStringW(L"");
        if (FUN_140966fc0() != 3 && FUN_140966fc0() != 9)
            return CStringW(L"");
        int nItemId = pRow->FUN_1408b4f20();
        CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
        return FUN_1401d0080(FUN_14061ad70(FUN_14028de60(0x63e), L" - "), strName);
    }
    return CStringW(L"");
}

// @0x141226580
CStringW CFunctionCubeObject::vfunc_7()
{
    return CStringW(L"key");
}

// @0x1412265d0
// MS2-FUNCTIONAL: packet written with the typed COutPacket; frame layout differs
void CFunctionCubeObject::vfunc_8(CString str)
{
    if (FUN_140966fc0() == 3 || FUN_140966fc0() == 9)
    {
        Unk_FcUseInfo kInfo;
        FUN_140ac2e80(&kInfo);
        kInfo.m_strId = m_strId;
        kInfo.m_nCount = 1;
        COutPacket kPacket(0x2e, 0);
        kPacket.vfunc_o10_1(5);
        kPacket.vfunc_o10_3(1);
        FUN_1401fc610(&kInfo, &kPacket);
        FUN_140710590(kPacket);
        FUN_140ac3050(&kInfo);
    }
}

// @0x1412266c0
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
bool CFunctionCubeObject::vfunc_9(CString str)
{
    return FUN_1401647e0(m_strId, str) != 0;
}

// @0x141226730
// MS2-FUNCTIONAL: random pick over the state's sound list; frame layout differs
void CFunctionCubeObject::vfunc_10(int nState, bool bFlag)
{
    if (nState < 0 || nState >= 6)
        return;
    Unk_FcStrList arrAnims;
    arrAnims.Copy(m_spData->m_anims[nState]);
    if (arrAnims.IsEmpty())
    {
        if (bFlag)
        {
            vfunc_12(FUN_14122edc0(nState), false);
            return;
        }
    }
    else if (m_spData->m_nCubeId != 0)
    {
        int nPick = rand() % arrAnims.GetCount();
        Unk_FcAnimName kName;
        FUN_1409989e0(&kName, arrAnims[nPick]);
        FUN_1409a1fc0(FUN_141b6f910(), *FUN_1408b76f0(m_ent.FUN_1408a9280()), &kName, 1.0f);
        FUN_1408a8900(&kName);
    }
    vfunc_11(nState);
}

// @0x141226950
// MS2-FUNCTIONAL: sound request built with the unit-local request type; frame layout differs
void CFunctionCubeObject::vfunc_11(int nState)
{
    if (m_nSoundHandle != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nSoundHandle);
    CString strSound = m_spData->m_sounds[nState];
    if (!strSound.IsEmpty())
    {
        Unk_FcSoundReq kReq;
        FUN_140a52ef0(&kReq);
        kReq.m_strName = strSound;
        kReq.m_nType = 0;
        FUN_1409fabf0(kReq.m_unk, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(m_ent.FUN_1408a9090())));
        m_nSoundHandle = FUN_1403ed280()->FUN_1411a49c0(&kReq);
        FUN_1405a89e0(&kReq);
    }
}

// @0x141226a90
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::vfunc_12(int nState, bool bFlag)
{
    if (nState < 0 || nState >= 6)
    {
        MS2_ASSERT_AT(0x126, FALSE);
        return;
    }
    m_nState = nState;
    if (!m_ent.FUN_1408b70b0(0))
        FUN_141226c20(bFlag);
}

// @0x141226b20
void CFunctionCubeObject::vfunc_14(MS2Ptr<Unk_FcStateMsg> sp)
{
    vfunc_12(sp->FUN_14112e290(), false);
}

// @0x141226b80
void CFunctionCubeObject::FUN_141226b80(CString str)
{
    m_strId = str;
}

// @0x141226bd0
CString CFunctionCubeObject::FUN_141226bd0()
{
    return m_strId;
}

// @0x141226c20
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::FUN_141226c20(bool bFlag)
{
    int nState = m_nState;
    if (nState >= 0)
    {
        if (nState <= 2)
            vfunc_10(m_nState, false);
        else if (nState > 2 && nState <= 5)
            vfunc_10(m_nState, true);
    }
    if (!bFlag)
    {
        FUN_141227950();
        FUN_141227cd0();
        FUN_141227dd0(0);
    }
}

// @0x141226cd0
int CFunctionCubeObject::FUN_141226cd0()
{
    return m_spItem->itemId;
}

// @0x141226d00
Unk_StreamPoint CFunctionCubeObject::FUN_141226d00()
{
    Unk_StreamPoint vPos;
    FUN_1409618c0(m_ent.FUN_1408a9280(), 0xfd95ca52, &vPos);
    return vPos;
}

// @0x141226d70
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    CGlobalKeyTextCallback::EndOfSequence(pkManager, eSequenceID, pkSeq, fEventTime);
    switch (m_nState)
    {
    case 3:
        vfunc_12(0, false);
        break;
    case 4:
        vfunc_12(1, false);
        break;
    case 5:
        vfunc_12(2, false);
        break;
    }
}

// @0x141226e60
Unk_EntRef CFunctionCubeObject::FUN_141226e60()
{
    return m_ent;
}

// @0x141226eb0
egf::EntityID CFunctionCubeObject::FUN_141226eb0()
{
    const egf::EntityID* pId = m_ent.FUN_1408a9090() != 0 ? FUN_1408b76f0(m_ent.FUN_1408a9280()) : &s_nullId;
    return *pId;
}

// @0x141226f30
int CFunctionCubeObject::vfunc_15()
{
    if (FUN_14122e710() == 0)
        return 0;
    if (FUN_140966fc0() == 3)
        return 1;
    if (FUN_140966fc0() == 9)
        return 1;
    return 0;
}

// @0x141226f90
// MS2-FUNCTIONAL: pose refresh through unit-local stand-ins; frame layout differs
MS2Ptr<CBoxCollision> CFunctionCubeObject::FUN_141226f90()
{
    Unk_StreamPoint vPos;
    Unk_StreamPoint vRot;
    FUN_1409618c0(m_ent.FUN_1408a9280(), 0xfd95ca52, &vPos);
    FUN_1409618c0(m_ent.FUN_1408a9280(), 0x68c7c29d, &vRot);
    if (m_spBox.get() != 0)
        m_spBox->vfunc_3(vPos, vRot, 1.0f);
    return m_spBox;
}

// @0x141227100
// MS2-FUNCTIONAL: the position copy and the float temporary differ
void CFunctionCubeObject::FUN_141227100(int nSound)
{
    Unk_StreamPoint vPos;
    FUN_1409618c0(m_ent.FUN_1408a9280(), 0xfd95ca52, &vPos);
    float fRange = FUN_1401d3200()->m_range.FUN_1402bac70();
    FUN_1403ed280()->FUN_1411a5580(nSound, m_n60, 1, vPos, fRange);
}

// @0x1412271c0
void CFunctionCubeObject::FUN_1412271c0(int nState)
{
    m_nState = nState;
    m_b21 = 1;
}

// @0x1412271f0
int CFunctionCubeObject::FUN_1412271f0()
{
    return FUN_1402a5b40(m_spData->m_strModel, "") || m_spData->m_n90 != 0;
}

// @0x141227270
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
unsigned char CFunctionCubeObject::FUN_141227270()
{
    return FUN_1402a5b40(m_spData->m_skill.m_strA, "");
}

// @0x1412272b0
Unk_FcSkillText CFunctionCubeObject::FUN_1412272b0()
{
    return m_spData->m_skill;
}

// @0x141227310
void CFunctionCubeObject::FUN_141227310()
{
    if (m_spBooty.get() != 0)
        FUN_141031a60(m_spBooty.operator->(), 1);
}

// @0x141227360
void CFunctionCubeObject::FUN_141227360()
{
    if (m_spBooty.get() != 0)
        FUN_141031a60(m_spBooty.operator->(), 0);
}

// @0x1412273b0
// MS2-FUNCTIONAL: item text lookup written with unit-local MS2Ptr stand-ins; frame layout differs
void CFunctionCubeObject::FUN_1412273b0()
{
    if (FUN_140966fc0() != 0xc)
        return;
    Unk_FcItemSvcPtr spSvc(FUN_1401cd040(&DAT_143b059e8));
    if (spSvc.FUN_140ef4cb0(0))
        return;
    MS2Ptr<Unk_FcItemRow> spRow(spSvc.FUN_1401cd1a0()->FUN_1410b8b00(FUN_14112e110()));
    if (spRow == 0)
        return;
    MS2Ptr<Unk_FcItemText> spText(spRow->m_spText);
    if (spText == 0)
        return;
    if (spText->FUN_1408b49c0().GetLength() == 0)
        return;
    if (m_spNotice == 0)
    {
        Unk_StreamPoint vPos;
        FUN_1409618c0(m_ent.FUN_1408a9280(), 0xfd95ca52, &vPos);
        m_spNotice.AssignRaw(new UIUGCCubeNoticePopup);
        FUN_140fb4c50(m_spNotice.operator->(), Unk_StreamPoint(vPos.x, vPos.y, vPos.z + 150.0f));
        FUN_140fb4cc0(m_spNotice.operator->(), m_spData->m_strNotice, spText->FUN_1408b49c0());
        FUN_140fb4bb0(m_spNotice.operator->());
    }
    FUN_140fb4cc0(m_spNotice.operator->(), m_spData->m_strNotice, spText->FUN_1408b49c0());
    FUN_140fb5080(m_spNotice.operator->(), 1);
}

// @0x141227780
void CFunctionCubeObject::FUN_141227780()
{
    if (m_spNotice.get() != 0)
        FUN_140fb5080(m_spNotice.operator->(), 0);
}

// @0x1412277d0
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::FUN_1412277d0(unsigned char bOn)
{
    if (m_ent.FUN_1408a9090() != 0)
    {
        m_bAlt = bOn;
        if (bOn)
            FUN_141b71e70(*FUN_1408b76f0(m_ent.FUN_1408a9280()), true, 1, false);
        else
            FUN_141b71e70(*FUN_1408b76f0(m_ent.FUN_1408a9280()), false, 1, false);
    }
}

// @0x1412278b0
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::FUN_1412278b0()
{
    if (FUN_14122e6d0() != 0)
    {
        int nSubKind = m_spData->m_nSubKind;
        if (nSubKind == 1)
            FUN_141228060();
        else if (nSubKind == 4)
            FUN_141228100();
        else if (nSubKind == 5)
            FUN_141228200();
        else if (nSubKind == 6)
            FUN_1412282d0();
        else if (nSubKind == 7)
            FUN_141228340();
    }
}

// @0x141227950
// MS2-FUNCTIONAL: camera effect parameter struct is a unit-local stand-in; frame layout differs
void CFunctionCubeObject::FUN_141227950()
{
    int nState = m_nState;
    if (FUN_1409478c0()->FUN_140a18070() == 0)
        return;
    if (nState == 1)
    {
        switch (m_spData->m_nEffect)
        {
        case 0:
            return;
        case 1:
            FUN_1409478c0()->FUN_140aeb420(9, 0);
            break;
        case 2:
            FUN_1409478c0()->FUN_140aeb420(10, 0);
            break;
        case 3:
        {
            Unk_FcCamFx kFx;
            FUN_140947440(&kFx);
            kFx.m_nKind = 1;
            kFx.m_fScale = 1.0f;
            kFx.m_n8 = FUN_1409478c0()->FUN_140ad4b40();
            kFx.m_nC = FUN_1409478c0()->FUN_140af7f00();
            kFx.m_n10 = FUN_1409478c0()->FUN_140af7ea0();
            Unk_StreamPoint vTmpA;
            kFx.m_v14 = *FUN_1409478c0()->FUN_140a17e10(&vTmpA);
            Unk_StreamPoint vTmpB;
            kFx.m_v20 = *FUN_1409478c0()->FUN_140af8290(&vTmpB);
            kFx.m_n30 = kFx.m_n8;
            kFx.m_n34 = kFx.m_nC;
            kFx.m_n38 = kFx.m_n10;
            FUN_141839640(kFx.m_unk3c, kFx.m_unk48);
            FUN_1409478c0()->FUN_140aeb420(11, &kFx);
            break;
        }
        case 4:
            FUN_1409478c0()->FUN_140aeb420(12, 0);
            break;
        case 5:
            FUN_1409478c0()->FUN_140aeb420(13, 0);
            break;
        case 6:
            FUN_1409478c0()->FUN_140aeb420(14, 0);
        }
        m_bFxOn = 1;
    }
    else if (m_bFxOn != 0)
    {
        m_bFxOn = 0;
        Unk_FcCamFx kFx;
        FUN_140947440(&kFx);
        kFx.m_nKind = 1;
        kFx.m_fScale = 1.0f;
        kFx.m_n8 = FUN_1409478c0()->FUN_140ad4b40();
        kFx.m_nC = FUN_1409478c0()->FUN_140af7f00();
        kFx.m_n10 = FUN_1409478c0()->FUN_140af7ea0();
        Unk_StreamPoint vTmpA;
        kFx.m_v14 = *FUN_1409478c0()->FUN_140a17e10(&vTmpA);
        Unk_StreamPoint vTmpB;
        kFx.m_v20 = *FUN_1409478c0()->FUN_140af8290(&vTmpB);
        kFx.m_n30 = kFx.m_n8;
        kFx.m_n34 = kFx.m_nC;
        kFx.m_n38 = kFx.m_n10;
        FUN_14183c3e0(kFx.m_unk3c, kFx.m_unk48);
        FUN_1409478c0()->FUN_140aeb420(2, &kFx);
    }
}

// @0x141227cd0
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::FUN_141227cd0()
{
    char bFlag = 0;
    FUN_1408a20a0(m_ent.FUN_1408a9280(), 0x38141815, &bFlag);
    if (bFlag != 0 && m_nState < 3)
    {
        if (m_spData->m_aAnim[m_nState] == 0)
            FUN_141689ec0(FUN_1409f7ca0(), m_ent.FUN_1408a9090(), 5, 0, 1);
        else
            FUN_141689ec0(FUN_1409f7ca0(), m_ent.FUN_1408a9090(), 9, 0, 1);
    }
}

// @0x141227dd0
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::FUN_141227dd0(int nSkip)
{
    bool bShow = (m_nState == 1 || m_nState == 4) ? true : false;
    if (nSkip != 0)
        bShow = false;
    if (m_spData->m_nE8 != 0)
        FUN_141231ce0(FUN_1409670b0(), 0, CString(m_strId), bShow);
    if (m_spData->m_nEC != 0)
    {
        FUN_141231ce0(FUN_1409670b0(), 1, CString(m_strId), bShow);
        FUN_1419f37f0(1);
    }
    if (m_spData->m_nF0 != 0)
    {
        FUN_141231ce0(FUN_1409670b0(), 2, CString(m_strId), bShow);
        FUN_1419f37f0(1);
    }
    if (m_spData->m_nF4 != 0)
    {
        FUN_141231ce0(FUN_1409670b0(), 3, CString(m_strId), bShow);
        FUN_1419f37f0(1);
    }
}

// @0x141228060
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::FUN_141228060()
{
    if (FUN_1403ed2b0()->FUN_141adc890(0x4e6b))
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e6b);
    UITriggerEditorDialog* pDlg = Unk_FcDialog<UITriggerEditorDialog>(0x4e6b);
    if (pDlg != 0)
    {
        pDlg->FUN_141b2b9a0(CString(m_strId), m_nArg);
        FUN_141924680(pDlg);
    }
}

// @0x141228100
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::FUN_141228100()
{
    Unk_FcItemSvcPtr spSvc(FUN_1401cd040(&DAT_143b059e8));
    Unk_FcItemRow* pRow = spSvc.FUN_1401cd1a0()->FUN_1410b8b00(m_nArg);
    if (pRow == 0)
        return;
    FUN_140de2a30(&DAT_143ab2d80, pRow->FUN_1408b4f20(), FUN_141226cd0());
    UIObjectStoreDialog* pDlg = Unk_FcDialog<UIObjectStoreDialog>(0x4e78);
    if (pDlg != 0)
    {
        pDlg->vfunc_84(&m_strId, FUN_141226cd0());
        FUN_141924680(pDlg);
    }
}

// @0x141228200
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
void CFunctionCubeObject::FUN_141228200()
{
    UISwfEntity* pEntry = FUN_1422b9e20(FUN_1408e57f0(), 0x620001f);
    if (pEntry != 0)
    {
        Unk_FcUIMsg kMsg;
        FUN_1422e4490(&kMsg);
        FUN_1422b82b0(&kMsg, "setCubeID");
        FUN_1422b82b0(&kMsg, (const char*)m_strId);
        static_cast<IMessageListener*>(pEntry)->OnMessage(0, reinterpret_cast<UIMsg*>(&kMsg));
    }
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001f);
}

// @0x1412282d0
void CFunctionCubeObject::FUN_1412282d0()
{
    UIHomePasswordDialog* pDlg = Unk_FcDialog<UIHomePasswordDialog>(0x4ed6);
    if (pDlg != 0)
    {
        pDlg->FUN_1412c9680(CString(m_strId));
        FUN_141924680(pDlg);
    }
}

// @0x141228340
void CFunctionCubeObject::FUN_141228340()
{
    UIHomeSummonDialog* pDlg = Unk_FcDialog<UIHomeSummonDialog>(0x4ede);
    if (pDlg != 0)
    {
        pDlg->FUN_141299eb0(CString(m_strId));
        FUN_141924680(pDlg);
    }
}

// ---- Homemade / Breeding / Farming ----

// Local player actor and the world / housing singletons (classes of other units; opaque here).
class Unk_FcActor;
void* FUN_1403ed2d0();                                              // the world manager
Unk_FcActor* FUN_141bd0cc0(void* pWorld);                           // the local player actor
int FUN_1416764d0(Unk_FcActor* p);                                  // is riding
int FUN_14166c930(Unk_FcActor* p);                                  // current state id
__int64 FUN_141656ad0(Unk_FcActor* p);                              // account id
unsigned FUN_141662750(Unk_FcActor* p, int nMastery);               // mastery level
void FUN_14152c280(Unk_FcActor* p, RideOffAction* pAction);         // queue a ride-off action
typedef void (*Unk_FcSetStateFn)(Unk_FcActor*, int, void*, int, int);
static void Unk_FcActorSetState(Unk_FcActor* p, int nState, void* pData, int nArg)
{
    (*(Unk_FcSetStateFn*)(*(char**)p + 0x1d8))(p, nState, pData, nArg, 0);
}
void* FUN_1409670e0();                                              // the housing manager
unsigned char FUN_1410c35c0(void* pHousing);                        // design mode
__int64 FUN_1410c3180(void* pHousing);                              // owner account id
void* FUN_1410b8b00(void* pHousing, int nObjectId);                 // placed object row

// Housing item rows of the cube (16 / 24 byte smart pointers, destroyed by exe helpers).
struct Unk_FcSp16 { char m_pad[16]; };
struct Unk_FcSp24 { char m_pad[24]; };
struct Unk_FcMasteryRow
{
    char m_pad_00[0x24];
    unsigned m_nLevel;                                              // +0x24
    __int64 m_nPrice;                                               // +0x28
};
struct Unk_FcHmInfo
{
    char m_pad_00[0x100];
    int m_nItemId;                                                  // +0x100
};
void* FUN_1409670c0();
void FUN_14066aa00(void* pSvc, Unk_FcSp16* pOut, int nItemId);
Unk_FcMasteryRow* FUN_140b6dda0(Unk_FcSp16* p);                     // != NULL
Unk_FcMasteryRow* FUN_14066d9a0(Unk_FcSp16* p);
void FUN_14066d5b0(Unk_FcSp16* p);
Unk_FcSp24* FUN_140ca6580(CHomemadeCubeObject* pThis, Unk_FcSp24* pOut);
Unk_FcHmInfo* FUN_1409658d0(Unk_FcSp24* p);
void FUN_140ca62a0(Unk_FcSp24* p);
extern __int64 DAT_143ab2898;                                       // the player's meso
__int64 FUN_140869440();                                            // now
int FUN_14086bd90(int nId);                                         // growth seconds of a table id
CStringW FUN_14086aec0(__int64 nSpan, int, int, int, int);          // format a time span
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
CStringW FUN_14086d060(int nStringId, const __int64* pnValue);
CStringW FUN_14028b8e0(const CStringW& strKey);                     // string table lookup by key
void FUN_1412751f0(const CStringW& str, int nA, int nB);            // floating notice
void FUN_140e59ea0(UIObject* pDlg, CHomemadeCubeObject* pCube);
class UIMasteryObjectMark : public UIDialog { public: char m_pad[8]; };

CFunctionCubeObject* FUN_141225470(int nKind);

// @0x1412283b0
CHomemadeCubeObject::CHomemadeCubeObject()
{
    m_nB8 = 0;
    m_nSoundHandle2 = 0;
    m_nB0 = FUN_140869440();
}

// @0x141228430
CHomemadeCubeObject::~CHomemadeCubeObject()
{
    if (m_nSoundHandle2 != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nSoundHandle2);
        m_nSoundHandle2 = 0;
    }
    m_nB0 = 0;
}

// @0x1412284c0
void CHomemadeCubeObject::vfunc_3()
{
}

// @0x1412284d0
// MS2-FUNCTIONAL: sound request built with the unit-local request type; frame layout differs
void CHomemadeCubeObject::vfunc_4()
{
    if (m_nSoundHandle2 != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nSoundHandle2);
        m_nSoundHandle2 = 0;
    }
    CString strSound = m_spData->m_str108;
    if (!strSound.IsEmpty())
    {
        if (FUN_141229120() != 0)
        {
            Unk_FcSoundReq kReq;
            FUN_140a52ef0(&kReq);
            kReq.m_strName = strSound;
            kReq.m_nType = 0;
            FUN_1409fabf0(kReq.m_unk, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(m_ent.FUN_1408a9090())));
            m_nSoundHandle2 = FUN_1403ed280()->FUN_1411a49c0(&kReq);
            FUN_1405a89e0(&kReq);
        }
    }
}

// @0x141228620
void CHomemadeCubeObject::vfunc_5(float)
{
}

// @0x141228640
void CHomemadeCubeObject::vfunc_13()
{
    UIMasteryObjectMark* pMark = Unk_FcDialog<UIMasteryObjectMark>(0x4f3a);
    if (pMark != 0)
        FUN_140e59ea0(pMark, this);
}

// @0x141228680
int CHomemadeCubeObject::vfunc_15()
{
    Unk_FcActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 0;
    if (FUN_14122e710() == 0)
        return 0;
    return 1;
}

// @0x1412286d0
CStringW CHomemadeCubeObject::vfunc_6()
{
    return CStringW(L"");
}

// @0x141228720
// MS2-FUNCTIONAL: string pieces built per branch; frame layout differs
CStringW CHomemadeCubeObject::vfunc_7()
{
    if (m_nState == 1)
        return CStringW(L"watch");
    if (vfunc_17() == 0)
        return CStringW(L"lock");
    if (FUN_1410c35c0(FUN_1409670e0()) == 0)
        return CFunctionCubeObject::vfunc_7();
    return CStringW(L"lock");
}

// @0x141228810
// MS2-FUNCTIONAL: ride-off action and state data built with unit-local smart pointer stand-ins; frame layout differs
void CHomemadeCubeObject::vfunc_8(CString str)
{
    Unk_FcActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return;
    if (FUN_141229000(1) == 0)
        return;
    Unk_FcSp24 kInfoRef;
    int nItemId = FUN_1409658d0(FUN_140ca6580(this, &kInfoRef))->m_nItemId;
    FUN_140ca62a0(&kInfoRef);
    if (m_nState == 0)
    {
        Unk_FcSp16 kItem;
        FUN_14066aa00(FUN_1409670c0(), &kItem, nItemId);
        if (FUN_140b6dda0(&kItem) != 0)
        {
            if (DAT_143ab2898 < FUN_14066d9a0(&kItem)->m_nPrice)
            {
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_mastery_error_lack_meso")), 1, 1);
            }
            else if (FUN_1416764d0(pActor) == 0)
            {
                MS2Ptr<StateHomemadeData> spData(new StateHomemadeData(vfunc_16(), str, nItemId));
                Unk_FcActorSetState(pActor, 0x37, spData.get(), 0x8e);
            }
            else
            {
                MS2Ptr<RideOffActionHomemade> spAct(new RideOffActionHomemade(0));
                spAct->m_s28 = str;
                spAct->m_n30 = nItemId;
                spAct->m_n34 = vfunc_16();
                spAct->m_n38 = 0x8e;
                FUN_14152c280(pActor, spAct.get());
            }
        }
        FUN_14066d5b0(&kItem);
    }
    else if (m_nState == 2)
    {
        if (FUN_1416764d0(pActor) == 0)
        {
            if (FUN_14166c930(pActor) != 0x37)
            {
                MS2Ptr<StateHomemadeData> spData(new StateHomemadeData(vfunc_16(), str, nItemId));
                Unk_FcActorSetState(pActor, 0x37, spData.get(), 0x8f);
            }
        }
        else
        {
            MS2Ptr<RideOffActionHomemade> spAct(new RideOffActionHomemade(0));
            spAct->m_s28 = str;
            spAct->m_n30 = nItemId;
            spAct->m_n34 = vfunc_16();
            spAct->m_n38 = 0x8f;
            FUN_14152c280(pActor, spAct.get());
        }
    }
}

// @0x141228e40
// MS2-FUNCTIONAL: sound request built with the unit-local request type; frame layout differs
void CHomemadeCubeObject::vfunc_11(int nState)
{
    CFunctionCubeObject::vfunc_11(nState);
    if (m_nSoundHandle2 != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nSoundHandle2);
        m_nSoundHandle2 = 0;
    }
    CString strSound = m_spData->m_str108;
    if (!strSound.IsEmpty())
    {
        if (FUN_141229120() != 0)
        {
            Unk_FcSoundReq kReq;
            FUN_140a52ef0(&kReq);
            kReq.m_strName = strSound;
            kReq.m_nType = 0;
            FUN_1409fabf0(kReq.m_unk, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(m_ent.FUN_1408a9090())));
            m_nSoundHandle2 = FUN_1403ed280()->FUN_1411a49c0(&kReq);
            FUN_1405a89e0(&kReq);
        }
    }
}

// @0x141228fa0
int CHomemadeCubeObject::vfunc_16()
{
    return 0;
}

// @0x141228fb0
void CHomemadeCubeObject::FUN_141228fb0(__int64 n)
{
    m_nB0 = n;
}

// @0x141228fe0
__int64 CHomemadeCubeObject::FUN_141228fe0()
{
    return m_nB0;
}

// @0x141229000
// MS2-FUNCTIONAL: nested conditions folded
int CHomemadeCubeObject::FUN_141229000(char bWatch)
{
    Unk_FcActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 0;
    if (bWatch == 0 || m_nState != 1)
    {
        if (FUN_1410c35c0(FUN_1409670e0()) == 0)
            return vfunc_17();
        return 0;
    }
    return 0;
}

// @0x141229080
// MS2-FUNCTIONAL: nested conditions folded
int CHomemadeCubeObject::FUN_141229080()
{
    Unk_FcActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 0;
    if (m_nState == 1)
        return 0;
    if (FUN_1410c35c0(FUN_1409670e0()) != 0)
        return 0;
    if (FUN_140e5cc00() == 1)
    {
        if (FUN_140e5cbf0() != FUN_141656ad0(pActor))
            return 0;
    }
    return 1;
}

// @0x141229120
// MS2-FUNCTIONAL: nested conditions folded
int CHomemadeCubeObject::FUN_141229120()
{
    Unk_FcActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 0;
    if (vfunc_15() == 0)
        return 0;
    if (m_nState == 1)
        return 0;
    if (FUN_140e5cc00() == 1)
    {
        if (FUN_140e5cbf0() != FUN_141656ad0(pActor))
            return 0;
    }
    if (FUN_1410c35c0(FUN_1409670e0()) == 0)
        return vfunc_17();
    return 0;
}

// @0x1412291e0
int CHomemadeCubeObject::vfunc_17()
{
    return 0;
}

// ---- Breeding ----

// The entity manager (creates / removes the pet entity) and the animation table row of a pet.
class Unk_FcEntMgr;
Unk_FcEntMgr* FUN_1409670f0();
void FUN_1411cf570(Unk_FcEntMgr* pMgr, Unk_Entity* pEntity);        // remove
void FUN_1411cf2d0(Unk_FcEntMgr* pMgr, Unk_Entity* pEntity, int nFlag);
Unk_EntRef* FUN_1411cec80(Unk_FcEntMgr* pMgr, Unk_EntRef* pOut, Unk_FcAnimName* pClass, egf::EntityID kId);
Unk_FcAnimName* FUN_140b7cc50(Unk_FcAnimSvc* pSvc, Unk_FcAnimName* pOut, egf::EntityID kId);  // current animation
unsigned char FUN_14122e000(Unk_FcAnimName* pName, const char* psz);                         // names are equal
struct Unk_FcAnimRow
{
    char m_pad_00[0x50];
    CString m_strName;                                              // +0x50 animation / model name
    void* m_pFx;                                                    // +0x58
    char m_pad_60[4];
    Unk_StreamPoint m_vOffset;                                      // +0x64
};
MS2_CHECK_OFFSET(Unk_FcAnimRow, m_vOffset, 0x64);
void FUN_1406cd330(Unk_FcSp16* pOut, int nId);                      // find the row
unsigned char FUN_1406a9050(Unk_FcSp16* p, int);                    // == NULL
Unk_FcAnimRow* FUN_14035eb90(Unk_FcSp16* p);
void FUN_14035e5b0(Unk_FcSp16* p);
void FUN_140de0cb0(efd::AssetID* pAsset, Unk_FcAnimName* pName);
void FUN_140de8bd0(Unk_Entity* pEntity, unsigned uHash, efd::AssetID* pAsset);
void FUN_140ae1240(Unk_Entity* pEntity, unsigned uHash, Unk_FcAnimName* pName);
void FUN_140a38a50(Unk_Entity* pEntity, unsigned uHash, Unk_StreamPoint* pPoint);
void FUN_1409457c0(Unk_Entity* pEntity, unsigned uHash, void* p);
void FUN_14098c6e0(Unk_Entity* pEntity, unsigned uHash, unsigned char* pb);
CString* FUN_1409a2360(CString* pOut, const char* psz, int nFlag);

// @0x1412291f0
CBreedingCubeObject::CBreedingCubeObject()
    : m_strAnim(""), m_entPet(0)
{
}

// @0x141229270
CBreedingCubeObject::~CBreedingCubeObject()
{
    m_strAnim = "";
    if (m_entPet.FUN_1408a9090() != 0)
    {
        FUN_1411cf570(FUN_1409670f0(), (Unk_Entity*)m_entPet.FUN_1408a9090());
        m_entPet.FUN_1408b6ec0(0);
    }
}

// @0x141229360
// MS2-FUNCTIONAL: pet entity built from the animation row with unit-local stand-ins; frame layout differs
int CBreedingCubeObject::vfunc_2(Unk_Entity* pEntity, const Unk_FcRow* pRow, int nCubeId, __int64 nArg,
    CubeItemInfo* pItem)
{
    if (CFunctionCubeObject::vfunc_2(pEntity, pRow, nCubeId, nArg, pItem) == 0)
        return 0;
    Unk_FcSp16 kAnim;
    FUN_1406cd330(&kAnim, pRow->m_nA4);
    if (FUN_1406a9050(&kAnim, 0) != 0)
    {
        FUN_14035e5b0(&kAnim);
        return 0;
    }
    if (pRow->m_nSub == 1)
        m_spData->m_bBuff = 1;
    m_spData->m_n100 = pRow->m_n170;
    m_spData->m_str108 = pRow->m_str178;
    m_spData->m_n110 = pRow->m_n108;
    Unk_FcSp16 kItem;
    FUN_14066aa00(FUN_1409670c0(), &kItem, pRow->m_n170);
    if (FUN_140b6dda0(&kItem) != 0)
        m_spData->m_n104 = FUN_14066d9a0(&kItem)->m_nLevel;
    if (FUN_1410b8b00(FUN_1409670e0(), m_nArg) != 0)
    {
        CString strAsset;
        strAsset.Format("urn:gamebryo-animation:%s", (const char*)FUN_14035eb90(&kAnim)->m_strName);
        efd::AssetID kAsset;
        Unk_FcAnimName kName;
        FUN_1409989e0(&kName, strAsset);
        FUN_140de0cb0(&kAsset, &kName);
        FUN_1408a8900(&kName);
        egf::EntityID kId = egf::EntityIDFactory::GetNextID();
        Unk_FcAnimName kClass;
        FUN_1409989e0(&kClass, "GameObject");
        Unk_EntRef kTmp(0);
        m_entPet = *FUN_1411cec80(FUN_1409670f0(), &kTmp, &kClass, kId);
        FUN_1408a8900(&kClass);
        if (m_entPet.FUN_1408a9090() != 0)
        {
            Unk_StreamPoint vPos = DAT_143b01a60;
            Unk_StreamPoint vRot = DAT_143b01a60;
            FUN_1409618c0(pEntity, 0xfd95ca52, &vPos);
            FUN_1409618c0(pEntity, 0x68c7c29d, &vRot);
            vPos = vPos.FUN_14097fd50(FUN_14035eb90(&kAnim)->m_vOffset);
            FUN_140de8bd0(m_entPet.FUN_1408a9280(), 0x12383cea, &kAsset);
            CString strIdle;
            FUN_1409a2360(&strIdle, "Idle_A", 0);
            Unk_FcAnimName kIdle;
            FUN_1409989e0(&kIdle, strIdle);
            FUN_140ae1240(m_entPet.FUN_1408a9280(), 0x3ff293c8, &kIdle);
            FUN_1408a8900(&kIdle);
            FUN_140a38a50(m_entPet.FUN_1408a9280(), 0xfd95ca52, &vPos);
            FUN_140a38a50(m_entPet.FUN_1408a9280(), 0x68c7c29d, &vRot);
            FUN_1409457c0(m_entPet.FUN_1408a9280(), 0x2d7cad2d, &FUN_14035eb90(&kAnim)->m_pFx);
            unsigned char bFlag = 0;
            FUN_14098c6e0(m_entPet.FUN_1408a9280(), 0xa0b6b179, &bFlag);
            FUN_1411cf2d0(FUN_1409670f0(), (Unk_Entity*)m_entPet.FUN_1408a9090(), 0);
            FUN_14066d5b0(&kItem);
            FUN_14035e5b0(&kAnim);
            return 1;
        }
    }
    FUN_14066d5b0(&kItem);
    FUN_14035e5b0(&kAnim);
    return 0;
}

// @0x1412299f0
// MS2-FUNCTIONAL: entity id copy and the animation name temporaries differ
void CBreedingCubeObject::vfunc_3()
{
    if (!m_entPet.FUN_1408b70b0(0) && !m_strAnim.IsEmpty())
    {
        egf::EntityID kId = *FUN_1408b76f0(m_entPet.FUN_1408a9280());
        Unk_FcAnimName kCur;
        if (FUN_14122e000(FUN_140b7cc50(FUN_141b6f910(), &kCur, kId), m_strAnim))
        {
            Unk_FcAnimName kName;
            FUN_1409989e0(&kName, m_strAnim);
            FUN_1409a1fc0(FUN_141b6f910(), kId, &kName, 1.0f);
            FUN_1408a8900(&kName);
        }
        FUN_1408a8900(&kCur);
    }
}

// @0x141229b70
// MS2-FUNCTIONAL: rotation property read-modify-write; frame layout differs
void CBreedingCubeObject::vfunc_5(float fArg)
{
    if (m_entPet.FUN_1408a9090() != 0)
    {
        Unk_StreamPoint vRot;
        FUN_1409618c0(m_entPet.FUN_1408a9280(), 0x68c7c29d, &vRot);
        vRot.z = fArg;
        FUN_140a38a50(m_entPet.FUN_1408a9280(), 0x68c7c29d, &vRot);
    }
}

// Breeding and Farming build the same tooltip: the strings differ by two ids.
static CStringW Unk_FcGatherTip(CHomemadeCubeObject* pThis, int nPriceStr, int nTimeStr)
{
    Unk_FcActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return CStringW(L"");
    void* pItemSvc = FUN_1401cd040(&DAT_143b059e8);
    if (pItemSvc == 0)
        return CStringW(L"");
    Unk_FcItemSvcPtr kSvc((Unk_FcItemSvc*)pItemSvc);
    if (kSvc.FUN_140ef4cb0(0))
        return CStringW(L"");
    Unk_FcItemRow* pRow = kSvc.FUN_1401cd1a0()->FUN_1410b8b00(pThis->FUN_14112e110());
    if (pRow == 0)
        return CStringW(L"");
    if (FUN_14166c930(pActor) == 0x37)
        return CStringW(L"");
    if (pThis->vfunc_17() == 0)
        return FUN_14028b8e0(CStringW(L"s_gathering_object_lack_mastery"));
    if (FUN_1410c35c0(FUN_1409670e0()) != 0)
        return FUN_14028b8e0(CStringW(L"s_mastery_error_notuse_designmode"));
    if (pThis->m_nState == 0)
    {
        Unk_FcSp24 kInfoRef;
        int nItemId = FUN_1409658d0(FUN_140ca6580(pThis, &kInfoRef))->m_nItemId;
        FUN_140ca62a0(&kInfoRef);
        Unk_FcSp16 kItem;
        FUN_14066aa00(FUN_1409670c0(), &kItem, nItemId);
        if (FUN_140b6dda0(&kItem) != 0)
        {
            CStringW strPrice = FUN_14086d060(nPriceStr, &FUN_14066d9a0(&kItem)->m_nPrice);
            CStringW strName = FUN_1401a9d70()->FUN_141811980(1, pRow->FUN_1408b4f20());
            CStringW strLine;
            strLine.Format(L"%s %s", (const wchar_t*)strName, (const wchar_t*)strPrice);
            CStringW strRet = FUN_14052bd00(0x634, strLine);
            FUN_14066d5b0(&kItem);
            return strRet;
        }
        FUN_14066d5b0(&kItem);
    }
    else if (pThis->m_nState == 2)
    {
        return FUN_14052bd00(0x634, FUN_14028de60(0x641));
    }
    else if (pThis->m_nState == 1)
    {
        Unk_FcHmInfo* pInfo = (Unk_FcHmInfo*)pThis->m_spData.operator->();
        __int64 nEnd = pThis->FUN_141228fe0() + FUN_14086bd90(pThis->m_spData->m_n110);
        ATL::CTimeSpan kSpan(nEnd - FUN_140869440());
        (void)pInfo;
        if (kSpan.GetTotalSeconds() > 59)
        {
            CStringW strSpan = FUN_14086aec0(kSpan.GetTimeSpan(), 0, 0, 1, 0);
            return FUN_14052bd00(nTimeStr, FUN_14052bd00(0x643, strSpan));
        }
        if (kSpan.GetTotalSeconds() > 0)
        {
            CStringW strSpan = FUN_14086aec0(kSpan.GetTimeSpan(), 0, 0, 0, 1);
            return FUN_14052bd00(nTimeStr, FUN_14052bd00(0x643, strSpan));
        }
    }
    return CStringW(L"");
}

// @0x141229c10
// MS2-FUNCTIONAL: shared tooltip builder instead of the exe's inline copy; frame layout differs
CStringW CBreedingCubeObject::vfunc_6()
{
    return Unk_FcGatherTip(this, 0x63f, 0x644);
}

// @0x14122a350
int CBreedingCubeObject::vfunc_16()
{
    return 5;
}

// @0x14122a370
// MS2-FUNCTIONAL: random pick over the state's animation list; frame layout differs
void CBreedingCubeObject::vfunc_10(int nState, bool bFlag)
{
    if (nState < 0 || nState >= 6)
        return;
    Unk_FcStrList arrAnims;
    arrAnims.Copy(m_spData->m_anims[nState]);
    if (bFlag)
    {
        if (arrAnims.IsEmpty() == false)
        {
            vfunc_12(FUN_14122edc0(nState), false);
            return;
        }
    }
    else if (m_entPet.FUN_1408a9090() != 0)
    {
        if (nState == 0)
        {
            unsigned char b = 0;
            FUN_14098c6e0(m_entPet.FUN_1408a9280(), 0xa0b6b179, &b);
        }
        else if (nState == 1)
        {
            unsigned char b = 1;
            FUN_14098c6e0(m_entPet.FUN_1408a9280(), 0xa0b6b179, &b);
        }
        else if (nState == 2)
        {
            unsigned char b = 1;
            FUN_14098c6e0(m_entPet.FUN_1408a9280(), 0xa0b6b179, &b);
        }
        if (arrAnims.GetCount() != 0)
        {
            m_strAnim = arrAnims[(unsigned)rand() % arrAnims.GetCount()];
            Unk_FcAnimName kName;
            FUN_1409989e0(&kName, m_strAnim);
            FUN_1409a1fc0(FUN_141b6f910(), *FUN_1408b76f0(m_entPet.FUN_1408a9280()), &kName, 1.0f);
            FUN_1408a8900(&kName);
        }
    }
    vfunc_11(nState);
}

// @0x14122a670
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
int CBreedingCubeObject::vfunc_17()
{
    Unk_FcActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 0;
    FunctionCubeData* pData = m_spData.operator->();
    unsigned nLevel = FUN_141662750(pActor, 5);
    if (nLevel < (unsigned)pData->m_n104)
        return 0;
    return 1;
}

// ---- Farming ----

// @0x14122a6e0
CFarmingCubeObject::CFarmingCubeObject()
{
}

// @0x14122a730
CFarmingCubeObject::~CFarmingCubeObject()
{
}

// @0x14122a770
// MS2-FUNCTIONAL: item level lookup through unit-local smart pointer stand-ins; frame layout differs
int CFarmingCubeObject::vfunc_2(Unk_Entity* pEntity, const Unk_FcRow* pRow, int nCubeId, __int64 nArg,
    CubeItemInfo* pItem)
{
    if (CFunctionCubeObject::vfunc_2(pEntity, pRow, nCubeId, nArg, pItem) == 0)
        return 0;
    if (pRow->m_nSub == 1)
        m_spData->m_bBuff = 1;
    m_spData->m_n100 = pRow->m_n170;
    m_spData->m_str108 = pRow->m_str178;
    m_spData->m_n110 = pRow->m_n108;
    Unk_FcSp16 kItem;
    FUN_14066aa00(FUN_1409670c0(), &kItem, pRow->m_n170);
    if (FUN_140b6dda0(&kItem) != 0)
        m_spData->m_n104 = FUN_14066d9a0(&kItem)->m_nLevel;
    FUN_14066d5b0(&kItem);
    return 1;
}

// @0x14122a900
// MS2-FUNCTIONAL: shared tooltip builder instead of the exe's inline copy; frame layout differs
CStringW CFarmingCubeObject::vfunc_6()
{
    return Unk_FcGatherTip(this, 0x640, 0x645);
}

// @0x14122b040
int CFarmingCubeObject::vfunc_16()
{
    return 6;
}

// @0x14122b060
// MS2-FUNCTIONAL: branch/temporary layout differs from the exe (equivalent behaviour)
int CFarmingCubeObject::vfunc_17()
{
    Unk_FcActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return 0;
    FunctionCubeData* pData = m_spData.operator->();
    unsigned nLevel = FUN_141662750(pActor, 6);
    if (nLevel < (unsigned)pData->m_n104)
        return 0;
    return 1;
}
