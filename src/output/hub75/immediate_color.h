#ifndef HUB75NANO_IMMEDIATE_COLOR_H
#define HUB75NANO_IMMEDIATE_COLOR_H

#define MAX_FRAMETIME 127

#include "../../buffer_setting/buffer_common.h"

#pragma region immediates

#pragma GCC push_options
#pragma GCC optimize("unroll-loops")
__attribute__((always_inline)) inline void SendRow()
{
    for (uint8_t i = 0; i < PANEL_X; i++)
    {
        Clock;
    }
}
#pragma GCC pop_options

void fillScreenColor(Color color)
{
    for (int8_t bitness = MAX_COLORDEPTH - 1; bitness >= 0; bitness--)
    {
        _set_color(
            (((color.blue >> bitness) & (uint8_t)1) << (uint8_t)7) |
            (((color.green >> bitness) & (uint8_t)1) << (uint8_t)6) |
            (((color.red >> bitness) & (uint8_t)1) << (uint8_t)5) |
            (((color.blue >> bitness) & (uint8_t)1) << (uint8_t)4) |
            (((color.green >> bitness) & (uint8_t)1) << (uint8_t)3) |
            (((color.red >> bitness) & (uint8_t)1) << (uint8_t)2));

        // todo continue work here building it up, but not top priority
        for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 32 rows
        {
            SendRow();
            HIGH_OE;
            LATCH;
            _stepRow();

            CLEAR_OE;
            delayMicroseconds(MAX_FRAMETIME >> (MAX_COLORDEPTH - bitness));
            HIGH_OE;
            delayMicroseconds(MAX_FRAMETIME >> (MAX_COLORDEPTH - bitness));
        }
    }
}
#pragma endregion // immediates

#endif // HUB75NANO_IMMEDIATE_COLOR_H