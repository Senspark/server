//
//  ILogger.h
//  server
//
//  Created by eps on 3/16/18.
//

#ifndef SF_I_LOGGER_HPP
#define SF_I_LOGGER_HPP

#include <functional>
#include <string>

namespace sf {
class ILogger {
private:
    using Self = ILogger;

public:
    using LogCallback = std::function<void(const std::string& message)>;

    virtual ~ILogger() = default;

    virtual Self& onLogged(const LogCallback& callback) = 0;
};
} // namespace sf

#endif /* SF_I_LOGGER_HPP */
