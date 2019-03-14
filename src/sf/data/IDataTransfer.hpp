//
//  IDataFetcher.h
//  server
//
//  Created by eps on 3/15/18.
//

#ifndef SF_I_DATA_TRANSFER_HPP
#define SF_I_DATA_TRANSFER_HPP

#include <functional>

#include <sf/Forward.hpp>

namespace sf {
class IDataTransfer {
private:
    using Self = IDataTransfer;

public:
    using FailureCallback = std::function<void()>;
    using SuccessCallback =
        std::function<void(const std::shared_ptr<IData>& data)>;

    virtual ~IDataTransfer() = default;

    /// Occurs when the operation has failed.
    virtual Self& onFailure(const FailureCallback& callback) = 0;

    /// Occurs when the operation has succeeded.
    virtual Self& onSuccess(const SuccessCallback& callback) = 0;
};

class IDataFetcher : public IDataTransfer {
private:
    using Self = IDataFetcher;

public:
    /// @see Super.
    virtual Self& onFailure(const FailureCallback& callback) = 0;

    /// @see Super.
    virtual Self& onSuccess(const SuccessCallback& callback) = 0;

    /// Starts the operation.
    virtual void start() = 0;
};

class IDataPusher : public IDataTransfer {
private:
    using Self = IDataPusher;
    
public:
    /// @see Super.
    virtual Self& onFailure(const FailureCallback& callback) = 0;

    /// @see Super.
    virtual Self& onSuccess(const SuccessCallback& callback) = 0;

    /// Starts the operation.
    virtual void start(const std::shared_ptr<IData>& data) = 0;
};

class IDataSyncer : public IDataTransfer {
private:
    using Self = IDataSyncer;

public:
    using ResolveCallback =
        std::function<void(const std::shared_ptr<IData>& localData,
                           const std::shared_ptr<IData>& cloudData,
                           const std::shared_ptr<IDataResolver>& resolver)>;

    /// @see Super.
    virtual Self& onFailure(const FailureCallback& callback) = 0;

    /// @see Super.
    virtual Self& onSuccess(const SuccessCallback& callback) = 0;

    /// Occurs when there is a data confliction.
    virtual Self& onConfliction(const ResolveCallback& callback) = 0;

    /// Starts the operation.
    virtual void start(const std::shared_ptr<IData>& data) = 0;
};
} // namespace sf

#endif /* SF_I_DATA_TRANSFER_HPP */
