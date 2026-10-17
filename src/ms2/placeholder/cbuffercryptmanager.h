// CBufferCryptManager: RTTI name; ctor 0x1401cdc50, deleting dtor allocation size 0x58.
#pragma once
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/buffercryptmanager.h"
class CBufferCryptManager : public TSingleton<CBufferCryptManager> {
public:
    CBufferCryptManager();
    virtual ~CBufferCryptManager();
    // One crypter per decimal digit of the connection sequence number (0 = none, 1 = rearrange, 2 = xor, 3 = table):
    // the ctor and both packet drivers (free functions in the unit) index it with a digit, so it is an array, not four
    // named pointers, and it is reachable directly.
    IBufferCrypter* m_crypters[4];
private:
    MS2_LAYOUT_FRIEND;
    CTableCrypter m_tableCrypter;
    CRearrangeCrypter m_rearrangeCrypter;
    CXORCrypter m_xorCrypter;
};
MS2_CHECK_SIZE(CBufferCryptManager,0x58);
MS2_CHECK_OFFSET(CBufferCryptManager,m_crypters,0x08);
MS2_CHECK_OFFSET(CBufferCryptManager,m_tableCrypter,0x28);
MS2_CHECK_OFFSET(CBufferCryptManager,m_xorCrypter,0x48);
