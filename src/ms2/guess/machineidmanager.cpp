// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMachineIDManager: the TSingleton-derived machine-id holder
// (ctor/dtor, the id builder, two getters) plus the TSingleton<CMachineIDManager> instantiation and the CRT memmove_s
// the unit ends with. See machineidmanager.h.
// MS2-UNIT: ?\machineidmanager.cpp
// MS2-RANGE: 0x140d4fcd0-0x140d50010 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\machineidmanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "machineidmanager.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The 40-byte working buffer the id builder passes to the (unrecovered) id helpers.
struct Unk_MachineIDLocal
{
    unsigned char m_data[0x28];
};
MS2_CHECK_SIZE(Unk_MachineIDLocal, 0x28);

void* FUN_14067c020(void* pId);                             // zero-inits the 16-byte id
void FUN_1423ae7f0(Unk_MachineIDLocal* pLocal);
void FUN_1423b10a0(Unk_MachineIDLocal* pLocal);
void* FUN_1423b1080(Unk_MachineIDLocal* pLocal);            // the id buffer inside the working object
unsigned int FUN_1423ae960(Unk_MachineIDLocal* pLocal);
void FUN_1423ae800(Unk_MachineIDLocal* pLocal);

CMachineIDManager* TSingleton<CMachineIDManager>::s_instance = 0;   // 0x143ab8aa8

// @0x140d4fcd0
CMachineIDManager::CMachineIDManager()
{
    FUN_14067c020(&m_id);
}

// @0x140d4fd20
CMachineIDManager::~CMachineIDManager()
{
}

// @0x140d4fd50
// MS2-FUNCTIONAL: the exe's frame carries an EH unwind (__GSHandlerCheck_EH) and the helper VAs are unmapped in the
// symbol map, so the prologue/GS record differ; the id-gathering call sequence and the 16-byte copy are equivalent.
void CMachineIDManager::BuildID()
{
    Unk_MachineIDLocal local;
    FUN_1423ae7f0(&local);
    FUN_1423b10a0(&local);
    unsigned char* pSrc = static_cast<unsigned char*>(FUN_1423b1080(&local));
    unsigned char* pDst = reinterpret_cast<unsigned char*>(&m_id);
    for (__int64 n = 0x10; n != 0; --n)
    {
        *pDst = *pSrc;
        ++pSrc;
        ++pDst;
    }
    m_n18 = FUN_1423ae960(&local);
    FUN_1423ae800(&local);
}
MS2_REPLACE_METHOD(0x140D4FD50, CMachineIDManager, BuildID, 139, 0xC65EBD09);

// @0x140d4fdf0
Unk_MachineID* CMachineIDManager::GetID()
{
    return &m_id;
}
MS2_REPLACE_METHOD(0x140D4FDF0, CMachineIDManager, GetID, 15, 0x46F5B241);

// @0x140d4fe10
unsigned int CMachineIDManager::GetValue()
{
    return m_n18;
}
MS2_REPLACE_METHOD(0x140D4FE10, CMachineIDManager, GetValue, 14, 0x72E52537);

// @0x140d4fe20
TSingleton<CMachineIDManager>::TSingleton()
{
    s_instance = static_cast<CMachineIDManager*>(this);
}

// @0x140d4fe50
TSingleton<CMachineIDManager>::~TSingleton()
{
    s_instance = 0;
}

// @0x140d4fef0
MS2_EMIT_CRT_MEMMOVE_S();
