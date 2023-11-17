#ifndef HUB75NANO_LINE_H
#define HUB75NANO_LINE_H

#include "drawing_common.h"

void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color)
{ // draws a line with color between the coords given
    // calculate both gradients
    int8_t dx = abs(x2 - x1);
    int8_t dy = -abs(y2 - y1);
    // create de-/increment values for walking the line
    int8_t sx = x1 < x2 ? 1 : -1;
    int8_t sy = y1 < y2 ? 1 : -1;
    // error corerction
    float err = dx + dy, e2;
    while (1)
    {
        setBuffer(x1, y1, color);
        e2 = 2 * err;
        if (e2 >= dy)
        {
            if (x1 == x2)
                break;
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx)
        {
            if (y1 == y2)
                break;
            err += dx;
            y1 += sy;
        }
    }
}

#endif // HUB75NANO_LINE_H