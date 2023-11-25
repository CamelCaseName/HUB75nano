#ifndef HUB75NANO_TRIANGLE_H
#define HUB75NANO_TRIANGLE_H

#include "drawing_common.h"
#include "line.h"

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
drawTriangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, Color color, bool fill)
{
    if (fill)
    {
        fillTriangle(x1, y1, x2, y2, x3, y3, color);
    }
    else
    {
        drawTriangleHollow(x1, y1, x2, y2, x3, y3, color);
    }
}

void drawTriangleHollow(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, Color color)
{
    drawLine(x1, y1, x2, y2, color);
    drawLine(x1, y1, x3, y3, color);
    drawLine(x2, y2, x3, y3, color);
}

/*
MIT License

Copyright (c) 2023 Gustavo Pezzi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
// adapted from https://github.com/gustavopezzi/triangle-rasterizer-int
void fillTriangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, Color color)
{
    // assure order
    if (x1 > x2)
    {
        uint8_t temp = x2;
        x2 = x1;
        x1 = temp;
        temp = y2;
        y2 = y1;
        y1 = temp;
    }
    else if (x1 > x3)
    {
        uint8_t temp = x3;
        x3 = x1;
        x1 = temp;
        temp = y3;
        y3 = y1;
        y1 = temp;
    }

    if (y2 > y3)
    {
        uint8_t temp = x3;
        x3 = x2;
        x2 = temp;
        temp = y3;
        y3 = y2;
        y2 = temp;
    }

    // fill outline
    drawLine(x1, y1, x2, y2, color);
    drawLine(x1, y1, x3, y3, color);
    drawLine(x2, y2, x3, y3, color);

    // Finds the bounding box with all candidate pixels
    uint8_t x_min = min(min(x1, x2), x3);
    uint8_t y_min = min(min(y1, y2), y3);
    uint8_t x_max = max(max(x1, x2), x3);
    uint8_t y_max = max(max(y1, y2), y3);

    // Compute the constant delta_s that will be used for the horizontal and vertical steps
    int8_t delta_w0_col = (y2 - y3);
    int8_t delta_w1_col = (y3 - y1);
    int8_t delta_w2_col = (y1 - y2);
    int8_t delta_w0_row = (x3 - x2);
    int8_t delta_w1_row = (x1 - x3);
    int8_t delta_w2_row = (x2 - x1);

    int8_t bias0 = (y3 - y2 < 0 || (y3 - y2 == 0 && x3 - x2 > 0)) ? 0 : -1;
    int8_t bias1 = (y1 - y3 < 0 || (y1 - y3 == 0 && x1 - x3 > 0)) ? 0 : -1;
    int8_t bias2 = (y2 - y1 < 0 || (y2 - y1 == 0 && x2 - x1 > 0)) ? 0 : -1;

    // Compute the edge functions for the fist (top-left) point
    int16_t w0_row = (x3 - x2) * (y_min - y2) - (y3 - y2) * (x_min - x2) + bias0;
    int16_t w1_row = (x1 - x3) * (y_min - y1) - (y1 - y3) * (x_min - x1) + bias1;
    int16_t w2_row = (x2 - x1) * (y_min - y2) - (y2 - y1) * (x_min - x2) + bias2;

    // Loop all candidate pixels inside the bounding box
    for (uint8_t y = y_min; y <= y_max; y++)
    {
        int16_t w0_col = w0_row;
        int16_t w1_col = w1_row;
        int16_t w2_col = w2_row;
        uint8_t firstX = 0;
        for (uint8_t x = x_min + 1; x <= x_max; x++)
        {
            w0_col += delta_w0_col;
            w1_col += delta_w1_col;
            w2_col += delta_w2_col;
            // pixel is inside the edges
            if (w0_col >= 0 && w1_col >= 0 && w2_col >= 0)
            {
                // save first and last pixel on this line that are in the triangle
                if (firstX == 0)
                {
                    setBuffer(x, y, color);
                    firstX = x;
                }
            }
            else if (firstX != 0)
            {
                // line drawn, skip rest of pixels in this line
                drawLine(firstX, y, x, y, color);
                x = 0xfe;
            }
        }
        w0_row += delta_w0_row;
        w1_row += delta_w1_row;
        w2_row += delta_w2_row;
    }
}

#endif // HUB75NANO_TRIANGLE_H