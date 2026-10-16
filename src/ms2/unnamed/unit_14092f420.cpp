// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's account/session state zone: the global block at
// 0x143ab2820..0x143ab34c8 (session flags, wallet currencies, item sound names, slot-use requests) and the free functions
// that read and write it. Not an original file: the exe has no __FILE__ for it, names are inferred from use.
// MS2-UNIT: unit_14092f420
// MS2-RANGE: 0x1400be590-0x1400be790 .text$di
// MS2-RANGE: 0x1400bed10-0x1400befb0 .text$di
// MS2-RANGE: 0x14092f420-0x140935c20 .text$mn
// MS2-RANGE: 0x142c9cc70-0x142c9cd70 .text$yd
// MS2-RANGE: 0x142c9d080-0x142c9d0a0 .text$yd
// MS2-RANGE: 0x142c9d0c0-0x142c9d1c0 .text$yd
// MS2-PIN: ??$forward@U?$pair@H_J@std@@@std@@YA$$QEAU?$pair@H_J@0@AEAU10@@Z 0x140932390 ; hand: callers expect this twin
// MS2-PIN: ??$construct@U?$pair@H_J@std@@U12@@?$_Default_allocator_traits@V?$allocator@U?$pair@H_J@std@@@std@@@std@@SAXAEAV?$allocator@U?$pair@H_J@std@@@1@QEAU?$pair@H_J@1@$$QEAU31@@Z 0x1409321e0 ; hand: callers expect this twin
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@IPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@I@std@@@1@@Z 0x140932640 ; hand: callers expect this twin
// MS2-PIN: ??1CAtlStringMgr@ATL@@UEAA@XZ 0x140932b60 ; hand: callers expect this twin
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@2@_K@Z 0x140935140 ; hand: callers expect this twin
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@2@PEAU32@@Z 0x140934ac0 ; hand: callers expect this twin
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@2@@Z 0x140934900 ; hand: callers expect this twin
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@2@@Z 0x140934da0 ; hand: callers expect this twin
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@SAPEAU?$_Tree_node@IPEAX@2@PEAU32@@Z 0x140934af0 ; hand: callers expect this twin
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x1409349e0 ; hand: callers expect this twin
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x140934e80 ; hand: callers expect this twin
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IVUnk_ALMissionState@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@2@XZ 0x1409347f0 ; hand: callers expect this twin
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140931d80 ; hand: callers expect this twin
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@1@@Z 0x140932600 ; hand: callers expect this twin
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@1@@Z 0x140932280 ; hand: callers expect this twin
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@0@AEAPEAU10@@Z 0x1409320e0 ; hand: callers expect this twin
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@1@AEAPEAU31@@Z 0x140932140 ; hand: callers expect this twin
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@$00@2@XZ 0x140934790 ; hand: callers expect this twin
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@$00@2@XZ 0x1409347a0 ; hand: callers expect this twin
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@IVUnk_ALMissionState@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@XZ 0x1409346e0 ; hand: callers expect this twin
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140931770 ; unique
// MS2-PIN: ??$_Emplace_back@U?$pair@H_J@std@@@?$_Uninitialized_backout_al@PEAU?$pair@H_J@std@@V?$allocator@U?$pair@H_J@std@@@2@@std@@QEAAX$$QEAU?$pair@H_J@1@@Z 0x140931a10 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@@?$_Tree_node@IPEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@PEAU01@@Z 0x140931e10 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@IPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@IPEAX@0@AEAPEAU10@@Z 0x1409320f0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@I@std@@@0@AEAV10@@Z 0x140932130 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@IPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@IPEAX@0@AEAPEAU10@@Z 0x140932360 ; prop
// MS2-PIN: ??$forward@AEBU?$less@I@std@@@std@@YAAEBU?$less@I@0@AEBU10@@Z 0x140932380 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAA@XZ 0x1409327b0 ; unique
// MS2-PIN: ??0?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@QEAA@XZ 0x140932870 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA@XZ 0x140932ab0 ; unique
// MS2-PIN: ??1TextKeyCallbackData@NiControllerSequence@@QEAA@XZ 0x140932b80 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140932cc0 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140932d40 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEAA?AV01@H@Z 0x140932e10 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140932e80 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140932f10 ; prop
// MS2-PIN: ??_GCAtlStringMgr@ATL@@UEAAPEAXI@Z 0x140932fa0 ; prop
// MS2-PIN: ??_GCWin32Heap@ATL@@UEAAPEAXI@Z 0x140932fe0 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VUnk_MapRec@@@@CAXPEAVUnk_MapRec@@@Z 0x1409334e0 ; prop
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IVUnk_ALMissionState@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@2@XZ 0x1409335f0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@XZ 0x1409336b0 ; prop
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXXZ 0x140933940 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@IVUnk_ALMissionState@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@2@@Z 0x1409339b0 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEAAPEAU?$_Tree_node@IPEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@@Z 0x1409340a0 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@U?$pair@H_J@std@@V?$allocator@U?$pair@H_J@std@@@2@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@U?$pair@H_J@std@@@std@@@2@XZ 0x140934710 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@H_J@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@H_J@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$pair@H_J@std@@@2@XZ 0x140934770 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$pair@H_J@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@H_J@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$pair@H_J@std@@@2@XZ 0x140934780 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@XZ 0x1409347b0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIVUnk_ALMissionState@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@2@XZ 0x1409347c0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$pair@H_J@std@@@std@@V?$_Vector_val@U?$_Simple_types@U?$pair@H_J@std@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@U?$pair@H_J@std@@@std@@@2@XZ 0x1409347d0 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@SAPEAU?$_Tree_node@IPEAX@2@PEAU32@@Z 0x140934b50 ; unique
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEBAAEAPEAU?$_Tree_node@IPEAX@2@XZ 0x140934d40 ; unique
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@QEBAAEAPEAU?$_Tree_node@IPEAX@2@XZ 0x140934d80 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@XZ 0x140935280 ; unique
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXXZ 0x1409353d0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IVUnk_ALMissionState@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@std@@@std@@@2@@Z 0x1409357e0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@V32@0@Z 0x140935890 ; unique
// MS2-PIN: ??__Fg_143ab3128@@YAXXZ 0x142c9cc90 ; unique
// MS2-PIN: ??__Fg_143ab2a90@@YAXXZ 0x142c9ccb0 ; unique
// MS2-PIN: ??__Fg_143ab3150@@YAXXZ 0x142c9cd10 ; unique
// MS2-PIN: ??__Fg_143ab31a0@@YAXXZ 0x142c9cd30 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/chatemoticoncli.h"
#include "ms2/client/ms2/uimainplayerinfo.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/commonfiles/usermail.h"
#include "hook/ms2hook.h"

#include <map>
#include <set>
#include <vector>
#include <utility>

// ---- unit-local stand-ins ---------------------------------------------------------------------------------------------

// The client's object table (0x1403ed2d0): the local player is its first entry.
class Unk_FieldRef;
class Unk_MailSession { public: MS2Ptr<Unk_FieldRef> FUN_141bd30a0(); };
typedef Unk_MailSession Unk_ObjTable;

// The local player (MyPC); only the two slots this zone calls are declared (78: level, 141: a cap).
class Unk_MyPc : public MyPC
{
public:
    virtual void vfunc_124(); virtual void vfunc_125(); virtual void vfunc_126(); virtual void vfunc_127();
    virtual void vfunc_128(); virtual void vfunc_129(); virtual void vfunc_130(); virtual void vfunc_131();
    virtual void vfunc_132(); virtual void vfunc_133(); virtual void vfunc_134(); virtual void vfunc_135();
    virtual void vfunc_136(); virtual void vfunc_137(); virtual void vfunc_138(); virtual void vfunc_139();
    virtual void vfunc_140();
    virtual unsigned vfunc_141();
};
Unk_MyPc* FUN_141bd0cc0(Unk_ObjTable* pTable);

// A learned skill: its record and flags (the skill book hands out MS2Ptr<Unk_SkillObj>).
class Unk_SkillRec { public: char m_pad_00[0xa8]; int m_pad_a8; unsigned char m_pad_ac; bool m_bBlocked; };
class Unk_SkillObj : public CPtred
{
public:
    Unk_SkillRec* FUN_140803e10();
    unsigned char FUN_140804450();
};
class Unk_SkillBook
{
public:
    virtual void vfunc_0();
    virtual MS2Ptr<Unk_SkillObj> vfunc_1(int nSkillId);
    virtual bool vfunc_2(int nSkillId);
};
Unk_SkillBook* FUN_1416546d0(Unk_MyPc* pPc);
unsigned FUN_141525480(Unk_MyPc* pPc, int nSkillId, unsigned char nFlag);

// The "slot in use" restrictions (0x143ab3330).
class Unk_Restrictions { public: int FUN_14138c900(int nKind); };
// The sound/effect sink (0x143ab3328).
class Unk_SoundSink { public: void FUN_14142f470(int nId, int nParam); };
// Three more one-method singletons.
class Unk_Hud { public: virtual void vfunc_0(); virtual void vfunc_1(); };
Unk_Hud* FUN_140933230();
class Unk_BonusBar { };
void FUN_140da55a0(Unk_BonusBar* pBar, unsigned nId, void* pObj);
class Unk_ItemSlotTable { public: int FUN_14087a930(CString strName); };
class Unk_QuestTable { };
void FUN_140663010(Unk_QuestTable* pTable, unsigned nId, unsigned nValue, ATL::CAtlArray<void*>& result);
class Unk_SkillSlots { public: void FUN_14035a870(int nSlot, int nValue); };
class Unk_StatTable { public: };

extern Unk_Restrictions* DAT_143ab3330;
extern Unk_SoundSink* DAT_143ab3328;
extern Unk_QuestTable* DAT_143ab0260;
extern Unk_ItemSlotTable* DAT_143ab1fc8;
extern Unk_BonusBar* DAT_143ab3338;
extern Unk_Hud* DAT_143ab3340;

// ---- data of the zone -------------------------------------------------------------------------------------------------

extern int DAT_1439f4a7c;
extern int DAT_1439f4a80;
extern __int64 DAT_143ab28f0;
extern int DAT_143ab2864;
extern int DAT_143ab2878;
extern int DAT_143ab287c;
extern int DAT_143ab2884;
extern int DAT_143ab2888;
extern bool DAT_143ab2857;
extern __int64 DAT_143ab2938;
extern unsigned short DAT_143ab2940;
extern bool DAT_143ab291e;
extern __int64 DAT_143ab2948;
extern bool DAT_143ab2947;
extern bool DAT_143ab2966;
extern int DAT_143ab2914;
extern unsigned short DAT_143ab291c;
extern __int64 DAT_143ab2920;
extern __int64 DAT_143ab2928;
extern __int64 DAT_143ab2978;
extern __int64 DAT_143ab2980;
extern __int64 DAT_143ab2988;
extern unsigned short DAT_143ab2944;
extern unsigned short DAT_143ab2964;
extern unsigned DAT_143ab2970;

// ---- statics of the zone (constructed by the .text$di initializers) ----------------------------------------------------

enum Unk_SlotKey { };                       // the map key is an enum (so ATL passes it by const reference)
typedef ATL::CAtlMap<Unk_SlotKey, unsigned> Unk_UIntMap;
typedef ATL::CAtlMap<int, int> Unk_IntMapA;
typedef ATL::CAtlMap<unsigned short, int> Unk_IntMapB;
typedef ATL::CAtlArray<void*> Unk_PtrArray;
typedef std::vector<__int64> Unk_Wallet;

// The block is shared with the exe: the hook DLL binds to the exe's objects instead of constructing its own.
#ifdef MS2_HOOK_DLL
#define MS2_ZONE_GLOBAL(type, name) extern type name
#define MS2_ZONE_GLOBAL_INIT(type, name, args) extern type name
#else
#define MS2_ZONE_GLOBAL(type, name) type name
#define MS2_ZONE_GLOBAL_INIT(type, name, args) type name args
#endif

MS2_ZONE_GLOBAL(Unk_UIntMap, g_143ab3220);                                                      // @0x1400be590
MS2_ZONE_GLOBAL(Unk_PtrArray, g_143ab3128);                                                     // @0x1400be5e0
MS2_ZONE_GLOBAL(Unk_Inventory, g_143ab2a90);                                                    // @0x1400be610
MS2_ZONE_GLOBAL(CString, g_143ab2a50);                                                          // @0x1400be640
MS2_ZONE_GLOBAL(CUserMail, g_143ab2ee0);                                                        // @0x1400be670
MS2_ZONE_GLOBAL(Unk_IntMapA, g_143ab3150);                                                      // @0x1400be6a0
MS2_ZONE_GLOBAL(Unk_IntMapB, g_143ab31a0);                                                      // @0x1400be6f0
MS2_ZONE_GLOBAL_INIT(Unk_Wallet, g_143ab2a78, (4, (__int64)0));                                 // @0x1400be740

static CString s_143ab3008("button_click");                                                     // @0x1400bed10
static CString s_143ab2ed8("button_click");                                                     // @0x1400bed40
static CString s_143ab3490[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};   // @0x1400bed70
#include "ms2/placeholder/header_statics_a.h"                                                   // @0x1400bee40..0x1400bef60

// ---- more unit-local stand-ins ----------------------------------------------------------------------------------------

typedef std::vector<std::pair<int, __int64> > Unk_PayList;           // (currency kind, amount) pairs

class Unk_SkillRow : public CPtred { public: unsigned char FUN_1407e9de0(); };
class Unk_SkillTable { public: MS2Ptr<Unk_SkillRow> FUN_1407ee1d0(int nSkillId); };
Unk_SkillTable* FUN_1401958b0();
class Unk_Options { public: bool FUN_14036d570(int nId); };
Unk_Options* FUN_140166410();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
bool FUN_14053e460(CItemData* pData);
int FUN_140526100(CItem* pItem);
void FUN_141275260(int nStringId, int nA, int nB);

class Unk_MapRec : public CPtred { public: char m_pad_18[4]; int m_nKind; };
class Unk_MapTable { public: MS2Ptr<Unk_MapRec> FUN_1403206b0(int nMapId); };
Unk_MapTable* FUN_14031c2a0();

class Unk_PartyRef : public CPtred { };
class Unk_PartyHolder { public: MS2Ptr<Unk_PartyRef> FUN_141768380(); };
Unk_PartyHolder* FUN_141523bc0(Unk_MyPc* pPc);
class Unk_FieldRef : public CPtred { };
unsigned FUN_14166ce30(Unk_MyPc* pPc);
int FUN_141654700(Unk_MyPc* pPc);
unsigned FUN_1403bb210(int nKind, int nMode);
int FUN_14086ace0(__int64 nTime);
bool FUN_14086ab70(CMsTime tmOld, CMsTime tmNew, int nBaseHour);
bool FUN_1406c5200();
__int64 FUN_140869440();

class Unk_NoticeSub { public: virtual void vfunc_0(); virtual unsigned char vfunc_1(); };
class Unk_NoticeSubRef;
class Unk_Notice { public: void* m_pad_00; Unk_NoticeSub m_sub; };
class Unk_NoticeTarget : public CPtred { public: unsigned FUN_14041f250(); };
class Unk_NoticeList
{
public:
    void FUN_14041f6e0();
    void FUN_14041f7c0(Unk_Notice* pNotice);
    MS2Ptr<Unk_NoticeTarget> FUN_14041f850(Unk_Notice* pNotice);
};

class Unk_Misc2d80 { public: void FUN_140de1070(); };
class Unk_Misc2e20 { public: void FUN_1408fbac0(); };
class Unk_Misc2e50 { public: void FUN_140dfc4f0(); };
class Unk_Misc32d8 { public: void FUN_140581e40(); };
// Same layout as the unit-local state of uiadventureleveldialog.cpp (the map global 0x143ab3318 is shared).
class Unk_ALMissionState
{
public:
    void* m_0; void* m_8; void* m_10;
    unsigned int m_18;
    bool m_1c;
};

class Unk_IdList { public: int FUN_140408410(const int& nId); };
class Unk_QuickSlots { };
int FUN_14035a870(Unk_QuickSlots* pSlots, int nSlot, unsigned nValue);
Unk_QuickSlots* FUN_140764010();
void FUN_140d9f140(CChatEmoticonCli* pCli);
CChatEmoticonCli* FUN_140931510();
extern Unk_Restrictions* DAT_143ab3330;
extern Unk_SoundSink* DAT_143ab3328;
extern Unk_QuestTable* DAT_143ab0260;
extern Unk_ItemSlotTable* DAT_143ab1fc8;
extern Unk_BonusBar* DAT_143ab3338;
extern Unk_Hud* DAT_143ab3340;
Unk_Restrictions* FUN_1409331e0();
Unk_SoundSink* FUN_1409331f0();
Unk_QuestTable* FUN_140933200();
Unk_ItemSlotTable* FUN_140933210();
Unk_BonusBar* FUN_140933220();
bool FUN_140930d70();
UIMainPlayerInfo* FUN_140931900(int nUiId);

extern Unk_NoticeList DAT_143ab2fc0;
extern Unk_NoticeList DAT_143ab3010;
extern Unk_Misc2d80 DAT_143ab2d80;
extern Unk_Misc2e20 DAT_143ab2e20;
extern Unk_Misc2e50 DAT_143ab2e50;
extern Unk_Misc32d8 DAT_143ab32d8;
extern std::map<unsigned int, Unk_ALMissionState> g_unkMissionStates;       // 0x143ab3318
extern Unk_IdList DAT_143ab3268;
extern ATL::CAtlArray<unsigned> DAT_143ab32b8;

class Unk_UiManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nUiId); };
Unk_UiManager* FUN_1403ed2b0();

void FUN_141276180(const CString& strSound, const CString& strArg);

// ---- functions --------------------------------------------------------------------------------------------------------

// @0x14092f420
void FUN_14092f420()
{
    FUN_140d9f140(FUN_140931510());
    DAT_143ab2d80.FUN_140de1070();
    g_143ab2a90.FUN_140a5c970();
    DAT_143ab2fc0.FUN_14041f6e0();
    DAT_143ab3010.FUN_14041f6e0();
    DAT_143ab2e20.FUN_1408fbac0();
    DAT_143ab2e50.FUN_140dfc4f0();
    DAT_143ab2857 = 0;
    DAT_143ab2938 = 0;
    DAT_143ab32d8.FUN_140581e40();
    DAT_143ab2940 = 0;
    DAT_143ab291e = 0;
    DAT_143ab2948 = 0;
    DAT_143ab2947 = 0;
    DAT_143ab2966 = 0;
    g_unkMissionStates.clear();
}

// @0x14092f4e0
unsigned FUN_14092f4e0(int nSkillId)
{
    if (g_143ab2a90.FUN_140a62d30(nSkillId) != 0)
        return 1;
    Unk_MyPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc != 0)
    {
        Unk_SkillBook* pBook = FUN_1416546d0(pPc);
        if (pBook->vfunc_2(nSkillId))
        {
            MS2Ptr<Unk_SkillObj> spSkill = FUN_1416546d0(pPc)->vfunc_1(nSkillId);
            if (spSkill.get() != 0)
            {
                if (spSkill->FUN_140803e10()->m_bBlocked)
                    return 0;
                return FUN_141525480(pPc, nSkillId, spSkill->FUN_140804450());
            }
            return FUN_141525480(pPc, nSkillId, 1);
        }
    }
    return 0;
}

// @0x14092f640
int FUN_14092f640()
{
    if (DAT_1439f4a7c == 0)
        return DAT_1439f4a80;
    return DAT_1439f4a7c;
}

// @0x14092f660
bool FUN_14092f660()
{
    return DAT_1439f4a7c == 0;
}

// @0x14092f690
// MS2-FUNCTIONAL: stack slot order of the CString("") temp differs (frame 0x10 larger), logic identical
int FUN_14092f690(int nSkillId, int nItemId, __int64 nItemUid, int nSlot, int nKind)
{
    if (FUN_1409331e0()->FUN_14138c900(10))
    {
        FUN_141275260(0x888, 1, 1);
        return 0;
    }
    if (FUN_1409331e0()->FUN_14138c900(11) && nKind != 8)
    {
        FUN_141275260(0x888, 1, 1);
        return 0;
    }
    if (FUN_1409331e0()->FUN_14138c900(12) && nKind != 9)
    {
        FUN_141275260(0x888, 1, 1);
        return 0;
    }
    if (nSkillId != 0)
    {
        MS2Ptr<Unk_SkillRow> spRow = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
        if (spRow.IsNull())
            return 0;
        if (spRow->FUN_1407e9de0())
        {
            FUN_141275260(0x9a7, 1, 1);
            return 0;
        }
        if (FUN_140166410()->FUN_14036d570(0xd3))
        {
            Unk_Inventory::ItemPtr spItem = g_143ab2a90.FUN_140a5e2e0(nItemId);
            if (spItem.get() != 0)
            {
                if (FUN_140526100(spItem.get()) != 0)
                    return 0;
            }
        }
    }
    else
    {
        MS2Ptr<CItemData> spData(0);
        Unk_Inventory::ItemPtr spItem = g_143ab2a90.FUN_140a5d680(nItemUid);
        if (spItem.get() != 0)
            spData.AssignRaw((CItemData*)spItem->FUN_140527840());
        else
            spData = FUN_14053f870(nItemId);
        if (spData == 0)
            return 0;
        if (!FUN_14053e460(spData.get()))
            return 0;
    }
    FUN_141276180(s_143ab2ed8, CString(""));
    if (!FUN_140930d70())
    {
        COutPacket packet(0x3a, 0);
        packet.vfunc_o10_1(3);
        packet.vfunc_o10_2((short)nSlot);
        packet.vfunc_o10_3(nSkillId);
        packet.vfunc_o10_3(nItemId);
        packet.vfunc_o10_4(nItemUid);
        packet.vfunc_o10_3(nKind);
        FUN_140710590(packet);
    }
    return 1;
}

// @0x14092fac0
// MS2-FUNCTIONAL: stack slot order of the CString("") temp differs (frame 0x10 larger), logic identical
int FUN_14092fac0(int nSkillId, int nItemId, __int64 nItemUid, int nSlot)
{
    UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo != 0 && pInfo->FUN_1419f29c0() != 0)
    {
        FUN_141275260(0x9a6, 1, 1);
        return 0;
    }
    if (nSkillId != 0)
    {
        MS2Ptr<Unk_SkillRow> spRow = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
        if (spRow.IsNull())
            return 0;
        if (spRow->FUN_1407e9de0())
        {
            FUN_141275260(0x9a7, 1, 1);
            return 0;
        }
        if (FUN_140166410()->FUN_14036d570(0xd3))
        {
            Unk_Inventory::ItemPtr spItem = g_143ab2a90.FUN_140a5e2e0(nItemId);
            if (spItem.get() != 0)
            {
                if (FUN_140526100(spItem.get()) != 0)
                    return 0;
            }
        }
    }
    else
    {
        MS2Ptr<CItemData> spData(0);
        Unk_Inventory::ItemPtr spItem = g_143ab2a90.FUN_140a5d680(nItemUid);
        if (spItem.get() != 0)
            spData.AssignRaw((CItemData*)spItem->FUN_140527840());
        else
            spData = FUN_14053f870(nItemId);
        if (spData == 0)
            return 0;
        if (!FUN_14053e460(spData.get()))
            return 0;
    }
    if (FUN_1409331e0()->FUN_14138c900(10) == 0 && FUN_1409331e0()->FUN_14138c900(11) == 0 &&
        FUN_1409331e0()->FUN_14138c900(12) == 0)
    {
        FUN_141276180(s_143ab2ed8, CString(""));
        if (!FUN_140930d70())
        {
            COutPacket packet(0x3a, 0);
            packet.vfunc_o10_1(4);
            packet.vfunc_o10_2((short)nSlot);
            packet.vfunc_o10_3(nSkillId);
            packet.vfunc_o10_3(nItemId);
            packet.vfunc_o10_4(nItemUid);
            packet.vfunc_o10_3(-1);
            FUN_140710590(packet);
        }
        return 1;
    }
    FUN_141275260(0x888, 1, 1);
    return 0;
}

// @0x14092fef0
int FUN_14092fef0(int nSkillId, int nItemId, __int64 nItemUid, int nSlot, int nParam)
{
    if (nSkillId == 0 && nItemUid == 0 && nItemId == 0)
        return 0;
    if (FUN_1409331e0()->FUN_14138c900(10) == 0)
    {
        FUN_141276180(s_143ab3008, CString(""));
        if (!FUN_140930d70())
        {
            COutPacket packet(0x3a, 0);
            packet.vfunc_o10_1(5);
            packet.vfunc_o10_2((short)nSlot);
            packet.vfunc_o10_3(nSkillId);
            packet.vfunc_o10_4(nItemUid);
            FUN_140710590(packet);
            FUN_1409331f0()->FUN_14142f470(nSlot, nParam);
        }
        return 1;
    }
    FUN_141275260(0x888, 1, 1);
    return 0;
}

// @0x140930040
int FUN_140930040()
{
    COutPacket packet(0x3a, 0);
    packet.vfunc_o10_1(6);
    FUN_140710590(packet);
    return 1;
}

// @0x1409300a0
int FUN_1409300a0(int nSlot)
{
    COutPacket packet(0x3a, 0);
    packet.vfunc_o10_1(8);
    packet.vfunc_o10_2((short)nSlot);
    FUN_140710590(packet);
    return 1;
}

// @0x140930110
bool FUN_140930110(int nValue)
{
    return DAT_143ab2864 == nValue;
}

// @0x140930150
void FUN_140930150(int nValue)
{
    DAT_143ab2914 = nValue;
    FUN_140933230()->vfunc_1();
}

// @0x140930190
int FUN_140930190()
{
    if (FUN_14086ace0(DAT_143ab2920))
        return 0;
    return 1;
}

// @0x1409301c0
bool FUN_1409301c0()
{
    if (FUN_14086ace0(DAT_143ab2928))
        return false;
    return true;
}

// @0x1409301f0
unsigned FUN_1409301f0()
{
    return 1;
}

// @0x140930200
unsigned char FUN_140930200(int nKind)
{
    int bResult;
    if (nKind != 0 && nKind != 1)
        bResult = 0;
    else
        bResult = 1;
    return bResult;
}

// @0x140930240
__int64 FUN_140930240()
{
    return DAT_143ab2978;
}

// @0x140930250
__int64 FUN_140930250()
{
    return g_143ab2a78[0] + g_143ab2a78[1];
}

// @0x1409302a0
__int64 FUN_1409302a0()
{
    return g_143ab2a78[2];
}

// @0x1409302d0
__int64 FUN_1409302d0()
{
    return g_143ab2a78[3];
}

// @0x140930300
__int64 FUN_140930300()
{
    return g_143ab2a78[0] + g_143ab2a78[1] + g_143ab2a78[3];
}

// @0x140930370
__int64 FUN_140930370()
{
    return g_143ab2a78[0];
}

// @0x140930390
__int64 FUN_140930390(unsigned nMask)
{
    if (nMask == 0)
        return 0;
    if (nMask == 0xffffffff)
        return DAT_143ab2978;
    __int64 nSum = 0;
    if (nMask & 1)
        nSum = nSum + g_143ab2a78[0];
    if (nMask & 2)
        nSum = nSum + g_143ab2a78[1];
    if (nMask & 4)
        nSum = nSum + g_143ab2a78[2];
    if (nMask & 8)
        nSum = nSum + g_143ab2a78[3];
    return nSum;
}

// @0x140930490
__int64 FUN_140930490()
{
    return DAT_143ab28f0;
}

// @0x1409304a0
void FUN_1409304a0(__int64 nValue)
{
    g_143ab2a78[0] = nValue;
}

// @0x1409304d0
void FUN_1409304d0(__int64 n0, __int64 n1, __int64 n2, __int64 n3)
{
    g_143ab2a78[0] = n0;
    g_143ab2a78[1] = n1;
    g_143ab2a78[2] = n2;
    g_143ab2a78[3] = n3;
    DAT_143ab2978 = n0 + n1 + n2 + n3;
}

// @0x140930580
Unk_Wallet* FUN_140930580()
{
    return &g_143ab2a78;
}

void FUN_140931590(Unk_Wallet* pVec, int nKind, __int64 nAmount);

// @0x140930590
bool FUN_140930590(__int64 nAmount, Unk_PayList* pOut)
{
    pOut->clear();
    __int64 nRemain = nAmount;
    if (0 < nAmount)
    {
        Unk_Wallet* pWallet = &g_143ab2a78;
        for (int i = 3; -1 < i; i = i - 1)
        {
            if (FUN_140930200(i) != true)
            {
                if (nRemain <= pWallet->at(i))
                {
                    pOut->push_back(std::pair<int, __int64>(i, nRemain));
                    nRemain = 0;
                    break;
                }
                __int64 nHave = pWallet->at(i);
                if (0 < nHave)
                {
                    nRemain = nRemain - nHave;
                    pOut->push_back(std::pair<int, __int64>(i, nHave));
                }
            }
        }
    }
    __int64 nCash = FUN_140930250();
    if (nRemain < 1 && !pOut->empty())
        return false;
    unsigned nKind = FUN_1409301f0();
    pOut->push_back(std::pair<int, __int64>(nKind, nRemain));
    return nCash < nRemain;
}

bool FUN_140930910(__int64 nAmount, unsigned nMask, Unk_Wallet* pVec);

// @0x140930750
bool FUN_140930750(Unk_PayList* pIn, Unk_PayList* pOut)
{
    pOut->clear();
    if (!pIn->empty())
    {
        Unk_Wallet vecTotals;
        for (int i = 0; i < 4; i = i + 1)
        {
            __int64 nNone = -1;
            vecTotals.push_back(nNone);
        }
        size_t nCount = pIn->size();
        for (size_t j = 0; j < nCount; j = j + 1)
        {
            std::pair<int, __int64>* pEntry = &(*pIn)[j];
            unsigned nMask = pEntry->first;
            FUN_140930910(pEntry->second, nMask, &vecTotals);
        }
        if (!vecTotals.empty())
        {
            size_t k = 0;
            while (k < vecTotals.size())
            {
                if (vecTotals[k] != -1)
                    pOut->push_back(std::pair<int, __int64>(k, vecTotals[k]));
                k = k + 1;
            }
            return true;
        }
        return false;
    }
    return false;
}

// @0x140930910
bool FUN_140930910(__int64 nAmount, unsigned nMask, Unk_Wallet* pVec)
{
    bool bResult;
    if (pVec->size() == 4)
    {
        __int64 nRemain = nAmount;
        if (0 < nAmount)
        {
            for (int i = 3; -1 < i; i = i - 1)
            {
                if (FUN_140930200(i) != true && (FUN_1403bb210(i, 0) & nMask) != 0)
                {
                    if (nRemain <= g_143ab2a78.at(i))
                    {
                        FUN_140931590(pVec, i, nRemain);
                        nRemain = 0;
                        break;
                    }
                    __int64 nHave = g_143ab2a78.at(i);
                    if (0 < nHave)
                    {
                        nRemain = nRemain - nHave;
                        FUN_140931590(pVec, i, nHave);
                    }
                }
            }
        }
        __int64 nCash;
        if (((nMask & 1) == 0 && (nMask & 2) == 0) ||
            ((nCash = FUN_140930250(), nRemain < 1 && !pVec->empty())))
            bResult = false;
        else
        {
            unsigned nKind = FUN_1409301f0();
            FUN_140931590(pVec, nKind, nRemain);
            bResult = nCash < nRemain;
        }
    }
    else
        bResult = false;
    return bResult;
}

// @0x140930ae0
__int64 FUN_140930ae0()
{
    return DAT_143ab2980;
}

// @0x140930af0
void FUN_140930af0(__int64 nValue)
{
    DAT_143ab2980 = nValue;
}

// @0x140930b10
bool FUN_140930b10()
{
    return DAT_143ab2878 != 0;
}

// @0x140930b40
bool FUN_140930b40()
{
    if (DAT_143ab2878 == 2)
        return true;
    if (DAT_143ab287c == 8)
        return true;
    return false;
}

// @0x140930b70
bool FUN_140930b70()
{
    if (DAT_143ab2878 == 2)
        return false;
    if (DAT_143ab287c != 0)
        return false;
    return true;
}

// @0x140930ba0
void FUN_140930ba0(int nMapId)
{
    DAT_143ab2884 = nMapId;
    DAT_143ab2888 = 0;
    MS2Ptr<Unk_MapRec> spMap = FUN_14031c2a0()->FUN_1403206b0(DAT_143ab2884);
    if (spMap.get() != 0)
        DAT_143ab2888 = spMap->m_nKind;
}

// @0x140930c20
bool FUN_140930c20()
{
    return DAT_143ab2888 == 3;
}

// @0x140930c50
unsigned char FUN_140930c50()
{
    int bResult;
    if (DAT_143ab2857 && DAT_143ab2938 != 0)
        bResult = 1;
    else
        bResult = 0;
    return bResult;
}

// @0x140930c90
unsigned char FUN_140930c90(__int64 nId)
{
    int bResult;
    if (DAT_143ab2857 && DAT_143ab2938 == nId)
        bResult = 1;
    else
        bResult = 0;
    return bResult;
}

// @0x140930ce0
unsigned char FUN_140930ce0()
{
    int bResult;
    if (DAT_143ab291e && DAT_143ab2948 != 0)
        bResult = 1;
    else
        bResult = 0;
    return bResult;
}

// @0x140930d20
unsigned char FUN_140930d20(__int64 nId)
{
    int bResult;
    if (DAT_143ab291e && DAT_143ab2948 == nId)
        bResult = 1;
    else
        bResult = 0;
    return bResult;
}

// @0x140930d70
bool FUN_140930d70()
{
    Unk_MyPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    bool bResult = FUN_141523bc0(pPc)->FUN_141768380().get() != 0;
    return bResult;
}

int FUN_140931890(ATL::CAtlArray<unsigned>* pArray, unsigned short* pValue);

// @0x140930e10
int FUN_140930e10()
{
    Unk_MyPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return 0;
    int nCount = 0;
    for (unsigned short nLevel = 1; nLevel <= DAT_143ab291c; nLevel++)
    {
        ATL::CAtlArray<void*> quests;
        int nJob = FUN_141654700(pPc);
        unsigned nLv = nLevel;
        FUN_140663010(FUN_140933200(), nLv, nJob, quests);
        if (quests.GetCount() == 0)
            continue;
        if (FUN_140931890(&DAT_143ab32b8, &nLevel) == -1)
            nCount = nCount + 1;
    }
    return nCount;
}

// @0x140930f20
void FUN_140930f20()
{
    if (!FUN_1406c5200())
        return;
    if (DAT_143ab2988 == 0)
        DAT_143ab2988 = FUN_140869440();
    __int64 nNow = FUN_140869440();
    if (DAT_143ab2988 == nNow)
        return;
    if (FUN_14086ab70(CMsTime(DAT_143ab2988), CMsTime(nNow), 0))
        g_143ab3150.RemoveAll();
    DAT_143ab2988 = nNow;
}

// @0x140930fe0
void FUN_140930fe0(Unk_Notice* pNotice)
{
    int nKind = (&pNotice->m_sub)->vfunc_1();
    switch (nKind)
    {
    case 0:
    {
        int nList = (&pNotice->m_sub)->vfunc_1();
        if (nList == 0)
            DAT_143ab2fc0.FUN_14041f7c0(pNotice);
        else if (nList == 1)
            DAT_143ab3010.FUN_14041f7c0(pNotice);
        break;
    }
    case 1:
    {
        int nList = (&pNotice->m_sub)->vfunc_1();
        MS2Ptr<Unk_NoticeTarget> spTarget;
        if (nList == 0)
            spTarget = DAT_143ab2fc0.FUN_14041f850(pNotice);
        else if (nList == 1)
            spTarget = DAT_143ab3010.FUN_14041f850(pNotice);
        if (spTarget.get() != 0)
        {
            void* pRaw = spTarget.get();
            unsigned nId = spTarget->FUN_14041f250();
            FUN_140da55a0(FUN_140933220(), nId, pRaw);
        }
        break;
    }
    }
}

// @0x140931210
unsigned FUN_140931210(Unk_SlotKey nKey)
{
    unsigned nValue = 0;
    g_143ab3220.Lookup(nKey, nValue);
    return nValue;
}

// @0x140931250
int FUN_140931250(Unk_SlotKey nKey)
{
    int nValue = FUN_140931210(nKey);
    return FUN_14035a870(FUN_140764010(), nKey, (unsigned)nValue);
}

// @0x140931290
int FUN_140931290()
{
    int nBest = 0;
    for (int i = 1; i < 10; i = i + 1)
    {
        int n = FUN_140931250((Unk_SlotKey)i);
        if (nBest < n)
            nBest = n;
    }
    return nBest;
}

// @0x1409312f0
bool FUN_1409312f0()
{
    if (DAT_1439f4a7c == 0)
        return false;
    if (FUN_140930b10())
        return false;
    Unk_MyPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return false;
    if (FUN_14166ce30(pPc))
        return false;
    MS2Ptr<Unk_FieldRef> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField.IsNull())
        return false;
    return true;
}

// @0x1409313b0
unsigned FUN_1409313b0()
{
    Unk_MyPc* pPc = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPc == 0)
        return 0xffffffff;
    unsigned short nLevel = (unsigned short)pPc->vfunc_78();
    unsigned short nCap = (std::max)(DAT_143ab2944, nLevel);
    if (nCap < DAT_143ab2964)
        return 1;
    if (pPc->vfunc_141() < DAT_143ab2970)
        return 2;
    return 0;
}

// @0x140931450
unsigned FUN_140931450(CString strName)
{
    int nSlot = FUN_140933210()->FUN_14087a930(strName);
    if (nSlot == 0)
        return 0;
    return DAT_143ab3268.FUN_140408410(nSlot) != -1;
}

// @0x140931510
CChatEmoticonCli* FUN_140931510()
{
    static CChatEmoticonCli s_emoticons;
    return &s_emoticons;
}

// @0x140931590
void FUN_140931590(Unk_Wallet* pVec, int nKind, __int64 nAmount)
{
    if (nKind < 0 || (int)pVec->size() <= nKind)
        return;
    if ((*pVec)[nKind] >= 0)
    {
        __int64* pSlot = &(*pVec)[nKind];
        *pSlot = *pSlot + nAmount;
    }
    else
        (*pVec)[nKind] = nAmount;
}

// @0x140931890
int FUN_140931890(ATL::CAtlArray<unsigned>* pArray, unsigned short* pValue)
{
    for (int i = 0; i < (int)pArray->GetCount(); i = i + 1)
    {
        if ((*pArray)[i] == (unsigned)*pValue)
            return i;
    }
    return -1;
}

// @0x140931900
UIMainPlayerInfo* FUN_140931900(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spUi = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (spUi.get() != 0)
            return dynamic_cast<UIMainPlayerInfo*>((UIObject*)spUi);
    }
    return 0;
}

// Template glue of the unit's containers (the exe holds the members its callers use; the full instantiation is a superset
// that tools/tplpin.py pairs against the exe).
template class ATL::CAtlMap<Unk_SlotKey, unsigned>;
template class ATL::CAtlMap<int, int>;
template class ATL::CAtlArray<unsigned>;
template class std::map<unsigned int, Unk_ALMissionState>;

// @0x1409331e0
Unk_Restrictions* FUN_1409331e0()
{
    return DAT_143ab3330;
}

// @0x1409331f0
Unk_SoundSink* FUN_1409331f0()
{
    return DAT_143ab3328;
}

// @0x140933200
Unk_QuestTable* FUN_140933200()
{
    return DAT_143ab0260;
}

// @0x140933210
Unk_ItemSlotTable* FUN_140933210()
{
    return DAT_143ab1fc8;
}

// @0x140933220
Unk_BonusBar* FUN_140933220()
{
    return DAT_143ab3338;
}

// @0x140933230
Unk_Hud* FUN_140933230()
{
    return DAT_143ab3340;
}
template class std::set<unsigned int>;
