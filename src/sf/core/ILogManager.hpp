//
//  ILogManager.hpp
//  server
//
//  Created by eps on 3/16/18.
//

#ifndef SF_I_LOG_MANAGER_HPP
#define SF_I_LOG_MANAGER_HPP

#include <memory>

#include "sf/Forward.hpp"

namespace sf {
class ILogManager {
public:
    virtual ~ILogManager() = default;

    virtual std::shared_ptr<ILogger> createLogger() = 0;
};
} // namespace

#endif /* SF_I_LOG_MANAGER_HPP */
