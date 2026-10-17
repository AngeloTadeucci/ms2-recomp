// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two more small wrapper helpers from the
// unnamed boxed-pointer TU: the first forwards a value to an identity thunk and re-initialises the
// 0x18-byte object it is given; the second wraps one argument through the same thunk and forwards it.
// MS2-UNIT: unit_1415ce810
// MS2-RANGE: 0x1415ce810-0x1415ce890 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// Unrecovered callees: FUN_1415e4f20 is the identity getter thunk (mov rax,rcx; ret); FUN_1415e7770
// zero-initialises the 0x18-byte object it is given and returns it.
extern void* FUN_1415e4f20(void* p);
extern void* FUN_1415e7770(void* p);

// @0x1415ce810
// MS2-FUNCTIONAL: cl loads the second-call argument into rcx directly, the exe loads it into rax and
// moves it to rcx; same behaviour.
void* FUN_1415ce810(void* p, bool b, void* v)
{
    FUN_1415e4f20(v);
    FUN_1415e7770(p);
    return p;
}

// @0x1415ce850
// MS2-FUNCTIONAL: same rax/rcx argument-load ordering difference as FUN_1415ce810.
void* FUN_1415ce850(void* p, void* v)
{
    bool b;
    FUN_1415ce810(p, b, FUN_1415e4f20(v));
    return p;
}
