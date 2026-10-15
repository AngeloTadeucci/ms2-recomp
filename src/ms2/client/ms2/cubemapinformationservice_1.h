#pragma once
#include <efd/StdContainers.h>
#include "ms2/ms2layout.h"
class Unk_CubeHeightIndex {
public:
    void FUN_1410b2510(int,int,int);
    void FUN_1410b25a0(int,int,int);
    void Clear();
    static inline int Key(int x,int y) { return (x&0xff)+((y&0xff)<<8); }
    efd::map<int,int> m_heights;
};

MS2_CHECK_SIZE(Unk_CubeHeightIndex,0x10);
