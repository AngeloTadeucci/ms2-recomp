// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Adventure level table, its singleton helper and mission rows.
// MS2-UNIT: ?\adventureleveltablehelper.cpp
// MS2-RANGE: 0x140195470-0x1401a2e40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_G?$TSingleton@VCAdventureLevelTableHelper@@@@UEAAPEAXI@Z 0x1401957e0 ; unique
// MS2-PIN: ??_GCAdventureLevelMissionData@@UEAAPEAXI@Z 0x140195820 ; unique
// MS2-PIN: ??_GCAdventureLevelTableHelper@@UEAAPEAXI@Z 0x140195860 ; unique
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140196c20 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140196c50 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140196c80 ; prop
// MS2-PIN: ??$?0AEAIAEAUCAdventureLevelAbility@@$0A@@?$pair@IUCAdventureLevelAbility@@@std@@QEAA@AEAIAEAUCAdventureLevelAbility@@@Z 0x140196d10 ; unique
// MS2-PIN: ??$?0AEAIAEAUCAdventureLevelMission@@$0A@@?$pair@IUCAdventureLevelMission@@@std@@QEAA@AEAIAEAUCAdventureLevelMission@@@Z 0x140196d70 ; unique
// MS2-PIN: ??$?0AEAIAEAUCAdventureLevelReward@@$0A@@?$pair@IUCAdventureLevelReward@@@std@@QEAA@AEAIAEAUCAdventureLevelReward@@@Z 0x140196dd0 ; unique
// MS2-PIN: ??$?0AEAPEAIAEAPEAI$0A@@?$pair@PEAIPEAI@std@@QEAA@AEAPEAI0@Z 0x140196e30 ; unique
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140196f70 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140196fc0 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140197010 ; prop
// MS2-PIN: ??$_Adl_verify_range1@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@0U?$integral_constant@_N$0A@@0@@Z 0x140197410 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@IUCAdventureLevelAbility@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@$$QEAU?$pair@IUCAdventureLevelAbility@@@1@@Z 0x1401974c0 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@IUCAdventureLevelMission@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@$$QEAU?$pair@IUCAdventureLevelMission@@@1@@Z 0x140197550 ; unique
// MS2-PIN: ??$_Buynode@U?$pair@IUCAdventureLevelReward@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@$$QEAU?$pair@IUCAdventureLevelReward@@@1@@Z 0x1401975e0 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBI@?$vector@IV?$allocator@I@std@@@std@@QEAAPEAIQEAIAEBI@Z 0x1401977a0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@PEAU01@@Z 0x1401979e0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@1@PEAU01@@Z 0x140197a70 ; prop
// MS2-PIN: ??$_Get_size_of_n@$0DI@@std@@YA_K_K@Z 0x140197cb0 ; unique
// MS2-PIN: ??$_Get_size_of_n@$0EA@@std@@YA_K_K@Z 0x140197d00 ; unique
// MS2-PIN: ??$_Guess_median_unchecked@PEAIP6A_NII@Z@std@@YAXPEAI00P6A_NII@Z@Z 0x140197d70 ; unique
// MS2-PIN: ??$_Guess_median_unchecked@PEAIU?$less@X@std@@@std@@YAXPEAI00U?$less@X@0@@Z 0x140197ec0 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIUCAdventureLevelAbility@@@1@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@@Z 0x140198a40 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIUCAdventureLevelMission@@@1@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@@Z 0x140198e50 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIUCAdventureLevelReward@@@1@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@@Z 0x140199260 ; unique
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@AEBI@Z 0x140199930 ; unique
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@AEBI@Z 0x1401999d0 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@0@AEAPEAU10@@Z 0x14019b160 ; unique
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@YAPEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@0@AEAPEAU10@@Z 0x14019b170 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBII@std@@@std@@YAPEAU?$pair@$$CBII@0@AEAU10@@Z 0x14019b1b0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@0@AEAV10@@Z 0x14019b200 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@AEAPEAU31@@Z 0x14019b2a0 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@@Z 0x14019b520 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@@Z 0x14019b530 ; prop
// MS2-PIN: ??$destroy@U?$pair@$$CBII@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@1@QEAU?$pair@$$CBII@1@@Z 0x14019b570 ; prop
// MS2-PIN: ??$forward@AEAPEAI@std@@YAAEAPEAIAEAPEAI@Z 0x14019b780 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@0@AEAPEAU10@@Z 0x14019b790 ; prop
// MS2-PIN: ??$forward@AEAUCAdventureLevelAbility@@@std@@YAAEAUCAdventureLevelAbility@@AEAU1@@Z 0x14019b810 ; prop
// MS2-PIN: ??$forward@AEAUCAdventureLevelMission@@@std@@YAAEAUCAdventureLevelMission@@AEAU1@@Z 0x14019b820 ; prop
// MS2-PIN: ??$forward@AEAUCAdventureLevelReward@@@std@@YAAEAUCAdventureLevelReward@@AEAU1@@Z 0x14019b830 ; prop
// MS2-PIN: ??$forward@UCAdventureLevelAbility@@@std@@YA$$QEAUCAdventureLevelAbility@@AEAU1@@Z 0x14019b8c0 ; unique
// MS2-PIN: ??$forward@UCAdventureLevelMission@@@std@@YA$$QEAUCAdventureLevelMission@@AEAU1@@Z 0x14019b8d0 ; unique
// MS2-PIN: ??$forward@UCAdventureLevelReward@@@std@@YA$$QEAUCAdventureLevelReward@@AEAU1@@Z 0x14019b8e0 ; unique
// MS2-PIN: ??$make_pair@AEAIAEAUCAdventureLevelAbility@@@std@@YA?AU?$pair@IUCAdventureLevelAbility@@@0@AEAIAEAUCAdventureLevelAbility@@@Z 0x14019ba10 ; prop
// MS2-PIN: ??$make_pair@AEAIAEAUCAdventureLevelMission@@@std@@YA?AU?$pair@IUCAdventureLevelMission@@@0@AEAIAEAUCAdventureLevelMission@@@Z 0x14019ba60 ; prop
// MS2-PIN: ??$make_pair@AEAIAEAUCAdventureLevelReward@@@std@@YA?AU?$pair@IUCAdventureLevelReward@@@0@AEAIAEAUCAdventureLevelReward@@@Z 0x14019bab0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14019bcd0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14019bd00 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14019bd30 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14019bdc0 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14019be00 ; prop
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14019be40 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@1@@Z 0x14019c040 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEAA@XZ 0x14019c2c0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@QEAA@XZ 0x14019c2f0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@QEAA@XZ 0x14019c320 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14019c3f0 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14019c400 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14019c410 ; prop
// MS2-PIN: ??0?$map@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@@std@@QEAA@XZ 0x14019c440 ; unique
// MS2-PIN: ??0?$map@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@@std@@QEAA@XZ 0x14019c470 ; unique
// MS2-PIN: ??0?$map@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@@std@@QEAA@XZ 0x14019c4a0 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x14019c570 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x14019c5a0 ; prop
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x14019c5d0 ; prop
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA@XZ 0x14019c6c0 ; prop
// MS2-PIN: ??1?$map@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@@std@@QEAA@XZ 0x14019c770 ; unique
// MS2-PIN: ??1?$map@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@@std@@QEAA@XZ 0x14019c790 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14019cb30 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019cb80 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14019cba0 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019cbf0 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14019cc10 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019cc60 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14019cd60 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14019cdf0 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14019ce80 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019d030 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019d050 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019d070 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019d090 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019d0b0 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14019d0d0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14019d0f0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14019d1c0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x14019d290 ; prop
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x14019db60 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x14019ddc0 ; unique
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@@Z 0x14019e0e0 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@@Z 0x14019e690 ; prop
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@@Z 0x14019ec40 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@2@XZ 0x1401a0110 ; unique
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@XZ 0x1401a05b0 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x1401a05e0 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@@Z 0x1401a06c0 ; prop
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@Z 0x1401a07a0 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@PEAU32@@Z 0x1401a0a70 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@PEAU32@@Z 0x1401a0aa0 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@PEAU32@@Z 0x1401a0b30 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@PEAU32@@Z 0x1401a0b60 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@PEAU32@@Z 0x1401a0b90 ; prop
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@XZ 0x1401a0c40 ; prop
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@XZ 0x1401a0c60 ; prop
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@XZ 0x1401a0ce0 ; prop
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@XZ 0x1401a0d00 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x1401a0d60 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@@Z 0x1401a0e40 ; prop
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@Z 0x1401a0f20 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x1401a11c0 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@_K@Z 0x1401a13b0 ; unique
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@XZ 0x1401a14a0 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@_K@Z 0x1401a1af0 ; prop
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@_K@Z 0x1401a1be0 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@XZ 0x1401a1ca0 ; prop
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@@Z 0x1401a20f0 ; prop
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140195720 ; unique: single byte-identical candidate
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x140195770 ; prop: symbols.tsv
// MS2-PIN: ??D?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEBAAEBIXZ 0x1401957b0 ; prop: symbols.tsv
// MS2-PIN: ??E?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEAAAEAV01@XZ 0x1401957c0 ; unique: single byte-identical candidate
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140196cb0 ; prop: 0x140196c20 taken by ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$C...
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140196ce0 ; prop: 0x140196cb0 taken by ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$C...
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140196e80 ; prop: symbols.tsv
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140196ed0 ; unique: caller ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@P...
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140196f20 ; prop: symbols.tsv
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140197060 ; prop: 0x140196f70 taken by ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compresse...
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1401972c0 ; prop: symbols.tsv
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIUCAdventureLevelAbility@@@std@@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIUCAdventureLevelAbility@@@1@@Z 0x140197460 ; prop: symbols.tsv
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIUCAdventureLevelMission@@@1@@Z 0x140197480 ; prop: symbols.tsv
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIUCAdventureLevelReward@@@std@@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIUCAdventureLevelReward@@@1@@Z 0x1401974a0 ; prop: symbols.tsv
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@1@AEAU?$pair@$$CBIUCAdventureLevelAbility@@@1@1@Z 0x140198020 ; prop: 0x140198380 taken by ??$_Insert_at@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAU?...
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@AEAU?$pair@$$CBIUCAdventureLevelMission@@@1@1@Z 0x140198380 ; unique: caller ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@P...
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@AEAU?$pair@$$CBIUCAdventureLevelReward@@@1@1@Z 0x1401986e0 ; prop: symbols.tsv
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@AEBI@Z 0x140199a70 ; prop: symbols.tsv
// MS2-PIN: ??$_Lbound@I@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@IPEAX@1@AEBI@Z 0x140199b10 ; prop: caller ?lower_bound@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@...
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@0@AEAV10@@Z 0x14019b130 ; prop: symbols.tsv
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@@Z 0x14019b540 ; unique: caller ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureL...
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@YAAEAU?$pair@$$CBIUCAdventureLevelMission@@@0@AEAU10@@Z 0x14019b7f0 ; unique: caller ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@P...
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@YAAEAU?$pair@$$CBIUCAdventureLevelReward@@@0@AEAU10@@Z 0x14019b800 ; prop: symbols.tsv
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14019b840 ; prop: symbols.tsv
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14019b850 ; prop: symbols.tsv
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14019b860 ; prop: symbols.tsv
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14019b8f0 ; prop: symbols.tsv
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@0@AEAV10@@Z 0x14019b910 ; prop: symbols.tsv
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14019bd60 ; prop: callee ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocato...
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@I@1@@Z 0x14019be80 ; prop: callee ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compresse...
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@1@@Z 0x14019bf40 ; unique: caller ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$C...
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@1@@Z 0x14019bf80 ; unique: caller ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$C...
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@1@@Z 0x14019c180 ; prop: symbols.tsv
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@1@@Z 0x14019c1c0 ; prop: symbols.tsv
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@1@@Z 0x14019c200 ; prop: caller ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pa...
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAA@XZ 0x14019c350 ; prop: caller ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$C...
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@QEAA@XZ 0x14019c420 ; prop: caller ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$C...
// MS2-PIN: ??0?$map@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@@std@@QEAA@XZ 0x14019c4d0 ; prop: callee ??0?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$...
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x14019c660 ; prop: symbols.tsv
// MS2-PIN: ??1?$map@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@@std@@QEAA@XZ 0x14019c750 ; unique: caller ??1CAdventureLevelTable@@UEAA@XZ
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@XZ 0x14019d480 ; prop: symbols.tsv
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@XZ 0x14019d6c0 ; prop: caller ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?...
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x14019dae0 ; prop: symbols.tsv
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x14019db20 ; prop: symbols.tsv
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x14019dba0 ; prop: caller ??$_Lbound@I@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@...
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14019dbe0 ; prop: symbols.tsv
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14019dc70 ; prop: caller ??0?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocato...
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@Z 0x14019dcd0 ; unique: single byte-identical candidate
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x14019fd50 ; prop: symbols.tsv
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@IPEAX@2@@Z 0x14019fde0 ; prop: callee ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allo...
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@2@@Z 0x14019fe10 ; prop: 0x14019fde0 taken by ?_Freenode0@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$...
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x1401a0080 ; prop: symbols.tsv
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x1401a0090 ; prop: symbols.tsv
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x1401a00a0 ; prop: symbols.tsv
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelReward@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x1401a00b0 ; prop: symbols.tsv
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@PEAX@std@@@2@XZ 0x1401a00c0 ; unique: caller ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelAbilit...
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@IPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x1401a0120 ; prop: caller ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allo...
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x1401a01b0 ; prop: symbols.tsv
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@IPEAX@std@@@2@XZ 0x1401a0360 ; prop: callee ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair...
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@2@XZ 0x1401a0390 ; prop: 0x1401a0360 taken by ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allo...
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1401a0420 ; prop: symbols.tsv
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@I@2@XZ 0x1401a0440 ; prop: symbols.tsv
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1401a0460 ; prop: symbols.tsv
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x1401a0480 ; prop: caller ?find@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A...
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEBAAEBIPEAU?$_Tree_node@U?$pair@$$CBIUCAdventureLevelMission@@@std@@PEAX@2@@Z 0x1401a04d0 ; unique: caller ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@P...
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEBAAEBIAEBU?$pair@$$CBIUCAdventureLevelMission@@@2@@Z 0x1401a0550 ; unique: caller ??$_Insert_nohint@AEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@P...
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1401a1220 ; prop: symbols.tsv
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x1401a1280 ; prop: symbols.tsv
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@XZ 0x1401a1d00 ; unique: caller ?find@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@...
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@XZ 0x1401a1dc0 ; unique: caller ?CollectMissionIds@CAdventureLevelTable@@QEAAXAEAV?$set@IU?$less@I...
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@XZ 0x1401a1e80 ; unique: caller ?GetReward@CAdventureLevelTable@@QEAAPEBUCAdventureLevelReward@@I@Z
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@0@Z 0x1401a2000 ; prop: symbols.tsv
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@0@Z 0x1401a21a0 ; prop: symbol ?begin@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I...
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@@std@@@2@AEBI@Z 0x1401a2900 ; unique: caller ?GetMission@CAdventureLevelTable@@QEAAPEBUCAdventureLevelMission@@I@Z
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelReward@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@@std@@@2@AEBI@Z 0x1401a29e0 ; unique: caller ?GetReward@CAdventureLevelTable@@QEAAPEBUCAdventureLevelReward@@I@Z
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@AEBI@Z 0x1401a2ac0 ; prop: callee ?lower_bound@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@...
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@std@@@std@@@2@AEBI@Z 0x1401a2ba0 ; unique: caller ?find@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@...
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@IU?$less@I@std@@V?$allocator@I@2@$0A@@std@@@std@@QEBA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@2@AEBI@Z 0x1401a2cc0 ; prop: callee ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@IU?$less@I@std@@V?$a...
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelAbility@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelAbility@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1401a2d50 ; prop: symbols.tsv
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@IUCAdventureLevelMission@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUCAdventureLevelMission@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x1401a2d70 ; prop: symbols.tsv
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBIUCAdventureLevelMission@@@std@@@std@@SAPEAU?$pair@$$CBIUCAdventureLevelMission@@@2@AEAU32@@Z 0x1401a2dd0 ; unique: caller ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$C...
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBIUCAdventureLevelReward@@@std@@@std@@SAPEAU?$pair@$$CBIUCAdventureLevelReward@@@2@AEAU32@@Z 0x1401a2df0 ; unique: caller ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$C...
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CAdventureLevelTable@@6B?$TSingleton@VCAdventureLevelTable@@@@@ 0x142ceb9b8
// MS2-PIN: ??_7CAdventureLevelTable@@6B?$CValidData@VCAdventureLevelTable@@@@@ 0x142ceb9e8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\adventureleveltablehelper.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "adventureleveltablehelper.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include "ms2/placeholder/tixmldocument.h"
#include <algorithm>
#include <utility>

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
bool FUN_14028f710(Unk_140165cf0*);
CString FUN_14015f710(Unk_140165cf0*, const char*, const CString&);   // string attribute
class Unk_140166410 { public: bool FUN_14036d570(int); };
Unk_140166410* FUN_140166410();
void FUN_14019d470(bool);

int FUN_1408731a0(Unk_140165cf0*, const char*, unsigned short*);
int FUN_1408731e0(Unk_140165cf0*, const char*, int*);
int FUN_140873220(Unk_140165cf0*, const char*, unsigned*);
int FUN_140873360(Unk_140165cf0*, const char*, float*);
void* FUN_140aafef0(void* pMgr, void* pHolder, unsigned nId, int n);
void* FUN_140184880(void* pHolder);
void FUN_1401836a0(void* pHolder);

extern void* DAT_143aac278;   // the CAdventureLevelTable singleton
extern void* DAT_143aac288;   // the effect manager singleton
extern CAdventureLevelReward DAT_142ceae98;    // the exe's default rows
extern CAdventureLevelAbility DAT_142ceaea8;
extern CAdventureLevelMission DAT_142ceaec8;

#define s_defReward DAT_142ceae98
#define s_defAbility DAT_142ceaea8
#define s_defMission DAT_142ceaec8

// Attribute readers: the default is returned when the attribute is missing.
// @0x140197310
unsigned short FUN_140197310(Unk_140165cf0* pElem, const char* pszName, unsigned short nDefault)
{
    unsigned short nVal;
    if (FUN_1408731a0(pElem, pszName, &nVal) != 0)
        return nDefault;
    return nVal;
}

// @0x140197350
int FUN_140197350(Unk_140165cf0* pElem, const char* pszName, int nDefault)
{
    int nVal;
    if (FUN_1408731e0(pElem, pszName, &nVal) != 0)
        return nDefault;
    return nVal;
}

// @0x140197390
unsigned FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned nDefault)
{
    unsigned nVal;
    if (FUN_140873220(pElem, pszName, &nVal) != 0)
        return nDefault;
    return nVal;
}

// @0x1401973d0
float FUN_1401973d0(Unk_140165cf0* pElem, const char* pszName, float fDefault)
{
    float fVal;
    if (FUN_140873360(pElem, pszName, &fVal) != 0)
        return fDefault;
    return fVal;
}

// @0x1401958b0
static void* GetEffectMgr()
{
    return DAT_143aac288;
}

// @0x1401958c0
// MS2-FUNCTIONAL: the exe body is 11 bytes (extra frame setup); this empty body compiles to a bare ret
void FUN_1401958c0()
{
}

// @0x1401958d0
bool FUN_1401958d0(CAdventureLevelReward* p)
{
    return &DAT_142ceae98 == p;
}

// @0x140195aa0
bool FUN_140195aa0(CAdventureLevelAbility* p)
{
    return p == &DAT_142ceaea8;
}

// @0x140195ae0
bool FUN_140195ae0(CAdventureLevelMission* p)
{
    return p == &DAT_142ceaec8;
}

// @0x1401958a0
static CAdventureLevelTable* GetTable()
{
    return static_cast<CAdventureLevelTable*>(DAT_143aac278);
}

// @0x140195b20
static int ParseRewardType(const CString& str)
{
    int nRet;
    if (str.CompareNoCase("statPoint") == 0)
    {
        nRet = 2;
    }
    else if (str.CompareNoCase("item") == 0)
    {
        nRet = 1;
    }
    else
    {
        nRet = 0;
    }
    return nRet;
}

// @0x140195470
CAdventureLevelTableHelper::CAdventureLevelTableHelper()
{
    m_pCurrent = 0;
}

// @0x1401954b0
CAdventureLevelTableHelper::~CAdventureLevelTableHelper()
{
}

// @0x140195660
CAdventureLevelMissionData::CAdventureLevelMissionData()
{
    m_nId = 0;
    m_b1c = false;
    m_p20 = 0;
}

// @0x140195700
// MS2-FUNCTIONAL: exe calls CPtred::~CPtred directly without storing the vptr; implicit dtor stores it
CAdventureLevelMissionData::~CAdventureLevelMissionData()
{
}

// @0x140195b80
// MS2-FUNCTIONAL: the exe pairs two distinct std::map<uint,?> instantiations at +0x10 / +0x20; both are map<uint,uint> here
CAdventureLevelTable::CAdventureLevelTable()
{
}

// @0x140195c60
// MS2-FUNCTIONAL: same two map instantiations as the ctor
CAdventureLevelTable::~CAdventureLevelTable()
{
}

// @0x140195d30
bool CAdventureLevelTable::LoadAll()
{
    if (!LoadUnused1())
        return false;
    if (!LoadUnused2())
        return false;
    if (!LoadReward())
        return false;
    if (!LoadAbility())
        return false;
    if (FUN_140166410()->FUN_14036d570(0xfb) && !LoadMission())
        return false;
    FUN_14019d470(true);
    return true;
}

// The two table loaders of the exe that load nothing.
// @0x1401961b0
bool CAdventureLevelTable::LoadUnused1()
{
    return true;
}

// @0x1401961a0
bool CAdventureLevelTable::LoadUnused2()
{
    return true;
}

// @0x140195e30
const CAdventureLevelReward* CAdventureLevelTable::GetReward(unsigned nLevel)
{
    std::map<unsigned, CAdventureLevelReward>::iterator it = m_mapReward.find(nLevel);
    if (it == m_mapReward.end())
        return &s_defReward;
    return &it->second;
}

// @0x140195ed0
const CAdventureLevelAbility* CAdventureLevelTable::GetAbility(unsigned nEffectId)
{
    std::map<unsigned, CAdventureLevelAbility>::iterator it = m_mapAbility.find(nEffectId);
    if (it == m_mapAbility.end())
        return &s_defAbility;
    return &it->second;
}

// @0x140196090
const CAdventureLevelMission* CAdventureLevelTable::GetMission(unsigned nMissionId)
{
    std::map<unsigned, CAdventureLevelMission>::iterator it = m_mapMission.find(nMissionId);
    if (it == m_mapMission.end())
        return &s_defMission;
    return &it->second;
}

// @0x140195f70
// MS2-FUNCTIONAL: the claimed container's type is unrecovered (std::set<unsigned> assumed); iterator temporaries differ
int CAdventureLevelTable::CountClaimedRewards(unsigned nLevel, const std::set<unsigned>& setClaimed)
{
    int nCount = 0;
    for (std::vector<unsigned>::iterator it = m_vecLevels.begin(); it != m_vecLevels.end() && *it <= nLevel; ++it) {
        if (GetReward(*it)->m_nType != 2 && setClaimed.find(*it) != setClaimed.end())
            ++nCount;
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x140195F70, CAdventureLevelTable, CountClaimedRewards, 282, 0x9CFE52F9);

// @0x140196110
// MS2-FUNCTIONAL: the output container's type is unrecovered (std::set<unsigned> assumed)
void CAdventureLevelTable::CollectMissionIds(std::set<unsigned>& setOut)
{
    for (std::map<unsigned, CAdventureLevelMission>::iterator it = m_mapMission.begin(); it != m_mapMission.end(); ++it)
        setOut.insert(it->first);
}
MS2_REPLACE_METHOD(0x140196110, CAdventureLevelTable, CollectMissionIds, 124, 0xCF2F835F);

// @0x140195eb0
std::vector<unsigned>& CAdventureLevelTable::GetLevels()
{
    return m_vecLevels;
}

// @0x140195f50
std::vector<unsigned>& CAdventureLevelTable::GetAbilityIds()
{
    return m_vecAbilityIds;
}

// @0x140196b70  ability ids ordered by required level (ties keep file order)
static bool AbilityLess(const unsigned& a, const unsigned& b)
{
    const CAdventureLevelAbility* pA = GetTable()->GetAbility(a);
    const CAdventureLevelAbility* pB = GetTable()->GetAbility(b);
    if (pA->m_nRequireLevel == pB->m_nRequireLevel)
        return pA->m_nId < pA->m_nId;   // sic: the exe compares the first row with itself
    return pA->m_nRequireLevel < pB->m_nRequireLevel;
}

// @0x1401961c0
// MS2-FUNCTIONAL: string temporaries are built in a different order from the exe; locals differ
bool CAdventureLevelTable::LoadReward()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("AdventureLevelReward.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("reward"); pNode != 0; pNode = pNode->FUN_140168650("reward"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nLevel = FUN_140197310(pNode, "level", 0);
        CAdventureLevelReward row;
        row.m_nType = ParseRewardType(FUN_14015f710(pNode, "type", CString("")).Trim());
        row.m_nId = FUN_140197390(pNode, "id", 0);
        row.m_nRank = FUN_140197350(pNode, "rank", 0);
        row.m_nValue = FUN_140197350(pNode, "value", 0);
        m_mapReward.insert(std::make_pair(nLevel, row));
        m_vecLevels.push_back(nLevel);
    }
    std::sort(m_vecLevels.begin(), m_vecLevels.end());
    return true;
}
MS2_REPLACE_METHOD(0x1401961C0, CAdventureLevelTable, LoadReward, 901, 0xD3A2F416);

// @0x140196550
// MS2-FUNCTIONAL: string temporaries are built in a different order from the exe; locals differ
bool CAdventureLevelTable::LoadAbility()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("AdventureLevelAbility.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("ability"); pNode != 0; pNode = pNode->FUN_140168650("ability"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        CAdventureLevelAbility row;
        row.m_nEffectId = FUN_140197390(pNode, "additionalEffectId", 0);
        row.m_nId = FUN_140197350(pNode, "id", 0);
        row.m_nRequireLevel = FUN_140197390(pNode, "requireLevel", 0);
        row.m_nInterval = FUN_140197350(pNode, "interval", 0);
        row.m_nMaxCount = FUN_140197350(pNode, "maxCount", 0);
        row.m_fStartValue = FUN_1401973d0(pNode, "startValue", 0);
        row.m_fAddValue = FUN_1401973d0(pNode, "addValue", 0);
        m_mapAbility.insert(std::make_pair(row.m_nEffectId, row));
        m_vecAbilityIds.push_back(row.m_nEffectId);
    }
    std::sort(m_vecAbilityIds.begin(), m_vecAbilityIds.end(), AbilityLess);
    return true;
}
MS2_REPLACE_METHOD(0x140196550, CAdventureLevelTable, LoadAbility, 848, 0x6F52A1EF);

// @0x1401968b0
// MS2-FUNCTIONAL: string temporaries are built in a different order from the exe; locals differ
bool CAdventureLevelTable::LoadMission()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("AdventureLevelMission.xml"));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("mission"); pNode != 0; pNode = pNode->FUN_140168650("mission"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        unsigned nId = FUN_140197390(pNode, "missionId", 0);
        CAdventureLevelMission row;
        row.m_nCount = FUN_140197390(pNode, "missionCount", 0);
        row.m_nOne = 1;
        row.m_nItemId = FUN_140197390(pNode, "itemId", 0);
        row.m_nItemRank = FUN_140197350(pNode, "itemRank", 0);
        row.m_nItemCount = FUN_140197350(pNode, "itemCount", 0);
        m_mapMission.insert(std::make_pair(nId, row));
    }
    return true;
}
MS2_REPLACE_METHOD(0x1401968B0, CAdventureLevelTable, LoadMission, 689, 0xABCA5713);

// @0x140195910
// MS2-FUNCTIONAL: single result slot is a dword in the exe (ternary 1:0 stored wide); here separate slots
unsigned short CAdventureLevelAbility::GetCount(unsigned nLevel) const
{
    unsigned nRet;
    if (m_nId == 0)
        return 0;
    if (m_nInterval == 0)
    {
        nRet = (nLevel >= m_nRequireLevel) ? 1 : 0;
    }
    else if (nLevel < m_nRequireLevel)
    {
        nRet = 0;
    }
    else
    {
        unsigned short nMax = (unsigned short)m_nMaxCount;
        unsigned short nCalc = (unsigned short)((nLevel - m_nRequireLevel + m_nInterval) / (unsigned)m_nInterval);
        nRet = (std::min)(nCalc, nMax);
    }
    return nRet;
}
MS2_REPLACE_METHOD(0x140195910, CAdventureLevelAbility, GetCount, 175, 0x757B70A5);

// @0x1401959d0
int CAdventureLevelAbility::GetLevelOfCount(unsigned nLevel) const
{
    if (m_nId == 0)
        return 0;
    return (GetCount(nLevel) - 1) * m_nInterval + m_nRequireLevel;
}

// @0x140195a20
float CAdventureLevelAbility::GetPercent(unsigned nLevel) const
{
    if (m_nId == 0)
        return 0.0f;
    return (m_fStartValue + (float)(int)(GetCount(nLevel) - 1) * m_fAddValue) * 100.0f;
}

// @0x1401954e0
// MS2-FUNCTIONAL: iterator glue and the effect-holder temp are written with real std::vector / extern calls
void CAdventureLevelTableHelper::FindCurrent()
{
    std::vector<unsigned>& ids = GetTable()->GetAbilityIds();
    std::vector<unsigned>::iterator it = ids.begin();
    while (it != ids.end())
    {
        unsigned* pId = &*it;
        const CAdventureLevelAbility* pAbility = GetTable()->GetAbility(*pId);
        char holder[0x18];
        FUN_140aafef0(GetEffectMgr(), holder, pAbility->m_nEffectId, 1);
        if (*(int*)((char*)FUN_140184880(holder) + 0x30) == 3)
        {
            m_pCurrent = const_cast<CAdventureLevelAbility*>(pAbility);
            FUN_1401836a0(holder);
            return;
        }
        FUN_1401836a0(holder);
        ++it;
    }
}

// @0x1401955f0
bool CAdventureLevelTableHelper::IsReached(unsigned nLevel)
{
    if (m_pCurrent == 0)
        return false;
    return nLevel >= m_pCurrent->m_nRequireLevel;
}

// @0x140195640
CAdventureLevelAbility* CAdventureLevelTableHelper::GetCurrent()
{
    return m_pCurrent;
}

MS2_EMIT_CRT_MEMMOVE_S();
