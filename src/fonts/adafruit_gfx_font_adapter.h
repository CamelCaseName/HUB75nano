#ifndef HUB75NANO_ADAFRUIT_GFX_FONT_ADAPTER_H
#define HUB75NANO_ADAFRUIT_GFX_FONT_ADAPTER_H

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <glcdfont.c>

// todo think about if it makes sense how i split the font stuff??
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline uint8_t
getFontLine(unsigned char data, int line_num)
{
    data++;
    uint8_t line = 0;
    for (uint8_t i = 0; i < 5; i++)
    { // Char bitmap = 5 columns
        line |= (((pgm_read_byte(&font[data * 5 + i]) >> line_num) & 1) << i);
    }
    return line;
} //<=============================================================================

// default adafruit font, cant change much here
inline void setFont() {}
inline void setFont(PGM_VOID_P fontArray) {}

#endif // HUB75NANO_ADAFRUIT_GFX_FONT_ADAPTER_H