#include "bonus.h"

#include <stdlib.h>

#include "common.h"
#include "sound.h"
#include "utils.h"

#define BONUS_CHAR_1 '*'
#define BONUS_CHAR_2 '$'
#define BONUS_CHAR_3 'r'

static uint8_t* last_row = calc_row_start(SCREEN_HEIGHT - 1);

static void low_beep() {
    sound_on();
    set_timbre(16);
    set_tone(140);
    usleep(0xff);
    sound_off();
}

static void high_beep() {
    sound_on();
    set_timbre(20);
    set_tone(200);
    usleep(0xff);
    sound_off();
}

static void set_bonus_char(char c, const game_state_t* game_state) {
    uint8_t bonus_pos;

    bonus_pos = rand() % game_state->pit_width;
    last_row[game_state->left_wall_width + bonus_pos] = c;
}

void probably_set_bonus(game_state_t* game_state) {
    uint16_t random_value = rand();

    if (random_value % 150 == 0) {
        set_bonus_char(BONUS_CHAR_3, game_state);
    } else if (random_value % 100 == 0) {
        set_bonus_char(BONUS_CHAR_2, game_state);
    } else if (random_value % 5 == 0) {
        set_bonus_char(BONUS_CHAR_1, game_state);
    }
}

int8_t bonus_hit(game_state_t* game_state) {
    uint8_t* ship_pos = calc_row_start(game_state->ship_y) + game_state->ship_x;
    switch (*ship_pos) {
        case BONUS_CHAR_1:
            *ship_pos = ' ';
            low_beep();
            return 50;
        case BONUS_CHAR_2:
            *ship_pos = ' ';
            high_beep();
            return 100;
        case BONUS_CHAR_3:
            *ship_pos = ' ';
            low_beep();
            high_beep();
            return 200;
        default:
            return 0;
    }
}
