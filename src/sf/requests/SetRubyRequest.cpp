//
//  SFSetRubyRequest.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

#include "sf/requests/SetRubyRequest.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Entities/Data/SFSObject.h>

namespace sf {
#define Self SetRubyRequest

const std::string Self::RequestId = "set_ruby";

Self::Self() {
    amount_ = 0;
}

Self& Self::setUserId(const std::string& value) {
    userId_ = value;
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
#define Self SetRubyRequest::Parser

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
