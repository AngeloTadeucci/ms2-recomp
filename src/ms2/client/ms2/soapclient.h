// soapclient.h - CSoapResult (RTTI .?AVCSoapResult@@, 0x28 bytes), the answer of one CSoapClient upload request:
// a result code and a text. The class CSoapClient itself is the shared placeholder ms2/placeholder/csoapclient.h.
// Header name assumed; member names invented from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CSoapResult : public CPtred
{
public:
    CSoapResult();                                          // 0x1417728a0 (result 1, empty text)
    CSoapResult(int nResult, const CString& strText);              // 0x141772820
                                                            // implicit virtual dtor 0x141772a40 (??_G 0x141772d20)

    int m_nResult;                                          // +0x18 (0 = ok)
    CString m_strText;                                      // +0x20
};
MS2_CHECK_SIZE(CSoapResult, 0x28);
MS2_CHECK_OFFSET(CSoapResult, m_strText, 0x20);
