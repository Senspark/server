//
//  SFRemoveUserRequest.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

#include "sf/requests/RemoveUserRequest.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Entities/Data/SFSObject.h>

namespace sf {
#define Self RemoveUserRequest

const std::string Self::RequestId = "remove_user";

Self::Self() {
    //
}

Self& Self::setName(const std::string& value) {
    name_ = value;
    return *this;
}

std::string Self::getRequestId() const {
    return RequestId;
}

Self::Parameter Self::build() const {
    auto params = boost::make_shared<Sfs2X::Entities::Data::SFSObject>();
    params->PutUtfString("name", name_);
    return params;
}

#undef Self
#define Self RemoveUserRequest::Parser

Self::Parser(const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object)
    : Super(object) {
    success_ = *object->GetBool("success");
}

bool Self::success() const {
    return success_;
}

#undef Self
} // namespace sf
