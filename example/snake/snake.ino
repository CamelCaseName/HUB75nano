#include <Panel.h>
#include <Pixel.h>

//which cable goes where

#define RA 14 //register selector a
#define RB 15 //register selector b
#define RC 16 //register selector c
#define RD 18 //register selector d
#define RF 2 //red first byte
#define RS 5 //red second byte
#define BF 4 //blue first byte
#define BS 7 //blue second byte
#define GF 3 //green first byte
#define GS 6 //green second byte
#define LAT 17 //data latch
#define CLK 8 //clock signal
#define OE 9 //output enable

uint8_t maxAmount = 96;

Panel panel(32, 64, true);
Pixel pixel(maxAmount, 32, 64);

//creates a sideways smiley face
void setup() {
    uint8_t temp = 0;
    //makes every pixel white
    for (uint8_t i = 0; i < maxAmount; i++)
    {
        pixel.pixs[i].r = 1;
        pixel.pixs[i].g = 1;
        pixel.pixs[i].b = 1;
        pixel.pixs[i].v = 0;
    }

    //sets the buffer background to black
    panel.createBufferBG(panel.BLUE);

    //writes pixels to buffer
    putPixels();
}

void loop() {

    //outputs the buffer
    panel.displayBuffer();
}

void putPixels() {
    for (uint16_t pixelIndex = 0; pixelIndex < maxAmount; pixelIndex++) {
        uint8_t tx = pixel.pixs[pixelIndex].x;
        uint8_t ty = pixel.pixs[pixelIndex].y;
        uint16_t c = tx / 8 + (ty) * 8;
        if (pixel.pixs[pixelIndex].v) {
            Serial.print(tx);
            Serial.print(" ");
            Serial.print(ty);
            Serial.print(" ");
            Serial.println(c);
            switch (tx % 8) {
            case 0:
                panel.buffer[c].rc1 = pixel.pixs[pixelIndex].r;
                panel.buffer[c].gc1 = pixel.pixs[pixelIndex].g;
                panel.buffer[c].bc1 = pixel.pixs[pixelIndex].b;
                break;

            case 1:
                panel.buffer[c].rc2 = pixel.pixs[pixelIndex].r;
                panel.buffer[c].gc2 = pixel.pixs[pixelIndex].g;
                panel.buffer[c].bc2 = pixel.pixs[pixelIndex].b;
                break;

            case 2:
                panel.buffer[c].rc3 = pixel.pixs[pixelIndex].r;
                panel.buffer[c].gc3 = pixel.pixs[pixelIndex].g;
                panel.buffer[c].bc3 = pixel.pixs[pixelIndex].b;
                break;

            case 3:
                panel.buffer[c].rc4 = pixel.pixs[pixelIndex].r;
                panel.buffer[c].gc4 = pixel.pixs[pixelIndex].g;
                panel.buffer[c].bc4 = pixel.pixs[pixelIndex].b;
                break;

            case 4:
                panel.buffer[c].rc5 = pixel.pixs[pixelIndex].r;
                panel.buffer[c].gc5 = pixel.pixs[pixelIndex].g;
                panel.buffer[c].bc5 = pixel.pixs[pixelIndex].b;
                break;

            case 5:
                panel.buffer[c].rc6 = pixel.pixs[pixelIndex].r;
                panel.buffer[c].gc6 = pixel.pixs[pixelIndex].g;
                panel.buffer[c].bc6 = pixel.pixs[pixelIndex].b;
                break;

            case 6:
                panel.buffer[c].rc7 = pixel.pixs[pixelIndex].r;
                panel.buffer[c].gc7 = pixel.pixs[pixelIndex].g;
                panel.buffer[c].bc7 = pixel.pixs[pixelIndex].b;
                break;

            case 7:
                panel.buffer[c].rc8 = pixel.pixs[pixelIndex].r;
                panel.buffer[c].gc8 = pixel.pixs[pixelIndex].g;
                panel.buffer[c].bc8 = pixel.pixs[pixelIndex].b;
                break;

            default:
                break;
            }
        }
    }
}