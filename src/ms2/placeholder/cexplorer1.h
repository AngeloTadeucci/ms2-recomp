// cexplorer1.h - PLACEHOLDER for CExplorer1 (RTTI .?AVCExplorer1@@, 0x110 bytes): the MFC ActiveX wrapper of the IE
// WebBrowser control (CLSID 8856F961-340A-11D0-A96B-00C04FD705A2) the Visual Studio "Add Class from TypeLib" wizard
// generates: methods are defined in the class body, so every user TU emits its COMDAT copies (first seen in
// cashchargedialog.cpp, 0x140b05050-0x140b05420). Only the pieces the cash-shop dialogs use are declared. NOT an original header.
#pragma once

#include <afxwin.h>
#include <afxdisp.h>
#include "ms2/ms2layout.h"

class CExplorer1 : public CWnd
{
protected:
    DECLARE_DYNCREATE(CExplorer1)
public:
    CLSID const& GetClsid()                                         // 0x140b053e0
    {
        static CLSID const clsid = { 0x8856f961, 0x340a, 0x11d0, { 0xa9, 0x6b, 0x00, 0xc0, 0x4f, 0xd7, 0x05, 0xa2 } };
        return clsid;
    }
    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
                        UINT nID, CCreateContext* pContext = NULL)  // slot 23, 0x140b05360
    {
        return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
    }
    void Navigate(LPCTSTR URL, VARIANT* Flags, VARIANT* TargetFrameName, VARIANT* PostData, VARIANT* Headers)  // 0x140b05420
    {
        static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT;
        InvokeHelper(0x68, DISPATCH_METHOD, VT_EMPTY, NULL, parms, URL, Flags, TargetFrameName, PostData, Headers);
    }
    char m_unkE8[0x28];                                             // not touched by the ctor
};
MS2_CHECK_SIZE(CExplorer1, 0x110);
