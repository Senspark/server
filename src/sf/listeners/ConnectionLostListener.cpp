//
//  SFConnectionLostListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/ConnectionLostListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = ConnectionLostListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::CONNECTION_LOST;
}

void Self::onEvent(const Parameter& params) {
    auto&& reason =
        boost::static_pointer_cast<std::string>(params->at("reason"));
    callback_(*reason);
}
} // namespace sf
