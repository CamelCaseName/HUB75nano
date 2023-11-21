#ifndef HUB75NANO_ELLIPSE_H
#define HUB75NANO_ELLIPSE_H

#include "drawing_common.h"
#include "circle.h"
#include "line.h"

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
/*
    @param a: pixels to extend in either x direction
    @param b: pixels to extend in either y direction
*/
inline void
drawEllipse(uint8_t xMiddle, uint8_t yMiddle, uint8_t a, uint8_t b, Color color, bool fill)
{
    // circle is faster
    if (a == b)
    {
        drawCircle(xMiddle, yMiddle, a, color, fill);
        return;
    }

    if (fill)
    {
        fillEllipse(xMiddle, yMiddle, a, b, color);
    }
    else
    {
        drawEllipseHollow(xMiddle, yMiddle, a, b, color);
    }
}

/*
    @param a: pixels to extend in either x direction
    @param b: pixels to extend in either y direction
*/
void drawEllipseHollow(uint8_t xMiddle, uint8_t yMiddle, uint8_t a, uint8_t b, Color color)
{
    // circle is faster
    if (a == b)
    {
        drawCircleHollow(xMiddle, yMiddle, a, color);
        return;
    }
    if (a == 0)
    {
        for (uint8_t j = yMiddle - b; j <= yMiddle + b; j++)
        {
            setBuffer(xMiddle, j, color);
        }
        return;
    }
    if (b == 0)
    {
        for (uint8_t j = xMiddle - a; j <= xMiddle + a; j++)
        {
            setBuffer(j, yMiddle, color);
        }
        return;
    }

    int8_t x = -a;
    int8_t y = 0; /* II. quadrant from bottom left to top right */
    int16_t a2 = a * a;
    int16_t b2 = b * b;
    int16_t e2 = b * b;
    int16_t err = x * (2 * e2 + x) + e2; /* error of 1.step */
    do
    {
        setBuffer(xMiddle - x, yMiddle + y, color); /*   I. Quadrant */
        setBuffer(xMiddle + x, yMiddle + y, color); /*  II. Quadrant */
        setBuffer(xMiddle + x, yMiddle - y, color); /* III. Quadrant */
        setBuffer(xMiddle - x, yMiddle - y, color); /*  IV. Quadrant */
        e2 = 2 * err;
        if (e2 >= (x * 2 + 1) * b2) /* e_xy+e_x > 0 */
            err += (++x * 2 + 1) * b2;
        if (e2 <= (y * 2 + 1) * a2) /* e_xy+e_y < 0 */
            err += (++y * 2 + 1) * a2;
    } while (x <= 0);
}

/*
    @param a: pixels to extend in either x direction
    @param b: pixels to extend in either y direction
*/
void fillEllipse(uint8_t xMiddle, uint8_t yMiddle, uint8_t a, uint8_t b, Color color)
{
    // circle is faster
    if (a == b)
    {
        drawCircleHollow(xMiddle, yMiddle, a, color);
        return;
    }
    if (a == 0)
    {
        drawLine(xMiddle, yMiddle - b, xMiddle, yMiddle + b, color);
        return;
    }
    if (b == 0)
    {
        drawLine(xMiddle - a, yMiddle, xMiddle + a, yMiddle, color);
        return;
    }

    int8_t x = -a;
    int8_t y = 0; /* II. quadrant from bottom left to top right */
    int16_t a2 = a * a;
    int16_t b2 = b * b;
    int16_t e2 = b * b;
    int16_t err = x * (2 * e2 + x) + e2; /* error of 1.step */
    drawLine(xMiddle + x, yMiddle, xMiddle - x, yMiddle, color);
    do
    {
        setBuffer(xMiddle - x, yMiddle + y, color); /*   I. Quadrant */
        setBuffer(xMiddle + x, yMiddle + y, color); /*  II. Quadrant */
        setBuffer(xMiddle + x, yMiddle - y, color); /* III. Quadrant */
        setBuffer(xMiddle - x, yMiddle - y, color); /*  IV. Quadrant */
        e2 = 2 * err;
        if (e2 >= (x * 2 + 1) * b2) /* e_xy+e_x > 0 */
        {
            err += (++x * 2 + 1) * b2;
        }
        if (e2 <= (y * 2 + 1) * a2) /* e_xy+e_y < 0 */
        {
            err += (++y * 2 + 1) * a2;
            // fill on each y step as a  horizontal line can be faster
            drawLine(xMiddle + x, yMiddle + y, xMiddle - x, yMiddle + y, color);
            drawLine(xMiddle + x, yMiddle - y, xMiddle - x, yMiddle - y, color);
        }
    } while (x <= 0);
}

#endif // HUB75NANO_ELLIPSE_H