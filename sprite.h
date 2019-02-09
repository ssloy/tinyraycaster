#ifndef SPRITE_H
#define SPRITE_H

#include <cstdlib>

struct Sprite {
    float x, y;
    size_t tex_id;
    float player_dist;
    bool operator < (const Sprite& s) const;
};

#endif // SPRITE_H

