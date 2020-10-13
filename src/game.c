#include "game.h"

#include <cbm.h>
#include <conio.h>
#include <stdint.h>

#include "bonus.h"
#include "common.h"
#include "pit.h"
#include "score.h"
#include "ship.h"
#include "utils.h"

#define SPEED_INCREASE 0x0f

void play(game_state_t* game_state) {
    uint8_t last_bonus;
    uint16_t usleep_value = 0x4ff;

    for (;;) {
        char c = 0;

        next_pit(game_state);
        probably_set_bonus(game_state);
        display_score(game_state);

        if (kbhit()) c = cgetc();
        switch (c) {
            case 'a':
            case CH_CURS_LEFT:
                move_ship_left(game_state);
                break;
            case 'd':
            case CH_CURS_RIGHT:
                move_ship_right(game_state);
                break;
            case 'q':
                return;
        }
        last_bonus = bonus_hit(game_state);
        game_state->score += last_bonus;

        if (!draw_ship(game_state)) {
            explode_ship(game_state);
            return;
        }

        if ((++game_state->score % 100) == 0) {
            game_state->pit_width--;
        }
        if (game_state->score % NEXT_LEVEL_AFTER == 0) {
            usleep_value -=
                SPEED_INCREASE * (game_state->score / NEXT_LEVEL_AFTER);
        }
        if (last_bonus == 200) {
            game_state->pit_width = DEFAULT_PIT_WIDTH;
        }

        usleep(usleep_value);
    }
}
