/*
  HUB75nano.h can be used to display stuff on a HUB75 panel with _row shift registers with 64x32px in 8, 16 or 4096 colors
  designed for ARDUINO nano.
  (c) Leonhard Seidel, itsaps, jandlseb, 2023
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef HUB75NANO_MAIN_H
#define HUB75NANO_MAIN_H
#include <Arduino.h>

#include "Settings.h"

#pragma region definitions

// buffer toggle
#ifdef PANEL_NO_BUFFER
#undef PANEL_FLASH
#undef PANEL_BIG
#define PANEL_NO_FONT
#endif

// flash toggle
#ifdef PANEL_FLASH
#undef PANEL_BIG
#endif

// color transformatuion values (no idea if )
#ifndef MAX_COLORDEPTH
#ifdef PANEL_BIG
#define MAX_COLORDEPTH 2
#else
#ifdef PANEL_FLASH
#define MAX_COLORDEPTH 4
#else
#ifdef PANEL_NO_BUFFER
#define MAX_COLORDEPTH 5
#else
#define MAX_COLORDEPTH 1
#endif
#endif
#endif
#endif

#pragma endregion // definitions

#include "boards/board.h"

// include colors
#include "structs/Colors.h"

// toggle is in there, decided by the definitions we set before the include
#include "fonts/font_common.h"

#ifdef ARDUINO_ARCH_SAMD
#ifndef PGM_VOID_P
#define PGM_VOID_P const void *
#endif
#endif

class Panel
{
public:
#pragma region constructors
#ifdef PANEL_FLASH
    Panel(PGM_VOID_P buffer_in)
    {
        buffer = buffer_in;
        set_pin_output(RA);
        set_pin_output(RB);
#if PANEL_Y > 8
        set_pin_output(RC);
#endif
#if PANEL_Y > 16
        set_pin_output(RD);
#endif
#if PANEL_Y > 32
        set_pin_output(RE);
#endif
        set_pin_output(RF);
        set_pin_output(RS);
        set_pin_output(GF);
        set_pin_output(GS);
        set_pin_output(BF);
        set_pin_output(BS);
        set_pin_output(CLK);
        set_pin_output(LAT);
        set_pin_output(OE);
    }
#else
    Panel()
    {
        set_pin_output(RA);
        set_pin_output(RB);
#if PANEL_Y > 8
        set_pin_output(RC);
#endif
#if PANEL_Y > 16
        set_pin_output(RD);
#endif
#if PANEL_Y > 32
        set_pin_output(RE);
#endif
        set_pin_output(RF);
        set_pin_output(RS);
        set_pin_output(GF);
        set_pin_output(GS);
        set_pin_output(BF);
        set_pin_output(BS);
        set_pin_output(CLK);
        set_pin_output(LAT);
        set_pin_output(OE);
    }
#endif
#pragma endregion // constructors

#pragma region buffer_copying
#ifdef PANEL_FLASH
    void swapBuffer(PGM_VOID_P newBuffer)
    {
        buffer = newBuffer;
    }
#else
#ifndef PANEL_NO_BUFFER
#include "structs/LED.h"
    void swapBuffer(const LED *newBuffer, uint8_t bufferLength)
    {
        memcpy(buffer, newBuffer, bufferLength);
    }

    __attribute__((always_inline)) inline void fillBuffer(Color color)
    {
        // fills the buffer
        fillRect(0, 0, PANEL_X - 1, PANEL_Y - 1, color);
    }
#endif
#endif
#pragma endregion // buffer_copying

// only include the buffer stuff if we are not in immediate mode
#ifndef PANEL_NO_BUFFER
#include "buffer_setting/buffer.h"
// include drawing code if we want it
#ifndef PANEL_FLASH
#include "drawing/drawing.h"
#endif
#endif

#include "output/output.h"
};
#endif // HUB75NANO_MAIN_H