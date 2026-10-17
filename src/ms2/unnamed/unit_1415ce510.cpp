// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two small wrapper helpers from the
// unnamed string/boxed-pointer TU: the first forwards a value to an identity thunk and re-initialises
// the 0x18-byte object; the second wraps one argument through the same thunk and forwards it.
// MS2-UNIT: unit_1415ce510
// MS2-RANGE: 0x1415ce510-0x1415ce590 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// Unrecovered callees: FUN_1415e4ec0 is the identity getter thunk (mov rax,rcx; ret); FUN_140296da0
// zero-initialises the 0x18-byte object it is given and returns it.
extern void* FUN_1415e4ec0(void* p);
extern void* FUN_140296da0(void* p);

// @0x1415ce510
// MS2-FUNCTIONAL: cl loads the second-call argument into rax before moving it to rcx (exe), our build
// loads it straight into rcx; same behaviour, 3 bytes shorter.
void* FUN_1415ce510(void* p, bool b, void* v)
{
    FUN_1415e4ec0(v);
    FUN_140296da0(p);
    return p;
}

// @0x1415ce550
// MS2-FUNCTIONAL: same rax/rcx argument-load ordering difference as FUN_1415ce510.
void* FUN_1415ce550(void* p, void* v)
{
    bool b;
    FUN_1415ce510(p, b, FUN_1415e4ec0(v));
    return p;
}
