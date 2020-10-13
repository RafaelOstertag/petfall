#ifndef UTILS_H
#define UTILS_H

#include <peekpoke.h>

#define LOWERCASE_MODE() POKE(59468, 14)
#define GRAPHICS_MODE() POKE(59468, 12)

#define usleep(n)                                 \
    {                                             \
        uint16_t __ctr__;                         \
        for (__ctr__ = 0; __ctr__ < n; __ctr__++) \
            ;                                     \
    }

#endif
