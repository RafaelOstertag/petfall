#include "intro.h"

#include <conio.h>

void intro(void) {
    clrscr();

    cputsxy(12, 1, "..:: petfall ::..");

    cputsxy(5, 3, "controls");
    cputsxy(5, 4, "--------");
    cputsxy(5, 6, "a or cursor left   move ship left");
    cputsxy(5, 8, "d or cursor right  move ship right");
    cputsxy(5, 10, "q                  quit game");

    cputsxy(5, 12, "bonus");
    cputsxy(5, 13, "-----");
    cputsxy(5, 15, "*                     50pts");
    cputsxy(5, 17, "$                    100pts");
    cputsxy(5, 19, "r                    200pts");

    cputsxy(10, 24, "press any key to start");

    cgetc();
}
