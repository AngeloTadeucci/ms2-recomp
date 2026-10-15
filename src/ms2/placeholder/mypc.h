// mypc.h - PLACEHOLDER for MyPC (efd RTTI name "MyPC", derives PCBase; ctor 0x141520680, 0x1808 bytes): the local
// player's character actor. NOT an original header; only the constructor is declared (members are unrecovered).
// Owning unit: ?\mypc.cpp.
#pragma once

#include "ms2/client/ms2/pcbase.h"

class MyPC : public PCBase
{
public:
    MyPC();                                                 // 0x141520680
    int vfunc_116() override;                               // declared only so the class is concrete
private:
    char m_pad[0x1808 - 0xd40];                             // unrecovered members
};
MS2_CHECK_SIZE(MyPC, 0x1808);
