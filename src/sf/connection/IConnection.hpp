//
//  ILoginBridge.h
//  gold-miner-vegas
//
//  Created by eps on 3/7/18.
//

#ifndef SF_I_CONNECTION_HPP
#define SF_I_CONNECTION_HPP

#include <functional>
#include <string>

#include "sf/Forward.hpp"

namespace sf {
class IConnection {
public:
    using LogCallback = std::function<void(bool success)>;

    virtual ~IConnection() = default;
    
    /// Gets the unique user ID for this connection.
    virtual std::string getUserId() const = 0;

    /// Checks whether the user is logged in Facebook.
    virtual bool isLoggedIn() const = 0;

    /// Attempts to log in to Facebook.
    virtual void logIn(const LogCallback& callback) = 0;

    /// Attempts to log out from Facebook.
    virtual void logOut(const LogCallback& callback) = 0;
};
} // namespace sf

#endif /* SF_I_CONNECTION_HPP */
