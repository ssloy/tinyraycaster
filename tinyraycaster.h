#ifndef TINYRAYCASTER_H
#define TINYRAYCASTER_H

struct GameState {
    Map map;
    Player player;
    std::vector<Sprite> monsters;
    Texture tex_walls;
    Texture tex_monst;
};

void render(FrameBuffer &fb, const GameState &gs);

#endif // TINYRAYCASTER_H

