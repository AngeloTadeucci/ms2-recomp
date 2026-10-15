// CMsTime: the game's time class from commonfiles\mstime.h (name invented; the header name comes from an assert's
// __FILE__). PLACEHOLDER: an ATL::CTime plus a flag byte (16 bytes). Methods are the out-of-unit inline helpers
// 0x1406c47a0.. that timeutil.cpp calls; declarations only.
#pragma once
#include <afx.h>
#include <atltime.h>
#include "ms2/ms2layout.h"
class CMsTime : public ATL::CTime {
public:
    CMsTime(__time64_t t);                                          // 0x1406c47a0
    CMsTime(int year,int month,int day,int hour,int minute,int second); // 0x1406c47d0
    CMsTime(const CMsTime&);                                        // 0x1406c4760
    CMsTime operator+(ATL::CTimeSpan span) const;                   // 0x1406c4ae0
    ATL::CTimeSpan operator-(const CMsTime&) const;                 // 0x1406c4a20
    bool operator!=(const CMsTime&) const;                          // 0x1406c4ba0
    bool operator<(const CMsTime&) const;                           // 0x1406c4c00
    bool operator>(const CMsTime&) const;                           // 0x1406c4c60
    bool operator<=(const CMsTime&) const;                          // 0x1406c4cc0
    __time64_t Get() const;                                         // 0x140282020 (asserts, then raw value)
    bool m_flag;
};
MS2_CHECK_SIZE(CMsTime,16);
