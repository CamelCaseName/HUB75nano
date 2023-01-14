#define PANEL_X 64
#define PANEL_Y 32
#define PANEL_NO_BUFFER 1

#include "Panel.h"

Panel panel = {};
uint8_t r = MAX_COLOR, g = MAX_COLOR, b = MAX_COLOR;
#define SLOWDOWN 50
#define MAX_ITER ((MAX_COLOR + 1) * (MAX_COLOR + 1) * (MAX_COLOR + 1))
#define OFFSET_R 0
#define OFFSET_G 10
#define OFFSET_B 21

void setup()
{
}

void loop()
{
    uint8_t ri, gi, bi;
    // this example iterates through ALL available colors in the panel

    for (uint8_t i = 0; i < MAX_ITER; i++)
    {
        // red
        if (i <= OFFSET_R)
            ri = OFFSET_R - i;
        if (i > (MAX_ITER / 2) + OFFSET_R)
            ri = MAX_ITER - i;
        else
            ri = i;

        // green
        if (i <= OFFSET_G)
            gi = OFFSET_G - i;
        else if (i < (MAX_ITER / 2) + OFFSET_G)
            gi = i - OFFSET_G;
        else
            gi = MAX_ITER + OFFSET_G - i;

        // blue
        if (i <= OFFSET_B)
            bi = OFFSET_B - i;
        else if (i < (MAX_ITER / 2) + OFFSET_B)
            bi = i - OFFSET_B;
        else
            bi = MAX_ITER + OFFSET_B - i;

        r = (ri - 1) / (MAX_COLOR + 1);
        g = (gi - 1) / (MAX_COLOR + 1);
        b = (bi - 1) / (MAX_COLOR + 1);

        for (size_t j = 0; j < SLOWDOWN; j++)
        {
            panel.fillScreenColor(FULL_TO_HIGH_COLOR(r, g, b));
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
