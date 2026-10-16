// chatemoticontable.h - the chat emoticon tables (RTTI names ChatEmoticonData, ChatEmoticonCategoryData,
// ChatEmoticonCachedData, CChatEmoticonTable). Loaded from Table/chatEmoticon.xml (<chatEmoticon id category_id group_id
// image_path height width vspace/>), chatEmoticonCategory.xml (<chatEmoticonCategory id icon_path/>) and
// stringChatEmoticon.xml (<key id name command/>), then cross-linked by FUN_1401e6a40 (category -> emoticons).
// Header name assumed (unit 0x1401e5760-0x1401f7ee0 is commonfiles\chatemoticontable.cpp, not yet recovered); member names
// are inferred from the xml attributes. Shared by UIChatEmoticonDialog and the chat emoticon client state.
#pragma once
#include <afx.h>
#include <list>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"

// One emoticon (<chatEmoticon>). RTTI ChatEmoticonData, 0x48 bytes, base CPtred; vftable 0x142cf0...(1 slot: dtor).
class ChatEmoticonData : public CPtred
{
public:
    ChatEmoticonData();                     // 0x1401e57f0
    virtual ~ChatEmoticonData();            // 0x1401e58a0

    int m_nId;                              // +0x18 "id"
    int m_nGroupId;                         // +0x1c "group_id" (the emoticon pack, see CChatEmoticonCli)
    CStringW m_strImagePath;                // +0x20 "image_path"
    int m_nCategoryId;                      // +0x28 "category_id"
    int m_nHeight;                          // +0x2c "height"
    int m_nWidth;                           // +0x30 "width"
    int m_nVSpace;                          // +0x34 "vspace" (ctor 0xfffffffd)
    CStringW m_strName;                     // +0x38 stringChatEmoticon "name"
    CStringW m_strCommand;                  // +0x40 stringChatEmoticon "command" (rewritten to ":{0}:")
};
MS2_CHECK_SIZE(ChatEmoticonData, 0x48);
MS2_CHECK_OFFSET(ChatEmoticonData, m_strImagePath, 0x20);
MS2_CHECK_OFFSET(ChatEmoticonData, m_nVSpace, 0x34);
MS2_CHECK_OFFSET(ChatEmoticonData, m_strCommand, 0x40);

typedef MS2SvrPtr<ChatEmoticonData> ChatEmoticonDataPtr;

// One category tab (<chatEmoticonCategory>). RTTI ChatEmoticonCategoryData, 0x28 bytes, base CPtred.
class ChatEmoticonCategoryData : public CPtred
{
public:
    ChatEmoticonCategoryData();             // 0x1401e5760 region (ctor not separately listed)
    virtual ~ChatEmoticonCategoryData();    // 0x1401e57b0

    int m_nId;                              // +0x18 "id"
    CStringW m_strIconPath;                 // +0x20 "icon_path"
};
MS2_CHECK_SIZE(ChatEmoticonCategoryData, 0x28);
MS2_CHECK_OFFSET(ChatEmoticonCategoryData, m_strIconPath, 0x20);

typedef MS2SvrPtr<ChatEmoticonCategoryData> ChatEmoticonCategoryDataPtr;

// The loaded set (new'd and zero-filled by FUN_1401e7040). RTTI ChatEmoticonCachedData, 0x68 bytes, base CPtred.
class ChatEmoticonCachedData : public CPtred
{
public:
    ChatEmoticonCachedData();               // 0x1401f0420 (the five containers are default constructed)
    virtual ~ChatEmoticonCachedData();      // 0x1401f0950 region

    MS2SvrPtr<CCacheData> m_spCache;                                        // +0x18 remembers chatEmoticonCategory.xml's path / time
    std::map<int, ChatEmoticonDataPtr> m_emoticons;                         // +0x28 id -> emoticon
    std::map<int, ChatEmoticonCategoryDataPtr> m_categories;                // +0x38 id -> category
    std::map<int, std::list<ChatEmoticonDataPtr> > m_byCategory;            // +0x48 category id -> its emoticons
    std::map<CStringW, ChatEmoticonDataPtr> m_byCommand;                    // +0x58 ":{0}:" command -> emoticon
};
MS2_CHECK_SIZE(ChatEmoticonCachedData, 0x68);
MS2_CHECK_OFFSET(ChatEmoticonCachedData, m_emoticons, 0x28);
MS2_CHECK_OFFSET(ChatEmoticonCachedData, m_byCommand, 0x58);

typedef MS2SvrPtr<ChatEmoticonCachedData> ChatEmoticonCachedDataPtr;

class CChatEmoticonTable;

// This instantiation stores the complete object pointer; DAT_143aac658 (getter FUN_1409eecd0).
template <> class TSingleton<CChatEmoticonTable>
{
public:
    TSingleton();                           // 0x1401ef7d0
    virtual ~TSingleton() { s_instance = 0; }   // 0x1401f0560
    static CChatEmoticonTable* s_instance;
};

// The table. RTTI CChatEmoticonTable, 0x20 bytes: TSingleton +0 (vftable 0x142cf...), CValidData +8, the loaded data +0x10.
class CChatEmoticonTable : public TSingleton<CChatEmoticonTable>, public CValidData<CChatEmoticonTable>
{
public:
    CChatEmoticonTable();                   // 0x1401e6f70
    virtual ~CChatEmoticonTable();          // 0x1401e6fe0

    bool Load();                                                    // 0x1401e7040 (name invented): builds and swaps in a new cached set
    ChatEmoticonDataPtr FUN_1401e7120(int nEmoticonId);             // emoticon by id (null when missing)
    ChatEmoticonCategoryDataPtr FUN_1401e7270(int nCategoryId);     // category by id (null when missing)
    void FUN_1401e73c0(int nCategoryId, std::list<ChatEmoticonDataPtr>* pOut);   // copy of the emoticons of a category
    ChatEmoticonCachedDataPtr FUN_1401e76a0();                      // the current cached set

    ChatEmoticonCachedDataPtr m_spData;     // +0x10
};
MS2_CHECK_SIZE(CChatEmoticonTable, 0x20);
MS2_CHECK_OFFSET(CChatEmoticonTable, m_spData, 0x10);
