// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's toolprogressdlg.cpp: CToolProgressDlg, the
// tool dialog of resource 0x90 that shows one progress bar (control 0x4cd). The dialog has no tool frame of its own,
// so it derives from CDialog; the OK and Cancel commands are handled locally and forwarded to the CDialog defaults.
// See toolprogressdlg.h.
// MS2-UNIT: ?\toolprogressdlg.cpp
// MS2-RANGE: 0x141855360-0x1418555f0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\toolprogressdlg.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "toolprogressdlg.h"

#include "hook/ms2hook.h"

IMPLEMENT_DYNAMIC(CToolProgressDlg, CDialog)

// @0x141855380
CToolProgressDlg::CToolProgressDlg(CWnd* pParent) : CDialog(0x90, pParent)
{
}

// @0x1418553e0
CToolProgressDlg::~CToolProgressDlg()
{
}

// @0x141855420
void CToolProgressDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, 0x4cd, m_prgProgress);
}

BEGIN_MESSAGE_MAP(CToolProgressDlg, CDialog)
    ON_COMMAND(IDOK, &CToolProgressDlg::OnBnClickedOk)
    ON_COMMAND(IDCANCEL, &CToolProgressDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

// @0x1418554a0
void CToolProgressDlg::OnBnClickedOk()
{
    OnOK();
}

// @0x1418554d0
void CToolProgressDlg::OnBnClickedCancel()
{
    OnCancel();
}
