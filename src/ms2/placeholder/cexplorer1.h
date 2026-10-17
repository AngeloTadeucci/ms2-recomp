// cexplorer1.h - PLACEHOLDER for CExplorer1 (RTTI .?AVCExplorer1@@, 0xe8 bytes): the MFC ActiveX wrapper for the
// IE WebBrowser control (CLSID 8856F961-340A-11D0-A96B-00C04FD705A2), generated from the type library. NOT an original header.
// Only the pieces the cash-shop dialogs use are declared; the wrapper bodies live in the unit_140d74b20 / cashchargedialog area.
#pragma once

#include <afxwin.h>
#include <afxdisp.h>
#include "ms2/ms2layout.h"

class CExplorer1 : public CWnd
{
public:
    CExplorer1();                                                   // 0x140b05050
    virtual ~CExplorer1();                                          // 0x140b05120 (deleting dtor 0x140b052a0)

    void Navigate(LPCTSTR URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers);   // 0x140b05420, dispid 0x68
};
MS2_CHECK_SIZE(CExplorer1, 0xe8);
