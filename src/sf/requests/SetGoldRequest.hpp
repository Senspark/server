//
//  RequestMoney.hpp
//  climber
//
//  Created by Zinge on 12/14/17.
//
//

#ifndef SF_SET_GOLD_REQUEST_HPP
#define SF_SET_GOLD_REQUEST_HPP

#include "sf/core/IRequest.hpp"

namespace sf {
class SetGoldRequest : public IRequest {
private:
    using Self = SetGoldRequest;

public:
    class Parser;

    static const std::string RequestId;

    SetGoldRequest();

    Self& setUserId(const std::string& value);
    Self& setAmount(int value);

    /// @see Super.
    virtual std::string getRequestId() const override;
    
    /// @see Super.
    virtual Parameter build() const override;

private:
    std::string userId_;
    int amount_;
};

class SetGoldRequest::Parser : public IParser {
private:
    using Super = IParser;

public:
    explicit Parser(
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object);

    bool success() const;
    int getAmount() const;

private:
    bool success_;
    int amount_;
};
} // namespace sf

#endif /* SF_SET_GOLD_REQUEST_HPP */
