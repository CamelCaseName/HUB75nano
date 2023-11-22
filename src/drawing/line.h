#ifndef HUB75NANO_LINE_H
#define HUB75NANO_LINE_H

#include "drawing_common.h"

void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color)
{
    // horizontal lines
    if (y1 == y2)
    {
        if (x1 > x2)
        {
            uint8_t a = x2;
            x2 = x1;
            x1 = a;
        }

        if (x2 >= PANEL_X)
        {
            x2 = PANEL_X - 1;
        }

        //  short horizontal lines
        while ((x1 & 3) != 0 && x1 < x2)
        {
            setBuffer(x1, y1, color);
            x1++;
        }

        // lines always appear one short
        x2++;
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
        return;
    }

    if (x1 == x2) // vertical lines
    {
        if (y1 > y2)
        {
            uint8_t a = y2;
            y2 = y1;
            y1 = a;
        }
        for (uint8_t j = y1; j <= y2; j++)
        {
            setBuffer(x1, j, color);
        }
        return;
    }

    // draws a line with color between the coords given
    // calculate both gradients
    int8_t dx = abs(x2 - x1);
    int8_t dy = -abs(y2 - y1);
    int8_t sy = y1 < y2 ? 1 : -1;
    int8_t sx = x1 < x2 ? 1 : -1;
    // error corerction
    int16_t err = dx + dy, e2;
    while (1)
    {
        setBuffer(x1, y1, color);
        setBuffer(x2, y2, color);
        e2 = 2 * err;
        if (e2 >= dy)
        {
            if (sx == 1)
            {
                if (x1 >= x2)
                    break;
            }
            else
            {
                if (x2 >= x1)
                    break;
            }
            err += dy;
            x1 += sx;
            x2 -= sx;
        }
        if (e2 <= dx)
        {
            if (sy == 1)
            {
                if (y1 >= y2)
                    break;
            }
            else
            {
                if (y2 >= y1)
                    break;
            }
            err += dx;
            y1 += sy;
            y2 -= sy;
        }
    }
}

// todo add line with width

#endif // HUB75NANO_LINE_H