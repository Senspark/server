//
//  SFExtensionResponseListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/ExtensionResponseListener.hpp"

#include <smartfox/Core/SFSEvent.h>
#include <smartfox/Entities/Data/ISFSObject.h>

namespace sf {
using Self = ExtensionResponseListener;

const boost::shared_ptr<std::string>& Self::Type =
    Sfs2X::Core::SFSEvent::EXTENSION_RESPONSE;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Type;
}

void Self::onEvent(const Parameter& params) {
    auto cmd = boost::static_pointer_cast<std::string>(params->at("cmd"));
    auto object = boost::static_pointer_cast<Sfs2X::Entities::Data::ISFSObject>(
        params->at("params"));
    callback_(*cmd, object);
}
} // namespace sf
