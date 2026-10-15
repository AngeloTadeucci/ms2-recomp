// postprocesssetting.h - PostProcessSetting: Gamebryo built-in model (egf::IBuiltinModelImpl) holding the 14 float
// parameters of one post-process look; PostProcessingService feeds them to the global shader constants every tick.
// Owning unit: ?\postprocesssetting.cpp (0x1416b5320-0x1416b9e50 + .di 0x1400fc960-0x1400fc9b0, dir client\ms2\postprocessing).
// Property ids are the model-data ids from the game's flat-model definitions (names unknown, so hex-named); the exe
// has one .rdata copy of each at 0x142f523b0..0x142f523e4 (sorted by value, as in the generated id header).
#pragma once
#include "ms2/ms2layout.h"
#include <egf/IBuiltinModelImpl.h>
#include <egf/BuiltinModelHelper.h>

static const efd::ClassID kCLASSID_PostProcessSetting = 0x06200005u;

static const egf::PropertyID kPropertyID_PostProcessSetting_0086E4DF = 0x0086E4DFu;
static const egf::PropertyID kPropertyID_PostProcessSetting_052A6D52 = 0x052A6D52u;
static const egf::PropertyID kPropertyID_PostProcessSetting_0E6F104E = 0x0E6F104Eu;
static const egf::PropertyID kPropertyID_PostProcessSetting_2968B120 = 0x2968B120u;
static const egf::PropertyID kPropertyID_PostProcessSetting_47428EF4 = 0x47428EF4u;
static const egf::PropertyID kPropertyID_PostProcessSetting_6FDE026D = 0x6FDE026Du;
static const egf::PropertyID kPropertyID_PostProcessSetting_806E8A1D = 0x806E8A1Du;
static const egf::PropertyID kPropertyID_PostProcessSetting_8E985908 = 0x8E985908u;
static const egf::PropertyID kPropertyID_PostProcessSetting_AA05C66E = 0xAA05C66Eu;
static const egf::PropertyID kPropertyID_PostProcessSetting_B88892DF = 0xB88892DFu;
static const egf::PropertyID kPropertyID_PostProcessSetting_CC4CE791 = 0xCC4CE791u;
static const egf::PropertyID kPropertyID_PostProcessSetting_CFC3E360 = 0xCFC3E360u;
static const egf::PropertyID kPropertyID_PostProcessSetting_D7DE6AC8 = 0xD7DE6AC8u;
static const egf::PropertyID kPropertyID_PostProcessSetting_FA326917 = 0xFA326917u;

// 0x60 bytes. vftables 0x142f52450 (IBuiltinModelImpl side, 17 slots) and 0x142f524e0 (+0x10, 20 slots).
class PostProcessSetting : public egf::IBuiltinModelImpl
{
    EE_DECLARE_CLASS1(PostProcessSetting, kCLASSID_PostProcessSetting, egf::IBuiltinModelImpl);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;

    EE_DECLARE_BUILTINMODEL_PROPERTIES

        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_8E985908, float, PostProcessSetting, m_f24)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_D7DE6AC8, float, PostProcessSetting, m_f28)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_CFC3E360, float, PostProcessSetting, m_f2c)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_CC4CE791, float, PostProcessSetting, m_f30)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_0086E4DF, float, PostProcessSetting, m_f34)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_AA05C66E, float, PostProcessSetting, m_f38)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_FA326917, float, PostProcessSetting, m_f3c)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_B88892DF, float, PostProcessSetting, m_f40)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_806E8A1D, float, PostProcessSetting, m_f44)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_0E6F104E, float, PostProcessSetting, m_f48)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_47428EF4, float, PostProcessSetting, m_f4c)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_052A6D52, float, PostProcessSetting, m_f50)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_2968B120, float, PostProcessSetting, m_f54)
        EE_BUILTINMODELPROPERTY(PostProcessSetting, kPropertyID_PostProcessSetting_6FDE026D, float, PostProcessSetting, m_f58)

    EE_END_BUILTINMODEL_PROPERTIES;

public:
    PostProcessSetting();                           // 0x1416b5320
    virtual ~PostProcessSetting();                  // 0x1416b5380, ??_G 0x1416b6bf0

    void ApplyShaderConstants(float fTime);         // 0x1416b53c0 (called by PostProcessingService::OnTick)

    float m_f24; float m_f28; float m_f2c;          // +0x24 .. (shader constants 0x143ae5408/10/18)
    float m_f30; float m_f34;                       // +0x30, +0x34 (property only)
    float m_f38; float m_f3c; float m_f40; float m_f44; float m_f48;   // shader constants 0x143ae5358/60/68/70/0x143ae5420
    float m_f4c; float m_f50; float m_f54; float m_f58;                // colour constant 0x143ae5428 (4c, 58, 54, 50)
    unsigned int m_pad5c;
};
MS2_CHECK_SIZE(PostProcessSetting, 0x60);
MS2_CHECK_OFFSET(PostProcessSetting, m_f24, 0x24);
MS2_CHECK_OFFSET(PostProcessSetting, m_f58, 0x58);
