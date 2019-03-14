//
//  LogManager.cpp
//  server
//
//  Created by eps on 3/16/18.
//

#include "sf/core/LogManager.hpp"
#include "sf/core/Logger.hpp"

namespace sf {
using Self = LogManager;

Self::~LogManager() {}

std::shared_ptr<ILogger> Self::createLogger() {
    auto logger = std::make_shared<Logger>();
    loggers_.emplace_back(logger);
    return logger;
}

void Self::log(const std::string& message) {
    for (std::size_t i = 0; i < loggers_.size(); ++i) {
        auto&& item = loggers_.at(i);
        if (item.expired()) {
            std::swap(item, loggers_.back());
            loggers_.pop_back();
            --i;
        } else {
            auto ptr = std::static_pointer_cast<Logger>(item.lock());
            ptr->log(message);
        }
    }
}
} // namespace sf
