//
//  SFKeepAliveRequest.hpp
//  climber
//
//  Created by Zinge on 1/9/18.
//
//

#ifndef SF_KEEP_ALIVE_REQUEST_HPP
#define SF_KEEP_ALIVE_REQUEST_HPP

#include "sf/core/IRequest.hpp"

namespace sf {
/// Used to keep server connection alive.
class KeepAliveRequest : public IRequest {
private:
    using Self = KeepAliveRequest;

public:
    static const std::string RequestId;

    KeepAliveRequest();

    /// @see Super.
    virtual std::string getRequestId() const override;
    
    /// @see Super.
    virtual Parameter build() const override;
};
} // namespace sf

#endif /* SF_KEEP_ALIVE_REQUEST_HPP */
