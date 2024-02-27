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

#if PANEL_X == 128
#define DCLK_GCLK_SCALED \
    DCLK_GCLK
#define DCLK_GCLK_SCALED_MINUS_ONE
#else
#if PANEL_X == 64
#define DCLK_GCLK_SCALED \
    DCLK_GCLK;           \
    DCLK_GCLK
#define DCLK_GCLK_SCALED_MINUS_ONE \
    DCLK_GCLK
#else
#if PANEL_X == 32
#define DCLK_GCLK_SCALED \
    DCLK_GCLK;           \
    DCLK_GCLK;           \
    DCLK_GCLK;           \
    DCLK_GCLK
#define DCLK_GCLK_SCALED_MINUS_ONE \
    DCLK_GCLK;                     \
    DCLK_GCLK;                     \
    DCLK_GCLK
#else
#if PANEL_X == 16
#define DCLK_GCLK_SCALED \
    DCLK_GCLK;           \
    DCLK_GCLK;           \
    DCLK_GCLK;           \
    DCLK_GCLK;           \
    DCLK_GCLK;           \
    DCLK_GCLK;           \
    DCLK_GCLK;           \
    DCLK_GCLK
#define DCLK_GCLK_SCALED_MINUS_ONE \
    DCLK_GCLK;                     \
    DCLK_GCLK;                     \
    DCLK_GCLK;                     \
    DCLK_GCLK;                     \
    DCLK_GCLK;                     \
    DCLK_GCLK;                     \
    DCLK_GCLK
#endif
#endif
#endif
#endif

#define LSB_FAKE                                \
    _set_color(0);                              \
    for (uint8_t x = 0; x < PANEL_E_X - 1; x++) \
    {                                           \
        DCLK_GCLK;                              \
    }                                           \
    HIGH_LAT;                                   \
    LATCH_GCLK;                                 \
    CLEAR_LAT

#endif // HUB75NANO_HUB75E_COMMON_H