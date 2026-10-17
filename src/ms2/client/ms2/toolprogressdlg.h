// toolprogressdlg.h - CToolProgressDlg (RTTI .?AVCToolProgressDlg@@): the tool dialog of resource id 0x90 ("progress"),
// whose only control is the progress bar 0x4cd, followed by the tool look, OK and Cancel buttons. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\toolprogressdlg.cpp` (0x141855360-0x1418555f0 .text$mn,
// dir client\ms2). Header name assumed; member and handler names invented from use.
#pragma once
#include <afxcmn.h>

#include "ms2/ms2layout.h"

// 0x218 = CDialog (0x130) + the one CProgressCtrl member (0xe8). Not a CToolBaseDialog: it has no tool frame state.
class CToolProgressDlg : public CDialog
{
    DECLARE_DYNAMIC(CToolProgressDlg)
public:
    CToolProgressDlg(CWnd* pParent);                                // 0x141855380
    virtual ~CToolProgressDlg();                                    // 0x1418553e0 (deleting dtor 0x141855590)

    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66, 0x141855420

    afx_msg void OnBnClickedOk();                                   // 0x1418554a0: IDOK
    afx_msg void OnBnClickedCancel();                               // 0x1418554d0: IDCANCEL
    DECLARE_MESSAGE_MAP()

public:
    CProgressCtrl m_prgProgress;                                    // +0x130 DDX 0x4cd
};
MS2_CHECK_SIZE(CToolProgressDlg, 0x218);
