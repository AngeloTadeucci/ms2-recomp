// ctextlogfile.h - PLACEHOLDER for CTextLogFile (RTTI .?AVCTextLogFile@@, vftable 0x142d9b308, deleting dtor 0x140867dc0): the
// crash-report log file object. NOT an original header; only what filebuffer.cpp#2 (CFileLogger) touches is named. The
// unit that owns the code is ?\textlogfile.cpp (0x140866b00-0x1408686b0, unrecovered). CPtred-derived, 0x58 bytes.
// Layout from ctor 0x140866b40: m_name (CStringW) at +0x18, two 16-byte line lists at +0x20 and +0x30 (ctor
// 0x140867b00), the byte limit pair at +0x40/+0x48 (-1 = unlimited) and a dword (0x18) at +0x50.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CTextLogFile : public CPtred
{
public:
    explicit CTextLogFile(const wchar_t* pszName);          // 0x140866b40
    virtual ~CTextLogFile();                                // 0x140866c00

    void FUN_140866c70();                                   // write the file next to the exe and drop the lines
    void FUN_140866f60(const char* pszLine);                // add a line to the first list
    void FUN_140867020(const char* pszLine);                // add a line to the second list
    void FUN_1408670e0(const CString& strLine);             // as 0x140866f60 for a CString
    void FUN_140867180(const CString& strLine);             // as 0x140867020 for a CString
    void FUN_140867220();                                   // clear the second list
    void FUN_140867260(unsigned long long nLimit);                // set the byte limit
    const CStringW& FUN_140867310() const;                  // the file name

private:
    MS2_LAYOUT_FRIEND;
    CStringW m_name;                                        // +0x18
    char m_pad_20[0x58 - 0x20];
};
MS2_CHECK_SIZE(CTextLogFile, 0x58);
