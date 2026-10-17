// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The GameEvent subclasses of commonfiles\gameevent.cpp:
// per class a factory (registered by name in the dynamic initializers), the name (vfunc_1), the ctor, the parser of the
// event's string fields (vfunc_2), the packet write / read (vfunc_3 / vfunc_4) and the start / end handlers (vfunc_5 /
// vfunc_6, mostly forwarding to CGameRule). The ctors of the *Context element types and the template glue follow at
// the end of the range; the vftables, ??_G and the implicit dtors are COMDATs of unit_1403e9650.
// MS2-UNIT: commonfiles\gameevent.cpp
// MS2-RANGE: 0x1400b6380-0x1400b8480 .text$di
// MS2-RANGE: 0x1403bb510-0x1403e4a90 .text$mn
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
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/gameeventuservaluenametable.h"
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
int FUN_140421810(GameEventUserValueNameTable* table, CStringW name);   // the id of the name

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

// ---- GameEventSaleChat ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleChat(L"GameEventSaleChat", FUN_1403bb510);
#endif
// @0x1403bb510
GameEvent* FUN_1403bb510() { return new GameEventSaleChat; }

// @0x1403bb570
CStringW GameEventSaleChat::vfunc_1() { return CStringW(L"GameEventSaleChat"); }

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

// @0x1403bb6a0
void GameEventSaleChat::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d4);
    out->WriteInt(m_d8);
}

// @0x1403bb700
void GameEventSaleChat::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d4 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadInt();
}

// @0x1403bb790
void GameEventSaleChat::vfunc_5() { FUN_1401c0d90()->FUN_140477020(m_id, m_d0, m_d4, m_d8); }

// @0x1403bb7e0
void GameEventSaleChat::vfunc_6() { FUN_1401c0d90()->FUN_1404770e0(m_id); }

// @0x1403bb810
void FUN_1403bb810() { FUN_1401c0d90()->FUN_140477180(); }
// @0x1403bb830
void FUN_1403bb830() { FUN_1401c0d90()->FUN_140477210(); }
// @0x1403bb850
void FUN_1403bb850() { FUN_1401c0d90()->FUN_1404772a0(); }
// @0x1403bb870
unsigned FUN_1403bb870() { return *FUN_1401d3200()->MeratConsumeSuperChat.Get(); }
// @0x1403bb8a0
unsigned FUN_1403bb8a0() { return *FUN_1401d3200()->MeratConsumeWorldChat.Get(); }
// @0x1403bb8d0
unsigned FUN_1403bb8d0() { return *FUN_1401d3200()->MeratConsumeChannelChat.Get(); }

// ---- GameEventSAHotTime ---------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSAHotTime(L"GameEventSAHotTime", FUN_1403bb900);
#endif
// @0x1403bb900
GameEvent* FUN_1403bb900() { return new GameEventSAHotTime; }

// @0x1403bb960
CStringW GameEventSAHotTime::vfunc_1() { return CStringW(L"GameEventSAHotTime"); }

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

// @0x1403bbc60
void GameEventSAHotTime::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_68);
    out->WriteStringW(m_70);
    out->WriteStringW(m_78);
    out->WriteStringW(m_80);
}

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

// @0x1403bc0c0
void GameEventSAHotTime::vfunc_6()
{
    FUN_1401c0d90()->FUN_140477420(FUN_1402e1d00());
    FUN_1401c0d90()->FUN_14047d900(FUN_1402e1d00());
}

// ---- GameEventPCBangSAHotTime ---------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regPCBangSAHotTime(L"GameEventPCBangSAHotTime", FUN_1403bc120);
#endif
// @0x1403bc120
GameEvent* FUN_1403bc120() { return new GameEventPCBangSAHotTime; }

// @0x1403bc180
CStringW GameEventPCBangSAHotTime::vfunc_1() { return CStringW(L"GameEventPCBangSAHotTime"); }

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

// @0x1403bc3b0
void GameEventSaleBeautyShop::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteInt(m_d4);
    out->WriteByte((unsigned char)m_d8);
}

// @0x1403bc430
void GameEventSaleBeautyShop::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d4 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadByte();
}

// @0x1403bc4f0
void GameEventSaleBeautyShop::vfunc_5()
{
    BOOL bOn = m_d8 ? FALSE : TRUE;
    FUN_1401c0d90()->FUN_140476b40(m_d0, m_d4, bOn);
}

// @0x1403bc560
void GameEventSaleBeautyShop::vfunc_6()
{
    BOOL bOn = m_d8 ? FALSE : TRUE;
    FUN_1401c0d90()->FUN_140476be0(m_d0, bOn);
}

// ---- GameEventUserCondition -----------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regUserCondition(L"GameEventUserCondition", FUN_1403bc5c0);
#endif
// @0x1403bc5c0
GameEvent* FUN_1403bc5c0() { return new GameEventUserCondition; }

// @0x1403bc620
CStringW GameEventUserCondition::vfunc_1() { return CStringW(L"GameEventUserCondition"); }

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

// @0x1403bc740
void GameEventUserCondition::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    out->WriteStringW(m_d8);
}

// @0x1403bc7b0
void GameEventUserCondition::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    m_d8 = MS2_GE_R(in)->ReadStringW();
}

// @0x1403bc870
void GameEventUserCondition::vfunc_5()
{
    if (m_d0 == 0)
        return;
    FUN_1401c0d90()->FUN_140477f20(m_d0, m_d8);
}

// @0x1403bc8f0
void GameEventUserCondition::vfunc_6() { FUN_1401c0d90()->FUN_140477fb0(m_d0); }

// ---- GameEventMesoRevival -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regMesoRevival(L"GameEventMesoRevival", FUN_1403bc920);
#endif
// @0x1403bc920
GameEvent* FUN_1403bc920() { return new GameEventMesoRevival; }

// @0x1403bc980
CStringW GameEventMesoRevival::vfunc_1() { return CStringW(L"GameEventMesoRevival"); }

// @0x1403bc9d0
GameEventMesoRevival::GameEventMesoRevival() : m_d0(false)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bca40
void GameEventMesoRevival::vfunc_2() { m_d0 = FUN_1407183f0(&m_68); }

// @0x1403bca70
void GameEventMesoRevival::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteBool(m_d0);
}

// @0x1403bcac0
void GameEventMesoRevival::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadBool();
}

// @0x1403bcb20
void GameEventMesoRevival::vfunc_5()
{
    MS2Ptr<MesoRevivalEventContext> spContext(new MesoRevivalEventContext);
    spContext->m_18 = m_d0;
    FUN_1401c0d90()->FUN_140477bd0(FUN_1402e1d00(), spContext);
}

// @0x1403bcc10
void GameEventMesoRevival::vfunc_6() { FUN_1401c0d90()->FUN_140477c90(FUN_1402e1d00()); }

// ---- GameEventItemBuff ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regItemBuff(L"GameEventItemBuff", FUN_1403bcc50);
#endif
// @0x1403bcc50
GameEvent* FUN_1403bcc50() { return new GameEventItemBuff; }

// @0x1403bccb0
CStringW GameEventItemBuff::vfunc_1() { return CStringW(L"GameEventItemBuff"); }

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

// @0x1403bcee0
void GameEventItemBuff::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}

// @0x1403bcf40
void GameEventItemBuff::vfunc_5() { FUN_1401c0d90()->FUN_14047a8c0(m_d0); }

// @0x1403bcf70
void GameEventItemBuff::vfunc_6() { FUN_1401c0d90()->FUN_14047a8c0(0); }

// ---- GameEventDungeonBonusReward ------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regDungeonBonusReward(L"GameEventDungeonBonusReward", FUN_1403bcfa0);
#endif
// @0x1403bcfa0
GameEvent* FUN_1403bcfa0() { return new GameEventDungeonBonusReward; }

// @0x1403bd000
CStringW GameEventDungeonBonusReward::vfunc_1() { return CStringW(L"GameEventDungeonBonusReward"); }

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

// @0x1403bd230
void GameEventDungeonBonusReward::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    MS2_GE_OUT(out) << m_d0;
}

// @0x1403bd270
void GameEventDungeonBonusReward::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    MS2_GE_IN(in) >> m_d0;
}

// @0x1403bd2c0
void GameEventDungeonBonusReward::vfunc_5() { FUN_1401c0d90()->FUN_14047a900(m_d0); }

// @0x1403bd330
void GameEventDungeonBonusReward::vfunc_6() { FUN_1401c0d90()->FUN_14047aa00(m_d0); }

// ---- GameEventFreeAirTaxi -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regFreeAirTaxi(L"GameEventFreeAirTaxi", FUN_1403bd3a0);
#endif
// @0x1403bd3a0
GameEvent* FUN_1403bd3a0() { return new GameEventFreeAirTaxi; }

// @0x1403bd400
CStringW GameEventFreeAirTaxi::vfunc_1() { return CStringW(L"GameEventFreeAirTaxi"); }

// @0x1403bd450
GameEventFreeAirTaxi::GameEventFreeAirTaxi()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bd4b0
void GameEventFreeAirTaxi::vfunc_2() {}

// @0x1403bd4c0
void GameEventFreeAirTaxi::vfunc_3(Unk_GEOut* out) { GameEvent::vfunc_3(out); }

// @0x1403bd4f0
void GameEventFreeAirTaxi::vfunc_4(Unk_GEIn* in) { GameEvent::vfunc_4(in); }

// @0x1403bd520
void GameEventFreeAirTaxi::vfunc_5() { FUN_1401c0d90()->FUN_140477dc0(FUN_1402e1d00()); }

// @0x1403bd560
void GameEventFreeAirTaxi::vfunc_6() { FUN_1401c0d90()->FUN_140477e30(FUN_1402e1d00()); }

// ---- GameEventOntime ------------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regOntime(L"GameEventOntime", FUN_1403bd5a0);
#endif
// @0x1403bd5a0
GameEvent* FUN_1403bd5a0() { return new GameEventOntime; }

// @0x1403bd600
CStringW GameEventOntime::vfunc_1() { return CStringW(L"GameEventOntime"); }

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

// @0x1403bdb80
void GameEventOntime::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt64(m_38.Get());
}

// @0x1403bdbe0
void GameEventOntime::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_38 = CMsTime(MS2_GE_R(in)->ReadInt64());
}

// @0x1403bdc50
void GameEventOntime::vfunc_5()
{
    if (m_d0.get()) {
        m_d0->m_1c = true;
        FUN_1401c0d90()->FUN_140478170(FUN_1402e1d00(), m_d0);
    }
}

// @0x1403bdd00
void GameEventOntime::vfunc_6() { FUN_1401c0d90()->FUN_1404781f0(FUN_1402e1d00()); }

// ---- GameEventSaleEnchant -------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regSaleEnchant(L"GameEventSaleEnchant", FUN_1403bdd40);
#endif
// @0x1403bdd40
GameEvent* FUN_1403bdd40() { return new GameEventSaleEnchant; }

// @0x1403bdda0
CStringW GameEventSaleEnchant::vfunc_1() { return CStringW(L"GameEventSaleEnchant"); }

// @0x1403bddf0
GameEventSaleEnchant::GameEventSaleEnchant() : m_d0(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403bde60
void GameEventSaleEnchant::vfunc_2() { m_d0 = FUN_140718200(&m_68); }

// @0x1403bde90
void GameEventSaleEnchant::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
}

// @0x1403bdee0
void GameEventSaleEnchant::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
}

// @0x1403bdf40
void GameEventSaleEnchant::vfunc_5() { FUN_1401c0d90()->FUN_140478a80(m_id, m_d0); }

// @0x1403bdf80
void GameEventSaleEnchant::vfunc_6() { FUN_1401c0d90()->FUN_140478af0(m_id); }

// ---- GameEventQuestTag ----------------------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regQuestTag(L"GameEventQuestTag", FUN_1403bdfb0);
#endif
// @0x1403bdfb0
GameEvent* FUN_1403bdfb0() { return new GameEventQuestTag; }

// @0x1403be010
CStringW GameEventQuestTag::vfunc_1() { return CStringW(L"GameEventQuestTag"); }

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

// @0x1403be200
void GameEventQuestTag::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_d0);
    out->WriteInt64(m_28.Get());
    out->WriteInt64(m_38.Get());
}

// @0x1403be2b0
void GameEventQuestTag::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadStringW();
    m_28 = CMsTime(MS2_GE_R(in)->ReadInt64());
    m_38 = CMsTime(MS2_GE_R(in)->ReadInt64());
}

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

// @0x1403be5c0
void GameEventQuestTag::vfunc_6() { FUN_1401c0d90()->FUN_140479070(m_d0); }

// ---- GameEventBlackMarketFeeDiscount --------------------------------------------------------------------------------
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regBlackMarketFeeDiscount(L"GameEventBlackMarketFeeDiscount", FUN_1403be630);
#endif
// @0x1403be630
GameEvent* FUN_1403be630() { return new GameEventBlackMarketFeeDiscount; }

// @0x1403be690
CStringW GameEventBlackMarketFeeDiscount::vfunc_1() { return CStringW(L"GameEventBlackMarketFeeDiscount"); }

// @0x1403be6e0
GameEventBlackMarketFeeDiscount::GameEventBlackMarketFeeDiscount() : m_d0(-1)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403be750
void GameEventBlackMarketFeeDiscount::vfunc_2() { m_d0 = FUN_1407181a0(&m_68); }

// @0x1403be780
void GameEventBlackMarketFeeDiscount::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_d0);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
}

// @0x1403be7f0
void GameEventBlackMarketFeeDiscount::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_d0 = MS2_GE_R(in)->ReadInt();
    FUN_14070f6b0(MS2_GE_R(in), &m_28);
    FUN_14070f6b0(MS2_GE_R(in), &m_38);
}

// @0x1403be880
void GameEventBlackMarketFeeDiscount::vfunc_5()
{
    static Unk_GameEventIntRange s_range(0, 10000);
    if (s_range.IsInRange(m_d0))
        FUN_1401c0d90()->FUN_140479510(m_d0, m_28.Get(), m_38.Get());
    else
        MS2_ASSERT_AT(MS2_LINE(841), FALSE);
}

// @0x1403be990
void GameEventBlackMarketFeeDiscount::vfunc_6() { FUN_1401c0d90()->FUN_140479510(-1, 0, 0); }
