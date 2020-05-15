#include <Panel.h>

struct LEDx8 {
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

Panel panel(32, 64, true);

static LEDx8 frame1[256];


void setup() {
    //a single line of the frame beeing set
    frame1[0].rc1 = 1; frame1[0].gc1 = 1; frame1[0].bc1 = 1; frame1[0].rc2 = 1; frame1[0].gc2 = 1; frame1[0].bc2 = 1; frame1[0].rc3 = 1; frame1[0].gc3 = 1; frame1[0].bc3 = 1; frame1[0].rc4 = 1; frame1[0].gc4 = 1; frame1[0].bc4 = 1; frame1[0].rc5 = 1; frame1[0].gc5 = 1; frame1[0].bc5 = 1; frame1[0].rc6 = 1; frame1[0].gc6 = 1; frame1[0].bc6 = 1; frame1[0].rc7 = 1; frame1[0].gc7 = 1; frame1[0].bc7 = 1; frame1[0].rc8 = 1; frame1[0].gc8 = 1; frame1[0].bc8 = 1; frame1[1].rc1 = 1; frame1[1].gc1 = 1; frame1[1].bc1 = 1; frame1[1].rc2 = 1; frame1[1].gc2 = 1; frame1[1].bc2 = 1; frame1[1].rc3 = 1; frame1[1].gc3 = 1; frame1[1].bc3 = 1; frame1[1].rc4 = 1; frame1[1].gc4 = 1; frame1[1].bc4 = 1; frame1[1].rc5 = 1; frame1[1].gc5 = 1; frame1[1].bc5 = 1; frame1[1].rc6 = 1; frame1[1].gc6 = 1; frame1[1].bc6 = 1; frame1[1].rc7 = 1; frame1[1].gc7 = 1; frame1[1].bc7 = 1; frame1[1].rc8 = 1; frame1[1].gc8 = 1; frame1[1].bc8 = 1; frame1[2].rc1 = 1; frame1[2].gc1 = 1; frame1[2].bc1 = 1; frame1[2].rc2 = 1; frame1[2].gc2 = 1; frame1[2].bc2 = 1; frame1[2].rc3 = 1; frame1[2].gc3 = 1; frame1[2].bc3 = 1; frame1[2].rc4 = 1; frame1[2].gc4 = 1; frame1[2].bc4 = 1; frame1[2].rc5 = 1; frame1[2].gc5 = 1; frame1[2].bc5 = 1; frame1[2].rc6 = 1; frame1[2].gc6 = 1; frame1[2].bc6 = 1; frame1[2].rc7 = 1; frame1[2].gc7 = 1; frame1[2].bc7 = 1; frame1[2].rc8 = 1; frame1[2].gc8 = 1; frame1[2].bc8 = 1; frame1[3].rc1 = 1; frame1[3].gc1 = 1; frame1[3].bc1 = 1; frame1[3].rc2 = 1; frame1[3].gc2 = 1; frame1[3].bc2 = 1; frame1[3].rc3 = 1; frame1[3].gc3 = 1; frame1[3].bc3 = 1; frame1[3].rc4 = 1; frame1[3].gc4 = 1; frame1[3].bc4 = 1; frame1[3].rc5 = 1; frame1[3].gc5 = 1; frame1[3].bc5 = 1; frame1[3].rc6 = 1; frame1[3].gc6 = 1; frame1[3].bc6 = 1; frame1[3].rc7 = 1; frame1[3].gc7 = 1; frame1[3].bc7 = 1; frame1[3].rc8 = 1; frame1[3].gc8 = 1; frame1[3].bc8 = 1; frame1[4].rc1 = 1; frame1[4].gc1 = 1; frame1[4].bc1 = 1; frame1[4].rc2 = 1; frame1[4].gc2 = 1; frame1[4].bc2 = 1; frame1[4].rc3 = 1; frame1[4].gc3 = 1; frame1[4].bc3 = 1; frame1[4].rc4 = 1; frame1[4].gc4 = 1; frame1[4].bc4 = 1; frame1[4].rc5 = 1; frame1[4].gc5 = 1; frame1[4].bc5 = 1; frame1[4].rc6 = 1; frame1[4].gc6 = 1; frame1[4].bc6 = 1; frame1[4].rc7 = 1; frame1[4].gc7 = 1; frame1[4].bc7 = 1; frame1[4].rc8 = 1; frame1[4].gc8 = 1; frame1[4].bc8 = 1; frame1[5].rc1 = 1; frame1[5].gc1 = 1; frame1[5].bc1 = 1; frame1[5].rc2 = 1; frame1[5].gc2 = 1; frame1[5].bc2 = 1; frame1[5].rc3 = 1; frame1[5].gc3 = 1; frame1[5].bc3 = 1; frame1[5].rc4 = 1; frame1[5].gc4 = 1; frame1[5].bc4 = 1; frame1[5].rc5 = 1; frame1[5].gc5 = 1; frame1[5].bc5 = 1; frame1[5].rc6 = 1; frame1[5].gc6 = 1; frame1[5].bc6 = 1; frame1[5].rc7 = 1; frame1[5].gc7 = 1; frame1[5].bc7 = 1; frame1[5].rc8 = 1; frame1[5].gc8 = 1; frame1[5].bc8 = 1; frame1[6].rc1 = 1; frame1[6].gc1 = 1; frame1[6].bc1 = 1; frame1[6].rc2 = 1; frame1[6].gc2 = 1; frame1[6].bc2 = 1; frame1[6].rc3 = 1; frame1[6].gc3 = 1; frame1[6].bc3 = 1; frame1[6].rc4 = 1; frame1[6].gc4 = 1; frame1[6].bc4 = 1; frame1[6].rc5 = 1; frame1[6].gc5 = 1; frame1[6].bc5 = 1; frame1[6].rc6 = 1; frame1[6].gc6 = 1; frame1[6].bc6 = 1; frame1[6].rc7 = 1; frame1[6].gc7 = 1; frame1[6].bc7 = 1; frame1[6].rc8 = 1; frame1[6].gc8 = 1; frame1[6].bc8 = 1; frame1[7].rc1 = 1; frame1[7].gc1 = 1; frame1[7].bc1 = 1; frame1[7].rc2 = 1; frame1[7].gc2 = 1; frame1[7].bc2 = 1; frame1[7].rc3 = 1; frame1[7].gc3 = 1; frame1[7].bc3 = 1; frame1[7].rc4 = 1; frame1[7].gc4 = 1; frame1[7].bc4 = 1; frame1[7].rc5 = 1; frame1[7].gc5 = 1; frame1[7].bc5 = 1; frame1[7].rc6 = 1; frame1[7].gc6 = 1; frame1[7].bc6 = 1; frame1[7].rc7 = 1; frame1[7].gc7 = 1; frame1[7].bc7 = 1; frame1[7].rc8 = 1; frame1[7].gc8 = 1; frame1[7].bc8 = 1;
    frame1[8].rc1 = 1; frame1[8].gc1 = 1; frame1[8].bc1 = 1; frame1[8].rc2 = 1; frame1[8].gc2 = 1; frame1[8].bc2 = 1; frame1[8].rc3 = 1; frame1[8].gc3 = 1; frame1[8].bc3 = 1; frame1[8].rc4 = 1; frame1[8].gc4 = 1; frame1[8].bc4 = 1; frame1[8].rc5 = 1; frame1[8].gc5 = 1; frame1[8].bc5 = 1; frame1[8].rc6 = 1; frame1[8].gc6 = 1; frame1[8].bc6 = 1; frame1[8].rc7 = 1; frame1[8].gc7 = 1; frame1[8].bc7 = 1; frame1[8].rc8 = 1; frame1[8].gc8 = 1; frame1[8].bc8 = 1; frame1[9].rc1 = 1; frame1[9].gc1 = 1; frame1[9].bc1 = 1; frame1[9].rc2 = 1; frame1[9].gc2 = 1; frame1[9].bc2 = 1; frame1[9].rc3 = 1; frame1[9].gc3 = 1; frame1[9].bc3 = 1; frame1[9].rc4 = 1; frame1[9].gc4 = 1; frame1[9].bc4 = 1; frame1[9].rc5 = 1; frame1[9].gc5 = 1; frame1[9].bc5 = 1; frame1[9].rc6 = 1; frame1[9].gc6 = 1; frame1[9].bc6 = 1; frame1[9].rc7 = 1; frame1[9].gc7 = 1; frame1[9].bc7 = 1; frame1[9].rc8 = 1; frame1[9].gc8 = 1; frame1[9].bc8 = 1; frame1[10].rc1 = 1; frame1[10].gc1 = 1; frame1[10].bc1 = 1; frame1[10].rc2 = 1; frame1[10].gc2 = 1; frame1[10].bc2 = 1; frame1[10].rc3 = 1; frame1[10].gc3 = 1; frame1[10].bc3 = 1; frame1[10].rc4 = 1; frame1[10].gc4 = 1; frame1[10].bc4 = 1; frame1[10].rc5 = 1; frame1[10].gc5 = 1; frame1[10].bc5 = 1; frame1[10].rc6 = 1; frame1[10].gc6 = 1; frame1[10].bc6 = 1; frame1[10].rc7 = 1; frame1[10].gc7 = 1; frame1[10].bc7 = 1; frame1[10].rc8 = 1; frame1[10].gc8 = 1; frame1[10].bc8 = 1; frame1[11].rc1 = 1; frame1[11].gc1 = 1; frame1[11].bc1 = 1; frame1[11].rc2 = 1; frame1[11].gc2 = 1; frame1[11].bc2 = 1; frame1[11].rc3 = 1; frame1[11].gc3 = 1; frame1[11].bc3 = 1; frame1[11].rc4 = 1; frame1[11].gc4 = 1; frame1[11].bc4 = 1; frame1[11].rc5 = 1; frame1[11].gc5 = 1; frame1[11].bc5 = 1; frame1[11].rc6 = 1; frame1[11].gc6 = 1; frame1[11].bc6 = 1; frame1[11].rc7 = 1; frame1[11].gc7 = 1; frame1[11].bc7 = 1; frame1[11].rc8 = 1; frame1[11].gc8 = 1; frame1[11].bc8 = 1; frame1[12].rc1 = 1; frame1[12].gc1 = 1; frame1[12].bc1 = 1; frame1[12].rc2 = 1; frame1[12].gc2 = 1; frame1[12].bc2 = 1; frame1[12].rc3 = 1; frame1[12].gc3 = 1; frame1[12].bc3 = 1; frame1[12].rc4 = 1; frame1[12].gc4 = 1; frame1[12].bc4 = 1; frame1[12].rc5 = 1; frame1[12].gc5 = 1; frame1[12].bc5 = 1; frame1[12].rc6 = 1; frame1[12].gc6 = 1; frame1[12].bc6 = 1; frame1[12].rc7 = 1; frame1[12].gc7 = 1; frame1[12].bc7 = 1; frame1[12].rc8 = 1; frame1[12].gc8 = 1; frame1[12].bc8 = 1; frame1[13].rc1 = 1; frame1[13].gc1 = 1; frame1[13].bc1 = 1; frame1[13].rc2 = 1; frame1[13].gc2 = 1; frame1[13].bc2 = 1; frame1[13].rc3 = 1; frame1[13].gc3 = 1; frame1[13].bc3 = 1; frame1[13].rc4 = 1; frame1[13].gc4 = 1; frame1[13].bc4 = 1; frame1[13].rc5 = 1; frame1[13].gc5 = 1; frame1[13].bc5 = 1; frame1[13].rc6 = 1; frame1[13].gc6 = 1; frame1[13].bc6 = 1; frame1[13].rc7 = 1; frame1[13].gc7 = 1; frame1[13].bc7 = 1; frame1[13].rc8 = 1; frame1[13].gc8 = 1; frame1[13].bc8 = 1; frame1[14].rc1 = 1; frame1[14].gc1 = 1; frame1[14].bc1 = 1; frame1[14].rc2 = 1; frame1[14].gc2 = 1; frame1[14].bc2 = 1; frame1[14].rc3 = 1; frame1[14].gc3 = 1; frame1[14].bc3 = 1; frame1[14].rc4 = 1; frame1[14].gc4 = 1; frame1[14].bc4 = 1; frame1[14].rc5 = 1; frame1[14].gc5 = 1; frame1[14].bc5 = 1; frame1[14].rc6 = 1; frame1[14].gc6 = 1; frame1[14].bc6 = 1; frame1[14].rc7 = 1; frame1[14].gc7 = 1; frame1[14].bc7 = 1; frame1[14].rc8 = 1; frame1[14].gc8 = 1; frame1[14].bc8 = 1; frame1[15].rc1 = 1; frame1[15].gc1 = 1; frame1[15].bc1 = 1; frame1[15].rc2 = 1; frame1[15].gc2 = 1; frame1[15].bc2 = 1; frame1[15].rc3 = 1; frame1[15].gc3 = 1; frame1[15].bc3 = 1; frame1[15].rc4 = 1; frame1[15].gc4 = 1; frame1[15].bc4 = 1; frame1[15].rc5 = 1; frame1[15].gc5 = 1; frame1[15].bc5 = 1; frame1[15].rc6 = 1; frame1[15].gc6 = 1; frame1[15].bc6 = 1; frame1[15].rc7 = 1; frame1[15].gc7 = 1; frame1[15].bc7 = 1; frame1[15].rc8 = 1; frame1[15].gc8 = 1; frame1[15].bc8 = 1;

    //sets the buffer background to black
    panel.createBufferBG(panel.BLACK);

    //put the predefined image in the buffer
    swapBuffer();
}

void loop() {

    //outputs the buffer
    panel.displayBuffer();
}

void swapBuffer() {
    for (uint16_t i = 0; i < 256; i++)
    {
        panel.buffer[i].rc1 = frame1[i].rc1;
        panel.buffer[i].gc1 = frame1[i].gc1;
        panel.buffer[i].bc1 = frame1[i].bc1;
        panel.buffer[i].rc2 = frame1[i].rc2;
        panel.buffer[i].gc2 = frame1[i].gc2;
        panel.buffer[i].bc2 = frame1[i].bc2;
        panel.buffer[i].rc3 = frame1[i].rc3;
        panel.buffer[i].gc3 = frame1[i].gc3;
        panel.buffer[i].bc3 = frame1[i].bc3;
        panel.buffer[i].rc4 = frame1[i].rc4;
        panel.buffer[i].gc4 = frame1[i].gc4;
        panel.buffer[i].bc4 = frame1[i].bc4;
        panel.buffer[i].rc5 = frame1[i].rc5;
        panel.buffer[i].gc5 = frame1[i].gc5;
        panel.buffer[i].bc5 = frame1[i].bc5;
        panel.buffer[i].rc6 = frame1[i].rc6;
        panel.buffer[i].gc6 = frame1[i].gc6;
        panel.buffer[i].bc6 = frame1[i].bc6;
        panel.buffer[i].rc7 = frame1[i].rc7;
        panel.buffer[i].gc7 = frame1[i].gc7;
        panel.buffer[i].bc7 = frame1[i].bc7;
        panel.buffer[i].rc8 = frame1[i].rc8;
        panel.buffer[i].gc8 = frame1[i].gc8;
        panel.buffer[i].bc8 = frame1[i].bc8;
    }
}