// coutpacket.h - PLACEHOLDER for COutPacket (RTTI .?AVCOutPacket@@, base COutputStream, vftable 0x142cf27e8,
// 17 slots). NOT an original header. Layout: COutputStream (0x18: vftable + 16 bytes), CAtlArray<void*> at +0x18.
// Ctor 0x140710500 (type, int; reserves 0x100 bytes), dtor 0x14020a630.
// Encode1/Encode4 are virtual (slots 1 and 3 of COutPacket's vftable, 0x14020ac70 / 0x14020adb0) but are called
// directly on local packets; the names are inferred from the argument sizes (byte / dword).
#pragma once

#include "ms2/ms2layout.h"

class COutPacket
{
public:
    COutPacket(int nType, int nUnk);
    virtual ~COutPacket();                                  // slot 0
    virtual void Encode1(unsigned char n);                  // slot 1 0x14020ac70
    virtual void Encode2(short n);                          // slot 2 0x14020ad10 (word; Ghidra: vfunc_2)
    virtual void Encode4(int n);                            // slot 3 0x14020adb0

private:
    // no array members in placeholders: an array makes every local of the class a /GS buffer (cookie + handler)
    void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(COutPacket, 0x38);

// Sends `packet` through the client socket (0x140710590: gets the socket singleton 0x140714f90, null-checked).
void FUN_140710590(COutPacket& packet);
