#ifndef HUB75NANO_1BIT_BUFFER_H
#define HUB75NANO_1BIT_BUFFER_H

#include "../../boards/board.h"
#include "../../structs/LED.h"

void _displaySmallBuffer()
{
    LED *index;
    CLEAR_OE;
    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 16 rows
    {
        index = (LED *)(&buffer) + (y << (uint8_t)4);
        // we set each pixel after the other

        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        Clock;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        Clock;
        // set row
        HIGH_OE;
        LATCH;
        _stepRow();
        CLEAR_OE;
    }
    HIGH_OE;
}

#endif // HUB75NANO_1BIT_BUFFER_H