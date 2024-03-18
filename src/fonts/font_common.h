#ifndef HUB75NANO_FONT_COMMON_H
#define HUB75NANO_FONT_COMMON_H
#include <avr/pgmspace.h>
#include "../Settings.h"
#ifndef PANEL_NO_FONT

#if PANEL_FONT == 0
// here we could decide on font
// our stadnard 3x5 font
#include "3x5font.h"
#define PANEL_FONT_X 4 /* set to 4 because the 3x5 font includes a spacing pixel so it tiles 4x5 or 4x6 */
#define PANEL_FONT_Y 5
#else
// classic adafruit 5x7 font
#if PANEL_FONT == 1
#include "adafruit_gfx_font_adapter.h"
#define PANEL_FONT_X 6 /* set to 4 because the 3x5 font includes a spacing pixel so it tiles 4x5 or 4x6 */
#define PANEL_FONT_Y 7
#else
#if PANEL_FONT == 2
#include "adafruit_gfx_new_font_adapter.h"
#else
#error "no font chosen"
#endif
#endif
#endif

#endif
#endif // HUB75NANO_FONT_COMMON_H