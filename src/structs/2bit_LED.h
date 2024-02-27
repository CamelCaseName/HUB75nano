#ifndef HUB75NANO_2BIT_LED_H
#define HUB75NANO_2BIT_LED_H

#include <inttypes.h>
#include "../Settings.h"

#pragma pack(push, 1)
typedef struct LED_long
{ // 6 bytes long, contains 8 leds at 2 bit color depth
#ifndef PANEL_COLOR_INVERSION
    uint8_t redUpperBit1Led1 : 1;
    uint8_t greenUpperBit1Led1 : 1;
    uint8_t blueUpperBit1Led1 : 1;
    uint8_t redLowerBit1Led1 : 1;
    uint8_t greenLowerBit1Led1 : 1;
    uint8_t blueLowerBit1Led1 : 1;
    uint8_t redUpperBit2Led1 : 1;
    uint8_t greenUpperBit2Led1 : 1;
    uint8_t : 0;
    uint8_t blueUpperBit2Led1 : 1;
    uint8_t redLowerBit2Led1 : 1;
    uint8_t greenLowerBit2Led1 : 1;
    uint8_t blueLowerBit2Led1 : 1;
    uint8_t redUpperBit1Led2 : 1;
    uint8_t greenUpperBit1Led2 : 1;
    uint8_t blueUpperBit1Led2 : 1;
    uint8_t redLowerBit1Led2 : 1;
    uint8_t : 0;
    uint8_t greenLowerBit1Led2 : 1;
    uint8_t blueLowerBit1Led2 : 1;
    uint8_t redUpperBit2Led2 : 1;
    uint8_t greenUpperBit2Led2 : 1;
    uint8_t blueUpperBit2Led2 : 1;
    uint8_t redLowerBit2Led2 : 1;
    uint8_t greenLowerBit2Led2 : 1;
    uint8_t blueLowerBit2Led2 : 1;
    uint8_t : 0;
    uint8_t redUpperBit1Led3 : 1;
    uint8_t greenUpperBit1Led3 : 1;
    uint8_t blueUpperBit1Led3 : 1;
    uint8_t redLowerBit1Led3 : 1;
    uint8_t greenLowerBit1Led3 : 1;
    uint8_t blueLowerBit1Led3 : 1;
    uint8_t redUpperBit2Led3 : 1;
    uint8_t greenUpperBit2Led3 : 1;
    uint8_t : 0;
    uint8_t blueUpperBit2Led3 : 1;
    uint8_t redLowerBit2Led3 : 1;
    uint8_t greenLowerBit2Led3 : 1;
    uint8_t blueLowerBit2Led3 : 1;
    uint8_t redUpperBit1Led4 : 1;
    uint8_t greenUpperBit1Led4 : 1;
    uint8_t blueUpperBit1Led4 : 1;
    uint8_t redLowerBit1Led4 : 1;
    uint8_t : 0;
    uint8_t greenLowerBit1Led4 : 1;
    uint8_t blueLowerBit1Led4 : 1;
    uint8_t redUpperBit2Led4 : 1;
    uint8_t greenUpperBit2Led4 : 1;
    uint8_t blueUpperBit2Led4 : 1;
    uint8_t redLowerBit2Led4 : 1;
    uint8_t greenLowerBit2Led4 : 1;
    uint8_t blueLowerBit2Led4 : 1;
    uint8_t : 0;
#else
    uint8_t blueUpperBit1Led1 : 1;
    uint8_t greenUpperBit1Led1 : 1;
    uint8_t redUpperBit1Led1 : 1;
    uint8_t blueLowerBit1Led1 : 1;
    uint8_t greenLowerBit1Led1 : 1;
    uint8_t redLowerBit1Led1 : 1;
    uint8_t blueUpperBit2Led1 : 1;
    uint8_t greenUpperBit2Led1 : 1;
    uint8_t : 0;
    uint8_t redUpperBit2Led1 : 1;
    uint8_t blueLowerBit2Led1 : 1;
    uint8_t greenLowerBit2Led1 : 1;
    uint8_t redLowerBit2Led1 : 1;
    uint8_t blueUpperBit1Led2 : 1;
    uint8_t greenUpperBit1Led2 : 1;
    uint8_t redUpperBit1Led2 : 1;
    uint8_t blueLowerBit1Led2 : 1;
    uint8_t : 0;
    uint8_t greenLowerBit1Led2 : 1;
    uint8_t redLowerBit1Led2 : 1;
    uint8_t blueUpperBit2Led2 : 1;
    uint8_t greenUpperBit2Led2 : 1;
    uint8_t redUpperBit2Led2 : 1;
    uint8_t blueLowerBit2Led2 : 1;
    uint8_t greenLowerBit2Led2 : 1;
    uint8_t redLowerBit2Led2 : 1;
    uint8_t : 0;
    uint8_t blueUpperBit1Led3 : 1;
    uint8_t greenUpperBit1Led3 : 1;
    uint8_t redUpperBit1Led3 : 1;
    uint8_t blueLowerBit1Led3 : 1;
    uint8_t greenLowerBit1Led3 : 1;
    uint8_t redLowerBit1Led3 : 1;
    uint8_t blueUpperBit2Led3 : 1;
    uint8_t greenUpperBit2Led3 : 1;
    uint8_t : 0;
    uint8_t redUpperBit2Led3 : 1;
    uint8_t blueLowerBit2Led3 : 1;
    uint8_t greenLowerBit2Led3 : 1;
    uint8_t redLowerBit2Led3 : 1;
    uint8_t blueUpperBit1Led4 : 1;
    uint8_t greenUpperBit1Led4 : 1;
    uint8_t redUpperBit1Led4 : 1;
    uint8_t blueLowerBit1Led4 : 1;
    uint8_t : 0;
    uint8_t greenLowerBit1Led4 : 1;
    uint8_t redLowerBit1Led4 : 1;
    uint8_t blueUpperBit2Led4 : 1;
    uint8_t greenUpperBit2Led4 : 1;
    uint8_t redUpperBit2Led4 : 1;
    uint8_t blueLowerBit2Led4 : 1;
    uint8_t greenLowerBit2Led4 : 1;
    uint8_t redLowerBit2Led4 : 1;
    uint8_t : 0;
#endif
} LED_long;
#pragma pack(pop)

// masks for the upper and lower bits
#define LED_LONG_MASK_UPPER_1 0b11000111
#define LED_LONG_MASK_UPPER_2 0b01110001
#define LED_LONG_MASK_UPPER_3 0b00011100
#define LED_LONG_MASK_UPPER_4 0b11000111
#define LED_LONG_MASK_UPPER_5 0b01110001
#define LED_LONG_MASK_UPPER_6 0b00011100
#define LED_LONG_MASK_LOWER_1 ~LED_LONG_MASK_UPPER_1
#define LED_LONG_MASK_LOWER_2 ~LED_LONG_MASK_UPPER_2
#define LED_LONG_MASK_LOWER_3 ~LED_LONG_MASK_UPPER_3
#define LED_LONG_MASK_LOWER_4 ~LED_LONG_MASK_UPPER_4
#define LED_LONG_MASK_LOWER_5 ~LED_LONG_MASK_UPPER_5
#define LED_LONG_MASK_LOWER_6 ~LED_LONG_MASK_UPPER_6

#endif // HUB75NANO_2BIT_LED_H