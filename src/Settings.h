
#ifndef PANEL_SETTINGS_H
#define PANEL_SETTINGS_H
/////////////////////
// #define PANEL_BIG // use 2 bit rgb image buffer
// #define PANEL_FLASH // 4 bit flash buffer
// #define PANEL_NO_BUFFER // no buffer, immediate mode only
// #define PANEL_NO_FONT // disables everything font related, saves some flash
// #define PANEL_MAX_SPEED // aggresively inlines the 4 draw assembly instructions, else its kept as a method to keep size down
// #define PANEL_FLIP_VERTICAL // flips the panel vertically
// #define PANEL_FLIP_HORIZONTAL // flips the panel horizontally
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

#endif // PANEL_SETTINGS_H