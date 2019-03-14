//
//  SFUserInfoRequest.cpp
//  climber
//
//  Created by Zinge on 12/22/17.
//
//

#include "sf/requests/DataRequest.hpp"
#include "sf/data/Data.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Entities/Data/SFSObject.h>

namespace sf {
#define Self DataRequest

const std::string Self::RequestId = "data";

Self::Self() {}

Self& Self::setUserId(const std::string& value) {
    userId_ = value;
    return *this;
}

std::string Self::getRequestId() const {
    return RequestId;
}

Self::Parameter Self::build() const {
    auto params = boost::make_shared<Sfs2X::Entities::Data::SFSObject>();
    params->PutUtfString("userId", userId_);
    return params;
}

#undef Self
#define Self DataRequest::Parser

Self::Parser(const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object)
    : Super(object) {
    success_ = *object->GetBool("success");
    data_ = std::make_shared<Data>();
    if (success_) {
        auto&& user = object->GetSFSObject("user");
        userId_ = *user->GetUtfString("name");
        data_->fromDict(user);
    } else {
        userId_ = "";
    }
}

bool Self::success() const {
    return success_;
}

const std::string& Self::getUserId() const {
    return userId_;
}

const std::shared_ptr<IData>& Self::getData() const {
    return data_;
}

#undef Self
} // namespace sf
