#ifndef HUB75NANO_BUFFER_H
#define HUB75NANO_BUFFER_H

#ifdef PANEL_BIG
#include "2bit_buffer_setting.h"
#else
#include "1bit_buffer_setting.h"
#endif

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
setBuffer(uint8_t x, uint8_t y, Color color)
{
#ifdef PANEL_BIG
    _setBigBuffer(x, y, color); // 1 bit buffer in ram
#else
#ifndef PANEL_FLASH
    _setSmallBuffer(x, y, color); // 2 bit buffer in ram
#else
#endif
#endif
}

#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
_setBuffer4xBlockWise(uint8_t x, uint8_t y, uint8_t block_count, Color color)
{
#ifdef PANEL_BIG
    _setBigBuffer4x(x, y, block_count, color); // 1 bit buffer in ram
#else
#ifndef PANEL_FLASH
    _setSmallBuffer4x(x, y, block_count, color); // 2 bit buffer in ram
#else
#endif
#endif
}

#endif // HUB75NANO_BUFFER_H