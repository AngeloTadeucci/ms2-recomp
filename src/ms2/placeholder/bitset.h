// bitset.h - PLACEHOLDER for the game's fixed-size bitset template (commonfiles\bitset.inl; the class name is invented,
// NOT an original header). Bytes, bit pos%8 of byte pos/8. The members follow the bitset.inl asserts: operator[] (line
// 152, "UINT(pos) < UINT(T)"), Set (243, "0"), Test (404, "0"). Instances: Unk_Bitset<3>::operator[] const / Set / Test
// at 0x140314650 / 0x140314670 / 0x140314790 (first instantiated by commonfiles\dungeonmatch.cpp).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"

extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#define MS2_BITSET_ASSERT(line, expression)                                                                       \
    (void)((!!(expression)) ||                                                                                     \
           (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl", line), 0))

template <int T> class Unk_Bitset
{
public:
    bool operator[](int pos) const { return Test(pos); }
    Unk_Bitset& Set(int pos, bool value = true)
    {
        if (UINT(pos) >= UINT(T)) { MS2_BITSET_ASSERT(243, 0); }
        if (value) m_bits[pos / 8] |= 1 << (pos % 8);
        else m_bits[pos / 8] &= ~(1 << (pos % 8));
        return *this;
    }
    bool Test(int pos) const
    {
        if (UINT(pos) >= UINT(T)) { MS2_BITSET_ASSERT(404, 0); return false; }
        return (m_bits[pos / 8] & (1 << (pos % 8))) != 0;
    }
private:
    unsigned char m_bits[(T + 7) / 8];
};
