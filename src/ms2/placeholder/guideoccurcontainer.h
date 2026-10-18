// guideoccurcontainer.h - PLACEHOLDER for GuideOccurContainer (RTTI .?AVGuideOccurContainer@@, 0x40 bytes) and
// GuideTriggerEventGroup (0x38): the per-event entity index CGuideManager builds from the guide entities' trigger maps
// (GuideOccurContainer: ctors 0x141397b20 (move) / ba0 (copy) / c20 (default), dtor 0x141398330) and the trigger values it has received
// (GuideTriggerEventGroup: ctor 0x141397c80, dtor 0x141398370). Layout proven from the operator new sizes of the
// deleting dtors 0x141399580 / 0x1413995c0 and the member ctors. NOT an original header (member names invented).
#pragma once

#include <map>
#include <set>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class CGuideEntity;
struct Unk_GameEventIntRange;

// 0x40. m_byValue: entities of an event keyed by its sub value; m_all: the entities with sub value 0.
class GuideOccurContainer : public CPtred
{
public:
    GuideOccurContainer() = default;                        // 0x141397c20 (implicit: value-initialization zero-fills first)
    GuideOccurContainer(const GuideOccurContainer& other);  // 0x141397ba0
    GuideOccurContainer(GuideOccurContainer&& other);       // 0x141397b20
    virtual ~GuideOccurContainer() = default;               // 0 0x141398330 (no vptr store) (??_G 0x141399580)

    std::map<int, std::vector<MS2Ptr<CGuideEntity> > > m_byValue;   // +0x18
    std::vector<MS2Ptr<CGuideEntity> > m_all;               // +0x28
};
MS2_CHECK_SIZE(GuideOccurContainer, 0x40);

// 0x38. The values and sub values raised for one trigger type.
class GuideTriggerEventGroup : public CPtred
{
public:
    GuideTriggerEventGroup();                               // 0x141397c80
    virtual ~GuideTriggerEventGroup() = default;             // 0 0x141398370 (no vptr store) (??_G 0x1413995c0)

    void AddValue(int nValue);                              // 0x14138a2f0
    bool HasValue(int nValue);                              // 0x14138a330
    bool HasValueInRange(Unk_GameEventIntRange* pRange);   // 0x14138a390: any value inside the [min, max] range
    void AddSubValue(int nValue);                           // 0x14138a430
    bool HasSubValue(int nValue);                           // 0x14138a470

    std::set<int> m_values;                                 // +0x18
    std::set<int> m_subValues;                              // +0x28
};
MS2_CHECK_SIZE(GuideTriggerEventGroup, 0x38);
