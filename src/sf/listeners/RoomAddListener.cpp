//
//  SFRoomAddListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/RoomAddListener.hpp"

#include <smartfox/Core/SFSEvent.h>
#include <smartfox/Entities/Room.h>

namespace sf {
using Self = RoomAddListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::ROOM_ADD;
}

void Self::onEvent(const Parameter& params) {
    auto&& room =
        boost::static_pointer_cast<Sfs2X::Entities::Room>(params->at("room"));
    callback_(room);
}
} // namespace sf
