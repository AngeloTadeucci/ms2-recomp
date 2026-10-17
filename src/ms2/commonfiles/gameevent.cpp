// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The GameEvent subclasses of commonfiles\gameevent.cpp:
// per class a factory (registered by name in the dynamic initializers), the name (vfunc_1), the ctor, the parser of the
// event's string fields (vfunc_2), the packet write / read (vfunc_3 / vfunc_4) and the start / end handlers (vfunc_5 /
// vfunc_6, mostly forwarding to CGameRule). The ctors of the *Context element types and the template glue follow at
// the end of the range; the vftables, ??_G and the implicit dtors are COMDATs of unit_1403e9650.
// MS2-UNIT: commonfiles\gameevent.cpp
// MS2-RANGE: 0x1400b6380-0x1400b8480 .text$di
// MS2-RANGE: 0x1403bb510-0x1403e4a90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@$$QEA_N@Z 0x1403d6e70 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@$$QEA_N@Z 0x1403d71f0 ; prop
// MS2-PIN: ??$?0V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@$$QEAV?$allocator@U?$_Tree_node@IPEAX@std@@@1@@Z 0x1403d7290 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAH@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@HPEAX@1@PEAU21@AEAH@Z 0x1403d84f0 ; prop
// MS2-PIN: ??$_Buynode@AEAU?$pair@$$CBHH@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEAU?$pair@$$CBHH@1@@Z 0x1403d86c0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x1403d87e0 ; unique
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1403d8b30 ; prop
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1403d8c50 ; unique
// MS2-PIN: ??$_Copy_nodes@U_Copy_tag@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEAU21@0U_Copy_tag@01@@Z 0x1403d8d70 ; unique
// MS2-PIN: ??$_Insert_at@AEAHPEAU?$_Tree_node@HPEAX@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@_NPEAU?$_Tree_node@HPEAX@1@AEAH1@Z 0x1403d9f20 ; prop
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@AEAU?$pair@$$CBHH@1@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x1403dc660 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAHPEAU?$_Tree_node@HPEAX@std@@@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@_N@1@_NAEAHPEAU?$_Tree_node@HPEAX@1@@Z 0x1403ddee0 ; prop
// MS2-PIN: ??$_Insert_nohint@AEBU?$pair@IH@std@@U_Not_a_node_tag@2@@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@@std@@_N@1@_NAEBU?$pair@IH@1@U_Not_a_node_tag@1@@Z 0x1403def20 ; unique
// MS2-PIN: ??$_Insert_nohint@U?$pair@IH@std@@U_Not_a_node_tag@2@@?$_Tree@V?$_Tset_traits@U?$pair@IH@std@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@IH@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@@std@@_N@1@_N$$QEAU?$pair@IH@1@U_Not_a_node_tag@1@@Z 0x1403df740 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x1403e00d0 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@0@AEAPEAU10@@Z 0x1403e0690 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBHH@std@@@std@@YAPEAU?$pair@$$CBHH@0@AEAU10@@Z 0x1403e06c0 ; prop
// MS2-PIN: ??$addressof@U?$pair@IH@std@@@std@@YAPEAU?$pair@IH@0@AEAU10@@Z 0x1403e06d0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@0@AEAV10@@Z 0x1403e06e0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@0@AEAV10@@Z 0x1403e06f0 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEAPEAU31@@Z 0x1403e07b0 ; prop
// MS2-PIN: ??$_Idl_distance@PEAIPEAI@std@@YA_JAEBQEAI0@Z 0x1403e0d50 ; unique
// MS2-PIN: ??$emplace_back@I@?$vector@IV?$allocator@I@std@@@std@@QEAAX$$QEAI@Z 0x1403e0df0 ; unique
// MS2-PIN: ??$emplace_hint@AEBH@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@1@V21@AEBH@Z 0x1403e0ed0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@0@AEAPEAU10@@Z 0x1403e1080 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@0@AEAV10@@Z 0x1403e1110 ; prop
// MS2-PIN: ??$insert@$0A@$0A@@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@_N@1@$$QEAI@Z 0x1403e12b0 ; unique
// MS2-PIN: ??$move@AEAI@std@@YA$$QEAIAEAI@Z 0x1403e13c0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x1403e30c0 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x1403e3150 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@1@@Z 0x1403e3230 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA@XZ 0x1403e3270 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@IH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@1@@Z 0x1403e32b0 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@1@@Z 0x1403e3330 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@1@@Z 0x1403e3390 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@IH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@IH@std@@@std@@@1@@Z 0x1403e3410 ; prop
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@@3@@ATL@@QEAA@II@Z 0x1403e3ba0 ; prop
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@@3@@ATL@@QEAA@II@Z 0x1403e3be0 ; prop
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@@3@@ATL@@IEAA@I@Z 0x1403e3d80 ; prop
// MS2-PIN: ??$forward_as_tuple@$$V@std@@YA?AV?$tuple@$$V@0@XZ 0x1403e40d0 ; prop
// MS2-PIN: ??0SAHotTimeEventContext@@QEAA@XZ 0x1403e4540 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??__Es_sortNames7@@YAXXZ 0x1400b8360
// MS2-PIN: ??__Es_skill@@YAXXZ 0x1400b8420
// MS2-PIN: ??__Es_stun@@YAXXZ 0x1400b8450
// The map<int,int> ctor: symbols.tsv binds the name to 0x1411af7d0, effectservice's map<CString,..> twin (its tree
// ctor forwards less<CStringA>).
// MS2-PIN: ??0?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA@XZ 0x1403e3810
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameevent.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cgamerule.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/gameeventuservaluenametable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The packet stand-ins of the GameEvent slots are the COutputStream / the CInPacket (its CInputStream base at +8).
#define MS2_GE_OUT(out) (*reinterpret_cast<COutputStream*>(out))
#define MS2_GE_IN(in) (*reinterpret_cast<CInputStream*>(&(in)->reader))
#ifdef __clang__
#define MS2_GE_R(in) (reinterpret_cast<Unk_GEReader*>(reinterpret_cast<char*>(in) + 8))
#else
#define MS2_GE_R(in) (&(in)->reader)
#endif

// Out-of-unit helpers.
// Constructor at 0x140316aa0: registers the factory under the name (the by-value CString is destroyed by the callee).
struct Unk_GEFactoryRegistry {
    Unk_GEFactoryRegistry(CStringW name, GameEvent* (*create)());
    char m_pad;
};
// Stream operators of CMsTime (packet.cpp).
Unk_GEOut* FUN_14070fb70(Unk_GEOut* out, const CMsTime* date);
Unk_GEReader* FUN_14070f6b0(Unk_GEReader* in, CMsTime* date);
// ... of CStringW.
Unk_GEOut* FUN_14070fae0(Unk_GEOut* out, const CStringW* str);
Unk_GEReader* FUN_14070f5f0(Unk_GEReader* in, CStringW* str);
// ... of unsigned.
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned value);
CInputStream& FUN_14070f480(CInputStream& in, unsigned& value);
// String field parsers (commonutil).
int FUN_140718200(CStringW* text);                                      // int
int FUN_1407181a0(CStringW* text);
bool FUN_1407183f0(CStringW* text);                                     // bool
void FUN_140274fc0(const CStringW& text, ATL::CAtlArray<unsigned>& ids, const wchar_t* delims);
void FUN_1402928e0(const CStringW& text, ATL::CAtlArray<float>& values, const wchar_t* delims);
void FUN_1401d9a30(const CStringW& text, ATL::CAtlArray<int>& values, const wchar_t* delims);
bool FUN_14081dcd0(int nSaType);                                        // the SA value is a percent
CGameRule* FUN_1401c0d90();                                             // TSingleton<CGameRule>::GetInstance
Unk_140165cf0* FUN_140345b40(TiXmlDocument* pDoc);                      // the document's first child element
Unk_140165cf0* FUN_140345b40(Unk_140165cf0* pNode);                     // first child element
Unk_140165cf0* FUN_1403f0510(Unk_140165cf0* pNode);                     // next sibling element
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);  // the document's first element by name
int FUN_140421810(GameEventUserValueNameTable* table, CStringW name);   // the id of the name
int FUN_1401d9a00(CStringW& text);                                      // a token as int
CShopEventManager* FUN_1403ed2a0();                                     // TSingleton<CShopEventManager>::GetInstance
CGameEventValueManager* FUN_140302b00();                                // TSingleton<CGameEventValueManager>::GetInstance
// The dungeon open period value (gameeventvalue.cpp): registers / removes a dungeon tag's open period.
bool FUN_140427690(Unk_GameEventLockedValue<0x78>* pValue, CStringW strTag, __int64 beginTime, __int64 endTime);
void FUN_140427780(Unk_GameEventLockedValue<0x78>* pValue, CStringW strTag);
// The guild rate values (gameeventvalue.cpp): set / get the event rate.
void FUN_1404234a0(Unk_GameEventLockedValue<0x38>* pValue, int rate);
void FUN_1404235b0(Unk_GameEventLockedValue<0x38>* pValue, int rate);
void FUN_1404236c0(Unk_GameEventLockedValue<0x38>* pValue, int rate);
unsigned FUN_140423670(Unk_GameEventLockedValue<0x38>* pValue);
void FUN_1404237d0(Unk_GameEventLockedValue<0x38>* pValue, int rate);
void FUN_1404238e0(Unk_GameEventLockedValue<0x38>* pValue, int rate);
// ... the mastery reward / reduce and merat market tab values.
void FUN_140423b10(Unk_GameEventLockedValue<0x40>* pValue, int eventId, int rate, const CStringW& str);
void FUN_140423da0(Unk_GameEventLockedValue<0x40>* pValue, int eventId);
void FUN_140424040(Unk_GameEventLockedValue<0x38>* pValue, const CStringW& tab);
void FUN_140424130(Unk_GameEventIntValue* pValue, int rate);
void FUN_1404249f0(Unk_GameEventLockedValue<0x80>* pValue, ATL::CAtlArray<unsigned>& items);
void FUN_140424ae0(Unk_GameEventLockedValue<0x80>* pValue);
// The table attribute readers with a default (adventureleveltablehelper.cpp).
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault);
unsigned FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned nDefault);
bool FUN_1404246b0(Unk_GameEventLockedValue<0x40>* pValue, MS2Ptr<ItemBoxEventContext> spBox);
void FUN_1404247e0(Unk_GameEventLockedValue<0x40>* pValue, MS2Ptr<ItemBoxEventContext> spBox);
// The shut down interact objects (shutdownevent): add / remove one (field id, object id).
void FUN_1407d0420(CShutdownEventInteractObject* pValue, unsigned nFieldId, int nObjectId);
void FUN_1407d04c0(CShutdownEventInteractObject* pValue, unsigned nFieldId, int nObjectId);
unsigned __int64 FUN_140718370(CStringW* text);                         // unsigned __int64
CStringW FUN_140718600(const CStringW& value);                         // copy
// The UGC cube palette (ugccubepalette.cpp): the show-item box.
unsigned FUN_140df20a0(unsigned nArgA, unsigned nArgB);
unsigned FUN_140df2130(CStringW strName, unsigned nArg);
void FUN_140df1f40(unsigned nBox, unsigned nItemId);
void FUN_140df2210(unsigned nBox);
CGuildManager* FUN_1403ed290();                                         // TSingleton<CGuildManager>::GetInstance
// The feature switches (featuremanager): whether feature `nId` is on.
class Unk_GuildFeatures {
public:
    bool FUN_14036d570(int nId);
};
Unk_GuildFeatures* FUN_140166410();
// The common log (FUN_140166440()).
class Unk_CommonLog
{
public:
    void Log(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* message);
};
Unk_CommonLog* FUN_140166440();
Unk_NpcEventTag FUN_14021bc30(const CStringA& name);    // commonenum.cpp
CUIService* FUN_1403ed2b0();

// The event factories (registered by name below each class).
GameEvent* FUN_1403bb510();
GameEvent* FUN_1403bb900();
GameEvent* FUN_1403bc120();
GameEvent* FUN_1403bc220();
GameEvent* FUN_1403bc5c0();
GameEvent* FUN_1403bc920();
GameEvent* FUN_1403bcc50();
GameEvent* FUN_1403bcfa0();
GameEvent* FUN_1403bd3a0();
GameEvent* FUN_1403bd5a0();
GameEvent* FUN_1403bdd40();
GameEvent* FUN_1403bdfb0();
GameEvent* FUN_1403be630();
GameEvent* FUN_1403be9c0();
GameEvent* FUN_1403bec20();
GameEvent* FUN_1403bf1e0();
GameEvent* FUN_1403bf4a0();
GameEvent* FUN_1403bf6f0();
GameEvent* FUN_1403bfa80();
GameEvent* FUN_1403bfe10();
GameEvent* FUN_1403bff70();
GameEvent* FUN_1403c0290();
GameEvent* FUN_1403c0690();
GameEvent* FUN_1403c0990();
GameEvent* FUN_1403c10e0();
GameEvent* FUN_1403c13e0();
GameEvent* FUN_1403c1560();
GameEvent* FUN_1403c1e00();
GameEvent* FUN_1403c2260();
GameEvent* FUN_1403c2b80();
GameEvent* FUN_1403c2d00();
GameEvent* FUN_1403c2f60();
GameEvent* FUN_1403c33f0();
GameEvent* FUN_1403c3ba0();
GameEvent* FUN_1403c40f0();
GameEvent* FUN_1403c4410();
GameEvent* FUN_1403c4680();
GameEvent* FUN_1403c50c0();
GameEvent* FUN_1403c51b0();
GameEvent* FUN_1403c5b40();
GameEvent* FUN_1403c6110();
GameEvent* FUN_1403c65c0();
GameEvent* FUN_1403c68a0();
GameEvent* FUN_1403c6a80();
GameEvent* FUN_1403c6e80();
GameEvent* FUN_1403c70f0();
GameEvent* FUN_1403c7360();
GameEvent* FUN_1403c7640();
GameEvent* FUN_1403c78b0();
GameEvent* FUN_1403c7b20();
GameEvent* FUN_1403c7e80();
GameEvent* FUN_1403c81a0();
GameEvent* FUN_1403c8400();
GameEvent* FUN_1403c8660();
GameEvent* FUN_1403c88d0();
GameEvent* FUN_1403c8b40();
GameEvent* FUN_1403c9190();
GameEvent* FUN_1403c9430();
GameEvent* FUN_1403c9720();
GameEvent* FUN_1403c9b20();
GameEvent* FUN_1403c9d90();
GameEvent* FUN_1403ca200();
GameEvent* FUN_1403ca470();
GameEvent* FUN_1403ca6e0();
GameEvent* FUN_1403cabf0();
GameEvent* FUN_1403cb1c0();
GameEvent* FUN_1403cb6f0();
GameEvent* FUN_1403cbbf0();
GameEvent* FUN_1403cbed0();
GameEvent* FUN_1403cc130();
GameEvent* FUN_1403cc2b0();
GameEvent* FUN_1403cc6c0();
GameEvent* FUN_1403ccaf0();
GameEvent* FUN_1403cd5e0();
GameEvent* FUN_1403cd970();
GameEvent* FUN_1403cdbe0();
GameEvent* FUN_1403ce7c0();
GameEvent* FUN_1403cf130();
GameEvent* FUN_1403cf400();
GameEvent* FUN_1403cf820();
GameEvent* FUN_1403cfb10();
GameEvent* FUN_1403d0090();
GameEvent* FUN_1403d03f0();
GameEvent* FUN_1403d1240();
GameEvent* FUN_1403d13e0();
GameEvent* FUN_1403d1580();
GameEvent* FUN_1403d16f0();
GameEvent* FUN_1403d1960();
GameEvent* FUN_1403d2930();
GameEvent* FUN_1403d3010();
GameEvent* FUN_1403d3570();
GameEvent* FUN_1403d3ae0();
GameEvent* FUN_1403d3f50();
GameEvent* FUN_1403d47f0();
GameEvent* FUN_1403d4e30();
GameEvent* FUN_1403d50e0();
GameEvent* FUN_1403d5350();
GameEvent* FUN_1403d5900();
GameEvent* FUN_1403d5f10();
GameEvent* FUN_1403d6050();
GameEvent* FUN_1403d6980();
GameEvent* FUN_1403d6ae0();

// Shared header statics (sort names, condition strings).
static CStringA s_sortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");

// MS2Ptr streaming (count-free: the pointee's own operator, a fresh object on read).
template <class T> COutputStream& operator<<(COutputStream& out, const MS2Ptr<T>& sp)
{
    out << *sp;
    return out;
}
template <class T> CInputStream& operator>>(CInputStream& in, MS2Ptr<T>& sp)
{
    sp.AssignRaw(new T);
    in >> *sp;
    return in;
}

// CAtlMap streaming: the count, then key / value pairs.
template <class K, class V, class KTraits, class VTraits>
COutputStream& operator<<(COutputStream& out, ATL::CAtlMap<K, V, KTraits, VTraits>& map)
{
    out.vfunc_o10_3((int)map.GetCount());
    for (POSITION pos = map.GetStartPosition(); pos != NULL; map.GetNext(pos))
    {
        FUN_14070f9a0(out, map.GetKeyAt(pos));
        out << map.GetValueAt(pos);
    }
    return out;
}
template <class K, class V, class KTraits, class VTraits>
CInputStream& operator>>(CInputStream& in, ATL::CAtlMap<K, V, KTraits, VTraits>& map)
{
    unsigned nCount = in.vfunc_o8_3();
    for (unsigned i = 0; i < nCount; ++i)
    {
        V value;
        K key;
        FUN_14070f480(in, key) >> value;
        map.SetAt(key, value);
    }
    return in;
}

// CAtlArray streaming: the count, then the elements.
template <class T>
COutputStream& operator<<(COutputStream& out, const ATL::CAtlArray<T>& arr)
{
    out.vfunc_o10_3((int)arr.GetCount());
    for (size_t i = 0; i < arr.GetCount(); i++)
        FUN_14070f9a0(out, arr[i]);
    return out;
}
template <class T>
CInputStream& operator>>(CInputStream& in, ATL::CAtlArray<T>& arr)
{
    unsigned nCount = in.vfunc_o8_3();
    for (unsigned i = 0; i < nCount; i++)
    {
        T value;
        FUN_14070f480(in, value);
        arr.Add(value);
    }
    return in;
}

// The set flavour of the token splitters above (FUN_1401d9a30 & co.): every token, as int, into the set.
template <class T>
void FUN_1403d8040(CStringW& text, std::set<T>& values, const wchar_t* delims)
{
    int nPos = 0;
    CStringW strToken = text.Tokenize(delims, nPos);
    while (!strToken.IsEmpty())
    {
        values.insert(FUN_1401d9a00(strToken));
        strToken = text.Tokenize(delims, nPos);
    }
}

// Count-prefixed streaming of a vector of contexts (their Write / Read members).
template <class T> void operator<<(COutputStream& out, std::vector<MS2Ptr<T> >& vec)
{
    out.vfunc_o10_3((int)vec.size());
    for (typename std::vector<MS2Ptr<T> >::iterator it = vec.begin(); it != vec.end(); it++)
        (*it)->Write(out);
}
template <class T> void operator>>(CInputStream& in, std::vector<MS2Ptr<T> >& vec)
{
    unsigned nCount = in.vfunc_o8_3();
    vec.reserve(nCount);
    for (unsigned i = 0; i < nCount; i++)
    {
        MS2Ptr<T> sp(new T);
        sp->Read(in);
        vec.push_back(sp);
    }
}

// commonutil.h's generic token converter: a type without a converter asserts and stays default-constructed.
template <> inline Unk_DayTime XmlConvert<Unk_DayTime>(const CString& str)
{
    (void)((!!(FALSE)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.h", 159), 0));
    return Unk_DayTime();
}

// An "a,b" attribute into a range (any other token count fails with TIXML_WRONG_TYPE, 2).
template <class T> int XmlValueRange(Unk_140165cf0* pElem, const char* pszName, T& range)
{
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet == 0)
    {
        ATL::CAtlArray<typename T::ValueType> values;
        XmlSplit(str, values, ",");
        if (values.GetCount() != 2)
            return 2;
        range.Init(values[0], values[1]);
    }
    return nRet;
}

// ---- GameEventSaleChat ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleChat(L"GameEventSaleChat", FUN_1403bb510);
#endif
// @0x1403bb510
GameEvent* FUN_1403bb510() { return new GameEventSaleChat; }

// @0x1403bb570
CStringW GameEventSaleChat::vfunc_1() { return CStringW(L"GameEventSaleChat"); }
MS2_REPLACE_METHOD(0x1403BB570, GameEventSaleChat, vfunc_1, 61, 0xDAB9D4B6);

// @0x1403bb5c0
GameEventSaleChat::GameEventSaleChat()
{
    m_d0 = 10000;
    m_d4 = 10000;
    m_d8 = 10000;
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bb650
void GameEventSaleChat::vfunc_2()
{
    m_d4 = FUN_140718200(&m_68);
    m_d8 = FUN_140718200(&m_70);
}
MS2_REPLACE_METHOD(0x1403BB650, GameEventSaleChat, vfunc_2, 70, 0x710F8703);

// @0x1403bb6a0
void GameEventSaleChat::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d4);
    out->WriteInt(m_d8);
}
MS2_REPLACE_METHOD(0x1403BB6A0, GameEventSaleChat, vfunc_3, 88, 0x8512DCB2);

// @0x1403bb700
void GameEventSaleChat::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d4 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BB700, GameEventSaleChat, vfunc_4, 124, 0x5A130818);

// @0x1403bb790
void GameEventSaleChat::vfunc_5() { FUN_1401c0d90()->FUN_140477020(m_id, m_d0, m_d4, m_d8); }
MS2_REPLACE_METHOD(0x1403BB790, GameEventSaleChat, vfunc_5, 74, 0xA2845D21);

// @0x1403bb7e0
void GameEventSaleChat::vfunc_6() { FUN_1401c0d90()->FUN_1404770e0(m_id); }
MS2_REPLACE_METHOD(0x1403BB7E0, GameEventSaleChat, vfunc_6, 35, 0x24F80A7E);

// @0x1403bb810
void FUN_1403bb810() { FUN_1401c0d90()->FUN_140477180(); }
MS2_REPLACE(0x1403BB810, FUN_1403bb810, 22, 0x5F8463DB);
// @0x1403bb830
void FUN_1403bb830() { FUN_1401c0d90()->FUN_140477210(); }
MS2_REPLACE(0x1403BB830, FUN_1403bb830, 22, 0x75EBD94B);
// @0x1403bb850
void FUN_1403bb850() { FUN_1401c0d90()->FUN_1404772a0(); }
MS2_REPLACE(0x1403BB850, FUN_1403bb850, 22, 0xB3D82860);
// @0x1403bb870
unsigned FUN_1403bb870() { return *FUN_1401d3200()->MeratConsumeSuperChat.Get(); }
MS2_REPLACE(0x1403BB870, FUN_1403bb870, 30, 0x8D4E122B);
// @0x1403bb8a0
unsigned FUN_1403bb8a0() { return *FUN_1401d3200()->MeratConsumeWorldChat.Get(); }
MS2_REPLACE(0x1403BB8A0, FUN_1403bb8a0, 30, 0xA8A84703);
// @0x1403bb8d0
unsigned FUN_1403bb8d0() { return *FUN_1401d3200()->MeratConsumeChannelChat.Get(); }
MS2_REPLACE(0x1403BB8D0, FUN_1403bb8d0, 30, 0xAE9B7E9B);

// ---- GameEventSAHotTime ---------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSAHotTime(L"GameEventSAHotTime", FUN_1403bb900);
#endif
// @0x1403bb900
GameEvent* FUN_1403bb900() { return new GameEventSAHotTime; }

// @0x1403bb960
CStringW GameEventSAHotTime::vfunc_1() { return CStringW(L"GameEventSAHotTime"); }
MS2_REPLACE_METHOD(0x1403BB960, GameEventSAHotTime, vfunc_1, 61, 0xDFFD3206);

// @0x1403bb9b0
GameEventSAHotTime::GameEventSAHotTime() : m_e8(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bba50
void GameEventSAHotTime::vfunc_2()
{
    ATL::CAtlArray<unsigned> ids;
    FUN_140274fc0(m_68, ids, L",");
    ATL::CAtlArray<float> values;
    FUN_1402928e0(m_70, values, L",");
    if (ids.GetCount() != values.GetCount())
        return;
    for (unsigned i = 0; i < ids.GetCount(); i++) {
        unsigned id = ids[i];
        if (FUN_14081dcd0(id))
            m_d0[id] = (int)(values[i] * 1000.0f);
        else
            m_d0[id] = (int)values[i];
    }
    m_e0 = m_80;
    m_e0.Replace(L"\\n", L"\n");
}
MS2_REPLACE_METHOD(0x1403BBA50, GameEventSAHotTime, vfunc_2, 512, 0x37C33D68);

// @0x1403bbc60
void GameEventSAHotTime::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_68);
    out->WriteStringW(m_70);
    out->WriteStringW(m_78);
    out->WriteStringW(m_80);
}
MS2_REPLACE_METHOD(0x1403BBC60, GameEventSAHotTime, vfunc_3, 188, 0x924F9839);

// @0x1403bbd30
void GameEventSAHotTime::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_68 = MS2_GE_R(in)->ReadStringW();
    m_70 = MS2_GE_R(in)->ReadStringW();
    m_78 = MS2_GE_R(in)->ReadStringW();
    m_80 = MS2_GE_R(in)->ReadStringW();
    vfunc_2();
}
MS2_REPLACE_METHOD(0x1403BBD30, GameEventSAHotTime, vfunc_4, 498, 0x00EAE5C2);

// @0x1403bbf30
void GameEventSAHotTime::vfunc_5()
{
    MS2Ptr<SAHotTimeEventContext> spContext(new SAHotTimeEventContext);
    spContext->m_18 = m_d0;
    spContext->m_28 = m_e0;
    spContext->m_30 = m_e8;
    FUN_1401c0d90()->FUN_140477360(FUN_1402e1d00(), spContext);
    FUN_1401c0d90()->FUN_14047d820(FUN_1402e1d00(), m_80);
}
MS2_REPLACE_METHOD(0x1403BBF30, GameEventSAHotTime, vfunc_5, 392, 0x94BE1A07);

// @0x1403bc0c0
void GameEventSAHotTime::vfunc_6()
{
    FUN_1401c0d90()->FUN_140477420(FUN_1402e1d00());
    FUN_1401c0d90()->FUN_14047d900(FUN_1402e1d00());
}
MS2_REPLACE_METHOD(0x1403BC0C0, GameEventSAHotTime, vfunc_6, 80, 0xE280C0AD);

// ---- GameEventPCBangSAHotTime ---------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regPCBangSAHotTime(L"GameEventPCBangSAHotTime", FUN_1403bc120);
#endif
// @0x1403bc120
GameEvent* FUN_1403bc120() { return new GameEventPCBangSAHotTime; }

// @0x1403bc180
CStringW GameEventPCBangSAHotTime::vfunc_1() { return CStringW(L"GameEventPCBangSAHotTime"); }
MS2_REPLACE_METHOD(0x1403BC180, GameEventPCBangSAHotTime, vfunc_1, 61, 0xD5AE5269);

// @0x1403bc1d0
GameEventPCBangSAHotTime::GameEventPCBangSAHotTime() { m_e8 = 1; }

// ---- GameEventSaleBeautyShop ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleBeautyShop(L"GameEventSaleBeautyShop", FUN_1403bc220);
#endif
// @0x1403bc220
GameEvent* FUN_1403bc220() { return new GameEventSaleBeautyShop; }

// @0x1403bc280
CStringW GameEventSaleBeautyShop::vfunc_1() { return CStringW(L"GameEventSaleBeautyShop"); }
MS2_REPLACE_METHOD(0x1403BC280, GameEventSaleBeautyShop, vfunc_1, 61, 0xB261509F);

// @0x1403bc2d0
GameEventSaleBeautyShop::GameEventSaleBeautyShop() : m_d4(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bc340
void GameEventSaleBeautyShop::vfunc_2()
{
    m_d0 = FUN_1407181a0(&m_68);
    m_d4 = FUN_140718200(&m_70);
    m_d8 = FUN_1407181a0(&m_78);
}
MS2_REPLACE_METHOD(0x1403BC340, GameEventSaleBeautyShop, vfunc_2, 98, 0x965E1866);

// @0x1403bc3b0
void GameEventSaleBeautyShop::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt(m_d4);
    out->WriteByte((unsigned char)m_d8);
}
MS2_REPLACE_METHOD(0x1403BC3B0, GameEventSaleBeautyShop, vfunc_3, 116, 0xEA691A38);

// @0x1403bc430
void GameEventSaleBeautyShop::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadByte();
}
MS2_REPLACE_METHOD(0x1403BC430, GameEventSaleBeautyShop, vfunc_4, 172, 0x5BC6B538);

// @0x1403bc4f0
void GameEventSaleBeautyShop::vfunc_5()
{
    BOOL bOn = m_d8 ? FALSE : TRUE;
    FUN_1401c0d90()->FUN_140476b40(m_d0, m_d4, bOn);
}
MS2_REPLACE_METHOD(0x1403BC4F0, GameEventSaleBeautyShop, vfunc_5, 95, 0x590385D4);

// @0x1403bc560
void GameEventSaleBeautyShop::vfunc_6()
{
    BOOL bOn = m_d8 ? FALSE : TRUE;
    FUN_1401c0d90()->FUN_140476be0(m_d0, bOn);
}
MS2_REPLACE_METHOD(0x1403BC560, GameEventSaleBeautyShop, vfunc_6, 83, 0x3BB39145);

// ---- GameEventUserCondition -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regUserCondition(L"GameEventUserCondition", FUN_1403bc5c0);
#endif
// @0x1403bc5c0
GameEvent* FUN_1403bc5c0() { return new GameEventUserCondition; }

// @0x1403bc620
CStringW GameEventUserCondition::vfunc_1() { return CStringW(L"GameEventUserCondition"); }
MS2_REPLACE_METHOD(0x1403BC620, GameEventUserCondition, vfunc_1, 61, 0x1E4F1C4B);

// @0x1403bc670
GameEventUserCondition::GameEventUserCondition() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bc6f0
void GameEventUserCondition::vfunc_2()
{
    m_d0 = FUN_140718200(&m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403BC6F0, GameEventUserCondition, vfunc_2, 72, 0x3D34AC18);

// @0x1403bc740
void GameEventUserCondition::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403BC740, GameEventUserCondition, vfunc_3, 101, 0x69E749FB);

// @0x1403bc7b0
void GameEventUserCondition::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403BC7B0, GameEventUserCondition, vfunc_4, 179, 0x9603FC7B);

// @0x1403bc870
void GameEventUserCondition::vfunc_5()
{
    if (m_d0 == 0)
        return;
    FUN_1401c0d90()->FUN_140477f20(m_d0, m_d8);
}
MS2_REPLACE_METHOD(0x1403BC870, GameEventUserCondition, vfunc_5, 119, 0xA883B333);

// @0x1403bc8f0
void GameEventUserCondition::vfunc_6() { FUN_1401c0d90()->FUN_140477fb0(m_d0); }
MS2_REPLACE_METHOD(0x1403BC8F0, GameEventUserCondition, vfunc_6, 38, 0x6A98F778);

// ---- GameEventMesoRevival -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regMesoRevival(L"GameEventMesoRevival", FUN_1403bc920);
#endif
// @0x1403bc920
GameEvent* FUN_1403bc920() { return new GameEventMesoRevival; }

// @0x1403bc980
CStringW GameEventMesoRevival::vfunc_1() { return CStringW(L"GameEventMesoRevival"); }
MS2_REPLACE_METHOD(0x1403BC980, GameEventMesoRevival, vfunc_1, 61, 0xED673EBF);

// @0x1403bc9d0
GameEventMesoRevival::GameEventMesoRevival() : m_d0(false)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bca40
void GameEventMesoRevival::vfunc_2() { m_d0 = FUN_1407183f0(&m_68); }
MS2_REPLACE_METHOD(0x1403BCA40, GameEventMesoRevival, vfunc_2, 42, 0xACBF923C);

// @0x1403bca70
void GameEventMesoRevival::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteBool(m_d0);
}
MS2_REPLACE_METHOD(0x1403BCA70, GameEventMesoRevival, vfunc_3, 61, 0x34D82FAC);

// @0x1403bcac0
void GameEventMesoRevival::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadBool();
}
MS2_REPLACE_METHOD(0x1403BCAC0, GameEventMesoRevival, vfunc_4, 78, 0xD08AD047);

// @0x1403bcb20
void GameEventMesoRevival::vfunc_5()
{
    MS2Ptr<MesoRevivalEventContext> spContext(new MesoRevivalEventContext);
    spContext->m_18 = m_d0;
    FUN_1401c0d90()->FUN_140477bd0(FUN_1402e1d00(), spContext);
}
MS2_REPLACE_METHOD(0x1403BCB20, GameEventMesoRevival, vfunc_5, 233, 0x23BFF202);

// @0x1403bcc10
void GameEventMesoRevival::vfunc_6() { FUN_1401c0d90()->FUN_140477c90(FUN_1402e1d00()); }
MS2_REPLACE_METHOD(0x1403BCC10, GameEventMesoRevival, vfunc_6, 47, 0xB874E1D4);

// ---- GameEventItemBuff ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regItemBuff(L"GameEventItemBuff", FUN_1403bcc50);
#endif
// @0x1403bcc50
GameEvent* FUN_1403bcc50() { return new GameEventItemBuff; }

// @0x1403bccb0
CStringW GameEventItemBuff::vfunc_1() { return CStringW(L"GameEventItemBuff"); }
MS2_REPLACE_METHOD(0x1403BCCB0, GameEventItemBuff, vfunc_1, 61, 0xC4330E28);

// @0x1403bcd00
GameEventItemBuff::GameEventItemBuff() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bcd70
void GameEventItemBuff::vfunc_2()
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_70) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    CStringW strType;
    FUN_140873420(pRoot, "type", strType);
    m_d0 = FUN_140421810(TSingleton<GameEventUserValueNameTable>::GetInstance(), strType);
}

// @0x1403bce90
void GameEventItemBuff::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403BCE90, GameEventItemBuff, vfunc_3, 61, 0x02BF481F);

// @0x1403bcee0
void GameEventItemBuff::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BCEE0, GameEventItemBuff, vfunc_4, 79, 0x4F54C1BA);

// @0x1403bcf40
void GameEventItemBuff::vfunc_5() { FUN_1401c0d90()->FUN_14047a8c0(m_d0); }
MS2_REPLACE_METHOD(0x1403BCF40, GameEventItemBuff, vfunc_5, 38, 0xD20048DD);

// @0x1403bcf70
void GameEventItemBuff::vfunc_6() { FUN_1401c0d90()->FUN_14047a8c0(0); }
MS2_REPLACE_METHOD(0x1403BCF70, GameEventItemBuff, vfunc_6, 29, 0x534100EE);

// ---- GameEventDungeonBonusReward ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regDungeonBonusReward(L"GameEventDungeonBonusReward", FUN_1403bcfa0);
#endif
// @0x1403bcfa0
GameEvent* FUN_1403bcfa0() { return new GameEventDungeonBonusReward; }

// @0x1403bd000
CStringW GameEventDungeonBonusReward::vfunc_1() { return CStringW(L"GameEventDungeonBonusReward"); }
MS2_REPLACE_METHOD(0x1403BD000, GameEventDungeonBonusReward, vfunc_1, 61, 0x00D72C52);

// @0x1403bd050
GameEventDungeonBonusReward::GameEventDungeonBonusReward()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
    m_d0.AssignRaw(new DungeonBonusRewardCtx);
}

// @0x1403bd120
void GameEventDungeonBonusReward::vfunc_2()
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_68) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    Unk_140165cf0* pElem = FUN_140345b40(pRoot);
    if ((m_d0.get() ? true : false) && pElem)
        m_d0->Load(pElem);
}
MS2_REPLACE_METHOD(0x1403BD120, GameEventDungeonBonusReward, vfunc_2, 254, 0x317C6221);

// @0x1403bd230
void GameEventDungeonBonusReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403BD230, GameEventDungeonBonusReward, vfunc_3, 58, 0x2CE714BB);

// @0x1403bd270
void GameEventDungeonBonusReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403BD270, GameEventDungeonBonusReward, vfunc_4, 62, 0xCEC9B3E2);

// @0x1403bd2c0
void GameEventDungeonBonusReward::vfunc_5() { FUN_1401c0d90()->FUN_14047a900(m_d0); }
MS2_REPLACE_METHOD(0x1403BD2C0, GameEventDungeonBonusReward, vfunc_5, 91, 0xA725C0A7);

// @0x1403bd330
void GameEventDungeonBonusReward::vfunc_6() { FUN_1401c0d90()->FUN_14047aa00(m_d0); }
MS2_REPLACE_METHOD(0x1403BD330, GameEventDungeonBonusReward, vfunc_6, 91, 0x977962AF);

// ---- GameEventFreeAirTaxi -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regFreeAirTaxi(L"GameEventFreeAirTaxi", FUN_1403bd3a0);
#endif
// @0x1403bd3a0
GameEvent* FUN_1403bd3a0() { return new GameEventFreeAirTaxi; }

// @0x1403bd400
CStringW GameEventFreeAirTaxi::vfunc_1() { return CStringW(L"GameEventFreeAirTaxi"); }
MS2_REPLACE_METHOD(0x1403BD400, GameEventFreeAirTaxi, vfunc_1, 61, 0x691F423F);

// @0x1403bd450
GameEventFreeAirTaxi::GameEventFreeAirTaxi()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bd4b0
void GameEventFreeAirTaxi::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403BD4B0, GameEventFreeAirTaxi, vfunc_2, 6, 0xA9AF6E37);

// @0x1403bd4c0
void GameEventFreeAirTaxi::vfunc_3(Unk_GEOut* out) { GameEvent::vfunc_3(out); }
MS2_REPLACE_METHOD(0x1403BD4C0, GameEventFreeAirTaxi, vfunc_3, 34, 0xA1F079D6);

// @0x1403bd4f0
void GameEventFreeAirTaxi::vfunc_4(Unk_GEIn* in) { GameEvent::vfunc_4(in); }
MS2_REPLACE_METHOD(0x1403BD4F0, GameEventFreeAirTaxi, vfunc_4, 34, 0x52D23EA6);

// @0x1403bd520
void GameEventFreeAirTaxi::vfunc_5() { FUN_1401c0d90()->FUN_140477dc0(FUN_1402e1d00()); }
MS2_REPLACE_METHOD(0x1403BD520, GameEventFreeAirTaxi, vfunc_5, 47, 0xE1812CAC);

// @0x1403bd560
void GameEventFreeAirTaxi::vfunc_6() { FUN_1401c0d90()->FUN_140477e30(FUN_1402e1d00()); }
MS2_REPLACE_METHOD(0x1403BD560, GameEventFreeAirTaxi, vfunc_6, 47, 0x59FF38BC);

// ---- GameEventOntime ------------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regOntime(L"GameEventOntime", FUN_1403bd5a0);
#endif
// @0x1403bd5a0
GameEvent* FUN_1403bd5a0() { return new GameEventOntime; }

// @0x1403bd600
CStringW GameEventOntime::vfunc_1() { return CStringW(L"GameEventOntime"); }
MS2_REPLACE_METHOD(0x1403BD600, GameEventOntime, vfunc_1, 61, 0xB2D5BB00);

// @0x1403bd650
GameEventOntime::GameEventOntime()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bd6c0
void GameEventOntime::vfunc_2()
{
    m_d0 = 0;
    const int nValueCount = 7;
    int nType = FUN_1407181a0(&m_68);
    ATL::CAtlArray<int> first;
    ATL::CAtlArray<int> second;
    FUN_1401d9a30(m_70, first, L",");
    FUN_1401d9a30(m_78, second, L",");
    if (first.GetCount() != nValueCount || second.GetCount() != nValueCount)
        return;
    m_d0.AssignRaw(new OntimeEventContext);
    m_d0->m_18 = FUN_1402e1d00();
    m_d0->m_20 = nType;
    m_d0->m_24.m_0 = first[0];
    m_d0->m_24.m_4 = first[1];
    m_d0->m_24.m_8 = first[2];
    m_d0->m_24.m_10 = first[3];
    m_d0->m_24.m_c = first[4];
    m_d0->m_24.m_14 = first[5];
    m_d0->m_24.m_18 = first[6];
    m_d0->m_40.m_0 = second[0];
    m_d0->m_40.m_4 = second[1];
    m_d0->m_40.m_8 = second[2];
    m_d0->m_40.m_10 = second[3];
    m_d0->m_40.m_c = second[4];
    m_d0->m_40.m_14 = second[5];
    m_d0->m_40.m_18 = second[6];
}
MS2_REPLACE_METHOD(0x1403BD6C0, GameEventOntime, vfunc_2, 1198, 0x8CF46CE6);

// @0x1403bdb80
void GameEventOntime::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt64(m_38.Get());
}
MS2_REPLACE_METHOD(0x1403BDB80, GameEventOntime, vfunc_3, 80, 0xC494E523);

// @0x1403bdbe0
void GameEventOntime::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_38 = CMsTime(MS2_GE_R(in)->ReadInt64());
}
MS2_REPLACE_METHOD(0x1403BDBE0, GameEventOntime, vfunc_4, 98, 0x459DA96A);

// @0x1403bdc50
void GameEventOntime::vfunc_5()
{
    if (m_d0.get()) {
        m_d0->m_1c = true;
        FUN_1401c0d90()->FUN_140478170(FUN_1402e1d00(), m_d0);
    }
}
MS2_REPLACE_METHOD(0x1403BDC50, GameEventOntime, vfunc_5, 158, 0x302A88DF);

// @0x1403bdd00
void GameEventOntime::vfunc_6() { FUN_1401c0d90()->FUN_1404781f0(FUN_1402e1d00()); }
MS2_REPLACE_METHOD(0x1403BDD00, GameEventOntime, vfunc_6, 47, 0xB82BE608);

// ---- GameEventSaleEnchant -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleEnchant(L"GameEventSaleEnchant", FUN_1403bdd40);
#endif
// @0x1403bdd40
GameEvent* FUN_1403bdd40() { return new GameEventSaleEnchant; }

// @0x1403bdda0
CStringW GameEventSaleEnchant::vfunc_1() { return CStringW(L"GameEventSaleEnchant"); }
MS2_REPLACE_METHOD(0x1403BDDA0, GameEventSaleEnchant, vfunc_1, 61, 0x97A44702);

// @0x1403bddf0
GameEventSaleEnchant::GameEventSaleEnchant() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bde60
void GameEventSaleEnchant::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403BDE60, GameEventSaleEnchant, vfunc_2, 42, 0x6531D9DD);

// @0x1403bde90
void GameEventSaleEnchant::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403BDE90, GameEventSaleEnchant, vfunc_3, 61, 0x6C5A016F);

// @0x1403bdee0
void GameEventSaleEnchant::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BDEE0, GameEventSaleEnchant, vfunc_4, 79, 0x936AB3EA);

// @0x1403bdf40
void GameEventSaleEnchant::vfunc_5() { FUN_1401c0d90()->FUN_140478a80(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403BDF40, GameEventSaleEnchant, vfunc_5, 47, 0x97CFC059);

// @0x1403bdf80
void GameEventSaleEnchant::vfunc_6() { FUN_1401c0d90()->FUN_140478af0(m_id); }
MS2_REPLACE_METHOD(0x1403BDF80, GameEventSaleEnchant, vfunc_6, 35, 0x8326983A);

// ---- GameEventQuestTag ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regQuestTag(L"GameEventQuestTag", FUN_1403bdfb0);
#endif
// @0x1403bdfb0
GameEvent* FUN_1403bdfb0() { return new GameEventQuestTag; }

// @0x1403be010
CStringW GameEventQuestTag::vfunc_1() { return CStringW(L"GameEventQuestTag"); }
MS2_REPLACE_METHOD(0x1403BE010, GameEventQuestTag, vfunc_1, 61, 0x4C810B65);

// @0x1403be060
GameEventQuestTag::GameEventQuestTag()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
    m_d8 = 0;
}

// @0x1403be0e0
void GameEventQuestTag::vfunc_2()
{
    m_d0 = m_68;
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_70) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    CStringA strType;
    FUN_1408733e0(pRoot, "type", strType);
    if (strType == "IsNewCharacter")
        m_d8 = 1;
}
MS2_REPLACE_METHOD(0x1403BE0E0, GameEventQuestTag, vfunc_2, 271, 0x760B8D93);

// @0x1403be200
void GameEventQuestTag::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
    out->WriteInt64(m_28.Get());
    out->WriteInt64(m_38.Get());
}
MS2_REPLACE_METHOD(0x1403BE200, GameEventQuestTag, vfunc_3, 166, 0xC79534CB);

// @0x1403be2b0
void GameEventQuestTag::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
    m_28 = CMsTime(MS2_GE_R(in)->ReadInt64());
    m_38 = CMsTime(MS2_GE_R(in)->ReadInt64());
}
MS2_REPLACE_METHOD(0x1403BE2B0, GameEventQuestTag, vfunc_4, 301, 0xE08C631B);

// @0x1403be3f0
void GameEventQuestTag::vfunc_5()
{
    MS2Ptr<EventQuestContext> spContext(new EventQuestContext);
    spContext->m_strTag = m_d0;
    spContext->m_beginTime = m_28.Get();
    spContext->m_endTime = m_38.Get();
    if (m_d8 != 0)
        spContext->m_newCharacterTime = m_28.Get();
    FUN_1401c0d90()->FUN_140478fd0(m_d0, spContext);
}
MS2_REPLACE_METHOD(0x1403BE3F0, GameEventQuestTag, vfunc_5, 458, 0x480EB6B1);

// @0x1403be5c0
void GameEventQuestTag::vfunc_6() { FUN_1401c0d90()->FUN_140479070(m_d0); }
MS2_REPLACE_METHOD(0x1403BE5C0, GameEventQuestTag, vfunc_6, 92, 0xF48635F9);

// ---- GameEventBlackMarketFeeDiscount --------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regBlackMarketFeeDiscount(L"GameEventBlackMarketFeeDiscount", FUN_1403be630);
#endif
// @0x1403be630
GameEvent* FUN_1403be630() { return new GameEventBlackMarketFeeDiscount; }

// @0x1403be690
CStringW GameEventBlackMarketFeeDiscount::vfunc_1() { return CStringW(L"GameEventBlackMarketFeeDiscount"); }
MS2_REPLACE_METHOD(0x1403BE690, GameEventBlackMarketFeeDiscount, vfunc_1, 61, 0x46CBC4E5);

// @0x1403be6e0
GameEventBlackMarketFeeDiscount::GameEventBlackMarketFeeDiscount() : m_d0(-1)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403be750
void GameEventBlackMarketFeeDiscount::vfunc_2() { m_d0 = FUN_1407181a0(&m_68); }
MS2_REPLACE_METHOD(0x1403BE750, GameEventBlackMarketFeeDiscount, vfunc_2, 42, 0x57A2105A);

// @0x1403be780
void GameEventBlackMarketFeeDiscount::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
}
MS2_REPLACE_METHOD(0x1403BE780, GameEventBlackMarketFeeDiscount, vfunc_3, 105, 0x940F1D10);

// @0x1403be7f0
void GameEventBlackMarketFeeDiscount::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    FUN_14070f6b0(MS2_GE_R(in), &m_28);
    FUN_14070f6b0(MS2_GE_R(in), &m_38);
}
MS2_REPLACE_METHOD(0x1403BE7F0, GameEventBlackMarketFeeDiscount, vfunc_4, 131, 0x2643A841);

// @0x1403be880
void GameEventBlackMarketFeeDiscount::vfunc_5()
{
    static Unk_GameEventIntRange s_range(0, 10000);
    if (s_range.IsInRange(m_d0))
        FUN_1401c0d90()->FUN_140479510(m_d0, m_28.Get(), m_38.Get());
    else
        MS2_ASSERT_AT(MS2_LINE(841), FALSE);
}
MS2_REPLACE_METHOD(0x1403BE880, GameEventBlackMarketFeeDiscount, vfunc_5, 261, 0x9867204A);

// @0x1403be990
void GameEventBlackMarketFeeDiscount::vfunc_6() { FUN_1401c0d90()->FUN_140479510(-1, 0, 0); }
MS2_REPLACE_METHOD(0x1403BE990, GameEventBlackMarketFeeDiscount, vfunc_6, 38, 0x03263CEE);

// ---- GameEventUGCMapSaleCoupon --------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regUGCMapSaleCoupon(L"GameEventUGCMapSaleCoupon", FUN_1403be9c0);
#endif
// @0x1403be9c0
GameEvent* FUN_1403be9c0() { return new GameEventUGCMapSaleCoupon; }

// @0x1403bea20
CStringW GameEventUGCMapSaleCoupon::vfunc_1() { return CStringW(L"GameEventUGCMapSaleCoupon"); }
MS2_REPLACE_METHOD(0x1403BEA20, GameEventUGCMapSaleCoupon, vfunc_1, 61, 0x3CB71A57);

// @0x1403bea70
GameEventUGCMapSaleCoupon::GameEventUGCMapSaleCoupon() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403beae0
void GameEventUGCMapSaleCoupon::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403BEAE0, GameEventUGCMapSaleCoupon, vfunc_2, 42, 0xC59BB9F9);

// @0x1403beb10
void GameEventUGCMapSaleCoupon::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403BEB10, GameEventUGCMapSaleCoupon, vfunc_3, 61, 0x0116D2EB);

// @0x1403beb60
void GameEventUGCMapSaleCoupon::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BEB60, GameEventUGCMapSaleCoupon, vfunc_4, 79, 0x922BFEA6);

// @0x1403bebc0
void GameEventUGCMapSaleCoupon::vfunc_5() { FUN_1401c0d90()->FUN_140479600(m_d0); }
MS2_REPLACE_METHOD(0x1403BEBC0, GameEventUGCMapSaleCoupon, vfunc_5, 38, 0x0BEE936B);

// @0x1403bebf0
void GameEventUGCMapSaleCoupon::vfunc_6() { FUN_1401c0d90()->FUN_140479600(0); }
MS2_REPLACE_METHOD(0x1403BEBF0, GameEventUGCMapSaleCoupon, vfunc_6, 29, 0xB67F6FA5);

// ---- GameEventPremiumMarketSale -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regPremiumMarketSale(L"GameEventPremiumMarketSale", FUN_1403bec20);
#endif
// @0x1403bec20
GameEvent* FUN_1403bec20() { return new GameEventPremiumMarketSale; }

// @0x1403bec80
CStringW GameEventPremiumMarketSale::vfunc_1() { return CStringW(L"GameEventPremiumMarketSale"); }
MS2_REPLACE_METHOD(0x1403BEC80, GameEventPremiumMarketSale, vfunc_1, 61, 0x7CD92CF0);

// @0x1403becd0
GameEventPremiumMarketSale::GameEventPremiumMarketSale() : m_d0(0), m_e8(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bed60
void GameEventPremiumMarketSale::vfunc_2()
{
    m_d0 = FUN_1407181a0(&m_68);
    FUN_1403d8040(m_70, m_d8, L",");
    m_e8 = FUN_140718200(&m_78);
}
MS2_REPLACE_METHOD(0x1403BED60, GameEventPremiumMarketSale, vfunc_2, 105, 0x4B5F2112);

// @0x1403bedd0
void GameEventPremiumMarketSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    int nCount = (int)m_d8.size();
    out->WriteInt(nCount);
    for (std::set<int>::iterator it = m_d8.begin(); it != m_d8.end(); ++it)
        out->WriteInt(*it);
    out->WriteInt(m_e8);
}
MS2_REPLACE_METHOD(0x1403BEDD0, GameEventPremiumMarketSale, vfunc_3, 251, 0x0E68AAD7);

// @0x1403beee0
void GameEventPremiumMarketSale::vfunc_4(Unk_GEIn* in)
{
    m_d8.clear();
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    int nCount = MS2_GE_R(in)->ReadInt();
    for (int i = 0; i < nCount; ++i)
    {
        int nValue = MS2_GE_R(in)->ReadInt();
        m_d8.insert(nValue);
    }
    m_e8 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BEEE0, GameEventPremiumMarketSale, vfunc_4, 280, 0x92747EB6);

// @0x1403bf000
void GameEventPremiumMarketSale::vfunc_5()
{
    MS2Ptr<PreminmMarketSaleEventContext> pContext(new PreminmMarketSaleEventContext);
    MS2_ASSERT_AT(MS2_LINE(967), pContext != NULL);
    pContext->m_18 = m_d0;
    pContext->m_20.insert(m_d8.begin(), m_d8.end());
    pContext->m_30 = m_e8;
    FUN_1403ed2a0()->FUN_1407ce2a0(FUN_1402e1d00(), pContext);
}
MS2_REPLACE_METHOD(0x1403BF000, GameEventPremiumMarketSale, vfunc_5, 403, 0x7A587F4F);

// @0x1403bf1a0
void GameEventPremiumMarketSale::vfunc_6() { FUN_1403ed2a0()->FUN_1407ce320(FUN_1402e1d00()); }
MS2_REPLACE_METHOD(0x1403BF1A0, GameEventPremiumMarketSale, vfunc_6, 47, 0x06CDE691);

// ---- GameEventGameMenuPopup -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regGameMenuPopup(L"GameEventGameMenuPopup", FUN_1403bf1e0);
#endif
// @0x1403bf1e0
GameEvent* FUN_1403bf1e0() { return new GameEventGameMenuPopup; }

// @0x1403bf240
CStringW GameEventGameMenuPopup::vfunc_1() { return CStringW(L"GameEventGameMenuPopup"); }
MS2_REPLACE_METHOD(0x1403BF240, GameEventGameMenuPopup, vfunc_1, 61, 0x0033437C);

// @0x1403bf290
GameEventGameMenuPopup::GameEventGameMenuPopup()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bf300
void GameEventGameMenuPopup::vfunc_2()
{
    m_d0 = FUN_1407181a0(&m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403BF300, GameEventGameMenuPopup, vfunc_2, 72, 0x0F93E293);

// @0x1403bf350
void GameEventGameMenuPopup::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteShort(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403BF350, GameEventGameMenuPopup, vfunc_3, 102, 0x0F5613F2);

// @0x1403bf3c0
void GameEventGameMenuPopup::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadShort();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403BF3C0, GameEventGameMenuPopup, vfunc_4, 182, 0x7B83F3DF);

// @0x1403bf480
void GameEventGameMenuPopup::vfunc_5() {}
MS2_REPLACE_METHOD(0x1403BF480, GameEventGameMenuPopup, vfunc_5, 6, 0xA9AF6E37);

// @0x1403bf490
void GameEventGameMenuPopup::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403BF490, GameEventGameMenuPopup, vfunc_6, 6, 0xA9AF6E37);

// ---- GameEventEventFieldPopup ---------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regEventFieldPopup(L"GameEventEventFieldPopup", FUN_1403bf4a0);
#endif
// @0x1403bf4a0
GameEvent* FUN_1403bf4a0() { return new GameEventEventFieldPopup; }

// @0x1403bf500
CStringW GameEventEventFieldPopup::vfunc_1() { return CStringW(L"GameEventEventFieldPopup"); }
MS2_REPLACE_METHOD(0x1403BF500, GameEventEventFieldPopup, vfunc_1, 61, 0x2C61EBA3);

// @0x1403bf550
GameEventEventFieldPopup::GameEventEventFieldPopup()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bf5b0
void GameEventEventFieldPopup::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403BF5B0, GameEventEventFieldPopup, vfunc_2, 42, 0x8A9C690C);

// @0x1403bf5e0
void GameEventEventFieldPopup::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403BF5E0, GameEventEventFieldPopup, vfunc_3, 61, 0xFCF00514);

// @0x1403bf630
void GameEventEventFieldPopup::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403BF630, GameEventEventFieldPopup, vfunc_4, 79, 0xBAF21AA1);

// @0x1403bf690
void GameEventEventFieldPopup::vfunc_5() { FUN_1401c0d90()->FUN_1404795c0(m_d0); }
MS2_REPLACE_METHOD(0x1403BF690, GameEventEventFieldPopup, vfunc_5, 38, 0x672A21AB);

// @0x1403bf6c0
void GameEventEventFieldPopup::vfunc_6() { FUN_1401c0d90()->FUN_1404795c0(0); }
MS2_REPLACE_METHOD(0x1403BF6C0, GameEventEventFieldPopup, vfunc_6, 29, 0xB5DD45F9);

// ---- GameEventSaleAutoFishing ----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleAutoFishing(L"GameEventSaleAutoFishing", FUN_1403bf6f0);
#endif
// @0x1403bf6f0
GameEvent* FUN_1403bf6f0() { return new GameEventSaleAutoFishing; }

// @0x1403bf750
CStringW GameEventSaleAutoFishing::vfunc_1() { return CStringW(L"GameEventSaleAutoFishing"); }
MS2_REPLACE_METHOD(0x1403BF750, GameEventSaleAutoFishing, vfunc_1, 61, 0xEA4EBEEE);

// @0x1403bf7a0
GameEventSaleAutoFishing::GameEventSaleAutoFishing()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bf810
void GameEventSaleAutoFishing::vfunc_2()
{
    m_d0 = FUN_140718200(&m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403BF810, GameEventSaleAutoFishing, vfunc_2, 72, 0x5F9D833B);

// @0x1403bf860
void GameEventSaleAutoFishing::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403BF860, GameEventSaleAutoFishing, vfunc_3, 101, 0x61DCC76E);

// @0x1403bf8d0
void GameEventSaleAutoFishing::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403BF8D0, GameEventSaleAutoFishing, vfunc_4, 179, 0x96AC65FC);

// @0x1403bf990
void GameEventSaleAutoFishing::vfunc_5()
{
    FUN_1401c0d90()->FUN_1404798e0(m_d0);
    FUN_1401c0d90()->FUN_140479920(m_d8);
}
MS2_REPLACE_METHOD(0x1403BF990, GameEventSaleAutoFishing, vfunc_5, 116, 0x7E5DA331);

// @0x1403bfa10
void GameEventSaleAutoFishing::vfunc_6()
{
    FUN_1401c0d90()->FUN_1404798e0(0);
    FUN_1401c0d90()->FUN_140479920(L"");
}
MS2_REPLACE_METHOD(0x1403BFA10, GameEventSaleAutoFishing, vfunc_6, 100, 0x95274BB3);
// ---- GameEventSaleAutoPlayInstrument ---------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleAutoPlayInstrument(L"GameEventSaleAutoPlayInstrument", FUN_1403bfa80);
#endif
// @0x1403bfa80
GameEvent* FUN_1403bfa80() { return new GameEventSaleAutoPlayInstrument; }

// @0x1403bfae0
CStringW GameEventSaleAutoPlayInstrument::vfunc_1() { return CStringW(L"GameEventSaleAutoPlayInstrument"); }
MS2_REPLACE_METHOD(0x1403BFAE0, GameEventSaleAutoPlayInstrument, vfunc_1, 61, 0xFC4F68B4);

// @0x1403bfb30
GameEventSaleAutoPlayInstrument::GameEventSaleAutoPlayInstrument()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bfba0
void GameEventSaleAutoPlayInstrument::vfunc_2()
{
    m_d0 = FUN_140718200(&m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403BFBA0, GameEventSaleAutoPlayInstrument, vfunc_2, 72, 0x857B3B83);

// @0x1403bfbf0
void GameEventSaleAutoPlayInstrument::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403BFBF0, GameEventSaleAutoPlayInstrument, vfunc_3, 101, 0xE544CC82);

// @0x1403bfc60
void GameEventSaleAutoPlayInstrument::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403BFC60, GameEventSaleAutoPlayInstrument, vfunc_4, 179, 0xBEF43DC2);

// @0x1403bfd20
void GameEventSaleAutoPlayInstrument::vfunc_5()
{
    FUN_1401c0d90()->FUN_140479a00(m_d0);
    FUN_1401c0d90()->FUN_140479a40(m_d8);
}
MS2_REPLACE_METHOD(0x1403BFD20, GameEventSaleAutoPlayInstrument, vfunc_5, 116, 0x1960A1F7);

// @0x1403bfda0
void GameEventSaleAutoPlayInstrument::vfunc_6()
{
    FUN_1401c0d90()->FUN_140479a00(0);
    FUN_1401c0d90()->FUN_140479a40(L"");
}
MS2_REPLACE_METHOD(0x1403BFDA0, GameEventSaleAutoPlayInstrument, vfunc_6, 100, 0x484B5738);

// ---- GameEventTrafficOptimizer --------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regTrafficOptimizer(L"GameEventTrafficOptimizer", FUN_1403bfe10);
#endif
// @0x1403bfe10
GameEvent* FUN_1403bfe10() { return new GameEventTrafficOptimizer; }

// @0x1403bfe70
CStringW GameEventTrafficOptimizer::vfunc_1() { return CStringW(L"GameEventTrafficOptimizer"); }
MS2_REPLACE_METHOD(0x1403BFE70, GameEventTrafficOptimizer, vfunc_1, 61, 0x73597DA3);

// @0x1403bfec0
GameEventTrafficOptimizer::GameEventTrafficOptimizer()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bff20
void GameEventTrafficOptimizer::vfunc_2() {}
MS2_REPLACE_METHOD(0x1403BFF20, GameEventTrafficOptimizer, vfunc_2, 6, 0xA9AF6E37);

// @0x1403bff30
void GameEventTrafficOptimizer::vfunc_5() {}
MS2_REPLACE_METHOD(0x1403BFF30, GameEventTrafficOptimizer, vfunc_5, 6, 0xA9AF6E37);

// @0x1403bff40
void GameEventTrafficOptimizer::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403BFF40, GameEventTrafficOptimizer, vfunc_6, 6, 0xA9AF6E37);

// @0x1403bff50
bool GameEventTrafficOptimizer::vfunc_9(void* other) { return true; }
MS2_REPLACE_METHOD(0x1403BFF50, GameEventTrafficOptimizer, vfunc_9, 13, 0xC078F4D1);

// ---- GameEventDungeonRoomShutdown -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regDungeonRoomShutdown(L"GameEventDungeonRoomShutdown", FUN_1403bff70);
#endif
// @0x1403bff70
GameEvent* FUN_1403bff70() { return new GameEventDungeonRoomShutdown; }

// @0x1403bffd0
CStringW GameEventDungeonRoomShutdown::vfunc_1() { return CStringW(L"GameEventDungeonRoomShutdown"); }
MS2_REPLACE_METHOD(0x1403BFFD0, GameEventDungeonRoomShutdown, vfunc_1, 61, 0x58ADE904);

// @0x1403c0020
GameEventDungeonRoomShutdown::GameEventDungeonRoomShutdown()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c0090
void GameEventDungeonRoomShutdown::vfunc_2()
{
    m_d0.AssignRaw(new DungeonRoomShutdownContext);
    m_d0->FUN_140343eb0(m_68);
    m_d0->FUN_140343fc0(m_70);
    if (!m_d0->FUN_1403441a0())
        m_d0 = 0;
}
MS2_REPLACE_METHOD(0x1403C0090, GameEventDungeonRoomShutdown, vfunc_2, 255, 0x59566783);

// @0x1403c01a0
void GameEventDungeonRoomShutdown::vfunc_5() { FUN_1401c0d90()->FUN_140479c80(m_d0); }
MS2_REPLACE_METHOD(0x1403C01A0, GameEventDungeonRoomShutdown, vfunc_5, 91, 0xA67C7DA7);

// @0x1403c0210
void GameEventDungeonRoomShutdown::vfunc_6() { FUN_1401c0d90()->FUN_140479c80(0); }
MS2_REPLACE_METHOD(0x1403C0210, GameEventDungeonRoomShutdown, vfunc_6, 79, 0x6FA85DE5);

// @0x1403c0270
bool GameEventDungeonRoomShutdown::vfunc_9(void* other) { return true; }
MS2_REPLACE_METHOD(0x1403C0270, GameEventDungeonRoomShutdown, vfunc_9, 13, 0xC078F4D1);

// ---- GameEventDungeonOpenPeriod -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regDungeonOpenPeriod(L"GameEventDungeonOpenPeriod", FUN_1403c0290);
#endif
// @0x1403c0290
GameEvent* FUN_1403c0290() { return new GameEventDungeonOpenPeriod; }

// @0x1403c02f0
CStringW GameEventDungeonOpenPeriod::vfunc_1() { return CStringW(L"GameEventDungeonOpenPeriod"); }
MS2_REPLACE_METHOD(0x1403C02F0, GameEventDungeonOpenPeriod, vfunc_1, 61, 0xB2E4B68E);

// @0x1403c0340
GameEventDungeonOpenPeriod::GameEventDungeonOpenPeriod()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c03b0
void GameEventDungeonOpenPeriod::vfunc_2() { m_d0 = m_68; }
MS2_REPLACE_METHOD(0x1403C03B0, GameEventDungeonOpenPeriod, vfunc_2, 44, 0x0D59366A);

// @0x1403c03f0
void GameEventDungeonOpenPeriod::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070fae0(out, &m_d0);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
}
MS2_REPLACE_METHOD(0x1403C03F0, GameEventDungeonOpenPeriod, vfunc_3, 102, 0x3A3BD060);

// @0x1403c0460
void GameEventDungeonOpenPeriod::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f5f0(MS2_GE_R(in), &m_d0);
    FUN_14070f6b0(MS2_GE_R(in), &m_28);
    FUN_14070f6b0(MS2_GE_R(in), &m_38);
}
MS2_REPLACE_METHOD(0x1403C0460, GameEventDungeonOpenPeriod, vfunc_4, 114, 0x92CEB667);

// @0x1403c04e0
void GameEventDungeonOpenPeriod::vfunc_5()
{
    if (m_d0.IsEmpty())
        return;
    if (!FUN_140427690(FUN_140302b00()->GetDungeonOpenPeriod(), m_d0, m_28.Get(), m_38.Get()))
    {
        FUN_140166440()->Log(0, 0, 0x5f, L"GameEventDungeonOpenPeriod TagID Duplicated");
        m_d0.Empty();
    }
}
MS2_REPLACE_METHOD(0x1403C04E0, GameEventDungeonOpenPeriod, vfunc_5, 268, 0xBC6FC0A8);

// @0x1403c0600
void GameEventDungeonOpenPeriod::vfunc_6()
{
    if (m_d0.IsEmpty())
        return;
    FUN_140427780(FUN_140302b00()->GetDungeonOpenPeriod(), m_d0);
}
MS2_REPLACE_METHOD(0x1403C0600, GameEventDungeonOpenPeriod, vfunc_6, 129, 0xB35F834A);

// ---- GameEventFieldShutdown -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regFieldShutdown(L"GameEventFieldShutdown", FUN_1403c0690);
#endif
// @0x1403c0690
GameEvent* FUN_1403c0690() { return new GameEventFieldShutdown; }

// @0x1403c06f0
CStringW GameEventFieldShutdown::vfunc_1() { return CStringW(L"GameEventFieldShutdown"); }
MS2_REPLACE_METHOD(0x1403C06F0, GameEventFieldShutdown, vfunc_1, 61, 0xCE8D8D4D);

// @0x1403c0740
GameEventFieldShutdown::GameEventFieldShutdown()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c07b0
void GameEventFieldShutdown::vfunc_2()
{
    m_d0.clear();
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_68) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    for (Unk_140165cf0* pNode = FUN_140345b40(pRoot); pNode; pNode = FUN_1403f0510(pNode))
    {
        unsigned nId = 0;
        FUN_140873220(pNode, "id", nId);
        if (nId > 0)
            m_d0.insert(nId);
    }
}
MS2_REPLACE_METHOD(0x1403C07B0, GameEventFieldShutdown, vfunc_2, 280, 0x89FDD054);

// @0x1403c08d0
void GameEventFieldShutdown::vfunc_5() { FUN_1401c0d90()->FUN_14047a360(m_d0); }
MS2_REPLACE_METHOD(0x1403C08D0, GameEventFieldShutdown, vfunc_5, 91, 0x94D3BD97);

// @0x1403c0940
void GameEventFieldShutdown::vfunc_6() { FUN_1401c0d90()->FUN_14047a3d0(); }
MS2_REPLACE_METHOD(0x1403C0940, GameEventFieldShutdown, vfunc_6, 27, 0x2DB313CE);

// @0x1403c0970
bool GameEventFieldShutdown::vfunc_9(void* other) { return true; }
MS2_REPLACE_METHOD(0x1403C0970, GameEventFieldShutdown, vfunc_9, 13, 0xC078F4D1);

// ---- GameEventDungeonExtraReward ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regDungeonExtraReward(L"GameEventDungeonExtraReward", FUN_1403c0990);
#endif
// @0x1403c0990
GameEvent* FUN_1403c0990() { return new GameEventDungeonExtraReward; }

// @0x1403c09f0
CStringW GameEventDungeonExtraReward::vfunc_1() { return CStringW(L"GameEventDungeonExtraReward"); }
MS2_REPLACE_METHOD(0x1403C09F0, GameEventDungeonExtraReward, vfunc_1, 61, 0x8E36E21E);

// @0x1403c0a40
GameEventDungeonExtraReward::GameEventDungeonExtraReward()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c0ae0
void GameEventDungeonExtraReward::vfunc_2()
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_68) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    for (Unk_140165cf0* pNode = FUN_140345b40(pRoot); pNode; pNode = FUN_1403f0510(pNode))
    {
        MS2Ptr<DungeonExtraRewardCountCtx> spCount(new DungeonExtraRewardCountCtx);
        spCount->m_18 = FUN_1402e1d00();
        spCount->Load(pNode);
        if (spCount->m_dungeonID == 0 || spCount->m_count == 0)
            continue;
        m_d0.SetAt(spCount->m_dungeonID, spCount);
    }
}
MS2_REPLACE_METHOD(0x1403C0AE0, GameEventDungeonExtraReward, vfunc_2, 427, 0x5A1AD044);

// @0x1403c0ca0
void GameEventDungeonExtraReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403C0CA0, GameEventDungeonExtraReward, vfunc_3, 58, 0x7D6F83BC);

// @0x1403c0ce0
void GameEventDungeonExtraReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403C0CE0, GameEventDungeonExtraReward, vfunc_4, 62, 0x41D09D75);

// @0x1403c0d30
void GameEventDungeonExtraReward::vfunc_5()
{
    for (POSITION pos = m_d0.GetStartPosition(); pos; m_d0.GetNext(pos))
    {
        if (!FUN_1401c0d90()->FUN_14047a420(m_d0.GetKeyAt(pos), m_d0.GetValueAt(pos)))
            FUN_140166440()->Log(0, 0, 0x2c, StringFormat(L"GameEventDungeonExtraReward::OnStart Duplicate DungeonID",
                                                         m_d0.GetKeyAt(pos)));
    }
}
MS2_REPLACE_METHOD(0x1403C0D30, GameEventDungeonExtraReward, vfunc_5, 359, 0x62073F0A);

// @0x1403c0ea0
void GameEventDungeonExtraReward::vfunc_6()
{
    for (POSITION pos = m_d0.GetStartPosition(); pos; m_d0.GetNext(pos))
    {
        MS2Ptr<DungeonExtraRewardCountCtx> spCount = m_d0.GetValueAt(pos);
        if (spCount.get())
            FUN_1401c0d90()->FUN_14047a4e0(m_d0.GetKeyAt(pos), spCount->m_18);
    }
}
MS2_REPLACE_METHOD(0x1403C0EA0, GameEventDungeonExtraReward, vfunc_6, 225, 0x1D2A0759);

// ---- GameEventSale --------------------------------------------------------------------------------------------------
// @0x1403c0f90
GameEventSale::GameEventSale() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c1000
void GameEventSale::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403C1000, GameEventSale, vfunc_2, 42, 0xB4C424AB);

// @0x1403c1030
void GameEventSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C1030, GameEventSale, vfunc_3, 61, 0x68660156);

// @0x1403c1080
void GameEventSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C1080, GameEventSale, vfunc_4, 79, 0x387A8D8B);

// ---- GameEventSaleRemake --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleRemake(L"GameEventSaleRemake", FUN_1403c10e0);
#endif
// @0x1403c10e0
GameEvent* FUN_1403c10e0() { return new GameEventSaleRemake; }

// @0x1403c1140
CStringW GameEventSaleRemake::vfunc_1() { return CStringW(L"GameEventSaleRemake"); }
MS2_REPLACE_METHOD(0x1403C1140, GameEventSaleRemake, vfunc_1, 61, 0xB6BF899D);

// @0x1403c1190
GameEventSaleRemake::GameEventSaleRemake() : m_d0(0), m_d4(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c1210
void GameEventSaleRemake::vfunc_2()
{
    m_d0 = FUN_140718200(&m_68);
    m_d4 = FUN_1407181a0(&m_70);
}
MS2_REPLACE_METHOD(0x1403C1210, GameEventSaleRemake, vfunc_2, 70, 0x58AE9BFB);

// @0x1403c1260
void GameEventSaleRemake::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteByte(m_d4);
}
MS2_REPLACE_METHOD(0x1403C1260, GameEventSaleRemake, vfunc_3, 89, 0x15897305);

// @0x1403c12c0
void GameEventSaleRemake::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadByte();
}
MS2_REPLACE_METHOD(0x1403C12C0, GameEventSaleRemake, vfunc_4, 127, 0x74CFAF45);

// @0x1403c1350
void GameEventSaleRemake::vfunc_5() { FUN_1401c0d90()->FUN_140478bd0(m_id, m_d4, m_d0); }
MS2_REPLACE_METHOD(0x1403C1350, GameEventSaleRemake, vfunc_5, 59, 0xCCEA410C);

// @0x1403c13a0
void GameEventSaleRemake::vfunc_6() { FUN_1401c0d90()->FUN_140478c50(m_id, m_d4); }
MS2_REPLACE_METHOD(0x1403C13A0, GameEventSaleRemake, vfunc_6, 47, 0xAB4281F4);

// ---- GameEventSaleGemStoneUpgrade -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleGemStoneUpgrade(L"GameEventSaleGemStoneUpgrade", FUN_1403c13e0);
#endif
// @0x1403c13e0
GameEvent* FUN_1403c13e0() { return new GameEventSaleGemStoneUpgrade; }

// @0x1403c1440
CStringW GameEventSaleGemStoneUpgrade::vfunc_1() { return CStringW(L"GameEventSaleGemStoneUpgrade"); }
MS2_REPLACE_METHOD(0x1403C1440, GameEventSaleGemStoneUpgrade, vfunc_1, 61, 0x9E6F808F);

// @0x1403c1490
GameEventSaleGemStoneUpgrade::GameEventSaleGemStoneUpgrade()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c14f0
void GameEventSaleGemStoneUpgrade::vfunc_5() { FUN_1401c0d90()->FUN_140478e80(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C14F0, GameEventSaleGemStoneUpgrade, vfunc_5, 47, 0x689EA1F8);

// @0x1403c1530
void GameEventSaleGemStoneUpgrade::vfunc_6() { FUN_1401c0d90()->FUN_140478ef0(m_id); }
MS2_REPLACE_METHOD(0x1403C1530, GameEventSaleGemStoneUpgrade, vfunc_6, 35, 0xC8B8A187);

// ---- GameEventSaleSkillUpgrade --------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleSkillUpgrade(L"GameEventSaleSkillUpgrade", FUN_1403c1560);
#endif
// @0x1403c1560
GameEvent* FUN_1403c1560() { return new GameEventSaleSkillUpgrade; }

// @0x1403c15c0
CStringW GameEventSaleSkillUpgrade::vfunc_1() { return CStringW(L"GameEventSaleSkillUpgrade"); }
MS2_REPLACE_METHOD(0x1403C15C0, GameEventSaleSkillUpgrade, vfunc_1, 61, 0x1F5BEC15);

// @0x1403c1610
GameEventSaleSkillUpgrade::GameEventSaleSkillUpgrade()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c16c0
void GameEventSaleSkillUpgrade::vfunc_2()
{
    m_d0 = m_68;
    m_d8 = m_70;
    m_e0 = m_78;
    m_e8 = m_80;
}
MS2_REPLACE_METHOD(0x1403C16C0, GameEventSaleSkillUpgrade, vfunc_2, 163, 0x05EF46DF);

// @0x1403c1770
void GameEventSaleSkillUpgrade::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringA(m_d0);
    out->WriteStringA(m_d8);
    out->WriteStringA(m_e0);
    out->WriteStringW(m_e8);
}
MS2_REPLACE_METHOD(0x1403C1770, GameEventSaleSkillUpgrade, vfunc_3, 194, 0xA552751C);

// @0x1403c1840
void GameEventSaleSkillUpgrade::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringA();
    m_d8 = MS2_GE_R(in)->ReadStringA();
    m_e0 = MS2_GE_R(in)->ReadStringA();
    m_e8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C1840, GameEventSaleSkillUpgrade, vfunc_4, 482, 0x3A8EF457);

// @0x1403c1a30
void GameEventSaleSkillUpgrade::vfunc_5()
{
    ATL::CAtlArray<unsigned> skillIds;
    ATL::CAtlArray<unsigned> levels;
    ATL::CAtlArray<unsigned> rates;
    XmlSplit(m_d0, skillIds, ",");
    XmlSplit(m_d8, levels, ",");
    XmlSplit(m_e0, rates, ",");
    if (skillIds.GetCount() != levels.GetCount())
        return;
    if (levels.GetCount() != rates.GetCount())
        return;
    for (size_t i = 0; i < skillIds.GetCount(); ++i)
    {
        MS2Ptr<SkillUpgradeSaleEventContext> spContext(new SkillUpgradeSaleEventContext);
        spContext->m_18 = skillIds[i];
        spContext->m_1c = levels[i];
        spContext->m_20 = rates[i];
        FUN_1401c0d90()->FUN_14047b540(spContext);
    }
    FUN_1401c0d90()->FUN_14047b6d0(m_e8);
}
MS2_REPLACE_METHOD(0x1403C1A30, GameEventSaleSkillUpgrade, vfunc_5, 789, 0xD857AE3F);

// @0x1403c1d50
void GameEventSaleSkillUpgrade::vfunc_6()
{
    ATL::CAtlArray<unsigned> skillIds;
    XmlSplit(m_d0, skillIds, ",");
    for (size_t i = 0; i < skillIds.GetCount(); ++i)
        FUN_1401c0d90()->FUN_14047b5c0(skillIds[i]);
}
MS2_REPLACE_METHOD(0x1403C1D50, GameEventSaleSkillUpgrade, vfunc_6, 158, 0x81180E3D);

// ---- GameEventNpcEventDrop ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regNpcEventDrop(L"GameEventNpcEventDrop", FUN_1403c1e00);
#endif
// @0x1403c1e00
GameEvent* FUN_1403c1e00() { return new GameEventNpcEventDrop; }

// @0x1403c1e60
CStringW GameEventNpcEventDrop::vfunc_1() { return CStringW(L"GameEventNpcEventDrop"); }
MS2_REPLACE_METHOD(0x1403C1E60, GameEventNpcEventDrop, vfunc_1, 61, 0xA2C14318);

// @0x1403c1eb0
GameEventNpcEventDrop::GameEventNpcEventDrop() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c1f30
void GameEventNpcEventDrop::vfunc_2()
{
    m_d0 = 0;
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_68) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    Unk_140165cf0* pNode = FUN_140345b40(pRoot);
    if (!pNode)
        return;
    MS2Ptr<NpcEventDropEventContext> spContext(new NpcEventDropEventContext);
    FUN_1408731a0(pNode, "minLevel", spContext->m_minLevel);
    FUN_1408731a0(pNode, "maxLevel", spContext->m_maxLevel);
    FUN_140873220(pNode, "fieldId", spContext->m_fieldId);
    XmlValue(pNode, "npcRank", spContext->m_npcRank);
    XmlTokenList(pNode, "customNpcId", spContext->m_customNpcIds);
    FUN_1408730a0(pNode, "isShow", spContext->m_isShow);
    XmlTokenList(pNode, "dropId", spContext->m_dropIds);
    XmlEnumName<Unk_NpcEventTag, FUN_14021bc30>(pNode, "eventTags", spContext->m_eventTag);
    m_d0 = spContext;
}
MS2_REPLACE_METHOD(0x1403C1F30, GameEventNpcEventDrop, vfunc_2, 598, 0xB54C8D81);

// @0x1403c2190
void GameEventNpcEventDrop::vfunc_5()
{
    if (m_d0.get())
        FUN_1401c0d90()->FUN_14047a6a0(FUN_1402e1d00(), m_d0);
}
MS2_REPLACE_METHOD(0x1403C2190, GameEventNpcEventDrop, vfunc_5, 135, 0x8347BC99);

// @0x1403c2220
void GameEventNpcEventDrop::vfunc_6() { FUN_1401c0d90()->FUN_14047a730(FUN_1402e1d00()); }
MS2_REPLACE_METHOD(0x1403C2220, GameEventNpcEventDrop, vfunc_6, 47, 0x0ADD96DA);

// ---- GameEventBlueMarble --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regBlueMarble(L"GameEventBlueMarble", FUN_1403c2260);
#endif
// @0x1403c2260
GameEvent* FUN_1403c2260() { return new GameEventBlueMarble; }

// @0x1403c22c0
CStringW GameEventBlueMarble::vfunc_1() { return CStringW(L"GameEventBlueMarble"); }
MS2_REPLACE_METHOD(0x1403C22C0, GameEventBlueMarble, vfunc_1, 61, 0x49E74EC9);

// @0x1403c2310
GameEventBlueMarble::GameEventBlueMarble()
{
    m_d0 = 0;
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c23a0
void GameEventBlueMarble::vfunc_2()
{
    TiXmlDocument docRound;
    TiXmlDocument docSlot;
    if (FUN_140166420()->FUN_140397ab0(&docRound, m_68) == 0)
        return;
    if (FUN_140166420()->FUN_140397ab0(&docSlot, m_70) == 0)
        return;
    MS2Ptr<BlueMarbleEventContext> spContext(new BlueMarbleEventContext(FUN_1402e1d00(), FUN_1402e2730()));
    Unk_140165cf0* pRound = FUN_140165cf0(&docRound, "round");
    if (pRound)
        spContext->LoadRewards(pRound);
    Unk_140165cf0* pSlots = FUN_140165cf0(&docSlot, "slots");
    if (pSlots)
        spContext->LoadSlots(pSlots);
    m_d0 = spContext;
}
MS2_REPLACE_METHOD(0x1403C23A0, GameEventBlueMarble, vfunc_2, 520, 0xE0741D96);

// @0x1403c25b0
void GameEventBlueMarble::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt((int)m_d0->m_rewards.GetCount());
    for (POSITION pos = m_d0->m_rewards.GetHeadPosition(); pos; m_d0->m_rewards.GetNext(pos))
    {
        MS2Ptr<ItemEntity> spItem = m_d0->m_rewards.GetValueAt(pos);
        out->WriteInt(m_d0->m_rewards.GetKeyAt(pos));
        out->WriteInt(spItem->m_itemId);
        out->WriteByte(spItem->vfunc_o18_1());
        out->WriteInt(spItem->m_count);
    }
}
MS2_REPLACE_METHOD(0x1403C25B0, GameEventBlueMarble, vfunc_3, 511, 0xCE411612);

// @0x1403c27c0
void GameEventBlueMarble::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new BlueMarbleEventContext(FUN_1402e1d00(), FUN_1402e2730()));
    size_t nCount = (unsigned)MS2_GE_R(in)->ReadInt();
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        int nRound = MS2_GE_R(in)->ReadInt();
        spItem->m_itemId = MS2_GE_R(in)->ReadInt();
        spItem->FUN_14026b1c0(MS2_GE_R(in)->ReadByte());
        spItem->m_count = MS2_GE_R(in)->ReadInt();
        m_d0->AddReward(nRound, spItem);
    }
}
MS2_REPLACE_METHOD(0x1403C27C0, GameEventBlueMarble, vfunc_4, 745, 0x0AF8B17F);

// @0x1403c2ab0
void GameEventBlueMarble::vfunc_5() { FUN_1401c0d90()->FUN_14047b8f0(m_d0); }
MS2_REPLACE_METHOD(0x1403C2AB0, GameEventBlueMarble, vfunc_5, 91, 0x52567E0A);

// @0x1403c2b20
void GameEventBlueMarble::vfunc_6() { FUN_1401c0d90()->FUN_14047b8f0(0); }
MS2_REPLACE_METHOD(0x1403C2B20, GameEventBlueMarble, vfunc_6, 79, 0xD37814B8);

// ---- GameEventSaleUGCDesign -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleUGCDesign(L"GameEventSaleUGCDesign", FUN_1403c2b80);
#endif
// @0x1403c2b80
GameEvent* FUN_1403c2b80() { return new GameEventSaleUGCDesign; }

// @0x1403c2be0
CStringW GameEventSaleUGCDesign::vfunc_1() { return CStringW(L"GameEventSaleUGCDesign"); }
MS2_REPLACE_METHOD(0x1403C2BE0, GameEventSaleUGCDesign, vfunc_1, 61, 0xFCF94496);

// @0x1403c2c30
GameEventSaleUGCDesign::GameEventSaleUGCDesign()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c2c90
void GameEventSaleUGCDesign::vfunc_5() { FUN_1401c0d90()->FUN_14047b9d0(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C2C90, GameEventSaleUGCDesign, vfunc_5, 47, 0x432176DC);

// @0x1403c2cd0
void GameEventSaleUGCDesign::vfunc_6() { FUN_1401c0d90()->FUN_14047ba40(m_id); }
MS2_REPLACE_METHOD(0x1403C2CD0, GameEventSaleUGCDesign, vfunc_6, 35, 0xC878D363);

// ---- GameEventMeratMarketNotice -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regMeratMarketNotice(L"GameEventMeratMarketNotice", FUN_1403c2d00);
#endif
// @0x1403c2d00
GameEvent* FUN_1403c2d00() { return new GameEventMeratMarketNotice; }

// @0x1403c2d60
CStringW GameEventMeratMarketNotice::vfunc_1() { return CStringW(L"GameEventMeratMarketNotice"); }
MS2_REPLACE_METHOD(0x1403C2D60, GameEventMeratMarketNotice, vfunc_1, 61, 0xC9F95959);

// @0x1403c2db0
GameEventMeratMarketNotice::GameEventMeratMarketNotice() : m_d0(L"")
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c2e30
void GameEventMeratMarketNotice::vfunc_2() { m_d0 = m_68; }
MS2_REPLACE_METHOD(0x1403C2E30, GameEventMeratMarketNotice, vfunc_2, 44, 0x73576DA6);

// @0x1403c2e70
void GameEventMeratMarketNotice::vfunc_3(Unk_GEOut* out) { out->WriteStringW(m_d0); }
MS2_REPLACE_METHOD(0x1403C2E70, GameEventMeratMarketNotice, vfunc_3, 59, 0xAE59AA54);

// @0x1403c2ec0
void GameEventMeratMarketNotice::vfunc_4(Unk_GEIn* in) { m_d0 = MS2_GE_R(in)->ReadStringW(); }
MS2_REPLACE_METHOD(0x1403C2EC0, GameEventMeratMarketNotice, vfunc_4, 119, 0xDAD2EB50);

// @0x1403c2f40
void GameEventMeratMarketNotice::vfunc_5() {}
MS2_REPLACE_METHOD(0x1403C2F40, GameEventMeratMarketNotice, vfunc_5, 6, 0xA9AF6E37);

// @0x1403c2f50
void GameEventMeratMarketNotice::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403C2F50, GameEventMeratMarketNotice, vfunc_6, 6, 0xA9AF6E37);

// ---- GameEventDungeonEnterTimeLimit ---------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regDungeonEnterTimeLimit(L"GameEventDungeonEnterTimeLimit", FUN_1403c2f60);
#endif
// @0x1403c2f60
GameEvent* FUN_1403c2f60() { return new GameEventDungeonEnterTimeLimit; }

// @0x1403c2fc0
CStringW GameEventDungeonEnterTimeLimit::vfunc_1() { return CStringW(L"GameEventDungeonEnterTimeLimit"); }
MS2_REPLACE_METHOD(0x1403C2FC0, GameEventDungeonEnterTimeLimit, vfunc_1, 61, 0xDA704B95);

// @0x1403c3010
GameEventDungeonEnterTimeLimit::GameEventDungeonEnterTimeLimit()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c3080
void GameEventDungeonEnterTimeLimit::vfunc_2() { FUN_1403c31c0(m_68); }
MS2_REPLACE_METHOD(0x1403C3080, GameEventDungeonEnterTimeLimit, vfunc_2, 36, 0xE1C0510D);

// @0x1403c30b0
void GameEventDungeonEnterTimeLimit::vfunc_5() { FUN_1401c0d90()->FUN_140479f30(m_d0); }
MS2_REPLACE_METHOD(0x1403C30B0, GameEventDungeonEnterTimeLimit, vfunc_5, 51, 0x03061B7D);

// @0x1403c30f0
void GameEventDungeonEnterTimeLimit::vfunc_6() { FUN_1401c0d90()->FUN_14047a0a0(FUN_1402e1d00()); }
MS2_REPLACE_METHOD(0x1403C30F0, GameEventDungeonEnterTimeLimit, vfunc_6, 47, 0x22EB50E5);

// @0x1403c3130
void GameEventDungeonEnterTimeLimit::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403C3130, GameEventDungeonEnterTimeLimit, vfunc_3, 58, 0x7BD7AF3B);

// @0x1403c3170
void GameEventDungeonEnterTimeLimit::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403C3170, GameEventDungeonEnterTimeLimit, vfunc_4, 62, 0x87FAC90C);

// @0x1403c31c0
void GameEventDungeonEnterTimeLimit::FUN_1403c31c0(const CStringW& strXml)
{
    m_d0.clear();
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, strXml) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (!pRoot)
        return;
    for (Unk_140165cf0* pNode = FUN_140345b40(pRoot); pNode; pNode = FUN_1403f0510(pNode))
    {
        MS2Ptr<EventTimeLimitDungeonContext> spContext(new EventTimeLimitDungeonContext);
        spContext->m_eventId = FUN_1402e1d00();
        FUN_140873220(pNode, "dungeonID", spContext->m_dungeonId);
        XmlValueRange(pNode, "rangeTime", spContext->m_rangeTime);
        if (spContext->m_dungeonId == 0 || spContext->m_rangeTime.m_start > spContext->m_rangeTime.m_end)
        {
            MS2_ASSERT_AT(MS2_LINE(1829), 0);
            continue;
        }
        m_d0.push_back(spContext);
    }
}
MS2_REPLACE_METHOD(0x1403C31C0, GameEventDungeonEnterTimeLimit, FUN_1403c31c0, 545, 0xAA0ABD16);

// ---- GameEventSaleHousing -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleHousing(L"GameEventSaleHousing", FUN_1403c33f0);
#endif
// @0x1403c33f0
GameEvent* FUN_1403c33f0() { return new GameEventSaleHousing; }

// @0x1403c3450
CStringW GameEventSaleHousing::vfunc_1() { return CStringW(L"GameEventSaleHousing"); }
MS2_REPLACE_METHOD(0x1403C3450, GameEventSaleHousing, vfunc_1, 61, 0xED0BCDC7);

// @0x1403c34a0
GameEventSaleHousing::GameEventSaleHousing() : m_d0(10)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c3520
void GameEventSaleHousing::vfunc_2()
{
    ATL::CAtlArray<unsigned> keys;
    FUN_140274fc0(m_68, keys, L",");
    ATL::CAtlArray<unsigned> values1c;
    FUN_140274fc0(m_70, values1c, L",");
    ATL::CAtlArray<unsigned> values20;
    FUN_140274fc0(m_78, values20, L",");
    if (keys.GetCount() != values1c.GetCount())
        return;
    if (values1c.GetCount() != values20.GetCount())
        return;
    for (unsigned i = 0; i < keys.GetCount(); i++)
    {
        MS2Ptr<SaleCube> spCube(new SaleCube);
        spCube->m_18 = (Unk_SaleHousingKey)keys[i];
        spCube->m_1c = values1c[i];
        spCube->m_20 = values20[i];
        m_d0.Insert(spCube->m_18, spCube);
    }
}
MS2_REPLACE_METHOD(0x1403C3520, GameEventSaleHousing, vfunc_2, 715, 0x9E5EB17E);

// @0x1403c3800
void GameEventSaleHousing::vfunc_5() { FUN_1401c0d90()->FUN_14047be80(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C3800, GameEventSaleHousing, vfunc_5, 59, 0x0D886633);

// @0x1403c3850
void GameEventSaleHousing::vfunc_6() { FUN_1401c0d90()->FUN_14047bfc0(m_id); }
MS2_REPLACE_METHOD(0x1403C3850, GameEventSaleHousing, vfunc_6, 35, 0x1CF60104);

// @0x1403c3880
void GameEventSaleHousing::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt((int)m_d0.GetCount());
    for (POSITION pos = m_d0.GetHeadPosition(); pos; m_d0.GetNext(pos))
    {
        MS2Ptr<SaleCube> spCube = m_d0.GetValueAt(pos);
        out->WriteShort((unsigned short)spCube->m_18);
        out->WriteShort((unsigned short)spCube->m_1c);
        out->WriteInt(spCube->m_20);
    }
}
MS2_REPLACE_METHOD(0x1403C3880, GameEventSaleHousing, vfunc_3, 325, 0x7FD464E2);

// @0x1403c39d0
void GameEventSaleHousing::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    int nCount = MS2_GE_R(in)->ReadInt();
    for (int i = 0; i < nCount; i++)
    {
        MS2Ptr<SaleCube> spCube(new SaleCube);
        spCube->m_18 = (Unk_SaleHousingKey)MS2_GE_R(in)->ReadShort();
        spCube->m_1c = MS2_GE_R(in)->ReadShort();
        spCube->m_20 = MS2_GE_R(in)->ReadInt();
        m_d0.Insert(spCube->m_18, spCube);
    }
}
MS2_REPLACE_METHOD(0x1403C39D0, GameEventSaleHousing, vfunc_4, 458, 0x2F7119E0);

// ---- GameEventEpicRestart -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regEpicRestart(L"GameEventEpicRestart", FUN_1403c3ba0);
#endif
// @0x1403c3ba0
GameEvent* FUN_1403c3ba0() { return new GameEventEpicRestart; }

// @0x1403c3c00
CStringW GameEventEpicRestart::vfunc_1() { return CStringW(L"GameEventEpicRestart"); }
MS2_REPLACE_METHOD(0x1403C3C00, GameEventEpicRestart, vfunc_1, 61, 0x0985CFB1);

// @0x1403c3c50
GameEventEpicRestart::GameEventEpicRestart()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c3cf0
void GameEventEpicRestart::vfunc_2()
{
    m_d0 = (const wchar_t*)m_68;
    m_e0 = (const wchar_t*)m_70;
    m_d8 = (const wchar_t*)m_78;
}
MS2_REPLACE_METHOD(0x1403C3CF0, GameEventEpicRestart, vfunc_2, 131, 0xE21A7CD6);

// @0x1403c3d80
void GameEventEpicRestart::vfunc_5() { FUN_1401c0d90()->FUN_14047c020(FUN_1402e1d00(), m_38.Get(), m_d0, m_e0, m_d8); }
MS2_REPLACE_METHOD(0x1403C3D80, GameEventEpicRestart, vfunc_5, 155, 0xDC91DCFD);

// @0x1403c3e30
void GameEventEpicRestart::vfunc_6() { FUN_1401c0d90()->FUN_14047c1e0(); }
MS2_REPLACE_METHOD(0x1403C3E30, GameEventEpicRestart, vfunc_6, 27, 0x4FC9645D);

// @0x1403c3e60
void GameEventEpicRestart::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt64(m_38.Get());
    out->WriteStringA(m_d0);
    out->WriteStringA(m_e0);
    out->WriteStringA(m_d8);
}
MS2_REPLACE_METHOD(0x1403C3E60, GameEventEpicRestart, vfunc_3, 200, 0x37DB4AB8);

// @0x1403c3f30
void GameEventEpicRestart::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_38 = CMsTime(MS2_GE_R(in)->ReadInt64());
    m_d0 = MS2_GE_R(in)->ReadStringA();
    m_e0 = MS2_GE_R(in)->ReadStringA();
    m_d8 = MS2_GE_R(in)->ReadStringA();
}
MS2_REPLACE_METHOD(0x1403C3F30, GameEventEpicRestart, vfunc_4, 440, 0x84F320C1);

// ---- GameEventLevelUpPackage ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regLevelUpPackage(L"GameEventLevelUpPackage", FUN_1403c40f0);
#endif
// @0x1403c40f0
GameEvent* FUN_1403c40f0() { return new GameEventLevelUpPackage; }

// @0x1403c4150
CStringW GameEventLevelUpPackage::vfunc_1() { return CStringW(L"GameEventLevelUpPackage"); }
MS2_REPLACE_METHOD(0x1403C4150, GameEventLevelUpPackage, vfunc_1, 61, 0xB78A86F4);

// @0x1403c41a0
GameEventLevelUpPackage::GameEventLevelUpPackage()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c4210
void GameEventLevelUpPackage::vfunc_2()
{
    m_d0 = FUN_140718200(&m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403C4210, GameEventLevelUpPackage, vfunc_2, 72, 0x151E7A50);

// @0x1403c4260
void GameEventLevelUpPackage::vfunc_5() { FUN_1401c0d90()->FUN_14047c740(m_d0, m_d8); }
MS2_REPLACE_METHOD(0x1403C4260, GameEventLevelUpPackage, vfunc_5, 62, 0x4F7D051A);

// @0x1403c42b0
void GameEventLevelUpPackage::vfunc_6() { FUN_1401c0d90()->FUN_14047c7c0(); }
MS2_REPLACE_METHOD(0x1403C42B0, GameEventLevelUpPackage, vfunc_6, 27, 0x1F6EC9DB);

// @0x1403c42e0
void GameEventLevelUpPackage::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403C42E0, GameEventLevelUpPackage, vfunc_3, 101, 0xE15070E8);

// @0x1403c4350
void GameEventLevelUpPackage::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C4350, GameEventLevelUpPackage, vfunc_4, 179, 0xEBAFE723);

// ---- GameEventUpdateString ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regUpdateString(L"GameEventUpdateString", FUN_1403c4410);
#endif
// @0x1403c4410
GameEvent* FUN_1403c4410() { return new GameEventUpdateString; }

// @0x1403c4470
CStringW GameEventUpdateString::vfunc_1() { return CStringW(L"GameEventUpdateString"); }
MS2_REPLACE_METHOD(0x1403C4470, GameEventUpdateString, vfunc_1, 61, 0xFF2F4C8C);

// @0x1403c44c0
GameEventUpdateString::GameEventUpdateString()
{
    FUN_1402e3480(2);
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c4540
void GameEventUpdateString::vfunc_2() { m_d0 = m_68; }
MS2_REPLACE_METHOD(0x1403C4540, GameEventUpdateString, vfunc_2, 44, 0xB7A08C4F);

// @0x1403c4580
void GameEventUpdateString::vfunc_5() {}
MS2_REPLACE_METHOD(0x1403C4580, GameEventUpdateString, vfunc_5, 6, 0xA9AF6E37);

// @0x1403c4590
void GameEventUpdateString::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403C4590, GameEventUpdateString, vfunc_6, 6, 0xA9AF6E37);

// @0x1403c45a0
void GameEventUpdateString::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
}
MS2_REPLACE_METHOD(0x1403C45A0, GameEventUpdateString, vfunc_3, 74, 0x7D451564);

// @0x1403c45f0
void GameEventUpdateString::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C45F0, GameEventUpdateString, vfunc_4, 134, 0x817B68F0);

// ---- GameEventStampEvent --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regStampEvent(L"GameEventStampEvent", FUN_1403c4680);
#endif
// @0x1403c4680
GameEvent* FUN_1403c4680() { return new GameEventStampEvent; }

// @0x1403c46e0
CStringW GameEventStampEvent::vfunc_1() { return CStringW(L"GameEventStampEvent"); }
MS2_REPLACE_METHOD(0x1403C46E0, GameEventStampEvent, vfunc_1, 61, 0xA9C46086);

// @0x1403c4730
GameEventStampEvent::GameEventStampEvent()
{
    FUN_1402e3480(3);
    FUN_1402e3480(1);
    m_d8 = 0;
    m_d0 = true;
}

// @0x1403c47c0
void GameEventStampEvent::vfunc_2()
{
    TiXmlDocument docStamp;
    TiXmlDocument docReward;
    if (FUN_140166420()->FUN_140397ab0(&docStamp, m_68) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(2060), 0);
        return;
    }
    if (FUN_140166420()->FUN_140397ab0(&docReward, m_70) == 0)
    {
        MS2_ASSERT_AT(MS2_LINE(2066), 0);
        return;
    }
    MS2Ptr<StampEventContext> spContext(new StampEventContext(FUN_1402e1d00()));
    Unk_140165cf0* pStampRoot = FUN_140345b40(&docStamp);
    if (pStampRoot)
    {
        Unk_140165cf0* pTag = pStampRoot->FUN_140165cf0("tag");
        if (pTag)
            FUN_140873420(pTag, "event", spContext->m_strTitle);
        for (Unk_140165cf0* pStamp = pStampRoot->FUN_140165cf0("stamp"); pStamp; pStamp = pStamp->FUN_140168650("stamp"))
        {
            MS2Ptr<StampEventContext::Stamp> spStamp(new StampEventContext::Stamp);
            FUN_140873220(pStamp, "quest", spStamp->m_id);
            FUN_1408731e0(pStamp, "special", spStamp->m_bStamped);
            FUN_1408731e0(pStamp, "x", spStamp->m_20);
            FUN_1408731e0(pStamp, "y", spStamp->m_24);
            spContext->m_stamps.Add(spStamp);
        }
    }
    Unk_140165cf0* pRewardRoot = FUN_140345b40(&docReward);
    if (pRewardRoot)
    {
        for (Unk_140165cf0* pReward = pRewardRoot->FUN_140165cf0("reward"); pReward;
             pReward = pReward->FUN_140168650("reward"))
        {
            MS2Ptr<StampEventContext::Reward> spReward(new StampEventContext::Reward);
            FUN_1408731e0(pReward, "special", spReward->m_bReceived);
            FUN_1408731e0(pReward, "count", spReward->m_count);
            CStringW strItem1;
            CStringW strItem2;
            FUN_140873420(pReward, "item01", strItem1);
            FUN_140873420(pReward, "item02", strItem2);
            spReward->m_item.vfunc_1(strItem1);
            spReward->m_item2.vfunc_1(strItem2);
            spContext->m_rewards.Add(spReward);
        }
    }
    spContext->m_item.vfunc_1(m_78);
    spContext->m_98 = FUN_1407181a0(&m_80);
    spContext->m_endTime = FUN_1402e2730().Get();
    spContext->m_b9c = m_d0;
    m_d8 = spContext;
}
MS2_REPLACE_METHOD(0x1403C47C0, GameEventStampEvent, vfunc_2, 1758, 0x516243D8);

// @0x1403c4eb0
void GameEventStampEvent::vfunc_5() { FUN_1401c0d90()->FUN_14047c8e0(m_d8); }
MS2_REPLACE_METHOD(0x1403C4EB0, GameEventStampEvent, vfunc_5, 91, 0x1128F1EB);

// @0x1403c4f20
void GameEventStampEvent::vfunc_6()
{
    FUN_1401c0d90()->FUN_14047c990(m_d8);
    FUN_1403ed2b0()->FUN_141adc5d0(eUI_4f33);
}
MS2_REPLACE_METHOD(0x1403C4F20, GameEventStampEvent, vfunc_6, 109, 0xDCD117E1);

// @0x1403c4fa0
void GameEventStampEvent::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (m_d8.IsNull())
        return;
    m_d8->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403C4FA0, GameEventStampEvent, vfunc_3, 94, 0xC3F5F23D);

// @0x1403c5010
void GameEventStampEvent::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d8.AssignRaw(new StampEventContext(FUN_1402e1d00()));
    m_d8->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403C5010, GameEventStampEvent, vfunc_4, 170, 0x5E42215F);

// ---- GameEventStampEventChar ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regStampEventChar(L"GameEventStampEventChar", FUN_1403c50c0);
#endif
// @0x1403c50c0
GameEvent* FUN_1403c50c0() { return new GameEventStampEventChar; }

// @0x1403c5120
CStringW GameEventStampEventChar::vfunc_1() { return CStringW(L"GameEventStampEventChar"); }
MS2_REPLACE_METHOD(0x1403C5120, GameEventStampEventChar, vfunc_1, 61, 0x93AF1272);

// @0x1403c5170
GameEventStampEventChar::GameEventStampEventChar() { m_d0 = false; }

// ---- GameEventTimeRunEvent ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regTimeRunEvent(L"GameEventTimeRunEvent", FUN_1403c51b0);
#endif
// @0x1403c51b0
GameEvent* FUN_1403c51b0() { return new GameEventTimeRunEvent; }

// @0x1403c5210
CStringW GameEventTimeRunEvent::vfunc_1() { return CStringW(L"GameEventTimeRunEvent"); }
MS2_REPLACE_METHOD(0x1403C5210, GameEventTimeRunEvent, vfunc_1, 61, 0x48F43C7E);

// @0x1403c5260
GameEventTimeRunEvent::GameEventTimeRunEvent()
{
    FUN_1402e3480(3);
    FUN_1402e3480(1);
    m_d0 = 0;
}

// @0x1403c52f0
void GameEventTimeRunEvent::vfunc_2()
{
    MS2Ptr<TimeRunEventContext> spContext(new TimeRunEventContext(FUN_1402e1d00()));
    if (FUN_1403c5670(spContext) == 0)
        return;
    if (FUN_1403c58e0(spContext) == 0)
        return;
    spContext->m_value = FUN_140718200(&m_78);
    spContext->m_endTime = FUN_1402e2730().Get();
    m_d0 = spContext;
}
MS2_REPLACE_METHOD(0x1403C52F0, GameEventTimeRunEvent, vfunc_2, 391, 0x7BB32E72);

// @0x1403c5480
void GameEventTimeRunEvent::vfunc_5() { FUN_1401c0d90()->FUN_14047d650(m_d0); }
MS2_REPLACE_METHOD(0x1403C5480, GameEventTimeRunEvent, vfunc_5, 91, 0xE2C6979A);

// @0x1403c54f0
void GameEventTimeRunEvent::vfunc_6() { FUN_1401c0d90()->FUN_14047d650(0); }
MS2_REPLACE_METHOD(0x1403C54F0, GameEventTimeRunEvent, vfunc_6, 79, 0x0C44DF80);

// @0x1403c5550
void GameEventTimeRunEvent::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (m_d0.IsNull())
        return;
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403C5550, GameEventTimeRunEvent, vfunc_3, 94, 0xC268AE54);

// @0x1403c55c0
void GameEventTimeRunEvent::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new TimeRunEventContext(FUN_1402e1d00()));
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403C55C0, GameEventTimeRunEvent, vfunc_4, 170, 0xD50DD980);

// @0x1403c5670
int GameEventTimeRunEvent::FUN_1403c5670(MS2Ptr<TimeRunEventContext> spContext)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_68) == 0)
        return 0;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return 0;
    for (Unk_140165cf0* pQuest = pRoot->FUN_140165cf0("quest"); pQuest; pQuest = pQuest->FUN_140168650("quest"))
    {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest(new TimeRunEventContext::QuestContext);
        FUN_140873220(pQuest, "questID", spQuest->m_questId);
        FUN_140873220(pQuest, "distance", spQuest->m_1c);
        FUN_1408731e0(pQuest, "openingDay", spQuest->m_20);
        spContext->m_quests.SetAt(spQuest->m_questId, spQuest);
        spContext->m_1c += spQuest->m_1c;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1403C5670, GameEventTimeRunEvent, FUN_1403c5670, 608, 0x6AA1FEF2);

// @0x1403c58e0
int GameEventTimeRunEvent::FUN_1403c58e0(MS2Ptr<TimeRunEventContext> spContext)
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_70) == 0)
        return 0;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return 0;
    for (Unk_140165cf0* pReward = pRoot->FUN_140165cf0("reward"); pReward; pReward = pReward->FUN_140168650("reward"))
    {
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        int nDistance = 0;
        FUN_1408731e0(pReward, "distance", nDistance);
        spItem->vfunc_2(pReward);
        spContext->m_rewards.SetAt(nDistance, spItem);
    }
    Unk_140165cf0* pFinal = pRoot->FUN_140165cf0("final");
    if (pFinal)
        spContext->m_item.vfunc_2(pFinal);
    return 1;
}
MS2_REPLACE_METHOD(0x1403C58E0, GameEventTimeRunEvent, FUN_1403c58e0, 590, 0xC06EC853);

// The uint64 flavour of FUN_140274fc0: every token, as unsigned __int64, into the array.
// @0x1403d7cb0
unsigned __int64 FUN_1403d7cb0(const CStringW& text) { return _wcstoui64(text, NULL, 10); }
MS2_REPLACE(0x1403D7CB0, FUN_1403d7cb0, 42, 0x3B925566);

// @0x1403d7f80
void FUN_1403d7f80(CStringW& text, ATL::CAtlArray<unsigned __int64>& values, const wchar_t* delims)
{
    int nPos = 0;
    CStringW strToken = text.Tokenize(delims, nPos);
    while (!strToken.IsEmpty())
    {
        values.Add(FUN_1403d7cb0(strToken));
        strToken = text.Tokenize(delims, nPos);
    }
}
MS2_REPLACE(0x1403D7F80, FUN_1403d7f80, 191, 0x139C2656);

// ---- GameEventMassiveConstructionEvent ------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regMassiveConstructionEvent(L"GameEventMassiveConstructionEvent", FUN_1403c5b40);
#endif
// @0x1403c5b40
GameEvent* FUN_1403c5b40() { return new GameEventMassiveConstructionEvent; }

// @0x1403c5ba0
CStringW GameEventMassiveConstructionEvent::vfunc_1() { return CStringW(L"GameEventMassiveConstructionEvent"); }
MS2_REPLACE_METHOD(0x1403C5BA0, GameEventMassiveConstructionEvent, vfunc_1, 61, 0x76A01F5C);

// @0x1403c5bf0
GameEventMassiveConstructionEvent::GameEventMassiveConstructionEvent()
{
    m_d0.RemoveAll();
    m_f0 = 0;
    m_f8.RemoveAll();
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c5cb0
void GameEventMassiveConstructionEvent::vfunc_2()
{
    FUN_140274fc0(m_68, m_d0, L",");
    m_f0 = FUN_1407181a0(&m_70);
    FUN_1403d7f80(m_78, m_f8, L",");
}
MS2_REPLACE_METHOD(0x1403C5CB0, GameEventMassiveConstructionEvent, vfunc_2, 112, 0xEF12FB45);

// @0x1403c5d30
void GameEventMassiveConstructionEvent::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    unsigned nCount = (unsigned)m_d0.GetCount();
    out->WriteInt(nCount);
    for (size_t i = 0; i < nCount; i++)
        out->WriteInt(m_d0[i]);
    out->WriteInt(m_f0);
    nCount = (unsigned)m_f8.GetCount();
    out->WriteInt(nCount);
    for (size_t i = 0; i < nCount; i++)
        out->WriteInt64(m_f8[i]);
}
MS2_REPLACE_METHOD(0x1403C5D30, GameEventMassiveConstructionEvent, vfunc_3, 326, 0x892A9D0B);

// @0x1403c5e80
void GameEventMassiveConstructionEvent::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    unsigned nCount = MS2_GE_R(in)->ReadInt();
    for (unsigned i = 0; i < nCount; i++)
    {
        unsigned id = MS2_GE_R(in)->ReadInt();
        m_d0.Add(id);
    }
    m_f0 = MS2_GE_R(in)->ReadInt();
    nCount = MS2_GE_R(in)->ReadInt();
    for (unsigned i = 0; i < nCount; i++)
    {
        unsigned __int64 id = MS2_GE_R(in)->ReadInt64();
        m_f8.Add(id);
    }
}
MS2_REPLACE_METHOD(0x1403C5E80, GameEventMassiveConstructionEvent, vfunc_4, 343, 0x425DC70D);

// @0x1403c5fe0
void GameEventMassiveConstructionEvent::vfunc_5()
{
    for (unsigned i = 0; i < m_d0.GetCount(); i++)
    {
        unsigned id = m_d0[i];
        FUN_1401c0d90()->FUN_14047dba0(id, m_f0);
    }
    for (unsigned i = 0; i < m_f8.GetCount(); i++)
    {
        unsigned __int64 id = m_f8[i];
        FUN_1401c0d90()->FUN_14047df50(id);
    }
}
MS2_REPLACE_METHOD(0x1403C5FE0, GameEventMassiveConstructionEvent, vfunc_5, 237, 0x4814B149);

// @0x1403c60e0
void GameEventMassiveConstructionEvent::vfunc_6()
{
    FUN_1401c0d90()->FUN_14047dd60();
    FUN_1401c0d90()->FUN_14047e0e0();
}
MS2_REPLACE_METHOD(0x1403C60E0, GameEventMassiveConstructionEvent, vfunc_6, 40, 0xDC8EBBD4);

// ---- GameEventEnchantRate -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regEnchantRate(L"GameEventEnchantRate", FUN_1403c6110);
#endif
// @0x1403c6110
GameEvent* FUN_1403c6110() { return new GameEventEnchantRate; }

// @0x1403c6170
CStringW GameEventEnchantRate::vfunc_1() { return CStringW(L"GameEventEnchantRate"); }
MS2_REPLACE_METHOD(0x1403C6170, GameEventEnchantRate, vfunc_1, 61, 0x5D3710E8);

// @0x1403c61c0
GameEventEnchantRate::GameEventEnchantRate()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c6230
void GameEventEnchantRate::vfunc_2()
{
    m_pContext.AssignRaw(new EnchantRateEventContext);
    m_pContext->m_nEventId = m_id;
    m_pContext->m_1c = FUN_140718200(&m_68);
    m_pContext->m_20 = FUN_140718200(&m_70);
}
MS2_REPLACE_METHOD(0x1403C6230, GameEventEnchantRate, vfunc_2, 226, 0x01175DDE);

// @0x1403c6320
void GameEventEnchantRate::vfunc_5() { FUN_1401c0d90()->FUN_14047e530(m_pContext); }
MS2_REPLACE_METHOD(0x1403C6320, GameEventEnchantRate, vfunc_5, 91, 0x69FE65A3);

// @0x1403c6390
void GameEventEnchantRate::vfunc_6()
{
    // the original asserts on its member names (m_gameEventID is m_id)
    (void)((!!(m_pContext->m_nEventId == m_id)) ||
           (_wassert(L"m_pContext->m_nEventId == m_gameEventID", _CRT_WIDE(MS2_THIS_FILE), MS2_LINE(2384)), 0));
    FUN_1401c0d90()->FUN_14047e630(m_pContext->m_nEventId);
}
MS2_REPLACE_METHOD(0x1403C6390, GameEventEnchantRate, vfunc_6, 119, 0x542B45BA);

// @0x1403c6410
void GameEventEnchantRate::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_pContext->m_1c);
    out->WriteInt(m_pContext->m_20);
}
MS2_REPLACE_METHOD(0x1403C6410, GameEventEnchantRate, vfunc_3, 130, 0x62E36E92);

// @0x1403c64a0
void GameEventEnchantRate::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_pContext.AssignRaw(new EnchantRateEventContext);
    m_pContext->m_nEventId = m_id;
    m_pContext->m_1c = MS2_GE_R(in)->ReadInt();
    m_pContext->m_20 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C64A0, GameEventEnchantRate, vfunc_4, 280, 0x5427E70E);

// ---- GameEventRankDuel ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regRankDuel(L"GameEventRankDuel", FUN_1403c65c0);
#endif
// @0x1403c65c0
GameEvent* FUN_1403c65c0() { return new GameEventRankDuel; }

// @0x1403c6620
CStringW GameEventRankDuel::vfunc_1() { return CStringW(L"GameEventRankDuel"); }
MS2_REPLACE_METHOD(0x1403C6620, GameEventRankDuel, vfunc_1, 61, 0xD0C386DB);

// @0x1403c6670
GameEventRankDuel::GameEventRankDuel() : m_d8(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c66f0
void GameEventRankDuel::vfunc_2()
{
    m_d0 = m_68;
    if (!m_80.IsEmpty())
        m_d8 = FUN_1407181a0(&m_80);
}
MS2_REPLACE_METHOD(0x1403C66F0, GameEventRankDuel, vfunc_2, 101, 0x3F1E221E);

// @0x1403c6760
void GameEventRankDuel::vfunc_5() { FUN_1401c0d90()->FUN_14047e740(true); }
MS2_REPLACE_METHOD(0x1403C6760, GameEventRankDuel, vfunc_5, 29, 0xCD62C311);

// @0x1403c6790
void GameEventRankDuel::vfunc_6() { FUN_1401c0d90()->FUN_14047e740(false); }
MS2_REPLACE_METHOD(0x1403C6790, GameEventRankDuel, vfunc_6, 29, 0x2805BD5A);

// @0x1403c67c0
void GameEventRankDuel::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
}
MS2_REPLACE_METHOD(0x1403C67C0, GameEventRankDuel, vfunc_3, 74, 0xACFA5F52);

// @0x1403c6810
void GameEventRankDuel::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C6810, GameEventRankDuel, vfunc_4, 134, 0x1C2FF7FE);

// ---- GameEventGuildChampionship -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regGuildChampionship(L"GameEventGuildChampionship", FUN_1403c68a0);
#endif
// @0x1403c68a0
GameEvent* FUN_1403c68a0() { return new GameEventGuildChampionship; }

// @0x1403c6900
CStringW GameEventGuildChampionship::vfunc_1() { return CStringW(L"GameEventGuildChampionship"); }
MS2_REPLACE_METHOD(0x1403C6900, GameEventGuildChampionship, vfunc_1, 61, 0x275F1859);

// @0x1403c6950
GameEventGuildChampionship::GameEventGuildChampionship() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c69c0
void GameEventGuildChampionship::vfunc_2()
{
    if (!m_80.IsEmpty())
        m_d0 = FUN_1407181a0(&m_80);
}
MS2_REPLACE_METHOD(0x1403C69C0, GameEventGuildChampionship, vfunc_2, 71, 0x83221AF0);

// @0x1403c6a10
void GameEventGuildChampionship::vfunc_5()
{
    if (!FUN_140166410()->FUN_14036d570(0x110))
        return;
    FUN_1401c0d90()->FUN_14047e830(true);
}
MS2_REPLACE_METHOD(0x1403C6A10, GameEventGuildChampionship, vfunc_5, 56, 0x274DE2BB);

// @0x1403c6a50
void GameEventGuildChampionship::vfunc_6() { FUN_1401c0d90()->FUN_14047e830(false); }
MS2_REPLACE_METHOD(0x1403C6A50, GameEventGuildChampionship, vfunc_6, 29, 0x2BB70B0E);

// ---- GameEventQuestAdditionalReward ---------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regQuestAdditionalReward(L"GameEventQuestAdditionalReward", FUN_1403c6a80);
#endif
// @0x1403c6a80
GameEvent* FUN_1403c6a80() { return new GameEventQuestAdditionalReward; }

// @0x1403c6ae0
CStringW GameEventQuestAdditionalReward::vfunc_1() { return CStringW(L"GameEventQuestAdditionalReward"); }
MS2_REPLACE_METHOD(0x1403C6AE0, GameEventQuestAdditionalReward, vfunc_1, 61, 0xFA4D8A7E);

// @0x1403c6b30
GameEventQuestAdditionalReward::GameEventQuestAdditionalReward()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
    m_d0 = 11;
    m_d4 = 0;
    m_d8.AssignRaw(new QuestAdditionalRewardContext);
}

// @0x1403c6c10
void GameEventQuestAdditionalReward::vfunc_2()
{
    m_d0 = FUN_1407181a0(&m_68);
    m_d4 = FUN_1407181a0(&m_70);
    m_d8->Load(&m_78);
}
MS2_REPLACE_METHOD(0x1403C6C10, GameEventQuestAdditionalReward, vfunc_2, 117, 0xF78122DB);

// @0x1403c6c90
void GameEventQuestAdditionalReward::vfunc_5() { FUN_1401c0d90()->FUN_14047e8e0(m_d0, m_d4, m_d8); }
MS2_REPLACE_METHOD(0x1403C6C90, GameEventQuestAdditionalReward, vfunc_5, 114, 0x99961A1D);

// @0x1403c6d10
void GameEventQuestAdditionalReward::vfunc_6() { FUN_1401c0d90()->FUN_14047e980(m_d0, m_d4); }
MS2_REPLACE_METHOD(0x1403C6D10, GameEventQuestAdditionalReward, vfunc_6, 50, 0xF99DD3D4);

// @0x1403c6d50
void GameEventQuestAdditionalReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteShort((unsigned short)m_d0);
    out->WriteShort((unsigned short)m_d4);
    m_d8->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403C6D50, GameEventQuestAdditionalReward, vfunc_3, 122, 0x31131576);

// @0x1403c6dd0
void GameEventQuestAdditionalReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadShort();
    m_d4 = MS2_GE_R(in)->ReadShort();
    m_d8->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403C6DD0, GameEventQuestAdditionalReward, vfunc_4, 162, 0x62AD7514);

// ---- GameEventGuildSkillSale ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regGuildSkillSale(L"GameEventGuildSkillSale", FUN_1403c6e80);
#endif
// @0x1403c6e80
GameEvent* FUN_1403c6e80() { return new GameEventGuildSkillSale; }

// @0x1403c6ee0
CStringW GameEventGuildSkillSale::vfunc_1() { return CStringW(L"GameEventGuildSkillSale"); }
MS2_REPLACE_METHOD(0x1403C6EE0, GameEventGuildSkillSale, vfunc_1, 61, 0x353F259E);

// @0x1403c6f30
GameEventGuildSkillSale::GameEventGuildSkillSale() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c6fa0
void GameEventGuildSkillSale::vfunc_2() { m_d0 = FUN_1407181a0(&m_68); }
MS2_REPLACE_METHOD(0x1403C6FA0, GameEventGuildSkillSale, vfunc_2, 42, 0x02B16B0B);

// @0x1403c6fd0
void GameEventGuildSkillSale::vfunc_5() { FUN_1404234a0(FUN_140302b00()->GuildSkillSale(), m_d0); }
MS2_REPLACE_METHOD(0x1403C6FD0, GameEventGuildSkillSale, vfunc_5, 46, 0x396ECFED);

// @0x1403c7010
void GameEventGuildSkillSale::vfunc_6() { FUN_1404234a0(FUN_140302b00()->GuildSkillSale(), 0); }
MS2_REPLACE_METHOD(0x1403C7010, GameEventGuildSkillSale, vfunc_6, 37, 0xA05B3701);

// @0x1403c7040
void GameEventGuildSkillSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C7040, GameEventGuildSkillSale, vfunc_3, 61, 0xCB9AEBE1);

// @0x1403c7090
void GameEventGuildSkillSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C7090, GameEventGuildSkillSale, vfunc_4, 79, 0xF3AF033C);

// ---- GameEventGuildPersonalSkillSale --------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regGuildPersonalSkillSale(L"GameEventGuildPersonalSkillSale", FUN_1403c70f0);
#endif
// @0x1403c70f0
GameEvent* FUN_1403c70f0() { return new GameEventGuildPersonalSkillSale; }

// @0x1403c7150
CStringW GameEventGuildPersonalSkillSale::vfunc_1() { return CStringW(L"GameEventGuildPersonalSkillSale"); }
MS2_REPLACE_METHOD(0x1403C7150, GameEventGuildPersonalSkillSale, vfunc_1, 61, 0x4C2BD31D);

// @0x1403c71a0
GameEventGuildPersonalSkillSale::GameEventGuildPersonalSkillSale() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c7210
void GameEventGuildPersonalSkillSale::vfunc_2() { m_d0 = FUN_1407181a0(&m_68); }
MS2_REPLACE_METHOD(0x1403C7210, GameEventGuildPersonalSkillSale, vfunc_2, 42, 0xE4F2E4E1);

// @0x1403c7240
void GameEventGuildPersonalSkillSale::vfunc_5() { FUN_1404235b0(FUN_140302b00()->GuildPersonalSkillSale(), m_d0); }
MS2_REPLACE_METHOD(0x1403C7240, GameEventGuildPersonalSkillSale, vfunc_5, 46, 0xB5FD3289);

// @0x1403c7280
void GameEventGuildPersonalSkillSale::vfunc_6() { FUN_1404235b0(FUN_140302b00()->GuildPersonalSkillSale(), 0); }
MS2_REPLACE_METHOD(0x1403C7280, GameEventGuildPersonalSkillSale, vfunc_6, 37, 0x74E6D016);

// @0x1403c72b0
void GameEventGuildPersonalSkillSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C72B0, GameEventGuildPersonalSkillSale, vfunc_3, 61, 0xA598974C);

// @0x1403c7300
void GameEventGuildPersonalSkillSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C7300, GameEventGuildPersonalSkillSale, vfunc_4, 79, 0x85989779);

// ---- GameEventGuildExp ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regGuildExp(L"GameEventGuildExp", FUN_1403c7360);
#endif
// @0x1403c7360
GameEvent* FUN_1403c7360() { return new GameEventGuildExp; }

// @0x1403c73c0
CStringW GameEventGuildExp::vfunc_1() { return CStringW(L"GameEventGuildExp"); }
MS2_REPLACE_METHOD(0x1403C73C0, GameEventGuildExp, vfunc_1, 61, 0x872D1709);

// @0x1403c7410
GameEventGuildExp::GameEventGuildExp() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c7480
void GameEventGuildExp::vfunc_2() { m_d0 = FUN_1407181a0(&m_68); }
MS2_REPLACE_METHOD(0x1403C7480, GameEventGuildExp, vfunc_2, 42, 0x65204B4F);

// @0x1403c74b0
void GameEventGuildExp::vfunc_5()
{
    FUN_1404236c0(FUN_140302b00()->GuildExp(), m_d0);
    FUN_1403ed290()->FUN_1413bd640(FUN_140423670(FUN_140302b00()->GuildExp()) > 0);
}
MS2_REPLACE_METHOD(0x1403C74B0, GameEventGuildExp, vfunc_5, 101, 0xE18D34FE);

// @0x1403c7520
void GameEventGuildExp::vfunc_6()
{
    FUN_1404236c0(FUN_140302b00()->GuildExp(), 0);
    FUN_1403ed290()->FUN_1413bd640(FUN_140423670(FUN_140302b00()->GuildExp()) > 0);
}
MS2_REPLACE_METHOD(0x1403C7520, GameEventGuildExp, vfunc_6, 92, 0x199CB83D);

// @0x1403c7590
void GameEventGuildExp::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C7590, GameEventGuildExp, vfunc_3, 61, 0xD36E6E5B);

// @0x1403c75e0
void GameEventGuildExp::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C75E0, GameEventGuildExp, vfunc_4, 79, 0x4BB6E3B6);

// ---- GameEventGuildFund ---------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regGuildFund(L"GameEventGuildFund", FUN_1403c7640);
#endif
// @0x1403c7640
GameEvent* FUN_1403c7640() { return new GameEventGuildFund; }

// @0x1403c76a0
CStringW GameEventGuildFund::vfunc_1() { return CStringW(L"GameEventGuildFund"); }
MS2_REPLACE_METHOD(0x1403C76A0, GameEventGuildFund, vfunc_1, 61, 0x6B63AA40);

// @0x1403c76f0
GameEventGuildFund::GameEventGuildFund() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c7760
void GameEventGuildFund::vfunc_2() { m_d0 = FUN_1407181a0(&m_68); }
MS2_REPLACE_METHOD(0x1403C7760, GameEventGuildFund, vfunc_2, 42, 0x82DACA1A);

// @0x1403c7790
void GameEventGuildFund::vfunc_5() { FUN_1404237d0(FUN_140302b00()->GuildFund(), m_d0); }
MS2_REPLACE_METHOD(0x1403C7790, GameEventGuildFund, vfunc_5, 46, 0x48EF6819);

// @0x1403c77d0
void GameEventGuildFund::vfunc_6() { FUN_1404237d0(FUN_140302b00()->GuildFund(), 0); }
MS2_REPLACE_METHOD(0x1403C77D0, GameEventGuildFund, vfunc_6, 37, 0x6FB11BD3);

// @0x1403c7800
void GameEventGuildFund::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C7800, GameEventGuildFund, vfunc_3, 61, 0x6C56B339);

// @0x1403c7850
void GameEventGuildFund::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C7850, GameEventGuildFund, vfunc_4, 79, 0xCC7FB574);

// ---- GameEventGuildCoin ---------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regGuildCoin(L"GameEventGuildCoin", FUN_1403c78b0);
#endif
// @0x1403c78b0
GameEvent* FUN_1403c78b0() { return new GameEventGuildCoin; }

// @0x1403c7910
CStringW GameEventGuildCoin::vfunc_1() { return CStringW(L"GameEventGuildCoin"); }
MS2_REPLACE_METHOD(0x1403C7910, GameEventGuildCoin, vfunc_1, 61, 0x362C4297);

// @0x1403c7960
GameEventGuildCoin::GameEventGuildCoin() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c79d0
void GameEventGuildCoin::vfunc_2() { m_d0 = FUN_1407181a0(&m_68); }
MS2_REPLACE_METHOD(0x1403C79D0, GameEventGuildCoin, vfunc_2, 42, 0x0E909E99);

// @0x1403c7a00
void GameEventGuildCoin::vfunc_5() { FUN_1404238e0(FUN_140302b00()->GuildCoin(), m_d0); }
MS2_REPLACE_METHOD(0x1403C7A00, GameEventGuildCoin, vfunc_5, 46, 0x16A44E78);

// @0x1403c7a40
void GameEventGuildCoin::vfunc_6() { FUN_1404238e0(FUN_140302b00()->GuildCoin(), 0); }
MS2_REPLACE_METHOD(0x1403C7A40, GameEventGuildCoin, vfunc_6, 37, 0xD8029974);

// @0x1403c7a70
void GameEventGuildCoin::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C7A70, GameEventGuildCoin, vfunc_3, 61, 0x0B1A74CF);

// @0x1403c7ac0
void GameEventGuildCoin::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C7AC0, GameEventGuildCoin, vfunc_4, 79, 0x114CC551);

// ---- GameEventMasteryReward -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regMasteryReward(L"GameEventMasteryReward", FUN_1403c7b20);
#endif
// @0x1403c7b20
GameEvent* FUN_1403c7b20() { return new GameEventMasteryReward; }

// @0x1403c7b80
CStringW GameEventMasteryReward::vfunc_1() { return CStringW(L"GameEventMasteryReward"); }
MS2_REPLACE_METHOD(0x1403C7B80, GameEventMasteryReward, vfunc_1, 61, 0xD35040E8);

// @0x1403c7bd0
GameEventMasteryReward::GameEventMasteryReward()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
    m_d0 = 0;
}

// @0x1403c7c50
void GameEventMasteryReward::vfunc_2()
{
    m_d0 = FUN_1407181a0(&m_68);
    m_d8 = m_70;
}
MS2_REPLACE_METHOD(0x1403C7C50, GameEventMasteryReward, vfunc_2, 72, 0x8C04152C);

// @0x1403c7ca0
void GameEventMasteryReward::vfunc_5()
{
    if (m_d0 == 0)
        return;
    FUN_140423b10(FUN_140302b00()->MasteryReward(), m_id, m_d0, m_d8);
}
MS2_REPLACE_METHOD(0x1403C7CA0, GameEventMasteryReward, vfunc_5, 95, 0xCEFD2DB8);

// @0x1403c7d10
void GameEventMasteryReward::vfunc_6() { FUN_140423da0(FUN_140302b00()->MasteryReward(), m_id); }
MS2_REPLACE_METHOD(0x1403C7D10, GameEventMasteryReward, vfunc_6, 43, 0x57F16CC7);

// @0x1403c7d50
void GameEventMasteryReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}
MS2_REPLACE_METHOD(0x1403C7D50, GameEventMasteryReward, vfunc_3, 101, 0x0F899DB2);

// @0x1403c7dc0
void GameEventMasteryReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C7DC0, GameEventMasteryReward, vfunc_4, 179, 0x2141B150);

// ---- GameEventMeratMarketOpenTab ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regMeratMarketOpenTab(L"GameEventMeratMarketOpenTab", FUN_1403c7e80);
#endif
// @0x1403c7e80
GameEvent* FUN_1403c7e80() { return new GameEventMeratMarketOpenTab; }

// @0x1403c7ee0
CStringW GameEventMeratMarketOpenTab::vfunc_1() { return CStringW(L"GameEventMeratMarketOpenTab"); }
MS2_REPLACE_METHOD(0x1403C7EE0, GameEventMeratMarketOpenTab, vfunc_1, 61, 0x4E8C3DA0);

// @0x1403c7f30
GameEventMeratMarketOpenTab::GameEventMeratMarketOpenTab()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c7fa0
void GameEventMeratMarketOpenTab::vfunc_2() { m_d0 = FUN_140718600(m_68); }
MS2_REPLACE_METHOD(0x1403C7FA0, GameEventMeratMarketOpenTab, vfunc_2, 97, 0xAA34B383);

// @0x1403c8010
void GameEventMeratMarketOpenTab::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
}
MS2_REPLACE_METHOD(0x1403C8010, GameEventMeratMarketOpenTab, vfunc_3, 74, 0x33840CEA);

// @0x1403c8060
void GameEventMeratMarketOpenTab::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C8060, GameEventMeratMarketOpenTab, vfunc_4, 134, 0xBFB0DF06);

// @0x1403c80f0
void GameEventMeratMarketOpenTab::vfunc_5() { FUN_140424040(FUN_140302b00()->MeratMarketOpenTab(), m_d0); }
MS2_REPLACE_METHOD(0x1403C80F0, GameEventMeratMarketOpenTab, vfunc_5, 59, 0x623AFBA5);

// @0x1403c8140
void GameEventMeratMarketOpenTab::vfunc_6()
{
    CStringW strEmpty(L"");
    FUN_140424040(FUN_140302b00()->MeratMarketOpenTab(), strEmpty);
}
MS2_REPLACE_METHOD(0x1403C8140, GameEventMeratMarketOpenTab, vfunc_6, 80, 0x2E26EE7B);

// ---- GameEventWorldmapIcon ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regWorldmapIcon(L"GameEventWorldmapIcon", FUN_1403c81a0);
#endif
// @0x1403c81a0
GameEvent* FUN_1403c81a0() { return new GameEventWorldmapIcon; }

// @0x1403c8200
CStringW GameEventWorldmapIcon::vfunc_1() { return CStringW(L"GameEventWorldmapIcon"); }
MS2_REPLACE_METHOD(0x1403C8200, GameEventWorldmapIcon, vfunc_1, 61, 0x9F63268F);

// @0x1403c8250
GameEventWorldmapIcon::GameEventWorldmapIcon()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c82c0
void GameEventWorldmapIcon::vfunc_2() { m_d0 = m_68; }
MS2_REPLACE_METHOD(0x1403C82C0, GameEventWorldmapIcon, vfunc_2, 44, 0x3A4EA00A);

// @0x1403c8300
void GameEventWorldmapIcon::vfunc_5() {}
MS2_REPLACE_METHOD(0x1403C8300, GameEventWorldmapIcon, vfunc_5, 6, 0xA9AF6E37);

// @0x1403c8310
void GameEventWorldmapIcon::vfunc_6() {}
MS2_REPLACE_METHOD(0x1403C8310, GameEventWorldmapIcon, vfunc_6, 6, 0xA9AF6E37);

// @0x1403c8320
void GameEventWorldmapIcon::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
}
MS2_REPLACE_METHOD(0x1403C8320, GameEventWorldmapIcon, vfunc_3, 74, 0x90D7B421);

// @0x1403c8370
void GameEventWorldmapIcon::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C8370, GameEventWorldmapIcon, vfunc_4, 134, 0x4F43BF29);

// ---- GameEventMasteryReduce -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regMasteryReduce(L"GameEventMasteryReduce", FUN_1403c8400);
#endif
// @0x1403c8400
GameEvent* FUN_1403c8400() { return new GameEventMasteryReduce; }

// @0x1403c8460
CStringW GameEventMasteryReduce::vfunc_1() { return CStringW(L"GameEventMasteryReduce"); }
MS2_REPLACE_METHOD(0x1403C8460, GameEventMasteryReduce, vfunc_1, 61, 0x6E5ADEFA);

// @0x1403c84b0
GameEventMasteryReduce::GameEventMasteryReduce()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c8510
void GameEventMasteryReduce::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403C8510, GameEventMasteryReduce, vfunc_2, 42, 0xD5B9BC39);

// @0x1403c8540
void GameEventMasteryReduce::vfunc_5() { FUN_140424130(FUN_140302b00()->MasteryReduce(), m_d0); }
MS2_REPLACE_METHOD(0x1403C8540, GameEventMasteryReduce, vfunc_5, 46, 0x889011F9);

// @0x1403c8580
void GameEventMasteryReduce::vfunc_6() { FUN_140424130(FUN_140302b00()->MasteryReduce(), 0); }
MS2_REPLACE_METHOD(0x1403C8580, GameEventMasteryReduce, vfunc_6, 37, 0x3AE96BBF);

// @0x1403c85b0
void GameEventMasteryReduce::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C85B0, GameEventMasteryReduce, vfunc_3, 61, 0x716A8CCB);

// @0x1403c8600
void GameEventMasteryReduce::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C8600, GameEventMasteryReduce, vfunc_4, 79, 0x568F6686);

// ---- GameEventUGCMapContractSale ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regUGCMapContractSale(L"GameEventUGCMapContractSale", FUN_1403c8660);
#endif
// @0x1403c8660
GameEvent* FUN_1403c8660() { return new GameEventUGCMapContractSale; }

// @0x1403c86c0
CStringW GameEventUGCMapContractSale::vfunc_1() { return CStringW(L"GameEventUGCMapContractSale"); }
MS2_REPLACE_METHOD(0x1403C86C0, GameEventUGCMapContractSale, vfunc_1, 61, 0x1AF8ADCA);

// @0x1403c8710
GameEventUGCMapContractSale::GameEventUGCMapContractSale() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c8780
void GameEventUGCMapContractSale::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403C8780, GameEventUGCMapContractSale, vfunc_2, 42, 0x28D4D427);

// @0x1403c87b0
void GameEventUGCMapContractSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C87B0, GameEventUGCMapContractSale, vfunc_3, 61, 0x83765A39);

// @0x1403c8800
void GameEventUGCMapContractSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C8800, GameEventUGCMapContractSale, vfunc_4, 79, 0x3CEA8454);

// @0x1403c8860
void GameEventUGCMapContractSale::vfunc_5() { FUN_1401c0d90()->FUN_140479640(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C8860, GameEventUGCMapContractSale, vfunc_5, 47, 0x1E1D85C1);

// @0x1403c88a0
void GameEventUGCMapContractSale::vfunc_6() { FUN_1401c0d90()->FUN_1404796b0(m_id); }
MS2_REPLACE_METHOD(0x1403C88A0, GameEventUGCMapContractSale, vfunc_6, 35, 0x88C86AFF);

// ---- GameEventUGCMapExtensionSale -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regUGCMapExtensionSale(L"GameEventUGCMapExtensionSale", FUN_1403c88d0);
#endif
// @0x1403c88d0
GameEvent* FUN_1403c88d0() { return new GameEventUGCMapExtensionSale; }

// @0x1403c8930
CStringW GameEventUGCMapExtensionSale::vfunc_1() { return CStringW(L"GameEventUGCMapExtensionSale"); }
MS2_REPLACE_METHOD(0x1403C8930, GameEventUGCMapExtensionSale, vfunc_1, 61, 0x164B8C71);

// @0x1403c8980
GameEventUGCMapExtensionSale::GameEventUGCMapExtensionSale() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c89f0
void GameEventUGCMapExtensionSale::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403C89F0, GameEventUGCMapExtensionSale, vfunc_2, 42, 0xEAD35C6C);

// @0x1403c8a20
void GameEventUGCMapExtensionSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403C8A20, GameEventUGCMapExtensionSale, vfunc_3, 61, 0x60A945AF);

// @0x1403c8a70
void GameEventUGCMapExtensionSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403C8A70, GameEventUGCMapExtensionSale, vfunc_4, 79, 0x4C71D44A);

// @0x1403c8ad0
void GameEventUGCMapExtensionSale::vfunc_5() { FUN_1401c0d90()->FUN_140479790(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403C8AD0, GameEventUGCMapExtensionSale, vfunc_5, 47, 0x7ABE58BB);

// @0x1403c8b10
void GameEventUGCMapExtensionSale::vfunc_6() { FUN_1401c0d90()->FUN_140479800(m_id); }
MS2_REPLACE_METHOD(0x1403C8B10, GameEventUGCMapExtensionSale, vfunc_6, 35, 0xB5927B20);

// ---- GameEventConstructShowItem -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regConstructShowItem(L"GameEventConstructShowItem", FUN_1403c8b40);
#endif
// @0x1403c8b40
GameEvent* FUN_1403c8b40() { return new GameEventConstructShowItem; }

// @0x1403c8ba0
CStringW GameEventConstructShowItem::vfunc_1() { return CStringW(L"GameEventConstructShowItem"); }
MS2_REPLACE_METHOD(0x1403C8BA0, GameEventConstructShowItem, vfunc_1, 61, 0x16234975);

// @0x1403c8bf0
GameEventConstructShowItem::GameEventConstructShowItem() : m_d0(0), m_d8(L""), m_e0(0), m_108(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c8cb0
void GameEventConstructShowItem::vfunc_2()
{
    m_d0 = FUN_140718200(&m_68);
    m_d8 = FUN_140718600(m_70);
    m_e0 = FUN_140718200(&m_78);
    FUN_140274fc0(m_80, m_e8, L",");
}
MS2_REPLACE_METHOD(0x1403C8CB0, GameEventConstructShowItem, vfunc_2, 191, 0x8BED3EDA);

// @0x1403c8d80
void GameEventConstructShowItem::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
    out->WriteShort((unsigned short)m_e0);
    out->WriteShort((unsigned short)m_e8.GetCount());
    for (size_t i = 0; i < m_e8.GetCount(); i++)
    {
        unsigned nItemId = m_e8[i];
        out->WriteInt(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403C8D80, GameEventConstructShowItem, vfunc_3, 279, 0x091D9521);

// @0x1403c8ea0
void GameEventConstructShowItem::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
    m_e0 = MS2_GE_R(in)->ReadShort();
    size_t nCount = MS2_GE_R(in)->ReadShort();
    for (size_t i = 0; i < nCount; i++)
    {
        unsigned nItemId = MS2_GE_R(in)->ReadInt();
        m_e8.Add(nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403C8EA0, GameEventConstructShowItem, vfunc_4, 422, 0x0FEEC4C1);

// @0x1403c9050
void GameEventConstructShowItem::vfunc_5()
{
    if (m_d8.IsEmpty())
        m_108 = FUN_140df20a0(m_d0, m_e0);
    else
        m_108 = FUN_140df2130(m_d8, m_e0);
    for (unsigned i = 0; i < m_e8.GetCount(); i++)
    {
        unsigned nItemId = m_e8[i];
        FUN_140df1f40(m_108, nItemId);
    }
}
MS2_REPLACE_METHOD(0x1403C9050, GameEventConstructShowItem, vfunc_5, 260, 0xE6FCC000);

// @0x1403c9160
void GameEventConstructShowItem::vfunc_6() { FUN_140df2210(m_108); }
MS2_REPLACE_METHOD(0x1403C9160, GameEventConstructShowItem, vfunc_6, 30, 0x417D1A43);

// ---- GameEventTransferItemBound -------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regTransferItemBound(L"GameEventTransferItemBound", FUN_1403c9190);
#endif
// @0x1403c9190
GameEvent* FUN_1403c9190() { return new GameEventTransferItemBound; }

// @0x1403c91f0
CStringW GameEventTransferItemBound::vfunc_1() { return CStringW(L"GameEventTransferItemBound"); }
MS2_REPLACE_METHOD(0x1403C91F0, GameEventTransferItemBound, vfunc_1, 61, 0x055A17FE);

// @0x1403c9240
GameEventTransferItemBound::GameEventTransferItemBound() : m_d0(true)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c92b0
void GameEventTransferItemBound::vfunc_2()
{
    if (!m_68.IsEmpty())
        m_d0 = FUN_1407183f0(&m_68);
}
MS2_REPLACE_METHOD(0x1403C92B0, GameEventTransferItemBound, vfunc_2, 67, 0x41D5E5F7);

// @0x1403c9300
void GameEventTransferItemBound::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteBool(m_d0);
}
MS2_REPLACE_METHOD(0x1403C9300, GameEventTransferItemBound, vfunc_3, 61, 0xE304EFF0);

// @0x1403c9350
void GameEventTransferItemBound::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadBool();
}
MS2_REPLACE_METHOD(0x1403C9350, GameEventTransferItemBound, vfunc_4, 78, 0x7AF36612);

// @0x1403c93b0
void GameEventTransferItemBound::vfunc_5() { FUN_1401c0d90()->SetTransferItemBound(m_d0); }
MS2_REPLACE_METHOD(0x1403C93B0, GameEventTransferItemBound, vfunc_5, 39, 0x1D75E411);

// @0x1403c93e0
void GameEventTransferItemBound::vfunc_6() { FUN_1401c0d90()->SetTransferItemBound(!m_d0); }
MS2_REPLACE_METHOD(0x1403C93E0, GameEventTransferItemBound, vfunc_6, 60, 0xFF7D7960);

// ---- GameEventSaleItemsRestricted -----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleItemsRestricted(L"GameEventSaleItemsRestricted", FUN_1403c9430);
#endif
// @0x1403c9430
GameEvent* FUN_1403c9430() { return new GameEventSaleItemsRestricted; }

// @0x1403c9490
CStringW GameEventSaleItemsRestricted::vfunc_1() { return CStringW(L"GameEventSaleItemsRestricted"); }
MS2_REPLACE_METHOD(0x1403C9490, GameEventSaleItemsRestricted, vfunc_1, 61, 0x5751C17B);

// @0x1403c94e0
GameEventSaleItemsRestricted::GameEventSaleItemsRestricted()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c9550
void GameEventSaleItemsRestricted::vfunc_2()
{
    if (!m_68.IsEmpty())
        FUN_140274fc0(m_68, m_d0, CStringW(","));
}
MS2_REPLACE_METHOD(0x1403C9550, GameEventSaleItemsRestricted, vfunc_2, 149, 0x2587F906);

// @0x1403c95f0
void GameEventSaleItemsRestricted::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}
MS2_REPLACE_METHOD(0x1403C95F0, GameEventSaleItemsRestricted, vfunc_3, 58, 0x0C2E8B42);

// @0x1403c9630
void GameEventSaleItemsRestricted::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.RemoveAll();
    MS2_GE_IN(in) >> m_d0;
}
MS2_REPLACE_METHOD(0x1403C9630, GameEventSaleItemsRestricted, vfunc_4, 81, 0x89DCC8A7);

// @0x1403c9690
void GameEventSaleItemsRestricted::vfunc_5()
{
    if (m_d0.IsEmpty())
        return;
    FUN_1404249f0(FUN_140302b00()->SaleItemsRestricted(), m_d0);
}
MS2_REPLACE_METHOD(0x1403C9690, GameEventSaleItemsRestricted, vfunc_5, 87, 0xA29CA15B);

// @0x1403c96f0
void GameEventSaleItemsRestricted::vfunc_6() { FUN_140424ae0(FUN_140302b00()->SaleItemsRestricted()); }
MS2_REPLACE_METHOD(0x1403C96F0, GameEventSaleItemsRestricted, vfunc_6, 35, 0xE41DF6E7);

// ---- GameEventUgcMapCommendationGM ----------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regUgcMapCommendationGM(L"GameEventUgcMapCommendationGM", FUN_1403c9720);
#endif
// @0x1403c9720
GameEvent* FUN_1403c9720() { return new GameEventUgcMapCommendationGM; }

// @0x1403c9780
CStringW GameEventUgcMapCommendationGM::vfunc_1() { return CStringW(L"GameEventUgcMapCommendationGM"); }
MS2_REPLACE_METHOD(0x1403C9780, GameEventUgcMapCommendationGM, vfunc_1, 61, 0x37F13374);

// @0x1403c97d0
GameEventUgcMapCommendationGM::GameEventUgcMapCommendationGM()
{
    m_d0 = 0;
    m_d8 = 0;
    m_e0 = L"";
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c9880
void GameEventUgcMapCommendationGM::vfunc_2()
{
    m_d0 = FUN_1407181a0(&m_68);
    m_d8 = FUN_140718370(&m_70);
    m_e0 = m_78;
}
MS2_REPLACE_METHOD(0x1403C9880, GameEventUgcMapCommendationGM, vfunc_2, 101, 0xF623363A);

// @0x1403c98f0
void GameEventUgcMapCommendationGM::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt64(m_d8);
    out->WriteStringW(m_e0);
}
MS2_REPLACE_METHOD(0x1403C98F0, GameEventUgcMapCommendationGM, vfunc_3, 129, 0xC2CC5233);

// @0x1403c9980
void GameEventUgcMapCommendationGM::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadInt64();
    m_e0 = MS2_GE_R(in)->ReadStringW();
}
MS2_REPLACE_METHOD(0x1403C9980, GameEventUgcMapCommendationGM, vfunc_4, 225, 0x40094F89);

// @0x1403c9a70
void GameEventUgcMapCommendationGM::vfunc_5() { FUN_1401c0d90()->FUN_1404784b0(m_d0, m_d8, m_e0); }
MS2_REPLACE_METHOD(0x1403C9A70, GameEventUgcMapCommendationGM, vfunc_5, 115, 0x22E4A6EC);

// @0x1403c9af0
void GameEventUgcMapCommendationGM::vfunc_6() { FUN_1401c0d90()->FUN_140478640(m_d0); }
MS2_REPLACE_METHOD(0x1403C9AF0, GameEventUgcMapCommendationGM, vfunc_6, 38, 0x26132507);

// ---- GameEventDeleteUrlCache ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regDeleteUrlCache(L"GameEventDeleteUrlCache", FUN_1403c9b20);
#endif
// @0x1403c9b20
GameEvent* FUN_1403c9b20() { return new GameEventDeleteUrlCache; }

// @0x1403c9b80
CStringW GameEventDeleteUrlCache::vfunc_1() { return CStringW(L"GameEventDeleteUrlCache"); }
MS2_REPLACE_METHOD(0x1403C9B80, GameEventDeleteUrlCache, vfunc_1, 61, 0x52EC09CC);

// @0x1403c9bd0
GameEventDeleteUrlCache::GameEventDeleteUrlCache() : m_d0(0)
{
    FUN_1402e3480(2);
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c9c50
void GameEventDeleteUrlCache::vfunc_2() { m_d0 = FUN_1407181a0(&m_68); }
MS2_REPLACE_METHOD(0x1403C9C50, GameEventDeleteUrlCache, vfunc_2, 42, 0x5A54E61A);

// @0x1403c9c80
void GameEventDeleteUrlCache::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteByte((unsigned char)m_d0);
}
MS2_REPLACE_METHOD(0x1403C9C80, GameEventDeleteUrlCache, vfunc_3, 62, 0xED75FA3A);

// @0x1403c9cd0
void GameEventDeleteUrlCache::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadByte();
}
MS2_REPLACE_METHOD(0x1403C9CD0, GameEventDeleteUrlCache, vfunc_4, 82, 0xC85C5644);

// @0x1403c9d30
void GameEventDeleteUrlCache::vfunc_5() { FUN_1401c0d90()->FUN_140478a40(m_d0); }
MS2_REPLACE_METHOD(0x1403C9D30, GameEventDeleteUrlCache, vfunc_5, 38, 0x9737F55E);

// @0x1403c9d60
void GameEventDeleteUrlCache::vfunc_6() { FUN_1401c0d90()->FUN_140478a40(0); }
MS2_REPLACE_METHOD(0x1403C9D60, GameEventDeleteUrlCache, vfunc_6, 29, 0x9173CFD7);

// ---- GameEventPetMastery --------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regPetMastery(L"GameEventPetMastery", FUN_1403c9d90);
#endif
// @0x1403c9d90
GameEvent* FUN_1403c9d90() { return new GameEventPetMastery; }

// @0x1403c9df0
CStringW GameEventPetMastery::vfunc_1() { return CStringW(L"GameEventPetMastery"); }
MS2_REPLACE_METHOD(0x1403C9DF0, GameEventPetMastery, vfunc_1, 61, 0x1A3DF688);

// @0x1403c9e40
GameEventPetMastery::GameEventPetMastery() : m_d0(0), m_d4(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403c9ec0
void GameEventPetMastery::vfunc_2()
{
    ATL::CAtlArray<unsigned> types;
    ATL::CAtlArray<unsigned> values;
    FUN_140274fc0(m_68, types, L",");
    FUN_140274fc0(m_70, values, L",");
    if (types.IsEmpty() || values.IsEmpty())
        return;
    if (types.GetCount() != values.GetCount())
        return;
    for (unsigned i = 0; i < types.GetCount(); i++)
    {
        if (types[i] == 1)
            m_d0 = values[i];
        else if (types[i] == 2)
            m_d4 = values[i];
    }
}
MS2_REPLACE_METHOD(0x1403C9EC0, GameEventPetMastery, vfunc_2, 419, 0x7A2472EC);

// @0x1403ca070
void GameEventPetMastery::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt(m_d4);
}
MS2_REPLACE_METHOD(0x1403CA070, GameEventPetMastery, vfunc_3, 88, 0xDE8A4540);

// @0x1403ca0d0
void GameEventPetMastery::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CA0D0, GameEventPetMastery, vfunc_4, 124, 0xD0D78123);

// @0x1403ca160
void GameEventPetMastery::vfunc_5()
{
    FUN_1401c0d90()->FUN_14047ef70(m_id, m_d0);
    FUN_1401c0d90()->FUN_14047f180(m_id, m_d4);
}
MS2_REPLACE_METHOD(0x1403CA160, GameEventPetMastery, vfunc_5, 80, 0xC297F8CB);

// @0x1403ca1c0
void GameEventPetMastery::vfunc_6()
{
    FUN_1401c0d90()->FUN_14047efe0(m_id);
    FUN_1401c0d90()->FUN_14047f1f0(m_id);
}
MS2_REPLACE_METHOD(0x1403CA1C0, GameEventPetMastery, vfunc_6, 56, 0x17A2B462);

// ---- GameEventPetBattleExp ------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regPetBattleExp(L"GameEventPetBattleExp", FUN_1403ca200);
#endif
// @0x1403ca200
GameEvent* FUN_1403ca200() { return new GameEventPetBattleExp; }

// @0x1403ca260
CStringW GameEventPetBattleExp::vfunc_1() { return CStringW(L"GameEventPetBattleExp"); }
MS2_REPLACE_METHOD(0x1403CA260, GameEventPetBattleExp, vfunc_1, 61, 0x5999CF35);

// @0x1403ca2b0
GameEventPetBattleExp::GameEventPetBattleExp() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403ca320
void GameEventPetBattleExp::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403CA320, GameEventPetBattleExp, vfunc_2, 42, 0x69C58673);

// @0x1403ca350
void GameEventPetBattleExp::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403CA350, GameEventPetBattleExp, vfunc_3, 61, 0x7171311C);

// @0x1403ca3a0
void GameEventPetBattleExp::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CA3A0, GameEventPetBattleExp, vfunc_4, 79, 0x6B14DA29);

// @0x1403ca400
void GameEventPetBattleExp::vfunc_5() { FUN_1401c0d90()->FUN_14047f390(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403CA400, GameEventPetBattleExp, vfunc_5, 47, 0x87E55C7F);

// @0x1403ca440
void GameEventPetBattleExp::vfunc_6() { FUN_1401c0d90()->FUN_14047f400(m_id); }
MS2_REPLACE_METHOD(0x1403CA440, GameEventPetBattleExp, vfunc_6, 35, 0xD43D95A8);

// ---- GameEventPetComposeSale ----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regPetComposeSale(L"GameEventPetComposeSale", FUN_1403ca470);
#endif
// @0x1403ca470
GameEvent* FUN_1403ca470() { return new GameEventPetComposeSale; }

// @0x1403ca4d0
CStringW GameEventPetComposeSale::vfunc_1() { return CStringW(L"GameEventPetComposeSale"); }
MS2_REPLACE_METHOD(0x1403CA4D0, GameEventPetComposeSale, vfunc_1, 61, 0xA9C55261);

// @0x1403ca520
GameEventPetComposeSale::GameEventPetComposeSale() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403ca590
void GameEventPetComposeSale::vfunc_2() { m_d0 = FUN_140718200(&m_68); }
MS2_REPLACE_METHOD(0x1403CA590, GameEventPetComposeSale, vfunc_2, 42, 0xFD0C0C19);

// @0x1403ca5c0
void GameEventPetComposeSale::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}
MS2_REPLACE_METHOD(0x1403CA5C0, GameEventPetComposeSale, vfunc_3, 61, 0x0EEFF51B);

// @0x1403ca610
void GameEventPetComposeSale::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}
MS2_REPLACE_METHOD(0x1403CA610, GameEventPetComposeSale, vfunc_4, 79, 0x47594ED6);

// @0x1403ca670
void GameEventPetComposeSale::vfunc_5() { FUN_1401c0d90()->FUN_14047f590(m_id, m_d0); }
MS2_REPLACE_METHOD(0x1403CA670, GameEventPetComposeSale, vfunc_5, 47, 0x7AD9EAA4);

// @0x1403ca6b0
void GameEventPetComposeSale::vfunc_6() { FUN_1401c0d90()->FUN_14047f600(m_id); }
MS2_REPLACE_METHOD(0x1403CA6B0, GameEventPetComposeSale, vfunc_6, 35, 0x448E3F17);

// ---- GameEventItemBox -----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regItemBox(L"GameEventItemBox", FUN_1403ca6e0);
#endif
// @0x1403ca6e0
GameEvent* FUN_1403ca6e0() { return new GameEventItemBox; }

// @0x1403ca740
CStringW GameEventItemBox::vfunc_1() { return CStringW(L"GameEventItemBox"); }
MS2_REPLACE_METHOD(0x1403CA740, GameEventItemBox, vfunc_1, 61, 0x0AF964E2);

// @0x1403ca790
GameEventItemBox::GameEventItemBox() : m_d0(0), m_e0(false)
{
    FUN_1402e3480(3);
    FUN_1402e3480(1);
}

// @0x1403ca810
void GameEventItemBox::vfunc_2()
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_68) == 0)
        return;
    MS2Ptr<ItemBoxEventContext> spBox(new ItemBoxEventContext);
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    spBox->m_3c = m_id;
    spBox->Load(pRoot);
    m_d0 = spBox;
}
MS2_REPLACE_METHOD(0x1403CA810, GameEventItemBox, vfunc_2, 319, 0x2F681F5C);

// @0x1403ca960
void GameEventItemBox::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    if (m_d0 == 0)
        m_d0.AssignRaw(new ItemBoxEventContext);
    m_d0->Write(MS2_GE_OUT(out));
}
MS2_REPLACE_METHOD(0x1403CA960, GameEventItemBox, vfunc_3, 186, 0x8A3F3283);

// @0x1403caa20
void GameEventItemBox::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.AssignRaw(new ItemBoxEventContext);
    m_d0->Read(*reinterpret_cast<CInPacket*>(in));
}
MS2_REPLACE_METHOD(0x1403CAA20, GameEventItemBox, vfunc_4, 158, 0xEF0D903E);

// The open box dialog of the item box event (RTTI .?AVUIItemEventOpenBoxDialog@@, class id 0x4f42): only the refresh
// vfunc_5 calls.
class UIItemEventOpenBoxDialog : public UIDialog
{
public:
    void FUN_140e48050();
};

// The ui object of a class id cast to its dialog class (0 while the ui service is not up).
template <class T> T* Unk_GameEventDialog(eUIClassID nClass)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// @0x1403caad0
void GameEventItemBox::vfunc_5()
{
    m_e0 = FUN_1404246b0(FUN_140302b00()->ItemBox(), m_d0);
    if (UIItemEventOpenBoxDialog* pDialog = Unk_GameEventDialog<UIItemEventOpenBoxDialog>(eUI_4f42))
        pDialog->FUN_140e48050();
}
MS2_REPLACE_METHOD(0x1403CAAD0, GameEventItemBox, vfunc_5, 143, 0x2230898A);

// @0x1403cab70
void GameEventItemBox::vfunc_6()
{
    if (m_e0)
        FUN_1404247e0(FUN_140302b00()->ItemBox(), m_d0);
}
MS2_REPLACE_METHOD(0x1403CAB70, GameEventItemBox, vfunc_6, 115, 0x11447945);

// ---- GameEventShutdownInteractObjectId ------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regShutdownInteractObjectId(L"GameEventShutdownInteractObjectId", FUN_1403cabf0);
#endif
// @0x1403cabf0
GameEvent* FUN_1403cabf0() { return new GameEventShutdownInteractObjectId; }

// @0x1403cac50
CStringW GameEventShutdownInteractObjectId::vfunc_1() { return CStringW(L"GameEventShutdownInteractObjectId"); }
MS2_REPLACE_METHOD(0x1403CAC50, GameEventShutdownInteractObjectId, vfunc_1, 61, 0x2CDB7EE0);

// @0x1403caca0
GameEventShutdownInteractObjectId::GameEventShutdownInteractObjectId()
{
    FUN_1402e3480(3);
    FUN_1402e3480(1);
}

// @0x1403cad10
void GameEventShutdownInteractObjectId::vfunc_2()
{
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, m_68) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("v"); pNode; pNode = pNode->FUN_140168650("v"))
    {
        unsigned nFieldId = FUN_140197390(pNode, "fieldId", 0);
        int nObjectId = FUN_140197350(pNode, "objectId", 0);
        if (nFieldId == 0 || nObjectId == 0)
            continue;
        m_d0.insert(std::make_pair(nFieldId, nObjectId));
    }
}
MS2_REPLACE_METHOD(0x1403CAD10, GameEventShutdownInteractObjectId, vfunc_2, 321, 0xA9508BF9);

// @0x1403cae60
void GameEventShutdownInteractObjectId::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt((int)m_d0.size());
    for (std::set<std::pair<unsigned, int> >::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
    {
        out->WriteInt((*it).first);
        out->WriteInt((*it).second);
    }
}
MS2_REPLACE_METHOD(0x1403CAE60, GameEventShutdownInteractObjectId, vfunc_3, 242, 0x1A39E46E);

// @0x1403caf60
void GameEventShutdownInteractObjectId::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0.clear();
    int nCount = MS2_GE_R(in)->ReadInt();
    for (int i = 0; i < nCount; i++)
    {
        std::pair<unsigned, int> v;
        v.first = MS2_GE_R(in)->ReadInt();
        v.second = MS2_GE_R(in)->ReadInt();
        m_d0.insert(v);
    }
}
MS2_REPLACE_METHOD(0x1403CAF60, GameEventShutdownInteractObjectId, vfunc_4, 241, 0x23A8AD86);

// @0x1403cb060
void GameEventShutdownInteractObjectId::vfunc_5()
{
    for (std::set<std::pair<unsigned, int> >::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
        FUN_1407d0420(FUN_140302b00()->ShutdownInteractObjectId(), (*it).first, (*it).second);
}
MS2_REPLACE_METHOD(0x1403CB060, GameEventShutdownInteractObjectId, vfunc_5, 165, 0x329092AB);

// @0x1403cb110
void GameEventShutdownInteractObjectId::vfunc_6()
{
    for (std::set<std::pair<unsigned, int> >::iterator it = m_d0.begin(), itEnd = m_d0.end(); it != itEnd; ++it)
        FUN_1407d04c0(FUN_140302b00()->ShutdownInteractObjectId(), (*it).first, (*it).second);
}
MS2_REPLACE_METHOD(0x1403CB110, GameEventShutdownInteractObjectId, vfunc_6, 165, 0xD1095170);
