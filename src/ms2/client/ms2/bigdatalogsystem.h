// bigdatalogsystem.h - CBigDataLogSystem (RTTI .?AVCBigDataLogSystem@@, 0xe8 bytes, TSingleton<CBigDataLogSystem> at +0): the
// client's "big data" statistics sampler. Three sample lists (fps, memory, latency) are filled every frame while enabled and
// flushed to the game server (packet 0x55) every five minutes. Owning unit client\ms2\bigdatalogsystem.cpp
// (0x140a1f250-0x140a20460). Members named from use; the CSampleList class is an invented name. w276.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/clockcriticalsection.h"

class CBigDataLogSystem : public TSingleton<CBigDataLogSystem>
{
public:
    // One sample series: the values since the last flush, guarded by a critical section (0x48 bytes).
    class CSampleList
    {
    public:
        void Clear();                                                   // 0x140a1f250
        void Add(float fValue);                                         // 0x140a1f2b0
        bool Calculate(float* pAverage, float* pMin, float* pMax, int* pCount, float* pDeviation);   // 0x140a1f320
    private:
        std::vector<float> m_values;                                    // +0x00
        CLockCriticalSection m_lock;                                    // +0x18
    };

    enum { SAMPLE_FPS, SAMPLE_MEMORY, SAMPLE_LATENCY, SAMPLE_MAX };

    CBigDataLogSystem();                                                // 0x140a1f690
    virtual ~CBigDataLogSystem();                                       //  0 0x140a1f720 (??_G 0x140a20200)

    void Reset();                                                       // 0x140a1f780 clear every list, restart the timer
    void SetEnable(bool bEnable);                                       // 0x140a1f7f0
    void AddSample(int nType, __int64 nValue);                          // 0x140a1f830
    void Update();                                                      // 0x140a1f8a0 flush every 5 minutes, take one sample of each
    void SendLog(const CString& strKey, const CString& strValue);       // 0x140a1f970 packet 0x55 sub 0
    void SendStatistics();                                              // 0x140a1fa00 packet 0x55 sub 1
    static const char* GetSampleName(int nType);                        // 0x140a1fb80

private:
    MS2_LAYOUT_FRIEND;
    CSampleList m_samples[SAMPLE_MAX];                                  // +0x08
    unsigned m_dwLastSendTick;                                          // +0xe0
    bool m_bEnable;                                                     // +0xe4
};
MS2_CHECK_SIZE(CBigDataLogSystem::CSampleList, 0x48);
MS2_CHECK_SIZE(CBigDataLogSystem, 0xe8);
MS2_CHECK_OFFSET(CBigDataLogSystem, m_samples, 0x8);
MS2_CHECK_OFFSET(CBigDataLogSystem, m_dwLastSendTick, 0xe0);
MS2_CHECK_OFFSET(CBigDataLogSystem, m_bEnable, 0xe4);
