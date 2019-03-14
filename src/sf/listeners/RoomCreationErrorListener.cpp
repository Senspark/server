//
//  SFRoomCreationError.cpp
//  climber
//
//  Created by Zinge on 12/28/17.
//
//

#include "sf/listeners/RoomCreationErrorListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = RoomCreationErrorListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::ROOM_CREATION_ERROR;
}

void Self::onEvent(const Parameter& params) {
    auto&& errorMessage =
        boost::static_pointer_cast<std::string>(params->at("errorMessage"));
    callback_(*errorMessage);
}
} // namespace sf
