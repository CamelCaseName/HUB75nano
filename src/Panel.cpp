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

uint8_t rows, cols, bsize, l, k, r, g, b;

#ifndef BIG
#pragma pack(1)
struct LED{//3 bytes long, contains 8 leds at 1 bit color depth
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

Panel::Panel(uint8_t height,uint8_t width){
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
#ifdef DEBUG
    Serial.begin(112500);
#endif // DEBUG
    
    //each LED struct contains 8 leds, rows * cols in total, so rows*cols/8 is needed
    bsize = rows * (cols / 8) - 1;
    LED buffer[bsize + 1];
}

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

void cnvColor(uint16_t c, uint8_t *rt, uint8_t *gt, uint8_t *bt ){//input color, get converted color by reference
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
        case LIGHTRED:
            *rt = 2;
            *gt = 0;
            *bt = 0;
            break;
        case LIGHTGREEN:
            *rt = 0;
            *gt = 2;
            *bt = 0;
            break;
        case LIGHTBLUE:
            *rt = 0;
            *gt = 0;
            *bt = 2;
            break;
        case LIGHTWHITE:
            *rt = 2;
            *gt = 2;
            *bt = 2;
            break;
        case LIGHTCYAN:
            *rt = 0;
            *gt = 2;
            *bt = 2;
            break;
        case DARKYELLOW:
            *rt = 1;
            *gt = 2;
            *bt = 0;
            break;
        case LIGHTPURPLE:
            *rt = 2;
            *gt = 0;
            *bt = 2;
            break;
        case LIGHTYELLOW:
            *rt = 2;
            *gt = 2;
            *bt = 0;
            break;
        case TURQUOISE:
            *rt = 0;
            *gt = 1;
            *bt = 2;
            break;
        case PINK:
            *rt = 1;
            *gt = 0;
            *bt = 2;
            break;
        case DARKPURPLE:
            *rt = 2;
            *gt = 0;
            *bt = 1;
            break;
        case BRIGHTGREEN:
            *rt = 2;
            *gt = 1;
            *bt = 0;
            break;
        case BRIGHTCYAN:
            *rt = 2;
            *gt = 1;
            *bt = 1;
            break;
        case MEDIUMGREEN:
            *rt = 2;
            *gt = 1;
            *bt = 2;
            break;
        case DEEPPURPLE:
            *rt = 2;
            *gt = 2;
            *bt = 1;
            break;
        case OCEANBLUE:
            *rt = 0;
            *gt = 2;
            *bt = 1;
            break;
        case FLESH:
            *rt = 1;
            *gt = 2;
            *bt = 2;
            break;
        case LIGHTPINK:
            *rt = 1;
            *gt = 2;
            *bt = 1;
            break;

        default:
            *rt = (c >> 11) & B00001111;//in binary: RRRRRGGGGGGBBBBB >> 11 = 00000000000RRRRR
            *gt = (c >> 5) & B00001111; //in binary RRRRRGGGGGGBBBBB >> 5 = RRRRRGGGGGG, & B00111111(63) = 0000000000GGGGGG
            *bt = c & B00001111;  //in binary RRRRRGGGGGGBBBBB & 31(B00011111) = 00000000000BBBBB
            break;
    }
}

void Panel::createBufferBG(uint16_t c){//creates a buffer used to display stuff
    //get colors
    uint8_t rt, gt, bt;
    cnvColor(c, &rt, &gt, &bt);

    //initiates buffer accordingly
    for(uint16_t x = 0; x < bsize + 1; x++){
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

void Panel::latch() {//this function cleans up and latches the data, so diplays it
    //latch output
    PORTC |= B00001000; //LAT HIGH
    PORTC &= B11110111; //LAT LOW
    PORTB |= B00000010; //OE HIGH

    PORTC &= B11111110; //RA LOW
    PORTC &= B11111101; //RB LOW
    PORTC &= B11111011; //RC LOW
    PORTC &= B11101111; //RD LOW

    PORTB &= B11111101; //OE LOW
}

void Panel::selectLine(uint8_t i) {//selects one of the 16 lines, 0 based

    PORTC = (k + (k > 7) * 8) + (k > 15); //sets all rows 
    /*
    if (i & B0000) {
        PORTC &= B11101000; //RA LOW
    }
    if (i & B0001) {
        PORTC |= B00000001; //RA HIGH
    }
    if (i & B0010) {
        PORTC |= B00000010; //RB HIGH
    }
    if (i & B0100) {
        PORTC |= B00000100; //RC HIGH
    }
    if (i & B1000) {
        PORTC |= B00010000; //RD HIGH
    }*/

}

void Panel::fillScreenShift(uint8_t s, uint8_t f, uint8_t o) {//creates interesting patterns (shift, factor, offset) | I honestly dont know what it does, @hexchen made this
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    for (uint8_t r = 0; r < rows / 2; r++) {
        //switch through all rows
        selectLine(r);

        for (uint8_t c = 0; c<cols; c++) {
            //c = coloumn r = row s = shift for moving fist number is offset for color, second for overall
            r =  ((c + 0 + r + s*1 + o) % f) == 0;
            b =  ((c + 1 + r + s*2 + o) % f) == 0;
            g =  ((c + 2 + r + s*3 + o) % f) == 0;
            r ^= ((c + 3 - r + s*1 + o) % f) == 0;
            g ^= ((c + 4 - r + s*2 + o) % f) == 0;
            b ^= ((c + 5 - r + s*3 + o) % f) == 0;
            sendTwoPixels(r,g,b,r,g,b);
        }       
        latch(); //general latch to get rid of ghosting, or so i thought
    }
}

void Panel::fillScreenColor(uint16_t c){//fills the screeen with the set color
    //switches all the colors and sets the values depending on colors
    cnvColor(c, &r, &g, &b);//gets first couple colors

    for (uint8_t i = 0; i < 16; i++) {
        for (uint8_t row = 0; row < rows / 2; row++) {
            //switch through all rows
            selectLine(row);
            sendWholeRow(i % r == 0, i % g == 0, i % b == 0, i % r == 0, i % g == 0, i % b == 0);
        }
    }
}

void Panel::sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl){ //sends two pixels, one in upper half, one in lower half to display | first upper half values, the lower half
    //first red pin
    if (ru) {
        PORTD |= B00000100;
    }
    else {
        PORTD &= B11111011;
    }
    //first green pin
    if (gu) {
        PORTD |= B00001000;
    }
    else {
        PORTD &= B11110111;
    }
    //first blue pin
    if (bu) {
        PORTD |= B00010000;
    }
    else {
        PORTD &= B11101111;
    }
    //second red pin
    if (rl) {
        PORTD |= B00100000;
    }
    else {
        PORTD &= B11011111;
    }
    //second green pin
    if (gl) {
        PORTD |= B01000000;
    }
    else {
        PORTD &= B10111111;
    }
    //second blue pin
    if (bl) {
        PORTD |= B10000000;
    }
    else {
        PORTD &= B01111111;
    }
    clock();
}

void Panel::sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl) { //sends two rows of pixels to display | first upper half values, the lower half
    
    //first red pin
    if (ru) {
        PORTD |= B00000100;
    }
    else {
        PORTD &= B11111011;
    }
    //first green pin
    if (gu) {
        PORTD |= B00001000;
    }
    else {
        PORTD &= B11110111;
    }
    //first blue pin
    if (bu) {
        PORTD |= B00010000;
    }
    else {
        PORTD &= B11101111;
    }
    //second red pin
    if (rl) {
        PORTD |= B00100000;
    }
    else {
        PORTD &= B11011111;
    }
    //second green pin
    if (gl) {
        PORTD |= B01000000;
    }
    else {
        PORTD &= B10111111;
    }
    //second blue pin
    if (bl) {
        PORTD |= B10000000;
    }
    else {
        PORTD &= B01111111;
    }

    for (uint8_t i = 0; i < cols; i++) {
        clock();
    }
    latch();
}

void Panel::clock() {//clock function for data entry

    //sets clock high low very fast
    PORTB |= B00000001; //CLK HIGH
    PORTB &= B11111110; //CLK LOW
}

void Panel::displayBuffer() {//puts the  buffer contents onto the display
    for (uint8_t i = 0; i < (bsize + 1) / 2; i++) {
        l = i + (bsize + 1) / 2;
        k = i / 8;
        //select current row (and adjust for row drift with the buffer)
        
        /*
        if (k > 0) {
            --k;
            if (k & B0000) {
                PORTC &= B11101000; //RA LOW
            }
            if (k & B0001) {
                PORTC |= B00000001; //RA HIGH
            }
            if (k & B0010) {
                PORTC |= B00000010; //RB HIGH
            }
            if (k & B0100) {
                PORTC |= B00000100; //RC HIGH
            }
            if (k & B1000) {
                PORTC |= B00010000; //RD HIGH
            }
        }
        else {//select line 15 cuz i dont know but works
            PORTC |= B00010111; //RA HIGH
        }*/

        /*

        --k;
        if (k & B0000) {
            PORTC &= B11101000; //RABCD LOW
        }
        if (k & B0001) {
            PORTC |= B00000001; //RA HIGH
        }
        if (k & B0010) {
            PORTC |= B00000010; //RB HIGH
        }
        if (k & B0100) {
            PORTC |= B00000100; //RC HIGH
        }
        if (k & B1000) {
            PORTC |= B00010000; //RD HIGH
        }
        */
        //first pixels
        //and checks wether pixel set in buffer, therefor deciding the voltage to give
        //Serial.println(buffer[i].gc1);
        //first red pin
        if (buffer[i].rc1) {
            //Serial.println("1st part");
            PORTD |= B00000100;
        }
        else {
            PORTD &= B11111011;
        }
        //first green pin
        if (buffer[i].gc1) {
            PORTD |= B00001000;
        }
        else {
            PORTD &= B11110111;
        }
        //first blue pin
        if (buffer[i].bc1) {
            PORTD |= B00010000;
        }
        else {
            PORTD &= B11101111;
        }
        //second red pin
        if (buffer[l].rc1) {
            PORTD |= B00100000;
        }
        else {
            PORTD &= B11011111;
        }
        //second green pin
        if (buffer[l].gc1) {
            PORTD |= B01000000;
        }
        else {
            PORTD &= B10111111;
        }
        //second blue pin
        if (buffer[l].bc1) {
            PORTD |= B10000000;
        }
        else {
            PORTD &= B01111111;
        }

        //sets clock high low very fast
        PORTB |= B00000001; //CLK HIGH
        PORTB &= B11111110; //CLK LOW

        //second pixels

        //first red pin
        if (buffer[i].rc2) {
            PORTD |= B00000100;
        }
        else {
            PORTD &= B11111011;
        }
        //first green pin
        if (buffer[i].gc2) {
            PORTD |= B00001000;
        }
        else {
            PORTD &= B11110111;
        }
        //first blue pin
        if (buffer[i].bc2) {
            PORTD |= B00010000;
        }
        else {
            PORTD &= B11101111;
        }
        //second red pin
        if (buffer[l].rc2) {
            PORTD |= B00100000;
        }
        else {
            PORTD &= B11011111;
        }
        //second green pin
        if (buffer[l].gc2) {
            PORTD |= B01000000;
        }
        else {
            PORTD &= B10111111;
        }
        //second blue pin
        if (buffer[l].bc2) {
            PORTD |= B10000000;
        }
        else {
            PORTD &= B01111111;
        }

        PORTB |= B00000001; //CLK HIGH
        PORTB &= B11111110; //CLK LOW

        //3rd pixels
        //first red pin
        if (buffer[i].rc3) {
            PORTD |= B00000100;
        }
        else {
            PORTD &= B11111011;
        }
        //first green pin
        if (buffer[i].gc3) {
            PORTD |= B00001000;
        }
        else {
            PORTD &= B11110111;
        }
        //first blue pin
        if (buffer[i].bc3) {
            PORTD |= B00010000;
        }
        else {
            PORTD &= B11101111;
        }
        //second red pin
        if (buffer[l].rc3) {
            PORTD |= B00100000;
        }
        else {
            PORTD &= B11011111;
        }
        //second green pin
        if (buffer[l].gc3) {
            PORTD |= B01000000;
        }
        else {
            PORTD &= B10111111;
        }
        //second blue pin
        if (buffer[l].bc3) {
            PORTD |= B10000000;
        }
        else {
            PORTD &= B01111111;
        }

        PORTB |= B00000001; //CLK HIGH
        PORTB &= B11111110; //CLK LOW

        //4th pixels
        //first red pin
        if (buffer[i].rc4) {
            PORTD |= B00000100;
        }
        else {
            PORTD &= B11111011;
        }
        //first green pin
        if (buffer[i].gc4) {
            PORTD |= B00001000;
        }
        else {
            PORTD &= B11110111;
        }
        //first blue pin
        if (buffer[i].bc4) {
            PORTD |= B00010000;
        }
        else {
            PORTD &= B11101111;
        }
        //second red pin
        if (buffer[l].rc4) {
            PORTD |= B00100000;
        }
        else {
            PORTD &= B11011111;
        }
        //second green pin
        if (buffer[l].gc4) {
            PORTD |= B01000000;
        }
        else {
            PORTD &= B10111111;
        }
        //second blue pin
        if (buffer[l].bc4) {
            PORTD |= B10000000;
        }
        else {
            PORTD &= B01111111;
        }

        PORTB |= B00000001; //CLK HIGH
        PORTB &= B11111110; //CLK LOW

        //5th pixels
        //first red pin
        if (buffer[i].rc5) {
            PORTD |= B00000100;
        }
        else {
            PORTD &= B11111011;
        }
        //first green pin
        if (buffer[i].gc5) {
            PORTD |= B00001000;
        }
        else {
            PORTD &= B11110111;
        }
        //first blue pin
        if (buffer[i].bc5) {
            PORTD |= B00010000;
        }
        else {
            PORTD &= B11101111;
        }
        //second red pin
        if (buffer[l].rc5) {
            PORTD |= B00100000;
        }
        else {
            PORTD &= B11011111;
        }
        //second green pin
        if (buffer[l].gc5) {
            PORTD |= B01000000;
        }
        else {
            PORTD &= B10111111;
        }
        //second blue pin
        if (buffer[l].bc5) {
            PORTD |= B10000000;
        }
        else {
            PORTD &= B01111111;
        }

        PORTB |= B00000001; //CLK HIGH
        PORTB &= B11111110; //CLK LOW

        //6th pixels
        //first red pin
        if (buffer[i].rc6) {
            PORTD |= B00000100;
        }
        else {
            PORTD &= B11111011;
        }
        //first green pin
        if (buffer[i].gc6) {
            PORTD |= B00001000;
        }
        else {
            PORTD &= B11110111;
        }
        //first blue pin
        if (buffer[i].bc6) {
            PORTD |= B00010000;
        }
        else {
            PORTD &= B11101111;
        }
        //second red pin
        if (buffer[l].rc6) {
            PORTD |= B00100000;
        }
        else {
            PORTD &= B11011111;
        }
        //second green pin
        if (buffer[l].gc6) {
            PORTD |= B01000000;
        }
        else {
            PORTD &= B10111111;
        }
        //second blue pin
        if (buffer[l].bc6) {
            PORTD |= B10000000;
        }
        else {
            PORTD &= B01111111;
        }

        PORTB |= B00000001; //CLK HIGH
        PORTB &= B11111110; //CLK LOW

        //7th pixels
        //first red pin
        if (buffer[i].rc7) {
            PORTD |= B00000100;
        }
        else {
            PORTD &= B11111011;
        }
        //first green pin
        if (buffer[i].gc7) {
            PORTD |= B00001000;
        }
        else {
            PORTD &= B11110111;
        }
        //first blue pin
        if (buffer[i].bc7) {
            PORTD |= B00010000;
        }
        else {
            PORTD &= B11101111;
        }
        //second red pin
        if (buffer[l].rc7) {
            PORTD |= B00100000;
        }
        else {
            PORTD &= B11011111;
        }
        //second green pin
        if (buffer[l].gc7) {
            PORTD |= B01000000;
        }
        else {
            PORTD &= B10111111;
        }
        //second blue pin
        if (buffer[l].bc7) {
            PORTD |= B10000000;
        }
        else {
            PORTD &= B01111111;
        }

        PORTB |= B00000001; //CLK HIGH
        PORTB &= B11111110; //CLK LOW

        //8th pixels
        //first red pin
        if (buffer[i].rc8) {
            PORTD |= B00000100;
        }
        else {
            PORTD &= B11111011;
        }
        //first green pin
        if (buffer[i].gc8) {
            PORTD |= B00001000;
        }
        else {
            PORTD &= B11110111;
        }
        //first blue pin
        if (buffer[i].bc8) {
            PORTD |= B00010000;
        }
        else {
            PORTD &= B11101111;
        }
        //second red pin
        if (buffer[l].rc8) {
            PORTD |= B00100000;
        }
        else {
            PORTD &= B11011111;
        }
        //second green pin
        if (buffer[l].gc8) {
            PORTD |= B01000000;
        }
        else {
            PORTD &= B10111111;
        }
        //second blue pin
        if (buffer[l].bc8) {
            PORTD |= B10000000;
        }
        else {
            PORTD &= B01111111;
        }

        PORTB |= B00000001; //CLK HIGH
        PORTB &= B11111110; //CLK LOW

//(k < 16) * 
// + (k & B00010000) * B00010111

        if ((i + 1) % 8 == 0) {
        
        
            //--k;
            //delay(30);

            //PORTC &= (k & 0) * B11101000 ;//+ (k & 15) * B11101000; //RABCD LOW
            
            PORTC = (k + (k > 7) * 8) + (k > 15); //sets all rows 
        
            
            //PORTC = B00010111;

            PORTC |= B00001000; //LAT HIGH
            PORTC &= B11110111; //LAT LOW 

            PORTB |= B00000010; //OE HIGH  
            PORTB &= B11111101; //OE LOW
            
            //PORTC |= B00010111;
            //PORTC &= B11101000; //RA LOW
        }
    }

    #ifdef BIG //only use when big buffer is wanted
        //to sort out half colors
        for (uint8_t i = 0; i < (bsize + 1) / 2; i++) {
            //m = i % 3;
            //i += 127;
            l = i + (bsize + 1) / 2;
            k = i / 8;
            // selectLine(i / 8);
            //select current row (and adjust for row drift with the buffer)
            /*
            if (k > 0) {
                --k;
                if (k & B0000) {
                    PORTC &= B11101000; //RA LOW
                }else
                {
                    PORTC |= k + (k>7)*8; //sets all rows but 0 and 15
                }
                
            }
            else {//select line 15 cuz i dont know but works
                PORTC |= B00010111; //RA HIGH
            }
            /*
            --k;
            if (k & B0000) {
                PORTC &= B11101000; //RABCD LOW
            }
            if (k & B0001) {
                PORTC |= B00000001; //RA HIGH
            }
            if (k & B0010) {
                PORTC |= B00000010; //RB HIGH
            }
            if (k & B0100) {
                PORTC |= B00000100; //RC HIGH
            }
            if (k & B1000) {
                PORTC |= B00010000; //RD HIGH
            }
*/
            //first pixels
            //and checks wether pixel set in buffer, therefor deciding the voltage to give
            //Serial.println(buffer[i].gc1);
            //first red pin
            if (buffer[i].rc1 == 1) {
                //Serial.println("2nd part");
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc1 == 1) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc1 == 1) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc1 == 1) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc1 == 1) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc1 == 1) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            //sets clock high low very fast
            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //second pixels

            //first red pin
            if (buffer[i].rc2 == 1) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc2 == 1) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc2 == 1) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc2 == 1) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc2 == 1) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc2 == 1) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //3rd pixels
            //first red pin
            if (buffer[i].rc3 == 1) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc3 == 1) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc3 == 1) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc3 == 1) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc3 == 1) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc3 == 1) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //4th pixels
            //first red pin
            if (buffer[i].rc4 == 1) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc4 == 1) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc4 == 1) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc4 == 1) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc4 == 1) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc4 == 1) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //5th pixels
            //first red pin
            if (buffer[i].rc5 == 1) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc5 == 1) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc5 == 1) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc5 == 1) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc5 == 1) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc5 == 1) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //6th pixels
            //first red pin
            if (buffer[i].rc6 == 1) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc6 == 1) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc6 == 1) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc6 == 1) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc6 == 1) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc6 == 1) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //7th pixels
            //first red pin
            if (buffer[i].rc7 == 1) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc7 == 1) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc7 == 1) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc7 == 1) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc7 == 1) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc7 == 1) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //8th pixels
            //first red pin
            if (buffer[i].rc8 == 1) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc8 == 1) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc8 == 1) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc8 == 1) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc8 == 1) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc8 == 1) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            if ((i + 1) % 8 == 0) {

                PORTC = (k + (k > 7) * 8) + (k > 15); //sets all rows 

                PORTC |= B00001000; //LAT HIGH
                PORTC &= B11110111; //LAT LOW 
                
                PORTB |= B00000010; //OE HIGH  
                PORTB &= B11111101; //OE LOW
                
                //PORTC |= B00010111;
                //PORTC &= B11101000; //RA LOW
            }
        }
        //to sort out third colors, which doesnt work sadly
        /*
        for (uint8_t i = 0; i < (bsize + 1) / 2; i++) {
            //m = i % 3;
            //i += 127;
            l = i + (bsize + 1) / 2;
            k = i / 8;

            //select current row (and adjust for row drift with the buffer)
            if (k > 0) {
                --k;
                if (k & B0000) {
                    PORTC &= B11111110; //RA LOW
                    PORTC &= B11111101; //RB LOW
                    PORTC &= B11111011; //RC LOW
                    PORTC &= B11101111; //RD LOW
                }
                if (k & B0001) {
                    PORTC |= B00000001; //RA HIGH
                }
                if (k & B0010) {
                    PORTC |= B00000010; //RB HIGH
                }
                if (k & B0100) {
                    PORTC |= B00000100; //RC HIGH
                }
                if (k & B1000) {
                    PORTC |= B00010000; //RD HIGH
                }
            }
            else {//select line 15 cuz i dont know but works
                PORTC |= B00000001; //RA HIGH
                PORTC |= B00000010; //RB HIGH
                PORTC |= B00000100; //RC HIGH
                PORTC |= B00010000; //RD HIGH
            }

            //first pixels
            //and checks wether pixel set in buffer, therefor deciding the voltage to give
            //Serial.println(buffer[i].gc1);
            //first red pin
            if (buffer[i].rc1 - 1 < 2) {
                //Serial.println("3rd part");
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc1 - 1 < 2) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc1 - 1 < 2) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc1 - 1 < 2) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc1 - 1 < 2) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc1 - 1 < 2) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            //sets clock high low very fast
            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //second pixels

            //first red pin
            if (buffer[i].rc2 - 1 < 2) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc2 - 1 < 2) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc2 - 1 < 2) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc2 - 1 < 2) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc2 - 1 < 2) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc2 - 1 < 2) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //3rd pixels
            //first red pin
            if (buffer[i].rc3 - 1 < 2) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc3 - 1 < 2) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc3 - 1 < 2) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc3 - 1 < 2) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc3 - 1 < 2) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc3 - 1 < 2) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //4th pixels
            //first red pin
            if (buffer[i].rc4 - 1 < 2) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc4 - 1 < 2) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc4 - 1 < 2) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc4 - 1 < 2) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc4 - 1 < 2) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc4 - 1 < 2) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //5th pixels
            //first red pin
            if (buffer[i].rc5 - 1 < 2) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc5 - 1 < 2) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc5 - 1 < 2) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc5 - 1 < 2) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc5 - 1 < 2) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc5 - 1 < 2) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //6th pixels
            //first red pin
            if (buffer[i].rc6 - 1 < 2) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc6 - 1 < 2) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc6 - 1 < 2) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc6 - 1 < 2) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc6 - 1 < 2) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc6 - 1 < 2) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //7th pixels
            //first red pin
            if (buffer[i].rc7 - 1 < 2) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc7 - 1 < 2) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc7 - 1 < 2) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc7 - 1 < 2) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc7 - 1 < 2) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc7 - 1 < 2) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            //8th pixels
            //first red pin
            if (buffer[i].rc8 - 1 < 2) {
                PORTD |= B00000100;
            }
            else {
                PORTD &= B11111011;
            }
            //first green pin
            if (buffer[i].gc8 - 1 < 2) {
                PORTD |= B00001000;
            }
            else {
                PORTD &= B11110111;
            }
            //first blue pin
            if (buffer[i].bc8 - 1 < 2) {
                PORTD |= B00010000;
            }
            else {
                PORTD &= B11101111;
            }
            //second red pin
            if (buffer[l].rc8 - 1 < 2) {
                PORTD |= B00100000;
            }
            else {
                PORTD &= B11011111;
            }
            //second green pin
            if (buffer[l].gc8 - 1 < 2) {
                PORTD |= B01000000;
            }
            else {
                PORTD &= B10111111;
            }
            //second blue pin
            if (buffer[l].bc8 - 1 < 2) {
                PORTD |= B10000000;
            }
            else {
                PORTD &= B01111111;
            }

            PORTB |= B00000001; //CLK HIGH
            PORTB &= B11111110; //CLK LOW

            if ((i + 1) % 8 == 0) {
                PORTC |= B00001000; //LAT HIGH
                PORTC &= B11110111; //LAT LOW
                PORTB |= B00000010; //OE HIGH

                PORTC &= B11111110; //RA LOW
                PORTC &= B11111101; //RB LOW
                PORTC &= B11111011; //RC LOW
                PORTC &= B11101111; //RD LOW

                PORTB &= B11111101; //OE LOW
            }
        }*/
    #endif //BIG
}

void Panel::clearBuffer(uint16_t c) {
    //get colors
    cnvColor(c, &r, &g, &b);

        //fills the buffer
    for (uint16_t x = 0; x < bsize + 1; x++) {
        buffer[x].rc1 = r;
        buffer[x].gc1 = g;
        buffer[x].bc1 = b;
        buffer[x].rc2 = r;
        buffer[x].gc2 = g;
        buffer[x].bc2 = b;
        buffer[x].rc3 = r;
        buffer[x].gc3 = g;
        buffer[x].bc3 = b;
        buffer[x].rc4 = r;
        buffer[x].gc4 = g;
        buffer[x].bc4 = b;
        buffer[x].rc5 = r;
        buffer[x].gc5 = g;
        buffer[x].bc5 = b;
        buffer[x].rc6 = r;
        buffer[x].gc6 = g;
        buffer[x].bc6 = b;
        buffer[x].rc7 = r;
        buffer[x].gc7 = g;
        buffer[x].bc7 = b;
        buffer[x].rc8 = r;
        buffer[x].gc8 = g;
        buffer[x].bc8 = b;
    }
}

void Panel::test(){
    fillScreenColor(OCEANBLUE);
    //fillScreenColor(2047);
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

void Panel::drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t c, bool fill) { //draws a rect filled ro not filled with the given color at coords (landscape, origin in upper left corner)
    //get colors
    cnvColor(c, &r, &g, &b);


        
          //  Serial.println("drawing rect");


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

void Panel::drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t c) { //draws a line with color at coords given, must be left to right
    //get colors
    
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

void Panel::drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t c, bool fill) { //draws a circle at the coords with radius and color
    //get colors
    
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

void Panel::drawChar(uint8_t x, uint8_t y, char ch, uint16_t c) {//deprecated, but probably faster
    //color for the char
    
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

void Panel::drawBigChar(uint8_t x, uint8_t y, char ch, uint16_t c, uint8_t size_modifier) {//new with scaling, but may be slower
    //color for the char
    cnvColor(c, &r, &g, &b);



          //  Serial.println("drawing char");



   // x = (x>64)*(x-64)+(x<64)*(x);

    //iterate through the character line by line
    uint8_t temp = 0;
    char out;
    for (uint8_t i = 0; i < 5*size_modifier; i++){
        out = getFontLine(ch, i/size_modifier);
        Serial.println(out);
        //iterate through the character bit by bit
        for (uint8_t j = 4*size_modifier; j > 0; --j) {
            temp = ((y + i) * (cols / 8) + (x + 4*size_modifier - j) / 8);
                //shift by j and check for bit set
            if (out & (1 << j/size_modifier)) {
                //set pixel at i and j
                setBuffer(r, g, b, temp, x + 4*size_modifier - j);
            }
        }
    }
}
