// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CubeMapInformationService container COMDAT tail, the
// `_Myend` .. `max_size` slice: the std/efd map, set and vector glue of the service's ~35 member trees and of the
// local containers of cubemapinformationservice.cpp, plus the MS2Ptr Release helpers of its CPtred records.
// Queue name unit_141148d70. The range holds no original (non-COMDAT) function: it is part of the mangled-name sorted
// COMDAT tail of client\ms2\cubemapinformationservice.cpp (0x1410d5bc0-0x14115b040, split into unnamed units by the
// unit map). The CU's own code lives in cubemapinformationservice_1/2/3.cpp, which call these instances through FUN_
// externs, so the container operations are driven from the functions at the end of this file.
// Key/value types: from the node sizes (allocate/deallocate), the value offset in the node, the comparators and the
// destroy chains of each family; record class names from RTTI (SalesInfo, SaleStateData, SetItemEffectInfo,
// AutomaticCreateCubeInfo, UICubeUGCHead), the others invented.
// MS2-UNIT: unit_141148d70
// MS2-RANGE: 0x141148d70-0x141159a60 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x141148db0 ; probe
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@QEAAAEAPEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141148df0 ; probe
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@@std@@QEAAAEAPEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141148e30 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@@std@@QEBAAEBQEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141148e50 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@@std@@QEAAAEAPEAUUnk_CMISElem52@@XZ 0x141148e70 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@@std@@QEAAAEAPEAVEntityID@egf@@XZ 0x141148eb0 ; probe
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x141148ed0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@@std@@QEAAAEAPEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141148fb0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@@std@@QEBAAEBQEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141148fd0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@@std@@QEAAAEAPEAUUnk_CMISElem52@@XZ 0x141148ff0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x141149050 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@HV?$CustomAllocator@H@efd@@@std@@@std@@QEAAAEAPEAHXZ 0x141149070 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@@std@@QEAAAEAPEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141149130 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@@std@@QEAAAEAPEAUUnk_CMISElem52@@XZ 0x141149170 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@@std@@QEAAXXZ 0x141149250 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@@std@@QEAAXXZ 0x141149270 ; prop
// MS2-PIN: ?max_size@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEBA_KXZ 0x141149290 ; order
// MS2-PIN: ?_Orphan_range@?$vector@HV?$CustomAllocator@H@efd@@@std@@AEBAXPEAH0@Z 0x1411492b0 ; probe
// MS2-PIN: ?_Orphan_range@?$vector@HV?$allocator@H@std@@@std@@AEBAXPEAH0@Z 0x1411492c0 ; probe
// MS2-PIN: ?_Orphan_range@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@AEBAXPEAV?$SmartPointer@VEntity@egf@@@efd@@0@Z 0x1411492d0 ; probe
// MS2-PIN: ?_Orphan_range@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@AEBAXPEAV?$SmartPointer@VEntity@egf@@@efd@@0@Z 0x1411492e0 ; probe
// MS2-PIN: ?_Orphan_range@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@AEBAXPEAVEntityID@egf@@0@Z 0x1411492f0 ; probe
// MS2-PIN: ?_Orphan_range@?$vector@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@AEBAXPEAUUnk_CMISElem52@@0@Z 0x141149300 ; probe
// MS2-PIN: ?Release@?$MS2Ptr@VAutomaticCreateCubeInfo@@@@AEAAXXZ 0x141149320 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VCFunctionCubeObject@@@@AEAAXXZ 0x141149360 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VCube@@@@AEAAXXZ 0x1411493a0 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VFittingDollData@@@@AEAAXXZ 0x1411493e0 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VSalesInfo@@@@AEAAXXZ 0x141149460 ; order
// MS2-PIN: ?Release@?$MS2Ptr@VUIHouseMarkEntity@@@@AEAAXXZ 0x1411494a0 ; order
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAHV?$CustomAllocator@H@efd@@@std@@QEAAPEAHXZ 0x1411494e0 ; probe
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAAPEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141149500 ; probe
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAV?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@QEAAPEAV?$SmartPointer@VEntity@egf@@@efd@@XZ 0x141149520 ; probe
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAVEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAAPEAVEntityID@egf@@XZ 0x141149540 ; probe
// MS2-PIN: ?_Release@?$_Uninitialized_backout_al@PEAUUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@QEAAPEAUUnk_CMISElem52@@XZ 0x141149560 ; probe
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VAutomaticCreateCubeInfo@@@@AEAAXPEAX@Z 0x141149580 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCFunctionCubeObject@@@@AEAAXPEAX@Z 0x1411495d0 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCube@@@@AEAAXPEAX@Z 0x141149620 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VFittingDollData@@@@AEAAXPEAX@Z 0x141149670 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VSaleStateData@@@@AEAAXPEAX@Z 0x1411496c0 ; order
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUIHouseMarkEntity@@@@AEAAXPEAX@Z 0x141149760 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@2@XZ 0x1411497d0 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@XZ 0x141149870 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@2@XZ 0x1411498b0 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@2@XZ 0x141149910 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@2@XZ 0x141149930 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@2@XZ 0x141149950 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@XZ 0x141149970 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@XZ 0x141149990 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@2@XZ 0x1411499b0 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@XZ 0x1411499d0 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@XZ 0x1411499f0 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@2@XZ 0x141149a10 ; order
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@2@XZ 0x141149a30 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@2@XZ 0x141149b10 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@XZ 0x141149bb0 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@2@XZ 0x141149bf0 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@2@XZ 0x141149c10 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@XZ 0x141149c30 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@2@XZ 0x141149c50 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@2@XZ 0x141149c90 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@XZ 0x141149cb0 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@XZ 0x141149cd0 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@2@XZ 0x141149cf0 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@XZ 0x141149d10 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@XZ 0x141149d30 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@2@XZ 0x141149d50 ; order
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@2@XZ 0x141149d70 ; order
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x141149e30 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x141149f10 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@@Z 0x141149ff0 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@2@@Z 0x14114a0d0 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@2@@Z 0x14114a1b0 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@2@@Z 0x14114a290 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@PEAX@2@@Z 0x14114a370 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@@Z 0x14114a450 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@2@@Z 0x14114a530 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@2@@Z 0x14114a610 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@2@@Z 0x14114a6f0 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@2@@Z 0x14114a7d0 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@2@@Z 0x14114aa70 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x14114ab50 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@@Z 0x14114ac30 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@2@@Z 0x14114ad10 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@@Z 0x14114adf0 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@2@@Z 0x14114aed0 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@@Z 0x14114afb0 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@2@@Z 0x14114b090 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@HH@std@@PEAX@2@@Z 0x14114b170 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@2@@Z 0x14114b250 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@@std@@QEAAXPEAU?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@2@@Z 0x14114b330 ; probe
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@QEAAXPEAU?$_Tree_node@VEntityID@egf@@PEAX@2@@Z 0x14114b410 ; probe
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114b550 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x14114b610 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114b730 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x14114b7f0 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114b850 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114b8b0 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x14114b910 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x14114b970 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@U?$less@H@2@V?$CustomAllocator@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114b9d0 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x14114ba90 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114baf0 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114bbb0 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114bc10 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x14114bc70 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114bcd0 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114bd30 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114bd90 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114be50 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114c030 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114c140 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x14114c190 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@V?$CustomAllocator@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114c1e0 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@$0A@@std@@@std@@IEAAXXZ 0x14114c230 ; prop
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@IEAAXXZ 0x14114c280 ; prop
// MS2-PIN: ?_Tidy@?$vector@HV?$CustomAllocator@H@efd@@@std@@AEAAXXZ 0x14114c2d0 ; prop
// MS2-PIN: ?_Tidy@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@AEAAXXZ 0x14114c470 ; prop
// MS2-PIN: ?_Tidy@?$vector@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@AEAAXXZ 0x14114c540 ; prop
// MS2-PIN: ?_Umove@?$vector@HV?$CustomAllocator@H@efd@@@std@@AEAAPEAHPEAH00@Z 0x14114c6e0 ; probe
// MS2-PIN: ?_Umove@?$vector@HV?$allocator@H@std@@@std@@AEAAPEAHPEAH00@Z 0x14114c720 ; probe
// MS2-PIN: ?_Umove@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@AEAAPEAV?$SmartPointer@VEntity@egf@@@efd@@PEAV34@00@Z 0x14114c760 ; probe
// MS2-PIN: ?_Umove@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@AEAAPEAV?$SmartPointer@VEntity@egf@@@efd@@PEAV34@00@Z 0x14114c7a0 ; probe
// MS2-PIN: ?_Umove@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@AEAAPEAVEntityID@egf@@PEAV34@00@Z 0x14114c7e0 ; probe
// MS2-PIN: ?_Umove@?$vector@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@AEAAPEAUUnk_CMISElem52@@PEAU3@00@Z 0x14114c820 ; probe
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@HV?$CustomAllocator@H@efd@@@std@@AEAAXPEAH00U?$integral_constant@_N$00@2@@Z 0x14114c8a0 ; probe
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH00U?$integral_constant@_N$00@2@@Z 0x14114c8e0 ; probe
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@AEAAXPEAV?$SmartPointer@VEntity@egf@@@efd@@00U?$integral_constant@_N$0A@@2@@Z 0x14114c920 ; probe
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@AEAAXPEAV?$SmartPointer@VEntity@egf@@@efd@@00U?$integral_constant@_N$0A@@2@@Z 0x14114c960 ; probe
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@AEAAXPEAVEntityID@egf@@00U?$integral_constant@_N$0A@@2@@Z 0x14114c9a0 ; probe
// MS2-PIN: ?_Umove_if_noexcept1@?$vector@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@AEAAXPEAUUnk_CMISElem52@@00U?$integral_constant@_N$00@2@@Z 0x14114c9e0 ; probe
// MS2-PIN: ?_Umove_if_noexcept@?$vector@HV?$CustomAllocator@H@efd@@@std@@AEAAXPEAH00@Z 0x14114ca60 ; probe
// MS2-PIN: ?_Umove_if_noexcept@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH00@Z 0x14114cac0 ; probe
// MS2-PIN: ?_Umove_if_noexcept@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@AEAAXPEAV?$SmartPointer@VEntity@egf@@@efd@@00@Z 0x14114cb20 ; probe
// MS2-PIN: ?_Umove_if_noexcept@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@AEAAXPEAV?$SmartPointer@VEntity@egf@@@efd@@00@Z 0x14114cb80 ; probe
// MS2-PIN: ?_Umove_if_noexcept@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@AEAAXPEAVEntityID@egf@@00@Z 0x14114cbe0 ; probe
// MS2-PIN: ?_Umove_if_noexcept@?$vector@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@AEAAXPEAUUnk_CMISElem52@@00@Z 0x14114cc40 ; probe
// MS2-PIN: ?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ 0x14114cd30 ; order
// MS2-PIN: ?_Xlength@?$vector@HV?$CustomAllocator@H@efd@@@std@@CAXXZ 0x14114cd50 ; order
// MS2-PIN: ?_Xlength@?$vector@HV?$allocator@H@std@@@std@@CAXXZ 0x14114cd70 ; order
// MS2-PIN: ?_Xlength@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@CAXXZ 0x14114cd90 ; order
// MS2-PIN: ?_Xlength@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@CAXXZ 0x14114cdb0 ; order
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@_KPEBX@Z 0x14114cf80 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@_KPEBX@Z 0x14114cfd0 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@std@@_KPEBX@Z 0x14114d020 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@_KPEBX@Z 0x14114d070 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@_KPEBX@Z 0x14114d0c0 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@_KPEBX@Z 0x14114d110 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@_KPEBX@Z 0x14114d1b0 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@_KPEBX@Z 0x14114d250 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@_KPEBX@Z 0x14114d2a0 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@_KPEBX@Z 0x14114d2f0 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@_KPEBX@Z 0x14114d340 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@std@@_KPEBX@Z 0x14114d390 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@_KPEBX@Z 0x14114d3e0 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@_KPEBX@Z 0x14114d430 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@_KPEBX@Z 0x14114d480 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@U?$pair@HH@std@@PEAX@std@@_KPEBX@Z 0x14114d4d0 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@VEntityID@egf@@PEAX@std@@_KPEBX@Z 0x14114d520 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@U?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@@efd@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@_KPEBX@Z 0x14114d610 ; probe
// MS2-PIN: ?allocate@?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@QEAAPEAV?$SmartPointer@VEntity@egf@@@2@_KPEBX@Z 0x14114d6b0 ; order
// MS2-PIN: ?allocate@?$CustomAllocator@VEntityID@egf@@@efd@@QEAAPEAVEntityID@egf@@_KPEBX@Z 0x14114d700 ; order
// MS2-PIN: ?allocate@?$allocator@D@std@@QEAAPEAD_K@Z 0x14114d7a0 ; order
// MS2-PIN: ?allocate@?$allocator@H@std@@QEAAPEAH_K@Z 0x14114d7d0 ; order
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@HPEAX@std@@@std@@QEAAPEAU?$_Tree_node@HPEAX@2@_K@Z 0x14114d800 ; order
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@2@_K@Z 0x14114d860 ; order
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@PEAX@2@_K@Z 0x14114d890 ; order
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@2@_K@Z 0x14114d8c0 ; order
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@_K@Z 0x14114d8f0 ; order
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@HH@std@@PEAX@2@_K@Z 0x14114d920 ; order
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@2@_K@Z 0x14114d950 ; order
// MS2-PIN: ?allocate@?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@QEAAPEAV?$SmartPointer@VEntity@egf@@@efd@@_K@Z 0x14114d980 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@XZ 0x14114d9f0 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@XZ 0x14114dad0 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@XZ 0x14114dc20 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@XZ 0x14114dd00 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@2@XZ 0x14114dde0 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@2@XZ 0x14114de50 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@XZ 0x14114dfa0 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@XZ 0x14114e080 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@XZ 0x14114e0f0 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@XZ 0x14114e160 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@XZ 0x14114e1d0 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@XZ 0x14114e240 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@XZ 0x14114e2b0 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@XZ 0x14114e320 ; order
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@XZ 0x14114e400 ; order
// MS2-PIN: ?begin@?$vector@HV?$CustomAllocator@H@efd@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@2@XZ 0x14114e8d0 ; prop
// MS2-PIN: ?begin@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@2@XZ 0x14114e9f0 ; order
// MS2-PIN: ?capacity@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEBA_KXZ 0x14114eb10 ; prop
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114ebe0 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14114ed20 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14114f040 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114f180 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x14114f220 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14114f400 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114f4a0 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114f5e0 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114f680 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x14114f720 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114f7c0 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114f860 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114f900 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114f9a0 ; order
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAAXXZ 0x14114fa40 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@_K@Z 0x1411505c0 ; probe
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@_K@Z 0x141150610 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@std@@_K@Z 0x141150660 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@_K@Z 0x1411506b0 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@_K@Z 0x141150700 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@_K@Z 0x141150750 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@_K@Z 0x1411507f0 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@_K@Z 0x141150890 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@_K@Z 0x1411508e0 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@_K@Z 0x141150930 ; probe
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@_K@Z 0x141150980 ; probe
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@std@@_K@Z 0x1411509d0 ; probe
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@_K@Z 0x141150a20 ; probe
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@_K@Z 0x141150a70 ; probe
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@U?$pair@HH@std@@PEAX@std@@_K@Z 0x141150b60 ; probe
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@VEntityID@egf@@PEAX@std@@_K@Z 0x141150c00 ; probe
// MS2-PIN: ?deallocate@?$CustomAllocator@U?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@@efd@@QEAAXPEAU?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@_K@Z 0x141150c50 ; order
// MS2-PIN: ?deallocate@?$CustomAllocator@VEntityID@egf@@@efd@@QEAAXPEAVEntityID@egf@@_K@Z 0x141150cf0 ; prop
// MS2-PIN: ?deallocate@?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@QEAAXPEAV?$SmartPointer@VEntity@egf@@@2@_K@Z 0x141150d40 ; prop
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@2@_K@Z 0x141150de0 ; order
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@_K@Z 0x141150e10 ; order
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@PEAX@2@_K@Z 0x141150e70 ; order
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@_K@Z 0x141150ea0 ; order
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@2@_K@Z 0x141150ed0 ; order
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@HH@std@@PEAX@2@_K@Z 0x141150f00 ; order
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@std@@@2@QEAU?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@2@_K@Z 0x141150f30 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@HPEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@HPEAX@std@@@efd@@PEAU?$_Tree_node@HPEAX@2@_K@Z 0x141150f60 ; prop
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@_K@Z 0x141150f90 ; prop
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@PEAX@2@_K@Z 0x141150fc0 ; prop
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_CMISCell@@@std@@PEAX@2@_K@Z 0x141150ff0 ; prop
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@2@_K@Z 0x141151020 ; probe
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@_K@Z 0x141151050 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@2@_K@Z 0x141151080 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@2@_K@Z 0x1411510b0 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@2@_K@Z 0x1411510e0 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@2@_K@Z 0x141151110 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@PEAX@2@_K@Z 0x141151140 ; prop
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@2@_K@Z 0x141151170 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@PEAX@2@_K@Z 0x1411511a0 ; prop
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@2@_K@Z 0x1411511d0 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@_K@Z 0x141151200 ; order
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@2@_K@Z 0x141151230 ; probe
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@2@_K@Z 0x141151260 ; probe
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@2@_K@Z 0x141151290 ; probe
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@2@_K@Z 0x1411512c0 ; probe
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@2@_K@Z 0x1411512f0 ; probe
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@efd@@PEAU?$_Tree_node@U?$pair@HH@std@@PEAX@2@_K@Z 0x141151380 ; probe
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@PEAU?$_Tree_node@VEntityID@egf@@PEAX@2@_K@Z 0x1411513e0 ; probe
// MS2-PIN: ?deallocate@?$_Normal_allocator_traits@V?$CustomAllocator@U?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@@efd@@@std@@SAXAEAV?$CustomAllocator@U?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@@efd@@PEAU?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@2@_K@Z 0x141151410 ; order
// MS2-PIN: ?move@?$char_traits@D@std@@SAPEADQEADQEBD_K@Z 0x141151440 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHUUnk_Int3@@@std@@PEAX@2@_K@Z 0x1411514a0 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@2@_K@Z 0x1411514d0 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@PEAX@2@_K@Z 0x141151500 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@PEAX@2@_K@Z 0x141151560 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@2@_K@Z 0x141151590 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@HH@std@@PEAX@2@_K@Z 0x1411515c0 ; order
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@V?$MS2Ptr@VCFunctionCubeObject@@@@PEAX@2@_K@Z 0x1411515f0 ; order
// MS2-PIN: ?destroy@?$CustomAllocator@H@efd@@QEAAXPEAH@Z 0x141151680 ; order
// MS2-PIN: ?empty@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@QEBA_NXZ 0x1411516e0 ; order
// MS2-PIN: ?empty@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEBA_NXZ 0x141151760 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@XZ 0x1411517f0 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@XZ 0x1411518b0 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@XZ 0x141151a90 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@2@XZ 0x141151b50 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@2@XZ 0x141151bb0 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@XZ 0x141151cd0 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@std@@@2@XZ 0x141151d30 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@XZ 0x141151d90 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@XZ 0x141151df0 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@XZ 0x141151e50 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@XZ 0x141151f10 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@XZ 0x141151f70 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@XZ 0x141151fd0 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@XZ 0x141152030 ; order
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@XZ 0x1411520f0 ; order
// MS2-PIN: ?end@?$vector@HV?$CustomAllocator@H@efd@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@2@XZ 0x141152510 ; order
// MS2-PIN: ?end@?$vector@HV?$allocator@H@std@@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@H@std@@@std@@@2@XZ 0x141152570 ; order
// MS2-PIN: ?end@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAA?AV?$_Vector_iterator@V?$_Vector_val@U?$_Simple_types@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@2@XZ 0x141152630 ; order
// MS2-PIN: ??$try_emplace@$$V@?$map@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x141152690 ; probe
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@V12@@2@AEBH@Z 0x141152790 ; order
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@std@@@std@@@std@@V12@@2@AEBH@Z 0x141152810 ; order
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@std@@@std@@@std@@V12@@2@AEBH@Z 0x141152850 ; order
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@std@@V12@@2@AEBH@Z 0x141152890 ; order
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@std@@V12@@2@AEBU?$pair@HH@2@@Z 0x1411528d0 ; order
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@V12@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x141152910 ; order
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@std@@V12@@2@AEBVEntityID@egf@@@Z 0x141152950 ; order
// MS2-PIN: ?equal_range@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@@std@@V12@@2@AEBVEntityID@egf@@@Z 0x141152990 ; probe
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@0@Z 0x141152c30 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@@Z 0x141152d20 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA_KAEBH@Z 0x141152dd0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@0@Z 0x141153050 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@@Z 0x141153140 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA_KAEBH@Z 0x1411531f0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@0@Z 0x1411535a0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@@Z 0x141153690 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA_KAEBH@Z 0x141153740 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@0@Z 0x141153950 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@@Z 0x141153a40 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VFittingDollData@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@@std@@@std@@@2@0@Z 0x141153b60 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAA_KAEBH@Z 0x141153d00 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@2@@Z 0x141153e60 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VUICubeUGCHead@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VUICubeUGCHead@@@@@std@@@3@$0A@@std@@@std@@QEAA_KAEBH@Z 0x141153f10 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@2@0@Z 0x141153f80 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@2@@Z 0x141154070 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@0@Z 0x141154460 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@@Z 0x141154550 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HUUnk_CMISMarkRec@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISMarkRec@@@std@@@efd@@$0A@@std@@@std@@QEAA_KAEBH@Z 0x1411547a0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@0@Z 0x141154810 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@@Z 0x141154900 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@0@Z 0x141154a20 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@@Z 0x141154b10 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@0@Z 0x141154bc0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@@Z 0x141154cb0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@0@Z 0x141154d60 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@@Z 0x141154e50 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@0@Z 0x141154f00 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@@Z 0x141154ff0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA_KAEBU?$pair@HH@2@@Z 0x1411550a0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@0@Z 0x141155110 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@@Z 0x141155200 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA_KAEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x1411552b0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@0@Z 0x141155320 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@@Z 0x141155410 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA_KAEBVEntityID@egf@@@Z 0x1411554c0 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@@2@@Z 0x141155620 ; probe
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@QEAA_KAEBVEntityID@egf@@@Z 0x1411556d0 ; probe
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@0@Z 0x141155740 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@@Z 0x141155830 ; order
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@V?$CustomAllocator@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@std@@@2@V32@@Z 0x1411569b0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@@std@@@2@V32@@Z 0x141156b50 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@2@V32@@Z 0x141156cf0 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@AEBH@Z 0x141156da0 ; probe
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@AEBH@Z 0x141156f60 ; probe
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@AEBH@Z 0x1411574a0 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@2@AEBH@Z 0x141157660 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSalesInfo@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSalesInfo@@@@@std@@@std@@@std@@@2@AEBH@Z 0x141157740 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$SmartPointer@VEntity@egf@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@@std@@@2@AEBH@Z 0x141157820 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@AEBH@Z 0x1411579e0 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@std@@@2@AEBH@Z 0x141157ac0 ; probe
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@AEBH@Z 0x141157ba0 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@AEBI@Z 0x141157c80 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@AEBI@Z 0x141157e40 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@AEBU?$pair@HH@2@@Z 0x141157f20 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x141158000 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x1411580e0 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x1411581c0 ; order
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@@2@AEBU?$pair@HH@2@@Z 0x141158700 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@@2@AEBU?$pair@HH@2@@Z 0x1411587e0 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@@std@@@2@AEBV?$MS2Ptr@VCFunctionCubeObject@@@@@Z 0x1411588c0 ; prop
// MS2-PIN: ?find@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x1411589a0 ; prop
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@AEBH@Z 0x141158bb0 ; probe
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCell@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCell@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCell@@@std@@@std@@@std@@@2@AEBH@Z 0x141158c10 ; probe
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@2@AEBH@Z 0x141158c70 ; probe
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HW4Unk_CMISKindA@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@@std@@@std@@@2@AEBH@Z 0x141158cd0 ; probe
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@U?$less@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@V?$CustomAllocator@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@std@@@std@@@2@AEBV?$MS2Ptr@VAutomaticCreateCubeInfo@@@@@Z 0x141158df0 ; probe
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@AEBH@Z 0x141158e50 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$MS2Ptr@VSetItemEffectInfo@@@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@@std@@@std@@@2@AEBH@Z 0x141158f10 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$map@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x141159030 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$vector@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@@std@@@std@@@2@AEBH@Z 0x141159090 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HUUnk_CMISCubeTimer@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_CMISCubeTimer@@@std@@@std@@@std@@@2@AEBH@Z 0x1411590f0 ; probe
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HVEntityID@egf@@U?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHVEntityID@egf@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHVEntityID@egf@@@std@@@std@@@std@@@2@AEBH@Z 0x141159150 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IHU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBIH@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIH@std@@@std@@@std@@@2@AEBI@Z 0x1411591b0 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$CustomAllocator@U?$pair@$$CBII@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@AEBI@Z 0x141159210 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@@std@@@std@@@std@@@2@AEBI@Z 0x1411592d0 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@U?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@@std@@@std@@@2@AEBU?$pair@HH@2@@Z 0x141159330 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@HU?$less@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@V?$CustomAllocator@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@2@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z 0x141159390 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@_JU?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@_J@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@_J@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x1411593f0 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@V?$MS2Ptr@VCube@@@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x1411594b0 ; order
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@W4Unk_CMISKindA@@HU?$less@W4Unk_CMISKindA@@@std@@V?$CustomAllocator@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@@2@AEBW4Unk_CMISKindA@@@Z 0x141159510 ; probe
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$CustomAllocator@U?$pair@HH@std@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@@2@AEBU?$pair@HH@2@@Z 0x1411596f0 ; prop
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@std@@@2@AEBU?$pair@HH@2@@Z 0x141159750 ; prop
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@V?$MS2Ptr@VCFunctionCubeObject@@@@U?$less@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@V?$allocator@V?$MS2Ptr@VCFunctionCubeObject@@@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@V?$MS2Ptr@VCFunctionCubeObject@@@@@std@@@std@@@2@AEBV?$MS2Ptr@VCFunctionCubeObject@@@@@Z 0x1411597b0 ; prop
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tset_traits@VEntityID@egf@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@VEntityID@egf@@@efd@@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@VEntityID@egf@@@std@@@std@@@2@AEBVEntityID@egf@@@Z 0x141159810 ; prop
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$SmartPointer@VEntity@egf@@@efd@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x1411598c0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x1411598d0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VFittingDollData@@@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x1411598e0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$MS2Ptr@VSetItemEffectInfo@@@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x1411598f0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$map@HV?$MS2Ptr@VCube@@@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@3@@std@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159900 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHV?$set@HU?$less@H@std@@@efd@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159910 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHVEntityID@egf@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159930 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBHW4Unk_CMISKindA@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159950 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBIH@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159960 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBU?$pair@HH@std@@V?$MS2Ptr@VSaleStateData@@@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159970 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159980 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159990 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@_J@std@@PEAX@std@@@efd@@QEBA_KXZ 0x1411599a0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBVEntityID@egf@@V?$MS2Ptr@VCube@@@@@std@@PEAX@std@@@efd@@QEBA_KXZ 0x1411599b0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@efd@@QEBA_KXZ 0x1411599c0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@VEntityID@egf@@PEAX@std@@@efd@@QEBA_KXZ 0x1411599d0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@PEAX@std@@@efd@@QEBA_KXZ 0x1411599e0 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@E@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159a00 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@V?$MS2Ptr@VAutomaticCreateCubeInfo@@@@PEAX@std@@@efd@@QEBA_KXZ 0x141159a10 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@U?$_Tree_node@U?$pair@$$CBW4Unk_CMISKindB@@H@std@@PEAX@std@@@efd@@QEBA_KXZ 0x141159a20 ; probe
// MS2-PIN: ?max_size@?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@QEBA_KXZ 0x141159a30 ; order
// MS2-PIN: ?max_size@?$CustomAllocator@VEntityID@egf@@@efd@@QEBA_KXZ 0x141159a40 ; order
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <set>
#include <vector>
#include <string>
#include <atlstr.h>
#include <efd/StdContainers.h>
#include <efd/utf8string.h>
#include <egf/EntityID.h>
#include <egf/Entity.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cube.h"
#include "ms2/client/ms2/uihousemark.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "hook/ms2hook.h"

// ---- record classes held by MS2Ptr (RTTI names; only the CPtred base matters here) --------------------------------------
class SalesInfo : public CPtred                         // house sale marker record (0x38, ctor 0x1411232e0)
{
public:
    SalesInfo();
    virtual ~SalesInfo();
};
class SetItemEffectInfo : public CPtred                 // ctor 0x1411233c0
{
public:
    SetItemEffectInfo();
    virtual ~SetItemEffectInfo();
};
class AutomaticCreateCubeInfo : public CPtred           // ctor 0x141122e70
{
public:
    AutomaticCreateCubeInfo();
    virtual ~AutomaticCreateCubeInfo();
};
class SaleStateData : public CPtred                     // sale state of a house (0x28, ctor 0x141123290)
{
public:
    SaleStateData();
    virtual ~SaleStateData();
};
class UICubeUGCHead : public CPtred                     // UGC cube head HUD (0x90, ctor 0x141906490)
{
public:
    virtual ~UICubeUGCHead();
};

// ---- unit-local value types (names invented) -------------------------------------------------------------------------
enum Unk_CMISKindA { Unk_CMISKindA_None };             // key of the 0x14112cb40 comparator family
enum Unk_CMISKindB { Unk_CMISKindB_None };             // key of the 0x14112cb80 comparator family

// mark record of a cube group: poll timer and the mark entities (node value of f288)
struct Unk_CMISMarkRec
{
    Timer m_timer;
    efd::vector<egf::EntityID> m_marks;
};
MS2_CHECK_SIZE(Unk_CMISMarkRec, 0x50);

// per-cell record with a UTF-8 name (node value of f2b8)
struct Unk_CMISCell
{
    efd::utf8string m_name;
    int m_a, m_b, m_c, m_d, m_e, m_f;
};
MS2_CHECK_SIZE(Unk_CMISCell, 0x38);

// cube timer record (node value of f1f8)
struct Unk_CMISCubeTimer
{
    Timer m_timer;
    __int64 m_a, m_b;
};
MS2_CHECK_SIZE(Unk_CMISCubeTimer, 0x48);

// 8-byte smart pointer to a PhysX prop object (dtor 0x140ae16b0; node value of f58)
class Unk_CMISPropPtr
{
public:
    Unk_CMISPropPtr();
    Unk_CMISPropPtr(const Unk_CMISPropPtr&);
    ~Unk_CMISPropPtr();
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_CMISPropPtr, 8);

// 0x34-byte POD element of an efd::vector
struct Unk_CMISElem52
{
    int m_v[13];
};
MS2_CHECK_SIZE(Unk_CMISElem52, 0x34);

// ---- the containers ----------------------------------------------------------------------------------------------------
typedef efd::map<int, unsigned int> Unk_CMISMapIntUInt;                                    // f338
typedef efd::map<int, Unk_CMISMarkRec> Unk_CMISMapMark;                                    // f288
typedef std::map<int, Unk_Int3> Unk_CMISMapNear;                                           // nearest cell per group
typedef efd::map<int, Unk_CMISCell> Unk_CMISMapCell;                                       // f2b8
typedef efd::map<int, egf::EntityPtr> Unk_CMISMapEntity;                                   // ff8
typedef efd::map<int, MS2Ptr<FittingDollData> > Unk_CMISMapDoll;                           // f118
typedef std::map<int, MS2Ptr<SalesInfo> > Unk_CMISMapSales;                                // f238
typedef efd::map<int, MS2Ptr<SetItemEffectInfo> > Unk_CMISMapSetEffect;                    // f348
typedef efd::map<int, MS2Ptr<Cube> > Unk_CMISMapCube;                                      // f88 f98 fb8
typedef std::map<int, MS2Ptr<UICubeUGCHead> > Unk_CMISMapHead;                             // f228
typedef std::set<int> Unk_CMISStdIntSet;
typedef std::map<unsigned int, Unk_CMISStdIntSet> Unk_CMISMapBucket;                       // set id -> cube keys
typedef std::map<int, Unk_CMISMapBucket> Unk_CMISMapBuckets;                               // f440
typedef std::map<int, MS2Ptr<Cube> > Unk_CMISStdMapCube;
typedef efd::map<int, Unk_CMISStdMapCube> Unk_CMISMapCubeGroups;                           // fc8
typedef efd::set<int> Unk_CMISIntSet;
typedef efd::map<int, Unk_CMISIntSet> Unk_CMISMapColumns;                                  // fd8
typedef efd::vector<egf::EntityPtr> Unk_CMISEntVec;
typedef efd::map<int, Unk_CMISEntVec> Unk_CMISMapEntVec;                                   // f1e8
typedef efd::map<int, egf::EntityID> Unk_CMISMapEntityId;                                  // f108 f2c8 f2e0
typedef efd::map<int, Unk_CMISCubeTimer> Unk_CMISMapCubeTimer;                             // f1f8
typedef efd::map<int, Unk_CMISKindA> Unk_CMISMapKind;                                      // f298
typedef efd::map<unsigned int, int> Unk_CMISMapUIntInt;
typedef efd::map<unsigned int, unsigned int> Unk_CMISMapUIntUInt;
typedef efd::map<std::pair<int, int>, MS2Ptr<SaleStateData> > Unk_CMISMapSaleState;       // fe8
typedef efd::map<CStringA, int> Unk_CMISMapName;                                           // f1a0 f358
typedef efd::map<egf::EntityID, __int64> Unk_CMISMapEntityVal;                             // f48
typedef efd::map<egf::EntityID, Unk_CMISPropPtr> Unk_CMISMapProp;                          // f58
typedef efd::map<egf::EntityID, MS2Ptr<Cube> > Unk_CMISMapEntityCube;                      // f78 fa8
typedef efd::map<Unk_CMISKindA, int> Unk_CMISMapKindCount;                                 // f3c8
typedef std::map<Unk_CMISKindA, int> Unk_CMISStdMapKindCount;                              // local counts
typedef efd::map<Unk_CMISKindB, int> Unk_CMISMapKindInt;                                   // f378
typedef efd::map<Unk_CMISKindB, unsigned char> Unk_CMISMapKindByte;                        // f368
typedef efd::set<std::pair<int, int> > Unk_CMISPairSet;
typedef std::set<std::pair<int, int> > Unk_CMISStdPairSet;                                 // exported columns
typedef efd::set<MS2Ptr<AutomaticCreateCubeInfo> > Unk_CMISAutoSet;                        // automatic cubes
typedef std::set<MS2Ptr<CFunctionCubeObject> > Unk_CMISFuncCubeSet;                        // f498
typedef efd::set<egf::EntityID> Unk_CMISEntityIdSet;                                       // f30 f68
typedef efd::vector<int> Unk_CMISIntVec;
typedef std::vector<egf::EntityPtr> Unk_CMISStdEntVec;
typedef efd::vector<egf::EntityID> Unk_CMISEntityIdVec;
typedef efd::vector<Unk_CMISElem52> Unk_CMISElem52Vec;
typedef std::vector<int> Unk_CMISStdIntVec;

// ---- drivers: the container operations the CU's code instantiates -----------------------------------------------------
template <class M> void Unk_CMISDriveMap(M& m, const typename M::key_type& k)
{
    M tmp;
    tmp[k];
    (void)m.begin();
    (void)m.end();
    (void)m.empty();
    (void)m.max_size();
    (void)m.find(k);
    (void)m.lower_bound(k);
    m.erase(m.begin());
    m.erase(m.begin(), m.end());
    m.clear();
}
template <class M> void Unk_CMISDriveMapKey(M& m, const typename M::key_type& k)
{
    Unk_CMISDriveMap(m, k);
    (void)m.equal_range(k);
    m.erase(k);
}
template <class S> void Unk_CMISDriveSet(S& s, const typename S::key_type& k)
{
    S tmp;
    tmp.insert(k);
    (void)s.begin();
    (void)s.end();
    (void)s.empty();
    (void)s.max_size();
    (void)s.find(k);
    (void)s.lower_bound(k);
    s.erase(s.begin());
    s.erase(s.begin(), s.end());
    s.clear();
}
template <class V> void Unk_CMISDriveVector(V& v, const typename V::value_type& x)
{
    V tmp;
    tmp.push_back(x);
    (void)v.begin();
    (void)v.end();
    (void)v.empty();
    (void)v.capacity();
    v.clear();
}

void Unk_CMISDriveTail()
{
    int nKey = 0;
    unsigned int uKey = 0;
    egf::EntityID id;
    { Unk_CMISMapIntUInt m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapMark m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapNear m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCell m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntity m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapDoll m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapSales m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapSetEffect m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapHead m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapBuckets m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapCubeGroups m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISStdMapCube m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapColumns m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntVec m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapEntityId m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapCubeTimer m; Unk_CMISDriveMapKey(m, nKey); }
    { Unk_CMISMapKind m; Unk_CMISDriveMap(m, nKey); }
    { Unk_CMISMapUIntInt m; Unk_CMISDriveMap(m, uKey); }
    { Unk_CMISMapUIntUInt m; unsigned int uVal; (void)m.find(uKey, uVal); (void)m.end(); (void)m.lower_bound(uKey); }
    { Unk_CMISMapBucket m; Unk_CMISDriveMap(m, uKey); }
    { Unk_CMISMapSaleState m; Unk_CMISDriveMapKey(m, std::pair<int, int>(0, 0)); }
    { Unk_CMISMapName m; Unk_CMISDriveMapKey(m, CStringA()); }
    { Unk_CMISMapEntityVal m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapProp m; Unk_CMISDriveMapKey(m, id); }
    { Unk_CMISMapEntityCube m; Unk_CMISDriveMap(m, id); }
    { Unk_CMISMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISStdMapKindCount m; Unk_CMISDriveMap(m, Unk_CMISKindA_None); }
    { Unk_CMISMapKindInt m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); }
    { Unk_CMISMapKindByte m; Unk_CMISDriveMap(m, Unk_CMISKindB_None); }
    { Unk_CMISIntSet s; Unk_CMISDriveSet(s, nKey); (void)s.equal_range(nKey); s.erase(nKey); (void)s.key_comp(); }
    { Unk_CMISPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISStdPairSet s; Unk_CMISDriveSet(s, std::pair<int, int>(0, 0)); }
    { Unk_CMISAutoSet s; MS2Ptr<AutomaticCreateCubeInfo> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISFuncCubeSet s; MS2Ptr<CFunctionCubeObject> p; Unk_CMISDriveSet(s, p); }
    { Unk_CMISEntityIdSet s; Unk_CMISDriveSet(s, id); }
    { Unk_CMISIntVec v; Unk_CMISDriveVector(v, nKey); }
    { Unk_CMISStdEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); }
    { Unk_CMISEntityIdVec v; Unk_CMISDriveVector(v, id); }
    { Unk_CMISEntVec v; Unk_CMISDriveVector(v, egf::EntityPtr()); }
    { Unk_CMISElem52Vec v; Unk_CMISDriveVector(v, Unk_CMISElem52()); }
    { Unk_CMISStdIntVec v; Unk_CMISDriveVector(v, nKey); }
    { MS2Ptr<UIHouseMarkEntity> p; }
    { efd::utf8string s; (void)s.find_last_of("/", 0); }
    { std::string s; s.append("x"); }
}
