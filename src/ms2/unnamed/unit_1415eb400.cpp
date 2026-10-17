// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The three Nexon Messenger stream-cryptor constructors
// (abstract base plus its two variants; each just stores its vftable) and a small helper that splits a 64-bit key
// into its high and low 32-bit halves by handing the key to the two accessor thunks.
// MS2-UNIT: unit_1415eb400
// MS2-RANGE: 0x1415eb400-0x1415eb4d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/unnamed/unit_1415eb400.h"

// Key accessor thunks (unit_1415f9410): the high and the low 32 bits of the 64-bit key they are pointed at.
extern unsigned int FUN_1415fb5f0(const unsigned __int64* p);   // *p >> 32
extern unsigned int FUN_1415fa150(const unsigned __int64* p);   // *p

// @0x1415eb400
CStreamCryptor::CStreamCryptor()
{
}

// @0x1415eb420
CStreamCryptor_v0::CStreamCryptor_v0()
{
}

// @0x1415eb450
CStreamCryptor_v1::CStreamCryptor_v1()
{
}

// @0x1415eb480 key splitter: out->kind = kind, out->hi = high dword of key, out->lo = low dword of key.
struct Unk_1415eb480
{
    unsigned int m_kind;    // +0x00
    unsigned int m_hi;      // +0x04
    unsigned int m_lo;      // +0x08
};
MS2_CHECK_SIZE(Unk_1415eb480, 0xc);

Unk_1415eb480* FUN_1415eb480(Unk_1415eb480* out, unsigned int kind, unsigned __int64 key)
{
    out->m_kind = kind;
    out->m_hi = FUN_1415fb5f0(&key);
    out->m_lo = FUN_1415fa150(&key);
    return out;
}
