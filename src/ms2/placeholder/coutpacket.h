// coutpacket.h - COutPacket (RTTI .?AVCOutPacket@@, base COutputStream, vftable 0x142cf27e8, 17 slots).
// Not an original header (packet.cpp defines the class in the exe); declaration proven from the exe.
// Slot list = COutputStream's 17 encoders (commonfiles/stream.h vfunc_o10_N); there is NO virtual destructor
// (slot 0 is the bool encoder 0x140710710, which calls slot 1). Non-virtual ~COutPacket at 0x14020a630.
// Layout: vftable +0, int +8 (=0), int +0xc (=0), int +0x10 (ctor arg 2), uint +0x14 (write offset),
// CAtlArray<void*>(?) at +0x18 (reserved 0x100 bytes by the ctor 0x140710500, which takes (type, int)).
// Slots: 0 bool 0x140710710, 1 u8 0x14020ac70, 2 i16 0x14020ad10, 3 i32 0x14020adb0, 4 i64 0x14020ae50,
// 5 float(as int) 0x14020b450, 6 CString->wide 0x14020afc0, 7 CString 0x14020b090, 8 CStringW 0x14020b1e0,
// 9 raw bytes 0x14020aef0, 10 point 0x14020b2c0, 11 point 0x14020b2f0, 12..16 scaled floats 0x14020b510..b5e0.
// Encode1/2/4/8 are the old names of slots 1..4; they are forced-inline wrappers that call the slot directly
// (the exe calls the slot functions directly on local packets).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"

class COutPacket : public COutputStream
{
public:
    COutPacket(int nType, int nUnk);
    ~COutPacket();
    void vfunc_o10_0(bool value) override;
    void vfunc_o10_1(unsigned char value) override;
    void vfunc_o10_2(short value) override;
    void vfunc_o10_3(int value) override;
    void vfunc_o10_4(__int64 value) override;
    void vfunc_o10_5(float value) override;
    void vfunc_o10_6(const CString& value) override;
    void vfunc_o10_7(const CString& value) override;
    void vfunc_o10_8(const CStringW& value) override;
    void vfunc_o10_9(const void* data, int count) override;
    void vfunc_o10_10(const Unk_StreamPoint& value) override;
    void vfunc_o10_11(const Unk_StreamPoint& value) override;
    void vfunc_o10_12(float value) override;
    void vfunc_o10_13(float value) override;
    void vfunc_o10_14(float value, int scale) override;
    void vfunc_o10_15(float value) override;
    void vfunc_o10_16(float value, int scale) override;

    __forceinline void Encode1(unsigned char n) { COutPacket::vfunc_o10_1(n); }
    __forceinline void Encode2(short n)         { COutPacket::vfunc_o10_2(n); }
    __forceinline void Encode4(int n)           { COutPacket::vfunc_o10_3(n); }
    __forceinline void Encode8(__int64 n)       { COutPacket::vfunc_o10_4(n); }
    __forceinline void FUN_14020ae50(__int64 n) { COutPacket::vfunc_o10_4(n); }

private:
    // no array members in placeholders: an array makes every local of the class a /GS buffer (cookie + handler)
    void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(COutPacket, 0x38);

// Sends `packet` through the client socket (0x140710590: gets the socket singleton 0x140714f90, null-checked).
void FUN_140710590(COutPacket& packet);
