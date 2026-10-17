// gfximageloader.h - PLACEHOLDER for GFxImageLoader (RTTI .?AVGFxImageLoader@@, base Scaleform::GFx::ImageCreator, 0x88
// bytes, vftable with 6 slots). NOT an original header. The game's Scaleform image creator; its nested Protocol names the
// image request handed to the image callbacks (TFunctor<Scaleform::Render::Image*, (const Protocol&, TextureManager*)>).
// The integration code has no unit yet; the Scaleform bases are not recovered, the layout is opaque.
#pragma once

#include "ms2/ms2layout.h"

class GFxImageLoader
{
public:
    class Protocol;
private:
    MS2_LAYOUT_FRIEND;
    char m_opaque[0x88];
};
MS2_CHECK_SIZE(GFxImageLoader, 0x88);
