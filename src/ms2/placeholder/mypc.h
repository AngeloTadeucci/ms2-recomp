// mypc.h - PLACEHOLDER for MyPC (efd RTTI name "MyPC", derives PCBase; ctor 0x141520680, 0x1808 bytes): the local
// player's character actor. NOT an original header; only the constructor is declared (members are unrecovered).
// Owning unit: ?\mypc.cpp.
#pragma once

#include "ms2/client/ms2/pcbase.h"

class CInPacket;
class CEquipItem;

class MyPC : public PCBase
{
public:
    MyPC();                                                 // 0x141520680
    int vfunc_116() override;                               // declared only so the class is concrete
    void FUN_14152a4a0(PCBase* pTarget);                    // observe pTarget (guild battle, uipvpguildteamdialog)
    void FUN_14152a960();                                   // stop observing
    void FUN_14152a2f0(int n);                              // scenestategame packet 0x35
    class Unk_MyPCSkillSlots* FUN_141523bc0();              // the skill slot set (skillslot.cpp, 0x141765de0 etc.)
    MS2Ptr<class Unk_MyPCStatPoints> FUN_140c25130();       // the stat point manager (statpointmanager.cpp)
    void FUN_141661370(int a, int b, int c);                // PC member (scenestategame packet 0x83)
    void FUN_141528c30(CInPacket& packet);                  // scenestategame packet 0x135
    void FUN_141662850(__int64 nValue);                     // PC member (scenestategame packet 0xe0)
    void FUN_141662890(__int64 nValue);                     // PC member
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 nItemUid);     // PC member: a worn item by uid (scenestategame 0x14173b420)
private:
    char m_pad[0x1808 - 0xd40];                             // unrecovered members
};
MS2_CHECK_SIZE(MyPC, 0x1808);
