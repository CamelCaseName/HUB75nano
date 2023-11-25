#define PANEL_X 64
#define PANEL_Y 32
#define PANEL_NO_BUFFER 1
#define MAX_FRAMETIME 127
#define MAX_COLORDEPTH 8
#include "HUB75nano.h"

Panel panel = {};
uint8_t ri, gi, bi;

template <int base, unsigned int exp>
struct Pow
{
    enum
    {
        value = base * Pow<base, exp - 1>::value
    };
};
// stopping condition
template <int base>
struct Pow<base, 0>
{
    enum
    {
        value = 1
    };
};

#define SLOWDOWN (uint8_t)(((8 - MAX_COLORDEPTH) * 10) + 1)

#define COLOR_COUNT (uint16_t)((Pow<2, MAX_COLORDEPTH>::value) * 3)
#define FIRST_THIRD (uint16_t)((COLOR_COUNT / 3)) - 1
#define SECOND_THIRD (uint16_t)((COLOR_COUNT / 3 * 2)) - 1
#define THIRD_THIRD (uint16_t)((COLOR_COUNT - 1))
#define MAX_COLOR (uint16_t)((Pow<2, MAX_COLORDEPTH>::value) - 1)
#define MAX_COLOR_TWO_THIRD (uint16_t)(MAX_COLOR / 3 * 2) + 1

void setup()
{
}

void loop()
{
    for (uint16_t i = 0; i < COLOR_COUNT; i++)
    {
        // red
        if (i <= FIRST_THIRD)
            ri = (uint8_t)(MAX_COLOR - i);
        else if (i <= SECOND_THIRD)
            ri = 0;
        else
            ri = (uint8_t)(i + 1 - SECOND_THIRD);

        // green
        if (i <= FIRST_THIRD)
            gi = (uint8_t)i;
        else if (i <= SECOND_THIRD)
            gi = (uint8_t)(MAX_COLOR - (i - FIRST_THIRD) - 1);
        else
            gi = 0;

        // blue
        if (i <= FIRST_THIRD)
            bi = 0;
        else if (i <= SECOND_THIRD)
            bi = (uint8_t)(i + 1 - FIRST_THIRD);
        else
            bi = (uint8_t)(MAX_COLOR - (i - SECOND_THIRD) - 1);

        for (size_t s = 0; s < SLOWDOWN; s++)
        {
            panel.fillScreenColor({{.red = ri, .green = gi, .blue = bi}});
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
