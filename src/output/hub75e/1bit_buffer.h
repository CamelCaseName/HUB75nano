#ifndef HUB75NANO_1BIT_BUFFER_E_H
#define HUB75NANO_1BIT_BUFFER_E_H

#include "../../buffer_setting/buffer_common.h"
#include "../../Settings.h"
#include "hub75e_common.h"

#define SET_4_PIXELS_LAST                                                                           \
    _set_color(*(uint8_t *)(index) << (uint8_t)2);                                                  \
    DCLK_GCLK_SCALED;                                                                               \
    _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));                                  \
    DCLK_GCLK_SCALED;                                                                               \
    _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2)); \
    DCLK_GCLK_SCALED;                                                                               \
    _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));                                  \
    DCLK_GCLK_SCALED_MINUS_ONE

#define SET_4_PIXELS   \
    SET_4_PIXELS_LAST; \
    DCLK_GCLK

#if PANEL_X == PANEL_E_X // 128
#define SET_CHIP_LAST \
    SET_4_PIXELS;     \
    ++index;          \
    SET_4_PIXELS;     \
    ++index;          \
    SET_4_PIXELS;     \
    ++index;          \
    SET_4_PIXELS_LAST
#else
#if PANEL_X == (PANEL_E_X / 2) // 64
#define SET_CHIP_LAST \
    SET_4_PIXELS;     \
    ++index;          \
    SET_4_PIXELS_LAST
#else
#if PANEL_X == (PANEL_E_X / 4) // 32
#define SET_CHIP_LAST \
    SET_4_PIXELS_LAST
#endif
#endif
#endif

#define SET_CHIP   \
    SET_CHIP_LAST; \
    DCLK_GCLK

void _displaySmallBuffer()
{
    LED *index = (LED *)&buffer;
    for (uint8_t y = 0; y < PANEL_E_Y / 2; y++) // 32 rows
    {
        _stepRow();

        index = (LED *)(&buffer) + ((y & (uint8_t)~1) << (uint8_t)3); // advance over last row
        Serial.print(y);
        Serial.print(": ");
        Serial.print(((y & (uint8_t)~1) << (uint8_t)3));
        Serial.print("\n");

        // we integer divide the screen by 2 and then set 16 led to 8 values in pairs

        // chip 0
        SET_CHIP;

        // chip 1
        ++index;
        SET_CHIP;

        // chip 2
        ++index;
        SET_CHIP;

        // chip 3
        ++index;
        SET_CHIP;

#if PANEL_X > (PANEL_E_X / 8) // 16
        // chip 4
        ++index;
        SET_CHIP;

        // chip 5
        ++index;
        SET_CHIP;

        // chip 6
        ++index;
        SET_CHIP;

        // chip 7
        ++index;
        SET_CHIP_LAST;

#if PANEL_X > (PANEL_E_X / 2) // 64
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
#endif
#endif

        //  latch data from shift registers to latch register, "buffer" for global release to pwm
        HIGH_LAT;
        LATCH_GCLK;
        CLEAR_LAT;

        // fake new data so we fill the buffer
        LSB_FAKE;

        //  display row once done, so move data from latch registers to pwm modules
        HIGH_LAT;
        LATCH_GCLK;
        LATCH_GCLK;
        CLEAR_LAT;
    }
}

#endif // HUB75NANO_1BIT_BUFFER_E_H