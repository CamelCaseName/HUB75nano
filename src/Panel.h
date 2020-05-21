/*
  Panel.h can be used to display stuff on a hub75 panel with up to 32 x 64 pixels
  designed for ARDUINO NANO.

  (c) Leonhard Seidel, 2020

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
Pin mapping:
A A0,
B A1,
C A2,
D A4,
R1 2,
R2 5,
B1 4,
B2 7,
G1 3,
G2 6,
LAT A3,
CLK 8,
OE 9,
GND GND
*/
//#include "../../../../../../../Program Files (x86)/Arduino/hardware/arduino/avr/cores/arduino/Arduino.h"
#include <arduino.h>

#ifndef Panel_h
#define Panel_h

class Panel{
    public:
        Panel(uint8_t height, uint8_t width, bool usebuffer);
        void emptyLine();
        void selectLine(uint8_t c);
        void Panel::fillScreenShift(uint8_t s, uint8_t f, uint8_t o);
        void fillScreenColor(uint8_t c);
        void sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl);
        void sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl);
        void displayBuffer();
        void test();
        void clock(uint8_t d);
        void latch();
        void createBufferBG(uint8_t c);
        void drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t c, bool fill);
        void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t c);
        void drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint8_t c, bool fill);
        struct LED {
            uint8_t rc1 : 1;
            uint8_t gc1 : 1;
            uint8_t bc1 : 1;
            uint8_t rc2 : 1;
            uint8_t gc2 : 1;
            uint8_t bc2 : 1;
            uint8_t rc3 : 1;
            uint8_t gc3 : 1;
            uint8_t : 0;
            uint8_t bc3 : 1;
            uint8_t rc4 : 1;
            uint8_t gc4 : 1;
            uint8_t bc4 : 1;
            uint8_t rc5 : 1;
            uint8_t gc5 : 1;
            uint8_t bc5 : 1;
            uint8_t rc6 : 1;
            uint8_t : 0;
            uint8_t gc6 : 1;
            uint8_t bc6 : 1;
            uint8_t rc7 : 1;
            uint8_t gc7 : 1;
            uint8_t bc7 : 1;
            uint8_t rc8 : 1;
            uint8_t gc8 : 1;
            uint8_t bc8 : 1;
            uint8_t : 0;
        };
        enum StringValue { RED, GREEN, BLUE, WHITE,BLACK,PURPLE,YELLOW,CYAN,LIGHTRED,LIGHTGREEN,LIGHTBLUE,LIGHTWHITE,LIGHTCYAN,DARKYELLOW,LIGHTPURPLE,LIGHTYELLOW,TURQUOISE,PINK,DARKPURPLE,BRIGHTGREEN,BRIGHTCYAN,MEDIUMGREEN,DEEPPURPLE,OCEANBLUE,FLESH,LIGHTPINK,};
        uint8_t rows,cols,rc1,gc1,bc1,rc2,gc2,bc2,t;
        uint16_t bsize;
        bool r1,g1,b1,r2,g2,b2; 
        LED buffer[];//uses 768 bytes on max size display
    private:
        void Panel::setBuffer(uint8_t r, uint8_t g, uint8_t b, uint8_t temp, uint8_t i);
};
#endif