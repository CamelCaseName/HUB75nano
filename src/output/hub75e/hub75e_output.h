#ifndef HUB75NANO_HUB75E_OUTPUT_H
#define HUB75NANO_HUB75E_OUTPUT_H

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
    _displayBigBuffer(); // 2 bit buffer in ram
#else
#ifdef PANEL_FLASH
    _displayFlashBuffer(); // 4 bit buffer in flash
#else
    _displaySmallBuffer(); // 1 bit buffer in ram
#endif
#endif
}
#endif

// shout out to sebitimewaster for his implementation on the esp32 as an arduino sketch, in the end i rebuilt it all from scratch tho, as none of the available implementations worked.
// also thanks to http://kuku.eu.org/?projects/hub75e/index for reverse engineering the row selection shift registers.
// i also retraced them and came to the same conclusion, so i can be very certain that the chips are equivalent, led drivers and row drivers

// it is however split 4 times for each coloumn of drivers. so we must also clock the pwclock with the serial clock, no hardware clock sadly

// BIGGEST help overall was the stp1612pw05 datasheet https://www.st.com/resource/en/datasheet/stp1612pw05.pdf,
// i found this chip and its datasheet after searching for comparable chips
// and it has a full description of everything we need to control those chips

// PINs for the row shift registers: A-> CLK   B-> OE    C-> SIN

// 4 SM5368 in series, in 2 rows gives the 8 we find on the board. they just shift form 1st to 32nd output, in parallel for bottom and top -> 64 rows total, just like standard hub75

#endif // HUB75NANO_HUB75E_OUTPUT_H