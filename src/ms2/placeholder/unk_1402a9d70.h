// unk_1402a9d70.h - the class of the condition-table static (ctor/dtor in commonfiles\conditionutil.cpp).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"

class Unk_1402a9d70
{
public:
    Unk_1402a9d70(int n1, float f1, float f2, float f3, int n2);   // 0x1402a9d70
    ~Unk_1402a9d70();                                               // 0x1402aa1d0

private:
    char m_pad[0x50];
};
MS2_CHECK_SIZE(Unk_1402a9d70, 0x50);
