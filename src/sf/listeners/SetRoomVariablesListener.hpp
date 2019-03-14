//
//  SFSetRoomVariablesListener.hpp
//  climber
//
//  Created by Zinge on 12/28/17.
//
//

#ifndef SF_SET_USER_VARIABLES_LISTENER_HPP
#define SF_SET_USER_VARIABLES_LISTENER_HPP

#include <vector>

#include "sf/core/IListener.hpp"

namespace sf {
class SetRoomVariablesListener : public IListener {
public:
    using Callback =
        std::function<void(const boost::shared_ptr<Sfs2X::Entities::Room>& room,
                           const std::vector<std::string>& changedVars)>;

    explicit SetRoomVariablesListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_SET_USER_VARIABLES_LISTENER_HPP */
