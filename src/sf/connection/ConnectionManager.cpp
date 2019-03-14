//
//  LoginManager.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/5/18.
//

#include "sf/connection/ConnectionManager.hpp"
#include "sf/connection/IConnection.hpp"
#include "sf/connection/GuardedConnection.hpp"
#include "sf/core/IBridge.hpp"

namespace sf {
using Self = ConnectionManager;

Self::ConnectionManager(std::unique_ptr<IConnection> server,
                        std::unique_ptr<IConnection> facebook)
    : server_(std::move(server))
    , facebook_(std::move(facebook)) {
    guardedServer_ = std::make_unique<GuardedConnection>(*server_);
    guardedFacebook_ = std::make_unique<GuardedConnection>(*facebook_);
}

Self::~ConnectionManager() {
    //
}

ConnectionState Self::getConnectionState() const {
    return state_;
}

IConnection& Self::getServerConnection() {
    return *guardedServer_;
}

IConnection& Self::getFacebookConnection() {
    return *guardedFacebook_;
}
} // namespace sf
