#ifndef HUB75NANO_FLASH_BUFFER_H
#define HUB75NANO_FLASH_BUFFER_H

#ifdef PANEL_FLASH

#include <Arduino.h>
#include "../../buffer_setting/buffer_common.h"
#include "../../Settings.h"

typedef const uint8_t *buffer_t;

void _displayFlashBuffer()
{
    buffer_t index = 0;
#ifdef PANEL_FLIP_HORIZONTAL
#define INDEX_MOVE index--
#else
#define INDEX_MOVE index++
#endif
#ifndef PANEL_FLIP_VERTICAL
    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 32 rows
#else
    for (int8_t y = (PANEL_Y / 2) - 1; y >= 0; y--) // 32 rows
#endif
    {
        // we send first the MMSB, then MSB, LSB, LLSB
        index = ((buffer_t)buffer) + ((uint16_t)y * PANEL_X);
#ifdef PANEL_FLIP_HORIZONTAL
        index += PANEL_X - 1;
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

#if PANEL_X > 16
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
#endif
#if PANEL_X > 32
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
#endif
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

#ifndef PANEL_FLIP_VERTICAL
    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 32 rows
#else
    for (int8_t y = (PANEL_Y / 2) - 1; y >= 0; y--) // 32 rows
#endif
    {
        index = ((buffer_t)buffer) + ((uint16_t)y * PANEL_X) + (PANEL_BUFFERSIZE / 4);

#ifdef PANEL_FLIP_HORIZONTAL
        index += PANEL_X - 1;
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

#if PANEL_X > 16
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
#endif
#if PANEL_X > 32
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
#endif
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

#ifndef PANEL_FLIP_VERTICAL
    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 32 rows
#else
    for (int8_t y = (PANEL_Y / 2) - 1; y >= 0; y--) // 32 rows
#endif
    {
        index = ((buffer_t)buffer) + ((uint16_t)y * PANEL_X) + (PANEL_BUFFERSIZE / 2);
#ifdef PANEL_FLIP_HORIZONTAL
        index += PANEL_X - 1;
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

#if PANEL_X > 16
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
#endif
#if PANEL_X > 32
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
#endif
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

#ifndef PANEL_FLIP_VERTICAL
    for (uint8_t y = 0; y < PANEL_Y / 2; y++) // 32 rows
#else
    for (int8_t y = (PANEL_Y / 2) - 1; y >= 0; y--) // 32 rows
#endif
    {
        index = ((buffer_t)buffer) + ((uint16_t)y * PANEL_X) + ((PANEL_BUFFERSIZE * 3) / 4);

#ifdef PANEL_FLIP_HORIZONTAL
        index += PANEL_X - 1;
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

#if PANEL_X > 16
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
#endif
#if PANEL_X > 32
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;

        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
        _set_color(pgm_read_byte(INDEX_MOVE));
        Clock;
#endif
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