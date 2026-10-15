#pragma once
#include "ms2/client/ms2/pcbase.h"
#include <NiFixedString.h>

// Heap-only views. PC derives PCBase (ctor 14164dfd0), and FittingDollPC
// derives PC (ctor 14121b350). No constructors or vftables are emitted here.
// The additional PC virtual interface is not used by the cube guide wrappers;
// calls through these pointers use the inherited GameObject slots only.
class PC : public PCBase {
public:
    virtual ~PC();
    unsigned char unknownD40[0x5a0];
};
MS2_CHECK_SIZE(PC, 0x12e0); // deleting dtor 1416678b0

class FittingDollPC : public PC {
public:
    virtual ~FittingDollPC();
    void FUN_14121c170(NiFixedString parentName);
    int type, index, unknown12e8;
    void* unknown12f0;
    NiFixedString parentName;
};
MS2_CHECK_SIZE(FittingDollPC, 0x1300); // deleting dtor 14121cca0
MS2_CHECK_OFFSET(FittingDollPC, parentName, 0x12f8);
