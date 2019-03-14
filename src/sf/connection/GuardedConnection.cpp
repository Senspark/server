//
//  GuardedConnectionBridge.cpp
//  server
//
//  Created by eps on 3/14/18.
//

#include "sf/connection/GuardedConnection.hpp"

namespace sf {
using Self = GuardedConnection;

Self::GuardedConnection(IConnection& connection)
    : connection_(connection) {
    isLoggingIn_ = false;
    isLoggingOut_ = false;
}

Self::~GuardedConnection() {
    //
}

std::string Self::getUserId() const {
    return connection_.getUserId();
}

bool Self::isLoggedIn() const {
    return connection_.isLoggedIn();
}

void Self::logIn(const LogCallback& callback) {
    if (isLoggingIn_) {
        callback(false);
    } else {
        isLoggingIn_ = true;
        connection_.logIn([this, callback](bool result) {
            isLoggingIn_ = false;
            callback(result);
        });
    }
}

void Self::logOut(const LogCallback& callback) {
    if (isLoggingOut_) {
        callback(false);
    } else {
        isLoggingOut_ = true;
        connection_.logOut([this, callback](bool result) {
            isLoggingOut_ = false;
            callback(result);
        });
    }
}
} // namespace sf
