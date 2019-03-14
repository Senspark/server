//
//  SmartFoxBridge.cpp
//  climber
//
//  Created by Zinge on 12/14/17.
//
//

#include <cassert>

#include "sf/core/Bridge.hpp"
#include "sf/core/EventDispatcher.hpp"
#include "sf/core/LogManager.hpp"
#include "sf/core/RequestHandler.hpp"
#include "sf/listeners/HandshakeListener.hpp"
#include "sf/listeners/SocketErrorListener.hpp"
#include "sf/listeners/ConnectionListener.hpp"
#include "sf/listeners/ConnectionLostListener.hpp"
#include "sf/listeners/ConnectionRetryListener.hpp"
#include "sf/listeners/ConnectionResumeListener.hpp"
#include "sf/listeners/ExtensionResponseListener.hpp"
#include "sf/listeners/LoginListener.hpp"
#include "sf/listeners/PingPongListener.hpp"
#include "sf/requests/KeepAliveRequest.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Entities/Variables/SFSRoomVariable.h>
#include <smartfox/Requests/CreateRoomRequest.h>
#include <smartfox/Requests/ExtensionRequest.h>
#include <smartfox/Requests/FindRoomsRequest.h>
#include <smartfox/Requests/FindUsersRequest.h>
#include <smartfox/Requests/Game/CreateSFSGameRequest.h>
#include <smartfox/Requests/Game/InviteUsersRequest.h>
#include <smartfox/Requests/Game/JoinRoomInvitationRequest.h>
#include <smartfox/Requests/Game/QuickJoinGameRequest.h>
#include <smartfox/Requests/Game/SFSGameSettings.h>
#include <smartfox/Requests/LoginRequest.h>
#include <smartfox/Requests/LogoutRequest.h>
#include <smartfox/Requests/RoomSettings.h>
#include <smartfox/Requests/SetRoomVariablesRequest.h>
#include <smartfox/Requests/SetUserVariablesRequest.h>
#include <smartfox/SmartFox.h>

#define NDEBUG

namespace sf {
using Self = Bridge;

namespace constants {
#ifndef NDEBUG
constexpr auto host = "14.161.14.97";
// constexpr auto host = "127.0.0.1";
#else  // NDEBUG
constexpr auto host = "127.0.0.1";
#endif // NDEBUG
constexpr auto port = 9933;
constexpr auto zone = "SpaceWar";
constexpr auto max_players = 2;
} // namespace constants

Self& Self::getInstance() {
    static Self sharedInstance;
    return sharedInstance;
}

Self::Bridge() {
    initialized_ = false;
    latency_ = -1;
}

Self::~Bridge() {
    //
}

namespace {
void onLogEventCallback(unsigned long long context,
                        boost::shared_ptr<Sfs2X::Core::BaseEvent> event) {
    SF_UNUSED_PARAM(context);
    auto&& params = event->Params();
    auto&& message =
        boost::static_pointer_cast<std::string>(params->at("message"));
    Self::getInstance().onLogged(*message);
}
} // namespace

void Self::initialize() {
    if (initialized_) {
        return;
    }
    client_ = boost::make_shared<Sfs2X::SmartFox>(true);
    eventDispatcher_ = std::make_unique<EventDispatcher>(getClient());
    requestHandler_ =
        std::make_unique<RequestHandler>(getEventDispatcher(), getClient());
    logManager_ = std::make_unique<LogManager>();

    client_->ThreadSafeMode(true);

    auto delegate = boost::make_shared<Sfs2X::Util::EventListenerDelegate>(
        onLogEventCallback, 0);
    client_->AddLogListener(Sfs2X::Logging::LogLevel::LOGLEVEL_DEBUG, delegate);

    listeners_.push_back(std::make_shared<HandshakeListener>([] { //
        int x = 1;
        SF_UNUSED_PARAM(x);
    }));
    listeners_.push_back(std::make_shared<SocketErrorListener>(
        [](const std::string& errorMessage) { //
            int x = 1;
            SF_UNUSED_PARAM(x);
        }));
    listeners_.push_back(
        std::make_shared<ConnectionListener>([this](bool success) {
            if (success) {
                // OK.
            } else {
                // Reinitialize socket engine.
                getClient().GetSocketEngine()->Init();
            }
        }));
    listeners_.push_back(std::make_shared<ConnectionLostListener>(
        [this](const std::string& reason) { //
            bool k = isConnected();
            int x = 1;
            SF_UNUSED_PARAM(x);
        }));
    listeners_.push_back(std::make_shared<ConnectionRetryListener>([] { //
        int x = 1;
        SF_UNUSED_PARAM(x);
    }));
    listeners_.push_back(std::make_shared<ConnectionResumeListener>([] { //
        int x = 1;
        SF_UNUSED_PARAM(x);
    }));
    listeners_.push_back(std::make_shared<LoginListener>(std::bind([this] { //
        client_->EnableLagMonitor(true, 3, 10);
    })));
    listeners_.push_back(
        std::make_shared<PingPongListener>([this](int lagValue) { //
            latency_ = lagValue;
        }));

    for (auto&& listener : listeners_) {
        getEventDispatcher().addListener(listener);
    }

    initialized_ = true;
}

void Self::reinitialize() {
    if (not initialized_) {
        return;
    }
    /*
    auto client = boost::make_shared<Sfs2X::SmartFox>();
    auto eventDispatcher = std::make_unique<EventDispatcher>(
        *client, static_cast<EventDispatcher&>(getEventDispatcher()));
    auto requestHandler = std::make_unique<RequestHandler>(
        *eventDispatcher, *client,
        static_cast<RequestHandler&>(getRequestHandler()));

    client->ThreadSafeMode(true);

    eventDispatcher->addListener(loginListener_);
    eventDispatcher->addListener(pingPongListener_);

    client_ = client;
    requestHandler_ = std::move(requestHandler);
    eventDispatcher_ = std::move(eventDispatcher);
     */
}

void Self::process() {
    if (initialized_) {
        getEventDispatcher().processEvents();
        client_->ProcessEvents();

        if (getClient().MySelf() != nullptr) {
            getRequestHandler().sendRequest(KeepAliveRequest());
        }
    }
}

Sfs2X::SmartFox& Self::getClient() const {
    return *client_;
}

IEventDispatcher& Self::getEventDispatcher() {
    return *eventDispatcher_;
}

IRequestHandler& Self::getRequestHandler() {
    return *requestHandler_;
}

ILogManager& Self::getLogManager() {
    return *logManager_;
}

std::string Self::getUserId() const {
    auto&& user = getClient().MySelf();
    return user == nullptr ? std::string() : *user->Name();
}

int Self::getLatency() const {
    return latency_;
}

bool Self::isConnected() const {
    return getClient().IsConnected();
}

void Self::connect() {
    getClient().Connect(constants::host, constants::port);
}

void Self::disconnect() {
    getClient().Disconnect();
    reinitialize();
}

bool Self::isLoggedIn() const {
    if (not isConnected()) {
        return false;
    }
    auto&& user = getClient().MySelf();
    return user != nullptr;
}

void Self::logIn(const std::string& userId, int version) {
    auto parameters = boost::make_shared<Sfs2X::Entities::Data::SFSObject>();
    parameters->PutUtfString("userId", userId);
    parameters->PutInt("version", version);
    auto request = boost::make_shared<Sfs2X::Requests::LoginRequest>(
        "", "", constants::zone, parameters);
    sendRequest(request);
}

void Self::logOut() {
    auto request = boost::make_shared<Sfs2X::Requests::LogoutRequest>();
    sendRequest(request);
}

void Self::sendRequest(
    const boost::shared_ptr<Sfs2X::Requests::IRequest>& request) {
    getClient().Send(request);
}

void Self::onLogged(const std::string& message) {
    static_cast<LogManager&>(getLogManager()).log(message);
}
} // namespace sf
