#ifndef HUB75NANO_BOARD_METHODS_h
#define HUB75NANO_BOARD_METHODS_H

#include <inttypes.h>

// forward declarations
// #ifdef PANEL_MAX_SPEED
// __attribute__((always_inline))
// #endif
// inline void
// _set_color(uint8_t value);

// #ifdef PANEL_MAX_SPEED
// __attribute__((always_inline))
// #endif
// inline void
// _stepRow();

// include the relevant file to get the thingies
#ifdef ARDUINO_AVR_NANO // nano with avr 328p
#include "boards/nano/nano_methods.h"
#else
#ifdef ARDUINO_AVR_UNO
#include "boards/uno/uno_methods.h"
#else
#ifdef ARDUINO_ARCH_SAMD // nano 33 iot
#include "boards/iot/iot_methods.h"
#else
#error "This library only supports the Arduino nano and Uno, so the atm368p with 2kb sram, 1kb eeprom and 32kb flash. For other chips/boards, please see the internet or try to adapt this library here, but no guarantees"
#endif
#endif
#endif

#endif // HUB75NANO_BOARD_METHODS