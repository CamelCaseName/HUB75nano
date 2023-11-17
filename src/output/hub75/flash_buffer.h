#ifndef HUB75NANO_FLASH_BUFFER_H
#define HUB75NANO_FLASH_BUFFER_H

#ifdef PANEL_FLASH

#include <avr/pgmspace.h>
#include "../../buffer_setting/buffer_common.h"

void _displayFlashBuffer()
{
    uint16_t index = 0;
#ifdef PANEL_FLIP_HORIZONTAL
#define INDEX_MOVE index--
#else
#define INDEX_MOVE index++
#endif
    for (uint8_t y = 0; y < PANEL_Y; y++) // 32 rows
    {
        // we send first the MMSB, then MSB, LSB, LLSB
        index = (uint16_t)(buffer + (y << (uint8_t)6));
#ifdef PANEL_FLIP_HORIZONTAL
        index += PANEL_X;
#endif

#pragma region MMSB
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(index));
        Clock;
        // shift data into buffers
        HIGH_OE;
        LATCH;
        _stepRow();
        CLEAR_OE;
#if MAX_BRIGHTNESS_SLEEP_MUSEC > 0
        delayMicroseconds(BRIGHTNESS_SLEEP_MUSEC);
#if BRIGHTNESS_SLEEP_MUSEC < MAX_BRIGHTNESS_SLEEP_MUSEC

        HIGH_OE;
        delayMicroseconds(MAX_BRIGHTNESS_SLEEP_MUSEC - BRIGHTNESS_SLEEP_MUSEC);
#endif
#endif
    }
#pragma endregion // MMSB

    for (uint8_t y = 0; y < PANEL_Y; y++) // 32 rows
    {
        index = (uint16_t)(buffer + (y << (uint8_t)6)) + (PANEL_BUFFERSIZE / 4);

#ifdef PANEL_FLIP_HORIZONTAL
        index += PANEL_X;
#endif
#pragma region MSB
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(index));
        Clock;
        // shift data into buffers
        HIGH_OE;
        LATCH;
        _stepRow();
        CLEAR_OE;
#if MAX_BRIGHTNESS_SLEEP_MUSEC > 0
        delayMicroseconds(BRIGHTNESS_SLEEP_MUSEC / 2);
#if BRIGHTNESS_SLEEP_MUSEC < MAX_BRIGHTNESS_SLEEP_MUSEC

        HIGH_OE;
        delayMicroseconds(MAX_BRIGHTNESS_SLEEP_MUSEC / 2 - BRIGHTNESS_SLEEP_MUSEC / 2);

#endif
#endif
    }
#pragma endregion // MMSB

    for (uint8_t y = 0; y < PANEL_Y; y++) // 32 rows
    {
        index = (uint16_t)(buffer + (y << (uint8_t)6)) + (PANEL_BUFFERSIZE / 2);

#ifdef PANEL_FLIP_HORIZONTAL
        index += PANEL_X;
#endif
#pragma region LSB
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(index));
        Clock;
        // shift data into buffers
        HIGH_OE;
        LATCH;
        _stepRow();
        CLEAR_OE;
#if MAX_BRIGHTNESS_SLEEP_MUSEC > 0
        delayMicroseconds(BRIGHTNESS_SLEEP_MUSEC / 4);
#if BRIGHTNESS_SLEEP_MUSEC < MAX_BRIGHTNESS_SLEEP_MUSEC

        HIGH_OE;
        delayMicroseconds(MAX_BRIGHTNESS_SLEEP_MUSEC / 4 - BRIGHTNESS_SLEEP_MUSEC / 4);
#endif
#endif
    }
#pragma endregion // LSB

    for (uint8_t y = 0; y < PANEL_Y; y++) // 32 rows
    {
        index = (uint16_t)(buffer + (y << (uint8_t)6)) + (PANEL_BUFFERSIZE * 3 / 4); // advance index to next section

#ifdef PANEL_FLIP_HORIZONTAL
        index += PANEL_X;
#endif
#pragma region LLSB
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(index));
        Clock;
        // shift data into buffers
        HIGH_OE;
        LATCH;
        _stepRow();
        CLEAR_OE;
#if MAX_BRIGHTNESS_SLEEP_MUSEC > 0
        delayMicroseconds(BRIGHTNESS_SLEEP_MUSEC / 8);
#if BRIGHTNESS_SLEEP_MUSEC < MAX_BRIGHTNESS_SLEEP_MUSEC

        HIGH_OE;
        delayMicroseconds(MAX_BRIGHTNESS_SLEEP_MUSEC / 8 - BRIGHTNESS_SLEEP_MUSEC / 8);
#endif
#endif
#pragma endregion // LLSB
    }
}

#endif
#endif // HUB75NANO_FLASH_BUFFER_H