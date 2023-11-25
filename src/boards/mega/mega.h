#ifndef HUB75NANO_MEGA_H
#define HUB75NANO_MEGA_H

#include <Arduino.h>
#include "mega_pin_helpers.h"

// actual pin numbers like in the arduino digitalwrite, can be changed here or in your project
#ifndef RA
#define RA 22 // row selector a
#endif
#ifndef RB
#define RB 23 // row selector b
#endif
#ifndef RC
#define RC 24 // row selector c
#endif
#ifndef RD
#define RD 25 // row selector d
#endif
// currently unused
#ifndef RE
#define RE 26 // row selector e
#endif

#ifndef RF
#define RF 47 // red first byte
#endif
#ifndef GF
#define GF 46 // green first byte
#endif
#ifndef BF
#define BF 45 // blue first byte
#endif
#ifndef RS
#define RS 44 // red second byte
#endif
#ifndef GS
#define GS 43 // green second byte
#endif
#ifndef BS
#define BS 42 // blue second byte
#endif
#ifndef CLK
#define CLK 37 // clock signal
#endif
#ifndef LAT
#define LAT 36 // data latch
#endif
#ifndef OE
#define OE 35 // output enable
#endif

// helper definitions for setting/clearing
#define high_pin(pin) *port_from_pin(arduino_pin_to_avr_pin(pin)) |= (uint8_t)(1 << bit_from_pin(arduino_pin_to_avr_pin(pin)))
#define clear_pin(pin) *port_from_pin(arduino_pin_to_avr_pin(pin)) &= (uint8_t)(~(1 << bit_from_pin(arduino_pin_to_avr_pin(pin))))

// Set pin to output mode
#define set_pin_output(pin) pinMode(pin, OUTPUT)

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

#endif // HUB75NANO_MEGA_H