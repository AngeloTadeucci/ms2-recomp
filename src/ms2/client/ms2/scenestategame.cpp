// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSceneStateGame: the in-field scene state and its field
// packet handlers (see scenestategame.h). The units.tsv range 0x141703a70-0x14174bd70 holds six objs; the other five
// (ridee, uirimlightdialog, rpgcameramode, scalemodifier, scenestatebase) are their own units.
// MS2-UNIT: client\ms2\scenestategame.cpp
// MS2-RANGE: 0x14170bda0-0x14174bd70 .text$mn
// MS2-RANGE: 0x1400ff860-0x140100050 .text$di
// MS2-RANGE: 0x142cb5fd0-0x142cb6450 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@$$QEA_N@Z 0x141740440 ; prop
// MS2-PIN: ??$?0AEBH@?$_Tuple_val@AEBH@std@@QEAA@AEBH@Z 0x1417406d0 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@std@@@0@AEAV10@@Z 0x1417451d0 ; prop
// MS2-PIN: ??1_ATL_COM_MODULE70@ATL@@QEAA@XZ 0x141746a80 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141747160 ; unique
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1417473e0 ; unique
// MS2-PIN: ??_GCAtlStringMgr@ATL@@UEAAPEAXI@Z 0x1417478d0 ; unique
// MS2-PIN: ?GetClassDesc@CSceneStateGame@@UEBAPEBVClassInfo@efd@@XZ 0x141747f90 ; unique
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@XZ 0x14174b020 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x14174b060 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@2@XZ 0x14174b070 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@2@XZ 0x14174b0a0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@2@XZ 0x14174b0b0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@XZ 0x14174b0c0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBH_N@std@@@std@@@2@XZ 0x14174b0d0 ; prop
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBH_N@std@@PEAX@std@@@2@XZ 0x14174b110 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@H_NU?$less@H@std@@V?$allocator@U?$pair@$$CBH_N@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x14174b190 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ?SetupClassInfo@CSceneStateGame@@SAXPEAVClassInfo@efd@@_K@Z 0x14174a6c0
// MS2-PIN: ?FUN_14174a560@Unk_SSGNpc@@QEAAXD@Z 0x14174a560
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestategame.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestategame.h"
#include "networkservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"
#include "ridee.h"
#include "reactor.h"
#include "cubecraft_1.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/client/ms2/stateemotionidle.h"
#include <efd/Helpers.h>
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include <atlcoll.h>
#include <map>

// ---- singletons and callees (names inferred; unit-local stand-ins) -----------------------------------------------
CNetworkService* FUN_140714f90();

// The world/field manager (FUN_1403ed2d0).
class Unk_SSGWorld
{
public:
    void FUN_141bbae40(IWorldServiceCallback* cb);          // register a callback
    void FUN_141bbae80(IWorldServiceCallback* cb);          // unregister it
    void FUN_141bbc580(int a, int b);
    int FUN_141bcfd10();                                    // world state (4 = in field)
    void FUN_141bdb690();
    void FUN_141bbbcf0(int nMapId, int n);
    GameObject* FUN_141bd1180(int nId);
    PC* FUN_141bd1290(int nId);
    PCBase* FUN_141bd1200(int nId);
    int FUN_141bd1a10(PCBase* pActor);
    PCBase* FUN_141bd3620();
    class Unk_SSGNpc* FUN_141bd1320(int nId);
    class Unk_SSGCubeObj* FUN_141bd13a0(int nId);
    void FUN_141bc92e0(CString strName);
    void FUN_141bc9480(CString strName);
    void FUN_141bca220();
    void FUN_141bca6d0(CInPacket& packet);
    void FUN_141bd3d70(Unk_StreamPoint pos, Unk_StreamPoint rot);
    void FUN_141bbbe40(int nMapId, int a, int nPortal);
    MyPC* FUN_141bd0cc0();                                  // the local player actor
    int FUN_141bd98d0();                                    // current field id
    void FUN_141bd9c20(CInPacket& packet);
};
Unk_SSGWorld* FUN_1403ed2d0();

// The UI manager (FUN_1403ed2b0).
class Unk_SSGUIMgr
{
public:
    void FUN_141add040(int nId);
    void FUN_141adc050();
    void FUN_141ad93b0();
    MS2Ptr<UIObject> FUN_141adcea0(int nId);
    void FUN_141adc400();
    int FUN_141adc940(int nId);
    void FUN_141ad9a60(CString strName);
    void FUN_141adc530(int nId);
    void FUN_141add1f0();
    void FUN_141adc5d0(int nId);
};
Unk_SSGUIMgr* FUN_1403ed2b0();

class Unk_SSGGuildMgr
{
public:
    void FUN_1413bc1f0(__int64 nGuildId, CStringW strName);
    void FUN_1413bcd10();
};
Unk_SSGGuildMgr* FUN_1403ed290();

class Unk_SSGEffectMgr
{
public:
    void FUN_1411a6060(int nHandle);                        // remove an effect
    void FUN_1411a4f40(CString strName, const NiPoint3& kPos);
    void FUN_1411a4a00(Unk_EffectQuery* pQuery);                    // play once
};
Unk_SSGEffectMgr* FUN_1403ed280();

class Unk_SSGOption
{
public:
    void FUN_140a1f7f0(bool bInField);
    void FUN_140a1f8a0();
    void FUN_140a1f970(const CString& strKey, const CString& strValue);
};
Unk_SSGOption* FUN_140d8ee90();

class Unk_SSGInput
{
public:
    void FUN_140ad1ef0();
    void FUN_140ad1da0(unsigned int nMsg, int wParam, int lParam);
};
Unk_SSGInput* FUN_140953f30();

class Unk_SSGKeyState { public: int FUN_1422aeed0(int n); };
Unk_SSGKeyState* FUN_14025e7a0();
class Unk_SSGKeyboard { public: bool FUN_14116d950(int nKey, bool bA, int b); bool FUN_14116d9c0(int nKey, bool bA, int b); };
Unk_SSGKeyboard* FUN_14025e7c0();

class Unk_SSGQuery { public: int FUN_140a18070(); void FUN_140aeb1a0(); void FUN_140aecbb0(int a, int b, bool c); };
Unk_SSGQuery* FUN_1409478c0();

// OnEnter/OnLeave service calls
class Unk_143a09680 { public: void* m_a; void* m_b; };
class Unk_1409879 : public Unk_143a09680 { };
Unk_1409879 FUN_140987930(const void*);
extern char DAT_143a09680[];
void* FUN_140aae430();
void FUN_141489ff0(void*, Unk_143a09680);
void* FUN_14086d260();
double FUN_141473280(void*);
void* FUN_140c7a250();
void FUN_140db8eb0(void*);
class Unk_SSG931510* FUN_140931510();
void FUN_140d9f040(void*);
void FUN_140d9f0c0(void*);
void* FUN_140e800e0();
void FUN_140aad0d0(void*);
void FUN_140aadd70(void*);
void* FUN_14015a050();
void FUN_140ceac00(void*);
void* FUN_1409eed70();
void FUN_140ad68a0(void*);
void* FUN_14052d220();
void FUN_1418894d0(void*);
void FUN_141889150(void*);
void* FUN_1409670d0();
void FUN_14162b790(void*);
void* FUN_1409a8b00();
void FUN_1409a4090(void*);

// Reconnect (as CSceneStateMulti/CSceneStateMove::OnUpdate)
extern CString DAT_143ab2a48;
extern unsigned short DAT_143ab2848;
extern int DAT_1439f4a78;
extern int DAT_143ab285c;
extern int DAT_143ab2860;
extern unsigned char DAT_143ab284b;
extern void (*DAT_143b03490)(short, unsigned char, const char*);
extern unsigned char DAT_1430c3b20;
CString FUN_14016a600(const wchar_t*, int);
CStringW FUN_14062b4f0(CStringW, const int&);
CStringW FUN_1408116a0(int, const int&);
void* FUN_141540270(int);
void FUN_1419e0050(void*, const CStringW&);
void FUN_141b6fcf0(const CStringW&, const CStringW&, int);

// The player's sub actors (FUN_141662440: ride/pet slots 0..2); slot 126 is their per-frame update.
class Unk_SSGSubActor : public PCBase
{
public:
    virtual void vfunc_124();
    virtual void vfunc_125();
    virtual void vfunc_126();
};
void FUN_141524a80(MyPC* pPC, int n);
Unk_SSGSubActor* FUN_141662440(MyPC* pPC, int nSlot);

// OnPacket direct dispatch targets
class Unk_SSGMisc2d80 { public: void FUN_140de3480(CInPacket& packet); void FUN_140de2a00(); };
extern Unk_SSGMisc2d80 DAT_143ab2d80;
class Unk_SSGArcade { public: void FUN_140b8c260(CInPacket& packet); };
Unk_SSGArcade* FUN_140ee0d10();
void FUN_140ceab50(void* pMgr, CInPacket& packet);
void FUN_140ad5f00(void* pMgr, CInPacket& packet);
class Unk_SSGDialog4edc { public: void FUN_1412a53e0(CInPacket& packet); };
Unk_SSGDialog4edc* FUN_140ce84f0(int nId);
class Unk_SSGSlotMgr { public: void FUN_141b83750(CInPacket& packet); };
Unk_SSGSlotMgr* FUN_1409eed90();

// The dialogs this unit looks up by id (GetDialog<T> instances 0x141742310..0x141743690).
class UINoticeDialog : public UIDialog
{
public:
    void FUN_141009680(CInPacket& packet);
};

template <class T> T* Unk_SSGGetDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// ---- packet handler callees ------------------------------------------------------------------------------------
// 0x9: the field-enter request body (account id, two ints, machine id), encoded by FUN_1401f9d20.
class Unk_SSGMachineId
{
public:
    Unk_SSGMachineId& FUN_14067c080(const Unk_SSGMachineId& other);
    unsigned char m_data[16];
};
class Unk_SSGEnterRequest
{
public:
    Unk_SSGEnterRequest();                                  // 0x141540ca0
    void FUN_1401f9d20(COutPacket& out);
    __int64 m_nAccountId;                                   // +0x00
    int m_n8;                                               // +0x08
    int m_nC;                                               // +0x0c
    Unk_SSGMachineId m_machineId;                           // +0x10
};
MS2_CHECK_SIZE(Unk_SSGEnterRequest, 0x20);
class Unk_SSGMachine { public: const Unk_SSGMachineId& FUN_140d4fdf0(); };
Unk_SSGMachine* FUN_140aadf70();
extern __int64 DAT_143ab2820;
extern int DAT_143ab284c;
extern int DAT_143ab2850;

// 0x15: field enter
class Unk_SSGIntList
{
public:
    void FUN_1402c2830();                                   // clear
    void FUN_1401855a0(int n);                              // push_back
};
extern Unk_SSGIntList DAT_143ab3058;
extern Unk_SSGIntList DAT_143ab3078;
extern Unk_SSGIntList DAT_143ab3098;
void FUN_14092f420();
int FUN_14092f640();
void FUN_1412751b0(const CStringW& strMsg, int nType);
extern int DAT_143ab2864;
extern __int64 DAT_143ab2828;
extern int DAT_1439f4a7c;
extern int DAT_1439f4a80;
extern __int64 DAT_143ab28a0;
extern __int64 DAT_143ab28a8;
extern __int64 DAT_143ab2898;
extern __int64 DAT_143ab28b0;
extern __int64 DAT_143ab28b8;
extern __int64 DAT_143ab28c0;
extern __int64 DAT_143ab28c8;
extern __int64 DAT_143ab28d0;
extern __int64 DAT_143ab28d8;
extern __int64 DAT_143ab28e0;
extern __int64 DAT_143ab28e8;
extern __int64 DAT_143ab28f0;
extern int DAT_143ab2918;
void FUN_1409304d0(__int64 a, __int64 b, __int64 c, __int64 d);
void FUN_140930af0(__int64 a);
class Unk_SSGChatTab { public: void FUN_140dbde50(int n); };
class Unk_SSGChatHolder { public: Unk_SSGChatTab* FUN_140f97f00(); };
Unk_SSGChatHolder* FUN_140f97ef0();
class Unk_SSGProfile
{
public:
    static void FUN_141b77e50(const CString& str);
    static void FUN_141b77e90(const CString& str);
    static void FUN_141b77ed0(const CString& str);
};
Unk_SSGProfile* FUN_140cc18a0();
class Unk_SSGChannelDialog { public: void FUN_141ad2ea0(int nChannel); };
Unk_SSGChannelDialog* FUN_14136f520(int nId);
class Unk_SSG1c0d90 { public: void FUN_1404766e0(); };
Unk_SSG1c0d90* FUN_1401c0d90();
class Unk_SSG3ed2a0 { public: void FUN_1407ce240(); };
Unk_SSG3ed2a0* FUN_1403ed2a0();
class Unk_SSGHome { public: __int64 FUN_14034a1b0(); };
Unk_SSGHome* FUN_1414a56d0();
class Unk_SSGConfig { public: bool FUN_14036e5b0(); };
Unk_SSGConfig* FUN_140166410();
class Unk_SSGB05bf0 { public: void FUN_140b06450(int n); };
Unk_SSGB05bf0* FUN_140b05bf0();

// 0x2b: the UGC map (house) info of the current field
class UGCMapDesignInfo : public CPtred
{
public:
    UGCMapDesignInfo();
    int m_nId;                                              // +0x18
    CString m_strName;                                      // +0x20
    __int64 m_nTime;                                        // +0x28
};
MS2_CHECK_SIZE(UGCMapDesignInfo, 0x30);
class UGCMapBlueprintInfo : public CPtred
{
public:
    UGCMapBlueprintInfo();
    int m_nId;                                              // +0x18
    CString m_strName;                                      // +0x20
    __int64 m_nTime;                                        // +0x28
};
MS2_CHECK_SIZE(UGCMapBlueprintInfo, 0x30);
// Three byte-sized house rules, decoded from the packet.
class Unk_SSGHouseRule
{
public:
    Unk_SSGHouseRule();                                     // 0x140b68e60
    void FUN_140b68ec0(CInPacket& packet);
    void FUN_140b68f60();
    unsigned char m_a, m_b, m_c;
};
MS2_CHECK_SIZE(Unk_SSGHouseRule, 3);
class Unk_Service6100017 : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    void FUN_1410c3020(int n);
    void FUN_1410c3120(int n);
    void FUN_1410c3160(int n);
    void FUN_1410cb8b0(bool b);
    void FUN_1410c31a0(__int64 nOwner);
    void FUN_1410c3220(const CStringW& str);
    void FUN_1410c32b0(const CStringW& str);
    void FUN_1410c3310(int n);
    void FUN_1410c3410(int n);
    void FUN_1410c3450(int n);
    void FUN_1410c3630(int n);
    void FUN_1410c3490(int n);
    void FUN_1410c34d0(int n);
    void FUN_1410c3530(Unk_SSGHouseRule rule);
    void FUN_1410c3670();
    void FUN_1410d43c0(ATL::CAtlArray<MS2Ptr<UGCMapDesignInfo> >& arr);
    void FUN_1410d4680(ATL::CAtlArray<MS2Ptr<UGCMapBlueprintInfo> >& arr);
    void FUN_1410c3e40(int nKey, bool bValue);
    void FUN_1410c3f10(int nKey, int nValue);
};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework* framework);
class Unk_SSG6aeee0 { public: bool FUN_1406af0c0(); };
Unk_SSG6aeee0* FUN_1406aeee0();

// 0x1a / 0x1b: character / channel move results
struct Unk_StreamPoint;
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
CStringW FUN_140cc20a0(int nError);
CStringW FUN_14028de60(int nId);
void FUN_1412751f0(const CStringW& strMsg, int a, int b);
void FUN_140930ba0(int n);
extern int DAT_143ab2870;
extern int DAT_143ab2878;
extern int DAT_143ab287c;
extern int DAT_143ab2880;
extern int DAT_143ab2890;
class Unk_SSG967100 { public: void FUN_141b21390(); void FUN_141b1ddd0(CInPacket& packet); };
Unk_SSG967100* FUN_140967100();
class Unk_SSG9331e0 { public: void FUN_14138d7e0(int a, int nMapId); void FUN_14138bf00(int nKind, int nId, int nArg); void FUN_14138b280(CInPacket& packet); };
Unk_SSG9331e0* FUN_1409331e0();
class Unk_SSGSoundCtl { public: void FUN_1422ba0d0(); void FUN_1422b9fd0(int nId); };
Unk_SSGSoundCtl* FUN_1408e57f0();
class Unk_SSG931510 { public: void FUN_140d9f710(CInPacket& packet); MS2Ptr<class Unk_SSGDungeonRecord> FUN_140d9f2c0(); MS2Ptr<class Unk_SSGChatEmoticon> FUN_140d9f8f0(); };
void FUN_1412b9870(int nId, int nType);

// 0x18..0x41: actor packets
class Unk_SSG9f7c90 { public: int FUN_1409f7ea0(); };
Unk_SSG9f7c90* FUN_1409f7c90();
void FUN_141663500(MyPC* pPC, int nMapId);                 // PC member (0x141663500), called on the local MyPC
// The npc / monster class (class id 0x06200011).
class Unk_SSGNpcData : public CPtred { public: char m_pad[0x60 - sizeof(CPtred)]; int m_n60; };   // the npc table row
MS2_CHECK_OFFSET(Unk_SSGNpcData, m_n60, 0x60);
class Unk_SSGNpc : public PCBase
{
public:
    static const efd::ClassID CLASS_ID = 0x06200011;
    virtual void vfunc_124();
    virtual void vfunc_125(int n);                          // 125 (called with 1 on packet 0x57)
    int FUN_1411900d0();
    MS2Ptr<Unk_SSGNpcData> FUN_141093270();                 // the npc table row
    void FUN_1410932c0(int n);
    void FUN_1410918e0(CByteBuffer& buf);                   // apply a sync block
    void FUN_14174a560(char c) { m_ce50 = c; }
    void FUN_141092c50(CInPacket& packet);

    char m_pad_d40[0xe50 - 0xd40];
    char m_ce50;                                            // +0xe50
};
MS2_CHECK_OFFSET(Unk_SSGNpc, m_ce50, 0xe50);
class Unk_PCItemCooldowns { public: void FUN_140c86510(__int64 nItemUid); };
// The item event hub (FUN_140a6a840); slots 5/21/23 are item notifications.
class Unk_SSGItemHub
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(CItem* pItem);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(CItem* pItem);
    virtual void vfunc_22();
    virtual void vfunc_23(CItem* pItem);
};
Unk_SSGItemHub* FUN_140a6a840();
void* FUN_1409613d0(PCBase* pPC);
int FUN_1422b9e00(Unk_SSGSoundCtl* p);

MyPC* FUN_14096e160(PCBase* pActor);                        // efd::DynamicCast<MyPC> (class id 0x06200004)

// 0x3f..0x5a: npc / actor state packets
class Unk_PCBaseComp_b18 : public CPtred { public: char m_pad[0x28 - sizeof(CPtred)]; __int64 m_nSkillUid; };   // the casting skill
MS2_CHECK_OFFSET(Unk_PCBaseComp_b18, m_nSkillUid, 0x28);
class NotifyRemoveNpc : public NotifyObject
{
public:
    NotifyRemoveNpc(efd::SmartPointer<Unk_SSGNpc> spNpc);   // 0x140db4930
    efd::SmartPointer<Unk_SSGNpc> m_spNpc;                  // +0x18
};
MS2_CHECK_SIZE(NotifyRemoveNpc, 0x20);
class Unk_SSGNotifyCenter { public: void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify); };
Unk_SSGNotifyCenter* FUN_140939a10();

// 0x4d..0xf2: forwarders to the feature managers
class Unk_SSGad4b90 { public: void FUN_141861840(CInPacket& packet); void FUN_141861f60(CInPacket& packet); };
Unk_SSGad4b90* FUN_140ad4b90();
class Unk_SSG9670b0 { public: void FUN_14122f270(CInPacket& packet); };
Unk_SSG9670b0* FUN_1409670b0();
class Unk_SSG97a780 { public: void FUN_140ae2e90(CInPacket& packet); };
Unk_SSG97a780* FUN_14097a780();
class Unk_SSGa6a830 { public: void FUN_140a2f730(CInPacket& packet); };
Unk_SSGa6a830* FUN_140a6a830();
class Unk_SSG9c4b20 { public: void FUN_1405322b0(CInPacket& packet); };
Unk_SSG9c4b20* FUN_1409c4b20();
class Unk_SSG535310 { public: void FUN_140612850(CInPacket& packet); };
Unk_SSG535310* FUN_140535310();
class Unk_SSG09a700 { public: void FUN_14127e250(CInPacket& packet); };
Unk_SSG09a700* FUN_14109a700();
class Unk_SSG9eed60 { public: void FUN_14127e550(CInPacket& packet); };
Unk_SSG9eed60* FUN_1409eed60();
class Unk_SSG953f20 { public: void FUN_140cd9840(CInPacket& packet); };
Unk_SSG953f20* FUN_140953f20();
class Unk_SSGc8dac0 { public: void FUN_140d061b0(CInPacket& packet); };
Unk_SSGc8dac0* FUN_140c8dac0();
class Unk_SSGDlg4e4c { public: void FUN_1419f5e90(CInPacket& packet); };
Unk_SSGDlg4e4c* FUN_140e01890(int nId);                     // GetDialog<T>(0x4e4c)
class Unk_SSGDlg4e52 { public: void FUN_141908290(CInPacket& packet); };
Unk_SSGDlg4e52* FUN_14136f290(int nId);                     // GetDialog<T>(0x4e52)
void FUN_140930fe0(CInPacket& packet);

// 0x1a..0xe7: feature manager / dialog handlers
class Unk_SSGCubeObj { public: void FUN_140b107f0(int n); void FUN_140b10a10(__int64 n); };
extern int DAT_143ab2900;
extern int DAT_143ab2918;
class Unk_SSGDlg4e28 { public: void FUN_141939620(); };
Unk_SSGDlg4e28* FUN_140938b90(int nId);                     // GetDialog<T>(0x4e28)
class Unk_MyPCSkillSlots { public: void FUN_141765de0(); void FUN_141767ae0(CInPacket& packet); };
class Unk_MyPCStatPoints : public CPtred { public: void FUN_140ca9e90(CInPacket& packet); };
class Unk_SSGConstValue { public: int* FUN_1402056b0(); int FUN_140ad5c50(); };
class Unk_SSGConstValue2 { public: int* FUN_1401d7c10(); };
class Unk_SSGConstants
{
public:
    char m_pad_00[0x2970];
    Unk_SSGConstValue m_2970;                               // +0x2970
    char m_pad_2971[0x3680 - 0x2971];
    Unk_SSGConstValue m_3680;                               // +0x3680
    char m_pad_3681[0x66d0 - 0x3681];
    Unk_SSGConstValue2 m_66d0;                              // +0x66d0
    char m_pad_66d1[0x67e0 - 0x66d1];
    Unk_SSGConstValue2 m_67e0;                              // +0x67e0
};
MS2_CHECK_OFFSET(Unk_SSGConstants, m_67e0, 0x67e0);
MS2_CHECK_OFFSET(Unk_SSGConstants, m_2970, 0x2970);
MS2_CHECK_OFFSET(Unk_SSGConstants, m_3680, 0x3680);
MS2_CHECK_OFFSET(Unk_SSGConstants, m_66d0, 0x66d0);
Unk_SSGConstants* FUN_1401d3200();
class UIAutoReviveCountDownDialog : public UIDialog { public: void FUN_141284d70(int n); };
class UIGlobalPortalDialog : public UIDialog { public: void FUN_1412c3020(CInPacket& packet); };
class UIQuizDialog : public UIDialog { public: void FUN_14129a930(CInPacket& packet); };
class UIIndividualPvPDialog : public UIDialog { public: void FUN_1412cacc0(); void FUN_1412cb220(); };
int FUN_141276180(const CString& strA, const CString& strB);
class Unk_SSGDungeonRecord : public CPtred { public: void FUN_140b20be0(CInPacket& packet); };
class Unk_SSGGlobalFactor { public: void FUN_1404c18c0(CInPacket& packet); };
Unk_SSGGlobalFactor* FUN_140302b10();
class Unk_SSGPreload { public: void FUN_14074ee30(); };
Unk_SSGPreload* FUN_1407476c0();

// 0xef..0x138
extern int DAT_143ab2950;
extern char DAT_143ab2943;
class Unk_SSGChatEmoticon : public CPtred { public: void FUN_140a3a700(CInPacket& packet); };   // CChatEmoticonCli
void FUN_140e146f0(CInPacket& packet);
class Unk_SSGHomeBlocks { public: void FUN_140a46b90(CInPacket& packet); };                     // HomeBlockManager
Unk_SSGHomeBlocks* FUN_1414a5830();

class Unk_SSGStatusListener { public: void FUN_141b0ce20(int a, int b); };
Unk_SSGStatusListener* FUN_140aa6d40();
void FUN_140930150(int n);
class Unk_PCCubeCraft { public: void FUN_1410aa5c0(CubeItemInfo* pInfo); };

void FUN_1403d7440(CInputStream& stream, CAtlArray<unsigned int>& arr);   // read a u32 array
class Unk_SSGMsgBoxFlags { public: void FUN_1417e25a0(int nClassId); };
Unk_SSGMsgBoxFlags* FUN_140aa6d30();
void FUN_140d73bc0(int nType, int a, void* p, CStringW strTag);
extern CStringW DAT_143ae79f0;
bool FUN_14028d780(unsigned char n);
class Unk_SSGDlg4e47 { public: void FUN_141b10ba0(int n); };
Unk_SSGDlg4e47* FUN_140de48d0(int nId);                     // GetDialog<T>(0x4e47)
class Unk_SSGDlg4ed8 { public: void FUN_1412c5330(int n); void FUN_1412c54e0(int n); };
Unk_SSGDlg4ed8* FUN_140bbea00(int nId);                     // GetDialog<T>(0x4ed8)

class Unk_SSGDlg4e29 { public: void FUN_141a3b130(__int64 nUid, int nType, const Unk_NiPoint3& kPos); };
Unk_SSGDlg4e29* FUN_140c9b540(int nId);                     // GetDialog<T>(0x4e29)

class Unk_SSGCommandLog { public: int FUN_1401859c0(int nType, int nValue, const wchar_t* pszText); };
Unk_SSGCommandLog* FUN_140166440();
class Unk_SSGChatDialog { public: void FUN_141ac1d10(int n); };
Unk_SSGChatDialog* FUN_140938cd0(int nId);                  // GetDialog<UIChatDialog>
class Unk_SSGMessengerBrowser { public: void FUN_141a265d0(); void FUN_141a26560(unsigned int nId); void FUN_141a26600(); };
Unk_SSGMessengerBrowser* FUN_140a3ab70(int nId);            // GetDialog<UIMessengerBrowser>
class UIUnlimitedEnchantDialog : public UIDialog
{
public:
    void FUN_140fb6310(CInPacket& packet);
    void FUN_140fb6b00(CInPacket& packet);
    void FUN_140fb6c30(int n);
};

class Unk_SSGBattleRecord { public: void FUN_140a05550(__int64 nKey, __int64 nDelta); };
Unk_SSGBattleRecord* FUN_140e09140();                       // TSingleton<CBattleRecordManager>
class Unk_SSG9a6f0 { public: void FUN_14117e4c0(__int64 nDelta); };
Unk_SSG9a6f0* FUN_14109a6f0();
void FUN_1413612c0(__int64 nDelta, int n);
class Unk_SSGQuestMgr { public: void FUN_1416ca2f0(); };
Unk_SSGQuestMgr* FUN_140764020();
class Unk_SSGGrabState : public State { public: int FUN_141024a30(int nId); };
class Unk_SSGDlg2711 { public: void FUN_141a5a560(); };
Unk_SSGDlg2711* FUN_140938c30(int nId);
void FUN_141a60f00(int nObjectId);
class Unk_SSGcea070 { public: void FUN_140dd86a0(int nA, int nB); };
Unk_SSGcea070* FUN_140cea070();
void FUN_141275260(int nStringId, int nA, int nB);

class Unk_SSGEffectCfg { public: char m_pad_00[0x358]; CString m_str358; };
MS2_CHECK_OFFSET(Unk_SSGEffectCfg, m_str358, 0x358);
Unk_SSGEffectCfg* FUN_1401d31f0();
PC* FUN_140974230(PCBase* pActor);                          // DynamicCast<PC> (class id 0x6200003)
class Unk_SSGa94350
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(int n);
};
Unk_SSGa94350* FUN_140a94350();

class Unk_SSGSkillAttr : public CPtred { };
class Unk_SSGSkillTable { public: MS2Ptr<Unk_SSGSkillAttr> FUN_140aafef0(int nSkillId, unsigned short nLevel); };
Unk_SSGSkillTable* FUN_1401958b0();                         // SkillDataTableCli
class Unk_SSGSkillCollision
{
public:
    void FUN_141755cd0(PCBase* pActor, MS2Ptr<Unk_SSGSkillAttr> spSkill, const Unk_StreamPoint& kPos, const Unk_StreamPoint& kDir);
};
Unk_SSGSkillCollision* FUN_141469a90();                     // CSkillCollisionManager
class Unk_SSGMyPCV : public PC
{
public:
    virtual void vfunc_147(); virtual void vfunc_148(); virtual void vfunc_149();
};

// ---- statics (exe .di order) -----------------------------------------------------------------------------------
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateGame);

static CStringW s_confirmChangeCharName(L"confirmChangeCharName");
static CStringW s_individualArenaJoin(L"individualArenaJoin");
static CStringW s_maintenanceExit(L"maintenanceExit");
static CStringW s_recallconfirm(L"recallconfirm");
static CStringW s_startbypass(L"startbypass");
static CStringW s_useBindEquipItem(L"useBindEquipItem");
static CString s_sort8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_sort7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill = "skill";
static CString s_stun = "stun";
static Unk_Handle1401cd100 s_handle(0);
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";
static CString s_noticeBattleHp10 = "notice_battle_hp_10percent";
static CString s_sound02100201 = "02100201";
static CString s_sound02100200 = "02100200";
static CString s_sound02100199 = "02100199";
static CString s_pcBuyHouse = "PC_buy_house";
static CString s_systemFieldWar = "System_FieldWar";
static CString s_telescopeFind = "Telescope_Find";
static CString s_guildBattleApply = "guildBattle_Apply";
static CString s_noticeWarningBag = "system_notice_error_warningBag";
static CString s_noticeWarningDanger = "system_notice_warningDanger";
static CString s_noticeWarningNoBuild = "system_notice_error_warningNoBuild";
static CString s_systemKillSlayer = "System_KillSlayer";
static CString s_summonCash = "Summon_Cash";
static CString s_systemTaxiFind = "system_Taxi_Find";
static CString s_ugcBuyland = "ugc_buyland";
static CString s_ugcRemoveblock = "ugc_removeblock";
static CString s_ugcRotateblock = "ugc_rotateblock";
static CString s_ugcSellland = "ugc_sellland";
static CString s_ugcSetblock = "ugc_setblock";

// @0x14170bda0
CSceneStateGame::CSceneStateGame()
{
    m_f20 = 0;
    m_nOpcode = 0;
    m_nTaxiEffect = 0;
    m_b18 = true;
}

// @0x14170be40
CSceneStateGame::~CSceneStateGame()
{
}

// @0x14170be90
int CSceneStateGame::vfunc_15()
{
    return 1;
}
MS2_REPLACE_METHOD(0x14170be90, CSceneStateGame, vfunc_15, 11, 0x30025ED0);

// @0x14170beb0
// MS2-FUNCTIONAL: the exe keeps the 24-byte FUN_140987930 result slot pointer in a stack temp before the call (same as CSceneStateMove/Multi::OnEnter)
void CSceneStateGame::OnEnter(int nPrevState)
{
    CSceneStateBase::OnEnter(nPrevState);
    FUN_1403ed2d0()->FUN_141bbae40(this);
    m_f20 = FUN_141473280(FUN_14086d260());
    FUN_141489ff0(FUN_140aae430(), static_cast<const Unk_143a09680&>(FUN_140987930(DAT_143a09680)));
    FUN_140d8ee90()->FUN_140a1f7f0(true);
    FUN_140db8eb0(FUN_140c7a250());
    m_bReconnecting = false;
    m_nRetry = 0;
    m_reconnectTimer.FUN_1408687f0();
    FUN_1403ed2b0()->FUN_141add040(0x4e32);
    FUN_140d9f040(FUN_140931510());
}
MS2_REPLACE_METHOD(0x14170beb0, CSceneStateGame, OnEnter, 270, 0x562E95A4);

// @0x14170bfd0
void CSceneStateGame::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
    FUN_140aad0d0(FUN_140e800e0());
    FUN_140d9f0c0(FUN_140931510());
    FUN_140ceac00(FUN_14015a050());
    FUN_140ad68a0(FUN_1409eed70());
    FUN_1418894d0(FUN_14052d220());
    FUN_1403ed2d0()->FUN_141bbae80(this);
    FUN_1403ed2b0()->FUN_141adc050();
    FUN_1403ed2d0()->FUN_141bbc580(0, 0);
    FUN_14162b790(FUN_1409670d0());
    FUN_140d8ee90()->FUN_140a1f7f0(false);
    FUN_1409a4090(FUN_1409a8b00());
}
MS2_REPLACE_METHOD(0x14170bfd0, CSceneStateGame, OnLeave, 220, 0x6782486F);

// @0x14170c0c0
void CSceneStateGame::OnUpdate(double fTime)
{
    CSceneStateBase::OnUpdate(fTime);
    if (m_bReconnecting)
    {
        if (m_nRetry < 5)
        {
            if (m_reconnectTimer.FUN_140868c00() != 0)
            {
                if (FUN_140714f90()->FUN_1415384e0() == 0)
                {
                    FUN_140714f90()->FUN_1415383a0(DAT_143ab2a48, DAT_143ab2848, 1, 1, 0);
                    m_nRetry = m_nRetry + 1;
                    CStringW text = FUN_14062b4f0(CStringW(L"s_reconnect_to_server"), m_nRetry);
                    void* loading = FUN_141540270(0x3ed);
                    if (loading)
                        FUN_1419e0050(loading, text);
                }
                m_reconnectTimer.FUN_140868750(10000);
            }
        }
        else if (m_nRetry == 5 && m_reconnectTimer.FUN_140868c00() != 0)
        {
            m_reconnectTimer.FUN_1408687f0();
            m_nRetry = 6;
            if (DAT_143b03490)
                DAT_143b03490(1, DAT_1430c3b20, efd::LogHelper(FUN_14016a600(FUN_1408116a0(0x20f, 7), 0)));
            FUN_140d86260()->vfunc_58(0x20f, 7);
            {
                CStringW title(L"MS2");
                FUN_141b6fcf0(FUN_1408116a0(0x20f, 7), title, 0);
            }
            TerminateProcess(GetCurrentProcess(), 2);
        }
    }
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
    {
        Ridee* pRidee = pPC->FUN_1416764a0();
        if (pRidee != 0)
            pRidee->FUN_141706650(false);
        else
            FUN_141524a80(pPC, 0);
        for (unsigned __int64 i = 0; i < 3; i++)
        {
            Unk_SSGSubActor* pSub = FUN_141662440(pPC, (int)i);
            if (pSub != 0)
                pSub->vfunc_126();
        }
    }
    FUN_140d8ee90()->FUN_140a1f8a0();
    FUN_140953f30()->FUN_140ad1ef0();
    if (FUN_140e800e0() != 0)
        FUN_140aadd70(FUN_140e800e0());
    FUN_14173fe20();
}
MS2_REPLACE_METHOD(0x14170c0c0, CSceneStateGame, OnUpdate, 1244, 0x2C40A545);

// @0x14170c5b0
void CSceneStateGame::OnPacket(CInPacket& packet)
{
    CSceneStateBase::OnPacket(packet);
    m_nOpcode = packet.FUN_14070fe80();
    switch (m_nOpcode)
    {
    case 0x9:
        FUN_14170dc90(packet);
        break;
    case 0x15:
        FUN_14170dd60(packet);
        break;
    case 0x7d:
        FUN_14170e800(packet);
        break;
    case 0x16:
        FUN_14170f930(packet);
        break;
    case 0x19:
        FUN_14170fc70(packet);
        break;
    case 0x17:
        FUN_14170fda0(packet);
        break;
    case 0x18:
        FUN_141711dc0(packet);
        break;
    case 0x1c:
        FUN_141712690(packet);
        break;
    case 0x7a:
        FUN_141712710(packet);
        break;
    case 0x1f:
        FUN_141712a90(packet);
        break;
    case 0x20:
        FUN_141712fb0(packet);
        break;
    case 0xce:
        FUN_1417132b0(packet);
        break;
    case 0x21:
        FUN_141713fb0(packet);
        break;
    case 0x22:
        DAT_143ab2d80.FUN_140de3480(packet);
        break;
    case 0x23:
        FUN_141715bd0(packet);
        break;
    case 0x24:
        FUN_141716200(packet);
        break;
    case 0x25:
        FUN_141716680(packet);
        break;
    case 0x26:
        FUN_141716b60(packet);
        break;
    case 0x27:
        FUN_141716d10(packet);
        break;
    case 0x28:
        FUN_141717000(packet);
        break;
    case 0x29:
        FUN_141717560(packet);
        break;
    case 0x2a:
        FUN_141717140(packet);
        break;
    case 0x30:
        FUN_141717340(packet);
        break;
    case 0x2b:
        FUN_141711e70(packet);
        break;
    case 0x2c:
        FUN_141712340(packet);
        break;
    case 0x2d:
        FUN_141712420(packet);
        break;
    case 0x3c:
        FUN_141717b40(packet);
        break;
    case 0x40:
        FUN_1417187b0(packet);
        break;
    case 0x41:
        FUN_141718b80(packet);
        break;
    case 0x2e:
        FUN_1417176b0(packet);
        break;
    case 0x2f:
        FUN_141717580(packet);
        break;
    case 0x34:
        FUN_14171a900(packet);
        break;
    case 0x33:
        FUN_14171a730(packet);
        break;
    case 0x35:
        FUN_14171aa90(packet);
        break;
    case 0x38:
        FUN_14171aec0(packet);
        break;
    case 0xae:
        FUN_14171b380(packet);
        break;
    case 0x37:
        FUN_14171ab00(packet);
        break;
    case 0x39:
        FUN_14171b630(packet);
        break;
    case 0x3a:
        FUN_14171b750(packet);
        break;
    case 0x117:
        FUN_14171bad0(packet);
        break;
    case 0x3b:
        FUN_14171bd90(packet);
        break;
    case 0x32:
        FUN_14171a6c0(packet);
        break;
    case 0x4b:
        FUN_141719a30(packet);
        break;
    case 0x48:
        FUN_14171ee80(packet);
        break;
    case 0x49:
        FUN_14171f8a0(packet);
        break;
    case 0x3d:
        FUN_14171c0b0(packet);
        break;
    case 0x47:
        FUN_141720480(packet);
        break;
    case 0x130:
        FUN_141720c60(packet);
        break;
    case 0x4c:
        FUN_141720e50(packet);
        break;
    case 0x4e:
        FUN_141721270(packet);
        break;
    case 0x4d:
        FUN_1417212a0(packet);
        break;
    case 0x55:
        FUN_141718cf0(packet);
        break;
    case 0x56:
        FUN_1417195f0(packet);
        break;
    case 0x57:
        FUN_1417197c0(packet);
        break;
    case 0x5a:
        FUN_141719a60(packet);
        break;
    case 0x5b:
        FUN_14171a2e0(packet);
        break;
    case 0x58:
        FUN_141719840(packet);
        break;
    case 0x5c:
        FUN_14171a5f0(packet);
        break;
    case 0x59:
        FUN_141719990(packet);
        break;
    case 0x4f:
        FUN_1417212d0(packet);
        break;
    case 0x50:
        if (FUN_140ee0d10() != 0)
            FUN_140ee0d10()->FUN_140b8c260(packet);
        break;
    case 0x5d:
        FUN_1417215a0(packet);
        break;
    case 0x36:
        FUN_141721940(packet);
        break;
    case 0xfa:
        FUN_14173b080(packet);
        break;
    case 0x3e:
        FUN_141718150(packet);
        break;
    case 0x3f:
        FUN_141718680(packet);
        break;
    case 0x5f:
        FUN_141721a30(packet);
        break;
    case 0x54:
        FUN_141721cd0(packet);
        break;
    case 0x60:
        FUN_141722f70(packet);
        break;
    case 0x61:
        FUN_141721c50(packet);
        break;
    case 0x62:
        FUN_141721c90(packet);
        break;
    case 0x64:
        FUN_141722fb0(packet);
        break;
    case 0x65:
        FUN_141723050(packet);
        break;
    case 0x66:
        FUN_141723260(packet);
        break;
    case 0x68:
        FUN_141723410(packet);
        break;
    case 0x69:
        FUN_141723670(packet);
        break;
    case 0x6a:
        FUN_141728110(packet);
        break;
    case 0x67:
        FUN_1417232a0(packet);
        break;
    case 0x70:
        FUN_141723330(packet);
        break;
    case 0x71:
        FUN_141728c20(packet);
        break;
    case 0x73:
        FUN_141729250(packet);
        break;
    case 0x74:
        FUN_141729ce0(packet);
        break;
    case 0x75:
        FUN_14172a1c0(packet);
        break;
    case 0x76:
        FUN_14172a7b0(packet);
        break;
    case 0x77:
        FUN_14172a850(packet);
        break;
    case 0x79:
        FUN_14172a8f0(packet);
        break;
    case 0x7b:
        FUN_14172b350(packet);
        break;
    case 0x6e:
        FUN_14172c170(packet);
        break;
    case 0x63:
        FUN_14172d0f0(packet);
        break;
    case 0x42:
        FUN_14172f030(packet);
        break;
    case 0x43:
        FUN_14172f1c0(packet);
        break;
    case 0x44:
        FUN_14172f210(packet);
        break;
    case 0x45:
        FUN_14172f480(packet);
        break;
    case 0x7e:
        FUN_14172f500(packet);
        break;
    case 0x7f:
        FUN_141730920(packet);
        break;
    case 0x80:
        FUN_141731470(packet);
        break;
    case 0x81:
        FUN_141731610(packet);
        break;
    case 0x83:
        FUN_1417316d0(packet);
        break;
    case 0x86:
        FUN_141731730(packet);
        break;
    case 0x89:
        FUN_141731160(packet);
        break;
    case 0x94:
        FUN_141731190(packet);
        break;
    case 0x95:
        FUN_141731350(packet);
        break;
    case 0x96:
        FUN_141731ac0(packet);
        break;
    case 0xdb:
        FUN_141731af0(packet);
        break;
    case 0xc:
        FUN_141731b20(packet);
        break;
    case 0x8c:
        FUN_141731c10(packet);
        break;
    case 0xb6:
        FUN_141732350(packet);
        break;
    case 0x9d:
        FUN_141732ac0(packet);
        break;
    case 0x9e:
        FUN_141732af0(packet);
        break;
    case 0x97:
        FUN_141732b20(packet);
        break;
    case 0x9b:
        FUN_141733140(packet);
        break;
    case 0x9f:
        FUN_141733440(packet);
        break;
    case 0xa1:
        FUN_141733660(packet);
        break;
    case 0xa2:
        FUN_1417337c0(packet);
        break;
    case 0xa3:
        FUN_141733850(packet);
        break;
    case 0xa6:
        FUN_141736880(packet);
        break;
    case 0xa8:
        FUN_141736940(packet);
        break;
    case 0x1a:
        FUN_141737360(packet);
        break;
    case 0xaa:
        FUN_1417373d0(packet);
        break;
    case 0xab:
        FUN_141739910(packet);
        break;
    case 0xac:
        FUN_141739e40(packet);
        break;
    case 0xb0:
        FUN_141733b30(packet);
        break;
    case 0xb1:
        FUN_141733e40(packet);
        break;
    case 0xb2:
        FUN_140ceab50(FUN_14015a050(), packet);
        break;
    case 0x137:
        FUN_140ad5f00(FUN_1409eed70(), packet);
        break;
    case 0xb5:
        FUN_141733f50(packet);
        break;
    case 0xb7:
        FUN_1417340f0(packet);
        break;
    case 0xb9:
        FUN_1417343c0(packet);
        break;
    case 0xba:
        FUN_1417343f0(packet);
        break;
    case 0xbc:
        FUN_141734530(packet);
        break;
    case 0xbd:
        {
            Unk_SSGDialog4edc* pDlg = FUN_140ce84f0(0x4edc);
            if (pDlg != 0)
                pDlg->FUN_1412a53e0(packet);
        }
        break;
    case 0xbe:
        FUN_141734930(packet);
        break;
    case 0xbf:
        FUN_141734950(packet);
        break;
    case 0xc1:
        FUN_141734b20(packet);
        break;
    case 0xc2:
        FUN_141734b70(packet);
        break;
    case 0xc3:
        FUN_141734bc0(packet);
        break;
    case 0xc4:
        FUN_141734c70(packet);
        break;
    case 0xc5:
        FUN_141734ca0(packet);
        break;
    case 0xd8:
        FUN_141734e00(packet);
        break;
    case 0xc7:
        FUN_1417353b0(packet);
        break;
    case 0xca:
        FUN_1417353e0(packet);
        break;
    case 0xcb:
        FUN_141735410(packet);
        break;
    case 0xcd:
        FUN_141735440(packet);
        break;
    case 0xd1:
        FUN_141737d60(packet);
        break;
    case 0xcf:
        {
            UINoticeDialog* pDlg = Unk_SSGGetDialog<UINoticeDialog>(0x4ee9);
            if (pDlg != 0)
                pDlg->FUN_141009680(packet);
        }
        break;
    case 0xd3:
        FUN_141737db0(packet);
        break;
    case 0xd6:
        FUN_1417380c0(packet);
        break;
    case 0xd7:
        FUN_141738120(packet);
        break;
    case 0xdc:
        FUN_141738290(packet);
        break;
    case 0xdd:
        FUN_141738380(packet);
        break;
    case 0xe8:
        FUN_141738430(packet);
        break;
    case 0xe7:
        FUN_141738ad0(packet);
        break;
    case 0xea:
        FUN_141738b40(packet);
        break;
    case 0xeb:
        FUN_141739f90(packet);
        break;
    case 0xec:
        FUN_14173a0d0(packet);
        break;
    case 0x101:
        FUN_14173a0f0(packet);
        break;
    case 0xe9:
        FUN_14173a370(packet);
        break;
    case 0xf1:
        FUN_14173a420(packet);
        break;
    case 0xf2:
        FUN_14173a5b0(packet);
        break;
    case 0xf3:
        FUN_14173a5e0(packet);
        break;
    case 0xf4:
        FUN_14173a720(packet);
        break;
    case 0xf8:
        FUN_14173a990(packet);
        break;
    case 0xf7:
        FUN_141735dd0(packet);
        break;
    case 0xf9:
        FUN_141736240(packet);
        break;
    case 0xfb:
        FUN_14173b1d0(packet);
        break;
    case 0xfd:
        FUN_14173b220(packet);
        break;
    case 0xfe:
        FUN_14173b380(packet);
        break;
    case 0x103:
        FUN_14173b420(packet);
        break;
    case 0x105:
        FUN_14173b5a0(packet);
        break;
    case 0x106:
        FUN_14173c090(packet);
        break;
    case 0x113:
        FUN_1403ed2d0()->FUN_141bd9c20(packet);
        break;
    case 0x111:
        FUN_14173c7a0(packet);
        break;
    case 0x115:
        FUN_14173c870(packet);
        break;
    case 0x118:
        FUN_14173ce30(packet);
        break;
    case 0x11a:
        FUN_14173d180(packet);
        break;
    case 0x11b:
        FUN_14173d2e0(packet);
        break;
    case 0x11c:
        FUN_14173d4d0(packet);
        break;
        break;  // the exe keeps a dead jmp here (a removed case's leftover break)
    case 0x120:
        FUN_14173ddf0(packet);
        break;
    case 0x121:
        FUN_14173de10(packet);
        break;
    case 0x91:
        FUN_14173def0(packet);
        break;
    case 0x11f:
        FUN_14173dfd0(packet);
        break;
    case 0x126:
        FUN_14173e440(packet);
        break;
    case 0xef:
        FUN_14173e4b0(packet);
        break;
    case 0xf5:
        FUN_14173e510(packet);
        break;
    case 0x128:
        FUN_1409eed90()->FUN_141b83750(packet);
        break;
    case 0x12b:
        FUN_14173e5b0(packet);
        break;
    case 0x12c:
        FUN_14173f0c0(packet);
        break;
    case 0x12e:
        FUN_14173f1a0(packet);
        break;
    case 0x12f:
        FUN_14173f280(packet);
        break;
    case 0xde:
        FUN_14173f550(packet);
        break;
    case 0x131:
        FUN_14173f7c0(packet);
        break;
    case 0x135:
        FUN_14173f810(packet);
        break;
    case 0x136:
        FUN_14173f860(packet);
        break;
    case 0x138:
        FUN_14173fc00(packet);
        break;
    case 0x139:
        FUN_14173fc40(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14170c5b0, CSceneStateGame, OnPacket, 4075, 0x85D9EB98);

// @0x14170d9f0
void CSceneStateGame::vfunc_1(int nParam)
{
    {
        COutPacket out(0xf, 0);
        out.COutPacket::vfunc_o10_3(FUN_1403ed2d0()->FUN_141bd98d0());
        FUN_140710590(out);
    }
    FUN_141889150(FUN_14052d220());
    {
        COutPacket out(0x38, 0);
        out.COutPacket::vfunc_o10_1(0x12);
        out.COutPacket::vfunc_o10_3(nParam);
        FUN_140710590(out);
    }
    FUN_141739450(false);
    if (DAT_143ab285c != 0 && DAT_143ab2860 == 3)
    {
        DAT_143ab285c = 0;
        DAT_143ab284b = 0;
    }
}

// @0x14170daf0
void CSceneStateGame::vfunc_4(int)
{
    FUN_141739880();
    if (DAT_1439f4a78 == 1)
    {
        m_bReconnecting = true;
        m_nRetry = 0;
        m_reconnectTimer.FUN_140868750(10000);
        FUN_140714f90()->FUN_1415383a0(DAT_143ab2a48, DAT_143ab2848, 1, 1, 0);
    }
}

// @0x14170dbc0
int CSceneStateGame::vfunc_14()
{
    return 1;
}
MS2_REPLACE_METHOD(0x14170dbc0, CSceneStateGame, vfunc_14, 11, 0x30025ED0);

// @0x14170dbe0
void CSceneStateGame::OnWndMessage(unsigned int nMsg, int wParam, int lParam)
{
    if (nMsg == 0x203)
    {
        if (FUN_14025e7a0()->FUN_1422aeed0(2) != 0)
            return;
        if (FUN_1409478c0()->FUN_140a18070() != 0)
            FUN_1409478c0()->FUN_140aeb1a0();
    }
    else if (nMsg == 0x200)
    {
        if (FUN_14025e7a0()->FUN_1422aeed0(2) != 0)
            return;
    }
    FUN_140953f30()->FUN_140ad1da0(nMsg, wParam, lParam);
}
MS2_REPLACE_METHOD(0x14170dbe0, CSceneStateGame, OnWndMessage, 155, 0x19D25A81);

// @0x14170dc90
void CSceneStateGame::FUN_14170dc90(CInPacket& packet)
{
    Unk_SSGEnterRequest req;
    req.m_nAccountId = DAT_143ab2820;
    req.m_n8 = DAT_143ab284c;
    req.m_nC = DAT_143ab2850;
    req.m_machineId.FUN_14067c080(FUN_140aadf70()->FUN_140d4fdf0());
    COutPacket out(4, 0);
    req.FUN_1401f9d20(out);
    FUN_140710590(out);
}
MS2_REPLACE_METHOD(0x14170dc90, CSceneStateGame, FUN_14170dc90, 191, 0x74DA6D2C);

// @0x14170dd60
void CSceneStateGame::FUN_14170dd60(CInPacket& packet)
{
    FUN_14092f420();
    DAT_143ab2864 = static_cast<CInputStream&>(packet).vfunc_o8_3();
    DAT_143ab2828 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nChannel = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    if (nChannel == 0 && DAT_1439f4a7c != 0)
        DAT_1439f4a80 = DAT_1439f4a7c < 1 ? 1 : DAT_1439f4a7c;
    if (nChannel != 0 && FUN_14092f640() != 0 && FUN_14092f640() != nChannel)
    {
        CStringW strMsg = FUN_1408116a0(0x2d7, nChannel);
        FUN_1412751b0(strMsg, 0x14);
    }
    if (nChannel != 0)
        FUN_140714f90()->FUN_141539130();
    __int64 a = 0, b = 0, c = 0, d = 0, e = 0;
    DAT_1439f4a7c = nChannel;
    DAT_143ab28a0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28a8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab2898 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    a = static_cast<CInputStream&>(packet).vfunc_o8_4();
    b = static_cast<CInputStream&>(packet).vfunc_o8_4();
    c = static_cast<CInputStream&>(packet).vfunc_o8_4();
    d = static_cast<CInputStream&>(packet).vfunc_o8_4();
    e = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28b0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28b8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28c0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28c8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28d0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28d8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28e0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28e8 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    DAT_143ab28f0 = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CString strUnk = static_cast<CInputStream&>(packet).vfunc_o8_6();
    int nChatFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    FUN_1409304d0(a, b, c, d);
    FUN_140930af0(e);
    if (FUN_140f97ef0() != 0)
        FUN_140f97ef0()->FUN_140f97f00()->FUN_140dbde50(nChatFlag);
    DAT_143ab3058.FUN_1402c2830();
    int nCount = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    for (int i = 0; i < nCount; i++)
    {
        int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab3058.FUN_1401855a0(n);
    }
    DAT_143ab3098.FUN_1402c2830();
    DAT_143ab3078.FUN_1402c2830();
    nCount = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    for (int j = 0; j < nCount; j++)
    {
        int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab3078.FUN_1401855a0(n);
    }
    __int64 nGuildId = static_cast<CInputStream&>(packet).vfunc_o8_4();
    CStringW strGuildName = static_cast<CInputStream&>(packet).vfunc_o8_8();
    FUN_1403ed290()->FUN_1413bc1f0(nGuildId, strGuildName);
    FUN_1403ed290()->FUN_1413bcd10();
    CString str1 = static_cast<CInputStream&>(packet).vfunc_o8_6();
    CString str2 = static_cast<CInputStream&>(packet).vfunc_o8_6();
    CString str3 = static_cast<CInputStream&>(packet).vfunc_o8_6();
    if (FUN_140cc18a0() != 0)
    {
        FUN_140cc18a0()->FUN_141b77e50(str1);
        FUN_140cc18a0()->FUN_141b77e90(str2);
        FUN_140cc18a0()->FUN_141b77ed0(str3);
    }
    Unk_SSGChannelDialog* pDlg = FUN_14136f520(0x4ef0);
    if (pDlg != 0)
        pDlg->FUN_141ad2ea0(nChannel);
    FUN_1403ed2b0()->FUN_141ad93b0();
    FUN_1401c0d90()->FUN_1404766e0();
    FUN_1403ed2a0()->FUN_1407ce240();
    if (DAT_143ab2918 == 0)
    {
        COutPacket out(0x82, 0);
        FUN_140710590(out);
    }
    FUN_140714f90()->FUN_141539260();
    if (FUN_1414a56d0() != 0)
    {
        COutPacket out(0xe, 0);
        out.COutPacket::vfunc_o10_4(FUN_1414a56d0()->FUN_14034a1b0());
        FUN_140710590(out);
    }
    if (FUN_140166410()->FUN_14036e5b0())
    {
        if (FUN_140b05bf0() != 0)
            FUN_140b05bf0()->FUN_140b06450(1);
    }
    CString strValue("x64");
    CString strKey("client_arch");
    FUN_140d8ee90()->FUN_140a1f970(strKey, strValue);
}
MS2_REPLACE_METHOD(0x14170dd60, CSceneStateGame, FUN_14170dd60, 2707, 0x78081C2A);

// @0x14170e800
// MS2-FUNCTIONAL: code bytes match; map<int,int>::map / map<int,bool>::begin,end auto-pair with the byte-identical in-range
// copies of another instantiation (0x141745b30/0x14174b5a0/0x14174b8d0) until that user is written; the exe calls 0x141122830/0x14114e5c0/0x141152270
void CSceneStateGame::FUN_14170e800(CInPacket& packet)
{
    if (FUN_1403ed2d0()->FUN_141bcfd10() != 4)
        return;
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nMapId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int bHasInfo = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (FUN_1406aeee0()->FUN_1406af0c0())
        nMode = 0;
    CStringW strName = L"";
    CStringW strDesc = L"";
    int nC = 0;
    __int64 nOwner = 0;
    int nA = 0;
    int nB = 0;
    int nD = 0;
    int nE = 0;
    int nF = 0;
    int nG = 10;
    int nH = 5;
    Unk_SSGHouseRule rule;
    std::map<int, bool> mapFlags;
    std::map<int, int> mapValues;
    ATL::CAtlArray<MS2Ptr<UGCMapDesignInfo> > arrDesign;
    ATL::CAtlArray<MS2Ptr<UGCMapBlueprintInfo> > arrBlueprint;
    if (bHasInfo != 0)
    {
        nOwner = static_cast<CInputStream&>(packet).vfunc_o8_4();
        strName = static_cast<CInputStream&>(packet).vfunc_o8_8();
        strDesc = static_cast<CInputStream&>(packet).vfunc_o8_8();
        nC = static_cast<CInputStream&>(packet).vfunc_o8_1();
        nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
        nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
        nD = static_cast<CInputStream&>(packet).vfunc_o8_3();
        nE = static_cast<CInputStream&>(packet).vfunc_o8_3();
        nF = static_cast<CInputStream&>(packet).vfunc_o8_1();
        nG = static_cast<CInputStream&>(packet).vfunc_o8_1();
        nH = static_cast<CInputStream&>(packet).vfunc_o8_1();
        rule.FUN_140b68ec0(packet);
        unsigned __int64 nFlags = static_cast<CInputStream&>(packet).vfunc_o8_1();
        for (unsigned __int64 i = 0; i < nFlags; i++)
        {
            int nKey = (int)i;
            bool bSet = static_cast<CInputStream&>(packet).vfunc_o8_1() == 1 ? true : false;
            mapFlags[nKey] = bSet;
            if (bSet)
            {
                int nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
                mapValues[nKey] = nValue;
            }
        }
        if (nOwner == DAT_143ab2820)
        {
            unsigned __int64 nDesigns = static_cast<CInputStream&>(packet).vfunc_o8_1();
            for (unsigned __int64 j = 0; j < nDesigns; j++)
            {
                MS2Ptr<UGCMapDesignInfo> pInfo(new UGCMapDesignInfo());
                pInfo->m_nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                pInfo->m_strName = static_cast<CInputStream&>(packet).vfunc_o8_6();
                pInfo->m_nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
                arrDesign.Add(pInfo);
            }
            unsigned __int64 nBlueprints = static_cast<CInputStream&>(packet).vfunc_o8_1();
            for (unsigned __int64 k = 0; k < nBlueprints; k++)
            {
                MS2Ptr<UGCMapBlueprintInfo> pInfo(new UGCMapBlueprintInfo());
                pInfo->m_nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
                pInfo->m_strName = static_cast<CInputStream&>(packet).vfunc_o8_6();
                pInfo->m_nTime = static_cast<CInputStream&>(packet).vfunc_o8_4();
                arrBlueprint.Add(pInfo);
            }
        }
        rule.FUN_140b68f60();
    }
    if (nMode == 0)
    {
        efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService)
        {
            spService->FUN_1410c3020(nMapId);
            spService->FUN_1410c3160(nE);
            spService->FUN_1410c3120(nD);
            spService->FUN_1410cb8b0(true);
            spService->FUN_1410c31a0(nOwner);
            spService->FUN_1410c3220(strName);
            spService->FUN_1410c32b0(strDesc);
            spService->FUN_1410c3310(nC);
            spService->FUN_1410c3410(nA);
            spService->FUN_1410c3450(nB);
            spService->FUN_1410c3630(nF);
            spService->FUN_1410c3490(nG);
            spService->FUN_1410c34d0(nH);
            spService->FUN_1410c3530(rule);
            if (bHasInfo != 0)
            {
                spService->FUN_1410c3670();
                if (nOwner == DAT_143ab2820)
                {
                    spService->FUN_1410d43c0(arrDesign);
                    spService->FUN_1410d4680(arrBlueprint);
                }
            }
            for (std::map<int, bool>::iterator it = mapFlags.begin(); it != mapFlags.end(); ++it)
            {
                int nKey = it->first;
                bool bValue = it->second;
                spService->FUN_1410c3e40(nKey, bValue);
            }
            for (std::map<int, int>::iterator it = mapValues.begin(); it != mapValues.end(); ++it)
            {
                int nKey = it->first;
                int nValue = it->second;
                spService->FUN_1410c3f10(nKey, nValue);
            }
        }
        COutPacket out(0x10, 0);
        out.COutPacket::vfunc_o10_3(FUN_1403ed2d0()->FUN_141bd98d0());
        FUN_140710590(out);
        FUN_1403ed2d0()->FUN_141bdb690();
    }
    else
    {
        efd::SmartPointer<Unk_Service6100017> spService(FUN_1401cd040(&DAT_143b059e8));
        if (spService)
        {
            spService->FUN_1410c3020(nMapId);
            spService->FUN_1410c3160(nE);
            spService->FUN_1410c3120(nD);
            spService->FUN_1410cb8b0(false);
            spService->FUN_1410c31a0(nOwner);
            spService->FUN_1410c3220(strName);
            spService->FUN_1410c32b0(strDesc);
            spService->FUN_1410c3310(nC);
            spService->FUN_1410c3410(nA);
            spService->FUN_1410c3450(nB);
            spService->FUN_1410c3630(nF);
            spService->FUN_1410c3490(nG);
            spService->FUN_1410c34d0(nH);
            spService->FUN_1410c3530(rule);
            if (bHasInfo != 0)
            {
                spService->FUN_1410c3670();
                if (nOwner == DAT_143ab2820)
                {
                    spService->FUN_1410d43c0(arrDesign);
                    spService->FUN_1410d4680(arrBlueprint);
                }
            }
            for (std::map<int, bool>::iterator it = mapFlags.begin(); it != mapFlags.end(); ++it)
            {
                int nKey = it->first;
                bool bValue = it->second;
                spService->FUN_1410c3e40(nKey, bValue);
            }
            for (std::map<int, int>::iterator it = mapValues.begin(); it != mapValues.end(); ++it)
            {
                int nKey = it->first;
                int nValue = it->second;
                spService->FUN_1410c3f10(nKey, nValue);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14170e800, CSceneStateGame, FUN_14170e800, 4389, 0xE0B12C5E);

// @0x14170f930
void CSceneStateGame::FUN_14170f930(CInPacket& packet)
{
    int nError = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nError == 0)
    {
        DAT_143ab2870 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        DAT_143ab2878 = static_cast<CInputStream&>(packet).vfunc_o8_1();
        DAT_143ab287c = static_cast<CInputStream&>(packet).vfunc_o8_1();
        DAT_143ab2880 = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_140930ba0(static_cast<CInputStream&>(packet).vfunc_o8_3());
        Unk_StreamPoint pos = static_cast<CInputStream&>(packet).vfunc_o8_10();
        Unk_StreamPoint rot = static_cast<CInputStream&>(packet).vfunc_o8_10();
        int nPortal = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_1403ed2d0()->FUN_141bd3d70(pos, rot);
        FUN_1403ed2d0()->FUN_141bbbe40(DAT_143ab2870, 1, nPortal);
        FUN_1403ed2b0()->FUN_141adc400();
        DAT_143ab2890 = 0;
        FUN_140967100()->FUN_141b21390();
        FUN_1409331e0()->FUN_14138d7e0(1, DAT_143ab2870);
    }
    else
    {
        FUN_140d73aa0(FUN_140cc20a0(nError), 0, 0, CStringW(L""));
    }
    FUN_1408e57f0()->FUN_1422ba0d0();
    if (DAT_143ab287c == 0xd)
        FUN_1408e57f0()->FUN_1422b9fd0(0x6200086);
}
MS2_REPLACE_METHOD(0x14170f930, CSceneStateGame, FUN_14170f930, 812, 0xCE56891C);

// @0x14170fc70
void CSceneStateGame::FUN_14170fc70(CInPacket& packet)
{
    int nResult = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nResult == 0)
    {
        FUN_140931510()->FUN_140d9f710(packet);
    }
    else if (nResult == 2)
    {
        int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_1412b9870(nId, nType);
    }
    else if (nResult == 1)
    {
        FUN_1412751f0(FUN_14028de60(0x99d), 1, 1);
    }
}
MS2_REPLACE_METHOD(0x14170fc70, CSceneStateGame, FUN_14170fc70, 291, 0x93A32950);

// @0x141711dc0
void CSceneStateGame::FUN_141711dc0(CInPacket& packet)
{
    int nMapId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    MyPC* pPC = pWorld->FUN_141bd0cc0();
    if (pPC != 0)
        FUN_141663500(pPC, nMapId);
    if (FUN_1409f7c90()->FUN_1409f7ea0() != 0)
        pWorld->FUN_141bbbcf0(nMapId, 1);
    else
        pWorld->FUN_141bbbcf0(nMapId, 0);
}
MS2_REPLACE_METHOD(0x141711dc0, CSceneStateGame, FUN_141711dc0, 160, 0xEBC6BBF3);

// @0x141712340
void CSceneStateGame::FUN_141712340(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    GameObject* pObj = FUN_1403ed2d0()->FUN_141bd1180(nId);
    if (pObj == 0)
        return;
    Unk_SSGNpc* pNpc = efd::DynamicCast<Unk_SSGNpc>(pObj);
    if (pNpc == 0)
        return;
    if (pNpc->FUN_1411900d0() == 0)
    {
        Unk_SSGWorld* pWorld = FUN_1403ed2d0();
        pNpc->vfunc_40(1.0f, 0, 0, 0.5f);
        pWorld->FUN_141bbbcf0(nId, 1);
    }
}
MS2_REPLACE_METHOD(0x141712340, CSceneStateGame, FUN_141712340, 205, 0x49E1B8C7);

// @0x141712690
void CSceneStateGame::FUN_141712690(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    FUN_1417127b0(packet, pPC);
}
MS2_REPLACE_METHOD(0x141712690, CSceneStateGame, FUN_141712690, 109, 0x001F1562);

// @0x141712710
void CSceneStateGame::FUN_141712710(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    if (pPC->FUN_1416764a0() == 0)
        return;
    Ridee* pRidee = pPC->FUN_1416764a0();
    FUN_1417127b0(packet, pRidee);
}
MS2_REPLACE_METHOD(0x141712710, CSceneStateGame, FUN_141712710, 141, 0xA57CCB2D);

// @0x141716b60
void CSceneStateGame::FUN_141716b60(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MS2Ptr<CItem> pItem = pPC->FUN_141655b80(nItemUid);
    if (!pItem)
        return;
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001f)
        pPC->vfunc_128(pItem.get(), 1);
    else
        pPC->vfunc_128(pItem.get(), 0);
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        Unk_SSGItemHub* pHub = FUN_140a6a840();
        pHub->vfunc_21(pItem.get());
    }
}
MS2_REPLACE_METHOD(0x141716b60, CSceneStateGame, FUN_141716b60, 415, 0xAD56BCEE);

// @0x141717000
void CSceneStateGame::FUN_141717000(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MS2Ptr<CItem> pItem = pPC->FUN_141655b80(nItemUid);
    if (!pItem)
        return;
    pPC->FUN_1416561c0()->FUN_140c86510(nItemUid);
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
        FUN_140a6a840()->vfunc_5(pItem.get());
}
MS2_REPLACE_METHOD(0x141717000, CSceneStateGame, FUN_141717000, 314, 0xBDB25741);

// @0x141717140
void CSceneStateGame::FUN_141717140(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nItemUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    MS2Ptr<CEquipItem> pEquip = pPC->FUN_141655c30(nItemUid);
    if (!pEquip)
        return;
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        Unk_SSGItemHub* pHub = FUN_140a6a840();
        pHub->vfunc_23(pEquip->FUN_1411dc7a0().get());
    }
    else
    {
        pEquip->FUN_1411dc7a0()->FUN_140524eb0(packet);
        pEquip->FUN_1411dd1c0();
    }
}
MS2_REPLACE_METHOD(0x141717140, CSceneStateGame, FUN_141717140, 494, 0xF8FCFF09);

// @0x141717560
void CSceneStateGame::FUN_141717560(CInPacket& packet)
{
}
MS2_REPLACE_METHOD(0x141717560, CSceneStateGame, FUN_141717560, 11, 0x02239C70);

// @0x141717580
void CSceneStateGame::FUN_141717580(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nEmotion = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor != 0)
    {
        if (pActor->FUN_14166c930() != 0xe)
            pActor->FUN_14166ce70(nEmotion);
        efd::SmartPointer<Ridee> spRidee(pActor->FUN_1416764a0());
        if (spRidee)
            spRidee->FUN_14166ce70(nEmotion);
        if (FUN_14096e160(pActor) != 0)
        {
            PCBase* pTarget = FUN_1403ed2d0()->FUN_141bd3620();
            if (pTarget != 0)
                pTarget->FUN_14166ce70(nEmotion);
        }
    }
}
MS2_REPLACE_METHOD(0x141717580, CSceneStateGame, FUN_141717580, 297, 0xF8FFE207);

// @0x141718680
void CSceneStateGame::FUN_141718680(CInPacket& packet)
{
    __int64 nSkillUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor != 0)
    {
        MS2Ptr<Unk_PCBaseComp_b18> spSkill = pActor->vfunc_103();
        if ((spSkill.get() ? true : false) && spSkill->m_nSkillUid == nSkillUid && pActor->FUN_14166c930() == 0x10)
            pActor->FUN_14166ccb0()->vfunc_7(1);
    }
}
MS2_REPLACE_METHOD(0x141718680, CSceneStateGame, FUN_141718680, 295, 0x1170D80D);

// @0x141718b80
void CSceneStateGame::FUN_141718b80(CInPacket& packet)
{
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nType)
    {
    case 6:
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nSkillUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
        int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nLevel = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            break;
        State* pState = pPC->FUN_14166ccb0();
        if (pState == 0)
            break;
        pState->vfunc_33(true);
    }
    }
}
MS2_REPLACE_METHOD(0x141718b80, CSceneStateGame, FUN_141718b80, 347, 0x325308DD);

// @0x1417195f0
void CSceneStateGame::FUN_1417195f0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGWorld* pWorld = FUN_1403ed2d0();
    Unk_SSGNpc* pNpc = pWorld->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    int n = pNpc->FUN_141093270()->m_n60;
    if (n != 0)
        pNpc->vfunc_40(1.0f, 0.0f, 0.0f, 0.5f);
    pNpc->FUN_1410932c0(0);
    pWorld->FUN_141bbbcf0(nId, 1);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyRemoveNpc(efd::SmartPointer<Unk_SSGNpc>(pNpc))));
}
MS2_REPLACE_METHOD(0x1417195f0, CSceneStateGame, FUN_1417195f0, 455, 0xC7E9BA24);

// @0x1417197c0
void CSceneStateGame::FUN_1417197c0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    pNpc->vfunc_125(1);
}
MS2_REPLACE_METHOD(0x1417197c0, CSceneStateGame, FUN_1417197c0, 113, 0xF86CD5AB);

// @0x141719840
void CSceneStateGame::FUN_141719840(CInPacket& packet)
{
    int nCount = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
    CByteBuffer buf;
    for (int i = 0; i < nCount; i++)
    {
        int nSize = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        buf.FUN_140518490();
        buf.FUN_140715230(nSize);
        static_cast<CInputStream&>(packet).vfunc_o8_9(buf.FUN_140204eb0(), nSize);
        int nId = buf.CByteBuffer::vfunc_o8_3();
        Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
        if (pNpc != 0)
            pNpc->FUN_1410918e0(buf);
    }
}
MS2_REPLACE_METHOD(0x141719840, CSceneStateGame, FUN_141719840, 329, 0xF8C75F47);

// @0x141719990
void CSceneStateGame::FUN_141719990(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    char cFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    pNpc->FUN_14174a560(cFlag);
}
MS2_REPLACE_METHOD(0x141719990, CSceneStateGame, FUN_141719990, 142, 0xE0A802D1);

// @0x141719a30
void CSceneStateGame::FUN_141719a30(CInPacket& packet)
{
    FUN_140967100()->FUN_141b1ddd0(packet);
}
MS2_REPLACE_METHOD(0x141719a30, CSceneStateGame, FUN_141719a30, 37, 0xEF938A5F);

// @0x141721270
void CSceneStateGame::FUN_141721270(CInPacket& packet)
{
    FUN_140ad4b90()->FUN_141861840(packet);
}
MS2_REPLACE_METHOD(0x141721270, CSceneStateGame, FUN_141721270, 37, 0x55E34197);

// @0x1417212a0
void CSceneStateGame::FUN_1417212a0(CInPacket& packet)
{
    FUN_1409670b0()->FUN_14122f270(packet);
}
MS2_REPLACE_METHOD(0x1417212a0, CSceneStateGame, FUN_1417212a0, 37, 0xF8895DB9);

// @0x141721c50
void CSceneStateGame::FUN_141721c50(CInPacket& packet)
{
    if (FUN_14097a780() != 0)
        FUN_14097a780()->FUN_140ae2e90(packet);
}
MS2_REPLACE_METHOD(0x141721c50, CSceneStateGame, FUN_141721c50, 47, 0xF8C8662A);

// @0x141721c90
void CSceneStateGame::FUN_141721c90(CInPacket& packet)
{
    if (FUN_140a6a830() != 0)
        FUN_140a6a830()->FUN_140a2f730(packet);
}
MS2_REPLACE_METHOD(0x141721c90, CSceneStateGame, FUN_141721c90, 47, 0x45BF210A);

// @0x141731ac0
void CSceneStateGame::FUN_141731ac0(CInPacket& packet)
{
    FUN_1409c4b20()->FUN_1405322b0(packet);
}
MS2_REPLACE_METHOD(0x141731ac0, CSceneStateGame, FUN_141731ac0, 37, 0x0832EFFE);

// @0x141731af0
void CSceneStateGame::FUN_141731af0(CInPacket& packet)
{
    FUN_140535310()->FUN_140612850(packet);
}
MS2_REPLACE_METHOD(0x141731af0, CSceneStateGame, FUN_141731af0, 37, 0x324CBB58);

// @0x141732ac0
void CSceneStateGame::FUN_141732ac0(CInPacket& packet)
{
    FUN_14109a700()->FUN_14127e250(packet);
}
MS2_REPLACE_METHOD(0x141732ac0, CSceneStateGame, FUN_141732ac0, 37, 0x8634E0BC);

// @0x141732af0
void CSceneStateGame::FUN_141732af0(CInPacket& packet)
{
    FUN_1409eed60()->FUN_14127e550(packet);
}
MS2_REPLACE_METHOD(0x141732af0, CSceneStateGame, FUN_141732af0, 37, 0x8D93BFEE);

// @0x141734c70
void CSceneStateGame::FUN_141734c70(CInPacket& packet)
{
    FUN_140953f20()->FUN_140cd9840(packet);
}
MS2_REPLACE_METHOD(0x141734c70, CSceneStateGame, FUN_141734c70, 37, 0x3370C6DF);

// @0x1417353b0
void CSceneStateGame::FUN_1417353b0(CInPacket& packet)
{
    FUN_140c8dac0()->FUN_140d061b0(packet);
}
MS2_REPLACE_METHOD(0x1417353b0, CSceneStateGame, FUN_1417353b0, 37, 0x814EE860);

// @0x141722f70
void CSceneStateGame::FUN_141722f70(CInPacket& packet)
{
    Unk_SSGDlg4e4c* pDlg = FUN_140e01890(0x4e4c);
    if (pDlg != 0)
        pDlg->FUN_1419f5e90(packet);
}
MS2_REPLACE_METHOD(0x141722f70, CSceneStateGame, FUN_141722f70, 57, 0x8318DC96);

// @0x141723260
void CSceneStateGame::FUN_141723260(CInPacket& packet)
{
    Unk_SSGDlg4e52* pDlg = FUN_14136f290(0x4e52);
    if (pDlg != 0)
        pDlg->FUN_141908290(packet);
}
MS2_REPLACE_METHOD(0x141723260, CSceneStateGame, FUN_141723260, 57, 0x8F3BC42A);

// @0x141731160
void CSceneStateGame::FUN_141731160(CInPacket& packet)
{
    FUN_1409331e0()->FUN_14138b280(packet);
}
MS2_REPLACE_METHOD(0x141731160, CSceneStateGame, FUN_141731160, 37, 0x18BEB48B);

// @0x1417343c0
void CSceneStateGame::FUN_1417343c0(CInPacket& packet)
{
    FUN_1403ed2d0()->FUN_141bca220();
}
MS2_REPLACE_METHOD(0x1417343c0, CSceneStateGame, FUN_1417343c0, 32, 0xFBF9896B);

// @0x141734930
void CSceneStateGame::FUN_141734930(CInPacket& packet)
{
}

// @0x1417353e0
void CSceneStateGame::FUN_1417353e0(CInPacket& packet)
{
    FUN_1403ed2d0()->FUN_141bca6d0(packet);
}
MS2_REPLACE_METHOD(0x1417353e0, CSceneStateGame, FUN_1417353e0, 37, 0xAEE8CE21);

// @0x141735410
void CSceneStateGame::FUN_141735410(CInPacket& packet)
{
    FUN_140930fe0(packet);
}
MS2_REPLACE_METHOD(0x141735410, CSceneStateGame, FUN_141735410, 29, 0x1B221102);

// @0x14173a0d0
void CSceneStateGame::FUN_14173a0d0(CInPacket& packet)
{
}

// @0x14173a5b0
void CSceneStateGame::FUN_14173a5b0(CInPacket& packet)
{
    FUN_140ad4b90()->FUN_141861f60(packet);
}
MS2_REPLACE_METHOD(0x14173a5b0, CSceneStateGame, FUN_14173a5b0, 37, 0xDB58DC13);

// @0x14171a5f0
void CSceneStateGame::FUN_14171a5f0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    __int64 nB = (unsigned int)static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGCubeObj* pObj = FUN_1403ed2d0()->FUN_141bd13a0(nId);
    if (pObj == 0)
        return;
    pObj->FUN_140b107f0(nA);
    pObj->FUN_140b10a10(nB);
}
MS2_REPLACE_METHOD(0x14171a5f0, CSceneStateGame, FUN_14171a5f0, 197, 0x64D7F3EC);

// @0x14171a6c0
void CSceneStateGame::FUN_14171a6c0(CInPacket& packet)
{
    DAT_143ab2900 = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGDlg4e28* pDlg = FUN_140938b90(0x4e28);
    if (pDlg != 0)
        pDlg->FUN_141939620();
}
MS2_REPLACE_METHOD(0x14171a6c0, CSceneStateGame, FUN_14171a6c0, 92, 0x4986CD7D);

// @0x14171aa90
void CSceneStateGame::FUN_14171aa90(CInPacket& packet)
{
    int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_14152a2f0(n);
}
MS2_REPLACE_METHOD(0x14171aa90, CSceneStateGame, FUN_14171aa90, 99, 0x3346EE17);

// @0x14172f1c0
void CSceneStateGame::FUN_14172f1c0(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141523bc0()->FUN_141765de0();
}
MS2_REPLACE_METHOD(0x14172f1c0, CSceneStateGame, FUN_14172f1c0, 65, 0xDA4F33D3);

// @0x14172f480
void CSceneStateGame::FUN_14172f480(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_140c25130()->FUN_140ca9e90(packet);
}
MS2_REPLACE_METHOD(0x14172f480, CSceneStateGame, FUN_14172f480, 120, 0xAF5B8007);

// @0x1417316d0
void CSceneStateGame::FUN_1417316d0(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141661370(1, *FUN_1401d3200()->m_3680.FUN_1402056b0(), 100000005);
}
MS2_REPLACE_METHOD(0x1417316d0, CSceneStateGame, FUN_1417316d0, 90, 0xE19EC5E4);

// @0x1417337c0
void CSceneStateGame::FUN_1417337c0(CInPacket& packet)
{
    int n = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (FUN_1403ed2b0()->FUN_141adc940(0x4ea2) != 0)
        FUN_1403ed2b0()->FUN_141adc530(0x4ea2);
    UIAutoReviveCountDownDialog* pDlg = Unk_SSGGetDialog<UIAutoReviveCountDownDialog>(0x4ea2);
    if (pDlg != 0)
        pDlg->FUN_141284d70(n);
}
MS2_REPLACE_METHOD(0x1417337c0, CSceneStateGame, FUN_1417337c0, 134, 0x0C0969CE);

// @0x141734b20
void CSceneStateGame::FUN_141734b20(CInPacket& packet)
{
    UIGlobalPortalDialog* pDlg = Unk_SSGGetDialog<UIGlobalPortalDialog>(0x4ed7);
    if (pDlg == 0)
        return;
    pDlg->FUN_1412c3020(packet);
}
MS2_REPLACE_METHOD(0x141734b20, CSceneStateGame, FUN_141734b20, 59, 0x0FB46947);

// @0x141734b70
void CSceneStateGame::FUN_141734b70(CInPacket& packet)
{
    UIQuizDialog* pDlg = Unk_SSGGetDialog<UIQuizDialog>(0x4ee1);
    if (pDlg == 0)
        return;
    pDlg->FUN_14129a930(packet);
}
MS2_REPLACE_METHOD(0x141734b70, CSceneStateGame, FUN_141734b70, 59, 0x27EDF9AF);

// @0x141734bc0
void CSceneStateGame::FUN_141734bc0(CInPacket& packet)
{
    CString strUrl = static_cast<CInputStream&>(packet).vfunc_o8_6();
    if (strUrl.GetLength() < 1)
        return;
    FUN_141276180(strUrl, "");
}
MS2_REPLACE_METHOD(0x141734bc0, CSceneStateGame, FUN_141734bc0, 155, 0x8BD553A5);

// @0x141737360
void CSceneStateGame::FUN_141737360(CInPacket& packet)
{
    FUN_140931510()->FUN_140d9f2c0()->FUN_140b20be0(packet);
}
MS2_REPLACE_METHOD(0x141737360, CSceneStateGame, FUN_141737360, 95, 0x096233CB);

// @0x141737d60
void CSceneStateGame::FUN_141737d60(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141523bc0()->FUN_141767ae0(packet);
}
MS2_REPLACE_METHOD(0x141737d60, CSceneStateGame, FUN_141737d60, 70, 0x9CE84DE8);

// @0x1417380c0
void CSceneStateGame::FUN_1417380c0(CInPacket& packet)
{
    if (FUN_140302b10() == 0)
        return;
    if (DAT_143ab2918 != 0)
        return;
    FUN_140302b10()->FUN_1404c18c0(packet);
    FUN_1407476c0()->FUN_14074ee30();
    DAT_143ab2918 = 1;
}
MS2_REPLACE_METHOD(0x1417380c0, CSceneStateGame, FUN_1417380c0, 83, 0x2B6EC18E);

// @0x141738240
void CSceneStateGame::FUN_141738240(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x141738240, CSceneStateGame, FUN_141738240, 60, 0xBCDE2DFF);

// @0x141738ad0
void CSceneStateGame::FUN_141738ad0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    pNpc->FUN_141092c50(packet);
}
MS2_REPLACE_METHOD(0x141738ad0, CSceneStateGame, FUN_141738ad0, 104, 0x158C510C);

// @0x141739880
void CSceneStateGame::FUN_141739880()
{
    if (m_nTaxiEffect == 0)
        return;
    FUN_1403ed280()->FUN_1411a6060(m_nTaxiEffect);
    m_nTaxiEffect = 0;
}
MS2_REPLACE_METHOD(0x141739880, CSceneStateGame, FUN_141739880, 60, 0xCFA8D3E8);

// @0x1417398d0
void CSceneStateGame::FUN_1417398d0()
{
    UIIndividualPvPDialog* pDlg = Unk_SSGGetDialog<UIIndividualPvPDialog>(0x4ed1);
    if (pDlg != 0)
    {
        pDlg->FUN_1412cacc0();
        pDlg->FUN_1412cb220();
    }
}
MS2_REPLACE_METHOD(0x1417398d0, CSceneStateGame, FUN_1417398d0, 57, 0x29BCBD60);

// @0x14173b1d0
void CSceneStateGame::FUN_14173b1d0(CInPacket& packet)
{
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    DAT_143ab2950 = nValue;
}
MS2_REPLACE_METHOD(0x14173b1d0, CSceneStateGame, FUN_14173b1d0, 67, 0x30E383DD);

// @0x14173c090
void CSceneStateGame::FUN_14173c090(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 1:
        FUN_14173c0f0(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14173c090, CSceneStateGame, FUN_14173c090, 90, 0x95D6D254);

// @0x14173ddf0
void CSceneStateGame::FUN_14173ddf0(CInPacket& packet)
{
}

// @0x14173e440
void CSceneStateGame::FUN_14173e440(CInPacket& packet)
{
    FUN_140931510()->FUN_140d9f8f0()->FUN_140a3a700(packet);
}
MS2_REPLACE_METHOD(0x14173e440, CSceneStateGame, FUN_14173e440, 95, 0x9668CF92);

// @0x14173e4b0
void CSceneStateGame::FUN_14173e4b0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        FUN_140e146f0(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14173e4b0, CSceneStateGame, FUN_14173e4b0, 87, 0xEB0B5C95);

// @0x14173f7c0
void CSceneStateGame::FUN_14173f7c0(CInPacket& packet)
{
    DAT_143ab2943 = static_cast<CInputStream&>(packet).vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x14173f7c0, CSceneStateGame, FUN_14173f7c0, 59, 0x3565632F);

// @0x14173f810
void CSceneStateGame::FUN_14173f810(CInPacket& packet)
{
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC != 0)
        pMyPC->FUN_141528c30(packet);
}
MS2_REPLACE_METHOD(0x14173f810, CSceneStateGame, FUN_14173f810, 60, 0xDC170DA8);

// @0x14173fc00
void CSceneStateGame::FUN_14173fc00(CInPacket& packet)
{
    if (FUN_1414a5830() != 0)
        FUN_1414a5830()->FUN_140a46b90(packet);
}
MS2_REPLACE_METHOD(0x14173fc00, CSceneStateGame, FUN_14173fc00, 47, 0xF0AACA5F);

// @0x14171c0b0
void CSceneStateGame::FUN_14171c0b0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        FUN_14171c1d0(packet);
        break;
    case 1:
        FUN_14171cdf0(packet);
        break;
    case 3:
        FUN_14171d610(packet);
        break;
    case 4:
        FUN_14171d820(packet);
        break;
    case 5:
        FUN_14171dc40(packet);
        break;
    case 6:
        FUN_14171e440(packet);
        break;
    case 7:
        FUN_14171e860(packet);
        break;
    case 8:
        FUN_14171e9a0(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14171c0b0, CSceneStateGame, FUN_14171c0b0, 237, 0x1D3E61F8);

// @0x141721940
void CSceneStateGame::FUN_141721940(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nState = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    pPC->vfunc_59(nState, 0, 0, 0);
    if (nState == 12)
        pPC->vfunc_137();
    else
        pPC->vfunc_59(nState, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x141721940, CSceneStateGame, FUN_141721940, 232, 0x5ADFE327);

// @0x141722fb0
void CSceneStateGame::FUN_141722fb0(CInPacket& packet)
{
    __int64 nSkillId = (unsigned int)static_cast<CInputStream&>(packet).vfunc_o8_3();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    State* pState = pMyPC->FUN_14166ccb0();
    if (pState != 0)
    {
        pMyPC->FUN_141670700(10, nSkillId);
        FUN_140aa6d40()->FUN_141b0ce20(2, 0);
    }
}
MS2_REPLACE_METHOD(0x141722fb0, CSceneStateGame, FUN_141722fb0, 152, 0x8674E8E3);

// @0x1417232a0
void CSceneStateGame::FUN_1417232a0(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
    {
        unsigned char nValue = static_cast<CInputStream&>(packet).vfunc_o8_1();
        FUN_140930150(nValue);
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x1417232a0, CSceneStateGame, FUN_1417232a0, 127, 0x2183B5C9);

// @0x141723330
void CSceneStateGame::FUN_141723330(CInPacket& packet)
{
    int nNpcId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->vfunc_59(0x46, new StateDataTriggerFollowNpc(nNpcId), 0, 0);
}
MS2_REPLACE_METHOD(0x141723330, CSceneStateGame, FUN_141723330, 203, 0x0195DA6E);

// @0x1417235a0
void CSceneStateGame::FUN_1417235a0(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    CubeItemInfo info(packet);
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    if (pPC->FUN_1416595d0() != 0)
    {
        Unk_PCCubeCraft* pCraft = pPC->FUN_141659700();
        if (pCraft != 0)
            pCraft->FUN_1410aa5c0(&info);
    }
}
MS2_REPLACE_METHOD(0x1417235a0, CSceneStateGame, FUN_1417235a0, 202, 0x35B1E1B2);

// @0x14172a7b0
void CSceneStateGame::FUN_14172a7b0(CInPacket& packet)
{
    CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
    FUN_1403ed2d0()->FUN_141bc92e0(strName);
}
MS2_REPLACE_METHOD(0x14172a7b0, CSceneStateGame, FUN_14172a7b0, 140, 0x6F42AED7);

// @0x14172a850
void CSceneStateGame::FUN_14172a850(CInPacket& packet)
{
    CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
    FUN_1403ed2d0()->FUN_141bc9480(strName);
}
MS2_REPLACE_METHOD(0x14172a850, CSceneStateGame, FUN_14172a850, 140, 0xE3DF6E2B);

// @0x141731610
void CSceneStateGame::FUN_141731610(CInPacket& packet)
{
    CAtlArray<unsigned int> arrIds;
    FUN_1403d7440(packet, arrIds);
    if (arrIds.IsEmpty())
        return;
    for (unsigned int i = 0; i < arrIds.GetCount(); i++)
        DAT_143ab3058.FUN_1401855a0(arrIds[i]);
}
MS2_REPLACE_METHOD(0x141731610, CSceneStateGame, FUN_141731610, 181, 0x2EBB1C24);

// @0x141731b20
void CSceneStateGame::FUN_141731b20(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 7:
    {
        int nResult = static_cast<CInputStream&>(packet).vfunc_o8_3();
        switch (nResult)
        {
        case 1:
            DAT_143ab284b = 1;
            FUN_140714f90()->FUN_1415388a0();
            FUN_140aa6d30()->FUN_1417e25a0(0x6200009);
            FUN_140d73bc0(0x27, 0, 0, DAT_143ae79f0);
            break;
        }
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x141731b20, CSceneStateGame, FUN_141731b20, 226, 0x7BCCAB8F);

// @0x141736880
void CSceneStateGame::FUN_141736880(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    bool bFlag = FUN_14028d780(static_cast<CInputStream&>(packet).vfunc_o8_1());
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    if (bFlag)
        pPC->FUN_141661ba0(1);
    pPC->vfunc_137();
}
MS2_REPLACE_METHOD(0x141736880, CSceneStateGame, FUN_141736880, 178, 0x4A0A130E);

// @0x141738290
void CSceneStateGame::FUN_141738290(CInPacket& packet)
{
    __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141662850(nValue);
    DAT_143ab2d80.FUN_140de2a00();
    FUN_1403ed2b0()->FUN_141adc530(0x4e47);
    Unk_SSGDlg4e47* pDlg = FUN_140de48d0(0x4e47);
    if (pDlg != 0)
        pDlg->FUN_141b10ba0(1);
    Unk_SSGDlg4ed8* pDlg2 = FUN_140bbea00(0x4ed8);
    if (pDlg2 != 0)
        pDlg2->FUN_1412c5330(*FUN_1401d3200()->m_66d0.FUN_1401d7c10());
}
MS2_REPLACE_METHOD(0x141738290, CSceneStateGame, FUN_141738290, 226, 0xEA7CE9F9);

// @0x141738380
void CSceneStateGame::FUN_141738380(CInPacket& packet)
{
    __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMyPC == 0)
        return;
    pMyPC->FUN_141662890(nValue);
    Unk_SSGDlg4ed8* pDlg = FUN_140bbea00(0x4ed8);
    if (pDlg != 0)
        pDlg->FUN_1412c54e0(*FUN_1401d3200()->m_67e0.FUN_1401d7c10());
}
MS2_REPLACE_METHOD(0x141738380, CSceneStateGame, FUN_141738380, 155, 0xA0FA9FF3);

// @0x14173a370
void CSceneStateGame::FUN_14173a370(CInPacket& packet)
{
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    bool bFlag = static_cast<CInputStream&>(packet).vfunc_o8_0();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (FUN_1409478c0() != 0)
        FUN_1409478c0()->FUN_140aecbb0(nA, nB, bFlag);
}
MS2_REPLACE_METHOD(0x14173a370, CSceneStateGame, FUN_14173a370, 170, 0x0E98F324);

// @0x14173a990
void CSceneStateGame::FUN_14173a990(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 2:
        FUN_14173aa10(packet);
        break;
    case 0:
        FUN_14173ad60(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x14173a990, CSceneStateGame, FUN_14173a990, 116, 0x91EABDAC);

// @0x14173b380
void CSceneStateGame::FUN_14173b380(CInPacket& packet)
{
    CString strName = static_cast<CInputStream&>(packet).vfunc_o8_7();
    FUN_1403ed2b0()->FUN_141ad9a60(strName);
}
MS2_REPLACE_METHOD(0x14173b380, CSceneStateGame, FUN_14173b380, 140, 0x9A5D042E);

// @0x14173c7a0
void CSceneStateGame::FUN_14173c7a0(CInPacket& packet)
{
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode == 1)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        __int64 nValue = static_cast<CInputStream&>(packet).vfunc_o8_4();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC != 0)
            pPC->FUN_141660000(nValue);
    }
}
MS2_REPLACE_METHOD(0x14173c7a0, CSceneStateGame, FUN_14173c7a0, 189, 0x0673F946);

// @0x14173de10
void CSceneStateGame::FUN_14173de10(CInPacket& packet)
{
    __int64 nUid = static_cast<CInputStream&>(packet).vfunc_o8_4();
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    Unk_NiPoint3 kPos(static_cast<CInputStream&>(packet).vfunc_o8_10());
    Unk_SSGDlg4e29* pDlg = FUN_140c9b540(0x4e29);
    if (pDlg != 0)
        pDlg->FUN_141a3b130(nUid, nType, kPos);
}
MS2_REPLACE_METHOD(0x14173de10, CSceneStateGame, FUN_14173de10, 217, 0x968A66BC);

// @0x14173def0
void CSceneStateGame::FUN_14173def0(CInPacket& packet)
{
    int nType = static_cast<CInputStream&>(packet).vfunc_o8_1();
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    CStringW strText = static_cast<CInputStream&>(packet).vfunc_o8_8();
    if (FUN_140166440() != 0)
        FUN_140166440()->FUN_1401859c0(nType, nValue, strText);
}
MS2_REPLACE_METHOD(0x14173def0, CSceneStateGame, FUN_14173def0, 215, 0x136244C6);

// @0x14173e510
void CSceneStateGame::FUN_14173e510(CInPacket& packet)
{
    int nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    if (nMode != 4)
        return;
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGChatDialog* pDlg = FUN_140938cd0(0x4e5d);
    if (pDlg != 0)
        pDlg->FUN_141ac1d10(nValue);
}
MS2_REPLACE_METHOD(0x14173e510, CSceneStateGame, FUN_14173e510, 144, 0xC2688D81);

// @0x14173f0c0
void CSceneStateGame::FUN_14173f0c0(CInPacket& packet)
{
    Unk_SSGMessengerBrowser* pDlg = FUN_140a3ab70(0x4e61);
    if (pDlg == 0)
        return;
    pDlg->FUN_141a265d0();
    unsigned int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (unsigned int i = 0; i < nCount; i++)
    {
        const unsigned int& nId = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        pDlg->FUN_141a26560(nId);
    }
    pDlg->FUN_141a26600();
}
MS2_REPLACE_METHOD(0x14173f0c0, CSceneStateGame, FUN_14173f0c0, 205, 0x3BC94772);

// @0x14173f1a0
void CSceneStateGame::FUN_14173f1a0(CInPacket& packet)
{
    UIUnlimitedEnchantDialog* pDlg = Unk_SSGGetDialog<UIUnlimitedEnchantDialog>(0x4f97);
    if (pDlg == 0)
        return;
    unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (nMode)
    {
    case 0:
        pDlg->FUN_140fb6310(packet);
        break;
    case 1:
        pDlg->FUN_140fb6b00(packet);
        break;
    case 2:
    {
        int nValue = (unsigned short)static_cast<CInputStream&>(packet).vfunc_o8_2();
        pDlg->FUN_140fb6c30(nValue);
        break;
    }
    }
}
MS2_REPLACE_METHOD(0x14173f1a0, CSceneStateGame, FUN_14173f1a0, 206, 0xE5A97C8E);

// @0x14173fe20
int CSceneStateGame::FUN_14173fe20()
{
    if (FUN_14025e7c0()->FUN_14116d950(0x1d, true, 0) && FUN_14025e7c0()->FUN_14116d950(0x38, true, 0)
        && FUN_14025e7c0()->FUN_14116d9c0(0x43, true, 0))
    {
        FUN_14173feb0();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14173fe20, CSceneStateGame, FUN_14173fe20, 126, 0x98F76DA5);

// @0x141740200
void CSceneStateGame::FUN_141740200(const CStringW& strName, int nType)
{
    COutPacket out(0x51, 0);
    out.COutPacket::vfunc_o10_1(0);
    out.COutPacket::vfunc_o10_8(strName);
    out.COutPacket::vfunc_o10_1(nType);
    FUN_140710590(out);
}
MS2_REPLACE_METHOD(0x141740200, CSceneStateGame, FUN_141740200, 118, 0x74A0A5D8);

// @0x14171b630
void CSceneStateGame::FUN_14171b630(CInPacket& packet)
{
    __int64 nNew = static_cast<CInputStream&>(packet).vfunc_o8_4();
    __int64 nDelta = nNew - DAT_143ab2898;
    DAT_143ab2898 = nNew;
    int nValue = static_cast<CInputStream&>(packet).vfunc_o8_3();
    if (nDelta > 0)
    {
        MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPC != 0)
            FUN_140e09140()->FUN_140a05550(pPC->FUN_141656a80(), nDelta);
        FUN_14109a6f0()->FUN_14117e4c0(nDelta);
    }
    FUN_1413612c0(nDelta, nValue);
    FUN_140aa6d40()->FUN_141b0ce20(8, 0);
    FUN_140764020()->FUN_1416ca2f0();
}
MS2_REPLACE_METHOD(0x14171b630, CSceneStateGame, FUN_14171b630, 272, 0xCC9143A6);

// @0x14171e860
void CSceneStateGame::FUN_14171e860(CInPacket& packet)
{
    int nTargetId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nCount = static_cast<CInputStream&>(packet).vfunc_o8_3();
    for (int i = 0; i < nCount; i++)
    {
        int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
        PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
        if (pPC == 0)
            continue;
        if (pPC->FUN_14166c930() == 0x2b)
        {
            Unk_SSGGrabState* pState = static_cast<Unk_SSGGrabState*>(pPC->FUN_14166ccb0());
            if (pState->FUN_141024a30(nTargetId))
                pPC->vfunc_59(1, 0, 0, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x14171e860, CSceneStateGame, FUN_14171e860, 308, 0x3B1A059E);

// @0x141731350
void CSceneStateGame::FUN_141731350(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    Unk_SSGNpc* pNpc = FUN_1403ed2d0()->FUN_141bd1320(nId);
    if (pNpc == 0)
        return;
    CString strEffect = static_cast<CInputStream&>(packet).vfunc_o8_6();
    FUN_1403ed280()->FUN_1411a4f40(strEffect, pNpc->vfunc_18());
}
MS2_REPLACE_METHOD(0x141731350, CSceneStateGame, FUN_141731350, 268, 0xD3681616);

// @0x141733e40
void CSceneStateGame::FUN_141733e40(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned short nA = static_cast<CInputStream&>(packet).vfunc_o8_2();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    pPC->FUN_141661dc0(nA, nB);
    FUN_141a60f00(pPC->FUN_14123c580());
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        Unk_SSGDlg2711* pDlg = FUN_140938c30(0x2711);
        if (pDlg != 0)
            pDlg->FUN_141a5a560();
    }
}
MS2_REPLACE_METHOD(0x141733e40, CSceneStateGame, FUN_141733e40, 262, 0x20BDD114);

// @0x141738120
void CSceneStateGame::FUN_141738120(CInPacket& packet)
{
    bool bPos = static_cast<CInputStream&>(packet).vfunc_o8_0();
    if (bPos)
    {
        int nX = static_cast<CInputStream&>(packet).vfunc_o8_3();
        int nY = static_cast<CInputStream&>(packet).vfunc_o8_3();
        FUN_140cea070()->FUN_140dd86a0(nX, nY);
    }
    else
    {
        unsigned char nMode = static_cast<CInputStream&>(packet).vfunc_o8_0();
        if (nMode == 1)
            FUN_1403ed2b0()->FUN_141add1f0();
        else
            FUN_141275260(static_cast<CInputStream&>(packet).vfunc_o8_3(), 1, 1);
    }
}
MS2_REPLACE_METHOD(0x141738120, CSceneStateGame, FUN_141738120, 279, 0x1DD3407C);

// @0x14171a730
// MS2-FUNCTIONAL: frame 0x88 vs 0xe8 only; shared Unk_EffectQuery (effectquery.h) is declared 0x10 but the 0x140a52ef0 ctor fills 0x70 bytes
void CSceneStateGame::FUN_14171a730(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    int nA = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nB = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int bEffect = pPC->FUN_141661aa0() && nB == 0;
    pPC->FUN_141661a60(nB);
    pPC->FUN_1416619d0(nA);
    void* pHost = FUN_1409613d0(pPC);
    if (pHost != 0)
    {
        if (bEffect)
        {
            Unk_EffectQuery query;
            query.m_strName = FUN_1401d31f0()->m_str358;
            query.m_nObject = FUN_1403ed2d0()->FUN_141bd1a10(pPC);
            query.FUN_140a53190(pPC->FUN_14123c580());
            FUN_1403ed280()->FUN_1411a4a00(&query);
        }
        else if (nB != 0)
        {
            FUN_1409331e0()->FUN_14138bf00(0xe, 0, 0);
        }
    }
}
MS2_REPLACE_METHOD(0x14171a730, CSceneStateGame, FUN_14171a730, 452, 0xFA154A72);

// @0x14171a900
void CSceneStateGame::FUN_14171a900(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nFlag = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor == 0)
        return;
    PC* pPC = FUN_140974230(pActor);
    if (pPC != 0)
        pPC->FUN_141661ba0(nFlag);
    pActor->FUN_14166ce50(0);
    MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pActor == pMyPC)
    {
        pMyPC->vfunc_59(0x18, 0, 0, 0);
        pMyPC->FUN_14152a960();
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e38);
        FUN_140a94350()->vfunc_10(8);
        FUN_1409331e0()->FUN_14138d7e0(0xb, 0);
    }
    if (pPC != 0)
        pPC->FUN_141661370(1, FUN_1401d3200()->m_2970.FUN_140ad5c50(), 100000004);
}
MS2_REPLACE_METHOD(0x14171a900, CSceneStateGame, FUN_14171a900, 393, 0xEF236C66);

// @0x141720c60
// MS2-FUNCTIONAL: code identical; the MS2Ptr<Unk_SSGSkillAttr> copy-ctor COMDAT pairs with the in-range copy 0x1417459d0 (called from 0x141725xxx) instead of 0x140182280
void CSceneStateGame::FUN_141720c60(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int nSkillId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    unsigned short nLevel = static_cast<CInputStream&>(packet).vfunc_o8_2();
    Unk_StreamPoint kPos = static_cast<CInputStream&>(packet).vfunc_o8_10();
    Unk_StreamPoint kDir = static_cast<CInputStream&>(packet).vfunc_o8_10();
    PCBase* pActor = FUN_1403ed2d0()->FUN_141bd1200(nId);
    if (pActor == 0)
        return;
    MS2Ptr<Unk_SSGSkillAttr> spSkill = FUN_1401958b0()->FUN_140aafef0(nSkillId, nLevel);
    if (spSkill == 0)
        return;
    FUN_141469a90()->FUN_141755cd0(pActor, spSkill, kPos, kDir);
}
MS2_REPLACE_METHOD(0x141720c60, CSceneStateGame, FUN_141720c60, 479, 0x10631625);

// @0x141723410
void CSceneStateGame::FUN_141723410(CInPacket& packet)
{
    int nId = static_cast<CInputStream&>(packet).vfunc_o8_3();
    int bHasItem = static_cast<CInputStream&>(packet).vfunc_o8_1();
    PC* pPC = FUN_1403ed2d0()->FUN_141bd1290(nId);
    if (pPC == 0)
        return;
    if (pPC->FUN_14166ce30() != 0)
        return;
    if (bHasItem)
    {
        CubeItemInfo info(packet);
        int nSlot = static_cast<CInputStream&>(packet).vfunc_o8_3();
        pPC->vfunc_135(bHasItem, nSlot, &info);
    }
    else
    {
        pPC->vfunc_135(bHasItem, 0, 0);
    }
    if (FUN_1409613d0(pPC) != 0)
    {
        PCBase* pTarget = FUN_1403ed2d0()->FUN_141bd3620();
        if (pTarget != 0)
            static_cast<Unk_SSGMyPCV*>(pTarget)->vfunc_149();
    }
}
MS2_REPLACE_METHOD(0x141723410, CSceneStateGame, FUN_141723410, 384, 0xE64CE8BE);
