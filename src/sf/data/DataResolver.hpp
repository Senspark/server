//
//  DataConflictResolver.hpp
//  server
//
//  Created by eps on 3/15/18.
//

#ifndef SF_DATA_RESOLVER_HPP
#define SF_DATA_RESOLVER_HPP

#include <functional>

#include "sf/data/IDataResolver.hpp"

namespace sf {
class DataResolver : public IDataResolver {
public:
    using SelectCallback = std::function<void(bool useLocal)>;

    explicit DataResolver(const SelectCallback& callback);
    
    virtual ~DataResolver() override;

    /// @see Super.
    virtual void useLocal() override;

    /// @see Super.
    virtual void useCloud() override;

private:
    bool selected_;
    SelectCallback selectCallback_;
};
} // namespace sf

#endif /* SF_DATA_RESOLVER_HPP */
