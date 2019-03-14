//
//  IUserProperty.h
//  server
//
//  Created by eps on 3/8/18.
//

#ifndef SF_PROPERTY_HPP
#define SF_PROPERTY_HPP

#include <memory>
#include <string>

#include "sf/data/IProperty.hpp"

namespace sf {
class Property : public IProperty {
private:
    using Self = Property;

public:
    static const Self Null;

    Property();

    explicit Property(int value);
    explicit Property(const std::string& value);
    explicit Property(std::string&& value);

    Property(const Self& other);
    Property(Self&& other);

    virtual ~Property() override;

    Self& operator=(const Self& other);
    Self& operator=(Self&& other);

    Self& operator=(int value);
    Self& operator=(const std::string& value);
    Self& operator=(std::string&& value);

    /// @see Super.
    virtual int asInt() const override;

    /// @see Super.
    virtual const std::string& asString() const override;

    /// @see Super.
    virtual std::string toString() const override;

    /// @see Super.
    virtual bool isNull() const override;

    /// @see Super.
    virtual bool isInt() const override;

    /// @see Super.
    virtual bool isString() const override;

    /// @see Super.
    virtual Type getType() const override;

    /// @see Super.
    virtual void clear() override;

protected:
    Self& operator=(const std::unique_ptr<std::string>& value);
    Self& operator=(std::unique_ptr<std::string>&& value);

private:
    Type type_;
    union Field {
        int i;
        std::unique_ptr<std::string> s;

        Field() {}
        ~Field() {}
    } field_;
};

template <class T>
auto makeProperty(T&& value) {
    return std::make_shared<Property>(std::forward<T>(value));
}
} // namespace sf

#endif /* SF_PROPERTY_HPP */
