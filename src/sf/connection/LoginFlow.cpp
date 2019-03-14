//
//  SFLoginFlow.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/1/18.
//

#include "sf/connection/LoginFlow.hpp"
#include "sf/core/IBridge.hpp"
#include "sf/core/IEventDispatcher.hpp"
#include "sf/listeners/ConnectionListener.hpp"
#include "sf/listeners/ConnectionLostListener.hpp"
#include "sf/listeners/LoginListener.hpp"
#include "sf/listeners/LoginErrorListener.hpp"

namespace sf {
using Self = LoginFlow;

std::shared_ptr<Self> Self::create(IBridge& bridge) {
    return std::shared_ptr<Self>(new Self(bridge));
}

Self::LoginFlow(IBridge& bridge)
    : bridge_(bridge) {
    version_ = 0;
    loginCallback_ = std::bind([] {
        // Empty.
    });

    connectionListener_ = std::make_shared<ConnectionListener>(
        std::bind(&Self::onConnection, this, std::placeholders::_1));
    connectionLostListener_ = std::make_shared<ConnectionLostListener>(
        std::bind(&Self::onConnectionLost, this, std::placeholders::_1));
    loginListener_ = std::make_shared<LoginListener>(
        std::bind(&Self::onLogin, this, std::placeholders::_1));
    loginErrorListener_ = std::make_shared<LoginErrorListener>(
        std::bind(&Self::onLoginError, this, std::placeholders::_1,
                  std::placeholders::_2));
}

Self::~LoginFlow() {
    deregisterListeners();
}

Self& Self::setUserId(const std::string& id) {
    userId_ = id;
    return *this;
}

Self& Self::setVersion(int version) {
    version_ = version;
    return *this;
}

Self& Self::setCallback(const LoginCallback& callback) {
    auto self = shared_from_this();
    loginCallback_ = [this, callback, self](bool result) {
        callback(result);
        loginCallback_ = nullptr;
    };
    return *this;
}

void Self::start() {
    registerListeners();
    if (bridge_.isConnected()) {
        bridge_.logIn(userId_, version_);
    } else {
        bridge_.connect();
    }
}

void Self::registerListeners() {
    auto&& dispatcher = bridge_.getEventDispatcher();
    dispatcher.addListener(connectionListener_);
    dispatcher.addListener(connectionLostListener_);
    dispatcher.addListener(loginListener_);
    dispatcher.addListener(loginErrorListener_);
}

void Self::deregisterListeners() {
    auto&& dispatcher = bridge_.getEventDispatcher();
    dispatcher.removeListener(connectionListener_);
    dispatcher.removeListener(connectionLostListener_);
    dispatcher.removeListener(loginListener_);
    dispatcher.removeListener(loginErrorListener_);
}

void Self::onConnection(bool success) {
    if (success) {
        bridge_.logIn(userId_, version_);
    } else {
        loginCallback_(false);
    }
}

void Self::onConnectionLost(const std::string& reason) {
    // Error.
    SF_UNUSED_PARAM(reason);
    loginCallback_(false);
}

void Self::onLogin(const boost::shared_ptr<Sfs2X::Entities::User>& user) {
    SF_UNUSED_PARAM(user);
    loginCallback_(true);
}

void Self::onLoginError(int errorCode, const std::string& errorMessage) {
    // Error.
    SF_UNUSED_PARAM(errorCode);
    SF_UNUSED_PARAM(errorMessage);
    loginCallback_(false);
}
} // namespace sf
