// physxpropmessage.h - ecrPhysX::PhysXPropMessage declaration only (not an original header).
// The real GameFramework/ecrPhysX/PhysXPropMessage.h is not usable in the game build because it includes
// efdPhysX/PhysXSDKManager.h (PhysX SDK headers are not on the include path). Same class id / base / layout:
// the message is an efd::IMessage plus an egf::EntityID. Used by WorldService's EE_HANDLER_WRAP statics.
#pragma once
#include <efd/Category.h>
#include <efd/IDs.h>
#include <efd/IMessage.h>
#include <ecr/ecrMessageIDs.h>
#include <egf/EntityID.h>

namespace ecrPhysX
{
class PhysXPropMessage : public efd::IMessage
{
    EE_DECLARE_CLASS1(PhysXPropMessage, efd::kMSGID_PhysXPropMessage, IMessage);
public:
    PhysXPropMessage();
    virtual void Serialize(efd::Archive& ar);
    const egf::EntityID& GetEntityID() const { return m_entityID; }
    void SetEntityID(const egf::EntityID& entityID) { m_entityID = entityID; }
    static efd::IBasePtr FactoryMethod();
protected:
    egf::EntityID m_entityID;
};
}
