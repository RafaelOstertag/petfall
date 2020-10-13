#include "gamestate.h"

#include <stdlib.h>

#include "common.h"

game_state_t* initialize_gamestate(void) {
    game_state_t* new_state = (game_state_t*)malloc(sizeof(game_state_t));

    new_state->score = 0;
    new_state->left_wall_width = 0;
    new_state->pit_width = DEFAULT_PIT_WIDTH;

    _randomize();

    return new_state;
}

void free_gamestate(game_state_t* game_state) { free(game_state); }
