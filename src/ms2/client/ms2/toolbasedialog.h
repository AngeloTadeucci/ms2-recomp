// toolbasedialog.h - CToolBaseDialog (RTTI .?AVCToolBaseDialog@@): the MFC base of the client's debug tool dialogs
// (CSoundDlg, CDPSDialog, CLogDialog, ...). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\toolbasedialog.cpp` (0x1418529d0-0x141852c30). Header name assumed; member names are invented.
// It swallows Enter/Escape and remembers whether the dialog window has been created yet.
#pragma once
#include "ms2/ms2layout.h"

class CToolBaseDialog : public CDialog
{
public:
    CToolBaseDialog(UINT nIDTemplate, CWnd* pParent);               // 0x1418529d0
    virtual ~CToolBaseDialog();                                     // 0x141852a30 (deleting dtor 0x141852bd0)

    virtual BOOL Create(UINT nIDTemplate, CWnd* pParentWnd = NULL); // slot 91, 0x141852a60
    virtual BOOL PreTranslateMessage(MSG* pMsg);                    // slot 69, 0x141852ab0
    virtual BOOL OnInitDialog();                                    // slot 96, 0x141852b10

    int IsNotCreated() const;                                       // 0x141852b50
    afx_msg void OnClose();                                         // 0x141852ba0
    DECLARE_MESSAGE_MAP()

public:
    int m_nNotCreated;                                              // +0x130: 1 until OnInitDialog ran, 1 again after WM_CLOSE
    int m_pad_134;
};
MS2_CHECK_SIZE(CToolBaseDialog, 0x138);
