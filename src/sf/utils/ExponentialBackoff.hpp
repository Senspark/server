//
//  ExponentialBackoff.hpp
//  server
//
//  Created by eps on 3/14/18.
//

#ifndef SF_EXPONENTIAL_BACKOFF_HPP
#define SF_EXPONENTIAL_BACKOFF_HPP

#include <memory>

#include "sf/Forward.hpp"

namespace sf {
class ExponentialBackoff {
private:
    using Self = ExponentialBackoff;
    
public:
    class Options;
    
    explicit ExponentialBackoff(const Options& options);
    
    /// Resets this exponential backoff.
    void reset();
    
    /// Returns the next interval.
    float next();
    
private:
    float interval_;
    std::unique_ptr<Options> options_;
    std::unique_ptr<RandomHelper> randomHelper_;
};
} // namespace sf

#endif /* SF_EXPONENTIAL_BACKOFF_HPP */
