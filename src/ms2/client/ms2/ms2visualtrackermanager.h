// ms2visualtrackermanager.h - MS2VisualTrackerManager (RTTI .?AVMS2VisualTrackerManager@@): the game's subclass of the
// engine's egmVisualTracker::VisualTrackerService. It builds the in-game performance overlay (F-key toggled pages:
// DebugString / System / Packet Traffic / PhysX / Debugging) out of CDrawDebugString lines and line charts and refreshes
// the lines every tick from the game's managers. Owning unit `?\ms2visualtrackermanager.cpp`
// (0x141515740-0x14151f150, dir client\ms2). Recovered from MapleStory2.exe KMS2_DEV x64.
#pragma once

#include "ms2/ms2layout.h"
#include <egmVisualTracker/VisualTrackerService.h>
#include "ms2/placeholder/cdrawdebugstring.h"

class MS2VisualTrackerManager;
template <class T> class TSingleton;
template <> class TSingleton<MS2VisualTrackerManager>
{
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static MS2VisualTrackerManager* s_instance;                 // 0x143ae0f40
};

class MS2VisualTrackerManager : public egmVisualTracker::VisualTrackerService, public TSingleton<MS2VisualTrackerManager>
{
public:
    MS2VisualTrackerManager();                                  // 0x141515740
    virtual ~MS2VisualTrackerManager();                         // 0x141515e80, ??_G 0x14151e490
    virtual efd::AsyncResult OnInit();                          // 0x141516490
    virtual efd::AsyncResult OnTick();                          // 0x141516580
    virtual void ToggleShowTrackers();                          // 0x141517ea0: cycle hidden -> page 1 -> ... -> hidden
    virtual efd::AsyncResult OnShutdown();                      // 0x141517f40
    virtual bool CreateVisualTrackers();                        // 0x141518590

public:   // not protected: the label-table helper in the .cpp calls AddDebugString
    // Helpers (non-virtual, in the order they follow CreateVisualTrackers in the exe).
    CDrawDebugStringPtr AddDebugString(unsigned page, const char* pszLabel, int x, int y, NiColorA color);  // 0x14151cf50
    void LoadConfig();                                          // 0x14151d350: [VisualTracker] PerfMaxValue / TimingMaxValue / MemMaxValue
    VisualTracker* AddChartPage(const char* pszName, NiRect<float> kDataRange, NiRect<float> kWindowRect,
        efd::TimeType fRate, unsigned nDecimals, bool bUpdateOnlyWhenVisible);                                  // 0x14151d570

public:
    int m_nPage;                                                // +0x90 selected page (0 = hidden)
    unsigned m_idDebugStringPage;                               // +0x94
    unsigned m_idSystemPage;                                    // +0x98
    unsigned m_idDebuggingPage;                                 // +0x9c
    unsigned m_idPhysXPage;                                     // +0xa0
    float m_fGpuMemoryMB;                                       // +0xa4 graphed as "GPU Memory(MB)"
    VisualTracker* m_pPerformanceChart;                         // +0xa8
    VisualTracker* m_pTimeChart;                                // +0xb0
    VisualTracker* m_pPacketChart;                              // +0xb8
    CDrawDebugStringPtr m_spFps;                                // +0xc0
    CDrawDebugStringPtr m_spFrameTime;                          // +0xc8
    CDrawDebugStringPtr m_spVisObjects;                         // +0xd0
    CDrawDebugStringPtr m_spInstancingGroup;                    // +0xd8
    CDrawDebugStringPtr m_spInstancingGrid;                     // +0xe0
    CDrawDebugStringPtr m_spEffectCount;                        // +0xe8
    CDrawDebugStringPtr m_spInfiniteEffectCount;                // +0xf0
    CDrawDebugStringPtr m_spActorCount;                         // +0xf8
    CDrawDebugStringPtr m_spAssetCount;                         // +0x100
    CDrawDebugStringPtr m_spKfmCacheCount;                      // +0x108
    CDrawDebugStringPtr m_spNifCount;                           // +0x110
    CDrawDebugStringPtr m_spTextureCount;                       // +0x118
    CDrawDebugStringPtr m_spNpcCount;                           // +0x120
    CDrawDebugStringPtr m_spLoadedMap;                          // +0x128
    CDrawDebugStringPtr m_spVertices;                           // +0x130
    CDrawDebugStringPtr m_spTriangles;                          // +0x138
    CDrawDebugStringPtr m_spBlockEntityCount;                   // +0x140
    CDrawDebugStringPtr m_spGameObjectEntityCount;              // +0x148
    CDrawDebugStringPtr m_spPageFile;                           // +0x150
    CDrawDebugStringPtr m_spSmallObject;                        // +0x158
    CDrawDebugStringPtr m_spGfxSysAlloc;                        // +0x160
    CDrawDebugStringPtr m_spPrivateUsage;                       // +0x168
    CDrawDebugStringPtr m_spEntityCount;                        // +0x170
    CDrawDebugStringPtr m_spSceneGraphCacheCount;               // +0x178
    CDrawDebugStringPtr m_spUseInstancing;                      // +0x180
    CDrawDebugStringPtr m_spPos;                                // +0x188
    CDrawDebugStringPtr m_spSpeed;                              // +0x190
    CDrawDebugStringPtr m_spAnim;                               // +0x198
    CDrawDebugStringPtr m_spEffectOid;                          // +0x1a0
    CDrawDebugStringPtr m_spOsName;                             // +0x1a8
    CDrawDebugStringPtr m_spMemory;                             // +0x1b0
    CDrawDebugStringPtr m_spCpuName;                            // +0x1b8
    CDrawDebugStringPtr m_spGpuName;                            // +0x1c0
    CDrawDebugStringPtr m_spGpuCore;                            // +0x1c8
    CDrawDebugStringPtr m_spGpuMemory;                          // +0x1d0
    CDrawDebugStringPtr m_spGpuAllocMemory;                     // +0x1d8
    CDrawDebugStringPtr m_spNifNotCache;                        // +0x1e0
    CDrawDebugStringPtr m_spNifForceKeep;                       // +0x1e8
    CDrawDebugStringPtr m_spNifMySkill;                         // +0x1f0
    CDrawDebugStringPtr m_spNifOtherSkill;                      // +0x1f8
    CDrawDebugStringPtr m_spNifNpc;                             // +0x200
    CDrawDebugStringPtr m_spNifDependTime;                      // +0x208
    CDrawDebugStringPtr m_spTexNotCache;                        // +0x210
    CDrawDebugStringPtr m_spTexForceKeep;                       // +0x218
    CDrawDebugStringPtr m_spTexMySkill;                         // +0x220
    CDrawDebugStringPtr m_spTexOtherSkill;                      // +0x228
    CDrawDebugStringPtr m_spTexNpc;                             // +0x230
    CDrawDebugStringPtr m_spTexDependTime;                      // +0x238
    CDrawDebugStringPtr m_spPhysXMem;                           // +0x240
    // PhysX scene statistics, two columns (scene 0 at +0x248, scene 1 at +0x298).
    CDrawDebugStringPtr m_spPx0AwakeGroups;                     // +0x248
    CDrawDebugStringPtr m_spPx0Actors;                          // +0x250 (never updated: OnTick writes scene 0's actors to m_spPx1Actors)
    CDrawDebugStringPtr m_spPx0DynamicActors;                   // +0x258
    CDrawDebugStringPtr m_spPx0DynamicShapes;                   // +0x260
    CDrawDebugStringPtr m_spPx0Joints;                          // +0x268
    CDrawDebugStringPtr m_spPx0Contacts;                        // +0x270
    CDrawDebugStringPtr m_spPx0Pairs;                           // +0x278
    CDrawDebugStringPtr m_spPx0AxisConstraints;                 // +0x280
    CDrawDebugStringPtr m_spPx0SolverBodies;                    // +0x288
    CDrawDebugStringPtr m_spPx0StaticShapes;                    // +0x290
    CDrawDebugStringPtr m_spPx1AwakeGroups;                     // +0x298
    CDrawDebugStringPtr m_spPx1Actors;                          // +0x2a0
    CDrawDebugStringPtr m_spPx1DynamicActors;                   // +0x2a8
    CDrawDebugStringPtr m_spPx1DynamicShapes;                   // +0x2b0
    CDrawDebugStringPtr m_spPx1Joints;                          // +0x2b8
    CDrawDebugStringPtr m_spPx1Contacts;                        // +0x2c0
    CDrawDebugStringPtr m_spPx1Pairs;                           // +0x2c8
    CDrawDebugStringPtr m_spPx1AxisConstraints;                 // +0x2d0
    CDrawDebugStringPtr m_spPx1SolverBodies;                    // +0x2d8
    CDrawDebugStringPtr m_spPx1StaticShapes;                    // +0x2e0
    CDrawDebugStringPtr m_spSortLabel[7];                       // +0x2e8 one line per sort category
    CDrawDebugStringPtr m_spFlatModelCount;                     // +0x320
};
MS2_CHECK_SIZE(MS2VisualTrackerManager, 0x328);
MS2_CHECK_OFFSET(MS2VisualTrackerManager, m_nPage, 0x90);
MS2_CHECK_OFFSET(MS2VisualTrackerManager, m_spSortLabel, 0x2e8);
