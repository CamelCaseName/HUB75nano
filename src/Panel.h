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

//#define DEBUG //[if you're reading this its already too late :)]
//#define BIG //uncomment this line when you need more ram, but not as much color. i might find a smaller way to store this, but i dont think there is one

#ifdef DEBUG
    #include "../../../../../../../Program Files (x86)/Arduino/hardware/arduino/avr/cores/arduino/Arduino.h"
#else
    #include <arduino.h>
#endif

#ifndef Panel_h
#define Panel_h

class Panel{
    public:
        uint8_t l;
        uint8_t k;
        void setBuffer(uint8_t r, uint8_t g, uint8_t b, uint8_t temp, uint8_t i); 
        Panel(uint8_t height, uint8_t width);
        const uint8_t font4x6[96][2];
        void selectLine(uint8_t i);
        void fillScreenShift(uint8_t s, uint8_t f, uint8_t o);
        void fillScreenColor(uint16_t c);
        //void cnvColor(uint16_t c, uint8_t* rt, uint8_t* gt, uint8_t* bt); //somehow doesnt work when not commented out
        void sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl);
        void sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl);
        void displayBuffer();
        void test();
        void clock();
        void latch();
        void createBufferBG(uint16_t c);
        void clearBuffer(uint16_t c);
        void drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t c, bool fill);
        void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t c);
        void drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t c, bool fill);
        void drawChar(uint8_t x, uint8_t y, char ch, uint16_t c);
        void drawBigChar(uint8_t x, uint8_t y, char ch, uint16_t c,uint8_t size_modifier);
#ifndef BIG
#pragma pack(1)
        struct LED {//3 bytes long, contains 8 leds at 1 bit color depth
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

#else
#pragma pack(1)
        struct LED {//6 bytes long, contains 8 leds at 2 bit color depth
            uint8_t rc1 : 2;
            uint8_t gc1 : 2;
            uint8_t bc1 : 2;
            uint8_t rc2 : 2;
            uint8_t : 0;
            uint8_t gc2 : 2;
            uint8_t bc2 : 2;
            uint8_t rc3 : 2;
            uint8_t gc3 : 2;
            uint8_t : 0;
            uint8_t bc3 : 2;
            uint8_t rc4 : 2;
            uint8_t gc4 : 2;
            uint8_t bc4 : 2;
            uint8_t : 0;
            uint8_t rc5 : 2;
            uint8_t gc5 : 2;
            uint8_t bc5 : 2;
            uint8_t rc6 : 2;
            uint8_t : 0;
            uint8_t gc6 : 2;
            uint8_t bc6 : 2;
            uint8_t rc7 : 2;
            uint8_t gc7 : 2;
            uint8_t : 0;
            uint8_t bc7 : 2;
            uint8_t rc8 : 2;
            uint8_t gc8 : 2;
            uint8_t bc8 : 2;
            uint8_t : 0;
        };
#endif
        enum Colors{
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
        };
        uint8_t rows,cols,halfbsize,bsize;
        LED buffer[256];//uses 768 bytes on max size display with 1 bit, 1536 bytes with 2 bits of depth - 2015 bytes of ram used
};
#endif
