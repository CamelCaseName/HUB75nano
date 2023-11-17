#ifndef HUB75NANO_ELLIPSE_H
#define HUB75NANO_ELLIPSE_H

#include "drawing_common.h"

void drawEllipse(uint8_t xm, uint8_t ym, uint8_t a, uint8_t b, Color color, bool fill)
{
    int8_t x = -a;
    int8_t y = 0; /* II. quadrant from bottom left to top right */
    int16_t a2 = a * a;
    int16_t b2 = b * b;
    int16_t e2 = b * b;
    int16_t err = x * (2 * e2 + x) + e2; /* error of 1.step */
    do
    {
        setBuffer(xm - x, ym + y, color); /*   I. Quadrant */
        setBuffer(xm + x, ym + y, color); /*  II. Quadrant */
        setBuffer(xm + x, ym - y, color); /* III. Quadrant */
        setBuffer(xm - x, ym - y, color); /*  IV. Quadrant */
        e2 = 2 * err;
        if (e2 >= (x * 2 + 1) * b2) /* e_xy+e_x > 0 */
            err += (++x * 2 + 1) * b2;
        if (e2 <= (y * 2 + 1) * a2) /* e_xy+e_y < 0 */
            err += (++y * 2 + 1) * a2;
    } while (x <= 0);
    while (y++ < b)
    {                                 /* to early stop of flat ellipses a=1, */
        setBuffer(xm, ym + y, color); /* -> finish tip of ellipse */
        setBuffer(xm, ym - y, color);
    }
    if (fill)
    {
        while (a > 0)
        {
            drawEllipse(xm, ym, --a, b, color, true);
        }
    }
}

#endif // HUB75NANO_ELLIPSE_H