//
//  SFRoomJoinListener.hpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#ifndef SF_ROOM_JOIN_LISTENER_HPP
#define SF_ROOM_JOIN_LISTENER_HPP

#include "sf/core/IListener.hpp"

namespace sf {
class RoomJoinListener : public IListener {
public:
    using Callback = std::function<void(
        const boost::shared_ptr<Sfs2X::Entities::Room>& room)>;

    explicit RoomJoinListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_ROOM_JOIN_LISTENER_HPP */
