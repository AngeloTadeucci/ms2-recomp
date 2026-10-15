// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 4/4 of commonstruct.cpp: the tail of the COMDAT zone
// (MSVC 14.16 std::list/vector/_Tree internals of the unit's containers, accessors, _Xlength_error stubs, CRT memcpy_s/memmove_s).
// Element types are unknown, so the instantiations are written as the free FUN_<va> helpers the callers use (i64 handles).
// MS2-UNIT: commonfiles\commonstruct.cpp#4
// MS2-RANGE: 0x140287f50-0x14028b820 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <math.h>
#include <vector>
#include <list>
#include <memory>
#include <errno.h>
#include <string.h>
typedef __int64 i64;
typedef unsigned __int64 u64;
// std::_Tree_node header of the unit's red-black tree (value after the isnil flag).
struct Unk_TNode { Unk_TNode* left; Unk_TNode* parent; Unk_TNode* right; char color; char isnil; };
// std::_Tree_val: head node pointer + element count.
struct Unk_TVal { Unk_TNode* head; u64 size; };
// Empty tag object of the STL iterator-dispatch overloads.
struct Unk_StlTag {};
#pragma function(memcpy, memset)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
i64 FUN_140159ba0(i64);
i64 FUN_140159bc0(i64);
i64 FUN_14016c7c0(i64);
i64 FUN_140190260(void);
i64 FUN_140277160(i64);
i64 FUN_140278630(i64, i64);
i64 FUN_1402786c0(i64);
i64 FUN_1402789b0(i64, i64, i64);
i64 FUN_14027a270(i64);
i64 FUN_14027a280(i64, i64);
i64 FUN_14027aaa0(i64, i64, i64, i64);
i64 FUN_14027ab70(i64, i64, i64, i64);
i64 FUN_14027ac40(i64, i64, i64, i64);
i64 FUN_14027b0b0(i64, i64, i64, i64);
i64 FUN_14027b180(i64, i64, i64, i64);
i64 FUN_14027b250(i64, i64, i64, i64);
i64 FUN_14027b4d0(i64);
i64 FUN_14027b4e0(i64);
i64 FUN_14027b4f0(i64);
i64 FUN_14027b540(i64);
i64 FUN_14027b560(i64);
i64 FUN_14027b570(i64);
i64 FUN_14027b580(i64);
i64 FUN_14027b590(i64);
i64 FUN_14027bb80(i64, i64);
i64 FUN_14027bcd0(i64, i64);
i64 FUN_14027bd40(i64, i64);
i64 FUN_14027bdb0(i64, i64);
i64 FUN_14027be20(i64, i64);
i64 FUN_14027c3e0(i64);
i64 FUN_14027c3f0(i64);
i64 FUN_14027c400(i64);
i64 FUN_14027ce50(i64, i64, i64);
i64 FUN_14027ced0(i64, i64, i64);
i64 FUN_14027cfb0(i64, i64, i64);
i64 FUN_14027d010(i64, i64, i64);
i64 FUN_14027d390(i64, i64, i64);
i64 FUN_14027d3d0(i64, i64, i64);
i64 FUN_14027d630(i64, i64);
char FUN_14027ee20(i64, i64);
char FUN_14027ef80(i64, i64);
i64 FUN_14027f3b0(i64);
i64 FUN_14027f4e0(i64, i64, i64);
i64 FUN_14027f5b0(i64, i64, i64);
i64 FUN_14027f600(i64);
char FUN_14027f870(i64, i64, i64);
i64 FUN_140281490(i64);
i64 FUN_1402866a0(i64);
i64 FUN_1402866c0(i64);
i64 FUN_1402866e0(i64);
i64 FUN_140286700(i64);
i64 FUN_140286720(i64);
i64 FUN_140286760(i64);
i64 FUN_140286780(i64);
i64 FUN_1402867a0(i64);
i64 FUN_1402867c0(i64);
i64 FUN_1402867e0(i64);
i64 FUN_140286800(i64);
i64 FUN_1402873b0(i64, i64, i64, i64);
i64 FUN_1402875b0(i64, i64, i64);
i64 FUN_1402875f0(i64, i64, i64);
i64 FUN_140287630(i64, i64, i64);
i64 FUN_140287670(i64, i64, i64);
i64 FUN_1402876b0(i64, i64, i64);
i64 FUN_140287740(i64, i64);
i64 FUN_1402877e0(i64, i64);
i64 FUN_140287e20(i64, i64);
i64 FUN_140287e70(i64);
i64 FUN_140287e90(i64);
i64 FUN_140287eb0(i64);
i64 FUN_140287ee0(i64);
i64 FUN_140287f10(i64);
i64 FUN_140287f30(i64);
i64 FUN_140287f50(i64 param_1);
i64 FUN_140287f70(i64 param_1);
i64 FUN_140287f90(i64 param_1);
i64 FUN_140287fb0(i64 param_1);
i64 FUN_140287fd0(i64 param_1);
i64 FUN_140287ff0(i64 param_1);
i64 FUN_140288010(i64 param_1);
i64 FUN_140288030(i64 param_1);
i64 FUN_140288050(i64 param_1);
i64 FUN_140288060(i64 param_1);
i64 FUN_140288070(i64 param_1);
i64 FUN_140288080(i64 param_1);
i64 FUN_140288090(i64 param_1);
i64 FUN_1402880a0(i64 param_1);
i64 FUN_1402880b0(i64 param_1);
i64 FUN_1402880c0(i64 param_1);
i64 FUN_1402880d0(i64 param_1);
i64 FUN_1402880e0(i64 param_1);
i64 FUN_1402880f0(i64 param_1);
i64 FUN_140288100(i64 param_1);
i64 FUN_140288110(i64 param_1);
i64 FUN_140288120(i64 param_1);
i64 FUN_140288130(i64 param_1);
i64 FUN_140288140(i64 param_1);
i64 FUN_140288150(i64 param_1);
i64 FUN_140288160(i64 param_1);
i64 FUN_140288170(i64 param_1);
i64 FUN_140288180(i64 param_1);
i64 FUN_140288190(i64 param_1);
i64 FUN_1402881a0(i64 param_1);
i64 FUN_1402881b0(i64 param_1);
i64 FUN_1402881c0(i64 param_1);
i64 FUN_1402881d0(i64 param_1);
i64 FUN_1402881e0(i64 param_1);
i64 FUN_1402881f0(i64 param_1);
i64 FUN_140288200(i64 param_1);
i64 FUN_140288210(i64 param_1);
i64 FUN_140288220(i64 param_1);
i64 FUN_140288230(i64 param_1);
i64 FUN_140288240(i64 param_1);
i64 FUN_140288250(i64 param_1);
i64 FUN_140288270(i64 param_1);
i64 FUN_140288290(i64 param_1);
i64 FUN_1402882c0(i64 param_1);
i64 FUN_1402882f0(i64 param_1);
i64 FUN_140288310(i64 param_1);
i64 FUN_140288330(i64 param_1);
i64 FUN_140288350(i64 param_1);
i64 FUN_140288370(i64 param_1);
i64 FUN_140288390(i64 param_1);
i64 FUN_1402883b0(i64 param_1);
i64 FUN_1402883d0(i64 param_1);
i64 FUN_1402883f0(i64 param_1);
i64 FUN_140288410(i64 param_1);
i64 FUN_140288430(i64 param_1);
i64 FUN_140288450(i64 param_1);
bool FUN_140288470(i64 param_1);
bool FUN_1402884c0(i64 param_1);
bool FUN_140288510(i64 param_1);
void FUN_140288560(i64 param_1, i64 param_2);
i64 FUN_1402885e0(i64 param_1, i64 param_2);
i64 FUN_140288610(i64 param_1, i64 param_2);
Unk_TNode** FUN_140288630(Unk_TVal* param_1);
void FUN_140288640(Unk_TVal* param_1, Unk_TNode* param_2);
i64 FUN_140288720(i64 param_1, i64 param_2, i64 param_3);
i64 FUN_140288770(i64 param_1, i64 param_2, i64 param_3);
Unk_TNode* FUN_1402887e0(Unk_TNode* param_1);
Unk_TNode* FUN_140288810(Unk_TNode* param_1);
i64 FUN_140288840(i64 param_1);
i64 FUN_140288860(i64 param_1);
i64 FUN_140288880(i64 param_1);
i64 FUN_1402888a0(i64 param_1);
i64 FUN_1402888c0(i64 param_1);
i64 FUN_1402888e0(i64 param_1);
i64 FUN_140288900(i64 param_1);
i64 FUN_140288920(i64 param_1);
i64 FUN_140288940(i64 param_1);
i64 FUN_140288960(i64 param_1);
i64 FUN_140288980(i64 param_1);
i64 FUN_1402889a0(i64 param_1);
i64 FUN_1402889c0(i64 param_1);
i64 FUN_1402889e0(i64 param_1);
i64 FUN_140288a00(i64 param_1);
i64 FUN_140288a20(i64 param_1);
i64 FUN_140288a40(i64 param_1);
i64 FUN_140288a60(i64 param_1);
i64 FUN_140288a80(i64 param_1);
i64 FUN_140288aa0(i64 param_1);
i64 FUN_140288ac0(i64 param_1);
i64 FUN_140288ae0(i64 param_1);
i64 FUN_140288b00(i64 param_1);
i64 FUN_140288b20(i64 param_1);
i64 FUN_140288b40(i64 param_1);
i64 FUN_140288b60(i64 param_1);
i64 FUN_140288b80(i64 param_1);
i64 FUN_140288ba0(i64 param_1);
i64 FUN_140288bc0(i64 param_1);
i64 FUN_140288be0(i64 param_1);
i64 FUN_140288c00(i64 param_1);
i64 FUN_140288c20(i64 param_1);
i64 FUN_140288c40(i64 param_1);
i64 FUN_140288c60(i64 param_1);
i64 FUN_140288c80(i64 param_1);
i64 FUN_140288ca0(i64 param_1);
i64 FUN_140288cc0(i64 param_1);
i64 FUN_140288ce0(i64 param_1);
void FUN_140288d00(void);
void FUN_140288d10(void);
void FUN_140288d20(void);
void FUN_140288d30(i64 param_1, u64 param_2);
void FUN_140288dd0(i64 param_1);
void FUN_140288e10(i64 param_1);
void FUN_140288e50(i64 param_1);
void FUN_140288e90(i64 param_1);
void FUN_140288ed0(i64 param_1);
void FUN_140288f10(i64 param_1);
void FUN_140288f50(i64 param_1);
void FUN_140288f90(i64 param_1);
void FUN_140288fd0(i64 param_1);
void FUN_140289010(i64 param_1);
void FUN_140289050(i64 param_1);
i64 FUN_140289090(i64 param_1);
i64 FUN_1402890b0(i64 param_1);
i64 FUN_1402890d0(i64 param_1);
i64 FUN_1402890f0(i64 param_1);
i64 FUN_140289110(i64 param_1);
void FUN_140289130(i64 param_1, i64 param_2);
void FUN_140289180(i64 param_1, i64 param_2);
void FUN_1402891d0(i64 param_1, i64 param_2);
void FUN_140289220(i64 param_1, i64 param_2);
void FUN_140289270(i64 param_1, i64 param_2);
void FUN_1402892c0(i64 param_1, i64 param_2);
void FUN_140289310(i64 param_1, i64 param_2);
void FUN_140289360(i64 param_1, i64 param_2);
void FUN_1402893b0(i64 param_1, i64 param_2);
void FUN_140289400(i64 param_1, i64 param_2);
void FUN_140289450(i64 param_1, i64 param_2);
Unk_TNode** FUN_1402894a0(Unk_TVal* param_1);
Unk_TNode** FUN_1402894c0(Unk_TVal* param_1);
void FUN_1402894e0(Unk_TVal* param_1, Unk_TNode* param_2);
void FUN_1402895c0(i64* param_1, i64 param_2);
void FUN_1402895f0(i64 param_1);
void FUN_140289650(i64 param_1);
void FUN_140289670(i64 param_1);
void FUN_140289740(i64 param_1);
void FUN_140289810(i64 param_1);
void FUN_1402898e0(i64 param_1);
void FUN_1402899b0(i64 param_1);
i64 FUN_140289a80(i64 param_1, i64 param_2, i64 param_3, i64 param_4);
i64 FUN_140289ac0(i64 param_1, i64 param_2, i64 param_3, i64 param_4);
i64 FUN_140289b00(i64 param_1, i64 param_2, i64 param_3, i64 param_4);
i64 FUN_140289b40(i64 param_1, i64 param_2, i64 param_3, i64 param_4, Unk_StlTag param_5);
i64 FUN_140289b80(i64 param_1, i64 param_2, i64 param_3, i64 param_4, Unk_StlTag param_5);
i64 FUN_140289bc0(i64 param_1, i64 param_2, i64 param_3, i64 param_4, Unk_StlTag param_5);
i64 FUN_140289c00(i64 param_1, i64 param_2, i64 param_3, i64 param_4);
i64 FUN_140289c60(i64 param_1, i64 param_2, i64 param_3, i64 param_4);
i64 FUN_140289cc0(i64 param_1, i64 param_2, i64 param_3, i64 param_4);
i64 FUN_140289d20(i64 param_1, i64 param_2);
i64 FUN_140289d60(i64 param_1);
i64 FUN_140289d80(i64 param_1, i64 param_2);
i64 FUN_140289dc0(i64 param_1);
i64 FUN_140289de0(i64 param_1, i64 param_2);
i64 FUN_140289e50(i64 param_1);
i64 FUN_140289e90(i64 param_1);
void FUN_140289ea0(void);
void FUN_140289ec0(void);
void FUN_140289ee0(void);
void FUN_140289f00(void);
void FUN_140289f20(void);
void FUN_140289f40(void);
i64 FUN_140289f60(i64 param_1, u64 param_2);
i64 FUN_140289f90(i64 param_1, u64 param_2);
i64 FUN_140289fc0(i64 param_1, i64 param_2);
i64 FUN_140289ff0(i64 param_1, u64 param_2);
i64 FUN_14028a020(i64 param_1, i64 param_2);
i64 FUN_14028a050(i64 param_1, u64 param_2);
i64 FUN_14028a080(i64 param_1, u64 param_2);
i64 FUN_14028a0b0(i64 param_1, i64 param_2);
i64 FUN_14028a0f0(i64 param_1, i64 param_2);
i64 FUN_14028a130(i64 param_1, i64 param_2);
i64 FUN_14028a1a0(i64 param_1, i64 param_2);
i64 FUN_14028a200(i64 param_1, i64 param_2);
i64 FUN_14028a260(i64 param_1, i64 param_2);
i64 FUN_14028a2c0(i64 param_1);
i64 FUN_14028a300(i64 param_1);
i64 FUN_14028a350(i64 param_1);
i64 FUN_14028a390(i64 param_1);
i64 FUN_14028a3d0(i64 param_1);
void FUN_14028a410(i64 param_1);
void FUN_14028a4b0(i64 param_1);
void FUN_14028a590(i64 param_1);
void FUN_14028a610(i64 param_1);
void FUN_14028a690(i64 param_1);
void FUN_14028a710(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a740(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a770(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a7a0(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a7d0(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a800(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a830(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a860(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a890(i64 param_1, i64 param_2, i64 param_3);
bool FUN_14028a8c0(i64 param_1);
i64 FUN_14028a910(i64 param_1, i64 param_2);
i64 FUN_14028a970(i64 param_1, i64 param_2);
i64 FUN_14028a9d0(i64 param_1, i64 param_2);
i64 FUN_14028aa30(i64 param_1, i64 param_2);
i64 FUN_14028aa90(i64 param_1, i64 param_2);
i64 FUN_14028aaf0(void);
i64 FUN_14028ab00(i64 param_1, i64 param_2, i64 param_3, i64 param_4);
i64 FUN_14028abf0(i64 param_1, i64 param_2, i64 param_3);
i64 FUN_14028aca0(i64 param_1, i64 param_2, i64 param_3);
i64* FUN_14028ad10(i64 param_1, i64* param_2, i64 param_3);
i64* FUN_14028adf0(i64 param_1, i64* param_2, i64 param_3);
float FUN_14028aed0(float param_1);
i64 FUN_14028aef0(i64 param_1);
i64 FUN_14028af20(i64 param_1, i64 param_2, i64 param_3);
i64 FUN_14028af80(i64 param_1, i64 param_2, i64 param_3);
i64 FUN_14028afe0(i64 param_1);
i64 FUN_14028aff0(i64 param_1);
i64 FUN_14028b000(i64 param_1);
i64 FUN_14028b010(i64 param_1);
i64 FUN_14028b020(i64 param_1);
i64 FUN_14028b030(i64 param_1);
i64 FUN_14028b040(i64 param_1);
i64 FUN_14028b050(i64 param_1);
i64 FUN_14028b070(i64 param_1);
u64 FUN_14028b090(i64 param_1);
u64 FUN_14028b0e0(i64 param_1);
u64 FUN_14028b130(i64 param_1);
u64 FUN_14028b180(i64 param_1);
u64 FUN_14028b1d0(i64 param_1);
i64 FUN_14028b220(i64 param_1);
i64 FUN_14028b240(i64 param_1);
void FUN_14028b260(i64 param_1, i64 param_2);
i64 FUN_14028b2a0(i64 param_1, i64 param_2);
i64 FUN_14028b2d0(i64 param_1, i64 param_2);
i64 FUN_14028b300(i64 param_1, i64 param_2);
i64 FUN_14028b330(i64 param_1, i64 param_2);
i64 FUN_14028b360(i64 param_1, i64 param_2);
void FUN_14028b3a0(i64 param_1, i64 param_2);
i64 FUN_14028b3f0(i64 param_1);
i64 FUN_14028b410(i64 param_1);
i64 FUN_14028b430(i64 param_1);
i64 FUN_14028b470(i64 param_1);
i64 FUN_14028b4c0(i64 param_1);
i64 FUN_14028b500(i64 param_1);
i64 FUN_14028b540(i64 param_1);
i64 FUN_14028b580(void);
i64 FUN_14028b590(void);
i64 FUN_14028b5a0(void);
errno_t FUN_14028b5b0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize);

// @0x140287f50
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140287f50(i64 param_1)
{
  return FUN_1402881d0(param_1);
}

// @0x140287f70
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140287f70(i64 param_1)
{
  return FUN_1402881e0(param_1);
}

// @0x140287f90
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140287f90(i64 param_1)
{
  return FUN_1402881f0(param_1);
}

// @0x140287fb0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140287fb0(i64 param_1)
{
  return FUN_140288200(param_1);
}

// @0x140287fd0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140287fd0(i64 param_1)
{
  return FUN_140288210(param_1);
}

// @0x140287ff0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140287ff0(i64 param_1)
{
  return FUN_140288220(param_1);
}

// @0x140288010
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288010(i64 param_1)
{
  return FUN_140288230(param_1);
}

// @0x140288030
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288030(i64 param_1)
{
  return FUN_140288240(param_1);
}

// @0x140288050
i64 FUN_140288050(i64 param_1)
{
  return param_1;
}

// @0x140288060
i64 FUN_140288060(i64 param_1)
{
  return param_1;
}

// @0x140288070
i64 FUN_140288070(i64 param_1)
{
  return param_1;
}

// @0x140288080
i64 FUN_140288080(i64 param_1)
{
  return param_1;
}

// @0x140288090
i64 FUN_140288090(i64 param_1)
{
  return param_1;
}

// @0x1402880a0
i64 FUN_1402880a0(i64 param_1)
{
  return param_1;
}

// @0x1402880b0
i64 FUN_1402880b0(i64 param_1)
{
  return param_1;
}

// @0x1402880c0
i64 FUN_1402880c0(i64 param_1)
{
  return param_1;
}

// @0x1402880d0
i64 FUN_1402880d0(i64 param_1)
{
  return param_1;
}

// @0x1402880e0
i64 FUN_1402880e0(i64 param_1)
{
  return param_1;
}

// @0x1402880f0
i64 FUN_1402880f0(i64 param_1)
{
  return param_1;
}

// @0x140288100
i64 FUN_140288100(i64 param_1)
{
  return param_1;
}

// @0x140288110
i64 FUN_140288110(i64 param_1)
{
  return param_1;
}

// @0x140288120
i64 FUN_140288120(i64 param_1)
{
  return param_1;
}

// @0x140288130
i64 FUN_140288130(i64 param_1)
{
  return param_1;
}

// @0x140288140
i64 FUN_140288140(i64 param_1)
{
  return param_1;
}

// @0x140288150
i64 FUN_140288150(i64 param_1)
{
  return param_1;
}

// @0x140288160
i64 FUN_140288160(i64 param_1)
{
  return param_1;
}

// @0x140288170
i64 FUN_140288170(i64 param_1)
{
  return param_1;
}

// @0x140288180
i64 FUN_140288180(i64 param_1)
{
  return param_1;
}

// @0x140288190
i64 FUN_140288190(i64 param_1)
{
  return param_1;
}

// @0x1402881a0
i64 FUN_1402881a0(i64 param_1)
{
  return param_1;
}

// @0x1402881b0
i64 FUN_1402881b0(i64 param_1)
{
  return param_1;
}

// @0x1402881c0
i64 FUN_1402881c0(i64 param_1)
{
  return param_1;
}

// @0x1402881d0
i64 FUN_1402881d0(i64 param_1)
{
  return param_1;
}

// @0x1402881e0
i64 FUN_1402881e0(i64 param_1)
{
  return param_1;
}

// @0x1402881f0
i64 FUN_1402881f0(i64 param_1)
{
  return param_1;
}

// @0x140288200
i64 FUN_140288200(i64 param_1)
{
  return param_1;
}

// @0x140288210
i64 FUN_140288210(i64 param_1)
{
  return param_1;
}

// @0x140288220
i64 FUN_140288220(i64 param_1)
{
  return param_1;
}

// @0x140288230
i64 FUN_140288230(i64 param_1)
{
  return param_1;
}

// @0x140288240
i64 FUN_140288240(i64 param_1)
{
  return param_1;
}

// @0x140288250
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288250(i64 param_1)
{
  return FUN_140288070(param_1);
}

// @0x140288270
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288270(i64 param_1)
{
  return FUN_140288080(param_1);
}

// @0x140288290
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288290(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_140288150(param_1);
  return FUN_140288090(uVar1);
}

// @0x1402882c0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402882c0(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_140288160(param_1);
  return FUN_1402880a0(uVar1);
}

// @0x1402882f0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402882f0(i64 param_1)
{
  return FUN_1402880b0(param_1);
}

// @0x140288310
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288310(i64 param_1)
{
  return FUN_1402880c0(param_1);
}

// @0x140288330
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288330(i64 param_1)
{
  return FUN_1402880d0(param_1);
}

// @0x140288350
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288350(i64 param_1)
{
  return FUN_1402880e0(param_1);
}

// @0x140288370
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288370(i64 param_1)
{
  return FUN_1402880f0(param_1);
}

// @0x140288390
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288390(i64 param_1)
{
  return FUN_140288100(param_1);
}

// @0x1402883b0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402883b0(i64 param_1)
{
  return FUN_140288110(param_1);
}

// @0x1402883d0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402883d0(i64 param_1)
{
  return FUN_140288120(param_1);
}

// @0x1402883f0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402883f0(i64 param_1)
{
  return FUN_140288130(param_1);
}

// @0x140288410
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288410(i64 param_1)
{
  return FUN_140288140(param_1);
}

// @0x140288430
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288430(i64 param_1)
{
  return FUN_140288050(param_1);
}

// @0x140288450
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288450(i64 param_1)
{
  return FUN_140288060(param_1);
}

// @0x140288470
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
bool FUN_140288470(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_1402888a0(param_1);
  plVar2 = (i64*)FUN_140288b40(param_1);
  return *plVar1 != *plVar2;
}

// @0x1402884c0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
bool FUN_1402884c0(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_1402888e0(param_1);
  plVar2 = (i64*)FUN_140288b80(param_1);
  return *plVar1 != *plVar2;
}

// @0x140288510
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
bool FUN_140288510(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288920(param_1);
  plVar2 = (i64*)FUN_140288bc0(param_1);
  return *plVar1 != *plVar2;
}

// @0x140288560
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140288560(i64 param_1, i64 param_2)
{
  i64 lVar1;
  i64* plVar2;
  lVar1 = FUN_14028b070(param_1);
  plVar2 = (i64*)FUN_140288c20(param_1);
  if ((lVar1 - *plVar2) - 1U < param_2) {
                    /* WARNING: Subroutine does not return */
    std::_Xlength_error("list<T> too long");
  }
  plVar2 = (i64*)FUN_140288c20(param_1);
  *plVar2 = *plVar2 + param_2;
  return;
}

// @0x1402885e0
i64 FUN_1402885e0(i64 param_1, i64 param_2)
{
  return FUN_140288610(param_1,param_2 + 0x1c);
}

// @0x140288610
i64 FUN_140288610(i64 param_1, i64 param_2)
{
  return FUN_14027a270(param_2);
}

// @0x140288630
Unk_TNode** FUN_140288630(Unk_TVal* param_1)
{
  return &param_1->head->left;
}

// @0x140288640
void FUN_140288640(Unk_TVal* param_1, Unk_TNode* param_2)
{
  Unk_TNode* plVar1;
  plVar1 = param_2->right;
  param_2->right = plVar1->left;
  if (plVar1->left->isnil == '\0') {
    plVar1->left->parent = param_2;
  }
  plVar1->parent = param_2->parent;
  if (param_2 == param_1->head->parent) {
    param_1->head->parent = plVar1;
  }
  else if (param_2 == param_2->parent->left) {
    param_2->parent->left = plVar1;
  }
  else {
    param_2->parent->right = plVar1;
  }
  plVar1->left = param_2;
  param_2->parent = plVar1;
}

// @0x140288720
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288720(i64 param_1, i64 param_2, i64 param_3)
{
  i64 uVar1;
  uVar1 = FUN_140287e90(param_1);
  uVar1 = FUN_14027b4e0(uVar1);
  FUN_14027ce50(param_2,param_3,uVar1);
  return param_2;
}

// @0x140288770
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288770(i64 param_1, i64 param_2, i64 param_3)
{
  i64* plVar1;
  i64 uVar2;
  plVar1 = (i64*)FUN_140288210(param_1);
  uVar2 = FUN_14027b590((i64)plVar1);
  FUN_14027d3d0(param_2,param_3 * 0x10 + *plVar1,uVar2);
  return param_2;
}

// @0x1402887e0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
Unk_TNode* FUN_1402887e0(Unk_TNode* param_1)
{
  Unk_TNode* local_res8;
  local_res8 = param_1;
  while (local_res8->right->isnil == '\0') {
    local_res8 = local_res8->right;
  }
  return local_res8;
}

// @0x140288810
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
Unk_TNode* FUN_140288810(Unk_TNode* param_1)
{
  Unk_TNode* local_res8;
  for (local_res8 = param_1; local_res8->left->isnil == '\0'; local_res8 = local_res8->left) {
  }
  return local_res8;
}

// @0x140288840
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288840(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f10(param_1);
  return lVar1 + 0x10;
}

// @0x140288860
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288860(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f30(param_1);
  return lVar1 + 0x10;
}

// @0x140288880
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288880(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f50(param_1);
  return lVar1 + 0x10;
}

// @0x1402888a0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402888a0(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f70(param_1);
  return lVar1 + 0x10;
}

// @0x1402888c0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402888c0(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f90(param_1);
  return lVar1 + 0x10;
}

// @0x1402888e0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402888e0(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287fb0(param_1);
  return lVar1 + 0x10;
}

// @0x140288900
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288900(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287fd0(param_1);
  return lVar1 + 0x10;
}

// @0x140288920
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288920(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287ff0(param_1);
  return lVar1 + 0x10;
}

// @0x140288940
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288940(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140288010(param_1);
  return lVar1 + 0x10;
}

// @0x140288960
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288960(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140288030(param_1);
  return lVar1 + 0x10;
}

// @0x140288980
i64 FUN_140288980(i64 param_1)
{
  return FUN_140287f10(param_1);
}

// @0x1402889a0
i64 FUN_1402889a0(i64 param_1)
{
  return FUN_140287f30(param_1);
}

// @0x1402889c0
i64 FUN_1402889c0(i64 param_1)
{
  return FUN_140287f50(param_1);
}

// @0x1402889e0
i64 FUN_1402889e0(i64 param_1)
{
  return FUN_140287f70(param_1);
}

// @0x140288a00
i64 FUN_140288a00(i64 param_1)
{
  return FUN_140287f90(param_1);
}

// @0x140288a20
i64 FUN_140288a20(i64 param_1)
{
  return FUN_140287fb0(param_1);
}

// @0x140288a40
i64 FUN_140288a40(i64 param_1)
{
  return FUN_140287fd0(param_1);
}

// @0x140288a60
i64 FUN_140288a60(i64 param_1)
{
  return FUN_140287ff0(param_1);
}

// @0x140288a80
i64 FUN_140288a80(i64 param_1)
{
  return FUN_140288010(param_1);
}

// @0x140288aa0
i64 FUN_140288aa0(i64 param_1)
{
  return FUN_140288030(param_1);
}

// @0x140288ac0
i64 FUN_140288ac0(i64 param_1)
{
  return FUN_140287e70(param_1);
}

// @0x140288ae0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288ae0(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f10(param_1);
  return lVar1 + 8;
}

// @0x140288b00
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288b00(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f30(param_1);
  return lVar1 + 8;
}

// @0x140288b20
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288b20(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f50(param_1);
  return lVar1 + 8;
}

// @0x140288b40
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288b40(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f70(param_1);
  return lVar1 + 8;
}

// @0x140288b60
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288b60(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287f90(param_1);
  return lVar1 + 8;
}

// @0x140288b80
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288b80(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287fb0(param_1);
  return lVar1 + 8;
}

// @0x140288ba0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288ba0(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287fd0(param_1);
  return lVar1 + 8;
}

// @0x140288bc0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288bc0(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287ff0(param_1);
  return lVar1 + 8;
}

// @0x140288be0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288be0(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140288010(param_1);
  return lVar1 + 8;
}

// @0x140288c00
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288c00(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140288030(param_1);
  return lVar1 + 8;
}

// @0x140288c20
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288c20(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287e70(param_1);
  return lVar1 + 8;
}

// @0x140288c40
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288c40(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287e90(param_1);
  return lVar1 + 8;
}

// @0x140288c60
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288c60(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_140287f10(param_1);
  return FUN_14016c7c0(uVar1);
}

// @0x140288c80
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288c80(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_140287f50(param_1);
  return FUN_14016c7c0(uVar1);
}

// @0x140288ca0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288ca0(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_140287f90(param_1);
  return FUN_14016c7c0(uVar1);
}

// @0x140288cc0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288cc0(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_140287fd0(param_1);
  return FUN_14016c7c0(uVar1);
}

// @0x140288ce0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140288ce0(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_140288010(param_1);
  return FUN_14016c7c0(uVar1);
}

// @0x140288d00
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140288d00(void)
{
  return;
}

// @0x140288d10
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140288d10(void)
{
  return;
}

// @0x140288d20
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140288d20(void)
{
  return;
}

// @0x140288d30
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140288d30(i64 param_1, u64 param_2)
{
  i64 uVar1;
  i64 allocThis;
  i64 newVec;
  i64* puVar3;
  i64* puVar4;
  uVar1 = FUN_14028b500(param_1);
  allocThis = FUN_1402883b0(param_1);
  newVec = FUN_14028a050(allocThis,param_2);
  puVar3 = (i64*)FUN_140288ba0(param_1);
  puVar4 = (i64*)FUN_140288a40(param_1);
  FUN_140289cc0(param_1,*puVar4,*puVar3,newVec);
  FUN_1402873b0(param_1,newVec,uVar1,param_2);
}

// @0x140288dd0
void FUN_140288dd0(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_140289130(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140288e10
void FUN_140288e10(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_140289180(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140288e50
void FUN_140288e50(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_1402891d0(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140288e90
void FUN_140288e90(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_140289220(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140288ed0
void FUN_140288ed0(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_140289270(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140288f10
void FUN_140288f10(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_1402892c0(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140288f50
void FUN_140288f50(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_140289310(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140288f90
void FUN_140288f90(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_140289360(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140288fd0
void FUN_140288fd0(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_1402893b0(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140289010
void FUN_140289010(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_140289400(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140289050
void FUN_140289050(i64 param_1)
{
  if (*(i64*)(param_1 + 8) != 0) {
    FUN_140289450(param_1,0);
    *(i64*)(param_1 + 8) = 0;
  }
  return;
}

// @0x140289090
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289090(i64 param_1)
{
  *(i64*)param_1 = ((i64*)param_1)[1];
  return ((i64*)param_1)[1];
}

// @0x1402890b0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402890b0(i64 param_1)
{
  *(i64*)param_1 = ((i64*)param_1)[1];
  return ((i64*)param_1)[1];
}

// @0x1402890d0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402890d0(i64 param_1)
{
  *(i64*)param_1 = ((i64*)param_1)[1];
  return ((i64*)param_1)[1];
}

// @0x1402890f0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_1402890f0(i64 param_1)
{
  *(i64*)param_1 = ((i64*)param_1)[1];
  return ((i64*)param_1)[1];
}

// @0x140289110
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289110(i64 param_1)
{
  *(i64*)param_1 = ((i64*)param_1)[1];
  return ((i64*)param_1)[1];
}

// @0x140289130
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289130(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_1402866a0(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x140289180
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289180(i64 param_1, i64 param_2)
{
  int iVar1;
  i64 uVar2;
  uVar2 = FUN_140281490(*(i64*)(param_1 + 8));
  iVar1 = FUN_140159bc0(uVar2);
  if (iVar1 == 0) {
    FUN_1402866c0(uVar2);
    FUN_140159ba0(uVar2);
  }
  return;
}

// @0x1402891d0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_1402891d0(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_1402866e0(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x140289220
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289220(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_140286700(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x140289270
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289270(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_140286720(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x1402892c0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_1402892c0(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_140286760(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x140289310
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289310(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_140286780(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x140289360
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289360(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_1402867a0(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x1402893b0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_1402893b0(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_1402867c0(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x140289400
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289400(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_1402867e0(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x140289450
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289450(i64 param_1, i64 param_2)
{
  int iVar1;
  iVar1 = FUN_140159bc0(*(i64*)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_140286800(*(i64*)(param_1 + 8));
    FUN_140159ba0(*(i64*)(param_1 + 8));
  }
  return;
}

// @0x1402894a0
Unk_TNode** FUN_1402894a0(Unk_TVal* param_1)
{
  return &param_1->head->right;
}

// @0x1402894c0
Unk_TNode** FUN_1402894c0(Unk_TVal* param_1)
{
  return &param_1->head->parent;
}

// @0x1402894e0
void FUN_1402894e0(Unk_TVal* param_1, Unk_TNode* param_2)
{
  Unk_TNode* lVar1;
  lVar1 = param_2->left;
  param_2->left = lVar1->right;
  if (lVar1->right->isnil == '\0') {
    lVar1->right->parent = param_2;
  }
  lVar1->parent = param_2->parent;
  if (param_2 == param_1->head->parent) {
    param_1->head->parent = lVar1;
  }
  else if (param_2 == param_2->parent->right) {
    param_2->parent->right = lVar1;
  }
  else {
    param_2->parent->left = lVar1;
  }
  lVar1->right = param_2;
  param_2->parent = lVar1;
}

// @0x1402895c0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_1402895c0(i64* param_1, i64 param_2)
{
  i64 uVar1;
  uVar1 = FUN_140277160(param_2);
  *param_1 = uVar1;
}

// @0x1402895f0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_1402895f0(i64 param_1)
{
  i64 uVar1;
  i64* puVar2;
  i64 local_28;
  i64 local_20;
  i64 local_18;
  puVar2 = (i64*)FUN_14028a910(param_1,(i64)&local_28);
  uVar1 = *puVar2;
  puVar2 = (i64*)FUN_14028a130(param_1,(i64)&local_20);
  FUN_14028ab00(param_1,(i64)&local_18,*puVar2,uVar1);
}

// @0x140289650
void FUN_140289650(i64 param_1)
{
  FUN_14028a4b0(param_1);
}

// @0x140289670
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289670(i64 param_1)
{
  i64* plVar1;
  i64* puVar2;
  i64* puVar3;
  i64 uVar4;
  i64 uVar5;
  FUN_140288c60(param_1);
  plVar1 = (i64*)FUN_140288980(param_1);
  if (*plVar1 != 0) {
    puVar2 = (i64*)FUN_140288ae0(param_1);
    puVar3 = (i64*)FUN_140288980(param_1);
    FUN_1402875b0(param_1,*puVar3,*puVar2);
    uVar4 = FUN_14028a2c0(param_1);
    puVar2 = (i64*)FUN_140288980(param_1);
    uVar5 = FUN_1402882f0(param_1);
    FUN_14028a7d0(uVar5,*puVar2,uVar4);
    puVar2 = (i64*)FUN_140288980(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288ae0(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288840(param_1);
    *puVar2 = 0;
  }
  return;
}

// @0x140289740
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289740(i64 param_1)
{
  i64* plVar1;
  i64* puVar2;
  i64* puVar3;
  i64 uVar4;
  i64 uVar5;
  FUN_140288c80(param_1);
  plVar1 = (i64*)FUN_1402889c0(param_1);
  if (*plVar1 != 0) {
    puVar2 = (i64*)FUN_140288b20(param_1);
    puVar3 = (i64*)FUN_1402889c0(param_1);
    FUN_1402875f0(param_1,*puVar3,*puVar2);
    uVar4 = FUN_14028a300(param_1);
    puVar2 = (i64*)FUN_1402889c0(param_1);
    uVar5 = FUN_140288330(param_1);
    FUN_14028a800(uVar5,*puVar2,uVar4);
    puVar2 = (i64*)FUN_1402889c0(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288b20(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288880(param_1);
    *puVar2 = 0;
  }
  return;
}

// @0x140289810
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_140289810(i64 param_1)
{
  i64* plVar1;
  i64* puVar2;
  i64* puVar3;
  i64 uVar4;
  i64 uVar5;
  FUN_140288ca0(param_1);
  plVar1 = (i64*)FUN_140288a00(param_1);
  if (*plVar1 != 0) {
    puVar2 = (i64*)FUN_140288b60(param_1);
    puVar3 = (i64*)FUN_140288a00(param_1);
    FUN_140287630(param_1,*puVar3,*puVar2);
    uVar4 = FUN_14028a350(param_1);
    puVar2 = (i64*)FUN_140288a00(param_1);
    uVar5 = FUN_140288370(param_1);
    FUN_14028a830(uVar5,*puVar2,uVar4);
    puVar2 = (i64*)FUN_140288a00(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288b60(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_1402888c0(param_1);
    *puVar2 = 0;
  }
  return;
}

// @0x1402898e0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_1402898e0(i64 param_1)
{
  i64* plVar1;
  i64* puVar2;
  i64* puVar3;
  i64 uVar4;
  i64 uVar5;
  FUN_140288cc0(param_1);
  plVar1 = (i64*)FUN_140288a40(param_1);
  if (*plVar1 != 0) {
    puVar2 = (i64*)FUN_140288ba0(param_1);
    puVar3 = (i64*)FUN_140288a40(param_1);
    FUN_140287670(param_1,*puVar3,*puVar2);
    uVar4 = FUN_14028a390(param_1);
    puVar2 = (i64*)FUN_140288a40(param_1);
    uVar5 = FUN_1402883b0(param_1);
    FUN_14028a860(uVar5,*puVar2,uVar4);
    puVar2 = (i64*)FUN_140288a40(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288ba0(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288900(param_1);
    *puVar2 = 0;
  }
  return;
}

// @0x1402899b0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_1402899b0(i64 param_1)
{
  i64* plVar1;
  i64* puVar2;
  i64* puVar3;
  i64 uVar4;
  i64 uVar5;
  FUN_140288ce0(param_1);
  plVar1 = (i64*)FUN_140288a80(param_1);
  if (*plVar1 != 0) {
    puVar2 = (i64*)FUN_140288be0(param_1);
    puVar3 = (i64*)FUN_140288a80(param_1);
    FUN_1402876b0(param_1,*puVar3,*puVar2);
    uVar4 = FUN_14028a3d0(param_1);
    puVar2 = (i64*)FUN_140288a80(param_1);
    uVar5 = FUN_1402883f0(param_1);
    FUN_14028a890(uVar5,*puVar2,uVar4);
    puVar2 = (i64*)FUN_140288a80(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288be0(param_1);
    *puVar2 = 0;
    puVar2 = (i64*)FUN_140288940(param_1);
    *puVar2 = 0;
  }
  return;
}

// @0x140289a80
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289a80(i64 param_1, i64 param_2, i64 param_3, i64 param_4)
{
  i64 uVar1;
  uVar1 = FUN_140288330(param_1);
  return FUN_14027b0b0(param_2,param_3,param_4,uVar1);
}

// @0x140289ac0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289ac0(i64 param_1, i64 param_2, i64 param_3, i64 param_4)
{
  i64 uVar1;
  uVar1 = FUN_140288370(param_1);
  return FUN_14027b180(param_2,param_3,param_4,uVar1);
}

// @0x140289b00
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289b00(i64 param_1, i64 param_2, i64 param_3, i64 param_4)
{
  i64 uVar1;
  uVar1 = FUN_1402883b0(param_1);
  return FUN_14027b250(param_2,param_3,param_4,uVar1);
}

// @0x140289b40
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289b40(i64 param_1, i64 param_2, i64 param_3, i64 param_4, Unk_StlTag param_5)
{
  i64 uVar1;
  uVar1 = FUN_140288330(param_1);
  return FUN_14027aaa0(param_2,param_3,param_4,uVar1);
}

// @0x140289b80
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289b80(i64 param_1, i64 param_2, i64 param_3, i64 param_4, Unk_StlTag param_5)
{
  i64 uVar1;
  uVar1 = FUN_140288370(param_1);
  return FUN_14027ab70(param_2,param_3,param_4,uVar1);
}

// @0x140289bc0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289bc0(i64 param_1, i64 param_2, i64 param_3, i64 param_4, Unk_StlTag param_5)
{
  i64 uVar1;
  uVar1 = FUN_1402883b0(param_1);
  return FUN_14027ac40(param_2,param_3,param_4,uVar1);
}

// @0x140289c00
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289c00(i64 param_1, i64 param_2, i64 param_3, i64 param_4)
{
  Unk_StlTag tag = Unk_StlTag();
  return FUN_140289b40(param_1,param_2,param_3,param_4,tag);
}

// @0x140289c60
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289c60(i64 param_1, i64 param_2, i64 param_3, i64 param_4)
{
  Unk_StlTag tag = Unk_StlTag();
  return FUN_140289b80(param_1,param_2,param_3,param_4,tag);
}

// @0x140289cc0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289cc0(i64 param_1, i64 param_2, i64 param_3, i64 param_4)
{
  Unk_StlTag tag = Unk_StlTag();
  return FUN_140289bc0(param_1,param_2,param_3,param_4,tag);
}

// @0x140289d20
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289d20(i64 param_1, i64 param_2)
{
  i64* puVar1;
  puVar1 = (i64*)FUN_140288ac0(param_1);
  FUN_14027ced0(param_2,*(i64*)*puVar1,0);
  return param_2;
}

// @0x140289d60
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289d60(i64 param_1)
{
  i64* puVar1;
  puVar1 = (i64*)FUN_140288a60(param_1);
  return *puVar1;
}

// @0x140289d80
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289d80(i64 param_1, i64 param_2)
{
  i64* puVar1;
  puVar1 = (i64*)FUN_140288ac0(param_1);
  FUN_14027ced0(param_2,*puVar1,0);
  return param_2;
}

// @0x140289dc0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289dc0(i64 param_1)
{
  i64* puVar1;
  puVar1 = (i64*)FUN_140288bc0(param_1);
  return *puVar1;
}

// @0x140289de0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289de0(i64 param_1, i64 param_2)
{
  i64* plVar1;
  *(i64*)((i64*)param_2)[1] = *(i64*)param_2;
  *(i64*)(*(i64*)param_2 + 8) = ((i64*)param_2)[1];
  plVar1 = (i64*)FUN_140288c20(param_1);
  *plVar1 = *plVar1 + -1;
  return param_2;
}

// @0x140289e50
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289e50(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288920(param_1);
  plVar2 = (i64*)FUN_140288bc0(param_1);
  return *plVar1 - *plVar2 >> 4;
}

// @0x140289e90
i64 FUN_140289e90(i64 param_1)
{
  return *(i64*)param_1;
}

// @0x140289ea0
void FUN_140289ea0(void)
{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector<T> too long");
}

// @0x140289ec0
void FUN_140289ec0(void)
{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector<T> too long");
}

// @0x140289ee0
void FUN_140289ee0(void)
{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector<T> too long");
}

// @0x140289f00
void FUN_140289f00(void)
{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector<T> too long");
}

// @0x140289f20
void FUN_140289f20(void)
{
                    /* WARNING: Subroutine does not return */
  std::_Xlength_error("vector<T> too long");
}

// @0x140289f40
void FUN_140289f40(void)
{
  std::_Xout_of_range("invalid vector<T> subscript");
  return;
}

// @0x140289f60
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289f60(i64 param_1, u64 param_2)
{
  u64 _Var1;
  i64 p_Var2;
  _Var1 = std::_Get_size_of_n<16>(param_2);
  p_Var2 = (i64)std::_Allocate<16,std::_Default_allocate_traits,0>(_Var1);
  return p_Var2;
}

// @0x140289f90
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289f90(i64 param_1, u64 param_2)
{
  u64 _Var1;
  i64 p_Var2;
  _Var1 = std::_Get_size_of_n<16>(param_2);
  p_Var2 = (i64)std::_Allocate<16,std::_Default_allocate_traits,0>(_Var1);
  return p_Var2;
}

// @0x140289fc0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289fc0(i64 param_1, i64 param_2)
{
  u64 _Var1;
  _Var1 = FUN_1402786c0(param_2);
  return (i64)std::_Allocate<16,std::_Default_allocate_traits,0>(_Var1);
}

// @0x140289ff0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_140289ff0(i64 param_1, u64 param_2)
{
  u64 _Var1;
  i64 p_Var2;
  _Var1 = std::_Get_size_of_n<16>(param_2);
  p_Var2 = (i64)std::_Allocate<16,std::_Default_allocate_traits,0>(_Var1);
  return p_Var2;
}

// @0x14028a020
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a020(i64 param_1, i64 param_2)
{
  u64 _Var1;
  _Var1 = FUN_1402786c0(param_2);
  return (i64)std::_Allocate<16,std::_Default_allocate_traits,0>(_Var1);
}

// @0x14028a050
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a050(i64 param_1, u64 param_2)
{
  u64 _Var1;
  i64 p_Var2;
  _Var1 = std::_Get_size_of_n<16>(param_2);
  p_Var2 = (i64)std::_Allocate<16,std::_Default_allocate_traits,0>(_Var1);
  return p_Var2;
}

// @0x14028a080
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a080(i64 param_1, u64 param_2)
{
  u64 _Var1;
  i64 p_Var2;
  _Var1 = std::_Get_size_of_n<16>(param_2);
  p_Var2 = (i64)std::_Allocate<16,std::_Default_allocate_traits,0>(_Var1);
  return p_Var2;
}

// @0x14028a0b0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a0b0(i64 param_1, i64 param_2)
{
  u64 uVar1;
  i64* plVar2;
  uVar1 = FUN_14028b500(param_1);
  if (uVar1 <= param_2) {
    FUN_140289f40();
  }
  plVar2 = (i64*)FUN_140288a40(param_1);
  return param_2 * 0x10 + *plVar2;
}

// @0x14028a0f0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a0f0(i64 param_1, i64 param_2)
{
  u64 uVar1;
  i64* plVar2;
  uVar1 = FUN_14028b500(param_1);
  if (uVar1 <= param_2) {
    FUN_140289f40();
  }
  plVar2 = (i64*)FUN_140288a60(param_1);
  return param_2 * 0x10 + *plVar2;
}

// @0x14028a130
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a130(i64 param_1, i64 param_2)
{
  Unk_TVal* uVar1;
  i64 uVar2;
  Unk_TNode** puVar3;
  uVar1 = (Unk_TVal*)FUN_140287eb0(param_1);
  uVar2 = FUN_14027b570((i64)uVar1);
  puVar3 = FUN_140288630(uVar1);
  FUN_14027d010(param_2,(i64)*puVar3,uVar2);
  return param_2;
}

// @0x14028a1a0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a1a0(i64 param_1, i64 param_2)
{
  i64 uVar1;
  i64* puVar2;
  uVar1 = FUN_140287e70(param_1);
  uVar1 = FUN_14027b560(uVar1);
  puVar2 = (i64*)FUN_140288ac0(param_1);
  FUN_14027ce50(param_2,*(i64*)*puVar2,uVar1);
  return param_2;
}

// @0x14028a200
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a200(i64 param_1, i64 param_2)
{
  i64 uVar1;
  i64* puVar2;
  uVar1 = FUN_140287f50(param_1);
  uVar1 = FUN_14027b580(uVar1);
  puVar2 = (i64*)FUN_1402889c0(param_1);
  FUN_14027d390(param_2,*puVar2,uVar1);
  return param_2;
}

// @0x14028a260
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a260(i64 param_1, i64 param_2)
{
  i64 uVar1;
  i64* puVar2;
  uVar1 = FUN_140287fd0(param_1);
  uVar1 = FUN_14027b590(uVar1);
  puVar2 = (i64*)FUN_140288a40(param_1);
  FUN_14027d3d0(param_2,*puVar2,uVar1);
  return param_2;
}

// @0x14028a2c0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a2c0(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288860(param_1);
  plVar2 = (i64*)FUN_1402889a0(param_1);
  return *plVar1 - *plVar2 >> 3;
}

// @0x14028a300
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a300(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_1402888a0(param_1);
  plVar2 = (i64*)FUN_1402889e0(param_1);
  return (*plVar1 - *plVar2) / 0x30;
}

// @0x14028a350
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a350(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_1402888e0(param_1);
  plVar2 = (i64*)FUN_140288a20(param_1);
  return *plVar1 - *plVar2 >> 3;
}

// @0x14028a390
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a390(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288920(param_1);
  plVar2 = (i64*)FUN_140288a60(param_1);
  return *plVar1 - *plVar2 >> 4;
}

// @0x14028a3d0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a3d0(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288960(param_1);
  plVar2 = (i64*)FUN_140288aa0(param_1);
  return *plVar1 - *plVar2 >> 4;
}

// @0x14028a410
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_14028a410(i64 param_1)
{
  Unk_TNode* uVar1;
  Unk_TVal* puVar2;
  puVar2 = (Unk_TVal*)FUN_140287eb0(param_1);
  uVar1 = puVar2->head;
  FUN_140287740(param_1,(i64)*FUN_1402894c0(puVar2));
  *FUN_1402894c0(puVar2) = uVar1;
  *FUN_140288630(puVar2) = uVar1;
  *FUN_1402894a0(puVar2) = uVar1;
  puVar2->size = 0;
}

// @0x14028a4b0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_14028a4b0(i64 param_1)
{
  i64* puVar1;
  i64* puVar2;
  i64* plVar3;
  i64* local_38;
  puVar1 = (i64*)FUN_140288ac0(param_1);
  local_38 = *(i64**)*puVar1;
  puVar1 = (i64*)FUN_140288ac0(param_1);
  puVar2 = (i64*)FUN_140288ac0(param_1);
  *(i64*)*puVar2 = *puVar1;
  puVar1 = (i64*)FUN_140288ac0(param_1);
  plVar3 = (i64*)FUN_140288ac0(param_1);
  *(i64*)(*plVar3 + 8) = *puVar1;
  puVar1 = (i64*)FUN_140288c20(param_1);
  *puVar1 = 0;
  while (true) {
    plVar3 = (i64*)FUN_140288ac0(param_1);
    if (local_38 == (i64*)*plVar3) break;
    puVar1 = (i64*)*local_38;
    FUN_140287e20(param_1,(i64)local_38);
    local_38 = puVar1;
  }
}

// @0x14028a590
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_14028a590(i64 param_1)
{
  i64* puVar1;
  i64* puVar2;
  FUN_140288c80(param_1);
  puVar1 = (i64*)FUN_140288b20(param_1);
  puVar2 = (i64*)FUN_1402889c0(param_1);
  FUN_1402875f0(param_1,*puVar2,*puVar1);
  puVar1 = (i64*)FUN_1402889c0(param_1);
  puVar2 = (i64*)FUN_140288b20(param_1);
  *puVar2 = *puVar1;
  return;
}

// @0x14028a610
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_14028a610(i64 param_1)
{
  i64* puVar1;
  i64* puVar2;
  FUN_140288cc0(param_1);
  puVar1 = (i64*)FUN_140288ba0(param_1);
  puVar2 = (i64*)FUN_140288a40(param_1);
  FUN_140287670(param_1,*puVar2,*puVar1);
  puVar1 = (i64*)FUN_140288a40(param_1);
  puVar2 = (i64*)FUN_140288ba0(param_1);
  *puVar2 = *puVar1;
  return;
}

// @0x14028a690
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_14028a690(i64 param_1)
{
  i64* puVar1;
  i64* puVar2;
  FUN_140288ce0(param_1);
  puVar1 = (i64*)FUN_140288be0(param_1);
  puVar2 = (i64*)FUN_140288a80(param_1);
  FUN_1402876b0(param_1,*puVar2,*puVar1);
  puVar1 = (i64*)FUN_140288a80(param_1);
  puVar2 = (i64*)FUN_140288be0(param_1);
  *puVar2 = *puVar1;
  return;
}

// @0x14028a710
void FUN_14028a710(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 * 0x20);
}

// @0x14028a740
void FUN_14028a740(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 * 0x28);
}

// @0x14028a770
void FUN_14028a770(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 * 0x20);
}

// @0x14028a7a0
void FUN_14028a7a0(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 * 0x28);
}

// @0x14028a7d0
void FUN_14028a7d0(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 << 3);
}

// @0x14028a800
void FUN_14028a800(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 * 0x30);
}

// @0x14028a830
void FUN_14028a830(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 << 3);
}

// @0x14028a860
void FUN_14028a860(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 * 0x10);
}

// @0x14028a890
void FUN_14028a890(i64 param_1, i64 param_2, i64 param_3)
{
  std::_Deallocate<8>((void*)param_2,param_3 * 0x10);
}

// @0x14028a8c0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
bool FUN_14028a8c0(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288a60(param_1);
  plVar2 = (i64*)FUN_140288bc0(param_1);
  return *plVar1 == *plVar2;
}

// @0x14028a910
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a910(i64 param_1, i64 param_2)
{
  i64* puVar1;
  i64 uVar2;
  puVar1 = (i64*)FUN_140287eb0(param_1);
  uVar2 = FUN_14027b570((i64)puVar1);
  FUN_14027d010(param_2,*puVar1,uVar2);
  return param_2;
}

// @0x14028a970
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a970(i64 param_1, i64 param_2)
{
  i64* puVar1;
  i64 uVar2;
  puVar1 = (i64*)FUN_140287ee0(param_1);
  uVar2 = FUN_14027b4f0((i64)puVar1);
  FUN_14027cfb0(param_2,*puVar1,uVar2);
  return param_2;
}

// @0x14028a9d0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028a9d0(i64 param_1, i64 param_2)
{
  i64 uVar1;
  i64* puVar2;
  uVar1 = FUN_140287e70(param_1);
  uVar1 = FUN_14027b560(uVar1);
  puVar2 = (i64*)FUN_140288ac0(param_1);
  FUN_14027ce50(param_2,*puVar2,uVar1);
  return param_2;
}

// @0x14028aa30
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028aa30(i64 param_1, i64 param_2)
{
  i64 uVar1;
  i64* puVar2;
  uVar1 = FUN_140287f50(param_1);
  uVar1 = FUN_14027b580(uVar1);
  puVar2 = (i64*)FUN_140288b20(param_1);
  FUN_14027d390(param_2,*puVar2,uVar1);
  return param_2;
}

// @0x14028aa90
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028aa90(i64 param_1, i64 param_2)
{
  i64 uVar1;
  i64* puVar2;
  uVar1 = FUN_140287fd0(param_1);
  uVar1 = FUN_14027b590(uVar1);
  puVar2 = (i64*)FUN_140288ba0(param_1);
  FUN_14027d3d0(param_2,*puVar2,uVar1);
  return param_2;
}

// @0x14028aaf0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028aaf0(void)
{
  return 0x34000000;
}

// @0x14028ab00
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028ab00(i64 param_1, i64 param_2, i64 param_3, i64 param_4)
{
  char cVar1;
  i64 uVar2;
  i64 local_res18;
  i64 local_res20;
  i64 local_28;
  i64 local_20;
  i64 local_18;
  i64 local_10;
  local_res18 = param_3;
  local_res20 = param_4;
  uVar2 = FUN_14028a130(param_1,(i64)&local_28);
  cVar1 = FUN_14027ee20((i64)&local_res18,uVar2);
  if (cVar1 != '\0') {
    uVar2 = FUN_14028a910(param_1,(i64)&local_20);
    cVar1 = FUN_14027ee20((i64)&local_res20,uVar2);
    if (cVar1 != '\0') {
      FUN_14028a410(param_1);
      FUN_14028a130(param_1,param_2);
      return param_2;
    }
  }
  while (cVar1 = FUN_14027ef80((i64)&local_res18,(i64)&local_res20), cVar1 != '\0') {
    FUN_14028abf0(param_1,(i64)&local_10,*(i64*)FUN_14027f5b0((i64)&local_res18,(i64)&local_18,0));
  }
  uVar2 = FUN_140287eb0(param_1);
  uVar2 = FUN_14027b570(uVar2);
  FUN_14027d010(param_2,local_res18,uVar2);
  return param_2;
}

// @0x14028abf0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028abf0(i64 param_1, i64 param_2, i64 param_3)
{
  i64 uVar1;
  i64 lVar2;
  i64 uVar3;
  i64 uVar4;
  i64 local_10;
  uVar1 = FUN_140287eb0(param_1);
  local_10 = param_3;
  FUN_14027f600((i64)&local_10);
  lVar2 = FUN_1402877e0(uVar1,param_3);
  uVar3 = FUN_140288290(param_1);
  uVar4 = FUN_14027b540(lVar2 + 0x1c);
  FUN_14027bb80(uVar3,uVar4);
  FUN_140278630(uVar3,lVar2);
  uVar1 = FUN_14027b570(uVar1);
  FUN_14027d010(param_2,local_10,uVar1);
  return param_2;
}

// @0x14028aca0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028aca0(i64 param_1, i64 param_2, i64 param_3)
{
  i64* puVar1;
  i64 uVar2;
  i64 local_res18;
  i64 local_10;
  local_res18 = param_3;
  puVar1 = (i64*)FUN_14027f4e0((i64)&local_res18,(i64)&local_10,0);
  uVar2 = FUN_140289de0(param_1,*puVar1);
  FUN_140287e20(param_1,uVar2);
  FUN_140288720(param_1,param_2,local_res18);
  return param_2;
}

// @0x14028ad10
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64* FUN_14028ad10(i64 param_1, i64* param_2, i64 param_3)
{
  char cVar1;
  i64 uVar2;
  i64 local_48;
  i64* local_40;
  i64 local_38;
  i64 local_30;
  i64 local_20;
  i64 local_18;
  FUN_14028af20(param_1,(i64)&local_48,param_3);
  uVar2 = FUN_14028a910(param_1,(i64)&local_20);
  cVar1 = FUN_14027ee20((i64)&local_48,uVar2);
  if (cVar1 == '\0') {
    local_38 = FUN_1402885e0(param_1,local_48);
    uVar2 = FUN_140288430(param_1);
    cVar1 = FUN_14027f870(uVar2,param_3,local_38);
    if (cVar1 == '\0') {
      local_40 = &local_30;
      goto LAB_14028adc4;
    }
  }
  local_40 = (i64*)FUN_14028a910(param_1,(i64)&local_18);
LAB_14028adc4:
  *param_2 = *local_40;
  return param_2;
}

// @0x14028adf0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64* FUN_14028adf0(i64 param_1, i64* param_2, i64 param_3)
{
  char cVar1;
  i64 uVar2;
  i64 local_48;
  i64* local_40;
  i64 local_38;
  i64 local_30;
  i64 local_20;
  i64 local_18;
  FUN_14028af80(param_1,(i64)&local_48,param_3);
  uVar2 = FUN_14028a970(param_1,(i64)&local_20);
  cVar1 = FUN_14027ee20((i64)&local_48,uVar2);
  if (cVar1 == '\0') {
    local_38 = FUN_1402885e0(param_1,local_48);
    uVar2 = FUN_140288450(param_1);
    cVar1 = FUN_14027f870(uVar2,param_3,local_38);
    if (cVar1 == '\0') {
      local_40 = &local_30;
      goto LAB_14028aea4;
    }
  }
  local_40 = (i64*)FUN_14028a970(param_1,(i64)&local_18);
LAB_14028aea4:
  *param_2 = *local_40;
  return param_2;
}

// @0x14028aed0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
float FUN_14028aed0(float param_1)
{
  return floorf(param_1);
}

// @0x14028aef0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028aef0(i64 param_1)
{
  i64 uVar1;
  i64 local_18;
  uVar1 = FUN_14028a1a0(param_1,(i64)&local_18);
  return FUN_14027f3b0(uVar1);
}

// @0x14028af20
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028af20(i64 param_1, i64 param_2, i64 param_3)
{
  i64 uVar1;
  i64 uVar2;
  uVar1 = FUN_140287eb0(param_1);
  uVar1 = FUN_14027b570(uVar1);
  uVar2 = FUN_14027a280(param_1,param_3);
  FUN_14027d010(param_2,uVar2,uVar1);
  return param_2;
}

// @0x14028af80
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028af80(i64 param_1, i64 param_2, i64 param_3)
{
  i64 uVar1;
  i64 uVar2;
  uVar1 = FUN_140287ee0(param_1);
  uVar1 = FUN_14027b4f0(uVar1);
  uVar2 = FUN_14027a280(param_1,param_3);
  FUN_14027cfb0(param_2,uVar2,uVar1);
  return param_2;
}

// @0x14028afe0
i64 FUN_14028afe0(i64 param_1)
{
  return 0x7ffffffffffffff;
}

// @0x14028aff0
i64 FUN_14028aff0(i64 param_1)
{
  return 0x666666666666666;
}

// @0x14028b000
i64 FUN_14028b000(i64 param_1)
{
  return 0x1fffffffffffffff;
}

// @0x14028b010
i64 FUN_14028b010(i64 param_1)
{
  return 0x555555555555555;
}

// @0x14028b020
i64 FUN_14028b020(i64 param_1)
{
  return 0x1fffffffffffffff;
}

// @0x14028b030
i64 FUN_14028b030(i64 param_1)
{
  return 0xfffffffffffffff;
}

// @0x14028b040
i64 FUN_14028b040(i64 param_1)
{
  return 0xfffffffffffffff;
}

// @0x14028b050
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b050(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_1402882c0(param_1);
  return FUN_14028aff0(uVar1);
}

// @0x14028b070
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b070(i64 param_1)
{
  i64 uVar1;
  uVar1 = FUN_140288270(param_1);
  return FUN_14028afe0(uVar1);
}

// @0x14028b090
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
u64 FUN_14028b090(i64 param_1)
{
  i64 uVar1;
  u64 local_10;
  u64 local_18;
  u64* p_Var2;
  uVar1 = FUN_140288310(param_1);
  local_18 = FUN_14028b000(uVar1);
  local_10 = FUN_140190260();
  p_Var2 = (u64*)&std::_Min_value<unsigned __int64>(local_10,local_18);
  return *p_Var2;
}

// @0x14028b0e0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
u64 FUN_14028b0e0(i64 param_1)
{
  i64 uVar1;
  u64 local_10;
  u64 local_18;
  u64* p_Var2;
  uVar1 = FUN_140288350(param_1);
  local_18 = FUN_14028b010(uVar1);
  local_10 = FUN_140190260();
  p_Var2 = (u64*)&std::_Min_value<unsigned __int64>(local_10,local_18);
  return *p_Var2;
}

// @0x14028b130
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
u64 FUN_14028b130(i64 param_1)
{
  i64 uVar1;
  u64 local_10;
  u64 local_18;
  u64* p_Var2;
  uVar1 = FUN_140288390(param_1);
  local_18 = FUN_14028b020(uVar1);
  local_10 = FUN_140190260();
  p_Var2 = (u64*)&std::_Min_value<unsigned __int64>(local_10,local_18);
  return *p_Var2;
}

// @0x14028b180
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
u64 FUN_14028b180(i64 param_1)
{
  i64 uVar1;
  u64 local_10;
  u64 local_18;
  u64* p_Var2;
  uVar1 = FUN_1402883d0(param_1);
  local_18 = FUN_14028b030(uVar1);
  local_10 = FUN_140190260();
  p_Var2 = (u64*)&std::_Min_value<unsigned __int64>(local_10,local_18);
  return *p_Var2;
}

// @0x14028b1d0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
u64 FUN_14028b1d0(i64 param_1)
{
  i64 uVar1;
  u64 local_10;
  u64 local_18;
  u64* p_Var2;
  uVar1 = FUN_140288410(param_1);
  local_18 = FUN_14028b040(uVar1);
  local_10 = FUN_140190260();
  p_Var2 = (u64*)&std::_Min_value<unsigned __int64>(local_10,local_18);
  return *p_Var2;
}

// @0x14028b220
i64 FUN_14028b220(i64 param_1)
{
  return FUN_14027b540(param_1);
}

// @0x14028b240
i64 FUN_14028b240(i64 param_1)
{
  return FUN_14027b4d0(param_1);
}

// @0x14028b260
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_14028b260(i64 param_1, i64 param_2)
{
  i64* puVar1;
  i64 local_10;
  puVar1 = (i64*)FUN_140289d80(param_1,(i64)&local_10);
  FUN_1402789b0(param_1,*puVar1,param_2);
}

// @0x14028b2a0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b2a0(i64 param_1, i64 param_2)
{
  i64 uVar1;
  uVar1 = FUN_14027c3e0(param_2);
  return FUN_14027bd40(param_1,uVar1);
}

// @0x14028b2d0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b2d0(i64 param_1, i64 param_2)
{
  i64 uVar1;
  uVar1 = FUN_14027c3f0(param_2);
  return FUN_14027bdb0(param_1,uVar1);
}

// @0x14028b300
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b300(i64 param_1, i64 param_2)
{
  i64 uVar1;
  uVar1 = FUN_14027c400(param_2);
  return FUN_14027be20(param_1,uVar1);
}

// @0x14028b330
i64 FUN_14028b330(i64 param_1, i64 param_2)
{
  return FUN_14027bcd0(param_1,param_2);
}

// @0x14028b360
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b360(i64 param_1, i64 param_2)
{
  i64* puVar1;
  i64 local_10;
  puVar1 = (i64*)FUN_14028aa30(param_1,(i64)&local_10);
  FUN_14027d630(param_2,*puVar1);
  return param_2;
}

// @0x14028b3a0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
void FUN_14028b3a0(i64 param_1, i64 param_2)
{
  u64 uVar1;
  uVar1 = FUN_14028a390(param_1);
  if (uVar1 < param_2) {
    uVar1 = FUN_14028b180(param_1);
    if (uVar1 < param_2) {
      FUN_140289f00();
    }
    FUN_140288d30(param_1,param_2);
  }
  return;
}

// @0x14028b3f0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b3f0(i64 param_1)
{
  i64 lVar1;
  lVar1 = FUN_140287ee0(param_1);
  return *(i64*)(lVar1 + 8);
}

// @0x14028b410
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b410(i64 param_1)
{
  i64* puVar1;
  puVar1 = (i64*)FUN_140288c40(param_1);
  return *puVar1;
}

// @0x14028b430
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b430(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288b00(param_1);
  plVar2 = (i64*)FUN_1402889a0(param_1);
  return *plVar1 - *plVar2 >> 3;
}

// @0x14028b470
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b470(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288b40(param_1);
  plVar2 = (i64*)FUN_1402889e0(param_1);
  return (*plVar1 - *plVar2) / 0x30;
}

// @0x14028b4c0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b4c0(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288b80(param_1);
  plVar2 = (i64*)FUN_140288a20(param_1);
  return *plVar1 - *plVar2 >> 3;
}

// @0x14028b500
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b500(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288bc0(param_1);
  plVar2 = (i64*)FUN_140288a60(param_1);
  return *plVar1 - *plVar2 >> 4;
}

// @0x14028b540
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b540(i64 param_1)
{
  i64* plVar1;
  i64* plVar2;
  plVar1 = (i64*)FUN_140288c00(param_1);
  plVar2 = (i64*)FUN_140288aa0(param_1);
  return *plVar1 - *plVar2 >> 4;
}

// @0x14028b580
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b580(void)
{
  return 7;
}

// @0x14028b590
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b590(void)
{
  return 3;
}

// @0x14028b5a0
// MS2-FUNCTIONAL: free-function form of MSVC STL template member (exe uses this-forwarding via rax/rcx, differing temps); logic identical
i64 FUN_14028b5a0(void)
{
  return 1;
}

// @0x14028b5b0
errno_t FUN_14028b5b0(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    if (src == NULL || dstSize < srcSize) {
        memset(dst, 0, dstSize);
        MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
        MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
        return EINVAL;
    }
    memcpy(dst, src, srcSize);
    return 0;
}

// @0x14028b700
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
