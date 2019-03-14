//
//  DataPusher.cpp
//  server
//
//  Created by eps on 3/15/18.
//

#include "sf/data/DataPusher.hpp"
#include "sf/core/IBridge.hpp"
#include "sf/core/IRequestHandler.hpp"
#include "sf/data/Data.hpp"
#include "sf/data/Property.hpp"
#include "sf/requests/UpdateDataRequest.hpp"

#include <boost/shared_ptr.hpp>

namespace sf {
using Self = DataPusher;

std::shared_ptr<Self> Self::create(IBridge& bridge) {
    return std::shared_ptr<Self>(new Self(bridge));
}

Self::DataPusher(IBridge& bridge)
    : bridge_(bridge) {
    int x = 1;
    SF_UNUSED_PARAM(x);
}

Self::~DataPusher() {
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

void Self::start(const std::shared_ptr<IData>& data) {
    auto request = UpdateDataRequest() //
                       .setUserId(bridge_.getUserId())
                       .setData(data);
    auto updatedData = std::make_shared<Data>();
    updatedData->fromDict(data->toDict());
    bridge_.getRequestHandler().sendRequest(
        request, [this, updatedData](
                     const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>&
                         object) {
            auto parser = UpdateDataRequest::Parser(object);
            if (parser.success()) {
                updatedData->writePropery("timestamp",
                                          makeProperty(parser.getTimestamp()));
                failureCallback_ = nullptr;
                if (successCallback_) {
                    successCallback_(updatedData);
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
