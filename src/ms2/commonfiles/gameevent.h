// Minimal GameEvent base (RTTI .?AVGameEvent@@; name assumed), recovered from the subclasses in gameeventlobbymap.cpp.
// NOT a full recovery: the base class unit (0x1402e1b80.., 0x1403bb510..) is not done yet. Only what the derived classes
// need is declared: vftable slots 0..9 (base vftable 0x142d22178), the id at +0x18, the CString at +0x68, size 0xd0.
// Members of the base are opaque padding until the base unit is recovered.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"

// Output / input stream stand-ins: only the virtual slot used by GameEvent subclasses (slot 3) is exact.
class Unk_GEOut {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void WriteInt(int value);   // slot 3
};
class Unk_GEReader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual int ReadInt();              // slot 3
};
// The input packet: the reader object is embedded at +8.
struct Unk_GEIn {
    char m_pad[8];
    Unk_GEReader reader;    // embedded at +8
};
// clang-cl devirtualizes a call on an embedded member object into a direct call to an undefined function; go through
// an opaque pointer there (the byte-matched cl build keeps the member call).
#ifdef __clang__
#define MS2_GE_READ_INT(in) (reinterpret_cast<Unk_GEReader*>(reinterpret_cast<char*>(in) + 8)->ReadInt())
#else
#define MS2_GE_READ_INT(in) ((in)->reader.ReadInt())
#endif
struct Unk_GE16 { char b[16]; };

class GameEvent : public CPtred {
public:
    GameEvent();                                // 0x1402e1b80
    virtual ~GameEvent();                       // slot 0 (body 0x1402e4cf0)
    virtual CStringW vfunc_1() = 0;             // event name
    virtual void vfunc_2() = 0;                 // parse the CString at +0x68
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1402e2190: out->WriteInt(m_id)
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1402e21d0
    virtual void vfunc_5() = 0;                 // event start
    virtual void vfunc_6() = 0;                 // event end
    virtual void vfunc_7(void* other);          // 0x1402e2220
    virtual void vfunc_8();                     // 0x1402e5510 (empty)
    virtual bool vfunc_9(void* other);          // 0x1402e2580
    void FUN_1402e3480(int kind);               // sets the flag `kind` in the set at +0x8c

protected:
    MS2_LAYOUT_FRIEND;
    int m_id;               // +0x18
    char m_pad_1c[4];
    char m_pad_20[0x18];
    Unk_GE16 m_38;          // +0x38
    char m_pad_48[0x20];
    CStringW m_68;          // +0x68
    char m_pad_70[0x60];
};
MS2_CHECK_SIZE(GameEvent, 0xd0);
MS2_CHECK_OFFSET(GameEvent, m_id, 0x18);
MS2_CHECK_OFFSET(GameEvent, m_38, 0x38);
MS2_CHECK_OFFSET(GameEvent, m_68, 0x68);
