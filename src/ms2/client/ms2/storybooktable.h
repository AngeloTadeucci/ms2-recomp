// storybooktable.h - CStoryBookTable / CStoryBookData / CStoryBookData::BookPage (RTTI names): the story book table read
// from Table/storybook.xml (<book id type><page number string valign image/></book>).
// Header name assumed. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// One <book>. RTTI CStoryBookData, 0x68 bytes, base CPtred, only the deleting destructor is virtual.
class CStoryBookData : public CPtred
{
public:
    // One <page>. RTTI CStoryBookData::BookPage, 0x30 bytes.
    class BookPage : public CPtred
    {
    public:
        BookPage();                         // 0x14180c840
        // implicit virtual dtor (0x14180cb30)

        CStringA m_strImage;                // +0x18 "image" resolved to the resource path
        CStringW m_strText;                 // +0x20 "string"
        CStringA m_strVAlign;               // +0x28 "valign"
    };
    typedef MS2Ptr<BookPage> BookPagePtr;

    CStoryBookData();                       // 0x14180c9b0
    // implicit virtual dtor (0x14180cc00)

    int m_nType;                            // +0x18 1 book, 2 sketchbook, 3 magazine, 4 adpaper
    int m_nMaxPage;                         // +0x1c the highest page number
    ATL::CAtlMap<int, BookPagePtr> m_pages; // +0x20 page number -> page
};
MS2_CHECK_SIZE(CStoryBookData::BookPage, 0x30);
MS2_CHECK_SIZE(CStoryBookData, 0x68);
MS2_CHECK_OFFSET(CStoryBookData, m_pages, 0x20);

typedef MS2Ptr<CStoryBookData> CStoryBookDataPtr;

// The table. RTTI CStoryBookTable, 0x58 bytes: TSingleton +0, CValidData +8 and the id -> book map +0x10. Created by
// CGameApp::InitInstance (?\ms2.cpp).
class CStoryBookTable : public TSingleton<CStoryBookTable>, public CValidData<CStoryBookTable>
{
public:
    CStoryBookTable();                      // 0x14180bc30
    virtual ~CStoryBookTable();             // 0x14180bce0

    void Load();                            // 0x14180bd40 parses the xml into the map
    CStoryBookDataPtr GetData(int nId);     // 0x14180c400 the book for an id (null when missing)
    int GetMaxPage(int nId);                // 0x14180c490 the book's highest page number (0 when missing)

    static void CheckInit();                // 0x14180cea0
    static void SetInit(bool b);            // 0x14180eb20

    static bool s_bInit;                    // DAT_143aeef28

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<int, CStoryBookDataPtr> m_map;     // +0x10 id -> book
};
MS2_CHECK_SIZE(CStoryBookTable, 0x58);
MS2_CHECK_OFFSET(CStoryBookTable, m_map, 0x10);
