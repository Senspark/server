//
//  SFBiMap.hpp
//  climber
//
//  Created by Zinge on 12/15/17.
//
//

#ifndef SF_BI_MAP_HPP
#define SF_BI_MAP_HPP

#include <map>

namespace sf {
template <class T>
class BiMap {
public:
    BiMap()
        : counter_(0) {}

    ~BiMap() = default;

    int add(const T& value) {
        instanceToId_.emplace(value, counter_);
        idToInstance_.emplace(counter_, value);
        return counter_++;
    }

    int remove(const T& value) {
        auto id = findId(value);
        idToInstance_.erase(id);
        return id;
    }

    const T& find(int id) const { //
        return idToInstance_.at(id);
    }

    int findId(const T& value) const { //
        return instanceToId_.at(value);
    }

    bool contain(const T& value) const {
        return instanceToId_.count(value) != 0;
    }

    int nextId() const { //
        return counter_;
    }

    std::size_t size() const { //
        return instanceToId_.size();
    }

private:
    int counter_;
    std::map<const T, int> instanceToId_;
    std::map<int, T> idToInstance_;
};
} // namespace sf

#endif /* SF_BI_MAP_HPP */
