#ifndef HUB75NANO_IOT_H
#define HUB75NANO_IOT_H

#include <Arduino.h>
#include "iot_pin_helpers.h"

// this one needs the PA/PBxx type pin numbers found in the arduino pinout datasheet
#ifndef RA
#define RA PA03 // row selector a
#endif
#ifndef RB
#define RB PA04 // row selector b
#endif
#ifndef RC
#define RC PA05 // row selector c
#endif
#ifndef RD
#define RD PA06 // row selector d
#endif
// currently unused
#ifndef RE
#define RE PA07 // row selector e
#endif
#ifndef RF
#define RF PA16 // red first byte
#endif
#ifndef GF
#define GF PA17 // green first byte
#endif
#ifndef BF
#define BF PA18 // blue first byte
#endif
#ifndef RS
#define RS PA19 // red second byte
#endif
#ifndef GS
#define GS PA20 // green second byte
#endif
#ifndef BS
#define BS PA21 // blue second byte
#endif
#ifndef CLK
#define CLK PA09 // clock signal
#endif
#ifndef LAT
#define LAT PA11 // data latch
#endif
#ifndef OE
#define OE PA10 // output enable
#endif

// helper definitions for setting/clearing
// todo!
#define high_pin(pin) PORT->Group[port_from_pin(pin)].OUTSET.reg = 1 << bit_from_pin(pin)
#define clear_pin(pin) PORT->Group[port_from_pin(pin)].OUTCLR.reg = 1 << bit_from_pin(pin)

#define HIGH_CLK high_pin(CLK)
#define CLEAR_CLK clear_pin(CLK)
#define HIGH_LAT high_pin(LAT)
#define CLEAR_LAT clear_pin(LAT)
#define HIGH_OE high_pin(OE)
#define CLEAR_OE clear_pin(OE)
#define Clock \
    HIGH_CLK; \
    CLEAR_CLK
#define LATCH \
    HIGH_LAT; \
    CLEAR_LAT

// todo, no idea how
#define OVERFLOW 0

#endif // HUB75NANO_IOT_H