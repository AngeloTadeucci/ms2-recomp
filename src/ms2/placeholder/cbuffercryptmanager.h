// CBufferCryptManager: RTTI name; ctor 0x1401cdc50, deleting dtor allocation size 0x58.
#pragma once
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/buffercryptmanager.h"
class CBufferCryptManager : public TSingleton<CBufferCryptManager> {
public:
    CBufferCryptManager();
    virtual ~CBufferCryptManager();
private:
    MS2_LAYOUT_FRIEND;
    IBufferCrypter* m_none;
    IBufferCrypter* m_rearrange;
    IBufferCrypter* m_xor;
    IBufferCrypter* m_table;
    CTableCrypter m_tableCrypter;
    CRearrangeCrypter m_rearrangeCrypter;
    CXORCrypter m_xorCrypter;
};
MS2_CHECK_SIZE(CBufferCryptManager,0x58);
MS2_CHECK_OFFSET(CBufferCryptManager,m_tableCrypter,0x28);
MS2_CHECK_OFFSET(CBufferCryptManager,m_xorCrypter,0x48);
