// cgraphicoptiontable.h - CGraphicOptionTable (RTTI .?AVCGraphicOptionTable@@, 0x168 bytes): the quality levels read from
// Table/graphicOption.xml (per-level hdr / mirror / shimmer / multisample flags, the shadow quality names). Header name
// assumed (graphicoptiontable.cpp is the unit); member and method names are invented from use.
// Bases: TSingleton<CGraphicOptionTable> at +0x0. Created by CGameApp::InitInstance (?\ms2.cpp).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/tixmldocument.h"

class CGraphicOptionTable : public TSingleton<CGraphicOptionTable>
{
public:
    CGraphicOptionTable();                                  // 0x141375cb0
    virtual ~CGraphicOptionTable();

    void Load();                                            // 0x141375e50
    void Clear();                                           // 0x1413764c0
    int IsHdrSupported(unsigned int nLevel);               // 0x141376510
    int IsMirrorSupported(unsigned int nLevel);            // 0x141376580
    int IsShimmerSupported(unsigned int nLevel);           // 0x1413765f0
    int GetMultisample(unsigned int nLevel);                // 0x141376660
    int GetMultisampleIndex(unsigned int nLevel);           // 0x141376720
    int GetMultisampleValue(int nIndex);                    // 0x141376790
    unsigned int FindLevel(int nHdr, int nMirror, int nShimmer);    // 0x1413767f0
    int GetShadowOption(int nKind);                         // 0x141376880
    int GetShadowOptionOffset(int nKind);                   // 0x1413769d0

private:
    MS2_LAYOUT_FRIEND;
    TiXmlDocument m_doc;                                    // +0x8
    ATL::CAtlMap<CString, unsigned int, ATL::CStringElementTraits<CString> > m_mapLevel;    // +0x78
    ATL::CAtlMap<CString, int, ATL::CStringElementTraits<CString> > m_mapShadow1;           // +0xc0
    ATL::CAtlMap<CString, int, ATL::CStringElementTraits<CString> > m_mapShadow2;           // +0x108
    int m_multisample[5];                                   // +0x150
    int m_pad_164;
};
MS2_CHECK_SIZE(CGraphicOptionTable, 0x168);
