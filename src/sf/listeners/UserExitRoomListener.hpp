//
//  SFUserExitRoomListener.hpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#ifndef SF_USER_EXIT_ROOM_LISTENER_HPP
#define SF_USER_EXIT_ROOM_LISTENER_HPP

#include "sf/core/IListener.hpp"

namespace sf {
class UserExitRoomListener : public IListener {
public:
    using Callback = std::function<void(
        const boost::shared_ptr<Sfs2X::Entities::User>& user,
        const boost::shared_ptr<Sfs2X::Entities::Room>& room)>;

    explicit UserExitRoomListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_USER_EXIT_ROOM_LISTENER_HPP */
