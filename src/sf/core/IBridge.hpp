//
//  IBridge.h
//  server
//
//  Created by eps on 3/8/18.
//

#ifndef SF_I_BRIDGE_HPP
#define SF_I_BRIDGE_HPP

#include <string>

#include "sf/Macro.hpp"
#include "sf/Forward.hpp"

namespace sf {
class IBridge {
private:
public:
    virtual ~IBridge() = default;
    
    /// Gets the event dispatcher associated with this bridge.
    virtual IEventDispatcher& getEventDispatcher() = 0;
    
    virtual IRequestHandler& getRequestHandler() = 0;
    
    virtual ILogManager& getLogManager() = 0;
    
    virtual std::string getUserId() const = 0;
    
    virtual bool isConnected() const = 0;
    
    /// Attempts to connect to the server.
    virtual void connect() = 0;
    
    virtual void disconnect() = 0;
    
    /// Checks whether the user is logged in the server.
    virtual bool isLoggedIn() const = 0;
    
    /// Attempts to log in the server.
    /// @param[in] userId The user ID.
    /// @param[in] version The application version.
    virtual void logIn(const std::string& userId, int version) = 0;
    
    /// Attempts to log out from the server.
    virtual void logOut() = 0;
};
} // namespace sf

#endif /* SF_I_BRIDGE_HPP */
