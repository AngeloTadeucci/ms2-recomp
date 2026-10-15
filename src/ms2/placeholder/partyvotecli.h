// PartyVoteCli layout from ctor 140a89190 and its virtual callers.
#pragma once
#include <afx.h>
#include <set>
#include "ms2/placeholder/cptred.h"
class CInPacket;
class PartyVoteCli : public CPtred {
public:
    virtual ~PartyVoteCli();
    virtual void vfunc_1(CInPacket&);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual CStringW vfunc_4();
    virtual unsigned char vfunc_5();
    virtual void vfunc_6(__int64);
    virtual void vfunc_7(__int64, bool);
    void FUN_140a894e0(__int64, bool);
    int id, kind;
    __int64 owner, expires;
    std::set<__int64> participants, yes, no;
};
MS2_CHECK_SIZE(PartyVoteCli, 0x60);
MS2_CHECK_OFFSET(PartyVoteCli, participants, 0x30);
