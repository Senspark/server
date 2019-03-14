//
//  DataSynchronizer.cpp
//  server
//
//  Created by eps on 3/15/18.
//

#include "sf/data/DataSyncer.hpp"
#include "sf/data/DataResolver.hpp"
#include "sf/data/DataFetcher.hpp"
#include "sf/data/DataPusher.hpp"
#include "sf/data/IData.hpp"
#include "sf/data/IProperty.hpp"

namespace sf {
using Self = DataSyncer;

std::shared_ptr<Self> Self::create(IBridge& bridge) {
    return std::shared_ptr<Self>(new Self(bridge));
}

Self::DataSyncer(IBridge& bridge)
    : bridge_(bridge) {
    int x = 1;
    SF_UNUSED_PARAM(x);
}

Self::~DataSyncer() {
    int x = 1;
    SF_UNUSED_PARAM(x);
}

void Self::setFailure() {
    conflictCallback_ = nullptr;
    successCallback_ = nullptr;
    if (failureCallback_) {
        failureCallback_();
    }
}

void Self::setSuccess(const std::shared_ptr<IData>& data) {
    conflictCallback_ = nullptr;
    failureCallback_ = nullptr;
    if (successCallback_) {
        successCallback_(data);
    }
}

void Self::compareData(const std::shared_ptr<IData>& localData,
                       const std::shared_ptr<IData>& cloudData) {
    auto cloudTimestamp = cloudData->readProperty("timestamp")->asInt();
    auto localTimestamp = localData->readProperty("timestamp")->asInt();
    if (cloudTimestamp == localTimestamp) {
        return setSuccess(localData);
    }
    if (conflictCallback_) {
        conflictCallback_(
            localData, cloudData,
            std::make_shared<DataResolver>(
                [this, localData, cloudData](bool useLocal) {
                    if (useLocal) {
                        (*DataPusher::create(bridge_))
                            .onFailure(std::bind(&Self::setFailure, this))
                            .onSuccess(std::bind(&Self::setSuccess, this,
                                                 std::placeholders::_1))
                            .start(localData);
                    } else {
                        setSuccess(cloudData);
                    }
                }));
    } else {
        setFailure();
    }
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

Self& Self::onConfliction(const ResolveCallback& callback) {
    auto self = shared_from_this();
    conflictCallback_ = [this, callback,
                         self](const std::shared_ptr<IData>& localData,
                               const std::shared_ptr<IData>& cloudData,
                               const std::shared_ptr<IDataResolver>& resolver) {
        callback(localData, cloudData, resolver);
        conflictCallback_ = nullptr;
    };
    return *this;
}

void Self::start(const std::shared_ptr<IData>& data) {
    (*DataFetcher::create(bridge_))
        .onFailure(std::bind(&Self::setFailure, this))
        .onSuccess(
            std::bind(&Self::compareData, this, data, std::placeholders::_1))
        .start();
}
} // namespace sf
