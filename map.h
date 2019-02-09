#ifndef MAP_H
#define MAP_H

#include <cstdlib>

struct Map {
    size_t w, h; // overall map dimensions
    Map();
    int get(const size_t i, const size_t j) const;
    bool is_empty(const size_t i, const size_t j) const;
};

#endif // MAP_H

