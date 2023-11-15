#define PANEL_X 64
#define PANEL_Y 32
#define PANEL_NO_BUFFER 1
// disable wait on the color output
#define MAX_BRIGHTNESS_SLEEP_MUSEC 0
#define BRIGHTNESS_SLEEP_MUSEC 20
#include "HUB75nano.h"

Panel panel = {};
uint8_t ri, gi, bi;

#define SLOWDOWN 5

void setup()
{
}

void loop()
{
    // this example iterates through colors in the panel
    for (uint8_t i = 0; i < 255; i++)
    {
        // red
        if (i <= 85)
            ri = 255 - i * 3;
        else if (i < 170)
            ri = 0;
        else
            ri = (i - 170) * 3;

        // green
        if (i <= 85)
            gi = i * 3;
        else if (i < 170)
            gi = (170 - i) * 3;
        else
            gi = 0;

        // blue
        if (i <= 85)
            bi = 0;
        else if (i < 170)
            bi = (i - 85) * 3;
        else
            bi = (255 - i) * 3;

        for (size_t s = 0; s < SLOWDOWN; s++)
        {
            panel.fillScreenColor({{.red = (uint8_t)(ri >> (8 - MAX_COLORDEPTH)), .green = (uint8_t)(gi >> (8 - MAX_COLORDEPTH)), .blue = (uint8_t)(bi >> (8 - MAX_COLORDEPTH))}});
        }
    }

    //         _    _
    //   Red: | \__/ |
    //        0 __   1
    // Green: |/  \__|
    //        0   __ 1
    //  Blue: |__/  \|
    //        0 |  | 1
    //         1/3 2/3
}
