// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBlockManager: account block restrictions.
// MS2-UNIT: ?\blockmanager.cpp
// MS2-RANGE: 0x1400c2fc0-0x1400c2ff0 .text$di
// MS2-RANGE: 0x140a2f540-0x140a31af0 .text$mn
// MS2-PIN: ??0?$Unk_BlockPtr@VCBlockChecker@@@@QEAA@PEAVCBlockChecker@@@Z 0x140a31810
// MS2-PIN: ??0?$Unk_BlockPtr@UUnk_BlockRecord@@@@QEAA@PEAUUnk_BlockRecord@@@Z 0x140a317e0
// MS2-PIN: ?Reset@?$Unk_BlockPtr@VCBlockChecker@@@@QEAAAEAV1@PEAVCBlockChecker@@@Z 0x140a318e0
// MS2-PIN: ??_G?$TSingleton@VCBlockManager@@@@UEAAPEAXI@Z 0x140a31960
// MS2-PIN: ??_GCBlockManager@@UEAAPEAXI@Z 0x140a319a0
// MS2-PIN: ??$BlockFormat@HHHHHHHHHHHHV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBH00000000000AEBV01@@Z 0x140a311c0
// MS2-FUNCTIONAL: the notice/dialog helpers (message boxes, string table) are opaque FUN_ externs; the 12/13-argument fmt
// instances are the natural StringFormat/BlockFormat calls.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\blockmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "blockmanager.h"
#include "ms2/ms2format.h"

typedef unsigned long long u64;

// Custom game time: the CTime value at offset zero and a flag at offset eight (ctor 0x1406c47a0).
#include "ms2/placeholder/mstime.h"

CStringW BlockFormat(int, const fmt::ArgList&);
FMT_VARIADIC_W(CStringW, BlockFormat, int)

// ---- out-of-unit callees ----
__int64 FUN_140869440();                                      // current server time
CStringW FUN_14028de60(int id);                               // string table lookup
void FUN_1412751b0(const CStringW& msg, int seconds);         // on-screen notice
CStringW FUN_1408116a0(int id, const int& v);                 // string table + one int
CStringW FUN_1409e8970(CStringW key, const int& a, const int& b);
void AddDays(CMsTime& time, long days);   // 0x14086a7e0 (commonfiles/timeutil.cpp)
void FUN_140268750(AccountBlockInfo* info, void* stream);     // AccountBlockInfo::Read
void FUN_140d73aa0(CStringW msg, int a, u64 cb, CStringW b);  // message box
void* FUN_140d73d20(void* outHandle, int flags, CStringW msg, u64 cb, CStringW b);   // dialog (smart-pointer handle out)
void* FUN_140d73e40(void* outHandle, int a, int id, int b, CStringW s);
void* FUN_140534fc0(void* handle);                            // handle->get()
void* FUN_140534fe0(void* handle);                            // handle->operator->
void* FUN_140534b80(void* out, void* handle);                 // handle copy
void FUN_140534d60(void* handle);                             // handle dtor
void FUN_140d73c60(void* h);
void FUN_141a015d0(void* dialog, const CStringW& text);
void* FUN_140166410();
char FUN_14036e4c0(void* p);
CStringW FUN_140217ff0(int id);
void FUN_140165320(void* dst, const CStringW& s);
void FUN_142c9ef00();

// Stream embedded at packet+8; slots: 1 = byte, 3 = int, 4 = int64.
struct Unk_BlockStream {
    virtual void v0(); virtual char ReadByte(); virtual void v2(); virtual int ReadInt(); virtual __int64 ReadLong();
};

// DAT_143ab5cc0 (dynamic initializer 0x1400c2fc0), DAT_143ab5cc8 = TSingleton<CBlockManager>::s_instance
static CStringW s_externalBlock(L"externalBlock");

// @0x140a2f540
CBlockManager::CBlockManager()
{
    m_checker.Reset(new CBlockChecker);
}

// @0x140a2f5e0
CBlockManager::~CBlockManager()
{
}

// @0x140a2f620
BlockPtr CBlockManager::FindBlockedAction(int action)
{
    BlockPtr p = m_checker.get()->FindAction(action);
    if (!(p == 0)) {
        Unk_BlockRecord* rec = p.operator->();
        if (FUN_140869440() <= rec->expiry)
            return static_cast<const BlockPtr&>(p);
    }
    return BlockPtr(0);
}

// @0x140a2f700
void CBlockManager::ClearBlocks()
{
    m_checker.get()->Clear();
}

// @0x140a2f730
void CBlockManager::OnBlockPacket(void* packet)
{
    Unk_BlockStream* s = (Unk_BlockStream*)((char*)packet + 8);
    char op = s->ReadByte();
    if (op == 0) {
        int n = s->ReadInt();
        for (int i = 0; i < n; ++i) {
            AccountBlockInfo* info = new AccountBlockInfo;
            BlockPtr bp(info);
            FUN_140268750(bp.get() ? (AccountBlockInfo*)bp.get() : 0, s);
            m_checker.get()->Set(bp);
            int kind = bp->kind;
            if (kind == 2) {
                FUN_1412751b0(FUN_14028de60(0x434), 0x14);
            } else if (kind == 4) {
                FUN_1412751b0(FUN_14028de60(0x439), 0x14);
            } else if (kind == 10) {
                CMsTime t(bp->expiry);
                AddDays(t, 1);
                int day = t.GetDay();
                int month = t.GetMonth();
                FUN_1412751b0(FUN_1409e8970(CStringW(L"s_admin_block_cash_out"), month, day), 0x14);
            }
        }
    } else if (op == 1) {
        __int64 id = s->ReadLong();
        BlockPtr removed = m_checker.get()->Remove(id);
    } else if (op == 2) {
        int a = (int)s->ReadLong();
        int type = s->ReadInt();
        __int64 expiry = s->ReadLong();
        int delta = s->ReadInt();
        BlockPtr r = m_checker.get()->SetExpiry((__int64)a, expiry);
        if (delta < 0) {
            if (type == 2) {
                int v = -delta;
                FUN_1412751b0(FUN_1408116a0(0x435, v), 0x14);
            } else if (type == 4) {
                int v = -delta;
                FUN_1412751b0(FUN_1408116a0(0x43a, v), 0x14);
            }
        }
    }
}

// @0x140a2fcd0  "from .. to" duration text (string 0x450) with the 12 date components
CStringW FUN_140a2fcd0(__int64 from, __int64 to)
{
    CMsTime t1(from);
    CMsTime t2(to);
    CStringW fmtStr = FUN_14028de60(0x450);
    int s2 = t2.GetSecond(), mi2 = t2.GetMinute(), h2 = t2.GetHour(), d2 = t2.GetDay(), mo2 = t2.GetMonth(), y2 = t2.GetYear();
    int s1 = t1.GetSecond(), mi1 = t1.GetMinute(), h1 = t1.GetHour(), d1 = t1.GetDay(), mo1 = t1.GetMonth(), y1 = t1.GetYear();
    CStringW r = StringFormat((const wchar_t*)fmtStr, y1, mo1, d1, h1, mi1, s1, y2, mo2, d2, h2, mi2, s2);
    return r;
}

// @0x140a30ad0  plain message box for a record + action
void FUN_140a30ad0(const BlockPtr& rec, int action, u64 cb)
{
    CStringW msg = FUN_1401ca400(rec, action);
    FUN_140d73aa0(CStringW(msg), 0, cb, CStringW(L""));
}

// @0x140a30b80
void FUN_140a30b80(char* dialog, int id)
{
    FUN_140165320(dialog + 0x228, FUN_140217ff0(id));
}

// @0x140a2ff20  show the "you are blocked" notice for a record
void FUN_140a2ff20(const BlockPtr& rec, int action, u64 cb)
{
    int kind = rec->kind;
    if (kind == 2 || kind == 4) {
        CMsTime t1((__int64)rec->m_38);
        CMsTime t2(rec->expiry);
        CStringW title, body;
        if (rec->kind == 2) {
            title = FUN_14028de60(0x436);
            int s2 = t2.GetSecond(), mi2 = t2.GetMinute(), h2 = t2.GetHour(), d2 = t2.GetDay(), mo2 = t2.GetMonth(), y2 = t2.GetYear();
            int s1 = t1.GetSecond(), mi1 = t1.GetMinute(), h1 = t1.GetHour(), d1 = t1.GetDay(), mo1 = t1.GetMonth(), y1 = t1.GetYear();
            body = BlockFormat(0x437, y1, mo1, d1, h1, mi1, s1, y2, mo2, d2, h2, mi2, s2, *(CStringW*)&rec->m_30);
        } else {
            title = FUN_14028de60(0x43b);
            int s2 = t2.GetSecond(), mi2 = t2.GetMinute(), h2 = t2.GetHour(), d2 = t2.GetDay(), mo2 = t2.GetMonth(), y2 = t2.GetYear();
            int s1 = t1.GetSecond(), mi1 = t1.GetMinute(), h1 = t1.GetHour(), d1 = t1.GetDay(), mo1 = t1.GetMonth(), y1 = t1.GetYear();
            body = BlockFormat(0x43c, y1, mo1, d1, h1, mi1, s1, y2, mo2, d2, h2, mi2, s2, *(CStringW*)&rec->m_30);
        }
        char h[16];
        FUN_140d73d20(h, 0x10, CStringW(body), cb, CStringW(L""));
        if (FUN_140534fc0(h)) {
            FUN_141a015d0(FUN_140534fe0(h), title);
            char tmp[16];
            FUN_140d73c60(FUN_140534b80(tmp, h));
        }
        FUN_140534d60(h);
    } else if (kind == 5) {
        if (!FUN_14036e4c0(FUN_140166410())) {
            CMsTime t1((__int64)rec->m_38);
            CMsTime t2(rec->expiry);
            CStringW title, body;
            title = FUN_14028de60(0x43d);
            int s2 = t2.GetSecond(), mi2 = t2.GetMinute(), h2 = t2.GetHour(), d2 = t2.GetDay(), mo2 = t2.GetMonth(), y2 = t2.GetYear();
            int s1 = t1.GetSecond(), mi1 = t1.GetMinute(), h1 = t1.GetHour(), d1 = t1.GetDay(), mo1 = t1.GetMonth(), y1 = t1.GetYear();
            body = BlockFormat(0x43e, y1, mo1, d1, h1, mi1, s1, y2, mo2, d2, h2, mi2, s2, *(CStringW*)&rec->m_30);
            char h[16];
            FUN_140d73d20(h, 0x10, CStringW(body), cb, CStringW(L""));
            if (FUN_140534fc0(h)) {
                FUN_141a015d0(FUN_140534fe0(h), title);
                char tmp[16];
                FUN_140d73c60(FUN_140534b80(tmp, h));
            }
            FUN_140534d60(h);
        } else {
            char h[16];
            FUN_140d73e40(h, 1, 0x440, 0, CStringW(s_externalBlock));
            if (FUN_140534fc0(h)) {
                FUN_140a30b80((char*)FUN_140534fe0(h), 1);
                FUN_141a015d0(FUN_140534fe0(h), FUN_14028de60(0x43f));
                char tmp[16];
                FUN_140d73c60(FUN_140534b80(tmp, h));
            }
            FUN_140534d60(h);
        }
    } else {
        FUN_140a30ad0(rec, action, cb);
    }
}
