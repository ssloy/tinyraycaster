#include <cassert>
#include "map.h"

static const char map[] = "0000222222220000"\
                          "1              5"\
                          "1              5"\
                          "1     01111    5"\
                          "0     0        5"\
                          "0     3     1155"\
                          "0   1000       5"\
                          "0   3  0       5"\
                          "5   4  100011  5"\
                          "5   4   1      4"\
                          "0       1      4"\
                          "2       1  44444"\
                          "0     000      4"\
                          "0 111          4"\
                          "0              4"\
                          "0002222244444444";

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

