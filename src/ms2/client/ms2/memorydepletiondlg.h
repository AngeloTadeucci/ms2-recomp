// memorydepletiondlg.h - the client's memory-depletion and error-notification dialogs. CMemoryDepletionDlg (RTTI
// .?AVCMemoryDepletionDlg@@) is the modal dialog of resource 3000 shown when the client runs out of memory: one text
// control bound with DDX_Text (0x40b) and one link control (0x40a) whose NM_CLICK opens the Nexon help page in the
// browser. CErrorNotificationDlg (RTTI .?AVCErrorNotificationDlg@@) is the plain notification dialog of resource
// 0xbb9 with a single DDX_Text text link (0x40c). Both derive from CDialogEx and are closed with the CDialog OK
// handler. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\memorydepletiondlg.cpp`
// (0x140d53490-0x140d53ad0 .text$mn, dir client\ms2). Header name assumed; member and handler names invented from use.
#pragma once
#include <afxdialogex.h>
#include <afxcmn.h>

#include "ms2/ms2layout.h"

// 0x180 = CDialogEx (0x170) + the text CString (8) + the "help page was opened" flag (4, padded).
class CMemoryDepletionDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CMemoryDepletionDlg)
public:
    CMemoryDepletionDlg(CWnd* pParent);                             // 0x140d534b0 (resource 3000)
    virtual ~CMemoryDepletionDlg();                                 // 0x140d53520 (deleting dtor 0x140d53950)

    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66, 0x140d535a0

    void FUN_140d53570(CString strText);                            // 0x140d53570: takes a text by value, body empty

    afx_msg void OnBnClickedOk();                                   // 0x140d53620: command 8, opens the help page, closes
    afx_msg void OnClickLink(NMHDR* pNMHDR, LRESULT* pResult);      // 0x140d53680: NM_CLICK of the link control 0x40a
    afx_msg void OnBnClickedHelp();                                 // 0x140d53700: command 10, opens the help page
    DECLARE_MESSAGE_MAP()

public:
    CString m_strText;                                              // +0x170 DDX_Text 0x40b
    int m_bHelpOpened;                                              // +0x178 0 when closed, 1 once the help page was opened
};
MS2_CHECK_SIZE(CMemoryDepletionDlg, 0x180);

// 0x178 = CDialogEx (0x170) + the one text CString (8).
class CErrorNotificationDlg : public CDialogEx
{
    DECLARE_DYNAMIC(CErrorNotificationDlg)
public:
    CErrorNotificationDlg(CWnd* pParent);                           // 0x140d537a0 (resource 0xbb9)
    virtual ~CErrorNotificationDlg();                               // 0x140d53800 (deleting dtor 0x140d538f0)

    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66, 0x140d53850

    afx_msg void OnBnClickedOk();                                   // 0x140d538d0: command 11
    DECLARE_MESSAGE_MAP()

public:
    CString m_strText;                                              // +0x170 DDX_Text 0x40c
};
MS2_CHECK_SIZE(CErrorNotificationDlg, 0x178);
