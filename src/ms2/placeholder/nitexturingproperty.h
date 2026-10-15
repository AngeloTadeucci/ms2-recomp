// nitexturingproperty.h - PLACEHOLDER for the parts of Gamebryo's NiTexturingProperty used by MS2 render steps (the
// CoreRuntime include dirs are not on the path). NOT an original header. Proven from the exe (KMS2_DEV x64):
//   NiTexturingProperty::ShaderMap : 0x28 bytes (Map base with a vfptr + m_uiID at +0x20), ctor 0x140c8f5d0
//   (NiTexture*, uint, ClampMode, FilterMode, uint id); NiTexturingProperty::SetShaderMap(uint, ShaderMap*) 0x141d20b10.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"

class NiTexturingProperty {
public:
    class ShaderMap : public efd::MemObject {
    public:
        ShaderMap(void* pkTexture, unsigned int a, unsigned int b, unsigned int c, unsigned int uiID);   // 0x140c8f5d0
    private:
        unsigned char m_pad[0x28];
    };
    void SetShaderMap(unsigned int uiIndex, ShaderMap* pkMap);      // 0x141d20b10
};
