//
//  IEventDispatcher.hpp
//  server
//
//  Created by eps on 3/8/18.
//

#ifndef SF_I_EVENT_DISPATCHER_HPP
#define SF_I_EVENT_DISPATCHER_HPP

#include <map>
#include <memory>
#include <string>

#include "sf/Macro.hpp"
#include "sf/Forward.hpp"

namespace sf {
class IEventDispatcher {
public:
    using Parameter =
        boost::shared_ptr<std::map<std::string, boost::shared_ptr<void>>>;

    virtual ~IEventDispatcher() = default;

    /// Process pending events.
    virtual void processEvents() = 0;

    /// Attempts to add an event listener.
    /// @param[in] listener The listener to be added.
    virtual bool addListener(const std::shared_ptr<IListener>& listener) = 0;

    /// Attempts to remove an event listener.
    /// @param[in] listener The listener to be removed.
    virtual bool removeListener(const std::shared_ptr<IListener>& listener) = 0;
};
} // namespace sf

#endif /* SF_I_EVENT_DISPATCHER_HPP */
