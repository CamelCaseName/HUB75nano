#ifndef HUB75NANO_IOT_H
#define HUB75NANO_IOT_H

#include <Arduino.h>

// actual pin numbers like in the arduino digitalwrite, can be changed here or in your project
#ifndef RA
#define RA 14 // row selector a
#endif
#ifndef RB
#define RB 15 // row selector b
#endif
#ifndef RC
#define RC 16 // row selector c
#endif
#ifndef RD
#define RD 17 // row selector d
#endif
// currently unused
#ifndef RE
#define RE 18 // row selector e
#endif
#ifndef RF
#define RF 2 // red first byte
#endif
#ifndef GF
#define GF 3 // green first byte
#endif
#ifndef BF
#define BF 4 // blue first byte
#endif
#ifndef RS
#define RS 5 // red second byte
#endif
#ifndef GS
#define GS 6 // green second byte
#endif
#ifndef BS
#define BS 7 // blue second byte
#endif
#ifndef CLK
#define CLK 9 // clock signal
#endif
#ifndef LAT
#define LAT 10 // data latch
#endif
#ifndef OE
#define OE 11 // output enable
#endif

// ref https://roboticsbackend.com/arduino-fast-digitalwrite/#Using_direct_port_manipulation_instead_of_digitalWrite
// helper definitions for setting/clearing
#define high_pin(port, number) port |= 1 << number
#define clear_pin(port, number) port &= ~(1 << number)

#endif // HUB75NANO_IOT_H