#include "HUB75nano.h"

struct coords
{
    uint8_t x1 : 6;
    uint8_t : 2;
    uint8_t x2 : 6;
    uint8_t : 2;
    uint8_t x3 : 6;
    uint8_t : 2;
    uint8_t x4 : 6;
    uint8_t : 2;
    uint8_t x5 : 6;
    uint8_t : 2;
    uint8_t x6 : 6;
    uint8_t : 2;
};

// a bit broken rn, after the first letters leave the screen it goes haywire

// create an instance of the panel
Panel panel = {};

String srcText = "     Hello, World!     ";
coords cords;

void setup()
{
    panel.fillBuffer(Colors::RED); // background COLOR
}

void loop()
{
    for (uint8_t j = 0; j < srcText.length() - 5; j++)
    {
        for (uint8_t i = 0; i < 10; i++)
        {
            panel.drawRect(0, 7, 63, 23, Colors::BLACK, true);
            cords.x1 = 0 - i;
            panel.drawBigChar(cords.x1, 7 + (i == 0), srcText[j], Colors::WHITE, 3);
            cords.x2 = 10 - i;
            panel.drawBigChar(cords.x2, 8, srcText[j + 1], Colors::WHITE, 3);
            cords.x3 = 20 - i;
            panel.drawBigChar(cords.x3, 8, srcText[j + 2], Colors::WHITE, 3);
            cords.x4 = 30 - i;
            panel.drawBigChar(cords.x4, 8, srcText[j + 3], Colors::WHITE, 3);
            cords.x5 = 40 - i;
            panel.drawBigChar(cords.x5, 8, srcText[j + 4], Colors::WHITE, 3);
            cords.x6 = 50 - i;
            panel.drawBigChar(cords.x6, 8, srcText[j + 5], Colors::WHITE, 3);

            for (uint8_t l = 0; l < 100; l++)
            {
                panel.displayBuffer(); // makes the buffer visible and the leds all blinky blinky
            }
        }
    }
}