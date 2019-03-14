//
//  EventDispatcher.hpp
//  server
//
//  Created by eps on 3/8/18.
//

#ifndef SF_EVENT_DISPATCHER_HPP
#define SF_EVENT_DISPATCHER_HPP

#include <set>

#include "sf/core/IEventDispatcher.hpp"

namespace sf {
class EventDispatcher : public IEventDispatcher {
private:
    using Self = EventDispatcher;

public:
    explicit EventDispatcher(Sfs2X::Core::IDispatchable& dispatcher);

    virtual ~EventDispatcher() override;

    void onEvent(int eventId, const Parameter& params);

    /// @see Super.
    virtual void processEvents() override;

    /// @see Super.
    virtual bool
    addListener(const std::shared_ptr<IListener>& listener) override;

    /// @see Super.
    virtual bool
    removeListener(const std::shared_ptr<IListener>& listener) override;

protected:
    bool addListenerImmediately(const std::shared_ptr<IListener>& listener);
    bool removeListenerImmediately(const std::shared_ptr<IListener>& listener);

private:
    Sfs2X::Core::IDispatchable& dispatcher_;

    std::unique_ptr<BiMap<boost::shared_ptr<std::string>>> listenerMap_;
    std::map<boost::shared_ptr<std::string>,
             std::set<std::shared_ptr<IListener>>>
        listeners_;

    std::set<std::shared_ptr<IListener>> toBeAddedListeners_;
    std::set<std::shared_ptr<IListener>> toBeRemovedListeners_;
};
} // namespace sf

#endif /* SF_EVENT_DISPATCHER_HPP */
