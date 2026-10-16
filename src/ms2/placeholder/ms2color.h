#pragma once
#include "ms2/ms2layout.h"
// RTTI names this value type MS2Color in Common::Constants::Values<MS2Color>.
// Packed ARGB constructor1408a85e0 and conversion1408a90b0 prove four floats.
struct MS2Color {
    MS2Color(unsigned color) {
        const float kInv255 = 1.0f / 255.0f;
        r = 0.003921569f * (float)(unsigned char)(color >> 16);
        g = 0.003921569f * (float)(unsigned char)(color >> 8);
        b = 0.003921569f * (float)(unsigned char)color;
        a = 0.003921569f * (float)(unsigned char)(color >> 24);
    }
    MS2Color(float red, float green, float blue, float alpha) : r(red),g(green),b(blue),a(alpha) {}
    operator unsigned() const {
        int red = r >= 1.0f ? 255 : (r <= 0.0f ? 0 : (int)(__int64)(r * 255.0f + 0.5f));
        int green = g >= 1.0f ? 255 : (g <= 0.0f ? 0 : (int)(__int64)(g * 255.0f + 0.5f));
        unsigned blue = b >= 1.0f ? 255 : (b <= 0.0f ? 0 : (unsigned)(__int64)(b * 255.0f + 0.5f));
        int alpha = a >= 1.0f ? 255 : (a <= 0.0f ? 0 : (int)(__int64)(a * 255.0f + 0.5f));
        return (alpha << 24) | (red << 16) | (green << 8) | blue;
    }
    float r,g,b,a;
};
inline MS2Color operator*(float factor, const MS2Color& color) {
    return MS2Color(factor * color.r, factor * color.g, factor * color.b, factor * color.a);
}
MS2_CHECK_SIZE(MS2Color,0x10);
