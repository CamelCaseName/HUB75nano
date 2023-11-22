#ifndef HUB75NANO_CIRCLE_H
#define HUB75NANO_CIRCLE_H

#include "drawing_common.h"
#include "line.h"

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
drawCircle(uint8_t xMiddle, uint8_t yMiddle, uint8_t radius, Color color, bool fill)
{
    if (fill)
    {
        fillCircle(xMiddle, yMiddle, radius, color);
    }
    else
    {
        drawCircleHollow(xMiddle, yMiddle, radius, color);
    }
}

void drawCircleHollow(uint8_t xMiddle, uint8_t yMiddle, uint8_t radius, Color color)
{
    switch (radius)
    {
    case 0:
        setBuffer(xMiddle, yMiddle, color);
        break;
    case 1:
        setBuffer(xMiddle, yMiddle, color);
        setBuffer(xMiddle + 1, yMiddle, color);
        setBuffer(xMiddle, yMiddle + 1, color);
        setBuffer(xMiddle - 1, yMiddle, color);
        setBuffer(xMiddle, yMiddle - 1, color);
        break;

    default:
        // adapted from jeskos method: https://schwarzers.com/algorithms/
        // draws a circle at the coords with radius and color
        int8_t x = radius;
        int8_t y = 0;
        // for bigger circles than can fit on the panel
        // int16_t error = radius >> 4, temp_error;
        int8_t error = 0, temp_error;
        while (x >= y)
        {
            setBuffer(xMiddle - x, yMiddle - y, color);
            setBuffer(xMiddle - x, yMiddle + y, color);
            setBuffer(xMiddle + x, yMiddle - y, color);
            setBuffer(xMiddle + x, yMiddle + y, color);
            setBuffer(xMiddle - y, yMiddle - x, color);
            setBuffer(xMiddle - y, yMiddle + x, color);
            setBuffer(xMiddle + y, yMiddle - x, color);
            setBuffer(xMiddle + y, yMiddle + x, color);
            y++;
            error += y;
            temp_error = error - x;
            if (temp_error >= 0)
            {
                error = temp_error;
                x--;
            }
        };
        break;
    }
}

void fillCircle(uint8_t xMiddle, uint8_t yMiddle, uint8_t radius, Color color)
{
    switch (radius)
    {
    case 0:
        setBuffer(xMiddle, yMiddle, color);
        break;
    case 1:
        setBuffer(xMiddle, yMiddle, color);
        setBuffer(xMiddle + 1, yMiddle, color);
        setBuffer(xMiddle, yMiddle + 1, color);
        setBuffer(xMiddle - 1, yMiddle, color);
        setBuffer(xMiddle, yMiddle - 1, color);
        break;

    default:
        // adapted from jeskos method: https://schwarzers.com/algorithms/
        // draws a filled circle at the coords with radius and color
        int8_t x = radius;
        int8_t y = 0;
        // for bigger circles than can fit on the panel
        // int16_t error = radius >> 4, temp_error;
        int8_t error = 0, temp_error;
        while (x >= y)
        {
            drawLine(xMiddle - x, yMiddle - y, xMiddle + x, yMiddle - y, color);
            drawLine(xMiddle - x, yMiddle + y, xMiddle + x, yMiddle + y, color);
            drawLine(xMiddle - y, yMiddle - x, xMiddle + y, yMiddle - x, color);
            drawLine(xMiddle - y, yMiddle + x, xMiddle + y, yMiddle + x, color);
            y++;
            error += y;
            temp_error = error - x;
            if (temp_error >= 0)
            {
                error = temp_error;
                x--;
            }
        };
        break;
    }
}

#endif // HUB75NANO_CIRCLE_H