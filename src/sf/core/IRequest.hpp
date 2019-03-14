//
//  SmartFoxRequest.hpp
//  climber
//
//  Created by Zinge on 12/14/17.
//
//

#ifndef SF_I_REQUEST_HPP
#define SF_I_REQUEST_HPP

#include <string>

#include "sf/Macro.hpp"
#include "sf/Forward.hpp"

namespace sf {
class IRequest {
public:
    class IParser;

    using Parameter = boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>;

    IRequest();

    virtual ~IRequest() = default;

    /// Gets the unique ID of this request.
    int getId() const;

    /// Gets the unique request ID.
    virtual std::string getRequestId() const = 0;

    /// Obtains request parameters from this request.
    virtual Parameter build() const = 0;

private:
    int id_;
};

class IRequest::IParser {
public:
    explicit IParser(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object);

    /// Gets the unique ID of the original request.
    int getId() const;

private:
    int id_;
};
} // namespace sf

#endif /* SF_I_REQUEST_HPP */
