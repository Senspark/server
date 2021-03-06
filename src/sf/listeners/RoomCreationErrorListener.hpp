//
//  SFRoomCreationError.hpp
//  climber
//
//  Created by Zinge on 12/28/17.
//
//

#ifndef SF_ROOM_CREATION_ERROR_LISTENER_HPP
#define SF_ROOM_CREATION_ERROR_LISTENER_HPP

#include "sf/core/IListener.hpp"

namespace sf {
class RoomCreationErrorListener : public IListener {
public:
    using Callback = std::function<void(const std::string& errorMessage)>;

    explicit RoomCreationErrorListener(const Callback& callback)
        : callback_(callback) {}

    virtual const boost::shared_ptr<std::string>& getType() const override;

    virtual void onEvent(const Parameter& params) override;

private:
    Callback callback_;
};
} // namespace sf

#endif /* SF_ROOM_CREATION_ERROR_LISTENER_HPP */
