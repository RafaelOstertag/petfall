#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>

#define SCREEN_BASE ((uint8_t*)0x8000)
#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 25

#define DEFAULT_PIT_WIDTH 12

#define MAX_OFFSET ((uint8_t)4)
#define calc_row_start(n) (SCREEN_BASE + (SCREEN_WIDTH * (n)))

extern const uint8_t SCREEN_CENTER;

#endif
