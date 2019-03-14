//
//  SFUpdateUserInfoRequest.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/7/18.
//

#include "sf/requests/UpdateDataRequest.hpp"
#include "sf/data/IData.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Entities/Data/SFSObject.h>

namespace sf {
#define Self UpdateDataRequest

const std::string Self::RequestId = "update_data";

Self::Self() {}

Self& Self::setUserId(const std::string& value) {
    userId_ = value;
    return *this;
}

Self& Self::setData(const std::shared_ptr<IData>& value) {
    data_ = value;
    return *this;
}

std::string Self::getRequestId() const {
    return RequestId;
}

Self::Parameter Self::build() const {
    auto params = boost::make_shared<Sfs2X::Entities::Data::SFSObject>();
    params->PutUtfString("userId", userId_);
    params->PutSFSObject("data", data_->toDict());
    return params;
}

#undef Self
#define Self UpdateDataRequest::Parser

Self::Parser(const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object)
    : Super(object) {
    success_ = *object->GetBool("success");
    if (success_) {
        timestamp_ = *object->GetInt("timestamp");
    } else {
        timestamp_ = 0;
    }
}

bool Self::success() const {
    return success_;
}

int Self::getTimestamp() const {
    return timestamp_;
}

#undef Self
} // namespace sf
