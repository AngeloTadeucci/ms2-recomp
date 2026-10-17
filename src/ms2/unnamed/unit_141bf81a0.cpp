// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two inline-shaped iterator helpers of the container family that
// fills 0x141bf8xxx (worldservice's entity list): dereferencing an iterator and a void-returning forwarder of it. The
// container, its iterator and the node type live in other units; only the pointer views used here are recovered.
// MS2-UNIT: unit_141bf81a0
// MS2-RANGE: 0x141bf81a0-0x141bf81d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x141bf81a0 - the dereference (the node pointer the iterator holds)
void* FUN_141bf81a0(void** pIter)
{
    return *pIter;
}

// @0x141bf81b0 - the void-returning form used at the call sites
void* FUN_141bf81b0(void** pIter)
{
    return FUN_141bf81a0(pIter);
}
