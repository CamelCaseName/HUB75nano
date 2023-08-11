#define PANEL_X 64
#define PANEL_Y 32
#define PANEL_NO_BUFFER 1
#define MAX_COLORDEPTH 4

#include "Panel.h"

Panel panel = {};
uint8_t r, g, b;
#if MAX_COLORDEPTH > 2
uint16_t ri, gi, bi;
#else
uint8_t ri, gi, bi;
#endif
#define MAX_ITER ((MAX_COLOR + 1) * (MAX_COLOR + 1) * (MAX_COLOR + 1))

#define SLOWDOWN 10

// tweak rgb wave here, offsets are to be a max of MAX_ITER / 2.
#define OFFSET_R (uint8_t)((MAX_COLOR + 1) * (MAX_COLOR + 1) * 0)
#define OFFSET_G (uint8_t)((MAX_COLOR + 1) * (MAX_COLOR + 1) * 0.3333)
#define OFFSET_B (uint8_t)((MAX_COLOR + 1) * (MAX_COLOR + 1) * 0.6666)

void setup()
{
}

void loop()
{
    // this example iterates through ALL available colors in the panel
    for (uint16_t i = 0; i < MAX_ITER; i++)
    {
        // red
        if (i <= OFFSET_R)
            ri = OFFSET_R - i;
        else if (i < (MAX_ITER / 2) + OFFSET_R)
            ri = i - OFFSET_R;
        else
            ri = MAX_ITER + OFFSET_R - i;

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

        for (uint8_t j = 0; j < SLOWDOWN; j++)
        {
            panel.fillScreenColor(r, g, b);
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
