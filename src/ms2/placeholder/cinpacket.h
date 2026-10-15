// CInPacket: wire input buffer; layout from packet.cpp and gamesocket's inline constructor.
#pragma once
#include <afx.h>
#include "ms2/commonfiles/stream.h"
class CInPacket : public CIOBuffer, public CInputStream {
public:
    inline explicit CInPacket(int flags=0);
    inline ~CInPacket();
    unsigned vfunc_0() override;
    short vfunc_1() override;

    bool vfunc_o8_0() override;
    unsigned char vfunc_o8_1() override;
    short vfunc_o8_2() override;
    int vfunc_o8_3() override;
    __int64 vfunc_o8_4() override;
    float vfunc_o8_5() override;
    CString vfunc_o8_6() override;
    CString vfunc_o8_7() override;
    CStringW vfunc_o8_8() override;
    void vfunc_o8_9(void* data,int count) override;
    Unk_StreamPoint vfunc_o8_10() override;
    Unk_StreamPoint vfunc_o8_11() override;
    float vfunc_o8_12() override;
    float vfunc_o8_13() override;
    float vfunc_o8_14(int scale) override;
    float vfunc_o8_15() override;
    float vfunc_o8_16(int scale) override;

    int FUN_14070ff00(void*,void*,int);
    void FUN_140710280(int,unsigned*);
    int FUN_14070fe80();
    void FUN_140713940();
    unsigned FUN_141269940(unsigned key) { return (unsigned)m_opcode ^ (key >> 16); }
    void FUN_14126c7b0(int n) { m_sequence=n; }
    int m_flags,m_state;
    ATL::CAtlArray<unsigned char> m_data;
    int m_length; unsigned short m_opcode;
    int m_40,m_packetLength,m_offset,m_sequence;
};
MS2_CHECK_SIZE(CInPacket,0x50);
MS2_CHECK_OFFSET(CInPacket,m_data,0x18);
MS2_CHECK_OFFSET(CInPacket,m_opcode,0x3c);
