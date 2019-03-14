//
//  DataFetcher.cpp
//  server
//
//  Created by eps on 3/15/18.
//

#include "sf/data/DataFetcher.hpp"
#include "sf/core/IBridge.hpp"
#include "sf/core/IRequestHandler.hpp"
#include "sf/requests/DataRequest.hpp"

namespace sf {
using Self = DataFetcher;

std::shared_ptr<Self> Self::create(IBridge& bridge) {
    return std::shared_ptr<Self>(new Self(bridge));
}

Self::DataFetcher(IBridge& bridge)
    : bridge_(bridge) {
    int x = 1;
    SF_UNUSED_PARAM(x);
}

Self::~DataFetcher() {
    int x = 1;
    SF_UNUSED_PARAM(x);
}

Self& Self::onFailure(const FailureCallback& callback) {
    auto self = shared_from_this();
    failureCallback_ = [this, callback, self] {
        callback();
        failureCallback_ = nullptr;
    };
    return *this;
}

Self& Self::onSuccess(const SuccessCallback& callback) {
    auto self = shared_from_this();
    successCallback_ = [this, callback,
                        self](const std::shared_ptr<IData>& data) {
        callback(data);
        successCallback_ = nullptr;
    };
    return *this;
}

void Self::start() {
    auto request = DataRequest().setUserId(bridge_.getUserId());
    bridge_.getRequestHandler().sendRequest(
        request,
        [this](const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>&
                   object) {
            auto parser = DataRequest::Parser(object);
            if (parser.success()) {
                failureCallback_ = nullptr;
                if (successCallback_) {
                    successCallback_(parser.getData());
                }
            } else {
                successCallback_ = nullptr;
                if (failureCallback_) {
                    failureCallback_();
                }
            }
        });
}
} // namespace sf
