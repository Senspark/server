//
//  DataPusher.hpp
//  server
//
//  Created by eps on 3/15/18.
//

#ifndef SF_DATA_PUSHER_HPP
#define SF_DATA_PUSHER_HPP

#include <memory>

#include "sf/data/IDataTransfer.hpp"

namespace sf {
class DataPusher : public IDataPusher,
                   public std::enable_shared_from_this<DataPusher> {
private:
    using Self = DataPusher;

public:
    static std::shared_ptr<Self> create(IBridge& bridge);

    virtual ~DataPusher() override;

    /// @see Super.
    virtual Self& onFailure(const FailureCallback& callback) override;

    /// @see Super.
    virtual Self& onSuccess(const SuccessCallback& callback) override;

    /// @see Super.
    virtual void start(const std::shared_ptr<IData>& data) override;

protected:
    explicit DataPusher(IBridge& bridge);

private:
    IBridge& bridge_;
    FailureCallback failureCallback_;
    SuccessCallback successCallback_;
};
} // namespace sf

#endif /* SF_DATA_PUSHER_HPP */
