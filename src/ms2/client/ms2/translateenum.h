// translateenum.h - CToolBlockFileModifyDialog (RTTI .?AVCToolBlockFileModifyDialog@@): the tool dialog of resource id
// 0xa2 with two text boxes (0x4f0, 0x470) and an OK button that hands both strings to the block-file modifier. Recovered
// from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `client\ms2\translateenum.cpp` (0x140cbf600-0x140cbfd50
// .text$mn), whose last function is the dungeon-group enum translator. Header name assumed.
#pragma once
#include <afxdialogex.h>

#include "ms2/ms2layout.h"

// CDialogEx and nothing else (no members of its own).
class CToolBlockFileModifyDialog : public CDialogEx
{
    DECLARE_DYNAMIC(CToolBlockFileModifyDialog)
public:
    CToolBlockFileModifyDialog(CWnd* pParent);                      // 0x140cbf620
    virtual ~CToolBlockFileModifyDialog();                          // 0x140cbf670 (deleting dtor 0x140cbf7e0)

    virtual void DoDataExchange(CDataExchange* pDX);                // slot 66, 0x140cbf6a0

    afx_msg void OnBnClickedOk();                                   // 0x140cbf700
    DECLARE_MESSAGE_MAP()
};
