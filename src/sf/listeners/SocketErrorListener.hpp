//
//  SocketError.hpp
//  server
//
//  Created by eps on 3/20/18.
//

#ifndef SF_SOCKET_ERROR_LISTENER_HPP
#define SF_SOCKET_ERROR_LISTENER_HPP

#include <functional>

#include "sf/core/IListener.hpp"

namespace sf {
class SocketErrorListener : public IListener {
public:
    using Callback = std::function<void(const std::string& errorMessage)>;

    explicit SocketErrorListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_SOCKET_ERROR_LISTENER_HPP */
