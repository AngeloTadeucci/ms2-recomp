// cgamerule.h - PLACEHOLDER for CGameRule (RTTI .?AVCGameRule@@, 0xf58 bytes). NOT an original header.
// Bases: TSingleton<CGameRule> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include <set>
#include <vector>
#include "ms2/commonfiles/os.h"

template <class T> class MS2Ptr;
struct SAHotTimeEventContext;
struct MesoRevivalEventContext;
struct OntimeEventContext;
class DungeonBonusRewardCtx;
class EventQuestContext;
class DungeonRoomShutdownContext;
class DungeonExtraRewardCountCtx;
struct SkillUpgradeSaleEventContext;
struct NpcEventDropEventContext;
class BlueMarbleEventContext;
class EventTimeLimitDungeonContext;

class CGameRule : public TSingleton<CGameRule>
{
public:
    CGameRule();                                            // 0x140474af0
    virtual ~CGameRule();
    // @0x1403f31d0 (GameEventTransferItemBound; name invented)
    void SetTransferItemBound(bool bBound) { m_transferItemBound = bBound; }
    // The game event handlers (commonfiles\gameevent.cpp vfunc_5 start / vfunc_6 end); names not recovered.
    void FUN_140477020(int eventId, int a, int b, int c);                   // GameEventSaleChat start
    void FUN_1404770e0(int eventId);
    void FUN_140477180();
    void FUN_140477210();
    void FUN_1404772a0();
    void FUN_140477360(int eventId, MS2Ptr<SAHotTimeEventContext> spContext);
    void FUN_140477420(int eventId);
    void FUN_14047d820(int eventId, const CStringW& text);
    void FUN_14047d900(int eventId);
    void FUN_140476b40(int a, int b, BOOL c);                               // GameEventSaleBeautyShop
    void FUN_140476be0(int a, BOOL c);
    void FUN_140477f20(int value, CStringW text);                           // GameEventUserCondition
    void FUN_140477fb0(int value);
    void FUN_140477bd0(int eventId, MS2Ptr<MesoRevivalEventContext> spContext);
    void FUN_140477c90(int eventId);
    void FUN_14047a8c0(int type);                                           // GameEventItemBuff
    void FUN_14047a900(MS2Ptr<DungeonBonusRewardCtx> spContext);
    void FUN_14047aa00(MS2Ptr<DungeonBonusRewardCtx> spContext);
    void FUN_140477dc0(int eventId);                                        // GameEventFreeAirTaxi
    void FUN_140477e30(int eventId);
    void FUN_140478170(int eventId, MS2Ptr<OntimeEventContext> spContext);   // GameEventOntime
    void FUN_1404781f0(int eventId);
    void FUN_140478a80(int eventId, int rate);                              // GameEventSaleEnchant
    void FUN_140478af0(int eventId);
    void FUN_140478fd0(CStringW tag, MS2Ptr<EventQuestContext> spContext);  // GameEventQuestTag
    void FUN_140479070(CStringW tag);
    void FUN_140479510(int rate, __int64 beginTime, __int64 endTime);       // GameEventBlackMarketFeeDiscount
    void FUN_1404795c0(int value);                                          // GameEventEventFieldPopup
    void FUN_140479600(int value);                                          // GameEventUGCMapSaleCoupon
    void FUN_1404798e0(int value);                                          // GameEventSaleAutoFishing
    void FUN_140479920(CStringW str);
    void FUN_140479a00(int value);                                          // GameEventSaleAutoPlayInstrument
    void FUN_140479a40(CStringW str);
    void FUN_140479c80(MS2Ptr<DungeonRoomShutdownContext> spContext);       // GameEventDungeonRoomShutdown
    void FUN_14047a360(std::set<unsigned> ids);                            // GameEventFieldShutdown on
    void FUN_14047a3d0();                                                   // ... off
    bool FUN_14047a420(unsigned dungeonId, MS2Ptr<DungeonExtraRewardCountCtx> spCount); // GameEventDungeonExtraReward
    void FUN_14047a4e0(unsigned dungeonId, int eventId);
    void FUN_140478bd0(int eventId, int type, int rate);                    // GameEventSaleRemake
    void FUN_140478c50(int eventId, int type);
    void FUN_140478e80(int eventId, int rate);                              // GameEventSaleGemStoneUpgrade
    void FUN_140478ef0(int eventId);
    void FUN_14047b540(MS2Ptr<SkillUpgradeSaleEventContext> spContext);     // GameEventSaleSkillUpgrade
    void FUN_14047b5c0(unsigned skillId);
    void FUN_14047b6d0(const CStringW& str);
    void FUN_14047a6a0(int eventId, MS2Ptr<NpcEventDropEventContext> spContext);   // GameEventNpcEventDrop
    void FUN_14047a730(int eventId);
    void FUN_14047b8f0(MS2Ptr<BlueMarbleEventContext> spContext);                  // GameEventBlueMarble
    void FUN_14047b9d0(int eventId, int rate);                                     // GameEventSaleUGCDesign
    void FUN_14047ba40(int eventId);
    void FUN_140479f30(std::vector<MS2Ptr<EventTimeLimitDungeonContext> >& contexts); // GameEventDungeonEnterTimeLimit
    void FUN_14047a0a0(int eventId);
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xa9c - 0x8];
    bool m_transferItemBound;                               // +0xa9c
    char m_pad_a9d[0xf58 - 0xa9d];
};
MS2_CHECK_SIZE(CGameRule, 0xf58);
MS2_CHECK_OFFSET(CGameRule, m_transferItemBound, 0xa9c);
