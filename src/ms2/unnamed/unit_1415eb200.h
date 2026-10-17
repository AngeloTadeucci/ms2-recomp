// unit_1415eb200.h - CNMVirtualUserInfo (RTTI .?AVCNMVirtualUserInfo@@) and its CNMSerializable base, from the Nexon
// Messenger (nm) SDK embedded in MapleStory2.exe KMS2_DEV x64 (2022-04-13). unit_1415eb200 recovers the two
// out-of-line copy constructors (reference and pointer overloads); the class's own ctor and its virtual bodies live in
// unit_14156a020 / unit_1415eaeb0. Header name assumed; member names are invented from use.
#pragma once
#include "ms2/ms2layout.h"

// CNMSerializable: the framing base (signature/kind/format/flag), 0x10 bytes, vftable 0x142f3bd18, 8 slots. Its
// plain ctor is 0x14156c8b0 and its copy ctor 0x1415eafb0.
class CNMSerializable
{
public:
    CNMSerializable();                                          // 0x14156c8b0
    CNMSerializable(const CNMSerializable& r);                  // 0x1415eafb0
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    MS2_LAYOUT_FRIEND;
    unsigned short m_wSignature;                                // +0x08 signature ("vU" = 0x7576)
    unsigned char m_bKind;                                      // +0x0a
    unsigned char m_bFormat;                                    // +0x0b
    unsigned char m_bFlag;                                      // +0x0c
};
MS2_CHECK_SIZE(CNMSerializable, 0x10);

// CNMVirtualUserInfo: one virtual (game) user record, 0x490 bytes, vftable 0x142f3c010 (8 slots: slot 0 is the scalar
// deleting destructor, slot 7 the shared CNMSerializable stub). Three fixed buffers plus a 64-bit key and four ints.
class CNMVirtualUserInfo : public CNMSerializable
{
public:
    CNMVirtualUserInfo();                                       // 0x14156ef50
    CNMVirtualUserInfo(const CNMVirtualUserInfo& r);            // 0x1415eb200
    CNMVirtualUserInfo(const CNMVirtualUserInfo* p);            // 0x1415eb300
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();

    MS2_LAYOUT_FRIEND;
    struct NMKey64 { unsigned __int64 v; } m_10;                 // +0x10 NMKey64
    char m_18[0x40];                                            // +0x18
    char m_58[0x40];                                            // +0x58
    char m_98[0x3e8];                                           // +0x98
    int m_480;                                                  // +0x480
    int m_484;                                                  // +0x484
    int m_488;                                                  // +0x488
    int m_48c;                                                  // +0x48c
};
MS2_CHECK_SIZE(CNMVirtualUserInfo, 0x490);
