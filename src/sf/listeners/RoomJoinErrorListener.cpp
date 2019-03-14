//
//  SFRoomJoinErrorListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/RoomJoinErrorListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = RoomJoinErrorListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::ROOM_JOIN_ERROR;
}

void Self::onEvent(const Parameter& params) {
    auto&& errorMessage =
        boost::static_pointer_cast<std::string>(params->at("errorMessage"));
    callback_(*errorMessage);
}
} // namespace sf
