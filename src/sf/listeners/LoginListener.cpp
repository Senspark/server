//
//  LoginListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/LoginListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = LoginListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::LOGIN;
}

void Self::onEvent(const Parameter& params) {
    auto&& user =
        boost::static_pointer_cast<Sfs2X::Entities::User>(params->at("user"));
    callback_(user);
}
} // namespace sf
