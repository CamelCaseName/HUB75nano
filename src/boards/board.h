#ifndef HUB75NANO_BOARD_H
#define HUB75NANO_BOARD_H

#include <Arduino.h>

// check we are on uno or nano, get pinout and how we access them
// mini pro is the exact same as nano
#ifdef ARDUINO_AVR_NANO || defined(ARDUINO_AVR_PRO) // nano avr 328p
#include "boards/nano/nano.h"
#if PANEL_X * PANEL_Y > 4096
#pragma GCC warning "this panel size may be too large for the mighty nano ram, please choose a smaller size and let the library simulate bigger pixels"
#endif
#else
#ifdef ARDUINO_AVR_UNO &&defined(__AVR_ATmega328P__)
#include "boards/uno/uno.h"
#else
#ifdef ARDUINO_SAMD_NANO_33_IOT
#include "boards/iot/iot.h"
#else
#ifdef ARDUINO_ARDUINO_NANO33BLE
#include "boards/ble/ble.h"
#else
#ifdef ARDUINO_AVR_NANO_EVERY
#include "boards/every/every.h"
#else
#ifdef ARDUINO_NANO_RP2040_CONNECT
#include "boards/rp2040/rp2040.h"
#else
#ifdef ARDUINO_AVR_MEGA2560
#include "boards/mega/mega.h"
#else
#ifdef ARDUINO_MINIMA
#include "boards/uno_r4/uno_r4.h"
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

#ifndef PANEL_X
#error "Panel size needs to be defined"
#endif

#ifndef PANEL_Y
#error "Panel size needs to be defined"
#endif

// test that everything got set correctly

#ifndef RA
#error "this needs to be set for the selected board first"
#endif

#ifndef RB
#ifndef PANEL_3_PIN_ROWS
#error "this needs to be set for the selected board first"
#endif
#endif

#if PANEL_Y > 8
#ifndef RC
#error "this needs to be set for the selected board first"
#endif
#endif

#if PANEL_Y > 16
#ifndef RD
#ifndef PANEL_3_PIN_ROWS
#error "this needs to be set for the selected board first"
#endif
#endif
#endif

#if PANEL_Y > 32
#ifndef RE
#ifndef PANEL_3_PIN_ROWS
#error "this needs to be set for the selected board first"
#endif
#endif
#endif

#ifndef RF
#error "this needs to be set for the selected board first"
#endif

#ifndef GF
#error "this needs to be set for the selected board first"
#endif

#ifndef BF
#error "this needs to be set for the selected board first"
#endif

#ifndef RS
#error "this needs to be set for the selected board first"
#endif

#ifndef GS
#error "this needs to be set for the selected board first"
#endif

#ifndef BS
#error "this needs to be set for the selected board first"
#endif

#ifndef CLK
#error "this needs to be set for the selected board first"
#endif

#ifndef LAT
#error "this needs to be set for the selected board first"
#endif

#ifndef OE
#error "this needs to be set for the selected board first"
#endif

#endif // HUB75NANO_BOARD_H