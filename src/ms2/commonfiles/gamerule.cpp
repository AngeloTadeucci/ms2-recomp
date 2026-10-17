// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CGameRule: the client side store of the running game
// events (rates, sales, contexts by event id); the GameEvent* handlers of gameevent.cpp fill it and the UI asks it.
// The range starts with the ctor / dtor and the GameReason helpers (the earlier unnamed units 0x140474af0 ..
// 0x1404776f0 are the same TU) and ends with the template COMDATs of its containers (0x14047fd60 .. 0x1404c11a0:
// the unnamed units 0x1404979e0, 0x14049bd70, 0x14049c0d0, 0x14049c890, 0x1404aeed0, 0x1404af2b0 and 0x1404af370 are
// this TU's COMDAT tail; the next TU is ?\gloabalfactor.cpp at 0x1404c11a0).
// MS2-UNIT: commonfiles\gamerule.cpp
// MS2-RANGE: 0x140474af0-0x1404c11a0 .text$mn
// MS2-RANGE: 0x1400b8d40-0x1400b8df1 .text$di
// MS2-RANGE: 0x142c9a920-0x142c9a950 .text$yd
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAHAEAH$0A@@?$pair@HH@std@@QEAA@AEAH0@Z 0x14047fff0 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@std@@@1@0@Z 0x140480240 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@@std@@@std@@@1@0@Z 0x140480290 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@1@0@Z 0x140480330 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@1@0@Z 0x1404803d0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@1@0@Z 0x1404804c0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VQuestAdditionalRewardContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VQuestAdditionalRewardContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VQuestAdditionalRewardContext@@@@@std@@@std@@@std@@@1@0@Z 0x140480510 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@@std@@@1@0@Z 0x140480560 ; unique
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@1@0@Z 0x1404806f0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@@1@0@Z 0x140480830 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140480920 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@@std@@@1@0@Z 0x140480970 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@1@0@Z 0x140480a10 ; prop
// MS2-PIN: ??$?0AEAIAEAI$0A@@?$pair@HH@std@@QEAA@AEAI0@Z 0x140480d30 ; unique
// MS2-PIN: ??$?0AEBK$$Z$$V@?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBK@1@V?$tuple@$$V@1@@Z 0x140480e20 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140480ec0 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140480f10 ; prop
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140480f60 ; prop
// MS2-PIN: ??$?0AEBU?$less@K@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBKK@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKK@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@K@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140480fb0 ; prop
// MS2-PIN: ??$?0AEBU?$less@K@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@K@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140481000 ; prop
// MS2-PIN: ??$?0AEBU?$pair@HH@std@@$$Z$$V@?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VQuestAdditionalRewardContext@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBU?$pair@HH@std@@@1@V?$tuple@$$V@1@@Z 0x140481230 ; prop
// MS2-PIN: ??$?0AEBV?$allocator@I@std@@$$V@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBV?$allocator@I@1@@Z 0x140481300 ; unique
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHK@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x140481520 ; prop
// MS2-PIN: ??$?0HV?$MS2Ptr@VEnchantRateEventContext@@@@$0A@@?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VEnchantRateEventContext@@@@@1@@Z 0x140481640 ; unique
// MS2-PIN: ??$?0HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@$0A@@?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@QEAA@$$QEAU?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@1@@Z 0x1404816e0 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140481b30 ; prop
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140481dc0 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBK@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@QEAA@AEAV?$tuple@AEBK@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140481e10 ; prop
// MS2-PIN: ??$?0V?$tuple@AEBU?$pair@HH@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VQuestAdditionalRewardContext@@@@@std@@QEAA@AEAV?$tuple@AEBU?$pair@HH@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140481eb0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@?$_Tree@V?$_Tmap_traits@KV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@1@@Z 0x1404824a0 ; prop
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@UNpcEventDropEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@1@@Z 0x1404824c0 ; unique
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@1@@Z 0x1404824e0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140482880 ; unique
// MS2-PIN: ??$_Distance1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x1404832e0 ; prop
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@HV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x140483e90 ; prop
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@HKU?$less@H@std@@V?$allocator@U?$pair@$$CBHK@std@@@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x140483f20 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@3@$00@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x140484430 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@3@$00@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x1404844c0 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$MS2Ptr@UNpcEventDropEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x1404849d0 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x140484ca0 ; prop
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x140484d30 ; prop
// MS2-PIN: ??$_Eqrange@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@@std@@@std@@V12@@1@AEBV?$MS2Ptr@VDungeonBonusRewardCtx@@@@@Z 0x140485240 ; prop
// MS2-PIN: ??$_Eqrange@UUnk_ConstructionKey@@@?$_Tree@V?$_Tset_traits@UUnk_ConstructionKey@@U?$less@UUnk_ConstructionKey@@@std@@V?$allocator@UUnk_ConstructionKey@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@UUnk_ConstructionKey@@@std@@@std@@@std@@V12@@1@AEBUUnk_ConstructionKey@@@Z 0x140485510 ; prop
// MS2-PIN: ??$_Eqrange@W4Unk_DungeonGroupType@@@?$_Tree@V?$_Tmap_traits@W4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@W4Unk_DungeonGroupType@@@3@V?$allocator@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@V12@@1@AEBW4Unk_DungeonGroupType@@@Z 0x140485d80 ; prop
// MS2-PIN: ??$_Eqrange@W4Unk_DungeonGroupType@@@?$_Tree@V?$_Tmap_traits@W4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@W4Unk_DungeonGroupType@@@3@V?$allocator@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@V12@@1@AEBW4Unk_DungeonGroupType@@@Z 0x140485e10 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@KV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAX@1@AEAU?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@1@1@Z 0x140487c70 ; prop
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@1@AEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@1@1@Z 0x140488330 ; prop
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@1@@Z 0x14048b350 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@KV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@PEAX@1@@Z 0x14048fcc0 ; prop
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@1@@Z 0x1404904e0 ; prop
// MS2-PIN: ??$_Try_emplace@AEBI$$V@?$map@IV?$MS2Ptr@UNpcEventDropEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x140493570 ; prop
// MS2-PIN: ??$_Try_emplace@AEBI$$V@?$map@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x1404936c0 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@0@AEBV10@@Z 0x1404945d0 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventTimeLimitDungeonContext@@@@@std@@@std@@@0@AEBV10@@Z 0x1404945f0 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@YAPEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@0@AEBV10@@Z 0x140494620 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@_J@std@@@0@AEAV10@@Z 0x140494690 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@@std@@YAPEAU?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@0@AEAU10@@Z 0x1404947a0 ; prop
// MS2-PIN: ??$addressof@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@YAPEAU?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@0@AEAU10@@Z 0x1404947b0 ; unique
// MS2-PIN: ??$addressof@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@YAPEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@0@AEAU10@@Z 0x1404947c0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@0@AEAV10@@Z 0x140494870 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@0@AEAV10@@Z 0x140494890 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@U?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@1@$$QEAU?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@1@@Z 0x140494eb0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBI@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBI@1@$$QEAV?$tuple@$$V@1@@Z 0x140494f00 ; unique
// MS2-PIN: ??$distance@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@std@@@std@@YA_JV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@0@0@Z 0x140495a50 ; prop
// MS2-PIN: ??$emplace@U?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@@3@$00@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@@std@@@std@@@std@@_N@1@$$QEAU?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@1@@Z 0x140495e30 ; unique
// MS2-PIN: ??$forward@$$QEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@YA$$QEAV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEAV12@@Z 0x140496520 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@YAAEAU?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@0@AEAU10@@Z 0x140496660 ; prop
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@YAAEAU?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@0@AEAU10@@Z 0x140496670 ; unique
// MS2-PIN: ??$forward@AEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@YAAEAU?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@0@AEAU10@@Z 0x140496680 ; prop
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140496810 ; prop
// MS2-PIN: ??$forward@U?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@@std@@YA$$QEAU?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@0@AEAU10@@Z 0x1404969a0 ; prop
// MS2-PIN: ??$forward@V?$MS2Ptr@VEnchantRateEventContext@@@@@std@@YA$$QEAV?$MS2Ptr@VEnchantRateEventContext@@@@AEAV1@@Z 0x1404969d0 ; prop
// MS2-PIN: ??$forward@V?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@YA$$QEAV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@AEAV1@@Z 0x1404969e0 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140496a60 ; prop
// MS2-PIN: ??$insert@U?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@X@?$multimap@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@@3@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@@std@@@std@@@1@$$QEAU?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@1@@Z 0x140496cf0 ; unique
// MS2-PIN: ??$move@AEAV?$tuple@AEBU?$pair@HH@std@@@std@@@std@@YA$$QEAV?$tuple@AEBU?$pair@HH@std@@@0@AEAV10@@Z 0x140496e90 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HKU?$less@H@std@@V?$allocator@U?$pair@$$CBHK@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHK@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140496f30 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@IV?$MS2Ptr@UNpcEventDropEventContext@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@UNpcEventDropEventContext@@@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x140496f70 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@IV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@_N@1@AEBI@Z 0x140496fb0 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@W4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@U?$less@W4Unk_DungeonGroupType@@@3@V?$allocator@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@3@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@@std@@@std@@@std@@_N@1@AEBW4Unk_DungeonGroupType@@@Z 0x1404970b0 ; prop
// MS2-PIN: ??0?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@IMMMI@Z 0x140497170 ; unique
// MS2-PIN: ??0?$CAtlMap@HV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@H@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@QEAA@IMMMI@Z 0x140497260 ; unique
// MS2-PIN: ??0?$CAtlMap@IV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@@ATL@@QEAA@IMMMI@Z 0x140497350 ; prop
// MS2-PIN: ??0?$CAtlMap@HV?$MS2Ptr@UMesoRevivalEventContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UMesoRevivalEventContext@@@@@3@@ATL@@QEAA@IMMMI@Z 0x140497440 ; unique
// MS2-PIN: ??0?$CAtlMap@HV?$MS2Ptr@UOntimeEventContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@UOntimeEventContext@@@@@3@@ATL@@QEAA@IMMMI@Z 0x140497530 ; unique
// MS2-PIN: ??0?$CAtlMap@HV?$MS2Ptr@USAHotTimeEventContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@USAHotTimeEventContext@@@@@3@@ATL@@QEAA@IMMMI@Z 0x140497620 ; unique
// MS2-PIN: ??0?$CAtlMap@IV?$MS2Ptr@USkillUpgradeSaleEventContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@USkillUpgradeSaleEventContext@@@@@3@@ATL@@QEAA@IMMMI@Z 0x140497710 ; unique
// MS2-PIN: ??0?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$MS2Ptr@VEventQuestContext@@@@V?$CStringElementTraits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$CElementTraits@V?$MS2Ptr@VEventQuestContext@@@@@2@@ATL@@QEAA@IMMMI@Z 0x140497800 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??0Unk_GameRuleLock@@QEAA@AEAVCLockCriticalSection@@H@Z 0x140203610
// MS2-PIN: ??1Unk_GameRuleLock@@QEAA@XZ 0x1401b5120
// MS2-PIN: ?FUN_140166410@@YAPEAVCFeatureManager@@XZ 0x140166410
// MS2-PIN: ?IsIn@Unk_EpicRestartRange@@QEBA_NI@Z 0x1403b4ef0
// pair<const int, map<DWORD,DWORD>> piecewise ctor (calls the map ctor 0x140445750; 0x140481dc0 is a look-alike)
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140481fa0
// MS2-PIN: ??$make_pair@AEAHAEAV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@std@@YA?AU?$pair@HV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@0@AEAHAEAV?$MS2Ptr@VUnk_ItemTagRewardContext@@@@@Z 0x140496df0
// look-alike callees resolved through their matched callers (bytematch -v)
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VEnchantRateEventContext@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@@3@$00@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VEnchantRateEventContext@@@@@std@@PEAX@1@@Z 0x14048f4a0
// MS2-PIN: ??$_Try_emplace@AEBK$$V@?$map@KV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@U?$less@K@2@V?$allocator@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@KKU?$less@K@std@@V?$allocator@U?$pair@$$CBKK@std@@@2@@std@@@std@@@std@@@std@@@std@@_N@1@AEBK@Z 0x140493960
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@std@@V12@@2@AEB_J@Z 0x140486050
// MS2-PIN: ??$_Eqrange@_J@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@std@@V12@@1@AEB_J@Z 0x1404860e0
// MS2-PIN: ??$?0V?$tuple@AEBW4Unk_DungeonGroupType@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@QEAA@AEAV?$tuple@AEBW4Unk_DungeonGroupType@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140481f00
// MS2-PIN: ??$?0AEBW4Unk_DungeonGroupType@@$$Z$$V@?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBW4Unk_DungeonGroupType@@@1@V?$tuple@$$V@1@@Z 0x1404814d0
// MS2-PIN: ??$construct@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBW4Unk_DungeonGroupType@@@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@std@@PEAX@std@@@1@QEAU?$pair@$$CBW4Unk_DungeonGroupType@@V?$set@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@U?$less@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@std@@V?$allocator@V?$MS2Ptr@VDungeonBonusRewardCtx@@@@@3@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBW4Unk_DungeonGroupType@@@1@$$QEAV?$tuple@$$V@1@@Z 0x1404951c0
// the boxed maps: TPtredDummy<CRBMultiMap<CubeFilterType,TPtr<SaleCube>>> (our Unk_SaleHousingKey / MS2Ptr names)
// MS2-PIN: ??_7?$TPtredDummy@V?$CRBMultiMap@W4Unk_SaleHousingKey@@V?$MS2Ptr@VSaleCube@@@@V?$CElementTraits@W4Unk_SaleHousingKey@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VSaleCube@@@@@4@@ATL@@@@6B@ 0x142d4ded8
// MS2-PIN: ?Allocate@?$Unk_GEBoxPtr@V?$CRBMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@@@CAPEAV?$TPtredDummy@V?$CRBMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@@@PEAX@Z 0x140482310
// MS2-PIN: ?Allocate@?$Unk_GEBoxPtr@V?$CRBMultiMap@W4Unk_SaleHousingKey@@V?$MS2Ptr@VSaleCube@@@@V?$CElementTraits@W4Unk_SaleHousingKey@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VSaleCube@@@@@4@@ATL@@@@CAPEAV?$TPtredDummy@V?$CRBMultiMap@W4Unk_SaleHousingKey@@V?$MS2Ptr@VSaleCube@@@@V?$CElementTraits@W4Unk_SaleHousingKey@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VSaleCube@@@@@4@@ATL@@@@PEAX@Z 0x140482380
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gamerule.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gamerule.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cfeaturemanager.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2recover.h"
#include <iterator>
#include <functional>
#include "hook/ms2hook.h"

// The scoped lock of this TU (the same exe ctor as Unk_PetLock; it acquires immediately, the dtor releases).
struct Unk_GameRuleLock {
    Unk_GameRuleLock(CLockCriticalSection& lock, int acquire);      // 0x140203610
    ~Unk_GameRuleLock();                                            // 0x1401b5120
    CLockCriticalSection* m_lock;
};

// Out-of-unit callees.
CFeatureManager* FUN_140166410();                       // the CFeatureManager singleton
bool FUN_14036e510(void* features);                     // the URL cache feature flag of CFeatureManager
void* FUN_1404a1bb0();
void FUN_140353610(void* p, unsigned short value);
__int64 FUN_140869440();                                // the server time
bool FUN_1407183f0(const CStringW& str);
int FUN_140408410(ATL::CAtlArray<unsigned>* arr, const unsigned* value);    // the index of value, -1 if missing
void FUN_140274fc0(const CStringW& str, ATL::CAtlArray<unsigned>* out, const wchar_t* sep);

// The global table of the attend gift values keyed by (kind, id) (0x143ab2fc0; uilongtermattendgiftdialog.cpp has
// the same types as Unk_Lta*). Only the inline readers of this TU are defined here.
struct Unk_LtaKey
{
    Unk_LtaKey(int n1, int n2);             // 0x14041eee0
    int m_0; int m_4;
};
class Unk_LtaValue;
class Unk_LtaIter
{
public:
    Unk_LtaIter();
    ~Unk_LtaIter();
    Unk_LtaValue* FUN_140420460();          // the entry
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
};
MS2_CHECK_SIZE(Unk_LtaIter, 0x18);
class Unk_LtaMap { public: bool FUN_140420bb0(const Unk_LtaKey& key, Unk_LtaIter& it); };
class Unk_LtaValue
{
public:
    // @0x1404822b0
    bool FUN_1404822b0(const bool& bDefault) const
    {
        CMsTime now(FUN_140869440());
        if (m_28 <= now)
            return bDefault;
        return FUN_1407183f0(m_20);
    }
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18;
    CStringW m_20;                          // +0x20 stored text
    CMsTime m_28;                           // +0x28 expiry
};
class Unk_AttendTable
{
public:
    // @0x1404821d0
    bool FUN_1404821d0(int nKind, int nId, const bool& bDefault)
    {
        Unk_LtaKey key(nKind, nId);
        Unk_LtaIter it;
        if (m_18.FUN_140420bb0(key, it))
            return it.FUN_140420460()->FUN_1404822b0(bDefault);
        return bDefault;
    }
    // @0x140482280
    bool FUN_140482280(int nKind, const bool& bDefault) { return FUN_1404821d0(nKind, 0, bDefault); }
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
    Unk_LtaMap m_18;                        // +0x18
};

// The sort names of a header this TU includes (every includer has its own copy).
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x140482050: the value after a rate (1/10000) discount
inline unsigned FUN_140482050(unsigned value, unsigned rate)
{
    double factor = 1.0 - (double)rate / 10000.0;
    return (unsigned)(value * factor + 1e-06);
}
// @0x1404820b0: the bonus of a rate
inline __int64 FUN_1404820b0(unsigned value, float rate)
{
    return (__int64)((double)value * rate + 1e-06);
}
// @0x1404820e0
inline void FUN_1404820e0(ATL::CRBMap<int, int>& dst, ATL::CRBMap<int, int>& src)
{
    for (POSITION pos = src.GetHeadPosition(); pos != NULL; src.GetNext(pos))
        dst.SetAt(src.GetKeyAt(pos), src.GetValueAt(pos));
}
// @0x140482160
inline void FUN_140482160(const std::vector<ItemEntity>& src, std::vector<ItemEntity>& dst)
{
    std::copy(src.begin(), src.end(), std::back_inserter(dst));
}
// 0x140323a40 (elsewhere)
template <class T> void Unk_AppendVector(const std::vector<T>& src, std::vector<T>& dst)
{
    std::copy(src.begin(), src.end(), std::back_inserter(dst));
}

// MS2-FUNCTIONAL: ctor member-init order/EH states differ (container element types approximated)
// @0x140474af0
CGameRule::CGameRule()
    : m_d0(0), m_d4(0), m_368(0), m_36c(0), m_3b0(0), m_690(-1), m_698(0), m_6a0(0), m_6a8(0), m_6f0(0), m_6f4(0),
      m_700(0), m_8d8(0), m_8e8(0), m_910(false), m_9d0(false), m_transferItemBound(false), m_b30(0), m_b40(0),
      m_bb0(0), m_bc0(0), m_bd0(0), m_be0(0), m_bf0(0), m_c00(0), m_c10(0), m_c14(0), m_c60(false), m_d10(false),
      m_e98(0), m_ef8(0)
{
    if (FUN_14036e510(FUN_140166410()))
        m_a98 = 1;
    else
        m_a98 = 0;
}

// @0x140475640
CGameRule::~CGameRule()
{
}

// @0x140475e40
int FUN_140475e40(int reason)
{
    int result = 0;
    switch (reason) {
    case 0x15:
        result = 60001;
        break;
    }
    return result;
}

// @0x140475e80
BOOL FUN_140475e80(int reason)
{
    BOOL result = FALSE;
    switch (reason) {
    case 0x15:
    case 0x3f2:
    case 0x423:
    case 0x427:
    case 0x42f:
    case 1099:
    case 0xbbd:
    case 0xc1f:
    case 0xc20:
    case 0xc21:
    case 0xc22:
    case 0xc23:
    case 0xc24:
    case 0xc25:
    case 0xc26:
    case 60001:
        result = TRUE;
        break;
    }
    return result;
}

// @0x140475f20
BOOL FUN_140475f20(int reason)
{
    BOOL result = FALSE;
    switch (reason) {
    case 0x15:
    case 0x33:
    case 0x3f2:
    case 0x400:
    case 0x43d:
    case 1099:
    case 60001:
        result = TRUE;
        break;
    }
    return result;
}

// @0x140475fa0
BOOL FUN_140475fa0(int reason)
{
    BOOL result = FALSE;
    switch (reason) {
    case 0x15:
    case 0x21:
    case 60001:
    case 60002:
        result = TRUE;
        break;
    }
    return result;
}

// @0x140475ff0
void FUN_140475ff0(unsigned short value)
{
    FUN_140353610(FUN_1404a1bb0(), value);
}

// @0x140476020
CString FUN_140476020(int reason)
{
    CString str("");
    switch (reason) {
    case 0: str = "GameReason_None"; break;
    case 1: str = "GameReason_CharacterCreate"; break;
    case 2: str = "GameReason_CharacterDelete"; break;
    case 4: str = "GameReason_DeleteAccount"; break;
    case 0xb: str = "GameReason_UserDestroy"; break;
    case 0xc: str = "GameReason_TestCreate"; break;
    case 0xd: str = "GameReason_TestDestroy"; break;
    case 0x15: str = "GameReason_NpcKill"; break;
    case 0x17: str = "GameReason_NpcCorpse"; break;
    case 0x1f: str = "GameReason_BreakableObject"; break;
    case 0x20: str = "GameReason_VibrateObject"; break;
    case 0x29: str = "GameReason_RevivalPrice"; break;
    case 0x2a: str = "GameReason_MoveFieldPrice"; break;
    case 0x33: str = "GameReason_ShopSell"; break;
    case 0x34: str = "GameReason_ShopBuy"; break;
    case 0x35: str = "GameReason_ShopRepurchase"; break;
    case 0x36: str = "GameReason_ShopListReset"; break;
    case 0x3d: str = "GameReason_MailFee"; break;
    case 0x3e: str = "GameReason_MailUserSend"; break;
    case 0x3f: str = "GameReason_MailExpire"; break;
    case 0x40: str = "GameReason_MailReturn"; break;
    case 0x41: str = "GameReason_MailUserDelete"; break;
    case 0x42: str = "GameReason_MailSystemDelete"; break;
    case 0x47: str = "GameReason_MailItemAttach"; break;
    case 0x48: str = "GameReason_MailItemDetach"; break;
    case 0x49: str = "GameReason_MailItemReceive"; break;
    case 0x51: str = "GameReason_StoreItemOut"; break;
    case 0x52: str = "GameReason_StoreItemIn"; break;
    case 0x53: str = "GameReason_StoreMoneyDeposit"; break;
    case 0x54: str = "GameReason_StoreMoneyWithdraw"; break;
    case 0x55: str = "GameReason_StoreExpand"; break;
    case 0x3e9: str = "GameReason_Beauty"; break;
    case 0x3ea: str = "GameReason_Consume"; break;
    case 0x3eb: str = "GameReason_MoveMerge"; break;
    case 0x3ec: str = "GameReason_SortMerge"; break;
    case 0x3ed: str = "GameReason_UserDrop"; break;
    case 0x3ee: str = "GameReason_DropNoPickup"; break;
    case 0x3ef: str = "GameReason_DropDivide"; break;
    case 0x3f0: str = "GameReason_InvenDivide"; break;
    case 0x3f1: str = "GameReason_MissionReward"; break;
    case 0x3f2: str = "GameReason_QuestReward"; break;
    case 0x3f3: str = "GameReason_AchieveReward"; break;
    case 0x3f4: str = "GameReason_UseSkill"; break;
    case 0x400: str = "GameReason_ItemBox"; break;
    case 1999: str = "GameReason_Restore"; break;
    case 40000: str = "GameReason_GMToolDelete"; break;
    case 59001: str = "GameReason_BonusMap"; break;
    case 59002: str = "GameReason_UserCommandSvr"; break;
    case 60001: str = "GameReason_NpcKill_LB"; break;
    }
    return str;
}

// @0x1404766e0
void CGameRule::FUN_1404766e0()
{
    {
        Unk_CriticalSectionLock lock(m_80, 1);
        m_b0.clear();
        m_c0.clear();
        m_38.RemoveAll();
        m_d0 = 0;
        m_d4 = 0;
    }
    if (Unk_LockGuard guard = m_128) {} else
    {
        for (size_t i = 0; i < 2; i++)
            m_158[i].RemoveAll();
    }
    if (Unk_LockGuard guard = m_1e8) {} else
    {
        m_218.RemoveAll();
    }
    if (Unk_LockGuard guard = m_370) {} else
    {
        m_3a0.clear();
    }
    m_690 = -1;
    if (Unk_LockGuard guard = m_4d0) {} else
    {
        m_500.RemoveAll();
    }
    if (Unk_LockGuard guard = m_8) {} else
    {
        m_890.RemoveAll();
        m_888.Empty();
    }
}

// @0x140476930
void CGameRule::FUN_140476930(int nEventId, int nRate)
{
    Unk_CriticalSectionLock lock(m_d8, 1);
    m_108.Set(nEventId, 0, nRate);
}

// @0x1404769a0
void CGameRule::FUN_1404769a0(int nEventId)
{
    Unk_CriticalSectionLock lock(m_d8, 1);
    m_108.Remove(nEventId, 0);
}

// @0x140476a10
__int64 CGameRule::FUN_140476a10(__int64 value)
{
    Unk_CriticalSectionLock lock(m_d8, 1);
    unsigned rate = m_108.Get(0, 0);
    if (rate == 0)
        return 0;
    unsigned result = (unsigned)(value * rate / 10000);
    return result;
}

// @0x140476ad0
unsigned CGameRule::FUN_140476ad0()
{
    Unk_CriticalSectionLock lock(m_d8, 1);
    return m_108.Get(0, 0);
}

// @0x140476b40
void CGameRule::FUN_140476b40(int a, int b, BOOL c)
{
    if (c < 0 || c >= 2)
        return;
    if (Unk_LockGuard guard = m_128) {} else
    {
        m_158[c].SetAt(a, b);
    }
}

// @0x140476be0
void CGameRule::FUN_140476be0(int a, BOOL c)
{
    if (c < 0 || c >= 2)
        return;
    if (Unk_LockGuard guard = m_128) {} else
    {
        m_158[c].RemoveKey(a);
    }
}

// @0x140476c70
unsigned CGameRule::FUN_140476c70(int nEvent, unsigned nPrice, int nLevel)
{
    unsigned nRate = 0;
    int nIndex = 2;
    FUN_140476d50(nEvent, nLevel, &nRate, &nIndex);
    unsigned nDiscount = nPrice * nRate / 10000;
    return nPrice - nDiscount;
}

// @0x140476cf0
int CGameRule::FUN_140476cf0(int nEvent, int nLevel)
{
    unsigned nRate = 0;
    int nIndex = 2;
    FUN_140476d50(nEvent, nLevel, &nRate, &nIndex);
    return nIndex;
}

// @0x140476d50
void CGameRule::FUN_140476d50(int nEvent, int nLevel, unsigned* pRate, int* pIndex)
{
    std::vector<unsigned> rates(2, 0);
    if (Unk_LockGuard guard = m_128) {} else
    {
        for (size_t i = 0; i < 2; i++) {
            int nRate = 0;
            if (m_158[i].Lookup(nEvent, nRate))
                rates[i] = nRate;
        }
    }
    unsigned nBest = 0;
    int nBestIndex = 2;
    for (int i = 0; i < 2; i++) {
        if (i == 0 && nLevel == 0)
            continue;
        if (nBest < rates[i]) {
            nBest = rates[i];
            nBestIndex = i;
        }
    }
    *pRate = nBest;
    *pIndex = nBestIndex;
}

// @0x140476ef0
void CGameRule::FUN_140476ef0(ATL::CAtlArray<int>& out, int nLevel, unsigned nMin)
{
    if (nMin == 0)
        return;
    if (Unk_LockGuard guard = m_128) {} else
    {
        for (int i = 0; i < 2; i++) {
            if (i == 0 && nLevel == 0)
                continue;
            ATL::CAtlMap<unsigned long, int>& sales = m_158[i];
            for (POSITION pos = sales.GetStartPosition(); pos != NULL; sales.GetNext(pos)) {
                const ATL::CAtlMap<unsigned long, int>::CPair* pPair = sales.GetAt(pos);
                if (pPair == NULL)
                    continue;
                if ((unsigned)pPair->m_value < nMin)
                    continue;
                out.Add(pPair->m_key);
            }
        }
    }
}

// @0x140477020
void CGameRule::FUN_140477020(int eventId, int a, int b, int c)
{
    Unk_CriticalSectionLock lock(m_260, 1);
    m_290.Set(eventId, 0, a);
    m_2b0.Set(eventId, 0, b);
    m_2d0.Set(eventId, 0, c);
}

// @0x1404770e0
void CGameRule::FUN_1404770e0(int eventId)
{
    Unk_CriticalSectionLock lock(m_260, 1);
    m_290.Remove(eventId, 0);
    m_2b0.Remove(eventId, 0);
    m_2d0.Remove(eventId, 0);
}

// @0x140477180
__int64 CGameRule::FUN_140477180()
{
    Unk_CriticalSectionLock lock(m_260, 1);
    unsigned rate = m_290.Get(0, 0);
    return FUN_140482050(*FUN_1401d3200()->MeratConsumeSuperChat.Get(), rate);
}

// @0x140477210
__int64 CGameRule::FUN_140477210()
{
    Unk_CriticalSectionLock lock(m_260, 1);
    unsigned rate = m_2b0.Get(0, 0);
    return FUN_140482050(*FUN_1401d3200()->MeratConsumeWorldChat.Get(), rate);
}

// @0x1404772a0
__int64 CGameRule::FUN_1404772a0()
{
    Unk_CriticalSectionLock lock(m_260, 1);
    unsigned rate = m_2d0.Get(0, 0);
    return FUN_140482050(*FUN_1401d3200()->MeratConsumeChannelChat.Get(), rate);
}

// @0x140477330
__int64 CGameRule::FUN_140477330()
{
    return *FUN_1401d3200()->PetChangeNameMerat.Get();
}

// @0x140477360
void CGameRule::FUN_140477360(int eventId, MS2Ptr<SAHotTimeEventContext> spContext)
{
    if (Unk_LockGuard guard = m_80) {} else
    {
        if (m_38.Lookup(eventId))
            FUN_140477420(eventId);
        m_38.SetAt(eventId, spContext);
        FUN_14047f9d0();
    }
}

// @0x140477420
void CGameRule::FUN_140477420(int eventId)
{
    if (Unk_LockGuard guard = m_80) {} else
    {
        m_38.RemoveKey(eventId);
        FUN_14047f9d0();
    }
}

// @0x1404774a0
int CGameRule::FUN_1404774a0(unsigned key, int bAll)
{
    Unk_CriticalSectionLock lock(m_80, 1);
    if (bAll != 0)
        return m_b0[key] + m_c0[key];
    return m_b0[key];
}

// @0x140477590
void CGameRule::FUN_140477590(ATL::CAtlList<MS2Ptr<SAHotTimeEventContext> >& list)
{
    if (Unk_LockGuard guard = m_80) {} else
    {
        for (POSITION pos = m_38.GetStartPosition(); pos != NULL; m_38.GetNext(pos))
            list.AddTail(m_38.GetValueAt(pos));
    }
}

// @0x140477640
int CGameRule::FUN_140477640(int bPcBang)
{
    if (Unk_LockGuard guard = m_80) {} else
    {
        if (m_d0 != 0)
            return 1;
        if (bPcBang != 0 && m_d4 != 0)
            return 1;
    }
    return 0;
}

// @0x1404776f0
// MS2-FUNCTIONAL: trailing nop after the LockGuard dtor in the fail path (RECOVERY "Unsolved")
int CGameRule::FUN_1404776f0(int key)
{
    if (Unk_LockGuard guard = m_1e8) {} else
    {
        int value = 0;
        if (m_218.Lookup(key, value))
            return value;
        return 0;
    }
}

// @0x1404777a0
void CGameRule::FUN_1404777a0(int key, int value)
{
    if (Unk_LockGuard guard = m_1e8) {} else
    {
        m_218.SetAt(key, value);
    }
}

// @0x140477820
void CGameRule::FUN_140477820(COutputStream& out, int key)
{
    if (Unk_LockGuard guard = m_1e8) {} else
    {
        if (key == 0) {
            out.vfunc_o10_1((unsigned char)m_218.GetCount());
            for (POSITION pos = m_218.GetStartPosition(); pos != NULL; m_218.GetNext(pos)) {
                int k = m_218.GetKeyAt(pos);
                int v = m_218.GetValueAt(pos);
                out.vfunc_o10_3(k);
                out.vfunc_o10_3(v);
            }
        }
        else {
            int v = FUN_1404776f0(key);
            out.vfunc_o10_1(1);
            out.vfunc_o10_3(key);
            out.vfunc_o10_3(v);
        }
    }
}

// @0x1404779b0
void CGameRule::FUN_1404779b0(CInPacket& packet)
{
    if (Unk_LockGuard guard = m_1e8) {} else
    {
        int count = packet.vfunc_o8_1();
        for (int i = 0; i < count; i++) {
            int k = packet.vfunc_o8_3();
            int v = packet.vfunc_o8_3();
            FUN_1404777a0(k, v);
        }
    }
}

// @0x140477ab0
void CGameRule::FUN_140477ab0(ATL::CAtlArray<std::pair<int, int> >& out)
{
    if (Unk_LockGuard guard = m_1e8) {} else
    {
        for (POSITION pos = m_218.GetStartPosition(); pos != NULL; m_218.GetNext(pos)) {
            int k = m_218.GetKeyAt(pos);
            int v = m_218.GetValueAt(pos);
            out.Add(std::pair<int, int>(k, v));
        }
    }
}

// @0x140477bb0
BOOL CGameRule::FUN_140477bb0()
{
    return TRUE;
}

// @0x140477bd0
void CGameRule::FUN_140477bd0(int eventId, MS2Ptr<MesoRevivalEventContext> spContext)
{
    if (Unk_LockGuard guard = m_338) {} else
    {
        if (m_2f0.Lookup(eventId))
            FUN_140477c90(eventId);
        m_2f0.SetAt(eventId, spContext);
        FUN_14047fc60();
    }
}

// @0x140477c90
void CGameRule::FUN_140477c90(int eventId)
{
    if (Unk_LockGuard guard = m_80) {} else
    {
        m_2f0.RemoveKey(eventId);
        FUN_14047fc60();
    }
}

// @0x140477d10
int CGameRule::FUN_140477d10(int bAll)
{
    if (Unk_LockGuard guard = m_80) {} else
    {
        if (m_368 != 0)
            return 1;
        if (bAll != 0 && m_36c != 0)
            return 1;
    }
    return 0;
}

// @0x140477dc0
void CGameRule::FUN_140477dc0(unsigned eventId)
{
    Unk_GameRuleLock lock(m_370, 1);
    m_3a0.insert(eventId);
}

// @0x140477e30
void CGameRule::FUN_140477e30(unsigned eventId)
{
    Unk_GameRuleLock lock(m_370, 1);
    m_3a0.erase(eventId);
}

// @0x140477ea0
BOOL CGameRule::FUN_140477ea0()
{
    Unk_GameRuleLock lock(m_370, 1);
    return !m_3a0.empty();
}

// @0x140477f20
void CGameRule::FUN_140477f20(int value, CStringW text)
{
    if (Unk_LockGuard guard = m_458) {} else
    {
        m_488.SetAt(value, text);
    }
}

// @0x140477fb0
void CGameRule::FUN_140477fb0(int value)
{
    if (Unk_LockGuard guard = m_458) {} else
    {
        m_488.RemoveKey(value);
    }
}

// @0x140478020
CStringW CGameRule::FUN_140478020(int value)
{
    CStringW str;
    if (Unk_LockGuard guard = m_458) {} else
    {
        m_488.Lookup(value, str);
    }
    return str;
}

// @0x1404780e0
BOOL CGameRule::FUN_1404780e0(int value)
{
    if (Unk_LockGuard guard = m_458) {} else
    {
        if (m_488.Lookup(value) != NULL)
            return TRUE;
    }
    return FALSE;
}

// @0x140478170
void CGameRule::FUN_140478170(int eventId, MS2Ptr<OntimeEventContext> spContext)
{
    Unk_GameRuleLock lock(m_4d0, 1);
    m_500.SetAt(eventId, spContext);
}

// @0x1404781f0
void CGameRule::FUN_1404781f0(int eventId)
{
    Unk_GameRuleLock lock(m_4d0, 1);
    ATL::CAtlMap<int, MS2Ptr<OntimeEventContext> >::CPair* pPair = m_500.Lookup(eventId);
    if (pPair != NULL)
        pPair->m_value->m_1c = false;
}

// @0x140478280
MS2Ptr<OntimeEventContext> CGameRule::FUN_140478280()
{
    Unk_GameRuleLock lock(m_4d0, 1);
    for (POSITION pos = m_500.GetStartPosition(); pos != NULL; m_500.GetNext(pos)) {
        MS2Ptr<OntimeEventContext> pEventCtx = m_500.GetValueAt(pos);
        MS2_ASSERT_AT(0x317, pEventCtx != NULL);
        if (pEventCtx->m_1c == true)
            return pEventCtx;
    }
    return MS2Ptr<OntimeEventContext>(0);
}

// @0x1404783e0
MS2Ptr<OntimeEventContext> CGameRule::FUN_1404783e0(int eventId)
{
    Unk_GameRuleLock lock(m_4d0, 1);
    ATL::CAtlMap<int, MS2Ptr<OntimeEventContext> >::CPair* pPair = m_500.Lookup(eventId);
    if (pPair != NULL)
        return pPair->m_value;
    return MS2Ptr<OntimeEventContext>(0);
}

// @0x1404784b0
void CGameRule::FUN_1404784b0(int a, __int64 b, CStringW str)
{
    if (Unk_LockGuard guard = m_9d8) {} else
    {
        MS2Ptr<UgcMapCommendationGMEvent> spOld(0);
        m_a08.Lookup(a, spOld);
        if (spOld.get())
            m_a08.RemoveKey(a);
        MS2Ptr<UgcMapCommendationGMEvent> spEvent(new UgcMapCommendationGMEvent(a, b, str));
        m_a08.SetAt(a, spEvent);
    }
}

// @0x140478640
void CGameRule::FUN_140478640(int a)
{
    if (Unk_LockGuard guard = m_9d8) {} else
    {
        m_a08.RemoveKey(a);
    }
}

// @0x1404786b0
MS2Ptr<UgcMapCommendationGMEvent> CGameRule::FUN_1404786b0(int a)
{
    MS2Ptr<UgcMapCommendationGMEvent> spEvent(0);
    if (Unk_LockGuard guard = m_9d8) {} else
    {
        m_a08.Lookup(a, spEvent);
    }
    return spEvent;
}

// @0x140478770
// MS2-FUNCTIONAL: Unk_GEBoxPtr approximation (exe: default ctor + operator==(0) 0x14049bf10 + operator=(tag) 0x14049f920)
void CGameRule::FUN_140478770(int value, int key, int sub)
{
    if (Unk_LockGuard guard = m_a38) {} else
    {
        IntMapBox box(0);
        m_a68.Lookup(key, box);
        if (box.get() == NULL) {
            box = IntMapBox(Unk_BingoNewTag(0));
            m_a68.SetAt(key, box);
        }
        if (box->Lookup(sub))
            box->RemoveKey(sub);
        box->SetAt(sub, value);
    }
}

// @0x1404788a0
// MS2-FUNCTIONAL: Unk_GEBoxPtr approximation (see 0x140478770)
void CGameRule::FUN_1404788a0(int key, int sub)
{
    if (Unk_LockGuard guard = m_a38) {} else
    {
        IntMapBox box(0);
        m_a68.Lookup(key, box);
        if (box.get())
            box->RemoveKey(sub);
    }
}

// @0x140478960
// MS2-FUNCTIONAL: Unk_GEBoxPtr approximation (see 0x140478770)
void CGameRule::FUN_140478960(int key, ATL::CRBMap<int, int>& out)
{
    out.RemoveAll();
    if (Unk_LockGuard guard = m_a38) {} else
    {
        IntMapBox box(0);
        m_a68.Lookup(key, box);
        if (box.get() == NULL)
            return;
        FUN_1404820e0(out, *box);
    }
}

// @0x140478a40
void CGameRule::FUN_140478a40(int value)
{
    m_a98 = value;
}

// @0x140478a60
int CGameRule::FUN_140478a60()
{
    return m_a98;
}

// @0x140478a80
void CGameRule::FUN_140478a80(int eventId, int rate)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_548.Set(eventId, 0, rate);
}

// @0x140478af0
void CGameRule::FUN_140478af0(int eventId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_548.Remove(eventId, 0);
}

// @0x140478b60
unsigned CGameRule::FUN_140478b60()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_548.Get(0, 0);
}

// @0x140478bd0
void CGameRule::FUN_140478bd0(int eventId, int type, int rate)
{
    if (Unk_LockGuard guard = m_8) {} else
    {
        m_568.Set(eventId, type, rate);
    }
}

// @0x140478c50
void CGameRule::FUN_140478c50(int eventId, int type)
{
    if (Unk_LockGuard guard = m_8) {} else
    {
        m_568.Remove(eventId, type);
    }
}

// @0x140478cd0
unsigned CGameRule::FUN_140478cd0(MS2Ptr<CItemData> spItem)
{
    if (spItem == 0)
        return 0;
    int type = 0;
    if (spItem->FUN_14053d600())
        type = 1;
    else if (spItem->FUN_14053d5c0())
        type = 2;
    else if (spItem->FUN_14053cc40())
        type = 3;
    return FUN_140478db0(type);
}

// @0x140478db0
// MS2-FUNCTIONAL: trailing nop after the LockGuard dtor in the fail path (RECOVERY "Unsolved")
unsigned CGameRule::FUN_140478db0(int type)
{
    if (Unk_LockGuard guard = m_8) {} else
    {
        unsigned rate = m_568.Get(type, 0);
        unsigned rateAll = m_568.Get(0, 0);
        return rateAll > rate ? rateAll : rate;
    }
}

// @0x140478e80
void CGameRule::FUN_140478e80(int eventId, int rate)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_588.Set(eventId, 0, rate);
}

// @0x140478ef0
void CGameRule::FUN_140478ef0(int eventId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_588.Remove(eventId, 0);
}

// @0x140478f60
unsigned CGameRule::FUN_140478f60()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_588.Get(0, 0);
}

// @0x140478fd0
void CGameRule::FUN_140478fd0(CStringW tag, MS2Ptr<EventQuestContext> spContext)
{
    if (Unk_LockGuard guard = m_5a8) {} else
    {
        m_5d8.SetAt(tag, spContext);
    }
}

// @0x140479070
void CGameRule::FUN_140479070(CStringW tag)
{
    if (Unk_LockGuard guard = m_5a8) {} else
    {
        m_5d8.RemoveKey(tag);
    }
}

// @0x140479100
BOOL CGameRule::FUN_140479100(CStringW tag)
{
    return FUN_1404791b0(tag).get() != NULL;
}

// @0x1404791b0
MS2Ptr<EventQuestContext> CGameRule::FUN_1404791b0(CStringW tag)
{
    MS2Ptr<EventQuestContext> spContext(0);
    if (Unk_LockGuard guard = m_5a8) {} else
    {
        m_5d8.Lookup(tag, spContext);
    }
    return spContext;
}

// @0x140479280
void CGameRule::FUN_140479280(MS2Ptr<TermTagContext> spContext)
{
    Unk_CriticalSectionLock lock(m_620, 1);
    m_650[spContext->FUN_140866690()] = spContext;
}

// @0x140479330
void CGameRule::FUN_140479330(const CStringW& name)
{
    Unk_CriticalSectionLock lock(m_620, 1);
    m_650.erase(name);
}

// @0x1404793a0
bool CGameRule::FUN_1404793a0(const CStringW& name)
{
    if (FUN_140479410(name) == 0)
        return false;
    return true;
}

// @0x140479410
MS2Ptr<TermTagContext> CGameRule::FUN_140479410(const CStringW& name)
{
    Unk_CriticalSectionLock lock(m_620, 1);
    std::unordered_map<CStringW, MS2Ptr<TermTagContext> >::iterator it = m_650.find(name);
    if (it == m_650.end())
        return MS2Ptr<TermTagContext>(0);
    return it->second;
}

// @0x140479510
void CGameRule::FUN_140479510(int rate, __int64 beginTime, __int64 endTime)
{
    m_690 = rate;
    m_698 = beginTime;
    m_6a0 = endTime;
}

// @0x140479560
int CGameRule::FUN_140479560()
{
    return m_690;
}

// @0x140479580
__int64 CGameRule::FUN_140479580()
{
    return m_698;
}

// @0x1404795a0
__int64 CGameRule::FUN_1404795a0()
{
    return m_6a0;
}

// @0x1404795c0
void CGameRule::FUN_1404795c0(int value)
{
    m_6f0 = value;
}

// @0x1404795e0
int CGameRule::FUN_1404795e0()
{
    return m_6f0;
}

// @0x140479600
void CGameRule::FUN_140479600(int value)
{
    m_6a8 = value;
}

// @0x140479620
int CGameRule::FUN_140479620()
{
    return m_6a8;
}

// @0x140479640
void CGameRule::FUN_140479640(int eventId, int rate)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_6b0.Set(eventId, 0, rate);
}

// @0x1404796b0
void CGameRule::FUN_1404796b0(int eventId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_6b0.Remove(eventId, 0);
}

// @0x140479720
unsigned CGameRule::FUN_140479720()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_6b0.Get(0, 0);
}

// @0x140479790
void CGameRule::FUN_140479790(int eventId, int rate)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_6d0.Set(eventId, 0, rate);
}

// @0x140479800
void CGameRule::FUN_140479800(int eventId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_6d0.Remove(eventId, 0);
}

// @0x140479870
unsigned CGameRule::FUN_140479870()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_6d0.Get(0, 0);
}

// @0x1404798e0
void CGameRule::FUN_1404798e0(int value)
{
    m_6f4 = value;
}

// @0x140479900
int CGameRule::FUN_140479900()
{
    return m_6f4;
}

// @0x140479920
void CGameRule::FUN_140479920(CStringW str)
{
    m_6f8 = str;
}

// @0x140479970
CStringW CGameRule::FUN_140479970()
{
    if (m_6f8.IsEmpty())
        return CStringW(L"AutoFishing");
    return m_6f8;
}

// @0x140479a00
void CGameRule::FUN_140479a00(int value)
{
    m_700 = value;
}

// @0x140479a20
int CGameRule::FUN_140479a20()
{
    return m_700;
}

// @0x140479a40
void CGameRule::FUN_140479a40(CStringW str)
{
    m_708 = str;
}

// @0x140479a90
CStringW CGameRule::FUN_140479a90()
{
    if (m_708.IsEmpty())
        return CStringW(L"AutoPlayInstrument");
    return m_708;
}

// @0x140479b20
bool CGameRule::FUN_140479b20(unsigned roomId)
{
    Unk_CriticalSectionLock lock(m_710, 1);
    if (m_740 == 0)
        return false;
    return m_740->FUN_1403440d0(roomId);
}

// @0x140479bd0
bool CGameRule::FUN_140479bd0(Unk_DungeonGroupType group)
{
    Unk_CriticalSectionLock lock(m_710, 1);
    if (m_740 == 0)
        return false;
    return m_740->FUN_140344140(group);
}

// @0x140479c80
void CGameRule::FUN_140479c80(MS2Ptr<DungeonRoomShutdownContext> spContext)
{
    Unk_CriticalSectionLock lock(m_710, 1);
    m_740 = spContext;
}

// @0x140479cf0
bool CGameRule::FUN_140479cf0(unsigned roomId)
{
    Unk_CriticalSectionLock lock(m_750, 1);
    if (m_780 == 0)
        return false;
    return m_780->FUN_1403440d0(roomId);
}

// @0x140479da0
void CGameRule::FUN_140479da0(MS2Ptr<DungeonRoomShutdownContext> spContext)
{
    Unk_CriticalSectionLock lock(m_750, 1);
    m_780 = spContext;
}

// @0x140479e10
bool CGameRule::FUN_140479e10(unsigned dungeonId)
{
    Unk_CriticalSectionLock lock(m_790, 1);
    Unk_DayTime now(FUN_140869440());
    typedef std::multimap<unsigned, MS2Ptr<EventTimeLimitDungeonContext> >::iterator Iter;
    std::pair<Iter, Iter> range = m_7c0.equal_range(dungeonId);
    for (; range.first != range.second; range.first++) {
        MS2Ptr<EventTimeLimitDungeonContext> spContext = range.first->second;
        if (spContext->m_rangeTime.Contains(now))
            return true;
    }
    return false;
}

// @0x140479f30
void CGameRule::FUN_140479f30(std::vector<MS2Ptr<EventTimeLimitDungeonContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_790, 1);
    for (size_t i = 0; i < contexts.size(); i++) {
        if (contexts[i]->m_eventId == 0 || contexts[i]->m_dungeonId == 0) {
            MS2_ASSERT_AT(0x48c, 0);
            continue;
        }
        m_7c0.insert(std::make_pair(contexts[i]->m_dungeonId, contexts[i]));
    }
}

// @0x14047a0a0
void CGameRule::FUN_14047a0a0(int eventId)
{
    Unk_CriticalSectionLock lock(m_790, 1);
    std::multimap<unsigned, MS2Ptr<EventTimeLimitDungeonContext> >::iterator it = m_7c0.begin();
    while (it != m_7c0.end()) {
        MS2Ptr<EventTimeLimitDungeonContext> spContext = it->second;
        if (spContext->m_eventId == eventId)
            m_7c0.erase(it++);
        else
            ++it;
    }
}

// @0x14047a1b0
void CGameRule::FUN_14047a1b0(unsigned dungeonId, std::vector<Unk_DayTimeRange>& out)
{
    typedef std::multimap<unsigned, MS2Ptr<EventTimeLimitDungeonContext> >::iterator Iter;
    std::pair<Iter, Iter> range = m_7c0.equal_range(dungeonId);
    for (; range.first != range.second; range.first++) {
        MS2Ptr<EventTimeLimitDungeonContext> spContext = range.first->second;
        out.push_back(spContext->m_rangeTime);
    }
}

// @0x14047a270
bool CGameRule::FUN_14047a270(unsigned id)
{
    Unk_GameRuleLock lock(m_7d0, 1);
    if (m_800.empty())
        return false;
    if (m_800.find(id) == m_800.end())
        return false;
    return true;
}

// @0x14047a360
void CGameRule::FUN_14047a360(std::set<unsigned> ids)
{
    Unk_GameRuleLock lock(m_7d0, 1);
    m_800 = ids;
}

// @0x14047a3d0
void CGameRule::FUN_14047a3d0()
{
    Unk_GameRuleLock lock(m_7d0, 1);
    m_800.clear();
}

// @0x14047a420
bool CGameRule::FUN_14047a420(unsigned dungeonId, MS2Ptr<DungeonExtraRewardCountCtx> spCount)
{
    Unk_CriticalSectionLock lock(m_810, 1);
    if (m_840.Lookup(dungeonId) != NULL)
        return false;
    m_840.SetAt(dungeonId, spCount);
    return true;
}

// @0x14047a4e0
void CGameRule::FUN_14047a4e0(unsigned dungeonId, int eventId)
{
    Unk_CriticalSectionLock lock(m_810, 1);
    MS2Ptr<DungeonExtraRewardCountCtx> spCount;
    if (m_840.Lookup(dungeonId, spCount)) {
        if (spCount->m_18 != eventId)
            return;
        m_840.RemoveKey(dungeonId);
    }
}

// @0x14047a5b0
MS2Ptr<DungeonExtraRewardCountCtx> CGameRule::FUN_14047a5b0(unsigned dungeonId)
{
    Unk_CriticalSectionLock lock(m_810, 1);
    MS2Ptr<DungeonExtraRewardCountCtx> spCount;
    if (m_840.Lookup(dungeonId, spCount))
        return spCount;
    return MS2Ptr<DungeonExtraRewardCountCtx>(0);
}

// @0x14047a6a0
void CGameRule::FUN_14047a6a0(int eventId, MS2Ptr<NpcEventDropEventContext> spContext)
{
    Unk_CriticalSectionLock lock(m_418, 1);
    m_448[eventId] = spContext;
}

// @0x14047a730
void CGameRule::FUN_14047a730(int eventId)
{
    Unk_CriticalSectionLock lock(m_418, 1);
    m_448.erase(eventId);
}

// @0x14047a7a0
void CGameRule::FUN_14047a7a0(std::vector<MS2Ptr<NpcEventDropEventContext> >& out)
{
    if (m_448.empty())
        return;
    Unk_CriticalSectionLock lock(m_418, 1);
    out.reserve(out.size() + m_448.size());
    std::map<unsigned, MS2Ptr<NpcEventDropEventContext> >::iterator it = m_448.begin();
    std::map<unsigned, MS2Ptr<NpcEventDropEventContext> >::iterator itEnd = m_448.end();
    for (; it != itEnd; ++it)
        out.push_back(it->second);
}

// @0x14047a8c0
void CGameRule::FUN_14047a8c0(int type)
{
    m_3b0 = type;
}

// @0x14047a8e0
int CGameRule::FUN_14047a8e0()
{
    return m_3b0;
}

// @0x14047a900
void CGameRule::FUN_14047a900(MS2Ptr<DungeonBonusRewardCtx> spContext)
{
    if (spContext == 0)
        return;
    Unk_CriticalSectionLock lock(m_8, 1);
    if (spContext->m_groupType != 0)
        m_3b8[spContext->m_groupType].insert(spContext);
    if (spContext->m_dungeonID != 0)
        m_3c8[spContext->m_dungeonID].insert(spContext);
}

// @0x14047aa00
void CGameRule::FUN_14047aa00(MS2Ptr<DungeonBonusRewardCtx> spContext)
{
    if (spContext == 0)
        return;
    Unk_CriticalSectionLock lock(m_8, 1);
    if (spContext->m_groupType != 0) {
        std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts = m_3b8[spContext->m_groupType];
        contexts.erase(spContext);
        if (contexts.empty())
            m_3b8.erase(spContext->m_groupType);
    }
    if (spContext->m_dungeonID != 0) {
        std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts = m_3c8[spContext->m_dungeonID];
        contexts.erase(spContext);
        if (contexts.empty())
            m_3c8.erase(spContext->m_dungeonID);
    }
}

// @0x14047ab70
MS2Ptr<DungeonBonusRewardCtx> CGameRule::FUN_14047ab70(Unk_DungeonGroupType group)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    std::map<Unk_DungeonGroupType, std::set<MS2Ptr<DungeonBonusRewardCtx> > >::iterator it = m_3b8.find(group);
    if (it == m_3b8.end())
        return MS2Ptr<DungeonBonusRewardCtx>(0);
    std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts = it->second;
    if (contexts.size() == 1)
        return *contexts.begin();
    MS2Ptr<DungeonBonusRewardCtx> spMerged = FUN_14047ae90(contexts);
    return spMerged;
}

// @0x14047ad00
MS2Ptr<DungeonBonusRewardCtx> CGameRule::FUN_14047ad00(unsigned dungeonId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    std::map<unsigned, std::set<MS2Ptr<DungeonBonusRewardCtx> > >::iterator it = m_3c8.find(dungeonId);
    if (it == m_3c8.end())
        return MS2Ptr<DungeonBonusRewardCtx>(0);
    std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts = it->second;
    if (contexts.size() == 1)
        return *contexts.begin();
    MS2Ptr<DungeonBonusRewardCtx> spMerged = FUN_14047ae90(contexts);
    return spMerged;
}

// @0x14047ae90
MS2Ptr<DungeonBonusRewardCtx> CGameRule::FUN_14047ae90(const std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts)
{
    std::set<MS2Ptr<DungeonBonusRewardCtx> >::const_iterator it = contexts.begin();
    std::set<MS2Ptr<DungeonBonusRewardCtx> >::const_iterator end = contexts.end();
    MS2Ptr<DungeonBonusRewardCtx> spMerged(new DungeonBonusRewardCtx);
    for (; it != end; ++it)
        spMerged->Merge(*it);
    return spMerged;
}

// @0x14047afb0
void CGameRule::FUN_14047afb0(MS2Ptr<DungeonBonusRewardCtx> spContext)
{
    if (spContext == 0)
        return;
    Unk_CriticalSectionLock lock(m_3d8, 1);
    if (spContext->m_dungeonID != 0)
        m_408[spContext->m_dungeonID].insert(spContext);
}

// @0x14047b070
void CGameRule::FUN_14047b070(MS2Ptr<DungeonBonusRewardCtx> spContext)
{
    if (spContext == 0)
        return;
    Unk_CriticalSectionLock lock(m_3d8, 1);
    if (spContext->m_dungeonID != 0) {
        std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts = m_408[spContext->m_dungeonID];
        contexts.erase(spContext);
        if (contexts.empty())
            m_408.erase(spContext->m_dungeonID);
    }
}

// @0x14047b170
MS2Ptr<DungeonBonusRewardCtx> CGameRule::FUN_14047b170(unsigned dungeonId)
{
    Unk_CriticalSectionLock lock(m_3d8, 1);
    std::map<unsigned, std::set<MS2Ptr<DungeonBonusRewardCtx> > >::iterator it = m_408.find(dungeonId);
    if (it == m_408.end())
        return MS2Ptr<DungeonBonusRewardCtx>(0);
    std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts = it->second;
    if (contexts.size() == 1)
        return *contexts.begin();
    MS2Ptr<DungeonBonusRewardCtx> spMerged = FUN_14047ae90(contexts);
    return spMerged;
}

// @0x14047b300
void CGameRule::FUN_14047b300(unsigned dungeonId, Unk_DungeonGroupType group, std::vector<unsigned>& out)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    std::map<Unk_DungeonGroupType, std::set<MS2Ptr<DungeonBonusRewardCtx> > >::iterator itGroup = m_3b8.find(group);
    if (itGroup != m_3b8.end()) {
        std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts = itGroup->second;
        for (std::set<MS2Ptr<DungeonBonusRewardCtx> >::iterator it = contexts.begin(); it != contexts.end(); ++it) {
            MS2Ptr<DungeonBonusRewardCtx> spContext = *it;
            Unk_AppendVector(spContext->m_customDropBoxIds, out);
        }
    }
    std::map<unsigned, std::set<MS2Ptr<DungeonBonusRewardCtx> > >::iterator itDungeon = m_3c8.find(dungeonId);
    if (itDungeon != m_3c8.end()) {
        std::set<MS2Ptr<DungeonBonusRewardCtx> >& contexts = itDungeon->second;
        for (std::set<MS2Ptr<DungeonBonusRewardCtx> >::iterator it = contexts.begin(); it != contexts.end(); ++it) {
            MS2Ptr<DungeonBonusRewardCtx> spContext = *it;
            Unk_AppendVector(spContext->m_customDropBoxIds, out);
        }
    }
}

// @0x14047b540
void CGameRule::FUN_14047b540(MS2Ptr<SkillUpgradeSaleEventContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_890.SetAt(spContext->m_18, spContext);
}

// @0x14047b5c0
void CGameRule::FUN_14047b5c0(unsigned skillId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_890.RemoveKey(skillId);
}

// @0x14047b620
MS2Ptr<SkillUpgradeSaleEventContext> CGameRule::FUN_14047b620(unsigned skillId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    MS2Ptr<SkillUpgradeSaleEventContext> spContext(0);
    m_890.Lookup(skillId, spContext);
    return spContext;
}

// @0x14047b6d0
void CGameRule::FUN_14047b6d0(const CStringW& str)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_888 = str;
}

// @0x14047b740
CStringW CGameRule::FUN_14047b740()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_888;
}

// @0x14047b7c0
unsigned CGameRule::FUN_14047b7c0(float rate, int value)
{
    if (rate > 0)
        return (unsigned)max((double)value, value * (1.0 + rate));
    return value;
}

// @0x14047b860
unsigned CGameRule::FUN_14047b860(float rate, unsigned value)
{
    if (rate > 0)
        return (unsigned)max(1.0f, value * (1.0f - rate));
    return value;
}

// @0x14047b8f0
void CGameRule::FUN_14047b8f0(MS2Ptr<BlueMarbleEventContext> spContext)
{
    m_8d8 = spContext;
}

// @0x14047b940
MS2Ptr<BlueMarbleEventContext> CGameRule::FUN_14047b940()
{
    return m_8d8;
}

// @0x14047b990
void CGameRule::FUN_14047b990(int value)
{
    m_8e8 = value;
}

// @0x14047b9b0
int CGameRule::FUN_14047b9b0()
{
    return m_8e8;
}

// @0x14047b9d0
void CGameRule::FUN_14047b9d0(int eventId, int rate)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_8f0.Set(eventId, 0, rate);
}

// @0x14047ba40
void CGameRule::FUN_14047ba40(int eventId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_8f0.Remove(eventId, 0);
}

// @0x14047bab0
unsigned CGameRule::FUN_14047bab0()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_8f0.Get(0, 0);
}

// @0x14047bb20
// MS2-FUNCTIONAL: exe has no EH info: CMsTime::operator= (0x1406c4930) is nothrow there; mstime.h is shared
void CGameRule::FUN_14047bb20(bool bOn, const CMsTime& time)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_910 = bOn;
    m_918 = time;
}

// @0x14047bb90
bool CGameRule::FUN_14047bb90()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_910;
}

// @0x14047bbe0
CMsTime CGameRule::FUN_14047bbe0()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_918;
}

// @0x14047bc50
// MS2-FUNCTIONAL: Unk_GEBoxPtr approximation (see 0x140478770)
__int64 CGameRule::FUN_14047bc50(Unk_SaleHousingKey key, int type, __int64 price)
{
    Unk_CriticalSectionLock lock(m_aa0, 1);
    for (POSITION pos = m_ad0.GetHeadPosition(); pos != NULL; m_ad0.GetNext(pos)) {
        SaleCubeBox box = m_ad0.GetValueAt(pos);
        if (!(box.get() == NULL)) {
            POSITION posCube = box->FindFirstWithKey(key);
            while (posCube) {
                MS2Ptr<SaleCube> spCube = box->GetNextValueWithKey(posCube, key);
                if (!(spCube == 0) && spCube->m_1c == type)
                    return (__int64)((float)price * (1.0f - (float)spCube->m_20 / 10000.0f) + 0.5f);
            }
        }
    }
    return price;
}

// @0x14047be80
void CGameRule::FUN_14047be80(int eventId, ATL::CRBMultiMap<Unk_SaleHousingKey, MS2Ptr<SaleCube> >& cubes)
{
    Unk_CriticalSectionLock lock(m_aa0, 1);
    m_ad0.RemoveKey(eventId);
    SaleCubeBox box(Unk_BingoNewTag(0));
    for (POSITION pos = cubes.GetHeadPosition(); pos != NULL; cubes.GetNext(pos)) {
        Unk_SaleHousingKey key = cubes.GetKeyAt(pos);
        MS2Ptr<SaleCube> spCube = cubes.GetValueAt(pos);
        box->Insert(key, spCube);
    }
    m_ad0.SetAt(eventId, box);
}

// @0x14047bfc0
void CGameRule::FUN_14047bfc0(int eventId)
{
    Unk_CriticalSectionLock lock(m_aa0, 1);
    m_ad0.RemoveKey(eventId);
}

// @0x14047c020
void CGameRule::FUN_14047c020(int eventId, __int64 endTime, const CStringA& a, const CStringA& b, const CStringA& c)
{
    Unk_CriticalSectionLock lock(m_b00, 1);
    MS2Ptr<EpicRestartContext> spContext(new EpicRestartContext);
    spContext->m_18 = eventId;
    spContext->m_20 = endTime;
    XmlSplit(c, spContext->m_58, ",");
    ATL::CAtlArray<unsigned> values;
    XmlSplit(b, values, ",");
    if (values.GetCount() > 0)
        spContext->m_78 = values[0];
    if (values.GetCount() > 1)
        spContext->m_7c = values[1];
    m_b30 = spContext;
}

// @0x14047c1e0
void CGameRule::FUN_14047c1e0()
{
    Unk_CriticalSectionLock lock(m_b00, 1);
    m_b30 = 0;
}

// @0x14047c240
int CGameRule::FUN_14047c240()
{
    Unk_CriticalSectionLock lock(m_b00, 1);
    if (m_b30 == 0)
        return 0;
    return m_b30->m_18;
}

// @0x14047c2e0
__int64 CGameRule::FUN_14047c2e0()
{
    Unk_CriticalSectionLock lock(m_b00, 1);
    if (m_b30 == 0)
        return 0;
    return m_b30->m_20;
}

// @0x14047c380
BOOL CGameRule::FUN_14047c380(unsigned value)
{
    Unk_CriticalSectionLock lock(m_b00, 1);
    if (m_b30 == 0)
        return FALSE;
    if (m_b30->m_28.find(value) != m_b30->m_28.end())
        return TRUE;
    for (size_t i = 0; i < m_b30->m_38.GetCount(); i++) {
        if (m_b30->m_38[i].IsIn(value))
            return TRUE;
    }
    return FALSE;
}

// @0x14047c530
BOOL CGameRule::FUN_14047c530(unsigned value)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (m_b30 == 0)
        return FALSE;
    if (FUN_140408410(&m_b30->m_58, &value) != -1)
        return FALSE;
    return TRUE;
}

// @0x14047c600
int CGameRule::FUN_14047c600()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (m_b30 == 0)
        return 0;
    return m_b30->m_78;
}

// @0x14047c6a0
int CGameRule::FUN_14047c6a0()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (m_b30 == 0)
        return 0;
    return m_b30->m_7c;
}

// @0x14047c740
void CGameRule::FUN_14047c740(int level, const CStringW& str)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_b40 = level;
    FUN_140274fc0(str, &m_b48, L",");
}

// @0x14047c7c0
void CGameRule::FUN_14047c7c0()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_b40 = 0;
    m_b48.RemoveAll();
}

// @0x14047c820
int CGameRule::FUN_14047c820()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_b40;
}

// @0x14047c870
void CGameRule::FUN_14047c870(ATL::CAtlArray<unsigned>& out)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    out.Copy(m_b48);
}

// @0x14047c8e0
// MS2-FUNCTIONAL: exe passes the m_b68 key by pointer: a non-primitive key type (enum/struct) not recovered
void CGameRule::FUN_14047c8e0(MS2Ptr<StampEventContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (spContext == 0)
        return;
    m_b68.SetAt(spContext->m_98, spContext);
}

// @0x14047c990
// MS2-FUNCTIONAL: m_b68 key type (see 0x14047c8e0)
void CGameRule::FUN_14047c990(MS2Ptr<StampEventContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (spContext == 0)
        return;
    m_b68.RemoveKey(spContext->m_98);
}

// @0x14047ca40
// MS2-FUNCTIONAL: m_b68 key type (see 0x14047c8e0)
MS2Ptr<StampEventContext> CGameRule::FUN_14047ca40(Unk_AttendTable& table)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    MS2Ptr<StampEventContext> spContext;
    if (m_b68.Lookup(10001, spContext) && table.FUN_140482280(10001, false))
        return spContext;
    if (m_b68.Lookup(10002, spContext) && table.FUN_140482280(10002, false))
        return spContext;
    if (m_b68.Lookup(0, spContext))
        return spContext;
    POSITION pos = m_b68.GetStartPosition();
    while (pos) {
        spContext = m_b68.GetValueAt(pos);
        if (spContext->m_98 == 0 || table.FUN_140482280(spContext->m_98, false))
            return spContext;
        m_b68.GetNext(pos);
    }
    return MS2Ptr<StampEventContext>(0);
}

// @0x14047cd30
void CGameRule::FUN_14047cd30(MS2Ptr<LongTermAttendGiftContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (spContext == 0)
        return;
    m_ef8 = spContext;
}

// @0x14047cdd0
void CGameRule::FUN_14047cdd0(MS2Ptr<LongTermAttendGiftContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (spContext == 0)
        return;
    m_ef8 = 0;
}

// @0x14047ce70
MS2Ptr<LongTermAttendGiftContext> CGameRule::FUN_14047ce70()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_ef8;
}

// @0x14047cef0
void CGameRule::FUN_14047cef0(MS2Ptr<GalleryContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_bb0 = spContext;
}

// @0x14047cf60
MS2Ptr<GalleryContext> CGameRule::FUN_14047cf60()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_bb0;
}

// @0x14047cfe0
void CGameRule::FUN_14047cfe0(MS2Ptr<SnowmanContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_bc0 = spContext;
}

// @0x14047d050
MS2Ptr<SnowmanContext> CGameRule::FUN_14047d050()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_bc0;
}

// @0x14047d0d0
void CGameRule::FUN_14047d0d0(MS2Ptr<RpsContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_bd0 = spContext;
}

// @0x14047d140
MS2Ptr<RpsContext> CGameRule::FUN_14047d140()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_bd0;
}

// @0x14047d1c0
void CGameRule::FUN_14047d1c0(MS2Ptr<ReactorContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_be0 = spContext;
}

// @0x14047d230
MS2Ptr<ReactorContext> CGameRule::FUN_14047d230()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_be0;
}

// @0x14047d2b0
void CGameRule::FUN_14047d2b0(MS2Ptr<TreeWateringContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_bf0 = spContext;
}

// @0x14047d320
MS2Ptr<TreeWateringContext> CGameRule::FUN_14047d320()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_bf0;
}

// @0x14047d3a0
void CGameRule::FUN_14047d3a0(MS2Ptr<Unk_GameRuleC00Context> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_c00 = spContext;
}

// @0x14047d410
MS2Ptr<Unk_GameRuleC00Context> CGameRule::FUN_14047d410()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_c00;
}

// @0x14047d490
void CGameRule::FUN_14047d490(unsigned value)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_c10 = value;
}

// @0x14047d4e0
float CGameRule::FUN_14047d4e0()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (m_c10 > 0)
        return (float)m_c10 / 100.0f;
    return 0.0f;
}

// @0x14047d570
void CGameRule::FUN_14047d570(unsigned value)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_c14 = value;
}

// @0x14047d5c0
float CGameRule::FUN_14047d5c0()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (m_c14 > 0)
        return (float)m_c14 / 100.0f;
    return 0.0f;
}

// @0x14047d650
void CGameRule::FUN_14047d650(MS2Ptr<TimeRunEventContext> spContext)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_e98 = spContext;
}

// @0x14047d6c0
MS2Ptr<TimeRunEventContext> CGameRule::FUN_14047d6c0()
{
    Unk_CriticalSectionLock lock(m_8, 1);
    return m_e98;
}

// @0x14047d740
int CGameRule::FUN_14047d740(unsigned questId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (m_e98.get()) {
        MS2Ptr<TimeRunEventContext::QuestContext> spQuest(0);
        if (m_e98->m_quests.Lookup(questId, spQuest))
            return spQuest->m_20;
    }
    return 0;
}

// @0x14047d820
void CGameRule::FUN_14047d820(int eventId, const CStringW& text)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    CStringW str(text);
    str.Replace(L"\\n", L" ");
    if (str.IsEmpty())
        return;
    m_c18.SetAt(eventId, str);
    m_c60 = true;
}

// @0x14047d900
void CGameRule::FUN_14047d900(int eventId)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (m_c18.RemoveKey(eventId))
        m_c60 = true;
}

#ifdef __clang__
CStringW FUN_1401d0080(const CStringW& strLeft, const CStringW& strRight);
#endif

// @0x14047d970
bool CGameRule::FUN_14047d970(CStringW& strNotice)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    if (!m_c60)
        return false;
    m_c60 = false;
    if (m_c18.IsEmpty())
        return true;
    CStringW strSeparator(L"       ");
    for (POSITION pos = m_c18.GetStartPosition(); pos != NULL; m_c18.GetNext(pos))
#ifdef __clang__
        // clang otherwise emits an unavailable CopyChars DLL import; bind the exe's operator+.
        strNotice += FUN_1401d0080(m_c18.GetValueAt(pos), strSeparator);
#else
        strNotice += m_c18.GetValueAt(pos) + strSeparator;
#endif
    return true;
}

// @0x14047dae0
void CGameRule::FUN_14047dae0(CStringW str)
{
    Unk_CriticalSectionLock lock(m_8, 1);
    m_c68 = str;
}

// @0x14047db50
CStringW CGameRule::FUN_14047db50()
{
    return m_c68;
}

// @0x14047dba0
void CGameRule::FUN_14047dba0(unsigned id, int value)
{
    if (Unk_LockGuard guard = m_c70) {} else
    {
        Unk_ConstructionKey key(id, value);
        if (m_ca0.find(key) == m_ca0.end())
            m_ca0.insert(key);
    }
}

// @0x14047dc80
void CGameRule::FUN_14047dc80(unsigned id, int value)
{
    if (Unk_LockGuard guard = m_c70) {} else
    {
        Unk_ConstructionKey key(id, value);
        if (m_ca0.find(key) != m_ca0.end())
            m_ca0.erase(key);
    }
}

// @0x14047dd60
void CGameRule::FUN_14047dd60()
{
    if (Unk_LockGuard guard = m_c70) {} else
    {
        m_ca0.clear();
    }
}

// @0x14047ddd0
bool CGameRule::FUN_14047ddd0(unsigned id, int value, __int64 objectId)
{
    if (Unk_LockGuard guard = m_c70) {} else
    {
        if (!m_cb0.empty()) {
            if (m_cb0.find(objectId) == m_cb0.end())
                return false;
        }
        Unk_ConstructionKey key(id, value);
        if (m_ca0.find(key) != m_ca0.end())
            return true;
    }
    return false;
}

// @0x14047df50
void CGameRule::FUN_14047df50(__int64 id)
{
    if (Unk_LockGuard guard = m_c70) {} else
    {
        if (m_cb0.find(id) == m_cb0.end())
            m_cb0.insert(id);
    }
}

// @0x14047e020
void CGameRule::FUN_14047e020(__int64 id)
{
    if (Unk_LockGuard guard = m_c70) {} else
    {
        if (m_cb0.find(id) != m_cb0.end())
            m_cb0.erase(id);
    }
}

// @0x14047e0e0
void CGameRule::FUN_14047e0e0()
{
    if (Unk_LockGuard guard = m_c70) {} else
    {
        m_cb0.clear();
    }
}

// @0x14047e150
bool CGameRule::FUN_14047e150(__int64 nId)
{
    if (Unk_LockGuard guard = m_cc0) {} else
    {
        if (!m_cf0.empty() && m_cf0.find(nId) != m_cf0.end())
            return true;
    }
    return false;
}

// @0x14047e230
void CGameRule::FUN_14047e230(__int64 nId)
{
    if (Unk_LockGuard guard = m_cc0) {} else
    {
        if (m_cf0.find(nId) == m_cf0.end())
            m_cf0.insert(nId);
    }
}

// @0x14047e300
void CGameRule::FUN_14047e300()
{
    if (Unk_LockGuard guard = m_cc0) {} else
    {
        m_cf0.clear();
    }
}

// @0x14047e370
// MS2-FUNCTIONAL: EnchantRateEventContext::m_20 is unsigned in the exe (pushed by address); gameevent.h is shared
unsigned CGameRule::FUN_14047e370(int key)
{
    Unk_GameRuleLock lock(m_928, 1);
    if (m_958.size() < 1)
        return 0;
    std::vector<unsigned> rates;
    typedef std::multimap<int, MS2Ptr<EnchantRateEventContext> >::iterator Iter;
    std::pair<Iter, Iter> range = m_958.equal_range(key);
    for (; range.first != range.second; range.first++) {
        MS2Ptr<EnchantRateEventContext> spContext = range.first->second;
        rates.push_back(spContext->m_20);
    }
    if (rates.size() != 0) {
        std::sort(rates.begin(), rates.end(), std::greater<unsigned>());
        return rates[0];
    }
    return 0;
}

// @0x14047e530
void CGameRule::FUN_14047e530(MS2Ptr<EnchantRateEventContext> spContext)
{
    Unk_GameRuleLock lock(m_928, 1);
    if (spContext->m_nEventId == 0) {
        MS2_ASSERT_AT(0x8aa, 0);
        return;
    }
    m_958.insert(std::make_pair(spContext->m_1c, spContext));
}

// @0x14047e630
void CGameRule::FUN_14047e630(int eventId)
{
    Unk_GameRuleLock lock(m_928, 1);
    std::multimap<int, MS2Ptr<EnchantRateEventContext> >::iterator it = m_958.begin();
    while (it != m_958.end()) {
        MS2Ptr<EnchantRateEventContext> spContext = it->second;
        if (spContext->m_nEventId == eventId)
            m_958.erase(it++);
        else
            ++it;
    }
}

// @0x14047e740
void CGameRule::FUN_14047e740(bool bOpen)
{
    Unk_GameRuleLock lock(m_968, 1);
    m_998 = bOpen;
}

// @0x14047e790
bool CGameRule::FUN_14047e790()
{
    if (FUN_140166410()->FUN_14036d8e0() != "CN")
        return true;
    Unk_GameRuleLock lock(m_968, 1);
    return m_998;
}

// @0x14047e830
void CGameRule::FUN_14047e830(bool bOpen)
{
    Unk_GameRuleLock lock(m_9a0, 1);
    m_9d0 = bOpen;
}

// @0x14047e880
bool CGameRule::FUN_14047e880()
{
    Unk_GameRuleLock lock(m_9a0, 1);
    return m_9d0;
}

// @0x14047e8e0
void CGameRule::FUN_14047e8e0(unsigned a, unsigned b, MS2Ptr<QuestAdditionalRewardContext> spContext)
{
    Unk_GameRuleLock lock(m_8, 1);
    std::pair<int, int> key(a, b);
    m_d00[key] = spContext;
}

// @0x14047e980
void CGameRule::FUN_14047e980(unsigned a, unsigned b)
{
    Unk_GameRuleLock lock(m_8, 1);
    std::pair<int, int> key(a, b);
    m_d00.erase(key);
}

// @0x14047ea00
unsigned CGameRule::FUN_14047ea00(unsigned a, unsigned b, int index)
{
    Unk_GameRuleLock lock(m_8, 1);
    std::pair<int, int> key(a, b);
    std::map<std::pair<int, int>, MS2Ptr<QuestAdditionalRewardContext> >::iterator it = m_d00.find(key);
    if (it != m_d00.end()) {
        MS2Ptr<QuestAdditionalRewardContext> spContext = it->second;
        if (index >= 0 && index < 8)
            return spContext->m_rates[index];
    }
    return 0;
}

// @0x14047eb30
unsigned CGameRule::FUN_14047eb30(unsigned a, unsigned b, unsigned itemId)
{
    Unk_GameRuleLock lock(m_8, 1);
    std::pair<int, int> key(a, b);
    std::map<std::pair<int, int>, MS2Ptr<QuestAdditionalRewardContext> >::iterator it = m_d00.find(key);
    if (it != m_d00.end()) {
        MS2Ptr<QuestAdditionalRewardContext> spContext = it->second;
        unsigned rate = 0;
        if (spContext->m_itemRates.Lookup(itemId, rate))
            return rate;
    }
    return 0;
}

// @0x14047ec80
void CGameRule::FUN_14047ec80(bool bOpen)
{
    m_d10 = bOpen;
}

// @0x14047eca0
bool CGameRule::FUN_14047eca0()
{
    return m_d10;
}

// @0x14047ecc0
void CGameRule::FUN_14047ecc0(CStringW tag, std::vector<ItemEntity>& out)
{
    Unk_CriticalSectionLock lock(m_d18, 1);
    for (std::multimap<int, MS2Ptr<Unk_ItemTagRewardContext> >::iterator it = m_d48.begin(); it != m_d48.end();
         it++) {
        MS2Ptr<Unk_ItemTagRewardContext> spReward = it->second;
        if (spReward->m_tags.find(tag) == spReward->m_tags.end())
            continue;
        FUN_140482160(spReward->m_items, out);
    }
}

// @0x14047ee40
// MS2-FUNCTIONAL: exe frame 0x10 larger around make_pair/insert; not found
void CGameRule::FUN_14047ee40(int key, MS2Ptr<Unk_ItemTagRewardContext> spContext)
{
    Unk_CriticalSectionLock lock(m_d18, 1);
    m_d48.insert(std::make_pair(key, spContext));
}

// @0x14047ef00
void CGameRule::FUN_14047ef00(int key)
{
    Unk_CriticalSectionLock lock(m_d18, 1);
    m_d48.erase(key);
}

// @0x14047ef70
void CGameRule::FUN_14047ef70(int eventId, int value)
{
    Unk_CriticalSectionLock lock(m_d58, 1);
    m_d88.Set(eventId, 0, value);
}

// @0x14047efe0
void CGameRule::FUN_14047efe0(int eventId)
{
    Unk_CriticalSectionLock lock(m_d58, 1);
    m_d88.Remove(eventId, 0);
}

// @0x14047f050
int CGameRule::FUN_14047f050(int value)
{
    Unk_CriticalSectionLock lock(m_d58, 1);
    unsigned rate = m_d88.Get(0, 0);
    double ratio = rate / 10000.0;
    return value + (int)FUN_1404820b0(value, (float)ratio);
}

// @0x14047f0f0
bool CGameRule::FUN_14047f0f0()
{
    Unk_CriticalSectionLock lock(m_d58, 1);
    if (m_d88.Get(0, 0) > 0)
        return true;
    return false;
}

// @0x14047f180
void CGameRule::FUN_14047f180(int eventId, int value)
{
    Unk_CriticalSectionLock lock(m_da8, 1);
    m_dd8.Set(eventId, 0, value);
}

// @0x14047f1f0
void CGameRule::FUN_14047f1f0(int eventId)
{
    Unk_CriticalSectionLock lock(m_da8, 1);
    m_dd8.Remove(eventId, 0);
}

// @0x14047f260
int CGameRule::FUN_14047f260(int value)
{
    Unk_CriticalSectionLock lock(m_da8, 1);
    unsigned rate = m_dd8.Get(0, 0);
    double ratio = rate / 10000.0;
    return value + (int)FUN_1404820b0(value, (float)ratio);
}

// @0x14047f300
bool CGameRule::FUN_14047f300()
{
    Unk_CriticalSectionLock lock(m_da8, 1);
    if (m_dd8.Get(0, 0) > 0)
        return true;
    return false;
}

// @0x14047f390
void CGameRule::FUN_14047f390(int eventId, int rate)
{
    Unk_CriticalSectionLock lock(m_df8, 1);
    m_e28.Set(eventId, 0, rate);
}

// @0x14047f400
void CGameRule::FUN_14047f400(int eventId)
{
    Unk_CriticalSectionLock lock(m_df8, 1);
    m_e28.Remove(eventId, 0);
}

// @0x14047f470
__int64 CGameRule::FUN_14047f470(__int64 value)
{
    Unk_CriticalSectionLock lock(m_df8, 1);
    unsigned rate = m_e28.Get(0, 0);
    double ratio = rate / 10000.0;
    return value + (unsigned)FUN_1404820b0((unsigned)value, (float)ratio);
}

// @0x14047f520
unsigned CGameRule::FUN_14047f520()
{
    Unk_CriticalSectionLock lock(m_e48, 1);
    return m_e78.Get(0, 0);
}

// @0x14047f590
void CGameRule::FUN_14047f590(int eventId, int rate)
{
    Unk_CriticalSectionLock lock(m_e48, 1);
    m_e78.Set(eventId, 0, rate);
}

// @0x14047f600
void CGameRule::FUN_14047f600(int eventId)
{
    Unk_CriticalSectionLock lock(m_e48, 1);
    m_e78.Remove(eventId, 0);
}

// @0x14047f670
__int64 CGameRule::FUN_14047f670(__int64 value)
{
    Unk_CriticalSectionLock lock(m_e48, 1);
    int rate = m_e78.Get(0, 0);
    if (rate == 0)
        return value;
    return (unsigned)FUN_140482050((unsigned)value, rate);
}

// @0x14047f720
unsigned CGameRule::FUN_14047f720(unsigned value)
{
    Unk_CriticalSectionLock lock(m_ea8, 1);
    unsigned rate = m_ed8.Get(0, 0);
    return FUN_140482050(value, rate);
}

// @0x14047f7a0
void CGameRule::FUN_14047f7a0(int nEventId, int nRate)
{
    Unk_CriticalSectionLock lock(m_ea8, 1);
    m_ed8.Set(nEventId, 0, nRate);
}

// @0x14047f810
void CGameRule::FUN_14047f810(int nEventId)
{
    Unk_CriticalSectionLock lock(m_ea8, 1);
    m_ed8.Remove(nEventId, 0);
}

// @0x14047f880
unsigned CGameRule::FUN_14047f880()
{
    Unk_CriticalSectionLock lock(m_f08, 1);
    return m_f38.Get(0, 0);
}

// @0x14047f8f0
void CGameRule::FUN_14047f8f0(int nEventId, int nRate)
{
    Unk_CriticalSectionLock lock(m_f08, 1);
    m_f38.Set(nEventId, 0, nRate);
}

// @0x14047f960
void CGameRule::FUN_14047f960(int nEventId)
{
    Unk_CriticalSectionLock lock(m_f08, 1);
    m_f38.Remove(nEventId, 0);
}

// @0x14047f9d0
void CGameRule::FUN_14047f9d0()
{
    m_b0.clear();
    m_c0.clear();
    m_d0 = 0;
    m_d4 = 0;
    for (POSITION pos = m_38.GetStartPosition(); pos != NULL; m_38.GetNext(pos)) {
        MS2Ptr<SAHotTimeEventContext> spContext = m_38.GetValueAt(pos);
        if (spContext == 0)
            continue;
        if (spContext->m_30 != 0) {
            m_d4 = 1;
            for (auto& rate : spContext->m_18)
                m_c0[rate.first] += rate.second;
        }
        else {
            m_d0 = 1;
            for (auto& rate : spContext->m_18)
                m_b0[rate.first] += rate.second;
        }
    }
}

// @0x14047fc60
void CGameRule::FUN_14047fc60()
{
    m_368 = 0;
    m_36c = 0;
    for (POSITION pos = m_2f0.GetStartPosition(); pos != NULL; m_2f0.GetNext(pos)) {
        MS2Ptr<MesoRevivalEventContext> spContext = m_2f0.GetValueAt(pos);
        if (spContext == 0)
            continue;
        if (spContext->m_18 != 0)
            m_36c = 1;
        else
            m_368 = 1;
    }
}
