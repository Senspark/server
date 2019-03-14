//
//  SFPingPongListener.hpp
//  climber
//
//  Created by Zinge on 1/8/18.
//
//

#ifndef SF_PING_PONG_LISTENER_HPP
#define SF_PING_PONG_LISTENER_HPP

#include "sf/core/IListener.hpp"

namespace sf {
class PingPongListener : public IListener {
public:
    using Callback = std::function<void(int lagValue)>;

    explicit PingPongListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_PING_PONG_LISTENER_HPP */
