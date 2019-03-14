//
//  RequestHandler.cpp
//  server
//
//  Created by eps on 3/8/18.
//

#include "sf/core/RequestHandler.hpp"
#include "sf/core/IEventDispatcher.hpp"
#include "sf/core/IRequest.hpp"
#include "sf/listeners/ExtensionResponseListener.hpp"

#include <boost/shared_ptr.hpp>

#include <smartfox/SmartFox.h>
#include <smartfox/Entities/Data/ISFSObject.h>
#include <smartfox/Requests/ExtensionRequest.h>

namespace sf {
using Self = RequestHandler;

Self::RequestHandler(IEventDispatcher& dispatcher, Sfs2X::SmartFox& client)
    : dispatcher_(dispatcher)
    , client_(client) {
    extensionListener_ = std::make_shared<ExtensionResponseListener>(
        [this](const std::string& cmd,
               const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>&
                   object) {
            auto parser = IRequest::IParser(object);
            auto callback = callbacks_.at(parser.getId());
            callbacks_.erase(parser.getId());
            callback(object);
        });
    dispatcher_.addListener(extensionListener_);
}

Self::~RequestHandler() {
    dispatcher_.removeListener(extensionListener_);
}

void Self::sendRequest(const IRequest& request) {
    auto params = request.build();
    params->PutInt("requestId", request.getId());
    client_.Send(boost::make_shared<Sfs2X::Requests::ExtensionRequest>(
        request.getRequestId(), params));
}

void Self::sendRequest(const IRequest& request,
                       const RequestCallback& callback) {
    callbacks_.emplace(request.getId(), callback);
    sendRequest(request);
}
} // namespace sf
