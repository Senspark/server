//
//  Logger.cpp
//  server
//
//  Created by eps on 3/16/18.
//

#include "sf/core/Logger.hpp"

namespace sf {
using Self = Logger;

Self::~Logger() {}

Self& Self::onLogged(const LogCallback& callback) {
    logCallback_ = callback;
    return *this;
}

void Self::log(const std::string& message) {
    if (logCallback_) {
        logCallback_(message);
    }
}
} // namespace sf
