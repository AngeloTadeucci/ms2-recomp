// asstat.h - PLACEHOLDER for ASStat (RTTI .?AVASStat@@, base ASObj, 0x100 bytes). NOT an original header.
// The AS object of a stat block: six AS arrays (title, hidden, random, special, compare, essential) created in the ctor and
// filled by the Add* members with { statName, statValue[, statStrengthen] } rows. Ctor/dtor in unit_1409f01a0.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/gfxvalue.h"

class ASStat : public ASObj
{
public:
    explicit ASStat(int nType);
    virtual ~ASStat() = default;
    void AddCompare(int nStat, __int64 nValue);                      // 0x1409f04f0: statName, statValue -> compare
    void AddStat(int nStat, unsigned nValue, unsigned nStrengthen, int bEssential);   // 0x1409f05d0: -> random, or essential
    void AddEssentialText(int a1, int a2);                           // 0x1409f06f0: formatted text row -> essential

private:
    Scaleform::GFx::Value m_title;       // +0x40
    Scaleform::GFx::Value m_hidden;      // +0x60
    Scaleform::GFx::Value m_random;      // +0x80
    Scaleform::GFx::Value m_special;     // +0xa0
    Scaleform::GFx::Value m_compare;     // +0xc0
    Scaleform::GFx::Value m_essential;   // +0xe0
};
MS2_CHECK_SIZE(ASStat, 0x100);
