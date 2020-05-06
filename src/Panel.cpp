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

uint8_t r = 0;
uint8_t g = 0;
uint8_t b = 0;

uint8_t rows;
uint8_t cols;

//register for string pin status
bool r1;
bool g1;
bool b1;
bool r2;
bool g2;
bool b2;

//color values
int rc1;
int gc1;
int bc1;
int rc2;
int gc2;
int bc2;

struct LED{
    unsigned int rc1 : 2;
    unsigned int gc1 : 2;
    unsigned int bc1 : 2;  
    unsigned int rc2 : 2;
    unsigned int :0;
    unsigned int gc2 : 2;
    unsigned int bc2 : 2; 
    unsigned int rc3 : 2;
    unsigned int gc3 : 2; 
    unsigned int :0;
    unsigned int bc3 : 2;
    unsigned int rc4 : 2; 
    unsigned int gc4 : 2;
    unsigned int bc4 : 2; 
};

enum StringValue { 
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

Panel::Panel(int height,int width){
    rows = height;
    cols = width;
}

void Panel::init(bool useBuffer){
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

    if(useBuffer){
        createBuffer();
    }
}

void Panel::createBuffer(){
    LED bufferOne[rows*cols/4];
    
    for(int x = 0; x < rows * cols / 4; x++){
        bufferOne[x].rc1 = 1;
        bufferOne[x].gc1 = 0;
        bufferOne[x].bc1 = 0;
        bufferOne[x].rc2 = 1;
        bufferOne[x].gc2 = 0;
        bufferOne[x].bc2 = 0;
        bufferOne[x].rc3 = 1;
        bufferOne[x].gc3 = 0;
        bufferOne[x].bc3 = 0;
        bufferOne[x].rc4 = 1;
        bufferOne[x].gc4 = 0;
        bufferOne[x].bc4 = 0;
    }
}

void Panel::emptyLine() {
    //output off
    digitalWrite(OE, LOW);
    //address zero
    digitalWrite(RA, LOW);
    digitalWrite(RB, LOW);
    digitalWrite(RC, LOW);
    digitalWrite(RD, LOW);
}

//this function cleans up and latches the data, so diplays it
void Panel::latch() {
    //latch output
    digitalWrite(LAT, HIGH);
    //delatch
    digitalWrite(LAT, LOW);
    //enable output
    digitalWrite(OE, HIGH);
    emptyLine();
}

void Panel::selectLine(uint8_t c) {
    switch (c) {
        case B0000:
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

void Panel::fillScreenShift(int s) {
    for (uint8_t r = 0; r < rows / 2; r++) {
        //switch through all rows
        selectLine(r);

        for (int c = 0; c<cols; c++) {
            //c = coloumn r = row s = shift for moving fist number is offset for color, second for overall
            rc1 =  ((c + 0 + r + s*2 + 0) % 16) == 0;
            bc1 =  ((c + 1 + r + s*2 + 0) % 16) == 0;
            gc1 =  ((c + 2 + r + s*3 + 0) % 16) == 0;
            rc1 ^= ((c + 3 - r + s*1 + 0) % 16) == 0;
            gc1 ^= ((c + 4 - r + s*2 + 0) % 16) == 0;
            bc1 ^= ((c + 5 - r + s*3 + 0) % 16) == 0;
            sendTwoPixels(rc1,gc1,bc1,rc1,gc1,bc1);
        }       
        latch(); //general latch to get rid of ghosting, or so i thought
    }
}

void Panel::fillScreenColor(int c){
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
                    clock(0);
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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
            for (int i = 0; i < 32; i++){//for loop to do pwm
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

//checks with bool wether pin has been set or not (to get rid of unnecessary changes)
void Panel::sendTwoPixels(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl){ //first upper half values, the lower half
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
    clock(0);
}

void Panel::sendWholeRow(uint8_t ru, uint8_t gu, uint8_t bu, uint8_t rl, uint8_t gl, uint8_t bl) { //first upper half values, the lower half
    
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

    for (int i = 0; i < cols; i++) {
        clock(0);
    }
    latch();
}

//clock function for data entry
void Panel::clock(uint8_t d) {
    digitalWrite(CLK, HIGH);
    if (d > 0) {
        delay(d);
    }
    digitalWrite(CLK, LOW);
}

//puts the  buffer contents onto the display
void Panel::displayBuffer(uint8_t bnum) {
    if(bnum == 0){
        for(long x = 0; x < rows * cols / 4; x++){
        if(x % (rows) == 0){
            latch();
            int temprow = x / (cols / 4) / 2;
            selectLine(temprow);
        }
        //                r1             g1                  b1               r2                                        g2                                        b2
        sendTwoPixels(bufferOne[x].rc1, bufferOne[x].gc1, bufferOne[x].bc1, bufferOne[x + (rows * cols / 4) / 2].rc1, bufferOne[x + (rows * cols / 4) / 2].gc1, bufferOne[x + (rows * cols / 4) / 2].bc1);
        sendTwoPixels(bufferOne[x].rc2, bufferOne[x].gc2, bufferOne[x].bc2, bufferOne[x + (rows * cols / 4) / 2].rc2, bufferOne[x + (rows * cols / 4) / 2].gc2, bufferOne[x + (rows * cols / 4) / 2].bc2);
        sendTwoPixels(bufferOne[x].rc3, bufferOne[x].gc3, bufferOne[x].bc3, bufferOne[x + (rows * cols / 4) / 2].rc3, bufferOne[x + (rows * cols / 4) / 2].gc3, bufferOne[x + (rows * cols / 4) / 2].bc3);
        sendTwoPixels(bufferOne[x].rc4, bufferOne[x].gc4, bufferOne[x].bc4, bufferOne[x + (rows * cols / 4) / 2].rc4, bufferOne[x + (rows * cols / 4) / 2].gc4, bufferOne[x + (rows * cols / 4) / 2].bc4);

        }
    }
}

void Panel::test(){
    //fills entire screen somehow
    fillScreenColor(FLESH);
}