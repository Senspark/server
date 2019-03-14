//
//  GuardedConnectionBridge.hpp
//  server
//
//  Created by eps on 3/14/18.
//

#ifndef SF_GUARDED_CONNECTION_HPP
#define SF_GUARDED_CONNECTION_HPP

#include "sf/connection/IConnection.hpp"

namespace sf {
class GuardedConnection : public IConnection {
private:
    using Self = GuardedConnection;

public:
    explicit GuardedConnection(IConnection& connection);

    virtual ~GuardedConnection() override;

    /// @see Super.
    virtual std::string getUserId() const override;

    /// @see Super.
    virtual bool isLoggedIn() const override;

    /// @see Super.
    virtual void logIn(const LogCallback& callback) override;

    /// @see Super.
    virtual void logOut(const LogCallback& callback) override;

private:
    bool isLoggingIn_;
    bool isLoggingOut_;

    IConnection& connection_;
};
} // namespace sf

#endif /* SF_GUARDED_CONNECTION_HPP */
