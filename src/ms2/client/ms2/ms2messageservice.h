// ms2messageservice.h - MS2MessageService (RTTI .?AVMS2MessageService@@): the game's subclass of efd::MessageService (size 0x198,
// same as the base). Adds no members; only a destructor that logs and releases the message lists itself.
// Recovered from MapleStory2.exe KMS2_DEV x64; owning unit `?\ms2messageservice.cpp` (0x140d966b0-0x140d9aba0, dir client\ms2).
#pragma once

#include "ms2/ms2layout.h"
#include <efd/MessageService.h>

class MS2MessageService : public efd::MessageService
{
public:
    MS2MessageService();                        // 0x140d966b0
    virtual ~MS2MessageService();               // 0x140d96710, ??_G 0x140d991f0
};
MS2_CHECK_SIZE(MS2MessageService, 0x198);
