#ifndef HUB75NANO_2BIT_BUFFER_H
#define HUB75NANO_2BIT_BUFFER_H
#ifdef PANEL_BIG

#include "../../buffer_setting/buffer_common.h"

void _displayBigBuffer()
{
    LED *index;

    // coding:
    // 00 -> off
    // 01 -> 33%
    // 10 -> 66%
    // 11 -> on
    // msb

    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 16 rows
    {
        index = (LED *)(&buffer) + (y << (uint8_t)4);

        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;

        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;

        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;

        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;

        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;

        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;

        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;

        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        ++index;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 3)))) >> (uint8_t)4));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 5))));
        Clock;
        // display _row
        HIGH_OE;
        LATCH;
        _stepRow();
        CLEAR_OE;

#if MAX_BRIGHTNESS_SLEEP_MUSEC > 0
        delayMicroseconds(BRIGHTNESS_SLEEP_MUSEC);
#if BRIGHTNESS_SLEEP_MUSEC < MAX_BRIGHTNESS_SLEEP_MUSEC

        delayMicroseconds(MAX_BRIGHTNESS_SLEEP_MUSEC - BRIGHTNESS_SLEEP_MUSEC);
        HIGH_OE;
#endif
#endif
    }
    // lsb
    for (uint8_t y = 0; y < PANEL_Y / 2; y++)
    {

        index = (LED *)(&buffer) + (y << (uint8_t)4);

        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + sizeof(uint8_t)))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 3))) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index)) + (sizeof(uint8_t) * 4)))) >> (uint8_t)2));
        Clock;
        // display _row
        HIGH_OE;
        LATCH;
        _stepRow();
        CLEAR_OE;

#if MAX_BRIGHTNESS_SLEEP_MUSEC > 0
        delayMicroseconds(BRIGHTNESS_SLEEP_MUSEC / 2);
#if BRIGHTNESS_SLEEP_MUSEC < MAX_BRIGHTNESS_SLEEP_MUSEC

        delayMicroseconds(MAX_BRIGHTNESS_SLEEP_MUSEC / 2 - BRIGHTNESS_SLEEP_MUSEC / 2);
        HIGH_OE;

#endif
#endif
    }
    HIGH_OE;
}

#endif
#endif // HUB75NANO_2BIT_BUFFER_H