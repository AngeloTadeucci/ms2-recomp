// loginbgbgmdata.h - the login screen background music tables (RTTI names LoginBgBgmData, LoginBgBgmTable), read from
// Table/loginBgBgm.xml: <login clientPropertyBgDay="" month="1,2" bgmID="1,2" bgmParam="0,0" priority=""/>.
// Header name assumed from the unit path; member and method names are invented from the xml attributes and use.
#pragma once
#include <afx.h>
#include <map>
#include <utility>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"

// One <login> row: the background (clientPropertyBgDay) and the bgm ids with their params for some months, 0x40 bytes.
class LoginBgBgmData : public CPtred
{
public:
    LoginBgBgmData();                       // 0x140a71e90
    virtual ~LoginBgBgmData();              // 0x140a71f20

    CStringA m_strBgDay;                    // +0x18 "clientPropertyBgDay"
    std::vector<std::pair<unsigned, unsigned> > m_bgm;  // +0x20 (bgmID, bgmParam) pairs
    unsigned m_nPriority;                   // +0x38 "priority"
};
MS2_CHECK_SIZE(LoginBgBgmData, 0x40);
MS2_CHECK_OFFSET(LoginBgBgmData, m_bgm, 0x20);
MS2_CHECK_OFFSET(LoginBgBgmData, m_nPriority, 0x38);

typedef MS2Ptr<LoginBgBgmData> LoginBgBgmDataPtr;

// RTTI LoginBgBgmTable (TSingleton at +0, CValidData at +8), 0x30 bytes.
class LoginBgBgmTable : public TSingleton<LoginBgBgmTable>, public CValidData<LoginBgBgmTable>
{
public:
    typedef std::vector<LoginBgBgmDataPtr> DataList;
    typedef std::map<unsigned, DataList> MonthMap;

    LoginBgBgmTable();                      // 0x140a71f90
    virtual ~LoginBgBgmTable();             // 0x140a720e0

    bool Load();                            // 0x140a72170 reads the xml into m_byMonth
    void SelectCurrent();                   // 0x140a729e0 picks this month's row (random among the top priority)
    CStringA GetBgDay();                    // 0x140a72cc0 the picked row's background
    std::pair<unsigned, unsigned> GetBgm(); // 0x140a72d70 a random (bgmID, bgmParam) of the picked row

    // @0x140a76ba0
    static void SetInit(bool bInit) { s_bInit = bInit; }

    static bool s_bInit;                    // DAT_143ab8310

    MonthMap m_byMonth;                     // +0x10 month (0..12) -> its rows
    LoginBgBgmDataPtr m_spCurrent;          // +0x20 the row SelectCurrent picked
};
MS2_CHECK_SIZE(LoginBgBgmTable, 0x30);
MS2_CHECK_OFFSET(LoginBgBgmTable, m_byMonth, 0x10);
MS2_CHECK_OFFSET(LoginBgBgmTable, m_spCurrent, 0x20);
