//
//  Logger.hpp
//  server
//
//  Created by eps on 3/16/18.
//

#ifndef SF_LOGGER_HPP
#define SF_LOGGER_HPP

#include "sf/core/ILogger.hpp"

namespace sf {
class LogManager;

class Logger : public ILogger {
private:
    using Self = Logger;

public:
    virtual ~Logger() override;

    virtual Self& onLogged(const LogCallback& callback) override;

protected:
    friend LogManager;

    void log(const std::string& message);

private:
    LogCallback logCallback_;
};
} // namespace sf

#endif /* SF_LOGGER_HPP */
