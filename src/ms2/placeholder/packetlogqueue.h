// PacketLogQueue: name from PrintPacketLogs; layout from 0x14026dd20/0x14026dd80.
#pragma once
#include <atlcoll.h>
#include "ms2/ms2layout.h"
struct Unk_CommonPacketLogEntry {
    Unk_CommonPacketLogEntry();
    void Set(int type,int loopback,__int64 time);
    int type,loopback;
    __int64 time;
};
MS2_CHECK_SIZE(Unk_CommonPacketLogEntry,0x10);
class PacketLogQueue {
public:
    PacketLogQueue(int count);
    void Add(int type,int loopback);
    void PrintPacketLogs();
private:
    MS2_LAYOUT_FRIEND;
    volatile LONG m_cursor;
    ATL::CAtlArray<Unk_CommonPacketLogEntry> m_entries;
};
MS2_CHECK_SIZE(PacketLogQueue,0x28);
MS2_CHECK_OFFSET(PacketLogQueue,m_entries,8);
