// functioncubeobject.h - the housing "function cube" objects (client\ms2\functioncubeobject.cpp, header name assumed):
// CFunctionCubeObject (a placed cube that does something when used: a sit/interact state machine with cube-state
// sounds and effects) and its subclasses CHomemadeCubeObject, CBreedingCubeObject, CFarmingCubeObject and
// CNurturingCubeObject, the FunctionCubeData they hold, and the CFunctionCubeService that creates them.
// All five objects are CPtred (+0) with the text-key listener CGlobalKeyTextCallback (+0x18, secondary vftable).
#pragma once

#include <afxtempl.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include <egf/EntityID.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/cbasecollision.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/client/ms2/animationcallbackmanager.h"      // CGlobalKeyTextCallback
#include "ms2/client/ms2/cubespawnobject.h"               // Unk_EntRef

// The interaction box: a debug-visible box collision (class of an unrecovered unit; only the ctor and the fields touched).
class CBoxCollision : public CBaseCollision
{
public:
    CBoxCollision();                                              // 0x140ada4c0
    virtual void vfunc_5();
    virtual float vfunc_6();
    Unk_StreamPoint m_ptBox;                                      // +0x78
    char m_pad_84[0x150 - 0x84];
};
MS2_CHECK_SIZE(CBoxCollision, 0x150);
class FunctionCubeData;
class Unk_Entity;



// 0x18-byte option block of the data row (FunctionCubeData +0xd0): int 0, short 1 at +4, int 0, float 0, int 0.
struct Unk_FcOptions
{
    Unk_FcOptions();                                              // 0x140708280
    int m_n0;                                                     // +0x00
    short m_n4;                                                   // +0x04
    int m_n8;                                                     // +0x08
    float m_fC;                                                   // +0x0c
    int m_n10;                                                    // +0x10
    int m_n14;                                                    // +0x14
};
MS2_CHECK_SIZE(Unk_FcOptions, 0x18);

// Per-state string lists: the animations (several per state) and the sound of each of the 6 cube states.
typedef ATL::CAtlArray<CString> Unk_FcStrList;
typedef ATL::CAtlArray<Unk_FcStrList> Unk_FcStrListList;

// A text pair + number (FunctionCubeData +0x118): copy ctor 0x14122da50, assign 0x14122df20.
struct Unk_FcSkillText
{
    Unk_FcSkillText();                                            // 0x140708950
    CString m_strA;                                               // +0x00
    CString m_strB;                                               // +0x08
    int m_nValue;                                                 // +0x10
};
MS2_CHECK_SIZE(Unk_FcSkillText, 0x18);

// The object's data row, copied from the cube table row when the object is created. Heap 0x138.
// vftable 0x142ec4d50 (1 slot), scalar deleting dtor 0x14122e2c0, ctor 0x14122d840, dtor 0x14122dbb0.
class FunctionCubeData : public CPtred
{
public:
    FunctionCubeData();                                           // 0x14122d840
    virtual ~FunctionCubeData();                                  // 0x14122dbb0

    int m_nCubeId;                                                // +0x18
    int m_bBuff;                                                  // +0x1c "Buy"-like flag (1 for kind 3/9 with sub 1)
    int m_bLike;                                                  // +0x20
    int m_nKind;                                                  // +0x24
    int m_nSubKind;                                               // +0x28
    int m_nSub;                                                   // +0x2c
    int m_nEffect;                                                // +0x30
    int m_n34;                                                    // +0x34
    Unk_FcStrListList m_anims;                                    // +0x38 per-state animation name lists (6 states)
    Unk_FcStrList m_sounds;                                       // +0x58 per-state sound names (6 states)
    int m_aAnim[3];                                               // +0x78
    int m_n84;                                                    // +0x84
    CString m_strModel;                                           // +0x88
    int m_n90;                                                    // +0x90
    CString m_strStr98;                                           // +0x98
    Unk_StreamPoint m_vA0;                                               // +0xa0
    Unk_StreamPoint m_vAC;                                               // +0xac
    CString m_strB8;                                              // +0xb8
    CString m_strC0;                                              // +0xc0
    CString m_strC8;                                              // +0xc8
    Unk_FcOptions m_opt;                                          // +0xd0
    int m_nE8;                                                    // +0xe8
    int m_nEC;                                                    // +0xec
    int m_nF0;                                                    // +0xf0
    int m_nF4;                                                    // +0xf4
    int m_nF8;                                                    // +0xf8
    int m_nFC;                                                    // +0xfc
    int m_n100;                                                   // +0x100
    int m_n104;                                                   // +0x104
    CString m_str108;                                             // +0x108
    int m_n110;                                                   // +0x110
    Unk_FcSkillText m_skill;                                      // +0x118
    CStringW m_strNotice;                                         // +0x130
};
MS2_CHECK_SIZE(FunctionCubeData, 0x138);

// ---- unit-local views of exe classes this unit calls into ----

// The cube table row an object is built from (only the columns the objects copy).
struct Unk_FcRow
{
    int m_n0;                                                     // +0x00
    int m_nCubeId;                                                // +0x04
    int m_nSub;                                                   // +0x08
    int m_nState;                                                 // +0x0c initial state
    int m_nKind;                                                  // +0x10
    int m_nSubKind;                                               // +0x14
    int m_nEffect;                                                // +0x18
    int m_nE8;                                                    // +0x1c
    int m_nEC;                                                    // +0x20
    int m_nF0;                                                    // +0x24
    int m_nF4;                                                    // +0x28
    int m_nF8;                                                    // +0x2c
    int m_n30;                                                    // +0x30
    int m_n84;                                                    // +0x34
    char m_pad_38[8];
    Unk_FcStrList m_anims;                                        // +0x40 one animation name per state
    Unk_FcStrList m_sounds;                                       // +0x60 one sound name per state
    int m_aAnim[3];                                               // +0x80
    char m_pad_8c[0x110 - 0x8c];
    CString m_strModel;                                           // +0x110
    int m_n118;                                                   // +0x118
    CString m_strStr98;                                           // +0x120
    Unk_StreamPoint m_vA0;                                               // +0x128
    Unk_StreamPoint m_vAC;                                               // +0x134
    CString m_strB8;                                              // +0x140
    CString m_strC0;                                              // +0x148
    CString m_strC8;                                              // +0x150
    Unk_FcOptions m_opt;                                          // +0x158
    char m_pad_170[0x280 - 0x170];
    Unk_FcSkillText m_skill;                                      // +0x280
    CStringW m_strNotice;                                         // +0x298
};
MS2_CHECK_OFFSET(Unk_FcRow, m_anims, 0x40);
MS2_CHECK_OFFSET(Unk_FcRow, m_aAnim, 0x80);
MS2_CHECK_OFFSET(Unk_FcRow, m_strModel, 0x110);
MS2_CHECK_OFFSET(Unk_FcRow, m_opt, 0x158);
MS2_CHECK_OFFSET(Unk_FcRow, m_skill, 0x280);
MS2_CHECK_OFFSET(Unk_FcRow, m_strNotice, 0x298);

// Popups the objects own (classes of other units; only the constructors and the setters used here).
class UIBootyPopup : public CPtred
{
public:
    UIBootyPopup();                                               // 0x141031430
    char m_pad_18[0x90 - 0x18];
};
MS2_CHECK_SIZE(UIBootyPopup, 0x90);
class UIUGCCubeNoticePopup : public CPtred
{
public:
    UIUGCCubeNoticePopup();                                       // 0x140fb49b0
    char m_pad_18[0x98 - 0x18];
};
MS2_CHECK_SIZE(UIUGCCubeNoticePopup, 0x98);

// The message a function cube is created from: an embedded sub object at +8 whose slot 3 yields the state.
class Unk_FcStateSrc
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual int vfunc_3();                                        // current state
};
struct Unk_FcMsg
{
    void* m_unk0;                                                 // +0x00
    Unk_FcStateSrc m_src;                                         // +0x08
};

// The state message vfunc_14 reads (FUN_14112e290 = its state field at +0x38).
class Unk_FcStateMsg : public CPtred
{
public:
    int FUN_14112e290();                                          // state
    char m_pad_18[0x20];
    int m_nState;                                                 // +0x38
};

// 0x18-byte sound/effect request (CeRequest-like, 0x78): name, type, then a 0x68 block. See FUN_1411a49c0.
struct Unk_FcSoundReq
{
    CString m_strName;                                            // +0x00
    int m_nType;                                                  // +0x08
    int m_nPad0c;                                                 // +0x0c
    char m_unk[0x68];                                             // +0x10 (constructed by FUN_1409fabf0)
};

// ---- the base class ----
// 0xb0 bytes. vftable 0x142ec4d60 (16 slots), listener vftable 0x142ec4de8 (EndOfSequence overridden).
class CFunctionCubeObject : public CPtred, public CGlobalKeyTextCallback
{
public:
    CFunctionCubeObject();                                        // 0x141225080
    virtual ~CFunctionCubeObject();                               // 0x141225270
    virtual void vfunc_1(Unk_FcMsg* pMsg);                        // 1  0x1412255c0
    virtual int vfunc_2(Unk_Entity* pEntity, const Unk_FcRow* pRow, int nCubeId, __int64 nArg,
        CubeItemInfo* pItem);                                     // 2  0x141225610 set up from a table row
    virtual void vfunc_3();                                       // 3  0x141226300
    virtual void vfunc_4();                                       // 4  0x141226310
    virtual void vfunc_5(float);                                  // 5  0x141226320
    virtual CStringW vfunc_6();                                   // 6  0x141226340 hover text
    virtual CStringW vfunc_7();                                   // 7  0x141226580 "key"
    virtual void vfunc_8(CString str);                            // 8  0x1412265d0 send the use packet
    virtual bool vfunc_9(CString str);                            // 9  0x1412266c0 is this the object with that id
    virtual void vfunc_10(int nState, bool bFlag);                // 10 0x141226730 play a random sound of the state
    virtual void vfunc_11(int nState);                            // 11 0x141226950
    virtual void vfunc_12(int nState, bool bFlag);                // 12 0x141226a90 set the state
    virtual void vfunc_13();                                      // 13 0x14122e7a0
    virtual void vfunc_14(MS2Ptr<Unk_FcStateMsg> sp);       // 14 0x141226b20
    virtual int vfunc_15();                                       // 15 0x141226f30

    // CGlobalKeyTextCallback override (secondary vftable slot 5)
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);           // 0x141226d70

    void FUN_141226b80(CString str);                              // 0x141226b80 set the id
    CString FUN_141226bd0();                                      // 0x141226bd0 the id
    void FUN_141226c20(bool bFlag);                               // 0x141226c20
    int FUN_141226cd0();                                          // 0x141226cd0 item id
    Unk_StreamPoint FUN_141226d00();                                     // 0x141226d00 position property
    Unk_EntRef FUN_141226e60();                                   // 0x141226e60 copy of the entity handle
    egf::EntityID FUN_141226eb0();                               // 0x141226eb0 the entity id (or 0)
    MS2Ptr<CBoxCollision> FUN_141226f90();                        // 0x141226f90 refresh the box pose, return it
    void FUN_141227100(int nSound);                               // 0x141227100
    void FUN_1412271c0(int nState);                               // 0x1412271c0
    int FUN_1412271f0();                                          // 0x1412271f0
    unsigned char FUN_141227270();                                         // 0x141227270
    Unk_FcSkillText FUN_1412272b0();                              // 0x1412272b0
    void FUN_141227310();                                         // 0x141227310
    void FUN_141227360();                                         // 0x141227360
    void FUN_1412273b0();                                         // 0x1412273b0
    void FUN_141227780();                                         // 0x141227780
    void FUN_1412277d0(unsigned char bOn);                                 // 0x1412277d0
    void FUN_1412278b0();                                         // 0x1412278b0
    void FUN_141227950();                                         // 0x141227950
    void FUN_141227cd0();                                         // 0x141227cd0
    void FUN_141227dd0(int nSkip);                                // 0x141227dd0
    void FUN_141228060();                                         // 0x141228060
    void FUN_141228100();                                         // 0x141228100
    void FUN_141228200();                                         // 0x141228200
    void FUN_1412282d0();                                         // 0x1412282d0
    void FUN_141228340();                                         // 0x141228340

    // exe members defined elsewhere
    int FUN_140966fc0();                                          // cube kind of the data row
    int FUN_14112e110();                                          // item id
    int FUN_14122e6d0();                                          // 0x14122e6d0
    int FUN_14122e710();                                          // 0x14122e710

public:
    MS2_LAYOUT_FRIEND;
    char m_bAlt;                                                  // +0x20
    char m_b21;                                                   // +0x21
    CString m_strId;                                              // +0x28
    Unk_EntRef m_ent;                                             // +0x30 the cube entity
    int m_nState;                                                 // +0x38
    int m_n3c;                                                    // +0x3c (not initialised by the ctor)
    int m_nArg;                                                   // +0x40
    __int64 m_nArg2;                                              // +0x48
    MS2Ptr<CBoxCollision> m_spBox;                                // +0x50 the interaction box
    int m_n60;                                                    // +0x60
    MS2Ptr<CubeItemInfo> m_spItem;                                // +0x68
    MS2Ptr<FunctionCubeData> m_spData;                            // +0x78
    int m_nSoundHandle;                                           // +0x88
    unsigned char m_bFxOn;                                                 // +0x8c
    MS2Ptr<UIBootyPopup> m_spBooty;                               // +0x90
    MS2Ptr<UIUGCCubeNoticePopup> m_spNotice;                      // +0xa0
};
MS2_CHECK_SIZE(CFunctionCubeObject, 0xb0);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_ent, 0x30);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spBox, 0x50);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spItem, 0x68);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spData, 0x78);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spBooty, 0x90);
MS2_CHECK_OFFSET(CFunctionCubeObject, m_spNotice, 0xa0);
