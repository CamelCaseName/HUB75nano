#ifndef HUB75NANO_1BIT_BUFFER_H
#define HUB75NANO_1BIT_BUFFER_H

#include "../../buffer_setting/buffer_common.h"
#include "../../Settings.h"

void _displaySmallBuffer()
{
    LED *index;
    CLEAR_OE;
    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 16 rows
    {
#if PANEL_Y > 32
        index = (LED *)(&buffer) + (y << (uint8_t)5);
#else
#if PANEL_Y > 16
        index = (LED *)(&buffer) + (y << (uint8_t)4);
#else
#if PANEL_Y > 8
        index = (LED *)(&buffer) + (y << (uint8_t)3);
#else
#if PANEL_Y > 4
        index = (LED *)(&buffer) + (y << (uint8_t)2);
#endif
#endif
#endif
#endif
        // we set each pixel after the other

        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;

        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;

#if PANEL_X > 16
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;

        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
#endif
#if PANEL_X > 32
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;

        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;

        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;

        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
        ++index;
        _set_color((*(uint8_t *)(index)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)6)) & 63);
        Clock;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)4) & 63);
        Clock;
        _set_color(*((((uint8_t *)(index)) + (sizeof(uint8_t) * 2))) >> (uint8_t)2);
        Clock;
#endif
        // set _row
        HIGH_OE;
        LATCH;
        _stepRow();
        CLEAR_OE;
    }
    HIGH_OE;
}

#endif // HUB75NANO_1BIT_BUFFER_H