// unit_1415eb400.h - CStreamCryptor and its two concrete subclasses CStreamCryptor_v0 / CStreamCryptor_v1 (RTTI names
// .?AVCStreamCryptor@@ / .?AVCStreamCryptor_v0@@ / .?AVCStreamCryptor_v1@@), from the Nexon Messenger (nm) SDK in
// MapleStory2.exe KMS2_DEV x64 (2022-04-13). unit_1415eb400 recovers the three base ctors and one key-splitting helper;
// the virtual bodies live in unit_1415c44c0 / unit_1415f9410. Header name assumed.
#pragma once
#include "ms2/ms2layout.h"

// CStreamCryptor: abstract stream-cipher interface, 8 bytes (only a vfptr), vftable 0x142f435f8 (7 slots: slot 0 the
// scalar deleting destructor, slots 1-6 pure -> _purecall).
class CStreamCryptor
{
public:
    CStreamCryptor();                                           // 0x1415eb400
    virtual ~CStreamCryptor();                                  // 0x1415f9310
    virtual void vfunc_1() = 0;
    virtual void vfunc_2() = 0;
    virtual void vfunc_3() = 0;
    virtual void vfunc_4() = 0;
    virtual void vfunc_5() = 0;
    virtual void vfunc_6() = 0;
};
MS2_CHECK_SIZE(CStreamCryptor, 8);

// CStreamCryptor_v0: variant 0, 8 bytes, vftable 0x142f43638.
class CStreamCryptor_v0 : public CStreamCryptor
{
public:
    CStreamCryptor_v0();                                        // 0x1415eb420
    virtual ~CStreamCryptor_v0();                               // 0x1415f9350
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
MS2_CHECK_SIZE(CStreamCryptor_v0, 8);

// CStreamCryptor_v1: variant 1, 8 bytes, vftable 0x142f43678.
class CStreamCryptor_v1 : public CStreamCryptor
{
public:
    CStreamCryptor_v1();                                        // 0x1415eb450
    virtual ~CStreamCryptor_v1();                               // 0x1415f9390
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
MS2_CHECK_SIZE(CStreamCryptor_v1, 8);
