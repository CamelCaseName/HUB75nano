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

// I M P O R T A N T

// in panel.h, you should comment out line Nr. 41 for this to work better/more reliable

void setup()
{
    // panel.createBufferBG(bgcolor);

    panel.fillBuffer(panel.BLACK); // background black
    // panel.createBufferBG(26);//background red

    panel.drawBigChar(0, 0, 'A', panel.RED, 1);
    panel.drawBigChar(4, 0, 'a', panel.GREEN, 1);
    panel.drawBigChar(8, 0, 'B', panel.BLUE, 1);
    panel.drawBigChar(12, 0, 'b', panel.WHITE, 1);
    panel.drawBigChar(16, 0, 'C', panel.PURPLE, 1);
    panel.drawBigChar(20, 0, 'c', panel.YELLOW, 1);
    panel.drawBigChar(24, 0, 'D', panel.CYAN, 1);
    panel.drawBigChar(28, 0, 'd', panel.DARKRED, 1);
    panel.drawBigChar(32, 0, 'E', panel.DARKGREEN, 1);
    panel.drawBigChar(36, 0, 'e', panel.DARKBLUE, 1);
    panel.drawBigChar(40, 0, 'F', panel.DARKWHITE, 1);
    panel.drawBigChar(44, 0, 'f', panel.DARKPURPLE, 1);
    panel.drawBigChar(48, 0, 'G', panel.DARKYELLOW, 1);
    panel.drawBigChar(52, 0, 'g', panel.DARKCYAN, 1);
    panel.drawBigChar(56, 0, 'H', panel.DARKERRED, 1);
    panel.drawBigChar(60, 0, 'h', panel.DARKERGREEN, 1);
    panel.drawBigChar(0, 6, 'I', panel.DARKERBLUE, 2);
    panel.drawBigChar(8, 6, 'i', panel.DARKERWHITE, 2);
    panel.drawBigChar(16, 6, 'J', panel.DARKERPURPLE, 2);
    panel.drawBigChar(24, 6, 'j', panel.DARKERYELLOW, 2);
    panel.drawBigChar(32, 6, 'K', panel.DARKERCYAN, 2);
    panel.drawBigChar(40, 6, 'k', panel.RED, 2);
    panel.drawBigChar(48, 6, 'L', panel.GREEN, 2);
    panel.drawBigChar(56, 6, 'l', panel.BLUE, 2);
    panel.drawBigChar(0, 17, 'M', panel.WHITE, 3);
    panel.drawBigChar(16, 17, 'm', panel.PURPLE, 3);
    panel.drawBigChar(32, 17, 'N', panel.YELLOW, 3);
    panel.drawBigChar(48, 17, 'n', panel.CYAN, 3);

    /*
    panel.drawBigChar(0,7,'2',0,3);
    panel.drawBigChar(10,7,'3',0,3);
    panel.drawBigChar(17,7,'.',0,3);
    panel.drawBigChar(24,7,'5',0,3);
    panel.drawBigChar(34,7,'7',2,3);
    panel.drawBigChar(44,7,'6',2,3);
    panel.drawBigChar(54,7,'%',2,3);


    panel.drawBigChar(0,7,test[0],0,3);
    panel.drawBigChar(10,7,test[1],0,3);
    panel.drawBigChar(17,7,test[2],0,3);
    panel.drawBigChar(24,7,test[3],0,3);
    panel.drawBigChar(34,7,test[4],2,3);
    panel.drawBigChar(44,7,test[5],2,3);
    panel.drawBigChar(54,7,test[6],2,3);
    */
}

void loop()
{
    // String test = "23.576%";
    // panel.drawBigChar(5,10,'2',0,3);
    panel.displayBuffer(); // makes the buffer visible and the leds all blinky blinky
}