//
//  SFPingPongListener.cpp
//  climber
//
//  Created by Zinge on 1/8/18.
//
//

#include "sf/listeners/PingPongListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = PingPongListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::PING_PONG;
}

void Self::onEvent(const Parameter& params) {
    auto&& lagValue =
        boost::static_pointer_cast<std::int32_t>(params->at("lagValue"));
    callback_(static_cast<int>(*lagValue));
}
} // namespace sf
