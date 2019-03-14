//
//  LoginManager.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/5/18.
//

#ifndef SF_CONNECTION_MANAGER_HPP
#define SF_CONNECTION_MANAGER_HPP

#include "sf/connection/IConnectionManager.hpp"

namespace sf {
class ConnectionManager : public IConnectionManager {
private:
    using Self = ConnectionManager;

public:
    explicit ConnectionManager(std::unique_ptr<IConnection> server,
                               std::unique_ptr<IConnection> facebook);

    virtual ~ConnectionManager() override;
    
    /// @see Super.
    virtual ConnectionState getConnectionState() const override;

    /// @see Super.
    virtual IConnection& getServerConnection() override;

    /// @see Super.
    virtual IConnection& getFacebookConnection() override;

protected:
private:
    ConnectionState state_;
    
    std::unique_ptr<IConnection> server_;
    std::unique_ptr<IConnection> facebook_;
    std::unique_ptr<IConnection> guardedServer_;
    std::unique_ptr<IConnection> guardedFacebook_;
};
} // namespace sf

#endif /* SF_CONNECTION_MANAGER_HPP */
