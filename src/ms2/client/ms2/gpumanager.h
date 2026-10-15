// GPUManager (RTTI name): picks the vendor GPU helper (NVIDIA/AMD-ATI/Intel) from the display adapter name and polls memory use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
class GPUManager;
template <class T> class TSingleton;
template <> class TSingleton<GPUManager> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static GPUManager* s_instance;
};

// Poll timer (same class as uidungeonrewarddialog.h's Timer; CPtred-derived, 0x38).
class Timer {
public:
    Timer();
    ~Timer();
    int FUN_140868c00();
    void FUN_140868750(unsigned int ms);
private:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30;
};
MS2_CHECK_SIZE(Timer, 0x38);

// Vendor helper interface (unrecovered base of NvidiaGPU / ATiGPU). Never instantiated here.
class Unk_GPUBase {
public:
    virtual ~Unk_GPUBase();
    virtual int vfunc_1();                              // init, 0 = failed
    virtual void vfunc_2();                             // shutdown
    virtual void vfunc_3(int* a, int* b);
    virtual unsigned __int64 vfunc_4();
    virtual void vfunc_5(unsigned __int64* a, unsigned __int64* b);
};
class ATiGPU : public Unk_GPUBase {
public:
    ATiGPU();                                           // 0x1409f0910
    void* m_pad[18];
};
MS2_CHECK_SIZE(ATiGPU, 0x98);
class NvidiaGPU : public Unk_GPUBase {
public:
    NvidiaGPU();                                        // 0x14160c6d0
    void* m_pad[21];
};
MS2_CHECK_SIZE(NvidiaGPU, 0xb0);

class Unk_GPUApp { public: double FUN_141473260(); };
Unk_GPUApp* FUN_14086d260();
class Unk_GPULog { public: void FUN_1401ce2b0(const char* text); };
Unk_GPULog* FUN_140a44830();
int FUN_140392040(char* buf, size_t size, const char* fmt, ...);

class GPUManager : public TSingleton<GPUManager> {
public:
    GPUManager();                                       // 0x141375250
    virtual ~GPUManager();                              // 0x141375320
    int FUN_141375390(CStringW adapterName);
    void FUN_1413758b0();
    void FUN_1413759f0();
    void FUN_141375a80();
    unsigned __int64 FUN_141375c80();
    unsigned __int64 FUN_141375c90();
    int FUN_141375ca0();

    int m_type;                                         // +0x08 1 nvidia, 2 amd/ati, 3 intel
    float m_elapsed;                                    // +0x0c
    Unk_GPUBase* m_gpu;                                 // +0x10
    CStringW m_name;                                    // +0x18
    unsigned __int64 m_20;                              // +0x20
    unsigned __int64 m_28;                              // +0x28
    int m_30;                                           // +0x30
    int m_34;                                           // +0x34
    unsigned __int64 m_38;                              // +0x38
    Timer m_timer;                                      // +0x40
};
MS2_CHECK_SIZE(GPUManager, 0x78);
