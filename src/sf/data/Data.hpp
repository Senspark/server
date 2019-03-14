//
//  SFUserInfo.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

#ifndef SF_DATA_HPP
#define SF_DATA_HPP

#include <map>
#include <string>

#include "sf/data/IData.hpp"

namespace sf {
class Data : public IData {
private:
    using Self = Data;

public:
    Data();

    virtual ~Data() override;

    /// @see Super.
    virtual void
    fromDict(const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& dict)
        override;

    /// @see Super.
    virtual boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>
    toDict() const override;

    /// @see Super.
    virtual std::vector<std::string> getKeys() const override;

    /// @see Super.
    virtual std::shared_ptr<IProperty>
    readProperty(const std::string& key) const override;

    /// @see Super.
    virtual void
    writePropery(const std::string& key,
                 const std::shared_ptr<IProperty>& property) override;

private:
    std::map<std::string, std::shared_ptr<IProperty>> properties_;
};
} // namespace sf

#endif /* SF_DATA_HPP */
