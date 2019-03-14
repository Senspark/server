//
//  DataSynchronizer.hpp
//  server
//
//  Created by eps on 3/15/18.
//

#ifndef SF_DATA_SYNCER_HPP
#define SF_DATA_SYNCER_HPP

#include <memory>

#include "sf/data/IDataTransfer.hpp"

namespace sf {
class DataSyncer : public IDataSyncer,
                   public std::enable_shared_from_this<DataSyncer> {
private:
    using Self = DataSyncer;

public:
    static std::shared_ptr<Self> create(IBridge& bridge);

    virtual ~DataSyncer() override;

    /// @see Super.
    virtual Self& onFailure(const FailureCallback& callback) override;

    /// @see Super.
    virtual Self& onSuccess(const SuccessCallback& callback) override;

    /// @see Super.
    virtual Self& onConfliction(const ResolveCallback& callback) override;

    /// @see Super.
    virtual void start(const std::shared_ptr<IData>& data) override;

protected:
    explicit DataSyncer(IBridge& bridge);

private:
    void setFailure();
    void setSuccess(const std::shared_ptr<IData>& data);
    void compareData(const std::shared_ptr<IData>& localData,
                     const std::shared_ptr<IData>& cloudData);

    IBridge& bridge_;
    FailureCallback failureCallback_;
    SuccessCallback successCallback_;
    ResolveCallback conflictCallback_;
};
} // namespace sf

#endif /* SF_DATA_SYNCER_HPP */
