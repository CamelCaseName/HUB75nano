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

/////////////////////
// #define PANEL_BIG // use 2 bit rgb image buffer
// #define PANEL_FLASH // 4 bit flash buffer
// #define PANEL_NO_BUFFER // no buffer, immediate mode only
// #define PANEL_NO_FONT // disables everything font related, saves some flash
// #define PANEL_MAX_SPEED // aggresively inlines the 4 draw assembly instructions, else its kept as a method to keep size down
// #define PANEL_FLIP_VERTICAL // flips the panel vertically
// #define PANEL_FLIP_HORIZONTAL // flips the panel horizontally
/////////////////////

// board size (currently max 1 board supported)
#ifndef PANEL_X
#define PANEL_X 64
#endif
#ifndef PANEL_Y
#define PANEL_Y 32
#endif

#pragma region definitions

// buffer toggle
#ifdef PANEL_NO_BUFFER
#undef PANEL_FLASH
#undef PANEL_BIG
#define PANEL_NO_FONT
#endif

// sleep for brightnesses
#ifndef MAX_BRIGHTNESS_SLEEP_MUSEC
#define MAX_BRIGHTNESS_SLEEP_MUSEC 100
#endif
#ifndef BRIGHTNESS_SLEEP_MUSEC
#define BRIGHTNESS_SLEEP_MUSEC 40
#endif

// flash toggle
#ifdef PANEL_FLASH
#undef PANEL_BIG
#ifdef PANEL_FLIP_VERTICAL
#error "vertical flip cannot be done on flash output, only horizontal"
#endif
// have it bigger a size as we have more available lol
#define PANEL_BUFFERSIZE (PANEL_X * PANEL_Y * 2) // 4 byte per led, we have 6 bit per 2 led per color depth -> about 4k
#endif

// standard LED struct buffer
#ifndef PANEL_BUFFERSIZE
#define PANEL_BUFFERSIZE (PANEL_X * PANEL_Y / 8)
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

class Panel
{
public:
#pragma region constructors
#ifdef PANEL_FLASH
    Panel(PGM_VOID_P buffer_in)
    {
        buffer = buffer_in;
        pinMode(RA, OUTPUT);
        pinMode(RB, OUTPUT);
        pinMode(RC, OUTPUT);
        pinMode(RD, OUTPUT);
        pinMode(RE, OUTPUT);
        pinMode(RF, OUTPUT);
        pinMode(RS, OUTPUT);
        pinMode(GF, OUTPUT);
        pinMode(GS, OUTPUT);
        pinMode(BF, OUTPUT);
        pinMode(BS, OUTPUT);
        pinMode(CLK, OUTPUT);
        pinMode(LAT, OUTPUT);
        pinMode(OE, OUTPUT);
    }
#else
    Panel()
    {
        pinMode(RA, OUTPUT);
        pinMode(RB, OUTPUT);
        pinMode(RC, OUTPUT);
        pinMode(RD, OUTPUT);
        pinMode(RE, OUTPUT);
        pinMode(RF, OUTPUT);
        pinMode(RS, OUTPUT);
        pinMode(GF, OUTPUT);
        pinMode(GS, OUTPUT);
        pinMode(BF, OUTPUT);
        pinMode(BS, OUTPUT);
        pinMode(CLK, OUTPUT);
        pinMode(LAT, OUTPUT);
        pinMode(OE, OUTPUT);
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

    void fillBuffer(Color color)
    {
        // fills the buffer
        for (uint8_t x = 0; x < PANEL_X; x++)
        {
            for (uint8_t y = 0; y < PANEL_Y; y++)
            {
                setBuffer(x, y, color);
            }
        }
    }
#endif
#endif
#pragma endregion // buffer_copying

// only include the buffer stuff if we are not in immediate mode
#ifndef PANEL_NO_BUFFER
#include "buffer_setting/buffer.h"
// include drawing code if we want it
#include "drawing/drawing.h"
#endif

#include "output/output.h"
};
#endif // HUB75NANO_MAIN_H