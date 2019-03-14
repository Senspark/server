//
//  SFLogoutListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/LogoutListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = LogoutListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::LOGOUT;
}

void Self::onEvent(const Parameter& params) {
    callback_();
}
} // namespace sf
