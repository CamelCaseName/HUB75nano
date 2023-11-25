#ifndef HUB75NANO_NANO_H
#define HUB75NANO_NANO_H

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

#define set_pin_output(pin) pinMode(pin, OUTPUT)

#include "nano_pin_helpers.h"

// pin access defines, rest
#define HIGH_CLK high_pin(PORT_CLK, PORT_PIN_CLK)
#define CLEAR_CLK clear_pin(PORT_CLK, PORT_PIN_CLK)
#define HIGH_LAT high_pin(PORT_LAT, PORT_PIN_LAT)
#define CLEAR_LAT clear_pin(PORT_LAT, PORT_PIN_LAT)
#define HIGH_OE high_pin(PORT_OE, PORT_PIN_OE)
#define CLEAR_OE clear_pin(PORT_OE, PORT_PIN_OE)
#define Clock \
    HIGH_CLK; \
    CLEAR_CLK
#define LATCH \
    HIGH_LAT; \
    CLEAR_LAT

#define OVERFLOW (SREG & _BV(SREG_C))

#endif // HUB75NANO_NANO_H