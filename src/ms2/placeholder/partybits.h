// partybits.h - Unk_PartyBits, a one-byte bitset (bitset.inl shape: bit test 0x1402e4ee0). NOT an original header; the
// class name is invented. Used for the party permissions (partymanager.h) and the dungeon room day-of-week limits
// (dungeonroom.h).
#pragma once
#include "ms2/ms2layout.h"

struct Unk_PartyBits {
    unsigned char bits;
    Unk_PartyBits(); // 1402e49d0
    bool FUN_1402e4ee0(int);
    bool FUN_140b912f0();
    void FUN_140837500();
};
MS2_CHECK_SIZE(Unk_PartyBits, 1);
