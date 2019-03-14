//
//  SFKeepAliveRequest.cpp
//  climber
//
//  Created by Zinge on 1/9/18.
//
//

#include "sf/requests/KeepAliveRequest.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Entities/Data/SFSObject.h>

namespace sf {
using Self = KeepAliveRequest;

const std::string Self::RequestId = "keep_alive";

Self::KeepAliveRequest() {
    //
}

std::string Self::getRequestId() const {
    return RequestId;
}

Self::Parameter Self::build() const {
    auto params = boost::make_shared<Sfs2X::Entities::Data::SFSObject>();
    params->PutBool("b", true);
    return params;
}
} // namespace sf
