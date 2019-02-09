#include <cstdlib>
#include "sprite.h"

bool Sprite::operator < (const Sprite& s) const {
      return player_dist > s.player_dist;
}

