#ifndef HUB75NANO_BOARD_H
#define HUB75NANO_BOARD_H

#include <Arduino.h>

// check we are on uno or nano, get pinout and how we access them
#ifdef ARDUINO_AVR_NANO // nano avr 328p
#include "boards/nano/nano.h"
#else
#ifdef ARDUINO_AVR_UNO
#include "boards/uno/uno.h"
#else
#ifdef ARDUINO_ARCH_SAMD // nano 33 iot
#include "boards/iot/iot.h"
#else
#error "This library only supports the Arduino nano and Uno, so the atm368p with 2kb sram, 1kb eeprom and 32kb flash. For other chips/boards, please see the internet or try to adapt this library here, but no guarantees"
#endif
#endif
#endif

#ifndef PANEL_X
#error "Panel size needs to be defined"
#endif

#ifndef PANEL_Y
#error "Panel size needs to be defined"
#endif

// test that everything got defined correctly
#ifndef HIGH_CLK
#error "this needs to be defined for the selected board first"
#endif
#ifndef CLEAR_CLK
#error "this needs to be defined for the selected board first"
#endif
#ifndef HIGH_LAT
#error "this needs to be defined for the selected board first"
#endif
#ifndef CLEAR_LAT
#error "this needs to be defined for the selected board first"
#endif
#ifndef HIGH_OE
#error "this needs to be defined for the selected board first"
#endif
#ifndef CLEAR_OE
#error "this needs to be defined for the selected board first"
#endif
#ifndef Clock
#error "this needs to be defined for the selected board first"
#endif
#ifndef LATCH
#error "this needs to be defined for the selected board first"
#endif

#ifndef OVERFLOW
#error "this needs to be defined for the selected board first"
#endif

#ifndef RA
#error "this needs to be defined for the selected board first"
#endif
#ifndef RB
#error "this needs to be defined for the selected board first"
#endif
#ifndef RC
#error "this needs to be defined for the selected board first"
#endif
#ifndef RD
#error "this needs to be defined for the selected board first"
#endif
// currently unused
#ifndef RE
#error "this needs to be defined for the selected board first"
#endif
#ifndef RF
#error "this needs to be defined for the selected board first"
#endif
#ifndef GF
#error "this needs to be defined for the selected board first"
#endif
#ifndef BF
#error "this needs to be defined for the selected board first"
#endif
#ifndef RS
#error "this needs to be defined for the selected board first"
#endif
#ifndef GS
#error "this needs to be defined for the selected board first"
#endif
#ifndef BS
#error "this needs to be defined for the selected board first"
#endif
#ifndef CLK
#error "this needs to be defined for the selected board first"
#endif
#ifndef LAT
#error "this needs to be defined for the selected board first"
#endif
#ifndef OE
#error "this needs to be defined for the selected board first"
#endif

#endif // HUB75NANO_BOARD_H