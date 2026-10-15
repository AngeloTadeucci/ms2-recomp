// clubcommon.h - CClub / CClubMember / CClubMemberProxy / CClubCli (RTTI names). Header name assumed (owning unit
// commonfiles\clubcommon.cpp, 0x14020c3a0..). Layouts proved from the constructors, destructors, reset functions and
// stream readers/writers cited per member. Unit workers: add FUN_ member declarations here as you recover them.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"              // MS2Ptr<T> (16 bytes, object pointer at +8)
#include "ms2/placeholder/clockcriticalsection.h"

// Player snapshot shared by club members. 0xa8 bytes. ctor 0x14020d270, dtor 0x14020d310, reset 0x14020d380,
// writer 0x14020d9a0 (field order: account, character, name, gender, jobCode, job, level, mapId, channel, picture,
// +0x40, +0x44, +0x48, +0x50, trophy). Name get/set 0x14020e5d0/0x14020e650 and picture get/set
// 0x14020e6c0/0x14020e740 hold m_lock.
class CClubMemberProxy : public CPtred
{
public:
    CClubMemberProxy();
    virtual ~CClubMemberProxy();                    // ??_G 0x1402127a0, vftable 0x142cf3958
    __int64 m_accountId;                            // +0x18
    __int64 m_characterId;                          // +0x20
    unsigned char m_gender;                         // +0x28 reset 3
    int m_jobCode;                                  // +0x2c
    int m_job;                                      // +0x30
    short m_level;                                  // +0x34
    int m_mapId;                                    // +0x38
    int m_channel;                                  // +0x3c (written as a short)
    int m_40;                                       // +0x40
    int m_44;                                       // +0x44
    int m_48;                                       // +0x48
    __int64 m_50;                                   // +0x50
    int m_trophy[3];                                // +0x58 12-byte triple (ctor 0x140267ba0, writer 0x140267f50;
                                                    //       same type as userproxy.h Unk_UserProxyColor)
    CLockCriticalSection m_lock;                    // +0x68
    CStringW m_name;                                // +0x98
    CString m_picture;                              // +0xa0
};
MS2_CHECK_SIZE(CClubMemberProxy, 0xa8);
MS2_CHECK_OFFSET(CClubMemberProxy, m_gender, 0x28);
MS2_CHECK_OFFSET(CClubMemberProxy, m_level, 0x34);
MS2_CHECK_OFFSET(CClubMemberProxy, m_50, 0x50);
MS2_CHECK_OFFSET(CClubMemberProxy, m_trophy, 0x58);
MS2_CHECK_OFFSET(CClubMemberProxy, m_lock, 0x68);
MS2_CHECK_OFFSET(CClubMemberProxy, m_name, 0x98);
MS2_CHECK_OFFSET(CClubMemberProxy, m_picture, 0xa0);

// 0xf8 bytes (operator new(0xf8) in 0x1402102xx and clubcli). ctor 0x14020e7b0, dtor 0x14020e820,
// reset 0x14020e890.
class CClubMember : public CPtred
{
public:
    CClubMember();
    virtual ~CClubMember();                         // ??_G 0x140212760, vftable 0x142cf3968
    __int64 m_18;                                   // +0x18
    CClubMemberProxy m_info;                        // +0x20 (character id at +0x40 is compared with the club leader)
    int m_c8;                                       // +0xc8
    int m_cc;                                       // +0xcc
    __int64 m_d0;                                   // +0xd0
    __int64 m_d8;                                   // +0xd8
    int m_e0;                                       // +0xe0
    CStringW m_e8;                                  // +0xe8
    int m_f0;                                       // +0xf0 reset 1
    int m_f4;                                       // +0xf4
};
MS2_CHECK_SIZE(CClubMember, 0xf8);
MS2_CHECK_OFFSET(CClubMember, m_info, 0x20);
MS2_CHECK_OFFSET(CClubMember, m_c8, 0xc8);
MS2_CHECK_OFFSET(CClubMember, m_e8, 0xe8);
MS2_CHECK_OFFSET(CClubMember, m_f4, 0xf4);

// 0xd8 bytes, no CPtred base and no virtual destructor (CClubCli adds CPtred at +0xd8). ctor 0x14020ee40,
// dtor 0x14020ef00, vftable 0x142cf3978 (6 slots, inherited unchanged by CClubCli 0x142ddacd0).
// Reader 0x14020fd80 field order: id, name, leader account, leader character, leader name, creation time, state
// (byte), +0x50, +0x54, +0x90; setters 0x14020f130/f230/f4e0/f5b0/f720/f310/f3f0. Accessors hold m_lock.
class CClub
{
public:
    CClub();
    ~CClub();
    virtual void vfunc_0();                         // 0 0x14020efb0 reset all fields (also called by ctor/dtor)
    virtual void vfunc_1(int n);                    // 1 0x140216b50 (empty)
    virtual void vfunc_2(int n);                    // 2 0x140216e40 (empty)
    virtual int vfunc_3();                          // 3 0x1402133d0 return 0
    virtual int vfunc_4(MS2Ptr<CClubMember> spMember);  // 4 0x140210340 add member (by value; max 10, sets m_leader)
    virtual void vfunc_5(CStringW strName);         // 5 0x1402104e0 remove member by name (by value)

    typedef ATL::CRBMap<CStringW, MS2Ptr<CClubMember>, ATL::CStringElementTraitsI<CStringW>> MemberMap;

    CLockCriticalSection m_lock;                    // +0x08
    __int64 m_clubId;                               // +0x38
    CStringW m_name;                                // +0x40
    int m_48;                                       // +0x48 reset 10
    int m_state;                                    // +0x4c (read as a byte)
    int m_50;                                       // +0x50
    int m_54;                                       // +0x54
    __int64 m_creationTime;                         // +0x58
    __int64 m_leaderAccountId;                      // +0x60
    __int64 m_leaderCharacterId;                    // +0x68
    CStringW m_leaderName;                          // +0x70
    __int64 m_78;                                   // +0x78
    __int64 m_80;                                   // +0x80
    CStringW m_88;                                  // +0x88
    __int64 m_90;                                   // +0x90
    MS2Ptr<CClubMember> m_leader;                   // +0x98 null ctor 0x140211ee0, reset(0) 0x140212520, dtor 0x140212330
    // +0xa8 members keyed by name, case-insensitive (Find 0x140212f90 -> _wcsicmp). CRBMap(10) ctor 0x140211bb0,
    // dtor 0x140212200, RemoveAll 0x140216500, SetAt 0x140216bd0, RemoveKey 0x140216660, Lookup 0x140214520.
    MemberMap m_members;
};
MS2_CHECK_SIZE(CClub, 0xd8);
MS2_CHECK_OFFSET(CClub, m_lock, 0x08);
MS2_CHECK_OFFSET(CClub, m_clubId, 0x38);
MS2_CHECK_OFFSET(CClub, m_state, 0x4c);
MS2_CHECK_OFFSET(CClub, m_creationTime, 0x58);
MS2_CHECK_OFFSET(CClub, m_leaderName, 0x70);
MS2_CHECK_OFFSET(CClub, m_90, 0x90);
MS2_CHECK_OFFSET(CClub, m_leader, 0x98);
MS2_CHECK_OFFSET(CClub, m_members, 0xa8);

// Client club: 0xf0 bytes (operator new(0xf0) in clubcli.cpp), no own members. ctor 0x140b12780, dtor 0x140b127f0,
// vftables 0x142ddacd0 (CClub part) and 0x142ddad08 (CPtred part at +0xd8; slot 0 thunk 0x140b19e80).
class CClubCli : public CClub, public CPtred
{
public:
    CClubCli();
    virtual ~CClubCli();
};
MS2_CHECK_SIZE(CClubCli, 0xf0);
