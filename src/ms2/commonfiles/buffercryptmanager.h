// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// Original CU: e:\build\kr\22_04\ms2code\commonfiles\buffercryptmanager.cpp  -- NAME GUESSED (no __FILE__ string):
// the code sits at 0x1401cd3b0..0x1401cdfd0 between blockchecker.cpp (0x1401c9ea0) and chatemoticontable.cpp
// (0x1401e6a40); commonfiles objs are linked in alphabetical order.
//
// Packet buffer crypters. The server side counterpart is Maple2's MapleCipher (XOR/Table/Rearrange crypt).
// CBufferCryptManager (TSingleton, instance pointer 0x143aac528) applies them per packet in the order given by the
// decimal digits of a sequence number: 1 = Rearrange, 2 = XOR, 3 = Table.
#pragma once

#include <windows.h>

// vftable 0x142cee440: 3 slots, all _purecall. No virtual destructor.
class IBufferCrypter
{
public:
    virtual void Init() = 0;
    virtual void Encrypt(BYTE* pBuffer, UINT nSize, void* pReserved) = 0;   // pReserved: passed through, unused
    virtual BOOL Decrypt(BYTE* pBuffer, UINT nSize, void* pReserved) = 0;
};

// vftable 0x142cee460, size 0x10.
class CXORCrypter : public IBufferCrypter
{
public:
    void Init() override;                                                   // 0x1401cd3b0 (not recovered)
    void Encrypt(BYTE* pBuffer, UINT nSize, void* pReserved) override;      // 0x1401cd490
    BOOL Decrypt(BYTE* pBuffer, UINT nSize, void* pReserved) override;      // 0x1401cd530

    BYTE* m_pKey;   // +0x08, new BYTE[2]
};

// vftable 0x142cee480, size 0x18.
class CTableCrypter : public IBufferCrypter
{
public:
    void Init() override;                                                   // 0x1401cd6b0 (not recovered)
    void Encrypt(BYTE* pBuffer, UINT nSize, void* pReserved) override;      // 0x1401cd7d0
    BOOL Decrypt(BYTE* pBuffer, UINT nSize, void* pReserved) override;      // 0x1401cd840

    BYTE* m_pEncryptTable;  // +0x08, new BYTE[256], shuffled 0..255
    BYTE* m_pDecryptTable;  // +0x10, new BYTE[256], inverse permutation
};

// vftable 0x142cee4a0, size 0x08.
class CRearrangeCrypter : public IBufferCrypter
{
public:
    void Init() override;                                                   // 0x1401cd910 (empty)
    void Encrypt(BYTE* pBuffer, UINT nSize, void* pReserved) override;      // 0x1401cd920
    BOOL Decrypt(BYTE* pBuffer, UINT nSize, void* pReserved) override;      // 0x1401cd9b0
};
