#ifndef HUB75NANO_ADAFRUIT_GFX_NEW_FONT_ADAPTER_H
#define HUB75NANO_ADAFRUIT_GFX_NEW_FONT_ADAPTER_H

#include "Arduino.h"
#include <Adafruit_GFX.h>

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline uint8_t
getFontLine(unsigned char data, int line_num)
{
    const uint8_t index = (data - 32);
    unsigned char pixel = 0;
    if (pgm_read_byte(&font4x6[index][1]) & (uint8_t)1 == 1)
        line_num -= 1;
    if (line_num == 0)
    {
        pixel = (pgm_read_byte(&font4x6[index][0])) >> (uint8_t)4;
    }
    else if (line_num == 1)
    {
        pixel = (pgm_read_byte(&font4x6[index][0])) >> (uint8_t)1;
    }
    else if (line_num == 2)
    {
        // Split over 2 bytes
        return (((pgm_read_byte(&font4x6[index][0])) & (uint8_t)0x03) << (uint8_t)2) | (((pgm_read_byte(&font4x6[index][1])) & (uint8_t)0x02));
    }
    else if (line_num == 3)
    {
        pixel = (pgm_read_byte(&font4x6[index][1])) >> (uint8_t)4;
    }
    else if (line_num == 4)
    {
        pixel = (pgm_read_byte(&font4x6[index][1])) >> (uint8_t)1;
    }
    return pixel & (uint8_t)0xE;
} //<=============================================================================

// default font
inline void setFont()
{
}

inline void setFont(PGM_VOID_P fontArray)
{
    if (fontArray == 0)
    {
        setFont();
        return;
    }
}

#endif // HUB75NANO_ADAFRUIT_GFX_NEW_FONT_ADAPTER_H