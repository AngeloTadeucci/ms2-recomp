// Content shutdown flags; class/member names inferred from the owning manager.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
class Unk_ShutdownOutput;
class Unk_ShutdownInput;
class CContentShutdown {
public:
    enum Content { None = 0, End = 117 };
    void Encode(Unk_ShutdownOutput&);
    void Decode(Unk_ShutdownInput&);
    int Get(Content);
    int Set(Content,int);
    int SetString(Content,const CString&);
    void Clear();
private:
    MS2_LAYOUT_FRIEND;
    int m_flags[117]; // Actual indexed flag storage, not padding.
};
MS2_CHECK_SIZE(CContentShutdown,0x1d4);
MS2_CHECK_OFFSET(CContentShutdown,m_flags,0);
