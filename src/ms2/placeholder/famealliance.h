// The alliance (faction) and season ids of the fame tables (commonfiles\famegradedata.cpp), shared with the quest data
// (CQuestData::m_4c, CQuestData::Require::m_alliance). Enums rather than ints: the exe's ATL containers take them by
// reference (a primitive int key would be passed by value), so the key traits are the default ones.
#pragma once
enum Unk_FameAlliance { Unk_FameAlliance_None };    // 1..9 are alliances, 10 ends the table
enum Unk_FameSeason { Unk_FameSeason_None };
