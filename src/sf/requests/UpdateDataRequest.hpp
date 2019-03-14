//
//  SFUpdateUserInfoRequest.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/7/18.
//

#ifndef SF_UPDATE_DATA_REQUEST_HPP
#define SF_UPDATE_DATA_REQUEST_HPP

#include "sf/core/IRequest.hpp"

namespace sf {
class UpdateDataRequest : public IRequest {
private:
    using Self = UpdateDataRequest;

public:
    class Parser;

    static const std::string RequestId;

    UpdateDataRequest();

    Self& setUserId(const std::string& value);
    Self& setData(const std::shared_ptr<IData>& value);

    /// @see Super.
    virtual std::string getRequestId() const override;

    /// @see Super.
    virtual Parameter build() const override;

private:
    std::string userId_;
    std::shared_ptr<IData> data_;
};

class UpdateDataRequest::Parser : public IParser {
private:
    using Self = Parser;
    using Super = IParser;

public:
    explicit Parser(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object);

    bool success() const;
    int getTimestamp() const;

private:
    bool success_;
    int timestamp_;
};
} // namespace sf

#endif /* SF_UPDATE_DATA_REQUEST_HPP */
