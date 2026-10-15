// Graph callback objects of the in-game performance overlay (NiVisualTracker::GraphCallbackObject subclasses). The unit
// 0x1414bc310-0x1414bc6c0 has no recovered source path; the class names are the RTTI names.
#pragma once
#include <NiVisualTracker.h>

// Accumulates the elapsed time handed to TakeSample (ms -> s). 0x10 bytes, (dtor + two TakeSample slots).
class ElapsedTimeUpdate : public NiVisualTracker::GraphCallbackObject
{
public:
    ElapsedTimeUpdate();                                    // 0x1414bc310
    ElapsedTimeUpdate(float fStart);                        // 0x1414bc350
    virtual float TakeSample(float fTime);                  // 0x1414bc3a0

    float m_fElapsed;                                       // +0x08
};

// Samples the scene service's averaged frame time. 8 bytes.
class FrameEventUpdate : public NiVisualTracker::GraphCallbackObject
{
public:
    FrameEventUpdate();                                     // 0x1414bc3f0
    virtual float TakeSample(float fTime);                  // 0x1414bc430
};
