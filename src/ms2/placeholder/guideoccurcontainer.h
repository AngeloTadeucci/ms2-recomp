// guideoccurcontainer.h - PLACEHOLDER for GuideOccurContainer (RTTI .?AVGuideOccurContainer@@, 0x40 bytes) and
// GuideTriggerEventGroup (0x38): the per-event entity index CGuideManager builds from the guide entities' trigger maps
// (GuideOccurContainer: ctors 0x141397b20/ba0/c20, dtor 0x141398330) and the trigger values it has received
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

// 0x40. m_byValue: entities of an event keyed by its sub value; m_all: the entities with sub value 0.
class GuideOccurContainer : public CPtred
{
public:
    GuideOccurContainer();                                  // 0x141397b20
    virtual ~GuideOccurContainer();                         // 0 0x141398330 (??_G 0x141399580)

    std::map<int, std::vector<MS2Ptr<CGuideEntity> > > m_byValue;   // +0x18
    std::vector<MS2Ptr<CGuideEntity> > m_all;               // +0x28
};
MS2_CHECK_SIZE(GuideOccurContainer, 0x40);

// 0x38. The values and sub values raised for one trigger type.
class GuideTriggerEventGroup : public CPtred
{
public:
    GuideTriggerEventGroup();                               // 0x141397c80
    virtual ~GuideTriggerEventGroup();                      // 0 0x141398370 (??_G 0x1413995c0)

    std::set<int> m_values;                                 // +0x18
    std::set<int> m_subValues;                              // +0x28
};
MS2_CHECK_SIZE(GuideTriggerEventGroup, 0x38);
