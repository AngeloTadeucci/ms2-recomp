// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Editor-side table exporters of the client: the field meta
// table (xblock/block scan feeding the Unk_FieldIdList maps), the market item SQL, the sound data table.
// MS2-UNIT: client\ms2\tableexporter.cpp
// MS2-RANGE: 0x141821bf0-0x1418379e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$StringFormat@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEB_KAEBV01@@Z 0x141827280 ; unique
// MS2-PIN: ??0?$tuple@$$V@std@@QEAA@AEBV01@@Z 0x141827a30 ; order
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@1@PEAU01@@Z 0x141828100 ; order
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@@?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@1@PEAU01@@Z 0x141828190 ; order
// MS2-PIN: ??$_Kfn@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@?$_Tmap_traits@HV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@3@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@1@@Z 0x14182d160 ; unique
// MS2-PIN: ??$_Kfn@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@?$_Tmap_traits@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@3@$0A@@std@@SAAEBIAEBU?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@1@@Z 0x14182d170 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x14182d990 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@0@AEAPEAU10@@Z 0x14182d9a0 ; order
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@0@AEAPEAU10@@Z 0x14182d9b0 ; order
// MS2-PIN: ??$addressof@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@YAPEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@0@AEAU10@@Z 0x14182d9e0 ; order
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@0@AEAV10@@Z 0x14182da30 ; order
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@0@AEAV10@@Z 0x14182da40 ; order
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x14182daa0 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@1@AEAPEAU31@@Z 0x14182daf0 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@1@@Z 0x14182df10 ; unique
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x14182df30 ; order
// MS2-PIN: ??$destroy@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@1@@Z 0x14182df80 ; order
// MS2-PIN: ??$destroy@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@std@@@1@QEAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x14182dfa0 ; order
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x14182e270 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x14182e280 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14182e2f0 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14182e300 ; unique
// MS2-PIN: ??$forward@AEBH@std@@YAAEBHAEBH@Z 0x14182e310 ; order
// MS2-PIN: ??$forward@AEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@YAAEBU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@0@AEBU10@@Z 0x14182e320 ; order
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14182e340 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14182e350 ; unique
// MS2-PIN: ??$move@AEAV?$tuple@AEBH@std@@@std@@YA$$QEAV?$tuple@AEBH@0@AEAV10@@Z 0x14182e370 ; order
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@1@@Z 0x14182ead0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@QEAA@XZ 0x14182eb10 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@1@@Z 0x14182eb90 ; order
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@1@@Z 0x14182ec70 ; order
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x14182ed30 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@1@@Z 0x14182ed50 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x14182ed90 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@1@@Z 0x14182ee10 ; order
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@QEAA@XZ 0x14182ef30 ; unique
// MS2-PIN: ??0?$allocator@U?$_List_node@UCSoundDataEntry@@PEAX@std@@@std@@QEAA@XZ 0x14182ef60 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14182efb0 ; unique
// MS2-PIN: ??1?$_List_alloc@U?$_List_base_types@UCSoundDataEntry@@V?$allocator@UCSoundDataEntry@@@std@@@std@@@std@@QEAA@XZ 0x14182f440 ; prop
// MS2-PIN: ??1?$_List_buy@UCSoundDataEntry@@V?$allocator@UCSoundDataEntry@@@std@@@std@@QEAA@XZ 0x14182f470 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAA@XZ 0x14182f4f0 ; order
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAA@XZ 0x14182f5e0 ; order
// MS2-PIN: ??1?$list@UCSoundDataEntry@@V?$allocator@UCSoundDataEntry@@@std@@@std@@QEAA@XZ 0x14182f670 ; prop
// MS2-PIN: ??1?$map@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@@std@@QEAA@XZ 0x14182f6e0 ; order
// MS2-PIN: ??1?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@QEAA@XZ 0x14182f740 ; unique
// MS2-PIN: ??1?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@QEAA@XZ 0x14182f760 ; prop
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14182f970 ; order
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14182fb50 ; order
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14182fb90 ; order
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14182fbd0 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@1@XZ 0x14182fe80 ; order
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@1@XZ 0x14182fec0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@1@XZ 0x14182fee0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEBAAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@XZ 0x14182ff20 ; order
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@1@XZ 0x14182ff40 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@1@XZ 0x14182ff60 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@1@XZ 0x14182ff80 ; order
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141830080 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1418300a0 ; order
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141830160 ; order
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x141830180 ; prop
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x141830210 ; order
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141830250 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1418302e0 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141830400 ; order
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1418304b0 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141830590 ; unique
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x141830660 ; prop
// MS2-PIN: ??_G?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@QEAAPEAXI@Z 0x1418309d0 ; unique
// MS2-PIN: ??_G?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@QEAAPEAXI@Z 0x141830a10 ; order
// MS2-PIN: ??_GCAtlStringMgr@ATL@@UEAAPEAXI@Z 0x141830ad0 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@XZ 0x141831f40 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@@Z 0x1418328b0 ; order
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@@Z 0x1418329f0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@2@@Z 0x1418335f0 ; order
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@@Z 0x141834150 ; prop
// MS2-PIN: ?_Freeheadnode@?$_List_alloc@U?$_List_base_types@UCSoundDataEntry@@V?$allocator@UCSoundDataEntry@@@std@@@std@@@std@@QEAAXPEAU?$_List_node@UCSoundDataEntry@@PEAX@2@@Z 0x141834700 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@@Z 0x141834790 ; order
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@@Z 0x141834820 ; order
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@@Z 0x141834850 ; order
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@2@XZ 0x141834a10 ; order
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@H@2@XZ 0x141834ad0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@H@2@XZ 0x141834ae0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x141834af0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x141834b00 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@2@XZ 0x141834b90 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@2@XZ 0x141834ba0 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@2@XZ 0x141834bb0 ; order
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@XZ 0x141834bf0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@XZ 0x141834c10 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@2@XZ 0x141834c20 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@2@$00@2@XZ 0x141834c30 ; order
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@XZ 0x141834ca0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@2@XZ 0x141834cb0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@2@XZ 0x141834cc0 ; order
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@2@XZ 0x141834dd0 ; unique
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@2@XZ 0x141834e00 ; order
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x141834f20 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@XZ 0x1418351b0 ; order
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@@Z 0x141835380 ; order
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@@Z 0x141835460 ; order
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@PEAU32@@Z 0x141835540 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@PEAU32@@Z 0x141835570 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@PEAU32@@Z 0x1418355a0 ; order
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@SAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@PEAU32@@Z 0x1418355d0 ; order
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@PEAU32@@Z 0x141835600 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@PEAU32@@Z 0x141835630 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@SAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@PEAU32@@Z 0x141835690 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@XZ 0x141835860 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@XZ 0x141835880 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@XZ 0x1418358e0 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@XZ 0x141835900 ; order
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@@Z 0x141835ae0 ; order
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEAX@2@@Z 0x141835bc0 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@IEAAXXZ 0x141835d60 ; order
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@_K@Z 0x141835f10 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@_K@Z 0x141835f40 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@2@XZ 0x1418360b0 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@@5@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@@std@@@std@@@2@XZ 0x141836190 ; prop
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x141836200 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAAXXZ 0x1418363b0 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAAXXZ 0x1418364f0 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@2@_K@Z 0x1418366d0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@PEAX@2@_K@Z 0x141836700 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@2@XZ 0x141836910 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@@5@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_SoundTag@@@std@@@std@@@std@@@2@XZ 0x1418369d0 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@XZ 0x141836a30 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@2@0@Z 0x141836dd0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@@std@@@2@@Z 0x141836ec0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@V32@0@Z 0x141837110 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@V32@@Z 0x141837200 ; prop
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@PEAX@std@@@2@@Z 0x1418377d0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@SAPEAU?$pair@$$CBHV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@2@AEAU32@@Z 0x1418378a0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@std@@@std@@SAPEAU?$pair@$$CBIV?$Unk_FieldPtr@V?$CAtlList@IV?$CElementTraits@I@ATL@@@ATL@@@@@2@AEAU32@@Z 0x1418378c0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@std@@@std@@SAPEAU?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$set@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@U?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$allocator@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@4@@std@@@2@AEAU32@@Z 0x1418378e0 ; order
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\tableexporter.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <atlfile.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/commonfiles/sounddatatable.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/soundservice.h"
#include "ms2/placeholder/fmodwrap.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
class Unk_ExportLog;                                            // the editor progress log window
Unk_ExportLog* FUN_141168200();
void FUN_141168270(Unk_ExportLog*);
void FUN_141168580(Unk_ExportLog*, int);
void FUN_1411683e0(Unk_ExportLog*, const char*);                // append a line
int FUN_1406516c0();                                            // current language id
CSoundDataTable* FUN_1414a57c0();
CSoundService* FUN_140c9cb10();

class Unk_SoundMgr
{
public:
    FMOD::EventGroup* FUN_14177d6e0(const char* pszGroup, int bLoad);
    void FUN_14177d9b0(const char* pszGroup, Unk_StrVec& rNames);   // event names of a group
};
Unk_SoundMgr* FUN_140d13c40();

typedef std::map<CString, std::set<CString> > Unk_VoiceGroupMap;   // trigger voice group -> sub sound names
class Unk_VoiceMgr
{
public:
    void FUN_141793210(Unk_VoiceGroupMap& rOut);
};
Unk_VoiceMgr* FUN_1411b1de0();

class Unk_140165cf0;
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);
Unk_140165cf0* FUN_140165cf0(Unk_140165cf0* pParent, const char* pszName);       // FirstChildElement
Unk_140165cf0* FUN_140168650(Unk_140165cf0* pElem, const char* pszName);         // NextSiblingElement
const char* FUN_14086f4b0(Unk_140165cf0*, const char*);         // attribute text
void FUN_14086e580(Unk_140165cf0* pParent, Unk_140165cf0* pChild);  // RemoveChild
void FUN_140870f90(TiXmlDocument* pDoc);                        // SaveFile
CString FUN_140188f50(const char* psz, int n);
CString FUN_14016a5c0(const char* psz, int n);
void FUN_14015f050(CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);
CString FUN_14038f6d0(const CString& str, const char* psz);     // str + psz
CString FUN_1401d2b10(const CString& a, const CString& b);      // a + b

// Model manager (editor side), 0xa8 bytes.
class Unk_ModelMgr
{
public:
    Unk_ModelMgr();                                             // 0x140a2a0a0
    ~Unk_ModelMgr();                                            // 0x140a2a140
    void* m_pad[0x15];
};
MS2_CHECK_SIZE(Unk_ModelMgr, 0xa8);
int FUN_140a2a180();                                            // loads the model tables
int FUN_140a2a920(Unk_ModelMgr* pMgr, const CString& strModel, CString strFilter);

// Containers filled by the field meta table export.
typedef std::map<unsigned int, Unk_FieldIdListPtr> Unk_FieldMapA;
typedef std::map<int, Unk_FieldIdListPtr> Unk_FieldMapB;
typedef std::map<CStringA, Unk_SoundTag> Unk_SoundTagMap;

// the sound service's tag map, +0x58
// @0x1418315f0
static const Unk_SoundTagMap& Unk_GetSoundTags(CSoundService* pService)
{
    return pService->m_mapTags;
}

int FUN_141827210(ATL::CAtlArray<CString>& rArray, const CString& str);

// Removes the named <property> children from every xblock / block entity whose model the model manager knows.
// MS2-FUNCTIONAL: instruction sequence matches but stack frame is 0x20 larger than the exe
// @0x141821bf0
void FUN_141821bf0(CString strModelFilter, CString strDeleteProps)
{
    FUN_141168270(FUN_141168200());
    FUN_141168580(FUN_141168200(), 1);
    FUN_1411683e0(FUN_141168200(), "Export FieldMetaTable");
    FUN_1411683e0(FUN_141168200(), "Read Model....");
    Unk_ModelMgr mgr;
    if (FUN_140a2a180() == 0) {
        MessageBoxA(NULL, "Fail to initialize Model Manager.", "Error", 0);
        return;
    }
    FUN_1411683e0(FUN_141168200(), "Read Model Complete");

    ATL::CAtlArray<CString> props;
    FUN_14015f050(strDeleteProps, props, ",");

    ATL::CAtlArray<CString> xblocks;
    FUN_140399100(".xblock", "./Data/Resource/Exported/XBlock", xblocks, "", false);
    for (size_t i = 0; i < xblocks.GetCount(); i++) {
        TiXmlDocument doc;
        int nDeleted = 0;
        if (FUN_140166420()->FUN_1403974b0(&doc, xblocks[i], 0, true, false) == 0)
            continue;
        Unk_140165cf0* pGame = FUN_140165cf0(&doc, "game");
        if (pGame == NULL)
            continue;
        Unk_140165cf0* pEntitySet = FUN_140165cf0(pGame, "entitySet");
        if (pEntitySet == NULL)
            continue;
        FUN_1411683e0(FUN_141168200(), StringFormat("{0} Read xblock {1}", i, xblocks[i]));
        for (Unk_140165cf0* pEntity = FUN_140165cf0(pEntitySet, "entity"); pEntity != NULL;
             pEntity = FUN_140168650(pEntity, "entity")) {
            CString strModel = FUN_140188f50(FUN_14086f4b0(pEntity, "modelName"), 0);
            if (FUN_140a2a920(&mgr, strModel, strModelFilter) != 0) {
                for (Unk_140165cf0* pProp = FUN_140165cf0(pEntity, "property"); pProp != NULL;
                     pProp = FUN_140168650(pProp, "property")) {
                    CString strName = FUN_140188f50(FUN_14086f4b0(pProp, "name"), 0);
                    if (FUN_141827210(props, strName) != -1) {
                        FUN_14086e580(pEntity, pProp);
                        nDeleted++;
                    }
                }
            }
        }
        if (nDeleted > 0) {
            FUN_140870f90(&doc);
            FUN_1411683e0(FUN_141168200(), StringFormat("{0} Save file. deleted {1} property ", xblocks[i], nDeleted));
        }
    }

    ATL::CAtlArray<CString> blocks;
    FUN_140399100(".block", "./Data/Resource/Block", blocks, "", false);
    for (size_t i = 0; i < blocks.GetCount(); i++) {
        TiXmlDocument doc;
        int nDeleted = 0;
        if (FUN_140166420()->FUN_1403974b0(&doc, blocks[i], 0, true, false) == 0)
            continue;
        Unk_140165cf0* pBlock = FUN_140165cf0(&doc, "block");
        if (pBlock == NULL)
            continue;
        Unk_140165cf0* pEntities = FUN_140165cf0(pBlock, "entities");
        if (pEntities == NULL)
            continue;
        FUN_1411683e0(FUN_141168200(), StringFormat("{0} Read block {1}", i, blocks[i]));
        for (Unk_140165cf0* pEntity = FUN_140165cf0(pEntities, "entity"); pEntity != NULL;
             pEntity = FUN_140168650(pEntity, "entity")) {
            CString strModel = FUN_140188f50(FUN_14086f4b0(pEntity, "model-name"), 0);
            if (FUN_140a2a920(&mgr, strModel, strModelFilter) != 0) {
                Unk_140165cf0* pProps = FUN_140165cf0(pEntity, "properties");
                if (pProps != NULL) {
                    for (Unk_140165cf0* pProp = FUN_140165cf0(pProps, "property"); pProp != NULL;
                         pProp = FUN_140168650(pProp, "property")) {
                        CString strName = FUN_140188f50(FUN_14086f4b0(pProp, "name"), 0);
                        if (FUN_141827210(props, strName) != -1) {
                            FUN_14086e580(pProps, pProp);
                            nDeleted++;
                        }
                    }
                }
            }
        }
        if (nDeleted > 0) {
            FUN_140870f90(&doc);
            FUN_1411683e0(FUN_141168200(), StringFormat("{0} Save file. deleted {1} property ", blocks[i], nDeleted));
        }
    }
    MessageBoxA(NULL, "Complete!", "", 0);
}

// index of the first string equal to str in the array, -1 if absent
// @0x141827210
int FUN_141827210(ATL::CAtlArray<CString>& rArray, const CString& str)
{
    for (int i = 0; i < (int)rArray.GetCount(); i++) {
        if (rArray[i] == str)
            return i;
    }
    return -1;
}

// Event sounds of one FMOD event group, with their lengths.
// @0x141825f60
void FUN_141825f60(const CString& strGroup, CSoundDataTable::SoundList& rOut)
{
    FMOD::EventGroup* pGroup = FUN_140d13c40()->FUN_14177d6e0(strGroup, 1);
    if (pGroup == NULL) {
        MS2_ASSERT_AT(0x3d4, 0);
        return;
    }
    Unk_StrVec names;
    FUN_140d13c40()->FUN_14177d9b0(strGroup, names);
    int nCount = (int)names.FUN_14028b4c0();
    for (int i = 0; i < nCount; i++) {
        CString& strName = *names.FUN_14027f1c0(i);
        FMOD::Event* pEvent = NULL;
        if (pGroup->getEvent(strName, FMOD_EVENT_INFOONLY, &pEvent) != FMOD_OK) {
            MS2_ASSERT_AT(0x3e2, 0);
            return;
        }
        if (pEvent == NULL) {
            MS2_ASSERT_AT(1000, 0);
            return;
        }
        int nIndex = 0;
        char* pszName = NULL;
        FMOD_EVENT_INFO info;
        if (pEvent->getInfo(&nIndex, &pszName, &info) != FMOD_OK) {
            MS2_ASSERT_AT(0x3f1, 0);
            return;
        }
        CString strPath = FUN_1401d2b10(FUN_14038f6d0(strGroup, "/"), strName);
        CSoundDataEntry entry;
        entry.nType = 0;
        entry.strName = strPath;
        entry.nLengthMs = info.lengthms;
        rOut.push_back(entry);
    }
}

// Programmer sounds: every tag of the sound service.
// @0x141826260
void FUN_141826260(CSoundDataTable::SoundList& rOut)
{
    const Unk_SoundTagMap& tags = Unk_GetSoundTags(FUN_140c9cb10());
    const Unk_SoundTagMap& range = tags;
    Unk_SoundTagMap::const_iterator itEnd = range.end();
    for (Unk_SoundTagMap::const_iterator it = range.begin(); it != itEnd; ++it) {
        const Unk_SoundTagMap::value_type& tag = *it;
        const CStringA& strName = tag.first;
        const Unk_SoundTag& info = tag.second;
        CSoundDataEntry entry;
        entry.nType = 1;
        entry.strName = strName;
        entry.nLengthMs = info.m_uLength;
        rOut.push_back(entry);
    }
}

// Trigger voice sounds: the longest sub sound of each group.
// @0x141826360
void FUN_141826360(CSoundDataTable::SoundList& rOut)
{
    Unk_VoiceGroupMap groups;
    FUN_1411b1de0()->FUN_141793210(groups);
    Unk_VoiceGroupMap& range = groups;
    Unk_VoiceGroupMap::const_iterator itEnd = range.end();
    for (Unk_VoiceGroupMap::const_iterator it = range.begin(); it != itEnd; ++it) {
        const Unk_VoiceGroupMap::value_type& group = *it;
        const CString& strGroup = group.first;
        const std::set<CString>& names = group.second;
        int nLength = 0;
        const std::set<CString>& rangeNames = names;
        std::set<CString>::const_iterator itNameEnd = rangeNames.end();
        for (std::set<CString>::const_iterator itName = rangeNames.begin(); itName != itNameEnd; ++itName) {
            CString strSub = *itName;
            size_t nBank = 0;
            int nSub = FUN_140c9cb10()->FUN_1417b04d0(strSub, &nBank);
            nLength = (std::max)(nSub, nLength);
        }
        CSoundDataEntry entry;
        entry.nType = 2;
        entry.strName = strGroup;
        entry.nLengthMs = nLength;
        rOut.push_back(entry);
    }
}

// Rewrites Table/soundDataTable_<language>.xml from the FMOD event groups, sound tags and trigger voices.
// @0x141825d60
bool FUN_141825d60(bool bMessageBox)
{
    bool bOk = true;
    int nLanguage = FUN_1406516c0();
    FUN_1414a57c0()->SetLanguage(nLanguage);
    FUN_1411683e0(FUN_141168200(), "Export SoundDataTable");
    {
        CSoundDataTable::SoundList events;
        FUN_141825f60("ms2sound/sound/voice", events);
        FUN_1414a57c0()->SetEventSounds(events);
    }
    {
        CSoundDataTable::SoundList programmer;
        FUN_141826260(programmer);
        FUN_1414a57c0()->SetProgrammerSounds(programmer);
    }
    {
        CSoundDataTable::SoundList triggerVoice;
        FUN_141826360(triggerVoice);
        FUN_1414a57c0()->SetTriggerVoiceSounds(triggerVoice);
    }
    CString strPath = FUN_1414a57c0()->GetPath();
    CString strResult;
    if (FUN_1414a57c0()->Save() == 0)
        bOk = false;
    if (bOk)
        strResult.Format("saved [%s]", (const char*)strPath);
    else
        strResult.Format("failed to save [%s]", (const char*)strPath);
    FUN_1411683e0(FUN_141168200(), strResult);
    if (bMessageBox)
        AfxMessageBox(strResult, 0, 0);
    return bOk;
}

// Adds nId to the id list of nKey (creating the list when the key is new).
// @0x141826d00
bool FUN_141826d00(int nKey, unsigned int nId, Unk_FieldMapB& rMap)
{
    if (rMap.find(nKey) == rMap.end()) {
        Unk_FieldIdListPtr fresh(0);
        fresh = Unk_FieldNewTag(0);
        rMap[nKey] = fresh;
    }
    Unk_FieldIdListPtr list(static_cast<const Unk_FieldIdListPtr&>(rMap[nKey]));
    POSITION pos = list.get()->Find(nId, NULL);
    if (pos == NULL)
        list.get()->AddTail(nId);
    return true;
}

// @0x141826e40
bool FUN_141826e40(unsigned int nKey, unsigned int nId, Unk_FieldMapA& rMap)
{
    if (rMap.find(nKey) == rMap.end()) {
        Unk_FieldIdListPtr fresh(0);
        fresh = Unk_FieldNewTag(0);
        rMap[nKey] = fresh;
    }
    Unk_FieldIdListPtr list(static_cast<const Unk_FieldIdListPtr&>(rMap[nKey]));
    POSITION pos = list.get()->Find(nId, NULL);
    if (pos == NULL)
        list.get()->AddTail(nId);
    return true;
}
