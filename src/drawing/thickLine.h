#include "drawing_common.h"
#include "rectangle.h"
#include "line.h"

void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color, uint8_t width)
{
    // no special width
    if (width <= 1)
    {
        drawLine(x1, y1, x2, y2, color);
        return;
    }

    width++;
    width >>= 1;

    // always go from left to right, 0 to +
    if (x1 > x2)
    {
        uint8_t a = x2;
        x2 = x1;
        x1 = a;
    }

    // horizontal lines
    if (y1 == y2)
    {
        if (y1 > y2)
        {
            uint8_t a = y2;
            y2 = y1;
            y1 = a;
        }
        fillRect(x1, y1 - width, x2, y2 + width, color);
        return;
    }
    // vertical lines
    if (x1 == x2)
    {
        fillRect(x1 - width, y1, x2 + width, y2, color);
        return;
    }

    uint8_t dx = x2 - x1;
    int8_t sx = x1 < x2 ? 1 : -1;
    int8_t dy = abs(y2 - y1);
    int8_t sy = y1 < y2 ? 1 : -1;
    int16_t err = dx - dy, e2; /* error value e_xy */
    uint8_t x3, y3;
    float ed = dx + dy == 0 ? 1 : sqrt((float)dx * dx + (float)dy * dy);

    while (1)
    { /* pixel loop */
        setBuffer(x1, y1, color);
        e2 = err;
        x3 = x1;
        if (2 * e2 >= -dx)
        { /* x step */
            for (e2 += dy, y3 = y1; e2 < ed * width && (y2 != y3 || dx > dy); e2 += dx)
                setBuffer(x1, y3 += sy, color);
            if (x1 == x2)
                break;
            e2 = err;
            err -= dy;
            x1 += sx;
        }
        if (2 * e2 <= dy)
        { /* y step */
            for (e2 = dx - e2; e2 < ed * width && (x2 != x3 || dx < dy); e2 += dy)
                setBuffer(x3 += sx, y1, color);
            if (y1 == y2)
                break;
            err += dx;
            y1 += sy;
        }
    }
}
