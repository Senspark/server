//
//  IUserManager.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/5/18.
//

#ifndef SF_I_LOGIN_INFO_HPP
#define SF_I_LOGIN_INFO_HPP

#include <string>

#include "sf/Forward.hpp"

namespace sf {
class ILoginInfo {
public:
    virtual ~ILoginInfo() = default;

    /// Gets the user unique ID (typically Facebook ID).
    /// Empty if not available.
    virtual std::string getUserId() const = 0;

    /// Gets the current application version.
    virtual int getVersion() const = 0;
};
} // namespace sf

#endif /* SF_I_LOGIN_INFO_HPP */
