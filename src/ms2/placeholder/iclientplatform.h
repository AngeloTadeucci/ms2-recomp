// iclientplatform.h - PLACEHOLDER for IClientPlatform (RTTI .?AVIClientPlatform@@, vftable 0x142e10008, 78 slots).
// NOT an original header. The publisher platform interface (base impl CClientPlatformBase 0x142e10280, the Nexon impl
// 0x142e10aa0) that client\ms2\ms2clientplatform.cpp hands out. Only the slot types CGameApp::InitInstance (?\ms2.cpp)
// proves are typed; the rest are `void()` stand-ins. Other units use their own views (networkservice.h
// Unk_NetworkCallbacks, gamesocket.cpp Unk_140d86260).
#pragma once

#include "ms2/ms2layout.h"

class IClientPlatform
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual int vfunc_4();                                  // 0x20: the authentication result (1 ok, 3 cancelled)
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22(int nCode, const char* pszFormat, ...);   // 0xb0: a startup step report ("GameInit", ...)
    virtual void vfunc_23(int nCode, const char* pszFormat, ...);   // 0xb8
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
};
MS2_CHECK_SIZE(IClientPlatform, 8);

// The live platform (0x140d86260; other units declare it under its FUN_ name with their own view type).
IClientPlatform* GetClientPlatform();
