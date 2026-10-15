// CThread: RTTI and deleting destructor establish the 0x18-byte worker base.
#pragma once
#include <windows.h>
#include "ms2/ms2layout.h"
class Unk_140659080;
class CThread {
public:
    CThread();
    virtual ~CThread();
    virtual unsigned int vfunc_1(void*, Unk_140659080&) = 0;
    bool FUN_1401d3510(DWORD timeout);
    // gamesocket.cpp worker management (non-virtual).
    bool FUN_141215220(void*,void*,int,int,int);
    HANDLE FUN_14126a990() const;
private:
    DWORD m_threadId;
    HANDLE m_thread;
};
MS2_CHECK_SIZE(CThread,0x18);
