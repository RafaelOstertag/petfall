#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <stdint.h>

struct game_state_ {
    uint16_t score;
    uint8_t pit_width;
    uint8_t left_wall_width;
    uint8_t ship_x;
    uint8_t ship_y;
};

typedef struct game_state_ game_state_t;

game_state_t* initialize_gamestate(void);
void free_gamestate(game_state_t* game_state);

#endif
