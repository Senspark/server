//
//  SFAsyncManager.hpp
//  gold-miner-vegas
//
//  Created by eps on 3/2/18.
//

#ifndef SF_ASYNC_MANAGER_HPP
#define SF_ASYNC_MANAGER_HPP

#include <functional>
#include <map>

#include "sf/Forward.hpp"

namespace sf {
template <class... Args>
class AsyncCallback {
private:
    using Self = AsyncCallback;
    using SuccessCallback = std::function<void(Args...)>;
    using FailureCallback = std::function<void()>;

public:
    AsyncCallback() {
        onSuccess(std::bind([] {
            // Empty.
        }));
        onFailure(std::bind([] {
            // Empty.
        }));
    }

    Self& onSuccess(const SuccessCallback& callback) {
        successCallback_ = callback;
        return *this;
    }

    Self& onFailure(const FailureCallback& callback) {
        failureCallback_ = callback;
        return *this;
    }

private:
    friend AsyncManager<Args...>;

    SuccessCallback successCallback_;
    FailureCallback failureCallback_;
};

template <class... Args>
class AsyncManager {
public:
    using Callback = AsyncCallback<Args...>;

    bool push(int id, const Callback& callback) {
        callbacks_.emplace(id, callback);
        return true;
    }

    template <class... Ts>
    bool succeed(int id, Ts... args) {
        auto iter = callbacks_.find(id);
        if (iter != callbacks_.cend()) {
            iter->second.successCallback_(std::forward<Ts>(args)...);
            callbacks_.erase(iter);
            return true;
        }
        return false;
    }

    bool fail(int id) {
        auto iter = callbacks_.find(id);
        if (iter != callbacks_.cend()) {
            iter->second.failureCallback_();
            callbacks_.erase(iter);
            return true;
        }
        return false;
    }

private:
    std::map<int, Callback> callbacks_;
};
} // namespace sf

#endif /* SF_ASYNC_MANAGER_HPP */
