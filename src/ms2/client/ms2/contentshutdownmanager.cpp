// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CContentShutdownManager: a TSingleton holding the
// server-sent "content shutdown" flags (CContentShutdown). Header: ms2/placeholder/ccontentshutdownmanager.h.
// MS2-UNIT: ?\contentshutdownmanager.cpp
// MS2-RANGE: 0x140cca6a0-0x140cca840 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\contentshutdownmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ccontentshutdownmanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140cca6a0
CContentShutdownManager::CContentShutdownManager()
{
}

// @0x140cca6f0
CContentShutdownManager::~CContentShutdownManager()
{
}

// @0x140cca720
void CContentShutdownManager::FUN_140cca720(Unk_ShutdownInput& in)
{
    m_flags.Decode(in);
}

// @0x140cca780
inline CContentShutdown::CContentShutdown()
{
    Clear();
}
