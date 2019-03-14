//
//  SFUserEnterRoomListener.cpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#include "sf/listeners/UserEnterRoomListener.hpp"

#include <smartfox/Core/SFSEvent.h>
#include <smartfox/Entities/Room.h>
#include <smartfox/Entities/User.h>

namespace sf {
using Self = UserEnterRoomListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::USER_ENTER_ROOM;
}

void Self::onEvent(const Parameter& params) {
    auto&& user =
        boost::static_pointer_cast<Sfs2X::Entities::User>(params->at("user"));
    auto&& room =
        boost::static_pointer_cast<Sfs2X::Entities::Room>(params->at("room"));
    callback_(user, room);
}
} // namespace sf
