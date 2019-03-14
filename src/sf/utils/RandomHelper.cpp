//
//  RandomHelper.cpp
//  server
//
//  Created by eps on 3/14/18.
//

#include "sf/utils/RandomHelper.hpp"

namespace sf {
using Self = RandomHelper;

Self::RandomHelper()
    : Self(static_cast<int>(std::random_device()())) {}

Self::RandomHelper(int seed)
    : engine_(static_cast<std::mt19937::result_type>(seed)) {}
} // namespace sf
