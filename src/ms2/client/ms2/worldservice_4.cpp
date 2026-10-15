// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService, part 4 of 4 (owner ws1).
// Functional tier: generated from the Ghidra decompile (work/ws/gen.py) as plain tagged functions.
// MS2-UNIT: ?\worldservice.cpp#4
// MS2-RANGE: 0x141bf2b70-0x141bf7060 .text$mn
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

struct ActorRemovedMessage { void* a; void* b; };   // size UNVERIFIED
struct AssetID { void* a; void* b; };   // size UNVERIFIED
struct CInteractWebObject { void* a; void* b; };   // size UNVERIFIED
struct CLiftableTargetBox { void* a; void* b; };   // size UNVERIFIED
struct CLiftableTargetGuide { void* a; void* b; };   // size UNVERIFIED
struct NotifyChangeServer { void* a; void* b; };   // size UNVERIFIED
struct NotifyCreateMyPC { void* a; void* b; };   // size UNVERIFIED
struct NotifyGameStart { void* a; void* b; };   // size UNVERIFIED
struct NotifyRemoveGameObject { void* a; void* b; };   // size UNVERIFIED
struct TextureLayerManager { void* a; void* b; };   // size UNVERIFIED
struct scheduler_resource_allocation_error { void* a; void* b; };   // size UNVERIFIED
// ---- callees in the exe (variadic prototypes, return types from the decompile; bound by VA at link) ----
undefined8 FUN_140159840(...);
undefined8 FUN_14016ad80(...);
undefined8 FUN_1401cd100(...);
undefined4 * FUN_14027db40(...);
undefined8 FUN_1405a93d0(...);
undefined8 FUN_1406c70a0(...);
ulonglong * FUN_1408995b0(...);
undefined8 FUN_140899bd0(...);
longlong * FUN_1408a7ed0(...);
undefined8 FUN_1408a8720(...);
longlong * FUN_1408b6680(...);
undefined8 FUN_1408b6b20(...);
void * FUN_140939070(...);
undefined8 FUN_140939260(...);
undefined8 FUN_140961b80(...);
undefined8 FUN_140961bd0(...);
longlong * FUN_140963d50(...);
longlong FUN_140963ff0(...);
longlong FUN_140964030(...);
undefined8 FUN_140964830(...);
undefined8 FUN_140964870(...);
undefined8 FUN_1409649b0(...);
undefined8 FUN_1409649e0(...);
undefined8 FUN_140964a10(...);
undefined8 FUN_140964a70(...);
undefined8 FUN_140968bd0(...);
undefined8 FUN_140969d60(...);
undefined8 FUN_140969da0(...);
undefined8 FUN_140980460(...);
undefined8 FUN_1409f20a0(...);
undefined8 FUN_1409f20e0(...);
undefined8 FUN_1409f25e0(...);
longlong * FUN_140a000a0(...);
longlong * FUN_140a000f0(...);
undefined8 FUN_140a00490(...);
undefined8 FUN_140a16650(...);
longlong * FUN_140a7b390(...);
longlong FUN_140a7b410(...);
undefined8 FUN_140a7b530(...);
undefined8 FUN_140a7bac0(...);
undefined8 FUN_140aac150(...);
longlong FUN_140ac5930(...);
longlong FUN_140ae13b0(...);
undefined8 FUN_140ae16b0(...);
undefined8 FUN_140b28610(...);
longlong FUN_140b2d2a0(...);
longlong FUN_140b2d2d0(...);
undefined8 FUN_140b2da40(...);
longlong * FUN_140c20410(...);
undefined8 FUN_140d28f40(...);
void * FUN_1410470b0(...);
undefined8 FUN_1410473c0(...);
longlong * FUN_1410a6960(...);
undefined8 FUN_1410a6c00(...);
undefined8 FUN_1410b4290(...);
undefined8 FUN_1410b4790(...);
undefined8 FUN_141125e50(...);
undefined8 FUN_141125f30(...);
longlong FUN_14123eb50(...);
undefined8 FUN_14123ebe0(...);
undefined8 FUN_141375010(...);
undefined8 FUN_141375140(...);
undefined8 FUN_1413751c0(...);
undefined8 FUN_1413fd240(...);
undefined8 FUN_1413fd380(...);
void * FUN_141441ec0(...);
undefined8 FUN_141448190(...);
undefined8 FUN_141448230(...);
longlong FUN_1416c2ba0(...);
undefined8 FUN_141746770(...);
undefined8 FUN_14174a7f0(...);
undefined8 FUN_14174b2b0(...);
undefined8 FUN_141b94450(...);
undefined8 FUN_141bdbaf0(...);
undefined8 FUN_141bdbb20(...);
undefined8 FUN_141bdbb50(...);
undefined8 FUN_141bdbb80(...);
undefined8 FUN_141bde8e0(...);
undefined8 FUN_141bde930(...);
undefined8 FUN_141bde980(...);
longlong * FUN_141bf0fd0(...);
longlong * FUN_141bf10a0(...);
longlong FUN_141bf11b0(...);
longlong FUN_141bf11e0(...);
longlong FUN_141bf12c0(...);
longlong FUN_141bf1330(...);
longlong FUN_141bf13c0(...);
longlong FUN_141bf1490(...);
longlong FUN_141bf15b0(...);
longlong FUN_141bf1670(...);
longlong FUN_141bf1700(...);
longlong FUN_141bf1720(...);
longlong FUN_141bf17b0(...);
longlong FUN_141bf1900(...);
undefined8 FUN_141bf1aa0(...);
undefined8 FUN_141bf1c30(...);
undefined8 FUN_141bf1c60(...);
undefined8 FUN_141bf1c90(...);
undefined8 FUN_141bf1cc0(...);
undefined8 FUN_141bf1cf0(...);
undefined8 FUN_141bf1d20(...);
undefined8 FUN_141bf1d50(...);
undefined8 FUN_141bf1d80(...);
undefined8 FUN_141bf1db0(...);
undefined8 FUN_141bf1de0(...);
undefined8 FUN_141bfaee0(...);
undefined8 FUN_141c16150(...);
undefined8 FUN_141c16230(...);
undefined8 FUN_141c16340(...);
undefined8 FUN_141c16450(...);
undefined8 FUN_141c16560(...);
undefined8 FUN_141c16670(...);
undefined8 FUN_141c16780(...);
undefined8 FUN_141c16890(...);
undefined8 FUN_141c169a0(...);
undefined8 FUN_141c16ab0(...);
undefined8 FUN_141c16bc0(...);
undefined8 FUN_141c16cd0(...);
undefined8 FUN_141c16de0(...);
undefined8 FUN_141c16e60(...);
undefined8 FUN_141c16ee0(...);
undefined8 FUN_141c16f60(...);
undefined8 FUN_141c16fe0(...);
undefined8 FUN_141c17060(...);
undefined8 FUN_141c170e0(...);
undefined8 FUN_141c17160(...);
undefined8 FUN_141c171e0(...);
undefined8 FUN_141c17260(...);
undefined8 FUN_141c172e0(...);
undefined8 FUN_141c17360(...);
undefined8 FUN_141c173e0(...);
undefined8 FUN_141c17460(...);
undefined8 FUN_141c174e0(...);
undefined8 FUN_141c17560(...);
undefined8 FUN_141c175e0(...);
undefined8 FUN_141c1f4a0(...);
undefined8 FUN_141c1f4d0(...);
undefined8 FUN_141c1f500(...);
undefined8 FUN_141c1f5c0(...);
undefined8 FUN_141c1f5f0(...);
undefined8 FUN_141c25b50(...);
undefined8 FUN_141c25b80(...);
undefined8 FUN_141c25bb0(...);
undefined8 FUN_141c25be0(...);
undefined8 FUN_141c25c10(...);
undefined8 FUN_141c25c40(...);
undefined8 FUN_141c25c70(...);
undefined8 FUN_141c25ca0(...);
undefined8 FUN_141c25cd0(...);
undefined8 FUN_141c25d00(...);
undefined8 FUN_141c25d30(...);
undefined8 FUN_141c26000(...);
undefined8 FUN_141c26060(...);
undefined8 FUN_141c260c0(...);
undefined8 FUN_141c26120(...);
undefined8 FUN_141c26180(...);
undefined8 FUN_141c261e0(...);
undefined8 FUN_141c26240(...);
undefined8 FUN_141c262a0(...);
undefined8 FUN_141c26300(...);
undefined8 FUN_141c26360(...);
undefined8 FUN_141c28930(...);
undefined8 FUN_141c28c80(...);
undefined8 FUN_141c28cc0(...);
undefined8 FUN_141c28d00(...);
undefined8 FUN_141c28d40(...);
undefined8 FUN_141c28d80(...);
undefined8 FUN_141c28dc0(...);
undefined8 FUN_141c28e00(...);
undefined8 FUN_141c29c50(...);
undefined8 FUN_141c29cb0(...);
undefined8 FUN_141c29d10(...);
undefined8 FUN_141c29d70(...);
undefined8 FUN_141c29dd0(...);
undefined8 FUN_141c29e30(...);
undefined8 FUN_141c29e90(...);
undefined8 FUN_141c29ef0(...);
undefined8 FUN_141c29f50(...);
undefined8 FUN_141c29fb0(...);
undefined8 FUN_141c2a000(...);
undefined8 FUN_141c2a020(...);
undefined8 FUN_141c2a0f0(...);
undefined8 FUN_141c2a1c0(...);
undefined8 FUN_141c2a290(...);
undefined8 FUN_1420b1020(...);
// ---- functions of this unit (forward declarations) ----
undefined8 FUN_141bf2b70(...);
undefined8 * FUN_141bf2b70(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2bb0(...);
undefined8 * FUN_141bf2bb0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2bf0(...);
undefined8 * FUN_141bf2bf0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2c30(...);
undefined8 * FUN_141bf2c30(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2c70(...);
undefined8 FUN_141bf2c70(undefined8 param_1);
undefined8 FUN_141bf2ca0(...);
undefined8 FUN_141bf2ca0(undefined8 param_1);
undefined8 FUN_141bf2cd0(...);
undefined8 FUN_141bf2cd0(undefined8 param_1);
undefined8 FUN_141bf2d00(...);
undefined8 FUN_141bf2d00(undefined8 param_1);
undefined8 FUN_141bf2d30(...);
undefined8 * FUN_141bf2d30(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2d70(...);
undefined8 FUN_141bf2d70(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf2db0(...);
undefined8 * FUN_141bf2db0(undefined8 *param_1);
undefined8 FUN_141bf2df0(...);
undefined8 * FUN_141bf2df0(undefined8 *param_1);
undefined8 FUN_141bf2e30(...);
undefined8 * FUN_141bf2e30(undefined8 *param_1);
undefined8 FUN_141bf2e70(...);
undefined8 * FUN_141bf2e70(undefined8 *param_1);
undefined8 FUN_141bf2eb0(...);
undefined8 FUN_141bf2eb0(undefined8 param_1);
undefined8 FUN_141bf2ec0(...);
undefined8 FUN_141bf2ec0(undefined8 param_1);
undefined8 FUN_141bf2ed0(...);
undefined8 FUN_141bf2ed0(undefined8 param_1);
undefined8 FUN_141bf2ee0(...);
undefined8 FUN_141bf2ee0(undefined8 param_1);
undefined8 FUN_141bf2ef0(...);
undefined8 FUN_141bf2ef0(undefined8 param_1);
undefined8 FUN_141bf2f00(...);
undefined8 FUN_141bf2f00(undefined8 param_1);
undefined8 FUN_141bf2f10(...);
undefined8 FUN_141bf2f10(undefined8 param_1);
undefined8 FUN_141bf2f20(...);
undefined8 FUN_141bf2f20(undefined8 param_1);
undefined8 FUN_141bf2f30(...);
undefined8 FUN_141bf2f30(undefined8 param_1);
undefined8 FUN_141bf2f40(...);
undefined8 FUN_141bf2f40(undefined8 param_1);
undefined8 FUN_141bf2f50(...);
undefined8 FUN_141bf2f50(undefined8 param_1);
undefined8 FUN_141bf2f60(...);
undefined8 FUN_141bf2f60(undefined8 param_1);
undefined8 FUN_141bf2f70(...);
undefined8 FUN_141bf2f70(undefined8 param_1);
undefined8 FUN_141bf2f80(...);
undefined8 FUN_141bf2f80(undefined8 param_1);
undefined8 FUN_141bf2f90(...);
undefined8 FUN_141bf2f90(undefined8 param_1);
undefined8 FUN_141bf2fa0(...);
undefined8 FUN_141bf2fa0(undefined8 param_1);
undefined8 FUN_141bf2fc0(...);
undefined8 FUN_141bf2fc0(undefined8 param_1);
undefined8 FUN_141bf2ff0(...);
undefined8 FUN_141bf2ff0(undefined8 param_1);
undefined8 FUN_141bf3020(...);
undefined8 FUN_141bf3020(undefined8 param_1);
undefined8 FUN_141bf3050(...);
undefined8 FUN_141bf3050(undefined8 param_1);
undefined8 FUN_141bf3080(...);
undefined8 FUN_141bf3080(undefined8 param_1);
undefined8 FUN_141bf30b0(...);
undefined8 FUN_141bf30b0(undefined8 param_1);
undefined8 FUN_141bf30e0(...);
undefined8 FUN_141bf30e0(undefined8 param_1);
undefined8 FUN_141bf3110(...);
undefined8 FUN_141bf3110(undefined8 param_1);
undefined8 FUN_141bf3140(...);
undefined8 FUN_141bf3140(undefined8 param_1);
undefined8 FUN_141bf3170(...);
undefined1 * FUN_141bf3170(undefined1 *param_1, undefined1 *param_2);
undefined8 FUN_141bf31d0(...);
undefined1 * FUN_141bf31d0(undefined1 *param_1, undefined1 *param_2);
undefined8 FUN_141bf3230(...);
undefined1 * FUN_141bf3230(undefined1 *param_1, undefined1 *param_2, undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf3280(...);
undefined1 * FUN_141bf3280(undefined1 *param_1, undefined1 *param_2, undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf32d0(...);
undefined8 FUN_141bf32d0(undefined8 param_1);
undefined8 FUN_141bf3300(...);
undefined8 FUN_141bf3300(undefined8 param_1);
undefined8 FUN_141bf3330(...);
undefined8 FUN_141bf3330(undefined8 param_1);
undefined8 FUN_141bf3360(...);
undefined8 FUN_141bf3360(undefined8 param_1);
undefined8 FUN_141bf3390(...);
undefined8 FUN_141bf3390(undefined8 param_1);
undefined8 FUN_141bf33c0(...);
 ActorRemovedMessage *  FUN_141bf33c0(ActorRemovedMessage *this_,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf3410(...);
AssetID * FUN_141bf3410(AssetID *param_1,undefined8 param_2,undefined4 param_3);
undefined8 FUN_141bf3460(...);
undefined1 * FUN_141bf3460(undefined1 *param_1);
undefined8 FUN_141bf34d0(...);
undefined1 * FUN_141bf34d0(undefined1 *param_1);
undefined8 FUN_141bf3570(...);
CInteractWebObject *  FUN_141bf3570(CInteractWebObject *this_);
undefined8 FUN_141bf35a0(...);
CLiftableTargetBox *  FUN_141bf35a0(CLiftableTargetBox *this_);
undefined8 FUN_141bf35d0(...);
CLiftableTargetGuide *  FUN_141bf35d0(CLiftableTargetGuide *this_);
undefined8 FUN_141bf3610(...);
longlong FUN_141bf3610(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf3640(...);
longlong FUN_141bf3640(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf3670(...);
longlong FUN_141bf3670(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf36a0(...);
longlong FUN_141bf36a0(longlong param_1,undefined4 param_2,undefined4 param_3);
undefined8 FUN_141bf36e0(...);
longlong FUN_141bf36e0(longlong param_1,undefined4 param_2,undefined4 param_3);
undefined8 FUN_141bf3720(...);
longlong FUN_141bf3720(longlong param_1,undefined4 param_2,undefined4 param_3);
undefined8 FUN_141bf3760(...);
longlong FUN_141bf3760(longlong param_1,undefined4 param_2,undefined4 param_3);
undefined8 FUN_141bf37a0(...);
longlong FUN_141bf37a0(longlong param_1,undefined4 param_2,undefined4 param_3);
undefined8 FUN_141bf37e0(...);
longlong FUN_141bf37e0(longlong param_1,undefined4 param_2,undefined4 param_3);
undefined8 FUN_141bf3820(...);
longlong FUN_141bf3820(longlong param_1,undefined8 param_2,undefined4 param_3);
undefined8 FUN_141bf3860(...);
longlong FUN_141bf3860(longlong param_1,undefined8 param_2,undefined4 param_3);
undefined8 FUN_141bf38a0(...);
longlong FUN_141bf38a0(longlong param_1,undefined8 param_2,undefined4 param_3);
undefined8 FUN_141bf38e0(...);
longlong FUN_141bf38e0(longlong param_1,undefined8 param_2,undefined4 param_3);
undefined8 FUN_141bf3920(...);
longlong FUN_141bf3920(longlong param_1,undefined8 param_2,undefined4 param_3);
undefined8 FUN_141bf3960(...);
longlong FUN_141bf3960(longlong param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf39b0(...);
longlong FUN_141bf39b0(longlong param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf3a00(...);
longlong FUN_141bf3a00(longlong param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf3a50(...);
longlong FUN_141bf3a50(longlong param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf3aa0(...);
longlong FUN_141bf3aa0(longlong param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf3af0(...);
longlong FUN_141bf3af0(longlong param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf3b40(...);
longlong FUN_141bf3b40(longlong param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf3b90(...);
longlong FUN_141bf3b90(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3be0(...);
longlong FUN_141bf3be0(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3c30(...);
longlong FUN_141bf3c30(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3c80(...);
longlong FUN_141bf3c80(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3cd0(...);
longlong FUN_141bf3cd0(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3d20(...);
longlong FUN_141bf3d20(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3d70(...);
longlong FUN_141bf3d70(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3dc0(...);
longlong FUN_141bf3dc0(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3e10(...);
longlong FUN_141bf3e10(longlong param_1,undefined8 param_2,undefined4 param_3);
undefined8 FUN_141bf3e60(...);
longlong FUN_141bf3e60(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf3eb0(...);
 undefined4 * FUN_141bf3eb0(undefined4 *param_1,undefined4 param_2);
undefined8 FUN_141bf3ef0(...);
undefined4 * FUN_141bf3ef0(undefined4 *param_1,undefined4 param_2);
undefined8 FUN_141bf3f30(...);
 undefined4 * FUN_141bf3f30(undefined4 *param_1,undefined4 param_2);
undefined8 FUN_141bf3f70(...);
 undefined4 * FUN_141bf3f70(undefined4 *param_1,undefined4 param_2);
undefined8 FUN_141bf3fb0(...);
 undefined4 * FUN_141bf3fb0(undefined4 *param_1,undefined4 param_2);
undefined8 FUN_141bf3ff0(...);
 undefined4 * FUN_141bf3ff0(undefined4 *param_1,undefined4 param_2);
undefined8 FUN_141bf4030(...);
undefined4 * FUN_141bf4030(undefined4 *param_1,undefined4 *param_2);
undefined8 FUN_141bf4070(...);
undefined8 * FUN_141bf4070(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf40b0(...);
 undefined8 * FUN_141bf40b0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf40f0(...);
 undefined8 * FUN_141bf40f0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf4130(...);
 undefined8 * FUN_141bf4130(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bf4170(...);
undefined4 * FUN_141bf4170(undefined4 *param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf41b0(...);
undefined4 * FUN_141bf41b0(undefined4 *param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf41f0(...);
undefined4 * FUN_141bf41f0(undefined4 *param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf4230(...);
undefined4 * FUN_141bf4230(undefined4 *param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf4270(...);
undefined4 * FUN_141bf4270(undefined4 *param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf42b0(...);
undefined4 * FUN_141bf42b0(undefined4 *param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf42f0(...);
undefined4 * FUN_141bf42f0(undefined4 *param_1,undefined4 param_2,undefined8 param_3);
undefined8 FUN_141bf4330(...);
undefined8 * FUN_141bf4330(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3);
undefined8 FUN_141bf4370(...);
 undefined8 * FUN_141bf4370(undefined8 *param_1,undefined8 *param_2,undefined8 param_3);
undefined8 FUN_141bf43c0(...);
undefined1 * FUN_141bf43c0(undefined1 *param_1, undefined1 *param_2, undefined8 param_3);
undefined8 FUN_141bf4420(...);
undefined1 * FUN_141bf4420(undefined1 *param_1, undefined1 *param_2, undefined8 param_3);
undefined8 FUN_141bf4480(...);
undefined1 * FUN_141bf4480(undefined1 *param_1, undefined1 *param_2, undefined8 param_3);
undefined8 FUN_141bf44e0(...);
undefined1 * FUN_141bf44e0(undefined1 *param_1, undefined1 *param_2, undefined8 param_3);
undefined8 FUN_141bf4540(...);
undefined1 * FUN_141bf4540(undefined1 *param_1, undefined1 *param_2, undefined8 param_3);
undefined8 FUN_141bf45a0(...);
longlong FUN_141bf45a0(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf45f0(...);
undefined4 * FUN_141bf45f0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3);
undefined8 FUN_141bf4620(...);
undefined8 * FUN_141bf4620(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bf4660(...);
undefined8 * FUN_141bf4660(undefined8 *param_1,undefined8 *param_2);
undefined8 FUN_141bf46d0(...);
undefined8 * FUN_141bf46d0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4, undefined4 param_5);
undefined8 FUN_141bf4740(...);
undefined8 * FUN_141bf4740(undefined8 *param_1);
undefined8 FUN_141bf4790(...);
NotifyChangeServer *  FUN_141bf4790(NotifyChangeServer *this_);
undefined8 FUN_141bf47c0(...);
NotifyCreateMyPC *  FUN_141bf47c0(NotifyCreateMyPC *this_);
undefined8 FUN_141bf47f0(...);
NotifyGameStart *  FUN_141bf47f0(NotifyGameStart *this_);
undefined8 FUN_141bf4820(...);
 scheduler_resource_allocation_error *  FUN_141bf4820(scheduler_resource_allocation_error *this_,long param_1);
undefined8 FUN_141bf4860(...);
longlong FUN_141bf4860(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf48b0(...);
longlong FUN_141bf48b0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf48f0(...);
TextureLayerManager *  FUN_141bf48f0(TextureLayerManager *this_);
undefined8 FUN_141bf4920(...);
 void  FUN_141bf4920(undefined1 *this_);
undefined8 FUN_141bf4960(...);
void FUN_141bf4960(undefined8 param_1);
undefined8 FUN_141bf4980(...);
void FUN_141bf4980(undefined8 param_1);
undefined8 FUN_141bf49b0(...);
void FUN_141bf49b0(undefined8 param_1);
undefined8 FUN_141bf49e0(...);
void FUN_141bf49e0(undefined8 param_1);
undefined8 FUN_141bf4a10(...);
void FUN_141bf4a10(undefined8 param_1);
undefined8 FUN_141bf4a40(...);
void FUN_141bf4a40(undefined8 param_1);
undefined8 FUN_141bf4a70(...);
void FUN_141bf4a70(undefined8 param_1);
undefined8 FUN_141bf4aa0(...);
void FUN_141bf4aa0(undefined8 param_1);
undefined8 FUN_141bf4ad0(...);
void FUN_141bf4ad0(undefined8 param_1);
undefined8 FUN_141bf4b00(...);
void FUN_141bf4b00(undefined8 param_1);
undefined8 FUN_141bf4b30(...);
void FUN_141bf4b30(undefined8 param_1);
undefined8 FUN_141bf4b60(...);
void FUN_141bf4b60(undefined8 param_1);
undefined8 FUN_141bf4b90(...);
void FUN_141bf4b90(undefined8 param_1);
undefined8 FUN_141bf4bb0(...);
void FUN_141bf4bb0(undefined8 param_1);
undefined8 FUN_141bf4bd0(...);
void FUN_141bf4bd0(undefined8 param_1);
undefined8 FUN_141bf4bf0(...);
void FUN_141bf4bf0(undefined8 param_1);
undefined8 FUN_141bf4c10(...);
void FUN_141bf4c10(undefined8 param_1);
undefined8 FUN_141bf4c30(...);
void FUN_141bf4c30(undefined8 param_1);
undefined8 FUN_141bf4c50(...);
void FUN_141bf4c50(undefined8 param_1);
undefined8 FUN_141bf4c70(...);
void FUN_141bf4c70(undefined8 param_1);
undefined8 FUN_141bf4c90(...);
void FUN_141bf4c90(undefined8 param_1);
undefined8 FUN_141bf4cb0(...);
void FUN_141bf4cb0(undefined8 param_1);
undefined8 FUN_141bf4cd0(...);
void FUN_141bf4cd0(undefined8 param_1);
undefined8 FUN_141bf4cf0(...);
void FUN_141bf4cf0(undefined8 param_1);
undefined8 FUN_141bf4d10(...);
void FUN_141bf4d10(undefined8 param_1);
undefined8 FUN_141bf4d30(...);
void FUN_141bf4d30(undefined8 param_1);
undefined8 FUN_141bf4d50(...);
void FUN_141bf4d50(undefined8 param_1);
undefined8 FUN_141bf4d70(...);
void FUN_141bf4d70(undefined8 param_1);
undefined8 FUN_141bf4d90(...);
void FUN_141bf4d90(undefined8 param_1);
undefined8 FUN_141bf4db0(...);
void FUN_141bf4db0(longlong param_1);
undefined8 FUN_141bf4df0(...);
void FUN_141bf4df0(longlong param_1);
undefined8 FUN_141bf4e30(...);
void FUN_141bf4e30(longlong param_1);
undefined8 FUN_141bf4e70(...);
void FUN_141bf4e70(longlong param_1);
undefined8 FUN_141bf4eb0(...);
void FUN_141bf4eb0(longlong param_1);
undefined8 FUN_141bf4ef0(...);
void FUN_141bf4ef0(longlong param_1);
undefined8 FUN_141bf4f30(...);
void FUN_141bf4f30(longlong param_1);
undefined8 FUN_141bf4f70(...);
void FUN_141bf4f70(longlong param_1);
undefined8 FUN_141bf4fb0(...);
void FUN_141bf4fb0(longlong param_1);
undefined8 FUN_141bf4ff0(...);
void FUN_141bf4ff0(longlong param_1);
undefined8 FUN_141bf5030(...);
void FUN_141bf5030(longlong param_1);
undefined8 FUN_141bf5070(...);
void FUN_141bf5070(longlong param_1);
undefined8 FUN_141bf50b0(...);
void FUN_141bf50b0(longlong param_1);
undefined8 FUN_141bf50f0(...);
void FUN_141bf50f0(longlong param_1);
undefined8 FUN_141bf5130(...);
void FUN_141bf5130(longlong param_1);
undefined8 FUN_141bf5170(...);
void FUN_141bf5170(longlong param_1);
undefined8 FUN_141bf51b0(...);
void FUN_141bf51b0(longlong param_1);
undefined8 FUN_141bf51f0(...);
void  FUN_141bf51f0(undefined1 *this_);
undefined8 FUN_141bf5210(...);
void  FUN_141bf5210(undefined1 *this_);
undefined8 FUN_141bf5230(...);
void  FUN_141bf5230(undefined1 *this_);
undefined8 FUN_141bf5250(...);
void  FUN_141bf5250(undefined1 *this_);
undefined8 FUN_141bf5270(...);
void  FUN_141bf5270(undefined1 *this_);
undefined8 FUN_141bf5290(...);
void  FUN_141bf5290(undefined1 *this_);
undefined8 FUN_141bf52b0(...);
void  FUN_141bf52b0(undefined1 *this_);
undefined8 FUN_141bf52d0(...);
void  FUN_141bf52d0(undefined1 *this_);
undefined8 FUN_141bf52f0(...);
void  FUN_141bf52f0(undefined1 *this_);
undefined8 FUN_141bf5310(...);
void  FUN_141bf5310(undefined1 *this_);
undefined8 FUN_141bf5330(...);
void  FUN_141bf5330(undefined1 *this_);
undefined8 FUN_141bf5350(...);
void  FUN_141bf5350(undefined1 *this_);
undefined8 FUN_141bf5370(...);
void  FUN_141bf5370(undefined1 *this_);
undefined8 FUN_141bf5390(...);
void  FUN_141bf5390(undefined1 *this_);
undefined8 FUN_141bf53b0(...);
void  FUN_141bf53b0(undefined1 *this_);
undefined8 FUN_141bf53d0(...);
void  FUN_141bf53d0(undefined1 *this_);
undefined8 FUN_141bf53f0(...);
void  FUN_141bf53f0(undefined1 *this_);
undefined8 FUN_141bf5410(...);
void FUN_141bf5410(longlong *param_1);
undefined8 FUN_141bf5440(...);
void FUN_141bf5440(longlong *param_1);
undefined8 FUN_141bf5470(...);
void FUN_141bf5470(longlong *param_1);
undefined8 FUN_141bf54a0(...);
void FUN_141bf54a0(longlong *param_1);
undefined8 FUN_141bf54e0(...);
void FUN_141bf54e0(longlong *param_1);
undefined8 FUN_141bf5510(...);
void FUN_141bf5510(longlong *param_1);
undefined8 FUN_141bf5540(...);
void FUN_141bf5540(longlong *param_1);
undefined8 FUN_141bf5570(...);
void FUN_141bf5570(undefined8 param_1);
undefined8 FUN_141bf55a0(...);
void FUN_141bf55a0(undefined8 param_1);
undefined8 FUN_141bf55d0(...);
void FUN_141bf55d0(undefined8 param_1);
undefined8 FUN_141bf5600(...);
void FUN_141bf5600(undefined8 param_1);
undefined8 FUN_141bf5630(...);
void FUN_141bf5630(undefined8 param_1);
undefined8 FUN_141bf5660(...);
void FUN_141bf5660(undefined8 param_1);
undefined8 FUN_141bf5690(...);
void FUN_141bf5690(undefined8 param_1);
undefined8 FUN_141bf56c0(...);
void  FUN_141bf56c0(undefined1 *this_);
undefined8 FUN_141bf56f0(...);
void  FUN_141bf56f0(undefined1 *this_);
undefined8 FUN_141bf5710(...);
void FUN_141bf5710(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5740(...);
void FUN_141bf5740(undefined8 param_1);
undefined8 FUN_141bf5760(...);
void FUN_141bf5760(undefined8 param_1);
undefined8 FUN_141bf5790(...);
void FUN_141bf5790(undefined8 param_1);
undefined8 FUN_141bf57c0(...);
void FUN_141bf57c0(undefined8 param_1);
undefined8 FUN_141bf57f0(...);
void FUN_141bf57f0(undefined8 param_1);
undefined8 FUN_141bf5820(...);
void FUN_141bf5820(undefined8 param_1);
undefined8 FUN_141bf5850(...);
void FUN_141bf5850(undefined8 param_1);
undefined8 FUN_141bf5880(...);
void FUN_141bf5880(undefined8 param_1);
undefined8 FUN_141bf58b0(...);
void FUN_141bf58b0(undefined8 param_1);
undefined8 FUN_141bf58e0(...);
void FUN_141bf58e0(undefined8 param_1);
undefined8 FUN_141bf5910(...);
void FUN_141bf5910(undefined8 param_1);
undefined8 FUN_141bf5940(...);
void FUN_141bf5940(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5970(...);
void FUN_141bf5970(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf59a0(...);
void FUN_141bf59a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf59d0(...);
void FUN_141bf59d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5a00(...);
void FUN_141bf5a00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5a30(...);
void FUN_141bf5a30(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5a60(...);
void FUN_141bf5a60(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5a90(...);
void FUN_141bf5a90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5ac0(...);
void FUN_141bf5ac0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5af0(...);
void FUN_141bf5af0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5b20(...);
void FUN_141bf5b20(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5b60(...);
void FUN_141bf5b60(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5ba0(...);
void FUN_141bf5ba0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5be0(...);
void FUN_141bf5be0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5c20(...);
void FUN_141bf5c20(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bf5c60(...);
void FUN_141bf5c60(undefined8 param_1);
undefined8 FUN_141bf5c90(...);
void FUN_141bf5c90(undefined8 param_1);
undefined8 FUN_141bf5cb0(...);
void FUN_141bf5cb0(undefined8 param_1);
undefined8 FUN_141bf5cd0(...);
void FUN_141bf5cd0(undefined8 param_1);
undefined8 FUN_141bf5cf0(...);
void FUN_141bf5cf0(undefined8 param_1);
undefined8 FUN_141bf5d10(...);
void FUN_141bf5d10(undefined8 param_1);
undefined8 FUN_141bf5d30(...);
void FUN_141bf5d30(undefined8 param_1);
undefined8 FUN_141bf5d50(...);
void FUN_141bf5d50(undefined8 param_1);
undefined8 FUN_141bf5d70(...);
void FUN_141bf5d70(undefined8 param_1);
undefined8 FUN_141bf5d90(...);
void FUN_141bf5d90(undefined8 param_1);
undefined8 FUN_141bf5db0(...);
void FUN_141bf5db0(longlong param_1);
undefined8 FUN_141bf5dd0(...);
void FUN_141bf5dd0(longlong param_1);
undefined8 FUN_141bf5df0(...);
void FUN_141bf5df0(longlong param_1);
undefined8 FUN_141bf5e10(...);
void FUN_141bf5e10(longlong param_1);
undefined8 FUN_141bf5e30(...);
void FUN_141bf5e30(longlong param_1);
undefined8 FUN_141bf5e50(...);
void FUN_141bf5e50(longlong param_1);
undefined8 FUN_141bf5e70(...);
void FUN_141bf5e70(undefined1 *param_1);
undefined8 FUN_141bf5ea0(...);
void FUN_141bf5ea0(undefined1 *param_1);
undefined8 FUN_141bf5ed0(...);
void FUN_141bf5ed0(undefined8 param_1);
undefined8 FUN_141bf5ef0(...);
void FUN_141bf5ef0(undefined8 param_1);
undefined8 FUN_141bf5f20(...);
void FUN_141bf5f20(undefined8 param_1);
undefined8 FUN_141bf5f50(...);
void FUN_141bf5f50(undefined8 param_1);
undefined8 FUN_141bf5f80(...);
void FUN_141bf5f80(undefined8 param_1);
undefined8 FUN_141bf5fb0(...);
 void  FUN_141bf5fb0(ActorRemovedMessage *this_);
undefined8 FUN_141bf5ff0(...);
void FUN_141bf5ff0(undefined1 *param_1);
undefined8 FUN_141bf6010(...);
void FUN_141bf6010(undefined1 *param_1);
undefined8 FUN_141bf6030(...);
void  FUN_141bf6030(CInteractWebObject *this_);
undefined8 FUN_141bf6050(...);
void  FUN_141bf6050(CLiftableTargetBox *this_);
undefined8 FUN_141bf6070(...);
void  FUN_141bf6070(CLiftableTargetGuide *this_);
undefined8 FUN_141bf60a0(...);
void FUN_141bf60a0(longlong param_1);
undefined8 FUN_141bf60c0(...);
void FUN_141bf60c0(undefined8 param_1);
undefined8 FUN_141bf60e0(...);
void FUN_141bf60e0(undefined8 param_1);
undefined8 FUN_141bf6100(...);
void FUN_141bf6100(undefined8 param_1);
undefined8 FUN_141bf6120(...);
void FUN_141bf6120(undefined8 param_1);
undefined8 FUN_141bf6140(...);
void FUN_141bf6140(undefined8 param_1);
undefined8 FUN_141bf6160(...);
void FUN_141bf6160(undefined8 param_1);
undefined8 FUN_141bf6180(...);
void FUN_141bf6180(undefined8 param_1);
undefined8 FUN_141bf61a0(...);
void FUN_141bf61a0(undefined8 param_1);
undefined8 FUN_141bf61c0(...);
void FUN_141bf61c0(undefined8 param_1);
undefined8 FUN_141bf61e0(...);
void FUN_141bf61e0(undefined8 param_1);
undefined8 FUN_141bf6200(...);
void FUN_141bf6200(undefined8 param_1);
undefined8 FUN_141bf6220(...);
void FUN_141bf6220(undefined8 param_1);
undefined8 FUN_141bf6240(...);
void FUN_141bf6240(undefined8 param_1);
undefined8 FUN_141bf6260(...);
void FUN_141bf6260(undefined8 param_1);
undefined8 FUN_141bf6280(...);
void FUN_141bf6280(undefined8 param_1);
undefined8 FUN_141bf62a0(...);
void FUN_141bf62a0(undefined8 param_1);
undefined8 FUN_141bf62c0(...);
void FUN_141bf62c0(undefined8 param_1);
undefined8 FUN_141bf62e0(...);
void FUN_141bf62e0(undefined8 param_1);
undefined8 FUN_141bf6300(...);
void FUN_141bf6300(undefined8 param_1);
undefined8 FUN_141bf6320(...);
void FUN_141bf6320(undefined8 param_1);
undefined8 FUN_141bf6340(...);
void FUN_141bf6340(undefined8 param_1);
undefined8 FUN_141bf6360(...);
void FUN_141bf6360(undefined8 param_1);
undefined8 FUN_141bf6380(...);
void FUN_141bf6380(undefined8 param_1);
undefined8 FUN_141bf63a0(...);
void FUN_141bf63a0(undefined8 param_1);
undefined8 FUN_141bf63c0(...);
void FUN_141bf63c0(undefined8 param_1);
undefined8 FUN_141bf63e0(...);
void FUN_141bf63e0(undefined8 param_1);
undefined8 FUN_141bf6400(...);
void FUN_141bf6400(undefined8 param_1);
undefined8 FUN_141bf6420(...);
void FUN_141bf6420(undefined8 param_1);
undefined8 FUN_141bf6440(...);
void FUN_141bf6440(longlong param_1);
undefined8 FUN_141bf6460(...);
void FUN_141bf6460(longlong param_1);
undefined8 FUN_141bf6480(...);
void FUN_141bf6480(longlong param_1);
undefined8 FUN_141bf64a0(...);
void FUN_141bf64a0(longlong param_1);
undefined8 FUN_141bf64c0(...);
void FUN_141bf64c0(longlong param_1);
undefined8 FUN_141bf64e0(...);
void FUN_141bf64e0(longlong param_1);
undefined8 FUN_141bf6500(...);
void FUN_141bf6500(longlong param_1);
undefined8 FUN_141bf6520(...);
void FUN_141bf6520(longlong param_1);
undefined8 FUN_141bf6540(...);
void FUN_141bf6540(longlong param_1);
undefined8 FUN_141bf6560(...);
void FUN_141bf6560(longlong param_1);
undefined8 FUN_141bf6580(...);
void FUN_141bf6580(longlong param_1);
undefined8 FUN_141bf65a0(...);
void FUN_141bf65a0(longlong param_1);
undefined8 FUN_141bf65c0(...);
void FUN_141bf65c0(longlong param_1);
undefined8 FUN_141bf65e0(...);
void FUN_141bf65e0(longlong param_1);
undefined8 FUN_141bf6600(...);
void FUN_141bf6600(longlong param_1);
undefined8 FUN_141bf6620(...);
void FUN_141bf6620(longlong param_1);
undefined8 FUN_141bf6640(...);
void FUN_141bf6640(longlong param_1);
undefined8 FUN_141bf6660(...);
void FUN_141bf6660(longlong param_1);
undefined8 FUN_141bf6680(...);
void FUN_141bf6680(void);
undefined8 FUN_141bf6690(...);
void FUN_141bf6690(longlong param_1);
undefined8 FUN_141bf66b0(...);
void FUN_141bf66b0(undefined1 *param_1);
undefined8 FUN_141bf66e0(...);
void FUN_141bf66e0(undefined1 *param_1);
undefined8 FUN_141bf6710(...);
void FUN_141bf6710(undefined1 *param_1);
undefined8 FUN_141bf6740(...);
void FUN_141bf6740(undefined1 *param_1);
undefined8 FUN_141bf6770(...);
void FUN_141bf6770(undefined1 *param_1);
undefined8 FUN_141bf67a0(...);
void FUN_141bf67a0(longlong param_1);
undefined8 FUN_141bf67c0(...);
void FUN_141bf67c0(void);
undefined8 FUN_141bf67d0(...);
void FUN_141bf67d0(longlong param_1);
undefined8 FUN_141bf67f0(...);
void  FUN_141bf67f0(NotifyChangeServer *this_);
undefined8 FUN_141bf6810(...);
void  FUN_141bf6810(NotifyCreateMyPC *this_);
undefined8 FUN_141bf6830(...);
void  FUN_141bf6830(NotifyGameStart *this_);
undefined8 FUN_141bf6850(...);
void  FUN_141bf6850(NotifyRemoveGameObject *this_);
undefined8 FUN_141bf6870(...);
void FUN_141bf6870(undefined8 param_1);
undefined8 FUN_141bf6890(...);
void  FUN_141bf6890(TextureLayerManager *this_);
undefined8 FUN_141bf68b0(...);
undefined1 * FUN_141bf68b0(undefined1 *param_1,undefined4 *param_2);
undefined8 FUN_141bf68e0(...);
longlong * FUN_141bf68e0(longlong *param_1,longlong param_2);
undefined8 FUN_141bf6950(...);
longlong * FUN_141bf6950(longlong *param_1,longlong *param_2);
undefined8 FUN_141bf69d0(...);
longlong * FUN_141bf69d0(longlong *param_1,longlong *param_2);
undefined8 FUN_141bf6a50(...);
longlong * FUN_141bf6a50(longlong *param_1,longlong *param_2);
undefined8 FUN_141bf6ad0(...);
longlong * FUN_141bf6ad0(longlong *param_1,longlong param_2);
undefined8 FUN_141bf6b40(...);
longlong * FUN_141bf6b40(longlong *param_1,longlong param_2);
undefined8 FUN_141bf6bc0(...);
longlong FUN_141bf6bc0(longlong param_1,longlong param_2);
undefined8 FUN_141bf6c00(...);
longlong FUN_141bf6c00(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf6c70(...);
longlong FUN_141bf6c70(longlong param_1,longlong param_2);
undefined8 FUN_141bf6cb0(...);
longlong FUN_141bf6cb0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf6d20(...);
longlong FUN_141bf6d20(longlong param_1,longlong param_2);
undefined8 FUN_141bf6d60(...);
longlong FUN_141bf6d60(longlong param_1,longlong param_2);
undefined8 FUN_141bf6da0(...);
longlong FUN_141bf6da0(longlong param_1,longlong param_2);
undefined8 FUN_141bf6de0(...);
undefined8 FUN_141bf6de0(undefined8 param_1);
undefined8 FUN_141bf6e10(...);
longlong FUN_141bf6e10(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf6e80(...);
longlong FUN_141bf6e80(longlong param_1,longlong param_2);
undefined8 FUN_141bf6ec0(...);
undefined8 FUN_141bf6ec0(undefined8 param_1);
undefined8 FUN_141bf6ef0(...);
longlong FUN_141bf6ef0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bf6f60(...);
longlong FUN_141bf6f60(longlong param_1,longlong param_2);
undefined8 FUN_141bf6fa0(...);
longlong FUN_141bf6fa0(longlong param_1,longlong param_2);
undefined8 FUN_141bf6fe0(...);
longlong FUN_141bf6fe0(longlong param_1,longlong param_2);
undefined8 FUN_141bf7020(...);
longlong FUN_141bf7020(longlong param_1,longlong param_2);

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2b70
undefined8 * FUN_141bf2b70(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2bb0
undefined8 * FUN_141bf2bb0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2bf0
undefined8 * FUN_141bf2bf0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2c30
undefined8 * FUN_141bf2c30(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf2c70
undefined8 FUN_141bf2c70(undefined8 param_1)
{
  return (undefined8)((undefined8 (*)(...))0x141bf2c70ULL)(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf2ca0
undefined8 FUN_141bf2ca0(undefined8 param_1)
{
  return (undefined8)((undefined8 (*)(...))0x141bf2ca0ULL)(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf2cd0
undefined8 FUN_141bf2cd0(undefined8 param_1)
{
  return (undefined8)((undefined8 (*)(...))0x141bf2cd0ULL)(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf2d00
undefined8 FUN_141bf2d00(undefined8 param_1)
{
  return (undefined8)((undefined8 (*)(...))0x141bf2d00ULL)(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2d30
undefined8 * FUN_141bf2d30(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_14016ad80(param_1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2d70
undefined8 FUN_141bf2d70(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf2d30(param_1,param_2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2db0
undefined8 * FUN_141bf2db0(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2df0
undefined8 * FUN_141bf2df0(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2e30
undefined8 * FUN_141bf2e30(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2e70
undefined8 * FUN_141bf2e70(undefined8 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2eb0
undefined8 FUN_141bf2eb0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2ec0
undefined8 FUN_141bf2ec0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2ed0
undefined8 FUN_141bf2ed0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2ee0
undefined8 FUN_141bf2ee0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2ef0
undefined8 FUN_141bf2ef0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f00
undefined8 FUN_141bf2f00(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f10
undefined8 FUN_141bf2f10(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f20
undefined8 FUN_141bf2f20(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f30
undefined8 FUN_141bf2f30(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f40
undefined8 FUN_141bf2f40(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f50
undefined8 FUN_141bf2f50(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f60
undefined8 FUN_141bf2f60(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f70
undefined8 FUN_141bf2f70(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f80
undefined8 FUN_141bf2f80(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2f90
undefined8 FUN_141bf2f90(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2fa0
undefined8 FUN_141bf2fa0(undefined8 param_1)
{
  FUN_141bf1aa0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2fc0
undefined8 FUN_141bf2fc0(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1c30(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf2ff0
undefined8 FUN_141bf2ff0(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1c60(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3020
undefined8 FUN_141bf3020(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1c90(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3050
undefined8 FUN_141bf3050(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1cc0(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3080
undefined8 FUN_141bf3080(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1cf0(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf30b0
undefined8 FUN_141bf30b0(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1d20(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf30e0
undefined8 FUN_141bf30e0(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1d50(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3110
undefined8 FUN_141bf3110(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1d80(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3140
undefined8 FUN_141bf3140(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1db0(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3170
undefined1 * FUN_141bf3170(undefined1 *param_1, undefined1 *param_2)
{
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  new ((void *)((undefined1 *)(param_1 + 8))) CStringW(*(const CStringW *)((undefined1 *)
              (param_2 + 8)));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf31d0
undefined1 * FUN_141bf31d0(undefined1 *param_1, undefined1 *param_2)
{
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  new ((void *)((undefined1 *)(param_1 + 8))) CStringW(*(const CStringW *)((undefined1 *)
              (param_2 + 8)));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3230
undefined1 * FUN_141bf3230(undefined1 *param_1, undefined1 *param_2, undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  
  uVar1 = 0xfffffffffffffffe;
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  FUN_140b2d2a0(param_1 + 8,param_2 + 8,param_3,param_4,uVar1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3280
undefined1 * FUN_141bf3280(undefined1 *param_1, undefined1 *param_2, undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  
  uVar1 = 0xfffffffffffffffe;
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  FUN_140b2d2d0(param_1 + 8,param_2 + 8,param_3,param_4,uVar1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf32d0
undefined8 FUN_141bf32d0(undefined8 param_1)
{
  undefined1 local_18 [24];
  
  FUN_141bf1de0(param_1,local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3300
undefined8 FUN_141bf3300(undefined8 param_1)
{
  FUN_141bf2c70(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3330
undefined8 FUN_141bf3330(undefined8 param_1)
{
  FUN_141bf2ca0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3360
undefined8 FUN_141bf3360(undefined8 param_1)
{
  FUN_141bf2cd0(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3390
undefined8 FUN_141bf3390(undefined8 param_1)
{
  FUN_141bf2d00(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf33c0
 ActorRemovedMessage *  FUN_141bf33c0(ActorRemovedMessage *this_,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  return (ActorRemovedMessage *)((undefined8 (*)(...))0x141bf33c0ULL)(this_,param_2,param_3,param_4);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf3410
AssetID * FUN_141bf3410(AssetID *param_1,undefined8 param_2,undefined4 param_3)
{
  return (AssetID *)((undefined8 (*)(...))0x141bf3410ULL)(param_1,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3460
undefined1 * FUN_141bf3460(undefined1 *param_1)
{
  new ((void *)(param_1)) CStringA("");
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf34d0
undefined1 * FUN_141bf34d0(undefined1 *param_1)
{
  undefined8 uVar1;
  
  uVar1 = 0xfffffffffffffffe;
  new ((void *)(param_1)) CStringA("");
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  FUN_14027db40(param_1 + 0x24,0,0,0,uVar1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3570
CInteractWebObject *  FUN_141bf3570(CInteractWebObject *this_)
{
  FUN_1413fd240((undefined1 *)this_);
  (*(undefined8 *)(this_)) = (undefined8)((undefined1 *)((undefined1 *)0x142ffed30ULL));
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf35a0
CLiftableTargetBox *  FUN_141bf35a0(CLiftableTargetBox *this_)
{
  FUN_141448190((undefined1 *)this_);
  (*(undefined8 *)(this_)) = (undefined8)((undefined1 *)((undefined1 *)0x142ffecf0ULL));
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf35d0
CLiftableTargetGuide *  FUN_141bf35d0(CLiftableTargetGuide *this_)
{
  return (CLiftableTargetGuide *)((undefined8 (*)(...))0x141bf35d0ULL)(this_);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3610
longlong FUN_141bf3610(longlong param_1,undefined8 param_2)
{
  FUN_141bf10a0(param_1 + 0x10,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3640
longlong FUN_141bf3640(longlong param_1,undefined8 param_2)
{
  FUN_140a000a0(param_1 + 0x10,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3670
longlong FUN_141bf3670(longlong param_1,undefined8 param_2)
{
  FUN_140c20410(param_1 + 0x10,param_2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf36a0
longlong FUN_141bf36a0(longlong param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_141bf3eb0(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf36e0
longlong FUN_141bf36e0(longlong param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_141bf3ef0(param_1,param_2);
  *(undefined4 *)(param_1 + 0x18) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3720
longlong FUN_141bf3720(longlong param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_141bf3f30(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3760
longlong FUN_141bf3760(longlong param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_141bf3f70(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf37a0
longlong FUN_141bf37a0(longlong param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_141bf3fb0(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf37e0
longlong FUN_141bf37e0(longlong param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_141bf3ff0(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3820
longlong FUN_141bf3820(longlong param_1,undefined8 param_2,undefined4 param_3)
{
  FUN_141bf4030(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3860
longlong FUN_141bf3860(longlong param_1,undefined8 param_2,undefined4 param_3)
{
  FUN_141bf4070(param_1,param_2);
  *(undefined4 *)(param_1 + 0x18) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf38a0
longlong FUN_141bf38a0(longlong param_1,undefined8 param_2,undefined4 param_3)
{
  FUN_141bf40b0(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf38e0
longlong FUN_141bf38e0(longlong param_1,undefined8 param_2,undefined4 param_3)
{
  FUN_141bf40f0(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3920
longlong FUN_141bf3920(longlong param_1,undefined8 param_2,undefined4 param_3)
{
  FUN_141bf4130(param_1,param_2);
  *(undefined4 *)(param_1 + 0x20) = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3960
longlong FUN_141bf3960(longlong param_1,undefined4 param_2,undefined8 param_3)
{
  FUN_141bf4170(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf39b0
longlong FUN_141bf39b0(longlong param_1,undefined4 param_2,undefined8 param_3)
{
  FUN_141bf41b0(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3a00
longlong FUN_141bf3a00(longlong param_1,undefined4 param_2,undefined8 param_3)
{
  FUN_141bf41f0(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3a50
longlong FUN_141bf3a50(longlong param_1,undefined4 param_2,undefined8 param_3)
{
  FUN_141bf4230(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3aa0
longlong FUN_141bf3aa0(longlong param_1,undefined4 param_2,undefined8 param_3)
{
  FUN_141bf4270(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3af0
longlong FUN_141bf3af0(longlong param_1,undefined4 param_2,undefined8 param_3)
{
  FUN_141bf42b0(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3b40
longlong FUN_141bf3b40(longlong param_1,undefined4 param_2,undefined8 param_3)
{
  FUN_141bf42f0(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3b90
longlong FUN_141bf3b90(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf4330(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3be0
longlong FUN_141bf3be0(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf4370(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3c30
longlong FUN_141bf3c30(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf43c0(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3c80
longlong FUN_141bf3c80(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf4420(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3cd0
longlong FUN_141bf3cd0(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf4480(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3d20
longlong FUN_141bf3d20(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf44e0(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3d70
longlong FUN_141bf3d70(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf4540(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3dc0
longlong FUN_141bf3dc0(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf45a0(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined8 *)(param_1 + 0x30) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3e10
longlong FUN_141bf3e10(longlong param_1,undefined8 param_2,undefined4 param_3)
{
  FUN_141bf45f0(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined8 *)(param_1 + 0x20) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3e60
longlong FUN_141bf3e60(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_141bf4620(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3eb0
 undefined4 * FUN_141bf3eb0(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  FUN_1416c2ba0(param_1 + 2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3ef0
undefined4 * FUN_141bf3ef0(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  FUN_141bf0fd0(param_1 + 2,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3f30
 undefined4 * FUN_141bf3f30(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  FUN_141bf11e0(param_1 + 2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3f70
 undefined4 * FUN_141bf3f70(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  FUN_141bf12c0(param_1 + 2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3fb0
 undefined4 * FUN_141bf3fb0(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  FUN_140ac5930(param_1 + 2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf3ff0
 undefined4 * FUN_141bf3ff0(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = param_2;
  FUN_141bf1700(param_1 + 2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4030
undefined4 * FUN_141bf4030(undefined4 *param_1,undefined4 *param_2)
{
  *param_1 = *param_2;
  FUN_141bf17b0(param_1 + 2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4070
undefined8 * FUN_141bf4070(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  FUN_1410a6960(param_1 + 1,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf40b0
 undefined8 * FUN_141bf40b0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  FUN_140ae13b0(param_1 + 1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf40f0
 undefined8 * FUN_141bf40f0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  FUN_14123eb50(param_1 + 1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4130
 undefined8 * FUN_141bf4130(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  FUN_141bf1490(param_1 + 1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4170
undefined4 * FUN_141bf4170(undefined4 *param_1,undefined4 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_140964030(param_1 + 2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf41b0
undefined4 * FUN_141bf41b0(undefined4 *param_1,undefined4 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_141bf15b0(param_1 + 2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf41f0
undefined4 * FUN_141bf41f0(undefined4 *param_1,undefined4 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_141bf4860(param_1 + 2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4230
undefined4 * FUN_141bf4230(undefined4 *param_1,undefined4 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_140a7b390(param_1 + 2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4270
undefined4 * FUN_141bf4270(undefined4 *param_1,undefined4 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_140a000a0(param_1 + 2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf42b0
undefined4 * FUN_141bf42b0(undefined4 *param_1,undefined4 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_140c20410(param_1 + 2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf42f0
undefined4 * FUN_141bf42f0(undefined4 *param_1,undefined4 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_141bf1900(param_1 + 2,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4330
undefined8 * FUN_141bf4330(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)
{
  *param_1 = *param_2;
  param_1[1] = *param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4370
 undefined8 * FUN_141bf4370(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)
{
  *param_1 = *param_2;
  FUN_141bf1330(param_1 + 1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf43c0
undefined1 * FUN_141bf43c0(undefined1 *param_1, undefined1 *param_2, undefined8 param_3)
{
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  FUN_140963d50(param_1 + 8,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4420
undefined1 * FUN_141bf4420(undefined1 *param_1, undefined1 *param_2, undefined8 param_3)
{
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  FUN_1408a7ed0(param_1 + 8,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4480
undefined1 * FUN_141bf4480(undefined1 *param_1, undefined1 *param_2, undefined8 param_3)
{
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  FUN_141bf1330(param_1 + 8,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf44e0
undefined1 * FUN_141bf44e0(undefined1 *param_1, undefined1 *param_2, undefined8 param_3)
{
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  FUN_140a7b410(param_1 + 8,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4540
undefined1 * FUN_141bf4540(undefined1 *param_1, undefined1 *param_2, undefined8 param_3)
{
  new ((void *)(param_1)) CStringA(*(const CStringA *)(param_2));
  FUN_140963ff0(param_1 + 8,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf45a0
longlong FUN_141bf45a0(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  FUN_1408b6b20(param_1,param_2);
  FUN_140a7b410(param_1 + 8,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf45f0
undefined4 * FUN_141bf45f0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)
{
  *param_1 = *param_2;
  param_1[1] = param_3;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4620
undefined8 * FUN_141bf4620(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  *param_1 = param_2;
  FUN_140a000a0(param_1 + 1,param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4660
undefined8 * FUN_141bf4660(undefined8 *param_1,undefined8 *param_2)
{
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 1) = *(undefined4 *)(param_2 + 1);
  FUN_1408b6b20(param_1 + 2,param_2 + 2);
  *(undefined4 *)(param_1 + 3) = *(undefined4 *)(param_2 + 3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf46d0
undefined8 * FUN_141bf46d0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4, undefined4 param_5)
{
  FUN_1408995b0(param_1 + 2);
  FUN_140899bd0(param_1 + 2,param_2);
  *param_1 = param_3;
  *(undefined4 *)(param_1 + 1) = param_4;
  *(undefined4 *)(param_1 + 3) = param_5;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4740
undefined8 * FUN_141bf4740(undefined8 *param_1)
{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  FUN_1401cd100(param_1 + 2,0);
  *(undefined4 *)(param_1 + 3) = 0xffffffff;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4790
NotifyChangeServer *  FUN_141bf4790(NotifyChangeServer *this_)
{
  FUN_140939070((undefined1 *)this_);
  (*(undefined8 *)(this_)) = (undefined8)((undefined1 *)((undefined1 *)0x142ffedd8ULL));
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf47c0
NotifyCreateMyPC *  FUN_141bf47c0(NotifyCreateMyPC *this_)
{
  FUN_140939070((undefined1 *)this_);
  (*(undefined8 *)(this_)) = (undefined8)((undefined1 *)((undefined1 *)0x142ffee08ULL));
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf47f0
NotifyGameStart *  FUN_141bf47f0(NotifyGameStart *this_)
{
  FUN_140939070((undefined1 *)this_);
  (*(undefined8 *)(this_)) = (undefined8)((undefined1 *)((undefined1 *)0x142ffedc0ULL));
  return this_;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf4820
 scheduler_resource_allocation_error *  FUN_141bf4820(scheduler_resource_allocation_error *this_,long param_1)
{
  return (scheduler_resource_allocation_error *)((undefined8 (*)(...))0x141bf4820ULL)(this_,param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4860
longlong FUN_141bf4860(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  FUN_140a000a0(param_1,param_2,param_3,param_4,0xfffffffffffffffe);
  FUN_1408b6b20(param_1 + 8,param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf48b0
longlong FUN_141bf48b0(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  FUN_140a000f0(param_1,0,param_3,param_4,0xfffffffffffffffe);
  FUN_1408995b0(param_1 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf48f0
TextureLayerManager *  FUN_141bf48f0(TextureLayerManager *this_)
{
  return (TextureLayerManager *)((undefined8 (*)(...))0x141bf48f0ULL)(this_);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4920
 void  FUN_141bf4920(undefined1 *this_)
{
  if (*(longlong *)this_ != 0) {
    FUN_141bfaee0(*(void ***)this_,*(__uint64 *)(this_ + 8));
    free(*(void **)this_);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4960
void FUN_141bf4960(undefined8 param_1)
{
  FUN_141c16150(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4980
void FUN_141bf4980(undefined8 param_1)
{
  FUN_141c16230(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf49b0
void FUN_141bf49b0(undefined8 param_1)
{
  FUN_141c16340(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf49e0
void FUN_141bf49e0(undefined8 param_1)
{
  FUN_141c16450(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4a10
void FUN_141bf4a10(undefined8 param_1)
{
  FUN_141c16560(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4a40
void FUN_141bf4a40(undefined8 param_1)
{
  FUN_141c16670(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4a70
void FUN_141bf4a70(undefined8 param_1)
{
  FUN_141c16780(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4aa0
void FUN_141bf4aa0(undefined8 param_1)
{
  FUN_141c16890(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4ad0
void FUN_141bf4ad0(undefined8 param_1)
{
  FUN_141c169a0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4b00
void FUN_141bf4b00(undefined8 param_1)
{
  FUN_141c16ab0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4b30
void FUN_141bf4b30(undefined8 param_1)
{
  FUN_141c16bc0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4b60
void FUN_141bf4b60(undefined8 param_1)
{
  FUN_141c16cd0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4b90
void FUN_141bf4b90(undefined8 param_1)
{
  FUN_141bf4e30(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4bb0
void FUN_141bf4bb0(undefined8 param_1)
{
  FUN_141bf4e70(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4bd0
void FUN_141bf4bd0(undefined8 param_1)
{
  FUN_141bf4eb0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4bf0
void FUN_141bf4bf0(undefined8 param_1)
{
  FUN_141bf4ef0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4c10
void FUN_141bf4c10(undefined8 param_1)
{
  FUN_141bf4f30(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4c30
void FUN_141bf4c30(undefined8 param_1)
{
  FUN_141bf4f70(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4c50
void FUN_141bf4c50(undefined8 param_1)
{
  FUN_141bf4fb0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4c70
void FUN_141bf4c70(undefined8 param_1)
{
  FUN_141bf4ff0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4c90
void FUN_141bf4c90(undefined8 param_1)
{
  FUN_141bf5030(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4cb0
void FUN_141bf4cb0(undefined8 param_1)
{
  FUN_141bf5070(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4cd0
void FUN_141bf4cd0(undefined8 param_1)
{
  FUN_141bf50b0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4cf0
void FUN_141bf4cf0(undefined8 param_1)
{
  FUN_141bf50f0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4d10
void FUN_141bf4d10(undefined8 param_1)
{
  FUN_141bf5130(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4d30
void FUN_141bf4d30(undefined8 param_1)
{
  FUN_141bf5170(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4d50
void FUN_141bf4d50(undefined8 param_1)
{
  FUN_141bf51b0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4d70
void FUN_141bf4d70(undefined8 param_1)
{
  FUN_141bf4db0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4d90
void FUN_141bf4d90(undefined8 param_1)
{
  FUN_141bf4df0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4db0
void FUN_141bf4db0(longlong param_1)
{
  FUN_141c16de0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4df0
void FUN_141bf4df0(longlong param_1)
{
  FUN_141c16e60(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4e30
void FUN_141bf4e30(longlong param_1)
{
  FUN_141c16ee0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4e70
void FUN_141bf4e70(longlong param_1)
{
  FUN_141c16f60(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4eb0
void FUN_141bf4eb0(longlong param_1)
{
  FUN_141c16fe0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4ef0
void FUN_141bf4ef0(longlong param_1)
{
  FUN_141c17060(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4f30
void FUN_141bf4f30(longlong param_1)
{
  FUN_141c170e0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4f70
void FUN_141bf4f70(longlong param_1)
{
  FUN_141c17160(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4fb0
void FUN_141bf4fb0(longlong param_1)
{
  FUN_141c171e0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf4ff0
void FUN_141bf4ff0(longlong param_1)
{
  FUN_141c17260(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5030
void FUN_141bf5030(longlong param_1)
{
  FUN_141c172e0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5070
void FUN_141bf5070(longlong param_1)
{
  FUN_141c17360(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf50b0
void FUN_141bf50b0(longlong param_1)
{
  FUN_141c173e0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf50f0
void FUN_141bf50f0(longlong param_1)
{
  FUN_141c17460(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5130
void FUN_141bf5130(longlong param_1)
{
  FUN_141c174e0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5170
void FUN_141bf5170(longlong param_1)
{
  FUN_141c17560(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf51b0
void FUN_141bf51b0(longlong param_1)
{
  FUN_141c175e0(param_1);
  if (*(longlong *)(param_1 + 0x28) != 0) {
    free(*(void **)(param_1 + 0x28));
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf51f0
void  FUN_141bf51f0(undefined1 *this_)
{
  FUN_1409f20a0((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5210
void  FUN_141bf5210(undefined1 *this_)
{
  FUN_1409f20a0((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5230
void  FUN_141bf5230(undefined1 *this_)
{
  FUN_141125e50((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5250
void  FUN_141bf5250(undefined1 *this_)
{
  FUN_141125e50((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5270
void  FUN_141bf5270(undefined1 *this_)
{
  FUN_141125e50((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5290
void  FUN_141bf5290(undefined1 *this_)
{
  FUN_141125e50((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf52b0
void  FUN_141bf52b0(undefined1 *this_)
{
  FUN_141125e50((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf52d0
void  FUN_141bf52d0(undefined1 *this_)
{
  FUN_141125e50((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf52f0
void  FUN_141bf52f0(undefined1 *this_)
{
  FUN_141125e50((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5310
void  FUN_141bf5310(undefined1 *this_)
{
  FUN_141125e50((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5330
void  FUN_141bf5330(undefined1 *this_)
{
  FUN_141bf5270((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5350
void  FUN_141bf5350(undefined1 *this_)
{
  FUN_141bf5290((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5370
void  FUN_141bf5370(undefined1 *this_)
{
  FUN_141bf52d0((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5390
void  FUN_141bf5390(undefined1 *this_)
{
  FUN_141bf5350((undefined1
              *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf53b0
void  FUN_141bf53b0(undefined1 *this_)
{
  FUN_141bf5350((undefined1
              *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf53d0
void  FUN_141bf53d0(undefined1 *this_)
{
  FUN_141bf5350((undefined1
              *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf53f0
void  FUN_141bf53f0(undefined1 *this_)
{
  FUN_141bf5370((undefined1
              *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5410
void FUN_141bf5410(longlong *param_1)
{
  if (*param_1 != 0) {
    FUN_1405a93d0(*param_1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5440
void FUN_141bf5440(longlong *param_1)
{
  if (*param_1 != 0) {
    FUN_1405a93d0(*param_1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5470
void FUN_141bf5470(longlong *param_1)
{
  if (*param_1 != 0) {
    FUN_1405a93d0(*param_1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf54a0
void FUN_141bf54a0(longlong *param_1)
{
  if (*param_1 != 0) {
    (**(code **)(*(longlong *)*param_1 + 0x10))(*param_1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf54e0
void FUN_141bf54e0(longlong *param_1)
{
  if (*param_1 != 0) {
    FUN_1405a93d0(*param_1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5510
void FUN_141bf5510(longlong *param_1)
{
  if (*param_1 != 0) {
    FUN_1405a93d0(*param_1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5540
void FUN_141bf5540(longlong *param_1)
{
  if (*param_1 != 0) {
    FUN_1405a93d0(*param_1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5570
void FUN_141bf5570(undefined8 param_1)
{
  FUN_141c28c80(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf55a0
void FUN_141bf55a0(undefined8 param_1)
{
  FUN_141c28cc0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf55d0
void FUN_141bf55d0(undefined8 param_1)
{
  FUN_141c28d00(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5600
void FUN_141bf5600(undefined8 param_1)
{
  FUN_141c28d40(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5630
void FUN_141bf5630(undefined8 param_1)
{
  FUN_141c28d80(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5660
void FUN_141bf5660(undefined8 param_1)
{
  FUN_141c28dc0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5690
void FUN_141bf5690(undefined8 param_1)
{
  FUN_141c28e00(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf56c0
void  FUN_141bf56c0(undefined1 *this_)
{
  FUN_141b94450(((undefined1 *)(this_) + 0x18));
  FUN_140159840((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf56f0
void  FUN_141bf56f0(undefined1 *this_)
{
  (*(undefined8 *)(this_)) = (undefined8)((undefined1 *)((undefined1 *)0x142ffeb88ULL));
  (*(undefined8 *)0x143aaee10ULL) = 0;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5710
void FUN_141bf5710(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c28930(param_1);
  FUN_141c25b50(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5740
void FUN_141bf5740(undefined8 param_1)
{
  FUN_141bf5710(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5760
void FUN_141bf5760(undefined8 param_1)
{
  FUN_141c29c50(param_1);
  FUN_141bf5940(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5790
void FUN_141bf5790(undefined8 param_1)
{
  FUN_141c29cb0(param_1);
  FUN_141bf5970(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf57c0
void FUN_141bf57c0(undefined8 param_1)
{
  FUN_141c29d10(param_1);
  FUN_141bf59a0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf57f0
void FUN_141bf57f0(undefined8 param_1)
{
  FUN_141c29d70(param_1);
  FUN_141bf59d0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5820
void FUN_141bf5820(undefined8 param_1)
{
  FUN_141c29dd0(param_1);
  FUN_141bf5a00(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5850
void FUN_141bf5850(undefined8 param_1)
{
  FUN_141c29e30(param_1);
  FUN_141bf5a30(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5880
void FUN_141bf5880(undefined8 param_1)
{
  FUN_141c29e90(param_1);
  FUN_141bf5a60(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf58b0
void FUN_141bf58b0(undefined8 param_1)
{
  FUN_141c29ef0(param_1);
  FUN_141bf5a90(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf58e0
void FUN_141bf58e0(undefined8 param_1)
{
  FUN_141c29f50(param_1);
  FUN_141bf5ac0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5910
void FUN_141bf5910(undefined8 param_1)
{
  FUN_141c29fb0(param_1);
  FUN_141bf5af0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5940
void FUN_141bf5940(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c26000(param_1);
  FUN_141c25b80(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5970
void FUN_141bf5970(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c26060(param_1);
  FUN_141c25bb0(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf59a0
void FUN_141bf59a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c260c0(param_1);
  FUN_141c25be0(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf59d0
void FUN_141bf59d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c26120(param_1);
  FUN_141c25c10(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5a00
void FUN_141bf5a00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c26180(param_1);
  FUN_141c25c40(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5a30
void FUN_141bf5a30(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c261e0(param_1);
  FUN_141c25c70(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5a60
void FUN_141bf5a60(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c26240(param_1);
  FUN_141c25ca0(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5a90
void FUN_141bf5a90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c262a0(param_1);
  FUN_141c25cd0(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5ac0
void FUN_141bf5ac0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c26300(param_1);
  FUN_141c25d00(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5af0
void FUN_141bf5af0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xfffffffffffffffe;
  puVar1 = (undefined8 *)FUN_141c26360(param_1);
  FUN_141c25d30(param_1,*puVar1,param_3,param_4,uVar2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5b20
void FUN_141bf5b20(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  FUN_141bde8e0(*param_1,param_1[1],param_1[2],param_4,0xfffffffffffffffe);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5b60
void FUN_141bf5b60(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  FUN_141bde930(*param_1,param_1[1],param_1[2],param_4,0xfffffffffffffffe);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5ba0
void FUN_141bf5ba0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  FUN_140961b80(*param_1,param_1[1],param_1[2],param_4,0xfffffffffffffffe);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5be0
void FUN_141bf5be0(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  FUN_140961bd0(*param_1,param_1[1],param_1[2],param_4,0xfffffffffffffffe);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5c20
void FUN_141bf5c20(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  FUN_141bde980(*param_1,param_1[1],param_1[2],param_4,0xfffffffffffffffe);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5c60
void FUN_141bf5c60(undefined8 param_1)
{
  FUN_141c2a000(param_1);
  FUN_141bf5740(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5c90
void FUN_141bf5c90(undefined8 param_1)
{
  FUN_141bf5760(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5cb0
void FUN_141bf5cb0(undefined8 param_1)
{
  FUN_141bf5790(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5cd0
void FUN_141bf5cd0(undefined8 param_1)
{
  FUN_141bf57c0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5cf0
void FUN_141bf5cf0(undefined8 param_1)
{
  FUN_141bf57f0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5d10
void FUN_141bf5d10(undefined8 param_1)
{
  FUN_141bf5820(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5d30
void FUN_141bf5d30(undefined8 param_1)
{
  FUN_141bf5850(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5d50
void FUN_141bf5d50(undefined8 param_1)
{
  FUN_141bf5880(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5d70
void FUN_141bf5d70(undefined8 param_1)
{
  FUN_141bf58b0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5d90
void FUN_141bf5d90(undefined8 param_1)
{
  FUN_141bf58e0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5db0
void FUN_141bf5db0(longlong param_1)
{
  FUN_140a16650(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5dd0
void FUN_141bf5dd0(longlong param_1)
{
  FUN_1408a8720(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5df0
void FUN_141bf5df0(longlong param_1)
{
  FUN_141bf5410(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5e10
void FUN_141bf5e10(longlong param_1)
{
  FUN_141bf5440(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5e30
void FUN_141bf5e30(longlong param_1)
{
  FUN_1408a8720(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5e50
void FUN_141bf5e50(longlong param_1)
{
  FUN_141375010(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5e70
void FUN_141bf5e70(undefined1 *param_1)
{
  ((CStringW *)((undefined1 *)(param_1 + 8)))->~CStringW();
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5ea0
void FUN_141bf5ea0(undefined1 *param_1)
{
  FUN_140b2da40(param_1 + 8);
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5ed0
void FUN_141bf5ed0(undefined8 param_1)
{
  FUN_141bf5910(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5ef0
void FUN_141bf5ef0(undefined8 param_1)
{
  FUN_141c2a020(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5f20
void FUN_141bf5f20(undefined8 param_1)
{
  FUN_141c2a0f0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5f50
void FUN_141bf5f50(undefined8 param_1)
{
  FUN_141c2a1c0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5f80
void FUN_141bf5f80(undefined8 param_1)
{
  FUN_141c2a290(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bf5fb0
 void  FUN_141bf5fb0(ActorRemovedMessage *this_)
{
  ((undefined8 (*)(...))0x141bf5fb0ULL)(this_);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf5ff0
void FUN_141bf5ff0(undefined1 *param_1)
{
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6010
void FUN_141bf6010(undefined1 *param_1)
{
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6030
void  FUN_141bf6030(CInteractWebObject *this_)
{
  FUN_1413fd380((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6050
void  FUN_141bf6050(CLiftableTargetBox *this_)
{
  FUN_141448230((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6070
void  FUN_141bf6070(CLiftableTargetGuide *this_)
{
  ((CStringA *)((undefined1 *)((undefined1 *)(this_) + 0x48)))->~CStringA();
  FUN_141448230((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf60a0
void FUN_141bf60a0(longlong param_1)
{
  FUN_140ae16b0(param_1 + 0x10);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf60c0
void FUN_141bf60c0(undefined8 param_1)
{
  FUN_141bf6440(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf60e0
void FUN_141bf60e0(undefined8 param_1)
{
  FUN_141bf6460(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6100
void FUN_141bf6100(undefined8 param_1)
{
  FUN_141bf6480(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6120
void FUN_141bf6120(undefined8 param_1)
{
  FUN_141bf64a0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6140
void FUN_141bf6140(undefined8 param_1)
{
  FUN_141bf64c0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6160
void FUN_141bf6160(undefined8 param_1)
{
  FUN_141bf64e0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6180
void FUN_141bf6180(undefined8 param_1)
{
  FUN_141bf6500(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf61a0
void FUN_141bf61a0(undefined8 param_1)
{
  FUN_141bf6520(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf61c0
void FUN_141bf61c0(undefined8 param_1)
{
  FUN_141bf6540(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf61e0
void FUN_141bf61e0(undefined8 param_1)
{
  FUN_141bf6560(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6200
void FUN_141bf6200(undefined8 param_1)
{
  FUN_141bf6580(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6220
void FUN_141bf6220(undefined8 param_1)
{
  FUN_141bf65a0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6240
void FUN_141bf6240(undefined8 param_1)
{
  FUN_141bf65c0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6260
void FUN_141bf6260(undefined8 param_1)
{
  FUN_141bf65e0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6280
void FUN_141bf6280(undefined8 param_1)
{
  FUN_141bf6600(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf62a0
void FUN_141bf62a0(undefined8 param_1)
{
  FUN_141bf6620(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf62c0
void FUN_141bf62c0(undefined8 param_1)
{
  FUN_141bf6640(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf62e0
void FUN_141bf62e0(undefined8 param_1)
{
  FUN_141bf6660(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6300
void FUN_141bf6300(undefined8 param_1)
{
  FUN_141bf6680(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6320
void FUN_141bf6320(undefined8 param_1)
{
  FUN_141bf6690(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6340
void FUN_141bf6340(undefined8 param_1)
{
  FUN_141bf66b0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6360
void FUN_141bf6360(undefined8 param_1)
{
  FUN_141bf66e0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6380
void FUN_141bf6380(undefined8 param_1)
{
  FUN_141bf6710(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf63a0
void FUN_141bf63a0(undefined8 param_1)
{
  FUN_141bf6740(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf63c0
void FUN_141bf63c0(undefined8 param_1)
{
  FUN_141bf6770(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf63e0
void FUN_141bf63e0(undefined8 param_1)
{
  FUN_141bf67a0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6400
void FUN_141bf6400(undefined8 param_1)
{
  FUN_141bf67c0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6420
void FUN_141bf6420(undefined8 param_1)
{
  FUN_141bf67d0(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6440
void FUN_141bf6440(longlong param_1)
{
  FUN_140964a70(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6460
void FUN_141bf6460(longlong param_1)
{
  FUN_141bf54a0(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6480
void FUN_141bf6480(longlong param_1)
{
  FUN_141bf5570(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf64a0
void FUN_141bf64a0(longlong param_1)
{
  FUN_1409f20e0(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf64c0
void FUN_141bf64c0(longlong param_1)
{
  FUN_1406c70a0(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf64e0
void FUN_141bf64e0(longlong param_1)
{
  FUN_141746770(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6500
void FUN_141bf6500(longlong param_1)
{
  FUN_141bf5630(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6520
void FUN_141bf6520(longlong param_1)
{
  FUN_1410a6c00(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6540
void FUN_141bf6540(longlong param_1)
{
  FUN_140a00490(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6560
void FUN_141bf6560(longlong param_1)
{
  FUN_14123ebe0(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6580
void FUN_141bf6580(longlong param_1)
{
  FUN_1410b4290(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf65a0
void FUN_141bf65a0(longlong param_1)
{
  FUN_140964a10(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf65c0
void FUN_141bf65c0(longlong param_1)
{
  FUN_141bf55a0(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf65e0
void FUN_141bf65e0(longlong param_1)
{
  FUN_141bf6870(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6600
void FUN_141bf6600(longlong param_1)
{
  FUN_140a7b530(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6620
void FUN_141bf6620(longlong param_1)
{
  FUN_140964870(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6640
void FUN_141bf6640(longlong param_1)
{
  FUN_140aac150(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6660
void FUN_141bf6660(longlong param_1)
{
  FUN_141bf5690(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6680
void FUN_141bf6680(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6690
void FUN_141bf6690(longlong param_1)
{
  FUN_140d28f40(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf66b0
void FUN_141bf66b0(undefined1 *param_1)
{
  FUN_140964830(param_1 + 8);
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf66e0
void FUN_141bf66e0(undefined1 *param_1)
{
  FUN_1408a8720(param_1 + 8);
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6710
void FUN_141bf6710(undefined1 *param_1)
{
  FUN_140d28f40(param_1 + 8);
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6740
void FUN_141bf6740(undefined1 *param_1)
{
  FUN_1409649b0(param_1 + 8);
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6770
void FUN_141bf6770(undefined1 *param_1)
{
  FUN_1409649e0(param_1 + 8);
  ((CStringA *)(param_1))->~CStringA();
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf67a0
void FUN_141bf67a0(longlong param_1)
{
  FUN_1409649b0(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf67c0
void FUN_141bf67c0(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf67d0
void FUN_141bf67d0(longlong param_1)
{
  FUN_140964870(param_1 + 8);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf67f0
void  FUN_141bf67f0(NotifyChangeServer *this_)
{
  FUN_140939260((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6810
void  FUN_141bf6810(NotifyCreateMyPC *this_)
{
  FUN_140939260((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6830
void  FUN_141bf6830(NotifyGameStart *this_)
{
  FUN_140939260((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6850
void  FUN_141bf6850(NotifyRemoveGameObject *this_)
{
  FUN_140939260((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6870
void FUN_141bf6870(undefined8 param_1)
{
  FUN_140964870(param_1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6890
void  FUN_141bf6890(TextureLayerManager *this_)
{
  FUN_1410473c0((undefined1 *)this_);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf68b0
undefined1 * FUN_141bf68b0(undefined1 *param_1,undefined4 *param_2)
{
  *(undefined4 *)(param_1 + 4) = *param_2;
  *param_1 = 1;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf68e0
longlong * FUN_141bf68e0(longlong *param_1,longlong param_2)
{
  if (*param_1 != param_2) {
    if (*param_1 != 0) {
      FUN_1405a93d0(*param_1);
    }
    *param_1 = param_2;
    if (*param_1 != 0) {
      FUN_140980460(*param_1);
    }
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6950
longlong * FUN_141bf6950(longlong *param_1,longlong *param_2)
{
  if (*param_1 != *param_2) {
    if (*param_1 != 0) {
      (**(code **)(*(longlong *)*param_1 + 0x10))(*param_1);
    }
    *param_1 = *param_2;
    if (*param_1 != 0) {
      (**(code **)(*(longlong *)*param_1 + 8))(*param_1);
    }
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf69d0
longlong * FUN_141bf69d0(longlong *param_1,longlong *param_2)
{
  if (*param_1 != *param_2) {
    if (*param_1 != 0) {
      (**(code **)(*(longlong *)*param_1 + 0x10))(*param_1);
    }
    *param_1 = *param_2;
    if (*param_1 != 0) {
      (**(code **)(*(longlong *)*param_1 + 8))(*param_1);
    }
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6a50
longlong * FUN_141bf6a50(longlong *param_1,longlong *param_2)
{
  if (*param_1 != *param_2) {
    if (*param_1 != 0) {
      (**(code **)(*(longlong *)*param_1 + 0x10))(*param_1);
    }
    *param_1 = *param_2;
    if (*param_1 != 0) {
      (**(code **)(*(longlong *)*param_1 + 8))(*param_1);
    }
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6ad0
longlong * FUN_141bf6ad0(longlong *param_1,longlong param_2)
{
  if (*param_1 != param_2) {
    if (*param_1 != 0) {
      FUN_1405a93d0(*param_1);
    }
    *param_1 = param_2;
    if (*param_1 != 0) {
      FUN_140980460(*param_1);
    }
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6b40
longlong * FUN_141bf6b40(longlong *param_1,longlong param_2)
{
  if (*param_1 != param_2) {
    if (*param_1 != 0) {
      (**(code **)(*(longlong *)*param_1 + 0x10))(*param_1);
    }
    *param_1 = param_2;
    if (*param_1 != 0) {
      (**(code **)(*(longlong *)*param_1 + 8))(*param_1);
    }
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6bc0
longlong FUN_141bf6bc0(longlong param_1,longlong param_2)
{
  FUN_141c1f4a0(param_2);
  FUN_141c28c80(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6c00
longlong FUN_141bf6c00(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined1 local_18 [8];
  undefined8 local_10;
  
  FUN_141bf11b0(local_18,param_2);
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = local_10;
  local_10 = uVar1;
  FUN_141bf5570(local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6c70
longlong FUN_141bf6c70(longlong param_1,longlong param_2)
{
  FUN_141c1f4d0(param_2);
  FUN_1409f25e0(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6cb0
longlong FUN_141bf6cb0(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined1 local_18 [8];
  undefined8 local_10;
  
  FUN_141bf13c0(local_18,param_2);
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = local_10;
  local_10 = uVar1;
  FUN_14123ebe0(local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6d20
longlong FUN_141bf6d20(longlong param_1,longlong param_2)
{
  FUN_141c1f500(param_2);
  FUN_1410b4790(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6d60
longlong FUN_141bf6d60(longlong param_1,longlong param_2)
{
  FUN_140a7bac0(param_2);
  FUN_140969d60(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6da0
longlong FUN_141bf6da0(longlong param_1,longlong param_2)
{
  FUN_140968bd0(param_2);
  FUN_140969da0(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6de0
undefined8 FUN_141bf6de0(undefined8 param_1)
{
  FUN_141c28d00(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6e10
longlong FUN_141bf6e10(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined1 local_18 [8];
  undefined8 local_10;
  
  FUN_141bf1670(local_18,param_2);
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = local_10;
  local_10 = uVar1;
  FUN_141bf55d0(local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6e80
longlong FUN_141bf6e80(longlong param_1,longlong param_2)
{
  FUN_14174a7f0(param_2);
  FUN_14174b2b0(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6ec0
undefined8 FUN_141bf6ec0(undefined8 param_1)
{
  FUN_141c28d40(param_1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6ef0
longlong FUN_141bf6ef0(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined1 local_18 [8];
  undefined8 local_10;
  
  FUN_141bf1720(local_18,param_2);
  uVar1 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = local_10;
  local_10 = uVar1;
  FUN_141bf5600(local_18);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6f60
longlong FUN_141bf6f60(longlong param_1,longlong param_2)
{
  FUN_140b28610(param_2);
  FUN_141c28d80(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6fa0
longlong FUN_141bf6fa0(longlong param_1,longlong param_2)
{
  FUN_141c1f5c0(param_2);
  FUN_141c28dc0(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf6fe0
longlong FUN_141bf6fe0(longlong param_1,longlong param_2)
{
  FUN_141375140(param_2);
  FUN_1413751c0(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bf7020
longlong FUN_141bf7020(longlong param_1,longlong param_2)
{
  FUN_141c1f5f0(param_2);
  FUN_141c28e00(param_1);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  return param_1;
}
