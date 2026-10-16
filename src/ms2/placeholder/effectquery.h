// effectquery.h - PLACEHOLDER for the request record handed to the client effect manager (name invented): an effect
// file name plus the owner's object id. Ctor 0x140a52ef0 and dtor 0x1405a89e0 are defined elsewhere (unrecovered).
// First used by ?\stateeffectmgr.cpp and ?\groundeffectdata.cpp.
#pragma once
#include <afx.h>

class Unk_EffectQuery
{
public:
    Unk_EffectQuery();                          // 0x140a52ef0
    ~Unk_EffectQuery();                         // 0x1405a89e0
    void FUN_140a53190(int nValue);

    CString m_strName;                          // +0x00 effect file name
    int m_nObject;                              // +0x08 owner object (player manager lookup)
    int m_nPad0c;                               // +0x0c
};
