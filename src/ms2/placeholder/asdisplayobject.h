// asdisplayobject.h - PLACEHOLDER for the ActionScript display-object wrappers (RTTI). NOT an original header.
//   ASEventDispatcher : AScript                  vftable 0x14310b510 (1 slot)
//   ASDisplayObject : ASEventDispatcher          vftable 0x14310ad10 (6 slots)
//   ASInteractiveObject : ASDisplayObject, ASDisplayObjectContainer : ASInteractiveObject, ASSprite : ...Container
//   ASMovieClip : ASSprite                       vftable 0x14310b160 (16 slots)
// Only what recovered code calls is declared. Sizes are not pinned (never constructed by recovered code yet).
#pragma once

#include <afx.h>

#include "ms2/placeholder/ascript.h"

class ASEventDispatcher : public AScript
{
public:
    virtual ~ASEventDispatcher();
};

class ASDisplayObject : public ASEventDispatcher
{
public:
    virtual ~ASDisplayObject();                                 // 0
    virtual void vfunc_1(int a1, int a2, int a3);               // 1 0x1422bf8c0
    virtual void vfunc_2(int a1, int a2, int a3);               // 2 0x1422bf840 (UISwfEntity::vfunc_44: resize)
    virtual void vfunc_3(int nVisible);                         // 3 0x1422bfc60 SetVisible
    virtual void vfunc_4(bool b);                               // 4 0x1422bfbd0
    virtual void vfunc_5();                                     // 5 0x1422c1560

    bool FUN_1422bfca0();                                       // IsVisible
    int FUN_1422c1340();                                        // ceil(width)
    int FUN_1422c13b0();                                        // ceil(height)
};

class ASInteractiveObject : public ASDisplayObject {};
class ASDisplayObjectContainer : public ASInteractiveObject {};
class ASSprite : public ASDisplayObjectContainer {};
class ASMovieClip : public ASSprite {};

// new ASDisplayObject(v, n) wrapped in an MS2Ptr (free function or static; 0x140d01be0).
MS2Ptr<ASDisplayObject> FUN_140d01be0(int n, const Scaleform::GFx::Value& v);
