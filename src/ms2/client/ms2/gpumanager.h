// GPUManager (RTTI name): picks the vendor GPU helper (NVIDIA/AMD-ATI/Intel) from the display adapter name and polls memory use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/timer.h"
class GPUManager;
template <class T> class TSingleton;
template <> class TSingleton<GPUManager> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static GPUManager* s_instance;
    static GPUManager* GetInstance();                   // 0x141245b20
};


// Vendor helper interface (RTTI name GPUBass; base of NvidiaGPU / ATiGPU, ?\atigpu.cpp). The no-GPU default bodies return 0.
class GPUBass {
public:
    GPUBass();                                          // 0x1409f0f30
    virtual ~GPUBass();                                 // 0x1409f0f50
    virtual int vfunc_1() = 0;                          // init, 0 = failed
    virtual void vfunc_2() = 0;                         // shutdown
    virtual int vfunc_3(int* a, int* b);                // 0x1409f1060
    virtual unsigned __int64 vfunc_4();                 // 0x1409f0ff0
    virtual int vfunc_5(unsigned __int64* a, unsigned __int64* b);   // 0x1409f1020
};
typedef GPUBass Unk_GPUBase;

// AMD Display Library (atiadlxx.dll) records the helper keeps.
struct Unk_ADLPMActivity { __int64 m_pad[5]; };         // 0x28 bytes
struct Unk_ADLMemoryInfo {                              // 0x110 bytes
    char m_pad_0[0x108];
    unsigned __int64 m_nBandwidth;                      // +0x108
};

class ATiGPU : public GPUBass {
public:
    ATiGPU();                                           // 0x1409f0910
    virtual ~ATiGPU();                                  // 0x1409f0a40
    virtual int vfunc_1() override;                     // 0x1409f0a70: loads atiadlxx.dll and starts ADL
    virtual void vfunc_2() override;                    // 0x1409f0dd0
    virtual int vfunc_3(int* a, int* b) override;       // 0x1409f1040
    virtual unsigned __int64 vfunc_4() override;        // 0x1409f0e80
    virtual int vfunc_5(unsigned __int64* a, unsigned __int64* b) override;   // 0x1409f1000

    FARPROC m_pfnMainControlCreate;                     // +0x08 ADL_Main_Control_Create
    FARPROC m_pfnMainControlDestroy;                    // +0x10
    FARPROC m_pfnNumberOfAdaptersGet;                   // +0x18
    FARPROC m_pfnDisplayInfoGet;                        // +0x20
    FARPROC m_pfnTemperatureGet;                        // +0x28
    FARPROC m_pfnFanSpeedInfoGet;                       // +0x30
    FARPROC m_pfnMemoryInfoGet;                         // +0x38
    FARPROC m_pfnSpeedGet;                              // +0x40
    FARPROC m_pfnFanSpeedGet;                           // +0x48
    FARPROC m_pfnCurrentActivityGet;                    // +0x50
    FARPROC m_pfnAdapterInfoGet;                        // +0x58
    FARPROC m_pfnAdapterActiveGet;                      // +0x60
    FARPROC m_pfnColorCapsGet;                          // +0x68
    FARPROC m_pfnColorGet;                              // +0x70
    FARPROC m_pfnColorSet;                              // +0x78
    HMODULE m_hModule;                                  // +0x80
    Unk_ADLPMActivity* m_pActivity;                     // +0x88
    Unk_ADLMemoryInfo* m_pMemoryInfo;                   // +0x90
};
MS2_CHECK_SIZE(ATiGPU, 0x98);
class NvidiaGPU : public GPUBass {
public:
    NvidiaGPU();                                        // 0x14160c6d0
    virtual ~NvidiaGPU();
    virtual int vfunc_1() override;
    virtual void vfunc_2() override;
    virtual int vfunc_3(int* a, int* b) override;
    virtual unsigned __int64 vfunc_4() override;
    virtual int vfunc_5(unsigned __int64* a, unsigned __int64* b) override;
    void* m_pad[21];
};
MS2_CHECK_SIZE(NvidiaGPU, 0xb0);

class Unk_GPUApp { public: double FUN_141473260(); float FUN_141473210(); /* frame rate (w25) */ };
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
    GPUBass* m_gpu;                                 // +0x10
    CStringW m_name;                                    // +0x18
    unsigned __int64 m_20;                              // +0x20
    unsigned __int64 m_28;                              // +0x28
    int m_30;                                           // +0x30
    int m_34;                                           // +0x34
    unsigned __int64 m_38;                              // +0x38
    Timer m_timer;                                      // +0x40
};
MS2_CHECK_SIZE(GPUManager, 0x78);
