//
//  IUserProperty.h
//  server
//
//  Created by eps on 3/8/18.
//

#ifndef SF_I_PROPERTY_HPP
#define SF_I_PROPERTY_HPP

#include <string>

#include "sf/Macro.hpp"

namespace sf {
class IProperty {
public:
    enum class Type {
        None,   ///< Empty.
        Int,    ///< Wraps an integer.
        String, ///< Wraps a string.
    };

    virtual ~IProperty() = default;

    virtual int asInt() const = 0;
    virtual const std::string& asString() const = 0;
    
    virtual std::string toString() const = 0;

    virtual bool isNull() const = 0;
    virtual bool isInt() const = 0;
    virtual bool isString() const = 0;

    virtual Type getType() const = 0;
    virtual void clear() = 0;
};
} // namespace sf

#endif /* SF_I_PROPERTY_HPP */
