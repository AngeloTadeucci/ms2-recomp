// GameEvent subclasses and *Context types of commonfiles\gameeventcontext.cpp (names from the exe's RTTI / registration
// strings; member names inferred from the XML loaders and the stream readers). w141 partial recovery.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/itemgift.h"

// clang-cl devirtualizes a call on an embedded member object into a direct call to an undefined function; go through
// an opaque pointer there (the byte-matched cl build keeps the member call).
#ifdef __clang__
#define MS2_GE_READ_BYTE(r) (reinterpret_cast<Unk_GEReader*>(r)->ReadByte())
#else
#define MS2_GE_READ_BYTE(r) ((r)->ReadByte())
#endif

// The attend reward entry of the cash attend table (looked up by id through the table group singleton; the table lives
// in attendgiftdatagroup.cpp). Name unknown.
class Unk_CashAttendEntry : public CPtred {
};
class Unk_AttendGiftDataGroup {
public:
    MS2Ptr<Unk_CashAttendEntry> FUN_1401ae630(int id);      // 0x1401ae630
};

class GameEventAttendGift : public GameEvent {
public:
    GameEventAttendGift();
    virtual CStringW vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_10();
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<ItemGift> > m_gifts;  // +0xd0
    CStringW m_strName;                         // +0xf0
    CStringA m_strDesc;                         // +0xf8
    int m_i100;
    int m_i104;
    __int64 m_i108;
    int m_i110;
    int m_i114;
    int m_i118;
    int m_i11c;
    int m_i120;
    bool m_b124;
    bool m_b125;
};
MS2_CHECK_SIZE(GameEventAttendGift, 0x128);
MS2_CHECK_OFFSET(GameEventAttendGift, m_gifts, 0xd0);
MS2_CHECK_OFFSET(GameEventAttendGift, m_strName, 0xf0);
MS2_CHECK_OFFSET(GameEventAttendGift, m_i108, 0x108);
MS2_CHECK_OFFSET(GameEventAttendGift, m_i120, 0x120);
MS2_CHECK_OFFSET(GameEventAttendGift, m_b125, 0x125);

class GameEventCashAttend : public GameEvent {
public:
    GameEventCashAttend();
    virtual CStringW vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_10();
    int FUN_1403fbdc0() { return m_i4; }        // 0x1403fbdc0
private:
    MS2_LAYOUT_FRIEND;
    int m_i0;                                   // +0xd0 table id
    int m_i4;                                   // +0xd4
    CStringW m_strDesc;                         // +0xd8
    MS2Ptr<Unk_CashAttendEntry> m_entry;        // +0xe0
};
MS2_CHECK_SIZE(GameEventCashAttend, 0xf0);
MS2_CHECK_OFFSET(GameEventCashAttend, m_i4, 0xd4);
MS2_CHECK_OFFSET(GameEventCashAttend, m_entry, 0xe0);
