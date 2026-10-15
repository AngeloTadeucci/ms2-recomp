// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Guild XML and wire data, part 2.
// MS2-UNIT: commonfiles\guilddef.cpp#2
// MS2-RANGE: 0x1404d4180-0x1404e5940 .text$mn
// MS2-RANGE: 0x1400b8e00-0x1400b8ec0 .text$di
// MS2-PIN: ??_7CGuildXmlData@@6B?$TSingleton@VCGuildXmlData@@@@@ 0x142d52ac8
// MS2-PIN: ??_7CGuildXmlData@@6B?$CValidData@VCGuildXmlData@@@@@ 0x142d52ad8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\guilddef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "guilddef_2.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/tixmldocument.h"
#include "hook/ms2hook.h"
// MS2-FUNCTIONAL: equivalent source; container spellings and /Od temporary placement remain under recovery.
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@1@0@Z 0x1404d96b0
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404d97a0
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404d97f0
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404d9840
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404d9930
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404d9980
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@std@@AEAV01@$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@std@@V12@@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@1@0@Z 0x1404d99d0
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404d9a20
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404d9a70
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x1404d9b10
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x1404d9b60
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x1404d9bb0
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x1404d9c50
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9ca0
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9cf0
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9d40
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9d90
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9de0
// MS2-PIN: ??$?0AEBU?$less@I@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@I@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9e30
// MS2-PIN: ??$?0AEBU?$less@U?$pair@HH@std@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@U?$pair@HH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@U?$pair@HH@std@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9e80
// MS2-PIN: ??$?0AEBU?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9ed0
// MS2-PIN: ??$?0AEBU?$less@W4Unk_GuildNpcKind@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@W4Unk_GuildNpcKind@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@W4Unk_GuildNpcKind@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@W4Unk_GuildNpcKind@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1404d9f20
// MS2-PIN: ??$?0AEBU?$pair@HH@std@@$$Z$$V@?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBU?$pair@HH@std@@@1@V?$tuple@$$V@1@@Z 0x1404d9fc0
// MS2-PIN: ??$?0AEBU?$pair@HH@std@@$0A@@?$tuple@AEBU?$pair@HH@std@@@std@@QEAA@AEBU?$pair@HH@1@@Z 0x1404da010
// MS2-PIN: ??$?0AEBU?$pair@W4Unk_GuildNpcKind@@H@std@@$$Z$$V@?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBU?$pair@W4Unk_GuildNpcKind@@H@std@@@1@V?$tuple@$$V@1@@Z 0x1404da090
// MS2-PIN: ??$?0AEBU?$pair@W4Unk_GuildNpcKind@@H@std@@$0A@@?$tuple@AEBU?$pair@W4Unk_GuildNpcKind@@H@std@@@std@@QEAA@AEBU?$pair@W4Unk_GuildNpcKind@@H@1@@Z 0x1404da0e0
// MS2-PIN: ??$?0U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@std@@@std@@QEAA@AEBV?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@1@@Z 0x1404da350
// MS2-PIN: ??$?0U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@std@@@std@@QEAA@AEBV?$allocator@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@1@@Z 0x1404da360
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404da3c0
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404da410
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404da460
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404da500
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404da550
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404da5a0
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404da5f0
// MS2-PIN: ??$?0V?$tuple@$$QEAH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@QEAA@AEAV?$tuple@$$QEAH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1404da640
// MS2-PIN: ??$?0V?$tuple@$$QEAH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@QEAA@AEAV?$tuple@$$QEAH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1404da690
// MS2-PIN: ??$?0V?$tuple@$$QEAH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@QEAA@AEAV?$tuple@$$QEAH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1404da6e0
// MS2-PIN: ??$?0V?$tuple@$$QEAH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@QEAA@AEAV?$tuple@$$QEAH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1404da730
// MS2-PIN: ??$?0V?$tuple@$$QEAI@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@QEAA@AEAV?$tuple@$$QEAI@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1404da780
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@1@@Z 0x1404dab00
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@1@@Z 0x1404dab20
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@1@@Z 0x1404dab40
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@1@@Z 0x1404dab60
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@1@@Z 0x1404dab80
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@1@@Z 0x1404daba0
// MS2-PIN: ??$_Buy_if_not_node@AEAU?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@1@PEAU21@AEAU?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@1@@Z 0x1404dabc0
// MS2-PIN: ??$_Buy_if_not_node@AEAW4Unk_GuildNpcKind@@@?$_Tree@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@1@PEAU21@AEAW4Unk_GuildNpcKind@@@Z 0x1404dabe0
// MS2-PIN: ??$_Buynode@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@1@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@1@@Z 0x1404dacc0
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1404db460
// MS2-PIN: ??$_Copy@U_Copy_tag@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAXAEBV01@U_Copy_tag@01@@Z 0x1404db580
// MS2-PIN: ??$_Copy_memmove@PEAHPEAH@std@@YAPEAHPEAH00@Z 0x1404db6a0
// MS2-PIN: ??$_Copy_nodes@U_Copy_tag@?$_Tree@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@@?$_Tree@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@1@PEAU21@0U_Copy_tag@01@@Z 0x1404db710
// MS2-PIN: ??$_Copy_nodes@U_Move_tag@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@1@PEAU21@0U_Move_tag@01@@Z 0x1404db820
// MS2-PIN: ??$_Copy_or_move@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@U?$integral_constant@_N$0A@@2@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@1@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@1@U_Copy_tag@01@U?$integral_constant@_N$0A@@1@@Z 0x1404db960
// MS2-PIN: ??$_Destroy_range1@V?$allocator@PEAX@std@@@std@@YAXPEAPEAX0AEAV?$allocator@PEAX@0@U?$integral_constant@_N$00@0@@Z 0x1404db9c0
// MS2-PIN: ??$_Destroy_range1@V?$allocator@U?$pair@HH@std@@@std@@@std@@YAXPEAU?$pair@HH@0@0AEAV?$allocator@U?$pair@HH@std@@@0@U?$integral_constant@_N$00@0@@Z 0x1404db9e0
// MS2-PIN: ??$_Destroy_range@V?$allocator@I@std@@@std@@YAXPEAI0AEAV?$allocator@I@0@@Z 0x1404dbb10
// MS2-PIN: ??$_Destroy_range@V?$allocator@PEAX@std@@@std@@YAXPEAPEAX0AEAV?$allocator@PEAX@0@@Z 0x1404dbb60
// MS2-PIN: ??$_Destroy_range@V?$allocator@U?$pair@HH@std@@@std@@@std@@YAXPEAU?$pair@HH@0@0AEAV?$allocator@U?$pair@HH@std@@@0@@Z 0x1404dbbb0
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x1404dbc00
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x1404dcac0
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x1404dcb50
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404dd060
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404dd0f0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404dd180
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404dd210
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404dd2a0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404dd330
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404dd3c0
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@std@@@std@@@?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@std@@@1@PEAU01@@Z 0x1404dd450
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@std@@@std@@@?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@std@@@1@PEAU01@@Z 0x1404dd4e0
// MS2-PIN: ??$_Get_unwrapped@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@YAPEAV?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@QEAV1@@Z 0x1404dd6e0
// MS2-PIN: ??$_Get_unwrapped@V?$Unk_PayloadPtr@VCNpcShopProductProxy@@@@@std@@YAPEAV?$Unk_PayloadPtr@VCNpcShopProductProxy@@@@QEAV1@@Z 0x1404dd6f0
// MS2-PIN: ??$_Idl_distance1@PEAU?$pair@HH@std@@PEAU12@@std@@YA_JAEBQEAU?$pair@HH@0@0Urandom_access_iterator_tag@0@@Z 0x1404dd760
// MS2-PIN: ??$_Insert_at@AEAW4Unk_GuildNpcKind@@PEAU?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@std@@@?$_Tree@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Unk_GuildNpcKind@@@std@@@std@@@1@_NPEAU?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@1@AEAW4Unk_GuildNpcKind@@1@Z 0x1404ded20
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@1@@Z 0x1404df740
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@1@@Z 0x1404e0380
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@1@@Z 0x1404e0fc0
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@1@@Z 0x1404e2840
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@1@@Z 0x1404e40c0
// MS2-PIN: ??$?0$$QEAH$$Z$$V@?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAH@1@V?$tuple@$$V@1@@Z 0x1404da160
// MS2-PIN: ??$?0AEBH$0A@@?$tuple@AEBH@std@@QEAA@AEBH@Z 0x1404da1b0
// MS2-PIN: ??$_Destroy_range@V?$allocator@UItemEntity@@@std@@@std@@YAXPEAUItemEntity@@0AEAV?$allocator@UItemEntity@@@0@@Z 0x1404dbac0
// MS2-PIN: ??$?0V?$tuple@AEBU?$pair@HH@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@QEAA@AEAV?$tuple@AEBU?$pair@HH@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1404da7d0
// MS2-PIN: ??$?0V?$tuple@AEBU?$pair@W4Unk_GuildNpcKind@@H@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@QEAA@AEAV?$tuple@AEBU?$pair@W4Unk_GuildNpcKind@@H@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1404da870
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1404d94f0
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@PEAX@std@@V?$_Vector_val@U?$_Simple_types@PEAX@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1404d9550
// MS2-PIN: ??$?0AEAHAEAH$0A@@?$pair@HH@std@@QEAA@AEAH0@Z 0x1404d9610
// MS2-PIN: ??$?0AEAW4Unk_GuildNpcKind@@AEAH$0A@@?$pair@W4Unk_GuildNpcKind@@H@std@@QEAA@AEAW4Unk_GuildNpcKind@@AEAH@Z 0x1404d9ac0
// MS2-PIN: ??$?0U_Exact_args_t@std@@AEBH$$V$0A@@?$tuple@AEBH@std@@QEAA@U_Exact_args_t@1@AEBH@Z 0x1404da2f0
// MS2-PIN: ??$_Buynode@AEAW4Unk_GuildNpcKind@@@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@1@AEAW4Unk_GuildNpcKind@@@Z 0x1404dac30
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x1404dad50
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x1404dae20
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x1404db160
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@$$QEAH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@$$QEAH@1@$$QEAV?$tuple@$$V@1@@Z 0x1404db300
// MS2-PIN: ??$_Buynode@AEBW4Unk_GuildNpcKind@@@?$_Tree_comp_alloc@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@1@AEBW4Unk_GuildNpcKind@@@Z 0x1404db3d0
// MS2-PIN: ??$_Destroy_range1@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@YAXPEAV?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@0AEAV?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@0@U?$integral_constant@_N$0A@@0@@Z 0x1404dba00
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@AEAAXAEBV?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@Z 0x1404dc020
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@QEAAPEAV?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@QEAV2@AEBV2@@Z 0x1404dc620
// MS2-PIN: ??$_Eqrange@I@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@VCGuildNpcShop@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@3@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@VCGuildNpcShop@@@@@std@@@std@@@std@@@std@@V12@@1@AEBI@Z 0x1404dcd90
// MS2-PIN: ??$_Get_unwrapped@U?$pair@HH@std@@@std@@YAPEAU?$pair@HH@0@QEAU10@@Z 0x1404dd700
// MS2-PIN: ??$_Get_unwrapped@UItemEntity@@@std@@YAPEAUItemEntity@@QEAU1@@Z 0x1404dd710
// MS2-PIN: ??$_Get_unwrapped_n@I_J$0A@@std@@YAPEAIQEAI_J@Z 0x1404dd730
// MS2-PIN: ??$_Idl_distance@PEAU?$pair@HH@std@@PEAU12@@std@@YA_JAEBQEAU?$pair@HH@0@0@Z 0x1404dd820
// MS2-PIN: ??$_Idl_distance@PEAV?$Unk_PayloadPtr@VCNpcShopProductProxy@@@@PEAV1@@std@@YA_JAEBQEAV?$Unk_PayloadPtr@VCNpcShopProductProxy@@@@0@Z 0x1404dd8b0
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@PEAX@1@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@1@1@Z 0x1404dd8e0
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@std@@PEAX@1@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildProperty@CGuildXmlData@@@@@1@1@Z 0x1404ddc40
// MS2-PIN: ??$_Insert_at@AEBW4Unk_GuildNpcKind@@U_Not_a_node_tag@std@@@?$_Tree@V?$_Tset_traits@W4Unk_GuildNpcKind@@U?$less@W4Unk_GuildNpcKind@@@std@@V?$allocator@W4Unk_GuildNpcKind@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Unk_GuildNpcKind@@@std@@@std@@@1@_NPEAU?$_Tree_node@W4Unk_GuildNpcKind@@PEAX@1@AEBW4Unk_GuildNpcKind@@U_Not_a_node_tag@1@@Z 0x1404df3e0
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBHV?$Unk_PayloadPtr@UGuildRaidReward@CGuildXmlData@@@@@std@@PEAX@1@@Z 0x1404e4d00
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@UItemEntity@@@std@@V?$_Vector_val@U?$_Simple_types@UItemEntity@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x1404d95b0
// MS2-PIN: ??$?0AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Unk_GuildNpcKind@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Unk_GuildNpcKind@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@W4Unk_GuildNpcKind@@@std@@@std@@@1@$$QEA_N@Z 0x1404d9750
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404d9890
// MS2-PIN: ??$?0$$QEAH$$Z$$V@?$pair@$$CBHV?$Unk_PayloadPtr@UGuildEvent@CGuildXmlData@@@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@$$QEAH@1@V?$tuple@$$V@1@@Z 0x1404d9c00
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x1404da4b0
// MS2-PIN: ??$?0V?$tuple@$$QEAU?$pair@W4Unk_GuildNpcKind@@H@std@@@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@QEAA@AEAV?$tuple@$$QEAU?$pair@W4Unk_GuildNpcKind@@H@std@@@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x1404da820
// MS2-PIN: ??$_Idl_distance@PEAIPEAI@std@@YA_JAEBQEAI0@Z 0x1404dd850
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@std@@PEAX@1@AEAU?$pair@$$CBHV?$vector@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@V?$allocator@V?$Unk_PayloadPtr@UGuildSkill@CGuildXmlData@@@@@std@@@std@@@1@1@Z 0x1404ddfa0
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@1@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@1@1@Z 0x1404de300
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@1@AEAU?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@1@1@Z 0x1404de9c0
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@U?$less@U?$pair@W4Unk_GuildNpcKind@@H@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@std@@PEAX@1@AEAU?$pair@$$CBU?$pair@W4Unk_GuildNpcKind@@H@std@@V?$Unk_PayloadPtr@UGuildNpc@CGuildXmlData@@@@@1@1@Z 0x1404df080
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@IV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@3@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBIV?$Unk_PayloadPtr@UGuildRaid@CGuildXmlData@@@@@std@@PEAX@1@@Z 0x1404e1c00
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@@std@@@std@@@1@AEAU?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@1@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$Unk_PayloadPtr@UGuildHouse@CGuildXmlData@@@@@std@@PEAX@1@@Z 0x1404e3480
extern bool FUN_14028f710(void*);
extern int FUN_1408731e0(void*,const char*,int*);
extern int FUN_140873220(void*,const char*,unsigned*);
extern int FUN_1408732e0(void*,const char*,__int64*);
extern int FUN_140873360(void*,const char*,float*);
extern int FUN_140873420(void*,const char*,CStringW*);
extern int FUN_1401785f0(void*,const char*,std::vector<int>*);
extern int FUN_1408731a0(void*,const char*,unsigned short*);
extern int FUN_1408733e0(void*,const char*,CString*);
extern Unk_GuildNpcKind FUN_140219f50(const CString&);
extern Unk_GuildContribution FUN_14021a0a0(const CString&);
template<class T>T Unk_GuildParseEnum(const CString&);
template<>inline Unk_GuildNpcKind Unk_GuildParseEnum<Unk_GuildNpcKind>(const CString& text){return FUN_140219f50(text);}
template<>inline Unk_GuildContribution Unk_GuildParseEnum<Unk_GuildContribution>(const CString& text){return FUN_14021a0a0(text);}
template<class T>int Unk_GuildReadEnum(void* node,const char* key,T* result) {
    CString text; int error=FUN_1408733e0(node,key,&text);
    if(error==0) *result=Unk_GuildParseEnum<T>(text);
    return error;
}
extern CString FUN_14071a5b0(const CString&,const CString&);
extern void* FUN_140166420();
extern void* FUN_140166440();
extern int FUN_1403974b0(void*,TiXmlDocument*,const char*,int,bool,int);
extern int FUN_140397ab0(void*,TiXmlDocument*,const CStringW&);
extern void* FUN_140165cf0(const void*,const char*);
extern void* FUN_140168650(const void*,const char*);
extern void* FUN_140345b40(const void*);
extern void* FUN_1403f0510(const void*);
extern void FUN_14028faa0(void*,const char*,const char*,std::vector<void*>&);
extern void FUN_14028fd90(void*,const char*,const char*,const char*,std::vector<void*>&);
extern void FUN_14015eb90(void*,int,int,const wchar_t*,const CString&);
extern void FUN_140353fc0(void*,int,int,const wchar_t*,const int&);
extern int FUN_14015f500(void*,const char*,int*);
extern void FUN_14026b1c0(ItemEntity*,int);
extern void FUN_1404fa010(bool);
extern void FUN_1404f3460();
extern __time64_t FUN_140869440();
// @0x1404d4180
CGuildPVPSeasonHistoryData::CGuildPVPSeasonHistoryData(){FUN_1404d4250();}
// @0x1404d41f0
CGuildPVPSeasonHistoryData::~CGuildPVPSeasonHistoryData(){}
// @0x1404d4250
void CGuildPVPSeasonHistoryData::FUN_1404d4250(){
    f18=0;f20=0;f28=0;f30.Empty();f38=0;f3c=0;f40=1;f48.Empty();
    f50=0;f54=0;f58=0;f5c=0;f60=0;f64=0;f68=0;
}
// @0x1404d4330
void CGuildPVPSeasonHistoryData::FUN_1404d4330(const CGuildPVPSeasonHistoryData* o){
    if(o){
        f18=o->f18;
        f20=o->f20;
        f28=o->f28;
        f30=o->f30;
        f38=o->f38;
        f3c=o->f3c;
        f40=o->f40;
        f48=o->f48;
        f50=o->f50;
        f54=o->f54;
        f58=o->f58;
        f5c=o->f5c;
        f60=o->f60;
        f64=o->f64;
        f68=o->f68;
    }
}
// @0x1404d4460
void CGuildPVPSeasonHistoryData::FUN_1404d4460(COutPacket* out){FUN_1404d44e0(*out);}
// @0x1404d4490
void CGuildPVPSeasonHistoryData::FUN_1404d4490(CInPacket* in){FUN_1404d4680(*static_cast<CInputStream*>(in));}
// @0x1404d44e0
void CGuildPVPSeasonHistoryData::FUN_1404d44e0(COutputStream& out){
    out.vfunc_o10_3(f18);
    out.vfunc_o10_4(f20);
    out.vfunc_o10_4(f28);
    out.vfunc_o10_8(f30);
    out.vfunc_o10_3(f38);
    out.vfunc_o10_3(f3c);
    out.vfunc_o10_3(f40);
    out.vfunc_o10_6(f48);
    out.vfunc_o10_3(f50);
    out.vfunc_o10_3(f54);
    out.vfunc_o10_3(f58);
    out.vfunc_o10_3(f5c);
    out.vfunc_o10_3(f60);
    out.vfunc_o10_3(f64);
    out.vfunc_o10_3(f68);
}
// @0x1404d4680
void CGuildPVPSeasonHistoryData::FUN_1404d4680(CInputStream& in){
    f18=in.vfunc_o8_3();
    f20=in.vfunc_o8_4();
    f28=in.vfunc_o8_4();
    f30=in.vfunc_o8_8();
    f38=in.vfunc_o8_3();
    f3c=in.vfunc_o8_3();
    f40=in.vfunc_o8_3();
    f48=in.vfunc_o8_6();
    f50=in.vfunc_o8_3();
    f54=in.vfunc_o8_3();
    f58=in.vfunc_o8_3();
    f5c=in.vfunc_o8_3();
    f60=in.vfunc_o8_3();
    f64=in.vfunc_o8_3();
    f68=in.vfunc_o8_3();
}
// @0x1404d4870
CGuildXmlData::GuildProperty::GuildProperty():f18(0),f1c(0),f20(0),f28(0),f30(0),f34(0),f38(0),f3c(0),f40(0),f44(0),f48(0),f4c(0),f50(0),f54(0),f58(0),f5c(0),f60(0),f64(0),f68(0){}
// @0x1404d4990
bool CGuildXmlData::GuildProperty::FUN_1404d4990(void* node){
    bool valid=FUN_14028f710(node);
    if(valid){
        FUN_1408731e0(node,"level",&f18);
        FUN_1408731e0(node,"accumExp",&f1c);
        FUN_1408731e0(node,"capacity",&f20);
        FUN_1408732e0(node,"fundMax",&f28);
        FUN_1408731e0(node,"donationMax",&f30);
        FUN_1408731e0(node,"attendGuildExp",&f34);
        FUN_1408731e0(node,"winMiniGameGuildExp",&f38);
        FUN_1408731e0(node,"loseMiniGameGuildExp",&f3c);
        FUN_1408731e0(node,"raidGuildExp",&f40);
        FUN_1408731e0(node,"attendGuildFund",&f44);
        FUN_1408731e0(node,"winMiniGameGuildFund",&f48);
        FUN_1408731e0(node,"loseMiniGameGuildFund",&f4c);
        FUN_1408731e0(node,"raidGuildFund",&f50);
        FUN_140873360(node,"attendUserExpFactor",&f54);
        FUN_140873360(node,"donationUserExpFactor",&f58);
        FUN_1408731e0(node,"attendGuildCoin",&f5c);
        FUN_1408731e0(node,"winMiniGameGuildCoin",&f64);
        FUN_1408731e0(node,"donateGuildCoin",&f60);
        FUN_1408731e0(node,"loseMiniGameGuildCoin",&f68);
    }
    return valid;
}
// @0x1404d4bf0
CGuildXmlData::GuildSkill::GuildSkill():f18(0),f1c(0),f20(0),f24(0),f28(0),f2c(0),f30(0),f34(0),f38(0),f3c(0){}
// @0x1404d4cb0
bool CGuildXmlData::GuildSkill::FUN_1404d4cb0(void* node){
    bool valid=FUN_14028f710(node);
    if(!valid)return false;
    int duration=0,cooltime=0;
        FUN_1408731e0(node,"id",&f18);
        FUN_1408731e0(node,"level",&f1c);
        FUN_1408731e0(node,"requireLevel",&f20);
        FUN_1408731e0(node,"upgradeCost",&f24);
        FUN_1408731e0(node,"cost",&f28);
        FUN_1408731e0(node,"duration",&duration);
        FUN_1408731e0(node,"cooltime",&cooltime);
        FUN_1408731e0(node,"additionalEffectId",&f34);
        FUN_1408731e0(node,"additionalEffectLevel",&f38);
        FUN_1408731e0(node,"type",&f3c);
        FUN_140873420(node,"functionName",&f40);
    f2c=duration*60;f30=cooltime*60;return true;
}
// @0x1404d4e40
bool CGuildXmlData::GuildSkill::FUN_1404d4e40(){return 10000<f18;}
// @0x1404d4e60
bool CGuildXmlData::GuildSkill::FUN_1404d4e60(){return f18<10001;}
// @0x1404d4e80
int CGuildXmlData::GuildSkill::FUN_1404d4e80(){if(f18<1001 || 10000<f18)return 0;else return 1;}
// @0x1404d4eb0
CGuildXmlData::GuildEvent::GuildEvent():f18(0),f1c(0){}
// @0x1404d4f10
bool CGuildXmlData::GuildEvent::FUN_1404d4f10(void* node){
    bool valid=FUN_14028f710(node);
    if(valid){
        FUN_1408731e0(node,"id",&f18);
        FUN_1408731e0(node,"mapCode",&f1c);
        FUN_140873420(node,"imagePath",&f20);
    }
    return valid;
}
// @0x1404d4fa0
CGuildXmlData::GuildHouse::GuildHouse():f18(0),f1c(0),f20(0),f24(0),f28(0),f2c(0),f30(0),f50(0){}
// @0x1404d5070
bool CGuildXmlData::GuildHouse::FUN_1404d5070(void* node){
    bool valid=FUN_14028f710(node);
    if(valid){
        FUN_1408731e0(node,"level",&f18);
        FUN_1408731e0(node,"theme",&f1c);
        FUN_140873220(node,"fieldID",&f50);
        FUN_1408731e0(node,"areaSize",&f24);
        FUN_1401785f0(node,"facility",&f38);
        FUN_1408731e0(node,"stringKey",&f20);
        FUN_1408731e0(node,"upgradeCost",&f28);
        FUN_1408731e0(node,"upgradeReqGuildLevel",&f2c);
        FUN_1408731e0(node,"rethemeCost",&f30);
        FUN_140873420(node,"imagePath",&f60);
        FUN_140873420(node,"thumbnailPath",&f58);
    }
    return valid;
}
// @0x1404d51f0
CGuildXmlData::GuildNpc::GuildNpc():f18(Unk_GuildNpcKind_None),f1c(0),f20(0),f28(0),f2c(0),f30(0){}
// @0x1404d5270
bool CGuildXmlData::GuildNpc::FUN_1404d5270(void* node){
    bool valid=FUN_14028f710(node);
    if(valid){
        Unk_GuildReadEnum(node,"type",&f18);
        FUN_1408731e0(node,"level",&f1c);
        FUN_1408732e0(node,"upgradeCost",&f20);
        FUN_1408731e0(node,"requireGuildLevel",&f28);
        FUN_1408731e0(node,"requireHouseLevel",&f2c);
        FUN_1408731e0(node,"stringKey",&f30);
    }
    return valid;
}
// @0x1404d5360
CGuildXmlData::GuildRaid::GuildRaid():f18(0),f1c(0),f20(1.0f),f24(1.0f){}
// @0x1404d53d0
bool CGuildXmlData::GuildRaid::FUN_1404d53d0(void* node){
    bool valid=FUN_14028f710(node);
    if(valid){
        FUN_140873220(node,"dungeonRoomID",&f18);
        FUN_1408731e0(node,"clearRaidPoint",&f1c);
        FUN_140873360(node,"clearGuildFund",&f20);
        FUN_140873360(node,"clearGuildExp",&f24);
    }
    return valid;
}
// @0x1404d5480
CGuildXmlData::GuildRaidReward::GuildRaidReward():f18(0),f20(0){}
// @0x1404d54e0
bool CGuildXmlData::GuildRaidReward::FUN_1404d54e0(void* node){
    if(!FUN_14028f710(node))return false;
    FUN_1408731e0(node,"raidPoint",&f18);
    FUN_1408732e0(node,"guildFund",&f20);
    CStringW path;
    FUN_140873420(node,"rewardItems",&path);
    if(0<path.GetLength()){
        TiXmlDocument doc;
        if(!FUN_140397ab0(FUN_140166420(),&doc,path)){
            FUN_140353fc0(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[GuildRaidReward raidPoint : {0}",f18);return false;
        }
        void* root=FUN_140345b40(&doc);
        if(!root){FUN_140353fc0(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[GuildRaidReward raidPoint : {0}",f18);return false;}
        for(void* child=FUN_140345b40(root);child;child=FUN_1403f0510(child)){
            ItemEntity item;int rank=1;
            FUN_140873220(child,"id",&item.m_itemId);
            FUN_14015f500(child,"rank",&rank);
            FUN_140873220(child,"count",&item.m_count);
            FUN_14026b1c0(&item,rank);
            items.push_back(item);
        }
    }
    return true;
}
// @0x1404d5790
CGuildXmlData::CGuildXmlData(){memset(questFactors,0,sizeof(questFactors));}
// @0x1404d5890
CGuildXmlData::~CGuildXmlData(){}
// @0x1404d5960
bool CGuildXmlData::FUN_1404d5960(){
    if(!FUN_1404d5a50())return false;
    if(!FUN_1404d5d20())return false;
    if(!FUN_1404d5fa0())return false;
    if(!FUN_1404d6210())return false;
    if(!FUN_1404d64c0())return false;
    if(!FUN_1404d67e0())return false;
    if(!FUN_1404d6ab0())return false;
    if(!FUN_1404d6ac0())return false;
    if(!FUN_1404d6ec0())return false;
    FUN_1404fa010(true);return true;
}
// @0x1404d5a50
bool CGuildXmlData::FUN_1404d5a50(){
    CString path=FUN_14071a5b0(CString("Table"),CString("GuildProperty.xml"));
    TiXmlDocument doc;
    if(!FUN_1403974b0(FUN_140166420(),&doc,path,0,true,0))return false;
    void* root=FUN_140165cf0(&doc,"ms2");
    if(!root){FUN_14015eb90(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[<ms2> {0}]",path);return false;}
    std::vector<void*> nodes;
    FUN_14028faa0(root,"property","level",nodes);
    for(size_t index=0;index<nodes.size();++index){
        Unk_PayloadPtr<GuildProperty> value=new GuildProperty;
        if(!value->FUN_1404d4990(nodes[index]))continue;
        property[value->f18]=value;
    }
    return true;
}
// @0x1404d5d20
bool CGuildXmlData::FUN_1404d5d20(){
    CString path=FUN_14071a5b0(CString("Table"),CString("GuildBuff.xml"));
    TiXmlDocument doc;
    if(!FUN_1403974b0(FUN_140166420(),&doc,path,0,true,0))return false;
    void* root=FUN_140165cf0(&doc,"ms2");
    if(!root){FUN_14015eb90(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[<ms2> {0}]",path);return false;}
    for(void* node=FUN_140165cf0(root,"guildBuff");node;node=FUN_140168650(node,"guildBuff")){
        Unk_PayloadPtr<GuildSkill> value=new GuildSkill;
        if(!value->FUN_1404d4cb0(node))continue;
        skill[value->f18].push_back(value);
    }
    return true;
}
// @0x1404d5fa0
bool CGuildXmlData::FUN_1404d5fa0(){
    CString path=FUN_14071a5b0(CString("Table"),CString("GuildEvent.xml"));
    TiXmlDocument doc;
    if(!FUN_1403974b0(FUN_140166420(),&doc,path,0,true,0))return false;
    void* root=FUN_140165cf0(&doc,"ms2");
    if(!root){FUN_14015eb90(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[<ms2> {0}]",path);return false;}
    for(void* node=FUN_140165cf0(root,"guildEvent");node;node=FUN_140168650(node,"guildEvent")){
        Unk_PayloadPtr<GuildEvent> value=new GuildEvent;
        if(!value->FUN_1404d4f10(node))continue;
        event[value->f18]=value;
    }
    return true;
}
// @0x1404d6210
bool CGuildXmlData::FUN_1404d6210(){
    CString path=FUN_14071a5b0(CString("Table"),CString("GuildHouse.xml"));
    TiXmlDocument doc;
    if(!FUN_1403974b0(FUN_140166420(),&doc,path,0,true,0))return false;
    void* root=FUN_140165cf0(&doc,"ms2");
    if(!root){FUN_14015eb90(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[<ms2> {0}]",path);return false;}
    for(void* node=FUN_140165cf0(root,"guildHouse");node;node=FUN_140168650(node,"guildHouse")){
        Unk_PayloadPtr<GuildHouse> value=new GuildHouse;
        if(!value->FUN_1404d5070(node))continue;
        house[std::pair<int,int>(value->f18,value->f1c)]=value;
    }
    return true;
}
// @0x1404d64c0
bool CGuildXmlData::FUN_1404d64c0(){
    CString path=FUN_14071a5b0(CString("Table"),CString("GuildNpc.xml"));
    TiXmlDocument doc;
    if(!FUN_1403974b0(FUN_140166420(),&doc,path,0,true,0))return false;
    void* root=FUN_140165cf0(&doc,"ms2");
    if(!root){FUN_14015eb90(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[<ms2> {0}]",path);return false;}
    std::vector<void*> nodes;
    FUN_14028fd90(root,"npc","type","level",nodes);
    for(size_t index=0;index<nodes.size();++index){
        Unk_PayloadPtr<GuildNpc> value=new GuildNpc;
        if(!value->FUN_1404d5270(nodes[index]))continue;
        npc[std::pair<Unk_GuildNpcKind,int>(value->f18,value->f1c)]=value;
    }
    return true;
}
// @0x1404d67e0
bool CGuildXmlData::FUN_1404d67e0(){
    CString path=FUN_14071a5b0(CString("Table"),CString("GuildRaid.xml"));
    TiXmlDocument doc;
    if(!FUN_1403974b0(FUN_140166420(),&doc,path,0,true,0))return false;
    void* root=FUN_140165cf0(&doc,"ms2");
    if(!root){FUN_14015eb90(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[<ms2> {0}]",path);return false;}
    std::vector<void*> nodes;
    FUN_14028faa0(root,"guildRaid","dungeonRoomID",nodes);
    for(size_t index=0;index<nodes.size();++index){
        Unk_PayloadPtr<GuildRaid> value=new GuildRaid;
        if(!value->FUN_1404d53d0(nodes[index]))continue;
        raid[value->f18]=value;
    }
    return true;
}
// @0x1404d6ab0
bool CGuildXmlData::FUN_1404d6ab0(){return true;}
// @0x1404d6ac0
bool CGuildXmlData::FUN_1404d6ac0(){
    CString path=FUN_14071a5b0(CString("Table"),CString("GuildQuestRewardFactor.xml"));
    TiXmlDocument doc;
    if(!FUN_1403974b0(FUN_140166420(),&doc,path,0,true,0))return false;
    void* root=FUN_140165cf0(&doc,"ms2");
    if(!root){FUN_14015eb90(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[<ms2> {0}]",path);return false;}
    std::vector<void*> nodes;
    FUN_14028faa0(root,"guildNpc","level",nodes);
    for(size_t index=0;index<nodes.size();++index){
        unsigned short level=0;float guildExp=0,userExp=0,guildFund=0,userMeso=0,guildCoin=0;
        FUN_1408731a0(nodes[index],"level",&level);
        FUN_140873360(nodes[index],"guildExpFactor",&guildExp);
        FUN_140873360(nodes[index],"userExpFactor",&userExp);
        FUN_140873360(nodes[index],"guildFundFactor",&guildFund);
        FUN_140873360(nodes[index],"userMesoFactor",&userMeso);
        FUN_140873360(nodes[index],"GuildCoinFactor",&guildCoin);
        if(level<300){questFactors[level][0]=guildExp;questFactors[level][1]=userExp;questFactors[level][2]=guildFund;questFactors[level][3]=userMeso;questFactors[level][4]=guildCoin;}
    }
    return true;
}
// @0x1404d6ec0
bool CGuildXmlData::FUN_1404d6ec0(){
    CString path=FUN_14071a5b0(CString("Table"),CString("GuildContribution.xml"));
    TiXmlDocument doc;
    if(!FUN_1403974b0(FUN_140166420(),&doc,path,0,true,0))return false;
    void* root=FUN_140165cf0(&doc,"ms2");
    if(!root){FUN_14015eb90(FUN_140166440(),1,19,L"xml 형식이 잘못 되었습니다[<ms2> {0}]",path);return false;}
    std::vector<void*> nodes;
    FUN_14028faa0(root,"contribution","type",nodes);
    for(size_t index=0;index<nodes.size();++index){
        Unk_GuildContribution kind=Unk_GuildContribution_None;int value=0;
        Unk_GuildReadEnum(nodes[index],"type",&kind);
        FUN_1408731e0(nodes[index],"value",&value);
        if(0<kind && kind<10)contribution[kind]=value;
    }
    return true;
}
// @0x1404d7130
unsigned CGuildXmlData::FUN_1404d7130(int exp){
    FUN_1404f3460();
    if(!property.empty()){
        for(auto i=property.begin();i!=property.end();++i){
            if(exp<i->second->f1c) return i->second->f18;
        }
        return FUN_1404d72f0();
    }
    return 0;
}
// @0x1404d7200
int CGuildXmlData::FUN_1404d7200(int level){
    FUN_1404f3460();
    if(level<1) return 0;
    if(!(property[level]==0)) return property[level]->f1c;
    return 0;
}
// @0x1404d7280
int CGuildXmlData::FUN_1404d7280(){
    if(property.size()<2) return 0;
    auto i=property.rbegin();
    i++;
    return i->second->f1c;
}
// @0x1404d72f0
int CGuildXmlData::FUN_1404d72f0(){
    FUN_1404f3460();
    if(!property.empty()) return property.rbegin()->second->f18;
    return 0;
}
// @0x1404d7360
float CGuildXmlData::FUN_1404d7360(unsigned short level,int index){
    FUN_1404f3460();
    if(level<300) return questFactors[level][index];
    return 1.0f;
}
// @0x1404d73d0
int CGuildXmlData::FUN_1404d73d0(int kind){
    FUN_1404f3460();
    if(kind<1 || 9<kind) return 0;
    return contribution[kind];
}
// @0x1404d7410
Unk_PayloadPtr<CGuildXmlData::GuildProperty> CGuildXmlData::FUN_1404d7410(int level){
    FUN_1404f3460();
    if(property.find(level)==property.end()) return Unk_PayloadPtr<GuildProperty>(0);
    return property[level];
}
// @0x1404d74e0
Unk_PayloadPtr<CGuildXmlData::GuildSkill> CGuildXmlData::FUN_1404d74e0(int id,int level){
    FUN_1404f3460();
    if(skill.find(id)==skill.end()) return Unk_PayloadPtr<GuildSkill>(0);
    std::vector<Unk_PayloadPtr<GuildSkill>>& list=skill[id];
    for(size_t i=0;i<list.size();++i){
        if(list[i]->f1c==level) return list[i];
    }
    return Unk_PayloadPtr<GuildSkill>(0);
}
// @0x1404d7630
void CGuildXmlData::FUN_1404d7630(std::vector<int>& out){
    FUN_1404f3460();
    out.reserve(skill.size());
    for(auto i=skill.begin();i!=skill.end();++i){
        if(!i->second.empty() && i->second[0]->FUN_1404d4e60()) out.push_back(i->first);
    }
}
// @0x1404d7730
void CGuildXmlData::FUN_1404d7730(std::vector<int>& out){
    FUN_1404f3460();
    out.reserve(skill.size());
    for(auto i=skill.begin();i!=skill.end();++i){
        if(!i->second.empty() && i->second[0]->FUN_1404d4e40()) out.push_back(i->first);
    }
}
// @0x1404d7830
Unk_PayloadPtr<CGuildXmlData::GuildEvent> CGuildXmlData::FUN_1404d7830(int id){
    FUN_1404f3460();
    if(event.find(id)==event.end()) return Unk_PayloadPtr<GuildEvent>(0);
    return event[id];
}
// @0x1404d7900
void CGuildXmlData::FUN_1404d7900(std::vector<int>& out){
    FUN_1404f3460();
    out.reserve(event.size());
    for(auto i=event.begin();i!=event.end();++i) out.push_back(i->first);
}
// @0x1404d79b0
Unk_PayloadPtr<CGuildXmlData::GuildHouse> CGuildXmlData::FUN_1404d79b0(int level,int theme){
    FUN_1404f3460();
    std::pair<int,int> key(level,theme);
    if(house.find(key)==house.end()) return Unk_PayloadPtr<GuildHouse>(0);
    return house[key];
}
// @0x1404d7a90
void CGuildXmlData::FUN_1404d7a90(std::vector<std::pair<int,int>>& out){
    FUN_1404f3460();
    out.reserve(house.size());
    for(auto i=house.begin();i!=house.end();++i) out.push_back(i->first);
}
// @0x1404d7b40
Unk_PayloadPtr<CGuildXmlData::GuildNpc> CGuildXmlData::FUN_1404d7b40(Unk_GuildNpcKind kind,int level){
    FUN_1404f3460();
    std::pair<Unk_GuildNpcKind,int> key(kind,level);
    if(npc.find(key)==npc.end()) return Unk_PayloadPtr<GuildNpc>(0);
    return npc[key];
}
// @0x1404d7c20
void CGuildXmlData::FUN_1404d7c20(std::set<Unk_GuildNpcKind>& out){
    FUN_1404f3460();
    for(auto i=npc.begin();i!=npc.end();++i) out.insert(i->first.first);
}
// @0x1404d7cb0
Unk_PayloadPtr<CGuildXmlData::GuildRaid> CGuildXmlData::FUN_1404d7cb0(unsigned id){
    FUN_1404f3460();
    if(raid.find(id)==raid.end()) return Unk_PayloadPtr<GuildRaid>(0);
    return raid[id];
}
// @0x1404d7d80
void CGuildXmlData::FUN_1404d7d80(std::vector<unsigned>& out){
    FUN_1404f3460();
    out.reserve(raid.size());
    for(auto i=raid.begin();i!=raid.end();++i) out.push_back(i->first);
}
// @0x1404d7e30
Unk_PayloadPtr<CGuildXmlData::GuildRaidReward> CGuildXmlData::FUN_1404d7e30(int id){
    FUN_1404f3460();
    if(id<0) return Unk_PayloadPtr<GuildRaidReward>(0);
    auto i=reward.find(id);
    if(i==reward.end()) return Unk_PayloadPtr<GuildRaidReward>(0);
    return i->second;
}
// @0x1404d7f20
void CNpcShopProductProxy::FUN_1404d7f20(COutputStream& out){
    out.vfunc_o10_3(f18);
    out.vfunc_o10_1((unsigned char)f1c);
    out.vfunc_o10_3(f20);
    out.vfunc_o10_3(f24);
}
// @0x1404d7fa0
void CNpcShopProductProxy::FUN_1404d7fa0(CInPacket* packet){
    CInputStream& in=*packet;
    f18=in.vfunc_o8_3();
    f1c=(unsigned char)in.vfunc_o8_1();
    f20=in.vfunc_o8_3();
    f24=in.vfunc_o8_3();
}
// @0x1404d8070
bool CGuildNpcShop::FUN_1404d8070(__int64 now){return f20<now;}
// @0x1404d80a0
void CGuildNpcShop::FUN_1404d80a0(){products.clear();}
// @0x1404d80d0
Unk_PayloadPtr<CNpcShopProductProxy> CGuildNpcShop::FUN_1404d80d0(int itemId,int rank,int price){
    Unk_PayloadPtr<CNpcShopProductProxy> ref(new CNpcShopProductProxy);
    if(ref!=0){
        ref->f18=itemId;
        ref->f1c=rank;
        ref->f20=price;
        products.push_back(ref);
    }
    return ref;
}
// @0x1404d81e0
Unk_PayloadPtr<CNpcShopProductProxy> CGuildNpcShop::FUN_1404d81e0(int itemId,int rank,int price){
    int index=FUN_1404d82a0(itemId,rank,price);
    if(-1<index && index<(int)products.size()) return products[index];
    return Unk_PayloadPtr<CNpcShopProductProxy>(0);
}
// @0x1404d82a0
int CGuildNpcShop::FUN_1404d82a0(int itemId,int rank,int price){
    if(!products.empty()){
        int count=(int)products.size();
        for(int i=0;i<count;++i){
            Unk_PayloadPtr<CNpcShopProductProxy> ref=products[i];
            if(ref==0){
                continue;
            }
            if(ref->f18==itemId && ref->f1c==rank && (price==0 || ref->f20==price)) return i;
        }
    }
    return -1;
}
// @0x1404d83e0
void CGuildNpcShop::FUN_1404d83e0(COutputStream& out){
    out.vfunc_o10_2((unsigned short)f18);
    out.vfunc_o10_4(f20);
    int n=(int)products.size();
    out.vfunc_o10_2((unsigned short)n);
    for(int i=0;i<n;++i){
        Unk_PayloadPtr<CNpcShopProductProxy> ref=products[i];
        out.vfunc_o10_0(ref!=0);
        if(ref!=0) ref->FUN_1404d7f20(out);
    }
}
// @0x1404d8520
void CGuildNpcShop::FUN_1404d8520(CInPacket* packet){
    CInputStream& in=*packet;
    f18=in.vfunc_o8_2();
    f20=in.vfunc_o8_4();
    products.clear();
    unsigned short n=in.vfunc_o8_2();
    for(int i=0;i<(int)n;++i){
        if(in.vfunc_o8_0()){
            Unk_PayloadPtr<CNpcShopProductProxy> ref(new CNpcShopProductProxy);
            ref->FUN_1404d7fa0(packet);
            products.push_back(ref);
        }
    }
}
// @0x1404d86e0
Unk_PayloadPtr<CGuildNpcShop> CGuildNpcShopMgr::FUN_1404d86e0(unsigned id,__int64 time){
    Unk_PayloadPtr<CGuildNpcShop> ref(new CGuildNpcShop);
    if(ref!=0){
        ref->f18=id;
        ref->f20=time;
        shops[ref->f18]=ref;
    }
    return ref;
}
// @0x1404d87f0
Unk_PayloadPtr<CGuildNpcShop> CGuildNpcShopMgr::FUN_1404d87f0(unsigned id){
    if(!shops.empty()){
        auto i=shops.find(id);
        if(i==shops.end()) return Unk_PayloadPtr<CGuildNpcShop>(0);
        return i->second;
    }
    return Unk_PayloadPtr<CGuildNpcShop>(0);
}
// @0x1404d88e0
Unk_PayloadPtr<CGuildNpcShop> CGuildNpcShopMgr::FUN_1404d88e0(unsigned id){
    Unk_PayloadPtr<CGuildNpcShop> ref=FUN_1404d87f0(id);
    if(ref==0){
        ref=new CGuildNpcShop;
        shops[id]=ref;
    }
    return ref;
}
// @0x1404d89e0
int CGuildNpcShopMgr::FUN_1404d89e0(ItemEntity* item,Unk_GuildShopOffer* offer,bool* created){
    __int64 now=FUN_140869440();
    Unk_PayloadPtr<CGuildNpcShop> shop=FUN_1404d87f0(offer->f20);
    if(shop!=0){
        bool keep=false;
        if(shop->f20==offer->f28){
            if(now<=shop->f20) keep=true;
        }
        if(!keep){
            shops.erase(offer->f20);
            shop=0;
        }
    }
    if(shop==0){
        shop=FUN_1404d86e0(offer->f20,offer->f28);
        *created=true;
    }
    if(shop==0){
        shop->f28=now;
        int rank=static_cast<ItemAble*>(item)->vfunc_o18_1();
        Unk_PayloadPtr<CNpcShopProductProxy> product=shop->FUN_1404d81e0(item->m_itemId,rank,0);
        unsigned total=item->m_count;
        if(product!=0) total=total+product->f24;
        if(offer->f1c<total) return 0x33;
        if(product==0){
            rank=static_cast<ItemAble*>(item)->vfunc_o18_1();
            product=shop->FUN_1404d80d0(item->m_itemId,rank,offer->f18);
        }
        product->f24=product->f24+item->m_count;
        return 0;
    }
    return 0x31;
}
// @0x1404d8d50
void CGuildNpcShopMgr::FUN_1404d8d50(COutputStream& out){
    out.vfunc_o10_2((unsigned short)shops.size());
    for(auto i=shops.begin();i!=shops.end();++i){
        Unk_PayloadPtr<CGuildNpcShop> ref=i->second;
        out.vfunc_o10_0(ref!=0);
        if(ref!=0) ref->FUN_1404d83e0(out);
    }
}
// @0x1404d8e80
void CGuildNpcShopMgr::FUN_1404d8e80(CInPacket* packet){
    CInputStream& in=*packet;
    unsigned short n=in.vfunc_o8_2();
    shops.clear();
    for(int i=0;i<(int)n;++i){
        if(in.vfunc_o8_0()){
            Unk_PayloadPtr<CGuildNpcShop> ref(new CGuildNpcShop);
            ref->FUN_1404d8520(packet);
            shops[ref->f18]=ref;
        }
    }
}
// @0x1404d8ff0
void CGuildNpcShopMgr::FUN_1404d8ff0(unsigned id,CInPacket* packet){
    Unk_PayloadPtr<CGuildNpcShop> ref=FUN_1404d88e0(id);
    if(ref!=0) ref->FUN_1404d8520(packet);
}
// @0x1404d9060
void CGuildNpcShopMgr::FUN_1404d9060(unsigned id,CInPacket* packet){
    Unk_PayloadPtr<CGuildNpcShop> ref=FUN_1404d88e0(id);
    if(ref!=0){
        Unk_PayloadPtr<CNpcShopProductProxy> product(new CNpcShopProductProxy);
        product->FUN_1404d7fa0(packet);
        int index=ref->FUN_1404d82a0(product->f18,product->f1c,0);
        if(index<0) ref->products.push_back(product);
        else ref->products[index]=product;
    }
}
// @0x1404d91e0
void Unk_GuildShopOffer::FUN_1404d91e0(COutputStream& out){
    out.vfunc_o10_3(f18);
    out.vfunc_o10_3(f1c);
    out.vfunc_o10_3(f20);
    out.vfunc_o10_4(f28);
}
// @0x1404d9260
void Unk_GuildShopOffer::FUN_1404d9260(CInPacket* packet){
    CInputStream& in=*packet;
    f18=in.vfunc_o8_3();
    f1c=in.vfunc_o8_3();
    f20=in.vfunc_o8_3();
    f28=in.vfunc_o8_4();
}
// @0x1404d9330
int FUN_1404d9330(const CString& text){
    if(text.CompareNoCase("exp")==0) return 1;
    if(text.CompareNoCase("fund")==0) return 2;
    if(text.CompareNoCase("guildCoin")==0) return 3;
    return 0;
}
// Container instantiations used by the guild XML tables (all member COMDATs are emitted, matching the exe).
template class std::map<int,Unk_PayloadPtr<CGuildXmlData::GuildProperty>>;
template class std::map<int,std::vector<Unk_PayloadPtr<CGuildXmlData::GuildSkill>>>;
template class std::map<int,Unk_PayloadPtr<CGuildXmlData::GuildEvent>>;
template class std::map<std::pair<Unk_GuildNpcKind,int>,Unk_PayloadPtr<CGuildXmlData::GuildNpc>>;
template class std::map<unsigned,Unk_PayloadPtr<CGuildXmlData::GuildRaid>>;
template class std::map<int,Unk_PayloadPtr<CGuildXmlData::GuildRaidReward>>;
template class std::map<std::pair<int,int>,Unk_PayloadPtr<CGuildXmlData::GuildHouse>>;
template class std::map<unsigned,Unk_PayloadPtr<CGuildNpcShop>>;
template class std::set<Unk_GuildNpcKind>;
// Display names of the guild store sort/order kinds (static initializer at 0x1400b8e00).
static CString s_guildNames[7]={CString("None"),CString("Buy"),CString("Like"),CString("PriceLow"),CString("PriceHigh"),CString("Create"),CString("EnumEnd")};
