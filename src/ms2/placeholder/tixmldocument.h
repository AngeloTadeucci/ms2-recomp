// Game-side TinyXML document (not efd::TiXmlDocument). Size from deleting destructor.
// Only directly called members are declared; no virtual dispatch through this placeholder.
#pragma once
#include "ms2/ms2layout.h"
class TiXmlDocument {
public:
    TiXmlDocument();
    virtual ~TiXmlDocument();
    bool FUN_140870fc0(const char* filename,int encoding);
private:
    void* m_08; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30;
    void* m_38; void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68;
};
MS2_CHECK_SIZE(TiXmlDocument,0x70);
