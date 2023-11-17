#ifndef HUB75NANO_STRING_H
#define HUB75NANO_STRING_H
#ifndef PANEL_NO_FONT

#include "drawing_common.h"

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline)) inline void drawString(uint8_t x, uint8_t y, char *str, Color color, Color bg_color)
#else
inline void drawString(uint8_t x, uint8_t y, char *str, Color color, Color bg_color)
#endif
{
    drawString(x, y, str, color, bg_color, 1);
}

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline)) inline void drawString(uint8_t x, uint8_t y, char *str, Color color)
#else
inline void drawString(uint8_t x, uint8_t y, char *str, Color color)
#endif
{
    drawString(x, y, str, color, Colors::NO_COLOR, 1);
}

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline)) inline void drawString(uint8_t x, uint8_t y, char *str, Color color, uint8_t size_modifier)
#else
inline void drawString(uint8_t x, uint8_t y, char *str, Color color, uint8_t size_modifier)
#endif
{
    drawString(x, y, str, color, Colors::NO_COLOR, size_modifier);
}

void drawString(uint8_t x, uint8_t y, char *str, Color color, Color bg_color, uint8_t size_modifier)
{
    for (uint8_t i = 0; i < strlen(str); i++)
    {
        uint8_t xoffset = x + (3 * size_modifier + 1) * i;
        if (xoffset > PANEL_X)
            return;

        drawBigChar(xoffset, y, str[i], color, bg_color, size_modifier); // seperate by 1
        // drawBigChar(x + 4 * size_modifier * i, y, str[i], color, size_modifier); //seperate by size
    }
}

#endif
#endif // HUB75NANO_STRING_H