// blockmanager.h - CBlockManager: client-side holder of the account's active block restrictions (CBlockChecker) and the
// handler for the server's block packet. Singleton (TSingleton<CBlockManager>).
// Owning unit: ?\blockmanager.cpp (0x140a2f540-0x140a31af0 .text$mn, 0x1400c2fc0 .text$di; dir client\ms2).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/blockchecker.h"

class AccountBlockInfo : public Unk_BlockRecord {   // 0x48 bytes, ctor 0x140268600 (unit_140268010), dtor 0x14027e4e0
public:
    AccountBlockInfo();
};
MS2_CHECK_SIZE(AccountBlockInfo, 0x48);

class CBlockManager : public TSingleton<CBlockManager>
{
public:
    CBlockManager();                                // 0x140a2f540
    virtual ~CBlockManager();                       // 0x140a2f5e0, ??_G 0x140a319a0

    BlockPtr FindBlockedAction(int action);         // 0x140a2f620: first live (not yet expired) record blocking `action`, or null
    void ClearBlocks();                             // 0x140a2f700
    void OnBlockPacket(void* packet);               // 0x140a2f730 (packet stream at +8)

public:
    Unk_BlockPtr<CBlockChecker> m_checker;          // +0x08
};
MS2_CHECK_SIZE(CBlockManager, 0x18);
