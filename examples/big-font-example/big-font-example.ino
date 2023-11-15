#define PANEL_BIG 1
#include "HUB75nano.h"

// create an instance of the panel
Panel panel = {};
char out[81];
uint8_t length = 0;
uint8_t oldlength;
uint8_t fcolor = 3;
uint8_t bgcolor = 2;
char t;
// String test = "23.576%";

void setup()
{
    // panel.createBufferBG(bgcolor);

    panel.fillBuffer(Colors::BLACK); // background black
    // panel.createBufferBG(26);//background red

    panel.drawBigChar(0, 0, 'A', Colors::RED, Colors::NO_COLOR, 1);
    panel.drawBigChar(4, 0, 'a', Colors::GREEN, Colors::NO_COLOR, 1);
    panel.drawBigChar(8, 0, 'B', Colors::BLUE, Colors::NO_COLOR, 1);
    panel.drawBigChar(12, 0, 'b', Colors::WHITE, Colors::NO_COLOR, 1);
    panel.drawBigChar(16, 0, 'C', Colors::PURPLE, Colors::NO_COLOR, 1);
    panel.drawBigChar(20, 0, 'c', Colors::YELLOW, Colors::NO_COLOR, 1);
    panel.drawBigChar(24, 0, 'D', Colors::CYAN, Colors::NO_COLOR, 1);
    panel.drawBigChar(28, 0, 'd', Colors::DARKRED, Colors::NO_COLOR, 1);
    panel.drawBigChar(32, 0, 'E', Colors::DARKGREEN, Colors::NO_COLOR, 1);
    panel.drawBigChar(36, 0, 'e', Colors::DARKBLUE, Colors::NO_COLOR, 1);
    panel.drawBigChar(40, 0, 'F', Colors::DARKWHITE, Colors::NO_COLOR, 1);
    panel.drawBigChar(44, 0, 'f', Colors::DARKPURPLE, Colors::NO_COLOR, 1);
    panel.drawBigChar(48, 0, 'G', Colors::DARKYELLOW, Colors::NO_COLOR, 1);
    panel.drawBigChar(52, 0, 'g', Colors::DARKCYAN, Colors::NO_COLOR, 1);
    panel.drawBigChar(56, 0, 'H', Colors::DARKERRED, Colors::NO_COLOR, 1);
    panel.drawBigChar(60, 0, 'h', Colors::DARKERGREEN, Colors::NO_COLOR, 1);
    panel.drawBigChar(0, 6, 'I', Colors::DARKERBLUE, Colors::NO_COLOR, 2);
    panel.drawBigChar(8, 6, 'i', Colors::DARKERWHITE, Colors::NO_COLOR, 2);
    panel.drawBigChar(16, 6, 'J', Colors::DARKERPURPLE, Colors::NO_COLOR, 2);
    panel.drawBigChar(24, 6, 'j', Colors::DARKERYELLOW, Colors::NO_COLOR, 2);
    panel.drawBigChar(32, 6, 'K', Colors::DARKERCYAN, Colors::NO_COLOR, 2);
    panel.drawBigChar(40, 6, 'k', Colors::RED, Colors::NO_COLOR, 2);
    panel.drawBigChar(48, 6, 'L', Colors::GREEN, Colors::NO_COLOR, 2);
    panel.drawBigChar(56, 6, 'l', Colors::BLUE, Colors::NO_COLOR, 2);
    panel.drawBigChar(0, 17, 'M', Colors::WHITE, Colors::NO_COLOR, 3);
    panel.drawBigChar(16, 17, 'm', Colors::PURPLE, Colors::NO_COLOR, 3);
    panel.drawBigChar(32, 17, 'N', Colors::YELLOW, Colors::NO_COLOR, 3);
    panel.drawBigChar(48, 17, 'n', Colors::CYAN, Colors::RED, 3);

    /*
    panel.drawBigChar( 0,7,'2',0,-1,3);
    panel.drawBigChar(10,7,'3',0,-1,3);
    panel.drawBigChar(17,7,'.',0,-1,3);
    panel.drawBigChar(24,7,'5',0,-1,3);
    panel.drawBigChar(34,7,'7',2,-1,3);
    panel.drawBigChar(44,7,'6',2,-1,3);
    panel.drawBigChar(54,7,'%',2,-1,3);


    panel.drawBigChar( 0,7,test[0],0,-1,3);
    panel.drawBigChar(10,7,test[1],0,-1,3);
    panel.drawBigChar(17,7,test[2],0,-1,3);
    panel.drawBigChar(24,7,test[3],0,-1,3);
    panel.drawBigChar(34,7,test[4],2,-1,3);
    panel.drawBigChar(44,7,test[5],2,-1,3);
    panel.drawBigChar(54,7,test[6],2,-1,3);
    */
}

void loop()
{
    // String test = "23.576%";
    // panel.drawBigChar(5,10,'2',0,3);
    panel.displayBuffer(); // makes the buffer visible and the leds all blinky blinky
}