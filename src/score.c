#include "score.h"

#include <stdio.h>
#include <string.h>

#include "common.h"

#define BUFFER_SIZE 20

static char score_buffer[BUFFER_SIZE];

void display_score(const game_state_t* game_state) {
    snprintf(score_buffer, BUFFER_SIZE, "score %05d l%d", game_state->score,
             game_state->score / NEXT_LEVEL_AFTER);
    memcpy(SCREEN_BASE, &score_buffer, strlen(score_buffer));
}
