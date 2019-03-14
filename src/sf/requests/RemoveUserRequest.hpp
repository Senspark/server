//
//  SFRemoveUserRequest.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

#ifndef SF_REMOVE_USER_REQUEST_HPP
#define SF_REMOVE_USER_REQUEST_HPP

#include "sf/core/IRequest.hpp"

namespace sf {
class RemoveUserRequest : public IRequest {
private:
    using Self = RemoveUserRequest;

public:
    class Parser;

    static const std::string RequestId;

    RemoveUserRequest();

    Self& setName(const std::string& value);

    /// @see Super.
    virtual std::string getRequestId() const override;
    
    /// @see Super.
    virtual Parameter build() const override;

private:
    std::string name_;
};

class RemoveUserRequest::Parser : public IParser {
private:
    using Super = IParser;

public:
    explicit Parser(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object);

    bool success() const;

private:
    bool success_;
};
} // namespace sf

#endif /* SF_REMOVE_USER_REQUEST_HPP */
