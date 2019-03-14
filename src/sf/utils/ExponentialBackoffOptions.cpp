//
//  ExponentialBackoff.cpp
//  server
//
//  Created by eps on 3/14/18.
//

#include "sf/utils/ExponentialBackoffOptions.hpp"

namespace sf {
using Self = ExponentialBackoff::Options;

Self::Options() {
    setInterval(1.0f);
    setMaxInterval(30.0f);
    setMultiplier(2.0f);
    setRandomRange(1.0f);
}

Self::~Options() {}

Self& Self::setInterval(float value) {
    interval_ = value;
    return *this;
}

Self& Self::setMaxInterval(float value) {
    maxInterval_ = value;
    return *this;
}

Self& Self::setMultiplier(float value) {
    multiplier_ = value;
    return *this;
}

Self& Self::setRandomRange(float value) {
    randomRange_ = value;
    return *this;
}
} // namespace sf
