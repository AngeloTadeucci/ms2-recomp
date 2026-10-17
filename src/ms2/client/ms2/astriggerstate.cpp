// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTriggerState: the Scaleform AS UI component behind the
// trigger editor (an ASUIComponent, 0x88 bytes, vftable 0x142dbf4c0, 25 slots). The class adds no members and no
// virtuals of its own: its vftable is ASUIComponent's slot list (3 / 4 override ASDisplayObject, 16-24 are
// ASUIComponent's), declared here because placeholder/asuicomponent.h declares no virtuals.
// MS2-UNIT: ?\astriggerstate.cpp
// MS2-RANGE: 0x1409f00e0-0x1409f01a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\astriggerstate.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class ASTriggerState : public ASUIComponent
{
public:
    ASTriggerState(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1409f00e0
    virtual ~ASTriggerState();                                      // 0x1409f0130
    virtual void vfunc_3(int nVisible);                             // 3  0x1422c7260
    virtual void vfunc_4(bool b);                                   // 4  0x1422c7230
    virtual void vfunc_16();                                        // 16 0x1422c7ec0
    virtual void vfunc_17();                                        // 17 0x1422c7f00
    virtual void vfunc_18();                                        // 18 0x1422c7f40
    virtual void vfunc_19();                                        // 19 0x1422c7f80
    virtual void vfunc_20();                                        // 20 0x1422c7fc0
    virtual void vfunc_21();                                        // 21 0x1422c8000
    virtual void vfunc_22();                                        // 22 0x1422c8040
    virtual void vfunc_23();                                        // 23 0x1422c8080
    virtual void vfunc_24(bool bRefresh);                           // 24 0x1422c80c0
};
MS2_CHECK_SIZE(ASTriggerState, 0x88);

// @0x1409f00e0
ASTriggerState::ASTriggerState(const Scaleform::GFx::Value& v, int nMovieId)
    : ASUIComponent(v, nMovieId)
{
}

// @0x1409f0130
ASTriggerState::~ASTriggerState()
{
}
