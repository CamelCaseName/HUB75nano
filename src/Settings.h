
#ifndef PANEL_SETTINGS_H
#define PANEL_SETTINGS_H
/////////////////////
// #define PANEL_HUB75E // switches output to a format compatible with most 128x64 flex panels (chips: icnd2153, stp1612pw05, FM6124C or similar)
// ######## ONLY WHEN IN THE HUB75E MODE:
// #define PANEL_SMALL_BRIGHT // gets the image muuuuch brighter on the hub75e 1 bit buffer at the cost of some slight ghosting
// #define PANEL_HIGH_RES // changes the size from effective 64x32 on the hub7e 128x64 panels to a full 64x64
// #define PANEL_GPIO_NON_INTRUSIVE // this saves the other pins on GPIOB on the nano and other smaller boards in hub75e mode
// ######## THE FOLLOWING WORK REGARDLESS OF PANEL TYPE
// #define PANEL_3_PIN_ROWS // swaps the row addressing in from 5(binary) pin to 3 pin(shift register)
// #define PANEL_BIG // use 2 bit rgb image buffer
// #define PANEL_FLASH // 4 bit flash buffer
// #define PANEL_NO_BUFFER // no buffer, immediate mode only
// #define PANEL_NO_FONT // disables everything font related, saves some flash
// #define PANEL_MAX_SPEED // uses more space but is faster, usually not needed
// #define PANEL_FLIP_VERTICAL // flips the panel vertically (in flash mode it flips the upper and lower half, but doesnt flip the whole panel)
// #define PANEL_FLIP_HORIZONTAL // flips the panel horizontally
// #define PANEL_X 64 // width in pixels
// #define PANEL_Y 32 // panel height in pixels
// #define PANEL_MAX_FRAMETIME 127 // shades all colors, should be of the form of (2^n - 1)
/////////////////////

// board size (currently max 1 board supported)
#ifndef PANEL_X
#define PANEL_X 64
#endif
#ifndef PANEL_Y
#define PANEL_Y 32
#endif

// sleep for brightnesses
#ifndef MAX_FRAMETIME
#define MAX_FRAMETIME 127
#endif

#ifdef PANEL_FLASH
// have it bigger a size as we have more available lol
#define PANEL_BUFFERSIZE (PANEL_X * PANEL_Y * 2) // 4 byte per led, we have 6 bit per 2 led per color depth -> about 4k
#endif

// standard LED struct buffer
#ifndef PANEL_BUFFERSIZE
#define PANEL_BUFFERSIZE (PANEL_X * PANEL_Y / 8)
#endif

#ifdef PANEL_HUB75E
#ifdef PANEL_3_PIN_ROWS
#undef PANEL_3_PIN_ROWS
#else
#define PANEL_3_PIN_ROWS
#endif
#endif

#endif // PANEL_SETTINGS_H