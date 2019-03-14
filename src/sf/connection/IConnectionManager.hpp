//
//  ILoginManager.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/5/18.
//

#ifndef SF_I_CONNECTION_MANAGER_HPP
#define SF_I_CONNECTION_MANAGER_HPP

#include <functional>

#include "sf/Forward.hpp"

namespace sf {
class IConnectionManager {
public:
    using StateChangedCallback = std::function<void(ConnectionState state)>;
    
    virtual ~IConnectionManager() = default;

    virtual ConnectionState getConnectionState() const = 0;
    virtual IConnection& getServerConnection() = 0;
    virtual IConnection& getFacebookConnection() = 0;
};
} // namespace sf

#endif /* SF_I_CONNECTION_MANAGER_HPP */
