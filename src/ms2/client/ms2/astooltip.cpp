// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASTooltip (item/skill tooltip builder, Scaleform AS bridge).
// MS2-UNIT: ?\astooltip.cpp
// MS2-RANGE: 0x1409c5210-0x1409f00e0 .text$mn
// MS2-RANGE: 0x1400c13a0-0x1400c2000 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x1409ef8a0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\astooltip.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern CStringW FUN_14028de60(int nId);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);
extern CString DAT_143ab45a8;
extern CString DAT_143ab45b0;

// @0x1409c6540
__int64 ASTooltip::FUN_1409c6540()
{
    return m_40;
}
MS2_REPLACE_METHOD(0x1409C6540, ASTooltip, FUN_1409c6540, 15, 0x8B0075C1);

// @0x1409c6560
unsigned ASTooltip::FUN_1409c6560()
{
    return m_48;
}
MS2_REPLACE_METHOD(0x1409C6560, ASTooltip, FUN_1409c6560, 14, 0x921EE467);

// @0x1409c6580
void ASTooltip::FUN_1409c6580(unsigned n)
{
    m_48 = n;
}
MS2_REPLACE_METHOD(0x1409C6580, ASTooltip, FUN_1409c6580, 22, 0x6608447B);

// @0x1409c65a0
void ASTooltip::FUN_1409c65a0()
{
    FUN_1407cbb20("enableUseDbClick", FUN_14028de60(0x762));
}
MS2_REPLACE_METHOD(0x1409C65A0, ASTooltip, FUN_1409c65a0, 66, 0xFCB30E07);

// @0x1409c65f0
void ASTooltip::FUN_1409c65f0(const CStringW& strText)
{
    FUN_1407cbb20("enableUseDbClick", strText);
}
MS2_REPLACE_METHOD(0x1409C65F0, ASTooltip, FUN_1409c65f0, 72, 0x638B88F9);

// @0x1409c6880
void ASTooltip::FUN_1409c6880()
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enablePuton", FUN_14028de60(0x751));
}
MS2_REPLACE_METHOD(0x1409C6880, ASTooltip, FUN_1409c6880, 85, 0xF4AF37A1);

// @0x1409c68e0
void ASTooltip::FUN_1409c68e0()
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enableCompareSwap", FUN_14028de60(0x765));
}
MS2_REPLACE_METHOD(0x1409C68E0, ASTooltip, FUN_1409c68e0, 85, 0xE798AF82);

// @0x1409c6940
void ASTooltip::FUN_1409c6940(const CStringW& strText)
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enableLClick", strText);
}
MS2_REPLACE_METHOD(0x1409C6940, ASTooltip, FUN_1409c6940, 91, 0x7BDAE921);

// @0x1409c69b0
void ASTooltip::FUN_1409c69b0(const CStringW& strTitle)
{
    if (m_48 & 0x100)
        return;
    FUN_1407cbb20("enablePuton", strTitle);
}
MS2_REPLACE_METHOD(0x1409C69B0, ASTooltip, FUN_1409c69b0, 91, 0x3AB5F601);

// @0x1409c6c80
void ASTooltip::FUN_1409c6c80()
{
    FUN_1407cbbe0("closeButton", true);
}
MS2_REPLACE_METHOD(0x1409C6C80, ASTooltip, FUN_1409c6c80, 34, 0x29258324);

// @0x1409c6cb0
void ASTooltip::FUN_1409c6cb0(const CStringW& strText)
{
    FUN_1407cbb20(DAT_143ab45a8, strText);
}
MS2_REPLACE_METHOD(0x1409C6CB0, ASTooltip, FUN_1409c6cb0, 81, 0x1E6A3D31);

// @0x1409c6d10
void ASTooltip::FUN_1409c6d10(const CString& str)
{
    FUN_1407cba60(DAT_143ab45a8, str);
}
MS2_REPLACE_METHOD(0x1409C6D10, ASTooltip, FUN_1409c6d10, 81, 0xB4DE3543);

// @0x1409c6d70
void ASTooltip::FUN_1409c6d70(const CString& strClass)
{
    FUN_1407cba60("tooltip", strClass);
}
MS2_REPLACE_METHOD(0x1409C6D70, ASTooltip, FUN_1409c6d70, 72, 0xEDA57631);

// @0x1409c6dc0
void ASTooltip::FUN_1409c6dc0(int n)
{
    FUN_1409eb310(DAT_143ab45b0, n);
}
MS2_REPLACE_METHOD(0x1409C6DC0, ASTooltip, FUN_1409c6dc0, 49, 0x3D4B1FA2);

// @0x1409c6e00
void ASTooltip::FUN_1409c6e00(int n)
{
    FUN_1407cb9c0("onDelay", n);
}
MS2_REPLACE_METHOD(0x1409C6E00, ASTooltip, FUN_1409c6e00, 40, 0x4B5EE22C);

// @0x1409c6e30
void ASTooltip::FUN_1409c6e30(int n)
{
    FUN_1407cb9c0("offDelay", n);
}
MS2_REPLACE_METHOD(0x1409C6E30, ASTooltip, FUN_1409c6e30, 40, 0xB08E9A97);

// @0x1409c6e60
void ASTooltip::FUN_1409c6e60(int n)
{
    FUN_1407cb9c0("offsetX", n);
}
MS2_REPLACE_METHOD(0x1409C6E60, ASTooltip, FUN_1409c6e60, 40, 0xFF9581A7);

// @0x1409c6e90
void ASTooltip::FUN_1409c6e90(int n)
{
    FUN_1407cb9c0("offsetY", n);
}
MS2_REPLACE_METHOD(0x1409C6E90, ASTooltip, FUN_1409c6e90, 40, 0x0CC6F34F);

// @0x1409c6ec0
void ASTooltip::FUN_1409c6ec0(int n)
{
    FUN_1407cb9c0("maxWidth", n);
}
MS2_REPLACE_METHOD(0x1409C6EC0, ASTooltip, FUN_1409c6ec0, 40, 0xD65BBE56);

// @0x1409eb310
void ASObj::FUN_1409eb310(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}
MS2_REPLACE_METHOD(0x1409EB310, ASObj, FUN_1409eb310, 152, 0x1164D0E6);

extern CString DAT_143ab4580;
extern CString DAT_143ab4588;
extern CString DAT_143ab45c8;

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409c62e0
ASTooltip::ASTooltip(int nMovieId)
    : ASObj(nMovieId)
{
    m_40 = 0;
    m_48 = 0;
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409c6350
ASTooltip::ASTooltip(const Scaleform::GFx::Value& root, int nMovieId)
    : ASObj(root, nMovieId)
{
    m_40 = 0;
    m_48 = 0;
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409c63d0
ASTooltip::ASTooltip(int a1, int a2)
    : ASObj(a2)
{
    m_40 = 0;
    m_48 = a1;
}

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409c6440
ASTooltip::ASTooltip(void* pOwner, int a1, int a2)
    : ASObj(a2)
{
    m_40 = (__int64)pOwner;
    m_48 = a1;
}

// @0x1409c7b10
void ASTooltip::FUN_1409c7b10(CItem* pItem)
{
    if (pItem == 0)
        return;
    CStringW str;
    FUN_1409d95f0(pItem, str);
    FUN_1409d8d90(pItem, str);
    FUN_1409d9330(pItem, str);
    FUN_1409d99a0(pItem, str);
    FUN_1409d9aa0(pItem, str);
    if (str.IsEmpty())
        return;
    FUN_1407cbb20("itemDamage", str);
}
MS2_REPLACE_METHOD(0x1409C7B10, ASTooltip, FUN_1409c7b10, 249, 0x1E53A7AB);

// @0x1409c7c10
void ASTooltip::FUN_1409c7c10(CItem* pItem)
{
    FUN_1407cbb20(DAT_143ab4580, pItem->FUN_140527b10());
}
MS2_REPLACE_METHOD(0x1409C7C10, ASTooltip, FUN_1409c7c10, 80, 0x3F6AE606);

// @0x1409c7c70
void ASTooltip::FUN_1409c7c70(CItem* pItem)
{
    FUN_1409adc90(DAT_143ab4588, pItem->FUN_140526bd0());
}
MS2_REPLACE_METHOD(0x1409C7C70, ASTooltip, FUN_1409c7c70, 66, 0xFE5BD3AD);

// @0x1409c7f70
void ASTooltip::FUN_1409c7f70(CItem* pItem)
{
    FUN_1407cb9c0(DAT_143ab45c8, pItem->FUN_140528840());
}
MS2_REPLACE_METHOD(0x1409C7F70, ASTooltip, FUN_1409c7f70, 66, 0xDD1978AD);

// @0x1409c7fc0
void ASTooltip::FUN_1409c7fc0(CItem* pItem)
{
    if ((m_48 & 0x800) != 0 && (m_48 & 0x10000) == 0)
        FUN_1409cc090(pItem);
    else
        FUN_1409c9170(pItem);
}
MS2_REPLACE_METHOD(0x1409C7FC0, ASTooltip, FUN_1409c7fc0, 85, 0xF8318C61);

// @0x1409e13a0
void ASTooltip::FUN_1409e13a0(CItem* pCompare, CItem* pItem)
{
    unsigned nFlags = FUN_1409c6560();
    FUN_1409e13f0(pCompare, pItem, nFlags, nFlags);
}
MS2_REPLACE_METHOD(0x1409E13A0, ASTooltip, FUN_1409e13a0, 71, 0x2CE140FC);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409e25e0
bool ASTooltip::FUN_1409e25e0(CItem* pItem, unsigned n)
{
    if (FUN_1409e0d40(pItem) == 0)
        return false;
    FUN_1409cf010(pItem, n);
    return true;
}
MS2_REPLACE_METHOD(0x1409E25E0, ASTooltip, FUN_1409e25e0, 72, 0x15346D77);

// @0x1409e26b0
int ASTooltip::FUN_1409e26b0(const CStringW& strText)
{
    if (strText.IsEmpty())
        return 0;
    FUN_1409c6d70("export_common_tooltip_tooltipText");
    FUN_1409c6cb0(strText);
    FUN_1409c6e00(300);
    FUN_1409c6e30(60000);
    return 1;
}
MS2_REPLACE_METHOD(0x1409E26B0, ASTooltip, FUN_1409e26b0, 146, 0x067A651D);

struct Unk_CommandStrings { CStringW FUN_141811980(int, int); };
Unk_CommandStrings* FUN_1401a9d70();
extern CString DAT_143ab4590;
extern CString DAT_143ab4550;
extern CString DAT_143ab4558;

// @0x1409d4350
void ASTooltip::FUN_1409d4350(CItemData* pData)
{
    if (pData == 0)
        return;
    FUN_1407cbbe0(DAT_143ab4590, pData->FUN_14053d990());
}
MS2_REPLACE_METHOD(0x1409D4350, ASTooltip, FUN_1409d4350, 78, 0xFE2943FA);

// @0x1409d43b0
void ASTooltip::FUN_1409d43b0(CItem* pItem)
{
    FUN_1409d74a0(pItem->FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1409D43B0, ASTooltip, FUN_1409d43b0, 41, 0x6D4FFE0F);

// @0x1409d43e0
void ASTooltip::FUN_1409d43e0(CItem* pItem)
{
    if (pItem->FUN_140525640() != 0)
    {
        FUN_1409adc90(DAT_143ab4550, pItem->FUN_140526bd0());
        FUN_1407cb9c0(DAT_143ab4558, 1);
    }
}
MS2_REPLACE_METHOD(0x1409D43E0, ASTooltip, FUN_1409d43e0, 112, 0x67EE15C6);

// @0x1409d4460
void ASTooltip::FUN_1409d4460(CItem* pItem)
{
    FUN_1409d8300(pItem->FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1409D4460, ASTooltip, FUN_1409d4460, 41, 0xA7E502CD);

// @0x1409d46a0
void ASTooltip::FUN_1409d46a0(CItem* pItem)
{
    if (pItem == 0)
        return;
    FUN_1409d77b0(pItem->FUN_1405276c0());
}
MS2_REPLACE_METHOD(0x1409D46A0, ASTooltip, FUN_1409d46a0, 51, 0x7A950BD3);

// @0x1409d5530
void ASTooltip::FUN_1409d5530(unsigned nId)
{
    FUN_1407cbb20(DAT_143ab4580, FUN_1401a9d70()->FUN_141811980(1, nId));
}
MS2_REPLACE_METHOD(0x1409D5530, ASTooltip, FUN_1409d5530, 93, 0xF4A248DA);

// MS2-FUNCTIONAL: bytes differ from the exe (operand order / temporaries / SEH state layout); behaviour equivalent
// @0x1409d55a0
void ASTooltip::FUN_1409d55a0(CItem* pItem, int n)
{
    FUN_1409adc90(DAT_143ab4588, n == 0 ? 1 : n);
}
MS2_REPLACE_METHOD(0x1409D55A0, ASTooltip, FUN_1409d55a0, 95, 0x6202B546);

MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);
extern CString DAT_143ab4560;
extern CString DAT_143ab4568;
extern CString DAT_143ab4578;
extern CString DAT_143ab45d0;
extern CString DAT_143ab45d8;
extern CString DAT_143ab45e0;

// @0x1409d5160
void ASTooltip::FUN_1409d5160(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(DAT_143ab4560, sp->FUN_14053cc40());
}
MS2_REPLACE_METHOD(0x1409D5160, ASTooltip, FUN_1409d5160, 139, 0x04E59FDE);

// @0x1409d5200
void ASTooltip::FUN_1409d5200(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(DAT_143ab4568, sp->FUN_14053e130());
}
MS2_REPLACE_METHOD(0x1409D5200, ASTooltip, FUN_1409d5200, 139, 0xDAA972D2);

// @0x1409d52a0
void ASTooltip::FUN_1409d52a0(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(DAT_143ab4578, sp->FUN_14053cf90());
}
MS2_REPLACE_METHOD(0x1409D52A0, ASTooltip, FUN_1409d52a0, 139, 0xFD2B7855);

// @0x1409d5340
void ASTooltip::FUN_1409d5340(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cb9c0(DAT_143ab45d0, sp->FUN_14053ce20() != 0);
}
MS2_REPLACE_METHOD(0x1409D5340, ASTooltip, FUN_1409d5340, 156, 0x2C1CCF54);

// @0x1409d53f0
void ASTooltip::FUN_1409d53f0(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(DAT_143ab45d8, sp->FUN_14053d1f0());
}
MS2_REPLACE_METHOD(0x1409D53F0, ASTooltip, FUN_1409d53f0, 139, 0x2426DEF4);

// @0x1409d5490
void ASTooltip::FUN_1409d5490(unsigned nItemId)
{
    MS2Ptr<CItemData> sp = FUN_14053f870(nItemId);
    if (sp.IsNull())
        return;
    FUN_1407cbbe0(DAT_143ab45e0, sp->FUN_14053d210());
}
MS2_REPLACE_METHOD(0x1409D5490, ASTooltip, FUN_1409d5490, 139, 0x00739E47);
