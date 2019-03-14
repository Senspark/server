//
//  SFLoginFlow.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/1/18.
//

#ifndef SF_LOGIN_FLOW_HPP
#define SF_LOGIN_FLOW_HPP

#include <functional>
#include <memory>
#include <string>

#include "sf/Macro.hpp"
#include "sf/Forward.hpp"

namespace sf {
class LoginFlow : public std::enable_shared_from_this<LoginFlow> {
private:
    using Self = LoginFlow;

public:
    using LoginCallback = std::function<void(bool success)>;

    static std::shared_ptr<Self> create(IBridge& bridge);

    ~LoginFlow();

    /// Sets the username.
    Self& setUserId(const std::string& id);

    /// Sets the local version.
    Self& setVersion(int version);

    Self& setCallback(const LoginCallback& callback);

    void start();

protected:
    explicit LoginFlow(IBridge& bridge);
    
    void registerListeners();
    void deregisterListeners();

    void onConnection(bool success);
    void onConnectionLost(const std::string& reason);
    void onLogin(const boost::shared_ptr<Sfs2X::Entities::User>& user);
    void onLoginError(int errorCode, const std::string& errorMessage);

private:
    IBridge& bridge_;
    std::string userId_;
    int version_;
    LoginCallback loginCallback_;

    std::shared_ptr<ConnectionListener> connectionListener_;
    std::shared_ptr<ConnectionLostListener> connectionLostListener_;
    std::shared_ptr<LoginListener> loginListener_;
    std::shared_ptr<LoginErrorListener> loginErrorListener_;
};
} // namespace sf

#endif /* SF_LOGIN_FLOW_HPP */
