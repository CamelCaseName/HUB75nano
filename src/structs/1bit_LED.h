#ifndef HUB75NANO_1BIT_LED_H
#define HUB75NANO_1BIT_LED_H

#include <inttypes.h>

#pragma pack(push, 1)
typedef struct LED_short
{ // 3 bytes long, contains 8 leds at 1 bit color depth
    uint8_t redUpperBit1Led1 : 1;
    uint8_t greenUpperBit1Led1 : 1;
    uint8_t blueUpperBit1Led1 : 1;
    uint8_t redLowerBit1Led1 : 1;
    uint8_t greenLowerBit1Led1 : 1;
    uint8_t blueLowerBit1Led1 : 1;
    uint8_t redUpperBit1Led2 : 1;
    uint8_t greenUpperBit1Led2 : 1;
    uint8_t : 0;
    uint8_t blueUpperBit1Led2 : 1;
    uint8_t redLowerBit1Led2 : 1;
    uint8_t greenLowerBit1Led2 : 1;
    uint8_t blueLowerBit1Led2 : 1;
    uint8_t redUpperBit1Led3 : 1;
    uint8_t greenUpperBit1Led3 : 1;
    uint8_t blueUpperBit1Led3 : 1;
    uint8_t redLowerBit1Led3 : 1;
    uint8_t : 0;
    uint8_t greenLowerBit1Led3 : 1;
    uint8_t blueLowerBit1Led3 : 1;
    uint8_t redUpperBit1Led4 : 1;
    uint8_t greenUpperBit1Led4 : 1;
    uint8_t blueUpperBit1Led4 : 1;
    uint8_t redLowerBit1Led4 : 1;
    uint8_t greenLowerBit1Led4 : 1;
    uint8_t blueLowerBit1Led4 : 1;
    uint8_t : 0;
} LED_short;
#pragma pack(pop);

// Masks for the upper and lower bits
#define LED_SHORT_MASK_UPPER_1 0b11000111
#define LED_SHORT_MASK_UPPER_2 0b01110001
#define LED_SHORT_MASK_UPPER_3 0b00011100
#define LED_SHORT_MASK_LOWER_1 ~LED_SHORT_MASK_UPPER_1
#define LED_SHORT_MASK_LOWER_2 ~LED_SHORT_MASK_UPPER_2
#define LED_SHORT_MASK_LOWER_3 ~LED_SHORT_MASK_UPPER_3

#endif // HUB75NANO_1BIT_LED_H