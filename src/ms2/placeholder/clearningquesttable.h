// Heap-only declaration. Constructor14064cbf0 initializes singleton and the
// unrecovered collection at+8; factory141215480 allocates0x38.
#pragma once
#include "ms2/commonfiles/os.h"
class CLearningQuestTable : public TSingleton<CLearningQuestTable> {
public:
    CLearningQuestTable();
    virtual ~CLearningQuestTable();
private:
    void* unknown08; void* unknown10; void* unknown18;
    void* unknown20; void* unknown28; void* unknown30;
};
MS2_CHECK_SIZE(CLearningQuestTable,0x38);
