//
//  LogManager.hpp
//  server
//
//  Created by eps on 3/16/18.
//

#ifndef SF_LOG_MANAGER_HPP
#define SF_LOG_MANAGER_HPP

#include <string>
#include <vector>

#include "sf/core/ILogManager.hpp"

namespace sf {
class LogManager : public ILogManager {
public:
    virtual ~LogManager() override;

    virtual std::shared_ptr<ILogger> createLogger() override;

protected:
    friend Bridge;

    void log(const std::string& message);

private:
    std::vector<std::weak_ptr<ILogger>> loggers_;
};
} // namespace sf

#endif /* SF_LOG_MANAGER_HPP */
