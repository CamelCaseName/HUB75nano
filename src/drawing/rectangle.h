#ifndef HUB75NANO_RECTANGLE_H
#define HUB75NANO_RECTANGLE_H

#include "drawing_common.h"

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color, bool fill)
{
    if (fill)
    {
        fillRect(x1, y1, x2, y2, color);
    }
    else
    {
        drawRectHollow(x1, y1, x2, y2, color);
    }
}

void drawRectHollow(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color)
{
    // draws a rect filled ro not filled with the given color at coords (landscape, origin in upper left corner)
    // vertical lines
    if (x1 == x2) // 1 wide ones
    {
        for (uint8_t j = y1; j <= y2; j++)
        {
            setBuffer(x1, j, color);
        }
        return;
    }

    for (uint8_t j = y1; j <= y2; j++)
    {
        setBuffer(x1, j, color);
        setBuffer(x2, j, color);
    }

    x1++;
    //  guard against rects beign 1 high
    if (y1 == y2)
    {
        // short horizontal lines
        while ((x1 & 3) != 0 && x1 < x2)
        {
            setBuffer(x1, y1, color);
            x1++;
        }

        while ((x2 & 3) != 0 && x2 > x1)
        {
            x2--;
            setBuffer(x2, y1, color);
        }

        // blocks of horizontal lines
        if (x2 - x1 >= 4 && !OVERFLOW)
        {
            uint8_t block_count = ((x2 - x1) / 4);
            _setBuffer4xBlockWise(x1, y1, block_count, color);
        }
    }
    else
    {
        // short horizontal lines
        while ((x1 & 3) != 0 && x1 < x2)
        {
            setBuffer(x1, y1, color);
            setBuffer(x1, y2, color);
            x1++;
        }

        while ((x2 & 3) != 0 && x2 > x1)
        {
            x2--;
            setBuffer(x2, y1, color);
            setBuffer(x2, y2, color);
        }

        // blocks of horizontal lines
        if (x2 - x1 >= 4 && !OVERFLOW)
        {
            uint8_t block_count = ((x2 - x1) / 4);

            _setBuffer4xBlockWise(x1, y1, block_count, color);
            _setBuffer4xBlockWise(x1, y2, block_count, color);
        }
    }
}

void fillRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color)
{
    if (x1 == x2) // 1 wide ones
    {
        for (uint8_t j = y1; j <= y2; j++)
        {
            setBuffer(x1, j, color);
        }
        return;
    }
    else if (x2 - x1 == 1) // 2 wide
    {
        for (uint8_t j = y1; j <= y2; j++)
        {
            setBuffer(x1, j, color);
            setBuffer(x1 + 1, j, color);
        }
        return;
    }
    else if (x2 - x1 == 2) // 3 wide
    {
        for (uint8_t j = y1; j <= y2; j++)
        {
            setBuffer(x1, j, color);
            setBuffer(x1 + 1, j, color);
            setBuffer(x1 + 2, j, color);
        }
        return;
    }

    // go through each horizontal line and fill (try for blocks of 4 led)
    uint8_t original_x1 = x1, original_x2 = x2 + 1;

    for (uint8_t j = y1; j <= y2; j++)
    { // horizontal lines
        x1 = original_x1;
        x2 = original_x2;
        while ((x1 & 3) != 0 && x1 < x2)
        {
            setBuffer(x1, j, color);
            x1++;
        }

        while ((x2 & 3) != 0 && x2 > x1)
        {
            x2--;
            setBuffer(x2, j, color);
        }

        // check against overflow
        if (x2 - x1 >= 4 && !OVERFLOW)
        {
            uint8_t block_count = ((x2 - x1) / 4);

            _setBuffer4xBlockWise(x1, j, block_count, color);
        }
    }
}

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
drawSquare(uint8_t x, uint8_t y, uint8_t size, Color color, bool fill)
{
    size--;
    if (fill)
    {
        fillRect(x, y, x + size, y + size, color);
    }
    else
    {
        drawRectHollow(x, y, x + size, y + size, color);
    }
}

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
drawSquareHollow(uint8_t x, uint8_t y, uint8_t size, Color color)
{
    size--;
    drawRectHollow(x, y, x + size, y + size, color);
}

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
fillSquare(uint8_t x, uint8_t y, uint8_t size, Color color)
{
    size--;
    fillRect(x, y, x + size, y + size, color);
}

#endif // HUB75NANO_RECTANGLE_H