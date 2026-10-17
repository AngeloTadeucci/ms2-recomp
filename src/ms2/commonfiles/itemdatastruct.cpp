// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The blocks of an item row (citemdata.h: limit, period,
// skill, property, install, effect, function, ...) and the item model block (itemdata.h: ModelPart, ModelGroup,
// ItemModelHead, ItemModelData): constructors, XML readers/writers and comparisons.
// MS2-UNIT: commonfiles\itemdatastruct.cpp
// MS2-RANGE: 0x140543a30-0x140555a70 .text$mn
// MS2-RANGE: 0x1400b9950-0x1400b9a40 .text$di
// MS2-RANGE: 0x142c9ad60-0x142c9ae90 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemdatastruct.cpp"
// The _stricmp calls of this unit go through the IAT, so not ms2/placeholder/ms2stdafx.h (its plain redeclaration).
#include <afx.h>
#include <afxwin.h>
#include "itemdata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// Unrecovered helpers.
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);       // TiXmlElement::Attribute
int ReadSlotAttr(Unk_140165cf0* pElem, const char* pszName, int* pnOut);    // banktable.h: slot name attribute
void FUN_1402c8940(const CString& str, std::vector<CString>& vec, const char* pszDelim);   // split into strings
int FUN_14021bdc0(CString& strName);    // slot name -> slot type
CString FUN_14021c050(int nType);       // slot type -> slot name
CString FUN_14016a5c0(const char* psz, int n);
unsigned FUN_1402227e0(int nJob, int n);    // job -> job flag
void* FUN_14086e000(void* pParent, const void* pChild);                     // InsertEndChild
void FUN_140873bc0(void* pElem, const char* pszName, bool bValue);          // SetAttribute(name, bool)
void FUN_140873ca0(void* pElem, const char* pszName, int nValue);           // SetAttribute(name, int)
void FUN_140873ce0(void* pElem, const char* pszName, unsigned nValue);      // SetAttribute(name, unsigned)
void FUN_140874050(void* pElem, const char* pszName, const CString& strValue);  // SetAttribute(name, string)
void FUN_1408740a0(void* pElem, const char* pszName, const CStringW& strValue); // SetAttribute(name, wide string)
void FUN_140873e30(void* pElem, const char* pszName, float fValue);         // SetAttribute(name, float)
void FUN_140874ad0(void* pElem, const char* pszName, const efd::Point3& kValue);    // SetAttribute(name, "x, y, z")
void FUN_1408746f0(Unk_140165cf0* pElem, const char* pszName, efd::Point3& kOut);   // Point3 attribute
template <class T> bool IsSameArray(const ATL::CAtlArray<T>& a, const ATL::CAtlArray<T>& b);   // additionalactionadditional.cpp

// The game settings: feature switches by number.
class Unk_GameFeatures
{
public:
    bool FUN_14036d570(int nFeature);   // the feature is enabled
};
Unk_GameFeatures* FUN_140166410();

// Unit-local view of the game's TiXmlElement (0x90 bytes).
// TinyXML attribute (only the sentinel of an element's attribute set is touched here).
class Unk_TiXmlAttribute
{
public:
    void* unknown00[7];                         // TiXmlBase, document, name, value, prev
    Unk_TiXmlAttribute* next;                   // +0x38
};
MS2_CHECK_SIZE(Unk_TiXmlAttribute, 0x40);

class Unk_TiXmlAttributeSet
{
public:
    // @0x140552d70
    Unk_TiXmlAttribute* First() { return (sentinel.next == &sentinel) ? 0 : sentinel.next; }
    Unk_TiXmlAttribute sentinel;
};

class Unk_TiXmlElement
{
public:
    Unk_TiXmlElement(const char* pszName);      // 0x14086f2f0
    ~Unk_TiXmlElement();                        // 0x14086f450
    // @0x140552e00
    bool HasAttributes() { return attributeSet.First() == 0 ? false : true; }
    // @0x140552e40
    bool HasChildren() { return firstChild == 0 ? false : true; }
    // @0x140552e70
    bool HasContent() { return HasAttributes() || HasChildren(); }
private:
    void* unknown00[5];                         // TiXmlBase, parent, type
    void* firstChild;                           // +0x28
    void* unknown30[4];                         // lastChild, value, prev, next
    Unk_TiXmlAttributeSet attributeSet;         // +0x50
};
MS2_CHECK_SIZE(Unk_TiXmlElement, 0x90);

// Drops one leading and one trailing comma of a joined list (an inline helper of the XML writers).
inline void TrimCommas(CString& str)
{
    if (!str.IsEmpty())
    {
        if (str[0] == ',')
            str = str.Mid(1);
        if (!str.IsEmpty())
        {
            if (str[str.GetLength() - 1] == ',')
                str = str.Mid(0, str.GetLength() - 1);
        }
    }
}

// The statics of this unit: the item list sort names and the key input controller (both header statics).
#ifndef MS2_HOOK_DLL
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;                // 0x143aaf5a0
#endif

// @0x140543a30
ModelNamedColor::ModelNamedColor()
{
    soft = 0.01f;
    posz = 0;
    zero = 0;
    negz = 0;
}

// @0x140543a90
ModelPart::ModelPart()
    : name0(""), name8(""), name10(""), isNif(0), pony(0), zalign(0), replace(0), earfold(0), ani(0), emotionhide(0),
      gender(2), capscale(1.0f), mantlescale(1.0f), ponyIndex(0), weapon(0), placeable(0), rotationMin(0, 0, 0),
      rotationMax(0, 0, 0)
{
}

// @0x140543ca0
int ModelPart::FUN_140543ca0(Unk_140165cf0* pElem)
{
    FUN_1408733e0(pElem, "name", name0);
    FUN_1408733e0(pElem, "selfnode", name8);
    FUN_1408733e0(pElem, "targetnode", name10);
    FUN_1408733e0(pElem, "attachnode", name18);
    name0.TrimRight();
    if (name0.Right(4) == ".nif")
    {
        isNif = 1;
    }
    else
    {
        isNif = 0;
        if (name0.Find("urn:gamebryo-animation:") == -1)
            name0 = "urn:gamebryo-animation:" + name0;
    }
    FUN_1408731e0(pElem, "pony", pony);
    FUN_140873220(pElem, "zalign", zalign);
    FUN_1408731e0(pElem, "replace", replace);
    FUN_1408731e0(pElem, "earfold", earfold);
    FUN_1408731e0(pElem, "ani", ani);
    FUN_1408731e0(pElem, "emotionhide", emotionhide);
    FUN_140873220(pElem, "gender", gender);
    FUN_140873360(pElem, "capscale", capscale);
    FUN_140873360(pElem, "mantlescale", mantlescale);
    FUN_1408731e0(pElem, "weapon", weapon);
    FUN_1408731e0(pElem, "placeable", placeable);
    for (Unk_140165cf0* pCustom = pElem->FUN_140165cf0("custom"); pCustom != 0;
         pCustom = pCustom->FUN_140168650("custom"))
    {
        MS2Ptr<ItemCustom> spCustom(new ItemCustom);
        spCustom->FUN_140266aa0(pCustom);
        customs.push_back(spCustom);
    }
    for (Unk_140165cf0* pRotation = pElem->FUN_140165cf0("userrotation"); pRotation != 0;
         pRotation = pRotation->FUN_140168650("userrotation"))
    {
        const char* pszAxis = FUN_14086f4b0(pRotation, "axis");
        if (pszAxis != 0)
        {
        if (_stricmp(pszAxis, "x") == 0)
        {
            FUN_140873360(pRotation, "min", rotationMin.x);
            FUN_140873360(pRotation, "max", rotationMax.x);
            ATL::CAtlArray<float> values;
            CString strDefault = FUN_14015f710(pRotation, "default", "");
            XmlSplit(strDefault, values, ",");
            points.resize(values.GetCount());
            for (size_t i = 0; i < points.size(); i++)
                points[i].x = values[i];
        }
        else if (_stricmp(pszAxis, "y") == 0)
        {
            FUN_140873360(pRotation, "min", rotationMin.y);
            FUN_140873360(pRotation, "max", rotationMax.y);
            ATL::CAtlArray<float> values;
            CString strDefault = FUN_14015f710(pRotation, "default", "");
            XmlSplit(strDefault, values, ",");
            points.resize(values.GetCount());
            for (size_t i = 0; i < points.size(); i++)
                points[i].y = values[i];
        }
        else if (_stricmp(pszAxis, "z") == 0)
        {
            FUN_140873360(pRotation, "min", rotationMin.z);
            FUN_140873360(pRotation, "max", rotationMax.z);
            ATL::CAtlArray<float> values;
            CString strDefault = FUN_14015f710(pRotation, "default", "");
            XmlSplit(strDefault, values, ",");
            points.resize(values.GetCount());
            for (size_t i = 0; i < points.size(); i++)
                points[i].z = values[i];
        }
        }
    }
    int nJoint = 0;
    for (Unk_140165cf0* pJoint = pElem->FUN_140165cf0("jointangle"); pJoint != 0;
         pJoint = pJoint->FUN_140168650("jointangle"))
    {
        if (nJoint == 4)
            break;
        const char* pszName = FUN_14086f4b0(pJoint, "name");
        ModelNamedColor& color = colors[nJoint++];
        color.name = pszName;
        FUN_140873360(pJoint, "soft", color.soft);
        FUN_140873360(pJoint, "posz", color.posz);
        FUN_140873360(pJoint, "zero", color.zero);
        FUN_140873360(pJoint, "negz", color.negz);
    }
    {
        CString strCapHair = FUN_14015f710(pElem, "capHair", "");
        ATL::CAtlArray<CString> capHairs;
        FUN_14015f050(strCapHair, capHairs, ",");
        char chKey = 'B';
        for (unsigned i = 0; i < capHairs.GetCount(); i++)
        {
            CString strKey(chKey++, 1);
            properties.insert(std::make_pair(strKey, capHairs[i]));
        }
    }
    for (Unk_140165cf0* pDummy = pElem->FUN_140165cf0("dummy"); pDummy != 0;
         pDummy = pDummy->FUN_140168650("dummy"))
    {
        ModelNameEntry entry;
        entry.FUN_140314350(pDummy);
        if (entry.targetNode.IsEmpty())
            entry.targetNode = name10;
        if (entry.gender == 2)
        {
            entries[0].push_back(entry);
            entries[1].push_back(entry);
        }
        else
        {
            entries[entry.gender].push_back(entry);
        }
    }
    Unk_140165cf0* pPhysX = pElem->FUN_140165cf0("physx");
    if (pPhysX != 0)
    {
        CString strAction = FUN_14015f710(pPhysX, "action", "");
        FUN_1402c8940(strAction, names, ", ");
    }
    return 1;
}

// @0x140544a80
int ModelPart::FUN_140544a80(void* pParent)
{
    return 1;
}

// @0x140544aa0
int ModelPart::FUN_140544aa0(int nGender, int nWeapon) const
{
    if (gender != 2 && gender != nGender)
        return 0;
    if (weapon == 0)
        return 1;
    if (nWeapon == 0)
        return 1;
    if (weapon != nWeapon)
        return 0;
    return 1;
}

// @0x140544b10
ModelFloatList::ModelFloatList() : maxValue(1.0f), minValue(0), reverse(0)
{
}

// @0x140544b70
int ModelFloatList::FUN_140544b70(Unk_140165cf0* pElem)
{
    XmlTokenList(pElem, "value", values);
    FUN_140873360(pElem, "min", minValue);
    FUN_140873360(pElem, "max", maxValue);
    FUN_1408731e0(pElem, "reverse", reverse);
    return 1;
}

// @0x140544c00
int ModelFloatList::FUN_140544c00(void* pParent)
{
    return 1;
}

// @0x140544c20
float ModelFloatList::FUN_140544c20() const
{
    if (values.empty())
        return 1.0f;
    return values[rand() % (int)values.size()];
}

// @0x140544ca0
ModelGroup::ModelGroup()
{
    type = 0;
}

// @0x140544cf0
void ModelGroup::FUN_140544cf0(Unk_140165cf0* pElem)
{
    ReadSlotAttr(pElem, "name", &type);
    int nPony = 0;
    for (Unk_140165cf0* pAsset = pElem->FUN_140165cf0("asset"); pAsset != 0;
         pAsset = pAsset->FUN_140168650("asset"))
    {
        parts.push_back(ModelPart());
        ModelPart* pPart = &parts[parts.size() - 1];
        pPart->FUN_140543ca0(pAsset);
        if (pPart->pony != 0)
            pPart->ponyIndex = nPony++;
    }
    for (Unk_140165cf0* pScale = pElem->FUN_140165cf0("scale"); pScale != 0;
         pScale = pScale->FUN_140168650("scale"))
    {
        floats.push_back(ModelFloatList());
        ModelFloatList* pFloats = &floats[floats.size() - 1];
        pFloats->FUN_140544b70(pScale);
    }
}

// @0x140544f00
void ModelGroup::FUN_140544f00(void* pParent)
{
}

// @0x140544f20
const ModelFloatList* ModelGroup::FUN_140544f20(size_t nIndex) const
{
    static ModelFloatList s_empty;
    if (nIndex < floats.size())
        return &floats[nIndex];
    return &s_empty;
}

// @0x140544fe0
const ModelPart* ModelGroup::FUN_140544fe0(size_t nIndex) const
{
    static ModelPart s_empty;
    if (nIndex < parts.size())
        return &parts[nIndex];
    return &s_empty;
}

// @0x140545090
size_t ModelGroup::FUN_140545090() const
{
    return floats.size();
}

// @0x1405450c0
size_t ModelGroup::FUN_1405450c0() const
{
    return parts.size();
}

// @0x1405450f0
float ModelGroup::FUN_1405450f0(int nIndex) const
{
    return FUN_140544f20(nIndex)->FUN_140544c20();
}

// @0x140545130
void ModelGroup::FUN_140545130(const CString& strName)
{
    for (unsigned i = 0; i < parts.size(); i++)
        parts[i].name0 = strName;
}

// @0x1405451a0
int ModelGroup::FUN_1405451a0() const
{
    return type;
}

// @0x1405451c0
int FUN_1405451c0(CString& strName)
{
    return FUN_14021bdc0(strName);
}

// @0x1405451e0
CString FUN_1405451e0(int nType)
{
    return FUN_14021c050(nType);
}

// @0x140545220
ItemLimit::ItemLimit()
    : levelLimit(1), genderLimit(2), transferType(ItemTransferTypeNone), transferTypeVersion(0), shopSell(false),
      enableBreak(ItemEnableBreakNone), enableRegisterMeratMarket(false), exceptEnchant(false), flag6a(false),
      wedding(false), vipLevel(0)
{
}

// @0x1405452f0
int ItemLimit::FUN_1405452f0(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pLimit = pElem->FUN_140165cf0("limit");
    if (pLimit != 0)
    {
        FUN_140873220(pLimit, "genderLimit", genderLimit);
        FUN_140873220(pLimit, "levelLimit", levelLimit);
        XmlValue(pLimit, "transferType", transferType);
        FUN_1408731e0(pLimit, "transferTypeVersion", transferTypeVersion);
        if (FUN_140166410()->FUN_14036d570(0x84) && FUN_14086f4b0(pLimit, "globalTransferType") != 0)
            XmlValue(pLimit, "globalTransferType", transferType);
        FUN_1408730a0(pLimit, "shopSell", shopSell);
        XmlValue(pLimit, "enableBreak", enableBreak);
        FUN_1408730a0(pLimit, "enableRegisterMeratMarket", enableRegisterMeratMarket);
        FUN_1408730a0(pLimit, "exceptEnchant", exceptEnchant);
        FUN_1408730a0(pLimit, "vip", flag6a);
        FUN_1408730a0(pLimit, "wedding", wedding);
        FUN_1408731e0(pLimit, "vipLevel", vipLevel);
        XmlTokenList(pLimit, "jobLimit", jobLimit);
        XmlTokenList(pLimit, "disableJobLimit", disableJobLimit);
        XmlTokenList(pLimit, "recommendJobs", recommendJobs);
    }
    return 1;
}

// @0x140545510
int ItemLimit::FUN_140545510(void* pParent)
{
    static ItemLimit s_default;
    if (FUN_140545a80(&s_default))
        return 1;
    Unk_TiXmlElement elem("limit");
    if (jobLimit.GetCount() > 0)
    {
        CString str;
        for (size_t i = 0; i < jobLimit.GetCount(); i++)
            str.AppendFormat(",%d", jobLimit[i]);
        TrimCommas(str);
        FUN_140874050(&elem, "jobLimit", str);
    }
    if (disableJobLimit.GetCount() > 0)
    {
        CString str;
        for (size_t i = 0; i < disableJobLimit.GetCount(); i++)
            str.AppendFormat(",%d", disableJobLimit[i]);
        TrimCommas(str);
        FUN_140874050(&elem, "disableJobLimit", str);
    }
    if (recommendJobs.size() > 0)
    {
        CString str;
        for (std::set<int>::iterator it = recommendJobs.begin(); it != recommendJobs.end(); ++it)
            str.AppendFormat(",%d", *it);
        TrimCommas(str);
        FUN_140874050(&elem, "recommendJobs", FUN_14016a5c0(str, 0));
    }
    if (levelLimit != 1)
        FUN_140873ce0(&elem, "levelLimit", levelLimit);
    if (genderLimit != 2)
        FUN_140873ce0(&elem, "genderLimit", genderLimit);
    if (transferType != ItemTransferTypeNone)
        FUN_140873ca0(&elem, "transferType", transferType);
    if (transferTypeVersion > 0)
        FUN_140873ca0(&elem, "transferTypeVersion", transferTypeVersion);
    if (shopSell)
        FUN_140873bc0(&elem, "shopSell", shopSell);
    if (enableBreak != ItemEnableBreakNone)
        FUN_140873ca0(&elem, "enableBreak", enableBreak);
    if (enableRegisterMeratMarket)
        FUN_140873bc0(&elem, "enableRegisterMeratMarket", enableRegisterMeratMarket);
    if (exceptEnchant)
        FUN_140873bc0(&elem, "exceptEnchant", exceptEnchant);
    if (flag6a)
        FUN_140873bc0(&elem, "vip", flag6a);
    if (wedding)
        FUN_140873bc0(&elem, "wedding", wedding);
    if (vipLevel != 0)
        FUN_140873ca0(&elem, "vipLevel", vipLevel);
    FUN_14086e000(pParent, &elem);
    return 1;
}

// @0x140545a80
bool ItemLimit::FUN_140545a80(const ItemLimit* pOther)
{
    return !FUN_140545ad0(pOther);
}

// @0x140545ad0
bool ItemLimit::FUN_140545ad0(const ItemLimit* pOther)
{
    if (genderLimit != pOther->genderLimit)
        return true;
    if (levelLimit != pOther->levelLimit)
        return true;
    if (transferType != pOther->transferType)
        return true;
    if (transferTypeVersion != pOther->transferTypeVersion)
        return true;
    if (shopSell != pOther->shopSell)
        return true;
    if (enableBreak != pOther->enableBreak)
        return true;
    if (enableRegisterMeratMarket != pOther->enableRegisterMeratMarket)
        return true;
    if (exceptEnchant != pOther->exceptEnchant)
        return true;
    if (flag6a != pOther->flag6a)
        return true;
    if (wedding != pOther->wedding)
        return true;
    if (vipLevel != pOther->vipLevel)
        return true;
    if (!IsSameArray(jobLimit, pOther->jobLimit))
        return true;
    if (!IsSameArray(disableJobLimit, pOther->disableJobLimit))
        return true;
    if (recommendJobs != pOther->recommendJobs)
        return true;
    return false;
}

// @0x140545c80
bool ItemLimit::FUN_140545c80(int nJob)
{
    if (nJob == 0)
        return false;
    for (unsigned i = 0; i < disableJobLimit.GetCount(); i++)
    {
        unsigned nDisabled = disableJobLimit[i];
        if (nDisabled == nJob)
            return false;
    }
    if (nJob == 1)
        nJob = 10;
    for (unsigned i = 0; i < jobLimit.GetCount(); i++)
    {
        unsigned nLimit = jobLimit[i];
        if (nLimit == 0)
            return true;
        if (nLimit == 1)
            return true;
        if (nLimit == nJob)
            return true;
    }
    return jobLimit.IsEmpty();
}

// @0x140545da0
bool ItemLimit::FUN_140545da0(int nJob)
{
    if (recommendJobs.empty())
        return true;
    if (nJob == 1)
        nJob = 10;
    if (recommendJobs.find(nJob) != recommendJobs.end())
        return true;
    return false;
}

// @0x140545e40
bool ItemLimit::FUN_140545e40()
{
    if (disableJobLimit.IsEmpty() && jobLimit.IsEmpty())
        return false;
    if (!disableJobLimit.IsEmpty())
        return true;
    if (!jobLimit.IsEmpty())
    {
        for (unsigned i = 0; i < jobLimit.GetCount(); i++)
        {
            unsigned nLimit = jobLimit[i];
            if (nLimit == 0)
                return false;
            if (nLimit == 1)
                return false;
        }
        return true;
    }
    return false;
}

// @0x140545f30
bool ItemLimit::FUN_140545f30()
{
    switch (transferType)
    {
    case 0:
    case 3:
    case 4:
    case 5:
        return true;
    }
    return false;
}

// @0x140545f70
unsigned ItemLimit::FUN_140545f70()
{
    if (recommendJobs.empty())
        return 0xfff;
    unsigned nFlags = 0;
    for (int nJob : recommendJobs)
        nFlags |= FUN_1402227e0(nJob, 0);
    return nFlags;
}

// @0x140546030
unsigned ItemLimit::FUN_140546030()
{
    if (jobLimit.IsEmpty())
        return 0;
    unsigned nFlags = 0;
    size_t nCount = jobLimit.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        unsigned nJob = jobLimit[i];
        if (nJob == 0)
            return 0xfff;
        nFlags |= FUN_1402227e0(nJob, 0);
    }
    return nFlags;
}

// @0x1405460f0
ItemPeriod::ItemPeriod() : usePeriod(0), expirationType(ItemExpirationTypeNone), numberOfWeeksMonths(0)
{
}

// @0x140546150
int ItemPeriod::FUN_140546150(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pLife = pElem->FUN_140165cf0("life");
    if (pLife != 0)
    {
        ATL::CAtlArray<int> values;
        CString strExpiration;
        FUN_1408731e0(pLife, "usePeriod", usePeriod);
        FUN_1408733e0(pLife, "expirationPeriod", strExpiration);
        XmlSplit(strExpiration, values, "-");
        if (values.GetCount() == 6)
            expiration = CMsTime(values[0], values[1], values[2], values[3], values[4], values[5]);
        XmlValue(pLife, "expirationType", expirationType);
        FUN_140873220(pLife, "numberOfWeeksMonths", numberOfWeeksMonths);
        FUN_140873420(pLife, "termTag", termTag);
    }
    return 1;
}

// @0x140546370
int ItemPeriod::FUN_140546370(void* pParent)
{
    if (usePeriod == 0 && expiration.Get() == 0 && expirationType == ItemExpirationTypeNone && numberOfWeeksMonths == 0 &&
        termTag.IsEmpty())
        return 1;
    Unk_TiXmlElement elem("life");
    if (usePeriod > 0)
        FUN_140873ca0(&elem, "usePeriod", usePeriod);
    CString strExpiration("");
    if (expiration.Get() > 0)
    {
        strExpiration.Format("%04d-%02d-%02d-%02d-%02d-%02d", expiration.GetYear(), expiration.GetMonth(),
                             expiration.GetDay(), expiration.GetHour(), expiration.GetMinute(), expiration.GetSecond());
    }
    if (!strExpiration.IsEmpty())
        FUN_140874050(&elem, "expirationPeriod", strExpiration);
    if (expirationType != ItemExpirationTypeNone)
        FUN_140873ca0(&elem, "expirationType", expirationType);
    if (numberOfWeeksMonths != 0)
        FUN_140873ce0(&elem, "numberOfWeeksMonths", numberOfWeeksMonths);
    if (!termTag.IsEmpty())
        FUN_1408740a0(&elem, "termTag", termTag);
    FUN_14086e000(pParent, &elem);
    return 1;
}

// @0x140546620
bool ItemPeriod::FUN_140546620(const ItemPeriod* pOther)
{
    if (usePeriod != pOther->usePeriod)
        return true;
    if (expiration != pOther->expiration)
        return true;
    if (expirationType != pOther->expirationType)
        return true;
    if (numberOfWeeksMonths != pOther->numberOfWeeksMonths)
        return true;
    if (termTag != pOther->termTag)
        return true;
    return false;
}

// @0x1405466d0
int ItemPeriod::FUN_1405466d0()
{
    return usePeriod > 0 || expiration.Get() > 0 || expirationType != ItemExpirationTypeNone || !termTag.IsEmpty();
}

// @0x140546740
ItemSkill::ItemSkill() : skillId(0), skillLevel(1)
{
}

// @0x140546770
int ItemSkill::FUN_140546770(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pSkill = pElem->FUN_140165cf0("skill");
    if (pSkill != 0)
    {
        FUN_140873220(pSkill, "skillID", skillId);
        FUN_1408731a0(pSkill, "skillLevel", skillLevel);
    }
    return 1;
}

// @0x1405467f0
int ItemSkill::FUN_1405467f0(void* pParent)
{
    return 1;
}

// @0x140546810
bool ItemSkill::FUN_140546810(const ItemSkill* pOther)
{
    if (skillId != pOther->skillId)
        return true;
    if (skillLevel != pOther->skillLevel)
        return true;
    return false;
}

// @0x140546860
MsTransform::MsTransform()
{
    scale = 1.0f;
}

// @0x1405468d0
void MsTransform::FUN_1405468d0(Unk_140165cf0* pElem)
{
    FUN_1408746f0(pElem, "position", position);
    FUN_1408746f0(pElem, "rotation", rotation);
    FUN_140873360(pElem, "scale", scale);
}

// @0x140546940
void MsTransform::FUN_140546940(void* pElem)
{
    if (position != efd::Point3::ZERO)
        FUN_140874ad0(pElem, "position", position);
    if (rotation != efd::Point3::ZERO)
        FUN_140874ad0(pElem, "rotation", rotation);
    if (scale != 1.0f)
        FUN_140873e30(pElem, "scale", scale);
}

// @0x140546a00
ItemModelHead::ItemModelHead() : flag10(false), flag11(false), unknown14(0), scale(false), rotation(false),
    translation(false), capAttach(false)
{
}

// @0x140546a90
int ItemModelHead::FUN_140546a90(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pCustomize = pElem->FUN_140165cf0("customize");
    if (pCustomize == 0)
        return 1;
    FUN_1408730a0(pCustomize, "color", flag10);
    FUN_140873220(pCustomize, "colorPalette", unknown14);
    CString strIds = FUN_14015f710(pCustomize, "defaultColorIndex", "-1");
    XmlSplit(strIds, ids, ",");
    CString strDelays = FUN_14015f710(pCustomize, "colorDelay", "");
    XmlSplit(strDelays, unknown30, ",");
    FUN_1408730a0(pCustomize, "scale", scale);
    FUN_1408730a0(pCustomize, "rotation", rotation);
    FUN_1408730a0(pCustomize, "translation", translation);
    FUN_1408730a0(pCustomize, "capAttach", capAttach);
    flag11 = ids.size() > 1;
    if (unknown14 == 0)
        flag10 = false;
    Unk_140165cf0* pCapTransform = pCustomize->FUN_140165cf0("capTransform");
    if (pCapTransform != 0)
    {
        handle.AssignRaw(new MsTransform);
        handle->FUN_1405468d0(pCapTransform);
    }
    return 1;
}

// The joined id/delay lists are built and trimmed but never written (as in the original).
// @0x140546d70
int ItemModelHead::FUN_140546d70(void* pParent)
{
    Unk_TiXmlElement elem("customize");
    if (flag10)
        FUN_140873ca0(&elem, "color", flag10 ? 1 : 0);
    if (unknown14 != 0)
        FUN_140873ce0(&elem, "colorPalette", unknown14);
    if (ids.size() > 0 && ids[0] != -1)
    {
        CString str;
        for (int nId : ids)
            str.AppendFormat(",%s", nId);
        TrimCommas(str);
    }
    if (unknown30.size() > 0 && unknown30[0] != 0)
    {
        CString str;
        for (int nDelay : unknown30)
            str.AppendFormat(",%s", nDelay);
        TrimCommas(str);
    }
    if (scale)
        FUN_140873ca0(&elem, "scale", 1);
    if (rotation)
        FUN_140873ca0(&elem, "rotation", 1);
    if (translation)
        FUN_140873ca0(&elem, "translation", 1);
    if (capAttach)
        FUN_140873ca0(&elem, "capAttach", 1);
    if (handle.get() != 0)
    {
        Unk_TiXmlElement transform("transform");
        handle->FUN_140546940(&transform);
        if (transform.HasContent())
            FUN_14086e000(&elem, &transform);
    }
    if (elem.HasContent())
        FUN_14086e000(pParent, &elem);
    return 1;
}

// @0x140547130
bool ItemModelHead::FUN_140547130()
{
    return scale;
}

// @0x140547150
bool ItemModelHead::FUN_140547150()
{
    return rotation;
}

// @0x140547170
bool ItemModelHead::FUN_140547170()
{
    return translation;
}

// @0x140547190
bool ItemModelHead::FUN_140547190()
{
    return flag10;
}

// @0x1405471b0
bool ItemModelHead::FUN_1405471b0()
{
    return capAttach;
}

// @0x1405471d0
bool ItemModelHead::FUN_1405471d0()
{
    return FUN_140547150() || FUN_140547170() || FUN_140547130();
}

// @0x140547230
bool ItemModelHead::FUN_140547230()
{
    return flag11;
}

// @0x140547250
int ItemModelHead::FUN_140547250()
{
    return unknown14;
}

// @0x140547270
int ItemModelHead::FUN_140547270(int nIndex) const
{
    int nCount = (int)ids.size();
    if (nCount == 0 || nCount <= nIndex)
        return -1;
    return ids[nIndex];
}

// @0x1405472d0
int ItemModelHead::FUN_1405472d0(int nIndex) const
{
    int nCount = (int)unknown30.size();
    if (nCount == 0 || nCount <= nIndex)
        return 0;
    return unknown30[nIndex];
}

// @0x140547330
size_t ItemModelHead::FUN_140547330()
{
    return ids.size();
}

// @0x140547360
MsTransform* ItemModelHead::FUN_140547360()
{
    return handle.get();
}

// @0x140547390
ItemMaterial::ItemMaterial()
{
    unknown0 = 0;
    attack = 0;
}

// @0x1405473c0
int ItemMaterial::FUN_1405473c0(Unk_140165cf0* pElem)
{
    Unk_140165cf0* pMaterial = pElem->FUN_140165cf0("material");
    if (pMaterial != 0)
    {
        FUN_1408731e0(pMaterial, "ui", unknown0);
        FUN_1408731e0(pMaterial, "attack", attack);
    }
    return 1;
}

// @0x140547440
int ItemMaterial::FUN_140547440(void* pParent)
{
    return 1;
}

// @0x140547460
bool ItemMaterial::FUN_140547460(const ItemMaterial* pOther)
{
    if (unknown0 != pOther->unknown0)
        return true;
    if (attack != pOther->attack)
        return true;
    return false;
}
