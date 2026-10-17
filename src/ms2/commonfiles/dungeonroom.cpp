// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The dungeon room table: DungeonRoom.xml and its companion
// tables (DungeonRankReward, DungeonSeason, DungeonRoundData, DungeonConfig, DungeonRewardCoupon).
// MS2-UNIT: commonfiles\dungeonroom.cpp
// MS2-RANGE: 0x14031c970-0x140343e50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@F@std@@V?$_Vector_val@U?$_Simple_types@F@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140322960 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140322b70 ; probe
// MS2-PIN: ??$_Pocca@V?$allocator@I@std@@@std@@YAXAEAV?$allocator@I@0@AEBV10@U?$integral_constant@_N$0A@@0@@Z 0x1403240c0 ; order
// MS2-PIN: ??$_Adl_verify_range@V?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@V12@@std@@YAXAEBV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@0@0@Z 0x140324110 ; order
// MS2-PIN: ??$_Destroy_range@V?$allocator@I@std@@@std@@YAXPEAI0AEAV?$allocator@I@0@@Z 0x140324cb0 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@F@?$vector@FV?$allocator@F@std@@@std@@AEAAX$$QEAF@Z 0x1403253b0 ; unique
// MS2-PIN: ??$_Freenode0@V?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@@?$_Tree_node@_JPEAX@std@@SAXAEAV?$allocator@U?$_Tree_node@_JPEAX@std@@@1@PEAU01@@Z 0x1403269f0 ; unique
// MS2-PIN: ??$_Convert_size@_K@std@@YA_K_K@Z 0x140326ae0 ; probe
// MS2-PIN: ??$_Get_unwrapped@F@std@@YAPEAFQEAF@Z 0x140326b00 ; probe
// MS2-PIN: ??$_Get_unwrapped@I@std@@YAPEAIQEAI@Z 0x140326b20 ; probe
// MS2-PIN: ??$_Unfancy@I@std@@YAPEAIPEAI@Z 0x140326b30 ; probe
// MS2-PIN: ??$_Get_unwrapped_n@F_J$0A@@std@@YAPEAFQEAF_J@Z 0x140326bd0 ; probe
// MS2-PIN: ??$_Idl_distance1@PEAFPEAF@std@@YA_JAEBQEAF0Urandom_access_iterator_tag@0@@Z 0x140326c30 ; unique
// MS2-PIN: ??$_Idl_distance@PEAFPEAF@std@@YA_JAEBQEAF0@Z 0x140326de0 ; prop
// MS2-PIN: ??$_Seek_wrapped@F@std@@YAXAEAPEAFQEAF@Z 0x14032de90 ; probe
// MS2-PIN: ??$_Seek_wrapped@I@std@@YAXAEAPEAIQEAI@Z 0x14032ded0 ; probe
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x14032df10 ; probe
// MS2-PIN: ??$_Unfancy@F@std@@YAPEAFPEAF@Z 0x14032e5b0 ; prop
// MS2-PIN: ??$addressof@$$CBV?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@YAPEBV?$_Vector_val@U?$_Simple_types@I@std@@@0@AEBV10@@Z 0x14032e600 ; probe
// MS2-PIN: ??$addressof@$$CBV?$vector@IV?$allocator@I@std@@@std@@@std@@YAPEBV?$vector@IV?$allocator@I@std@@@0@AEBV10@@Z 0x14032e610 ; probe
// MS2-PIN: ??$addressof@PEAU?$_Tree_node@_JPEAX@std@@@std@@YAPEAPEAU?$_Tree_node@_JPEAX@0@AEAPEAU10@@Z 0x14032f7d0 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@_J@std@@@0@AEAV10@@Z 0x14032f8c0 ; prop
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@F@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@F@std@@@0@AEAV10@@Z 0x14032f8d0 ; prop
// MS2-PIN: ??$addressof@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@YAPEAV?$_Vector_val@U?$_Simple_types@I@std@@@0@AEAV10@@Z 0x14032f8e0 ; order
// MS2-PIN: ??$construct@FF@?$_Default_allocator_traits@V?$allocator@F@std@@@std@@SAXAEAV?$allocator@F@1@QEAF$$QEAF@Z 0x14032f9b0 ; unique
// MS2-PIN: ??$construct@PEAU?$_Tree_node@_JPEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@_JPEAX@std@@@1@QEAPEAU?$_Tree_node@_JPEAX@1@AEAPEAU31@@Z 0x14032fc30 ; prop
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@_JPEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@_JPEAX@std@@@1@QEAPEAU?$_Tree_node@_JPEAX@1@@Z 0x1403307f0 ; prop
// MS2-PIN: ??$destroy@_J@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@_JPEAX@std@@@1@QEA_J@Z 0x140330980 ; prop
// MS2-PIN: ??$emplace_back@F@?$vector@FV?$allocator@F@std@@@std@@QEAAX$$QEAF@Z 0x140330aa0 ; prop
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@_JPEAX@std@@@std@@YAAEAPEAU?$_Tree_node@_JPEAX@0@AEAPEAU10@@Z 0x140331050 ; prop
// MS2-PIN: ??$forward@AEBI@std@@YAAEBIAEBI@Z 0x140331100 ; probe
// MS2-PIN: ??$forward@F@std@@YA$$QEAFAEAF@Z 0x1403311a0 ; prop
// MS2-PIN: ??$forward@I@std@@YA$$QEAIAEAI@Z 0x140331210 ; prop
// MS2-PIN: ??$forward@U_Zero_then_variadic_args_t@std@@@std@@YA$$QEAU_Zero_then_variadic_args_t@0@AEAU10@@Z 0x140331220 ; probe
// MS2-PIN: ??$move@AEAD@std@@YA$$QEADAEAD@Z 0x1403312b0 ; probe
// MS2-PIN: ??$move@AEAF@std@@YA$$QEAFAEAF@Z 0x1403312c0 ; probe
// MS2-PIN: ??$move@AEAI@std@@YA$$QEAIAEAI@Z 0x1403312d0 ; probe
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@_JPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@_J@std@@@1@@Z 0x140332440 ; prop
// MS2-PIN: ??0ArgType@internal@fmt@@QEAA@XZ 0x140332680 ; probe
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@_JPEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@_J@std@@@1@@Z 0x140332840 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEAA@XZ 0x140332b80 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAA@XZ 0x140332c10 ; probe
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@F@std@@@std@@@std@@QEAA@PEAFPEBU_Container_base0@1@@Z 0x140332cd0 ; prop
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEAA@PEAIPEBU_Container_base0@1@@Z 0x140332d10 ; order
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@F@std@@@std@@@std@@QEAA@PEAFPEBU_Container_base0@1@@Z 0x140332d50 ; prop
// MS2-PIN: ??0?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEAA@PEAIPEBU_Container_base0@1@@Z 0x140332d90 ; order
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@F@std@@@std@@QEAA@XZ 0x140332dd0 ; prop
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@I@std@@@std@@QEAA@XZ 0x140332e90 ; probe
// MS2-PIN: ??0?$allocator@F@std@@QEAA@XZ 0x140332f90 ; prop
// MS2-PIN: ??0?$allocator@I@std@@QEAA@XZ 0x140333040 ; probe
// MS2-PIN: ??0?$vector@FV?$allocator@F@std@@@std@@QEAA@XZ 0x140333340 ; unique
// MS2-PIN: ??0?$vector@IV?$allocator@I@std@@@std@@QEAA@XZ 0x1403333d0 ; probe
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA@XZ 0x140333920 ; unique
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x140334800 ; probe
// MS2-PIN: ?_Unwrapped@?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEBAPEBIXZ 0x140334ab0 ; probe
// MS2-PIN: ?_Unwrapped@?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@I@std@@@std@@@std@@QEBAPEAIXZ 0x140336900 ; probe
// MS2-PIN: ?Reference@?$MS2Ptr@VDungeonRoom@@@@CAXPEAVDungeonRoom@@@Z 0x140337020 ; order
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@_JPEAX@2@XZ 0x140337750 ; prop
// MS2-PIN: ?_Calculate_growth@?$vector@FV?$allocator@F@std@@@std@@AEBA_K_K@Z 0x140337e30 ; prop
// MS2-PIN: ?_Change_array@?$vector@FV?$allocator@F@std@@@std@@AEAAXQEAF_K1@Z 0x140338220 ; unique
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x140338b10 ; order
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAAXXZ 0x140338c70 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@_JPEAX@2@@Z 0x1403394b0 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@_J@std@@@2@XZ 0x14033c840 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@F@std@@@2@XZ 0x14033c870 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@F@std@@@2@XZ 0x14033c890 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x14033c9b0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x14033c9d0 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VDungeonRoundData@@@@V?$allocator@V?$MS2Ptr@VDungeonRoundData@@@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VDungeonRoundData@@@@@std@@@2@XZ 0x14033c9f0 ; probe
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@F@std@@V?$_Vector_val@U?$_Simple_types@F@std@@@2@$00@std@@QEAAAEAV?$allocator@F@2@XZ 0x14033ca30 ; probe
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEBAAEBV?$allocator@I@2@XZ 0x14033ca40 ; probe
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAAAEAV?$allocator@I@2@XZ 0x14033cb00 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@F@std@@V?$_Vector_val@U?$_Simple_types@F@std@@@2@$00@std@@QEBAAEBV?$allocator@F@2@XZ 0x14033cb10 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@F@std@@V?$_Vector_val@U?$_Simple_types@F@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@F@std@@@2@XZ 0x14033cdc0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@F@std@@V?$_Vector_val@U?$_Simple_types@F@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@F@std@@@2@XZ 0x14033cdd0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@_J@std@@@2@XZ 0x14033cec0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x14033cf50 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@I@std@@V?$_Vector_val@U?$_Simple_types@I@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@I@std@@@2@XZ 0x14033cf60 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VDungeonRoundData@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VDungeonRoundData@@@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VDungeonRoundData@@@@@std@@@2@XZ 0x14033cf70 ; probe
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEBAAEBV?$allocator@F@2@XZ 0x14033d280 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBV?$allocator@I@2@XZ 0x14033d440 ; probe
// MS2-PIN: ?_Has_unused_capacity@?$vector@FV?$allocator@F@std@@@std@@AEBA_NXZ 0x14033d5c0 ; prop
// MS2-PIN: ?_Has_unused_capacity@?$vector@IV?$allocator@I@std@@@std@@AEBA_NXZ 0x14033d700 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEAAAEAPEAFXZ 0x14033e460 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEBAAEBQEAFXZ 0x14033e480 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAAEAPEAIXZ 0x14033e5a0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBQEAIXZ 0x14033e5c0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEAAAEAPEAFXZ 0x14033e620 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEBAAEBQEAFXZ 0x14033e640 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAAEAPEAIXZ 0x14033e760 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEAAAEAPEAFXZ 0x14033e7e0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEBAAEBQEAFXZ 0x14033e800 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAAEAPEAIXZ 0x14033e920 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEBAAEBQEAIXZ 0x14033e940 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@FV?$allocator@F@std@@@std@@@std@@QEAAXXZ 0x14033e9a0 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@IV?$allocator@I@std@@@std@@@std@@QEAAXXZ 0x14033ea40 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@FV?$allocator@F@std@@@std@@AEBAXPEAF0@Z 0x14033ea80 ; prop
// MS2-PIN: ?_Orphan_range@?$vector@IV?$allocator@I@std@@@std@@AEBAXPEAI0@Z 0x14033eab0 ; probe
// MS2-PIN: ?Release@?$MS2Ptr@VDungeonRoom@@@@AEAAXXZ 0x14033ecb0 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VDungeonRoom@@@@AEAAXPEAX@Z 0x14033ef50 ; order
// MS2-PIN: ?_Tidy@?$vector@V?$MS2Ptr@VDungeonRoundData@@@@V?$allocator@V?$MS2Ptr@VDungeonRoundData@@@@@std@@@std@@AEAAXXZ 0x140340020 ; unique
// MS2-PIN: ??__EInitializeCAtlStringMgr@ATLImplementationDetails@ATL@@YAXXZ 0x1403408f0 ; probe
// MS2-PIN: ?_Xlength@?$vector@V?$MS2Ptr@VDungeonRoundData@@@@V?$allocator@V?$MS2Ptr@VDungeonRoundData@@@@@std@@@std@@CAXXZ 0x140340950 ; probe
// MS2-PIN: ?_Xlength@?$vector@IV?$allocator@I@std@@@std@@CAXXZ 0x140340990 ; probe
// MS2-PIN: ?allocate@?$allocator@F@std@@QEAAPEAF_K@Z 0x1403409d0 ; prop
// MS2-PIN: ?allocate@?$allocator@V?$MS2Ptr@VDungeonRoundData@@@@@std@@QEAAPEAV?$MS2Ptr@VDungeonRoundData@@@@_K@Z 0x140340be0 ; probe
// MS2-PIN: ?begin@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@2@XZ 0x140340ff0 ; unique
// MS2-PIN: ?capacity@?$vector@FV?$allocator@F@std@@@std@@QEBA_KXZ 0x1403410c0 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAAXXZ 0x1403416e0 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@_JPEAX@std@@@2@QEAU?$_Tree_node@_JPEAX@2@_K@Z 0x140341950 ; prop
// MS2-PIN: ?deallocate@?$allocator@F@std@@QEAAXQEAF_K@Z 0x140341980 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@_JPEAX@std@@@std@@QEAAXQEAU?$_Tree_node@_JPEAX@2@_K@Z 0x140341b00 ; prop
// MS2-PIN: ?empty@?$vector@FV?$allocator@F@std@@@std@@QEBA_NXZ 0x140341c50 ; unique
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@2@XZ 0x140341f40 ; unique
// MS2-PIN: ?end@?$vector@FV?$allocator@F@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@F@std@@@std@@@2@XZ 0x140341fa0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@2@V32@0@Z 0x140342bc0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@_JU?$less@_J@std@@V?$allocator@_J@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@_J@std@@@std@@@2@V32@@Z 0x140342cb0 ; prop
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@F@std@@@std@@SA_KAEBV?$allocator@F@2@@Z 0x140343400 ; unique
// MS2-PIN: ?max_size@?$vector@FV?$allocator@F@std@@@std@@QEBA_KXZ 0x1403435c0 ; prop
// MS2-PIN: ?size@?$vector@FV?$allocator@F@std@@@std@@QEBA_KXZ 0x140343c30 ; unique
// MS2-PINS-END tplpin
// Partial recovery: the free helpers and the DungeonRoom / DungeonRankRewardBase / DungeonLobbyCtx code.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonroom.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dungeonroom.h"
#include "dungeonrewardcoupon.h"
#include "timeutil.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <iterator>
#include <stdlib.h>

// The common log (FUN_140166440()).
class Unk_CommonLog : public CLogString
{
public:
    template <class T> void Log(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* format, const T& value)
    {
        fmt::internal::Value values[] = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
        FUN_1406535b0(a, b, flags, format, fmt::ArgList(fmt::internal::make_type(value), values));
    }
    void FUN_1402804e0(unsigned __int64 a, unsigned __int64 b, int flags, const wchar_t* message);
};
Unk_CommonLog* FUN_140166440();

class Unk_140166410 { public: bool FUN_14036d570(int nId); };   // the content switches
Unk_140166410* FUN_140166410();

int FUN_140768010(int nRange, int nBase);              // random number in [nBase, nBase + nRange)
int FUN_1402178b0(int nValue);
int FUN_140873160(Unk_140165cf0* pElem, const char* pszName, short& nOut);
int FUN_140873600(Unk_140165cf0* pElem, const char* pszName, CMsTime& tOut);
int FUN_14021ab60(const CString& str);                 // timer type name -> value
void FUN_140274fc0(CStringW& str, void* pOut, const wchar_t* pszDelim);   // split into a CAtlArray<unsigned>

// Clamps v into [lo, hi].
template <class T> T Clamp(const T& v, T lo, T hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}

// Appends src to the end of out.
template <class C> void AppendTo(const C& src, C& out)
{
    std::copy(src.begin(), src.end(), std::back_inserter(out));
}

// The "kill"/"damage"/... boss ranking type names.
DungeonBossRankingType ParseBossRankingType(const CString& str);   // 0x1403227f0

// Sets the bits listed in a comma separated string ("1,3,5").
inline void SetBitsFromString(Unk_PartyBits& bits, CStringW str)
{
    if (str.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> arr;
    FUN_140274fc0(str, &arr, L",");
    for (unsigned i = 0; i < arr.GetCount(); i++)
        bits.FUN_1402e69d0(arr[i], true);
}
inline void SetBits(Unk_PartyBits& bits, CStringW str)
{
    SetBitsFromString(bits, str);
}

// tinyxmlhelper.h readers.
inline int ReadDayBits(Unk_140165cf0* pElem, const char* pszName, Unk_PartyBits& out)
{
    CStringW str;
    int nRet = FUN_140873420(pElem, pszName, str);
    if (nRet == 0)
        SetBits(out, str);
    return nRet;
}
inline int ReadBossRankingType(Unk_140165cf0* pElem, const char* pszName, DungeonBossRankingType& out)
{
    if (0)
    {
        MS2_TINYXMLHELPER_ASSERT(250, FALSE);
        return 2;
    }
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet != 0)
        return nRet;
    out = ParseBossRankingType(str);
    return nRet;
}
inline int ReadTimerType(Unk_140165cf0* pElem, const char* pszName, DungeonTimerType& out)
{
    if (0)
    {
        MS2_TINYXMLHELPER_ASSERT(250, FALSE);
        return 2;
    }
    CString str;
    int nRet = FUN_1408733e0(pElem, pszName, str);
    if (nRet != 0)
        return nRet;
    out = (DungeonTimerType)FUN_14021ab60(str);
    return nRet;
}

// @0x14031c970
int MakeDungeonRoomId(int nDungeonId, int nIndex)
{
    return nDungeonId * 1000 + nIndex;
}
MS2_REPLACE_OVERLOAD(0x14031C970, int(int, int), MakeDungeonRoomId, 21, 0xD0D09CEF);

// @0x14031c990
unsigned GetDungeonIdOfRoom(unsigned nRoomId)
{
    return nRoomId / 1000;
}
MS2_REPLACE_OVERLOAD(0x14031C990, unsigned(unsigned), GetDungeonIdOfRoom, 18, 0x9F64D931);

// @0x14031c9b0
unsigned GetIndexOfRoom(unsigned nRoomId)
{
    return nRoomId % 1000;
}
MS2_REPLACE_OVERLOAD(0x14031C9B0, unsigned(unsigned), GetIndexOfRoom, 20, 0xB85C6666);

// @0x14031c9d0
CString GetRankName(int nRank)
{
    if (nRank < 0)
        return "rank_unknown";
    return StringFormat("rank{0}", nRank);
}
MS2_REPLACE_OVERLOAD(0x14031C9D0, CString(int), GetRankName, 107, 0x7CC0E8D0);

// @0x14031ca50
DungeonLobbyCtx::DungeonLobbyCtx()
    : m_18(0), m_1c(0), m_20(0)
{
}

// @0x14031cad0
DungeonRankRewardBase::DungeonRankRewardBase()
    : m_rewardID(0), m_maxRank(0)
{
}

// @0x14031cb30
bool DungeonRankRewardBase::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "rewardID", m_rewardID);
    m_items.resize(6);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("v"); pChild; pChild = pChild->FUN_140168650("v"))
    {
        int nRank = 0;
        FUN_1408731e0(pChild, "rank", nRank);
        if (nRank <= 0 || nRank > 5)
        {
            FUN_140166440()->FUN_1402804e0(0, 0, 0x13, StringFormat(L"DungeonRankReward::FromXel Invalid Rank", m_rewardID, nRank));
            return false;
        }
        if (m_maxRank < nRank)
            m_maxRank = nRank;
        DungeonRankRewardItem& item = m_items[nRank];
        FUN_140873220(pChild, "itemID", item.itemID);
        FUN_1408731e0(pChild, "systemMailID", item.systemMailID);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14031CB30, DungeonRankRewardBase, Load, 434, 0x129CC2FA);

// @0x14031ccf0
unsigned DungeonRankRewardBase::GetId()
{
    return m_rewardID;
}
MS2_REPLACE_METHOD(0x14031CCF0, DungeonRankRewardBase, GetId, 14, 0x72E52537);

// @0x14031cd10
unsigned DungeonRankRewardBase::GetItemId(int nRank)
{
    if ((size_t)nRank >= m_items.size())
        return 0;
    return m_items[nRank].itemID;
}
MS2_REPLACE_METHOD(0x14031CD10, DungeonRankRewardBase, GetItemId, 80, 0x197FCB72);

// @0x14031cd70
int DungeonRankRewardBase::GetSystemMailId(int nRank)
{
    if ((size_t)nRank >= m_items.size())
        return 0;
    return m_items[nRank].systemMailID;
}
MS2_REPLACE_METHOD(0x14031CD70, DungeonRankRewardBase, GetSystemMailId, 81, 0x282CEAA5);

// @0x14031cdd0
int DungeonRankRewardBase::GetMaxRank()
{
    return m_maxRank;
}
MS2_REPLACE_METHOD(0x14031CDD0, DungeonRankRewardBase, GetMaxRank, 14, 0xB2976B17);

// @0x14031cdf0
DungeonRoom::DungeonRoom()
    : m_dungeonRoomID(0), m_groupType((DungeonGroupType)0), m_dungeonLevel(0), m_limitEnter(false), m_clearKillNpc(0),
      m_sortOrder(0), m_cooldownValue(0), m_rewardCount(0), m_subRewardCount(0), m_isAccountReward(false),
      m_unionRewardID(0), m_roundID(0), m_rewardExp(0), m_rewardExpRate(0), m_rewardMeso(0), m_seasonRankRewardID(0),
      m_scoreBonusId(0), m_extraRewardTicketTableID(0), m_extraRewardTicketBaseCount(0), m_lobbyFieldID(0),
      m_durationSeconds(0), m_isExpireTimeOut(false), m_timerType((DungeonTimerType)0), m_minUserCount(0),
      m_maxUserCount(0), m_gearScore(0), m_limitAchieveID(0), m_limitPlayerLevel(0), m_limitVIP(false),
      m_isLimitTime(false), m_limitMesoRevival(false), m_limitMeratRevival(false), m_limitRecommendWeapon(false),
      m_defaultRevivalLimitCount(0), m_isTimeUp(0), m_isUseBossIcon(false),
      m_bossRankingType((DungeonBossRankingType)0), m_bossRanking(0), m_isRandomField(false), m_isPartyOnly(false),
      m_isChangeMaxUser(false), m_playerCountFactorID(0), m_customMonsterLevel(0), m_chaosDamageMeter(false),
      m_isMoveOutToBackupField(false), m_dungeonHelperRequireClearCount(0), m_isUseRandomMatch(false),
      m_isDisableRandomMatch(false), m_isLeaveAfterCloseReward(false), m_rankTableID(0), m_representID(0),
      m_dungeonScaleStatID(0), m_pRoundGroup(0), m_pCoupon(0)
{
}

// @0x14031d220
DungeonRoom::~DungeonRoom()
{
}

// @0x14031d350
void DungeonRoom::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dungeonRoomID", m_dungeonRoomID);
    FUN_1408731a0(pElem, "dungeonLevel", m_dungeonLevel);
    FUN_1408730a0(pElem, "limitEnter", m_limitEnter);
    XmlValue(pElem, "groupType", m_groupType);
    FUN_1408731e0(pElem, "clearKillNpc", m_clearKillNpc);
    FUN_1408731e0(pElem, "cooldownValue", m_cooldownValue);
    FUN_1408731e0(pElem, "sortOrder", m_sortOrder);
    FUN_140873220(pElem, "rewardCount", m_rewardCount);
    FUN_140873220(pElem, "subRewardCount", m_subRewardCount);
    FUN_1408730a0(pElem, "isAccountReward", m_isAccountReward);
    FUN_140873220(pElem, "unionRewardID", m_unionRewardID);
    FUN_140873220(pElem, "roundID", m_roundID);
    FUN_1408732e0(pElem, "rewardExp", m_rewardExp);
    FUN_140873360(pElem, "rewardExpRate", m_rewardExpRate);
    FUN_1408732e0(pElem, "rewardMeso", m_rewardMeso);
    FUN_1408731e0(pElem, "scoreBonusId", m_scoreBonusId);
    XmlTokenList(pElem, "rewardLimitedDropBoxIds", m_rewardLimitedDropBoxIds);
    XmlTokenList(pElem, "rewardLimitedDropBoxIds2", m_rewardLimitedDropBoxIds2);
    FUN_140873220(pElem, "seasonRankRewardID", m_seasonRankRewardID);
    m_rewardDropBoxIds = m_rewardLimitedDropBoxIds;
    std::copy(m_rewardLimitedDropBoxIds2.begin(), m_rewardLimitedDropBoxIds2.end(), std::back_inserter(m_rewardDropBoxIds));
    FUN_140873220(pElem, "extraRewardTicketTableID", m_extraRewardTicketTableID);
    FUN_140873220(pElem, "extraRewardTicketBaseCount", m_extraRewardTicketBaseCount);
    FUN_140873220(pElem, "lobbyFieldID", m_lobbyFieldID);
    XmlTokenList(pElem, "fieldIDs", m_fieldIDs);
    FUN_1408731e0(pElem, "durationSeconds", m_durationSeconds);
    FUN_1408730a0(pElem, "isExpireTimeOut", m_isExpireTimeOut);
    ReadTimerType(pElem, "timerType", m_timerType);
    FUN_140873220(pElem, "minUserCount", m_minUserCount);
    FUN_140873220(pElem, "maxUserCount", m_maxUserCount);
    FUN_140873220(pElem, "gearScore", m_gearScore);
    FUN_1408731e0(pElem, "limitAchieveID", m_limitAchieveID);
    FUN_1408731a0(pElem, "limitPlayerLevel", m_limitPlayerLevel);
    ReadDayBits(pElem, "limitDayOfWeeks", m_limitDayOfWeeks);
    FUN_1408730a0(pElem, "limitVIP", m_limitVIP);
    FUN_1408730a0(pElem, "isLimitTime", m_isLimitTime);
    FUN_1408730a0(pElem, "limitMesoRevival", m_limitMesoRevival);
    FUN_1408730a0(pElem, "limitMeratRevival", m_limitMeratRevival);
    XmlTokenList(pElem, "limitClearDungeon", m_limitClearDungeon);
    XmlTokenList(pElem, "limitAdditionalEffects", m_limitAdditionalEffects);
    FUN_1408730a0(pElem, "limitRecommendWeapon", m_limitRecommendWeapon);
    FUN_1408733e0(pElem, "dungeonBanner", m_dungeonBanner);
    FUN_1408733e0(pElem, "bossIcon", m_bossIcon);
    FUN_1408731e0(pElem, "isTimeUp", m_isTimeUp);
    FUN_1408730a0(pElem, "isUseBossIcon", m_isUseBossIcon);
    ReadBossRankingType(pElem, "BossRankingType", m_bossRankingType);
    FUN_140873220(pElem, "BossRanking", m_bossRanking);
    FUN_140873420(pElem, "openPeriodTag", m_openPeriodTag);
    FUN_140873600(pElem, "openPeriodDate", m_openPeriodDate);
    FUN_1408730a0(pElem, "isRandomField", m_isRandomField);
    FUN_1408730a0(pElem, "isPartyOnly", m_isPartyOnly);
    FUN_1408730a0(pElem, "isChangeMaxUser", m_isChangeMaxUser);
    FUN_140873220(pElem, "playerCountFactorID", m_playerCountFactorID);
    FUN_1408731e0(pElem, "customMonsterLevel", m_customMonsterLevel);
    FUN_1408730a0(pElem, "chaosDamageMeter", m_chaosDamageMeter);
    FUN_1408730a0(pElem, "isMoveOutToBackupField", m_isMoveOutToBackupField);
    FUN_140873220(pElem, "defaultRevivalLimitCount", m_defaultRevivalLimitCount);
    FUN_1408731e0(pElem, "dungeonHelperRequireClearCount", m_dungeonHelperRequireClearCount);
    XmlTokenList(pElem, "findHelperRewardDropBoxIds", m_findHelperRewardDropBoxIds);
    FUN_1408730a0(pElem, "isUseRandomMatch", m_isUseRandomMatch);
    FUN_1408730a0(pElem, "isDisableRandomMatch", m_isDisableRandomMatch);
    FUN_1408730a0(pElem, "isLeaveAfterCloseReward", m_isLeaveAfterCloseReward);
    XmlTokenList(pElem, "partyMissions", m_partyMissions);
    XmlTokenList(pElem, "userMissions", m_userMissions);
    FUN_140873220(pElem, "rankTableID", m_rankTableID);
    FUN_140873220(pElem, "representID", m_representID);
    FUN_140873220(pElem, "dungeonScaleStatID", m_dungeonScaleStatID);
    ApplyConstants();
    if (m_bossRankingType == 0 && m_bossRanking != 0)
    {
        FUN_140166440()->Log(0, 0, 0x13, L"DungeonRoom::FromXel : m_bossRanking is exists but bossRankingType is none or empty. use kill type as default. ID=[{0}]", m_dungeonRoomID);
        m_bossRankingType = (DungeonBossRankingType)1;
    }
}
MS2_REPLACE_METHOD(0x14031D350, DungeonRoom, Load, 2671, 0x847FF231);

// @0x14031ddd0
unsigned DungeonRoom::GetDungeonRoomID()
{
    return m_dungeonRoomID;
}
MS2_REPLACE_METHOD(0x14031DDD0, DungeonRoom, GetDungeonRoomID, 14, 0x72E52537);

// @0x14031ddf0
unsigned DungeonRoom::GetRewardRoomID()
{
    if (m_unionRewardID != 0)
        return m_unionRewardID;
    return m_dungeonRoomID;
}
MS2_REPLACE_METHOD(0x14031DDF0, DungeonRoom, GetRewardRoomID, 35, 0x23747190);

// @0x14031de20
unsigned DungeonRoom::GetDungeonID()
{
    return GetDungeonIdOfRoom(m_dungeonRoomID);
}
MS2_REPLACE_METHOD(0x14031DE20, DungeonRoom, GetDungeonID, 27, 0xDAE514A2);

// @0x14031de50
unsigned DungeonRoom::GetRoomIndex()
{
    return GetIndexOfRoom(m_dungeonRoomID);
}
MS2_REPLACE_METHOD(0x14031DE50, DungeonRoom, GetRoomIndex, 27, 0xDEC64D72);

// @0x14031de80
bool DungeonRoom::HasEnterRequirement()
{
    if (m_limitPlayerLevel != 0)
        return true;
    if (m_gearScore != 0)
        return true;
    if (m_limitAchieveID != 0)
        return true;
    if (m_limitClearDungeon.size() > 0)
        return true;
    if (m_limitRecommendWeapon)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14031DE80, DungeonRoom, HasEnterRequirement, 120, 0x2760FAFF);

// @0x14031df00
unsigned DungeonRoom::GetLobbyFieldID()
{
    return m_lobbyFieldID;
}
MS2_REPLACE_METHOD(0x14031DF00, DungeonRoom, GetLobbyFieldID, 17, 0x33D25353);

// @0x14031df20
unsigned DungeonRoom::GetFirstFieldID()
{
    if (m_fieldIDs.IsEmpty())
        return 0;
    return m_fieldIDs[0];
}
MS2_REPLACE_METHOD(0x14031DF20, DungeonRoom, GetFirstFieldID, 67, 0xB0309514);

// @0x14031df70
int DungeonRoom::GetLimitType()
{
    if (m_limitEnter)
        return 2;
    return 1;
}
MS2_REPLACE_METHOD(0x14031DF70, DungeonRoom, GetLimitType, 31, 0x7E625B46);

// @0x14031dfa0
int DungeonRoom::GetCooldownType()
{
    if (m_cooldownValue == 0)
        return 2;
    return 1;
}
MS2_REPLACE_METHOD(0x14031DFA0, DungeonRoom, GetCooldownType, 29, 0x1F7BD1B6);

// @0x14031dfd0
int DungeonRoom::GetCooldownValue()
{
    return m_cooldownValue;
}
MS2_REPLACE_METHOD(0x14031DFD0, DungeonRoom, GetCooldownValue, 14, 0x9A8B24F3);

// @0x14031dff0
__int64 DungeonRoom::GetCooldownEndTime(__int64 tNow)
{
    return CalcCooldownEndTime(GetCooldownType(), m_cooldownValue, tNow);
}
MS2_REPLACE_METHOD(0x14031DFF0, DungeonRoom, GetCooldownEndTime, 49, 0x1EF01660);

// @0x14031e030
unsigned DungeonRoom::GetMaxUserCount(unsigned nUser)
{
    if (!m_isChangeMaxUser)
        return m_maxUserCount;
    return Clamp(nUser, 2u, m_maxUserCount);
}
MS2_REPLACE_METHOD(0x14031E030, DungeonRoom, GetMaxUserCount, 74, 0xD5A8F3B9);

// @0x14031e0d0
bool DungeonRoom::HasExtraRewardTicket()
{
    return m_extraRewardTicketTableID != 0;
}
MS2_REPLACE_METHOD(0x14031E0D0, DungeonRoom, HasExtraRewardTicket, 48, 0x0FD978E4);

// @0x14031e110
unsigned DungeonRoom::GetCouponBaseItemID()
{
    DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return 0;
    return pCoupon->m_baseItemID;
}

// @0x14031e150
unsigned DungeonRoom::GetCouponTicketTag()
{
    DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return 0;
    return pCoupon->m_ticketTag;
}

// @0x14031e190
bool DungeonRoom::CanBuyCouponInMeratMarket()
{
    DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return false;
    return pCoupon->m_canBuyInMeratMarket;
}

// @0x14031e1d0
bool DungeonRoom::HasMissions()
{
    if (m_partyMissions.size() > 0)
        return true;
    if (m_userMissions.size() > 0)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14031E1D0, DungeonRoom, HasMissions, 72, 0x07D4B4BD);

// @0x14031e220
unsigned DungeonRoom::GetSeasonRankRewardID()
{
    return m_seasonRankRewardID;
}
MS2_REPLACE_METHOD(0x14031E220, DungeonRoom, GetSeasonRankRewardID, 17, 0x1F8D7963);

// @0x14031e240
unsigned DungeonRoom::GetRandomFieldID()
{
    if (m_fieldIDs.IsEmpty())
        return 0;
    unsigned nIndex = FUN_140768010((int)m_fieldIDs.GetCount(), 0);
    return m_fieldIDs[nIndex];
}
MS2_REPLACE_METHOD(0x14031E240, DungeonRoom, GetRandomFieldID, 101, 0x827DB8B9);

// @0x14031e2b0
unsigned DungeonRoom::GetExtraRewardTicketCost(unsigned nCount)
{
    const DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return 0;
    int nRates = (int)pCoupon->m_baseRate.GetCount();
    unsigned nIndex = Clamp(nCount, 0u, (unsigned)(nRates - 1));
    return m_extraRewardTicketBaseCount * pCoupon->m_baseRate[nIndex];
}

// @0x14031e340
int DungeonRoom::GetCouponMaxExtraCount()
{
    DungeonRewardCoupon* pCoupon = GetCoupon();
    if (pCoupon == 0)
        return 0;
    return pCoupon->m_maxExtraCount;
}

// @0x14031e380
void DungeonRoom::GetRewardDropBoxIds(std::vector<unsigned>& out)
{
    AppendTo(m_rewardDropBoxIds, out);
}
MS2_REPLACE_METHOD(0x14031E380, DungeonRoom, GetRewardDropBoxIds, 43, 0xE46707CA);

// @0x14031e3c0
unsigned DungeonRoom::GetDefaultRevivalLimitCount()
{
    return m_defaultRevivalLimitCount;
}
MS2_REPLACE_METHOD(0x14031E3C0, DungeonRoom, GetDefaultRevivalLimitCount, 17, 0x59A3408A);

// @0x14031e3e0
void DungeonRoom::GetMissions(std::vector<unsigned>& out)
{
    out.clear();
    AppendTo(m_partyMissions, out);
    AppendTo(m_userMissions, out);
}
MS2_REPLACE_METHOD(0x14031E3E0, DungeonRoom, GetMissions, 77, 0xA4197214);

// @0x14031e440
int DungeonRoom::GetRank(short nScore)
{
    return DungeonRoomTable::GetInstance()->GetRank(this, nScore);
}

// @0x14031e480
bool DungeonRoom::IsSeasonRankRoom()
{
    if (m_groupType != 3)
        return false;
    if (m_limitPlayerLevel < (unsigned)FUN_1401d3200()->DungeonSeasonRankMinLevel)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x14031E480, DungeonRoom, IsSeasonRankRoom, 68, 0xCDEF7F9A);

// @0x14031e4d0
bool DungeonRoom::IsRandomMatchable()
{
    if (!FUN_140166410()->FUN_14036d570(0xb8))
        return false;
    switch (m_groupType)
    {
    case 1:
    case 2:
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14031E4D0, DungeonRoom, IsRandomMatchable, 77, 0xB1B0E732);

// @0x14031e530
bool DungeonRoom::HasRoundGroup() const
{
    return m_pRoundGroup != 0;
}
MS2_REPLACE_METHOD(0x14031E530, DungeonRoom, HasRoundGroup, 49, 0x3DE75B1F);

// @0x14031e570
bool DungeonRoom::IsSingleRound()
{
    if (m_groupType == 7)
        return false;
    if (HasRoundGroup())
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x14031E570, DungeonRoom, IsSingleRound, 52, 0x5C55AC09);

// @0x14031e5b0
void DungeonRoom::GetRoundRewardIds(unsigned char nFrom, unsigned char nTo, std::vector<unsigned>& out)
{
    if (m_pRoundGroup == 0)
        return;
    m_pRoundGroup->GetRewardIds(nFrom, nTo, out);
}
MS2_REPLACE_METHOD(0x14031E5B0, DungeonRoom, GetRoundRewardIds, 78, 0xC9F4DBD5);

// @0x14031e610
int DungeonRoom::GetRankTableID()
{
    if (m_rankTableID != 0)
        return m_rankTableID;
    switch (m_groupType)
    {
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 8: return 6;
    case 12: return 5;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14031E610, DungeonRoom, GetRankTableID, 133, 0x32CB022B);

// @0x14031e6d0
int Unk_DungeonRoom_14031e6d0(int nType)
{
    switch (nType)
    {
    case 1:
        return 4;
    }
    MS2_ASSERT_AT(0x165, 0);
    return 0;
}
MS2_REPLACE_OVERLOAD(0x14031E6D0, int(int), Unk_DungeonRoom_14031e6d0, 73, 0xBB0DDCAC);

// @0x14031e720
bool IsDungeonLevelInRange(unsigned short nLevel, unsigned short nDungeonLevel)
{
    if (abs(nLevel - nDungeonLevel) <= 5)
        return true;
    if (nDungeonLevel >= 50 && nLevel >= 50 && nLevel <= nDungeonLevel)
        return true;
    return false;
}
MS2_REPLACE_OVERLOAD(0x14031E720, bool(unsigned short, unsigned short), IsDungeonLevelInRange, 79, 0xA936A542);

// @0x14031e780
bool Unk_DungeonRoom_14031e780(int nValue)
{
    int nResult = FUN_1402178b0(nValue);
    return nResult != 0;
}
MS2_REPLACE_OVERLOAD(0x14031E780, bool(int), Unk_DungeonRoom_14031e780, 56, 0x8141B625);

// @0x14031e7c0
__int64 CalcCooldownEndTime(int nType, int nValue, __int64 tNow)
{
    switch (nType)
    {
    case 1:
    {
#ifdef __clang__
        CMsTime tStart(tNow); // clang cannot bind the temporary to CMsTime&
        __int64 t = GetWeekdayStart(tStart, nValue);
#else
        __int64 t = GetWeekdayStart(CMsTime(tNow), nValue);
#endif
        if (t == 0)
            t = tNow;
        return t;
    }
    break;
    case 2:
        return GetNextDayStart(tNow);
    }
    return tNow;
}
MS2_REPLACE_OVERLOAD(0x14031E7C0, __int64(int, int, __int64), CalcCooldownEndTime, 120, 0x93DA44F0);

// @0x14031e840
void DungeonRoom::ApplyConstants()
{
    if (*FUN_1401d3200()->DisableSoloPlayHighLevelDungeon.Get() && m_groupType == 1 && m_limitPlayerLevel >= 50)
        m_isPartyOnly = true;
}
MS2_REPLACE_METHOD(0x14031E840, DungeonRoom, ApplyConstants, 80, 0x325A4B4F);

// @0x14031e8a0
DungeonRewardCoupon* DungeonRoom::GetCoupon()
{
    if (m_unionRewardID != 0)
    {
        DungeonRoomPtr pRoom = DungeonRoomTable::GetInstance()->GetRoom(m_unionRewardID);
        if (pRoom == 0)
            return 0;
        return pRoom->m_pCoupon;
    }
    return m_pCoupon;
}

// @0x14031e950
DungeonSeasonItemGift::DungeonSeasonItemGift()
    : m_requireScore(0)
{
}

// @0x14031e9a0
void DungeonSeasonItemGift::vfunc_4(Unk_140165cf0* pElem)
{
    ItemEntity::vfunc_2(pElem);
    FUN_140873220(pElem, "requireScore", m_requireScore);
}
MS2_REPLACE_METHOD(0x14031E9A0, DungeonSeasonItemGift, vfunc_4, 63, 0x75B0CC90);

// @0x14031e9f0
DungeonRankRequire::DungeonRankRequire()
    : m_maxScore(0)
{
}

// @0x14031ea30
void DungeonRankRequire::Load(Unk_140165cf0* pElem)
{
    FUN_140873160(pElem, "maxScore", m_maxScore);
    int nPrev = -1;
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("rank"); pChild; pChild = pChild->FUN_140168650("rank"))
    {
        int nScore = 0;
        FUN_1408731e0(pChild, "score", nScore);
        if (nPrev >= nScore)
        {
            FUN_140166440()->FUN_1402804e0(0, 0, 0x13, L"DungeonRankRequire Error Score");
            return;
        }
        nPrev = nScore;
        short sScore = (short)nScore;
        m_scores.push_back(sScore);
    }
    if (m_scores.empty() || *m_scores.rbegin() > m_maxScore)
        FUN_140166440()->FUN_1402804e0(0, 0, 0x13, L"DungeonRankRequire Error Score");
}
MS2_REPLACE_METHOD(0x14031EA30, DungeonRankRequire, Load, 337, 0xF8BFEB06);

// @0x14031eb90
short DungeonRankRequire::GetMaxScore()
{
    return m_maxScore;
}
MS2_REPLACE_METHOD(0x14031EB90, DungeonRankRequire, GetMaxScore, 14, 0x1731A3BA);

// @0x14031ebb0
int DungeonRankRequire::GetRank(short nScore)
{
    int nLast = (int)m_scores.size() - 1;
    for (int i = nLast; i >= 0; i--)
    {
        if (nScore >= m_scores[i])
            return i + 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14031EBB0, DungeonRankRequire, GetRank, 133, 0x75BE13E9);

// @0x14031ec40
int DungeonRankRequire::GetCount()
{
    return (int)m_scores.size();
}
MS2_REPLACE_METHOD(0x14031EC40, DungeonRankRequire, GetCount, 31, 0xE38FCB57);

// @0x14031ec70
short DungeonRankRequire::GetScore(unsigned __int64 nIndex)
{
    if (nIndex >= m_scores.size())
        return 0;
    return m_scores[nIndex];
}
MS2_REPLACE_METHOD(0x14031EC70, DungeonRankRequire, GetScore, 72, 0xB175E5B7);

// @0x14031ecc0
DungeonSeason::DungeonSeason()
    : m_seasonID(0), m_maxSeasonScore(0), m_systemMailID(0), m_dayOfWeeks(0)
{
}

// @0x14031ed50
DungeonSeason::~DungeonSeason()
{
}

// @0x14031ed90
bool DungeonSeason::Load(Unk_140165cf0* pElem)
{
    FUN_140873160(pElem, "seasonID", m_seasonID);
    FUN_140873220(pElem, "maxSeasonScore", m_maxSeasonScore);
    FUN_1408731e0(pElem, "systemMailID", m_systemMailID);
    FUN_1408731e0(pElem, "dayOfWeeks", m_dayOfWeeks);
    m_period.FUN_140868d60(pElem);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("Reward"); pChild; pChild = pChild->FUN_140168650("Reward"))
    {
        MS2Ptr<DungeonSeasonItemGift> pReward(new DungeonSeasonItemGift);
        pReward->vfunc_4(pChild);
        m_rewards.push_back(pReward);
    }
    if (m_rewards.size() > 2)
    {
        for (unsigned i = 0; i < m_rewards.size() - 1; i++)
        {
            if (m_rewards[i]->m_requireScore <= m_rewards[i + 1]->m_requireScore)
            {
                FUN_140166440()->FUN_1402804e0(0, 0, 0x13, L"DungeonSeason Reward Item RequireScore");
                return false;
            }
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x14031ED90, DungeonSeason, Load, 652, 0x9A7CADD3);

// @0x14031f030
bool DungeonSeason::IsInPeriod(const CMsTime& t)
{
    return m_period.FUN_140868f60(t);
}
MS2_REPLACE_METHOD(0x14031F030, DungeonSeason, IsInPeriod, 41, 0x58E9BF83);

// @0x14031f060
MS2Ptr<DungeonSeasonItemGift> DungeonSeason::GetReward(unsigned nScore)
{
    for (unsigned i = 0; i < m_rewards.size(); i++)
    {
        if (m_rewards[i]->m_requireScore <= nScore)
            return m_rewards[i];
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14031F060, DungeonSeason, GetReward, 206, 0xEF2C7266);

// @0x14031f140
DungeonUnitedWeeklyReward::DungeonUnitedWeeklyReward()
    : m_rewardCount(0), m_rewardID(0), m_uiPosX(0), m_uiShowBg(false)
{
}

// @0x14031f1a0
DungeonUnitedWeeklyReward::~DungeonUnitedWeeklyReward()
{
}

// @0x14031f1d0
bool DungeonUnitedWeeklyReward::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "rewardCount", m_rewardCount);
    FUN_140873220(pElem, "rewardID", m_rewardID);
    FUN_1408731e0(pElem, "uiPosX", m_uiPosX);
    FUN_1408730a0(pElem, "uiShowBg", m_uiShowBg);
    return true;
}
MS2_REPLACE_METHOD(0x14031F1D0, DungeonUnitedWeeklyReward, Load, 137, 0xC9AEC35F);

// @0x14031f260
DungeonRoundData::DungeonRoundData()
    : m_rewardID(0), m_gearScore(0)
{
}

// @0x14031f2b0
bool DungeonRoundData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "rewardID", m_rewardID);
    FUN_140873220(pElem, "gearScore", m_gearScore);
    return true;
}
MS2_REPLACE_METHOD(0x14031F2B0, DungeonRoundData, Load, 79, 0xDE3B4585);

// @0x14031f310
DungeonRoundGroup::DungeonRoundGroup()
    : m_id(0)
{
}

// @0x14031f360
bool DungeonRoundGroup::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_id);
    if (m_id == 0)
        return false;
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("v"); pChild; pChild = pChild->FUN_140168650("v"))
    {
        MS2Ptr<DungeonRoundData> pRound(new DungeonRoundData);
        pRound->Load(pChild);
        m_rounds.push_back(pRound);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14031F360, DungeonRoundGroup, Load, 271, 0xADB62A2B);

// @0x14031f480
void DungeonRoundGroup::GetRewardIds(unsigned char nFrom, unsigned char nTo, std::vector<unsigned>& out)
{
    out.reserve(m_rounds.size());
    for (size_t i = nFrom; i < nTo; i++)
    {
        if (i >= m_rounds.size())
            break;
        out.push_back(m_rounds[i]->m_rewardID);
    }
}
MS2_REPLACE_METHOD(0x14031F480, DungeonRoundGroup, GetRewardIds, 170, 0x06171F6B);

// @0x14031f530
MS2Ptr<DungeonRoundData> DungeonRoundGroup::GetRound(unsigned nIndex)
{
    if (nIndex >= m_rounds.size())
        return 0;
    return m_rounds[nIndex];
}
MS2_REPLACE_METHOD(0x14031F530, DungeonRoundGroup, GetRound, 144, 0x042CDDBF);
