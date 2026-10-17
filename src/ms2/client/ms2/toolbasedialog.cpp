// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's toolbasedialog.cpp: base of the MFC tool dialogs.
// MS2-UNIT: ?\toolbasedialog.cpp
// MS2-RANGE: 0x1418529d0-0x141852c30 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\toolbasedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "toolbasedialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1418529d0
CToolBaseDialog::CToolBaseDialog(UINT nIDTemplate, CWnd* pParent)
    : CDialog(nIDTemplate, pParent)
{
    m_nNotCreated = 1;
}

// @0x141852a30
CToolBaseDialog::~CToolBaseDialog()
{
}

// @0x141852a60
BOOL CToolBaseDialog::Create(UINT nIDTemplate, CWnd* pParentWnd)
{
    if (IsNotCreated() == 0)
        return 0;
    return CDialog::Create(nIDTemplate, pParentWnd);
}

// @0x141852ab0
BOOL CToolBaseDialog::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_ESCAPE || pMsg->wParam == VK_RETURN))
        return 0;
    return CDialog::PreTranslateMessage(pMsg);
}

// @0x141852b10
BOOL CToolBaseDialog::OnInitDialog()
{
    if (!CDialog::OnInitDialog())
        return 0;
    m_nNotCreated = 0;
    return 1;
}

// @0x141852b50
int CToolBaseDialog::IsNotCreated() const
{
    return m_nNotCreated;
}

BEGIN_MESSAGE_MAP(CToolBaseDialog, CDialog)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

// @0x141852ba0
void CToolBaseDialog::OnClose()
{
    Default();
    m_nNotCreated = 1;
}
