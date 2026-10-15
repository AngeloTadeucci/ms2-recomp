// actioncameradata.h - CActionCameraData (RTTI CActionCameraData, 0x38 bytes, CCacheData-derived): one Camera/<name>.xml
// file (<ms2><actionCamera path stayLocked interpolationTime/></ms2>), cached per name in a static red-black map.
// Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>

// The parsed values at +0x28 (ctor 0x140943e10).
struct ActionCameraInfo
{
    ActionCameraInfo() : m_fInterpolationTime(-1.0f) { m_bStayLocked ^= m_bStayLocked; }   // 0x140943e10

    CString m_strPath;                  // +0x00 "path"
    float m_fInterpolationTime;         // +0x08 "interpolationTime" (-1 = unset)
    unsigned int m_bStayLocked;         // +0x0c "stayLocked" == "true"
};
MS2_CHECK_SIZE(ActionCameraInfo, 0x10);

class CActionCameraData : public CCacheData
{
public:
    typedef MS2Ptr<CActionCameraData> DataPtr;

    CActionCameraData();                // 0x1409436b0
    virtual ~CActionCameraData();       // 0x140943700

    static DataPtr Get(CString strName);                // 0x140943740 cached lookup (reloads a stale entry)
    static DataPtr Load(const CString& strName);        // 0x140943890 reads Camera/<name>

    // @0x140944280
    ActionCameraInfo* GetInfo() { return &m_info; }

    ActionCameraInfo m_info;            // +0x28
};
MS2_CHECK_SIZE(CActionCameraData, 0x38);
MS2_CHECK_OFFSET(CActionCameraData, m_info, 0x28);
