#include "ship.h"

#include <peekpoke.h>

#include "common.h"
#include "utils.h"

#define SHIP_CHAR 'v'

static uint8_t explosion[] = {'.', '*', 'o', '0', '@', ' ', 0};

void initialize_ship(game_state_t* game_state) {
    uint8_t i;
    uint8_t* row_ptr;

    game_state->ship_y = SCREEN_HEIGHT / 2;
    row_ptr = calc_row_start(game_state->ship_y);

    for (i = 0; i < SCREEN_WIDTH; i++) {
        if (row_ptr[i] == ' ') {
            game_state->ship_x = i + (game_state->pit_width / 2);
            row_ptr[game_state->ship_x] = SHIP_CHAR;
            break;
        }
    }
}

void move_ship_left(game_state_t* game_state) {
    if (game_state->ship_x > 1) {
        game_state->ship_x--;
    }
}

void move_ship_right(game_state_t* game_state) {
    if (game_state->ship_x < (SCREEN_WIDTH - 1)) {
        game_state->ship_x++;
    }
}

int draw_ship(const game_state_t* game_state) {
    uint8_t* scr_pos = calc_row_start(game_state->ship_y) + game_state->ship_x;
    if (*scr_pos != ' ') {
        *scr_pos = SHIP_CHAR;
        return 0;
    }
    *scr_pos = SHIP_CHAR;
    return 1;
}

void explode_ship(const game_state_t* game_state) {
    uint8_t* e_ptr;
    uint8_t* ship_pos = calc_row_start(game_state->ship_y) + game_state->ship_x;

    for (e_ptr = explosion; *e_ptr != 0; e_ptr++) {
        *ship_pos = *e_ptr;
        usleep(0xf00);
    }
}
