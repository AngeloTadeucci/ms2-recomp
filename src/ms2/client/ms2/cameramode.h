// cameramode.h - CCameraMode (RTTI .?AVCCameraMode@@): the abstract base of the client's camera modes (RPG, action,
// target, fly-by, tool, ... about 20 classes). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\cameramode.cpp` (0x140afd490-0x140afe800). Header name assumed; the vfunc_N names are vftable slot numbers and the
// member names are invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"

// The object that owns the camera modes (CCameraMode::m_pOwner); it forwards the settings to the engine camera
// through a property bag at +0x10 (hash-keyed setters).
class Unk_CameraPropertyBag
{
public:
    void FUN_14098c6e0(unsigned int nHash, const bool& bValue);
};

class Unk_CameraOwner
{
public:
    void FUN_140a38dc0(Unk_StreamPoint pt);     // property 0xfd95ca52 (look-at offset)
    void FUN_140a38e00(Unk_StreamPoint pt);     // second point property
    void FUN_140947940(float f);                // property 0x88b558f6 (distance)
    // @0x140afe7c0
    void FUN_140afe7c0(bool b)
    {
        if (m_10)
            m_10->FUN_14098c6e0(0x2310d55e, b);
    }

    void* m_pad_00;
    void* m_pad_08;
    Unk_CameraPropertyBag* m_10;                // +0x10
};

// The camera settings block at CCameraMode+0x20 (0x28 bytes). The ctor (0x140ae7ce0) and the implicit copy
// assignment (0x140ae7de0) belong to another obj; the ctor is defined here so the hook DLL has it.
extern const Unk_StreamPoint g_143b01a60;       // NiPoint3::ZERO
struct Unk_CameraSetting
{
    // 0x140ae7d90 (another obj): the members are default-constructed, then assigned
    Unk_CameraSetting(const Unk_CameraSetting& o)
    {
        *this = o;
    }
    Unk_CameraSetting()
    {
        m_c = g_143b01a60;
        m_18 = g_143b01a60;
        m_0 = 0.0f;
        m_4 = 250.0f;
        m_8 = 18000.0f;
        m_24 = false;
    }

    float m_0;                                  // +0x00
    float m_4;                                  // +0x04
    float m_8;                                  // +0x08
    Unk_StreamPoint m_c;                        // +0x0c (vfunc_3)
    Unk_StreamPoint m_18;                       // +0x18 (vfunc_4)
    bool m_24;                                  // +0x24 (vfunc_5)
};
MS2_CHECK_SIZE(Unk_CameraSetting, 0x28);

// The camera target entity (+0x1c0 of the camera manager); slot 17 returns its position.
class Unk_CameraTargetEntity
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16();
    virtual Unk_StreamPoint vfunc_17();
};

class CCameraMode;
class Unk_PickListPtr;                  // picked-object list (defined by the units that use it)

// The camera manager singleton (0x143ab3700). Its methods are inline COMDATs of other objs.
class Unk_CameraManager
{
public:
    static Unk_CameraManager* FUN_1409478c0();          // inline, ?\actioncameramode.cpp obj
    Unk_CameraTargetEntity* FUN_140a38d60();            // m_1c0 (the camera target)
    int FUN_140af01d0();                                // camera control type (0: normal, 1: ...)
    float FUN_140b67d10();                              // distance of the current mode (0 without one)
    void FUN_140aeaf40(Unk_CameraTargetEntity* pTarget, int n);
    CCameraMode* FUN_140af24f0();                       // the current camera mode
    Unk_StreamPoint FUN_140a38d00();                    // m_138 (pending move input)
    void FUN_140a38d90(Unk_StreamPoint pt);             // m_138 = pt
    Unk_PickListPtr FUN_140af0850(float fX, float fY, bool b1, bool b2, bool b3, void* p);  // pick at the cursor
};

// Argument of vfunc_36 (a camera preset row).
struct Unk_CameraPreset
{
    char m_pad_00[0x1c];
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
};

// 0x78 bytes. vftable 0x142dd6ab8, 37 slots (slots 1 and 2 pure).
class CCameraMode : public CPtred
{
public:
    CCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x140afd490 (copies pPrev's settings)
    virtual ~CCameraMode();                                         // 0x140afd540

    virtual int vfunc_1() = 0;                                      // mode id
    virtual bool vfunc_2() = 0;
    virtual void vfunc_3(Unk_StreamPoint pt);                       // 0x140afd570
    virtual void vfunc_4(Unk_StreamPoint pt);                       // 0x140afd5d0
    virtual void vfunc_5(bool b);                                   // 0x140afd630
    virtual void vfunc_6(int n);                                    // 0x140afd670
    virtual void vfunc_7();                                         // 0x140afd740
    virtual void vfunc_8(double fTime);                             // 0x140afd750
    virtual void vfunc_9();                                         // 0x140afd770
    virtual void vfunc_10();                                        // 0x140afd780
    virtual void vfunc_11(float f);                                 // 0x140afd790
    virtual void vfunc_12(float fDegree);                           // 0x140afd7f0
    virtual void vfunc_13(float fDegree);                           // 0x140afd830
    virtual void vfunc_14(float f);                                 // 0x140afd870
    virtual float vfunc_15();                                       // 0x140afd8a0
    virtual void vfunc_16(float f);                                 // 0x140afd8c0
    virtual float vfunc_17();                                       // 0x140afd8f0
    virtual void vfunc_18(float f1, float f2);                      // 0x140afd910
    virtual float vfunc_19();                                       // 0x140afd950
    virtual void vfunc_20(float f);                                 // 0x140afd970
    virtual void vfunc_21(float f, int n);                          // 0x140afd9a0
    virtual float vfunc_22();                                       // 0x140afd9d0
    virtual float vfunc_23();                                       // 0x140afd9e0
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);                 // 0x140afd9f0
    virtual Unk_CameraTargetEntity* vfunc_25();                                   // 0x140afda10
    virtual Unk_StreamPoint vfunc_26();                             // 0x140afda20
    virtual float vfunc_27();                                       // 0x140afda50
    virtual int vfunc_28();                                         // 0x140afda60
    virtual void vfunc_29(float f1, float f2, float f3);            // 0x140afda80
    // 0x140947930 (COMDAT of the ?\actioncameramode.cpp obj)
    virtual void vfunc_30() {}
    virtual BOOL vfunc_31();                                        // 0x140afe2c0
    virtual void vfunc_32(float f);                                 // 0x140afe320
    virtual void vfunc_33();                                        // 0x140afe350
    // 0x1409478d0 (COMDAT of the ?\actioncameramode.cpp obj)
    virtual bool vfunc_34() { return true; }
    virtual Unk_StreamPoint vfunc_35();                             // 0x140afe360
    virtual void vfunc_36(Unk_CameraPreset* pPreset);               // 0x140afe410

    void FUN_140afdaa0(MS2Ptr<CCameraMode> pPrev);                  // copy pPrev's settings or set the defaults
    static Unk_StreamPoint FUN_140afdd40(const Unk_StreamPoint& ptEye, const Unk_StreamPoint& ptAt,
                                         const Unk_StreamPoint& ptUp);     // look-at -> euler angles (degrees)
    static Unk_StreamPoint FUN_140afdec0(float t, const Unk_StreamPoint& a, const Unk_StreamPoint& b); // angle lerp
    void FUN_140afe270(float f, bool bApply);
    float FUN_140afe2e0();
    float FUN_140afe300();
    void FUN_140afe4b0();

    // 0x1409f2540 (inline, another obj)
    Unk_StreamPoint FUN_1409f2540() { return m_setting.m_c; }
    // 0x140af8260 (inline, another obj)
    Unk_StreamPoint FUN_140af8260() { return m_setting.m_18; }
    // 0x140ad4b30 (inline, another obj)
    float FUN_140ad4b30() { return m_setting.m_0; }

    Unk_CameraOwner* m_pOwner;          // +0x18
    Unk_CameraSetting m_setting;        // +0x20
    float m_48;                         // +0x48 (radians; vfunc_12 adds pi)
    float m_4c;                         // +0x4c (radians)
    float m_50;
    float m_54;
    float m_58;
    float m_5c;
    float m_60;
    float m_64;
    float m_68;
    float m_6c;
    float m_70;                         // +0x70 (ctor 1.0)
};
MS2_CHECK_SIZE(CCameraMode, 0x78);
MS2_CHECK_OFFSET(CCameraMode, m_pOwner, 0x18);
MS2_CHECK_OFFSET(CCameraMode, m_setting, 0x20);
MS2_CHECK_OFFSET(CCameraMode, m_70, 0x70);
