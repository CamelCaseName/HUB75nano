#define PANEL_BIG 1
#include "HUB75nano.h"

// create an instance of the panel
Panel panel = {};

void setup()
{

    panel.fillBuffer(Colors::BLACK); // background black
    // panel.createBufferBG(26);//background red

    panel.drawRect(0, 0, 5, 10, Colors::YELLOW, true);    // yellow filled rectangle top left
    panel.drawRect(25, 16, 29, 23, Colors::GREEN, false); // green hollow rectangle somewhere in the middle
    panel.drawLine(6, 0, 63, 31, Colors::WHITE);          // white diagonal through nearly the whole frame
    panel.drawCircle(50, 10, 5, Colors::BLUE, false);     // hollow blue circle top right
    panel.drawCircle(11, 25, 5, Colors::DARKBLUE, true);  // filled cyan circle bottom left
    panel.drawEllipse(30, 6, 6, 3, Colors::GREEN, false);
    panel.drawEllipse(60, 19, 3, 8, Colors::DARKPURPLE, true);
}

void loop()
{
    panel.displayBuffer(); // makes the buffer visible and the leds all blinky blinky
}