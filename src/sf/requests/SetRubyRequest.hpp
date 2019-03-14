//
//  SFSetRubyRequest.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

#ifndef SF_SET_RUBY_REQUEST_HPP
#define SF_SET_RUBY_REQUEST_HPP

#include "sf/core/IRequest.hpp"

namespace sf {
class SetRubyRequest : public IRequest {
private:
    using Self = SetRubyRequest;

public:
    class Parser;

    static const std::string RequestId;

    SetRubyRequest();

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

class SetRubyRequest::Parser : public IParser {
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

#endif /* SF_SET_RUBY_REQUEST_HPP */
