#ifndef HUB75NANO_FLASH_BUFFER_H
#define HUB75NANO_FLASH_BUFFER_H

#ifdef PANEL_FLASH

#include <Arduino.h>
#include "../../buffer_setting/buffer_common.h"

typedef const uint16_t *buffer_t;

void _displayFlashBuffer()
{
    buffer_t index = 0;
#ifdef PANEL_FLIP_HORIZONTAL
#define INDEX_MOVE index--
#else
#define INDEX_MOVE index++
#endif
    for (uint8_t y = 0; y < PANEL_Y; y++) // 32 rows
    {
        // we send first the MMSB, then MSB, LSB, LLSB
        index = (buffer_t)(buffer + (y << (uint8_t)6));
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
#if MAX_FRAMETIME > 0
        delayMicroseconds(MAX_FRAMETIME);
        HIGH_OE;
        delayMicroseconds(MAX_FRAMETIME);
#endif
    }
#pragma endregion // MMSB

    for (uint8_t y = 0; y < PANEL_Y; y++) // 32 rows
    {
        index = (buffer_t)(buffer + (y << (uint8_t)6)) + (PANEL_BUFFERSIZE / 4);

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
#if MAX_FRAMETIME > 0
        delayMicroseconds(MAX_FRAMETIME >> (1));
        HIGH_OE;
        delayMicroseconds(MAX_FRAMETIME >> (1));
#endif
    }
#pragma endregion // MMSB

    for (uint8_t y = 0; y < PANEL_Y; y++) // 32 rows
    {
        index = (buffer_t)(buffer + (y << (uint8_t)6)) + (PANEL_BUFFERSIZE / 2);

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
#if MAX_FRAMETIME > 0
        delayMicroseconds(MAX_FRAMETIME >> (2));
        HIGH_OE;
        delayMicroseconds(MAX_FRAMETIME >> (2));
#endif
    }
#pragma endregion // LSB

    for (uint8_t y = 0; y < PANEL_Y; y++) // 32 rows
    {
        index = (buffer_t)(buffer + (y << (uint8_t)6)) + (PANEL_BUFFERSIZE * 3 / 4); // advance index to next section

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
#if MAX_FRAMETIME > 0
        delayMicroseconds(MAX_FRAMETIME >> (3));
        HIGH_OE;
        delayMicroseconds(MAX_FRAMETIME >> (3));
#endif
#pragma endregion // LLSB
    }
}

#endif
#endif // HUB75NANO_FLASH_BUFFER_H