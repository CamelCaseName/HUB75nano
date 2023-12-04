#ifndef HUB75NANO_IOT_H
#define HUB75NANO_IOT_H

#include <Arduino.h>
#include "iot_pin_helpers.h"

// this one needs the PA/PBxx type pin numbers found in the arduino pinout datasheet
// todo add a way to decode the normal arduino numbers to this at compile time
#ifndef RA
// this was planned as PA03, cannot use arduino digital pin numbering as it is the AREF pin and that has no number so we define our own
// using PA03/AREF is possible but for our application with high frequencies we would need to desolder the two filter capacitors on this line
#define RA A0 // row selector a
#endif
#ifndef RB
#define RB 6 // row selector b
#endif
#ifndef RC
#define RC 5 // row selector c
#endif
#ifndef RD
#define RD 7 // row selector d
#endif
// currently unused
#ifndef RE
#define RE 4 // row selector e
#endif
#ifndef RF
#define RF 11 // red first byte
#endif
#ifndef GF
#define GF 13 // green first byte
#endif
#ifndef BF
#define BF 8 // blue first byte
#endif
#ifndef RS
#define RS 12 // red second byte
#endif
#ifndef GS
#define GS 9 // green second byte
#endif
#ifndef BS
#define BS 10 // blue second byte
#endif
#ifndef CLK
#define CLK A6 // clock signal
#endif
#ifndef LAT
#define LAT A2 // data latch
#endif
#ifndef OE
#define OE A3 // output enable
#endif

/*
as the pins are locked by the shield i can make a tabel here with the direct translation between the pins

hub     iot     scope
RA      PA02    6
RB      PA04    7
RC      PA05    8
RD      PA06    9
RE      PA07    /

RF      PA16    0
GF      PA17    1
BF      PA18    2

RS      PA19    3
GS      PA20    4
BS      PA21    5

CLK     PA09    10
LAT     PA11    11
OE      PA10    12

*/

// helper definitions for setting/clearing
#define high_pin(pin) PORT_IOBUS->Group[port_from_pin(arduino_pin_to_avr_pin(pin))].OUTSET.reg = 1 << bit_from_pin(arduino_pin_to_avr_pin(pin))
#define clear_pin(pin) PORT_IOBUS->Group[port_from_pin(arduino_pin_to_avr_pin(pin))].OUTCLR.reg = 1 << bit_from_pin(arduino_pin_to_avr_pin(pin))

// enable input, to support reading back values, with pullups disabled
// Set pin to output mode
#define set_pin_output(pin)                                                                                                                      \
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(pin))].PINCFG[bit_from_pin(arduino_pin_to_avr_pin(pin))].reg = (uint8_t)(PORT_PINCFG_INEN); \
    PORT->Group[port_from_pin(arduino_pin_to_avr_pin(pin))].DIRSET.reg = (uint32_t)(1 << bit_from_pin(arduino_pin_to_avr_pin(pin)));

#define HIGH_CLK high_pin(CLK)
#define CLEAR_CLK clear_pin(CLK)
#define HIGH_LAT high_pin(LAT)
#define CLEAR_LAT clear_pin(LAT)
#define HIGH_OE high_pin(OE)
#define CLEAR_OE clear_pin(OE)
#define Clock             \
    HIGH_CLK;             \
    delayMicroseconds(2); \
    CLEAR_CLK;            \
    delayMicroseconds(2)
#define LATCH             \
    HIGH_LAT;             \
    delayMicroseconds(2); \
    CLEAR_LAT;            \
    delayMicroseconds(2)

// todo, no idea how
#define OVERFLOW 0

#endif // HUB75NANO_IOT_H