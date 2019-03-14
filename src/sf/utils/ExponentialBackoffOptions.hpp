//
//  ExponentialBackoff.hpp
//  server
//
//  Created by eps on 3/14/18.
//

#ifndef SF_EXPONENTIAL_BACKOFF_OPTIONS_HPP
#define SF_EXPONENTIAL_BACKOFF_OPTIONS_HPP

#include "sf/utils/ExponentialBackoff.hpp"

namespace sf {
class ExponentialBackoff::Options {
private:
    using Self = Options;

public:
    Options();
    ~Options();
    
    Self& setInterval(float value);
    Self& setMaxInterval(float value);
    Self& setMultiplier(float value);
    Self& setRandomRange(float value);

private:
    friend ExponentialBackoff;
    
    float interval_;
    float maxInterval_;
    float multiplier_;
    float randomRange_;
};
} // namespace sf

#endif /* SF_EXPONENTIAL_BACKOFF_OPTIONS_HPP */
