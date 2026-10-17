// cashchargedialog.h - CCashChargeDialog (RTTI .?AVCCashChargeDialog@@): the modal dialog (resource 0x94) that hosts an
// IE WebBrowser control (0x4d4) for the cash charge page. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the
// unit is `?\cashchargedialog.cpp` (0x140b04a50-0x140b055c0). Header name assumed; member names are invented from use.
#pragma once
#include <afxdialogex.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cexplorer1.h"

class CCashChargeDialog : public CDialogEx
{
    DECLARE_DYNAMIC(CCashChargeDialog)
public:
    CCashChargeDialog(CWnd* pParent);                               // 0x140b04a70
    virtual ~CCashChargeDialog();                                   // 0x140b04af0 (deleting dtor 0x140b05240)

    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66
    virtual BOOL PreTranslateMessage(MSG* pMsg);                    // slot 69
    virtual BOOL OnInitDialog();                                    // slot 96

    void Navigate(CString strUrl);                                  // 0x140b04c40
    void CenterOnScreen();                                          // 0x140b04cf0

    afx_msg void OnClose();                                         // WM_CLOSE, 0x140b04ed0
    void OnWindowClosing(BOOL bIsChildWindow, BOOL* pbCancel);      // 0x140b04f40
    void OnNavigateComplete2(LPDISPATCH pDisp, VARIANT* pURL);      // 0x140b04e90 (empty)
    void OnDocumentComplete(LPDISPATCH pDisp, VARIANT* pURL);       // 0x140b04eb0 (empty)
    DECLARE_MESSAGE_MAP()
    DECLARE_EVENTSINK_MAP()

public:
    CString m_strUrl;                                               // +0x170
    CExplorer1 m_explorer;                                          // +0x178 DDX 0x4d4
};
MS2_CHECK_SIZE(CCashChargeDialog, 0x288);
