// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's observer managers: PacketHandlerManager (opcode ->
// Delegate<void(CInPacket&)> list), GameEventUserValueManager (event id -> Delegate<void(GameEventVariable*)> list) and the
// container / Delegate glue shared with NotifySystem's name -> Delegate<void(NotifyObject*)> map (owned by ?\notifysystem.cpp,
// instantiated here by an anchor), plus the Notify* name virtuals.
// MS2-UNIT: unit_140da50e0
// MS2-RANGE: 0x140da50e0-0x140db46d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140da5710 ; prop
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140da5740 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140da57a0 ; prop
// MS2-PIN: ??$?0AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140da57f0 ; prop
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140da5930 ; unique
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140da5980 ; unique
// MS2-PIN: ??$?0AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@$$Z$$V@?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@V?$tuple@$$V@1@@Z 0x140da5a20 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140da5a70 ; prop
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@1@$$QEA_N@Z 0x140da5ac0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140da5df0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140da5ec0 ; prop
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@4@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@1@$$QEAV?$tuple@$$V@1@@Z 0x140da5f90 ; unique
// MS2-PIN: ??$_Idl_distance1@PEAV?$Delegate@$$A6AXAEAVCInPacket@@@Z@@PEAV1@@std@@YA_JAEBQEAV?$Delegate@$$A6AXAEAVCInPacket@@@Z@@0Urandom_access_iterator_tag@0@@Z 0x140da6fc0 ; unique
// MS2-PIN: ??$_Idl_distance1@PEAV?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@PEAV1@@std@@YA_JAEBQEAV?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@0Urandom_access_iterator_tag@0@@Z 0x140da6ff0 ; unique
// MS2-PIN: ??$_Idl_distance1@PEAV?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@PEAV1@@std@@YA_JAEBQEAV?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@0Urandom_access_iterator_tag@0@@Z 0x140da7020 ; unique
// MS2-PIN: ??$_Kfn@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@1@@Z 0x140daabf0 ; prop
// MS2-PIN: ??$_Kfn@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@1@@Z 0x140daac00 ; prop
// MS2-PIN: ??$_Kfn@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@?$_Tmap_traits@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@4@V?$allocator@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@4@$0A@@std@@SAAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@AEBU?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@1@@Z 0x140daac10 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$Delegate@$$A6AXAEAVCInPacket@@@Z@@0@Z 0x140dab040 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@0@Z 0x140dab070 ; unique
// MS2-PIN: ??$_Ptr_copy_cat@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V1@@std@@YA?AU_General_ptr_iterator_tag@0@AEBQEAV?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@0@Z 0x140dab0a0 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140dab1c0 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140dab310 ; unique
// MS2-PIN: ??$construct@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V1@@?$_Default_allocator_traits@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@SAXAEAV?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@1@QEAV?$Delegate@$$A6AXAEAVCInPacket@@@Z@@$$QEAV3@@Z 0x140dac1c0 ; unique
// MS2-PIN: ??$construct@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@SAXAEAV?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@1@QEAV?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@AEAV3@@Z 0x140dac210 ; unique
// MS2-PIN: ??$construct@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V1@@?$_Default_allocator_traits@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@SAXAEAV?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@1@QEAV?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@$$QEAV3@@Z 0x140dac2b0 ; unique
// MS2-PIN: ??$construct@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@AEAV1@@?$_Default_allocator_traits@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@SAXAEAV?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@1@QEAV?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@AEAV3@@Z 0x140dac300 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@1@@Z 0x140dac6b0 ; unique
// MS2-PIN: ??$destroy@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@1@@Z 0x140dac6c0 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140dac990 ; prop
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140daca30 ; prop
// MS2-PIN: ??$forward@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@YA$$QEAV?$Delegate@$$A6AXAEAVCInPacket@@@Z@@AEAV1@@Z 0x140dacc60 ; unique
// MS2-PIN: ??$forward@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@YA$$QEAV?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@AEAV1@@Z 0x140dacc70 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@1@@Z 0x140dad0c0 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@1@@Z 0x140dad120 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@1@@Z 0x140dad180 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@1@@Z 0x140dad2a0 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@1@@Z 0x140dad300 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@1@@Z 0x140dad360 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@XZ 0x140dad3a0 ; unique
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x140dad3c0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@QEAA@XZ 0x140dad3f0 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@QEAA@XZ 0x140dad510 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@QEAA@XZ 0x140dad540 ; prop
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@QEAA@XZ 0x140dad570 ; unique
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@QEAA@PEAV?$Delegate@$$A6AXAEAVCInPacket@@@Z@@PEBU_Container_base0@1@@Z 0x140dad5a0 ; unique
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@QEAA@PEAV?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@PEBU_Container_base0@1@@Z 0x140dad5e0 ; unique
// MS2-PIN: ??0?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@QEAA@PEAV?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@PEBU_Container_base0@1@@Z 0x140dad620 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@QEAA@XZ 0x140dad720 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@QEAA@XZ 0x140dad760 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@QEAA@XZ 0x140dad7a0 ; unique
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140dad810 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@QEAA@XZ 0x140dad820 ; prop
// MS2-PIN: ??0?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@QEAA@XZ 0x140dad8d0 ; prop
// MS2-PIN: ??0?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@QEAA@XZ 0x140dad900 ; prop
// MS2-PIN: ??1?$TSingleton@VGameEventUserValueManager@@@@UEAA@XZ 0x140dad960 ; prop
// MS2-PIN: ??1?$TSingleton@VPacketHandlerManager@@@@UEAA@XZ 0x140dad9a0 ; prop
// MS2-PIN: ?_Allocate@_Default_allocate_traits@std@@SAPEAX_K@Z 0x140dadbe0 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140dae630 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140dae6c0 ; unique
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140dae750 ; unique
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140dae7e0 ; prop
// MS2-PIN: ??F?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140dae800 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140dae840 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140dae860 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140dae8a0 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140dae970 ; prop
// MS2-PIN: ??F?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140daea40 ; unique
// MS2-PIN: ??_G?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAAPEAXI@Z 0x140daee10 ; unique
// MS2-PIN: ??_G?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@QEAAPEAXI@Z 0x140daee50 ; unique
// MS2-PIN: ??_G?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAAPEAXI@Z 0x140daee90 ; unique
// MS2-PIN: ??_G?$TSingleton@VGameEventUserValueManager@@@@UEAAPEAXI@Z 0x140daeed0 ; prop
// MS2-PIN: ??_G?$TSingleton@VPacketHandlerManager@@@@UEAAPEAXI@Z 0x140daef50 ; prop
// MS2-PIN: ??_GCWin32Heap@ATL@@UEAAPEAXI@Z 0x140daf090 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x140dafad0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x140dafb10 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x140db1400 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x140db1410 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@V?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@2@XZ 0x140db1420 ; unique
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@QEBAAEBV?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@2@XZ 0x140db17c0 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@2@@Z 0x140db1990 ; unique
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@2@@Z 0x140db19c0 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@2@@Z 0x140db1a20 ; prop
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@2@@Z 0x140db1a40 ; prop
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@2@PEAU32@@Z 0x140db1d50 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@2@PEAU32@@Z 0x140db1d80 ; unique
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@2@PEAU32@@Z 0x140db1db0 ; prop
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@2@PEAU32@@Z 0x140db1de0 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@2@PEAU32@@Z 0x140db1e10 ; unique
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@2@PEAU32@@Z 0x140db1e40 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@2@_K@Z 0x140db31f0 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@2@_K@Z 0x140db3220 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@2@@Z 0x140db3d30 ; unique
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@@std@@SA_KAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@2@@Z 0x140db3d40 ; unique
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/gameeventuservaluemanager.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/ugcmanager.h"

// ---- Delegate comparison / invocation (the out-of-line COMDATs of the three handler signatures) ----------------------

// @0x140dae000
template<> bool Delegate<void(CInPacket&)>::operator==(const Delegate& o) const
{
    if (m_pImpl == 0 && o.m_pImpl == 0)
        return true;
    if (m_pImpl == 0 || o.m_pImpl == 0)
        return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}

// @0x140dae070
template<> bool Delegate<void(GameEventVariable*)>::operator==(const Delegate& o) const
{
    if (m_pImpl == 0 && o.m_pImpl == 0)
        return true;
    if (m_pImpl == 0 || o.m_pImpl == 0)
        return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}

// @0x140dae0e0
template<> bool Delegate<void(NotifyObject*)>::operator==(const Delegate& o) const
{
    if (m_pImpl == 0 && o.m_pImpl == 0)
        return true;
    if (m_pImpl == 0 || o.m_pImpl == 0)
        return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}

void FUN_140657820();                                           // invalid call of an empty Delegate (shared)

// @0x140daec00
template<> void Delegate<void(CInPacket&)>::operator()(CInPacket& a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

// @0x140daec40
template<> void Delegate<void(GameEventVariable*)>::operator()(GameEventVariable* a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

// @0x140daec80
template<> void Delegate<void(NotifyObject*)>::operator()(NotifyObject* a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

// ---- NotifySystem's map (?\notifysystem.cpp owns the members, 0x140da4e40 / 0x140da4eb0 / 0x140da4fe0) -------------------

typedef std::vector<Delegate<void(NotifyObject*)> > Unk_NotifyHandlerList;
typedef std::map<CStringW, Unk_NotifyHandlerList> Unk_NotifyMap;

// Instantiates the NotifySystem map glue that the exe places in this range (the member functions live in another unit).
void Unk_NotifyMapAnchor(Unk_NotifyMap& map, CStringW strName, Delegate<void(NotifyObject*)> handler, NotifyObject* pNotify)
{
    map[strName].push_back(handler);
    Unk_NotifyHandlerList& list = map[strName];
    for (unsigned i = 0; i < list.size(); ++i)
    {
        if (list[i] == handler)
        {
            list.erase(list.begin() + i);
            return;
        }
    }
    Unk_NotifyHandlerList& all = map[pNotify->vfunc_1()];
    for (unsigned i = 0; i < all.size(); ++i)
        all[i](pNotify);
}

// ---- PacketHandlerManager ---------------------------------------------------------------------------------------------

// @0x140da50e0
PacketHandlerManager::PacketHandlerManager() {}

// @0x140da5130
PacketHandlerManager::~PacketHandlerManager()
{
    m_handlers.clear();
}

// @0x140da5180
void PacketHandlerManager::RegisterHandler(int nOpcode, Delegate<void(CInPacket&)> handler)
{
    std::vector<Delegate<void(CInPacket&)> >& list = m_handlers[nOpcode];
    list.push_back(handler);
}

// @0x140da51e0
void PacketHandlerManager::UnregisterHandler(int nOpcode, Delegate<void(CInPacket&)> handler)
{
    std::vector<Delegate<void(CInPacket&)> >& list = m_handlers[nOpcode];
    for (unsigned i = 0; i < list.size(); ++i)
    {
        if (list[i] == handler)
        {
            list.erase(list.begin() + i);
            return;
        }
    }
}

// @0x140da52f0
void PacketHandlerManager::Dispatch(int nOpcode, CInPacket& iPacket)
{
    std::vector<Delegate<void(CInPacket&)> >& list = m_handlers[nOpcode];
    for (unsigned i = 0; i < list.size(); ++i)
    {
        iPacket.FUN_14070fe80();
        list[i](iPacket);
    }
}

// ---- GameEventUserValueManager ----------------------------------------------------------------------------------------

// @0x140da5390
GameEventUserValueManager::GameEventUserValueManager() {}

// @0x140da53e0
GameEventUserValueManager::~GameEventUserValueManager()
{
    m_listeners.clear();
}

// @0x140da5430
void GameEventUserValueManager::RegisterListener(int nEvent, Delegate<void(GameEventVariable*)> listener)
{
    std::vector<Delegate<void(GameEventVariable*)> >& list = m_listeners[nEvent];
    list.push_back(listener);
}

// @0x140da5490
void GameEventUserValueManager::UnregisterListener(int nEvent, Delegate<void(GameEventVariable*)> listener)
{
    std::vector<Delegate<void(GameEventVariable*)> >& list = m_listeners[nEvent];
    for (unsigned i = 0; i < list.size(); ++i)
    {
        if (list[i] == listener)
        {
            list.erase(list.begin() + i);
            return;
        }
    }
}

// @0x140da55a0
void GameEventUserValueManager::Dispatch(int nEvent, GameEventVariable* pVariable)
{
    std::vector<Delegate<void(GameEventVariable*)> >& list = m_listeners[nEvent];
    for (unsigned i = 0; i < list.size(); ++i)
        list[i](pVariable);
}

// ---- Notify* names (the inline vfunc_1 COMDATs of the notice classes, emitted here) -----------------------------------------
// The classes are declared by their users; only the name virtual is defined here, so these stand-ins carry no members.
class NotifyLearnEmotion : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyPcBang : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyGameStart : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyChangeServer : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyChangeMyJob : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyChangeMyLevel : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyRemoveGameObject : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyCutSceneCinematicSkip : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyCreateMyPC : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyChangeMyPC : public NotifyObject { public: virtual CStringW vfunc_1(); };
class NotifyChangedTokenMoney : public NotifyObject { public: virtual CStringW vfunc_1(); };

// @0x140db40d0
CStringW NotifyObject::vfunc_1()
{
    return L"NotifyObject";
}

// @0x140db4130
CStringW NotifyGameEventChanged::vfunc_1()
{
    return L"NotifyGameEventChanged";
}

// @0x140db4190
CStringW NotifyLearnEmotion::vfunc_1()
{
    return L"NotifyLearnEmotion";
}

// @0x140db41f0
CStringW NotifyPcBang::vfunc_1()
{
    return L"NotifyPcBang";
}

// @0x140db4250
CStringW NotifyUgcDownloadComplete::vfunc_1()
{
    return L"NotifyUgcDownloadComplete";
}

// @0x140db42b0
CStringW NotifyGameStart::vfunc_1()
{
    return L"NotifyGameStart";
}

// @0x140db4310
CStringW NotifyChangeServer::vfunc_1()
{
    return L"NotifyChangeServer";
}

// @0x140db4370
CStringW NotifyChangeMyJob::vfunc_1()
{
    return L"NotifyChangeMyJob";
}

// @0x140db43d0
CStringW NotifyChangeMyLevel::vfunc_1()
{
    return L"NotifyChangeMyLevel";
}

// @0x140db4430
CStringW NotifyRemoveGameObject::vfunc_1()
{
    return L"NotifyRemoveGameObject";
}

// @0x140db4490
CStringW NotifyCutSceneCinematicSkip::vfunc_1()
{
    return L"NotifyCutSceneCinematicSkip";
}

// @0x140db44f0
CStringW NotifyCreateMyPC::vfunc_1()
{
    return L"NotifyCreateMyPC";
}

// @0x140db4550
CStringW NotifyCompleteMyPC::vfunc_1()
{
    return L"NotifyCompleteMyPC";
}

// @0x140db45b0
CStringW NotifyChangeMyPC::vfunc_1()
{
    return L"NotifyChangeMyPC";
}

// @0x140db4610
CStringW NotifyChangedTokenMoney::vfunc_1()
{
    return L"NotifyChangedTokenMoney";
}

// @0x140db4670
CStringW NotifyUseSKill::vfunc_1()
{
    return L"NotifyUseSKill";
}

