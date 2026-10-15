// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService, part 3 of 4 (owner ws1).
// Functional tier: generated from the Ghidra decompile (work/ws/gen.py) as plain tagged functions.
// MS2-UNIT: ?\worldservice.cpp#3
// MS2-RANGE: 0x141bedaf0-0x141bf2b70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <new>

typedef unsigned char undefined; typedef unsigned char undefined1; typedef unsigned short undefined2;
typedef unsigned int undefined4; typedef unsigned long long undefined8; typedef long long longlong;
typedef unsigned long long ulonglong; typedef unsigned int uint; typedef unsigned short ushort;
typedef unsigned char byte; typedef unsigned char uchar; typedef unsigned int dword; typedef unsigned long long qword;
typedef unsigned short word; typedef signed char schar; typedef undefined8 code(...);
#pragma warning(disable:4716)
 typedef unsigned long long __uint64;

// ---- callees in the exe (variadic prototypes, return types from the decompile; bound by VA at link) ----
void * FUN_140159740(...);
undefined8 FUN_140162e40(...);
undefined8 FUN_140162ef0(...);
undefined8 FUN_140162f40(...);
undefined8 FUN_14016ad80(...);
undefined8 FUN_140180c20(...);
undefined8 FUN_1401db5d0(...);
undefined8 FUN_1401ef380(...);
ushort * FUN_1402da110(...);
undefined8 FUN_1403b8210(...);
undefined8 FUN_140442200(...);
undefined8 FUN_140968bd0(...);
undefined8 FUN_140968c00(...);
longlong FUN_140969b00(...);
longlong FUN_140969b40(...);
undefined8 FUN_140980460(...);
undefined8 FUN_1409f1fa0(...);
undefined1 * FUN_1409f1fe0(...);
undefined8 FUN_140ae1dd0(...);
undefined8 FUN_140af5a50(...);
undefined8 FUN_140af5ad0(...);
undefined8 FUN_140b28610(...);
undefined8 FUN_14111ce10(...);
undefined8 FUN_14111d050(...);
void * FUN_141122f10(...);
undefined8 FUN_14123f020(...);
undefined8 FUN_14133e6f0(...);
undefined8 FUN_141375140(...);
undefined8 FUN_1413f7bd0(...);
undefined8 FUN_1414c6a20(...);
undefined8 * FUN_1415325f0(...);
undefined8 FUN_141669140(...);
undefined8 FUN_14174a7f0(...);
undefined8 * FUN_141b943c0(...);
undefined8 FUN_141bdb8e0(...);
longlong FUN_141bdc120(...);
undefined8 FUN_141bdc260(...);
undefined8 FUN_141bdc2b0(...);
undefined8 FUN_141bdc300(...);
undefined8 FUN_141bdc350(...);
undefined8 FUN_141bdc3a0(...);
undefined8 FUN_141bdc3f0(...);
undefined8 FUN_141bdc440(...);
undefined8 FUN_141bdc490(...);
undefined8 FUN_141bdc4e0(...);
undefined8 FUN_141bdc530(...);
longlong FUN_141bdc620(...);
longlong FUN_141bdc670(...);
longlong FUN_141bdcde0(...);
longlong FUN_141bdce30(...);
longlong FUN_141bddcc0(...);
longlong FUN_141bddd90(...);
longlong FUN_141bdde60(...);
longlong FUN_141bddf30(...);
longlong FUN_141bde000(...);
longlong FUN_141bde0d0(...);
longlong FUN_141bde1a0(...);
longlong FUN_141bde300(...);
longlong FUN_141bde390(...);
longlong FUN_141bde420(...);
longlong FUN_141bde9d0(...);
longlong FUN_141bdea30(...);
undefined8 FUN_141bdee50(...);
undefined8 FUN_141bdef10(...);
undefined8 FUN_141bdefd0(...);
undefined8 FUN_141bdf090(...);
undefined8 FUN_141bdf150(...);
longlong FUN_141bdf210(...);
longlong FUN_141bdf460(...);
longlong FUN_141bdf6b0(...);
longlong FUN_141bdf900(...);
longlong FUN_141bdfb50(...);
undefined8 * FUN_141be31f0(...);
undefined8 * FUN_141be3e30(...);
undefined8 * FUN_141be4a70(...);
undefined8 * FUN_141be56b0(...);
undefined8 * FUN_141be62f0(...);
undefined8 * FUN_141be6f30(...);
undefined8 FUN_141be87a0(...);
undefined8 FUN_141be8bb0(...);
undefined8 FUN_141be8fc0(...);
undefined8 FUN_141bea000(...);
undefined8 FUN_141bea410(...);
undefined8 FUN_141beb310(...);
undefined8 FUN_141beb460(...);
undefined8 FUN_141beb5b0(...);
undefined8 FUN_141beb700(...);
undefined8 FUN_141beb850(...);
undefined8 FUN_141beb9a0(...);
undefined8 FUN_141bebaf0(...);
undefined8 FUN_141beca40(...);
void * FUN_141bf9e10(...);
void * FUN_141bf9ed0(...);
void * FUN_141bf9f10(...);
void * FUN_141bf9f50(...);
void * FUN_141bf9f90(...);
void * FUN_141bf9fd0(...);
void * FUN_141bfa010(...);
void * FUN_141bfa050(...);
void * FUN_141bfa090(...);
void * FUN_141bfa0d0(...);
undefined8 FUN_141c1c2f0(...);
undefined8 FUN_141c1c3a0(...);
undefined8 FUN_141c1c450(...);
undefined8 FUN_141c1c500(...);
undefined8 FUN_141c1c5b0(...);
undefined8 FUN_141c1c660(...);
undefined8 FUN_141c1c710(...);
undefined8 FUN_141c1c7c0(...);
undefined8 FUN_141c1c870(...);
undefined8 FUN_141c1c920(...);
undefined8 FUN_141c1c9d0(...);
undefined8 FUN_141c1f4a0(...);
undefined8 FUN_141c1f4d0(...);
undefined8 FUN_141c1f500(...);
undefined8 FUN_141c1f530(...);
undefined8 FUN_141c1f560(...);
undefined8 FUN_141c1f590(...);
undefined8 FUN_141c1f5c0(...);
undefined8 FUN_141c1f5f0(...);
undefined8 FUN_141c1f860(...);
undefined8 FUN_141c1f8d0(...);
undefined8 FUN_141c215c0(...);
undefined8 FUN_141c215f0(...);
undefined8 FUN_141c21620(...);
undefined8 FUN_141c21650(...);
undefined8 FUN_141c21680(...);
undefined8 FUN_141c216b0(...);
undefined8 FUN_141c216e0(...);
undefined8 FUN_141c21710(...);
undefined8 FUN_141c21740(...);
undefined8 FUN_141c21770(...);
undefined8 FUN_141c273a0(...);
undefined8 FUN_141c273f0(...);
undefined8 FUN_141c27440(...);
undefined8 FUN_141c27490(...);
undefined8 FUN_141c274e0(...);
undefined8 FUN_141c28930(...);
undefined8 FUN_141c28970(...);
undefined8 FUN_141c289b0(...);
undefined8 FUN_141c289f0(...);
undefined8 FUN_141c2cc90(...);
undefined8 FUN_141c2ce30(...);
undefined8 FUN_141c2cfd0(...);
undefined8 FUN_141c2d170(...);
// ---- functions of this unit (forward declarations) ----
undefined8 FUN_141bedaf0(...);
void FUN_141bedaf0(void);
undefined8 FUN_141bedb00(...);
void FUN_141bedb00(void);
undefined8 FUN_141bedb10(...);
void FUN_141bedb10(void);
undefined8 FUN_141bedb20(...);
void FUN_141bedb20(void);
undefined8 FUN_141bedb30(...);
void FUN_141bedb30(void);
undefined8 FUN_141bedb40(...);
void FUN_141bedb40(void);
undefined8 FUN_141bedb50(...);
void FUN_141bedb50(void);
undefined8 FUN_141bedb60(...);
void FUN_141bedb60(void);
undefined8 FUN_141bedb70(...);
void FUN_141bedb70(void);
undefined8 FUN_141bedb80(...);
void FUN_141bedb80(void);
undefined8 FUN_141bedb90(...);
void FUN_141bedb90(void);
undefined8 FUN_141bedba0(...);
void FUN_141bedba0(void);
undefined8 FUN_141bedbb0(...);
 void FUN_141bedbb0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedbd0(...);
 void FUN_141bedbd0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedbf0(...);
 void FUN_141bedbf0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedc10(...);
 void FUN_141bedc10(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedc30(...);
 void FUN_141bedc30(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedc50(...);
void FUN_141bedc50(void);
undefined8 FUN_141bedc60(...);
void FUN_141bedc60(void);
undefined8 FUN_141bedc70(...);
 void FUN_141bedc70(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedc90(...);
 void FUN_141bedc90(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedcb0(...);
 void FUN_141bedcb0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedcd0(...);
 void FUN_141bedcd0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedcf0(...);
 void FUN_141bedcf0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedd10(...);
void FUN_141bedd10(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedd40(...);
void FUN_141bedd40(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedd70(...);
undefined8 FUN_141bedd70(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bedde0(...);
undefined8 FUN_141bedde0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bede50(...);
undefined8 FUN_141bede50(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bedec0(...);
void FUN_141bedec0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedf30(...);
void FUN_141bedf30(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bedfa0(...);
void FUN_141bedfa0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bee010(...);
void FUN_141bee010(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bee080(...);
void FUN_141bee080(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bee0f0(...);
undefined8 FUN_141bee0f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141bee190(...);
undefined8 FUN_141bee190(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141bee230(...);
undefined8 FUN_141bee230(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141bee2d0(...);
undefined8 FUN_141bee2d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141bee370(...);
undefined8 FUN_141bee370(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141bee410(...);
undefined8 FUN_141bee410(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141bee4b0(...);
undefined8 FUN_141bee4b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141bee550(...);
undefined8 FUN_141bee550(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bee590(...);
undefined8 FUN_141bee590(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bee5d0(...);
undefined8 FUN_141bee5d0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bee610(...);
undefined8 FUN_141bee610(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bee650(...);
undefined8 FUN_141bee650(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bee690(...);
 void FUN_141bee690(undefined8 param_1,undefined8 *param_2,undefined4 *param_3);
undefined8 FUN_141bee7b0(...);
void FUN_141bee7b0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bee7e0(...);
undefined8 FUN_141bee7e0(undefined8 param_1);
undefined8 FUN_141bee7f0(...);
undefined8 FUN_141bee7f0(undefined8 param_1);
undefined8 FUN_141bee800(...);
undefined8 FUN_141bee800(undefined8 param_1);
undefined8 FUN_141bee810(...);
undefined8 FUN_141bee810(undefined8 param_1);
undefined8 FUN_141bee820(...);
undefined8 FUN_141bee820(undefined8 param_1);
undefined8 FUN_141bee830(...);
undefined8 FUN_141bee830(undefined8 param_1);
undefined8 FUN_141bee840(...);
undefined8 FUN_141bee840(undefined8 param_1);
undefined8 FUN_141bee850(...);
undefined8 FUN_141bee850(undefined8 param_1);
undefined8 FUN_141bee860(...);
undefined8 FUN_141bee860(undefined8 param_1);
undefined8 FUN_141bee870(...);
undefined8 FUN_141bee870(undefined8 param_1);
undefined8 FUN_141bee880(...);
undefined8 FUN_141bee880(undefined8 param_1);
undefined8 FUN_141bee890(...);
undefined8 FUN_141bee890(undefined8 param_1);
undefined8 FUN_141bee8a0(...);
undefined8 FUN_141bee8a0(undefined8 param_1);
undefined8 FUN_141bee8b0(...);
undefined8 FUN_141bee8b0(undefined8 param_1);
undefined8 FUN_141bee8c0(...);
undefined8 FUN_141bee8c0(undefined8 param_1);
undefined8 FUN_141bee8d0(...);
undefined8 FUN_141bee8d0(undefined8 param_1);
undefined8 FUN_141bee8e0(...);
undefined8 FUN_141bee8e0(undefined8 param_1);
undefined8 FUN_141bee8f0(...);
undefined8 FUN_141bee8f0(undefined8 param_1);
undefined8 FUN_141bee900(...);
undefined8 FUN_141bee900(undefined8 param_1);
undefined8 FUN_141bee910(...);
undefined8 FUN_141bee910(undefined8 param_1);
undefined8 FUN_141bee920(...);
undefined8 FUN_141bee920(undefined8 param_1);
undefined8 FUN_141bee930(...);
undefined8 FUN_141bee930(undefined8 param_1);
undefined8 FUN_141bee940(...);
undefined8 FUN_141bee940(undefined8 param_1);
undefined8 FUN_141bee950(...);
undefined8 FUN_141bee950(undefined8 param_1);
undefined8 FUN_141bee960(...);
undefined8 FUN_141bee960(undefined8 param_1);
undefined8 FUN_141bee970(...);
undefined8 FUN_141bee970(undefined8 param_1);
undefined8 FUN_141bee980(...);
undefined8 FUN_141bee980(undefined8 param_1);
undefined8 FUN_141bee990(...);
undefined8 FUN_141bee990(undefined8 param_1);
undefined8 FUN_141bee9a0(...);
undefined8 FUN_141bee9a0(undefined8 param_1);
undefined8 FUN_141bee9b0(...);
undefined8 FUN_141bee9b0(undefined8 param_1);
undefined8 FUN_141bee9c0(...);
undefined8 FUN_141bee9c0(undefined8 param_1);
undefined8 FUN_141bee9d0(...);
undefined8 FUN_141bee9d0(undefined8 param_1);
undefined8 FUN_141bee9e0(...);
undefined8 FUN_141bee9e0(undefined8 param_1);
undefined8 FUN_141bee9f0(...);
undefined8 FUN_141bee9f0(undefined8 param_1);
undefined8 FUN_141beea00(...);
undefined8 FUN_141beea00(undefined8 param_1);
undefined8 FUN_141beea10(...);
undefined8 FUN_141beea10(undefined8 param_1);
undefined8 FUN_141beea20(...);
undefined8 FUN_141beea20(undefined8 param_1);
undefined8 FUN_141beea30(...);
undefined8 FUN_141beea30(undefined8 param_1);
undefined8 FUN_141beea40(...);
undefined8 FUN_141beea40(undefined8 param_1);
undefined8 FUN_141beea50(...);
undefined8 FUN_141beea50(undefined8 param_1);
undefined8 FUN_141beea60(...);
undefined8 FUN_141beea60(undefined8 param_1);
undefined8 FUN_141beea70(...);
undefined8 FUN_141beea70(undefined8 param_1);
undefined8 FUN_141beea80(...);
undefined8 FUN_141beea80(undefined8 param_1);
undefined8 FUN_141beea90(...);
undefined8 FUN_141beea90(undefined8 param_1);
undefined8 FUN_141beeaa0(...);
undefined8 FUN_141beeaa0(undefined8 param_1);
undefined8 FUN_141beeab0(...);
undefined8 FUN_141beeab0(undefined8 param_1);
undefined8 FUN_141beeac0(...);
undefined8 FUN_141beeac0(undefined8 param_1);
undefined8 FUN_141beead0(...);
undefined8 FUN_141beead0(undefined8 param_1);
undefined8 FUN_141beeae0(...);
undefined8 FUN_141beeae0(undefined8 param_1);
undefined8 FUN_141beeaf0(...);
undefined8 FUN_141beeaf0(undefined8 param_1);
undefined8 FUN_141beeb00(...);
undefined8 FUN_141beeb00(undefined8 param_1);
undefined8 FUN_141beeb10(...);
undefined8 FUN_141beeb10(undefined8 param_1);
undefined8 FUN_141beeb20(...);
undefined8 FUN_141beeb20(undefined8 param_1);
undefined8 FUN_141beeb30(...);
undefined8 FUN_141beeb30(undefined8 param_1);
undefined8 FUN_141beeb40(...);
undefined8 FUN_141beeb40(undefined8 param_1);
undefined8 FUN_141beeb50(...);
undefined8 FUN_141beeb50(undefined8 param_1);
undefined8 FUN_141beeb60(...);
undefined8 FUN_141beeb60(undefined8 param_1);
undefined8 FUN_141beeb70(...);
undefined8 FUN_141beeb70(undefined8 param_1);
undefined8 FUN_141beeb80(...);
undefined8 FUN_141beeb80(undefined8 param_1);
undefined8 FUN_141beeb90(...);
undefined8 FUN_141beeb90(undefined8 param_1);
undefined8 FUN_141beeba0(...);
undefined8 FUN_141beeba0(undefined8 param_1);
undefined8 FUN_141beebb0(...);
undefined8 FUN_141beebb0(undefined8 param_1);
undefined8 FUN_141beebc0(...);
undefined8 FUN_141beebc0(undefined8 param_1);
undefined8 FUN_141beebd0(...);
undefined8 FUN_141beebd0(undefined8 param_1);
undefined8 FUN_141beebe0(...);
undefined8 FUN_141beebe0(undefined8 param_1);
undefined8 FUN_141beebf0(...);
undefined8 FUN_141beebf0(undefined8 param_1);
undefined8 FUN_141beec00(...);
undefined8 FUN_141beec00(undefined8 param_1);
undefined8 FUN_141beec10(...);
undefined8 FUN_141beec10(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beec50(...);
undefined8 FUN_141beec50(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beec90(...);
undefined8 FUN_141beec90(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beecd0(...);
undefined8 FUN_141beecd0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beed10(...);
undefined8 FUN_141beed10(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beed50(...);
 undefined8 FUN_141beed50(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beeda0(...);
 undefined8 FUN_141beeda0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beedf0(...);
 undefined8 FUN_141beedf0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beee40(...);
 undefined8 FUN_141beee40(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beee90(...);
 undefined8 FUN_141beee90(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beeee0(...);
void FUN_141beeee0(undefined8 param_1);
undefined8 FUN_141beef00(...);
undefined8 FUN_141beef00(undefined8 param_1);
undefined8 FUN_141beef10(...);
undefined8 FUN_141beef10(undefined8 param_1);
undefined8 FUN_141beef20(...);
undefined8 FUN_141beef20(undefined8 param_1);
undefined8 FUN_141beef30(...);
undefined8 FUN_141beef30(undefined8 param_1);
undefined8 FUN_141beef40(...);
undefined8 FUN_141beef40(undefined8 param_1);
undefined8 FUN_141beef50(...);
undefined8 FUN_141beef50(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beef90(...);
undefined8 FUN_141beef90(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beefd0(...);
undefined8 FUN_141beefd0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bef010(...);
undefined8 FUN_141bef010(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bef050(...);
undefined8 FUN_141bef050(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bef090(...);
undefined8 FUN_141bef090(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bef0d0(...);
undefined8 FUN_141bef0d0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bef110(...);
 void FUN_141bef110(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bef1b0(...);
undefined8 FUN_141bef1b0(void);
undefined8 FUN_141bef1c0(...);
 undefined1 *  FUN_141bef1c0(undefined1 *this_);
undefined8 FUN_141bef200(...);
undefined8 * FUN_141bef200(undefined8 *param_1,undefined4 param_2);
undefined8 FUN_141bef260(...);
undefined8 * FUN_141bef260(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141bef350(...);
undefined8 * FUN_141bef350(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141bef440(...);
undefined8 * FUN_141bef440(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141bef530(...);
undefined8 * FUN_141bef530(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141bef620(...);
undefined8 * FUN_141bef620(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141bef710(...);
undefined8 * FUN_141bef710(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141bef800(...);
undefined8 * FUN_141bef800(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141bef8f0(...);
undefined8 * FUN_141bef8f0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141bef9e0(...);
undefined8 * FUN_141bef9e0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141befad0(...);
undefined8 * FUN_141befad0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141befbc0(...);
undefined8 * FUN_141befbc0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6);
undefined8 FUN_141befcb0(...);
undefined8 FUN_141befcb0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befce0(...);
undefined8 FUN_141befce0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befd10(...);
undefined8 FUN_141befd10(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befd40(...);
undefined8 FUN_141befd40(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befd70(...);
undefined8 FUN_141befd70(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befda0(...);
undefined8 FUN_141befda0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befdd0(...);
undefined8 FUN_141befdd0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befe00(...);
undefined8 FUN_141befe00(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befe30(...);
undefined8 FUN_141befe30(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befe60(...);
undefined8 FUN_141befe60(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befe90(...);
undefined8 FUN_141befe90(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befec0(...);
undefined8 FUN_141befec0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141befef0(...);
undefined8 FUN_141befef0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beff20(...);
undefined8 FUN_141beff20(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beff50(...);
undefined8 FUN_141beff50(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beff80(...);
undefined8 FUN_141beff80(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beffb0(...);
undefined8 FUN_141beffb0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beffe0(...);
undefined8 * FUN_141beffe0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0040(...);
undefined8 * FUN_141bf0040(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf00a0(...);
undefined8 * FUN_141bf00a0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0100(...);
undefined8 * FUN_141bf0100(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0160(...);
undefined8 * FUN_141bf0160(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf01c0(...);
undefined8 * FUN_141bf01c0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0220(...);
undefined8 * FUN_141bf0220(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0280(...);
undefined8 * FUN_141bf0280(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf02e0(...);
undefined8 * FUN_141bf02e0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0340(...);
undefined8 * FUN_141bf0340(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf03a0(...);
undefined8 * FUN_141bf03a0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0400(...);
undefined8 * FUN_141bf0400(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0460(...);
undefined8 * FUN_141bf0460(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf04c0(...);
undefined8 * FUN_141bf04c0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0520(...);
undefined8 * FUN_141bf0520(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0580(...);
undefined8 * FUN_141bf0580(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf05e0(...);
undefined8 * FUN_141bf05e0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf0640(...);
undefined1 *  FUN_141bf0640(undefined1 *this_,undefined8 *param_2,undefined8 param_3);
undefined8 FUN_141bf06a0(...);
undefined1 *  FUN_141bf06a0(undefined1 *this_,longlong param_2);
undefined8 FUN_141bf0700(...);
undefined1 *  FUN_141bf0700(undefined1 *this_,undefined8 *param_2,undefined1 *param_3);
undefined8 FUN_141bf0760(...);
undefined1 *  FUN_141bf0760(undefined1 *this_,longlong param_2);
undefined8 FUN_141bf07d0(...);
undefined1 *  FUN_141bf07d0(undefined1 *this_, undefined1 *param_2);
undefined8 FUN_141bf0850(...);
undefined1 *  FUN_141bf0850(undefined1 *this_, undefined1 *param_2);
undefined8 FUN_141bf08d0(...);
undefined1 *  FUN_141bf08d0(undefined1 *this_, undefined1 *param_2);
undefined8 FUN_141bf0950(...);
undefined1 *  FUN_141bf0950(undefined1 *this_, undefined1 *param_2);
undefined8 FUN_141bf09d0(...);
undefined1 *  FUN_141bf09d0(undefined1 *this_, undefined1 *param_2);
undefined8 FUN_141bf0a50(...);
undefined1 *  FUN_141bf0a50(undefined1 *this_, undefined1 *param_2);
undefined8 FUN_141bf0ad0(...);
undefined1 *  FUN_141bf0ad0(undefined1 *this_, undefined1 *param_2);
undefined8 FUN_141bf0b50(...);
undefined1 *  FUN_141bf0b50(undefined1 *this_, undefined1 *param_2);
undefined8 FUN_141bf0bd0(...);
undefined1 *  FUN_141bf0bd0(undefined1 *this_,undefined1 *param_2);
undefined8 FUN_141bf0c30(...);
undefined1 *  FUN_141bf0c30(undefined1 *this_,undefined1 *param_2);
undefined8 FUN_141bf0c90(...);
undefined1 *  FUN_141bf0c90(undefined1 *this_,undefined1 *param_2);
undefined8 FUN_141bf0cf0(...);
undefined1 *  FUN_141bf0cf0(undefined1 *this_,undefined1 *param_2);
undefined8 FUN_141bf0d50(...);
undefined1 *  FUN_141bf0d50(undefined1 *this_,undefined1 *param_2);
undefined8 FUN_141bf0db0(...);
undefined1 *  FUN_141bf0db0(undefined1 *this_,undefined1 *param_2);
undefined8 FUN_141bf0e10(...);
undefined1 *  FUN_141bf0e10(undefined1 *this_,undefined1 *param_2);
undefined8 FUN_141bf0e70(...);
undefined1 * FUN_141bf0e70(undefined1 *param_1);
undefined8 FUN_141bf0e90(...);
longlong * FUN_141bf0e90(longlong *param_1,longlong *param_2);
undefined8 FUN_141bf0ed0(...);
longlong * FUN_141bf0ed0(longlong *param_1,longlong param_2);
undefined8 FUN_141bf0f10(...);
longlong * FUN_141bf0f10(longlong *param_1,longlong *param_2);
undefined8 FUN_141bf0f50(...);
longlong * FUN_141bf0f50(longlong *param_1,longlong param_2);
undefined8 FUN_141bf0f90(...);
longlong * FUN_141bf0f90(longlong *param_1,longlong param_2);
undefined8 FUN_141bf0fd0(...);
 longlong * FUN_141bf0fd0(longlong *param_1,longlong param_2);
undefined8 FUN_141bf1020(...);
longlong * FUN_141bf1020(longlong *param_1,longlong param_2);
undefined8 FUN_141bf1060(...);
longlong * FUN_141bf1060(longlong *param_1,longlong param_2);
undefined8 FUN_141bf10a0(...);
longlong * FUN_141bf10a0(longlong *param_1,longlong *param_2);
undefined8 FUN_141bf10e0(...);
longlong * FUN_141bf10e0(longlong *param_1,longlong *param_2);
undefined8 FUN_141bf1130(...);
longlong * FUN_141bf1130(longlong *param_1,longlong param_2);
undefined8 FUN_141bf1170(...);
longlong FUN_141bf1170(longlong param_1,longlong param_2);
undefined8 FUN_141bf11b0(...);
longlong FUN_141bf11b0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf11e0(...);
longlong FUN_141bf11e0(longlong param_1);
undefined8 FUN_141bf1200(...);
longlong FUN_141bf1200(longlong param_1,longlong param_2);
undefined8 FUN_141bf1230(...);
longlong FUN_141bf1230(longlong param_1,longlong param_2);
undefined8 FUN_141bf1270(...);
longlong FUN_141bf1270(longlong param_1);
undefined8 FUN_141bf12a0(...);
longlong FUN_141bf12a0(longlong param_1);
undefined8 FUN_141bf12c0(...);
longlong FUN_141bf12c0(longlong param_1);
undefined8 FUN_141bf12e0(...);
longlong FUN_141bf12e0(longlong param_1);
undefined8 FUN_141bf1300(...);
longlong FUN_141bf1300(longlong param_1,longlong param_2);
undefined8 FUN_141bf1330(...);
longlong FUN_141bf1330(longlong param_1,longlong param_2);
undefined8 FUN_141bf1370(...);
longlong FUN_141bf1370(longlong param_1);
undefined8 FUN_141bf1390(...);
longlong FUN_141bf1390(longlong param_1,longlong param_2);
undefined8 FUN_141bf13c0(...);
longlong FUN_141bf13c0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf13f0(...);
longlong FUN_141bf13f0(longlong param_1,longlong param_2);
undefined8 FUN_141bf1420(...);
longlong FUN_141bf1420(longlong param_1,longlong param_2);
undefined8 FUN_141bf1460(...);
longlong FUN_141bf1460(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf1490(...);
longlong FUN_141bf1490(longlong param_1);
undefined8 FUN_141bf14b0(...);
longlong FUN_141bf14b0(longlong param_1);
undefined8 FUN_141bf14d0(...);
longlong FUN_141bf14d0(longlong param_1,longlong param_2);
undefined8 FUN_141bf1500(...);
longlong FUN_141bf1500(longlong param_1);
undefined8 FUN_141bf1520(...);
longlong FUN_141bf1520(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf1550(...);
longlong FUN_141bf1550(longlong param_1,longlong param_2);
undefined8 FUN_141bf1580(...);
longlong FUN_141bf1580(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf15b0(...);
longlong FUN_141bf15b0(longlong param_1,longlong param_2);
undefined8 FUN_141bf15f0(...);
longlong FUN_141bf15f0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf1620(...);
longlong FUN_141bf1620(longlong param_1,longlong param_2);
undefined8 FUN_141bf1650(...);
longlong FUN_141bf1650(longlong param_1);
undefined8 FUN_141bf1670(...);
longlong FUN_141bf1670(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf16a0(...);
longlong FUN_141bf16a0(longlong param_1,longlong param_2);
undefined8 FUN_141bf16e0(...);
longlong FUN_141bf16e0(longlong param_1);
undefined8 FUN_141bf1700(...);
longlong FUN_141bf1700(longlong param_1);
undefined8 FUN_141bf1720(...);
longlong FUN_141bf1720(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf1750(...);
longlong FUN_141bf1750(longlong param_1);
undefined8 FUN_141bf1770(...);
longlong FUN_141bf1770(longlong param_1,longlong param_2);
undefined8 FUN_141bf17b0(...);
longlong FUN_141bf17b0(longlong param_1);
undefined8 FUN_141bf17d0(...);
longlong FUN_141bf17d0(longlong param_1,longlong param_2);
undefined8 FUN_141bf1800(...);
longlong FUN_141bf1800(longlong param_1,longlong param_2);
undefined8 FUN_141bf1840(...);
longlong FUN_141bf1840(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf1870(...);
longlong FUN_141bf1870(longlong param_1,longlong param_2);
undefined8 FUN_141bf18b0(...);
longlong FUN_141bf18b0(longlong param_1);
undefined8 FUN_141bf18d0(...);
longlong FUN_141bf18d0(longlong param_1,longlong param_2);
undefined8 FUN_141bf1900(...);
longlong FUN_141bf1900(longlong param_1,longlong param_2);
undefined8 FUN_141bf1940(...);
longlong FUN_141bf1940(longlong param_1);
undefined8 FUN_141bf1960(...);
longlong FUN_141bf1960(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf1990(...);
longlong FUN_141bf1990(longlong param_1);
undefined8 FUN_141bf19b0(...);
undefined1 *  FUN_141bf19b0(undefined1 *this_);
undefined8 FUN_141bf1a00(...);
undefined1 *  FUN_141bf1a00(undefined1 *this_);
undefined8 FUN_141bf1a50(...);
undefined8 FUN_141bf1a50(undefined8 param_1);
undefined8 FUN_141bf1aa0(...);
undefined8 FUN_141bf1aa0(undefined8 param_1);
undefined8 FUN_141bf1ac0(...);
undefined8 FUN_141bf1ac0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf1b00(...);
undefined8 FUN_141bf1b00(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf1b40(...);
undefined8 * FUN_141bf1b40(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf1b80(...);
undefined8 FUN_141bf1b80(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf1bc0(...);
undefined8 FUN_141bf1bc0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf1c00(...);
undefined8 * FUN_141bf1c00(undefined8 *param_1);
undefined8 FUN_141bf1c30(...);
undefined8 FUN_141bf1c30(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1c60(...);
undefined8 FUN_141bf1c60(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1c90(...);
undefined8 FUN_141bf1c90(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1cc0(...);
undefined8 FUN_141bf1cc0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1cf0(...);
undefined8 FUN_141bf1cf0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1d20(...);
undefined8 FUN_141bf1d20(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1d50(...);
undefined8 FUN_141bf1d50(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1d80(...);
undefined8 FUN_141bf1d80(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1db0(...);
undefined8 FUN_141bf1db0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1de0(...);
undefined8 FUN_141bf1de0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1e10(...);
undefined8 FUN_141bf1e10(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1e50(...);
undefined8 FUN_141bf1e50(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1e90(...);
undefined8 FUN_141bf1e90(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1ed0(...);
undefined8 FUN_141bf1ed0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1f10(...);
undefined8 FUN_141bf1f10(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1f50(...);
undefined8 FUN_141bf1f50(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1f90(...);
undefined8 FUN_141bf1f90(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf1fd0(...);
undefined8 FUN_141bf1fd0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf2010(...);
undefined8 FUN_141bf2010(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf2050(...);
undefined8 FUN_141bf2050(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bf2090(...);
undefined8 FUN_141bf2090(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf20d0(...);
undefined8 FUN_141bf20d0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2110(...);
undefined8 FUN_141bf2110(undefined8 param_1);
undefined8 FUN_141bf2130(...);
undefined8 FUN_141bf2130(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2170(...);
undefined8 FUN_141bf2170(undefined8 param_1);
undefined8 FUN_141bf2190(...);
undefined8 FUN_141bf2190(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf21d0(...);
undefined8 FUN_141bf21d0(undefined8 param_1);
undefined8 FUN_141bf21f0(...);
undefined8 FUN_141bf21f0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2230(...);
undefined8 FUN_141bf2230(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2270(...);
undefined8 FUN_141bf2270(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf22b0(...);
undefined8 FUN_141bf22b0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf22f0(...);
undefined8 FUN_141bf22f0(undefined8 param_1);
undefined8 FUN_141bf2310(...);
undefined8 FUN_141bf2310(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2350(...);
undefined8 FUN_141bf2350(undefined8 param_1);
undefined8 FUN_141bf2370(...);
undefined8 FUN_141bf2370(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf23b0(...);
undefined8 FUN_141bf23b0(undefined8 param_1);
undefined8 FUN_141bf23d0(...);
undefined8 FUN_141bf23d0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2410(...);
undefined8 FUN_141bf2410(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2450(...);
undefined8 FUN_141bf2450(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2490(...);
undefined8 FUN_141bf2490(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf24d0(...);
undefined8 FUN_141bf24d0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2510(...);
undefined8 FUN_141bf2510(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2550(...);
undefined8 FUN_141bf2550(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2590(...);
undefined8 FUN_141bf2590(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf25d0(...);
undefined8 FUN_141bf25d0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2610(...);
undefined8 * FUN_141bf2610(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2650(...);
undefined8 * FUN_141bf2650(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2690(...);
undefined8 * FUN_141bf2690(undefined8 *param_1);
undefined8 FUN_141bf26b0(...);
undefined8 * FUN_141bf26b0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf26f0(...);
undefined8 * FUN_141bf26f0(undefined8 *param_1);
undefined8 FUN_141bf2710(...);
undefined8 * FUN_141bf2710(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2750(...);
undefined8 * FUN_141bf2750(undefined8 *param_1);
undefined8 FUN_141bf2770(...);
undefined8 * FUN_141bf2770(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf27b0(...);
undefined8 * FUN_141bf27b0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf27f0(...);
undefined8 * FUN_141bf27f0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2830(...);
undefined8 * FUN_141bf2830(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2870(...);
undefined8 * FUN_141bf2870(undefined8 *param_1);
undefined8 FUN_141bf2890(...);
undefined8 * FUN_141bf2890(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf28d0(...);
undefined8 * FUN_141bf28d0(undefined8 *param_1);
undefined8 FUN_141bf28f0(...);
undefined8 * FUN_141bf28f0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2930(...);
undefined8 * FUN_141bf2930(undefined8 *param_1);
undefined8 FUN_141bf2950(...);
undefined8 * FUN_141bf2950(undefined8 *param_1);
undefined8 FUN_141bf2980(...);
undefined8 * FUN_141bf2980(undefined8 *param_1);
undefined8 FUN_141bf29b0(...);
undefined8 * FUN_141bf29b0(undefined8 *param_1);
undefined8 FUN_141bf29e0(...);
undefined8 * FUN_141bf29e0(undefined8 *param_1);
undefined8 FUN_141bf2a10(...);
undefined8 * FUN_141bf2a10(undefined8 *param_1);
undefined8 FUN_141bf2a40(...);
undefined8 * FUN_141bf2a40(undefined8 *param_1);
undefined8 FUN_141bf2a70(...);
undefined8 * FUN_141bf2a70(undefined8 *param_1);
undefined8 FUN_141bf2aa0(...);
undefined8 * FUN_141bf2aa0(undefined8 *param_1);
undefined8 FUN_141bf2ad0(...);
undefined8 * FUN_141bf2ad0(undefined8 *param_1);
undefined8 FUN_141bf2b00(...);
undefined8 * FUN_141bf2b00(undefined8 *param_1);
undefined8 FUN_141bf2b30(...);
undefined8 * FUN_141bf2b30(undefined8 *param_1,undefined8 param_2,undefined8 param_3);

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedaf0
void FUN_141bedaf0(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb00
void FUN_141bedb00(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb10
void FUN_141bedb10(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb20
void FUN_141bedb20(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb30
void FUN_141bedb30(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb40
void FUN_141bedb40(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb50
void FUN_141bedb50(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb60
void FUN_141bedb60(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb70
void FUN_141bedb70(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb80
void FUN_141bedb80(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedb90
void FUN_141bedb90(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedba0
void FUN_141bedba0(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedbb0
 void FUN_141bedbb0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf9ed0(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedbd0
 void FUN_141bedbd0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf9f10(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedbf0
 void FUN_141bedbf0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf9f50(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedc10
 void FUN_141bedc10(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf9f90(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedc30
 void FUN_141bedc30(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf9fd0(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedc50
void FUN_141bedc50(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedc60
void FUN_141bedc60(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedc70
 void FUN_141bedc70(undefined8 param_1,undefined8 param_2)
{
  FUN_141bfa010(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedc90
 void FUN_141bedc90(undefined8 param_1,undefined8 param_2)
{
  FUN_141bfa050(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedcb0
 void FUN_141bedcb0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bfa090(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedcd0
 void FUN_141bedcd0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bfa0d0(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedcf0
 void FUN_141bedcf0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf9e10(param_2,0);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedd10
void FUN_141bedd10(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  
  FUN_141bde9d0(param_1,param_2,local_18);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedd40
void FUN_141bedd40(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  
  FUN_141bdea30(param_1,param_2,local_18);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedd70
undefined8 FUN_141bedd70(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = FUN_141beeb00(param_3);
  lVar2 = FUN_141bde300(param_1,uVar1);
  FUN_141be87a0(param_1,param_2,0,lVar2 + 0x20,lVar2);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedde0
undefined8 FUN_141bedde0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = FUN_141beeb10(param_3);
  lVar2 = FUN_141bde390(param_1,uVar1);
  FUN_141be8bb0(param_1,param_2,0,lVar2 + 0x20,lVar2);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bede50
undefined8 FUN_141bede50(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = FUN_141beeb20(param_3);
  lVar2 = FUN_141bde420(param_1,uVar1);
  FUN_141be8fc0(param_1,param_2,0,lVar2 + 0x20,lVar2);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedec0
void FUN_141bedec0(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  cVar1 = FUN_141c27490(param_1);
  if (cVar1 == '\0') {
    uVar2 = FUN_141beeaa0(param_2);
    puVar3 = (undefined8 *)FUN_140969b40(param_1);
    FUN_141bdf210(param_1,*puVar3,uVar2);
  }
  else {
    uVar2 = FUN_141beeaa0(param_2);
    FUN_141bdee50(param_1,uVar2);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedf30
void FUN_141bedf30(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  cVar1 = FUN_141c273a0(param_1);
  if (cVar1 == '\0') {
    uVar2 = FUN_141beeae0(param_2);
    puVar3 = (undefined8 *)FUN_141c28970(param_1);
    FUN_141bdf460(param_1,*puVar3,uVar2);
  }
  else {
    uVar2 = FUN_141beeae0(param_2);
    FUN_141bdef10(param_1,uVar2);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedfa0
void FUN_141bedfa0(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  cVar1 = FUN_141c273f0(param_1);
  if (cVar1 == '\0') {
    uVar2 = FUN_141beeaf0(param_2);
    puVar3 = (undefined8 *)FUN_141c289b0(param_1);
    FUN_141bdf6b0(param_1,*puVar3,uVar2);
  }
  else {
    uVar2 = FUN_141beeaf0(param_2);
    FUN_141bdefd0(param_1,uVar2);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee010
void FUN_141bee010(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  cVar1 = FUN_141c27440(param_1);
  if (cVar1 == '\0') {
    uVar2 = FUN_141beeb30(param_2);
    puVar3 = (undefined8 *)FUN_140969b00(param_1);
    FUN_141bdf900(param_1,*puVar3,uVar2);
  }
  else {
    uVar2 = FUN_141beeb30(param_2);
    FUN_141bdf090(param_1,uVar2);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee080
void FUN_141bee080(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  cVar1 = FUN_141c274e0(param_1);
  if (cVar1 == '\0') {
    uVar2 = FUN_141beeb50(param_2);
    puVar3 = (undefined8 *)FUN_141c289f0(param_1);
    FUN_141bdfb50(param_1,*puVar3,uVar2);
  }
  else {
    uVar2 = FUN_141beeb50(param_2);
    FUN_141bdf150(param_1,uVar2);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee0f0
undefined8 FUN_141bee0f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar1 = FUN_140162f40(param_6);
  uVar2 = FUN_14133e6f0(param_5);
  uVar3 = FUN_140162ef0(param_4);
  lVar4 = FUN_141bddcc0(param_1,uVar3,uVar2,uVar1);
  FUN_141be6f30(param_1,param_2,param_3,lVar4 + 0x20,lVar4);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee190
undefined8 FUN_141bee190(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar1 = FUN_140162f40(param_6);
  uVar2 = FUN_1401ef380(param_5);
  uVar3 = FUN_140162ef0(param_4);
  lVar4 = FUN_141bddd90(param_1,uVar3,uVar2,uVar1);
  FUN_141be31f0(param_1,param_2,param_3,lVar4 + 0x20,lVar4);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee230
undefined8 FUN_141bee230(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar1 = FUN_140162f40(param_6);
  uVar2 = FUN_1401ef380(param_5);
  uVar3 = FUN_140162ef0(param_4);
  lVar4 = FUN_141bdde60(param_1,uVar3,uVar2,uVar1);
  FUN_141be3e30(param_1,param_2,param_3,lVar4 + 0x20,lVar4);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee2d0
undefined8 FUN_141bee2d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar1 = FUN_140162f40(param_6);
  uVar2 = FUN_1401db5d0(param_5);
  uVar3 = FUN_140162ef0(param_4);
  lVar4 = FUN_141bddf30(param_1,uVar3,uVar2,uVar1);
  FUN_141be4a70(param_1,param_2,param_3,lVar4 + 0x20,lVar4);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee370
undefined8 FUN_141bee370(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar1 = FUN_140162f40(param_6);
  uVar2 = FUN_14111d050(param_5);
  uVar3 = FUN_140162ef0(param_4);
  lVar4 = FUN_141bde000(param_1,uVar3,uVar2,uVar1);
  FUN_141be56b0(param_1,param_2,param_3,lVar4 + 0x20,lVar4);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee410
undefined8 FUN_141bee410(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar1 = FUN_140162f40(param_6);
  uVar2 = FUN_14111d050(param_5);
  uVar3 = FUN_140162ef0(param_4);
  lVar4 = FUN_141bde0d0(param_1,uVar3,uVar2,uVar1);
  FUN_141be62f0(param_1,param_2,param_3,lVar4 + 0x20,lVar4);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee4b0
undefined8 FUN_141bee4b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5,undefined8 param_6)
{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  
  uVar1 = FUN_140162f40(param_6);
  uVar2 = FUN_140442200(param_5);
  uVar3 = FUN_140162ef0(param_4);
  lVar4 = FUN_141bde1a0(param_1,uVar3,uVar2,uVar1);
  FUN_141be6f30(param_1,param_2,param_3,lVar4 + 0x20,lVar4);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee550
undefined8 FUN_141bee550(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_1413f7bd0(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee590
undefined8 FUN_141bee590(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141c2cc90(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee5d0
undefined8 FUN_141bee5d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141c2ce30(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee610
undefined8 FUN_141bee610(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141c2cfd0(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee650
undefined8 FUN_141bee650(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141c2d170(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee690
 void FUN_141bee690(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)
{
  undefined8 uVar1;
  undefined1 auStack_198 [32];
  undefined4 *local_178;
  undefined4 local_170 [4];
  undefined4 local_160;
  undefined8 local_158;
  ulonglong local_28;
  
  local_158 = 0xfffffffffffffffe;
  local_178 = local_170;
  local_170[0] = *param_3;
  local_160 = 1;
  uVar1 = (undefined8)(FUN_1402da110(param_1,param_2,local_170));
  *param_2 = uVar1;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee7b0
void FUN_141bee7b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bee690(param_1,param_3,param_2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee7e0
undefined8 FUN_141bee7e0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee7f0
undefined8 FUN_141bee7f0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee800
undefined8 FUN_141bee800(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee810
undefined8 FUN_141bee810(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee820
undefined8 FUN_141bee820(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee830
undefined8 FUN_141bee830(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee840
undefined8 FUN_141bee840(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee850
undefined8 FUN_141bee850(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee860
undefined8 FUN_141bee860(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee870
undefined8 FUN_141bee870(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee880
undefined8 FUN_141bee880(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee890
undefined8 FUN_141bee890(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee8a0
undefined8 FUN_141bee8a0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee8b0
undefined8 FUN_141bee8b0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee8c0
undefined8 FUN_141bee8c0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee8d0
undefined8 FUN_141bee8d0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee8e0
undefined8 FUN_141bee8e0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee8f0
undefined8 FUN_141bee8f0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee900
undefined8 FUN_141bee900(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee910
undefined8 FUN_141bee910(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee920
undefined8 FUN_141bee920(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee930
undefined8 FUN_141bee930(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee940
undefined8 FUN_141bee940(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee950
undefined8 FUN_141bee950(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee960
undefined8 FUN_141bee960(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee970
undefined8 FUN_141bee970(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee980
undefined8 FUN_141bee980(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee990
undefined8 FUN_141bee990(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee9a0
undefined8 FUN_141bee9a0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee9b0
undefined8 FUN_141bee9b0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee9c0
undefined8 FUN_141bee9c0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee9d0
undefined8 FUN_141bee9d0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee9e0
undefined8 FUN_141bee9e0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bee9f0
undefined8 FUN_141bee9f0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea00
undefined8 FUN_141beea00(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea10
undefined8 FUN_141beea10(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea20
undefined8 FUN_141beea20(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea30
undefined8 FUN_141beea30(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea40
undefined8 FUN_141beea40(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea50
undefined8 FUN_141beea50(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea60
undefined8 FUN_141beea60(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea70
undefined8 FUN_141beea70(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea80
undefined8 FUN_141beea80(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beea90
undefined8 FUN_141beea90(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeaa0
undefined8 FUN_141beeaa0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeab0
undefined8 FUN_141beeab0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeac0
undefined8 FUN_141beeac0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beead0
undefined8 FUN_141beead0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeae0
undefined8 FUN_141beeae0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeaf0
undefined8 FUN_141beeaf0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb00
undefined8 FUN_141beeb00(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb10
undefined8 FUN_141beeb10(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb20
undefined8 FUN_141beeb20(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb30
undefined8 FUN_141beeb30(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb40
undefined8 FUN_141beeb40(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb50
undefined8 FUN_141beeb50(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb60
undefined8 FUN_141beeb60(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb70
undefined8 FUN_141beeb70(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb80
undefined8 FUN_141beeb80(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeb90
undefined8 FUN_141beeb90(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeba0
undefined8 FUN_141beeba0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beebb0
undefined8 FUN_141beebb0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beebc0
undefined8 FUN_141beebc0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beebd0
undefined8 FUN_141beebd0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beebe0
undefined8 FUN_141beebe0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beebf0
undefined8 FUN_141beebf0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beec00
undefined8 FUN_141beec00(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beec10
undefined8 FUN_141beec10(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bea000(param_1,param_2,0,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beec50
undefined8 FUN_141beec50(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bea410(param_1,param_2,0,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beec90
undefined8 FUN_141beec90(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141beeb00(param_3);
  FUN_141bedd70(param_1,param_2,uVar1);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beecd0
undefined8 FUN_141beecd0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141beeb10(param_3);
  FUN_141bedde0(param_1,param_2,uVar1);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beed10
undefined8 FUN_141beed10(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141beeb20(param_3);
  FUN_141bede50(param_1,param_2,uVar1);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beed50
 undefined8 FUN_141beed50(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_140180c20(param_3);
  uVar2 = FUN_140af5a50(param_2);
  FUN_141bdc120(param_1,uVar2,uVar1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeda0
 undefined8 FUN_141beeda0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_140162e40(param_3);
  uVar2 = FUN_14111ce10(param_2);
  FUN_141bdc620(param_1,uVar2,uVar1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beedf0
 undefined8 FUN_141beedf0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_1414c6a20(param_3);
  uVar2 = FUN_14111ce10(param_2);
  FUN_141bdc670(param_1,uVar2,uVar1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beee40
 undefined8 FUN_141beee40(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_141bee890(param_3);
  uVar2 = FUN_140af5ad0(param_2);
  FUN_141bdcde0(param_1,uVar2,uVar1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beee90
 undefined8 FUN_141beee90(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_141bee8a0(param_3);
  uVar2 = FUN_140af5ad0(param_2);
  FUN_141bdce30(param_1,uVar2,uVar1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beeee0
void FUN_141beeee0(undefined8 param_1)
{
  FUN_141bef1b0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beef00
undefined8 FUN_141beef00(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beef10
undefined8 FUN_141beef10(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beef20
undefined8 FUN_141beef20(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beef30
undefined8 FUN_141beef30(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beef40
undefined8 FUN_141beef40(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beef50
undefined8 FUN_141beef50(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141beb310(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beef90
undefined8 FUN_141beef90(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141beb460(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beefd0
undefined8 FUN_141beefd0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141beb5b0(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef010
undefined8 FUN_141bef010(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141beb700(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef050
undefined8 FUN_141bef050(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141beb850(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef090
undefined8 FUN_141bef090(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_1403b8210(param_3);
  FUN_141bebaf0(param_1,param_2,uVar1);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef0d0
undefined8 FUN_141bef0d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141beb9a0(param_1,param_2,param_3);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef110
 void FUN_141bef110(undefined8 param_1,undefined8 param_2)
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  longlong lVar3;
  undefined1 auStack_58 [32];
  undefined1 *local_38;
  undefined1 local_30 [16];
  ulonglong local_20;
  
  puVar1 = (undefined1 *)FUN_141beca40(param_1);
  puVar2 = local_30;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  local_38 = (undefined1 *)FUN_141beca40(param_2);
  puVar2 = (undefined1 *)FUN_141beca40(param_1);
  puVar1 = local_38;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined1 *)FUN_141beca40(param_2);
  puVar1 = local_30;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef1b0
undefined8 FUN_141bef1b0(void)
{
  return 0xd;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef1c0
 undefined1 *  FUN_141bef1c0(undefined1 *this_)
{
  *(undefined8 *)this_ = 0;
  *(undefined8 *)(this_ + 8) = 0;
  *(undefined8 *)(this_ + 0x10) = 0;
  *(undefined4 *)(this_ + 0x18) = 0;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef200
undefined8 * FUN_141bef200(undefined8 *param_1,undefined4 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined4 *)(param_1 + 5) = param_2;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef260
undefined8 * FUN_141bef260(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c2f0(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef350
undefined8 * FUN_141bef350(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c3a0(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef440
undefined8 * FUN_141bef440(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c450(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef530
undefined8 * FUN_141bef530(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c500(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef620
undefined8 * FUN_141bef620(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c5b0(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef710
undefined8 * FUN_141bef710(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c660(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef800
undefined8 * FUN_141bef800(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c710(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef8f0
undefined8 * FUN_141bef8f0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c7c0(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bef9e0
undefined8 * FUN_141bef9e0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c870(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befad0
undefined8 * FUN_141befad0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c920(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befbc0
undefined8 * FUN_141befbc0(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6)
{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 2) = param_2;
  *(undefined4 *)((longlong)param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 3) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x1c) = param_5;
  param_1[4] = 0xffffffff;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)((longlong)param_1 + 0x34) = param_6;
  param_1[7] = 0;
  param_1[8] = 0;
  FUN_141c1c9d0(param_1,param_3,param_4,param_5,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befcb0
undefined8 FUN_141befcb0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf00a0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befce0
undefined8 FUN_141befce0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0100(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befd10
undefined8 FUN_141befd10(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0160(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befd40
undefined8 FUN_141befd40(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf01c0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befd70
undefined8 FUN_141befd70(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0220(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befda0
undefined8 FUN_141befda0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0280(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befdd0
undefined8 FUN_141befdd0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf02e0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befe00
undefined8 FUN_141befe00(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0340(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befe30
undefined8 FUN_141befe30(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf03a0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befe60
undefined8 FUN_141befe60(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0400(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befe90
undefined8 FUN_141befe90(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0460(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befec0
undefined8 FUN_141befec0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf04c0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141befef0
undefined8 FUN_141befef0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0520(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beff20
undefined8 FUN_141beff20(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0580(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beff50
undefined8 FUN_141beff50(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf05e0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beff80
undefined8 FUN_141beff80(undefined8 param_1,undefined8 param_2)
{
  FUN_141beffe0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beffb0
undefined8 FUN_141beffb0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf0040(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beffe0
undefined8 * FUN_141beffe0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0040
undefined8 * FUN_141bf0040(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf00a0
undefined8 * FUN_141bf00a0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0100
undefined8 * FUN_141bf0100(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0160
undefined8 * FUN_141bf0160(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf01c0
undefined8 * FUN_141bf01c0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0220
undefined8 * FUN_141bf0220(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0280
undefined8 * FUN_141bf0280(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf02e0
undefined8 * FUN_141bf02e0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0340
undefined8 * FUN_141bf0340(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf03a0
undefined8 * FUN_141bf03a0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0400
undefined8 * FUN_141bf0400(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0460
undefined8 * FUN_141bf0460(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf04c0
undefined8 * FUN_141bf04c0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0520
undefined8 * FUN_141bf0520(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0580
undefined8 * FUN_141bf0580(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf05e0
undefined8 * FUN_141bf05e0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf0640
undefined1 *  FUN_141bf0640(undefined1 *this_,undefined8 *param_2,undefined8 param_3)
{
  return (undefined1 *)((undefined8 (*)(...))0x141bf0640ULL)(this_,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf06a0
undefined1 *  FUN_141bf06a0(undefined1 *this_,longlong param_2)
{
  return (undefined1 *)((undefined8 (*)(...))0x141bf06a0ULL)(this_,param_2);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf0700
undefined1 *  FUN_141bf0700(undefined1 *this_,undefined8 *param_2,undefined1 *param_3)
{
  return (undefined1 *)((undefined8 (*)(...))0x141bf0700ULL)(this_,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf0760
undefined1 *  FUN_141bf0760(undefined1 *this_,longlong param_2)
{
  return (undefined1 *)((undefined8 (*)(...))0x141bf0760ULL)(this_,param_2);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf07d0
undefined1 *  FUN_141bf07d0(undefined1 *this_, undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *pMVar2;
  
  FUN_141122f10((undefined1 *)this_);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffef60ULL));
  pMVar2 = this_ + 0x18;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *pMVar2 = *param_2;
    param_2 = param_2 + 1;
    pMVar2 = pMVar2 + 1;
  }
  *(undefined1 **)(this_ + 8) = (undefined1 *)((*(undefined8 *)0x143b023b0ULL));
  (*(undefined8 *)0x143b023b0ULL) = (undefined8)(this_);
  *(undefined4 *)(this_ + 0x10) = 0x3004;
  *(undefined4 *)(this_ + 0x14) = 0x6100002;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf0850
undefined1 *  FUN_141bf0850(undefined1 *this_, undefined1 *param_2)
{
  return (undefined1 *)((undefined8 (*)(...))0x141bf0850ULL)(this_,param_2);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf08d0
undefined1 *  FUN_141bf08d0(undefined1 *this_, undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *pMVar2;
  
  FUN_141122f10((undefined1 *)this_);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffef20ULL));
  pMVar2 = this_ + 0x18;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *pMVar2 = *param_2;
    param_2 = param_2 + 1;
    pMVar2 = pMVar2 + 1;
  }
  *(undefined1 **)(this_ + 8) = (undefined1 *)((*(undefined8 *)0x143b023b0ULL));
  (*(undefined8 *)0x143b023b0ULL) = (undefined8)(this_);
  *(undefined4 *)(this_ + 0x10) = 0x1043;
  *(undefined4 *)(this_ + 0x14) = 0x6100002;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0950
undefined1 *  FUN_141bf0950(undefined1 *this_, undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *pMVar2;
  
  FUN_141122f10((undefined1 *)this_);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffee80ULL));
  pMVar2 = this_ + 0x18;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *pMVar2 = *param_2;
    param_2 = param_2 + 1;
    pMVar2 = pMVar2 + 1;
  }
  *(undefined1 **)(this_ + 8) = (undefined1 *)((*(undefined8 *)0x143b023b0ULL));
  (*(undefined8 *)0x143b023b0ULL) = (undefined8)(this_);
  *(undefined4 *)(this_ + 0x10) = 0x2006;
  *(undefined4 *)(this_ + 0x14) = 0x6100002;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf09d0
undefined1 *  FUN_141bf09d0(undefined1 *this_, undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *pMVar2;
  
  FUN_141122f10((undefined1 *)this_);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffefa0ULL));
  pMVar2 = this_ + 0x18;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *pMVar2 = *param_2;
    param_2 = param_2 + 1;
    pMVar2 = pMVar2 + 1;
  }
  *(undefined1 **)(this_ + 8) = (undefined1 *)((*(undefined8 *)0x143b023b0ULL));
  (*(undefined8 *)0x143b023b0ULL) = (undefined8)(this_);
  *(undefined4 *)(this_ + 0x10) = 0x200b;
  *(undefined4 *)(this_ + 0x14) = 0x6100002;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0a50
undefined1 *  FUN_141bf0a50(undefined1 *this_, undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *pMVar2;
  
  FUN_141122f10((undefined1 *)this_);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffee20ULL));
  pMVar2 = this_ + 0x18;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *pMVar2 = *param_2;
    param_2 = param_2 + 1;
    pMVar2 = pMVar2 + 1;
  }
  *(undefined1 **)(this_ + 8) = (undefined1 *)((*(undefined8 *)0x143b023b0ULL));
  (*(undefined8 *)0x143b023b0ULL) = (undefined8)(this_);
  *(undefined4 *)(this_ + 0x10) = 0x3014;
  *(undefined4 *)(this_ + 0x14) = 0x6100002;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0ad0
undefined1 *  FUN_141bf0ad0(undefined1 *this_, undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *pMVar2;
  
  FUN_141122f10((undefined1 *)this_);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffefc0ULL));
  pMVar2 = this_ + 0x18;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *pMVar2 = *param_2;
    param_2 = param_2 + 1;
    pMVar2 = pMVar2 + 1;
  }
  *(undefined1 **)(this_ + 8) = (undefined1 *)((*(undefined8 *)0x143b023b0ULL));
  (*(undefined8 *)0x143b023b0ULL) = (undefined8)(this_);
  *(undefined4 *)(this_ + 0x10) = 0x3001;
  *(undefined4 *)(this_ + 0x14) = 0x6100002;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0b50
undefined1 *  FUN_141bf0b50(undefined1 *this_, undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *pMVar2;
  
  FUN_141122f10((undefined1 *)this_);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffefe0ULL));
  pMVar2 = this_ + 0x18;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *pMVar2 = *param_2;
    param_2 = param_2 + 1;
    pMVar2 = pMVar2 + 1;
  }
  *(undefined1 **)(this_ + 8) = (undefined1 *)((*(undefined8 *)0x143b023b0ULL));
  (*(undefined8 *)0x143b023b0ULL) = (undefined8)(this_);
  *(undefined4 *)(this_ + 0x10) = 0x3002;
  *(undefined4 *)(this_ + 0x14) = 0x6100002;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0bd0
undefined1 *  FUN_141bf0bd0(undefined1 *this_,undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_28 [24];
  
  puVar2 = local_28;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_141bf08d0((undefined1 *)this_,local_28);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffef40ULL));
  *(undefined4 *)(this_ + 0x10) = 0x202d;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0c30
undefined1 *  FUN_141bf0c30(undefined1 *this_,undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_28 [24];
  
  puVar2 = local_28;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_141bf0950((undefined1 *)this_,local_28);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffeea0ULL));
  *(undefined4 *)(this_ + 0x10) = 0x2006;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0c90
undefined1 *  FUN_141bf0c90(undefined1 *this_,undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_28 [24];
  
  puVar2 = local_28;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_141bf0a50((undefined1 *)this_,local_28);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffee40ULL));
  *(undefined4 *)(this_ + 0x10) = 0x3014;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0cf0
undefined1 *  FUN_141bf0cf0(undefined1 *this_,undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_28 [24];
  
  puVar2 = local_28;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_141bf0c30((undefined1
              *)this_,local_28);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffef00ULL));
  *(undefined4 *)(this_ + 0x10) = 0x2004;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0d50
undefined1 *  FUN_141bf0d50(undefined1 *this_,undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_28 [24];
  
  puVar2 = local_28;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_141bf0c30((undefined1
              *)this_,local_28);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffeec0ULL));
  *(undefined4 *)(this_ + 0x10) = 0x203d;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0db0
undefined1 *  FUN_141bf0db0(undefined1 *this_,undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_28 [24];
  
  puVar2 = local_28;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_141bf0c30((undefined1
              *)this_,local_28);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffeee0ULL));
  *(undefined4 *)(this_ + 0x10) = 0x203e;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0e10
undefined1 *  FUN_141bf0e10(undefined1 *this_,undefined1 *param_2)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_28 [24];
  
  puVar2 = local_28;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_141bf0c90((undefined1
              *)this_,local_28);
  *(undefined ***)this_ = (undefined **)(((undefined1 *)0x142ffee60ULL));
  *(undefined4 *)(this_ + 0x10) = 0x300b;
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0e70
undefined1 * FUN_141bf0e70(undefined1 *param_1)
{
  *param_1 = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0e90
longlong * FUN_141bf0e90(longlong *param_1,longlong *param_2)
{
  *param_1 = *param_2;
  if (*param_1 != 0) {
    FUN_140980460(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0ed0
longlong * FUN_141bf0ed0(longlong *param_1,longlong param_2)
{
  *param_1 = param_2;
  if (*param_1 != 0) {
    FUN_140980460(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0f10
longlong * FUN_141bf0f10(longlong *param_1,longlong *param_2)
{
  *param_1 = *param_2;
  if (*param_1 != 0) {
    FUN_140980460(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0f50
longlong * FUN_141bf0f50(longlong *param_1,longlong param_2)
{
  *param_1 = param_2;
  if (*param_1 != 0) {
    FUN_140980460(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0f90
longlong * FUN_141bf0f90(longlong *param_1,longlong param_2)
{
  *param_1 = param_2;
  if (*param_1 != 0) {
    FUN_140980460(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf0fd0
 longlong * FUN_141bf0fd0(longlong *param_1,longlong param_2)
{
  *param_1 = param_2;
  if (*param_1 != 0) {
    (**(code **)(*(longlong *)*param_1 + 8))(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1020
longlong * FUN_141bf1020(longlong *param_1,longlong param_2)
{
  *param_1 = param_2;
  if (*param_1 != 0) {
    FUN_140980460(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1060
longlong * FUN_141bf1060(longlong *param_1,longlong param_2)
{
  *param_1 = param_2;
  if (*param_1 != 0) {
    FUN_140980460(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf10a0
longlong * FUN_141bf10a0(longlong *param_1,longlong *param_2)
{
  *param_1 = *param_2;
  if (*param_1 != 0) {
    FUN_140ae1dd0(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf10e0
longlong * FUN_141bf10e0(longlong *param_1,longlong *param_2)
{
  *param_1 = *param_2;
  if (*param_1 != 0) {
    (**(code **)(*(longlong *)*param_1 + 8))(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1130
longlong * FUN_141bf1130(longlong *param_1,longlong param_2)
{
  *param_1 = param_2;
  if (*param_1 != 0) {
    FUN_140980460(*param_1);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1170
longlong FUN_141bf1170(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_141c1f4a0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf11b0
longlong FUN_141bf11b0(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_141c1f4a0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf11e0
longlong FUN_141bf11e0(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1200
longlong FUN_141bf1200(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1230
longlong FUN_141bf1230(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_141c1f4d0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1270
longlong FUN_141bf1270(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  FUN_141c1f860(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf12a0
longlong FUN_141bf12a0(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf12c0
longlong FUN_141bf12c0(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf12e0
longlong FUN_141bf12e0(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1300
longlong FUN_141bf1300(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1330
longlong FUN_141bf1330(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_141669140(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1370
longlong FUN_141bf1370(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1390
longlong FUN_141bf1390(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf13c0
longlong FUN_141bf13c0(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_14123f020(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf13f0
longlong FUN_141bf13f0(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1420
longlong FUN_141bf1420(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_141c1f500(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1460
longlong FUN_141bf1460(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_141c1f500(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1490
longlong FUN_141bf1490(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf14b0
longlong FUN_141bf14b0(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf14d0
longlong FUN_141bf14d0(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1500
longlong FUN_141bf1500(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1520
longlong FUN_141bf1520(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_140968bd0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1550
longlong FUN_141bf1550(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1580
longlong FUN_141bf1580(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_140968c00(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf15b0
longlong FUN_141bf15b0(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_141c1f530(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf15f0
longlong FUN_141bf15f0(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_141c1f530(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1620
longlong FUN_141bf1620(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1650
longlong FUN_141bf1650(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1670
longlong FUN_141bf1670(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_141c1f560(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf16a0
longlong FUN_141bf16a0(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_14174a7f0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf16e0
longlong FUN_141bf16e0(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1700
longlong FUN_141bf1700(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1720
longlong FUN_141bf1720(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_141c1f590(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1750
longlong FUN_141bf1750(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1770
longlong FUN_141bf1770(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_140b28610(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf17b0
longlong FUN_141bf17b0(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf17d0
longlong FUN_141bf17d0(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1800
longlong FUN_141bf1800(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_141c1f5c0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1840
longlong FUN_141bf1840(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_141c1f5c0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1870
longlong FUN_141bf1870(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_141375140(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf18b0
longlong FUN_141bf18b0(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf18d0
longlong FUN_141bf18d0(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1900
longlong FUN_141bf1900(longlong param_1,longlong param_2)
{
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  FUN_141c1f5f0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1940
longlong FUN_141bf1940(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1960
longlong FUN_141bf1960(longlong param_1,undefined8 param_2)
{
  *(undefined8 *)(param_1 + 8) = param_2;
  FUN_141c1f5f0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1990
longlong FUN_141bf1990(longlong param_1)
{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf19b0
undefined1 *  FUN_141bf19b0(undefined1 *this_)
{
  return (undefined1 *)((undefined8 (*)(...))0x141bf19b0ULL)(this_);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1a00
undefined1 *  FUN_141bf1a00(undefined1 *this_)
{
  undefined1 *local_18;
  
  (*(undefined8 *)(this_)) = (undefined8)((undefined1 *)((undefined1 *)0x142ffeb88ULL));
  if (this_ == (undefined1 *)0x0) {
    local_18 = (undefined1 *)0x0;
  }
  else {
    local_18 = this_ + -3;
  }
  (*(undefined8 *)0x143aaee10ULL) = (undefined8)(local_18);
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1a50
undefined8 FUN_141bf1a50(undefined8 param_1)
{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined1 local_18;
  
  FUN_141bdb8e0(param_1,local_18);
  uVar1 = FUN_141c1f8d0(param_1);
  puVar2 = (undefined8 *)FUN_141c28930(param_1);
  *puVar2 = uVar1;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1aa0
undefined8 FUN_141bf1aa0(undefined8 param_1)
{
  FUN_141bf1a50(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1ac0
undefined8 FUN_141bf1ac0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf1b40(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1b00
undefined8 FUN_141bf1b00(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf1ac0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1b40
undefined8 * FUN_141bf1b40(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1b80
undefined8 FUN_141bf1b80(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_1415325f0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1bc0
undefined8 FUN_141bf1bc0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf1b40(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1c00
undefined8 * FUN_141bf1c00(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1c30
undefined8 FUN_141bf1c30(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf1e10(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1c60
undefined8 FUN_141bf1c60(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf1e50(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1c90
undefined8 FUN_141bf1c90(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf1e90(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1cc0
undefined8 FUN_141bf1cc0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf1ed0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1cf0
undefined8 FUN_141bf1cf0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf1f10(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1d20
undefined8 FUN_141bf1d20(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf1f50(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1d50
undefined8 FUN_141bf1d50(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf1f90(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1d80
undefined8 FUN_141bf1d80(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf1fd0(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1db0
undefined8 FUN_141bf1db0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf2010(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1de0
undefined8 FUN_141bf1de0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bf2050(param_1,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1e10
undefined8 FUN_141bf1e10(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc260(param_1,local_17,param_2,&local_18);
  FUN_141c215c0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1e50
undefined8 FUN_141bf1e50(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc2b0(param_1,local_17,param_2,&local_18);
  FUN_141c215f0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1e90
undefined8 FUN_141bf1e90(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc300(param_1,local_17,param_2,&local_18);
  FUN_141c21620(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1ed0
undefined8 FUN_141bf1ed0(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc3a0(param_1,local_17,param_2,&local_18);
  FUN_141c21650(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1f10
undefined8 FUN_141bf1f10(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc3f0(param_1,local_17,param_2,&local_18);
  FUN_141c21680(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1f50
undefined8 FUN_141bf1f50(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc440(param_1,local_17,param_2,&local_18);
  FUN_141c216b0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1f90
undefined8 FUN_141bf1f90(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc490(param_1,local_17,param_2,&local_18);
  FUN_141c216e0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf1fd0
undefined8 FUN_141bf1fd0(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc4e0(param_1,local_17,param_2,&local_18);
  FUN_141c21710(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2010
undefined8 FUN_141bf2010(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc530(param_1,local_17,param_2,&local_18);
  FUN_141c21740(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2050
undefined8 FUN_141bf2050(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  undefined1 local_17;
  
  FUN_141bdc350(param_1,local_17,param_2,&local_18);
  FUN_141c21770(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2090
undefined8 FUN_141bf2090(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2610(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf20d0
undefined8 FUN_141bf20d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2650(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2110
undefined8 FUN_141bf2110(undefined8 param_1)
{
  FUN_141bf2690(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2130
undefined8 FUN_141bf2130(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf26b0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2170
undefined8 FUN_141bf2170(undefined8 param_1)
{
  FUN_141bf26f0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2190
undefined8 FUN_141bf2190(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2710(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf21d0
undefined8 FUN_141bf21d0(undefined8 param_1)
{
  FUN_141bf2750(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf21f0
undefined8 FUN_141bf21f0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2770(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2230
undefined8 FUN_141bf2230(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf27b0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2270
undefined8 FUN_141bf2270(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf27f0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf22b0
undefined8 FUN_141bf22b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2830(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf22f0
undefined8 FUN_141bf22f0(undefined8 param_1)
{
  FUN_141bf2870(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2310
undefined8 FUN_141bf2310(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2890(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2350
undefined8 FUN_141bf2350(undefined8 param_1)
{
  FUN_141bf28d0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2370
undefined8 FUN_141bf2370(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf28f0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf23b0
undefined8 FUN_141bf23b0(undefined8 param_1)
{
  FUN_141bf2930(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf23d0
undefined8 FUN_141bf23d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf20d0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2410
undefined8 FUN_141bf2410(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2130(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2450
undefined8 FUN_141bf2450(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2190(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2490
undefined8 FUN_141bf2490(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf21f0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf24d0
undefined8 FUN_141bf24d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2230(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2510
undefined8 FUN_141bf2510(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2270(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2550
undefined8 FUN_141bf2550(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf22b0(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2590
undefined8 FUN_141bf2590(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2310(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf25d0
undefined8 FUN_141bf25d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2370(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2610
undefined8 * FUN_141bf2610(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2650
undefined8 * FUN_141bf2650(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2690
undefined8 * FUN_141bf2690(undefined8 *param_1)
{
  *param_1 = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf26b0
undefined8 * FUN_141bf26b0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf26f0
undefined8 * FUN_141bf26f0(undefined8 *param_1)
{
  *param_1 = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2710
undefined8 * FUN_141bf2710(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2750
undefined8 * FUN_141bf2750(undefined8 *param_1)
{
  *param_1 = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2770
undefined8 * FUN_141bf2770(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf27b0
undefined8 * FUN_141bf27b0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf27f0
undefined8 * FUN_141bf27f0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2830
undefined8 * FUN_141bf2830(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2870
undefined8 * FUN_141bf2870(undefined8 *param_1)
{
  *param_1 = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2890
undefined8 * FUN_141bf2890(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf28d0
undefined8 * FUN_141bf28d0(undefined8 *param_1)
{
  *param_1 = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf28f0
undefined8 * FUN_141bf28f0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2930
undefined8 * FUN_141bf2930(undefined8 *param_1)
{
  *param_1 = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2950
undefined8 * FUN_141bf2950(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2980
undefined8 * FUN_141bf2980(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf29b0
undefined8 * FUN_141bf29b0(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf29e0
undefined8 * FUN_141bf29e0(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2a10
undefined8 * FUN_141bf2a10(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2a40
undefined8 * FUN_141bf2a40(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2a70
undefined8 * FUN_141bf2a70(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2aa0
undefined8 * FUN_141bf2aa0(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2ad0
undefined8 * FUN_141bf2ad0(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2b00
undefined8 * FUN_141bf2b00(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2b30
undefined8 * FUN_141bf2b30(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = param_3;
  return param_1;
}
