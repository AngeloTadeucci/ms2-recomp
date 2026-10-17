// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two iterator helpers of the same container family as
// unit_141bf81a0 (worldservice's entity list): the stride-0x10 advance and its void-returning form. The container and its
// iterator type live in other units; the iterator here is recovered as a pointer-to-node-pointer view.
// MS2-UNIT: unit_141bf8d20
// MS2-RANGE: 0x141bf8d20-0x141bf8d60 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x141bf8d20 - advance the iterator by one 0x10-byte node
void** FUN_141bf8d20(void** pIter)
{
    *pIter = (void*)((char*)*pIter + 0x10);
    return pIter;
}

// @0x141bf8d40 - advances and hands the iterator back (the exe reloads its own home slot, so the source returns pIter)
void** FUN_141bf8d40(void** pIter)
{
    FUN_141bf8d20(pIter);
    return pIter;
}
