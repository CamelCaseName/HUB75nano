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

#include <arduino.h>

#ifndef Panel_h
#define Panel_h

class Panel{
  public:
    Panel(int height, int width);
    void init(bool useBuffer);
    void emptyLine();
    void selectLine(uint8_t c);
    void fillScreenShift(int s);
    void fillScreenColor(int c);
    void sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl);
    void sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl);
    void sendData(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl, bool rows);
    void displayBuffer();
    void test();
    void clock(uint8_t d);
    void latch();
    void createBuffer();
    struct LED{
      unsigned int rc1 : 1;
      unsigned int gc1 : 1;
      unsigned int bc1 : 1;  
      unsigned int rc2 : 1;
      unsigned int gc2 : 1;
      unsigned int bc2 : 1; 
      unsigned int rc3 : 1;
      unsigned int gc3 : 1; 
      unsigned int :0;
      unsigned int bc3 : 1;
      unsigned int rc4 : 1; 
      unsigned int gc4 : 1;
      unsigned int bc4 : 1; 
      unsigned int rc5 : 1;
      unsigned int gc5 : 1;
      unsigned int bc5 : 1;  
      unsigned int rc6 : 1;
      unsigned int :0;
      unsigned int gc6 : 1;
      unsigned int bc6 : 1; 
      unsigned int rc7 : 1;
      unsigned int gc7 : 1; 
      unsigned int bc7 : 1;
      unsigned int rc8 : 1; 
      unsigned int gc8 : 1;
      unsigned int bc8 : 1; 
      unsigned int :0;
    };
    enum StringValue { RED, GREEN, BLUE, WHITE,BLACK,PURPLE,YELLOW,CYAN,LIGHTRED,LIGHTGREEN,LIGHTBLUE,LIGHTWHITE,LIGHTCYAN,DARKYELLOW,LIGHTPURPLE,LIGHTYELLOW,TURQUOISE,PINK,DARKPURPLE,BRIGHTGREEN,BRIGHTCYAN,MEDIUMGREEN,DEEPPURPLE,OCEANBLUE,FLESH,LIGHTPINK,};
    int rc1,gc1,bc1,rc2,gc2,bc2;
    uint8_t r,g,b,rows,cols;
    bool r1,g1,b1,r2,g2,b2; 
    LED buffer[256];
};

#endif