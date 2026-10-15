// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Packet payload serializers.
// MS2-UNIT: unit_1401f9eb0
// MS2-RANGE: 0x1401f9eb0-0x140208340 .text$mn
#define MS2_THIS_FILE "" // No original source path recovered; no unit-file assertions here.
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_1401f9eb0.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/exception.h"
// Invented constraint names; the representation follows commonfiles/constraints.h calls.
#define PAYLOAD_CONSTRAINT_ASSERT(line,expr) (void)((!!(expr)) || (_wassert(_CRT_WIDE(#expr),L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\constraints.h",line),0))
template<class T>struct Unk_140203550 {
    T minimum,maximum;
    Unk_140203550(T constraintMin,T constraintMax):minimum(constraintMin),maximum(constraintMax) {
        PAYLOAD_CONSTRAINT_ASSERT(157,constraintMin <= constraintMax);
    }
    bool Check(T value)const {
        bool checkResult = minimum <= value && value <= maximum;
        PAYLOAD_CONSTRAINT_ASSERT(164,checkResult);
        return checkResult;
    }
};
struct Unk_1402c43a0 {bool Check(unsigned int)const;};
struct Unk_1402c4270 {bool Check(unsigned int)const;};
struct Unk_1402c41d0 {bool Check(unsigned int)const;};
struct Unk_1402c4220 {bool Check(unsigned short)const;};
struct Unk_1402c43f0 {bool Check(unsigned char)const;};
template<class Constraint>unsigned int Unk_Read32(void* packet,Constraint constraint) {
    unsigned int value=reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(packet)+8)->vfunc_o8_3();
    if(!constraint.Check(value))throw Exception(13);
    return value;
}
template<class Constraint>unsigned char Unk_Read8(void* packet,Constraint constraint) {
    unsigned char value=reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(packet)+8)->vfunc_o8_1();
    if(!constraint.Check(value))throw Exception(13);
    return value;
}
template<class Constraint>unsigned short Unk_Read16(void* packet,Constraint constraint) {
    unsigned short value=reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(packet)+8)->vfunc_o8_2();
    if(!constraint.Check(value))throw Exception(13);
    return value;
}

// Payloads are opaque: these helpers neither allocate nor copy whole payload objects.
// Typed accesses preserve each observed field offset and wire width.

// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1401f9f20
void FUN_1401f9f20(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x18));
    stream.vfunc_o10_2(*reinterpret_cast<short*>(payload + 0x1c));
    stream.vfunc_o10_8(reinterpret_cast<CStringW*>(payload + 0x20)->Trim());
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x28));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x2c));
    stream.vfunc_o10_2(static_cast<short>(reinterpret_cast<CByteBuffer*>(payload + 0x30)->FUN_140205190()));
    stream.vfunc_o10_9(reinterpret_cast<CByteBuffer*>(payload + 0x30)->FUN_140204eb0(),reinterpret_cast<CByteBuffer*>(payload + 0x30)->FUN_140205190());
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x70));
}
MS2_REPLACE(0x1401F9F20, FUN_1401f9f20, 345, 0x728AE70E);


// @0x1401fa2c0
void FUN_1401fa2c0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x8));
}
MS2_REPLACE(0x1401FA2C0, FUN_1401fa2c0, 81, 0xC84F2203);


// @0x1401fa3d0
void FUN_1401fa3d0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FA3D0, FUN_1401fa3d0, 43, 0xCCA85769);


// @0x1401fa410
void FUN_1401fa410(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FA410, FUN_1401fa410, 61, 0xD1979832);


// @0x1401fa460
void FUN_1401fa460(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FA460, FUN_1401fa460, 43, 0xCCA85769);


// @0x1401fa4a0
void FUN_1401fa4a0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FA4A0, FUN_1401fa4a0, 61, 0xD1979832);


// @0x1401fa4f0
void FUN_1401fa4f0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FA4F0, FUN_1401fa4f0, 43, 0xCCA85769);


// @0x1401fa530
void FUN_1401fa530(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FA530, FUN_1401fa530, 61, 0xD1979832);


// @0x1401fa580
void FUN_1401fa580(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
}
MS2_REPLACE(0x1401FA580, FUN_1401fa580, 66, 0x5231AD06);


// @0x1401fa5d0
void FUN_1401fa5d0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<int*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x1401FA5D0, FUN_1401fa5d0, 102, 0x24BCB130);


// @0x1401fa640
void FUN_1401fa640(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
}
MS2_REPLACE(0x1401FA640, FUN_1401fa640, 66, 0x5231AD06);


// @0x1401fa690
void FUN_1401fa690(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<int*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x1401FA690, FUN_1401fa690, 102, 0x24BCB130);


// @0x1401fa700
void FUN_1401fa700(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x8));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x10));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x18));
}
MS2_REPLACE(0x1401FA700, FUN_1401fa700, 144, 0x8BFAAA30);


// @0x1401fa9a0
void FUN_1401fa9a0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x8));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0xc));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x10));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x18));
}
MS2_REPLACE(0x1401FA9A0, FUN_1401fa9a0, 190, 0x5E157002);


// @0x1401fb760
void FUN_1401fb760(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x8));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0xc));
}
MS2_REPLACE(0x1401FB760, FUN_1401fb760, 93, 0xDAD03993);


// @0x1401fb7d0
void FUN_1401fb7d0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<unsigned int*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0xc) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
}
MS2_REPLACE(0x1401FB7D0, FUN_1401fb7d0, 151, 0x2EDB9444);


// @0x1401fb910
void FUN_1401fb910(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FB910, FUN_1401fb910, 43, 0xCCA85769);


// @0x1401fb950
void FUN_1401fb950(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FB950, FUN_1401fb950, 61, 0xD1979832);


// @0x1401fb9a0
void FUN_1401fb9a0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x8));
}
MS2_REPLACE(0x1401FB9A0, FUN_1401fb9a0, 68, 0xFCB16D80);


// @0x1401fb9f0
void FUN_1401fb9f0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<unsigned int*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
}
MS2_REPLACE(0x1401FB9F0, FUN_1401fb9f0, 106, 0xF2686973);


// @0x1401fba60
void FUN_1401fba60(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FBA60, FUN_1401fba60, 43, 0xCCA85769);


// @0x1401fbaa0
void FUN_1401fbaa0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FBAA0, FUN_1401fbaa0, 61, 0xD1979832);


// @0x1401fbaf0
void FUN_1401fbaf0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x8));
    stream.vfunc_o10_2(*reinterpret_cast<short*>(payload + 0x10));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x14));
}
MS2_REPLACE(0x1401FBAF0, FUN_1401fbaf0, 117, 0x8616E2DF);


// @0x1401fbb70
void FUN_1401fbb70(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<__int64*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<short*>(payload + 0x10) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_2();
    *reinterpret_cast<int*>(payload + 0x14) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x1401FBB70, FUN_1401fbb70, 189, 0x2402E752);


// @0x1401fbc40
void FUN_1401fbc40(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x8));
}
MS2_REPLACE(0x1401FBC40, FUN_1401fbc40, 81, 0xC84F2203);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1401fbd30
void FUN_1401fbd30(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload));
}
MS2_REPLACE(0x1401FBD30, FUN_1401fbd30, 53, 0x02F7FD6B);


// @0x1401fbf70
void FUN_1401fbf70(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x8));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x10));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FBF70, FUN_1401fbf70, 105, 0x2AC57676);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1401fc0b0
void FUN_1401fc0b0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x8));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0xc));
}
MS2_REPLACE(0x1401FC0B0, FUN_1401fc0b0, 102, 0x13010E13);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1401fc1e0
void FUN_1401fc1e0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload));
}
MS2_REPLACE(0x1401FC1E0, FUN_1401fc1e0, 53, 0x02F7FD6B);


// @0x1401fc470
void FUN_1401fc470(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x8));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x10));
}
MS2_REPLACE(0x1401FC470, FUN_1401fc470, 92, 0x04B23741);


// @0x1401fc4e0
void FUN_1401fc4e0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned char*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<__int64*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<int*>(payload + 0x10) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x1401FC4E0, FUN_1401fc4e0, 145, 0x7317C2E7);


// @0x1401fc580
void FUN_1401fc580(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload));
}
MS2_REPLACE(0x1401FC580, FUN_1401fc580, 43, 0xC51E1559);


// @0x1401fc5c0
void FUN_1401fc5c0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned char*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
}
MS2_REPLACE(0x1401FC5C0, FUN_1401fc5c0, 60, 0x2C84E205);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1401fc610
void FUN_1401fc610(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_6(*reinterpret_cast<CString*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x8));
}
MS2_REPLACE(0x1401FC610, FUN_1401fc610, 78, 0x705DDEAA);


// @0x1401fc710
void FUN_1401fc710(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_5(*reinterpret_cast<float*>(payload));
}
MS2_REPLACE(0x1401FC710, FUN_1401fc710, 44, 0xDE48B588);


// @0x1401fcc00
void FUN_1401fcc00(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_2(*reinterpret_cast<short*>(payload));
}
MS2_REPLACE(0x1401FCC00, FUN_1401fcc00, 43, 0x3CA2416A);


// @0x1401fcc40
void FUN_1401fcc40(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned int*>(payload) = static_cast<unsigned short>(reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_2());
}
MS2_REPLACE(0x1401FCC40, FUN_1401fcc40, 63, 0xA149175E);


// @0x1401fcc90
void FUN_1401fcc90(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x8));
}
MS2_REPLACE(0x1401FCC90, FUN_1401fcc90, 67, 0xE289C58A);


// @0x1401fcce0
void FUN_1401fcce0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<__int64*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FCCE0, FUN_1401fcce0, 103, 0x0C837FA4);


// @0x1401fcd50
void FUN_1401fcd50(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
}
MS2_REPLACE(0x1401FCD50, FUN_1401fcd50, 42, 0x198D3D0B);


// @0x1401fcd80
void FUN_1401fcd80(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x1401FCD80, FUN_1401fcd80, 60, 0x21DC48C6);


// @0x1401fd190
void FUN_1401fd190(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x8));
}
MS2_REPLACE(0x1401FD190, FUN_1401fd190, 68, 0xFCB16D80);


// @0x1401fd1e0
void FUN_1401fd1e0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<unsigned char*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
}
MS2_REPLACE(0x1401FD1E0, FUN_1401fd1e0, 103, 0xCBD3A54D);


// @0x1401fd250
void FUN_1401fd250(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload));
}
MS2_REPLACE(0x1401FD250, FUN_1401fd250, 43, 0xC51E1559);


// @0x1401fd290
void FUN_1401fd290(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned char*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
}
MS2_REPLACE(0x1401FD290, FUN_1401fd290, 60, 0x2C84E205);


// @0x1401fd400
void FUN_1401fd400(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<unsigned short*>(payload + 0x4));
    stream.vfunc_o10_5(*reinterpret_cast<float*>(payload + 0x8));
}
MS2_REPLACE(0x1401FD400, FUN_1401fd400, 105, 0x8D4447BE);


// @0x1401fd470
void FUN_1401fd470(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<short*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<float*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_5();
}
MS2_REPLACE(0x1401FD470, FUN_1401fd470, 147, 0x5C477225);


// @0x1401fdad0
void FUN_1401fdad0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
}
MS2_REPLACE(0x1401FDAD0, FUN_1401fdad0, 42, 0x198D3D0B);


// @0x1401fdb00
void FUN_1401fdb00(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x1401FDB00, FUN_1401fdb00, 60, 0x21DC48C6);


// @0x1401fdb50
void FUN_1401fdb50(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x8));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x10));
    stream.vfunc_o10_2(*reinterpret_cast<short*>(payload + 0x14));
}
MS2_REPLACE(0x1401FDB50, FUN_1401fdb50, 116, 0x3693878F);


// @0x1401fdc80
void FUN_1401fdc80(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
    stream.vfunc_o10_2(*reinterpret_cast<short*>(payload + 0x8));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0xc));
}
MS2_REPLACE(0x1401FDC80, FUN_1401fdc80, 116, 0xEAE15273);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1401fe0d0
void FUN_1401fe0d0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_7(*reinterpret_cast<CString*>(payload));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x8));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x10));
    stream.vfunc_o10_2(*reinterpret_cast<short*>(payload + 0x14));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x18));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x1c));
}
MS2_REPLACE(0x1401FE0D0, FUN_1401fe0d0, 177, 0x7B6F94D9);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1401fe310
void FUN_1401fe310(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_6(*reinterpret_cast<CString*>(payload));
}
MS2_REPLACE(0x1401FE310, FUN_1401fe310, 53, 0xEE8624DB);


// @0x1401fe790
void FUN_1401fe790(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FE790, FUN_1401fe790, 43, 0xCCA85769);


// @0x1401fe7d0
void FUN_1401fe7d0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FE7D0, FUN_1401fe7d0, 61, 0xD1979832);


// @0x1401fe820
void FUN_1401fe820(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
}
MS2_REPLACE(0x1401FE820, FUN_1401fe820, 42, 0x198D3D0B);


// Not hooked: validation can construct a DLL-local Exception.
// @0x1401fe850
void FUN_1401fe850(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned int*>(payload) = Unk_Read32(inputPacket,Unk_1402c43a0());

}

// @0x1401fe880
void FUN_1401fe880(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x4));
}
MS2_REPLACE(0x1401FE880, FUN_1401fe880, 67, 0xC1D05E0E);


// Not hooked: validation can construct a DLL-local Exception.
// @0x1401fe8d0
void FUN_1401fe8d0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned int*>(payload) = Unk_Read32(inputPacket,Unk_1402c43a0());
    *reinterpret_cast<unsigned char*>(payload+4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket)+8)->vfunc_o8_1();
}

// @0x1401fe930
void FUN_1401fe930(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x4));
}
MS2_REPLACE(0x1401FE930, FUN_1401fe930, 67, 0xC1D05E0E);


// Not hooked: validation can construct a DLL-local Exception.
// @0x1401fe980
void FUN_1401fe980(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned int*>(payload) = Unk_Read32(inputPacket,Unk_1402c43a0());
    *reinterpret_cast<unsigned int*>(payload+4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket)+8)->vfunc_o8_1();
}

// @0x1401fe9e0
void FUN_1401fe9e0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
}
MS2_REPLACE(0x1401FE9E0, FUN_1401fe9e0, 66, 0x5231AD06);


// Not hooked: validation can construct a DLL-local Exception.
// @0x1401fea30
void FUN_1401fea30(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned int*>(payload) = Unk_Read32(inputPacket,Unk_1402c4270());
    *reinterpret_cast<unsigned int*>(payload+4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket)+8)->vfunc_o8_3();
}

// @0x1401fea90
void FUN_1401fea90(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FEA90, FUN_1401fea90, 43, 0xCCA85769);


// @0x1401fead0
void FUN_1401fead0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FEAD0, FUN_1401fead0, 61, 0xD1979832);


// @0x1401feb20
void FUN_1401feb20(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FEB20, FUN_1401feb20, 43, 0xCCA85769);


// @0x1401feb60
void FUN_1401feb60(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FEB60, FUN_1401feb60, 61, 0xD1979832);


// @0x1401febb0
void FUN_1401febb0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
}
MS2_REPLACE(0x1401FEBB0, FUN_1401febb0, 43, 0xCCA85769);


// @0x1401febf0
void FUN_1401febf0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FEBF0, FUN_1401febf0, 61, 0xD1979832);


// @0x1401fec40
void FUN_1401fec40(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x8));
}
MS2_REPLACE(0x1401FEC40, FUN_1401fec40, 68, 0x0FA3158C);


// @0x1401fec90
void FUN_1401fec90(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<__int64*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FEC90, FUN_1401fec90, 104, 0x1A92EBE0);


// @0x1401fed00
void FUN_1401fed00(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x8));
}
MS2_REPLACE(0x1401FED00, FUN_1401fed00, 68, 0x0FA3158C);


// @0x1401fed50
void FUN_1401fed50(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<__int64*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
}
MS2_REPLACE(0x1401FED50, FUN_1401fed50, 104, 0x1A92EBE0);


// @0x1401ff810
void FUN_1401ff810(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x4));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x8));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0xc));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x10));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x14));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x18));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x20));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x24));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x1c));
}
MS2_REPLACE(0x1401FF810, FUN_1401ff810, 267, 0xEF8C240A);


// @0x1401ff930
void FUN_1401ff930(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0x8) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0xc) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0x10) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0x14) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0x18) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0x20) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    *reinterpret_cast<unsigned int*>(payload + 0x24) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<unsigned int*>(payload + 0x1c) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
}
MS2_REPLACE(0x1401FF930, FUN_1401ff930, 555, 0x6D2D944B);


// @0x1401ffb70
void FUN_1401ffb70(unsigned int* destination, const unsigned int* source)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 0) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 0);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 4) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 4);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 8) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 8);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 12) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 12);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 16) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 16);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 20) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 20);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 24) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 24);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 32) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 32);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 36) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 36);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(destination) + 28) = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(source) + 28);
}
MS2_REPLACE(0x1401FFB70, FUN_1401ffb70, 169, 0xFB714906);


// @0x1401ffd60
void FUN_1401ffd60(unsigned char* payload)
{
    *reinterpret_cast<__int64*>(payload) = 0;
    *reinterpret_cast<int*>(payload + 0x8) = 0;
    *reinterpret_cast<int*>(payload + 0xc) = 0;
    reinterpret_cast<CStringW*>(payload + 16)->Empty();
    reinterpret_cast<CString*>(payload + 24)->Empty();
}
MS2_REPLACE(0x1401FFD60, FUN_1401ffd60, 86, 0x55B411BB);

// @0x140201180
void FUN_140201180(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x4));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x88));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x90));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x98));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0xa0));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0xa8));
    stream.vfunc_o10_7(*reinterpret_cast<CString*>(payload + 0xb0));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0xb8));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0xc0));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0xc8));
    stream.vfunc_o10_7(*reinterpret_cast<CString*>(payload + 0xd0));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0xd8));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0xe0));
}
MS2_REPLACE(0x140201180, FUN_140201180, 463, 0xFA1E0F19);


// @0x140201a10
void FUN_140201a10(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x18));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x20));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x24));
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload + 0x28));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x2c));
    stream.vfunc_o10_7(*reinterpret_cast<CString*>(payload + 0x30));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x38));
}
MS2_REPLACE(0x140201A10, FUN_140201a10, 231, 0xE74226EA);


// @0x140201e50
void FUN_140201e50(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
}
MS2_REPLACE(0x140201E50, FUN_140201e50, 66, 0x5231AD06);


// @0x140201ea0
void FUN_140201ea0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<int*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x140201EA0, FUN_140201ea0, 102, 0x24BCB130);


// @0x140201f10
void FUN_140201f10(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
}
MS2_REPLACE(0x140201F10, FUN_140201f10, 66, 0x5231AD06);


// @0x140201f60
void FUN_140201f60(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<int*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x140201F60, FUN_140201f60, 102, 0x24BCB130);


// @0x140201fd0
void FUN_140201fd0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
}
MS2_REPLACE(0x140201FD0, FUN_140201fd0, 42, 0x198D3D0B);


// @0x140202000
void FUN_140202000(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x140202000, FUN_140202000, 60, 0x21DC48C6);


// @0x140202050
void FUN_140202050(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
}
MS2_REPLACE(0x140202050, FUN_140202050, 42, 0x198D3D0B);


// @0x140202080
void FUN_140202080(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x140202080, FUN_140202080, 60, 0x21DC48C6);


// @0x1402020d0
void FUN_1402020d0(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
}
MS2_REPLACE(0x1402020D0, FUN_1402020d0, 66, 0x5231AD06);


// @0x140202120
void FUN_140202120(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    *reinterpret_cast<int*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x140202120, FUN_140202120, 102, 0x24BCB130);


// @0x140202190
void FUN_140202190(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload));
    stream.vfunc_o10_8(*reinterpret_cast<CStringW*>(payload + 0x8));
}
MS2_REPLACE(0x140202190, FUN_140202190, 80, 0x1F873B3D);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x140202290
void FUN_140202290(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload));
    if (*reinterpret_cast<int*>(payload) == 3) {
        stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
    }
}
MS2_REPLACE(0x140202290, FUN_140202290, 87, 0xE6055E16);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1402022f0
void FUN_1402022f0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    if (*reinterpret_cast<unsigned int*>(payload) == 3) {
        *reinterpret_cast<int*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    }
}
MS2_REPLACE(0x1402022F0, FUN_1402022f0, 125, 0x35803A0D);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x140202380
void FUN_140202380(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_1(*reinterpret_cast<unsigned char*>(payload));
    if (*reinterpret_cast<int*>(payload) == 5) {
        stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x4));
    }
}
MS2_REPLACE(0x140202380, FUN_140202380, 87, 0x884B7380);


// MS2-FUNCTIONAL: equivalent field operations; /Od temporary placement differs.
// @0x1402023e0
void FUN_1402023e0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<unsigned int*>(payload) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_1();
    if (*reinterpret_cast<unsigned int*>(payload) == 5) {
        *reinterpret_cast<int*>(payload + 0x4) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
    }
}
MS2_REPLACE(0x1402023E0, FUN_1402023e0, 125, 0x9EC6C0F7);


// @0x140202470
void FUN_140202470(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x18));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x20));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x28));
}
MS2_REPLACE(0x140202470, FUN_140202470, 93, 0xF27221B3);


// @0x1402024e0
void FUN_1402024e0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload + 0x18) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<__int64*>(payload + 0x20) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<int*>(payload + 0x28) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x1402024E0, FUN_1402024e0, 147, 0xCDACF076);


// @0x140202580
void FUN_140202580(unsigned char* payload, COutputStream& stream)
{
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x18));
    stream.vfunc_o10_4(*reinterpret_cast<__int64*>(payload + 0x20));
    stream.vfunc_o10_3(*reinterpret_cast<int*>(payload + 0x28));
}
MS2_REPLACE(0x140202580, FUN_140202580, 93, 0xF27221B3);


// @0x1402025f0
void FUN_1402025f0(unsigned char* payload, void* inputPacket)
{
    *reinterpret_cast<__int64*>(payload + 0x18) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<__int64*>(payload + 0x20) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_4();
    *reinterpret_cast<int*>(payload + 0x28) = reinterpret_cast<CInputStream*>(static_cast<unsigned char*>(inputPacket) + 8)->vfunc_o8_3();
}
MS2_REPLACE(0x1402025F0, FUN_1402025f0, 147, 0xCDACF076);



// @0x140204670
inline void CByteBuffer::FUN_140204670(int count) {
    unsigned required=m_uOffset+count;
    if(m_aByteBuff.GetCount()<required) {
        size_t capacity=m_aByteBuff.GetCount();
        do {capacity<<=1;} while(capacity<required);
        m_aByteBuff.SetCount(capacity);
    }
    m_uLength+=count;
}
// @0x140204eb0
inline unsigned char* CByteBuffer::FUN_140204eb0(){return &m_aByteBuff[0];}
// @0x140205190
inline unsigned CByteBuffer::FUN_140205190()const{return m_uLength;}
MS2_EMIT_CRT_MEMMOVE_S();
