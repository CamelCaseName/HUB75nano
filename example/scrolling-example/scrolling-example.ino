#include "Panel.h"

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



// I M P O R T A N T

//in panel.h, you should comment out line Nr. 41 for this to work

//create an instance of the panel
Panel panel(32, 64);

String srcText = "Hello, World";
coords cords;

void setup() {
	panel.createBufferBG(panel.BLACK);//background COLOR
}


void loop() {
    for (uint8_t j = 0; j < srcText.length()-5; j++)
    {
        for (uint8_t i = 0; i < 10; i++)
        {
            panel.clearBuffer(panel.BLACK);
            cords.x1 = 0-i;
            panel.drawBigChar(cords.x1,8,srcText[j],panel.WHITE,3);
            cords.x2 = 10-i;
            panel.drawBigChar(cords.x2,8,srcText[j+1],panel.WHITE,3);
            cords.x3 = 20-i;
            panel.drawBigChar(cords.x3,8,srcText[j+2],panel.WHITE,3);
            cords.x4 = 30-i;
            panel.drawBigChar(cords.x4,8,srcText[j+3],panel.WHITE,3);
            cords.x5 = 40-i;
            panel.drawBigChar(cords.x5,8,srcText[j+4],panel.WHITE,3);
            cords.x6 = 50-i;
            panel.drawBigChar(cords.x6,8,srcText[j+5],panel.WHITE,3);
            
            for (uint8_t k = 0; k < 50; k++)
            {
                panel.displayBuffer(); //makes the buffer visible and the leds all blinky blinky
            }
            
        }
    }
}