#pragma once
#include <egf/EntityManager.h>
#include <efd/AssetID.h>
#include "ms2/ms2layout.h"
class MS2EntityManagerService : public egf::EntityManager {
public:
    MS2EntityManagerService();
    virtual ~MS2EntityManagerService();
    egf::EntityID FUN_1414b4b00(const efd::utf8string&,efd::AssetID&,bool);
    virtual void SendEntityUpdateNotification(egf::Entity*);
    bool FUN_1414b54f0(const egf::Entity*);
};
MS2_CHECK_SIZE(MS2EntityManagerService,0x1b0);
