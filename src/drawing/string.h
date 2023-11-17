#ifndef HUB75NANO_STRING_H
#define HUB75NANO_STRING_H
#ifndef PANEL_NO_FONT

#include "drawing_common.h"
#include "char.h"

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
drawString(uint8_t x, uint8_t y, char *str, Color color)

{
    drawString(x, y, str, color, Colors::NO_COLOR);
}

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
drawBigString(uint8_t x, uint8_t y, char *str, Color color, uint8_t size_modifier)
{
    drawBigString(x, y, str, color, Colors::NO_COLOR, size_modifier);
}

void drawBigString(uint8_t x, uint8_t y, char *str, Color color, Color bg_color, uint8_t size_modifier)
{
    if (size_modifier == 1)
    {
        drawString(x, y, str, color, bg_color);
        return;
    }
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        uint8_t xoffset = x + (3 * size_modifier + 1) * i;
        if (xoffset > PANEL_X)
            return;

        drawBigChar(xoffset, y, str[i], color, bg_color, size_modifier); // seperate by 1
        // drawBigChar(x + 4 * size_modifier * i, y, str[i], color, size_modifier); //seperate by size
    }
}

void drawString(uint8_t x, uint8_t y, char *str, Color color, Color bg_color)
{
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        uint8_t xoffset = x + 4 * i;
        if (xoffset > PANEL_X)
            return;

        drawChar(xoffset, y, str[i], color, bg_color); // seperate by 1
        // drawBigChar(x + 4 * size_modifier * i, y, str[i], color, size_modifier); //seperate by size
    }
}

#endif
#endif // HUB75NANO_STRING_H