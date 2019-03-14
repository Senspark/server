//
//  EventDispatcher.cpp
//  server
//
//  Created by eps on 3/8/18.
//

#include "sf/core/EventDispatcher.hpp"
#include "sf/core/IListener.hpp"
#include "sf/core/Bridge.hpp"
#include "sf/utils/BiMap.hpp"

#include <boost/make_shared.hpp>

#include <smartfox/Core/IDispatchable.h>

namespace sf {
using Self = EventDispatcher;

Self::EventDispatcher(Sfs2X::Core::IDispatchable& dispatcher)
    : dispatcher_(dispatcher) {
    listenerMap_ = std::make_unique<BiMap<boost::shared_ptr<std::string>>>();
}

Self::~EventDispatcher() {
    //
}

void Self::processEvents() {
    for (auto&& listener : toBeAddedListeners_) {
        auto result = addListenerImmediately(listener);
        SF_ASSERT(result);
    }
    for (auto&& listener : toBeRemovedListeners_) {
        auto result = removeListenerImmediately(listener);
        SF_ASSERT(result);
    }
    toBeAddedListeners_.clear();
    toBeRemovedListeners_.clear();
}

void Self::onEvent(int eventId, const Parameter& params) {
    auto&& type = listenerMap_->find(eventId);
    auto&& listeners = listeners_.at(type);
    for (auto&& listener : listeners) {
        listener->onEvent(params);
    }
}

namespace {
void onEventCallback(unsigned long long context,
                     boost::shared_ptr<Sfs2X::Core::BaseEvent> event) {
    // CCLOG("%s: %s", __PRETTY_FUNCTION__, event->ToString()->c_str());
    auto eventId = static_cast<int>(context);
    auto&& bridge = Bridge::getInstance();
    auto&& dispatcher = static_cast<Self&>(bridge.getEventDispatcher());
    dispatcher.onEvent(eventId, event->Params());
}
} // namespace

bool Self::addListener(const std::shared_ptr<IListener>& listener) {
    SF_ASSERT(listener != nullptr);
    auto iter = toBeAddedListeners_.find(listener);
    if (iter != toBeAddedListeners_.cend()) {
        return false;
    }
    toBeAddedListeners_.insert(listener);
    return true;
}

bool Self::removeListener(const std::shared_ptr<IListener>& listener) {
    SF_ASSERT(listener != nullptr);
    auto iter = toBeRemovedListeners_.find(listener);
    if (iter != toBeRemovedListeners_.cend()) {
        return false;
    }
    toBeRemovedListeners_.insert(listener);
    return true;
}

bool Self::addListenerImmediately(const std::shared_ptr<IListener>& listener) {
    auto&& listeners = listeners_[listener->getType()];
    if (listeners.empty()) {
        auto eventId = listenerMap_->add(listener->getType());
        auto context = static_cast<unsigned long long>(eventId);
        auto delegate = boost::make_shared<Sfs2X::Util::EventListenerDelegate>(
            onEventCallback, context);
        dispatcher_.AddEventListener(listener->getType(), delegate);
    }
    auto iter = listeners.find(listener);
    if (iter != listeners.cend()) {
        return false;
    }
    listeners.insert(listener);
    return true;
}

bool Self::removeListenerImmediately(
    const std::shared_ptr<IListener>& listener) {
    auto&& listeners = listeners_[listener->getType()];
    auto iter = listeners.find(listener);
    if (iter == listeners.cend()) {
        return false;
    }
    listeners.erase(iter);
    return true;
}
} // namespace sf
