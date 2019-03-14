//
//  LoginListener.hpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#ifndef SF_LOGIN_LISTENER_HPP
#define SF_LOGIN_LISTENER_HPP

#include <functional>

#include "sf/core/IListener.hpp"

namespace sf {
class LoginListener : public IListener {
public:
    using Callback = std::function<void(
        const boost::shared_ptr<Sfs2X::Entities::User>& user)>;

    explicit LoginListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_LOGIN_LISTENER_HPP */
