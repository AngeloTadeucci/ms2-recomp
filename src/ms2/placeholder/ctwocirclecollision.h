// ctwocirclecollision.h - CTwoCircleCollision (0xb0 bytes, ctor 0x1416c4b00): the debug-visible attenuation shape of a
// sound event (an inner and an outer circle). NOT an original header (name from the exe's RTTI, layout from the
// operator new size in CSoundEvent::CSoundEvent). Owning unit: not recovered; only the members the callers use are
// declared. The virtual destructor is the key function, so no vftable is emitted in the including unit.
#pragma once
#include "ms2/placeholder/cbasecollision.h"

class CTwoCircleCollision : public CBaseCollision
{
public:
    CTwoCircleCollision();                                          // 0x1416c4b00
    virtual ~CTwoCircleCollision();
    virtual void vfunc_5();                                         // builds the two wire circles
    virtual float vfunc_6();
    void FUN_1416c4b60(float fMin);                                 // the inner radius
    void FUN_1416c4bf0(float fMax);                                 // the outer radius

    char m_pad_78[0xb0 - 0x78];
};
MS2_CHECK_SIZE(CTwoCircleCollision, 0xb0);
