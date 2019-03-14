//
//  SFSetRoomVariablesListener.cpp
//  climber
//
//  Created by Zinge on 12/28/17.
//
//

#include "sf/listeners/SetRoomVariablesListener.hpp"

#include <smartfox/Core/SFSEvent.h>
#include <smartfox/Entities/Room.h>

namespace sf {
using Self = SetRoomVariablesListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::ROOM_VARIABLES_UPDATE;
}

void Self::onEvent(const Parameter& params) {
    auto&& room =
        boost::static_pointer_cast<Sfs2X::Entities::Room>(params->at("room"));
    auto&& changedVars = boost::static_pointer_cast<std::vector<std::string>>(
        params->at("changedVars"));
    callback_(room, *changedVars);
}
} // namespace sf
