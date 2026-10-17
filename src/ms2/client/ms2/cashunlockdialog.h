// cashunlockdialog.h - CCashUnlockDialog (RTTI .?AVCCashUnlockDialog@@): the modal dialog (resource 0x96) that hosts an
// IE WebBrowser control (0x4d5) for the cash unlock page. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the
// unit is `?\cashunlockdialog.cpp` (0x140b0dc70-0x140b0e5f0). Header name assumed; member names are invented from use.
#pragma once
#include <afxdialogex.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cexplorer1.h"

class CCashUnlockDialog : public CDialogEx
{
    DECLARE_DYNAMIC(CCashUnlockDialog)
public:
    CCashUnlockDialog(CWnd* pParent);                               // 0x140b0dc90
    virtual ~CCashUnlockDialog();                                   // 0x140b0dd10 (deleting dtor 0x140b0e320)

    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66
    virtual BOOL PreTranslateMessage(MSG* pMsg);                    // slot 69
    virtual BOOL OnInitDialog();                                    // slot 96

    void Navigate(CString strUrl);                                  // 0x140b0de60
    void CenterOnScreen();                                          // 0x140b0df10

    afx_msg void OnClose();                                         // WM_CLOSE, 0x140b0e080
    void OnWindowClosing(BOOL bIsChildWindow, BOOL* pbCancel);      // 0x140b0e120
    void OnNavigateComplete2(LPDISPATCH pDisp, VARIANT* pURL);      // 0x140b0e170
    void OnDocumentComplete(LPDISPATCH pDisp, VARIANT* pURL);       // 0x140b0e190
    DECLARE_MESSAGE_MAP()
    DECLARE_EVENTSINK_MAP()

public:
    CString m_strUrl;                                               // +0x170
    CExplorer1 m_explorer;                                          // +0x178 DDX 0x4d5
    char m_unk260[0x28];                                            // +0x260 not touched by the ctor
};
MS2_CHECK_SIZE(CCashUnlockDialog, 0x288);
