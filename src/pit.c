#include "pit.h"

#include <stdlib.h>
#include <string.h>

#include "common.h"

#define ROCK_CHAR 0x166
#define PATH_CHAR 0x20

#define random_offset() (HALF_OFFSET - (rand() % (MAX_OFFSET + 1)))

static const uint8_t HALF_OFFSET = MAX_OFFSET / 2;
static const uint8_t* SCREEN_2ND_ROW = SCREEN_BASE + SCREEN_WIDTH;
static const uint8_t* SCREEN_3RD_ROW = SCREEN_BASE + (2 * SCREEN_WIDTH);

static const uint8_t MIN_LEFT_WALL_WIDTH = 2;

static void calculate_wall_width(game_state_t* game_state) {
    uint8_t max_left_wall_width = SCREEN_WIDTH - game_state->pit_width - 2;
    if (game_state->left_wall_width != 0) {
        uint8_t offset = random_offset();
        uint8_t width = game_state->left_wall_width + offset;
        width = width > max_left_wall_width ? max_left_wall_width : width;
        width = width < MIN_LEFT_WALL_WIDTH ? MIN_LEFT_WALL_WIDTH : width;

        game_state->left_wall_width = width;
    } else {
        game_state->left_wall_width =
            SCREEN_CENTER - (game_state->pit_width / 2);
    }
}

void initialize_pit(game_state_t* game_state) {
    uint8_t row;
    memset(SCREEN_BASE, ' ', SCREEN_WIDTH);
    for (row = 1; row < SCREEN_HEIGHT; row++) {
        uint8_t* row_ptr = calc_row_start(row);
        calculate_wall_width(game_state);

        memset(row_ptr, ROCK_CHAR, SCREEN_WIDTH);
        memset(row_ptr + game_state->left_wall_width, PATH_CHAR,
               game_state->pit_width);
    }
}

void next_pit(game_state_t* game_state) {
    uint8_t* last_row = calc_row_start(SCREEN_HEIGHT - 1);
    uint8_t* ship_pos = calc_row_start(game_state->ship_y) + game_state->ship_x;

    *ship_pos = PATH_CHAR;

    memmove(SCREEN_2ND_ROW, SCREEN_3RD_ROW, SCREEN_WIDTH * (SCREEN_HEIGHT - 2));

    calculate_wall_width(game_state);
    memset(last_row, ROCK_CHAR, SCREEN_WIDTH);
    memset(last_row + game_state->left_wall_width, PATH_CHAR,
           game_state->pit_width);
}
