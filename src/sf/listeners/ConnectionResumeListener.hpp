//
//  ConnectionResumeListener.hpp
//  server
//
//  Created by eps on 3/20/18.
//

#ifndef SF_CONNECTION_RESUME_LISTENER_HPP
#define SF_CONNECTION_RESUME_LISTENER_HPP

#include "sf/core/IListener.hpp"

namespace sf {
class ConnectionResumeListener : public IListener {
public:
    using Callback = std::function<void()>;

    explicit ConnectionResumeListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_CONNECTION_RESUME_LISTENER_HPP */
