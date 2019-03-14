//
//  IDataConflictResolver.hpp
//  server
//
//  Created by eps on 3/15/18.
//

#ifndef SF_I_DATA_RESOLVER_HPP
#define SF_I_DATA_RESOLVER_HPP

#include "sf/Macro.hpp"
#include "sf/Forward.hpp"

namespace sf {
class IDataResolver {
public:
    virtual ~IDataResolver() = default;

    virtual void useLocal() = 0;
    virtual void useCloud() = 0;
};
} // namespace sf

#endif /* SF_I_DATA_RESOLVER_HPP */
