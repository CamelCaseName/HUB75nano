#include "Pixel.h"



//a struct for a 1x1 pixel
struct Small {
    uint8_t y : 5; //y coordinate of set pixel
    uint8_t r : 1; //r value of set pixel
    uint8_t g : 1; //g value of set pixel
    uint8_t b : 1; //b value of set pixel
    uint8_t : 0;
    uint8_t x : 6; //x coordinate of set pixel
    uint8_t v : 1; //visible or not
    uint8_t : 1;
    uint8_t : 0;
};

//a struct for a 2x2 led pixel
/*struct Large {
    uint8_t x : 4; //x coordinate of set pixel
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

Pixel::Pixel(uint8_t maxAmount, uint8_t panelX, uint8_t panelY) {
    Small pixs[maxAmount];
    height = panelX;
    width = panelY;
}

void Pixel::translate(uint8_t Xspeed, uint8_t Yspeed, uint8_t index) {
    pixs[index].x += Xspeed;
    pixs[index].y += Yspeed;
};
/*
uint16_t Panel::convertCoords(uint8_t x, uint8_t y) {
    return x / 8 * y;
}
*/
