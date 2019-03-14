//
//  RequestHandler.hpp
//  server
//
//  Created by eps on 3/8/18.
//

#ifndef SF_REQUEST_HANDLER_HPP
#define SF_REQUEST_HANDLER_HPP

#include <map>
#include <memory>

#include "sf/core/IRequestHandler.hpp"

namespace sf {
class RequestHandler : public IRequestHandler {
private:
public:
    explicit RequestHandler(IEventDispatcher& dispatcher,
                            Sfs2X::SmartFox& client);

    virtual ~RequestHandler() override;

    /// @see Super.
    virtual void sendRequest(const IRequest& request) override;

    /// @see Super.
    virtual void sendRequest(const IRequest& request,
                             const RequestCallback& callback) override;

protected:
private:
    IEventDispatcher& dispatcher_;
    Sfs2X::SmartFox& client_;
    std::shared_ptr<ExtensionResponseListener> extensionListener_;
    std::map<int, RequestCallback> callbacks_;
};
} // namespace sf

#endif /* SF_REQUEST_HANDLER_HPP */
