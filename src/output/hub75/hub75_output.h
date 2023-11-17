#ifndef HUB75NANO_HUB75_OUTPUT_H
#define HUB75NANO_HUB75_OUTPUT_H

#ifdef PANEL_BIG
#include "2bit_buffer.h"
#else
#ifdef PANEL_FLASH
#include "flash_buffer.h"
#else
#ifdef PANEL_NO_BUFFER
#include "immediate_color.h"
#else
#include "1bit_buffer.h"
#endif
#endif
#endif

#ifndef PANEL_NO_BUFFER
#ifdef PANEL_MAX_SPEED
__attribute__((always_inline))
#endif
inline void
displayBuffer()
{
    // puts the  buffer contents onto the panel
#ifdef PANEL_BIG
    _displayBigBuffer(); // 1 bit buffer in ram
#else
#ifdef PANEL_FLASH
    _displayFlashBuffer(); // 4 bit buffer in flash
#else
    _displaySmallBuffer(); // 2 bit buffer in ram
#endif
#endif
}
#endif

#endif // HUB75NANO_HUB75_OUTPUT_H