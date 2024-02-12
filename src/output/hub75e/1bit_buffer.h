#ifndef HUB75NANO_1BIT_BUFFER_E_H
#define HUB75NANO_1BIT_BUFFER_E_H

#include "../../buffer_setting/buffer_common.h"
#include "../../Settings.h"
#include "hub75e_common.h"

void _displaySmallBuffer()
{
    LED *index = (LED *)&buffer;
    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 32 rows
    {
#ifndef PANEL_SMALL_BRIGHT
        _stepRow();
#endif

        index = (LED *)(&buffer) + ((y & (uint8_t)~1) << (uint8_t)3); // advance over last row
        // we integer divide the screen by 2 and then set 16 led to 8 values in pairs

        // chip 0
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 1

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 2
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 3
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 4
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 5
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;

        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 6
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;

        // chip 7
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;
        DCLK_GCLK;
        ++index;
        _set_color(*(uint8_t *)(index) << (uint8_t)2);
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(index)) >> (uint8_t)4)));
        DCLK_GCLK;
        DCLK_GCLK;
        _set_color((uint8_t)((*((uint16_t *)(((uint8_t *)(index) + sizeof(uint8_t))))) >> (uint8_t)2));
        DCLK_GCLK;

#ifdef PANEL_SMALL_BRIGHT

        HIGH_LAT;
        LATCH_GCLK;
        CLEAR_LAT;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));

#else
        DCLK_GCLK;
        _set_color((*(((uint8_t *)(index)) + (sizeof(uint8_t) * 2))));
        DCLK_GCLK;

        //  latch data from shift registers to latch register, "buffer" for global release to pwm
        HIGH_LAT;
        LATCH_GCLK;
        CLEAR_LAT;

        // fake new data so we fill the buffer
        LSB_FAKE;
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

#endif // HUB75NANO_1BIT_BUFFER_E_H