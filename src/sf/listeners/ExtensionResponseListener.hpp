//
//  SFExtensionResponseListener.hpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#ifndef SF_EXTENSION_RESPONSE_LISTENER_HPP
#define SF_EXTENSION_RESPONSE_LISTENER_HPP

#include "sf/core/IListener.hpp"

namespace sf {
class ExtensionResponseListener : public IListener {
public:
    using Callback = std::function<void(
        const std::string& cmd,
        const boost::shared_ptr<Sfs2X::Entities::Data::ISFSObject>& object)>;

    static const boost::shared_ptr<std::string>& Type;

    explicit ExtensionResponseListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_EXTENSION_RESPONSE_LISTENER_HPP */
