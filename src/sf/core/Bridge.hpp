//
//  SmartFoxBridge.hpp
//  climber
//
//  Created by Zinge on 12/14/17.
//
//

#ifndef SF_BRIDGE_HPP
#define SF_BRIDGE_HPP

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "sf/core/IBridge.hpp"

#include <boost/shared_ptr.hpp>

namespace sf {
class Bridge : public IBridge {
private:
    using Self = Bridge;

public:
    static Self& getInstance();

    void initialize();
    void process();

    Sfs2X::SmartFox& getClient() const;

    /// @see Super.
    virtual IEventDispatcher& getEventDispatcher() override;
    
    /// @see Super.
    virtual IRequestHandler& getRequestHandler() override;
    
    /// @see Super.
    virtual ILogManager& getLogManager() override;
    
    /// @see Super.
    virtual std::string getUserId() const override;

    /// Returns -1 if the user is not logged in.
    int getLatency() const;

    /// @see Super.
    virtual bool isConnected() const override;
    
    /// @see Super.
    virtual void connect() override;
    
    /// @see Super.
    virtual void disconnect() override;
    
    /// @see Super.
    virtual bool isLoggedIn() const override;

    /// @see Super.
    virtual void logIn(const std::string& userId, int version) override;
    
    /// @see Super.
    virtual void logOut() override;

    void
    sendRequest(const boost::shared_ptr<Sfs2X::Requests::IRequest>& request);
    
    void onLogged(const std::string& message);

protected:
    Bridge();
    ~Bridge();

    Bridge(const Self&) = delete;
    Self& operator=(const Self&) = delete;

    void reinitialize();

private:
    bool initialized_;

    // Must be boost::shared_ptr because implemention use
    // boost::enable_shared_from_this
    boost::shared_ptr<Sfs2X::SmartFox> client_;

    std::unique_ptr<IEventDispatcher> eventDispatcher_;
    std::unique_ptr<IRequestHandler> requestHandler_;
    std::unique_ptr<ILogManager> logManager_;

    int latency_;
    std::vector<std::shared_ptr<IListener>> listeners_;
};
} // namespace sf

#endif /* SF_BRIDGE_HPP */
