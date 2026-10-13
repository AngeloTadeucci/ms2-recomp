// uiswfentity.h - PLACEHOLDER for UISwfEntity (RTTI .?AVUISwfEntity@@, 0x68 bytes). NOT an original header.
// Bases: CPtred (+0x00), IMessageListener (+0x18). Primary vftable 0x1431129c0 (47 slots), IMessageListener-in-
// UISwfEntity vftable 0x143112b40. No constructor found in the exe (abstract use only through UIObject).
//
// Ownership: shared placeholder (docs/RECOVERY.md). Every slot is declared in vftable order so derived vftables
// come out right; unknown signatures are `void vfunc_N()`. Change a slot's signature only from evidence (an
// override or a call site), and keep the slot comment (index, exe address of UISwfEntity's implementation).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/imessagelistener.h"

class UISwfEntity : public CPtred, public IMessageListener
{
public:
    virtual ~UISwfEntity();                                                                             //  0 0x1422dcb70
    virtual CString vfunc_1();                                                                          //  1 0x1422db670
    virtual void vfunc_2();                                                                             //  2 0x1422db6c0
    virtual void vfunc_3();                                                                             //  3 0x1422db6d0
    virtual void vfunc_4();                                                                             //  4 0x1422dbac0
    virtual void vfunc_5();                                                                             //  5 0x1422dbad0
    virtual void vfunc_6();                                                                             //  6 0x1422dbae0
    virtual void vfunc_7();                                                                             //  7 0x1422dbaf0
    virtual void vfunc_8();                                                                             //  8 0x1422dbc20
    virtual void vfunc_9();                                                                             //  9 0x1422dbcc0
    virtual void vfunc_10();                                                                            // 10 0x1422dc4d0
    virtual void vfunc_11();                                                                            // 11 0x1422dc4e0
    virtual void vfunc_12();                                                                            // 12 0x1422dc4f0
    virtual int vfunc_13();                                                                             // 13 0x1422dc500
    virtual void vfunc_14();                                                                            // 14 0x1422dc510
    virtual void vfunc_15();                                                                            // 15 0x1422dc520
    virtual void vfunc_16();                                                                            // 16 0x1422dc530
    virtual bool vfunc_17();                                                                            // 17 0x1422dc540
    virtual void vfunc_18();                                                                            // 18 0x1422dc550
    virtual void vfunc_19();                                                                            // 19 0x1422dc580
    virtual void OnLoadInit();                                                                          // 20 0x1422dc610
    virtual void vfunc_21();                                                                            // 21 0x1422dc620
    virtual void OnLoadComplete();                                                                      // 22 0x1422dc630
    virtual void vfunc_23();                                                                            // 23 0x1422dc680
    virtual void vfunc_24();                                                                            // 24 0x1422dc6a0
    virtual void vfunc_25();                                                                            // 25 0x1422dc6c0
    virtual void vfunc_26();                                                                            // 26 0x1422dc6f0
    virtual void vfunc_27();                                                                            // 27 0x1422dc700
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs); // 28 0x1422dc710
    virtual void vfunc_29();                                                                            // 29 0x1422dc730
    virtual void vfunc_30(const CString& a1, const CString& a2, const CString& a3);                     // 30 0x1422dc750
    virtual void vfunc_31(const CString& a1, float a2, const void* a3);                                 // 31 0x1422dc770
    virtual void vfunc_32();                                                                            // 32 0x1422dc7b0
    virtual void vfunc_33();                                                                            // 33 0x1422dc7d0
    virtual void vfunc_34();                                                                            // 34 0x1422dc7f0
    virtual void vfunc_35();                                                                            // 35 0x1422dc810
    virtual void vfunc_36();                                                                            // 36 0x1422dc830
    virtual void vfunc_37();                                                                            // 37 0x1422dc850
    virtual void vfunc_38();                                                                            // 38 0x1422dc870
    virtual void vfunc_39();                                                                            // 39 0x1422dc890
    virtual void vfunc_40();                                                                            // 40 0x1422dc8b0
    virtual void vfunc_41();                                                                            // 41 0x1422dc8c0
    virtual void vfunc_42();                                                                            // 42 0x1422dc930
    virtual void vfunc_43();                                                                            // 43 0x1422dc950
    virtual void vfunc_44();                                                                            // 44 0x1422dc960
    virtual void vfunc_45();                                                                            // 45 0x1422dca20
    virtual void vfunc_46();                                                                            // 46 0x1422dca40

    // IMessageListener (vftable at +0x18; this = the IMessageListener subobject)
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);                                          //  0 0x1422dc790

    // Returns the AS child `strName` of this entity's movie (COMDAT template; 0x14135b280 for T = Unk_ASVideoPlayer).
    template <class T> MS2Ptr<T> GetChild(const CString& strName);

    void FUN_1422dbf00(int a1, int a2, int a3);     // called with (m_2c, 0, 0) to start showing the entity?
    void FUN_1422dc080();
    int FUN_1422dc2d0();

protected:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0xc];
    int m_2c;                           // +0x2c set to 0x21 by UICutSceneMovie's ctor (layer/depth?)
    MS2Ptr<AScript> m_30;               // +0x30 the entity's root AS object (movie)
    char m_pad_40[0xc];
    int m_4c;                           // +0x4c nonzero once the movie is loaded?
    int m_50;                           // +0x50
    char m_pad_54[0x14];
};
MS2_CHECK_SIZE(UISwfEntity, 0x68);
MS2_CHECK_OFFSET(UISwfEntity, m_2c, 0x2c);
MS2_CHECK_OFFSET(UISwfEntity, m_30, 0x30);
MS2_CHECK_OFFSET(UISwfEntity, m_4c, 0x4c);
MS2_CHECK_OFFSET(UISwfEntity, m_50, 0x50);
