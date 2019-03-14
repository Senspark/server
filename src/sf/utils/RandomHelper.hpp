//
//  RandomHelper.hpp
//  server
//
//  Created by eps on 3/14/18.
//

#ifndef SF_RANDOM_HELPER_HPP
#define SF_RANDOM_HELPER_HPP

#include <random>

namespace sf {
class RandomHelper {
public:
    RandomHelper();

    explicit RandomHelper(int seed);

    template <class T>
    T randomFloat(T min, T max) {
        std::uniform_real_distribution<T> dist(min, max);
        return dist(engine_);
    }

    template <class T>
    T randomInt(T min, T max) {
        std::uniform_int_distribution<T> dist(min, max);
        return dist(engine_);
    }

private:
    std::mt19937 engine_;
};
} // namespace sf

#endif /* SF_RANDOM_HELPER_HPP */
