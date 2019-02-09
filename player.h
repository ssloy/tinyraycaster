#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    float x, y; // position
    float a;    // view direction
    float fov;  // field of view
    int turn, walk;
};

#endif // PLAYER_H

