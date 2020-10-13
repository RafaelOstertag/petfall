#ifndef SHIP_H
#define SHIP_H

#include "gamestate.h"

void initialize_ship(game_state_t* game_state);
void move_ship_left(game_state_t* game_state);
void move_ship_right(game_state_t* game_state);

int draw_ship(const game_state_t* game_state);

void explode_ship(const game_state_t* game_state);

#endif
