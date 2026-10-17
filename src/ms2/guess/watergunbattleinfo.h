// watergunbattleinfo.h - WaterGunBattleInfo (RTTI .?AVWaterGunBattleInfo@@, vftable 0x142da71d8, only the deleting dtor
// in slot 0): a small CPtred-derived record holding one flag and one int, with a Write/Read pair against the game's
// output/input streams. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\watergunbattleinfo.cpp`
// (0x1408fdf10-0x1408fe100 .text$mn). Header name assumed; method and member names invented.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// Output stream (the game's COutputStream, commonfiles/stream.h). Only slots 0 and 3 are touched here; the slot list
// matches Unk_GEOut in commonfiles/gameevent.h (proven from GameEvent::vfunc_3 and other writers).
struct Unk_WgbOut
{
    virtual void WriteBool(bool value);                     // slot 0
    virtual void WriteByte(unsigned char value);            // slot 1
    virtual void WriteShort(unsigned short value);          // slot 2
    virtual void WriteInt(int value);                       // slot 3
};

// Input stream reader (the game's CInputStream); the reader object is embedded at +8 of the packet.
struct Unk_WgbReader
{
    virtual bool ReadBool();                                // slot 0
    virtual unsigned char ReadByte();                       // slot 1
    virtual unsigned short ReadShort();                     // slot 2
    virtual int ReadInt();                                  // slot 3
};
// The input packet: the reader object is embedded at +8 (layout of FieldProperty's Unk_PktIn / GameEvent's Unk_GEIn).
struct Unk_WgbIn
{
    void* m_pad_00;
    Unk_WgbReader reader;                                   // +0x08
};

class WaterGunBattleInfo : public CPtred
{
public:
    WaterGunBattleInfo();                                   // 0x1408fdf10
    virtual ~WaterGunBattleInfo();                          // 0x1408fdf60 (??_G 0x1408fe0c0)
    void Write(Unk_WgbOut* out);                            // 0x1408fdf90
    void Read(Unk_WgbIn* in);                               // 0x1408fdfe0
    bool GetFlag();                                         // 0x1408fe070
    int GetValue();                                         // 0x1408fe0b0

    bool m_bFlag;                                           // +0x18
    int m_nValue;                                           // +0x1c
};
MS2_CHECK_SIZE(WaterGunBattleInfo, 0x20);
MS2_CHECK_OFFSET(WaterGunBattleInfo, m_bFlag, 0x18);
MS2_CHECK_OFFSET(WaterGunBattleInfo, m_nValue, 0x1c);
