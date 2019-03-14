//
//  SocketError.cpp
//  server
//
//  Created by eps on 3/20/18.
//

#include "sf/listeners/SocketErrorListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = SocketErrorListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::SFS_SOCKET_ERROR;
}

void Self::onEvent(const Parameter& params) {
    auto&& errorMessage =
        boost::static_pointer_cast<std::string>(params->at("errorMessage"));
    callback_(*errorMessage);
}
} // namespace sf
