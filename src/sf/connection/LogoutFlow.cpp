//
//  LogoutFlow.cpp
//  server
//
//  Created by eps on 3/9/18.
//

#include "LogoutFlow.hpp"
#include "sf/core/IBridge.hpp"
#include "sf/core/IEventDispatcher.hpp"
#include "sf/listeners/ConnectionLostListener.hpp"
#include "sf/listeners/LogoutListener.hpp"

namespace sf {
using Self = LogoutFlow;

std::shared_ptr<Self> Self::create(IBridge& bridge) {
    return std::shared_ptr<Self>(new Self(bridge));
}

Self::LogoutFlow(IBridge& bridge)
    : bridge_(bridge) {
    logoutCallback_ = std::bind([] {
        // Empty.
    });

    connectionLostListener_ = std::make_shared<ConnectionLostListener>(
        std::bind(&Self::onConnectionLost, this, std::placeholders::_1));
    logoutListener_ =
        std::make_shared<LogoutListener>(std::bind(&Self::onLogout, this));
}

Self::~LogoutFlow() {
    deregisterListeners();
}

Self& Self::setCallback(const LogoutCallback& callback) {
    auto self = shared_from_this();
    logoutCallback_ = [this, callback, self](bool result) {
        callback(result);
        logoutCallback_ = nullptr;
    };
    return *this;
}

void Self::start() {
    registerListeners();
    bridge_.logOut();
}

void Self::registerListeners() {
    auto&& dispatcher = bridge_.getEventDispatcher();
    dispatcher.addListener(connectionLostListener_);
    dispatcher.addListener(logoutListener_);
}

void Self::deregisterListeners() {
    auto&& dispatcher = bridge_.getEventDispatcher();
    dispatcher.removeListener(connectionLostListener_);
    dispatcher.removeListener(logoutListener_);
}

void Self::onConnectionLost(const std::string& reason) {
    // Error.
    SF_UNUSED_PARAM(reason);
    logoutCallback_(false);
}

void Self::onLogout() {
    logoutCallback_(true);
}
} // namespace sf
