//
//  IUserInfo.h
//  server
//
//  Created by eps on 3/8/18.
//

#ifndef SF_I_DATA_HPP
#define SF_I_DATA_HPP

#include <memory>
#include <string>

#include "sf/Macro.hpp"
#include "sf/Forward.hpp"

namespace sf {
class IData {
public:
    virtual ~IData() = default;

    virtual void fromDict(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& dict) = 0;

    virtual boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>
    toDict() const = 0;

    virtual std::vector<std::string> getKeys() const = 0;

    virtual std::shared_ptr<IProperty>
    readProperty(const std::string& key) const = 0;

    virtual void writePropery(const std::string& key,
                              const std::shared_ptr<IProperty>& property) = 0;
};
} // namespace sf

#endif /* SF_I_DATA_HPP */
