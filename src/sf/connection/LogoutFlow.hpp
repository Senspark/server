//
//  LogoutFlow.hpp
//  server
//
//  Created by eps on 3/9/18.
//

#ifndef SF_LOGOUT_FLOW_HPP
#define SF_LOGOUT_FLOW_HPP

#include <functional>
#include <memory>
#include <string>

#include "sf/Macro.hpp"
#include "sf/Forward.hpp"

namespace sf {
class LogoutFlow : public std::enable_shared_from_this<LogoutFlow> {
private:
    using Self = LogoutFlow;

public:
    using LogoutCallback = std::function<void(bool success)>;

    static std::shared_ptr<Self> create(IBridge& bridge);

    ~LogoutFlow();

    Self& setCallback(const LogoutCallback& callback);

    void start();

protected:
    explicit LogoutFlow(IBridge& bridge);
    
    void registerListeners();
    void deregisterListeners();

    void onConnectionLost(const std::string& reason);
    void onLogout();

private:
    IBridge& bridge_;
    LogoutCallback logoutCallback_;

    std::shared_ptr<ConnectionLostListener> connectionLostListener_;
    std::shared_ptr<LogoutListener> logoutListener_;
};
} // namespace sf

#endif /* SF_LOGOUT_FLOW_HPP */
