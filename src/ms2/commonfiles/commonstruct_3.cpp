// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 3 of commonstruct.cpp: the COMDAT tail 0x14027f2d0-0x140287f50
// (MSVC 14.16 std::_Tree / ATL CAtlArray/CAtlList/CAtlMap/CRBTree internals and scalar deleting destructors of the unit's types).
// Element types are unknown, so the instantiations are written as the free FUN_<va> helpers the callers use (i64 handles).
// MS2-UNIT: commonfiles\commonstruct.cpp#3
// MS2-RANGE: 0x14027f2d0-0x140287f50 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <new>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <intrin.h>
#include <atlcoll.h>
typedef __int64 i64;
typedef unsigned __int64 u64;
typedef unsigned int u32;

// Field access on an i64 base address of an unrecovered node/array/map layout.
#define Q8(p, o) (*(i64*)((i64)(p) + (o)))
#define I4(p, o) (*(int*)((i64)(p) + (o)))
#define U4(p, o) (*(u32*)((i64)(p) + (o)))
#define C1(p, o) (*(char*)((i64)(p) + (o)))
struct Unk_B10 { char b[0x10]; };
struct Unk_B18 { char b[0x18]; };

// ---- callees outside this part (exe-bound by name) ----
__declspec(noreturn) void FUN_140159b70(u32 hr);
i64 FUN_140159860(u64 size, i64 where);   // placement new
i64 FUN_140159c30(i64 head, int n, int elemSize);   // CPlex::Create
i64 FUN_14015b320(i64 plex);   // CPlex::data
void FUN_140159e70(i64 plex);   // CPlex::FreeDataChain
void FUN_14015b020(i64 p);
void FUN_14028b240(i64); void FUN_14028b220(i64);
i64 FUN_140288810(i64); i64 FUN_1402887e0(i64);
void FUN_14027df70(void*); void FUN_14027e060(void*); void FUN_14027e120(void*);
void FUN_14027e180(void*); void FUN_14027e4e0(void*); void FUN_1402677e0(void*); void FUN_14027e510(void*);
void FUN_14027e530(void*); void FUN_14027e590(void*); void FUN_14026fa50(void*); void FUN_14027e5c0(void*);
void FUN_14027e600(void*); void FUN_14026b980(void*); void FUN_14027e620(void*); void FUN_14027e640(void*);
void FUN_14027e670(void*); void FUN_14027e690(void*); void FUN_14027e6b0(void*); void FUN_14027e6d0(void*);
void FUN_14027e6e0(void*); void FUN_140269970(void*); void FUN_14027e720(void*); void FUN_14027e760(void*);
void FUN_14027e7a0(void*); void FUN_1402694a0(void*); void FUN_14027e7c0(void*); void FUN_14027e7e0(void*);
void FUN_14027e800(void*); void FUN_14026c610(void*); void FUN_14027e820(void*); void FUN_14027e870(void*);
void FUN_14027e890(void*); void FUN_14027e8c0(void*); void FUN_14027e8e0(void*); void FUN_14027e920(void*);
void FUN_1402675b0(void*); void FUN_14026e750(void*);
void FUN_14027dd60(i64, i64); void FUN_14027dd20(i64, i64); void FUN_14027e900(i64); void FUN_14027e990(i64, i64);
void FUN_14027dcb0(i64); void FUN_14026dca0(i64); void FUN_14027d8d0(i64); void FUN_14027d940(i64);
void FUN_14027d970(i64, i64); void FUN_14027d9a0(i64, i64); void FUN_14027d9d0(i64, i64);
void FUN_14027d9f0(i64, int, int); void FUN_14027da30(i64, int, int); void FUN_14027da70(i64, i64, i64);
void FUN_1406535b0(i64, i64, i64, int, i64, i64);
i64 FUN_140183290(void*);
u32 FUN_140167190(int*);
char FUN_140165720(i64, int*);
int FUN_140212e20(i64*, i64); char FUN_140212d80(i64*, i64);
i64 FUN_140277470(i64, i64, i64);
void FUN_1401ba320(i64, u64, int);
char FUN_1401b8ac0(i64*, u64);
i64 FUN_140159db0(i64, i64);
// EXT-BEGIN
void FUN_1402774c0(i64, i64, i64);
void FUN_140277510(i64, i64, i64);
i64 FUN_140278630(i64, i64);
i64 FUN_14027b540(i64);
i64 FUN_14027bb80(i64, i64);
i64 FUN_140288150(i64 param_1);
i64 FUN_140288160(i64 param_1);
i64 FUN_140288170(i64 param_1);
i64 FUN_140288180(i64 param_1);
i64* FUN_140288190(i64 param_1);
i64* FUN_1402881a0(i64 param_1);
i64 FUN_1402881b0(i64 param_1);
i64 FUN_1402881c0(i64 param_1);
i64 FUN_140288250(i64 param_1);
i64 FUN_140288290(i64 param_1);
i64 FUN_1402882f0(i64 param_1);
i64 FUN_140288330(i64 param_1);
i64 FUN_140288370(i64 param_1);
i64 FUN_1402883b0(i64 param_1);
i64 FUN_1402883f0(i64 param_1);
i64 FUN_140288450(i64 param_1);
i64* FUN_140288630(i64 param_1);
void FUN_140288640(i64 param_1, i64 param_2);
i64* FUN_140288840(i64 param_1);
i64* FUN_140288880(i64 param_1);
i64* FUN_1402888c0(i64 param_1);
i64* FUN_140288900(i64 param_1);
i64* FUN_140288940(i64 param_1);
i64* FUN_140288980(i64 param_1);
i64* FUN_1402889c0(i64 param_1);
i64* FUN_140288a00(i64 param_1);
i64* FUN_140288a40(i64 param_1);
i64* FUN_140288a80(i64 param_1);
i64* FUN_140288ae0(i64 param_1);
i64* FUN_140288b20(i64 param_1);
i64* FUN_140288b60(i64 param_1);
i64* FUN_140288ba0(i64 param_1);
i64* FUN_140288be0(i64 param_1);
i64 FUN_140288c80(i64 param_1);
i64 FUN_140288ca0(i64 param_1);
i64 FUN_140288cc0(i64 param_1);
void FUN_140288e10(i64 param_1);
i64* FUN_1402894a0(i64 param_1);
i64* FUN_1402894c0(i64 param_1);
void FUN_1402894e0(i64 param_1, i64 param_2);
void FUN_140289ea0(void);
void FUN_140289f20(void);
i64 FUN_140289f60(i64 param_1, u64 param_2);
i64 FUN_140289f90(i64 param_1, u64 param_2);
i64 FUN_140289fc0(i64 param_1, i64 param_2);
i64 FUN_14028a080(i64 param_1, u64 param_2);
i64 FUN_14028a2c0(i64 param_1);
i64 FUN_14028a300(i64 param_1);
i64 FUN_14028a350(i64 param_1);
i64 FUN_14028a390(i64 param_1);
i64 FUN_14028a3d0(i64 param_1);
void FUN_14028a800(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a830(i64 param_1, i64 param_2, i64 param_3);
void FUN_14028a860(i64 param_1, i64 param_2, i64 param_3);
u64 FUN_14028b090(i64 param_1);
u64 FUN_14028b0e0(i64 param_1);
u64 FUN_14028b130(i64 param_1);
u64 FUN_14028b180(i64 param_1);
u64 FUN_14028b1d0(i64 param_1);
void FUN_140163110(char*, char*);
i64 FUN_1401ba820(i64);
i64 FUN_140276880(int);
void FUN_140277560(i64, i64, i64);
void FUN_1402775b0(i64, i64, i64);
void FUN_1402785c0(i64, i64);
void FUN_14027a4a0(i64, i64);
void FUN_14027a4e0(i64, i64);
i64 FUN_14027b520(i64);
i64 FUN_14027b530(i64);
i64 FUN_14027b550(i64);
void FUN_14027b6f0(i64, i64, i64*);
void FUN_14027b740(i64, i64, i64*);
void FUN_14027bc00(i64, i64);
i64 FUN_14027f280(i64);
// EXT-END
extern int DAT_143aacd90; extern int DAT_143ab05ac; extern int DAT_143ab05b0; extern char DAT_143ab05a8;
extern const u32 DAT_142ce52b0[];

// ---- functions of this part (forward declarations) ----
i64 FUN_14027f2d0(i64 p);
i64 FUN_14027f2e0(i64 p);
i64 FUN_14027f2f0(i64 p);
i64 FUN_14027f300(i64 p);
i64 FUN_14027f310(i64 p);
i64 FUN_14027f320(i64 p);
i64 FUN_14027f330(i64 p);
i64 FUN_14027f340(i64 p);
void FUN_14027f350(i64* p);
void FUN_14027f370(i64* p);
i64 FUN_14027f390(i64* p);
void FUN_14027f3b0(i64* p);
i64 FUN_14027f3d0(i64* p);
void FUN_14027f3f0(i64* p);
i64 FUN_14027f410(i64* p);
i64 FUN_14027f430(i64* p);
i64 FUN_14027f450(i64* p);
i64 FUN_14027f460(i64* p);
void FUN_14027f470(i64* p);
void FUN_14027f490(i64* p);
void FUN_14027f4b0(i64* p);
i64* FUN_14027f4e0(i64* p, i64* out);
i64* FUN_14027f530(i64* p);
i64* FUN_14027f550(i64* p);
i64* FUN_14027f570(i64* p);
i64* FUN_14027f590(i64* p);
i64* FUN_14027f5b0(i64* p, i64* out);
i64* FUN_14027f600(i64* p);
i64* FUN_14027f620(i64* p);
i64* FUN_14027f6b0(i64* p);
i64* FUN_14027f6d0(i64* p);
i64* FUN_14027f700(i64* p);
i64* FUN_14027f720(i64* p);
i64* FUN_14027f740(i64* p);
i64* FUN_14027f760(i64* p);
i64* FUN_14027f830(i64* p);
i64* FUN_14027f850(i64* p);
bool FUN_14027f870(i64, int* a, int* b);
void* FUN_14027f8b0(void* p, u32 f);
void* FUN_14027f8f0(void* p, u32 f);
void* FUN_14027f930(void* p, u32 f);
void* FUN_14027f970(void* p, u32 f);
void* FUN_14027f9b0(void* p, u32 f);
void* FUN_14027f9f0(void* p, u32 f);
void* FUN_14027fa30(void* p, u32 f);
void* FUN_14027fa70(void* p, u32 f);
void* FUN_14027fab0(void* p, u32 f);
void* FUN_14027faf0(void* p, u32 f);
void* FUN_14027fb30(void* p, u32 f);
void* FUN_14027fb70(void* p, u32 f);
void* FUN_14027fbb0(void* p, u32 f);
void* FUN_14027fbf0(void* p, u32 f);
void* FUN_14027fc30(void* p, u32 f);
void* FUN_14027fc70(void* p, u32 f);
void* FUN_14027fcb0(void* p, u32 f);
void* FUN_14027fcf0(void* p, u32 f);
void* FUN_14027fd30(void* p, u32 f);
void* FUN_14027fd70(void* p, u32 f);
void* FUN_14027fdb0(void* p, u32 f);
void* FUN_14027fdf0(void* p, u32 f);
void* FUN_14027fe30(void* p, u32 f);
void* FUN_14027fe70(void* p, u32 f);
void* FUN_14027feb0(void* p, u32 f);
void* FUN_14027fef0(void* p, u32 f);
void* FUN_14027ff30(void* p, u32 f);
void* FUN_14027ff70(void* p, u32 f);
void* FUN_14027ffb0(void* p, u32 f);
void* FUN_14027fff0(void* p, u32 f);
void* FUN_140280030(void* p, u32 f);
void* FUN_140280070(void* p, u32 f);
void* FUN_1402800b0(void* p, u32 f);
void* FUN_1402800f0(void* p, u32 f);
void* FUN_140280130(void* p, u32 f);
void* FUN_140280170(void* p, u32 f);
void* FUN_1402801b0(void* p, u32 f);
u64 FUN_1402801f0(i64* a, i64 e);
u64 FUN_1402802a0(i64* a, Unk_B18* e);
u64 FUN_140280350(i64* a, Unk_B10* e);
u64 FUN_140280400(i64* a, i64 e);
void FUN_1402804b0(i64 p, int v);
void FUN_1402804e0(i64 a, i64 b, i64 c, int d, i64 e);
i64 FUN_140280530(i64* l, i64 e);
i64 FUN_1402805b0(i64* l, i64 e);
i64 FUN_140280630(i64* l, int* e);
void FUN_1402806b0(i64 l, i64 src);
i64 FUN_140280740(i64 p);
void FUN_140280770(i64 base, u64 n);
void FUN_1402807f0(i64 base, u64 n);
void FUN_140280870(i64 base, u64 n);
void FUN_1402808f0(i64 base, u64 n);
void FUN_140280970(void** p, u64 n);
void FUN_1402809b0(void** p, u64 n);
void FUN_1402809f0(void** p, u64 n);
void FUN_140280a30(void** p, u64 n);
void FUN_140280a70(i64* a, i64* src);
void FUN_140280ae0(i64* a, i64* src);
void FUN_140280b50(i64 dst, i64 src, u64 n);
void FUN_140280bc0(i64 dst, i64 src, u64 n);
i64 FUN_140280c30(i64* m, int key, u32 bin, int hash);
i64 FUN_140280cb0(i64* m, int key, u32 bin, int hash);
void FUN_140280d30(i64 m);
void FUN_140280d50(i64 m);
void FUN_140280d70(i64 m);
void FUN_140280d90(i64 m);
i64 FUN_140280db0(i64* t, i64 key);
i64 FUN_140280ea0(i64* m, i64 node);
i64 FUN_140280f60(i64* m, i64 node);
void FUN_140281020(i64 l, i64* n);
void FUN_140281090(i64 l, i64* n);
void FUN_140281100(i64 l, i64* n);
void FUN_140281170(i64 m, i64 n);
void FUN_140281260(i64 m, i64 n);
void FUN_140281350(i64 t, i64 n);
void FUN_1402813f0(i64 m);
void FUN_140281440(i64 m);
i64 FUN_140281490(i64 p);
i64 FUN_1402814d0(i64, i64 n);
i64 FUN_140281540(i64, i64 n);
i64 FUN_1402815b0(i64 p);
i64 FUN_1402815c0(i64 p);
i64 FUN_1402815d0(i64 p);
i64 FUN_1402815e0(i64 p);
i64 FUN_1402815f0(i64 p);
i64 FUN_140281600(i64 p);
void FUN_140281610(i64 l);
void FUN_1402816f0(i64 l);
void FUN_1402817d0(i64 l);
u32 FUN_1402818b0(i64 n);
u32 FUN_1402818c0(i64 n);
i64 FUN_1402818d0(i64* p);
i64 FUN_140281930(i64* p);
i64 FUN_140281940(i64* p);
i64 FUN_140281950(i64* p);
void FUN_140281960(i64* p);
i64 FUN_140281980(void);
i64 FUN_140281990(i64, i64 n);
i64 FUN_140281a00(i64, i64 n);
i64* FUN_140281a70(i64, i64* pos);
i64* FUN_140281af0(i64, i64* pos);
i64* FUN_140281b70(i64, i64* pos);
i64 FUN_140281bf0(i64 c, i64* pos);
i64 FUN_140281c40(i64 c, i64* pos);
i64 FUN_140281c90(i64 c, i64* pos);
i64 FUN_140281ce0(i64 c, i64* pos);
i64 FUN_140281d20(i64* m, int key, u32* pBin, u32* pHash, i64* pPrev);
i64 FUN_140281e10(i64* m, int key, u32* pBin, u32* pHash, i64* pPrev);
i64 FUN_140281f00(i64 p);
i64 FUN_140281f10(i64 p);
i64 FUN_140281f20(void);
i64 FUN_140281f40(i64* m);
i64 FUN_140281fb0(i64* m);
void FUN_140282020(i64* t);
i64 FUN_140282070(i64* t);
i64 FUN_1402820c0(i64, i64 n);
i64 FUN_140282130(i64, i64 n);
i64 FUN_1402821a0(i64, i64 n);
i64 FUN_140282210(i64, i64 n);
char FUN_140282270(i64* a, u64 want);
char FUN_140282410(i64* a, u64 want);
char FUN_1402825b0(i64* a, u64 want);
char FUN_140282750(i64* a, u64 want);
char FUN_1402828f0(i64* a, u64 want);
char FUN_140282a90(i64* m, u32 nBins, char bAllocNow);
char FUN_140282bb0(i64* m, u32 nBins, char bAllocNow);
i64 FUN_140282cd0(i64* t, i64 key, i64 val);
bool FUN_140282dd0(i64 p);
bool FUN_140282e00(i64 p);
bool FUN_140282e30(i64 p);
bool FUN_140282e60(i64 p);
bool FUN_140282e90(i64 p);
bool FUN_140282ec0(i64* t, i64 n);
i64 FUN_140282f00(i64* t, i64 node);
char FUN_140283010(i64* m, int key);
bool FUN_140283050(i64* t, i64 key, i64 out);
i64 FUN_1402830a0(i64* t, i64 n);
i64 FUN_140283110(i64* t, i64 n);
i64* FUN_140283180(i64 l, i64 e, i64 prev, i64 next);
i64* FUN_140283240(i64 l, i64 e, i64 prev, i64 next);
i64* FUN_140283300(i64 l, i64 e, i64 prev, i64 next);
i64 FUN_1402833c0(i64* m, int key, u32 iBin, int hash);
i64 FUN_1402835d0(i64* m, int key, u32 iBin, int hash);
i64 FUN_1402837e0(i64* t, i64 key, i64 val);
u32 FUN_140283a40(i64 m, u64 nElements);
u32 FUN_140283b30(i64 m, u64 nElements);
i64 FUN_140283c20(i64* t, i64 n);
bool FUN_140283cf0(i64* t, i64 node);
void FUN_140283ea0(i64* t, i64 x);
i64 FUN_1402841d0(i64* t, i64 key, i64 val);
void FUN_140284450(i64* m, u32 nBins);
void FUN_140284680(i64* m, u32 nBins);
void FUN_1402848b0(void* dst, void* src, i64 n);
void FUN_1402848f0(void* dst, void* src, i64 n);
void FUN_140284930(void* dst, void* src, i64 n);
void FUN_140284970(void* dst, void* src, i64 n);
void FUN_1402849b0(void* dst, void* src, i64 n);
void FUN_1402849f0(i64* a);
void FUN_140284a10(i64* a);
void FUN_140284a30(i64* a);
void FUN_140284a50(i64* l);
void FUN_140284b30(i64* l);
void FUN_140284c10(i64* l);
void FUN_140284cf0(i64* m);
void FUN_140284e00(i64* m);
void FUN_140284f10(i64* t);
void FUN_140284f90(i64* l, i64* pos);
void FUN_140285070(i64* t, i64 n);
void FUN_1402850a0(i64* m, i64 node);
void FUN_140285190(i64* m, i64 node);
i64 FUN_140285280(i64* l, i64 out);
void FUN_140285380(i64* l);
void FUN_140285430(i64* m, i64 node, i64 prev);
void FUN_1402854f0(i64* m, i64 node, i64 prev);
void FUN_1402855b0(i64* t, i64 n);
i64 FUN_140285610(i64* t, i64 node);
i64 FUN_140285720(i64* m, int key, int val);
i64 FUN_1402857b0(i64* m, int key, int* val);
i64 FUN_140285850(i64* t, i64 key, i64 val);
char FUN_1402858c0(i64* a, u64 n, int grow);
char FUN_140285a50(i64* a, u64 n, int grow);
char FUN_140285be0(i64* a, u64 n, int grow);
char FUN_140285d70(i64* a, u64 n, int grow);
void FUN_140285f00(i64* t, i64* p);
void FUN_140285f70(i64 m, float opt, float lo, float hi, char rehash);
void FUN_140286020(i64 m, float opt, float lo, float hi, char rehash);
i64 FUN_1402860d0(i64* t, i64 n);
void FUN_1402861a0(i64* t, i64 dst, i64 src);
void FUN_140286300(i64 m);
void FUN_1402863e0(i64 m);
void FUN_1402864c0(i64 p);
void FUN_1402864f0(i64 p);
void FUN_140286520(i64 p);
void FUN_140286550(i64 p);
void FUN_140286580(i64 p);
void FUN_1402865b0(i64 p);
void FUN_1402865e0(i64 p);
void FUN_140286610(i64 p);
void FUN_140286640(i64 p);
void FUN_140286670(i64 p);
void FUN_1402866a0(i64 p);
void FUN_1402866c0(i64 p);
void FUN_1402866e0(i64 p);
void FUN_140286700(i64 p);
void FUN_140286720(i64 p);
void FUN_140286740(i64 p);
void FUN_140286760(i64 p);
void FUN_140286780(i64 p);
void FUN_1402867a0(i64 p);
void FUN_1402867c0(i64 p);
void FUN_1402867e0(i64 p);
void FUN_140286800(i64 p);
void FUN_140286820(i64 p, int);
void FUN_140286850(i64 p, int);
void FUN_140286880(i64 p, int);
void FUN_1402868b0(i64 p, int);
void FUN_1402868e0(i64 p, int);
void FUN_140286910(i64 p, int);
void FUN_140286940(i64 p, int);
void FUN_140286970(i64 p, int);
void FUN_1402869a0(i64 p, int);
void FUN_1402869d0(i64 p, int);
void FUN_140286a00(i64 p);
i64 FUN_140286a30(i64 self);
u64 FUN_140286a60(i64 v, u64 n);
u64 FUN_140286b50(i64 v, u64 n);
void FUN_140286c40(i64 p);
i64 FUN_140286c60(i64 self);
i64 FUN_140286d20(i64 self, i64 left, i64 right);
i64 FUN_140286de0(i64 self);
u64 FUN_140286ec0(i64 v, u64 want);
u64 FUN_140286f50(i64 v, u64 want);
u64 FUN_140286fe0(i64 v, u64 want);
u64 FUN_140287070(i64 v, u64 want);
u64 FUN_140287100(i64 v, u64 want);
void FUN_140287190(i64 v, i64 newvec, i64 newsize, i64 newcap);
void FUN_1402872a0(i64 v, i64 newvec, i64 newsize, i64 newcap);
void FUN_1402873b0(i64 v, i64 newvec, i64 newsize, i64 newcap);
void FUN_1402874c0(i64 self, int* a, int* b);
void FUN_140287500(void);
void FUN_140287510(void);
void FUN_140287520(i64 self);
void FUN_140287550(i64 self, i64 other);
void FUN_140287580(i64 self, i64 other);
void FUN_1402875b0(i64 self, i64 first, i64 last);
void FUN_1402875f0(i64 self, i64 first, i64 last);
void FUN_140287630(i64 self, i64 first, i64 last);
void FUN_140287670(i64 self, i64 first, i64 last);
void FUN_1402876b0(i64 self, i64 first, i64 last);
void FUN_1402876f0(i64 self, i64 node);
void FUN_140287740(i64 self, i64* root);
i64* FUN_1402877e0(i64 self, i64* where);
void FUN_140287d90(i64 self, i64 p);
void FUN_140287dc0(i64 self, i64 p);
void FUN_140287df0(i64 self, i64 p);
void FUN_140287e20(i64 self, i64 node);
void FUN_140287e70(i64 p);
void FUN_140287e90(i64 p);
i64* FUN_140287eb0(i64 p);
i64* FUN_140287ee0(i64 p);
void FUN_140287f10(i64 p);
void FUN_140287f30(i64 p);

// @0x14027f2d0
i64 FUN_14027f2d0(i64 p) { return Q8(p, 8); }
// @0x14027f2e0
i64 FUN_14027f2e0(i64 p) { return Q8(p, 8); }
// @0x14027f2f0
i64 FUN_14027f2f0(i64 p) { return Q8(p, 8); }
// @0x14027f300
i64 FUN_14027f300(i64 p) { return Q8(p, 8); }
// @0x14027f310
i64 FUN_14027f310(i64 p) { return Q8(p, 8); }
// @0x14027f320
i64 FUN_14027f320(i64 p) { return Q8(p, 8); }
// @0x14027f330
i64 FUN_14027f330(i64 p) { return Q8(p, 8); }
// @0x14027f340
i64 FUN_14027f340(i64 p) { return Q8(p, 8); }
// @0x14027f350
void FUN_14027f350(i64* p) { FUN_14028b240(FUN_14027f410(p)); }
// @0x14027f370
void FUN_14027f370(i64* p) { FUN_14028b220(FUN_14027f430(p)); }
// @0x14027f390
i64 FUN_14027f390(i64* p) { return *p + 0x10; }
// @0x14027f3b0
void FUN_14027f3b0(i64* p) { FUN_14027f390(p); }
// @0x14027f3d0
i64 FUN_14027f3d0(i64* p) { return *p + 0x10; }
// @0x14027f3f0
void FUN_14027f3f0(i64* p) { FUN_14027f3d0(p); }
// @0x14027f410
i64 FUN_14027f410(i64* p) { return *p + 0x1c; }
// @0x14027f430
i64 FUN_14027f430(i64* p) { return FUN_14027f410(p); }
// @0x14027f450
i64 FUN_14027f450(i64* p) { return *p; }
// @0x14027f460
i64 FUN_14027f460(i64* p) { return *p; }
// @0x14027f470
void FUN_14027f470(i64* p) { FUN_14027f450(p); }
// @0x14027f490
void FUN_14027f490(i64* p) { FUN_14027f460(p); }
// @0x14027f4b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_14027f4b0(i64* p)
{
    i64 it[3];
    it[0] = *p;
    i64* r = FUN_14027f850(it);
    FUN_14027f470(r);
}
// @0x14027f4e0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_14027f4e0(i64* p, i64* out)
{
    i64 old = *p;
    FUN_14027f530(p);
    *out = old;
    return out;
}
// @0x14027f530
i64* FUN_14027f530(i64* p) { *p = Q8(*p, 0); return p; }
// @0x14027f550
i64* FUN_14027f550(i64* p) { FUN_14027f530(p); return p; }
// @0x14027f570
i64* FUN_14027f570(i64* p) { *p = Q8(*p, 0); return p; }
// @0x14027f590
i64* FUN_14027f590(i64* p) { FUN_14027f570(p); return p; }
// @0x14027f5b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_14027f5b0(i64* p, i64* out)
{
    i64 old = *p;
    FUN_14027f600(p);
    *out = old;
    return out;
}
// @0x14027f600
i64* FUN_14027f600(i64* p) { FUN_14027f620(p); return p; }
// std::_Tree_unchecked_const_iterator::operator++
// @0x14027f620
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_14027f620(i64* p)
{
    if (C1(Q8(*p, 0x10), 0x19) == 0) {
        *p = FUN_140288810(Q8(*p, 0x10));
    } else {
        i64 n;
        while (n = Q8(*p, 8), C1(n, 0x19) == 0 && *p == Q8(n, 0x10))
            *p = n;
        *p = n;
    }
    return p;
}
// @0x14027f6b0
i64* FUN_14027f6b0(i64* p) { *p = *p + 0x30; return p; }
// @0x14027f6d0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_14027f6d0(i64* p) { *p = Q8(*p, 8); return p; }
// @0x14027f700
i64* FUN_14027f700(i64* p) { FUN_14027f6d0(p); return p; }
// @0x14027f720
i64* FUN_14027f720(i64* p) { FUN_14027f760(p); return p; }
// @0x14027f740
i64* FUN_14027f740(i64* p) { FUN_14027f720(p); return p; }
// std::_Tree_unchecked_const_iterator::operator--
// @0x14027f760
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_14027f760(i64* p)
{
    if (C1(*p, 0x19) == 0) {
        if (C1(Q8(*p, 0), 0x19) == 0) {
            *p = FUN_1402887e0(Q8(*p, 0));
        } else {
            i64 n;
            while (n = Q8(*p, 8), C1(n, 0x19) == 0 && *p == Q8(n, 0))
                *p = n;
            if (C1(*p, 0x19) == 0)
                *p = n;
        }
    } else {
        *p = Q8(*p, 0x10);
    }
    return p;
}
// @0x14027f830
i64* FUN_14027f830(i64* p) { *p = *p - 0x30; return p; }
// @0x14027f850
i64* FUN_14027f850(i64* p) { FUN_14027f830(p); return p; }
// std::less<int>::operator()
// @0x14027f870
bool FUN_14027f870(i64, int* a, int* b) { return *a < *b; }

// scalar deleting destructors of the unit's header-inline types: dtor, then operator delete(this, sizeof)
// @0x14027f8b0
void* FUN_14027f8b0(void* p, u32 f) { FUN_14027df70(p); if ((f & 1) != 0) operator delete(p, 0x10); return p; }
// @0x14027f8f0
void* FUN_14027f8f0(void* p, u32 f) { FUN_14027e060(p); if ((f & 1) != 0) operator delete(p, 0x10); return p; }
// @0x14027f930
void* FUN_14027f930(void* p, u32 f) { FUN_14027e120(p); if ((f & 1) != 0) operator delete(p, 0x10); return p; }
// @0x14027f970
void* FUN_14027f970(void* p, u32 f) { FUN_14027e180(p); if ((f & 1) != 0) operator delete(p, 0x48); return p; }
// @0x14027f9b0
void* FUN_14027f9b0(void* p, u32 f) { FUN_14027e4e0(p); if ((f & 1) != 0) operator delete(p, 0x48); return p; }
// @0x14027f9f0
void* FUN_14027f9f0(void* p, u32 f) { FUN_1402677e0(p); if ((f & 1) != 0) operator delete(p, 0x78); return p; }
// @0x14027fa30
void* FUN_14027fa30(void* p, u32 f) { FUN_14027e510(p); if ((f & 1) != 0) operator delete(p, 0x20); return p; }
// @0x14027fa70
void* FUN_14027fa70(void* p, u32 f) { FUN_14027e530(p); if ((f & 1) != 0) operator delete(p, 0x88); return p; }
// @0x14027fab0
void* FUN_14027fab0(void* p, u32 f) { FUN_14027e590(p); if ((f & 1) != 0) operator delete(p, 0x48); return p; }
// @0x14027faf0
void* FUN_14027faf0(void* p, u32 f) { FUN_14026fa50(p); if ((f & 1) != 0) operator delete(p, 0x68); return p; }
// @0x14027fb30
void* FUN_14027fb30(void* p, u32 f) { FUN_14027e5c0(p); if ((f & 1) != 0) operator delete(p, 0x50); return p; }
// @0x14027fb70
void* FUN_14027fb70(void* p, u32 f) { FUN_14027e600(p); if ((f & 1) != 0) operator delete(p, 0x40); return p; }
// @0x14027fbb0
void* FUN_14027fbb0(void* p, u32 f) { FUN_14026b980(p); if ((f & 1) != 0) operator delete(p, 0x30); return p; }
// @0x14027fbf0
void* FUN_14027fbf0(void* p, u32 f) { FUN_14027e620(p); if ((f & 1) != 0) operator delete(p, 0x28); return p; }
// @0x14027fc30
void* FUN_14027fc30(void* p, u32 f) { FUN_14027e640(p); if ((f & 1) != 0) operator delete(p, 0x58); return p; }
// @0x14027fc70
void* FUN_14027fc70(void* p, u32 f) { FUN_14027e670(p); if ((f & 1) != 0) operator delete(p, 0x20); return p; }
// @0x14027fcb0
void* FUN_14027fcb0(void* p, u32 f) { FUN_14027e690(p); if ((f & 1) != 0) operator delete(p, 0x28); return p; }
// @0x14027fcf0
void* FUN_14027fcf0(void* p, u32 f) { FUN_14027e6b0(p); if ((f & 1) != 0) operator delete(p, 0x20); return p; }
// @0x14027fd30
void* FUN_14027fd30(void* p, u32 f) { FUN_14027e6d0(p); if ((f & 1) != 0) operator delete(p, 0x18); return p; }
// @0x14027fd70
void* FUN_14027fd70(void* p, u32 f) { FUN_14027e6e0(p); if ((f & 1) != 0) operator delete(p, 0x38); return p; }
// @0x14027fdb0
void* FUN_14027fdb0(void* p, u32 f) { FUN_140269970(p); if ((f & 1) != 0) operator delete(p, 0x80); return p; }
// @0x14027fdf0
void* FUN_14027fdf0(void* p, u32 f) { FUN_14027e720(p); if ((f & 1) != 0) operator delete(p, 0x70); return p; }
// @0x14027fe30
void* FUN_14027fe30(void* p, u32 f) { FUN_14027e760(p); if ((f & 1) != 0) operator delete(p, 0x38); return p; }
// @0x14027fe70
void* FUN_14027fe70(void* p, u32 f) { FUN_14027e7a0(p); if ((f & 1) != 0) operator delete(p, 0x50); return p; }
// @0x14027feb0
void* FUN_14027feb0(void* p, u32 f) { FUN_1402694a0(p); if ((f & 1) != 0) operator delete(p, 0x50); return p; }
// @0x14027fef0
void* FUN_14027fef0(void* p, u32 f) { FUN_14027e7c0(p); if ((f & 1) != 0) operator delete(p, 0x50); return p; }
// @0x14027ff30
void* FUN_14027ff30(void* p, u32 f) { FUN_14027e7e0(p); if ((f & 1) != 0) operator delete(p, 0x60); return p; }
// @0x14027ff70
void* FUN_14027ff70(void* p, u32 f) { FUN_14027e800(p); if ((f & 1) != 0) operator delete(p, 0x178); return p; }
// @0x14027ffb0
void* FUN_14027ffb0(void* p, u32 f) { FUN_14026c610(p); if ((f & 1) != 0) operator delete(p, 0x40); return p; }
// @0x14027fff0
void* FUN_14027fff0(void* p, u32 f) { FUN_14027e820(p); if ((f & 1) != 0) operator delete(p, 0x58); return p; }
// @0x140280030
void* FUN_140280030(void* p, u32 f) { FUN_14027e870(p); if ((f & 1) != 0) operator delete(p, 0x28); return p; }
// @0x140280070
void* FUN_140280070(void* p, u32 f) { FUN_14027e890(p); if ((f & 1) != 0) operator delete(p, 0x38); return p; }
// @0x1402800b0
void* FUN_1402800b0(void* p, u32 f) { FUN_14027e8c0(p); if ((f & 1) != 0) operator delete(p, 0x30); return p; }
// @0x1402800f0
void* FUN_1402800f0(void* p, u32 f) { FUN_14027e8e0(p); if ((f & 1) != 0) operator delete(p, 0x38); return p; }
// @0x140280130
void* FUN_140280130(void* p, u32 f) { FUN_14027e920(p); if ((f & 1) != 0) operator delete(p, 0x40); return p; }
// @0x140280170
void* FUN_140280170(void* p, u32 f) { FUN_1402675b0(p); if ((f & 1) != 0) operator delete(p, 0x80); return p; }
// @0x1402801b0
void* FUN_1402801b0(void* p, u32 f) { FUN_14026e750(p); if ((f & 1) != 0) operator delete(p, 0x40); return p; }

// CAtlArray<T>::Add(const T&) of a 0x18-byte type with a copy constructor
// @0x1402801f0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
u64 FUN_1402801f0(i64* a, i64 e)
{
    u64 idx = a[1];
    if ((u64)a[2] <= idx) {
        char ok = FUN_140282410(a, idx + 1);
        if (ok == 0)
            FUN_140159b70(0x8007000e);
    }
    i64 slot = FUN_140159860(0x18, idx * 0x18 + a[0]);
    FUN_14027dd60(slot, e);
    a[1] = a[1] + 1;
    return idx;
}
// CAtlArray<T>::Add(const T&) of POD types
// @0x1402802a0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
u64 FUN_1402802a0(i64* a, Unk_B18* e)
{
    u64 idx = a[1];
    if ((u64)a[2] <= idx) {
        char ok = FUN_140282750(a, idx + 1);
        if (ok == 0)
            FUN_140159b70(0x8007000e);
    }
    Unk_B18* slot = (Unk_B18*)FUN_140159860(0x18, idx * 0x18 + a[0]);
    *slot = *e;
    a[1] = a[1] + 1;
    return idx;
}
// @0x140280350
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
u64 FUN_140280350(i64* a, Unk_B10* e)
{
    u64 idx = a[1];
    if ((u64)a[2] <= idx) {
        char ok = FUN_1402828f0(a, idx + 1);
        if (ok == 0)
            FUN_140159b70(0x8007000e);
    }
    Unk_B10* slot = (Unk_B10*)FUN_140159860(0x10, idx * 0x10 + a[0]);
    *slot = *e;
    a[1] = a[1] + 1;
    return idx;
}
// @0x140280400
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
u64 FUN_140280400(i64* a, i64 e)
{
    u64 idx = a[1];
    if ((u64)a[2] <= idx) {
        char ok = FUN_1401b8ac0(a, idx + 1);
        if (ok == 0)
            FUN_140159b70(0x8007000e);
    }
    i64* slot = (i64*)FUN_140159860(8, *a + idx * 8);
    *slot = e;
    a[1] = a[1] + 1;
    return idx;
}
// @0x1402804b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402804b0(i64 p, int v)
{
    int a[6];
    a[0] = v;
    FUN_140280630((i64*)(p + 0x18), a);
}
// @0x1402804e0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402804e0(i64 a, i64 b, i64 c, int d, i64 e)
{
    char tmp[24];
    i64 r = FUN_140183290(tmp);
    FUN_1406535b0(a, b, c, d, e, r);
}
// CAtlList<T>::AddTail(const T&) -- one per element type
// @0x140280530
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140280530(i64* l, i64 e)
{
    i64* n = FUN_140283180((i64)l, (i64)e, l[1], 0);
    if (l[1] == 0)
        *l = (i64)n;
    else
        Q8(l[1], 0) = (i64)n;
    l[1] = (i64)n;
    return (i64)n;
}
// @0x1402805b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402805b0(i64* l, i64 e)
{
    i64* n = FUN_140283240((i64)l, (i64)e, l[1], 0);
    if (l[1] == 0)
        *l = (i64)n;
    else
        Q8(l[1], 0) = (i64)n;
    l[1] = (i64)n;
    return (i64)n;
}
// @0x140280630
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140280630(i64* l, int* e)
{
    i64* n = FUN_140283300((i64)l, (i64)e, l[1], 0);
    if (l[1] == 0)
        *l = (i64)n;
    else
        Q8(l[1], 0) = (i64)n;
    l[1] = (i64)n;
    return (i64)n;
}
// CAtlList<T>::AddTailList(const CAtlList*)
// @0x1402806b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402806b0(i64 l, i64 src)
{
    if (src != 0) {
        i64 pos = FUN_140281950((i64*)src);
        while (pos != 0) {
            i64* e = FUN_140281b70(src, &pos);
            FUN_140280630((i64*)l, (int*)e);
        }
        return;
    }
    FUN_140159b70(0x80004005);
}
// @0x140280740
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140280740(i64 p) { FUN_140286a00(p); return p; }
// CAtlArray<T>::SetCount helper: default-construct n elements of 0x10/0x18 bytes
// @0x140280770
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140280770(i64 base, u64 n)
{
    for (u64 i = 0; i < n; i++) {
        i64 s = FUN_140159860(0x10, base + i * 0x10);
        FUN_14027dcb0(s);
    }
}
// @0x1402807f0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402807f0(i64 base, u64 n)
{
    for (u64 i = 0; i < n; i++) {
        i64 s = FUN_140159860(0x10, base + i * 0x10);
        FUN_14026dca0(s);
    }
}
// @0x140280870
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140280870(i64 base, u64 n)
{
    for (u64 i = 0; i < n; i++) {
        i64 s = FUN_140159860(0x18, base + i * 0x18);
        FUN_14027d8d0(s);
    }
}
// @0x1402808f0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402808f0(i64 base, u64 n)
{
    for (u64 i = 0; i < n; i++) {
        i64 s = FUN_140159860(0x10, base + i * 0x10);
        FUN_14027d940(s);
    }
}
// ATL::CAtlArray<void*>::CallDestructors (POD elements: the destructor loop is empty)
// @0x140280970
void FUN_140280970(void** p, u64 n) { for (u64 i = 0; i < n; i++) {} }
// @0x1402809b0
void FUN_1402809b0(void** p, u64 n) { for (u64 i = 0; i < n; i++) {} }
// @0x1402809f0
void FUN_1402809f0(void** p, u64 n) { for (u64 i = 0; i < n; i++) {} }
// @0x140280a30
void FUN_140280a30(void** p, u64 n) { for (u64 i = 0; i < n; i++) {} }
// CAtlArray<T>::Copy(const CAtlArray&)
// @0x140280a70
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140280a70(i64* a, i64* src)
{
    char ok = FUN_1402858c0(a, src[1], -1);
    if (ok == 0)
        FUN_140159b70(0x8007000e);
    FUN_140280b50(*a, *src, src[1]);
}
// @0x140280ae0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140280ae0(i64* a, i64* src)
{
    char ok = FUN_140285be0(a, src[1], -1);
    if (ok == 0)
        FUN_140159b70(0x8007000e);
    FUN_140280bc0(*a, *src, src[1]);
}
// CElementTraits<POD>::CopyElements
// @0x140280b50
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140280b50(i64 dst, i64 src, u64 n)
{
    Unk_B10* d = (Unk_B10*)dst;
    Unk_B10* s = (Unk_B10*)src;
    for (u64 i = 0; i < n; i++)
        d[i] = s[i];
}
// @0x140280bc0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140280bc0(i64 dst, i64 src, u64 n)
{
    Unk_B18* d = (Unk_B18*)dst;
    Unk_B18* s = (Unk_B18*)src;
    for (u64 i = 0; i < n; i++)
        d[i] = s[i];
}
// CAtlMap<K,V>::SetAt step: create the bucket table on first use, then NewNode
// @0x140280c30
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140280c30(i64* m, int key, u32 bin, int hash)
{
    if (*m == 0) {
        char ok = FUN_140282a90(m, U4((i64)m, 0x10), 1);
        if (ok == 0)
            FUN_140159b70(0x8007000e);
    }
    return FUN_1402833c0(m, key, bin, hash);
}
// @0x140280cb0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140280cb0(i64* m, int key, u32 bin, int hash)
{
    if (*m == 0) {
        char ok = FUN_140282bb0(m, U4((i64)m, 0x10), 1);
        if (ok == 0)
            FUN_140159b70(0x8007000e);
    }
    return FUN_1402835d0(m, key, bin, hash);
}
// CAtlMap::DisableAutoRehash / EnableAutoRehash
// @0x140280d30
void FUN_140280d30(i64 m) { I4(m, 0x30) = I4(m, 0x30) + 1; }
// @0x140280d50
void FUN_140280d50(i64 m) { I4(m, 0x30) = I4(m, 0x30) + 1; }
// @0x140280d70
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140280d70(i64 m) { I4(m, 0x30) = I4(m, 0x30) - 1; }
// @0x140280d90
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140280d90(i64 m) { I4(m, 0x30) = I4(m, 0x30) - 1; }
// CRBTree::Find(key): lower bound search by FUN_140212e20 comparator
// @0x140280db0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140280db0(i64* t, i64 key)
{
    i64 found = 0;
    i64 cur = *t;
    i64 k[3];
    k[0] = key;
    while (FUN_140282ec0(t, cur) == 0 && found == 0) {
        int c = FUN_140212e20(k, cur);
        if (c == 0)
            found = cur;
        else if (c < 0)
            cur = Q8(cur, 0x20);
        else
            cur = Q8(cur, 0x28);
    }
    i64 prev = found;
    if (found == 0) {
        found = 0;
    } else {
        do {
            found = prev;
            prev = FUN_140283c20(t, found);
            if (prev == 0)
                return found;
        } while (FUN_140212d80(k, prev) != 0);
    }
    return found;
}
// CAtlMap::GetNextAssoc-like: next non-empty bin after the node
// @0x140280ea0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140280ea0(i64* m, i64 node)
{
    i64 next;
    if (node == 0) {
        next = 0;
    } else if (Q8(node, 8) == 0) {
        next = 0;
        u64 h = FUN_1402818b0(node);
        u32 bin = (u32)((h & 0xffffffff) % (u64)U4((i64)m, 0x10));
        while (bin = bin + 1, next == 0 && bin < U4((i64)m, 0x10)) {
            if (Q8(*m, (u64)bin * 8) != 0)
                next = Q8(*m, (u64)bin * 8);
        }
    } else {
        next = Q8(node, 8);
    }
    return next;
}
// @0x140280f60
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140280f60(i64* m, i64 node)
{
    i64 next;
    if (node == 0) {
        next = 0;
    } else if (Q8(node, 8) == 0) {
        next = 0;
        u64 h = FUN_1402818c0(node);
        u32 bin = (u32)((h & 0xffffffff) % (u64)U4((i64)m, 0x10));
        while (bin = bin + 1, next == 0 && bin < U4((i64)m, 0x10)) {
            if (Q8(*m, (u64)bin * 8) != 0)
                next = Q8(*m, (u64)bin * 8);
        }
    } else {
        next = Q8(node, 8);
    }
    return next;
}
// CAtlList<T>::FreeNode: destruct, push onto the free list, free the plex chain when empty
// @0x140281020
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140281020(i64 l, i64* n)
{
    FUN_14027fcb0(n, 0);
    *n = Q8(l, 0x20);
    Q8(l, 0x20) = (i64)n;
    Q8(l, 0x10) = Q8(l, 0x10) - 1;
    if (Q8(l, 0x10) == 0)
        FUN_140284a50((i64*)l);
}
// @0x140281090
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140281090(i64 l, i64* n)
{
    FUN_14027fcf0(n, 0);
    *n = Q8(l, 0x20);
    Q8(l, 0x20) = (i64)n;
    Q8(l, 0x10) = Q8(l, 0x10) - 1;
    if (Q8(l, 0x10) == 0)
        FUN_140284b30((i64*)l);
}
// @0x140281100
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140281100(i64 l, i64* n)
{
    FUN_14027fd30(n, 0);
    *n = Q8(l, 0x20);
    Q8(l, 0x20) = (i64)n;
    Q8(l, 0x10) = Q8(l, 0x10) - 1;
    if (Q8(l, 0x10) == 0)
        FUN_140284c10((i64*)l);
}
// CAtlMap<K,V>::FreeNode
// @0x140281170
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140281170(i64 m, i64 n)
{
    if (n != 0) {
        Q8(n, 8) = Q8(m, 0x40);
        Q8(m, 0x40) = n;
        Q8(m, 8) = Q8(m, 8) - 1;
        if ((u64)Q8(m, 8) < (u64)Q8(m, 0x28) && FUN_140282e60(m) == 0) {
            u32 bins = FUN_140283a40(m, Q8(m, 8));
            FUN_140284450((i64*)m, bins);
        }
        if (Q8(m, 8) == 0)
            FUN_1402813f0(m);
        return;
    }
    FUN_140159b70(0x80004005);
}
// @0x140281260
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140281260(i64 m, i64 n)
{
    if (n != 0) {
        Q8(n, 8) = Q8(m, 0x40);
        Q8(m, 0x40) = n;
        Q8(m, 8) = Q8(m, 8) - 1;
        if ((u64)Q8(m, 8) < (u64)Q8(m, 0x28) && FUN_140282e90(m) == 0) {
            u32 bins = FUN_140283b30(m, Q8(m, 8));
            FUN_140284680((i64*)m, bins);
        }
        if (Q8(m, 8) == 0)
            FUN_140281440(m);
        return;
    }
    FUN_140159b70(0x80004005);
}
// CRBTree::FreeNode
// @0x140281350
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140281350(i64 t, i64 n)
{
    if (n != 0) {
        FUN_14027fd70((void*)n, 0);
        Q8(n, 0x20) = Q8(t, 0x10);
        Q8(t, 0x10) = n;
        Q8(t, 8) = Q8(t, 8) - 1;
        return;
    }
    FUN_140159b70(0x80004005);
}
// CAtlMap::FreePlexes (RemoveAll tail)
// @0x1402813f0
void FUN_1402813f0(i64 m)
{
    Q8(m, 0x40) = 0;
    if (Q8(m, 0x38) != 0) {
        FUN_140159e70(Q8(m, 0x38));
        Q8(m, 0x38) = 0;
    }
}
// @0x140281440
void FUN_140281440(i64 m)
{
    Q8(m, 0x40) = 0;
    if (Q8(m, 0x38) != 0) {
        FUN_140159e70(Q8(m, 0x38));
        Q8(m, 0x38) = 0;
    }
}
// @0x140281490
i64 FUN_140281490(i64 p)
{
    i64 r;
    if (p == 0)
        r = 0;
    else
        r = p - 0x18;
    return r;
}
// @0x1402814d0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402814d0(i64, i64 n)
{
    if (n != 0)
        return n + 0x10;
    FUN_140159b70(0x80004005);
}
// @0x140281540
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281540(i64, i64 n)
{
    if (n != 0)
        return n + 0x10;
    FUN_140159b70(0x80004005);
}
// @0x1402815b0
i64 FUN_1402815b0(i64 p) { return Q8(p, 8); }
// @0x1402815c0
i64 FUN_1402815c0(i64 p) { return Q8(p, 8); }
// @0x1402815d0
i64 FUN_1402815d0(i64 p) { return Q8(p, 8); }
// @0x1402815e0
i64 FUN_1402815e0(i64 p) { return Q8(p, 8); }
// @0x1402815f0
i64 FUN_1402815f0(i64 p) { return Q8(p, 8); }
// @0x140281600
i64 FUN_140281600(i64 p) { return Q8(p, 8); }
// CAtlList<T>::GetFreeNode plex growth (node size 0x28 / 0x20 / 0x18)
// @0x140281610
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140281610(i64 l)
{
    if (Q8(l, 0x20) == 0) {
        i64 plex = FUN_140159c30(l + 0x18, I4(l, 0x28), 0x28);
        if (plex == 0)
            FUN_140159b70(0x8007000e);
        plex = FUN_14015b320(plex);
        i64* node = (i64*)(plex + (u64)(I4(l, 0x28) - 1) * 0x28);
        int i = I4(l, 0x28);
        while (i = i - 1, -1 < i) {
            *node = Q8(l, 0x20);
            Q8(l, 0x20) = (i64)node;
            node = node - 5;
        }
    }
}
// @0x1402816f0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402816f0(i64 l)
{
    if (Q8(l, 0x20) == 0) {
        i64 plex = FUN_140159c30(l + 0x18, I4(l, 0x28), 0x20);
        if (plex == 0)
            FUN_140159b70(0x8007000e);
        plex = FUN_14015b320(plex);
        i64* node = (i64*)(plex + (u64)(I4(l, 0x28) - 1) * 0x20);
        int i = I4(l, 0x28);
        while (i = i - 1, -1 < i) {
            *node = Q8(l, 0x20);
            Q8(l, 0x20) = (i64)node;
            node = node - 4;
        }
    }
}
// @0x1402817d0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402817d0(i64 l)
{
    if (Q8(l, 0x20) == 0) {
        i64 plex = FUN_140159c30(l + 0x18, I4(l, 0x28), 0x18);
        if (plex == 0)
            FUN_140159b70(0x8007000e);
        plex = FUN_14015b320(plex);
        i64* node = (i64*)(plex + (u64)(I4(l, 0x28) - 1) * 0x18);
        int i = I4(l, 0x28);
        while (i = i - 1, -1 < i) {
            *node = Q8(l, 0x20);
            Q8(l, 0x20) = (i64)node;
            node = node - 3;
        }
    }
}
// CAtlMap node: hash of the key (stored at +0x10)
// @0x1402818b0
u32 FUN_1402818b0(i64 n) { return U4(n, 0x10); }
// @0x1402818c0
u32 FUN_1402818c0(i64 n) { return U4(n, 0x10); }
// @0x1402818d0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402818d0(i64* p)
{
    if (*p != 0)
        return *p + 0x10;
    FUN_140159b70(0x80004005);
}
// @0x140281930
i64 FUN_140281930(i64* p) { return *p; }
// @0x140281940
i64 FUN_140281940(i64* p) { return *p; }
// @0x140281950
i64 FUN_140281950(i64* p) { return *p; }
// @0x140281960
void FUN_140281960(i64* p) { FUN_140283110(p, *p); }
// @0x140281980
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281980(void) { return DAT_143aacd90; }
// @0x140281990
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281990(i64, i64 n)
{
    if (n != 0)
        return n;
    FUN_140159b70(0x80004005);
}
// @0x140281a00
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281a00(i64, i64 n)
{
    if (n != 0)
        return n;
    FUN_140159b70(0x80004005);
}
// CAtlList<T>::GetNext(POSITION&)
// @0x140281a70
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_140281a70(i64, i64* pos)
{
    if (*pos != 0) {
        i64* node = (i64*)*pos;
        *pos = *node;
        return node + 2;
    }
    FUN_140159b70(0x80004005);
}
// @0x140281af0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_140281af0(i64, i64* pos)
{
    if (*pos != 0) {
        i64* node = (i64*)*pos;
        *pos = *node;
        return node + 2;
    }
    FUN_140159b70(0x80004005);
}
// @0x140281b70
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_140281b70(i64, i64* pos)
{
    if (*pos != 0) {
        i64* node = (i64*)*pos;
        *pos = *node;
        return node + 2;
    }
    FUN_140159b70(0x80004005);
}
// GetNextAssoc-style iterator advance: returns the current position, steps it
// @0x140281bf0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281bf0(i64 c, i64* pos)
{
    i64 cur = *pos;
    i64 next = FUN_140159db0(c, cur);
    *pos = next;
    return cur;
}
// @0x140281c40
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281c40(i64 c, i64* pos)
{
    i64 cur = *pos;
    i64 next = FUN_140280ea0((i64*)c, cur);
    *pos = next;
    return cur;
}
// @0x140281c90
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281c90(i64 c, i64* pos)
{
    i64 cur = *pos;
    i64 next = FUN_140280f60((i64*)c, cur);
    *pos = next;
    return cur;
}
// @0x140281ce0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281ce0(i64 c, i64* pos)
{
    i64 cur = *pos;
    i64 next = FUN_1402860d0((i64*)c, cur);
    *pos = next;
    return cur;
}
// CAtlMap<int,V>::GetNode(key, bin, hash, prev)
// @0x140281d20
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281d20(i64* m, int key, u32* pBin, u32* pHash, i64* pPrev)
{
    int k[2];
    k[0] = key;
    u32 h = FUN_140167190(k);
    *pHash = h;
    *pBin = *pHash % U4((i64)m, 0x10);
    *pPrev = 0;
    if (*m != 0) {
        i64 prev = 0;
        for (i64 n = Q8(*m, (u64)*pBin * 8); n != 0; n = Q8(n, 8)) {
            if (FUN_1402818b0(n) == *pHash && FUN_140165720(n, k) != 0) {
                *pPrev = prev;
                return n;
            }
            prev = n;
        }
    }
    return 0;
}
// @0x140281e10
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281e10(i64* m, int key, u32* pBin, u32* pHash, i64* pPrev)
{
    int k[2];
    k[0] = key;
    u32 h = FUN_140167190(k);
    *pHash = h;
    *pBin = *pHash % U4((i64)m, 0x10);
    *pPrev = 0;
    if (*m != 0) {
        i64 prev = 0;
        for (i64 n = Q8(*m, (u64)*pBin * 8); n != 0; n = Q8(n, 8)) {
            if (FUN_1402818c0(n) == *pHash && FUN_140165720(n, k) != 0) {
                *pPrev = prev;
                return n;
            }
            prev = n;
        }
    }
    return 0;
}
// @0x140281f00
i64 FUN_140281f00(i64 p) { return Q8(p, 8); }
// @0x140281f10
i64 FUN_140281f10(i64 p) { return Q8(p, 8); }
// CMsTime header inlines first instantiated here (see ms2/placeholder/mstime.h): CalcZoneOffset, Get, GetTime
// @0x140281f20
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281f20(void) { return (i64)(DAT_143ab05ac - DAT_143ab05b0 * 3600); }
// CAtlMap::GetStartPosition
// @0x140281f40
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281f40(i64* m)
{
    if (FUN_140282e00((i64)m) == 0) {
        for (u32 bin = 0; bin < U4((i64)m, 0x10); bin++) {
            if (Q8(*m, (u64)bin * 8) != 0)
                return Q8(*m, (u64)bin * 8);
        }
    }
    return 0;
}
// @0x140281fb0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140281fb0(i64* m)
{
    if (FUN_140282e30((i64)m) == 0) {
        for (u32 bin = 0; bin < U4((i64)m, 0x10); bin++) {
            if (Q8(*m, (u64)bin * 8) != 0)
                return Q8(*m, (u64)bin * 8);
        }
    }
    return 0;
}
// @0x140282020
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140282020(i64* t)
{
    if (*t != 0 && DAT_143ab05a8 == 0)
        _wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\mstime.h", 0x7d);
    FUN_140282070(t);
}
// @0x140282070
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140282070(i64* t)
{
    i64 r;
    if (*t == 0) {
        r = 0;
    } else if ((char)t[1] == 1) {
        r = FUN_140281f20();
        r = r + *t;
    } else {
        r = *t;
    }
    return r;
}
// @0x1402820c0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402820c0(i64, i64 n)
{
    if (n != 0)
        return n + 8;
    FUN_140159b70(0x80004005);
}
// @0x140282130
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140282130(i64, i64 n)
{
    if (n != 0)
        return n + 4;
    FUN_140159b70(0x80004005);
}
// @0x1402821a0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402821a0(i64, i64 n)
{
    if (n != 0)
        return n + 4;
    FUN_140159b70(0x80004005);
}
// @0x140282210
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140282210(i64, i64 n)
{
    if (n != 0)
        return n + 8;
    FUN_140159b70(0x80004005);
}
// CAtlArray<T>::SetCount-grow: ATL CAtlArray::GrowBuffer for element size 0x10 / 0x18
// @0x140282270
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140282270(i64* a, u64 want)
{
    if ((u64)a[2] < want) {
        if (*a == 0) {
            size_t cap = want;
            if (want < (u64)(i64)(int)a[3])
                cap = (size_t)(int)a[3];
            void* p = calloc(cap, 0x10);
            *a = (i64)p;
            if (*a == 0)
                return 0;
            a[2] = cap;
        } else {
            u64 grow = (u64)(int)a[3];
            if (grow == 0 && (grow = (u64)a[2] / 2, grow < want - a[2]))
                grow = want - a[2];
            size_t cap = want;
            if (want < a[2] + grow)
                cap = a[2] + grow;
            void* p = calloc(cap, 0x10);
            if (p == 0)
                return 0;
            FUN_1402848b0(p, (void*)*a, a[1]);
            free((void*)*a);
            *a = (i64)p;
            a[2] = cap;
        }
    }
    return 1;
}

// @0x140282410
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140282410(i64* a, u64 want)
{
    if ((u64)a[2] < want) {
        if (*a == 0) {
            size_t cap = want;
            if (want < (u64)(i64)(int)a[3])
                cap = (size_t)(int)a[3];
            void* p = calloc(cap, 0x18);
            *a = (i64)p;
            if (*a == 0)
                return 0;
            a[2] = cap;
        } else {
            u64 grow = (u64)(int)a[3];
            if (grow == 0 && (grow = (u64)a[2] / 2, grow < want - a[2]))
                grow = want - a[2];
            size_t cap = want;
            if (want < a[2] + grow)
                cap = a[2] + grow;
            void* p = calloc(cap, 0x18);
            if (p == 0)
                return 0;
            FUN_1402848f0(p, (void*)*a, a[1]);
            free((void*)*a);
            *a = (i64)p;
            a[2] = cap;
        }
    }
    return 1;
}

// @0x1402825b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_1402825b0(i64* a, u64 want)
{
    if ((u64)a[2] < want) {
        if (*a == 0) {
            size_t cap = want;
            if (want < (u64)(i64)(int)a[3])
                cap = (size_t)(int)a[3];
            void* p = calloc(cap, 0x10);
            *a = (i64)p;
            if (*a == 0)
                return 0;
            a[2] = cap;
        } else {
            u64 grow = (u64)(int)a[3];
            if (grow == 0 && (grow = (u64)a[2] / 2, grow < want - a[2]))
                grow = want - a[2];
            size_t cap = want;
            if (want < a[2] + grow)
                cap = a[2] + grow;
            void* p = calloc(cap, 0x10);
            if (p == 0)
                return 0;
            FUN_140284930(p, (void*)*a, a[1]);
            free((void*)*a);
            *a = (i64)p;
            a[2] = cap;
        }
    }
    return 1;
}

// @0x140282750
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140282750(i64* a, u64 want)
{
    if ((u64)a[2] < want) {
        if (*a == 0) {
            size_t cap = want;
            if (want < (u64)(i64)(int)a[3])
                cap = (size_t)(int)a[3];
            void* p = calloc(cap, 0x18);
            *a = (i64)p;
            if (*a == 0)
                return 0;
            a[2] = cap;
        } else {
            u64 grow = (u64)(int)a[3];
            if (grow == 0 && (grow = (u64)a[2] / 2, grow < want - a[2]))
                grow = want - a[2];
            size_t cap = want;
            if (want < a[2] + grow)
                cap = a[2] + grow;
            void* p = calloc(cap, 0x18);
            if (p == 0)
                return 0;
            FUN_140284970(p, (void*)*a, a[1]);
            free((void*)*a);
            *a = (i64)p;
            a[2] = cap;
        }
    }
    return 1;
}

// @0x1402828f0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_1402828f0(i64* a, u64 want)
{
    if ((u64)a[2] < want) {
        if (*a == 0) {
            size_t cap = want;
            if (want < (u64)(i64)(int)a[3])
                cap = (size_t)(int)a[3];
            void* p = calloc(cap, 0x10);
            *a = (i64)p;
            if (*a == 0)
                return 0;
            a[2] = cap;
        } else {
            u64 grow = (u64)(int)a[3];
            if (grow == 0 && (grow = (u64)a[2] / 2, grow < want - a[2]))
                grow = want - a[2];
            size_t cap = want;
            if (want < a[2] + grow)
                cap = a[2] + grow;
            void* p = calloc(cap, 0x10);
            if (p == 0)
                return 0;
            FUN_1402849b0(p, (void*)*a, a[1]);
            free((void*)*a);
            *a = (i64)p;
            a[2] = cap;
        }
    }
    return 1;
}
// CAtlMap<K,V>::InitHashTable(nBins, bAllocNow)
// @0x140282a90
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140282a90(i64* m, u32 nBins, char bAllocNow)
{
    if (*m != 0) {
        delete[] (i64*)*m;
        *m = 0;
    }
    if (bAllocNow != 0) {
        *m = (i64)new i64[nBins];
        if (*m == 0)
            return 0;
        if (0x1fffffff < nBins)
            FUN_140159b70(0x80004005);
        __stosb((unsigned char*)*m, 0, (u64)nBins << 3);
    }
    U4((i64)m, 0x10) = nBins;
    FUN_140286300((i64)m);
    return 1;
}
// @0x140282bb0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140282bb0(i64* m, u32 nBins, char bAllocNow)
{
    if (*m != 0) {
        delete[] (i64*)*m;
        *m = 0;
    }
    if (bAllocNow != 0) {
        *m = (i64)new i64[nBins];
        if (*m == 0)
            return 0;
        if (0x1fffffff < nBins)
            FUN_140159b70(0x80004005);
        __stosb((unsigned char*)*m, 0, (u64)nBins << 3);
    }
    U4((i64)m, 0x10) = nBins;
    FUN_1402863e0((i64)m);
    return 1;
}
// CRBTree::Insert (internal): new node, descend by the key comparator, link as a leaf
// @0x140282cd0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140282cd0(i64* t, i64 key, i64 val)
{
    i64 k[2];
    k[0] = key;
    k[1] = val;
    i64 n = FUN_1402837e0(t, key, val);
    i64 parent = 0;
    i64 cur = *t;
    while (FUN_140282ec0(t, cur) == 0) {
        parent = cur;
        int c = FUN_140212e20(&k[0], cur);
        if (c < 1)
            cur = Q8(cur, 0x20);
        else
            cur = Q8(cur, 0x28);
    }
    Q8(n, 0x30) = parent;
    if (parent == 0) {
        *t = n;
    } else {
        int c = FUN_140212e20(&k[0], parent);
        if (c < 1)
            Q8(parent, 0x20) = n;
        else
            Q8(parent, 0x28) = n;
    }
    return n;
}
// @0x140282dd0
bool FUN_140282dd0(i64 p) { return Q8(p, 0x10) == 0; }
// @0x140282e00
bool FUN_140282e00(i64 p) { return Q8(p, 8) == 0; }
// @0x140282e30
bool FUN_140282e30(i64 p) { return Q8(p, 8) == 0; }
// @0x140282e60
bool FUN_140282e60(i64 p) { return I4(p, 0x30) != 0; }
// @0x140282e90
bool FUN_140282e90(i64 p) { return I4(p, 0x30) != 0; }
// CRBTree::IsNil
// @0x140282ec0
bool FUN_140282ec0(i64* t, i64 n) { return n == Q8((i64)t, 0x28); }
// CRBTree::RotateLeft
// @0x140282f00
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140282f00(i64* t, i64 node)
{
    if (node == 0) {
        node = 0;
    } else {
        i64 r = Q8(node, 0x28);
        Q8(node, 0x28) = Q8(r, 0x20);
        if (FUN_140282ec0(t, Q8(r, 0x20)) == 0)
            Q8(Q8(r, 0x20), 0x30) = node;
        Q8(r, 0x30) = Q8(node, 0x30);
        if (FUN_140282ec0(t, Q8(node, 0x30)) == 0) {
            if (node == Q8(Q8(node, 0x30), 0x20))
                Q8(Q8(node, 0x30), 0x20) = r;
            else
                Q8(Q8(node, 0x30), 0x28) = r;
        } else {
            *t = r;
        }
        Q8(r, 0x20) = node;
        Q8(node, 0x30) = r;
    }
    return node;
}
// @0x140283010
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140283010(i64* m, int key)
{
    u32 hash;
    u32 bin[3];
    i64 prev[3];
    return (char)FUN_140281e10(m, key, bin, &hash, prev);
}
// @0x140283050
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
bool FUN_140283050(i64* t, i64 key, i64 out)
{
    i64 n = FUN_140280db0(t, key);
    if (n != 0)
        FUN_14027e990(out, n + 8);
    return n != 0;
}
// CRBTree::Max of a subtree (rightmost non-nil)
// @0x1402830a0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402830a0(i64* t, i64 n)
{
    i64 r;
    char c;
    if (n == 0 || (c = FUN_140282ec0(t, n), r = n, c != 0)) {
        r = 0;
    } else {
        while (c = FUN_140282ec0(t, Q8(r, 0x28)), c == 0)
            r = Q8(r, 0x28);
    }
    return r;
}
// CRBTree::Min of a subtree (leftmost non-nil)
// @0x140283110
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140283110(i64* t, i64 n)
{
    i64 r;
    char c;
    if (n == 0 || (c = FUN_140282ec0(t, n), r = n, c != 0)) {
        r = 0;
    } else {
        while (c = FUN_140282ec0(t, Q8(r, 0x20)), c == 0)
            r = Q8(r, 0x20);
    }
    return r;
}
// CAtlList<T>::NewNode(element, prev, next) for node sizes 0x28 / 0x20 / 0x18
// @0x140283180
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_140283180(i64 l, i64 e, i64 prev, i64 next)
{
    FUN_140281610(l);
    i64* node = (i64*)Q8(l, 0x20);
    i64 nextFree = *(i64*)Q8(l, 0x20);
    i64 slot = FUN_140159860(0x28, (i64)node);
    FUN_14027d970(slot, e);
    Q8(l, 0x20) = nextFree;
    node[1] = prev;
    *node = next;
    Q8(l, 0x10) = Q8(l, 0x10) + 1;
    return node;
}
// @0x140283240
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_140283240(i64 l, i64 e, i64 prev, i64 next)
{
    FUN_1402816f0(l);
    i64* node = (i64*)Q8(l, 0x20);
    i64 nextFree = *(i64*)Q8(l, 0x20);
    i64 slot = FUN_140159860(0x20, (i64)node);
    FUN_14027d9a0(slot, e);
    Q8(l, 0x20) = nextFree;
    node[1] = prev;
    *node = next;
    Q8(l, 0x10) = Q8(l, 0x10) + 1;
    return node;
}
// @0x140283300
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_140283300(i64 l, i64 e, i64 prev, i64 next)
{
    FUN_1402817d0(l);
    i64* node = (i64*)Q8(l, 0x20);
    i64 nextFree = *(i64*)Q8(l, 0x20);
    i64 slot = FUN_140159860(0x18, (i64)node);
    FUN_14027d9d0(slot, e);
    Q8(l, 0x20) = nextFree;
    node[1] = prev;
    *node = next;
    Q8(l, 0x10) = Q8(l, 0x10) + 1;
    return node;
}
// CAtlMap::NewNode(key, iBin, nHash) for 0x18-byte nodes
// @0x1402833c0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402833c0(i64* m, int key, u32 iBin, int hash)
{
    if (m[8] == 0) {
        i64 plex = FUN_140159c30((i64)(m + 7), I4(m, 0x34), 0x18);
        if (plex == 0)
            FUN_140159b70(0x8007000e);
        i64 node = FUN_14015b320(plex);
        node = node + (u64)(I4(m, 0x34) - 1) * 0x18;
        int i = I4(m, 0x34);
        while (i = i - 1, -1 < i) {
            Q8(node, 8) = m[8];
            m[8] = node;
            node = node - 0x18;
        }
    }
    if (m[8] != 0) {
        i64 n = m[8];
        m[8] = Q8(n, 8);
        i64 slot = FUN_140159860(0x18, n);
        FUN_14027d9f0(slot, key, hash);
        m[1] = m[1] + 1;
        Q8(n, 8) = Q8(*m, (u64)iBin * 8);
        Q8(*m, (u64)iBin * 8) = n;
        if ((u64)m[4] < (u64)m[1] && FUN_140282e60((i64)m) == 0) {
            u32 bins = FUN_140283a40((i64)m, m[1]);
            FUN_140284450(m, bins);
        }
        return n;
    }
    FUN_140159b70(0x80004005);
}
// @0x1402835d0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402835d0(i64* m, int key, u32 iBin, int hash)
{
    if (m[8] == 0) {
        i64 plex = FUN_140159c30((i64)(m + 7), I4(m, 0x34), 0x18);
        if (plex == 0)
            FUN_140159b70(0x8007000e);
        i64 node = FUN_14015b320(plex);
        node = node + (u64)(I4(m, 0x34) - 1) * 0x18;
        int i = I4(m, 0x34);
        while (i = i - 1, -1 < i) {
            Q8(node, 8) = m[8];
            m[8] = node;
            node = node - 0x18;
        }
    }
    if (m[8] != 0) {
        i64 n = m[8];
        m[8] = Q8(n, 8);
        i64 slot = FUN_140159860(0x18, n);
        FUN_14027da30(slot, key, hash);
        m[1] = m[1] + 1;
        Q8(n, 8) = Q8(*m, (u64)iBin * 8);
        Q8(*m, (u64)iBin * 8) = n;
        if ((u64)m[4] < (u64)m[1] && FUN_140282e90((i64)m) == 0) {
            u32 bins = FUN_140283b30((i64)m, m[1]);
            FUN_140284680(m, bins);
        }
        return n;
    }
    FUN_140159b70(0x80004005);
}
// CRBTree::NewNode(key, value): allocates the nil sentinel on first use, then a node from the free list
// @0x1402837e0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402837e0(i64* t, i64 key, i64 val)
{
    if (t[2] == 0) {
        if (t[5] == 0) {
            t[5] = (i64)malloc(0x38);
            if (t[5] == 0)
                FUN_140159b70(0x8007000e);
            __stosb((unsigned char*)t[5], 0, 0x38);
            I4(t[5], 0x18) = 1;
            Q8(t[5], 0x28) = t[5];
            Q8(t[5], 0x20) = Q8(t[5], 0x28);
            Q8(t[5], 0x30) = Q8(t[5], 0x20);
            *t = t[5];
        }
        i64 plex = FUN_140159c30((i64)(t + 3), (int)t[4], 0x38);
        if (plex == 0)
            FUN_140159b70(0x8007000e);
        i64 node = FUN_14015b320(plex);
        node = node + (t[4] - 1) * 0x38;
        i64 i = t[4];
        while (i = i - 1, -1 < i) {
            Q8(node, 0x20) = t[2];
            t[2] = node;
            node = node - 0x38;
        }
    }
    i64 n = t[2];
    i64 slot = FUN_140159860(0x38, n);
    FUN_14027da70(slot, key, val);
    t[2] = Q8(t[2], 0x20);
    I4(n, 0x18) = 0;
    FUN_140285f00(t, (i64*)(n + 0x20));
    FUN_140285f00(t, (i64*)(n + 0x28));
    FUN_140285f00(t, (i64*)(n + 0x30));
    t[1] = t[1] + 1;
    return n;
}
// CAtlMap::PickSize(nElements): smallest prime above nElements / load factor
// @0x140283a40
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
u32 FUN_140283a40(i64 m, u64 nElements)
{
    u64 nBins = (u64)((float)nElements / *(float*)(m + 0x14));
    u32 est = (u32)(0xffffffffu < nBins ? 0xffffffffu : nBins);
    int ip = 0;
    while (est > DAT_142ce52b0[ip])
        ip++;
    if (DAT_142ce52b0[ip] == 0xffffffffu)
        return est;
    return DAT_142ce52b0[ip];
}
// @0x140283b30
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
u32 FUN_140283b30(i64 m, u64 nElements)
{
    u64 nBins = (u64)((float)nElements / *(float*)(m + 0x14));
    u32 est = (u32)(0xffffffffu < nBins ? 0xffffffffu : nBins);
    int ip = 0;
    while (est > DAT_142ce52b0[ip])
        ip++;
    if (DAT_142ce52b0[ip] == 0xffffffffu)
        return est;
    return DAT_142ce52b0[ip];
}
// CRBTree::Predecessor(node)
// @0x140283c20
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140283c20(i64* t, i64 n)
{
    i64 r;
    if (n == 0) {
        r = 0;
    } else {
        if (FUN_140282ec0(t, Q8(n, 0x20)) == 0) {
            r = FUN_1402830a0(t, Q8(n, 0x20));
        } else {
            i64 prev = n;
            for (r = Q8(n, 0x30); FUN_140282ec0(t, r) == 0 && prev == Q8(r, 0x20); r = Q8(r, 0x30))
                prev = r;
            if (FUN_140282ec0(t, r) != 0)
                r = 0;
        }
    }
    return r;
}
// CRBTree::RemoveNode(node)
// @0x140283cf0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
bool FUN_140283cf0(i64* t, i64 node)
{
    bool ret;
    if (node == 0) {
        ret = false;
    } else {
        char c = FUN_140282ec0(t, Q8(node, 0x20));
        i64 y = node;
        if (c == 0 && (c = FUN_140282ec0(t, Q8(node, 0x28)), c == 0))
            y = FUN_1402860d0(t, node);
        i64 x;
        c = FUN_140282ec0(t, Q8(y, 0x20));
        if (c == 0)
            x = Q8(y, 0x20);
        else
            x = Q8(y, 0x28);
        Q8(x, 0x30) = Q8(y, 0x30);
        c = FUN_140282ec0(t, Q8(y, 0x30));
        if (c == 0) {
            if (y == Q8(Q8(y, 0x30), 0x20))
                Q8(Q8(y, 0x30), 0x20) = x;
            else
                Q8(Q8(y, 0x30), 0x28) = x;
        } else {
            *t = x;
        }
        if (I4(y, 0x18) == 1)
            FUN_140283ea0(t, x);
        if (y != node)
            FUN_1402861a0(t, y, node);
        if (*t != 0)
            FUN_140285f00(t, (i64*)(*t + 0x30));
        FUN_140281350((i64)t, node);
        ret = true;
    }
    return ret;
}
// CRBTree::RBDeleteFixup(x)
// @0x140283ea0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140283ea0(i64* t, i64 x)
{
    if (x == 0)
        FUN_140159b70(0x80004005);
    i64 w;
    while (x != *t && I4(x, 0x18) == 1) {
        if (x == Q8(Q8(x, 0x30), 0x20)) {
            w = Q8(Q8(x, 0x30), 0x28);
            if (I4(w, 0x18) == 0) {
                I4(w, 0x18) = 1;
                I4(Q8(w, 0x30), 0x18) = 0;
                FUN_140282f00(t, Q8(x, 0x30));
                w = Q8(Q8(x, 0x30), 0x28);
            }
            if (I4(Q8(w, 0x20), 0x18) == 1 && I4(Q8(w, 0x28), 0x18) == 1) {
                I4(w, 0x18) = 0;
                x = Q8(x, 0x30);
            } else {
                if (I4(Q8(w, 0x28), 0x18) == 1) {
                    I4(Q8(w, 0x20), 0x18) = 1;
                    I4(w, 0x18) = 0;
                    FUN_140285610(t, w);
                    w = Q8(Q8(x, 0x30), 0x28);
                }
                I4(w, 0x18) = I4(Q8(x, 0x30), 0x18);
                I4(Q8(x, 0x30), 0x18) = 1;
                I4(Q8(w, 0x28), 0x18) = 1;
                FUN_140282f00(t, Q8(x, 0x30));
                x = *t;
            }
        } else {
            w = Q8(Q8(x, 0x30), 0x20);
            if (I4(w, 0x18) == 0) {
                I4(w, 0x18) = 1;
                I4(Q8(w, 0x30), 0x18) = 0;
                FUN_140285610(t, Q8(x, 0x30));
                w = Q8(Q8(x, 0x30), 0x20);
            }
            if (I4(Q8(w, 0x28), 0x18) == 1 && I4(Q8(w, 0x20), 0x18) == 1) {
                I4(w, 0x18) = 0;
                x = Q8(x, 0x30);
            } else {
                if (I4(Q8(w, 0x20), 0x18) == 1) {
                    I4(Q8(w, 0x28), 0x18) = 1;
                    I4(w, 0x18) = 0;
                    FUN_140282f00(t, w);
                    w = Q8(Q8(x, 0x30), 0x20);
                }
                I4(w, 0x18) = I4(Q8(x, 0x30), 0x18);
                I4(Q8(x, 0x30), 0x18) = 1;
                I4(Q8(w, 0x20), 0x18) = 1;
                FUN_140285610(t, Q8(x, 0x30));
                x = *t;
            }
        }
    }
    I4(x, 0x18) = 1;
}
// CRBTree::Insert(key, value): insert as a leaf, then rebalance
// @0x1402841d0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402841d0(i64* t, i64 key, i64 val)
{
    i64 n = FUN_140282cd0(t, key, val);
    I4(n, 0x18) = 0;
    i64 x = n;
    while (x != *t && I4(Q8(x, 0x30), 0x18) == 0) {
        if (Q8(x, 0x30) == Q8(Q8(Q8(x, 0x30), 0x30), 0x20)) {
            i64 y = Q8(Q8(Q8(x, 0x30), 0x30), 0x28);
            if (y == 0 || I4(y, 0x18) != 0) {
                if (x == Q8(Q8(x, 0x30), 0x28)) {
                    x = Q8(x, 0x30);
                    FUN_140282f00(t, x);
                }
                I4(Q8(x, 0x30), 0x18) = 1;
                I4(Q8(Q8(x, 0x30), 0x30), 0x18) = 0;
                FUN_140285610(t, Q8(Q8(x, 0x30), 0x30));
            } else {
                I4(Q8(x, 0x30), 0x18) = 1;
                I4(y, 0x18) = 1;
                I4(Q8(Q8(x, 0x30), 0x30), 0x18) = 0;
                x = Q8(Q8(x, 0x30), 0x30);
            }
        } else {
            i64 y = Q8(Q8(Q8(x, 0x30), 0x30), 0x20);
            if (y == 0 || I4(y, 0x18) != 0) {
                if (x == Q8(Q8(x, 0x30), 0x20)) {
                    x = Q8(x, 0x30);
                    FUN_140285610(t, x);
                }
                I4(Q8(x, 0x30), 0x18) = 1;
                I4(Q8(Q8(x, 0x30), 0x30), 0x18) = 0;
                FUN_140282f00(t, Q8(Q8(x, 0x30), 0x30));
            } else {
                I4(Q8(x, 0x30), 0x18) = 1;
                I4(y, 0x18) = 1;
                I4(Q8(Q8(x, 0x30), 0x30), 0x18) = 0;
                x = Q8(Q8(x, 0x30), 0x30);
            }
        }
    }
    I4(*t, 0x18) = 1;
    FUN_140285f00(t, (i64*)(*t + 0x30));
    return n;
}
// CAtlMap::Rehash(nBins)
// @0x140284450
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284450(i64* m, u32 nBins)
{
    if (nBins == 0)
        nBins = FUN_140283a40((i64)m, m[1]);
    if (nBins != U4(m, 0x10)) {
        if (*m == 0) {
            FUN_140282a90(m, nBins, 0);
        } else {
            i64* newBins = new i64[nBins];
            if (newBins == 0)
                FUN_140159b70(0x8007000e);
            if (0x1fffffff < nBins)
                FUN_140159b70(0x80004005);
            __stosb((unsigned char*)newBins, 0, (u64)nBins << 3);
            for (u32 i = 0; i < U4(m, 0x10); i++) {
                i64 n = Q8(*m, (u64)i * 8);
                while (n != 0) {
                    i64 next = Q8(n, 8);
                    u64 h = FUN_1402818b0(n);
                    h = (h & 0xffffffff) % nBins;
                    Q8(n, 8) = newBins[h];
                    newBins[h] = n;
                    n = next;
                }
            }
            delete[] (i64*)*m;
            *m = (i64)newBins;
            U4(m, 0x10) = nBins;
            FUN_140286300((i64)m);
        }
    }
}
// @0x140284680
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284680(i64* m, u32 nBins)
{
    if (nBins == 0)
        nBins = FUN_140283b30((i64)m, m[1]);
    if (nBins != U4(m, 0x10)) {
        if (*m == 0) {
            FUN_140282bb0(m, nBins, 0);
        } else {
            i64* newBins = new i64[nBins];
            if (newBins == 0)
                FUN_140159b70(0x8007000e);
            if (0x1fffffff < nBins)
                FUN_140159b70(0x80004005);
            __stosb((unsigned char*)newBins, 0, (u64)nBins << 3);
            for (u32 i = 0; i < U4(m, 0x10); i++) {
                i64 n = Q8(*m, (u64)i * 8);
                while (n != 0) {
                    i64 next = Q8(n, 8);
                    u64 h = FUN_1402818c0(n);
                    h = (h & 0xffffffff) % nBins;
                    Q8(n, 8) = newBins[h];
                    newBins[h] = n;
                    n = next;
                }
            }
            delete[] (i64*)*m;
            *m = (i64)newBins;
            U4(m, 0x10) = nBins;
            FUN_1402863e0((i64)m);
        }
    }
}
// ATL::Checked::memmove_s of n elements (element size 0x10 / 0x18)
// @0x1402848b0
void FUN_1402848b0(void* dst, void* src, i64 n) { ATL::Checked::memmove_s(dst, n * 0x10, src, n * 0x10); }
// @0x1402848f0
void FUN_1402848f0(void* dst, void* src, i64 n) { ATL::Checked::memmove_s(dst, n * 0x18, src, n * 0x18); }
// @0x140284930
void FUN_140284930(void* dst, void* src, i64 n) { ATL::Checked::memmove_s(dst, n * 0x10, src, n * 0x10); }
// @0x140284970
void FUN_140284970(void* dst, void* src, i64 n) { ATL::Checked::memmove_s(dst, n * 0x18, src, n * 0x18); }
// @0x1402849b0
void FUN_1402849b0(void* dst, void* src, i64 n) { ATL::Checked::memmove_s(dst, n * 0x10, src, n * 0x10); }
// CAtlArray<T>::RemoveAll
// @0x1402849f0
void FUN_1402849f0(i64* a) { FUN_140285be0(a, 0, -1); }
// @0x140284a10
void FUN_140284a10(i64* a) { FUN_140285d70(a, 0, -1); }
// @0x140284a30
void FUN_140284a30(i64* a) { FUN_1401ba320((i64)a, 0, -1); }
// CAtlList<T>::RemoveAll (node size 0x28 / 0x20 / 0x18)
// @0x140284a50
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284a50(i64* l)
{
    while (l[2] != 0) {
        i64 kill = *l;
        if (kill == 0)
            FUN_140159b70(0x80004005);
        *l = *(i64*)*l;
        FUN_140281020((i64)l, (i64*)kill);
    }
    *l = 0;
    l[1] = 0;
    l[4] = 0;
    if (l[3] != 0) {
        FUN_140159e70(l[3]);
        l[3] = 0;
    }
}
// @0x140284b30
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284b30(i64* l)
{
    while (l[2] != 0) {
        i64 kill = *l;
        if (kill == 0)
            FUN_140159b70(0x80004005);
        *l = *(i64*)*l;
        FUN_140281090((i64)l, (i64*)kill);
    }
    *l = 0;
    l[1] = 0;
    l[4] = 0;
    if (l[3] != 0) {
        FUN_140159e70(l[3]);
        l[3] = 0;
    }
}
// @0x140284c10
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284c10(i64* l)
{
    while (l[2] != 0) {
        i64 kill = *l;
        if (kill == 0)
            FUN_140159b70(0x80004005);
        *l = *(i64*)*l;
        FUN_140281100((i64)l, (i64*)kill);
    }
    *l = 0;
    l[1] = 0;
    l[4] = 0;
    if (l[3] != 0) {
        FUN_140159e70(l[3]);
        l[3] = 0;
    }
}
// CAtlMap<K,V>::RemoveAll
// @0x140284cf0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284cf0(i64* m)
{
    FUN_140280d30((i64)m);
    if (*m != 0) {
        for (u32 i = 0; i < U4(m, 0x10); i++) {
            i64 n = Q8(*m, (u64)i * 8);
            while (n != 0) {
                i64 next = Q8(n, 8);
                FUN_140281170((i64)m, n);
                n = next;
            }
        }
    }
    delete[] (i64*)*m;
    *m = 0;
    m[1] = 0;
    if (FUN_140282e60((i64)m) == 0) {
        u32 bins = FUN_140283a40((i64)m, m[1]);
        FUN_140282a90(m, bins, 0);
    }
    FUN_1402813f0((i64)m);
    FUN_140280d70((i64)m);
}
// @0x140284e00
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284e00(i64* m)
{
    FUN_140280d50((i64)m);
    if (*m != 0) {
        for (u32 i = 0; i < U4(m, 0x10); i++) {
            i64 n = Q8(*m, (u64)i * 8);
            while (n != 0) {
                i64 next = Q8(n, 8);
                FUN_140281260((i64)m, n);
                n = next;
            }
        }
    }
    delete[] (i64*)*m;
    *m = 0;
    m[1] = 0;
    if (FUN_140282e90((i64)m) == 0) {
        u32 bins = FUN_140283b30((i64)m, m[1]);
        FUN_140282bb0(m, bins, 0);
    }
    FUN_140281440((i64)m);
    FUN_140280d90((i64)m);
}
// CRBTree::RemoveAll
// @0x140284f10
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284f10(i64* t)
{
    if (FUN_140282ec0(t, *t) == 0)
        FUN_1402855b0(t, *t);
    t[1] = 0;
    FUN_140159e70(t[3]);
    t[3] = 0;
    t[2] = 0;
    *t = t[5];
}
// CAtlList<T>::RemoveAt(pos)
// @0x140284f90
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140284f90(i64* l, i64* pos)
{
    if (pos != 0) {
        if (pos == (i64*)*l)
            *l = *pos;
        else
            *(i64*)pos[1] = *pos;
        if (pos == (i64*)l[1])
            l[1] = pos[1];
        else
            *(i64*)(*pos + 8) = pos[1];
        FUN_140281090((i64)l, pos);
        return;
    }
    FUN_140159b70(0x80004005);
}
// @0x140285070
void FUN_140285070(i64* t, i64 n) { FUN_140283cf0(t, n); }
// CAtlMap<K,V>::RemoveAtPos(pos)
// @0x1402850a0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402850a0(i64* m, i64 node)
{
    if (node != 0) {
        u64 bin = FUN_1402818b0(node);
        bin = (bin & 0xffffffff) % U4(m, 0x10);
        i64 prev;
        if (node == Q8(*m, bin * 8)) {
            prev = 0;
        } else {
            for (prev = Q8(*m, bin * 8); Q8(prev, 8) != node; prev = Q8(prev, 8)) {}
        }
        FUN_140285430(m, node, prev);
        return;
    }
    FUN_140159b70(0x80004005);
}
// @0x140285190
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140285190(i64* m, i64 node)
{
    if (node != 0) {
        u64 bin = FUN_1402818c0(node);
        bin = (bin & 0xffffffff) % U4(m, 0x10);
        i64 prev;
        if (node == Q8(*m, bin * 8)) {
            prev = 0;
        } else {
            for (prev = Q8(*m, bin * 8); Q8(prev, 8) != node; prev = Q8(prev, 8)) {}
        }
        FUN_1402854f0(m, node, prev);
        return;
    }
    FUN_140159b70(0x80004005);
}
// CAtlList<T>::RemoveHead() returning the element by value
// @0x140285280
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140285280(i64* l, i64 out)
{
    if (*l != 0) {
        i64* node = (i64*)*l;
        char tmp[40];
        FUN_14027dd60((i64)tmp, (i64)(node + 2));
        *l = *node;
        if (*l == 0)
            l[1] = 0;
        else
            Q8(*l, 8) = 0;
        FUN_140281020((i64)l, node);
        FUN_14027dd20(out, (i64)tmp);
        FUN_14027e900((i64)tmp);
        return out;
    }
    FUN_140159b70(0x80004005);
}
// CAtlList<T>::RemoveHead() discarding the element
// @0x140285380
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140285380(i64* l)
{
    if (*l != 0) {
        i64* node = (i64*)*l;
        *l = *node;
        if (*l == 0)
            l[1] = 0;
        else
            Q8(*l, 8) = 0;
        FUN_140281020((i64)l, node);
        return;
    }
    FUN_140159b70(0x80004005);
}
// CAtlMap<K,V>::RemoveNode(node, prev)
// @0x140285430
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140285430(i64* m, i64 node, i64 prev)
{
    if (node != 0) {
        u64 hash = FUN_1402818b0(node);
        if (prev == 0)
            Q8(*m, ((hash & 0xffffffff) % U4(m, 0x10)) * 8) = Q8(node, 8);
        else
            Q8(prev, 8) = Q8(node, 8);
        FUN_140281170((i64)m, node);
        return;
    }
    FUN_140159b70(0x80004005);
}
// @0x1402854f0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402854f0(i64* m, i64 node, i64 prev)
{
    if (node != 0) {
        u64 hash = FUN_1402818c0(node);
        if (prev == 0)
            Q8(*m, ((hash & 0xffffffff) % U4(m, 0x10)) * 8) = Q8(node, 8);
        else
            Q8(prev, 8) = Q8(node, 8);
        FUN_140281260((i64)m, node);
        return;
    }
    FUN_140159b70(0x80004005);
}
// CRBTree::FreeTree(node)
// @0x1402855b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402855b0(i64* t, i64 n)
{
    if (FUN_140282ec0(t, n) == 0) {
        FUN_1402855b0(t, Q8(n, 0x20));
        FUN_1402855b0(t, Q8(n, 0x28));
        FUN_140281350((i64)t, n);
    }
}
// CRBTree::RotateRight
// @0x140285610
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140285610(i64* t, i64 node)
{
    if (node == 0) {
        node = 0;
    } else {
        i64 l = Q8(node, 0x20);
        Q8(node, 0x20) = Q8(l, 0x28);
        if (FUN_140282ec0(t, Q8(l, 0x28)) == 0)
            Q8(Q8(l, 0x28), 0x30) = node;
        Q8(l, 0x30) = Q8(node, 0x30);
        if (FUN_140282ec0(t, Q8(node, 0x30)) == 0) {
            if (node == Q8(Q8(node, 0x30), 0x28))
                Q8(Q8(node, 0x30), 0x28) = l;
            else
                Q8(Q8(node, 0x30), 0x20) = l;
        } else {
            *t = l;
        }
        Q8(l, 0x28) = node;
        Q8(node, 0x30) = l;
    }
    return node;
}
// CAtlMap<int,int>::SetAt(key, value)
// @0x140285720
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140285720(i64* m, int key, int val)
{
    u32 bin;
    u32 hash;
    i64 prev[2];
    i64 n = FUN_140281d20(m, key, &bin, &hash, prev);
    if (n == 0) {
        n = FUN_140280c30(m, key, bin, hash);
        try {
            I4(n, 4) = val;
        }
    catch
    (...) {
            FUN_1402850a0(m, n);
            throw;
        }
    } else {
        I4(n, 4) = val;
    }
    return n;
}
// @0x1402857b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402857b0(i64* m, int key, int* val)
{
    u32 bin;
    u32 hash;
    i64 prev[2];
    i64 n = FUN_140281e10(m, key, &bin, &hash, prev);
    if (n == 0) {
        n = FUN_140280cb0(m, key, bin, hash);
        try {
            I4(n, 4) = *val;
        }
    catch
    (...) {
            FUN_140285190(m, n);
            throw;
        }
    } else {
        I4(n, 4) = *val;
    }
    return n;
}
// CRBMap<K,V>::SetAt(key, value)
// @0x140285850
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140285850(i64* t, i64 key, i64 val)
{
    i64 n = FUN_140280db0(t, key);
    if (n == 0)
        n = FUN_1402841d0(t, key, val);
    else
        FUN_14027e990(n + 8, val);
    return n;
}
// CAtlArray<T>::SetCount(nNewSize, nGrowBy) for element sizes 0x10 / 0x18
// @0x1402858c0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_1402858c0(i64* a, u64 n, int grow)
{
    if (grow != -1)
        I4(a, 0x18) = grow;
    if (n == 0) {
        if (*a != 0) {
            FUN_140280970((void**)*a, a[1]);
            free((void*)*a);
            *a = 0;
        }
        a[1] = 0;
        a[2] = 0;
    } else if ((u64)a[2] < n) {
        char ok = FUN_140282270(a, n);
        if (ok == 0)
            return 0;
        FUN_140280770(a[1] * 0x10 + *a, n - a[1]);
        a[1] = n;
    } else {
        if ((u64)a[1] < n)
            FUN_140280770(a[1] * 0x10 + *a, n - a[1]);
        else if (n < (u64)a[1])
            FUN_140280970((void**)(n * 0x10 + *a), a[1] - n);
        a[1] = n;
    }
    return 1;
}
// @0x140285a50
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140285a50(i64* a, u64 n, int grow)
{
    if (grow != -1)
        I4(a, 0x18) = grow;
    if (n == 0) {
        if (*a != 0) {
            FUN_1402809b0((void**)*a, a[1]);
            free((void*)*a);
            *a = 0;
        }
        a[1] = 0;
        a[2] = 0;
    } else if ((u64)a[2] < n) {
        char ok = FUN_1402825b0(a, n);
        if (ok == 0)
            return 0;
        FUN_1402807f0(a[1] * 0x10 + *a, n - a[1]);
        a[1] = n;
    } else {
        if ((u64)a[1] < n)
            FUN_1402807f0(a[1] * 0x10 + *a, n - a[1]);
        else if (n < (u64)a[1])
            FUN_1402809b0((void**)(n * 0x10 + *a), a[1] - n);
        a[1] = n;
    }
    return 1;
}
// @0x140285be0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140285be0(i64* a, u64 n, int grow)
{
    if (grow != -1)
        I4(a, 0x18) = grow;
    if (n == 0) {
        if (*a != 0) {
            FUN_1402809f0((void**)*a, a[1]);
            free((void*)*a);
            *a = 0;
        }
        a[1] = 0;
        a[2] = 0;
    } else if ((u64)a[2] < n) {
        char ok = FUN_140282750(a, n);
        if (ok == 0)
            return 0;
        FUN_140280870(a[1] * 0x18 + *a, n - a[1]);
        a[1] = n;
    } else {
        if ((u64)a[1] < n)
            FUN_140280870(a[1] * 0x18 + *a, n - a[1]);
        else if (n < (u64)a[1])
            FUN_1402809f0((void**)(n * 0x18 + *a), a[1] - n);
        a[1] = n;
    }
    return 1;
}
// @0x140285d70
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
char FUN_140285d70(i64* a, u64 n, int grow)
{
    if (grow != -1)
        I4(a, 0x18) = grow;
    if (n == 0) {
        if (*a != 0) {
            FUN_140280a30((void**)*a, a[1]);
            free((void*)*a);
            *a = 0;
        }
        a[1] = 0;
        a[2] = 0;
    } else if ((u64)a[2] < n) {
        char ok = FUN_1402828f0(a, n);
        if (ok == 0)
            return 0;
        FUN_1402808f0(a[1] * 0x10 + *a, n - a[1]);
        a[1] = n;
    } else {
        if ((u64)a[1] < n)
            FUN_1402808f0(a[1] * 0x10 + *a, n - a[1]);
        else if (n < (u64)a[1])
            FUN_140280a30((void**)(n * 0x10 + *a), a[1] - n);
        a[1] = n;
    }
    return 1;
}
// @0x140285f00
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140285f00(i64* t, i64* p)
{
    if (p != 0) {
        *p = Q8(t, 0x28);
        return;
    }
    FUN_140159b70(0x80004005);
}
// CAtlMap::SetOptimalLoad(fOptimalLoad, fLowThreshold, fHighThreshold, bRehashNow)
// @0x140285f70
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140285f70(i64 m, float opt, float lo, float hi, char rehash)
{
    *(float*)(m + 0x14) = opt;
    *(float*)(m + 0x18) = lo;
    *(float*)(m + 0x1c) = hi;
    FUN_140286300(m);
    if (rehash != 0 && ((u64)Q8(m, 0x20) < (u64)Q8(m, 8) || (u64)Q8(m, 8) < (u64)Q8(m, 0x28))) {
        u32 bins = FUN_140283a40(m, Q8(m, 8));
        FUN_140284450((i64*)m, bins);
    }
}
// @0x140286020
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140286020(i64 m, float opt, float lo, float hi, char rehash)
{
    *(float*)(m + 0x14) = opt;
    *(float*)(m + 0x18) = lo;
    *(float*)(m + 0x1c) = hi;
    FUN_1402863e0(m);
    if (rehash != 0 && ((u64)Q8(m, 0x20) < (u64)Q8(m, 8) || (u64)Q8(m, 8) < (u64)Q8(m, 0x28))) {
        u32 bins = FUN_140283b30(m, Q8(m, 8));
        FUN_140284680((i64*)m, bins);
    }
}
// CRBTree::Successor(node)
// @0x1402860d0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_1402860d0(i64* t, i64 n)
{
    i64 r;
    if (n == 0) {
        r = 0;
    } else {
        if (FUN_140282ec0(t, Q8(n, 0x28)) == 0) {
            r = FUN_140283110(t, Q8(n, 0x28));
        } else {
            i64 prev = n;
            for (r = Q8(n, 0x30); FUN_140282ec0(t, r) == 0 && prev == Q8(r, 0x28); r = Q8(r, 0x30))
                prev = r;
            if (FUN_140282ec0(t, r) != 0)
                r = 0;
        }
    }
    return r;
}
// CRBTree::SwapNode(dst, src): put dst in the tree position of src
// @0x1402861a0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402861a0(i64* t, i64 dst, i64 src)
{
    if (dst == 0)
        FUN_140159b70(0x80004005);
    if (src != 0) {
        Q8(dst, 0x30) = Q8(src, 0x30);
        if (Q8(Q8(src, 0x30), 0x20) == src)
            Q8(Q8(src, 0x30), 0x20) = dst;
        else
            Q8(Q8(src, 0x30), 0x28) = dst;
        Q8(dst, 0x28) = Q8(src, 0x28);
        Q8(dst, 0x20) = Q8(src, 0x20);
        I4(dst, 0x18) = I4(src, 0x18);
        Q8(Q8(dst, 0x28), 0x30) = dst;
        Q8(Q8(dst, 0x20), 0x30) = dst;
        if (*t == src)
            *t = dst;
        return;
    }
    FUN_140159b70(0x80004005);
}
// CAtlMap::UpdateRehashThresholds
// @0x140286300
void FUN_140286300(i64 m)
{
    Q8(m, 0x20) = (u64)(*(float*)(m + 0x1c) * (float)U4(m, 0x10));
    Q8(m, 0x28) = (u64)(*(float*)(m + 0x18) * (float)U4(m, 0x10));
    if ((u64)Q8(m, 0x28) < 0x11)
        Q8(m, 0x28) = 0;
}
// @0x1402863e0
void FUN_1402863e0(i64 m)
{
    Q8(m, 0x20) = (u64)(*(float*)(m + 0x1c) * (float)U4(m, 0x10));
    Q8(m, 0x28) = (u64)(*(float*)(m + 0x18) * (float)U4(m, 0x10));
    if ((u64)Q8(m, 0x28) < 0x11)
        Q8(m, 0x28) = 0;
}
// std::vector / std::list container-proxy hooks: Free-proxy and element-ref release helpers
// @0x1402864c0
void FUN_1402864c0(i64 p) { if (Q8(p, 8) != 0) FUN_140286820(p, 0); }
// @0x1402864f0
void FUN_1402864f0(i64 p) { if (Q8(p, 8) != 0) FUN_140286850(p, 0); }
// @0x140286520
void FUN_140286520(i64 p) { if (Q8(p, 8) != 0) FUN_140286880(p, 0); }
// @0x140286550
void FUN_140286550(i64 p) { if (Q8(p, 8) != 0) FUN_1402868b0(p, 0); }
// @0x140286580
void FUN_140286580(i64 p) { if (Q8(p, 8) != 0) FUN_1402868e0(p, 0); }
// @0x1402865b0
void FUN_1402865b0(i64 p) { if (Q8(p, 8) != 0) FUN_140286910(p, 0); }
// @0x1402865e0
void FUN_1402865e0(i64 p) { if (Q8(p, 8) != 0) FUN_140286940(p, 0); }
// @0x140286610
void FUN_140286610(i64 p) { if (Q8(p, 8) != 0) FUN_140286970(p, 0); }
// @0x140286640
void FUN_140286640(i64 p) { if (Q8(p, 8) != 0) FUN_1402869a0(p, 0); }
// @0x140286670
void FUN_140286670(i64 p) { if (Q8(p, 8) != 0) FUN_1402869d0(p, 0); }
// @0x1402866a0
void FUN_1402866a0(i64 p) { FUN_14015b020(p); }
// @0x1402866c0
void FUN_1402866c0(i64 p) { FUN_14015b020(p); }
// @0x1402866e0
void FUN_1402866e0(i64 p) { FUN_14015b020(p); }
// @0x140286700
void FUN_140286700(i64 p) { FUN_14015b020(p); }
// @0x140286720
void FUN_140286720(i64 p) { FUN_14015b020(p); }
// @0x140286740
void FUN_140286740(i64 p) { FUN_14015b020(p); }
// @0x140286760
void FUN_140286760(i64 p) { FUN_14015b020(p); }
// @0x140286780
void FUN_140286780(i64 p) { FUN_14015b020(p); }
// @0x1402867a0
void FUN_1402867a0(i64 p) { FUN_14015b020(p); }
// @0x1402867c0
void FUN_1402867c0(i64 p) { FUN_14015b020(p); }
// @0x1402867e0
void FUN_1402867e0(i64 p) { FUN_14015b020(p); }
// @0x140286800
void FUN_140286800(i64 p) { FUN_14015b020(p); }
// @0x140286820
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140286820(i64 p, int) { FUN_1402866a0(Q8(p, 8)); }
// @0x140286850
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140286850(i64 p, int) { FUN_1402866c0(FUN_140281490(Q8(p, 8))); }
// @0x140286880
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140286880(i64 p, int) { FUN_1402866e0(Q8(p, 8)); }
// @0x1402868b0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402868b0(i64 p, int) { FUN_140286700(Q8(p, 8)); }
// @0x1402868e0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402868e0(i64 p, int) { FUN_140286720(Q8(p, 8)); }
// @0x140286910
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140286910(i64 p, int) { FUN_140286740(Q8(p, 8)); }
// @0x140286940
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140286940(i64 p, int) { FUN_140286760(Q8(p, 8)); }
// @0x140286970
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140286970(i64 p, int) { FUN_140286780(Q8(p, 8)); }
// @0x1402869a0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402869a0(i64 p, int) { FUN_1402867e0(Q8(p, 8)); }
// @0x1402869d0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402869d0(i64 p, int) { FUN_140286800(Q8(p, 8)); }
// @0x140286a00
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140286a00(i64 p)
{
    FUN_140288e10(p);
    i64 v = FUN_140286a30(0);
    Q8(p, 8) = v;
}
// @0x140286a30
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140286a30(i64 self)
{
    i64 a = FUN_140276880(0);
    a = FUN_1401ba820(a);
    return FUN_14027f280(a);
}
// std::vector<T>::_Buy(n) for element sizes 8 / 0x10
// @0x140286a60
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
u64 FUN_140286a60(i64 v, u64 n)
{
    *FUN_140288980((i64)v) = 0;
    *FUN_140288ae0(v) = 0;
    *FUN_140288840(v) = 0;
    u64 r;
    if (n == 0) {
        r = 0;
    } else {
        if (FUN_14028b090(v) < n)
            FUN_140289ea0();
        i64 mem = FUN_140289fc0(FUN_1402882f0(v), n);
        *FUN_140288980((i64)v) = mem;
        *FUN_140288ae0(v) = *FUN_140288980(v);
        *FUN_140288840(v) = *FUN_140288980(v) + n * 8;
        r = 1;
    }
    return r;
}
// @0x140286b50
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
u64 FUN_140286b50(i64 v, u64 n)
{
    *FUN_140288a80(v) = 0;
    *FUN_140288be0(v) = 0;
    *FUN_140288940(v) = 0;
    u64 r;
    if (n == 0) {
        r = 0;
    } else {
        if (FUN_14028b1d0(v) < n)
            FUN_140289f20();
        i64 mem = FUN_14028a080(FUN_1402883f0(v), n);
        *FUN_140288a80(v) = mem;
        *FUN_140288be0(v) = *FUN_140288a80(v);
        *FUN_140288940(v) = *FUN_140288a80(v) + n * 0x10;
        r = 1;
    }
    return r;
}
// @0x140286c40
void FUN_140286c40(i64 p) { FUN_140286d20(p, 0, 0); }
// std::_Tree::_Buyheadnode
// @0x140286c60
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140286c60(i64 self)
{
    i64 al = FUN_140288290(self);
    i64 node = FUN_140289f90(al, 1);
    i64 u = FUN_14027b530(node);
    FUN_14027b740(al, u, &node);
    u = FUN_14027b530(node + 8);
    FUN_14027b740(al, u, &node);
    u = FUN_14027b530(node + 0x10);
    FUN_14027b740(al, u, &node);
    C1(node, 0x18) = 1;
    C1(node, 0x19) = 1;
    return node;
}
// std::_Tree::_Buynode0(left, right)
// @0x140286d20
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140286d20(i64 self, i64 left, i64 right)
{
    i64 a[1];
    i64 b[1];
    a[0] = left;
    b[0] = right;
    i64 al = FUN_140288250(self);
    i64 node = FUN_140289f60(al, 1);
    if (a[0] == 0) {
        a[0] = node;
        b[0] = node;
    }
    i64 al2 = FUN_140288250(self);
    i64 u = FUN_14027b520(node);
    FUN_14027b6f0(al2, u, a);
    u = FUN_14027b520(node + 8);
    FUN_14027b6f0(al2, u, b);
    return node;
}
// @0x140286de0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64 FUN_140286de0(i64 self)
{
    i64 al = FUN_140288290(self);
    i64 node = FUN_140289f90(al, 1);
    i64* arg = FUN_140287eb0(self);
    i64 u = FUN_14027b530(node);
    FUN_14027b740(al, u, arg);
    u = FUN_14027b530(node + 8);
    FUN_14027b740(al, u, arg);
    u = FUN_14027b530(node + 0x10);
    FUN_14027b740(al, u, arg);
    return node;
}
// std::vector<T>::_Calculate_growth(newSize) for the five element types
// @0x140286ec0
u64 FUN_140286ec0(i64 v, u64 want)
{
    u64 old = FUN_14028a2c0(v);
    if (old > FUN_14028b090(v) - old / 2)
        return want;
    u64 geo = old + old / 2;
    if (geo < want)
        return want;
    return geo;
}
// @0x140286f50
u64 FUN_140286f50(i64 v, u64 want)
{
    u64 old = FUN_14028a300(v);
    if (old > FUN_14028b0e0(v) - old / 2)
        return want;
    u64 geo = old + old / 2;
    if (geo < want)
        return want;
    return geo;
}
// @0x140286fe0
u64 FUN_140286fe0(i64 v, u64 want)
{
    u64 old = FUN_14028a350(v);
    if (old > FUN_14028b130(v) - old / 2)
        return want;
    u64 geo = old + old / 2;
    if (geo < want)
        return want;
    return geo;
}
// @0x140287070
u64 FUN_140287070(i64 v, u64 want)
{
    u64 old = FUN_14028a390(v);
    if (old > FUN_14028b180(v) - old / 2)
        return want;
    u64 geo = old + old / 2;
    if (geo < want)
        return want;
    return geo;
}
// @0x140287100
u64 FUN_140287100(i64 v, u64 want)
{
    u64 old = FUN_14028a3d0(v);
    if (old > FUN_14028b1d0(v) - old / 2)
        return want;
    u64 geo = old + old / 2;
    if (geo < want)
        return want;
    return geo;
}
// std::vector<T>::_Change_array(newvec, newsize, newcap) for element sizes 0x30 / 8 / 0x10
// @0x140287190
void FUN_140287190(i64 v, i64 newvec, i64 newsize, i64 newcap)
{
    FUN_140288c80(v);
    if (*FUN_1402889c0(v) != 0) {
        FUN_1402875f0(v, *FUN_1402889c0(v), *FUN_140288b20(v));
        FUN_14028a800(FUN_140288330(v), *FUN_1402889c0(v), FUN_14028a300(v));
    }
    *FUN_1402889c0(v) = newvec;
    *FUN_140288b20(v) = newvec + newsize * 0x30;
    *FUN_140288880(v) = newvec + newcap * 0x30;
}
// @0x1402872a0
void FUN_1402872a0(i64 v, i64 newvec, i64 newsize, i64 newcap)
{
    FUN_140288ca0(v);
    if (*FUN_140288a00(v) != 0) {
        FUN_140287630(v, *FUN_140288a00(v), *FUN_140288b60(v));
        FUN_14028a830(FUN_140288370(v), *FUN_140288a00(v), FUN_14028a350(v));
    }
    *FUN_140288a00(v) = newvec;
    *FUN_140288b60(v) = newvec + newsize * 8;
    *FUN_1402888c0(v) = newvec + newcap * 8;
}
// @0x1402873b0
void FUN_1402873b0(i64 v, i64 newvec, i64 newsize, i64 newcap)
{
    FUN_140288cc0(v);
    if (*FUN_140288a40(v) != 0) {
        FUN_140287670(v, *FUN_140288a40(v), *FUN_140288ba0(v));
        FUN_14028a860(FUN_1402883b0(v), *FUN_140288a40(v), FUN_14028a390(v));
    }
    *FUN_140288a40(v) = newvec;
    *FUN_140288ba0(v) = newvec + newsize * 0x10;
    *FUN_140288900(v) = newvec + newcap * 0x10;
}
// @0x1402874c0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402874c0(i64 self, int* a, int* b)
{
    i64 cmp = FUN_140288450(self);
    FUN_14027f870(cmp, a, b);
}
// @0x140287500
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140287500(void) {}
// @0x140287510
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140287510(void) {}
// @0x140287520
void FUN_140287520(i64 self)
{
    i64 head = FUN_140286c60(self);
    *FUN_140287eb0(self) = head;
}
// allocator propagate-on-container-copy-assignment hooks
// @0x140287550
void FUN_140287550(i64 self, i64 other) { FUN_14027a4a0(FUN_1402882f0(self), other); }
// @0x140287580
void FUN_140287580(i64 self, i64 other) { FUN_14027a4e0(FUN_1402883f0(self), other); }
// std::vector<T>::_Destroy(first, last) per element type
// @0x1402875b0
void FUN_1402875b0(i64 self, i64 first, i64 last) { FUN_140277470(first, last, FUN_1402882f0(self)); }
// @0x1402875f0
void FUN_1402875f0(i64 self, i64 first, i64 last) { FUN_1402774c0(first, last, FUN_140288330(self)); }
// @0x140287630
void FUN_140287630(i64 self, i64 first, i64 last) { FUN_140277510(first, last, FUN_140288370(self)); }
// @0x140287670
void FUN_140287670(i64 self, i64 first, i64 last) { FUN_140277560(first, last, FUN_1402883b0(self)); }
// @0x1402876b0
void FUN_1402876b0(i64 self, i64 first, i64 last) { FUN_1402775b0(first, last, FUN_1402883f0(self)); }
// std::_Tree::_Freenode(node): destroy the value, then free the node
// @0x1402876f0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_1402876f0(i64 self, i64 node)
{
    i64 al = FUN_140288290(self);
    i64 val = FUN_14027b540(node + 0x1c);
    FUN_14027bb80(al, val);
    FUN_140278630(al, node);
}
// std::_Tree::_Erase(root)
// @0x140287740
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140287740(i64 self, i64* root)
{
    i64* node = root;
    while (C1(node, 0x19) == 0) {
        FUN_140287740(self, (i64*)node[2]);
        i64* next = (i64*)*node;
        i64 al = FUN_140288290(self);
        i64 val = FUN_14027b540((i64)node + 0x1c);
        FUN_14027bb80(al, val);
        FUN_140278630(al, (i64)node);
        node = next;
    }
}
// std::_Tree_val::_Extract(_Where): unlink the node and rebalance
// @0x1402877e0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_1402877e0(i64 self, i64* where)
{
    i64* it[3];
    it[0] = where;
    FUN_14027f600((i64*)it);
    i64* erased = where;
    i64* pnode = where;
    i64* fix;
    i64* fixparent;
    if (C1(*erased, 0x19) == 0) {
        if (C1(erased[2], 0x19) == 0) {
            pnode = it[0];
            fix = (i64*)it[0][2];
        } else {
            fix = (i64*)*erased;
        }
    } else {
        fix = (i64*)erased[2];
    }
    if (pnode == erased) {
        fixparent = (i64*)erased[1];
        if (C1(fix, 0x19) == 0)
            fix[1] = (i64)fixparent;
        if ((i64*)*FUN_1402894c0(self) == erased)
            *FUN_1402894c0(self) = (i64)fix;
        else if ((i64*)*fixparent == erased)
            *fixparent = (i64)fix;
        else
            fixparent[2] = (i64)fix;
        if ((i64*)*FUN_140288630(self) == erased) {
            i64* lm = fixparent;
            if (C1(fix, 0x19) == 0)
                lm = (i64*)FUN_140288810((i64)fix);
            *FUN_140288630(self) = (i64)lm;
        }
        if ((i64*)*FUN_1402894a0(self) == erased) {
            i64* rm = fixparent;
            if (C1(fix, 0x19) == 0)
                rm = (i64*)FUN_1402887e0((i64)fix);
            *FUN_1402894a0(self) = (i64)rm;
        }
    } else {
        *(i64*)(*erased + 8) = (i64)pnode;
        *pnode = *erased;
        if (pnode == (i64*)erased[2]) {
            fixparent = pnode;
        } else {
            fixparent = (i64*)pnode[1];
            if (C1(fix, 0x19) == 0)
                fix[1] = (i64)fixparent;
            *fixparent = (i64)fix;
            pnode[2] = erased[2];
            *(i64*)(erased[2] + 8) = (i64)pnode;
        }
        if ((i64*)*FUN_1402894c0(self) == erased)
            *FUN_1402894c0(self) = (i64)pnode;
        else if (*(i64**)erased[1] == erased)
            *(i64**)erased[1] = pnode;
        else
            *(i64**)(erased[1] + 0x10) = pnode;
        pnode[1] = erased[1];
        FUN_140163110((char*)(pnode + 3), (char*)(erased + 3));
    }
    if ((char)erased[3] == 1) {
        for (; fix != (i64*)*FUN_1402894c0(self) && (char)fix[3] == 1; fixparent = (i64*)fix[1]) {
            if (fix == (i64*)*fixparent) {
                pnode = (i64*)fixparent[2];
                if ((char)pnode[3] == 0) {
                    C1(pnode, 0x18) = 1;
                    C1(fixparent, 0x18) = 0;
                    FUN_140288640(self, (i64)fixparent);
                    pnode = (i64*)fixparent[2];
                }
                if (C1(pnode, 0x19) != 0) {
                    fix = fixparent;
                } else if (C1(*pnode, 0x18) == 1 && C1(pnode[2], 0x18) == 1) {
                    C1(pnode, 0x18) = 0;
                    fix = fixparent;
                } else {
                    if (C1(pnode[2], 0x18) == 1) {
                        C1(*pnode, 0x18) = 1;
                        C1(pnode, 0x18) = 0;
                        FUN_1402894e0(self, (i64)pnode);
                        pnode = (i64*)fixparent[2];
                    }
                    C1(pnode, 0x18) = C1(fixparent, 0x18);
                    C1(fixparent, 0x18) = 1;
                    C1(pnode[2], 0x18) = 1;
                    FUN_140288640(self, (i64)fixparent);
                    break;
                }
            } else {
                pnode = (i64*)*fixparent;
                if ((char)pnode[3] == 0) {
                    C1(pnode, 0x18) = 1;
                    C1(fixparent, 0x18) = 0;
                    FUN_1402894e0(self, (i64)fixparent);
                    pnode = (i64*)*fixparent;
                }
                if (C1(pnode, 0x19) != 0) {
                    fix = fixparent;
                } else if (C1(pnode[2], 0x18) == 1 && C1(*pnode, 0x18) == 1) {
                    C1(pnode, 0x18) = 0;
                    fix = fixparent;
                } else {
                    if (C1(*pnode, 0x18) == 1) {
                        C1(pnode[2], 0x18) = 1;
                        C1(pnode, 0x18) = 0;
                        FUN_140288640(self, (i64)pnode);
                        pnode = (i64*)*fixparent;
                    }
                    C1(pnode, 0x18) = C1(fixparent, 0x18);
                    C1(fixparent, 0x18) = 1;
                    C1(*pnode, 0x18) = 1;
                    FUN_1402894e0(self, (i64)fixparent);
                    break;
                }
            }
        }
        C1(fix, 0x18) = 1;
    }
    if (Q8(self, 8) != 0)
        Q8(self, 8) = Q8(self, 8) - 1;
    return erased;
}
// @0x140287d90
void FUN_140287d90(i64 self, i64 p) { FUN_1402785c0(FUN_140288250(self), p); }
// @0x140287dc0
void FUN_140287dc0(i64 self, i64 p) { FUN_140278630(FUN_140288290(self), p); }
// @0x140287df0
void FUN_140287df0(i64 self, i64 p) { FUN_140278630(FUN_140288290(self), p); }
// @0x140287e20
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140287e20(i64 self, i64 node)
{
    i64 al = FUN_140288250(self);
    i64 val = FUN_14027b550(node + 0x10);
    FUN_14027bc00(al, val);
    FUN_1402785c0(al, node);
}
// @0x140287e70
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140287e70(i64 p) { FUN_140288170(p); }
// @0x140287e90
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140287e90(i64 p) { FUN_140288180(p); }
// @0x140287eb0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_140287eb0(i64 p) { return FUN_140288190(FUN_140288150(p)); }
// @0x140287ee0
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
i64* FUN_140287ee0(i64 p) { return FUN_1402881a0(FUN_140288160(p)); }
// @0x140287f10
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140287f10(i64 p) { FUN_1402881b0(p); }
// @0x140287f30
// MS2-FUNCTIONAL: ATL/STL template instantiation over unrecovered element types, written as typed free-function helpers; codegen differs in temps/spills/param widths, logic identical
void FUN_140287f30(i64 p) { FUN_1402881c0(p); }
