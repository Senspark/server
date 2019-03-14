//
//  SFRubyObserver.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

/*
#include "SFRubyObserver.hpp"
#include "SFBridge.hpp"
#include "SFExtensionResponseListener.hpp"
#include "SFUserInfoRequest.hpp"
#include "SFSetRubyRequest.hpp"

namespace sf {
using Self = RubyObserver;

Self::RubyObserver(const Callback& callback)
    : callback_(callback) {
    extensionListener_ = std::make_shared<ExtensionResponseListener>(
        [this](const std::string& cmd,
               const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>&
                   object) {
            if (cmd == UserInfoRequest::RequestId) {
                return onUserInfoRequest(object);
            }
            if (cmd == SetRubyRequest::RequestId) {
                return onSetRubyRequest(object);
            }
        });

    auto&& bridge = Bridge::getInstance();
    bridge.addListener(extensionListener_);
}

Self::~RubyObserver() {
    auto&& bridge = Bridge::getInstance();
    bridge.removeListener(extensionListener_);
}

void Self::onUserInfoRequest(
    const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object) {
    auto parser = UserInfoRequest::Parser(object);
    callback_(parser.getUserInfo().getRuby());
}

void Self::onSetRubyRequest(
    const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object) {
    auto parser = SetRubyRequest::Parser(object);
    if (parser.success()) {
        callback_(parser.getAmount());
    }
}
} // namespace sf
*/
