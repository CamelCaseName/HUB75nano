#ifndef HUB75NANO_HUB75E_COMMON_H
#define HUB75NANO_HUB75E_COMMON_H

#define DCLK_GCLK16X \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK

#define DCLK_GCLK15X \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK;       \
    DCLK_GCLK

#define LSB_FAKE   \
    _set_color(0); \
    DCLK_GCLK16X;  \
    DCLK_GCLK16X;  \
    DCLK_GCLK16X;  \
    DCLK_GCLK16X;  \
    DCLK_GCLK16X;  \
    DCLK_GCLK16X;  \
    DCLK_GCLK16X;  \
    DCLK_GCLK15X;  \
    HIGH_LAT;      \
    LATCH_GCLK;    \
    CLEAR_LAT

#endif // HUB75NANO_HUB75E_COMMON_H