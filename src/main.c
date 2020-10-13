#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "game.h"
#include "gamestate.h"
#include "intro.h"
#include "pit.h"
#include "ship.h"
#include "utils.h"

void cleanup() {
    clrscr();
    while (kbhit()) {
        cgetc();
    }
    GRAPHICS_MODE();
}

int main(void) {
    game_state_t* game_state;

    intro();

    LOWERCASE_MODE();

    game_state = initialize_gamestate();
    initialize_pit(game_state);
    initialize_ship(game_state);

    sleep(2);

    play(game_state);

    free_gamestate(game_state);

    cleanup();
    printf("score %05d\n", game_state->score);
    return 0;
}
