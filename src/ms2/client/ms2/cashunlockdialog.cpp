// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's cashunlockdialog.cpp: the cash unlock web dialog.
// MS2-UNIT: ?\cashunlockdialog.cpp
// MS2-RANGE: 0x140b0dc70-0x140b0e5f0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ?GetRuntimeClass@CCashUnlockDialog@@UEBAPEAUCRuntimeClass@@XZ 0x140b0dc70
// MS2-PIN: ?GetMessageMap@CCashUnlockDialog@@MEBAPEBUAFX_MSGMAP@@XZ 0x140b0e060
// MS2-PIN: ?GetEventSinkMap@CCashUnlockDialog@@MEBAPEBUAFX_EVENTSINKMAP@@XZ 0x140b0e100
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cashunlockdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <exdisp.h>
#include <mshtml.h>
#include "cashunlockdialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

struct UICashShopDialog;

// A smart handle (0x20 bytes, the pointee at +8) the UI manager hands out for a dialog id.
struct Unk_CashShopRef
{
    void* m_unk0;
    UICashShopDialog* m_pDialog;
    void* m_unk10;
    void* m_unk18;
    Unk_CashShopRef(UICashShopDialog* pDialog);                     // 0x140b05020
    ~Unk_CashShopRef();                                             // 0x140b05080
    UICashShopDialog* Get() const;                                  // 0x140b051c0
    UICashShopDialog* GetDialog() const;                            // 0x140b051d0
};
MS2_CHECK_SIZE(Unk_CashShopRef, 0x20);

UICashShopDialog* FUN_140b04f80(int nId);                           // the UICashShopDialog with the id
void FUN_141035970(UICashShopDialog* pDialog, int nArg);
void* FUN_140aadf80();                                              // the screen
void FUN_140ad4c30(void* pScreen, RECT* pRect);                     // the screen rect
void FUN_140b053f0(CWnd* pWnd, RECT* pRect);                        // GetWindowRect
void FUN_14098a440(CDialogEx* pDlg, CDataExchange* pDX);
void FUN_14098a5d0(CWnd* pWnd);

IMPLEMENT_DYNAMIC(CCashUnlockDialog, CDialogEx)

// The UCRT's header-inline memcpy_s / memmove_s of this TU (0x140b0e380 / 0x140b0e4d0), kept alive through ATL::Checked.
// @0x140b0e380
#pragma function(memset, memcpy)
static __inline errno_t ms2_cud_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnCudMemcpyS)(void*, size_t, const void*, size_t) = &ms2_cud_memcpy_s;
MS2_EMIT_CRT_MEMMOVE_S();

// @0x140b0dc90
CCashUnlockDialog::CCashUnlockDialog(CWnd* pParent)
    : CDialogEx(0x96, pParent)
{
}

// @0x140b0dd10
CCashUnlockDialog::~CCashUnlockDialog()
{
}

// @0x140b0dd70
BOOL CCashUnlockDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    if (m_strUrl.IsEmpty())
        m_strUrl = "about:blank";
    m_explorer.Navigate(m_strUrl, 0, 0, 0, 0);
    return 1;
}

// @0x140b0de10
BOOL CCashUnlockDialog::PreTranslateMessage(MSG* pMsg)
{
    if (pMsg->wParam == 0xd || pMsg->wParam == 0x1b)
        return 1;
    return CDialog::PreTranslateMessage(pMsg);
}

// @0x140b0de60
void CCashUnlockDialog::Navigate(CString strUrl)
{
    if (strUrl.IsEmpty())
        return;
    m_strUrl = strUrl;
    m_explorer.Navigate(m_strUrl, 0, 0, 0, 0);
}

// @0x140b0df10
// MS2-FUNCTIONAL: the exe folds the MoveWindow arguments without the temporaries cl keeps here
void CCashUnlockDialog::CenterOnScreen()
{
    RECT rcScreen;
    RECT rcWindow;
    FUN_140ad4c30(FUN_140aadf80(), &rcScreen);
    FUN_140b053f0(this, &rcWindow);
    MoveWindow(((rcScreen.right - rcScreen.left) - (rcWindow.right - rcWindow.left)) / 2 + rcScreen.left,
               ((rcScreen.bottom - rcScreen.top) - (rcWindow.bottom - rcWindow.top)) / 2 + rcScreen.top,
               rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top, 1);
}

// @0x140b0e000
void CCashUnlockDialog::DoDataExchange(CDataExchange* pDX)
{
    FUN_14098a440(this, pDX);
    DDX_Control(pDX, 0x4d5, m_explorer);
}

BEGIN_MESSAGE_MAP(CCashUnlockDialog, CDialogEx)
    ON_WM_CLOSE()
END_MESSAGE_MAP()

// @0x140b0e080
// MS2-FUNCTIONAL: cl reserves 0x10 more frame bytes than the exe for the same locals
void CCashUnlockDialog::OnClose()
{
    {
        Unk_CashShopRef ref(FUN_140b04f80(0x4ebc));
        if (ref.Get() != 0)
            FUN_141035970(ref.GetDialog(), 0);
    }
    FUN_14098a5d0(this);
}

BEGIN_EVENTSINK_MAP(CCashUnlockDialog, CDialogEx)
    ON_EVENT(CCashUnlockDialog, 0x4d5, 0x107, CCashUnlockDialog::OnWindowClosing, VTS_BOOL VTS_PBOOL)
    ON_EVENT(CCashUnlockDialog, 0x4d5, 0xfc, CCashUnlockDialog::OnNavigateComplete2, VTS_DISPATCH VTS_PVARIANT)
    ON_EVENT(CCashUnlockDialog, 0x4d5, 0x103, CCashUnlockDialog::OnDocumentComplete, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()

// @0x140b0e120
void CCashUnlockDialog::OnWindowClosing(BOOL bIsChildWindow, BOOL* pbCancel)
{
    if (bIsChildWindow == 0)
    {
        *pbCancel = -1;
        ::SendMessageA(m_hWnd, WM_CLOSE, 0, 0);
    }
}

// @0x140b0e170
void CCashUnlockDialog::OnNavigateComplete2(LPDISPATCH pDisp, VARIANT* pURL)
{
}

// @0x140b0e190
// MS2-FUNCTIONAL: the exe's first QueryInterface call passes a fifth argument (a different wrapper than the plain COM call)
void CCashUnlockDialog::OnDocumentComplete(LPDISPATCH pDisp, VARIANT* pURL)
{
    IWebBrowser2* pBrowser = 0;
    pDisp->QueryInterface(IID_IWebBrowser2, (void**)&pBrowser);
    IDispatch* pDocDisp = 0;
    pBrowser->get_Document(&pDocDisp);
    if (pDocDisp != 0)
    {
        VARIANT vUnused;
        VariantInit(&vUnused);
        IHTMLDocument2* pDoc = 0;
        pDocDisp->QueryInterface(IID_IHTMLDocument2, (void**)&pDoc);
        IHTMLElement* pBody = 0;
        pDoc->get_body(&pBody);
        IHTMLBodyElement* pBodyElement = 0;
        pBody->QueryInterface(IID_IHTMLBodyElement, (void**)&pBodyElement);
        if (pBodyElement != 0)
        {
            pBodyElement->put_scroll(SysAllocString(L"no"));
            pBodyElement->Release();
        }
        pBody->Release();
        pDoc->Release();
        pDocDisp->Release();
    }
    pBrowser->Release();
}
