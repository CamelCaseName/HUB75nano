#define PANEL_X 64
#define PANEL_Y 32

#include "Panel.h"

Panel panel;
float Hue = 0.0f;
#define MAX_COLOR 16
uint8_t r = MAX_COLOR, g = MAX_COLOR, b = MAX_COLOR;
#define MAX_HUE 120
#define SIXTH_HUE static_cast<uint16_t>(MAX_HUE * 0.17)

void setup()
{
}

void loop()
{
    // this example iterates through ALL available colors in the panel
    for (uint16_t i = 0; i < MAX_HUE; i++)
    {
        Hue = 1.0f - ((MAX_HUE + 1.0f) / (i + 1.0f));
        if (Hue < 0.33333333f)
        {
            r = (2.0f - Hue * 6.0f) * MAX_COLOR;
            g = (Hue * 6.0f) * MAX_COLOR;
            b = 0;
        }
        else if (Hue < 0.6666666f)
        {
            r = 0;
            g = (4.0f - Hue * 6.0f) * MAX_COLOR;
            b = (Hue * 6.0f - 2.0f) * MAX_COLOR;
        }
        else
        {
            r = (Hue * 6.0f - 4.0f) * MAX_COLOR;
            g = 0;
            b = ((1.0f - Hue) * 6.0f) * MAX_COLOR;
        }
        r = r < MAX_COLOR ?: MAX_COLOR;
        g = g < MAX_COLOR ?: MAX_COLOR;
        b = b < MAX_COLOR ?: MAX_COLOR;

        //         _    _
        //   Red: | \__/ |
        //        0 __   1
        // Green: |/  \__|
        //        0   __ 1
        //  Blue: |__/  \|
        //        0 |  | 1
        //         1/3 2/3

        // panel.fillScreenColor(i / 4); // changes after some time (fast time)
        panel.fillScreenColor(FULL_TO_HIGH_COLOR(r, g, b));
    }

    // panel.test();

    /*
    |||ALL NAMED COLORS|||

    RED,
    GREEN,
    BLUE,
    WHITE,
    BLACK,
    PURPLE,
    YELLOW,
    CYAN,
    LIGHTRED,
    LIGHTGREEN,
    LIGHTBLUE,
    LIGHTWHITE,
    LIGHTCYAN,
    DARKYELLOW,
    LIGHTPURPLE,
    LIGHTYELLOW,
    TURQUOISE,
    PINK,
    DARKPURPLE,
    BRIGHTGREEN,
    BRIGHTCYAN,
    MEDIUMGREEN,
    DEEPPURPLE,
    OCEANBLUE,
    FLESH,
    LIGHTPINK,
    */

    // panel.fillScreenColor(panel.RED);
}
