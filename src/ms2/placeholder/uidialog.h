// uidialog.h - PLACEHOLDER for UIDialog (RTTI .?AVUIDialog@@, 0x178 bytes), the base of ~320 dialogs. NOT an
// original header. Base UIObject (uiobject.h) -> UISwfEntity (src/ms2/gfxui/uiswfentity.h). Primary vftable
// 0x142fa1638 (84 slots: UIObject's 52 + 52..83), IMessageListener-in-UIDialog 0x142fa18e0. Ctor 0x1419231f0, dtor
// 0x141923420 (??_G 0x141927340). Its unit is ?\uidialog.cpp (0x14191c7d0-0x141927f70, 253 functions; it also holds
// UIBeautyShopDevDialog).
//
// Complete slot list. Signatures come from the /Od prologues of UIDialog's implementations and of every override in
// the 318 derived classes (work/uibase/slotsig.py UIDialog 52); returns from the base implementations. Slots 0-51 are
// declared in uiswfentity.h / uiobject.h; only UIDialog's overrides are repeated here. Names follow Ghidra
// (vfunc_<slot>, FUN_<va>) so a derived class's decompile maps 1:1; comments say what each one does.
//
// Ownership: wave-1 foundation (docs/RECOVERY.md section 12). The slot list and the layout are complete: unit agents
// do not change them. Agents MAY append non-virtual member declarations to the marked section at the end of the
// public part (one line each, `FUN_<va>` + comment, sorted by address) when their unit calls one.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiobject.h"

class UIDialog : public UIObject
{
public:
    UIDialog();                                                             // 0x1419231f0
    virtual ~UIDialog();                                                    //  0 0x141923420 (??_G 0x141927340)
    virtual CString vfunc_1();                                              //  1 0x1419234e0
    virtual int vfunc_4();                                                  //  4 0x1419237c0
    virtual int vfunc_5();                                                  //  5 0x141923a70
    virtual int vfunc_6();                                                  //  6 0x1419237a0 returns m_74
    virtual void vfunc_8(int nVisible);                                     //  8 0x141924780
    virtual int vfunc_9();                                                  //  9 0x1419247b0
    virtual int vfunc_13();                                                 // 13 0x141925900
    virtual bool vfunc_17();                                                // 17 0x1419254f0
    virtual void vfunc_18();                                                // 18 0x141925330
    virtual void OnLoadComplete();                                          // 22 0x141925130
    virtual void vfunc_26();                                                // 26 0x141925250
    virtual void vfunc_27();                                                // 27 0x1419252f0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x141925a50
    virtual void vfunc_32(void* p, float x, float y);                       // 32 0x141925c10
    virtual void vfunc_41(const Scaleform::GFx::Value& root);               // 41 0x141925c50
    virtual void vfunc_42(GfxException* pException);                        // 42 0x141925d60
    virtual void vfunc_43();                                                // 43 0x1419257b0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);               // IMessageListener 0 0x141925a00

    virtual int vfunc_52();                                                 // 52 0x141923530 has an "m_dragBar" child
    virtual int vfunc_53(void* pCfg);                                       // 53 0x141923c90 save "transform" (x/y/width/height/rate/editAlign); returns 1
    virtual int vfunc_54(void* pCfg);                                       // 54 0x141923ed0 load "transform"; returns 1
    virtual int vfunc_55();                                                 // 55 0x1419247d0 m_68 && m_c0 == 2 (closed)
    virtual int vfunc_56();                                                 // 56 0x141924810 FUN_1419244c0(0)
    virtual int vfunc_57();                                                 // 57 0x141924830 m_84
    virtual int vfunc_58();                                                 // 58 0x141924850 m_88
    virtual int vfunc_59();                                                 // 59 0x141924870 m_158
    virtual int vfunc_60();                                                 // 60 0x141924890 m_158 && m_15c
    virtual void vfunc_61(int n);                                           // 61 0x1419248e0 m_8c = n
    virtual void vfunc_62(int nWidth, int nHeight);                         // 62 0x141924900 resize the ASDialog (clamped)
    virtual void vfunc_63(int n);                                           // 63 0x1419249d0 m_6c = n
    virtual int vfunc_64();                                                 // 64 0x1419249f0 m_6c
    virtual int vfunc_65();                                                 // 65 0x141924a10 Open: vfunc_55/vfunc_73 checks, load swf, register; 1 = opened
    virtual void vfunc_66();                                                // 66 0x141924cb0 remember the position (m_d8/m_dc)
    virtual void vfunc_67();                                                // 67 0x141924d70 Close (m_68 = 1)
    virtual void vfunc_68();                                                // 68 0x141924df0 close request ("Close Dialog [{0}]")
    virtual void vfunc_69();                                                // 69 0x141924fa0 if (!vfunc_71()) vfunc_67()
    virtual void vfunc_70();                                                // 70 0x141924fe0 if (!vfunc_71()) vfunc_67()
    virtual int vfunc_71();                                                 // 71 0x141925020 returns 0
    virtual void vfunc_72();                                                // 72 0x141925030 empty
    virtual int vfunc_73();                                                 // 73 0x141925040 can open (checks; vfunc_75)
    virtual int vfunc_74(int a1, void* p2, void* p3);                       // 74 0x141925100 returns 0
    virtual bool vfunc_75();                                                // 75 0x141925120 returns true
    virtual void vfunc_76();                                                // 76 0x141925670 m_70 = 1
    virtual void vfunc_77();                                                // 77 0x141925690 if (m_70) {...; m_70 = 0; m_74 = 1; vfunc_4()}
    virtual void vfunc_78();                                                // 78 0x141925720 unregister from the manager (m_e0)
    virtual void vfunc_79(void* p);                                         // 79 0x1419259c0 empty
    virtual void vfunc_80(void* p);                                         // 80 0x1419259e0 empty
    virtual void vfunc_81();                                                // 81 0x141925be0 empty
    virtual int vfunc_82();                                                 // 82 0x141925bf0 returns -1
    virtual void vfunc_83();                                                // 83 0x141925dc0 m_74 = 0

    // Non-virtual members (signatures from the prologues; this = UIDialog*).
    void FUN_1419235d0();                                   // ASWindow "setTopMostLayer"
    void FUN_141923680(int n);                              // ASWindow FUN_1422e61f0(n)
    void FUN_141923710(int n);                              // ASWindow FUN_1422e6230(n)
    void FUN_141924170(int n);                              // m_c4 = n (open/close tweens)
    void FUN_141924190();                                   // close part 1 (called by vfunc_67)
    void FUN_141924330(int n);                              // close part 2 (called by vfunc_67 with m_c4)
    int FUN_141924470();                                    // m_158 && m_160
    int FUN_1419244c0(int nBit);                            // m_a0 flag test
    void FUN_141924510();                                   // stop "m_openTween"
    void FUN_141924680();
    void FUN_1419246f0();                                   // vfunc_55() ? vfunc_70() : FUN_141924680()
    int FUN_141924740();                                    // !m_68 && !m_c0
    void FUN_141925de0();                                   // vfunc_70()
    void FUN_141925e70(int nBit, int bSet);                 // m_a0 flag set
    void FUN_1419265e0(const CString& str);                 // m_170 = str
    bool FUN_141926960();                                   // m_168
    void FUN_141926980(bool b);                             // m_168 = b
    // ---- agents: append further non-virtual UIDialog members below this line (sorted by address) ----
    void FUN_141925ec0(CString strName);                     // bind close button (UILoginNotice)
    void FUN_141925fa0(CString strName);                     // bind drag bar (UIDungeonPopupRewardDialog)
    int FUN_141924630();                                    // vfunc_55() == 0 (UICoupleDanceEventDialog)
    void FUN_141904ab0(const int* pnLayer) { m_e0 = *pnLayer; }    // 0x141904ab0 (inline, uicommon.cpp)
    void FUN_1419260d0(CString strName, int n);             // takes the child name by value (UIDungeonLobby: "m_webGuideButton", 0)

protected:
    MS2_LAYOUT_FRIEND;
    int m_68;                           // +0x68 1; 1 = closed (vfunc_67 sets, vfunc_65 clears)
    int m_6c;                           // +0x6c vfunc_63/vfunc_64
    int m_70;                           // +0x70 vfunc_76/vfunc_77
    int m_74;                           // +0x74 "editAlign"; vfunc_6
    int m_78;                           // +0x78
    int m_7c;                           // +0x7c 1; 0 = also save width/height
    int m_80;                           // +0x80 1; save/load the "transform"
    int m_84;                           // +0x84 vfunc_57
    int m_88;                           // +0x88 vfunc_58
    int m_8c;                           // +0x8c 1; vfunc_61
    void* m_90;                         // +0x90 MS2Ptr<?> (16 bytes, pointer at +0x98; ctor 0x140e44ca0, dtor 0x140e44f20)
    void* m_98;                         // +0x98   ... the AS object (m_openTween lives here)
    unsigned int m_a0;                  // +0xa0 flags (ctor 0x1402a5610 zeroes 4 bytes; test 0x1402a8f80, set 0x1402a8e70)
    void* m_a8;                         // +0xa8 std::vector<?> (ctor 0x141000210, dtor 0x141000690): first
    void* m_b0;                         // +0xb0   last
    void* m_b8;                         // +0xb8   end
    int m_c0;                           // +0xc0 2; open state (0 open, 2 closed)
    int m_c4;                           // +0xc4 open/close tweens enabled (FUN_141924170)
    CString m_c8;                       // +0xc8
    CString m_d0;                       // +0xd0
    float m_d8;                         // +0xd8 remembered x (8-byte point, copy ctor 0x140db9c80; default 0x143b02320)
    float m_dc;                         // +0xdc remembered y
    int m_e0;                           // +0xe0 4; manager layer (FUN_1422d4780/FUN_1422d48f0)
    void* m_e8;                         // +0xe8 TiXmlDocument (0x70 bytes, +0xe8..+0x158), opaque
    void* m_f0;
    void* m_f8;
    void* m_100;
    void* m_108;
    void* m_110;
    void* m_118;
    void* m_120;
    void* m_128;
    void* m_130;
    void* m_138;
    void* m_140;
    void* m_148;
    void* m_150;
    int m_158;                          // +0x158 vfunc_59
    int m_15c;                          // +0x15c
    int m_160;                          // +0x160
    int m_164;                          // +0x164 nonzero: register in the global dialog list (0x143af2258)
    bool m_168;                         // +0x168 1; FUN_141926960/FUN_141926980
    CString m_170;                      // +0x170 FUN_1419265e0
};
MS2_CHECK_SIZE(UIDialog, 0x178);
MS2_CHECK_OFFSET(UIDialog, m_68, 0x68);
MS2_CHECK_OFFSET(UIDialog, m_90, 0x90);
MS2_CHECK_OFFSET(UIDialog, m_a0, 0xa0);
MS2_CHECK_OFFSET(UIDialog, m_a8, 0xa8);
MS2_CHECK_OFFSET(UIDialog, m_c0, 0xc0);
MS2_CHECK_OFFSET(UIDialog, m_c8, 0xc8);
MS2_CHECK_OFFSET(UIDialog, m_d8, 0xd8);
MS2_CHECK_OFFSET(UIDialog, m_e0, 0xe0);
MS2_CHECK_OFFSET(UIDialog, m_e8, 0xe8);
MS2_CHECK_OFFSET(UIDialog, m_158, 0x158);
MS2_CHECK_OFFSET(UIDialog, m_168, 0x168);
MS2_CHECK_OFFSET(UIDialog, m_170, 0x170);
