// systemmailcontent.h - CSystemMailContent (RTTI .?AVCSystemMailContent@@, 0x50 bytes): one <mail> row of the system mail
// text table systemMailContent.xml (<mail id sender subject content/>). A cached data record (CCacheData +0, CValidData +0x28).
// Owning unit: ?\systemmailcontent.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CSystemMailContent : public CCacheData, public CValidData<CSystemMailContent>
{
public:
    typedef MS2Ptr<CSystemMailContent> Ptr;

    CSystemMailContent();                       // 0x140851620
    virtual ~CSystemMailContent();              // 0x1408516c0 (??_G 0x1408523a0)

    static Ptr GetMail(int nId);                // 0x140851e50 the mail text by id (reloads when the file changed)
    static void CheckInit();                    // 0x1408523e0
    static void SetInit(bool b);                // 0x1408532b0

    static bool s_bInit;                        // 0x143ab1ca0

    int m_nId;                                  // +0x30 "id"
    CStringW m_strSender;                       // +0x38 "sender"
    CStringW m_strSubject;                      // +0x40 "subject"
    CStringW m_strContent;                      // +0x48 "content"
};
MS2_CHECK_SIZE(CSystemMailContent, 0x50);
MS2_CHECK_OFFSET(CSystemMailContent, m_nId, 0x30);
MS2_CHECK_OFFSET(CSystemMailContent, m_strContent, 0x48);
