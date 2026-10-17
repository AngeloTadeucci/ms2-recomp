// statehomeconvenient.h - the housing convenience call state StateHomeConvenient (type 0x36): calls the home bank / doctor
// NPC, plays the call animation under a casting bar and tells the server when it ends. NOT an original header (name
// assumed from the unit client\ms2\statehomeconvenientdata.cpp). Derives State / StateData (ms2/placeholder/state.h).
//   kind (StateHomeConvenientData::m_nKind): 1/2 = bank call, 3 = doctor call.
//   sub states (m_n10): 0x88 call running, 0x89 ended.
#pragma once
#include <efd/utf8string.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>

// 0x20. +0x18 the call kind (travels through the state-sync record as a decimal string).
class StateHomeConvenientData : public StateData
{
public:
    StateHomeConvenientData();                              // 0x140ddcf00
    StateHomeConvenientData(int nKind);                     // 0x140ddcf40
    ~StateHomeConvenientData() = default;                   // 0x140dddd40 (??_G 0x140ddde70)
    virtual void vfunc_1(Unk_StateDataArg* p);              // 0x140ddcf90
    virtual void vfunc_2(Unk_StateDataArg* p);              // 0x140ddd010

    int m_nKind;                                            // +0x18
    int m_pad_1c;
};
MS2_CHECK_SIZE(StateHomeConvenientData, 0x20);
MS2_CHECK_OFFSET(StateHomeConvenientData, m_nKind, 0x18);

// 0x60. m_n44 / m_n48 are the elapsed and the total call time in ms.
class StateHomeConvenient : public State
{
public:
    StateHomeConvenient(PCBase* pOwner);                    // 0x140ddd060
    virtual ~StateHomeConvenient();                         // 0x140ddd0d0 (??_G 0x140ddde30)
    virtual int vfunc_1();                                  // 1  0x140dddf30: 0x36
    virtual void vfunc_3(double fTime);                     // 3  0x140ddd4c0
    virtual void vfunc_4(StateData* pData);                 // 4  0x140ddd120
    virtual void vfunc_5(int n);                            // 5  0x140ddd420
    virtual void vfunc_6();                                 // 6  0x140ddd6b0
    virtual void vfunc_7(int n);                            // 7  0x140ddd3b0
    virtual void vfunc_8(double fTime);                     // 8  0x140ddd5b0
    virtual MS2Ptr<StateData> vfunc_27();                   // 27 0x140dddeb0: an empty StateHomeConvenientData

    int GetKind();                                          // 0x140ddd6f0
    int GetDuration();                                      // 0x140ddd740 (ms, from the client constants)
    CStringW GetLabel();                                    // 0x140ddd7c0
    efd::utf8string GetAnimation();                         // 0x140ddd870
    void Finish(double fTime);                              // 0x140ddd950
    void SetSub(int nSub, int nAddTime);                    // 0x140dddc90

    int m_n40;                                              // +0x40 the end packet was sent
    int m_n44;                                              // +0x44
    int m_n48;                                              // +0x48
    int m_pad_4c;
    MS2Ptr<StateHomeConvenientData> m_spHome;               // +0x50
};
MS2_CHECK_SIZE(StateHomeConvenient, 0x60);
MS2_CHECK_OFFSET(StateHomeConvenient, m_n40, 0x40);
MS2_CHECK_OFFSET(StateHomeConvenient, m_spHome, 0x50);
