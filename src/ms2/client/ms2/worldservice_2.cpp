// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService, part 2 of 4 (owner ws1).
// Functional tier: generated from the Ghidra decompile (work/ws/gen.py) as plain tagged functions.
// MS2-UNIT: ?\worldservice.cpp#2
// MS2-RANGE: 0x141bdbd10-0x141bedaf0 .text$mn
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
struct EntityLoadResult { void* a; void* b; };   // size UNVERIFIED
struct GameObjectEffectNifCtx { void* a; void* b; };   // size UNVERIFIED
struct _Container_proxy { void* a; void* b; };   // size UNVERIFIED
// ---- callees in the exe (variadic prototypes, return types from the decompile; bound by VA at link) ----
undefined8 FUN_140159860(...);
undefined8 FUN_140162e40(...);
undefined8 FUN_140162ef0(...);
undefined8 FUN_140162f10(...);
undefined8 FUN_140162f40(...);
undefined8 FUN_140162f70(...);
undefined8 FUN_140162f80(...);
undefined8 FUN_140163dc0(...);
undefined8 * FUN_140163e50(...);
undefined8 * FUN_140163e80(...);
ulonglong FUN_14016d660(...);
undefined8 FUN_140177620(...);
undefined8 FUN_140180bc0(...);
undefined8 FUN_140180c20(...);
bool FUN_140185090(...);
undefined8 FUN_14019b870(...);
undefined8 * FUN_1401d1ee0(...);
undefined8 * FUN_1401d2510(...);
undefined8 FUN_1401db5a0(...);
undefined8 FUN_1401db5d0(...);
undefined8 FUN_1401db5e0(...);
undefined8 FUN_1401db610(...);
undefined8 FUN_1401db6a0(...);
undefined8 * FUN_1401dbc50(...);
undefined8 FUN_1401ef2f0(...);
undefined8 FUN_1401ef380(...);
undefined8 FUN_1401ef3a0(...);
undefined8 FUN_1401ef400(...);
undefined8 FUN_1401ef440(...);
undefined8 * FUN_1401f03a0(...);
bool FUN_1401f1b70(...);
undefined8 FUN_1403311c0(...);
undefined8 FUN_14040e970(...);
undefined8 FUN_140442070(...);
undefined8 FUN_140442200(...);
undefined8 FUN_140442240(...);
undefined8 FUN_140442290(...);
undefined8 FUN_1404426d0(...);
undefined8 * FUN_1404459d0(...);
bool FUN_14044a540(...);
void * FUN_1404746a0(...);
undefined8 FUN_140474900(...);
undefined8 FUN_1406530d0(...);
longlong * FUN_14070f480(...);
undefined4 * FUN_140876480(...);
ulonglong * FUN_1408995b0(...);
undefined8 FUN_140899bd0(...);
longlong * FUN_1408b6680(...);
undefined8 FUN_1408b6b20(...);
undefined8 FUN_140963570(...);
undefined8 FUN_140963580(...);
longlong FUN_140963ff0(...);
longlong FUN_140964030(...);
undefined8 FUN_140969790(...);
undefined8 FUN_1409697b0(...);
undefined8 FUN_140969a80(...);
undefined8 FUN_140969ac0(...);
longlong FUN_140969b00(...);
longlong FUN_140969b40(...);
longlong FUN_14096b140(...);
longlong FUN_14096b180(...);
undefined8 FUN_140999030(...);
undefined8 FUN_140a144b0(...);
undefined8 FUN_140a14530(...);
undefined8 FUN_140a14560(...);
undefined8 FUN_140a14570(...);
undefined8 FUN_140a14dd0(...);
undefined8 FUN_140a14e30(...);
undefined8 FUN_140a14e50(...);
undefined8 FUN_140a15890(...);
undefined8 FUN_140a15e30(...);
bool FUN_140a16950(...);
undefined8 FUN_140a1b9b0(...);
undefined8 FUN_140a1b9e0(...);
undefined8 FUN_140a1be00(...);
undefined8 FUN_140a1be30(...);
undefined8 FUN_140a1c170(...);
undefined8 FUN_140a1c180(...);
undefined8 FUN_140a1c430(...);
longlong FUN_140a1c6b0(...);
longlong * FUN_140a1c800(...);
longlong FUN_140a1c9e0(...);
longlong FUN_140a1ca00(...);
longlong FUN_140a1ca80(...);
longlong FUN_140a1caa0(...);
undefined8 FUN_140a1cd60(...);
undefined8 FUN_140a1d600(...);
undefined8 FUN_140a7b650(...);
undefined8 FUN_140a7b660(...);
undefined8 FUN_140af5a50(...);
undefined8 FUN_140af5ad0(...);
longlong * FUN_140d98a60(...);
undefined8 FUN_14111ce10(...);
undefined8 FUN_14111d050(...);
undefined8 FUN_14111d0b0(...);
undefined8 FUN_14111d1c0(...);
undefined8 FUN_14111d4d0(...);
undefined8 * FUN_141122c00(...);
undefined8 FUN_14133e6f0(...);
undefined8 FUN_14133e700(...);
undefined8 FUN_14133e730(...);
undefined8 FUN_14133e750(...);
undefined8 * FUN_14133e9c0(...);
undefined8 FUN_1414c6a20(...);
undefined8 FUN_141531da0(...);
void * FUN_1415373e0(...);
undefined8 FUN_141537590(...);
void * FUN_141622af0(...);
undefined8 FUN_141623bd0(...);
undefined8 FUN_141623f00(...);
undefined8 FUN_141625060(...);
undefined8 FUN_141bdb890(...);
undefined8 FUN_141bdb910(...);
undefined8 FUN_141bdb940(...);
undefined8 FUN_141bdb970(...);
undefined8 FUN_141bdb9a0(...);
undefined8 FUN_141bdb9d0(...);
undefined8 FUN_141bdba00(...);
undefined8 FUN_141bdba30(...);
undefined8 FUN_141bdba60(...);
undefined8 FUN_141bdba90(...);
undefined8 FUN_141bdbac0(...);
undefined8 * FUN_141bdbc70(...);
undefined8 * FUN_141bdbcc0(...);
undefined8 FUN_141bedaf0(...);
undefined8 FUN_141bedb00(...);
undefined8 FUN_141bedb10(...);
undefined8 FUN_141bedb20(...);
undefined8 FUN_141bedb30(...);
undefined8 FUN_141bedb40(...);
undefined8 FUN_141bedb50(...);
undefined8 FUN_141bedb60(...);
undefined8 FUN_141bedb70(...);
undefined8 FUN_141bedc90(...);
undefined8 FUN_141bedcb0(...);
undefined8 FUN_141bedcd0(...);
undefined8 FUN_141bedcf0(...);
undefined8 FUN_141bee0f0(...);
undefined8 FUN_141bee190(...);
undefined8 FUN_141bee230(...);
undefined8 FUN_141bee2d0(...);
undefined8 FUN_141bee370(...);
undefined8 FUN_141bee410(...);
undefined8 FUN_141bee4b0(...);
undefined8 FUN_141bee7b0(...);
undefined8 FUN_141bee7e0(...);
undefined8 FUN_141bee7f0(...);
undefined8 FUN_141bee800(...);
undefined8 FUN_141bee810(...);
undefined8 FUN_141bee820(...);
undefined8 FUN_141bee830(...);
undefined8 FUN_141bee840(...);
undefined8 FUN_141bee850(...);
undefined8 FUN_141bee860(...);
undefined8 FUN_141bee870(...);
undefined8 FUN_141bee880(...);
undefined8 FUN_141bee890(...);
undefined8 FUN_141bee8a0(...);
undefined8 FUN_141bee8b0(...);
undefined8 FUN_141bee8c0(...);
undefined8 FUN_141bee8d0(...);
undefined8 FUN_141bee8e0(...);
undefined8 FUN_141bee8f0(...);
undefined8 FUN_141bee900(...);
undefined8 FUN_141bee910(...);
undefined8 FUN_141bee920(...);
undefined8 FUN_141bee930(...);
undefined8 FUN_141bee940(...);
undefined8 FUN_141bee950(...);
undefined8 FUN_141bee970(...);
undefined8 FUN_141bee980(...);
undefined8 FUN_141bee990(...);
undefined8 FUN_141bee9c0(...);
undefined8 FUN_141bee9d0(...);
undefined8 FUN_141bee9e0(...);
undefined8 FUN_141bee9f0(...);
undefined8 FUN_141beea00(...);
undefined8 FUN_141beea10(...);
undefined8 FUN_141beea20(...);
undefined8 FUN_141beea30(...);
undefined8 FUN_141beea40(...);
undefined8 FUN_141beea50(...);
undefined8 FUN_141beea60(...);
undefined8 FUN_141beea70(...);
undefined8 FUN_141beea80(...);
undefined8 FUN_141beea90(...);
undefined8 FUN_141beeaa0(...);
undefined8 FUN_141beeab0(...);
undefined8 FUN_141beeac0(...);
undefined8 FUN_141beead0(...);
undefined8 FUN_141beeae0(...);
undefined8 FUN_141beeaf0(...);
undefined8 FUN_141beeb00(...);
undefined8 FUN_141beeb10(...);
undefined8 FUN_141beeb20(...);
undefined8 FUN_141beeb30(...);
undefined8 FUN_141beeb40(...);
undefined8 FUN_141beeb50(...);
undefined8 FUN_141beeb60(...);
undefined8 FUN_141beeb70(...);
undefined8 FUN_141beeb80(...);
undefined8 FUN_141beeb90(...);
undefined8 FUN_141beeba0(...);
undefined8 FUN_141beebb0(...);
undefined8 FUN_141beebc0(...);
undefined8 FUN_141beebd0(...);
undefined8 FUN_141beebe0(...);
undefined8 FUN_141beebf0(...);
undefined8 FUN_141beec00(...);
undefined8 FUN_141beeee0(...);
undefined8 FUN_141beef00(...);
undefined8 FUN_141beef10(...);
undefined8 FUN_141beef20(...);
undefined8 FUN_141beef30(...);
undefined8 FUN_141beef40(...);
undefined8 FUN_141bf0640(...);
undefined8 FUN_141bf0700(...);
longlong * FUN_141bf0ed0(...);
longlong * FUN_141bf0f50(...);
longlong FUN_141bf11e0(...);
longlong FUN_141bf14d0(...);
longlong FUN_141bf1550(...);
longlong FUN_141bf17d0(...);
longlong FUN_141bf1800(...);
longlong FUN_141bf18b0(...);
undefined8 FUN_141bf19b0(...);
undefined8 FUN_141bf2090(...);
undefined8 FUN_141bf2110(...);
undefined8 FUN_141bf2170(...);
undefined8 FUN_141bf21d0(...);
undefined8 FUN_141bf22f0(...);
undefined8 FUN_141bf2310(...);
undefined8 FUN_141bf2350(...);
undefined8 FUN_141bf2370(...);
undefined8 FUN_141bf23b0(...);
undefined8 FUN_141bf23d0(...);
undefined8 FUN_141bf2410(...);
undefined8 FUN_141bf2450(...);
undefined8 FUN_141bf2490(...);
undefined8 FUN_141bf24d0(...);
undefined8 FUN_141bf2510(...);
undefined8 FUN_141bf2550(...);
undefined8 FUN_141bf2590(...);
undefined8 FUN_141bf25d0(...);
undefined8 * FUN_141bf2b30(...);
undefined8 * FUN_141bf2b70(...);
undefined8 * FUN_141bf2bb0(...);
undefined8 * FUN_141bf2bf0(...);
undefined8 * FUN_141bf2c30(...);
undefined1 * FUN_141bf3170(...);
undefined1 * FUN_141bf31d0(...);
undefined1 * FUN_141bf3230(...);
undefined1 * FUN_141bf3280(...);
undefined8 FUN_141bf33c0(...);
undefined8 * FUN_141bf4660(...);
undefined8 * FUN_141bf4740(...);
undefined8 FUN_141bf5570(...);
undefined8 FUN_141bf5b20(...);
undefined8 FUN_141bf5b60(...);
undefined8 FUN_141bf5ba0(...);
undefined8 FUN_141bf5be0(...);
undefined8 FUN_141bf5c20(...);
longlong FUN_141bf6c00(...);
longlong FUN_141bf6fa0(...);
bool FUN_141bf73c0(...);
bool FUN_141bf7400(...);
bool FUN_141bf7440(...);
bool FUN_141bf7480(...);
bool FUN_141bf74c0(...);
bool FUN_141bf7500(...);
bool FUN_141bf7540(...);
bool FUN_141bf7580(...);
bool FUN_141bf75c0(...);
bool FUN_141bf7600(...);
bool FUN_141bf78d0(...);
bool FUN_141bf7910(...);
undefined8 FUN_141bf7ef0(...);
undefined8 FUN_141bf8300(...);
undefined8 FUN_141bf8370(...);
undefined8 FUN_141bf83e0(...);
undefined8 FUN_141bf85a0(...);
undefined8 FUN_141bf8610(...);
undefined8 FUN_141bf8680(...);
undefined8 FUN_141bf8740(...);
undefined8 FUN_141bf8760(...);
undefined8 FUN_141bf8d60(...);
undefined8 FUN_141bf8d80(...);
undefined8 FUN_141bf8da0(...);
undefined8 FUN_141bf8dc0(...);
undefined8 FUN_141bf8e40(...);
undefined8 FUN_141bf8e60(...);
undefined8 FUN_141bf8e80(...);
undefined8 FUN_141bf8ea0(...);
undefined8 FUN_141bf8ec0(...);
undefined8 FUN_141bf8ee0(...);
undefined8 FUN_141bf8f00(...);
undefined8 FUN_141bf8f20(...);
undefined8 FUN_141bf8f40(...);
undefined8 FUN_141bf8f60(...);
undefined8 FUN_141bf8f80(...);
undefined8 FUN_141bf8fa0(...);
undefined8 FUN_141bf8fc0(...);
bool FUN_141bf9950(...);
undefined8 FUN_141bf9990(...);
undefined8 FUN_141c1ae60(...);
undefined8 FUN_141c20070(...);
undefined8 FUN_141c20130(...);
undefined8 FUN_141c20210(...);
undefined8 FUN_141c202f0(...);
undefined8 FUN_141c203d0(...);
undefined8 FUN_141c204b0(...);
undefined8 FUN_141c20590(...);
undefined8 FUN_141c20670(...);
undefined8 FUN_141c20750(...);
undefined8 FUN_141c20830(...);
undefined8 FUN_141c20910(...);
undefined8 FUN_141c209f0(...);
undefined8 FUN_141c20ad0(...);
undefined8 FUN_141c20b60(...);
undefined8 FUN_141c20bf0(...);
undefined8 FUN_141c20c80(...);
undefined8 FUN_141c20d10(...);
undefined8 FUN_141c20da0(...);
undefined8 FUN_141c20eb0(...);
undefined8 FUN_141c20fc0(...);
undefined8 FUN_141c210d0(...);
undefined8 FUN_141c211e0(...);
undefined8 FUN_141c212f0(...);
undefined8 FUN_141c21330(...);
undefined8 FUN_141c21370(...);
undefined8 FUN_141c213b0(...);
undefined8 FUN_141c213f0(...);
undefined8 FUN_141c21430(...);
undefined8 FUN_141c21470(...);
undefined8 FUN_141c214b0(...);
undefined8 FUN_141c214f0(...);
undefined8 FUN_141c21530(...);
undefined8 FUN_141c21570(...);
undefined8 FUN_141c21930(...);
undefined8 FUN_141c21980(...);
undefined8 FUN_141c219d0(...);
undefined8 FUN_141c21a20(...);
undefined8 FUN_141c21a70(...);
undefined8 FUN_141c21ac0(...);
undefined8 FUN_141c21b10(...);
undefined8 FUN_141c21b60(...);
undefined8 FUN_141c21bb0(...);
undefined8 FUN_141c21c00(...);
undefined8 FUN_141c21c10(...);
undefined8 FUN_141c26000(...);
undefined8 FUN_141c26030(...);
undefined8 FUN_141c26060(...);
undefined8 FUN_141c26090(...);
undefined8 FUN_141c260c0(...);
undefined8 FUN_141c260f0(...);
undefined8 FUN_141c26120(...);
undefined8 FUN_141c26150(...);
undefined8 FUN_141c26180(...);
undefined8 FUN_141c261b0(...);
undefined8 FUN_141c261e0(...);
undefined8 FUN_141c26210(...);
undefined8 FUN_141c26240(...);
undefined8 FUN_141c26270(...);
undefined8 FUN_141c262a0(...);
undefined8 FUN_141c262d0(...);
undefined8 FUN_141c26300(...);
undefined8 FUN_141c26330(...);
undefined8 FUN_141c26360(...);
undefined8 FUN_141c26390(...);
undefined8 FUN_141c26bb0(...);
undefined8 FUN_141c26bf0(...);
undefined8 FUN_141c26c50(...);
undefined8 FUN_141c26cb0(...);
undefined8 FUN_141c26d10(...);
undefined8 FUN_141c26d70(...);
undefined8 FUN_141c26dd0(...);
undefined8 FUN_141c26e30(...);
undefined8 FUN_141c26e90(...);
undefined8 FUN_141c26ef0(...);
undefined8 FUN_141c26f50(...);
undefined8 FUN_141c27000(...);
undefined8 FUN_141c27040(...);
undefined8 FUN_141c270c0(...);
undefined8 FUN_141c27100(...);
undefined8 FUN_141c27140(...);
undefined8 FUN_141c27180(...);
undefined8 FUN_141c271c0(...);
undefined8 FUN_141c27200(...);
undefined8 FUN_141c27240(...);
undefined8 FUN_141c27280(...);
undefined8 FUN_141c272c0(...);
undefined8 FUN_141c272e0(...);
undefined8 FUN_141c27300(...);
undefined8 FUN_141c27320(...);
undefined8 FUN_141c27340(...);
undefined8 FUN_141c27380(...);
undefined8 FUN_141c27530(...);
undefined8 FUN_141c275b0(...);
undefined8 FUN_141c27630(...);
undefined8 FUN_141c27660(...);
undefined8 FUN_141c27690(...);
undefined8 FUN_141c276c0(...);
undefined8 FUN_141c276f0(...);
undefined8 FUN_141c27720(...);
undefined8 FUN_141c27750(...);
undefined8 FUN_141c27780(...);
undefined8 FUN_141c277b0(...);
undefined8 FUN_141c277e0(...);
undefined8 FUN_141c27810(...);
undefined8 FUN_141c27840(...);
undefined8 FUN_141c27860(...);
undefined8 FUN_141c27880(...);
undefined8 FUN_141c278a0(...);
undefined8 FUN_141c278c0(...);
undefined8 FUN_141c278e0(...);
undefined8 FUN_141c27900(...);
undefined8 FUN_141c27920(...);
undefined8 FUN_141c27940(...);
undefined8 FUN_141c27960(...);
undefined8 FUN_141c27980(...);
undefined8 FUN_141c279c0(...);
undefined8 FUN_141c279d0(...);
undefined8 FUN_141c279e0(...);
undefined8 FUN_141c279f0(...);
undefined8 FUN_141c27a00(...);
undefined8 FUN_141c27a10(...);
undefined8 FUN_141c27a20(...);
undefined8 FUN_141c27a30(...);
undefined8 FUN_141c27a40(...);
undefined8 FUN_141c27a50(...);
undefined8 FUN_141c27a60(...);
undefined8 FUN_141c27b40(...);
undefined8 FUN_141c27c20(...);
undefined8 FUN_141c27d00(...);
undefined8 FUN_141c27de0(...);
undefined8 FUN_141c27ec0(...);
undefined8 FUN_141c27fa0(...);
undefined8 FUN_141c28080(...);
undefined8 FUN_141c28160(...);
undefined8 FUN_141c28240(...);
undefined8 FUN_141c28870(...);
undefined8 FUN_141c288b0(...);
undefined8 FUN_141c288f0(...);
undefined8 FUN_141c28970(...);
undefined8 FUN_141c289b0(...);
undefined8 FUN_141c289f0(...);
undefined8 FUN_141c28af0(...);
undefined8 FUN_141c28b00(...);
undefined8 FUN_141c28b10(...);
undefined8 FUN_141c28b20(...);
undefined8 FUN_141c28b30(...);
undefined8 FUN_141c28e40(...);
undefined8 FUN_141c28e60(...);
undefined8 FUN_141c28e80(...);
undefined8 FUN_141c28ea0(...);
undefined8 FUN_141c28ec0(...);
undefined8 FUN_141c29110(...);
undefined8 FUN_141c29130(...);
undefined8 FUN_141c29150(...);
undefined8 FUN_141c29170(...);
undefined8 FUN_141c29190(...);
undefined8 FUN_141c291b0(...);
undefined8 FUN_141c291d0(...);
undefined8 FUN_141c291f0(...);
undefined8 FUN_141c29210(...);
undefined8 FUN_141c29230(...);
undefined8 FUN_141c29250(...);
undefined8 FUN_141c29270(...);
undefined8 FUN_141c29290(...);
undefined8 FUN_141c292b0(...);
undefined8 FUN_141c292d0(...);
undefined8 FUN_141c292f0(...);
undefined8 FUN_141c29310(...);
undefined8 FUN_141c29330(...);
undefined8 FUN_141c29350(...);
undefined8 FUN_141c29370(...);
undefined8 FUN_141c29390(...);
undefined8 FUN_141c29470(...);
undefined8 FUN_141c29550(...);
undefined8 FUN_141c29630(...);
undefined8 FUN_141c29710(...);
undefined8 FUN_141c297f0(...);
undefined8 FUN_141c298d0(...);
undefined8 FUN_141c299b0(...);
undefined8 FUN_141c29a90(...);
undefined8 FUN_141c29b70(...);
undefined8 FUN_141c2a360(...);
undefined8 FUN_141c2a3a0(...);
undefined8 FUN_141c2a3e0(...);
undefined8 FUN_141c2a420(...);
undefined8 FUN_141c2a460(...);
undefined8 FUN_141c2a5e0(...);
undefined8 FUN_141c2a640(...);
undefined8 FUN_141c2a6a0(...);
undefined8 FUN_141c2a700(...);
undefined8 FUN_141c2a760(...);
undefined8 FUN_141c2a8b0(...);
undefined8 FUN_141c2a8d0(...);
undefined8 FUN_141c2a8f0(...);
undefined8 FUN_141c2a910(...);
undefined8 FUN_141c2a930(...);
undefined8 FUN_141c2ab60(...);
undefined8 FUN_141c2ab90(...);
undefined8 FUN_141c2abc0(...);
undefined8 FUN_141c2abf0(...);
undefined8 FUN_141c2ac20(...);
undefined8 FUN_141c2ac50(...);
undefined8 FUN_141c2acc0(...);
undefined8 FUN_141c2ad30(...);
undefined8 FUN_141c2ada0(...);
undefined8 FUN_141c2ae10(...);
undefined8 FUN_141c2ae80(...);
undefined8 FUN_141c2aef0(...);
undefined8 FUN_141c2af60(...);
undefined8 FUN_141c2afd0(...);
undefined8 FUN_141c2b040(...);
undefined8 FUN_141c2bba0(...);
undefined8 FUN_141c2bbd0(...);
undefined8 FUN_141c2bc00(...);
undefined8 FUN_141c2bc30(...);
undefined8 FUN_141c2bc60(...);
undefined8 FUN_141c2bc90(...);
undefined8 FUN_141c2bcc0(...);
undefined8 FUN_141c2bcf0(...);
undefined8 FUN_141c2bd20(...);
undefined8 FUN_141c2bd50(...);
undefined8 FUN_141c2bd80(...);
undefined8 FUN_141c2c220(...);
undefined8 FUN_141c2c280(...);
undefined8 FUN_141c2c2e0(...);
undefined8 FUN_141c2c460(...);
undefined8 FUN_141c2c4c0(...);
undefined8 FUN_141c2c520(...);
undefined8 FUN_141c2e120(...);
undefined8 FUN_141c2e180(...);
undefined8 FUN_141c2e1e0(...);
undefined8 FUN_141c2e360(...);
undefined8 FUN_141c2e3c0(...);
undefined8 FUN_141c2e420(...);
undefined8 FUN_141c2e660(...);
undefined8 FUN_141c2e680(...);
undefined8 FUN_141c2e6a0(...);
undefined8 FUN_141c2e6c0(...);
undefined8 FUN_141c2e6e0(...);
undefined8 FUN_141c2e700(...);
undefined8 FUN_141c2e720(...);
undefined8 FUN_141c2e740(...);
undefined8 FUN_141c2e760(...);
undefined8 FUN_141c2e780(...);
undefined8 FUN_141c2e7a0(...);
undefined8 FUN_141c2e800(...);
undefined8 FUN_141c2e850(...);
undefined8 FUN_141c2e8a0(...);
undefined8 FUN_141c2e8f0(...);
undefined8 FUN_141c2e940(...);
undefined8 FUN_141c2ed10(...);
undefined8 FUN_141c2ed30(...);
undefined8 FUN_141c2ed50(...);
undefined8 FUN_141c2ed70(...);
undefined8 FUN_141c2ed90(...);
undefined8 FUN_141c2edb0(...);
undefined8 FUN_141c2ee10(...);
undefined8 FUN_141c2ee50(...);
undefined8 FUN_141c2eea0(...);
undefined8 FUN_14208a860(...);
undefined8 FUN_14214f570(...);
undefined8 FUN_142172a80(...);
// ---- functions of this unit (forward declarations) ----
undefined8 FUN_141bdbd10(...);
undefined8 * FUN_141bdbd10(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbd60(...);
undefined8 * FUN_141bdbd60(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbdb0(...);
undefined8 * FUN_141bdbdb0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbe00(...);
undefined8 * FUN_141bdbe00(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbe50(...);
undefined8 * FUN_141bdbe50(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbea0(...);
undefined8 * FUN_141bdbea0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbef0(...);
undefined8 * FUN_141bdbef0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbf40(...);
undefined8 * FUN_141bdbf40(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbf90(...);
undefined8 * FUN_141bdbf90(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdbfe0(...);
undefined8 * FUN_141bdbfe0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc030(...);
undefined8 * FUN_141bdc030(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc080(...);
undefined8 * FUN_141bdc080(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc0d0(...);
undefined8 * FUN_141bdc0d0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc120(...);
longlong FUN_141bdc120(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc170(...);
undefined8 FUN_141bdc170(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc1c0(...);
undefined8 FUN_141bdc1c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc210(...);
undefined8 FUN_141bdc210(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc260(...);
undefined8 FUN_141bdc260(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc2b0(...);
undefined8 FUN_141bdc2b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc300(...);
undefined8 FUN_141bdc300(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc350(...);
undefined8 FUN_141bdc350(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc3a0(...);
undefined8 FUN_141bdc3a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc3f0(...);
undefined8 FUN_141bdc3f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc440(...);
undefined8 FUN_141bdc440(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc490(...);
undefined8 FUN_141bdc490(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc4e0(...);
undefined8 FUN_141bdc4e0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc530(...);
undefined8 FUN_141bdc530(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc580(...);
undefined8 FUN_141bdc580(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc5d0(...);
undefined8 FUN_141bdc5d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc620(...);
longlong FUN_141bdc620(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc670(...);
longlong FUN_141bdc670(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc6c0(...);
undefined8 FUN_141bdc6c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdc710(...);
undefined8 * FUN_141bdc710(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc790(...);
undefined8 * FUN_141bdc790(undefined8 *param_1,undefined8 param_2,undefined1 *param_3);
undefined8 FUN_141bdc830(...);
undefined8 * FUN_141bdc830(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc880(...);
undefined8 * FUN_141bdc880(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc8d0(...);
undefined8 * FUN_141bdc8d0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc920(...);
undefined8 * FUN_141bdc920(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc970(...);
undefined8 * FUN_141bdc970(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdc9c0(...);
undefined8 * FUN_141bdc9c0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdca10(...);
undefined8 * FUN_141bdca10(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdca60(...);
undefined8 * FUN_141bdca60(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdcab0(...);
undefined8 * FUN_141bdcab0(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdcb00(...);
undefined8 * FUN_141bdcb00(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdcb50(...);
undefined8 * FUN_141bdcb50(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdcba0(...);
undefined8 * FUN_141bdcba0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bdcbf0(...);
undefined4 * FUN_141bdcbf0(undefined4 *param_1,undefined8 param_2);
undefined8 FUN_141bdcc40(...);
undefined4 * FUN_141bdcc40(undefined4 *param_1,undefined8 param_2);
undefined8 FUN_141bdcc90(...);
undefined4 * FUN_141bdcc90(undefined4 *param_1,undefined8 param_2);
undefined8 FUN_141bdcce0(...);
longlong FUN_141bdcce0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdcd40(...);
longlong FUN_141bdcd40(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdcd90(...);
undefined8 * FUN_141bdcd90(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bdcde0(...);
longlong FUN_141bdcde0(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdce30(...);
longlong FUN_141bdce30(longlong param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdce80(...);
longlong FUN_141bdce80(longlong param_1);
undefined8 FUN_141bdceb0(...);
longlong FUN_141bdceb0(longlong param_1,longlong param_2);
undefined8 FUN_141bdcf10(...);
longlong FUN_141bdcf10(longlong param_1,longlong param_2);
undefined8 FUN_141bdcf70(...);
longlong FUN_141bdcf70(longlong param_1,longlong param_2);
undefined8 FUN_141bdcfd0(...);
undefined8 * FUN_141bdcfd0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bdd000(...);
undefined8 * FUN_141bdd000(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141bdd030(...);
longlong FUN_141bdd030(longlong param_1,longlong param_2);
undefined8 FUN_141bdd080(...);
longlong * FUN_141bdd080(longlong *param_1,undefined8 param_2);
undefined8 FUN_141bdd120(...);
undefined8 FUN_141bdd120(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdd1b0(...);
void FUN_141bdd1b0(undefined8 *param_1,undefined4 param_2);
undefined8 FUN_141bdd1e0(...);
void FUN_141bdd1e0(undefined8 *param_1,undefined4 param_2);
undefined8 FUN_141bdd210(...);
void FUN_141bdd210(undefined8 *param_1,undefined4 param_2);
undefined8 FUN_141bdd240(...);
void FUN_141bdd240(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4, undefined8 *param_5,undefined8 param_6);
undefined8 FUN_141bdd540(...);
undefined8 FUN_141bdd540(longlong *param_1);
undefined8 FUN_141bdd590(...);
undefined8 FUN_141bdd590(longlong *param_1);
undefined8 FUN_141bdd5e0(...);
undefined8 FUN_141bdd5e0(undefined8 param_1);
undefined8 FUN_141bdd660(...);
undefined8 FUN_141bdd660(longlong *param_1);
undefined8 FUN_141bdd6b0(...);
 undefined8 FUN_141bdd6b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdd750(...);
undefined8 FUN_141bdd750(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdd7f0(...);
undefined8 FUN_141bdd7f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdd890(...);
undefined8 FUN_141bdd890(void);
undefined8 FUN_141bdd900(...);
undefined8 FUN_141bdd900(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdd920(...);
undefined8 FUN_141bdd920(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdd940(...);
undefined8 FUN_141bdd940(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdd960(...);
undefined8 FUN_141bdd960(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdd980(...);
undefined8 FUN_141bdd980(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdd9a0(...);
undefined8 FUN_141bdd9a0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdd9c0(...);
undefined8 FUN_141bdd9c0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdd9e0(...);
undefined8 FUN_141bdd9e0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdda00(...);
undefined8 FUN_141bdda00(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdda20(...);
undefined8 FUN_141bdda20(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdda50(...);
undefined8 FUN_141bdda50(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdda80(...);
longlong FUN_141bdda80(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bddb10(...);
longlong FUN_141bddb10(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bddba0(...);
longlong FUN_141bddba0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bddc30(...);
longlong FUN_141bddc30(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bddcc0(...);
longlong FUN_141bddcc0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bddd90(...);
longlong FUN_141bddd90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bdde60(...);
longlong FUN_141bdde60(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bddf30(...);
longlong FUN_141bddf30(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bde000(...);
longlong FUN_141bde000(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bde0d0(...);
longlong FUN_141bde0d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bde1a0(...);
longlong FUN_141bde1a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bde270(...);
longlong FUN_141bde270(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bde300(...);
longlong FUN_141bde300(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bde390(...);
longlong FUN_141bde390(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bde420(...);
longlong FUN_141bde420(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bde4b0(...);
void FUN_141bde4b0(undefined8 param_1,undefined8 param_2,undefined1 param_3);
undefined8 FUN_141bde5d0(...);
undefined8 * FUN_141bde5d0(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined1 param_4);
undefined8 FUN_141bde6e0(...);
undefined8 FUN_141bde6e0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bde710(...);
void FUN_141bde710(longlong param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bde770(...);
void FUN_141bde770(longlong param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bde7d0(...);
void FUN_141bde7d0(longlong param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bde830(...);
void FUN_141bde830(longlong param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bde890(...);
void FUN_141bde890(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bde8e0(...);
void FUN_141bde8e0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bde930(...);
void FUN_141bde930(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bde980(...);
void FUN_141bde980(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bde9d0(...);
longlong FUN_141bde9d0(undefined8 param_1,undefined8 param_2,undefined1 param_3);
undefined8 FUN_141bdea30(...);
longlong FUN_141bdea30(undefined8 param_1,undefined8 param_2,undefined1 param_3);
undefined8 FUN_141bdea90(...);
void FUN_141bdea90(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdeaf0(...);
void FUN_141bdeaf0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdeb50(...);
void FUN_141bdeb50(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdebb0(...);
void FUN_141bdebb0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdec10(...);
void FUN_141bdec10(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdec70(...);
void FUN_141bdec70(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdecd0(...);
void FUN_141bdecd0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bded30(...);
void FUN_141bded30(longlong param_1,undefined8 param_2);
undefined8 FUN_141bded90(...);
void FUN_141bded90(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdedf0(...);
void FUN_141bdedf0(longlong param_1,undefined8 param_2);
undefined8 FUN_141bdee50(...);
void FUN_141bdee50(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdef10(...);
void FUN_141bdef10(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdefd0(...);
void FUN_141bdefd0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdf090(...);
void FUN_141bdf090(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdf150(...);
void FUN_141bdf150(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bdf210(...);
longlong FUN_141bdf210(undefined8 param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bdf460(...);
longlong FUN_141bdf460(undefined8 param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bdf6b0(...);
longlong FUN_141bdf6b0(undefined8 param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bdf900(...);
longlong FUN_141bdf900(undefined8 param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bdfb50(...);
longlong FUN_141bdfb50(undefined8 param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141bdfda0(...);
undefined8 FUN_141bdfda0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bdfe30(...);
undefined8 FUN_141bdfe30(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141be0070(...);
undefined8 FUN_141be0070(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141be0100(...);
undefined8 FUN_141be0100(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141be0340(...);
void FUN_141be0340(undefined8 param_1,longlong param_2);
undefined8 FUN_141be03b0(...);
void FUN_141be03b0(undefined8 param_1,longlong param_2);
undefined8 FUN_141be0440(...);
void FUN_141be0440(undefined8 param_1,longlong param_2);
undefined8 FUN_141be04d0(...);
void FUN_141be04d0(undefined8 param_1,longlong param_2);
undefined8 FUN_141be0560(...);
void FUN_141be0560(undefined8 param_1,longlong param_2);
undefined8 FUN_141be05f0(...);
void FUN_141be05f0(undefined8 param_1,longlong param_2);
undefined8 FUN_141be0680(...);
void FUN_141be0680(undefined8 param_1,longlong param_2);
undefined8 FUN_141be0710(...);
void FUN_141be0710(undefined8 param_1,longlong param_2);
undefined8 FUN_141be07a0(...);
void FUN_141be07a0(undefined8 param_1,longlong param_2);
undefined8 FUN_141be0830(...);
void FUN_141be0830(undefined8 param_1,longlong param_2);
undefined8 FUN_141be08c0(...);
void FUN_141be08c0(undefined8 param_1,longlong param_2);
undefined8 FUN_141be0950(...);
undefined8 FUN_141be0950(undefined8 param_1);
undefined8 FUN_141be0960(...);
undefined8 FUN_141be0960(undefined8 param_1);
undefined8 FUN_141be0970(...);
undefined8 FUN_141be0970(undefined8 param_1);
undefined8 FUN_141be0980(...);
undefined8 FUN_141be0980(undefined8 param_1);
undefined8 FUN_141be0990(...);
undefined8 FUN_141be0990(undefined8 param_1);
undefined8 FUN_141be09a0(...);
undefined8 FUN_141be09a0(undefined8 param_1);
undefined8 FUN_141be09b0(...);
undefined8 FUN_141be09b0(undefined8 param_1);
undefined8 FUN_141be09c0(...);
undefined8 FUN_141be09c0(undefined8 param_1);
undefined8 FUN_141be09d0(...);
undefined8 FUN_141be09d0(undefined8 param_1);
undefined8 FUN_141be09e0(...);
undefined8 FUN_141be09e0(undefined8 param_1);
undefined8 FUN_141be09f0(...);
longlong FUN_141be09f0(longlong *param_1,longlong *param_2);
undefined8 FUN_141be0a20(...);
longlong FUN_141be0a20(longlong *param_1,longlong *param_2);
undefined8 FUN_141be0a50(...);
longlong FUN_141be0a50(longlong *param_1,longlong *param_2);
undefined8 FUN_141be0a80(...);
longlong FUN_141be0a80(longlong *param_1,longlong *param_2);
undefined8 FUN_141be0ab0(...);
longlong FUN_141be0ab0(longlong *param_1,longlong *param_2);
undefined8 FUN_141be0ae0(...);
undefined8 FUN_141be0ae0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141be0b10(...);
undefined8 FUN_141be0b10(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141be0b40(...);
undefined8 FUN_141be0b40(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141be0b70(...);
undefined8 FUN_141be0b70(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141be0ba0(...);
undefined8 FUN_141be0ba0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141be0bd0(...);
void FUN_141be0bd0(undefined8 param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141be0c50(...);
void FUN_141be0c50(undefined8 param_1,longlong param_2,undefined8 param_3);
undefined8 FUN_141be0cd0(...);
undefined8 FUN_141be0cd0(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be1030(...);
undefined8 FUN_141be1030(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be1390(...);
undefined8 FUN_141be1390(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be16f0(...);
undefined8 FUN_141be16f0(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be1a50(...);
undefined8 FUN_141be1a50(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be1db0(...);
undefined8 FUN_141be1db0(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be2110(...);
undefined8 FUN_141be2110(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be2470(...);
undefined8 FUN_141be2470(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be27d0(...);
undefined8 FUN_141be27d0(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6);
undefined8 FUN_141be2b30(...);
undefined8 FUN_141be2b30(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined1 param_6);
undefined8 FUN_141be2e90(...);
undefined8 FUN_141be2e90(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined1 param_6);
undefined8 FUN_141be31f0(...);
 undefined8 * FUN_141be31f0(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be3e30(...);
 undefined8 * FUN_141be3e30(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be4a70(...);
 undefined8 * FUN_141be4a70(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be56b0(...);
 undefined8 * FUN_141be56b0(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be62f0(...);
 undefined8 * FUN_141be62f0(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be6f30(...);
 undefined8 * FUN_141be6f30(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be7b70(...);
 undefined8 FUN_141be7b70(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be7f80(...);
 undefined8 FUN_141be7f80(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be8390(...);
 undefined8 FUN_141be8390(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be87a0(...);
 undefined8 FUN_141be87a0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be8bb0(...);
 undefined8 FUN_141be8bb0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be8fc0(...);
 undefined8 FUN_141be8fc0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be93d0(...);
 undefined8 FUN_141be93d0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be97e0(...);
 undefined8 FUN_141be97e0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141be9bf0(...);
 undefined8 FUN_141be9bf0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141bea000(...);
 undefined8 FUN_141bea000(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined1 param_5);
undefined8 FUN_141bea410(...);
 undefined8 FUN_141bea410(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined1 param_5);
undefined8 FUN_141bea820(...);
undefined8 FUN_141bea820(undefined8 param_1);
undefined8 FUN_141bea830(...);
undefined8 FUN_141bea830(undefined8 param_1);
undefined8 FUN_141bea840(...);
undefined8 FUN_141bea840(undefined8 param_1);
undefined8 FUN_141bea850(...);
undefined8 FUN_141bea850(undefined8 param_1);
undefined8 FUN_141bea860(...);
undefined8 FUN_141bea860(undefined8 param_1);
undefined8 FUN_141bea870(...);
undefined8 FUN_141bea870(undefined8 param_1);
undefined8 FUN_141bea880(...);
undefined8 FUN_141bea880(undefined8 param_1);
undefined8 FUN_141bea890(...);
undefined8 FUN_141bea890(undefined8 param_1);
undefined8 FUN_141bea8a0(...);
undefined8 FUN_141bea8a0(undefined8 param_1);
undefined8 FUN_141bea8b0(...);
undefined8 * FUN_141bea8b0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bea950(...);
undefined8 * FUN_141bea950(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bea9f0(...);
undefined8 * FUN_141bea9f0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beaa90(...);
undefined8 * FUN_141beaa90(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beab30(...);
undefined8 * FUN_141beab30(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beabd0(...);
undefined8 * FUN_141beabd0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beac70(...);
undefined8 * FUN_141beac70(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141bead10(...);
undefined8 * FUN_141bead10(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beadb0(...);
undefined8 * FUN_141beadb0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beae50(...);
undefined8 * FUN_141beae50(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beaef0(...);
undefined8 * FUN_141beaef0(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beaf90(...);
 longlong FUN_141beaf90(longlong param_1,longlong param_2,longlong param_3);
undefined8 FUN_141beb000(...);
void FUN_141beb000(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beb050(...);
 void FUN_141beb050(undefined8 param_1,undefined8 param_2);
undefined8 FUN_141beb080(...);
void FUN_141beb080(void);
undefined8 FUN_141beb090(...);
undefined1 FUN_141beb090(void);
undefined8 FUN_141beb0c0(...);
undefined1 FUN_141beb0c0(void);
undefined8 FUN_141beb0f0(...);
undefined1 FUN_141beb0f0(void);
undefined8 FUN_141beb120(...);
undefined1 FUN_141beb120(void);
undefined8 FUN_141beb150(...);
undefined1 FUN_141beb150(void);
undefined8 FUN_141beb180(...);
undefined1 FUN_141beb180(void);
undefined8 FUN_141beb1b0(...);
undefined1 FUN_141beb1b0(void);
undefined8 FUN_141beb1e0(...);
undefined1 FUN_141beb1e0(void);
undefined8 FUN_141beb210(...);
undefined1 FUN_141beb210(void);
undefined8 FUN_141beb240(...);
undefined1 FUN_141beb240(void);
undefined8 FUN_141beb270(...);
void FUN_141beb270(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141beb290(...);
void FUN_141beb290(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141beb2b0(...);
void FUN_141beb2b0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141beb2d0(...);
void FUN_141beb2d0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141beb2f0(...);
void FUN_141beb2f0(undefined8 *param_1,undefined8 param_2);
undefined8 FUN_141beb310(...);
undefined8 FUN_141beb310(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beb460(...);
undefined8 FUN_141beb460(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beb5b0(...);
undefined8 FUN_141beb5b0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beb700(...);
undefined8 FUN_141beb700(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beb850(...);
undefined8 FUN_141beb850(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beb9a0(...);
undefined8 FUN_141beb9a0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bebaf0(...);
undefined8 FUN_141bebaf0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bebc40(...);
undefined8 FUN_141bebc40(undefined8 param_1);
undefined8 FUN_141bebc50(...);
undefined8 FUN_141bebc50(undefined8 param_1);
undefined8 FUN_141bebc60(...);
undefined8 FUN_141bebc60(undefined8 param_1);
undefined8 FUN_141bebc70(...);
undefined8 FUN_141bebc70(undefined8 param_1);
undefined8 FUN_141bebc80(...);
undefined8 FUN_141bebc80(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bebd50(...);
undefined8 FUN_141bebd50(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bebe20(...);
undefined8 FUN_141bebe20(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bebef0(...);
undefined8 FUN_141bebef0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bebfc0(...);
undefined8 FUN_141bebfc0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec090(...);
undefined8 FUN_141bec090(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec120(...);
undefined8 FUN_141bec120(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec1b0(...);
undefined8 FUN_141bec1b0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec240(...);
undefined8 FUN_141bec240(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec2d0(...);
undefined8 FUN_141bec2d0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec360(...);
undefined8 FUN_141bec360(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec430(...);
undefined8 FUN_141bec430(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec500(...);
undefined8 FUN_141bec500(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec5d0(...);
undefined8 FUN_141bec5d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec6a0(...);
undefined8 FUN_141bec6a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec770(...);
undefined8 FUN_141bec770(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec800(...);
undefined8 FUN_141bec800(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec890(...);
undefined8 FUN_141bec890(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec920(...);
undefined8 FUN_141bec920(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141bec9b0(...);
undefined8 FUN_141bec9b0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4);
undefined8 FUN_141beca40(...);
undefined8 FUN_141beca40(undefined8 param_1);
undefined8 FUN_141beca50(...);
undefined8 FUN_141beca50(undefined8 param_1);
undefined8 FUN_141beca60(...);
undefined8 FUN_141beca60(undefined8 param_1);
undefined8 FUN_141beca70(...);
undefined8 FUN_141beca70(undefined8 param_1);
undefined8 FUN_141beca80(...);
undefined8 FUN_141beca80(undefined8 param_1);
undefined8 FUN_141beca90(...);
undefined8 FUN_141beca90(undefined8 param_1);
undefined8 FUN_141becaa0(...);
undefined8 FUN_141becaa0(undefined8 param_1);
undefined8 FUN_141becab0(...);
undefined8 FUN_141becab0(undefined8 param_1);
undefined8 FUN_141becac0(...);
undefined8 FUN_141becac0(undefined8 param_1);
undefined8 FUN_141becad0(...);
undefined8 FUN_141becad0(undefined8 param_1);
undefined8 FUN_141becae0(...);
undefined8 FUN_141becae0(undefined8 param_1);
undefined8 FUN_141becaf0(...);
undefined8 FUN_141becaf0(undefined8 param_1);
undefined8 FUN_141becb00(...);
undefined8 FUN_141becb00(undefined8 param_1);
undefined8 FUN_141becb10(...);
undefined8 FUN_141becb10(undefined8 param_1);
undefined8 FUN_141becb20(...);
undefined8 FUN_141becb20(undefined8 param_1);
undefined8 FUN_141becb30(...);
undefined8 FUN_141becb30(undefined8 param_1);
undefined8 FUN_141becb40(...);
undefined8 FUN_141becb40(undefined8 param_1);
undefined8 FUN_141becb50(...);
undefined8 FUN_141becb50(undefined8 param_1);
undefined8 FUN_141becb60(...);
undefined8 FUN_141becb60(undefined8 param_1);
undefined8 FUN_141becb70(...);
undefined8 FUN_141becb70(undefined8 param_1);
undefined8 FUN_141becb80(...);
undefined8 FUN_141becb80(undefined8 param_1);
undefined8 FUN_141becb90(...);
undefined8 FUN_141becb90(undefined8 param_1);
undefined8 FUN_141becba0(...);
undefined8 FUN_141becba0(undefined8 param_1);
undefined8 FUN_141becbb0(...);
undefined8 FUN_141becbb0(undefined8 param_1);
undefined8 FUN_141becbc0(...);
undefined8 FUN_141becbc0(undefined8 param_1);
undefined8 FUN_141becbd0(...);
undefined8 FUN_141becbd0(undefined8 param_1);
undefined8 FUN_141becbe0(...);
undefined8 FUN_141becbe0(undefined8 param_1);
undefined8 FUN_141becbf0(...);
undefined8 FUN_141becbf0(undefined8 param_1);
undefined8 FUN_141becc00(...);
undefined8 FUN_141becc00(undefined8 param_1);
undefined8 FUN_141becc10(...);
undefined8 FUN_141becc10(undefined8 param_1);
undefined8 FUN_141becc20(...);
undefined8 FUN_141becc20(undefined8 param_1);
undefined8 FUN_141becc30(...);
undefined8 FUN_141becc30(undefined8 param_1);
undefined8 FUN_141becc40(...);
undefined8 FUN_141becc40(undefined8 param_1);
undefined8 FUN_141becc50(...);
undefined8 FUN_141becc50(undefined8 param_1);
undefined8 FUN_141becc60(...);
undefined8 FUN_141becc60(undefined8 param_1);
undefined8 FUN_141becc70(...);
undefined8 FUN_141becc70(undefined8 param_1);
undefined8 FUN_141becc80(...);
undefined8 FUN_141becc80(undefined8 param_1);
undefined8 FUN_141becc90(...);
undefined8 FUN_141becc90(undefined8 param_1);
undefined8 FUN_141becca0(...);
 void FUN_141becca0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beccf0(...);
 void FUN_141beccf0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141becd40(...);
 void FUN_141becd40(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141becd90(...);
 void FUN_141becd90(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141becde0(...);
 void FUN_141becde0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bece30(...);
 void FUN_141bece30(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bece80(...);
 void FUN_141bece80(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beced0(...);
 void FUN_141beced0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141becf20(...);
 void FUN_141becf20(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141becf70(...);
 void FUN_141becf70(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141becfc0(...);
 void FUN_141becfc0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed010(...);
 void FUN_141bed010(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed060(...);
 void FUN_141bed060(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed0b0(...);
 void FUN_141bed0b0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed100(...);
void FUN_141bed100(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141bed1b0(...);
void FUN_141bed1b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141bed260(...);
void FUN_141bed260(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141bed310(...);
void FUN_141bed310(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed360(...);
void FUN_141bed360(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed3b0(...);
void FUN_141bed3b0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed400(...);
void FUN_141bed400(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141bed4b0(...);
void FUN_141bed4b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141bed560(...);
void FUN_141bed560(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141bed610(...);
void FUN_141bed610(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5);
undefined8 FUN_141bed6c0(...);
void FUN_141bed6c0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed710(...);
void FUN_141bed710(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed760(...);
void FUN_141bed760(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed7b0(...);
void FUN_141bed7b0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed800(...);
void FUN_141bed800(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed850(...);
void FUN_141bed850(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed8a0(...);
void FUN_141bed8a0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed8f0(...);
void FUN_141bed8f0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed940(...);
void FUN_141bed940(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed990(...);
void FUN_141bed990(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bed9e0(...);
void FUN_141bed9e0(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beda30(...);
void FUN_141beda30(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141beda80(...);
void FUN_141beda80(undefined8 param_1,undefined8 param_2,undefined8 param_3);
undefined8 FUN_141bedad0(...);
void FUN_141bedad0(void);
undefined8 FUN_141bedae0(...);
void FUN_141bedae0(void);

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbd10
undefined8 * FUN_141bdbd10(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141bee9c0(param_2);
  (*(undefined8 *)((undefined1 *)param_1 + 0x8)) = *(undefined8 *)FUN_141bee9c0(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbd60
undefined8 * FUN_141bdbd60(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141bee9d0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbdb0
undefined8 * FUN_141bdbdb0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141bee9e0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbe00
undefined8 * FUN_141bdbe00(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141bee9f0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbe50
undefined8 * FUN_141bdbe50(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea00(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbea0
undefined8 * FUN_141bdbea0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea10(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbef0
undefined8 * FUN_141bdbef0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea20(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbf40
undefined8 * FUN_141bdbf40(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea30(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbf90
undefined8 * FUN_141bdbf90(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea40(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdbfe0
undefined8 * FUN_141bdbfe0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea50(param_2);
  (*(undefined8 *)((undefined1 *)param_1 + 0x8)) = *(undefined8 *)FUN_141beea50(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc030
undefined8 * FUN_141bdc030(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea50(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc080
undefined8 * FUN_141bdc080(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea60(param_2);
  (*(undefined8 *)((undefined1 *)param_1 + 0x8)) = *(undefined8 *)FUN_141beea60(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc0d0
undefined8 * FUN_141bdc0d0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beea60(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc120
longlong FUN_141bdc120(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  
  FUN_1408b6b20(param_1,(FUN_140af5a50(param_2)));
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)FUN_140180c20(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc170
undefined8 FUN_141bdc170(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 local_17;
  
  FUN_141bdcbf0(param_1,param_3,param_4,local_17);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc1c0
undefined8 FUN_141bdc1c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 local_17;
  
  FUN_141bdcc40(param_1,param_3,param_4,local_17);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc210
undefined8 FUN_141bdc210(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 local_17;
  
  FUN_141bdcc90(param_1,param_3,param_4,local_17);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc260
undefined8 FUN_141bdc260(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_1401ef2f0(param_3);
  FUN_141bdb940(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc2b0
undefined8 FUN_141bdc2b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_1401ef2f0(param_3);
  FUN_141bdb970(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc300
undefined8 FUN_141bdc300(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_140180bc0(param_3);
  FUN_141bdb9a0(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc350
undefined8 FUN_141bdc350(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_141beea90(param_3);
  FUN_141bdb910(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc3a0
undefined8 FUN_141bdc3a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_140a14e30(param_3);
  FUN_141bdb9d0(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc3f0
undefined8 FUN_141bdc3f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_140a14e30(param_3);
  FUN_141bdba00(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc440
undefined8 FUN_141bdc440(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_140a14e30(param_3);
  FUN_141bdba30(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc490
undefined8 FUN_141bdc490(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_140a14e30(param_3);
  FUN_141bdba60(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc4e0
undefined8 FUN_141bdc4e0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_140a14e30(param_3);
  FUN_141bdba90(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc530
undefined8 FUN_141bdc530(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  
  FUN_1403311c0(param_3);
  FUN_141bdbac0(param_1,*(undefined1 *)FUN_140162f10(param_4));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc580
undefined8 FUN_141bdc580(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 local_17;
  
  FUN_141bdcce0(param_1,param_3,param_4,local_17);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc5d0
undefined8 FUN_141bdc5d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 local_17;
  
  FUN_141bdcd40(param_1,param_3,param_4,local_17);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc620
longlong FUN_141bdc620(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  
  FUN_1408b6b20(param_1,(FUN_14111ce10(param_2)));
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)FUN_140162e40(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc670
longlong FUN_141bdc670(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  
  FUN_1408b6b20(param_1,(FUN_14111ce10(param_2)));
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)FUN_1414c6a20(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc6c0
undefined8 FUN_141bdc6c0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 local_17;
  
  FUN_141bdcd90(param_1,param_3,param_4,local_17);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc710
undefined8 * FUN_141bdc710(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  undefined1
  *pCVar1;
  undefined8 local_20;
  
  pCVar1 = (undefined1 *)(operator new(0x18));
  if (pCVar1 == (undefined1
                 *)0x0) {
    local_20 = 0;
  }
  else {
    local_20 = FUN_141bf0640(pCVar1,param_2,param_3);
  }
  *param_1 = local_20;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc790
undefined8 * FUN_141bdc790(undefined8 *param_1,undefined8 param_2,undefined1 *param_3)
{
  undefined1
  *pCVar1;
  longlong lVar2;
  undefined1 *puVar3;
  undefined8 local_40;
  undefined1 local_28 [24];
  
  pCVar1 = (undefined1 *)(operator new(0x20));
  if (pCVar1 == (undefined1
                 *)0x0) {
    local_40 = 0;
  }
  else {
    puVar3 = local_28;
    for (lVar2 = 0x10; lVar2 != 0; lVar2 = lVar2 + -1) {
      *puVar3 = *param_3;
      param_3 = param_3 + 1;
      puVar3 = puVar3 + 1;
    }
    local_40 = FUN_141bf0700(pCVar1,param_2,local_28);
  }
  *param_1 = local_40;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc830
undefined8 * FUN_141bdc830(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beeb60(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc880
undefined8 * FUN_141bdc880(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beeb70(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc8d0
undefined8 * FUN_141bdc8d0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beeb80(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc920
undefined8 * FUN_141bdc920(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beeb90(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc970
undefined8 * FUN_141bdc970(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beeba0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdc9c0
undefined8 * FUN_141bdc9c0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beebb0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdca10
undefined8 * FUN_141bdca10(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beebc0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdca60
undefined8 * FUN_141bdca60(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beebd0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcab0
undefined8 * FUN_141bdcab0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beebe0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcb00
undefined8 * FUN_141bdcb00(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beebf0(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcb50
undefined8 * FUN_141bdcb50(undefined8 *param_1,undefined8 param_2,undefined8 param_3)
{
  
  *param_1 = *(undefined8 *)FUN_141beec00(param_2);
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)FUN_140162f70(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcba0
undefined8 * FUN_141bdcba0(undefined8 *param_1,undefined8 param_2)
{
  
  *param_1 = *((undefined8 *)FUN_14133e730((FUN_14133e750(param_2))));
  FUN_141bf18b0(param_1 + 1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcbf0
undefined4 * FUN_141bdcbf0(undefined4 *param_1,undefined8 param_2)
{
  
  *param_1 = *((undefined4 *)FUN_1401ef400((FUN_1401ef440(param_2))));
  FUN_141bdce80(param_1 + 2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcc40
undefined4 * FUN_141bdcc40(undefined4 *param_1,undefined8 param_2)
{
  
  *param_1 = *((undefined4 *)FUN_1401ef400((FUN_1401ef440(param_2))));
  FUN_140a15e30(param_1 + 2);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcc90
undefined4 * FUN_141bdcc90(undefined4 *param_1,undefined8 param_2)
{
  
  *param_1 = *((undefined4 *)FUN_1401db610((FUN_1401db6a0(param_2))));
  FUN_1408b6680(param_1 + 2,0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcce0
longlong FUN_141bdcce0(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_14111d4d0(param_2);
  FUN_1408b6b20(param_1,(FUN_14111d1c0(uVar1)));
  FUN_141bf4740(param_1 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcd40
longlong FUN_141bdcd40(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_14111d4d0(param_2);
  FUN_1408b6b20(param_1,(FUN_14111d1c0(uVar1)));
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcd90
undefined8 * FUN_141bdcd90(undefined8 *param_1,undefined8 param_2)
{
  
  *param_1 = *((undefined8 *)FUN_140442290((FUN_1404426d0(param_2))));
  FUN_141bf18b0(param_1 + 1);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcde0
longlong FUN_141bdcde0(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  
  FUN_1408b6b20(param_1,(FUN_140af5ad0(param_2)));
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)FUN_141bee890(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdce30
longlong FUN_141bdce30(longlong param_1,undefined8 param_2,undefined8 param_3)
{
  
  FUN_1408b6b20(param_1,(FUN_140af5ad0(param_2)));
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)FUN_141bee8a0(param_3);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdce80
longlong FUN_141bdce80(longlong param_1)
{
  FUN_1408995b0(param_1);
  *(undefined4 *)(param_1 + 8) = 0;
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdceb0
longlong FUN_141bdceb0(longlong param_1,longlong param_2)
{
  
  FUN_1408b6b20(param_1,(FUN_140af5ad0(param_2)));
  FUN_141bf0ed0(param_1 + 8,*(undefined8 *)FUN_141beeac0(param_2 + 8));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcf10
longlong FUN_141bdcf10(longlong param_1,longlong param_2)
{
  
  FUN_1408b6b20(param_1,(FUN_140af5ad0(param_2)));
  FUN_141bf0f50(param_1 + 8,*(undefined8 *)FUN_141beead0(param_2 + 8));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcf70
longlong FUN_141bdcf70(longlong param_1,longlong param_2)
{
  
  FUN_1408b6b20(param_1,(FUN_140af5ad0(param_2)));
  FUN_1408b6680(param_1 + 8,*(undefined8 *)FUN_140a14e50(param_2 + 8));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdcfd0
undefined8 * FUN_141bdcfd0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  (*(undefined8 *)((undefined1 *)param_1 + 0x8)) = (undefined8)(FUN_141bee7b0);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd000
undefined8 * FUN_141bdd000(undefined8 *param_1,undefined8 param_2)
{
  
  *param_1 = (FUN_141beeee0(param_2));
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd030
longlong FUN_141bdd030(longlong param_1,longlong param_2)
{
  
  FUN_140899bd0(param_1,(FUN_140af5ad0(param_2)));
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)FUN_140180c20(param_2 + 8);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd080
longlong * FUN_141bdd080(longlong *param_1,undefined8 param_2)
{
  uint uVar1;
  undefined8 uVar2;
  uint local_38;
  undefined4 local_30 [2];
  undefined8 local_28;
  undefined1 local_20 [32];
  
  local_28 = 0xfffffffffffffffe;
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  for (local_38 = 0; local_38 < uVar1; local_38 = local_38 + 1) {
    FUN_141bf11e0(local_20);
    uVar2 = (undefined8)(FUN_14070f480(param_1,local_30));
    FUN_141bdd120(uVar2,local_20);
    FUN_141c1ae60(param_2,local_30[0],local_20);
    FUN_141bf5570(local_20);
  }
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bdd120
undefined8 FUN_141bdd120(undefined8 param_1,undefined8 param_2)
{
  return (undefined8)((undefined8 (*)(...))0x141bdd120ULL)(param_1,param_2);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd1b0
void FUN_141bdd1b0(undefined8 *param_1,undefined4 param_2)
{
  (**(code **)*param_1)(param_1,0x7002002,param_2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd1e0
void FUN_141bdd1e0(undefined8 *param_1,undefined4 param_2)
{
  (**(code **)*param_1)(param_1,0x7001004,param_2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd210
void FUN_141bdd210(undefined8 *param_1,undefined4 param_2)
{
  (**(code **)*param_1)(param_1,0x7002020,param_2);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd240
void FUN_141bdd240(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4, undefined8 *param_5,undefined8 param_6)
{
  undefined1 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  longlong lVar18;
  undefined1 *puVar19;
  undefined1 local_e8 [8];
  undefined1 local_e0 [8];
  undefined1 local_d8 [8];
  undefined1 local_d0 [8];
  undefined1 local_c8 [8];
  undefined1 local_c0 [8];
  undefined1 local_b8 [8];
  undefined1 local_b0 [8];
  undefined1 local_a8 [8];
  undefined1 local_a0 [8];
  undefined1 local_98 [8];
  undefined1 local_90 [8];
  undefined1 local_88 [8];
  undefined1 local_80 [8];
  undefined1 local_78 [8];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [32];
  
  puVar1 = (undefined1 *)FUN_1401d2510(local_50,*param_5);
  puVar19 = local_70;
  for (lVar18 = 0x10; lVar18 != 0; lVar18 = lVar18 + -1) {
    *puVar19 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar19 = puVar19 + 1;
  }
  puVar1 = (undefined1 *)FUN_141bdcfd0(local_40,param_6);
  puVar19 = local_60;
  for (lVar18 = 0x10; lVar18 != 0; lVar18 = lVar18 + -1) {
    *puVar19 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar19 = puVar19 + 1;
  }
  puVar2 = (undefined8 *)FUN_140163e80(local_d8);
  puVar3 = (undefined8 *)FUN_140163e80(local_d0);
  puVar4 = (undefined8 *)FUN_140163e80(local_c8);
  puVar5 = (undefined8 *)FUN_140163e80(local_c0);
  puVar6 = (undefined8 *)FUN_140163e80(local_b8);
  puVar7 = (undefined8 *)FUN_140163e80(local_b0);
  puVar8 = (undefined8 *)FUN_140163e80(local_a8);
  puVar9 = (undefined8 *)FUN_140163e80(local_a0);
  puVar10 = (undefined8 *)FUN_140163e80(local_98);
  puVar11 = (undefined8 *)FUN_140163e80(local_90);
  puVar12 = (undefined8 *)FUN_140163e80(local_88);
  puVar13 = (undefined8 *)FUN_140163e80(local_80);
  puVar14 = (undefined8 *)FUN_140163e80(local_78);
  puVar15 = (undefined8 *)FUN_141bdd000(local_e8,param_6);
  puVar16 = (undefined8 *)FUN_1401d1ee0(local_e0,param_5);
  uVar17 = FUN_14016d660(*puVar16,*puVar15,*puVar14,*puVar13,*puVar12,*puVar11,*puVar10,*puVar9,
                         *puVar8,*puVar7,*puVar6,*puVar5,*puVar4,*puVar3,*puVar2);
  FUN_1406530d0(param_1,param_2,param_3,param_4,(FUN_140163e50(local_30,uVar17,local_70)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd540
undefined8 FUN_141bdd540(longlong *param_1)
{
  char cVar1;
  undefined8 local_18 [3];
  
  local_18[0] = 0;
  if ((param_1 == (longlong *)0x0) ||
     (cVar1 = (**(code **)(*param_1 + 0x20))(param_1,0x3005,local_18), cVar1 == '\0')) {
    local_18[0] = 0;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd590
undefined8 FUN_141bdd590(longlong *param_1)
{
  char cVar1;
  undefined8 local_18 [3];
  
  local_18[0] = 0;
  if ((param_1 == (longlong *)0x0) ||
     (cVar1 = (**(code **)(*param_1 + 0x20))(param_1,0x200b,local_18), cVar1 == '\0')) {
    local_18[0] = 0;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd5e0
undefined8 FUN_141bdd5e0(undefined8 param_1)
{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 local_18 [3];
  
  local_18[0] = 0;
  lVar2 = FUN_140a7b650(param_1);
  if (lVar2 != 0) {
    plVar3 = (longlong *)FUN_140a7b660(param_1);
    cVar1 = (**(code **)(*plVar3 + 0x28))(plVar3,0x6200074,local_18);
    if (cVar1 != '\0') {
      return local_18[0];
    }
  }
  return 0;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd660
undefined8 FUN_141bdd660(longlong *param_1)
{
  char cVar1;
  undefined8 local_18 [3];
  
  local_18[0] = 0;
  if ((param_1 == (longlong *)0x0) ||
     (cVar1 = (**(code **)(*param_1 + 0x28))(param_1,0x6100002,local_18), cVar1 == '\0')) {
    local_18[0] = 0;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bdd6b0
 undefined8 FUN_141bdd6b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  return (undefined8)((undefined8 (*)(...))0x141bdd6b0ULL)(param_1,param_2,param_3,param_4);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bdd750
undefined8 FUN_141bdd750(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  return (undefined8)((undefined8 (*)(...))0x141bdd750ULL)(param_1,param_2,param_3,param_4);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd7f0
undefined8 FUN_141bdd7f0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 local_34 [4];
  longlong local_30;
  undefined8 local_28;
  undefined4 *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  local_20 = (undefined4 *)FUN_140876480(local_34,0,param_3,param_4,0);
  local_30 = FUN_14208a860(0xb0,*local_20);
  if (local_30 == 0) {
    local_28 = 0;
  }
  else {
    local_28 = FUN_142172a80(local_30);
  }
  local_18 = local_28;
  FUN_140d98a60(param_1,local_28);
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd890
undefined8 FUN_141bdd890(void)
{
  undefined1
  *pTVar1;
  longlong lVar2;
  undefined1
  *pTVar3;
  undefined8 local_20;
  
  pTVar1 = (undefined1 *)(operator new(0x48));
  if (pTVar1 == (undefined1
                 *)0x0) {
    local_20 = 0;
  }
  else {
    pTVar3 = pTVar1;
    for (lVar2 = 0x48; lVar2 != 0; lVar2 = lVar2 + -1) {
      *(undefined1 *)(pTVar3) = 0;
      pTVar3 = (undefined1
                *)((longlong)(pTVar3) + 1);
    }
    local_20 = FUN_141bf19b0(pTVar1);
  }
  return local_20;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd900
undefined8 FUN_141bdd900(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd920
undefined8 FUN_141bdd920(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd940
undefined8 FUN_141bdd940(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd960
undefined8 FUN_141bdd960(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd980
undefined8 FUN_141bdd980(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd9a0
undefined8 FUN_141bdd9a0(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd9c0
undefined8 FUN_141bdd9c0(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdd9e0
undefined8 FUN_141bdd9e0(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdda00
undefined8 FUN_141bdda00(undefined8 param_1,undefined8 param_2)
{
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdda20
undefined8 FUN_141bdda20(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  FUN_141bddc30(param_1,(FUN_141beea80(param_3)));
  return 0; // RAXCHECK: callers use the return value
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdda50
undefined8 FUN_141bdda50(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  FUN_141bde270(param_1,(FUN_141beeab0(param_3)));
  return 0; // RAXCHECK: callers use the return value
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdda80
longlong FUN_141bdda80(undefined8 param_1,undefined8 param_2)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = (longlong)(FUN_141622af0(param_1));
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_140af5a50(param_2);
  uVar3 = FUN_140a14570(lVar1 + 0x20);
  FUN_141beda80((FUN_140a1be30(param_1)),uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bddb10
longlong FUN_141bddb10(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = (longlong)(FUN_1415373e0(param_1,param_2,param_3));
  uVar2 = FUN_141537590(param_1);
  FUN_141bed010(uVar2,(FUN_141531da0(lVar1 + 0x10)),(FUN_141beea70(param_4)));
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bddba0
longlong FUN_141bddba0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_141c20070(param_1,param_2,param_3);
  uVar2 = FUN_141c26bb0(param_1);
  FUN_141bed060(uVar2,(FUN_140a144b0(lVar1 + 0x10)),(FUN_140a14dd0(param_4)));
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bddc30
longlong FUN_141bddc30(undefined8 param_1,undefined8 param_2)
{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_141c20910(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_141beea80(param_2);
  FUN_141bed0b0((FUN_141c26f50(param_1)),(FUN_141becb40(lVar1 + 0x20)),uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bddcc0
longlong FUN_141bddcc0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_141c20830(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_140162f40(param_4);
  uVar3 = FUN_14133e6f0(param_3);
  uVar4 = FUN_140162ef0(param_2);
  uVar5 = FUN_141becbd0(lVar1 + 0x20);
  FUN_141bed560((FUN_141c26ef0(param_1)),uVar5,uVar4,uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bddd90
longlong FUN_141bddd90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_141c20130(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_140162f40(param_4);
  uVar3 = FUN_1401ef380(param_3);
  uVar4 = FUN_140162ef0(param_2);
  uVar5 = FUN_141becb50(lVar1 + 0x20);
  FUN_141bed100((FUN_141c26bf0(param_1)),uVar5,uVar4,uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdde60
longlong FUN_141bdde60(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_141c20210(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_140162f40(param_4);
  uVar3 = FUN_1401ef380(param_3);
  uVar4 = FUN_140162ef0(param_2);
  uVar5 = FUN_141becb60(lVar1 + 0x20);
  FUN_141bed1b0((FUN_141c26c50(param_1)),uVar5,uVar4,uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bddf30
longlong FUN_141bddf30(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_141c202f0(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_140162f40(param_4);
  uVar3 = FUN_1401db5d0(param_3);
  uVar4 = FUN_140162ef0(param_2);
  uVar5 = FUN_141becb70(lVar1 + 0x20);
  FUN_141bed260((FUN_141c26cb0(param_1)),uVar5,uVar4,uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde000
longlong FUN_141bde000(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_141c20670(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_140162f40(param_4);
  uVar3 = FUN_14111d050(param_3);
  uVar4 = FUN_140162ef0(param_2);
  uVar5 = FUN_141becbb0(lVar1 + 0x20);
  FUN_141bed400((FUN_141c26e30(param_1)),uVar5,uVar4,uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde0d0
longlong FUN_141bde0d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_141c20750(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_140162f40(param_4);
  uVar3 = FUN_14111d050(param_3);
  uVar4 = FUN_140162ef0(param_2);
  uVar5 = FUN_141becbc0(lVar1 + 0x20);
  FUN_141bed4b0((FUN_141c26e90(param_1)),uVar5,uVar4,uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde1a0
longlong FUN_141bde1a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar1 = FUN_141c20830(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_140162f40(param_4);
  uVar3 = FUN_140442200(param_3);
  uVar4 = FUN_140162ef0(param_2);
  uVar5 = FUN_141becbd0(lVar1 + 0x20);
  FUN_141bed610((FUN_141c26ef0(param_1)),uVar5,uVar4,uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde270
longlong FUN_141bde270(undefined8 param_1,undefined8 param_2)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = FUN_141c209f0(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_141beeab0(param_2);
  uVar3 = FUN_140a14560(lVar1 + 0x20);
  FUN_141beda30((FUN_140a1be00(param_1)),uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde300
longlong FUN_141bde300(undefined8 param_1,undefined8 param_2)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = FUN_141c203d0(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_141beeb00(param_2);
  uVar3 = FUN_141becb80(lVar1 + 0x20);
  FUN_141bed310((FUN_141c26d10(param_1)),uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde390
longlong FUN_141bde390(undefined8 param_1,undefined8 param_2)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = FUN_141c204b0(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_141beeb10(param_2);
  uVar3 = FUN_141becb90(lVar1 + 0x20);
  FUN_141bed360((FUN_141c26d70(param_1)),uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde420
longlong FUN_141bde420(undefined8 param_1,undefined8 param_2)
{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = FUN_141c20590(param_1);
  *(undefined1 *)(lVar1 + 0x18) = 0;
  *(undefined1 *)(lVar1 + 0x19) = 0;
  uVar2 = FUN_141beeb20(param_2);
  uVar3 = FUN_141becba0(lVar1 + 0x20);
  FUN_141bed3b0((FUN_141c26dd0(param_1)),uVar3,uVar2);
  return lVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde4b0
void FUN_141bde4b0(undefined8 param_1,undefined8 param_2,undefined1 param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  
  puVar1 = (undefined8 *)FUN_140a1b9e0(param_1);
  uVar2 = FUN_141bde5d0(param_1,*((undefined8 *)FUN_140a1caa0((FUN_141623bd0(param_2)))),*puVar1,param_3);
  puVar3 = (undefined8 *)FUN_140a1caa0(puVar1);
  *puVar3 = uVar2;
  uVar2 = FUN_141625060(param_2);
  (*(undefined8 *)((undefined1 *)puVar1 + 0x8)) = uVar2;
  plVar4 = (longlong *)FUN_140a1caa0(puVar1);
  if (*(char *)(*plVar4 + 0x19) == '\0') {
    puVar3 = (undefined8 *)FUN_140a1caa0(puVar1);
    uVar2 = (undefined8)(FUN_140a1c800(*puVar3));
    puVar3 = (undefined8 *)FUN_140a1c180(puVar1);
    *puVar3 = uVar2;
    puVar3 = (undefined8 *)FUN_140a1caa0(puVar1);
    uVar2 = FUN_140a1c6b0(*puVar3);
    puVar1 = (undefined8 *)FUN_140a1ca00(puVar1);
    *puVar1 = uVar2;
  }
  else {
    puVar3 = (undefined8 *)FUN_140a1c180(puVar1);
    *puVar3 = *puVar1;
    puVar3 = (undefined8 *)FUN_140a1ca00(puVar1);
    *puVar3 = *puVar1;
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde5d0
undefined8 * FUN_141bde5d0(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined1 param_4)
{
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined1 local_38;
  undefined8 *local_28;
  
  local_28 = (undefined8 *)*(longlong *)FUN_140a1b9e0(param_1);
  if (*(char *)((longlong)param_2 + 0x19) == '\0') {
    puVar2 = (undefined8 *)FUN_141bde6e0(param_1,param_2 + 4,param_4,local_38);
    (*(undefined8 *)((undefined1 *)puVar2 + 0x8)) = param_3;
    *(undefined1 *)(puVar2 + 3) = *(undefined1 *)(param_2 + 3);
    if (*(char *)((longlong)local_28 + 0x19) != '\0') {
      local_28 = puVar2;
    }
    uVar3 = FUN_141bde5d0(param_1,*param_2,puVar2,param_4);
    *puVar2 = uVar3;
    uVar3 = FUN_141bde5d0(param_1,(*(undefined8 *)((undefined1 *)param_2 + 0x10)),puVar2,param_4);
    (*(undefined8 *)((undefined1 *)puVar2 + 0x10)) = uVar3;
  }
  return local_28;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde6e0
undefined8 FUN_141bde6e0(undefined8 param_1,undefined8 param_2)
{
  FUN_141bdda80(param_1,param_2);
  return 0; // RAXCHECK: callers use the return value
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde710
void FUN_141bde710(longlong param_1,longlong param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 local_res8;
  
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    uVar1 = FUN_141bebc40(local_res8);
    FUN_141bedc90(param_3,uVar1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde770
void FUN_141bde770(longlong param_1,longlong param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 local_res8;
  
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    uVar1 = FUN_141bebc50(local_res8);
    FUN_141bedcb0(param_3,uVar1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde7d0
void FUN_141bde7d0(longlong param_1,longlong param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 local_res8;
  
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x18) {
    uVar1 = FUN_141bebc60(local_res8);
    FUN_141bedcd0(param_3,uVar1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde830
void FUN_141bde830(longlong param_1,longlong param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined8 local_res8;
  
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    uVar1 = FUN_141bebc70(local_res8);
    FUN_141bedcf0(param_3,uVar1);
  }
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde890
void FUN_141bde890(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_141bde710(param_1,param_2,param_3,local_18[0]);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde8e0
void FUN_141bde8e0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_141bde770(param_1,param_2,param_3,local_18[0]);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde930
void FUN_141bde930(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_141bde7d0(param_1,param_2,param_3,local_18[0]);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde980
void FUN_141bde980(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_141bde830(param_1,param_2,param_3,local_18[0]);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bde9d0
longlong FUN_141bde9d0(undefined8 param_1,undefined8 param_2,undefined1 param_3)
{
  char cVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined1 local_res18;
  longlong local_18;
  
  local_18 = 0;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  while( true ) {
    cVar1 = FUN_141bf78d0(&local_res8,&local_res10);
    if (cVar1 == '\0') break;
    local_18 = local_18 + 1;
    FUN_141bf8740(&local_res8);
  }
  return local_18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdea30
longlong FUN_141bdea30(undefined8 param_1,undefined8 param_2,undefined1 param_3)
{
  char cVar1;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined1 local_res18;
  longlong local_18;
  
  local_18 = 0;
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18 = param_3;
  while( true ) {
    cVar1 = FUN_141bf7910(&local_res8,&local_res10);
    if (cVar1 == '\0') break;
    local_18 = local_18 + 1;
    FUN_141bf8760(&local_res8);
  }
  return local_18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdea90
void FUN_141bdea90(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141bee940(param_2);
  FUN_141bed6c0(*(undefined8 *)(param_1 + 0x10),(FUN_141bebc50(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdeaf0
void FUN_141bdeaf0(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141bee950(param_2);
  FUN_141bed760(*(undefined8 *)(param_1 + 0x10),(FUN_141bebc60(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x18;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdeb50
void FUN_141bdeb50(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141bee970(param_2);
  FUN_141bed800(*(undefined8 *)(param_1 + 0x10),(FUN_140963570(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdebb0
void FUN_141bdebb0(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141bee980(param_2);
  FUN_141bed8a0(*(undefined8 *)(param_1 + 0x10),(FUN_140963580(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdec10
void FUN_141bdec10(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141bee990(param_2);
  FUN_141bed990(*(undefined8 *)(param_1 + 0x10),(FUN_141bebc70(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdec70
void FUN_141bdec70(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141beeae0(param_2);
  FUN_141bed710(*(undefined8 *)(param_1 + 0x10),(FUN_141bebc50(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdecd0
void FUN_141bdecd0(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141beeaf0(param_2);
  FUN_141bed7b0(*(undefined8 *)(param_1 + 0x10),(FUN_141bebc60(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x18;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bded30
void FUN_141bded30(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141beeb30(param_2);
  FUN_141bed850(*(undefined8 *)(param_1 + 0x10),(FUN_140963570(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bded90
void FUN_141bded90(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141beeb40(param_2);
  FUN_141bed940(*(undefined8 *)(param_1 + 0x10),(FUN_140963580(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdedf0
void FUN_141bdedf0(longlong param_1,undefined8 param_2)
{
  undefined8 uVar1;
  
  uVar1 = FUN_141beeb50(param_2);
  FUN_141bed9e0(*(undefined8 *)(param_1 + 0x10),(FUN_141bebc70(*(undefined8 *)(param_1 + 8))),uVar1);
  *(longlong *)(param_1 + 8) = *(longlong *)(param_1 + 8) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdee50
void FUN_141bdee50(undefined8 param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_141beeaa0(param_2);
  uVar3 = FUN_140963580(*(undefined8 *)FUN_140969b40(param_1));
  FUN_141bed8f0((FUN_1409697b0(param_1)),uVar3,uVar1);
  puVar2 = (undefined8 *)FUN_140969b40(param_1);
  FUN_141c28b20(param_1,*(undefined8 *)FUN_140969b40(param_1),*puVar2);
  FUN_140969b40(param_1);
  *(longlong *)FUN_140969b40(param_1) = *(longlong *)FUN_140969b40(param_1) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdef10
void FUN_141bdef10(undefined8 param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_141beeae0(param_2);
  uVar3 = FUN_141bebc50(*(undefined8 *)FUN_141c28970(param_1));
  FUN_141bed710((FUN_141c27000(param_1)),uVar3,uVar1);
  puVar2 = (undefined8 *)FUN_141c28970(param_1);
  FUN_141c28af0(param_1,*(undefined8 *)FUN_141c28970(param_1),*puVar2);
  FUN_141c28970(param_1);
  *(longlong *)FUN_141c28970(param_1) = *(longlong *)FUN_141c28970(param_1) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdefd0
void FUN_141bdefd0(undefined8 param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_141beeaf0(param_2);
  uVar3 = FUN_141bebc60(*(undefined8 *)FUN_141c289b0(param_1));
  FUN_141bed7b0((FUN_141c27040(param_1)),uVar3,uVar1);
  puVar2 = (undefined8 *)FUN_141c289b0(param_1);
  FUN_141c28b00(param_1,*(undefined8 *)FUN_141c289b0(param_1),*puVar2);
  FUN_141c289b0(param_1);
  *(longlong *)FUN_141c289b0(param_1) = *(longlong *)FUN_141c289b0(param_1) + 0x18;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdf090
void FUN_141bdf090(undefined8 param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_141beeb30(param_2);
  uVar3 = FUN_140963570(*(undefined8 *)FUN_140969b00(param_1));
  FUN_141bed850((FUN_140969790(param_1)),uVar3,uVar1);
  puVar2 = (undefined8 *)FUN_140969b00(param_1);
  FUN_141c28b10(param_1,*(undefined8 *)FUN_140969b00(param_1),*puVar2);
  FUN_140969b00(param_1);
  *(longlong *)FUN_140969b00(param_1) = *(longlong *)FUN_140969b00(param_1) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdf150
void FUN_141bdf150(undefined8 param_1,undefined8 param_2)
{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_141beeb50(param_2);
  uVar3 = FUN_141bebc70(*(undefined8 *)FUN_141c289f0(param_1));
  FUN_141bed9e0((FUN_141c270c0(param_1)),uVar3,uVar1);
  puVar2 = (undefined8 *)FUN_141c289f0(param_1);
  FUN_141c28b30(param_1,*(undefined8 *)FUN_141c289f0(param_1),*puVar2);
  FUN_141c289f0(param_1);
  *(longlong *)FUN_141c289f0(param_1) = *(longlong *)FUN_141c289f0(param_1) + 0x10;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdf210
longlong FUN_141bdf210(undefined8 param_1,longlong param_2,undefined8 param_3)
{
  longlong *plVar1;
  longlong lVar2;
  undefined1 *this_;
  longlong lVar3;
  longlong lVar4;
  __uint64 _Var5;
  _Container_proxy *p_Var6;
  undefined8 uVar7;
  undefined8 *puVar9;
  undefined8 *puVar10;
  _Container_proxy *p_Var11;
  _Container_proxy *p_Var12;
  
  lVar2 = param_2 - *(longlong *)FUN_140969ac0(param_1) >> 4;
  this_ = (undefined1 *)FUN_1409697b0(param_1);
  lVar3 = FUN_14096b180(param_1);
  lVar4 = FUN_141c2e8f0(param_1);
  if (lVar3 == lVar4) {
    FUN_141c2a910();
  }
  _Var5 = FUN_141c20c80(param_1,lVar3 + 1);
  p_Var6 = (_Container_proxy *)(FUN_141c2abf0(this_,_Var5));
  uVar7 = FUN_140963580(p_Var6 + lVar2);
  FUN_141bed8f0(this_,uVar7,(FUN_141beeaa0(param_3)));
  p_Var11 = p_Var6 + lVar2;
  plVar1 = (longlong *)FUN_140969b40(param_1);
  if (param_2 == *plVar1) {
    puVar9 = (undefined8 *)FUN_140969b40(param_1);
    puVar10 = (undefined8 *)FUN_140969ac0(param_1);
    FUN_141c2a700(param_1,*puVar10,*puVar9,p_Var6);
  }
  else {
    puVar9 = (undefined8 *)FUN_140969ac0(param_1);
    FUN_141c2a420(param_1,*puVar9,param_2,p_Var6,p_Var6,lVar2,p_Var11);
    p_Var11 = p_Var6 + lVar2 + 1;
    p_Var12 = p_Var6;
    puVar9 = (undefined8 *)FUN_140969b40(param_1);
    FUN_141c2a420(param_1,param_2,*puVar9,p_Var11,p_Var6,lVar2,p_Var12);
  }
  FUN_141c210d0(param_1,p_Var6,lVar3 + 1,_Var5);
  return lVar2 * 0x10 + *(longlong *)FUN_140969ac0(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdf460
longlong FUN_141bdf460(undefined8 param_1,longlong param_2,undefined8 param_3)
{
  longlong *plVar1;
  longlong lVar2;
  undefined1 *this_;
  longlong lVar3;
  longlong lVar4;
  __uint64 _Var5;
  _Container_proxy *p_Var6;
  undefined8 uVar7;
  undefined8 *puVar9;
  undefined8 *puVar10;
  _Container_proxy *p_Var11;
  _Container_proxy *p_Var12;
  
  lVar2 = param_2 - *(longlong *)FUN_141c28870(param_1) >> 4;
  this_ = (undefined1 *)FUN_141c27000(param_1);
  lVar3 = FUN_141c2ee10(param_1);
  lVar4 = FUN_141c2e800(param_1);
  if (lVar3 == lVar4) {
    FUN_141c2a8b0();
  }
  _Var5 = FUN_141c20ad0(param_1,lVar3 + 1);
  p_Var6 = (_Container_proxy *)(FUN_141c2ab60(this_,_Var5));
  uVar7 = FUN_141bebc50(p_Var6 + lVar2);
  FUN_141bed710(this_,uVar7,(FUN_141beeae0(param_3)));
  p_Var11 = p_Var6 + lVar2;
  plVar1 = (longlong *)FUN_141c28970(param_1);
  if (param_2 == *plVar1) {
    puVar9 = (undefined8 *)FUN_141c28970(param_1);
    puVar10 = (undefined8 *)FUN_141c28870(param_1);
    FUN_141c2a5e0(param_1,*puVar10,*puVar9,p_Var6);
  }
  else {
    puVar9 = (undefined8 *)FUN_141c28870(param_1);
    FUN_141c2a360(param_1,*puVar9,param_2,p_Var6,p_Var6,lVar2,p_Var11);
    p_Var11 = p_Var6 + lVar2 + 1;
    p_Var12 = p_Var6;
    puVar9 = (undefined8 *)FUN_141c28970(param_1);
    FUN_141c2a360(param_1,param_2,*puVar9,p_Var11,p_Var6,lVar2,p_Var12);
  }
  FUN_141c20da0(param_1,p_Var6,lVar3 + 1,_Var5);
  return lVar2 * 0x10 + *(longlong *)FUN_141c28870(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdf6b0
longlong FUN_141bdf6b0(undefined8 param_1,longlong param_2,undefined8 param_3)
{
  longlong *plVar1;
  longlong lVar2;
  undefined1 *this_;
  longlong lVar3;
  longlong lVar4;
  __uint64 _Var5;
  _Container_proxy *p_Var6;
  undefined8 uVar7;
  undefined8 *puVar9;
  undefined8 *puVar10;
  _Container_proxy *p_Var11;
  
  plVar1 = (longlong *)FUN_141c288b0(param_1);
  lVar2 = (param_2 - *plVar1) / 0x18;
  this_ = (undefined1 *)FUN_141c27040(param_1,(param_2 - *plVar1) % 0x18);
  lVar3 = FUN_141c2ee50(param_1);
  lVar4 = FUN_141c2e850(param_1);
  if (lVar3 == lVar4) {
    FUN_141c2a8d0();
  }
  _Var5 = FUN_141c20b60(param_1,lVar3 + 1);
  p_Var6 = (_Container_proxy *)(FUN_141c2ab90(this_,_Var5));
  uVar7 = FUN_141bebc60((longlong)p_Var6 + lVar2 * 0x18);
  FUN_141bed7b0(this_,uVar7,(FUN_141beeaf0(param_3)));
  lVar4 = (longlong)p_Var6 + lVar2 * 0x18;
  plVar1 = (longlong *)FUN_141c289b0(param_1);
  if (param_2 == *plVar1) {
    puVar9 = (undefined8 *)FUN_141c289b0(param_1);
    puVar10 = (undefined8 *)FUN_141c288b0(param_1);
    FUN_141c2a640(param_1,*puVar10,*puVar9,p_Var6);
  }
  else {
    puVar9 = (undefined8 *)FUN_141c288b0(param_1);
    FUN_141c2a3a0(param_1,*puVar9,param_2,p_Var6,p_Var6,lVar2,lVar4);
    lVar4 = (longlong)p_Var6 + lVar2 * 0x18 + 0x18;
    p_Var11 = p_Var6;
    puVar9 = (undefined8 *)FUN_141c289b0(param_1);
    FUN_141c2a3a0(param_1,param_2,*puVar9,lVar4,p_Var6,lVar2,p_Var11);
  }
  FUN_141c20eb0(param_1,p_Var6,lVar3 + 1,_Var5);
  return lVar2 * 0x18 + *(longlong *)FUN_141c288b0(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdf900
longlong FUN_141bdf900(undefined8 param_1,longlong param_2,undefined8 param_3)
{
  longlong *plVar1;
  longlong lVar2;
  undefined1 *this_;
  longlong lVar3;
  longlong lVar4;
  __uint64 _Var5;
  _Container_proxy *p_Var6;
  undefined8 uVar7;
  undefined8 *puVar9;
  undefined8 *puVar10;
  _Container_proxy *p_Var11;
  _Container_proxy *p_Var12;
  
  lVar2 = param_2 - *(longlong *)FUN_140969a80(param_1) >> 4;
  this_ = (undefined1 *)FUN_140969790(param_1);
  lVar3 = FUN_14096b140(param_1);
  lVar4 = FUN_141c2e8a0(param_1);
  if (lVar3 == lVar4) {
    FUN_141c2a8f0();
  }
  _Var5 = FUN_141c20bf0(param_1,lVar3 + 1);
  p_Var6 = (_Container_proxy *)(FUN_141c2abc0(this_,_Var5));
  uVar7 = FUN_140963570(p_Var6 + lVar2);
  FUN_141bed850(this_,uVar7,(FUN_141beeb30(param_3)));
  p_Var11 = p_Var6 + lVar2;
  plVar1 = (longlong *)FUN_140969b00(param_1);
  if (param_2 == *plVar1) {
    puVar9 = (undefined8 *)FUN_140969b00(param_1);
    puVar10 = (undefined8 *)FUN_140969a80(param_1);
    FUN_141c2a6a0(param_1,*puVar10,*puVar9,p_Var6);
  }
  else {
    puVar9 = (undefined8 *)FUN_140969a80(param_1);
    FUN_141c2a3e0(param_1,*puVar9,param_2,p_Var6,p_Var6,lVar2,p_Var11);
    p_Var11 = p_Var6 + lVar2 + 1;
    p_Var12 = p_Var6;
    puVar9 = (undefined8 *)FUN_140969b00(param_1);
    FUN_141c2a3e0(param_1,param_2,*puVar9,p_Var11,p_Var6,lVar2,p_Var12);
  }
  FUN_141c20fc0(param_1,p_Var6,lVar3 + 1,_Var5);
  return lVar2 * 0x10 + *(longlong *)FUN_140969a80(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdfb50
longlong FUN_141bdfb50(undefined8 param_1,longlong param_2,undefined8 param_3)
{
  longlong *plVar1;
  longlong lVar2;
  undefined1 *this_;
  longlong lVar3;
  longlong lVar4;
  __uint64 _Var5;
  _Container_proxy *p_Var6;
  undefined8 uVar7;
  undefined8 *puVar9;
  undefined8 *puVar10;
  _Container_proxy *p_Var11;
  _Container_proxy *p_Var12;
  
  lVar2 = param_2 - *(longlong *)FUN_141c288f0(param_1) >> 4;
  this_ = (undefined1 *)FUN_141c270c0(param_1);
  lVar3 = FUN_141c2eea0(param_1);
  lVar4 = FUN_141c2e940(param_1);
  if (lVar3 == lVar4) {
    FUN_141c2a930();
  }
  _Var5 = FUN_141c20d10(param_1,lVar3 + 1);
  p_Var6 = (_Container_proxy *)(FUN_141c2ac20(this_,_Var5));
  uVar7 = FUN_141bebc70(p_Var6 + lVar2);
  FUN_141bed9e0(this_,uVar7,(FUN_141beeb50(param_3)));
  p_Var11 = p_Var6 + lVar2;
  plVar1 = (longlong *)FUN_141c289f0(param_1);
  if (param_2 == *plVar1) {
    puVar9 = (undefined8 *)FUN_141c289f0(param_1);
    puVar10 = (undefined8 *)FUN_141c288f0(param_1);
    FUN_141c2a760(param_1,*puVar10,*puVar9,p_Var6);
  }
  else {
    puVar9 = (undefined8 *)FUN_141c288f0(param_1);
    FUN_141c2a460(param_1,*puVar9,param_2,p_Var6,p_Var6,lVar2,p_Var11);
    p_Var11 = p_Var6 + lVar2 + 1;
    p_Var12 = p_Var6;
    puVar9 = (undefined8 *)FUN_141c289f0(param_1);
    FUN_141c2a460(param_1,param_2,*puVar9,p_Var11,p_Var6,lVar2,p_Var12);
  }
  FUN_141c211e0(param_1,p_Var6,lVar3 + 1,_Var5);
  return lVar2 * 0x10 + *(longlong *)FUN_141c288f0(param_1);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdfda0
undefined8 FUN_141bdfda0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined8 local_20;
  undefined8 local_18;
  
  FUN_141bdfe30(param_1,&local_20,param_3);
  uVar1 = FUN_141c262a0(param_1);
  uVar1 = FUN_141becc70(uVar1);
  FUN_141bf2590(local_28,local_20,uVar1);
  FUN_141bf2590(local_30,local_18,uVar1);
  FUN_141bdbfe0(param_2,local_28,local_30);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bdfe30
undefined8 FUN_141bdfe30(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  char cVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *local_58;
  undefined8 *local_48;
  undefined8 *local_40;
  undefined8 *local_38;
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  puVar2 = (undefined8 *)FUN_141c262d0(param_1);
  local_58 = (undefined8 *)FUN_141c29350(puVar2);
  local_58 = (undefined8 *)*local_58;
  local_38 = (undefined8 *)*puVar2;
  local_48 = (undefined8 *)*puVar2;
  while (*(char *)((longlong)local_58 + 0x19) == '\0') {
    uVar3 = FUN_141c27780(param_1,local_58);
    uVar4 = FUN_141c272e0(param_1);
    cVar1 = FUN_140999030(uVar4,uVar3,param_3);
    if (cVar1 == '\0') {
      if (*(char *)((longlong)local_48 + 0x19) != '\0') {
        uVar3 = FUN_141c27780(param_1,local_58);
        uVar4 = FUN_141c272e0(param_1);
        cVar1 = FUN_140999030(uVar4,param_3,uVar3);
        if (cVar1 != '\0') {
          local_48 = local_58;
        }
      }
      local_38 = local_58;
      local_58 = (undefined8 *)*local_58;
    }
    else {
      local_58 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_58 + 0x10));
    }
  }
  if (*(char *)((longlong)local_48 + 0x19) == '\0') {
    local_40 = (undefined8 *)*local_48;
  }
  else {
    local_40 = (undefined8 *)FUN_141c29350(puVar2);
    local_40 = (undefined8 *)*local_40;
  }
  local_58 = local_40;
  while (*(char *)((longlong)local_58 + 0x19) == '\0') {
    uVar3 = FUN_141c27780(param_1,local_58);
    uVar4 = FUN_141c272e0(param_1);
    cVar1 = FUN_140999030(uVar4,param_3,uVar3);
    if (cVar1 == '\0') {
      local_58 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_58 + 0x10));
    }
    else {
      local_48 = local_58;
      local_58 = (undefined8 *)*local_58;
    }
  }
  FUN_141bf2310(local_10,local_38,(FUN_141beca70(puVar2)));
  FUN_141bf2310(local_18,local_48,(FUN_141beca70(puVar2)));
  FUN_141bdbcc0(param_2,local_10,local_18);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0070
undefined8 FUN_141be0070(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined8 local_20;
  undefined8 local_18;
  
  FUN_141be0100(param_1,&local_20,param_3);
  uVar1 = FUN_141c26300(param_1);
  uVar1 = FUN_141becc80(uVar1);
  FUN_141bf25d0(local_28,local_20,uVar1);
  FUN_141bf25d0(local_30,local_18,uVar1);
  FUN_141bdc080(param_2,local_28,local_30);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0100
undefined8 FUN_141be0100(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  char cVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *local_58;
  undefined8 *local_48;
  undefined8 *local_40;
  undefined8 *local_38;
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  puVar2 = (undefined8 *)FUN_141c26330(param_1);
  local_58 = (undefined8 *)FUN_141c29370(puVar2);
  local_58 = (undefined8 *)*local_58;
  local_38 = (undefined8 *)*puVar2;
  local_48 = (undefined8 *)*puVar2;
  while (*(char *)((longlong)local_58 + 0x19) == '\0') {
    uVar3 = FUN_141c277b0(param_1,local_58);
    uVar4 = FUN_141c27320(param_1);
    cVar1 = FUN_14044a540(uVar4,uVar3,param_3);
    if (cVar1 == '\0') {
      if (*(char *)((longlong)local_48 + 0x19) != '\0') {
        uVar3 = FUN_141c277b0(param_1,local_58);
        uVar4 = FUN_141c27320(param_1);
        cVar1 = FUN_14044a540(uVar4,param_3,uVar3);
        if (cVar1 != '\0') {
          local_48 = local_58;
        }
      }
      local_38 = local_58;
      local_58 = (undefined8 *)*local_58;
    }
    else {
      local_58 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_58 + 0x10));
    }
  }
  if (*(char *)((longlong)local_48 + 0x19) == '\0') {
    local_40 = (undefined8 *)*local_48;
  }
  else {
    local_40 = (undefined8 *)FUN_141c29370(puVar2);
    local_40 = (undefined8 *)*local_40;
  }
  local_58 = local_40;
  while (*(char *)((longlong)local_58 + 0x19) == '\0') {
    uVar3 = FUN_141c277b0(param_1,local_58);
    uVar4 = FUN_141c27320(param_1);
    cVar1 = FUN_14044a540(uVar4,param_3,uVar3);
    if (cVar1 == '\0') {
      local_58 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_58 + 0x10));
    }
    else {
      local_48 = local_58;
      local_58 = (undefined8 *)*local_58;
    }
  }
  FUN_141bf2370(local_10,local_38,(FUN_141beca80(puVar2)));
  FUN_141bf2370(local_18,local_48,(FUN_141beca80(puVar2)));
  FUN_141bdbd10(param_2,local_10,local_18);
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0340
void FUN_141be0340(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedad0(local_18,(FUN_141beca90(param_2)));
  FUN_141bedad0(local_18,(FUN_141beca90(param_2 + 8)));
  FUN_141c2bba0(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be03b0
void FUN_141be03b0(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedae0(local_18,(FUN_141becaa0(param_2)));
  FUN_141bedae0(local_18,(FUN_141becaa0(param_2 + 8)));
  FUN_141bedae0(local_18,(FUN_141becaa0(param_2 + 0x10)));
  FUN_141c2bbd0(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0440
void FUN_141be0440(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedaf0(local_18,(FUN_141becab0(param_2)));
  FUN_141bedaf0(local_18,(FUN_141becab0(param_2 + 8)));
  FUN_141bedaf0(local_18,(FUN_141becab0(param_2 + 0x10)));
  FUN_141c2bc00(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be04d0
void FUN_141be04d0(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedb00(local_18,(FUN_141becac0(param_2)));
  FUN_141bedb00(local_18,(FUN_141becac0(param_2 + 8)));
  FUN_141bedb00(local_18,(FUN_141becac0(param_2 + 0x10)));
  FUN_141c2bc30(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0560
void FUN_141be0560(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedb10(local_18,(FUN_141becad0(param_2)));
  FUN_141bedb10(local_18,(FUN_141becad0(param_2 + 8)));
  FUN_141bedb10(local_18,(FUN_141becad0(param_2 + 0x10)));
  FUN_141c2bc60(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be05f0
void FUN_141be05f0(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedb20(local_18,(FUN_141becae0(param_2)));
  FUN_141bedb20(local_18,(FUN_141becae0(param_2 + 8)));
  FUN_141bedb20(local_18,(FUN_141becae0(param_2 + 0x10)));
  FUN_141c2bc90(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0680
void FUN_141be0680(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedb30(local_18,(FUN_141becaf0(param_2)));
  FUN_141bedb30(local_18,(FUN_141becaf0(param_2 + 8)));
  FUN_141bedb30(local_18,(FUN_141becaf0(param_2 + 0x10)));
  FUN_141c2bcc0(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0710
void FUN_141be0710(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedb40(local_18,(FUN_141becb00(param_2)));
  FUN_141bedb40(local_18,(FUN_141becb00(param_2 + 8)));
  FUN_141bedb40(local_18,(FUN_141becb00(param_2 + 0x10)));
  FUN_141c2bcf0(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be07a0
void FUN_141be07a0(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedb50(local_18,(FUN_141becb10(param_2)));
  FUN_141bedb50(local_18,(FUN_141becb10(param_2 + 8)));
  FUN_141bedb50(local_18,(FUN_141becb10(param_2 + 0x10)));
  FUN_141c2bd20(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0830
void FUN_141be0830(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedb60(local_18,(FUN_141becb20(param_2)));
  FUN_141bedb60(local_18,(FUN_141becb20(param_2 + 8)));
  FUN_141bedb60(local_18,(FUN_141becb20(param_2 + 0x10)));
  FUN_141c2bd50(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be08c0
void FUN_141be08c0(undefined8 param_1,longlong param_2)
{
  undefined1 local_18 [8];
  undefined8 local_10;
  
  local_10 = 0xfffffffffffffffe;
  FUN_141bedb70(local_18,(FUN_141becb30(param_2)));
  FUN_141bedb70(local_18,(FUN_141becb30(param_2 + 8)));
  FUN_141bedb70(local_18,(FUN_141becb30(param_2 + 0x10)));
  FUN_141c2bd80(local_18,param_2,1);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0950
undefined8 FUN_141be0950(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0960
undefined8 FUN_141be0960(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0970
undefined8 FUN_141be0970(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0980
undefined8 FUN_141be0980(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0990
undefined8 FUN_141be0990(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be09a0
undefined8 FUN_141be09a0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be09b0
undefined8 FUN_141be09b0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be09c0
undefined8 FUN_141be09c0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be09d0
undefined8 FUN_141be09d0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be09e0
undefined8 FUN_141be09e0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be09f0
longlong FUN_141be09f0(longlong *param_1,longlong *param_2)
{
  return *param_2 - *param_1 >> 4;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0a20
longlong FUN_141be0a20(longlong *param_1,longlong *param_2)
{
  return (*param_2 - *param_1) / 0x18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0a50
longlong FUN_141be0a50(longlong *param_1,longlong *param_2)
{
  return *param_2 - *param_1 >> 4;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0a80
longlong FUN_141be0a80(longlong *param_1,longlong *param_2)
{
  return *param_2 - *param_1 >> 4;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0ab0
longlong FUN_141be0ab0(longlong *param_1,longlong *param_2)
{
  return *param_2 - *param_1 >> 4;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0ae0
undefined8 FUN_141be0ae0(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  
  FUN_141be09f0(param_1,param_2,local_18);
  return 0; // RAXCHECK: callers use the return value
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0b10
undefined8 FUN_141be0b10(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  
  FUN_141be0a20(param_1,param_2,local_18);
  return 0; // RAXCHECK: callers use the return value
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0b40
undefined8 FUN_141be0b40(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  
  FUN_141be0a50(param_1,param_2,local_18);
  return 0; // RAXCHECK: callers use the return value
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0b70
undefined8 FUN_141be0b70(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  
  FUN_141be0a80(param_1,param_2,local_18);
  return 0; // RAXCHECK: callers use the return value
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0ba0
undefined8 FUN_141be0ba0(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  
  FUN_141be0ab0(param_1,param_2,local_18);
  return 0; // RAXCHECK: callers use the return value
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0bd0
void FUN_141be0bd0(undefined8 param_1,longlong param_2,undefined8 param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = *(undefined8 **)(param_2 + 8);
  uVar2 = FUN_141beea70(param_3);
  uVar2 = FUN_141bddb10(param_1,param_2,puVar1,uVar2);
  FUN_141c27530(param_1,1);
  *(undefined8 *)(param_2 + 8) = uVar2;
  *puVar1 = uVar2;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0c50
void FUN_141be0c50(undefined8 param_1,longlong param_2,undefined8 param_3)
{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = *(undefined8 **)(param_2 + 8);
  uVar2 = FUN_140a14dd0(param_3);
  uVar2 = FUN_141bddba0(param_1,param_2,puVar1,uVar2);
  FUN_141c275b0(param_1,1);
  *(undefined8 *)(param_2 + 8) = uVar2;
  *puVar1 = uVar2;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be0cd0
undefined8 FUN_141be0cd0(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c26000(param_1);
  lVar3 = FUN_141c2e660(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee8b0(param_5);
    lVar3 = FUN_141bdd900(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c29270(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c279d0(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c29130(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c29130(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c29130(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c279d0(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c279d0(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c27b40(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c29470(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c29470(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c27b40(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c29270(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc00(plVar2);
    FUN_141bf23d0(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21930(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be1030
undefined8 FUN_141be1030(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c26060(param_1);
  lVar3 = FUN_141c2e680(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee8c0(param_5);
    lVar3 = FUN_141bdd920(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c29290(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c279e0(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c29150(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c29150(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c29150(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c279e0(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c279e0(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c27c20(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c29550(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c29550(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c27c20(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c29290(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc10(plVar2);
    FUN_141bf2410(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21980(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be1390
undefined8 FUN_141be1390(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c260c0(param_1);
  lVar3 = FUN_141c2e6a0(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee8d0(param_5);
    lVar3 = FUN_141bdd940(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c292b0(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c279f0(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c29170(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c29170(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c29170(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c279f0(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c279f0(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c27d00(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c29630(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c29630(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c27d00(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c292b0(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc20(plVar2);
    FUN_141bf2450(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c219d0(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be16f0
undefined8 FUN_141be16f0(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c26120(param_1);
  lVar3 = FUN_141c2e6c0(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee8e0(param_5);
    lVar3 = FUN_141bdd960(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c292d0(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c27a00(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c29190(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c29190(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c29190(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c27a00(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c27a00(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c27de0(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c29710(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c29710(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c27de0(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c292d0(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc30(plVar2);
    FUN_141bf2490(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21a20(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be1a50
undefined8 FUN_141be1a50(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c26180(param_1);
  lVar3 = FUN_141c2e6e0(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee8f0(param_5);
    lVar3 = FUN_141bdd980(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c292f0(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c27a10(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c291b0(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c291b0(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c291b0(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c27a10(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c27a10(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c27ec0(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c297f0(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c297f0(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c27ec0(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c292f0(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc40(plVar2);
    FUN_141bf24d0(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21a70(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be1db0
undefined8 FUN_141be1db0(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c261e0(param_1);
  lVar3 = FUN_141c2e700(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee900(param_5);
    lVar3 = FUN_141bdd9a0(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c29310(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c27a20(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c291d0(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c291d0(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c291d0(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c27a20(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c27a20(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c27fa0(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c298d0(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c298d0(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c27fa0(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c29310(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc50(plVar2);
    FUN_141bf2510(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21ac0(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be2110
undefined8 FUN_141be2110(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c26240(param_1);
  lVar3 = FUN_141c2e720(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee910(param_5);
    lVar3 = FUN_141bdd9c0(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c29330(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c27a30(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c291f0(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c291f0(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c291f0(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c27a30(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c27a30(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c28080(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c299b0(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c299b0(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c28080(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c29330(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc60(plVar2);
    FUN_141bf2550(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21b10(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be2470
undefined8 FUN_141be2470(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c262a0(param_1);
  lVar3 = FUN_141c2e740(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee920(param_5);
    lVar3 = FUN_141bdd9e0(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c29350(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c27a40(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c29210(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c29210(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c29210(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c27a40(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c27a40(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c28160(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c29a90(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c29a90(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c28160(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c29350(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc70(plVar2);
    FUN_141bf2590(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21b60(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be27d0
undefined8 FUN_141be27d0(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined8 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c26300(param_1);
  lVar3 = FUN_141c2e760(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141bee930(param_5);
    lVar3 = FUN_141bdda00(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c29370(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c27a50(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c29230(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c29230(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c29230(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c27a50(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c27a50(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c28240(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c29b70(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c29b70(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c28240(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c29370(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becc80(plVar2);
    FUN_141bf25d0(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21bb0(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be2b30
undefined8 FUN_141be2b30(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined1 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_141c26360(param_1);
  lVar3 = FUN_141c2e780(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141beea80(param_5);
    lVar3 = FUN_141bdda20(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_141c29250(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c279c0(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_141c29110(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_141c29110(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c29110(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_141c279c0(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_141c279c0(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c27a60(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c29390(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_141c29390(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_141c27a60(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_141c29250(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_141becbf0(plVar2);
    FUN_141bf2090(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21c00(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be2e90
undefined8 FUN_141be2e90(undefined8 param_1,undefined8 param_2,char param_3,longlong *param_4, undefined8 param_5,undefined1 param_6)
{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong local_28;
  
  plVar2 = (longlong *)FUN_140a1b9b0(param_1);
  lVar3 = FUN_141c2e7a0(param_1);
  if ((ulonglong)(*(longlong *)((undefined1 *)plVar2 + 0x8)) < lVar3 - 1U) {
    uVar4 = FUN_141beeab0(param_5);
    lVar3 = FUN_141bdda50(param_1,param_6,uVar4);
    (*(longlong *)((undefined1 *)plVar2 + 0x8)) = (*(longlong *)((undefined1 *)plVar2 + 0x8)) + 1;
    *(longlong **)(lVar3 + 8) = param_4;
    local_28 = lVar3;
    if (param_4 == (longlong *)*plVar2) {
      plVar5 = (longlong *)FUN_140a1ca80(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_140a1c170(plVar2);
      *plVar5 = lVar3;
      plVar5 = (longlong *)FUN_140a1c9e0(plVar2);
      *plVar5 = lVar3;
    }
    else if (param_3 == '\0') {
      (*(longlong *)((undefined1 *)param_4 + 0x10)) = lVar3;
      plVar5 = (longlong *)FUN_140a1c9e0(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_140a1c9e0(plVar2);
        *plVar5 = lVar3;
      }
    }
    else {
      *param_4 = lVar3;
      plVar5 = (longlong *)FUN_140a1c170(plVar2);
      if (param_4 == (longlong *)*plVar5) {
        plVar5 = (longlong *)FUN_140a1c170(plVar2);
        *plVar5 = lVar3;
      }
    }
    while (*(char *)(*(longlong *)(local_28 + 8) + 0x18) == '\0') {
      if (*(longlong *)(local_28 + 8) == **(longlong **)(*(longlong *)(local_28 + 8) + 8)) {
        lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x10);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == *(longlong *)(*(longlong *)(local_28 + 8) + 0x10)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_140a1c430(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_140a1cd60(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
      else {
        lVar1 = **(longlong **)(*(longlong *)(local_28 + 8) + 8);
        if (*(char *)(lVar1 + 0x18) == '\0') {
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(lVar1 + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          local_28 = *(longlong *)(*(longlong *)(local_28 + 8) + 8);
        }
        else {
          if (local_28 == **(longlong **)(local_28 + 8)) {
            local_28 = *(longlong *)(local_28 + 8);
            FUN_140a1cd60(plVar2,local_28);
          }
          *(undefined1 *)(*(longlong *)(local_28 + 8) + 0x18) = 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(local_28 + 8) + 8) + 0x18) = 0;
          FUN_140a1c430(plVar2,*(undefined8 *)(*(longlong *)(local_28 + 8) + 8));
        }
      }
    }
    plVar5 = (longlong *)FUN_140a1ca80(plVar2);
    *(undefined1 *)(*plVar5 + 0x18) = 1;
    uVar4 = FUN_140a14530(plVar2);
    FUN_140a15890(param_2,lVar3,uVar4);
    return param_2;
  }
  FUN_141c21c10(param_1,param_6);
                    
  ((undefined8 (*)(...))0x14274cd7bULL)("map/undefined1 too long");
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be31f0
 undefined8 * FUN_141be31f0(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5)
{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_res18;
  undefined8 local_res20;
  longlong local_180 [2];
  char local_16f;
  char local_16e;
  char local_16d;
  char local_16c;
  char local_16b;
  char local_16a;
  char local_169;
  char local_168;
  char local_167;
  undefined8 *local_160;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [32];
  
  local_58 = 0xfffffffffffffffe;
  local_res18 = param_3;
  local_res20 = param_4;
  FUN_141bf2110(local_180);
  local_160 = (undefined8 *)FUN_141c26000(param_1);
  lVar1 = FUN_141c2ed10(param_1);
  if (lVar1 == 0) {
    uVar2 = FUN_141bee8b0(local_res20);
    FUN_141be0cd0(param_1,param_2,1,*local_160,uVar2,param_5);
    return param_2;
  }
  uVar2 = FUN_141c2ac50(param_1,local_38);
  local_16f = FUN_141bf7400(&local_res18,uVar2);
  if (local_16f == '\0') {
    uVar2 = FUN_141c2c220(param_1,local_30);
    local_16d = FUN_141bf7400(&local_res18,uVar2);
    if (local_16d == '\0') {
      local_a8 = FUN_141c27630(param_1,local_res18);
      local_a0 = FUN_141c27840(param_1,local_res20);
      uVar2 = FUN_141c27100(param_1);
      local_16b = FUN_1401f1b70(uVar2,local_a0,local_a8);
      if (local_16b != '\0') {
        local_180[0] = local_res18;
        local_90 = FUN_141c27840(param_1,local_res20);
        local_98 = (undefined8 *)FUN_141bf8d80(local_180);
        local_88 = FUN_141c27630(param_1,*local_98);
        uVar2 = FUN_141c27100(param_1);
        local_16a = FUN_1401f1b70(uVar2,local_88,local_90);
        if (local_16a != '\0') {
          if (*(char *)(*(longlong *)(local_180[0] + 0x10) + 0x19) != '\0') {
            uVar2 = FUN_141bee8b0(local_res20);
            FUN_141be0cd0(param_1,param_2,0,local_180[0],uVar2,param_5);
            return param_2;
          }
          uVar2 = FUN_141bee8b0(local_res20);
          FUN_141be0cd0(param_1,param_2,1,local_res18,uVar2,param_5);
          return param_2;
        }
      }
      local_80 = FUN_141c27840(param_1,local_res20);
      local_78 = FUN_141c27630(param_1,local_res18);
      uVar2 = FUN_141c27100(param_1);
      local_169 = FUN_1401f1b70(uVar2,local_78,local_80);
      if (local_169 != '\0') {
        local_180[0] = local_res18;
        local_70 = FUN_141bf8300(local_180);
        uVar2 = FUN_141c2c220(param_1,local_28);
        local_168 = FUN_141bf7400(local_70,uVar2);
        if (local_168 == '\0') {
          local_68 = FUN_141c27630(param_1,local_180[0]);
          local_60 = FUN_141c27840(param_1,local_res20);
          uVar2 = FUN_141c27100(param_1);
          local_167 = FUN_1401f1b70(uVar2,local_60,local_68);
          if (local_167 == '\0') goto LAB_141be3dcb;
        }
        if (*(char *)(*(longlong *)(local_res18 + 0x10) + 0x19) != '\0') {
          uVar2 = FUN_141bee8b0(local_res20);
          FUN_141be0cd0(param_1,param_2,0,local_res18,uVar2,param_5);
          return param_2;
        }
        uVar2 = FUN_141bee8b0(local_res20);
        FUN_141be0cd0(param_1,param_2,1,local_180[0],uVar2,param_5);
        return param_2;
      }
    }
    else {
      local_c0 = FUN_141c27840(param_1,local_res20);
      local_c8 = (undefined8 *)FUN_141c29130(local_160);
      local_b8 = FUN_141c27630(param_1,*local_c8);
      uVar2 = FUN_141c27100(param_1);
      local_16c = FUN_1401f1b70(uVar2,local_b8,local_c0);
      if (local_16c != '\0') {
        local_b0 = (undefined8 *)FUN_141c29130(local_160);
        uVar2 = FUN_141bee8b0(local_res20);
        FUN_141be0cd0(param_1,param_2,0,*local_b0,uVar2,param_5);
        return param_2;
      }
      local_16c = 0;
    }
  }
  else {
    local_d8 = FUN_141c27630(param_1,local_res18);
    local_d0 = FUN_141c27840(param_1,local_res20);
    uVar2 = FUN_141c27100(param_1);
    local_16e = FUN_1401f1b70(uVar2,local_d0,local_d8);
    if (local_16e != '\0') {
      uVar2 = FUN_141bee8b0(local_res20);
      FUN_141be0cd0(param_1,param_2,1,local_res18,uVar2,param_5);
      return param_2;
    }
    local_16e = 0;
  }
LAB_141be3dcb:
  *param_2 = *((undefined8 *)FUN_141be7b70(param_1,local_20,0,(FUN_141bee8b0(local_res20)),param_5));
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be3e30
 undefined8 * FUN_141be3e30(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5)
{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_res18;
  undefined8 local_res20;
  longlong local_180 [2];
  char local_16f;
  char local_16e;
  char local_16d;
  char local_16c;
  char local_16b;
  char local_16a;
  char local_169;
  char local_168;
  char local_167;
  undefined8 *local_160;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [32];
  
  local_58 = 0xfffffffffffffffe;
  local_res18 = param_3;
  local_res20 = param_4;
  FUN_141bf2170(local_180);
  local_160 = (undefined8 *)FUN_141c26060(param_1);
  lVar1 = FUN_141c2ed30(param_1);
  if (lVar1 == 0) {
    uVar2 = FUN_141bee8c0(local_res20);
    FUN_141be1030(param_1,param_2,1,*local_160,uVar2,param_5);
    return param_2;
  }
  uVar2 = FUN_141c2acc0(param_1,local_38);
  local_16f = FUN_141bf7440(&local_res18,uVar2);
  if (local_16f == '\0') {
    uVar2 = FUN_141c2c280(param_1,local_30);
    local_16d = FUN_141bf7440(&local_res18,uVar2);
    if (local_16d == '\0') {
      local_a8 = FUN_141c27660(param_1,local_res18);
      local_a0 = FUN_141c27860(param_1,local_res20);
      uVar2 = FUN_141c27140(param_1);
      local_16b = FUN_1401f1b70(uVar2,local_a0,local_a8);
      if (local_16b != '\0') {
        local_180[0] = local_res18;
        local_90 = FUN_141c27860(param_1,local_res20);
        local_98 = (undefined8 *)FUN_141bf8da0(local_180);
        local_88 = FUN_141c27660(param_1,*local_98);
        uVar2 = FUN_141c27140(param_1);
        local_16a = FUN_1401f1b70(uVar2,local_88,local_90);
        if (local_16a != '\0') {
          if (*(char *)(*(longlong *)(local_180[0] + 0x10) + 0x19) != '\0') {
            uVar2 = FUN_141bee8c0(local_res20);
            FUN_141be1030(param_1,param_2,0,local_180[0],uVar2,param_5);
            return param_2;
          }
          uVar2 = FUN_141bee8c0(local_res20);
          FUN_141be1030(param_1,param_2,1,local_res18,uVar2,param_5);
          return param_2;
        }
      }
      local_80 = FUN_141c27860(param_1,local_res20);
      local_78 = FUN_141c27660(param_1,local_res18);
      uVar2 = FUN_141c27140(param_1);
      local_169 = FUN_1401f1b70(uVar2,local_78,local_80);
      if (local_169 != '\0') {
        local_180[0] = local_res18;
        local_70 = FUN_141bf8370(local_180);
        uVar2 = FUN_141c2c280(param_1,local_28);
        local_168 = FUN_141bf7440(local_70,uVar2);
        if (local_168 == '\0') {
          local_68 = FUN_141c27660(param_1,local_180[0]);
          local_60 = FUN_141c27860(param_1,local_res20);
          uVar2 = FUN_141c27140(param_1);
          local_167 = FUN_1401f1b70(uVar2,local_60,local_68);
          if (local_167 == '\0') goto LAB_141be4a0b;
        }
        if (*(char *)(*(longlong *)(local_res18 + 0x10) + 0x19) != '\0') {
          uVar2 = FUN_141bee8c0(local_res20);
          FUN_141be1030(param_1,param_2,0,local_res18,uVar2,param_5);
          return param_2;
        }
        uVar2 = FUN_141bee8c0(local_res20);
        FUN_141be1030(param_1,param_2,1,local_180[0],uVar2,param_5);
        return param_2;
      }
    }
    else {
      local_c0 = FUN_141c27860(param_1,local_res20);
      local_c8 = (undefined8 *)FUN_141c29150(local_160);
      local_b8 = FUN_141c27660(param_1,*local_c8);
      uVar2 = FUN_141c27140(param_1);
      local_16c = FUN_1401f1b70(uVar2,local_b8,local_c0);
      if (local_16c != '\0') {
        local_b0 = (undefined8 *)FUN_141c29150(local_160);
        uVar2 = FUN_141bee8c0(local_res20);
        FUN_141be1030(param_1,param_2,0,*local_b0,uVar2,param_5);
        return param_2;
      }
      local_16c = 0;
    }
  }
  else {
    local_d8 = FUN_141c27660(param_1,local_res18);
    local_d0 = FUN_141c27860(param_1,local_res20);
    uVar2 = FUN_141c27140(param_1);
    local_16e = FUN_1401f1b70(uVar2,local_d0,local_d8);
    if (local_16e != '\0') {
      uVar2 = FUN_141bee8c0(local_res20);
      FUN_141be1030(param_1,param_2,1,local_res18,uVar2,param_5);
      return param_2;
    }
    local_16e = 0;
  }
LAB_141be4a0b:
  *param_2 = *((undefined8 *)FUN_141be7f80(param_1,local_20,0,(FUN_141bee8c0(local_res20)),param_5));
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be4a70
 undefined8 * FUN_141be4a70(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5)
{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_res18;
  undefined8 local_res20;
  longlong local_180 [2];
  char local_16f;
  char local_16e;
  char local_16d;
  char local_16c;
  char local_16b;
  char local_16a;
  char local_169;
  char local_168;
  char local_167;
  undefined8 *local_160;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [32];
  
  local_58 = 0xfffffffffffffffe;
  local_res18 = param_3;
  local_res20 = param_4;
  FUN_141bf21d0(local_180);
  local_160 = (undefined8 *)FUN_141c260c0(param_1);
  lVar1 = FUN_141c2ed50(param_1);
  if (lVar1 == 0) {
    uVar2 = FUN_141bee8d0(local_res20);
    FUN_141be1390(param_1,param_2,1,*local_160,uVar2,param_5);
    return param_2;
  }
  uVar2 = FUN_141c2ad30(param_1,local_38);
  local_16f = FUN_141bf7480(&local_res18,uVar2);
  if (local_16f == '\0') {
    uVar2 = FUN_141c2c2e0(param_1,local_30);
    local_16d = FUN_141bf7480(&local_res18,uVar2);
    if (local_16d == '\0') {
      local_a8 = FUN_141c27690(param_1,local_res18);
      local_a0 = FUN_141c27880(param_1,local_res20);
      uVar2 = FUN_141c27180(param_1);
      local_16b = FUN_140185090(uVar2,local_a0,local_a8);
      if (local_16b != '\0') {
        local_180[0] = local_res18;
        local_90 = FUN_141c27880(param_1,local_res20);
        local_98 = (undefined8 *)FUN_141bf8dc0(local_180);
        local_88 = FUN_141c27690(param_1,*local_98);
        uVar2 = FUN_141c27180(param_1);
        local_16a = FUN_140185090(uVar2,local_88,local_90);
        if (local_16a != '\0') {
          if (*(char *)(*(longlong *)(local_180[0] + 0x10) + 0x19) != '\0') {
            uVar2 = FUN_141bee8d0(local_res20);
            FUN_141be1390(param_1,param_2,0,local_180[0],uVar2,param_5);
            return param_2;
          }
          uVar2 = FUN_141bee8d0(local_res20);
          FUN_141be1390(param_1,param_2,1,local_res18,uVar2,param_5);
          return param_2;
        }
      }
      local_80 = FUN_141c27880(param_1,local_res20);
      local_78 = FUN_141c27690(param_1,local_res18);
      uVar2 = FUN_141c27180(param_1);
      local_169 = FUN_140185090(uVar2,local_78,local_80);
      if (local_169 != '\0') {
        local_180[0] = local_res18;
        local_70 = FUN_141bf83e0(local_180);
        uVar2 = FUN_141c2c2e0(param_1,local_28);
        local_168 = FUN_141bf7480(local_70,uVar2);
        if (local_168 == '\0') {
          local_68 = FUN_141c27690(param_1,local_180[0]);
          local_60 = FUN_141c27880(param_1,local_res20);
          uVar2 = FUN_141c27180(param_1);
          local_167 = FUN_140185090(uVar2,local_60,local_68);
          if (local_167 == '\0') goto LAB_141be564b;
        }
        if (*(char *)(*(longlong *)(local_res18 + 0x10) + 0x19) != '\0') {
          uVar2 = FUN_141bee8d0(local_res20);
          FUN_141be1390(param_1,param_2,0,local_res18,uVar2,param_5);
          return param_2;
        }
        uVar2 = FUN_141bee8d0(local_res20);
        FUN_141be1390(param_1,param_2,1,local_180[0],uVar2,param_5);
        return param_2;
      }
    }
    else {
      local_c0 = FUN_141c27880(param_1,local_res20);
      local_c8 = (undefined8 *)FUN_141c29170(local_160);
      local_b8 = FUN_141c27690(param_1,*local_c8);
      uVar2 = FUN_141c27180(param_1);
      local_16c = FUN_140185090(uVar2,local_b8,local_c0);
      if (local_16c != '\0') {
        local_b0 = (undefined8 *)FUN_141c29170(local_160);
        uVar2 = FUN_141bee8d0(local_res20);
        FUN_141be1390(param_1,param_2,0,*local_b0,uVar2,param_5);
        return param_2;
      }
      local_16c = 0;
    }
  }
  else {
    local_d8 = FUN_141c27690(param_1,local_res18);
    local_d0 = FUN_141c27880(param_1,local_res20);
    uVar2 = FUN_141c27180(param_1);
    local_16e = FUN_140185090(uVar2,local_d0,local_d8);
    if (local_16e != '\0') {
      uVar2 = FUN_141bee8d0(local_res20);
      FUN_141be1390(param_1,param_2,1,local_res18,uVar2,param_5);
      return param_2;
    }
    local_16e = 0;
  }
LAB_141be564b:
  *param_2 = *((undefined8 *)FUN_141be8390(param_1,local_20,0,(FUN_141bee8d0(local_res20)),param_5));
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be56b0
 undefined8 * FUN_141be56b0(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5)
{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_res18;
  undefined8 local_res20;
  longlong local_180 [2];
  char local_16f;
  char local_16e;
  char local_16d;
  char local_16c;
  char local_16b;
  char local_16a;
  char local_169;
  char local_168;
  char local_167;
  undefined8 *local_160;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [32];
  
  local_58 = 0xfffffffffffffffe;
  local_res18 = param_3;
  local_res20 = param_4;
  FUN_141bf22f0(local_180);
  local_160 = (undefined8 *)FUN_141c26240(param_1);
  lVar1 = FUN_141c2ed70(param_1);
  if (lVar1 == 0) {
    uVar2 = FUN_141bee910(local_res20);
    FUN_141be2110(param_1,param_2,1,*local_160,uVar2,param_5);
    return param_2;
  }
  uVar2 = FUN_141c2aef0(param_1,local_38);
  local_16f = FUN_141bf7580(&local_res18,uVar2);
  if (local_16f == '\0') {
    uVar2 = FUN_141c2c460(param_1,local_30);
    local_16d = FUN_141bf7580(&local_res18,uVar2);
    if (local_16d == '\0') {
      local_a8 = FUN_141c27750(param_1,local_res18);
      local_a0 = FUN_141c27900(param_1,local_res20);
      uVar2 = FUN_141c27280(param_1);
      local_16b = FUN_140999030(uVar2,local_a0,local_a8);
      if (local_16b != '\0') {
        local_180[0] = local_res18;
        local_90 = FUN_141c27900(param_1,local_res20);
        local_98 = (undefined8 *)FUN_141bf8e40(local_180);
        local_88 = FUN_141c27750(param_1,*local_98);
        uVar2 = FUN_141c27280(param_1);
        local_16a = FUN_140999030(uVar2,local_88,local_90);
        if (local_16a != '\0') {
          if (*(char *)(*(longlong *)(local_180[0] + 0x10) + 0x19) != '\0') {
            uVar2 = FUN_141bee910(local_res20);
            FUN_141be2110(param_1,param_2,0,local_180[0],uVar2,param_5);
            return param_2;
          }
          uVar2 = FUN_141bee910(local_res20);
          FUN_141be2110(param_1,param_2,1,local_res18,uVar2,param_5);
          return param_2;
        }
      }
      local_80 = FUN_141c27900(param_1,local_res20);
      local_78 = FUN_141c27750(param_1,local_res18);
      uVar2 = FUN_141c27280(param_1);
      local_169 = FUN_140999030(uVar2,local_78,local_80);
      if (local_169 != '\0') {
        local_180[0] = local_res18;
        local_70 = FUN_141bf85a0(local_180);
        uVar2 = FUN_141c2c460(param_1,local_28);
        local_168 = FUN_141bf7580(local_70,uVar2);
        if (local_168 == '\0') {
          local_68 = FUN_141c27750(param_1,local_180[0]);
          local_60 = FUN_141c27900(param_1,local_res20);
          uVar2 = FUN_141c27280(param_1);
          local_167 = FUN_140999030(uVar2,local_60,local_68);
          if (local_167 == '\0') goto LAB_141be628b;
        }
        if (*(char *)(*(longlong *)(local_res18 + 0x10) + 0x19) != '\0') {
          uVar2 = FUN_141bee910(local_res20);
          FUN_141be2110(param_1,param_2,0,local_res18,uVar2,param_5);
          return param_2;
        }
        uVar2 = FUN_141bee910(local_res20);
        FUN_141be2110(param_1,param_2,1,local_180[0],uVar2,param_5);
        return param_2;
      }
    }
    else {
      local_c0 = FUN_141c27900(param_1,local_res20);
      local_c8 = (undefined8 *)FUN_141c291f0(local_160);
      local_b8 = FUN_141c27750(param_1,*local_c8);
      uVar2 = FUN_141c27280(param_1);
      local_16c = FUN_140999030(uVar2,local_b8,local_c0);
      if (local_16c != '\0') {
        local_b0 = (undefined8 *)FUN_141c291f0(local_160);
        uVar2 = FUN_141bee910(local_res20);
        FUN_141be2110(param_1,param_2,0,*local_b0,uVar2,param_5);
        return param_2;
      }
      local_16c = 0;
    }
  }
  else {
    local_d8 = FUN_141c27750(param_1,local_res18);
    local_d0 = FUN_141c27900(param_1,local_res20);
    uVar2 = FUN_141c27280(param_1);
    local_16e = FUN_140999030(uVar2,local_d0,local_d8);
    if (local_16e != '\0') {
      uVar2 = FUN_141bee910(local_res20);
      FUN_141be2110(param_1,param_2,1,local_res18,uVar2,param_5);
      return param_2;
    }
    local_16e = 0;
  }
LAB_141be628b:
  *param_2 = *((undefined8 *)FUN_141be93d0(param_1,local_20,0,(FUN_141bee910(local_res20)),param_5));
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be62f0
 undefined8 * FUN_141be62f0(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5)
{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_res18;
  undefined8 local_res20;
  longlong local_180 [2];
  char local_16f;
  char local_16e;
  char local_16d;
  char local_16c;
  char local_16b;
  char local_16a;
  char local_169;
  char local_168;
  char local_167;
  undefined8 *local_160;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [32];
  
  local_58 = 0xfffffffffffffffe;
  local_res18 = param_3;
  local_res20 = param_4;
  FUN_141bf2350(local_180);
  local_160 = (undefined8 *)FUN_141c262a0(param_1);
  lVar1 = FUN_141c2ed90(param_1);
  if (lVar1 == 0) {
    uVar2 = FUN_141bee920(local_res20);
    FUN_141be2470(param_1,param_2,1,*local_160,uVar2,param_5);
    return param_2;
  }
  uVar2 = FUN_141c2af60(param_1,local_38);
  local_16f = FUN_141bf75c0(&local_res18,uVar2);
  if (local_16f == '\0') {
    uVar2 = FUN_141c2c4c0(param_1,local_30);
    local_16d = FUN_141bf75c0(&local_res18,uVar2);
    if (local_16d == '\0') {
      local_a8 = FUN_141c27780(param_1,local_res18);
      local_a0 = FUN_141c27920(param_1,local_res20);
      uVar2 = FUN_141c272c0(param_1);
      local_16b = FUN_140999030(uVar2,local_a0,local_a8);
      if (local_16b != '\0') {
        local_180[0] = local_res18;
        local_90 = FUN_141c27920(param_1,local_res20);
        local_98 = (undefined8 *)FUN_141bf8e60(local_180);
        local_88 = FUN_141c27780(param_1,*local_98);
        uVar2 = FUN_141c272c0(param_1);
        local_16a = FUN_140999030(uVar2,local_88,local_90);
        if (local_16a != '\0') {
          if (*(char *)(*(longlong *)(local_180[0] + 0x10) + 0x19) != '\0') {
            uVar2 = FUN_141bee920(local_res20);
            FUN_141be2470(param_1,param_2,0,local_180[0],uVar2,param_5);
            return param_2;
          }
          uVar2 = FUN_141bee920(local_res20);
          FUN_141be2470(param_1,param_2,1,local_res18,uVar2,param_5);
          return param_2;
        }
      }
      local_80 = FUN_141c27920(param_1,local_res20);
      local_78 = FUN_141c27780(param_1,local_res18);
      uVar2 = FUN_141c272c0(param_1);
      local_169 = FUN_140999030(uVar2,local_78,local_80);
      if (local_169 != '\0') {
        local_180[0] = local_res18;
        local_70 = FUN_141bf8610(local_180);
        uVar2 = FUN_141c2c4c0(param_1,local_28);
        local_168 = FUN_141bf75c0(local_70,uVar2);
        if (local_168 == '\0') {
          local_68 = FUN_141c27780(param_1,local_180[0]);
          local_60 = FUN_141c27920(param_1,local_res20);
          uVar2 = FUN_141c272c0(param_1);
          local_167 = FUN_140999030(uVar2,local_60,local_68);
          if (local_167 == '\0') goto LAB_141be6ecb;
        }
        if (*(char *)(*(longlong *)(local_res18 + 0x10) + 0x19) != '\0') {
          uVar2 = FUN_141bee920(local_res20);
          FUN_141be2470(param_1,param_2,0,local_res18,uVar2,param_5);
          return param_2;
        }
        uVar2 = FUN_141bee920(local_res20);
        FUN_141be2470(param_1,param_2,1,local_180[0],uVar2,param_5);
        return param_2;
      }
    }
    else {
      local_c0 = FUN_141c27920(param_1,local_res20);
      local_c8 = (undefined8 *)FUN_141c29210(local_160);
      local_b8 = FUN_141c27780(param_1,*local_c8);
      uVar2 = FUN_141c272c0(param_1);
      local_16c = FUN_140999030(uVar2,local_b8,local_c0);
      if (local_16c != '\0') {
        local_b0 = (undefined8 *)FUN_141c29210(local_160);
        uVar2 = FUN_141bee920(local_res20);
        FUN_141be2470(param_1,param_2,0,*local_b0,uVar2,param_5);
        return param_2;
      }
      local_16c = 0;
    }
  }
  else {
    local_d8 = FUN_141c27780(param_1,local_res18);
    local_d0 = FUN_141c27920(param_1,local_res20);
    uVar2 = FUN_141c272c0(param_1);
    local_16e = FUN_140999030(uVar2,local_d0,local_d8);
    if (local_16e != '\0') {
      uVar2 = FUN_141bee920(local_res20);
      FUN_141be2470(param_1,param_2,1,local_res18,uVar2,param_5);
      return param_2;
    }
    local_16e = 0;
  }
LAB_141be6ecb:
  *param_2 = *((undefined8 *)FUN_141be97e0(param_1,local_20,0,(FUN_141bee920(local_res20)),param_5));
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be6f30
 undefined8 * FUN_141be6f30(undefined8 param_1,undefined8 *param_2,longlong param_3,undefined8 param_4, undefined8 param_5)
{
  longlong lVar1;
  undefined8 uVar2;
  longlong local_res18;
  undefined8 local_res20;
  longlong local_180 [2];
  char local_16f;
  char local_16e;
  char local_16d;
  char local_16c;
  char local_16b;
  char local_16a;
  char local_169;
  char local_168;
  char local_167;
  undefined8 *local_160;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [32];
  
  local_58 = 0xfffffffffffffffe;
  local_res18 = param_3;
  local_res20 = param_4;
  FUN_141bf23b0(local_180);
  local_160 = (undefined8 *)FUN_141c26300(param_1);
  lVar1 = FUN_141c2edb0(param_1);
  if (lVar1 == 0) {
    uVar2 = FUN_141bee930(local_res20);
    FUN_141be27d0(param_1,param_2,1,*local_160,uVar2,param_5);
    return param_2;
  }
  uVar2 = FUN_141c2afd0(param_1,local_38);
  local_16f = FUN_141bf7600(&local_res18,uVar2);
  if (local_16f == '\0') {
    uVar2 = FUN_141c2c520(param_1,local_30);
    local_16d = FUN_141bf7600(&local_res18,uVar2);
    if (local_16d == '\0') {
      local_a8 = FUN_141c277b0(param_1,local_res18);
      local_a0 = FUN_141c27940(param_1,local_res20);
      uVar2 = FUN_141c27300(param_1);
      local_16b = FUN_14044a540(uVar2,local_a0,local_a8);
      if (local_16b != '\0') {
        local_180[0] = local_res18;
        local_90 = FUN_141c27940(param_1,local_res20);
        local_98 = (undefined8 *)FUN_141bf8e80(local_180);
        local_88 = FUN_141c277b0(param_1,*local_98);
        uVar2 = FUN_141c27300(param_1);
        local_16a = FUN_14044a540(uVar2,local_88,local_90);
        if (local_16a != '\0') {
          if (*(char *)(*(longlong *)(local_180[0] + 0x10) + 0x19) != '\0') {
            uVar2 = FUN_141bee930(local_res20);
            FUN_141be27d0(param_1,param_2,0,local_180[0],uVar2,param_5);
            return param_2;
          }
          uVar2 = FUN_141bee930(local_res20);
          FUN_141be27d0(param_1,param_2,1,local_res18,uVar2,param_5);
          return param_2;
        }
      }
      local_80 = FUN_141c27940(param_1,local_res20);
      local_78 = FUN_141c277b0(param_1,local_res18);
      uVar2 = FUN_141c27300(param_1);
      local_169 = FUN_14044a540(uVar2,local_78,local_80);
      if (local_169 != '\0') {
        local_180[0] = local_res18;
        local_70 = FUN_141bf8680(local_180);
        uVar2 = FUN_141c2c520(param_1,local_28);
        local_168 = FUN_141bf7600(local_70,uVar2);
        if (local_168 == '\0') {
          local_68 = FUN_141c277b0(param_1,local_180[0]);
          local_60 = FUN_141c27940(param_1,local_res20);
          uVar2 = FUN_141c27300(param_1);
          local_167 = FUN_14044a540(uVar2,local_60,local_68);
          if (local_167 == '\0') goto LAB_141be7b0b;
        }
        if (*(char *)(*(longlong *)(local_res18 + 0x10) + 0x19) != '\0') {
          uVar2 = FUN_141bee930(local_res20);
          FUN_141be27d0(param_1,param_2,0,local_res18,uVar2,param_5);
          return param_2;
        }
        uVar2 = FUN_141bee930(local_res20);
        FUN_141be27d0(param_1,param_2,1,local_180[0],uVar2,param_5);
        return param_2;
      }
    }
    else {
      local_c0 = FUN_141c27940(param_1,local_res20);
      local_c8 = (undefined8 *)FUN_141c29230(local_160);
      local_b8 = FUN_141c277b0(param_1,*local_c8);
      uVar2 = FUN_141c27300(param_1);
      local_16c = FUN_14044a540(uVar2,local_b8,local_c0);
      if (local_16c != '\0') {
        local_b0 = (undefined8 *)FUN_141c29230(local_160);
        uVar2 = FUN_141bee930(local_res20);
        FUN_141be27d0(param_1,param_2,0,*local_b0,uVar2,param_5);
        return param_2;
      }
      local_16c = 0;
    }
  }
  else {
    local_d8 = FUN_141c277b0(param_1,local_res18);
    local_d0 = FUN_141c27940(param_1,local_res20);
    uVar2 = FUN_141c27300(param_1);
    local_16e = FUN_14044a540(uVar2,local_d0,local_d8);
    if (local_16e != '\0') {
      uVar2 = FUN_141bee930(local_res20);
      FUN_141be27d0(param_1,param_2,1,local_res18,uVar2,param_5);
      return param_2;
    }
    local_16e = 0;
  }
LAB_141be7b0b:
  *param_2 = *((undefined8 *)FUN_141be9bf0(param_1,local_20,0,(FUN_141bee930(local_res20)),param_5));
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be7b70
 undefined8 FUN_141be7b70(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c26000(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c27630(param_1,local_a8);
      local_60 = FUN_141c27840(param_1,param_4);
      uVar2 = FUN_141c27100(param_1);
      local_b8 = FUN_1401f1b70(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c27840(param_1,param_4);
      local_70 = FUN_141c27630(param_1,local_a8);
      uVar2 = FUN_141c27100(param_1);
      cVar1 = FUN_1401f1b70(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc00(local_80);
  FUN_141bf23d0(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2ac50(param_1,local_20);
    cVar1 = FUN_141bf7400(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee8b0(param_4);
      local_50 = FUN_141be0cd0(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdc8d0(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8ec0(&local_90);
  }
  local_48 = FUN_141c27840(param_1,param_4);
  local_40 = FUN_141c27630(param_1,local_90);
  uVar2 = FUN_141c27100(param_1);
  local_b2 = FUN_1401f1b70(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21930(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbdb0(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee8b0(param_4);
    local_38 = FUN_141be0cd0(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdc8d0(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be7f80
 undefined8 FUN_141be7f80(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c26060(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c27660(param_1,local_a8);
      local_60 = FUN_141c27860(param_1,param_4);
      uVar2 = FUN_141c27140(param_1);
      local_b8 = FUN_1401f1b70(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c27860(param_1,param_4);
      local_70 = FUN_141c27660(param_1,local_a8);
      uVar2 = FUN_141c27140(param_1);
      cVar1 = FUN_1401f1b70(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc10(local_80);
  FUN_141bf2410(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2acc0(param_1,local_20);
    cVar1 = FUN_141bf7440(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee8c0(param_4);
      local_50 = FUN_141be1030(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdc920(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8ee0(&local_90);
  }
  local_48 = FUN_141c27860(param_1,param_4);
  local_40 = FUN_141c27660(param_1,local_90);
  uVar2 = FUN_141c27140(param_1);
  local_b2 = FUN_1401f1b70(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21980(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbe00(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee8c0(param_4);
    local_38 = FUN_141be1030(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdc920(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be8390
 undefined8 FUN_141be8390(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c260c0(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c27690(param_1,local_a8);
      local_60 = FUN_141c27880(param_1,param_4);
      uVar2 = FUN_141c27180(param_1);
      local_b8 = FUN_140185090(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c27880(param_1,param_4);
      local_70 = FUN_141c27690(param_1,local_a8);
      uVar2 = FUN_141c27180(param_1);
      cVar1 = FUN_140185090(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc20(local_80);
  FUN_141bf2450(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2ad30(param_1,local_20);
    cVar1 = FUN_141bf7480(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee8d0(param_4);
      local_50 = FUN_141be1390(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdc970(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8f00(&local_90);
  }
  local_48 = FUN_141c27880(param_1,param_4);
  local_40 = FUN_141c27690(param_1,local_90);
  uVar2 = FUN_141c27180(param_1);
  local_b2 = FUN_140185090(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c219d0(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbe50(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee8d0(param_4);
    local_38 = FUN_141be1390(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdc970(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be87a0
 undefined8 FUN_141be87a0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c26120(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c276c0(param_1,local_a8);
      local_60 = FUN_141c278a0(param_1,param_4);
      uVar2 = FUN_141c271c0(param_1);
      local_b8 = FUN_140999030(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c278a0(param_1,param_4);
      local_70 = FUN_141c276c0(param_1,local_a8);
      uVar2 = FUN_141c271c0(param_1);
      cVar1 = FUN_140999030(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc30(local_80);
  FUN_141bf2490(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2ada0(param_1,local_20);
    cVar1 = FUN_141bf74c0(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee8e0(param_4);
      local_50 = FUN_141be16f0(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdc9c0(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8f20(&local_90);
  }
  local_48 = FUN_141c278a0(param_1,param_4);
  local_40 = FUN_141c276c0(param_1,local_90);
  uVar2 = FUN_141c271c0(param_1);
  local_b2 = FUN_140999030(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21a20(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbea0(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee8e0(param_4);
    local_38 = FUN_141be16f0(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdc9c0(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be8bb0
 undefined8 FUN_141be8bb0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c26180(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c276f0(param_1,local_a8);
      local_60 = FUN_141c278c0(param_1,param_4);
      uVar2 = FUN_141c27200(param_1);
      local_b8 = FUN_140999030(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c278c0(param_1,param_4);
      local_70 = FUN_141c276f0(param_1,local_a8);
      uVar2 = FUN_141c27200(param_1);
      cVar1 = FUN_140999030(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc40(local_80);
  FUN_141bf24d0(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2ae10(param_1,local_20);
    cVar1 = FUN_141bf7500(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee8f0(param_4);
      local_50 = FUN_141be1a50(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdca10(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8f40(&local_90);
  }
  local_48 = FUN_141c278c0(param_1,param_4);
  local_40 = FUN_141c276f0(param_1,local_90);
  uVar2 = FUN_141c27200(param_1);
  local_b2 = FUN_140999030(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21a70(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbef0(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee8f0(param_4);
    local_38 = FUN_141be1a50(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdca10(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be8fc0
 undefined8 FUN_141be8fc0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c261e0(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c27720(param_1,local_a8);
      local_60 = FUN_141c278e0(param_1,param_4);
      uVar2 = FUN_141c27240(param_1);
      local_b8 = FUN_140999030(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c278e0(param_1,param_4);
      local_70 = FUN_141c27720(param_1,local_a8);
      uVar2 = FUN_141c27240(param_1);
      cVar1 = FUN_140999030(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc50(local_80);
  FUN_141bf2510(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2ae80(param_1,local_20);
    cVar1 = FUN_141bf7540(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee900(param_4);
      local_50 = FUN_141be1db0(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdca60(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8f60(&local_90);
  }
  local_48 = FUN_141c278e0(param_1,param_4);
  local_40 = FUN_141c27720(param_1,local_90);
  uVar2 = FUN_141c27240(param_1);
  local_b2 = FUN_140999030(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21ac0(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbf40(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee900(param_4);
    local_38 = FUN_141be1db0(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdca60(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be93d0
 undefined8 FUN_141be93d0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c26240(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c27750(param_1,local_a8);
      local_60 = FUN_141c27900(param_1,param_4);
      uVar2 = FUN_141c27280(param_1);
      local_b8 = FUN_140999030(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c27900(param_1,param_4);
      local_70 = FUN_141c27750(param_1,local_a8);
      uVar2 = FUN_141c27280(param_1);
      cVar1 = FUN_140999030(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc60(local_80);
  FUN_141bf2550(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2aef0(param_1,local_20);
    cVar1 = FUN_141bf7580(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee910(param_4);
      local_50 = FUN_141be2110(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdcab0(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8f80(&local_90);
  }
  local_48 = FUN_141c27900(param_1,param_4);
  local_40 = FUN_141c27750(param_1,local_90);
  uVar2 = FUN_141c27280(param_1);
  local_b2 = FUN_140999030(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21b10(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbf90(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee910(param_4);
    local_38 = FUN_141be2110(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdcab0(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be97e0
 undefined8 FUN_141be97e0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c262a0(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c27780(param_1,local_a8);
      local_60 = FUN_141c27920(param_1,param_4);
      uVar2 = FUN_141c272c0(param_1);
      local_b8 = FUN_140999030(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c27920(param_1,param_4);
      local_70 = FUN_141c27780(param_1,local_a8);
      uVar2 = FUN_141c272c0(param_1);
      cVar1 = FUN_140999030(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc70(local_80);
  FUN_141bf2590(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2af60(param_1,local_20);
    cVar1 = FUN_141bf75c0(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee920(param_4);
      local_50 = FUN_141be2470(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdcb00(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8fa0(&local_90);
  }
  local_48 = FUN_141c27920(param_1,param_4);
  local_40 = FUN_141c27780(param_1,local_90);
  uVar2 = FUN_141c272c0(param_1);
  local_b2 = FUN_140999030(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21b60(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdc030(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee920(param_4);
    local_38 = FUN_141be2470(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdcb00(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141be9bf0
 undefined8 FUN_141be9bf0(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined8 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c26300(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c277b0(param_1,local_a8);
      local_60 = FUN_141c27940(param_1,param_4);
      uVar2 = FUN_141c27300(param_1);
      local_b8 = FUN_14044a540(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c27940(param_1,param_4);
      local_70 = FUN_141c277b0(param_1,local_a8);
      uVar2 = FUN_141c27300(param_1);
      cVar1 = FUN_14044a540(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becc80(local_80);
  FUN_141bf25d0(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2afd0(param_1,local_20);
    cVar1 = FUN_141bf7600(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141bee930(param_4);
      local_50 = FUN_141be27d0(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdcb50(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8fc0(&local_90);
  }
  local_48 = FUN_141c27940(param_1,param_4);
  local_40 = FUN_141c277b0(param_1,local_90);
  uVar2 = FUN_141c27300(param_1);
  local_b2 = FUN_14044a540(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21bb0(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdc0d0(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141bee930(param_4);
    local_38 = FUN_141be27d0(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdcb50(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea000
 undefined8 FUN_141bea000(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined1 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_141c26360(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c277e0(param_1,local_a8);
      local_60 = FUN_141c27960(param_1,param_4);
      uVar2 = FUN_141c27340(param_1);
      local_b8 = FUN_141bf9950(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c27960(param_1,param_4);
      local_70 = FUN_141c277e0(param_1,local_a8);
      uVar2 = FUN_141c27340(param_1);
      cVar1 = FUN_141bf9950(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_141becbf0(local_80);
  FUN_141bf2090(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_141c2b040(param_1,local_20);
    cVar1 = FUN_141bf73c0(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141beea80(param_4);
      local_50 = FUN_141be2b30(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdc830(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8d60(&local_90);
  }
  local_48 = FUN_141c27960(param_1,param_4);
  local_40 = FUN_141c277e0(param_1,local_90);
  uVar2 = FUN_141c27340(param_1);
  local_b2 = FUN_141bf9950(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21c00(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbc70(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141beea80(param_4);
    local_38 = FUN_141be2b30(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdc830(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea410
 undefined8 FUN_141bea410(undefined8 param_1,undefined8 param_2,char param_3,undefined8 param_4, undefined1 param_5)
{
  char cVar1;
  undefined8 uVar2;
  char local_b8;
  undefined1 local_b3;
  char local_b2;
  undefined1 local_b1;
  undefined1 local_b0 [8];
  undefined8 *local_a8;
  undefined8 *local_a0;
  uint local_98;
  undefined8 local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [16];
  
  local_30 = 0xfffffffffffffffe;
  local_80 = (longlong *)FUN_140a1b9b0(param_1);
  local_a0 = (undefined8 *)*local_80;
  local_a8 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a0 + 0x8));
  local_b8 = '\x01';
  while (*(char *)((longlong)local_a8 + 0x19) == '\0') {
    local_a0 = local_a8;
    if (param_3 == '\0') {
      local_68 = FUN_141c27810(param_1,local_a8);
      local_60 = FUN_141c27980(param_1,param_4);
      uVar2 = FUN_141c27380(param_1);
      local_b8 = FUN_141bf9990(uVar2,local_60,local_68);
    }
    else {
      local_78 = FUN_141c27980(param_1,param_4);
      local_70 = FUN_141c27810(param_1,local_a8);
      uVar2 = FUN_141c27380(param_1);
      cVar1 = FUN_141bf9990(uVar2,local_70,local_78);
      local_b8 = cVar1 == '\0';
      local_98 = (uint)(byte)local_b8;
    }
    if (local_b8 == '\0') {
      local_88 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_a8 + 0x10));
    }
    else {
      local_88 = (undefined8 *)*local_a8;
    }
    local_a8 = local_88;
  }
  uVar2 = FUN_140a14530(local_80);
  FUN_140a15890(&local_90,local_a0,uVar2);
  if (local_b8 != '\0') {
    uVar2 = FUN_140a1d600(param_1,local_20);
    cVar1 = FUN_140a16950(&local_90,uVar2);
    if (cVar1 != '\0') {
      local_b3 = 1;
      uVar2 = FUN_141beeab0(param_4);
      local_50 = FUN_141be2e90(param_1,local_18,1,local_a0,uVar2,param_5);
      FUN_141bdc880(param_2,local_50,&local_b3);
      return param_2;
    }
    FUN_141bf8ea0(&local_90);
  }
  local_48 = FUN_141c27980(param_1,param_4);
  local_40 = FUN_141c27810(param_1,local_90);
  uVar2 = FUN_141c27380(param_1);
  local_b2 = FUN_141bf9990(uVar2,local_40,local_48);
  if (local_b2 == '\0') {
    FUN_141c21c10(param_1,param_5);
    local_b0[0] = 0;
    FUN_141bdbd60(param_2,&local_90,local_b0);
  }
  else {
    local_b1 = 1;
    uVar2 = FUN_141beeab0(param_4);
    local_38 = FUN_141be2e90(param_1,local_10,local_b8,local_a0,uVar2,param_5);
    FUN_141bdc880(param_2,local_38,&local_b1);
  }
  return param_2;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea820
undefined8 FUN_141bea820(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea830
undefined8 FUN_141bea830(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea840
undefined8 FUN_141bea840(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea850
undefined8 FUN_141bea850(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea860
undefined8 FUN_141bea860(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea870
undefined8 FUN_141bea870(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea880
undefined8 FUN_141bea880(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea890
undefined8 FUN_141bea890(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea8a0
undefined8 FUN_141bea8a0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea8b0
undefined8 * FUN_141bea8b0(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c26030(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c27630(param_1,local_18);
    cVar1 = FUN_141c212f0(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea950
undefined8 * FUN_141bea950(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c26090(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c27660(param_1,local_18);
    cVar1 = FUN_141c21330(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bea9f0
undefined8 * FUN_141bea9f0(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c260f0(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c27690(param_1,local_18);
    cVar1 = FUN_141c21370(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beaa90
undefined8 * FUN_141beaa90(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c26390(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c277e0(param_1,local_18);
    cVar1 = FUN_141c21530(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beab30
undefined8 * FUN_141beab30(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c26150(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c276c0(param_1,local_18);
    cVar1 = FUN_141c213b0(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beabd0
undefined8 * FUN_141beabd0(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c261b0(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c276f0(param_1,local_18);
    cVar1 = FUN_141c213f0(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beac70
undefined8 * FUN_141beac70(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c26210(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c27720(param_1,local_18);
    cVar1 = FUN_141c21430(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bead10
undefined8 * FUN_141bead10(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c26270(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c27750(param_1,local_18);
    cVar1 = FUN_141c21470(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beadb0
undefined8 * FUN_141beadb0(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c262d0(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c27780(param_1,local_18);
    cVar1 = FUN_141c214b0(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beae50
undefined8 * FUN_141beae50(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141623bd0(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141623f00(param_1,local_18);
    cVar1 = FUN_141c21570(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beaef0
undefined8 * FUN_141beaef0(undefined8 param_1,undefined8 param_2)
{
  char cVar1;
  undefined8 uVar3;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_10 = (undefined8 *)*(longlong *)FUN_141c26330(param_1);
  local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_10 + 0x8));
  while (*(char *)((longlong)local_18 + 0x19) == '\0') {
    uVar3 = FUN_141c277b0(param_1,local_18);
    cVar1 = FUN_141c214f0(param_1,uVar3,param_2);
    if (cVar1 == '\0') {
      local_10 = local_18;
      local_18 = (undefined8 *)*local_18;
    }
    else {
      local_18 = (undefined8 *)(*(undefined8 *)((undefined1 *)local_18 + 0x10));
    }
  }
  return local_10;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beaf90
 longlong FUN_141beaf90(longlong param_1,longlong param_2,longlong param_3)
{
  undefined8 uVar1;
  undefined8 local_res8;
  undefined8 local_res18;
  
  local_res18 = param_3;
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    uVar1 = FUN_141beef40(local_res8);
    FUN_141bf6fa0(local_res18,uVar1);
    local_res18 = local_res18 + 0x10;
  }
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb000
void FUN_141beb000(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  
  local_res8 = param_1;
  local_res10 = param_2;
  local_res18[0] = param_3;
  FUN_141beaf90(local_res8,local_res10,local_res18[0],(FUN_141beb240(&local_res8,local_res18)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb050
 void FUN_141beb050(undefined8 param_1,undefined8 param_2)
{
  undefined1 local_18;
  
  FUN_141beb080(param_1,param_2,local_18);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb080
void FUN_141beb080(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb090
undefined1 FUN_141beb090(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb0c0
undefined1 FUN_141beb0c0(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb0f0
undefined1 FUN_141beb0f0(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb120
undefined1 FUN_141beb120(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb150
undefined1 FUN_141beb150(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb180
undefined1 FUN_141beb180(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb1b0
undefined1 FUN_141beb1b0(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb1e0
undefined1 FUN_141beb1e0(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb210
undefined1 FUN_141beb210(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb240
undefined1 FUN_141beb240(void)
{
  longlong lVar1;
  undefined1 *puVar2;
  undefined1 local_18 [16];
  
  puVar2 = local_18;
  for (lVar1 = 1; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return local_18[0];
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb270
void FUN_141beb270(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb290
void FUN_141beb290(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb2b0
void FUN_141beb2b0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb2d0
void FUN_141beb2d0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beb2f0
void FUN_141beb2f0(undefined8 *param_1,undefined8 param_2)
{
  *param_1 = param_2;
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141beb310
undefined8 FUN_141beb310(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  return (undefined8)((undefined8 (*)(...))0x141beb310ULL)(param_1,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141beb460
undefined8 FUN_141beb460(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  return (undefined8)((undefined8 (*)(...))0x141beb460ULL)(param_1,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141beb5b0
undefined8 FUN_141beb5b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  return (undefined8)((undefined8 (*)(...))0x141beb5b0ULL)(param_1,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141beb700
undefined8 FUN_141beb700(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  return (undefined8)((undefined8 (*)(...))0x141beb700ULL)(param_1,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141beb850
undefined8 FUN_141beb850(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  return (undefined8)((undefined8 (*)(...))0x141beb850ULL)(param_1,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141beb9a0
undefined8 FUN_141beb9a0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  return (undefined8)((undefined8 (*)(...))0x141beb9a0ULL)(param_1,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// MS2-FUNCTIONAL: forwards to the exe copy (translation did not compile)
// @0x141bebaf0
undefined8 FUN_141bebaf0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  return (undefined8)((undefined8 (*)(...))0x141bebaf0ULL)(param_1,param_2,param_3);
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebc40
undefined8 FUN_141bebc40(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebc50
undefined8 FUN_141bebc50(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebc60
undefined8 FUN_141bebc60(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebc70
undefined8 FUN_141bebc70(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebc80
undefined8 FUN_141bebc80(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0950(param_1);
  local_20 = FUN_141be0950(param_2);
  local_28 = FUN_141be09a0(local_res18,(FUN_141be0ae0(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb090(&local_30,&local_28);
  FUN_141beb270(&local_res18,(FUN_141bec090(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebd50
undefined8 FUN_141bebd50(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0960(param_1);
  local_20 = FUN_141be0960(param_2);
  local_28 = FUN_141be09b0(local_res18,(FUN_141be0b10(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb0c0(&local_30,&local_28);
  FUN_141beb290(&local_res18,(FUN_141bec120(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebe20
undefined8 FUN_141bebe20(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0970(param_1);
  local_20 = FUN_141be0970(param_2);
  local_28 = FUN_141be09c0(local_res18,(FUN_141be0b40(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb0f0(&local_30,&local_28);
  FUN_141beb2b0(&local_res18,(FUN_141bec1b0(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebef0
undefined8 FUN_141bebef0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0980(param_1);
  local_20 = FUN_141be0980(param_2);
  local_28 = FUN_141be09d0(local_res18,(FUN_141be0b70(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb120(&local_30,&local_28);
  FUN_141beb2d0(&local_res18,(FUN_141bec240(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bebfc0
undefined8 FUN_141bebfc0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0990(param_1);
  local_20 = FUN_141be0990(param_2);
  local_28 = FUN_141be09e0(local_res18,(FUN_141be0ba0(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb150(&local_30,&local_28);
  FUN_141beb2f0(&local_res18,(FUN_141bec2d0(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec090
undefined8 FUN_141bec090(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2b30(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    FUN_141bdea90(local_28,local_res8);
  }
  uVar1 = FUN_141c28e40(local_28);
  FUN_141bf5b20(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec120
undefined8 FUN_141bec120(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2b70(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x18) {
    FUN_141bdeaf0(local_28,local_res8);
  }
  uVar1 = FUN_141c28e60(local_28);
  FUN_141bf5b60(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec1b0
undefined8 FUN_141bec1b0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2bb0(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    FUN_141bdeb50(local_28,local_res8);
  }
  uVar1 = FUN_141c28e80(local_28);
  FUN_141bf5ba0(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec240
undefined8 FUN_141bec240(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2bf0(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    FUN_141bdebb0(local_28,local_res8);
  }
  uVar1 = FUN_141c28ea0(local_28);
  FUN_141bf5be0(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec2d0
undefined8 FUN_141bec2d0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2c30(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    FUN_141bdec10(local_28,local_res8);
  }
  uVar1 = FUN_141c28ec0(local_28);
  FUN_141bf5c20(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec360
undefined8 FUN_141bec360(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0950(param_1);
  local_20 = FUN_141be0950(param_2);
  local_28 = FUN_141be09a0(local_res18,(FUN_141be0ae0(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb180(&local_30,&local_28);
  FUN_141beb270(&local_res18,(FUN_141bec770(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec430
undefined8 FUN_141bec430(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0960(param_1);
  local_20 = FUN_141be0960(param_2);
  local_28 = FUN_141be09b0(local_res18,(FUN_141be0b10(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb1b0(&local_30,&local_28);
  FUN_141beb290(&local_res18,(FUN_141bec800(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec500
undefined8 FUN_141bec500(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0970(param_1);
  local_20 = FUN_141be0970(param_2);
  local_28 = FUN_141be09c0(local_res18,(FUN_141be0b40(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb1e0(&local_30,&local_28);
  FUN_141beb2b0(&local_res18,(FUN_141bec890(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec5d0
undefined8 FUN_141bec5d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0980(param_1);
  local_20 = FUN_141be0980(param_2);
  local_28 = FUN_141be09d0(local_res18,(FUN_141be0b70(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb210(&local_30,&local_28);
  FUN_141beb2d0(&local_res18,(FUN_141bec920(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec6a0
undefined8 FUN_141bec6a0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)
{
  undefined1 uVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  undefined1 local_37;
  undefined1 local_36 [6];
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_res18 = param_3;
  local_res20 = param_4;
  local_30 = FUN_141be0990(param_1);
  local_20 = FUN_141be0990(param_2);
  local_28 = FUN_141be09e0(local_res18,(FUN_141be0ba0(&local_30,&local_20)));
  local_18 = &local_37;
  uVar1 = FUN_141beb240(&local_30,&local_28);
  FUN_141beb2f0(&local_res18,(FUN_141bec9b0(local_30,local_20,local_28,local_res20,uVar1,*(undefined1 *)FUN_140177620(local_18,local_36))));
  return local_res18;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec770
undefined8 FUN_141bec770(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2b30(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    uVar1 = FUN_141beef00(local_res8);
    FUN_141bdec70(local_28,uVar1);
  }
  uVar1 = FUN_141c28e40(local_28);
  FUN_141bf5b20(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec800
undefined8 FUN_141bec800(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2b70(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x18) {
    uVar1 = FUN_141beef10(local_res8);
    FUN_141bdecd0(local_28,uVar1);
  }
  uVar1 = FUN_141c28e60(local_28);
  FUN_141bf5b60(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec890
undefined8 FUN_141bec890(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2bb0(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    uVar1 = FUN_141beef20(local_res8);
    FUN_141bded30(local_28,uVar1);
  }
  uVar1 = FUN_141c28e80(local_28);
  FUN_141bf5ba0(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec920
undefined8 FUN_141bec920(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2bf0(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    uVar1 = FUN_141beef30(local_res8);
    FUN_141bded90(local_28,uVar1);
  }
  uVar1 = FUN_141c28ea0(local_28);
  FUN_141bf5be0(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bec9b0
undefined8 FUN_141bec9b0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)
{
  undefined8 uVar1;
  longlong local_res8;
  undefined1 local_28 [40];
  
  FUN_141bf2c30(local_28,param_3,param_4);
  for (local_res8 = param_1; local_res8 != param_2; local_res8 = local_res8 + 0x10) {
    uVar1 = FUN_141beef40(local_res8);
    FUN_141bdedf0(local_28,uVar1);
  }
  uVar1 = FUN_141c28ec0(local_28);
  FUN_141bf5c20(local_28);
  return uVar1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beca40
undefined8 FUN_141beca40(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beca50
undefined8 FUN_141beca50(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beca60
undefined8 FUN_141beca60(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beca70
undefined8 FUN_141beca70(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beca80
undefined8 FUN_141beca80(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beca90
undefined8 FUN_141beca90(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becaa0
undefined8 FUN_141becaa0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becab0
undefined8 FUN_141becab0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becac0
undefined8 FUN_141becac0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becad0
undefined8 FUN_141becad0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becae0
undefined8 FUN_141becae0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becaf0
undefined8 FUN_141becaf0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb00
undefined8 FUN_141becb00(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb10
undefined8 FUN_141becb10(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb20
undefined8 FUN_141becb20(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb30
undefined8 FUN_141becb30(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb40
undefined8 FUN_141becb40(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb50
undefined8 FUN_141becb50(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb60
undefined8 FUN_141becb60(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb70
undefined8 FUN_141becb70(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb80
undefined8 FUN_141becb80(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becb90
undefined8 FUN_141becb90(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becba0
undefined8 FUN_141becba0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becbb0
undefined8 FUN_141becbb0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becbc0
undefined8 FUN_141becbc0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becbd0
undefined8 FUN_141becbd0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becbe0
undefined8 FUN_141becbe0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becbf0
undefined8 FUN_141becbf0(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc00
undefined8 FUN_141becc00(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc10
undefined8 FUN_141becc10(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc20
undefined8 FUN_141becc20(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc30
undefined8 FUN_141becc30(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc40
undefined8 FUN_141becc40(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc50
undefined8 FUN_141becc50(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc60
undefined8 FUN_141becc60(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc70
undefined8 FUN_141becc70(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc80
undefined8 FUN_141becc80(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becc90
undefined8 FUN_141becc90(undefined8 param_1)
{
  return param_1;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becca0
 void FUN_141becca0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee7e0(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beccf0
 void FUN_141beccf0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee7f0(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becd40
 void FUN_141becd40(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee800(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becd90
 void FUN_141becd90(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee810(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becde0
 void FUN_141becde0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee820(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bece30
 void FUN_141bece30(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee830(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bece80
 void FUN_141bece80(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee840(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beced0
 void FUN_141beced0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee850(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becf20
 void FUN_141becf20(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee860(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becf70
 void FUN_141becf70(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee870(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141becfc0
 void FUN_141becfc0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141bee880(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed010
 void FUN_141bed010(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141beea70(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed060
 void FUN_141bed060(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_140a14dd0(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed0b0
 void FUN_141bed0b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  
  *(undefined8 *)FUN_140159860(8,param_2) = *(undefined8 *)FUN_141beea80(param_3);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed100
void FUN_141bed100(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5)
{
  undefined1 local_48 [8];
  undefined1 *local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18 [24];
  
  local_20 = FUN_140159860(0x18,param_2);
  local_40 = local_48;
  local_38 = local_18;
  local_30 = FUN_140163dc0(local_40,(FUN_140162f40(param_5)));
  local_28 = (undefined8)(FUN_1401f03a0(local_38,(FUN_1401ef380(param_4))));
  FUN_141bdc170(local_20,*(undefined1 *)FUN_140162ef0(param_3),local_28,local_30);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed1b0
void FUN_141bed1b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5)
{
  undefined1 local_48 [8];
  undefined1 *local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18 [24];
  
  local_20 = FUN_140159860(0x18,param_2);
  local_40 = local_48;
  local_38 = local_18;
  local_30 = FUN_140163dc0(local_40,(FUN_140162f40(param_5)));
  local_28 = (undefined8)(FUN_1401f03a0(local_38,(FUN_1401ef380(param_4))));
  FUN_141bdc1c0(local_20,*(undefined1 *)FUN_140162ef0(param_3),local_28,local_30);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed260
void FUN_141bed260(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5)
{
  undefined1 local_48 [8];
  undefined1 *local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18 [24];
  
  local_20 = FUN_140159860(0x10,param_2);
  local_40 = local_48;
  local_38 = local_18;
  local_30 = FUN_140163dc0(local_40,(FUN_140162f40(param_5)));
  local_28 = (undefined8)(FUN_1401dbc50(local_38,(FUN_1401db5d0(param_4))));
  FUN_141bdc210(local_20,*(undefined1 *)FUN_140162ef0(param_3),local_28,local_30);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed310
void FUN_141bed310(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bdceb0(uVar1,(FUN_141beeb00(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed360
void FUN_141bed360(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bdcf10(uVar1,(FUN_141beeb10(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed3b0
void FUN_141bed3b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bdcf70(uVar1,(FUN_141beeb20(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed400
void FUN_141bed400(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5)
{
  undefined1 local_48 [8];
  undefined1 *local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18 [24];
  
  local_20 = FUN_140159860(0x28,param_2);
  local_40 = local_48;
  local_38 = local_18;
  local_30 = FUN_140163dc0(local_40,(FUN_140162f40(param_5)));
  local_28 = (undefined8)(FUN_141122c00(local_38,(FUN_14111d050(param_4))));
  FUN_141bdc580(local_20,*(undefined1 *)FUN_140162ef0(param_3),local_28,local_30);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed4b0
void FUN_141bed4b0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5)
{
  undefined1 local_48 [8];
  undefined1 *local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18 [24];
  
  local_20 = FUN_140159860(0x10,param_2);
  local_40 = local_48;
  local_38 = local_18;
  local_30 = FUN_140163dc0(local_40,(FUN_140162f40(param_5)));
  local_28 = (undefined8)(FUN_141122c00(local_38,(FUN_14111d050(param_4))));
  FUN_141bdc5d0(local_20,*(undefined1 *)FUN_140162ef0(param_3),local_28,local_30);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed560
void FUN_141bed560(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5)
{
  undefined1 local_48 [8];
  undefined1 *local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18 [24];
  
  local_20 = FUN_140159860(0x18,param_2);
  local_40 = local_48;
  local_38 = local_18;
  local_30 = FUN_140163dc0(local_40,(FUN_140162f40(param_5)));
  local_28 = (undefined8)(FUN_14133e9c0(local_38,(FUN_14133e6f0(param_4))));
  FUN_141bdb890(local_20,*(undefined1 *)FUN_140162ef0(param_3),local_28,local_30);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed610
void FUN_141bed610(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4, undefined8 param_5)
{
  undefined1 local_48 [8];
  undefined1 *local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18 [24];
  
  local_20 = FUN_140159860(0x18,param_2);
  local_40 = local_48;
  local_38 = local_18;
  local_30 = FUN_140163dc0(local_40,(FUN_140162f40(param_5)));
  local_28 = (undefined8)(FUN_1404459d0(local_38,(FUN_140442200(param_4))));
  FUN_141bdc6c0(local_20,*(undefined1 *)FUN_140162ef0(param_3),local_28,local_30);
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed6c0
void FUN_141bed6c0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bf31d0(uVar1,(FUN_141bee940(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed710
void FUN_141bed710(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bf3170(uVar1,(FUN_141beeae0(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed760
void FUN_141bed760(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x18,param_2);
  FUN_141bf3280(uVar1,(FUN_141bee950(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed7b0
void FUN_141bed7b0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x18,param_2);
  FUN_141bf3230(uVar1,(FUN_141beeaf0(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed800
void FUN_141bed800(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_140963ff0(uVar1,(FUN_141bee970(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed850
void FUN_141bed850(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bf14d0(uVar1,(FUN_141beeb30(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed8a0
void FUN_141bed8a0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_140964030(uVar1,(FUN_141bee980(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed8f0
void FUN_141bed8f0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_140964030(uVar1,(FUN_141beeaa0(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed940
void FUN_141bed940(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bf1550(uVar1,(FUN_141beeb40(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed990
void FUN_141bed990(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bf1800(uVar1,(FUN_141bee990(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bed9e0
void FUN_141bed9e0(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x10,param_2);
  FUN_141bf17d0(uVar1,(FUN_141beeb50(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beda30
void FUN_141beda30(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(0x20,param_2);
  FUN_141bf4660(uVar1,(FUN_141beeab0(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141beda80
void FUN_141beda80(undefined8 param_1,undefined8 param_2,undefined8 param_3)
{
  undefined8 uVar1;
  
  uVar1 = FUN_140159860(8,param_2);
  FUN_1408b6b20(uVar1,(FUN_140af5a50(param_3)));
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedad0
void FUN_141bedad0(void)
{
  return;
}

// MS2-FUNCTIONAL: translated from the decompile; exact bytes not attempted
// @0x141bedae0
void FUN_141bedae0(void)
{
  return;
}
