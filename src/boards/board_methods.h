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
#error "This library currently only supports the Arduino Nano or Uno with Atmega328(p), Nano Every, Nano 33 IOT, Nano 33 BLE, Nano RP2040"
#endif
#endif
#endif
#endif
#endif
#endif
#endif

#endif // HUB75NANO_BOARD_METHODS