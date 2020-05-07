#include <Panel.h>

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

Panel panel(32,64);

void setup() {
    //use buffer
    panel.init(true);  
    //delay(3000);
}

void loop() {
    //panel.fillScreenColor(panel.PURPLE);
    panel.displayBuffer();
}
