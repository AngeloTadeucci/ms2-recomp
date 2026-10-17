// cgamerule.h - PLACEHOLDER for CGameRule (RTTI .?AVCGameRule@@, 0xf58 bytes). NOT an original header.
// Bases: TSingleton<CGameRule> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include <set>
#include <atlcoll.h>
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
class SaleCube;
class StampEventContext;
class TimeRunEventContext;
class EnchantRateEventContext;
class GalleryContext;
class SnowmanContext;
class RpsContext;
class ReactorContext;
class TreeWateringContext;
class QuestAdditionalRewardContext;
enum Unk_SaleHousingKey : int;

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
    void FUN_14047be80(int eventId, ATL::CRBMultiMap<Unk_SaleHousingKey, MS2Ptr<SaleCube> >& cubes);   // GameEventSaleHousing
    void FUN_14047bfc0(int eventId);
    void FUN_14047c020(int eventId, __int64 endTime, const CStringA& a, const CStringA& b, const CStringA& c); // GameEventEpicRestart
    void FUN_14047c1e0();
    void FUN_14047c740(int level, const CStringW& str);                            // GameEventLevelUpPackage
    void FUN_14047c7c0();
    void FUN_14047c8e0(MS2Ptr<StampEventContext> spContext);                      // GameEventStampEvent
    void FUN_14047c990(MS2Ptr<StampEventContext> spContext);
    void FUN_14047d650(MS2Ptr<TimeRunEventContext> spContext);              // GameEventTimeRunEvent start / end (null)
    void FUN_14047dba0(unsigned id, int value);                                   // GameEventMassiveConstructionEvent
    void FUN_14047dd60();
    void FUN_14047df50(unsigned __int64 id);
    void FUN_14047e0e0();
    void FUN_14047e530(MS2Ptr<EnchantRateEventContext> spContext);                // GameEventEnchantRate
    void FUN_14047e630(int eventId);
    void FUN_14047e740(bool bOpen);                                               // GameEventRankDuel
    void FUN_14047e830(bool bOpen);                                               // GameEventGuildChampionship
    void FUN_14047e8e0(unsigned a, unsigned b, MS2Ptr<QuestAdditionalRewardContext> spContext);   // GameEventQuestAdditionalReward
    void FUN_14047e980(unsigned a, unsigned b);
    void FUN_140479640(int eventId, int rate);                                    // GameEventUGCMapContractSale
    void FUN_1404796b0(int eventId);
    void FUN_140479790(int eventId, int rate);                                    // GameEventUGCMapExtensionSale
    void FUN_140479800(int eventId);
    void FUN_1404784b0(int a, __int64 b, CStringW str);                           // GameEventUgcMapCommendationGM
    void FUN_140478640(int a);
    void FUN_140478a40(int value);                                                // GameEventDeleteUrlCache
    void FUN_14047ef70(int eventId, int value);                                   // GameEventPetMastery
    void FUN_14047f180(int eventId, int value);
    void FUN_14047efe0(int eventId);
    void FUN_14047f1f0(int eventId);
    void FUN_14047f390(int eventId, int rate);                                    // GameEventPetBattleExp
    void FUN_14047f400(int eventId);
    void FUN_14047f590(int eventId, int rate);                                    // GameEventPetComposeSale
    void FUN_14047f600(int eventId);
    void FUN_14047ec80(bool bOpen);                         // guild vs game open
    void FUN_14047cef0(MS2Ptr<GalleryContext> spContext);                        // GameEventGallery
    void FUN_14047cfe0(MS2Ptr<SnowmanContext> spContext);                        // GameEventSnowman
    void FUN_14047d0d0(MS2Ptr<RpsContext> spContext);                            // GameEventRps
    void FUN_14047d1c0(MS2Ptr<ReactorContext> spContext);                        // GameEventReactor
    void FUN_14047d2b0(MS2Ptr<TreeWateringContext> spContext);                   // GameEventTreeWatering
    void FUN_140476930(int nEventId, int nRate);                                 // adventure level bonus exp rate
    void FUN_1404769a0(int nEventId);                                            // ... removed
    void FUN_14047e230(unsigned __int64 nId);                                    // ignore the construction lock of one id
    void FUN_14047e300();                                                        // ... clear them
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xa9c - 0x8];
    bool m_transferItemBound;                               // +0xa9c
    char m_pad_a9d[0xf58 - 0xa9d];
};
MS2_CHECK_SIZE(CGameRule, 0xf58);
MS2_CHECK_OFFSET(CGameRule, m_transferItemBound, 0xa9c);
