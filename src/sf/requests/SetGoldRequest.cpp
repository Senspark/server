//
//  RequestMoney.cpp
//  climber
//
//  Created by Zinge on 12/14/17.
//
//

#include "sf/requests/SetGoldRequest.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Entities/Data/SFSObject.h>

namespace sf {
#define Self SetGoldRequest

const std::string Self::RequestId = "set_gold";

Self::Self() {
    amount_ = 0;
}

Self& Self::setUserId(const std::string& userId) {
    userId_ = userId;
    return *this;
}

Self& Self::setAmount(int value) {
    amount_ = value;
    return *this;
}

std::string Self::getRequestId() const {
    return RequestId;
}

Self::Parameter Self::build() const {
    auto params = boost::make_shared<Sfs2X::Entities::Data::SFSObject>();
    params->PutUtfString("userId", userId_);
    params->PutInt("amount", amount_);
    return params;
}

#undef Self
#define Self SetGoldRequest::Parser

Self::Parser(const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object)
    : Super(object) {
    success_ = *object->GetBool("success");
    if (success_) {
        amount_ = *object->GetInt("amount");
    } else {
        amount_ = 0;
    }
}

bool Self::success() const {
    return success_;
}

int Self::getAmount() const {
    return amount_;
}

#undef Self
} // namespace sf
