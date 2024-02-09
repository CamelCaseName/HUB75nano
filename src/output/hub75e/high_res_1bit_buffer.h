#ifndef HUB75NANO_HIGH_RES_1BIT_BUFFER_E_H
#define HUB75NANO_HIGH_RES_1BIT_BUFFER_E_H
#include "../../buffer_setting/buffer_common.h"
#include "../../Settings.h"

void _displaySmallHighResBuffer()
{
    LED *index = (LED *)&buffer;
    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 32 rows
    {
#ifndef PANEL_SMALL_BRIGHT
        _stepRow();
#endif

        index = (LED *)(&buffer) + (y << (uint8_t)4); // advance over last row

        // chip 0
        _set_color(0);
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 1

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 2
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;

        // chip 3
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;

        // chip 4
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;

        // chip 5
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;

        // chip 6
        _set_color(0);
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 7
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

#ifdef PANEL_SMALL_BRIGHT

        HIGH_LAT;
        LATCH_GCLK;
        CLEAR_LAT;

#else
        DCLK_GCLK;
        DCLK_GCLK;

        //  latch data from shift registers to latch register, "buffer" for global release to pwm
        HIGH_LAT;
        LATCH_GCLK;
        CLEAR_LAT;

        // fake new data so we fill the buffer
#pragma region LSB_fake
        // no need to set color to 0 as it already is

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;
        DCLK_GCLK;

        HIGH_LAT;
        LATCH_GCLK;
        CLEAR_LAT;
#pragma endregion // LSB_fake
#endif

        //  display row once done, so move data from latch registers to pwm modules
        HIGH_LAT;
        LATCH_GCLK;
        LATCH_GCLK;
        CLEAR_LAT;

#ifdef PANEL_SMALL_BRIGHT
        // advance 1 in row once we are done with one
        stepRow();
#endif
    }
}
#endif // HUB75NANO_HIGH_RES_1BIT_BUFFER_E_H