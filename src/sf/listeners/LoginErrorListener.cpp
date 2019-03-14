//
//  SFLoginErrorListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/LoginErrorListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = LoginErrorListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::LOGIN_ERROR;
}

void Self::onEvent(const Parameter& params) {
    auto&& errorCode =
        boost::static_pointer_cast<std::int16_t>(params->at("errorCode"));
    auto&& errorMessage =
        boost::static_pointer_cast<std::string>(params->at("errorMessage"));
    callback_(static_cast<int>(*errorCode), *errorMessage);
}
} // namespace sf
