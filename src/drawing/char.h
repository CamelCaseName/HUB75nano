#ifndef HUB75NANO_CHAR_H
#define HUB75NANO_CHAR_H

#ifndef PANEL_NO_FONT
#include "../fonts/font_common.h"
#include "drawing_common.h"

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline)) inline void drawChar(uint8_t x, uint8_t y, char letter, Color color)
#else
inline void drawChar(uint8_t x, uint8_t y, char letter, Color color)
#endif
{
    drawChar(x, y, letter, color, Colors::NO_COLOR);
}

void drawChar(uint8_t x, uint8_t y, char letter, Color color, const Color bg_color)
{
    // iterate through the character line by line
    for (uint8_t i = 0; i < 5; i++)
    {
        char current_line = getFontLine(letter, i);
        // iterate through the character bit by bit
        for (uint8_t j = 0; j < 4; j++)
        {
            // shift by j and check for bit set
            if (current_line & (uint8_t)(1 << (uint8_t)(4 - j)))
            {
                // set pixel at i and j
                setBuffer(x + j, y + i, color);
            }
            else if (bg_color.invalid_bits == 0)
            {
                setBuffer(x + j, y + i, bg_color);
            }
        }
    }
}

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline)) inline void drawBigChar(uint8_t x, uint8_t y, char letter, Color color, uint8_t size_modifier)
#else
inline void drawBigChar(uint8_t x, uint8_t y, char letter, Color color, uint8_t size_modifier)
#endif
{
    if (size_modifier == 1)
    {
        drawChar(x, y, letter, color, Colors::NO_COLOR);
        return;
    }
    drawBigChar(x, y, letter, color, Colors::NO_COLOR, size_modifier);
}

void drawBigChar(uint8_t x, uint8_t y, char letter, Color color, Color bg_color, uint8_t size_modifier)
{ // new with scaling, but may be slower
    if (size_modifier == 1)
    {
        drawChar(x, y, letter, color, bg_color);
        return;
    }

    // iterate through the character line by line
    for (uint8_t i = 0; i < 5; i++)
    {
        char current_line = getFontLine(letter, i);
        // iterate through the character bit by bit, so x direction
        for (uint8_t j = 0; j < 4; j++)
        {
            // shift by j and check for bit set
            if (current_line & (uint8_t)(1 << (uint8_t)(4 - j)))
            {
                // set pixel at i and j
                drawSquare(x + j * size_modifier, y + i * size_modifier, size_modifier, color, true);
            }
            else if (bg_color.invalid_bits == 0)
            {
                drawSquare(x + j * size_modifier, y + i * size_modifier, size_modifier, bg_color, true);
            }
        }
    }
}

#endif
#endif // HUB75NANO_CHAR_H