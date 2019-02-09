#include <cstdlib>
#include <cassert>

#include "map.h"

static const char map[] = "0000222222220000"\
                          "1              0"\
                          "1      11111   0"\
                          "1     0        0"\
                          "0     0  1110000"\
                          "0     3        0"\
                          "0   10000      0"\
                          "0   3   11100  0"\
                          "5   4   0      0"\
                          "5   4   1  00000"\
                          "0       1      0"\
                          "2       1      0"\
                          "0       0      0"\
                          "0 0000000      0"\
                          "0              0"\
                          "0002222222200000";

Map::Map() : w(16), h(16) {
    assert(sizeof(map) == w*h+1); // +1 for the null terminated string
}

int Map::get(const size_t i, const size_t j) const {
    assert(i<w && j<h && sizeof(map) == w*h+1);
    return map[i+j*w] - '0';
}

bool Map::is_empty(const size_t i, const size_t j) const {
    assert(i<w && j<h && sizeof(map) == w*h+1);
    return map[i+j*w] == ' ';
}

