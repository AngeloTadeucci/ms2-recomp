// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Stream cryptor destructor chain.
// MS2-UNIT: unit_1415ef060
// MS2-RANGE: 0x1415ef060-0x1415ef0e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

class CStreamCryptor
{
public:
    virtual ~CStreamCryptor();
};

class CStreamCryptor_v0 : public CStreamCryptor
{
public:
    ~CStreamCryptor_v0() override;
};

class CStreamCryptor_v1 : public CStreamCryptor
{
public:
    ~CStreamCryptor_v1() override;
};

// @0x1415ef060
CStreamCryptor::~CStreamCryptor() = default;

// @0x1415ef080
CStreamCryptor_v0::~CStreamCryptor_v0() = default;

// @0x1415ef0b0
CStreamCryptor_v1::~CStreamCryptor_v1() = default;
