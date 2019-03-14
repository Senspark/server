//
//  ExponentialBackoff.cpp
//  server
//
//  Created by eps on 3/14/18.
//

#include "sf/utils/ExponentialBackoff.hpp"
#include "sf/utils/ExponentialBackoffOptions.hpp"
#include "sf/utils/RandomHelper.hpp"

namespace sf {
using Self = ExponentialBackoff;

Self::ExponentialBackoff(const Options& options) {
    options_ = std::make_unique<Options>(options);
    randomHelper_ = std::make_unique<RandomHelper>();
    reset();
}

void Self::reset() {
    interval_ = 0.0f;
}

float Self::next() {
    if (interval_ == 0.0f) {
        interval_ = options_->interval_;
    } else {
        interval_ = interval_ * options_->multiplier_;
    }
    interval_ = std::min(interval_, options_->maxInterval_);
    return interval_ + randomHelper_->randomFloat(0.0f, options_->randomRange_);
}
} // namespace sf
