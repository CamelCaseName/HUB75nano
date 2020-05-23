#include "Panel.h"

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

uint8_t rows;
uint8_t cols;
uint16_t bsize;

//color values
uint8_t rc1;
uint8_t gc1;
uint8_t bc1;
uint8_t rc2;
uint8_t gc2;
uint8_t bc2;

//register for string pin status
bool r1;
bool g1;
bool b1;
bool r2;
bool g2;
bool b2;

#pragma pack(1)
struct LED{//3 bytes long, contains 8 leds
    uint8_t rc1 : 1;
    uint8_t gc1 : 1;
    uint8_t bc1 : 1;  
    uint8_t rc2 : 1;
    uint8_t gc2 : 1;
    uint8_t bc2 : 1; 
    uint8_t rc3 : 1;
    uint8_t gc3 : 1; 
    uint8_t :0;
    uint8_t bc3 : 1;
    uint8_t rc4 : 1; 
    uint8_t gc4 : 1;
    uint8_t bc4 : 1; 
    uint8_t rc5 : 1;
    uint8_t gc5 : 1;
    uint8_t bc5 : 1;  
    uint8_t rc6 : 1;
    uint8_t :0;
    uint8_t gc6 : 1;
    uint8_t bc6 : 1; 
    uint8_t rc7 : 1;
    uint8_t gc7 : 1; 
    uint8_t bc7 : 1;
    uint8_t rc8 : 1; 
    uint8_t gc8 : 1;
    uint8_t bc8 : 1; 
    uint8_t :0;
};

//Copyright <2010> <Robey Pointer, https://robey.lag.net/> =========>
// 
//Permission is hereby granted, free of charge, to any person obtaining a copy of this softwareand associated documentation files(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and /or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions :
//The above copyright noticeand this permission notice shall be included in all copies or substantial portions of the Software.
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// Font Definition
const uint8_t font4x6[96][2] PROGMEM = {
 {  0x00  ,  0x00  },   /*SPACE*/
 {  0x49  ,  0x08  },   /*'!'*/
 {  0xb4  ,  0x00  },   /*'"'*/
 {  0xbe  ,  0xf6  },   /*'#'*/
 {  0x7b  ,  0x7a  },   /*'$'*/
 {  0xa5  ,  0x94  },   /*'%'*/
 {  0x55  ,  0xb8  },   /*'&'*/
 {  0x48  ,  0x00  },   /*'''*/
 {  0x29  ,  0x44  },   /*'('*/
 {  0x44  ,  0x2a  },   /*')'*/
 {  0x15  ,  0xa0  },   /*'*'*/
 {  0x0b  ,  0x42  },   /*'+'*/
 {  0x00  ,  0x50  },   /*','*/
 {  0x03  ,  0x02  },   /*'-'*/
 {  0x00  ,  0x08  },   /*'.'*/
 {  0x25  ,  0x90  },   /*'/'*/
 {  0x76  ,  0xba  },   /*'0'*/
 {  0x59  ,  0x5c  },   /*'1'*/
 {  0xc5  ,  0x9e  },   /*'2'*/
 {  0xc5  ,  0x38  },   /*'3'*/
 {  0x92  ,  0xe6  },   /*'4'*/
 {  0xf3  ,  0x3a  },   /*'5'*/
 {  0x73  ,  0xba  },   /*'6'*/
 {  0xe5  ,  0x90  },   /*'7'*/
 {  0x77  ,  0xba  },   /*'8'*/
 {  0x77  ,  0x3a  },   /*'9'*/
 {  0x08  ,  0x40  },   /*':'*/
 {  0x08  ,  0x50  },   /*';'*/
 {  0x2a  ,  0x44  },   /*'<'*/
 {  0x1c  ,  0xe0  },   /*'='*/
 {  0x88  ,  0x52  },   /*'>'*/
 {  0xe5  ,  0x08  },   /*'?'*/
 {  0x56  ,  0x8e  },   /*'@'*/
 {  0x77  ,  0xb6  },   /*'A'*/
 {  0x77  ,  0xb8  },   /*'B'*/
 {  0x72  ,  0x8c  },   /*'C'*/
 {  0xd6  ,  0xba  },   /*'D'*/
 {  0x73  ,  0x9e  },   /*'E'*/
 {  0x73  ,  0x92  },   /*'F'*/
 {  0x72  ,  0xae  },   /*'G'*/
 {  0xb7  ,  0xb6  },   /*'H'*/
 {  0xe9  ,  0x5c  },   /*'I'*/
 {  0x64  ,  0xaa  },   /*'J'*/
 {  0xb7  ,  0xb4  },   /*'K'*/
 {  0x92  ,  0x9c  },   /*'L'*/
 {  0xbe  ,  0xb6  },   /*'M'*/
 {  0xd6  ,  0xb6  },   /*'N'*/
 {  0x56  ,  0xaa  },   /*'O'*/
 {  0xd7  ,  0x92  },   /*'P'*/
 {  0x76  ,  0xee  },   /*'Q'*/
 {  0x77  ,  0xb4  },   /*'R'*/
 {  0x71  ,  0x38  },   /*'S'*/
 {  0xe9  ,  0x48  },   /*'T'*/
 {  0xb6  ,  0xae  },   /*'U'*/
 {  0xb6  ,  0xaa  },   /*'V'*/
 {  0xb6  ,  0xf6  },   /*'W'*/
 {  0xb5  ,  0xb4  },   /*'X'*/
 {  0xb5  ,  0x48  },   /*'Y'*/
 {  0xe5  ,  0x9c  },   /*'Z'*/
 {  0x69  ,  0x4c  },   /*'['*/
 {  0x91  ,  0x24  },   /*'\'*/
 {  0x64  ,  0x2e  },   /*']'*/
 {  0x54  ,  0x00  },   /*'^'*/
 {  0x00  ,  0x1c  },   /*'_'*/
 {  0x44  ,  0x00  },   /*'`'*/
 {  0x0e  ,  0xae  },   /*'a'*/
 {  0x9a  ,  0xba  },   /*'b'*/
 {  0x0e  ,  0x8c  },   /*'c'*/
 {  0x2e  ,  0xae  },   /*'d'*/
 {  0x0e  ,  0xce  },   /*'e'*/
 {  0x56  ,  0xd0  },   /*'f'*/
 {  0x55  ,  0x3B  },   /*'g'*/
 {  0x93  ,  0xb4  },   /*'h'*/
 {  0x41  ,  0x44  },   /*'i'*/
 {  0x41  ,  0x51  },   /*'j'*/
 {  0x97  ,  0xb4  },   /*'k'*/
 {  0x49  ,  0x44  },   /*'l'*/
 {  0x17  ,  0xb6  },   /*'m'*/
 {  0x1a  ,  0xb6  },   /*'n'*/
 {  0x0a  ,  0xaa  },   /*'o'*/
 {  0xd6  ,  0xd3  },   /*'p'*/
 {  0x76  ,  0x67  },   /*'q'*/
 {  0x17  ,  0x90  },   /*'r'*/
 {  0x0f  ,  0x38  },   /*'s'*/
 {  0x9a  ,  0x8c  },   /*'t'*/
 {  0x16  ,  0xae  },   /*'u'*/
 {  0x16  ,  0xba  },   /*'v'*/
 {  0x16  ,  0xf6  },   /*'w'*/
 {  0x15  ,  0xb4  },   /*'x'*/
 {  0xb5  ,  0x2b  },   /*'y'*/
 {  0x1c  ,  0x5e  },   /*'z'*/
 {  0x6b  ,  0x4c  },   /*'{'*/
 {  0x49  ,  0x48  },   /*'|'*/
 {  0xc9  ,  0x5a  },   /*'}'*/
 {  0x54  ,  0x00  },   /*'~'*/
 {  0x56  ,  0xe2  }    /*''*/
};
//<=============================================================================
// 
//  
// 
//Copyright <2015> <https://hackaday.io/PK.3>========================>
// 
//Permission is hereby granted, free of charge, to any person obtaining a copy of this softwareand associated documentation files(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and /or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions :
//The above copyright noticeand this permission notice shall be included in all copies or substantial portions of the Software.
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//Font retreival function - ugly, but needed. 
//kindly stolen from https://hackaday.io/project/6309-vga-graphics-over-spi-and-serial-vgatonic/log/20759-a-tiny-4x6-pixel-font-that-will-fit-on-almost-any-microcontroller-license-mit#header
unsigned char getFontLine(unsigned char data, int line_num) {
    const uint8_t index = (data - 32);
    unsigned char pixel = 0;
    if (pgm_read_byte(&font4x6[index][1]) & 1 == 1) line_num -= 1;
    if (line_num == 0) {
        pixel = (pgm_read_byte(&font4x6[index][0])) >> 4;
    }
    else if (line_num == 1) {
        pixel = (pgm_read_byte(&font4x6[index][0])) >> 1;
    }
    else if (line_num == 2) {
        // Split over 2 bytes
        return (((pgm_read_byte(&font4x6[index][0])) & 0x03) << 2) | (((pgm_read_byte(&font4x6[index][1])) & 0x02));
    }
    else if (line_num == 3) {
        pixel = (pgm_read_byte(&font4x6[index][1])) >> 4;
    }
    else if (line_num == 4) {
        pixel = (pgm_read_byte(&font4x6[index][1])) >> 1;
    }
    return pixel & 0xE;
}//<=============================================================================

enum Colors { 
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

Panel::Panel(uint8_t height,uint8_t width, bool usebuffer){
    rows = height;
    cols = width;
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
    pinMode(RA, OUTPUT);
    pinMode(RB, OUTPUT);
    pinMode(RC, OUTPUT);
    pinMode(RD, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(RF, OUTPUT);
    pinMode(RS, OUTPUT);
    pinMode(GF, OUTPUT);
    pinMode(GS, OUTPUT);
    pinMode(BF, OUTPUT);
    pinMode(BS, OUTPUT);
    pinMode(LAT, OUTPUT);
    pinMode(OE, OUTPUT);
    
    //primarily used for debugging
    Serial.begin(112500);
    
    
    if (usebuffer) {
        //each LED struct contains 8 leds, rows * cols in total, so rows*cols/8 is needed
        bsize = rows * (cols / 8);
        LED buffer[bsize];
    }
}

void cnvColor(uint8_t c, uint8_t *rt, uint8_t *gt, uint8_t *bt ){//input color, get converted color by reference
    switch (c){
        case RED:
            *rt = 1;
            *gt = 0;
            *bt = 0;
            break;
        case GREEN:
            *rt = 0;
            *gt = 1;
            *bt = 0;
            break;
        case BLUE:
            *rt = 0;
            *gt = 0;
            *bt = 1;
            break;
        case WHITE:
            *rt = 1;
            *gt = 1;
            *bt = 1;
            break;
        case BLACK:
            *rt = 0;
            *gt = 0;
            *bt = 0;
            break;
        case PURPLE:
            *rt = 1;
            *gt = 0;
            *bt = 1;
            break;
        case YELLOW:
            *rt = 1;
            *gt = 1;
            *bt = 0;
            break;
        case CYAN:
            *rt = 0;
            *gt = 1;
            *bt = 1;
            break;

        default:
            *rt = 1;
            *gt = 1;
            *bt = 1;
            break;
    }
}

void Panel::createBufferBG(uint8_t c){//creates a buffer used to display stuff
    //get colors
    uint8_t rt, gt, bt;
    cnvColor(c, &rt, &gt, &bt);

    //initiates buffer accordingly
    for(uint16_t x = 0; x < bsize; x++){
        buffer[x].rc1 = rt;
        buffer[x].gc1 = gt;
        buffer[x].bc1 = bt;
        buffer[x].rc2 = rt;
        buffer[x].gc2 = gt;
        buffer[x].bc2 = bt;
        buffer[x].rc3 = rt;
        buffer[x].gc3 = gt;
        buffer[x].bc3 = bt;
        buffer[x].rc4 = rt;
        buffer[x].gc4 = gt;
        buffer[x].bc4 = bt;
        buffer[x].rc5 = rt;
        buffer[x].gc5 = gt;
        buffer[x].bc5 = bt;
        buffer[x].rc6 = rt;
        buffer[x].gc6 = gt;
        buffer[x].bc6 = bt;
        buffer[x].rc7 = rt;
        buffer[x].gc7 = gt;
        buffer[x].bc7 = bt;
        buffer[x].rc8 = rt;
        buffer[x].gc8 = gt;
        buffer[x].bc8 = bt;
    }
}

void Panel::emptyLine() {//outputs an empty row on the selected line
    //output off
    digitalWrite(OE, LOW);
    //address zero
    digitalWrite(RA, LOW);
    digitalWrite(RB, LOW);
    digitalWrite(RC, LOW);
    digitalWrite(RD, LOW);
}

void Panel::latch() {//this function cleans up and latches the data, so diplays it
    //latch output
    digitalWrite(LAT, HIGH);
    //delatch
    digitalWrite(LAT, LOW);
    //enable output
    digitalWrite(OE, HIGH);
    emptyLine();
}

void Panel::selectLine(uint8_t c) {//selects one of the 16 lines, 0 based
    switch (c) {
        case B0000:
            digitalWrite(RA, HIGH);
            digitalWrite(RB, HIGH);
            digitalWrite(RC, HIGH);
            digitalWrite(RD, HIGH);
            digitalWrite(RA, LOW);
            digitalWrite(RB, LOW);
            digitalWrite(RC, LOW);
            digitalWrite(RD, LOW);
        break;
        case B0001:
            digitalWrite(RA, HIGH);
        break;
        case B0010:
            digitalWrite(RB, HIGH);
        break;
        case B0011:
            digitalWrite(RA, HIGH);
            digitalWrite(RB, HIGH);
        break;
        case B0100:
            digitalWrite(RC, HIGH);
        break;
        case B0101:
            digitalWrite(RA, HIGH);
            digitalWrite(RC, HIGH);
        break;
        case B0110:
            digitalWrite(RB, HIGH);
            digitalWrite(RC, HIGH);
        break;
        case B0111:
            digitalWrite(RA, HIGH);
            digitalWrite(RB, HIGH);
            digitalWrite(RC, HIGH);
        break;
        case B1000:
            digitalWrite(RD, HIGH);
        break;
        case B1001:
            digitalWrite(RA, HIGH);
            digitalWrite(RD, HIGH);
        break;
        case B1010:
            digitalWrite(RB, HIGH);
            digitalWrite(RD, HIGH);
        break;
        case B1011:
            digitalWrite(RA, HIGH);
            digitalWrite(RB, HIGH);
            digitalWrite(RD, HIGH);
        break;
        case B1100:
            digitalWrite(RC, HIGH);
            digitalWrite(RD, HIGH);
        break;
        case B1101:
            digitalWrite(RA, HIGH);
            digitalWrite(RC, HIGH);
            digitalWrite(RD, HIGH);
        break;
        case B1110:
            digitalWrite(RB, HIGH);
            digitalWrite(RC, HIGH);
            digitalWrite(RD, HIGH);
        break;
        case B1111:
            digitalWrite(RA, HIGH);
            digitalWrite(RB, HIGH);
            digitalWrite(RC, HIGH);
            digitalWrite(RD, HIGH);
        break;
    }
}

void Panel::fillScreenShift(uint8_t s, uint8_t f, uint8_t o) {//creates interesting patterns (shift, factor, offset)
    for (uint8_t r = 0; r < rows / 2; r++) {
        //switch through all rows
        selectLine(r);

        for (uint8_t c = 0; c<cols; c++) {
            //c = coloumn r = row s = shift for moving fist number is offset for color, second for overall
            rc1 =  ((c + 0 + r + s*1 + o) % f) == 0;
            bc1 =  ((c + 1 + r + s*2 + o) % f) == 0;
            gc1 =  ((c + 2 + r + s*3 + o) % f) == 0;
            rc1 ^= ((c + 3 - r + s*1 + o) % f) == 0;
            gc1 ^= ((c + 4 - r + s*2 + o) % f) == 0;
            bc1 ^= ((c + 5 - r + s*3 + o) % f) == 0;
            sendTwoPixels(rc1,gc1,bc1,rc1,gc1,bc1);
        }       
        latch(); //general latch to get rid of ghosting, or so i thought
    }
}

void Panel::fillScreenColor(uint8_t c){//fills the screeen with the set color
    //switches all the colrs and sets the values depending on colors
    switch (c)
    {
        case RED:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                rc1 = 1;
                gc1 = 0;
                bc1 = 0;
                sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
            }
            break;
        
        case GREEN:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                rc1 = 0;
                gc1 = 1;
                bc1 = 0;
                sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
            }
            break;
        
        case BLUE:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                rc1 = 0;
                gc1 = 0;
                bc1 = 1;
                sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
            }
            break;
        
        case WHITE:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                rc1 = 1;
                gc1 = 1;
                bc1 = 1;
                sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
            }
            break;
        
        case BLACK:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                //output off
                digitalWrite(OE, LOW);
                //address zero
                digitalWrite(RA, LOW);
                digitalWrite(RB, LOW);
                digitalWrite(RC, LOW);
                digitalWrite(RD, LOW);
                for (size_t i = 0; i < cols; i++)
                {
                    clock();
                }
            }
            break;
        
        case PURPLE:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                rc1 = 1;
                gc1 = 0;
                bc1 = 1;
                sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
            }
            break;
        
        case YELLOW:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                rc1 = 1;
                gc1 = 1;
                bc1 = 0;
                sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
            }
            break;
        
        case CYAN:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                rc1 = 0;
                gc1 = 1;
                bc1 = 1;
                sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
            }
            break;
        case LIGHTRED:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = 0;
                bc1 = 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;
        
        case LIGHTGREEN:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 0;
                gc1 = (i % 2) == 0;
                bc1 = 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;
        
        case LIGHTBLUE:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 0; 
                gc1 = 0;
                bc1 = (i % 2) == 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;
        
        case LIGHTWHITE:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = (i % 2) == 0;
                bc1 = (i % 2) == 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;
        
        case LIGHTCYAN:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 0;
                gc1 = (i % 2) == 0;
                bc1 = (i % 2) == 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;
        
        case DARKYELLOW:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 1;
                gc1 = (i % 2) == 0;
                bc1 = 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case LIGHTPURPLE:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = 0;
                bc1 = (i % 2) == 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case LIGHTYELLOW:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = (i % 2) == 0;
                bc1 = 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case TURQUOISE:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 0;
                gc1 = 1;
                bc1 = (i % 2) == 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case PINK:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 1;
                gc1 = 0;
                bc1 = (i % 2) == 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;
        
        case DARKPURPLE:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = 0;
                bc1 = 1;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case BRIGHTGREEN:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = 1;
                bc1 = 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case BRIGHTCYAN:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = 1;
                bc1 = 1;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case MEDIUMGREEN:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = 1;
                bc1 = (i % 2) == 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case DEEPPURPLE:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = (i % 2) == 0;
                gc1 = (i % 2) == 0;
                bc1 = 1;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case OCEANBLUE:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 0;
                gc1 = (i % 2) == 0;
                bc1 = 1;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case FLESH:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 1;
                gc1 = (i % 2) == 0;
                bc1 = (i % 2) == 0;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        case LIGHTPINK:
            for (uint8_t i = 0; i < 32; i++){//for loop to do pwm
                //depending on wether to switch led fast or not
                rc1 = 1;
                gc1 = (i % 2) == 0;
                bc1 = 1;
                for (uint8_t r = 0; r < rows / 2; r++) {
                    //switch through all rows
                    selectLine(r);
                    sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
                }
            }
            break;

        default:
            for (uint8_t r = 0; r < rows / 2; r++) {
                //switch through all rows
                selectLine(r);

                rc1 = 1;
                gc1 = 1;
                bc1 = 1;
                sendWholeRow(rc1,gc1,bc1,rc1,gc1,bc1);
            }
            break;
    }
}

void Panel::sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl){ //sends two pixels, one in upper half, one in lower half to display | first upper half values, the lower half
    if (ru > 0 && r1 == false) //turns upper half red
    {
        digitalWrite(RF, HIGH);
        r1 = true;
    }
    else if (ru == 0 && r1 == true) {
        digitalWrite(RF, LOW);
        r1 = false;
    }

    if (gu > 0 && g1 == false) //turns upper half green
    {
        digitalWrite(GF, HIGH);
        g1 = true;
    }
    else if (gu == 0 && g1 == true) {
        digitalWrite(GF, LOW);
        g1 = false;
    }

    if (bu > 0 && b1 == false) //turns upper half blue
    {
        digitalWrite(BF, HIGH);
        b1 = true;
    }
    else if (bu == 0 && b1 == true) {
        digitalWrite(BF, LOW);
        b1 = false;
    }

    if (rl > 0 && r2 == false) //turns lower half red
    {
        digitalWrite(RS, HIGH);
        r2 = true;
    }
    else if (rl == 0 && r2 == true) {
        digitalWrite(RS, LOW);
        r2 = false;
    }

    if (gl > 0 && g2 == false) //turns lower half green
    {
        digitalWrite(GS, HIGH);
        g2 = true;
    }
    else if (gl == 0 && g2 == true) {
        digitalWrite(GS, LOW);
        g2 = false;
    }

    if (bl > 0 && b2 == false) //turns lower half blue
    {
        digitalWrite(BS, HIGH);
        b2 = true;
    }
    else if (bl == 0 && b2 == true) {
        digitalWrite(BS, LOW);
        b2 = false;
    }
    clock();
}

void Panel::sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl) { //sends two rows of pixels to display | first upper half values, the lower half
    
    if (ru > 0 && r1 == false) //turns upper half red
    {
        digitalWrite(RF, HIGH);
        r1 = true;
    }
    else if (ru == 0 && r1 == true) {
        digitalWrite(RF, LOW);
        r1 = false;
    }

    if (gu > 0 && g1 == false) //turns upper half green
    {
        digitalWrite(GF, HIGH);
        g1 = true;
    }
    else if (gu == 0 && g1 == true) {
        digitalWrite(GF, LOW);
        g1 = false;
    }

    if (bu > 0 && b1 == false) //turns upper half blue
    {
        digitalWrite(BF, HIGH);
        b1 = true;
    }
    else if (bu == 0 && b1 == true) {
        digitalWrite(BF, LOW);
        b1 = false;
    }

    if (rl > 0 && r2 == false) //turns lower half red
    {
        digitalWrite(RS, HIGH);
        r2 = true;
    }
    else if (rl == 0 && r2 == true) {
        digitalWrite(RS, LOW);
        r2 = false;
    }

    if (gl > 0 && g2 == false) //turns lower half green
    {
        digitalWrite(GS, HIGH);
        g2 = true;
    }
    else if (gl == 0 && g2 == true) {
        digitalWrite(GS, LOW);
        g2 = false;
    }

    if (bl > 0 && b2 == false) //turns lower half blue
    {
        digitalWrite(BS, HIGH);
        b2 = true;
    }
    else if (bl == 0 && b2 == true) {
        digitalWrite(BS, LOW);
        b2 = false;
    }

    for (uint8_t i = 0; i < cols; i++) {
        clock();
    }
    latch();
}

void Panel::clock() {//clock function for data entry
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
}

void Panel::displayBuffer() {//puts the  buffer contents onto the display
    uint8_t t = rows * 4;
    //uint16_t t = 3 * 4;
    uint8_t x = 0;
    for(x = 0; x < t; x++){
        //Serial.println(x/8);
        //for (uint8_t f = 0; f < 2; f++) {
        if (x / 8 > 0) {
            selectLine((x / 8) - 1);
        }
        else {
            selectLine(15);
        }
        
        //             r1                  g1                  b1                   r2                    g2                        b2
        sendTwoPixels(buffer[x + 0].rc1, buffer[x + 0].gc1, buffer[x + 0].bc1, buffer[x + 0 + (t)].rc1, buffer[x + 0 + (t)].gc1, buffer[x + 0 + (t)].bc1);
        sendTwoPixels(buffer[x + 0].rc2, buffer[x + 0].gc2, buffer[x + 0].bc2, buffer[x + 0 + (t)].rc2, buffer[x + 0 + (t)].gc2, buffer[x + 0 + (t)].bc2);
        sendTwoPixels(buffer[x + 0].rc3, buffer[x + 0].gc3, buffer[x + 0].bc3, buffer[x + 0 + (t)].rc3, buffer[x + 0 + (t)].gc3, buffer[x + 0 + (t)].bc3);
        sendTwoPixels(buffer[x + 0].rc4, buffer[x + 0].gc4, buffer[x + 0].bc4, buffer[x + 0 + (t)].rc4, buffer[x + 0 + (t)].gc4, buffer[x + 0 + (t)].bc4);
        sendTwoPixels(buffer[x + 0].rc5, buffer[x + 0].gc5, buffer[x + 0].bc5, buffer[x + 0 + (t)].rc5, buffer[x + 0 + (t)].gc5, buffer[x + 0 + (t)].bc5);
        sendTwoPixels(buffer[x + 0].rc6, buffer[x + 0].gc6, buffer[x + 0].bc6, buffer[x + 0 + (t)].rc6, buffer[x + 0 + (t)].gc6, buffer[x + 0 + (t)].bc6);
        sendTwoPixels(buffer[x + 0].rc7, buffer[x + 0].gc7, buffer[x + 0].bc7, buffer[x + 0 + (t)].rc7, buffer[x + 0 + (t)].gc7, buffer[x + 0 + (t)].bc7);
        sendTwoPixels(buffer[x + 0].rc8, buffer[x + 0].gc8, buffer[x + 0].bc8, buffer[x + 0 + (t)].rc8, buffer[x + 0 + (t)].gc8, buffer[x + 0 + (t)].bc8);
        sendTwoPixels(buffer[x + 1].rc1, buffer[x + 1].gc1, buffer[x + 1].bc1, buffer[x + 1 + (t)].rc1, buffer[x + 1 + (t)].gc1, buffer[x + 1 + (t)].bc1);
        sendTwoPixels(buffer[x + 1].rc2, buffer[x + 1].gc2, buffer[x + 1].bc2, buffer[x + 1 + (t)].rc2, buffer[x + 1 + (t)].gc2, buffer[x + 1 + (t)].bc2);
        sendTwoPixels(buffer[x + 1].rc3, buffer[x + 1].gc3, buffer[x + 1].bc3, buffer[x + 1 + (t)].rc3, buffer[x + 1 + (t)].gc3, buffer[x + 1 + (t)].bc3);
        sendTwoPixels(buffer[x + 1].rc4, buffer[x + 1].gc4, buffer[x + 1].bc4, buffer[x + 1 + (t)].rc4, buffer[x + 1 + (t)].gc4, buffer[x + 1 + (t)].bc4);
        sendTwoPixels(buffer[x + 1].rc5, buffer[x + 1].gc5, buffer[x + 1].bc5, buffer[x + 1 + (t)].rc5, buffer[x + 1 + (t)].gc5, buffer[x + 1 + (t)].bc5);
        sendTwoPixels(buffer[x + 1].rc6, buffer[x + 1].gc6, buffer[x + 1].bc6, buffer[x + 1 + (t)].rc6, buffer[x + 1 + (t)].gc6, buffer[x + 1 + (t)].bc6);
        sendTwoPixels(buffer[x + 1].rc7, buffer[x + 1].gc7, buffer[x + 1].bc7, buffer[x + 1 + (t)].rc7, buffer[x + 1 + (t)].gc7, buffer[x + 1 + (t)].bc7);
        sendTwoPixels(buffer[x + 1].rc8, buffer[x + 1].gc8, buffer[x + 1].bc8, buffer[x + 1 + (t)].rc8, buffer[x + 1 + (t)].gc8, buffer[x + 1 + (t)].bc8);
        sendTwoPixels(buffer[x + 2].rc1, buffer[x + 2].gc1, buffer[x + 2].bc1, buffer[x + 2 + (t)].rc1, buffer[x + 2 + (t)].gc1, buffer[x + 2 + (t)].bc1);
        sendTwoPixels(buffer[x + 2].rc2, buffer[x + 2].gc2, buffer[x + 2].bc2, buffer[x + 2 + (t)].rc2, buffer[x + 2 + (t)].gc2, buffer[x + 2 + (t)].bc2);
        sendTwoPixels(buffer[x + 2].rc3, buffer[x + 2].gc3, buffer[x + 2].bc3, buffer[x + 2 + (t)].rc3, buffer[x + 2 + (t)].gc3, buffer[x + 2 + (t)].bc3);
        sendTwoPixels(buffer[x + 2].rc4, buffer[x + 2].gc4, buffer[x + 2].bc4, buffer[x + 2 + (t)].rc4, buffer[x + 2 + (t)].gc4, buffer[x + 2 + (t)].bc4);
        sendTwoPixels(buffer[x + 2].rc5, buffer[x + 2].gc5, buffer[x + 2].bc5, buffer[x + 2 + (t)].rc5, buffer[x + 2 + (t)].gc5, buffer[x + 2 + (t)].bc5);
        sendTwoPixels(buffer[x + 2].rc6, buffer[x + 2].gc6, buffer[x + 2].bc6, buffer[x + 2 + (t)].rc6, buffer[x + 2 + (t)].gc6, buffer[x + 2 + (t)].bc6);
        sendTwoPixels(buffer[x + 2].rc7, buffer[x + 2].gc7, buffer[x + 2].bc7, buffer[x + 2 + (t)].rc7, buffer[x + 2 + (t)].gc7, buffer[x + 2 + (t)].bc7);
        sendTwoPixels(buffer[x + 2].rc8, buffer[x + 2].gc8, buffer[x + 2].bc8, buffer[x + 2 + (t)].rc8, buffer[x + 2 + (t)].gc8, buffer[x + 2 + (t)].bc8);
        sendTwoPixels(buffer[x + 3].rc1, buffer[x + 3].gc1, buffer[x + 3].bc1, buffer[x + 3 + (t)].rc1, buffer[x + 3 + (t)].gc1, buffer[x + 3 + (t)].bc1);
        sendTwoPixels(buffer[x + 3].rc2, buffer[x + 3].gc2, buffer[x + 3].bc2, buffer[x + 3 + (t)].rc2, buffer[x + 3 + (t)].gc2, buffer[x + 3 + (t)].bc2);
        sendTwoPixels(buffer[x + 3].rc3, buffer[x + 3].gc3, buffer[x + 3].bc3, buffer[x + 3 + (t)].rc3, buffer[x + 3 + (t)].gc3, buffer[x + 3 + (t)].bc3);
        sendTwoPixels(buffer[x + 3].rc4, buffer[x + 3].gc4, buffer[x + 3].bc4, buffer[x + 3 + (t)].rc4, buffer[x + 3 + (t)].gc4, buffer[x + 3 + (t)].bc4);
        sendTwoPixels(buffer[x + 3].rc5, buffer[x + 3].gc5, buffer[x + 3].bc5, buffer[x + 3 + (t)].rc5, buffer[x + 3 + (t)].gc5, buffer[x + 3 + (t)].bc5);
        sendTwoPixels(buffer[x + 3].rc6, buffer[x + 3].gc6, buffer[x + 3].bc6, buffer[x + 3 + (t)].rc6, buffer[x + 3 + (t)].gc6, buffer[x + 3 + (t)].bc6);
        sendTwoPixels(buffer[x + 3].rc7, buffer[x + 3].gc7, buffer[x + 3].bc7, buffer[x + 3 + (t)].rc7, buffer[x + 3 + (t)].gc7, buffer[x + 3 + (t)].bc7);
        sendTwoPixels(buffer[x + 3].rc8, buffer[x + 3].gc8, buffer[x + 3].bc8, buffer[x + 3 + (t)].rc8, buffer[x + 3 + (t)].gc8, buffer[x + 3 + (t)].bc8);
        sendTwoPixels(buffer[x + 4].rc1, buffer[x + 4].gc1, buffer[x + 4].bc1, buffer[x + 4 + (t)].rc1, buffer[x + 4 + (t)].gc1, buffer[x + 4 + (t)].bc1);
        sendTwoPixels(buffer[x + 4].rc2, buffer[x + 4].gc2, buffer[x + 4].bc2, buffer[x + 4 + (t)].rc2, buffer[x + 4 + (t)].gc2, buffer[x + 4 + (t)].bc2);
        sendTwoPixels(buffer[x + 4].rc3, buffer[x + 4].gc3, buffer[x + 4].bc3, buffer[x + 4 + (t)].rc3, buffer[x + 4 + (t)].gc3, buffer[x + 4 + (t)].bc3);
        sendTwoPixels(buffer[x + 4].rc4, buffer[x + 4].gc4, buffer[x + 4].bc4, buffer[x + 4 + (t)].rc4, buffer[x + 4 + (t)].gc4, buffer[x + 4 + (t)].bc4);
        sendTwoPixels(buffer[x + 4].rc5, buffer[x + 4].gc5, buffer[x + 4].bc5, buffer[x + 4 + (t)].rc5, buffer[x + 4 + (t)].gc5, buffer[x + 4 + (t)].bc5);
        sendTwoPixels(buffer[x + 4].rc6, buffer[x + 4].gc6, buffer[x + 4].bc6, buffer[x + 4 + (t)].rc6, buffer[x + 4 + (t)].gc6, buffer[x + 4 + (t)].bc6);
        sendTwoPixels(buffer[x + 4].rc7, buffer[x + 4].gc7, buffer[x + 4].bc7, buffer[x + 4 + (t)].rc7, buffer[x + 4 + (t)].gc7, buffer[x + 4 + (t)].bc7);
        sendTwoPixels(buffer[x + 4].rc8, buffer[x + 4].gc8, buffer[x + 4].bc8, buffer[x + 4 + (t)].rc8, buffer[x + 4 + (t)].gc8, buffer[x + 4 + (t)].bc8);
        sendTwoPixels(buffer[x + 5].rc1, buffer[x + 5].gc1, buffer[x + 5].bc1, buffer[x + 5 + (t)].rc1, buffer[x + 5 + (t)].gc1, buffer[x + 5 + (t)].bc1);
        sendTwoPixels(buffer[x + 5].rc2, buffer[x + 5].gc2, buffer[x + 5].bc2, buffer[x + 5 + (t)].rc2, buffer[x + 5 + (t)].gc2, buffer[x + 5 + (t)].bc2);
        sendTwoPixels(buffer[x + 5].rc3, buffer[x + 5].gc3, buffer[x + 5].bc3, buffer[x + 5 + (t)].rc3, buffer[x + 5 + (t)].gc3, buffer[x + 5 + (t)].bc3);
        sendTwoPixels(buffer[x + 5].rc4, buffer[x + 5].gc4, buffer[x + 5].bc4, buffer[x + 5 + (t)].rc4, buffer[x + 5 + (t)].gc4, buffer[x + 5 + (t)].bc4);
        sendTwoPixels(buffer[x + 5].rc5, buffer[x + 5].gc5, buffer[x + 5].bc5, buffer[x + 5 + (t)].rc5, buffer[x + 5 + (t)].gc5, buffer[x + 5 + (t)].bc5);
        sendTwoPixels(buffer[x + 5].rc6, buffer[x + 5].gc6, buffer[x + 5].bc6, buffer[x + 5 + (t)].rc6, buffer[x + 5 + (t)].gc6, buffer[x + 5 + (t)].bc6);
        sendTwoPixels(buffer[x + 5].rc7, buffer[x + 5].gc7, buffer[x + 5].bc7, buffer[x + 5 + (t)].rc7, buffer[x + 5 + (t)].gc7, buffer[x + 5 + (t)].bc7);
        sendTwoPixels(buffer[x + 5].rc8, buffer[x + 5].gc8, buffer[x + 5].bc8, buffer[x + 5 + (t)].rc8, buffer[x + 5 + (t)].gc8, buffer[x + 5 + (t)].bc8);
        sendTwoPixels(buffer[x + 6].rc1, buffer[x + 6].gc1, buffer[x + 6].bc1, buffer[x + 6 + (t)].rc1, buffer[x + 6 + (t)].gc1, buffer[x + 6 + (t)].bc1);
        sendTwoPixels(buffer[x + 6].rc2, buffer[x + 6].gc2, buffer[x + 6].bc2, buffer[x + 6 + (t)].rc2, buffer[x + 6 + (t)].gc2, buffer[x + 6 + (t)].bc2);
        sendTwoPixels(buffer[x + 6].rc3, buffer[x + 6].gc3, buffer[x + 6].bc3, buffer[x + 6 + (t)].rc3, buffer[x + 6 + (t)].gc3, buffer[x + 6 + (t)].bc3);
        sendTwoPixels(buffer[x + 6].rc4, buffer[x + 6].gc4, buffer[x + 6].bc4, buffer[x + 6 + (t)].rc4, buffer[x + 6 + (t)].gc4, buffer[x + 6 + (t)].bc4);
        sendTwoPixels(buffer[x + 6].rc5, buffer[x + 6].gc5, buffer[x + 6].bc5, buffer[x + 6 + (t)].rc5, buffer[x + 6 + (t)].gc5, buffer[x + 6 + (t)].bc5);
        sendTwoPixels(buffer[x + 6].rc6, buffer[x + 6].gc6, buffer[x + 6].bc6, buffer[x + 6 + (t)].rc6, buffer[x + 6 + (t)].gc6, buffer[x + 6 + (t)].bc6);
        sendTwoPixels(buffer[x + 6].rc7, buffer[x + 6].gc7, buffer[x + 6].bc7, buffer[x + 6 + (t)].rc7, buffer[x + 6 + (t)].gc7, buffer[x + 6 + (t)].bc7);
        sendTwoPixels(buffer[x + 6].rc8, buffer[x + 6].gc8, buffer[x + 6].bc8, buffer[x + 6 + (t)].rc8, buffer[x + 6 + (t)].gc8, buffer[x + 6 + (t)].bc8);
        sendTwoPixels(buffer[x + 7].rc1, buffer[x + 7].gc1, buffer[x + 7].bc1, buffer[x + 7 + (t)].rc1, buffer[x + 7 + (t)].gc1, buffer[x + 7 + (t)].bc1);
        sendTwoPixels(buffer[x + 7].rc2, buffer[x + 7].gc2, buffer[x + 7].bc2, buffer[x + 7 + (t)].rc2, buffer[x + 7 + (t)].gc2, buffer[x + 7 + (t)].bc2);
        sendTwoPixels(buffer[x + 7].rc3, buffer[x + 7].gc3, buffer[x + 7].bc3, buffer[x + 7 + (t)].rc3, buffer[x + 7 + (t)].gc3, buffer[x + 7 + (t)].bc3);
        sendTwoPixels(buffer[x + 7].rc4, buffer[x + 7].gc4, buffer[x + 7].bc4, buffer[x + 7 + (t)].rc4, buffer[x + 7 + (t)].gc4, buffer[x + 7 + (t)].bc4);
        sendTwoPixels(buffer[x + 7].rc5, buffer[x + 7].gc5, buffer[x + 7].bc5, buffer[x + 7 + (t)].rc5, buffer[x + 7 + (t)].gc5, buffer[x + 7 + (t)].bc5);
        sendTwoPixels(buffer[x + 7].rc6, buffer[x + 7].gc6, buffer[x + 7].bc6, buffer[x + 7 + (t)].rc6, buffer[x + 7 + (t)].gc6, buffer[x + 7 + (t)].bc6);
        sendTwoPixels(buffer[x + 7].rc7, buffer[x + 7].gc7, buffer[x + 7].bc7, buffer[x + 7 + (t)].rc7, buffer[x + 7 + (t)].gc7, buffer[x + 7 + (t)].bc7);
        sendTwoPixels(buffer[x + 7].rc8, buffer[x + 7].gc8, buffer[x + 7].bc8, buffer[x + 7 + (t)].rc8, buffer[x + 7 + (t)].gc8, buffer[x + 7 + (t)].bc8);
        latch();
        //}
        x+=7;
    }
}

void Panel::clearBuffer(uint8_t c) {
    //get colors
    uint8_t rt, gt, bt;
    cnvColor(c, &rt, &gt, &bt);

        //fills the buffer
    for (uint16_t x = 0; x < bsize; x++) {
        buffer[x].rc1 = rt;
        buffer[x].gc1 = gt;
        buffer[x].bc1 = bt;
        buffer[x].rc2 = rt;
        buffer[x].gc2 = gt;
        buffer[x].bc2 = bt;
        buffer[x].rc3 = rt;
        buffer[x].gc3 = gt;
        buffer[x].bc3 = bt;
        buffer[x].rc4 = rt;
        buffer[x].gc4 = gt;
        buffer[x].bc4 = bt;
        buffer[x].rc5 = rt;
        buffer[x].gc5 = gt;
        buffer[x].bc5 = bt;
        buffer[x].rc6 = rt;
        buffer[x].gc6 = gt;
        buffer[x].bc6 = bt;
        buffer[x].rc7 = rt;
        buffer[x].gc7 = gt;
        buffer[x].bc7 = bt;
        buffer[x].rc8 = rt;
        buffer[x].gc8 = gt;
        buffer[x].bc8 = bt;
    }
}

void Panel::test(){
    //fills entire screen somehow
    fillScreenColor(OCEANBLUE);
}

void Panel::setBuffer(uint8_t r, uint8_t g, uint8_t b, uint8_t temp, uint8_t i) {
    switch (i % 8) {
        case 0:
            buffer[temp].rc1 = r;
            buffer[temp].gc1 = g;
            buffer[temp].bc1 = b;
            break;
        case 1:
            buffer[temp].rc2 = r;
            buffer[temp].gc2 = g;
            buffer[temp].bc2 = b;
            break;
        case 2:
            buffer[temp].rc3 = r;
            buffer[temp].gc3 = g;
            buffer[temp].bc3 = b;
            break;
        case 3:
            buffer[temp].rc4 = r;
            buffer[temp].gc4 = g;
            buffer[temp].bc4 = b;
            break;
        case 4:
            buffer[temp].rc5 = r;
            buffer[temp].gc5 = g;
            buffer[temp].bc5 = b;
            break;
        case 5:
            buffer[temp].rc6 = r;
            buffer[temp].gc6 = g;
            buffer[temp].bc6 = b;
            break;
        case 6:
            buffer[temp].rc7 = r;
            buffer[temp].gc7 = g;
            buffer[temp].bc7 = b;
            break;
        case 7: 
            buffer[temp].rc8 = r;
            buffer[temp].gc8 = g;
            buffer[temp].bc8 = b;
            break;
        default:
            break;
    }
}

void Panel::drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t c, bool fill) { //draws a rect filled ro not filled with the given color at coords (landscape, origin in upper left corner)
    //get colors
    uint8_t r, g, b;
    cnvColor(c, &r, &g, &b);

    if (fill) {
        for (uint8_t i = x1; i <= x2; i++) {
            for (uint8_t j = y1; j <= y2; j++) {
                uint8_t temp = (j * cols / 8) + (i / 8);
                setBuffer(r, g, b, temp, i);
            }
        }
    }
    else {
        //left line
        for (uint8_t j = y1; j <= y2; j++) {
            uint8_t temp = (j * cols / 8) + (x1 / 8);
            setBuffer(r, g, b, temp, x1);
        }

        //right line
        for (uint8_t j = y1; j <= y2; j++) {
            uint8_t temp = (j * cols / 8) + (x2 / 8);
            setBuffer(r, g, b, temp, x2);
        }
        
        //top line
        for (uint8_t i = x1; i <= x2; i++) {
            uint8_t temp = (y1 * cols / 8) + (i / 8);
            setBuffer(r, g, b, temp, i);
        }

        //bottom line
        for (uint8_t i = x1; i <= x2; i++) {
            uint8_t temp = (y2 * cols / 8) + (i / 8);
            setBuffer(r, g, b, temp, i);
        }
    }
}

void Panel::drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t c) { //draws a line with color at coords given, must be left to right
    //get colors
    uint8_t r, g, b;
    cnvColor(c, &r, &g, &b);

    //  f(x) = m*x+t
    //  t = f(0) = y1
    //  m =(y2-y1)/(x2-x1)
    //  ->iterate for each x from x1 to x2
    //

    float dy = y2 + 1 - y1;//delta y
    float m = dy / (x2 + 1 - x1);
    uint8_t temp = 0;
    //Serial.println(m);
    for (uint8_t x = 0; x <= (x2 - x1); x++){
        //Serial.print((m * x + y1) + 0.5f);
        //Serial.print(" ");
        //Serial.println(x + x1);
        uint8_t y = (uint8_t)(m * x + y1) + 0.5f;
        temp = (uint8_t) (y * cols / 8) + ((x + x1) / 8);
        setBuffer(r, g, b, temp, x + x1);
    }
}

void Panel::drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint8_t c, bool fill) { //draws a circle at the coords with radius and color
    //get colors
    uint8_t r, g, b;
    cnvColor(c, &r, &g, &b);
    uint8_t temp = 0;
    int xC;
    int yC;

    if (fill) {
        //draw outline
        for (uint8_t i = 1; i < 180; i++) {
            xC = x + (radius - 0.1) * cos(i * 0.035) + 0.5;
            yC = y + (radius - 0.1) * sin(i * 0.035) + 0.5;
            temp = (uint8_t)(yC * cols / 8) + xC / 8;
            setBuffer(r, g, b, temp, xC);
        }
        //check if point in circle, then fill
        for (uint8_t i = x - radius; i < x + radius; i++) {
            for (uint8_t j = y - radius; j < y + radius; j++) {
                if ((x - i) * (x - i) + (y - j) * (y - j) < ((radius - 0.5) * (radius - 0.5))) {
                    temp = (j * cols / 8) + i / 8;
                    setBuffer(r, g, b, temp, i);
                }
            }
        }
        //todo learn for finals
    }
    else {
        //draw circle outline
        for (uint8_t i = 1; i < 180; i++) {
            //draws a circle using trigonomic formulas
            xC = x + radius * cos(i * 0.035) + 0.5;
            yC = y + radius * sin(i * 0.035) + 0.5;
            //create index
            temp = (uint8_t) (yC * cols / 8) + xC / 8;
            setBuffer(r, g, b, temp, xC);
        }
    }
}

void Panel::drawChar(uint8_t x, uint8_t y, char ch, uint8_t c) {
    //color for the char
    uint8_t r, g, b;
    cnvColor(c, &r, &g, &b);
    //iterate through the character line by line
    uint8_t temp = 0;
    char out;
    for (uint8_t i = 0; i < 5; i++){
        out = getFontLine(ch, i);
        //iterate through the character bit by bit
        for (uint8_t j = 4; j > 0; --j) {
            temp = ((y + i) * (cols / 8) + (x + 4 - j) / 8);
                //shift by j and check for bit set
            if (out & (1 << j)) {
                //set pixel at i and j
                setBuffer(r, g, b, temp, x + 4 - j);
            }
        }
    }
}