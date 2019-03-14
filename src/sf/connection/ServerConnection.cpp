//
//  ServerLoginFlow.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/5/18.
//

#include "sf/connection/ServerConnection.hpp"
#include "sf/core/IBridge.hpp"
#include "sf/connection/LoginFlow.hpp"
#include "sf/connection/LogoutFlow.hpp"
#include "sf/connection/ILoginInfo.hpp"

namespace sf {
using Self = ServerConnection;

Self::ServerConnection(IBridge& bridge, std::unique_ptr<ILoginInfo> info)
    : bridge_(bridge)
    , info_(std::move(info)) {
    //
}

Self::~ServerConnection() {
    //
}

std::string Self::getUserId() const {
    return bridge_.getUserId();
}

bool Self::isLoggedIn() const {
    return bridge_.isLoggedIn();
}

void Self::logIn(const LogCallback& callback) {
    (*LoginFlow::create(bridge_)) //
        .setUserId(info_->getUserId())
        .setVersion(info_->getVersion())
        .setCallback(callback)
        .start();
}

void Self::logOut(const LogCallback& callback) {
    // bridge_.disconnect();
    (*LogoutFlow::create(bridge_)) //
        .setCallback(callback)
        .start();
}
} // namespace sf
