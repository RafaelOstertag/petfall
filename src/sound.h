#ifndef SOUND_H
#define SOUND_H

#include <peekpoke.h>

#define sound_on()   \
    POKE(59467, 16); \
    POKE(59464, 0)

#define sound_off() POKE(59467, 0)

#define set_timbre(n) POKE(59466, n)
#define set_tone(n) POKE(59464, n)
#endif
