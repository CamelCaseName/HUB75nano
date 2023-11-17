#ifndef HUB75NANO_IMMEDIATE_COLOR_H
#define HUB75NANO_IMMEDIATE_COLOR_H

#include "../../buffer_setting/buffer_common.h"

#pragma region immediates

#pragma GCC push_options
#pragma GCC optimize("unroll-loops")
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline)) inline void SendRow()
#else
inline void SendRow()
#endif
{
    for (uint8_t i = 0; i < PANEL_X; i++)
    {
        Clock;
    }
}
#pragma GCC pop_options

void fillScreenColor(Color color)
{
    for (uint8_t bitness = MAX_COLORDEPTH - 1; bitness < MAX_COLORDEPTH; bitness--)
    {
        _set_color((((color.red >> (uint8_t)bitness) & (uint8_t)1) << (uint8_t)7) | (((color.green >> (uint8_t)bitness) & (uint8_t)1) << (uint8_t)6) | (((color.blue >> (uint8_t)bitness) & (uint8_t)1) << (uint8_t)5) | (((color.red >> (uint8_t)bitness) & (uint8_t)1) << (uint8_t)4) | (((color.green >> (uint8_t)bitness) & (uint8_t)1) << (uint8_t)3) | (((color.blue >> (uint8_t)bitness) & (uint8_t)1) << (uint8_t)2));

        // todo continue work here building it up, but not top priority
        for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 32 rows
        {
            SendRow();
            LATCH;
            _stepRow();
            CLEAR_OE;

#if MAX_BRIGHTNESS_SLEEP_MUSEC > 0
            delayMicroseconds(BRIGHTNESS_SLEEP_MUSEC >> bitness);
            if (BRIGHTNESS_SLEEP_MUSEC < MAX_BRIGHTNESS_SLEEP_MUSEC)
            {
                HIGH_OE;
                delayMicroseconds((MAX_BRIGHTNESS_SLEEP_MUSEC - BRIGHTNESS_SLEEP_MUSEC) >> bitness);
            }
#endif
        }
    }
}
#pragma endregion // immediates

#endif // HUB75NANO_IMMEDIATE_COLOR_H