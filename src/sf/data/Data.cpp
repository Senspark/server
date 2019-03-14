//
//  SFUserInfo.cpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

#include "sf/data/Data.hpp"
#include "sf/data/Property.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Entities/Data/SFSObject.h>

namespace sf {
using Self = Data;

Self::Data() {
    //
}

Self::~Data() {
    //
}

void Self::fromDict(
    const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& dict) {
    properties_.clear();
    auto keys = dict->GetKeys();
    for (auto&& key : *keys) {
        auto&& property = dict->GetData(key);
        switch (property->Type()) {
        case Sfs2X::Entities::Data::SFSDataType::SFSDATATYPE_INT:
            properties_.emplace(key,
                                std::make_shared<Property>(
                                    *boost::static_pointer_cast<std::int32_t>(
                                        property->Data())));
            break;
        case Sfs2X::Entities::Data::SFSDataType::SFSDATATYPE_UTF_STRING:
            properties_.emplace(key,
                                std::make_shared<Property>(
                                    *boost::static_pointer_cast<std::string>(
                                        property->Data())));
            break;
        default:
            SF_ASSERT(false);
            break;
        }
    }
}

boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject> Self::toDict() const {
    auto dict = boost::make_shared<Sfs2X::Entities::Data::SFSObject>();
    for (auto && [key, property] : properties_) {
        switch (property->getType()) {
        case Property::Type::Int:
            dict->PutInt(key, property->asInt());
            break;
        case Property::Type::String:
            dict->PutUtfString(key, property->asString());
            break;
        default:
            SF_ASSERT(false);
            break;
        }
    }
    return dict;
}

std::vector<std::string> Self::getKeys() const {
    std::vector<std::string> keys;
    keys.reserve(properties_.size());
    for (auto && [key, property] : properties_) {
        keys.push_back(key);
    }
    return keys;
}

std::shared_ptr<IProperty> Self::readProperty(const std::string& key) const {
    auto iter = properties_.find(key);
    if (iter == properties_.cend()) {
        return nullptr;
    }
    return iter->second;
}

void Self::writePropery(const std::string& key,
                        const std::shared_ptr<IProperty>& property) {
    properties_.insert_or_assign(key, property);
}
} // namespace sf
