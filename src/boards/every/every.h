#ifndef HUB75NANO_EVERY_H
#define HUB75NANO_EVERY_H

#include <Arduino.h>
#include "every_pin_helpers.h"

// actual pin numbers like in the arduino digitalwrite, can be changed here or in your project
#ifndef RA
#define RA 11 // row selector a
#endif
#ifndef RB
#define RB 12 // row selector b
#endif
#ifndef RC
#define RC 13 // row selector c
#endif
#ifndef RD
#define RD 8 // row selector d
#endif
// currently unused
#ifndef RE
#define RE 2 // row selector e
#endif
#ifndef RF
#define RF A3 // red first byte
#endif
#ifndef GF
#define GF A2 // green first byte
#endif
#ifndef BF
#define BF A1 // blue first byte
#endif
#ifndef RS
#define RS A0 // red second byte
#endif
#ifndef GS
#define GS A6 // green second byte
#endif
#ifndef BS
#define BS A7 // blue second byte
#endif
#ifndef CLK
#define CLK 9 // clock signal
#endif
#ifndef LAT
#define LAT 10 // data latch
#endif
#ifndef OE
#define OE 5 // output enable
#endif

// helper definitions for setting/clearing
#define high_pin(pin) ((PORT_t *)&PORTA + port_from_pin(arduino_pin_to_avr_pin(pin)))->OUTSET = 1 << bit_from_pin(arduino_pin_to_avr_pin(pin))
#define clear_pin(pin) ((PORT_t *)&PORTA + port_from_pin(arduino_pin_to_avr_pin(pin)))->OUTCLR = 1 << bit_from_pin(arduino_pin_to_avr_pin(pin))

// Set pin to output mode
#define set_pin_output(pin) \
    ((PORT_t *)&PORTA + port_from_pin(arduino_pin_to_avr_pin(pin)))->DIRSET = 1 << bit_from_pin(arduino_pin_to_avr_pin(pin))

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

#define OVERFLOW (SREG & _BV(SREG_C))

#endif // HUB75NANO_EVERY_H