// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService.cpp COMDAT tail (ATL/STL container glue of the
// WorldService members, efd message handler / ClassFunHandler scalar deleting dtors, Notify* ??_G).
// MS2-UNIT: unit_141bf99b8
// MS2-RANGE: 0x141bf99b8-0x141c00000 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GUnk_WsVa18@@QEAAPEAXI@Z 0x141bf99d0 ; probe
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VActorAddedMessage@egmAnimation@@@efd@@UEAAPEAXI@Z 0x141bf9a50 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VActorRemovedMessage@egmAnimation@@@efd@@UEAAPEAXI@Z 0x141bf9a90 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VAssetLoadResponse@efd@@@efd@@UEAAPEAXI@Z 0x141bf9ad0 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VEntityChangeMessage@egf@@@efd@@UEAAPEAXI@Z 0x141bf9b10 ; order
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VEntityLoadResult@egf@@@efd@@UEAAPEAXI@Z 0x141bf9b50 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VPhysXPropMessage@ecrPhysX@@@efd@@UEAAPEAXI@Z 0x141bf9b90 ; order
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VSceneGraphAddedMessage@ecr@@@efd@@UEAAPEAXI@Z 0x141bf9bd0 ; prop
// MS2-PIN: ??_G?$MessageHandlerImpl@VWorldService@@VSceneGraphRemovedMessage@ecr@@@efd@@UEAAPEAXI@Z 0x141bf9c10 ; prop
// MS2-PIN: ??_G?$MessageSubclassHandler@VWorldService@@VAssetLoadResponse@efd@@VFlatModelFactoryResponse@egf@@@efd@@UEAAPEAXI@Z 0x141bf9c50 ; prop
// MS2-PIN: ??_G?$MessageSubclassHandler@VWorldService@@VEntityChangeMessage@egf@@V23@@efd@@UEAAPEAXI@Z 0x141bf9c90 ; order
// MS2-PIN: ??_G?$MessageSubclassHandler@VWorldService@@VPhysXPropMessage@ecrPhysX@@V23@@efd@@UEAAPEAXI@Z 0x141bf9cd0 ; order
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VWorldService@@VEntityChangeMessage@egf@@V23@$0CAAE@@efd@@UEAAPEAXI@Z 0x141bf9d10 ; prop
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VWorldService@@VEntityChangeMessage@egf@@V23@$0CADN@@efd@@UEAAPEAXI@Z 0x141bf9d50 ; prop
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VWorldService@@VEntityChangeMessage@egf@@V23@$0CADO@@efd@@UEAAPEAXI@Z 0x141bf9d90 ; prop
// MS2-PIN: ??_G?$MessageWrapperSubclassHandler@VWorldService@@VPhysXPropMessage@ecrPhysX@@V23@$0DAAL@@efd@@UEAAPEAXI@Z 0x141bf9dd0 ; prop
// MS2-PIN: ??_GUnk_WsVa00@@QEAAPEAXI@Z 0x141bf9e10 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x141bfaff0 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@IUUnk_WsV350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV350@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x141bfb070 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@IUUnk_WsV3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV3a0@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x141bfb0f0 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@IUUnk_WsV738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV738@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x141bfb170 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@_KUUnk_WsV2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV2f8@@@3@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141bfb2f0 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@_KUUnk_WsV420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV420@@@3@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141bfb370 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@_KUUnk_WsV468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV468@@@3@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141bfb3f0 ; probe
// MS2-PIN: ?CreateNode@?$CAtlMap@_KUUnk_WsV5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV5a0@@@3@@ATL@@AEAAPEAVCNode@12@_KII@Z 0x141bfb470 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@QEAAXXZ 0x141bfb660 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV350@@@3@@ATL@@QEAAXXZ 0x141bfb680 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV3a0@@@3@@ATL@@QEAAXXZ 0x141bfb6a0 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV738@@@3@@ATL@@QEAAXXZ 0x141bfb6c0 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV780@@@3@@ATL@@QEAAXXZ 0x141bfb6e0 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@QEAAXXZ 0x141bfb700 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@IUUnk_WsV930@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV930@@@3@@ATL@@QEAAXXZ 0x141bfb720 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KUUnk_WsV2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV2f8@@@3@@ATL@@QEAAXXZ 0x141bfb740 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KUUnk_WsV420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV420@@@3@@ATL@@QEAAXXZ 0x141bfb760 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KUUnk_WsV468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV468@@@3@@ATL@@QEAAXXZ 0x141bfb780 ; probe
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@_KUUnk_WsV5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV5a0@@@3@@ATL@@QEAAXXZ 0x141bfb7a0 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@QEAAXXZ 0x141bfb860 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV350@@@3@@ATL@@QEAAXXZ 0x141bfb880 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV3a0@@@3@@ATL@@QEAAXXZ 0x141bfb8a0 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV738@@@3@@ATL@@QEAAXXZ 0x141bfb8c0 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV780@@@3@@ATL@@QEAAXXZ 0x141bfb8e0 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@QEAAXXZ 0x141bfb900 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@IUUnk_WsV930@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV930@@@3@@ATL@@QEAAXXZ 0x141bfb920 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KUUnk_WsV2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV2f8@@@3@@ATL@@QEAAXXZ 0x141bfb940 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KUUnk_WsV420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV420@@@3@@ATL@@QEAAXXZ 0x141bfb960 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KUUnk_WsV468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV468@@@3@@ATL@@QEAAXXZ 0x141bfb980 ; probe
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@_KUUnk_WsV5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV5a0@@@3@@ATL@@QEAAXXZ 0x141bfb9a0 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV5e8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV5e8@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfbe70 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV7c8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV7c8@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfbf60 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV4b0@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV4b0@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfc050 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV510@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV510@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfc140 ; probe
// MS2-PIN: ?Find@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV678@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV678@@@2@@ATL@@IEBAPEAVCNode@12@AEBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@2@@Z 0x141bfc230 ; probe
// MS2-PIN: ?FindNextNode@?$CAtlMap@_KUUnk_WsV2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV2f8@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfca70 ; probe
// MS2-PIN: ?FindNextNode@?$CAtlMap@_KUUnk_WsV420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV420@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfcb30 ; probe
// MS2-PIN: ?FindNextNode@?$CAtlMap@_KUUnk_WsV468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV468@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141bfcbf0 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@HUUnk_WsV540@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV540@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd820 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@HUUnk_WsV570@@V?$CElementTraits@H@ATL@@V?$CElementTraits@UUnk_WsV570@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd8c0 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV1a8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV1a8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfd960 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV0e8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV0e8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfda00 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV118@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV118@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdaa0 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV148@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV148@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdb40 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@IUUnk_WsV708@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV708@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdbe0 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV5e8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV5e8@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdc80 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV4b0@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV4b0@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdd20 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV7c8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV7c8@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfddc0 ; probe
// MS2-PIN: ?FreeNode@?$CRBTree@_KUUnk_WsV0b8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV0b8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfde60 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV510@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV510@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdf00 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV678@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV678@@@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfdfa0 ; order
// MS2-PIN: ?FreeNode@?$CRBTree@_KUUnk_WsV4e0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV4e0@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfe040 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@_KUUnk_WsV6a8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV6a8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfe0e0 ; prop
// MS2-PIN: ?FreeNode@?$CRBTree@_KUUnk_WsV6d8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV6d8@@@3@@ATL@@AEAAXPEAVCNode@12@@Z 0x141bfe220 ; prop
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_WsV208@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV208@@@3@@ATL@@AEAAXXZ 0x141bfe2c0 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_WsV350@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV350@@@3@@ATL@@AEAAXXZ 0x141bfe310 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_WsV3a0@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV3a0@@@3@@ATL@@AEAAXXZ 0x141bfe360 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_WsV738@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV738@@@3@@ATL@@AEAAXXZ 0x141bfe3b0 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_WsV780@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV780@@@3@@ATL@@AEAAXXZ 0x141bfe400 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_WsV848@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV848@@@3@@ATL@@AEAAXXZ 0x141bfe450 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@IUUnk_WsV930@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV930@@@3@@ATL@@AEAAXXZ 0x141bfe4a0 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KUUnk_WsV2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV2f8@@@3@@ATL@@AEAAXXZ 0x141bfe4f0 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KUUnk_WsV420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV420@@@3@@ATL@@AEAAXXZ 0x141bfe540 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KUUnk_WsV468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV468@@@3@@ATL@@AEAAXXZ 0x141bfe590 ; probe
// MS2-PIN: ?FreePlexes@?$CAtlMap@_KUUnk_WsV5a0@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV5a0@@@3@@ATL@@AEAAXXZ 0x141bfe5e0 ; probe
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x141bfe680 ; probe
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@_KUUnk_WsV2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV2f8@@@3@@ATL@@QEBAIXZ 0x141bfeaa0 ; probe
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@_KUUnk_WsV420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV420@@@3@@ATL@@QEBAIXZ 0x141bfeab0 ; probe
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@_KUUnk_WsV468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV468@@@3@@ATL@@QEBAIXZ 0x141bfeac0 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@IUUnk_WsV0e8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV0e8@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfeaf0 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@IUUnk_WsV148@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV148@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfeb10 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@IUUnk_WsV1a8@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV1a8@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfeb30 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@IUUnk_WsV708@@V?$CElementTraits@I@ATL@@V?$CElementTraits@UUnk_WsV708@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfeb50 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV4b0@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV4b0@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfeb70 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV510@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV510@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfeb90 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV5e8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV5e8@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfebb0 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV678@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV678@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfebd0 ; probe
// MS2-PIN: ?GetHeadPosition@?$CRBTree@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@UUnk_WsV7c8@@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@V?$CElementTraits@UUnk_WsV7c8@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x141bfebf0 ; probe
// MS2-PIN: ?GetNode@?$CAtlMap@_KUUnk_WsV2f8@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV2f8@@@3@@ATL@@AEBAPEAVCNode@12@_KAEAI1AEAPEAV312@@Z 0x141bffb10 ; probe
// MS2-PIN: ?GetNode@?$CAtlMap@_KUUnk_WsV420@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV420@@@3@@ATL@@AEBAPEAVCNode@12@_KAEAI1AEAPEAV312@@Z 0x141bffc00 ; probe
// MS2-PIN: ?GetNode@?$CAtlMap@_KUUnk_WsV468@@V?$CElementTraits@_K@ATL@@V?$CElementTraits@UUnk_WsV468@@@3@@ATL@@AEBAPEAVCNode@12@_KAEAI1AEAPEAV312@@Z 0x141bffcf0 ; probe
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/MessageService.h>
#include <efd/AssetLoadResponse.h>
#include <egf/EntityChangeMessage.h>
#include <egf/EntityLoaderMessages.h>
#include <egf/FlatModelFactoryResponse.h>
#include <ecr/CoreRuntimeMessages.h>
#include "ms2/placeholder/physxpropmessage.h"
#include <egmAnimation/ActorMessages.h>
#define WS_INST_FN Unk_WsInst6
#include "ms2/client/ms2/worldservice_inst.inl"

#ifndef MS2_HOOK_DLL  // MS2: instantiates the handler classes (and their scalar deleting dtors) whose COMDATs sit in this tail; the same
// statics live in worldservice_1.cpp (.text$di 0x140120290), so the hook DLL must not register a second set.
EE_HANDLER_WRAP(WorldService, FUN_141bc0530, ecrPhysX::PhysXPropMessage, 12299);
EE_HANDLER_WRAP(WorldService, FUN_141bbd640, egf::EntityChangeMessage, 8253);
EE_HANDLER_WRAP(WorldService, FUN_141bbf2f0, egf::EntityChangeMessage, 8254);
EE_HANDLER_WRAP(WorldService, FUN_141bbfa50, egf::EntityChangeMessage, 8196);
EE_HANDLER(WorldService, FUN_141bbf9f0, efd::AssetLoadResponse);
EE_HANDLER_SUBCLASS(WorldService, FUN_141bc0f50, efd::AssetLoadResponse, egf::FlatModelFactoryResponse);
EE_HANDLER(WorldService, FUN_141bbfb50, egmAnimation::ActorAddedMessage);
EE_HANDLER(WorldService, FUN_141bbfde0, egmAnimation::ActorRemovedMessage);
EE_HANDLER(WorldService, FUN_141bc0a70, egf::EntityLoadResult);
EE_HANDLER(WorldService, FUN_141bbfe30, ecr::SceneGraphAddedMessage);
EE_HANDLER(WorldService, FUN_141bc0290, ecr::SceneGraphRemovedMessage);
#endif
