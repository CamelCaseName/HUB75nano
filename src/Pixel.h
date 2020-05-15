/*
  Pixel.h is a library which can be used to generate single pixels to use together with led panel.

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

#include "arduino.h"

#ifndef Pixel_h
#define Pixel_h

class Pixel {
    public:
        Pixel(uint8_t maxAmount, uint8_t panelX, uint8_t panelY);
        void translate(uint8_t newX, uint8_t newY);
        //uint16_t convertCoords(uint8_t x, uint8_t y);
        struct Small {
            uint8_t y : 5; //x coordinate of set pixel, long side
            uint8_t r : 1; //r value of set pixel
            uint8_t g : 1; //g value of set pixel
            uint8_t b : 1; //b value of set pixel
            uint8_t : 0;
            uint8_t x : 6; //y coordinate of set pixel
            uint8_t v : 1; //visible or not
            uint8_t : 1;
            uint8_t : 0;
        };
        /*struct Large {
            uint8_t x : 4; //x coordinate of set pixel, short side
            uint8_t r : 1; //r value of set pixel
            uint8_t g : 1; //g value of set pixel
            uint8_t b : 1; //b value of set pixel
            uint8_t : 1;
            uint8_t : 0;
            uint8_t y : 5; //y coordinate of set pixel
            uint8_t v : 1; //visible or not
            uint8_t : 2;
            uint8_t : 0;
        };*/
        uint8_t height;
        uint8_t width;
        Small pixs[256];//ram limits
        //Large pixl[];
};

#endif