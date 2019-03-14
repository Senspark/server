//
//  ServerLoginFlow.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/5/18.
//

#ifndef SF_SERVER_CONNECTION_HPP
#define SF_SERVER_CONNECTION_HPP

#include "sf/connection/IConnection.hpp"

namespace sf {
class ServerConnection : public IConnection {
private:
    using Self = ServerConnection;

public:
    explicit ServerConnection(IBridge& bridge,
                              std::unique_ptr<ILoginInfo> info);

    virtual ~ServerConnection() override;

    /// @see Super.
    virtual std::string getUserId() const override;

    /// @see Super.
    virtual bool isLoggedIn() const override;

    /// @see Super.
    virtual void logIn(const LogCallback& callback) override;

    /// @see Super.
    virtual void logOut(const LogCallback& callback) override;

private:
    IBridge& bridge_;
    std::unique_ptr<ILoginInfo> info_;
};
} // namespace sf

#endif /* SF_SERVER_CONNECTION_HPP */
