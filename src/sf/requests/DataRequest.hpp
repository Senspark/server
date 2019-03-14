//
//  SFUserInfoRequest.hpp
//  climber
//
//  Created by Zinge on 12/22/17.
//
//

#ifndef SF_USER_REQUEST_HPP
#define SF_USER_REQUEST_HPP

#include "sf/core/IRequest.hpp"

namespace sf {
class DataRequest : public IRequest {
private:
    using Self = DataRequest;

public:
    class Parser;

    static const std::string RequestId;

    DataRequest();

    Self& setUserId(const std::string& value);

    /// @see Super.
    virtual std::string getRequestId() const override;

    /// @see Super.
    virtual Parameter build() const override;

private:
    std::string userId_;
};

class DataRequest::Parser : public IParser {
private:
    using Self = Parser;
    using Super = IParser;

public:
    explicit Parser(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object);

    bool success() const;
    const std::string& getUserId() const;
    const std::shared_ptr<IData>& getData() const;

private:
    bool success_;
    std::string userId_;
    std::shared_ptr<IData> data_;
};
} // namespace sf

#endif /* SF_DATA_REQUEST_HPP */
