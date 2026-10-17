// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEvent subclasses GameEventAttendGift / CashAttend /
// DTReward, the *Context types the event XML loaders fill, and the CAtlArray / std:: glue over them.
// MS2-UNIT: commonfiles\gameeventcontext.cpp
// MS2-RANGE: 0x1400b8480-0x1400b8700 .text$di
// MS2-RANGE: 0x1403f4e10-0x14041b140 .text$mn
// MS2-PIN: ??1GameEventAttendGift@@UEAA@XZ 0x1403fc070
// MS2-PIN: ??1GameEventCashAttend@@UEAA@XZ 0x1403fc0d0
// MS2-PIN: ??_GGameEventAttendGift@@UEAAPEAXI@Z 0x1403fc190
// MS2-PIN: ??_GGameEventCashAttend@@UEAAPEAXI@Z 0x1403fc1d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventcontext.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <new>
#include <vector>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "gameeventcontext.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit helpers.
// Constructor at 0x140316aa0: registers the factory under the name (the by-value CString is destroyed by the callee).
struct Unk_GEFactoryRegistry {
    Unk_GEFactoryRegistry(CStringW name, GameEvent* (*create)());
    char m_pad;
};
int FUN_140718200(CStringW* text);
// Stream helpers (CInputStream / COutputStream operator<< / >> overloads).
Unk_GEOut* FUN_14070f9a0(Unk_GEOut* out, int value);
Unk_GEOut* FUN_14070fa20(Unk_GEOut* out, __int64 value);
Unk_GEOut* FUN_14070f820(Unk_GEOut* out, bool value);
Unk_GEOut* FUN_14070fb70(Unk_GEOut* out, const Unk_GE16* date);
Unk_GEOut* FUN_14070fae0(Unk_GEOut* out, const CStringW* text);
Unk_GEOut* FUN_14070faa0(Unk_GEOut* out, const CStringA* text);
Unk_GEReader* FUN_14070f480(Unk_GEReader* in, int* value);
Unk_GEReader* FUN_14070f500(Unk_GEReader* in, __int64* value);
Unk_GEReader* FUN_14070f300(Unk_GEReader* in, bool* value);
Unk_GEReader* FUN_14070f6b0(Unk_GEReader* in, Unk_GE16* date);
Unk_GEReader* FUN_14070f5f0(Unk_GEReader* in, CStringW* text);
Unk_GEReader* FUN_14070f580(Unk_GEReader* in, CStringA* text);
Unk_AttendGiftDataGroup* FUN_1403fc330();
GameEvent* FUN_1403fb400();
GameEvent* FUN_1403fb9a0();
void FUN_1403fbe50(Unk_GEReader* in, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts);
void FUN_1403fbf30(Unk_GEOut* out, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts);

extern Unk_AttendGiftDataGroup* DAT_143aac2a8;

// Sort-key names (header static shared with several units).
static CStringA s_sortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CStringA s_sortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

#ifndef MS2_HOOK_DLL
// Registration of the event factories by name (dynamic initializers).
static Unk_GEFactoryRegistry s_regAttendGift(L"GameEventAttendGift", FUN_1403fb400);     // 0x143aaee24
static Unk_GEFactoryRegistry s_regCashAttend(L"GameEventCashAttend", FUN_1403fb9a0);     // 0x143aaee25
#endif

// @0x1403fb400
GameEvent* FUN_1403fb400() { return new GameEventAttendGift; }

// @0x1403fb460
CStringW GameEventAttendGift::vfunc_1() { return CStringW(L"GameEventAttendGift"); }

// @0x1403fb4b0
GameEventAttendGift::GameEventAttendGift()
    : m_i100(0), m_i104(0), m_i108(0), m_i110(0), m_i114(0), m_i118(0), m_i11c(0), m_i120(0), m_b124(false), m_b125(true)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403fb5e0
void GameEventAttendGift::vfunc_2() {}

// @0x1403fb5f0
void GameEventAttendGift::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
    FUN_14070fae0(out, &m_strName);
    FUN_14070faa0(out, &m_strDesc);
    FUN_14070f820(out, m_b124);
    FUN_14070f820(out, m_b125);
    FUN_14070f9a0(out, m_i120);
    out->WriteByte(m_i114);
    FUN_14070f9a0(out, m_i118);
    out->WriteByte(m_i100);
    if (m_i100 != 0) {
        FUN_14070f9a0(out, m_i104);
        FUN_14070fa20(out, m_i108);
        FUN_14070f9a0(out, m_i110);
    }
    FUN_1403fbf30(out, &m_gifts);
}

// @0x1403fb770
void GameEventAttendGift::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f6b0(&in->reader, &m_28);
    FUN_14070f6b0(&in->reader, &m_38);
    FUN_14070f5f0(&in->reader, &m_strName);
    FUN_14070f580(&in->reader, &m_strDesc);
    FUN_14070f300(&in->reader, &m_b124);
    FUN_14070f300(&in->reader, &m_b125);
    FUN_14070f480(&in->reader, &m_i120);
    m_i114 = MS2_GE_READ_BYTE(&in->reader);
    FUN_14070f480(&in->reader, &m_i118);
    m_i100 = MS2_GE_READ_BYTE(&in->reader);
    if (m_i100 != 0) {
        FUN_14070f480(&in->reader, &m_i104);
        FUN_14070f500(&in->reader, &m_i108);
        FUN_14070f480(&in->reader, &m_i110);
    }
    FUN_1403fbe50(&in->reader, &m_gifts);
    vfunc_10();
}

// @0x1403fb970
void GameEventAttendGift::vfunc_5() {}

// @0x1403fb980
void GameEventAttendGift::vfunc_6() {}

// @0x1403fb990
void GameEventAttendGift::vfunc_10() {}

// @0x1403fb9a0
GameEvent* FUN_1403fb9a0() { return new GameEventCashAttend; }

// @0x1403fba00
CStringW GameEventCashAttend::vfunc_1() { return CStringW(L"GameEventCashAttend"); }

// @0x1403fba50
GameEventCashAttend::GameEventCashAttend() : m_i0(0), m_i4(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403fbb00
void GameEventCashAttend::vfunc_2()
{
    m_i0 = FUN_140718200(&m_68);
    m_i4 = FUN_140718200(&m_70);
    m_strDesc = m_78;
    m_entry = FUN_1403fc330()->FUN_1401ae630(m_i0);
}

// @0x1403fbbd0
void GameEventCashAttend::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
    FUN_14070f9a0(out, m_i0);
    FUN_14070f9a0(out, m_i4);
    FUN_14070fae0(out, &m_strDesc);
}

// @0x1403fbc70
void GameEventCashAttend::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f6b0(&in->reader, &m_28);
    FUN_14070f6b0(&in->reader, &m_38);
    FUN_14070f480(&in->reader, &m_i0);
    FUN_14070f480(&in->reader, &m_i4);
    FUN_14070f5f0(&in->reader, &m_strDesc);
    m_entry = FUN_1403fc330()->FUN_1401ae630(m_i0);
    vfunc_10();
}

// @0x1403fbd90
void GameEventCashAttend::vfunc_5() {}

// @0x1403fbda0
void GameEventCashAttend::vfunc_6() {}

// @0x1403fbdb0
void GameEventCashAttend::vfunc_10() {}

// @0x1403fbde0
int FUN_1403fbde0(const CStringA& name)
{
    if (name.CompareNoCase("UserValue") == 0)
        return 1;
    else if (name.CompareNoCase("ItemID") == 0)
        return 2;
    else if (name.CompareNoCase("NotUserValue") == 0)
        return 3;
    return 0;
}

// @0x1403fbe50
void FUN_1403fbe50(Unk_GEReader* in, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts)
{
    unsigned count = in->ReadInt();
    for (unsigned i = 0; i < count; i++) {
        MS2Ptr<ItemGift> gift(new ItemGift);
        gift->FUN_14026b100(*reinterpret_cast<Unk_GiftInput*>(in));
        gifts->Add(gift);
    }
}

// @0x1403fbf30
void FUN_1403fbf30(Unk_GEOut* out, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts)
{
    out->WriteInt(gifts->GetCount());
    for (unsigned i = 0; i < gifts->GetCount(); i++) {
        MS2Ptr<ItemGift>& gift = (*gifts)[i];
        gift->FUN_14026b030(*reinterpret_cast<Unk_GiftOutput*>(out));
    }
}

// @0x1403fc330
Unk_AttendGiftDataGroup* FUN_1403fc330() { return DAT_143aac2a8; }
