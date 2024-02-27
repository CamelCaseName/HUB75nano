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
#ifdef ARDUINO_SAMD_NANO_33_IOT // nano 33 iot
#include "boards/iot/iot_methods.h"
#else
#ifdef ARDUINO_ARDUINO_NANO33BLE
#include "boards/ble/ble_methods.h"
#else
#ifdef ARDUINO_AVR_NANO_EVERY
#include "boards/every/every_methods.h"
#else
#ifdef ARDUINO_NANO_RP2040_CONNECT
#include "boards/rp2040/rp2040_methods.h"
#else
#ifdef ARDUINO_AVR_MEGA2560
#include "boards/mega/mega_methods.h"
#else
#ifdef ARDUINO_MINIMA
#include "boards/uno_r4/uno_r4_methods.h"
#else
#error "This library currently only supports the Arduino Nano or Uno with Atmega328(p), Nano Every, Nano 33 IOT, Nano 33 BLE, Nano RP2040"
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif

#ifndef HIGH_CLK
#error "this needs to be set for the selected board first"
#endif
#ifndef CLEAR_CLK
#error "this needs to be set for the selected board first"
#endif
#ifndef HIGH_LAT
#error "this needs to be set for the selected board first"
#endif
#ifndef CLEAR_LAT
#error "this needs to be set for the selected board first"
#endif
#ifndef HIGH_OE
#error "this needs to be set for the selected board first"
#endif
#ifndef CLEAR_OE
#error "this needs to be set for the selected board first"
#endif
#ifndef Clock
#error "this needs to be set for the selected board first"
#endif
#ifndef LATCH
#error "this needs to be set for the selected board first"
#endif
// todo is this the correct order to avoid half definitions?
#ifndef DCLK_GCLK
#define DCLK_GCLK \
    HIGH_OE;      \
    HIGH_CLK;     \
    CLEAR_CLK;    \
    CLEAR_OE
#pragma GCC warning "No DCLK_GCLK defined for this board, using slower substitute"
#endif
#ifndef LATCH_GCLK
#define LATCH_GCLK DCLK_GCLK
#pragma GCC warning "No LATCH_GCLK defined for this board, using slower substitute"
#endif

#ifndef OVERFLOW
#error "this needs to be set for the selected board first"
#endif

#ifndef set_pin_output
#error "this needs to be set for the selected board first"
#endif

#ifndef high_pin
#error "this needs to be set for the selected board first"
#endif

#ifndef clear_pin
#error "this needs to be set for the selected board first"
#endif

#endif // HUB75NANO_BOARD_METHODS