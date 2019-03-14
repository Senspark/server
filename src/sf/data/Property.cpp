//
//  UserProperty.cpp
//  server
//
//  Created by eps on 3/8/18.
//

#include "sf/data/Property.hpp"

namespace sf {
using Self = Property;

Self::Property() {
    type_ = Type::None;
}

Self::Property(int value) {
    type_ = Type::None;
    *this = value;
}

Self::Property(const std::string& value) {
    type_ = Type::None;
    *this = value;
}

Self::Property(std::string&& value) {
    type_ = Type::None;
    *this = std::move(value);
}

Self::Property(const Self& other) {
    type_ = Type::None;
    *this = other;
}

Self::Property(Self&& other) {
    type_ = Type::None;
    *this = std::move(other);
}

Self::~Property() {
    clear();
}

Self& Self::operator=(const Self& other) {
    if (this == &other) {
        return *this;
    }
    switch (other.getType()) {
    case Type::None:
        clear();
        break;
    case Type::Int:
        *this = other.field_.i;
        break;
    case Type::String:
        *this = other.field_.s;
        break;
    }
    type_ = other.getType();
    return *this;
}

Self& Self::operator=(Self&& other) {
    if (this == &other) {
        return *this;
    }
    switch (other.getType()) {
    case Type::None:
        clear();
        break;
    case Type::Int:
        *this = std::move(other.field_.i);
        break;
    case Type::String:
        *this = std::move(other.field_.s);
        break;
    }
    type_ = other.getType();
    other.clear();
    return *this;
}

Self& Self::operator=(int value) {
    clear();
    field_.i = value;
    type_ = Type::Int;
    return *this;
}

Self& Self::operator=(const std::string& value) {
    return *this = std::make_unique<std::string>(value);
}

Self& Self::operator=(std::string&& value) {
    return *this = std::make_unique<std::string>(std::move(value));
}

int Self::asInt() const {
    SF_ASSERT(isInt());
    return field_.i;
}

const std::string& Self::asString() const {
    SF_ASSERT(isString());
    return *field_.s;
}

std::string Self::toString() const {
    if (isNull()) {
        return "";
    }
    if (isInt()) {
        return std::to_string(asInt());
    }
    if (isString()) {
        return asString();
    }
    SF_ASSERT(false);
    return "";
}

bool Self::isNull() const {
    return getType() == Type::None;
}

bool Self::isInt() const {
    return getType() == Type::Int;
}

bool Self::isString() const {
    return getType() == Type::String;
}

Self::Type Self::getType() const {
    return type_;
}

void Self::clear() {
    switch (getType()) {
    case Type::None:
        break;
    case Type::Int:
        field_.i = 0;
        break;
    case Type::String:
        field_.s.~unique_ptr();
        break;
    }
    type_ = Type::None;
}

Self& Self::operator=(const std::unique_ptr<std::string>& value) {
    clear();
    new (&field_.s) std::unique_ptr<std::string>(new std::string(*value));
    type_ = Type::String;
    return *this;
}

Self& Self::operator=(std::unique_ptr<std::string>&& value) {
    clear();
    new (&field_.s) std::unique_ptr<std::string>(std::move(value));
    type_ = Type::String;
    return *this;
}
} // namespace sf
