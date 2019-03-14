//
//  ConnectionRetryListener.cpp
//  server
//
//  Created by eps on 3/20/18.
//

#include "sf/listeners/ConnectionRetryListener.hpp"

#include <smartfox/Core/SFSEvent.h>

namespace sf {
using Self = ConnectionRetryListener;

const boost::shared_ptr<std::string>& Self::getType() const {
    return Sfs2X::Core::SFSEvent::CONNECTION_RETRY;
}

void Self::onEvent(const Parameter& params) {
    callback_();
}
} // namespace sf
