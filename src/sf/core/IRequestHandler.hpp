//
//  IRequestHandler.hpp
//  server
//
//  Created by eps on 3/8/18.
//

#ifndef SF_I_REQUEST_HANDLER_HPP
#define SF_I_REQUEST_HANDLER_HPP

#include <functional>

#include "sf/Macro.hpp"
#include "sf/Forward.hpp"

namespace sf {
class IRequestHandler {
public:
    using RequestCallback = std::function<void(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object)>;

    virtual ~IRequestHandler() = default;
    
    /// Attempts to send a request.
    virtual void sendRequest(const IRequest& request) = 0;

    /// Attempts to send a request with a completion callback.
    virtual void sendRequest(const IRequest& request,
                             const RequestCallback& callback) = 0;
};
} // namespace sf

#endif /* SF_I_REQUEST_HANDLER_HPP */
