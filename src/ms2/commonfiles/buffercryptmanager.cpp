// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See buffercryptmanager.h for the CU name evidence.
// The original was compiled without optimization (/Od: locals on the stack, swap not inlined). Under cl 19.16 with
// cmake/ms2-game-flags.cmake every function here byte-matches the exe (tools/bytematch.py).
#include "buffercryptmanager.h"

#include <utility>

#include "hook/ms2hook.h"

// ---------------------------------------------------------------------------------------------------------------
// CXORCrypter: XOR with a 2-byte key, alternating key bytes. Encrypt == Decrypt.

void CXORCrypter::Encrypt(BYTE* pBuffer, UINT nSize, void* /*pReserved*/)
{
    int nKeyIndex = 0;
    for (UINT i = 0; i < nSize; ++i)
    {
        pBuffer[i] ^= m_pKey[nKeyIndex];
        nKeyIndex = (nKeyIndex == 0) ? 1 : 0;
    }
}
MS2_REPLACE_METHOD(0x1401CD490, CXORCrypter, Encrypt, 141, 0xC2E8D752);

BOOL CXORCrypter::Decrypt(BYTE* pBuffer, UINT nSize, void* /*pReserved*/)
{
    int nKeyIndex = 0;
    for (UINT i = 0; i < nSize; ++i)
    {
        pBuffer[i] ^= m_pKey[nKeyIndex];
        nKeyIndex = (nKeyIndex == 0) ? 1 : 0;
    }
    return TRUE;
}
MS2_REPLACE_METHOD(0x1401CD530, CXORCrypter, Decrypt, 146, 0x416CBFED);

// ---------------------------------------------------------------------------------------------------------------
// CTableCrypter: byte substitution through a 256-entry permutation (and its inverse for Decrypt).

void CTableCrypter::Encrypt(BYTE* pBuffer, UINT nSize, void* /*pReserved*/)
{
    for (UINT i = 0; i < nSize; ++i)
        pBuffer[i] = m_pEncryptTable[pBuffer[i]];
}
MS2_REPLACE_METHOD(0x1401CD7D0, CTableCrypter, Encrypt, 94, 0xEE661B00);

BOOL CTableCrypter::Decrypt(BYTE* pBuffer, UINT nSize, void* /*pReserved*/)
{
    for (UINT i = 0; i < nSize; ++i)
        pBuffer[i] = m_pDecryptTable[pBuffer[i]];
    return TRUE;
}
MS2_REPLACE_METHOD(0x1401CD840, CTableCrypter, Decrypt, 99, 0x8BEE29AF);

// ---------------------------------------------------------------------------------------------------------------
// CRearrangeCrypter: swap the first and second half of the buffer (odd size: the last byte stays).

void CRearrangeCrypter::Init()   // 0x1401cd910, 6 bytes: not worth a hook
{
}

// The exe's swap<unsigned char> (0x1401cdb50, COMDAT) is not VS2017's std::swap (3 std::move calls): it calls
// one identity function (std::forward<unsigned char&>) four times. Name unknown; this reproduces it byte for byte.
template <class T> void SwapT(T& a, T& b)
{
    T t = std::forward<T&>(a);
    std::forward<T&>(a) = std::forward<T&>(b);
    std::forward<T&>(b) = t;
}

void CRearrangeCrypter::Encrypt(BYTE* pBuffer, UINT nSize, void* /*pReserved*/)
{
    UINT nHalf = nSize / 2;
    for (UINT i = 0; i < nHalf; ++i)
        SwapT(pBuffer[i], pBuffer[nHalf + i]);
}
MS2_REPLACE_METHOD(0x1401CD920, CRearrangeCrypter, Encrypt, 126, 0x566F6F41);

BOOL CRearrangeCrypter::Decrypt(BYTE* pBuffer, UINT nSize, void* /*pReserved*/)
{
    UINT nHalf = nSize / 2;
    for (UINT i = 0; i < nHalf; ++i)
        SwapT(pBuffer[i], pBuffer[nHalf + i]);
    return TRUE;
}
MS2_REPLACE_METHOD(0x1401CD9B0, CRearrangeCrypter, Decrypt, 131, 0x8AE4685C);
