// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Static market filter labels and controller data.
// MS2-UNIT: unit_14011d8d0
// MS2-RANGE: 0x14011d8d0-0x14011dbe0 .text$di
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include <new>

extern "C" char DAT_143af6980, DAT_143af6988, DAT_143af6990, DAT_143af6998;
extern "C" char DAT_143af69a0, DAT_143af69a8, DAT_143af69b0, DAT_143af69b8, DAT_143af69c0;
extern "C" char DAT_143af69d0, DAT_143af6a20, DAT_143af6a28, DAT_143af6a30, DAT_143af6a38;
extern "C" char DAT_143af6a40, DAT_143af6a48, DAT_143af6a50, DAT_143af6a58, DAT_143af6a60;
extern "C" char DAT_143af6a70, DAT_143af6ac0;
extern void FUN_142cc2950();
extern void FUN_142cc2980();
extern void FUN_142cc29a0();
extern void FUN_142cc29c0();
extern void FUN_142cc29e0();
extern void FUN_142cc2a10();
extern void FUN_142cc2a30();
extern void FUN_142cc2a50();
extern void FUN_142cc2a70();
extern void FUN_1402a9d70(void*, int, float, float, float, int);

static void SetText(char& storage, const char* value)
{
    new (&storage) CStringA(value);
}

// @0x14011d8d0
void FUN_14011d8d0()
{
    SetText(DAT_143af6990, "None");
    SetText(DAT_143af6998, "Buy");
    SetText(DAT_143af69a0, "Like");
    SetText(DAT_143af69a8, "PriceLow");
    SetText(DAT_143af69b0, "PriceHigh");
    SetText(DAT_143af69b8, "Create");
    SetText(DAT_143af69c0, "EnumEnd");
    atexit(FUN_142cc2950);
}

// @0x14011d990
void FUN_14011d990()
{
    SetText(DAT_143af6988, "skill");
    atexit(FUN_142cc2980);
}

// @0x14011d9c0
void FUN_14011d9c0()
{
    SetText(DAT_143af6980, "stun");
    atexit(FUN_142cc29a0);
}

// @0x14011d9f0
void FUN_14011d9f0()
{
    FUN_1402a9d70(&DAT_143af69d0, 0x11, 0.75f, 0.25f, 2.25f, 10);
    atexit(FUN_142cc29c0);
}

// @0x14011da40
void FUN_14011da40()
{
    SetText(DAT_143af6a30, "None");
    SetText(DAT_143af6a38, "Buy");
    SetText(DAT_143af6a40, "Like");
    SetText(DAT_143af6a48, "PriceLow");
    SetText(DAT_143af6a50, "PriceHigh");
    SetText(DAT_143af6a58, "Create");
    SetText(DAT_143af6a60, "EnumEnd");
    atexit(FUN_142cc29e0);
}

// @0x14011db00
void FUN_14011db00()
{
    SetText(DAT_143af6a28, "skill");
    atexit(FUN_142cc2a10);
}

// @0x14011db30
void FUN_14011db30()
{
    SetText(DAT_143af6a20, "stun");
    atexit(FUN_142cc2a30);
}

// @0x14011db60
void FUN_14011db60()
{
    FUN_1402a9d70(&DAT_143af6a70, 0x11, 0.75f, 0.25f, 2.25f, 10);
    atexit(FUN_142cc2a50);
}

// @0x14011dbb0
void FUN_14011dbb0()
{
    new (&DAT_143af6ac0) UICommon::CMyPCKeyInputController();
    atexit(FUN_142cc2a70);
}
