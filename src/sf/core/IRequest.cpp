//
//  SFIRequest.cpp
//  climber
//
//  Created by Zinge on 12/22/17.
//
//

#include "sf/core/IRequest.hpp"

#include <smartfox/Entities/Data/ISFSObject.h>

namespace sf {
#define Self IRequest

Self::Self() {
    static int counter = 0;
    id_ = counter++;
}

int Self::getId() const {
    return id_;
}

#undef Self
#define Self IRequest::IParser

Self::IParser(
    const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object) {
    id_ = *object->GetInt("requestId");
}

int Self::getId() const {
    return id_;
}

#undef Self
} // namespace sf
