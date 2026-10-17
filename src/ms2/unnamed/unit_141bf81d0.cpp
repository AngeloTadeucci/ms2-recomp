// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Intrusive list iterator advance and transfer.
// MS2-UNIT: unit_141bf81d0
// MS2-RANGE: 0x141bf81d0-0x141bf8240 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void** FUN_141bf8220(void** iterator);

// @0x141bf81d0
void** FUN_141bf81d0(void** iterator, void** out)
{
    void* current = *iterator;
    FUN_141bf8220(iterator);
    *out = current;
    return out;
}

// @0x141bf8220
void** FUN_141bf8220(void** iterator)
{
    *iterator = *static_cast<void**>(*iterator);
    return iterator;
}
