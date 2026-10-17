// cshutdownevent.h - PLACEHOLDER for the CShutdownEvent* members of CGameEventValueManager (RTTI
// .?AVCShutdownEventInteractObject@@, .?AVCShutdownEventFunctionItem@@, .?AV?$CShutdownEventKeyCountMap@IH@@).
// NOT an original header. Each one is a CPtred with a CLockCriticalSection at +0x18 and a container at +0x48; their
// ctors are in the shutdown event TU (0x1407d03c0, 0x1407d09f0) and in gameeventvalue (0x14046d570).
#pragma once

#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"

// Shutdown count per key: a key is shut down while its count is non-zero. vftable 0x142d499d0 (only ??_G).
// The map key is DWORD (unsigned long), not K: the exe's operator[] / end() this code calls (0x1403e89a0, 0x140265e30)
// are the map<unsigned long, int> copies of the symbol table (unit_1403e8960), byte-identical to but distinct from the
// map<unsigned int, int> family (client\ms2\gameobject.cpp, 0x140a4xxxx / 0x14123ed20), and the key is passed
// straight to operator[] (no conversion temporary).
template <class K, class V>
class CShutdownEventKeyCountMap : public CPtred
{
public:
    CShutdownEventKeyCountMap();                            // 0x14046d570 (K = unsigned, V = int)
    // @0x1403f3150
    bool SetShutdown(unsigned long key)
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        m_counts[key]++;
        return true;
    }
    // @0x1403f24d0
    void ResetShutdown(unsigned long key)
    {
        Unk_CriticalSectionLock lock(m_lock, 1);
        if (m_counts.find(key) == m_counts.end())
            return;
        V count = m_counts[key];
        if (count < 2)
            m_counts.erase(key);
        else
            m_counts[key]--;
    }
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    std::map<unsigned long, V> m_counts;                    // +0x48
};
typedef CShutdownEventKeyCountMap<unsigned int, int> CShutdownEventKeyCountMapUInt;
MS2_CHECK_SIZE(CShutdownEventKeyCountMapUInt, 0x58);

// Shut down interact object ids (vftable written by 0x1407d03c0). Container at +0x48 not recovered.
class CShutdownEventInteractObject : public CPtred
{
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    char m_pad_48[0x58 - 0x48];
};
MS2_CHECK_SIZE(CShutdownEventInteractObject, 0x58);

// Shut down function items (vftable written by 0x1407d09f0). Container at +0x48 not recovered.
class CShutdownEventFunctionItem : public CPtred
{
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x18
    char m_pad_48[0x58 - 0x48];
};
MS2_CHECK_SIZE(CShutdownEventFunctionItem, 0x58);
