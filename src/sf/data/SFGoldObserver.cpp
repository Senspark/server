//
//  SFGoldObserver.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

/*
#include "SFGoldObserver.hpp"
#include "SFBridge.hpp"
#include "SFExtensionResponseListener.hpp"
#include "SFUserInfoRequest.hpp"
#include "SFSetGoldRequest.hpp"

namespace sf {
using Self = GoldObserver;

Self::GoldObserver(const Callback& callback)
    : callback_(callback) {
    extensionListener_ = std::make_shared<ExtensionResponseListener>(
        [this](const std::string& cmd,
               const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>&
                   object) {
            if (cmd == UserInfoRequest::RequestId) {
                return onUserInfoRequest(object);
            }
            if (cmd == SetGoldRequest::RequestId) {
                return onSetGoldRequest(object);
            }
        });

    auto&& bridge = Bridge::getInstance();
    bridge.addListener(extensionListener_);
}

Self::~GoldObserver() {
    auto&& bridge = Bridge::getInstance();
    bridge.removeListener(extensionListener_);
}

void Self::onUserInfoRequest(
    const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object) {
    auto parser = UserInfoRequest::Parser(object);
    callback_(parser.getUserInfo().getGold());
}

void Self::onSetGoldRequest(
    const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object) {
    auto parser = SetGoldRequest::Parser(object);
    if (parser.success()) {
        callback_(parser.getAmount());
    }
}
} // namespace sf
*/
