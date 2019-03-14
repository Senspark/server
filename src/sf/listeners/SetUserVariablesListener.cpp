//
//  SFSetUserVariablesListener.cpp
//  climber
//
//  Created by Zinge on 12/28/17.
//
//

#include "sf/listeners/SetUserVariablesListener.hpp"

#include <smartfox/Core/SFSEvent.h>
#include <smartfox/Entities/User.h>

namespace sf {
using Self = SetUserVariablesListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::USER_VARIABLES_UPDATE;
}

void Self::onEvent(const Parameter& params) {
    auto&& user =
        boost::static_pointer_cast<Sfs2X::Entities::User>(params->at("user"));
    auto&& changedVars = boost::static_pointer_cast<std::vector<std::string>>(
        params->at("changedVars"));
    callback_(user, *changedVars);
}
} // namespace sf
