#ifndef HUB75NANO_NANO_H
#define HUB75NANO_NANO_H

#include <Arduino.h>

// actual pin numbers like in the arduino digitalwrite, can be changed here or in your project
#ifndef RA
#define RA 2 // row selector a
#endif
#ifndef RB
#define RB 3 // row selector b
#endif
#ifndef RC
#define RC 4 // row selector c
#endif
#ifndef RD
#define RD 5 // row selector d
#endif
// currently unused
#ifndef RE
#define RE 6 // row selector e
#endif
#ifndef RF
#define RF 14 // red first byte
#endif
#ifndef GF
#define GF 15 // green first byte
#endif
#ifndef BF
#define BF 16 // blue first byte
#endif
#ifndef RS
#define RS 17 // red second byte
#endif
#ifndef GS
#define GS 18 // green second byte
#endif
#ifndef BS
#define BS 19 // blue second byte
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

#if (OE < 8 && CLK < 8 && LAT < 8) || (OE < 14 && CLK < 14 && LAT < 14) || (OE > 13 && CLK > 13 && LAT > 13)
#define PANEL_GPIO_NON_INTRUSIVE
#endif

#ifdef PANEL_GPIO_NON_INTRUSIVE
#define DCLK_GCLK                           \
    PORTB |= 5 << (uint8_t)1;               \
    /*turn on clk and oe at the same time*/ \
    PORTB &= (uint8_t) ~(5 << (uint8_t)1);  \
    /*turn off clk and oe at the same time*/
#define LATCH_GCLK DCLK_GCLK
#else
// todo find a way to decouple the pin and leave it floating
#define DCLK_GCLK                                                            \
    PORT_CLK = (1 << (uint8_t)PORT_PIN_CLK) + (1 << (uint8_t)PORT_PIN_OE);   \
    /*turn on clk and oe at the same time, with no regards to other values*/ \
    PORT_CLK = 0;                                                            \
    /*turn off clk and oe at the same time, with no regards to other values*/
#define LATCH_GCLK                                                                                                                     \
    PORT_CLK = (1 << (uint8_t)PORT_PIN_CLK) + (1 << (uint8_t)PORT_PIN_OE) + (1 << (uint8_t)PORT_PIN_LAT); /*pin 1, 2 and 3 of byte b*/ \
    /*turn on clk and oe at the same time, with no regards to other values*/                                                           \
    PORT_CLK = (1 << (uint8_t)PORT_PIN_LAT); /*pin 2 of byte b*/                                                                       \
    /*turn off clk and oe at the same time, with no regards to other values*/
#endif

#define OVERFLOW (SREG & _BV(SREG_C))

#endif // HUB75NANO_NANO_H