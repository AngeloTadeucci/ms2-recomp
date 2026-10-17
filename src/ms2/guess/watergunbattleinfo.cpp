// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WaterGunBattleInfo: a small CPtred-derived record (one flag,
// one int) with its stream Write/Read pair and two getters. See watergunbattleinfo.h.
// MS2-UNIT: ?\watergunbattleinfo.cpp
// MS2-RANGE: 0x1408fdf10-0x1408fe100 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\watergunbattleinfo.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "watergunbattleinfo.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1408fdf10
WaterGunBattleInfo::WaterGunBattleInfo() : m_bFlag(false), m_nValue(0)
{
}

// @0x1408fdf60
WaterGunBattleInfo::~WaterGunBattleInfo()
{
}

// @0x1408fdf90
void WaterGunBattleInfo::Write(Unk_WgbOut* out)
{
    out->WriteBool(m_bFlag);
    out->WriteInt(m_nValue);
}
MS2_REPLACE_METHOD(0x1408FDF90, WaterGunBattleInfo, Write, 67, 0x1D527824);

// @0x1408fdfe0
void WaterGunBattleInfo::Read(Unk_WgbIn* in)
{
    // The reader is the object embedded at packet+8. clang-cl devirtualizes a call on an embedded member into a direct
    // call to an undefined function, so go through an opaque pointer there (the byte-matched cl build keeps the member
    // call, which is the exe's shape). Same guard as commonfiles/gameevent.h.
#ifdef __clang__
    Unk_WgbReader* r = reinterpret_cast<Unk_WgbReader*>(reinterpret_cast<char*>(in) + 8);
    m_bFlag = r->ReadBool();
    m_nValue = r->ReadInt();
#else
    m_bFlag = in->reader.ReadBool();
    m_nValue = in->reader.ReadInt();
#endif
}
MS2_REPLACE_METHOD(0x1408FDFE0, WaterGunBattleInfo, Read, 102, 0x76DACCB3);

// @0x1408fe070
bool WaterGunBattleInfo::GetFlag()
{
    return m_bFlag;
}
MS2_REPLACE_METHOD(0x1408FE070, WaterGunBattleInfo, GetFlag, 15, 0x12EF4005);

// @0x1408fe0b0
int WaterGunBattleInfo::GetValue()
{
    return m_nValue;
}
MS2_REPLACE_METHOD(0x1408FE0B0, WaterGunBattleInfo, GetValue, 14, 0x8AEE455B);
