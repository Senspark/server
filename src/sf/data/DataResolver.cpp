//
//  DataConflictResolver.cpp
//  server
//
//  Created by eps on 3/15/18.
//

#include "sf/data/DataResolver.hpp"

namespace sf {
using Self = DataResolver;

Self::DataResolver(const SelectCallback& callback)
    : selectCallback_(callback) {
    selected_ = false;
}

Self::~DataResolver() {
    if (not selected_) {
        selectCallback_(true);
    }
}

void Self::useLocal() {
    SF_ASSERT(not selected_);
    selected_ = true;
    selectCallback_(true);
}

void Self::useCloud() {
    SF_ASSERT(not selected_);
    selected_ = true;
    selectCallback_(false);
}
} // namespace sf
