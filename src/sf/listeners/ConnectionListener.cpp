//
//  ConnectionListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/ConnectionListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = ConnectionListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::CONNECTION;
}

void Self::onEvent(const Parameter& params) {
    auto&& success = boost::static_pointer_cast<bool>(params->at("success"));
    callback_(*success);
}
} // namespace sf
