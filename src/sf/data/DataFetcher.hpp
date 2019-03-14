//
//  DataFetcher.hpp
//  server
//
//  Created by eps on 3/15/18.
//

#ifndef SF_DATA_FETCHER_HPP
#define SF_DATA_FETCHER_HPP

#include <memory>

#include "sf/data/IDataTransfer.hpp"

namespace sf {
class DataFetcher : public IDataFetcher,
                    public std::enable_shared_from_this<DataFetcher> {
private:
    using Self = DataFetcher;

public:
    static std::shared_ptr<Self> create(IBridge& bridge);

    virtual ~DataFetcher() override;

    /// @see Super.
    virtual Self& onFailure(const FailureCallback& callback) override;

    /// @see Super.
    virtual Self& onSuccess(const SuccessCallback& callback) override;

    /// @see Super.
    virtual void start() override;

protected:
    explicit DataFetcher(IBridge& bridge);

private:
    IBridge& bridge_;
    FailureCallback failureCallback_;
    SuccessCallback successCallback_;
};
} // namespace sf

#endif /* SF_DATA_FETCHER_HPP */
